// XTPPubEndPoint.cpp: implementation of the CXTPPubEndPoint class.
//
// 20061020  赵鸿昊 增加发送状态日志
// 20061107  赵鸿昊 将发送状态日志由事件改为状态
// 20090617  赵鸿昊 NT-0083: XTP Nak记入syslog
// 20120319  江鹏   NT-0139 加快响应时间：优化了定时器调试、把发布从OnTimer中移出
// 20120409  江鹏   NT-0139 加快响应时间：xtp协议修改为微秒级调度
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "XTPPubEndPoint.h"
#include "monitorIndex.h"

const int MAX_PUB_PORTS			= 8;	//pubport的最大个数
const int FRONT_MERGE_DISTANCE	= 10000;//向前合并距离
const int BACK_MERGE_DISTANCE	= 10000;//向后合并距离
const DWORD SEND_HEARTBEAT_TIMEOUT	= 500;	//发送心跳时间间隔，单位为毫秒
const DWORD LOG_TIMEOUT	= 5000;	//写日志时间间隔，单位为毫秒

static CStringBufferMonitorIndex XTPPubMonitor("XTPPub", 10);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CXTPPubEndPoint::CXTPPubEndPoint(CReadOnlyFlow *pFlow, DWORD nSubjectID, 
								 CProtocol *pSendProtocol, CXTPPubHelper *pControlHelper)
{
	m_pFlow = pFlow;
	m_nSubjectID = nSubjectID;
	m_pSendProtocol = pSendProtocol;
	m_pControlHelper = pControlHelper;
	m_nLastSendClock = 0;
	m_nSendHeartbeatClock = 0;
	m_nLogClock = 0;
	m_SendPackage.ConstructAllocate(XTP_PACKAGE_MAX_SIZE+XTPHLEN, 1000);
}

CXTPPubEndPoint::~CXTPPubEndPoint()
{
	for (int i=0; i<m_PublishPorts.size(); i++)
	{
		delete m_PublishPorts[i];
	}
}

int ComparePublishPort(const void *elem1, const void * elem2 )
{
	int nNextId1 = (*((CPublishPort **)elem1))->GetNextId();
	int nNextId2 = (*((CPublishPort **)elem2))->GetNextId();
	if (nNextId1 > nNextId2)
	{
		return 1;
	}
	if (nNextId1 < nNextId2)
	{
		return -1;
	}

	return 0;
}

void CXTPPubEndPoint::Publish(QWORD nCurrClock)
{
	QWORD nClockLapse = nCurrClock - m_nLastSendClock;
	m_nLastSendClock = nCurrClock;
	int i = 0;
	for (i=0; i<m_PublishPorts.size(); i++)
	{
		m_PublishPorts[i]->Publish(nClockLapse);
	}

	if (m_PublishPorts.size() < 2)
	{
		return;
	}
	//如果两个PublishPort离的很近，则将其合并，每次最多只合并一对
	qsort(&m_PublishPorts[0], m_PublishPorts.size(), sizeof(CPublishPort *),
		ComparePublishPort);
	for (i=m_PublishPorts.size()-2; i>=0; i--)
	{
		int nDiff = m_PublishPorts[i+1]->GetNextId()-m_PublishPorts[i]->GetNextId();
		if (nDiff<FRONT_MERGE_DISTANCE/2 && nDiff>-BACK_MERGE_DISTANCE/2)
		{
			NET_STATUS_LOG3("Merge Publish Port[%d], merge from [%d] to [%d],", i,
				m_PublishPorts[i+1]->GetNextId(), m_PublishPorts[i]->GetNextId());
			m_PublishPorts[i]->Merge(m_PublishPorts[i+1]);
			RemovePublishPort(m_PublishPorts[i+1]);
			NET_STATUS_LOG1("Remain Publish Port Count [%d]\n", m_PublishPorts.size());
			break;
		}
	}
}

void CXTPPubEndPoint::OnNak(DWORD dwSubscriberID, int nStartID, DWORD dwNakTime)
{
	REPORT_EVENT(LOG_INFO, "XTP", 
		"Receive Nak: Subject=[0x%04x] SubscriberID=[%x] StartID=[%d]\n",
		m_nSubjectID, dwSubscriberID, nStartID);
	int i = 0;
	for (i=0; i<m_PublishPorts.size(); i++)
	{
		CPublishPort *pCurrPort = m_PublishPorts[i];
		if (pCurrPort->IsServeFor(dwSubscriberID))
		{
			int nDistance = pCurrPort->GetNextId() - nStartID;
			if(pCurrPort->GetSubscirberCount() <= 1
				|| nDistance>-BACK_MERGE_DISTANCE && nDistance<FRONT_MERGE_DISTANCE)
			{
				// 只回退不向前进、防止一个发布端口有多个订阅者时来回跳动而引发更多的nak				
				if (nStartID < pCurrPort->GetNextId())
				{
					pCurrPort->MoveTo(nStartID);
				}

				return ;
			}
			pCurrPort->DelSubscriber(dwSubscriberID);
			if (pCurrPort->GetSubscirberCount() <= 0)
			{
				RemovePublishPort(pCurrPort);
			}
			break;
		}
	}

	//找出离nStrartID最近的前后两个PublishPort
	CPublishPort *pFrontPort = NULL;
	CPublishPort *pBackPort = NULL;
	int nBackDistance = 0x80000000;
	int nFrontDistance = 0x7FFFFFFF;
	for (i=0; i<m_PublishPorts.size(); i++)
	{
		int nDistance = m_PublishPorts[i]->GetNextId() - nStartID;
		if (nDistance < 0)
		{
			if (nBackDistance < nDistance)
			{
				nBackDistance = nDistance;
				pBackPort = m_PublishPorts[i];
			}
		}
		else
		{
			if (nFrontDistance > nDistance)
			{
				nFrontDistance = nDistance;
				pFrontPort = m_PublishPorts[i];
			}
		}
	}

	if (pBackPort != NULL && (-nBackDistance) <= BACK_MERGE_DISTANCE)
	{
		//后面的pubport已经很近了，不需要移动指针
		pBackPort->AddSubscriber(dwSubscriberID, dwNakTime);
		return;
	}

	if (pFrontPort != NULL && nFrontDistance <= FRONT_MERGE_DISTANCE)
	{
		//前面的pubport在可用范围内，指针回退
		pFrontPort->AddSubscriber(dwSubscriberID, dwNakTime);

		// 只回退不向前进、防止一个发布端口有多个订阅者时来回跳动而引发更多的nak				
		if (nStartID < pFrontPort->GetNextId())
		{
			pFrontPort->MoveTo(nStartID);
		}

		return;
	}

	//如果pubport已经达到最大数量，则：
	//	如果后面有pubport，则什么也不做，等待这个pubport提供服务
	//  如果后面已经没有pubport，则将前面的pubport回退
	if(m_PublishPorts.size() >= MAX_PUB_PORTS)
	{
		if (pBackPort == NULL)
		{
			if (pFrontPort == NULL)
			{
				pFrontPort = m_PublishPorts[0];
			}

			// 只回退不向前进、防止一个发布端口有多个订阅者时来回跳动而引发更多的nak				
			if (nStartID < pFrontPort->GetNextId())
			{
				pFrontPort->MoveTo(nStartID);
			}

			pFrontPort->AddSubscriber(dwSubscriberID, dwNakTime);
		}
		else
		{
			pBackPort->AddSubscriber(dwSubscriberID, dwNakTime);
		}
		return;
	}

	CreatePublishPort(dwSubscriberID, nStartID, dwNakTime);
}

void CXTPPubEndPoint::OnAck(DWORD dwSubscriberID, int nStartID, DWORD dwAckTime)
{
	//printf("OnAck [%x][%d]\n", dwSubscriberID, nStartID);
	for (int i=0; i<m_PublishPorts.size(); i++)
	{
		CPublishPort *pCurrPort = m_PublishPorts[i];
		if (pCurrPort->IsServeFor(dwSubscriberID))
		{
			if (nStartID > pCurrPort->GetNextId())
			{
				CPublishPort *pNextPort = NULL;
				if (i != m_PublishPorts.size()-1)
				{
					pNextPort = m_PublishPorts[i+1];
				}

				if (pNextPort != NULL && 
					nStartID-pNextPort->GetNextId() > FRONT_MERGE_DISTANCE/2)
				{
					pCurrPort->DelSubscriber(dwSubscriberID);
					pNextPort->AddSubscriber(dwSubscriberID, dwAckTime);
					pCurrPort = pNextPort;
				}
				else
				{
					if (pCurrPort->GetSubscirberCount() <= 1)
					{
						//？？？这里不应减速
						pCurrPort->MoveTo(nStartID);
					}

				}
			}
			pCurrPort->UpdSubscriber(dwSubscriberID, dwAckTime);
			break;
		}
	}
}

void CXTPPubEndPoint::CreatePublishPort(DWORD dwSubscriberID, int nStartID, DWORD dwNakTime)
{
	//创建新的pubport
	CPublishPort *pPublishPort = new CPublishPort(m_pSendProtocol, &m_SendPackage, m_nSubjectID);
	pPublishPort->AttachFlow(m_pFlow,nStartID);
		
	for (int k=0; k<m_PublishPorts.size(); k++)
	{
		NET_STATUS_LOG3("Old Publish Ports: m_PublishPorts[%d] = [%p], startid=[%d]\n", 
			k, m_PublishPorts[k], m_PublishPorts[k]->GetNextId());
	}

	//将新创建的pubport插入到数组的i位置
	m_PublishPorts.push_back(pPublishPort);
	pPublishPort->AddSubscriber(dwSubscriberID, dwNakTime);

	NET_STATUS_LOG2("New Publish Port SubscriberID=[%x] StartID=[%d]\n",dwSubscriberID, nStartID);
}

void CXTPPubEndPoint::RemovePublishPort(CPublishPort *pPublishPort)
{
	m_PublishPorts.erase(find(m_PublishPorts.begin(),
		m_PublishPorts.end(), pPublishPort));

	delete pPublishPort;
}

void CXTPPubEndPoint::OnTimer(DWORD nCurrClock)
{	
	//定期发出心跳
	if (m_pFlow != NULL && nCurrClock-m_nSendHeartbeatClock > SEND_HEARTBEAT_TIMEOUT)
	{
		m_pControlHelper->SendHeartBeat(GetSubjectID(), m_pFlow->GetCommPhaseNo(), m_pFlow->GetCount());
		m_nSendHeartbeatClock = nCurrClock;
	}

	vector<CPublishPort *>::iterator i = m_PublishPorts.begin();
	for (; i!= m_PublishPorts.end(); i++)
	{
		CPublishPort *pPublishPort = *i;

		if (pPublishPort->RemoveTimeoutSubscriber(nCurrClock))
		{
			if (pPublishPort->GetSubscirberCount() <= 0)
			{
				m_PublishPorts.erase(i);
				delete pPublishPort;
				break;
			}
		}
	}

	//定期写日志	
	if (m_pFlow != NULL && nCurrClock-m_nLogClock > LOG_TIMEOUT)
	{
		char buf[1000];
		sprintf(buf, "SubjectID=0X%X, Flow Size=%d, PublishPort:", 
			GetSubjectID(), m_pFlow->GetCount());
		i = m_PublishPorts.begin();
		for (; i!= m_PublishPorts.end(); i++)
		{
			sprintf(buf+strlen(buf), " %d", (*i)->GetNextId());
		}
//		strcat(buf, "\n");

		XTPPubMonitor.setValue(buf);

		m_nLogClock = nCurrClock;
	}
}
