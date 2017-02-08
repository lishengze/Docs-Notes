// XTPPubEndPoint.cpp: implementation of the CXTPPubEndPoint class.
//
// 20061020  �Ժ�� ���ӷ���״̬��־
// 20061107  �Ժ�� ������״̬��־���¼���Ϊ״̬
// 20090617  �Ժ�� NT-0083: XTP Nak����syslog
// 20120319  ����   NT-0139 �ӿ���Ӧʱ�䣺�Ż��˶�ʱ�����ԡ��ѷ�����OnTimer���Ƴ�
// 20120409  ����   NT-0139 �ӿ���Ӧʱ�䣺xtpЭ���޸�Ϊ΢�뼶����
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "XTPPubEndPoint.h"
#include "monitorIndex.h"

const int MAX_PUB_PORTS			= 8;	//pubport��������
const int FRONT_MERGE_DISTANCE	= 10000;//��ǰ�ϲ�����
const int BACK_MERGE_DISTANCE	= 10000;//���ϲ�����
const DWORD SEND_HEARTBEAT_TIMEOUT	= 500;	//��������ʱ��������λΪ����
const DWORD LOG_TIMEOUT	= 5000;	//д��־ʱ��������λΪ����

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
	//�������PublishPort��ĺܽ�������ϲ���ÿ�����ֻ�ϲ�һ��
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
				// ֻ���˲���ǰ������ֹһ�������˿��ж��������ʱ�������������������nak				
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

	//�ҳ���nStrartID�����ǰ������PublishPort
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
		//�����pubport�Ѿ��ܽ��ˣ�����Ҫ�ƶ�ָ��
		pBackPort->AddSubscriber(dwSubscriberID, dwNakTime);
		return;
	}

	if (pFrontPort != NULL && nFrontDistance <= FRONT_MERGE_DISTANCE)
	{
		//ǰ���pubport�ڿ��÷�Χ�ڣ�ָ�����
		pFrontPort->AddSubscriber(dwSubscriberID, dwNakTime);

		// ֻ���˲���ǰ������ֹһ�������˿��ж��������ʱ�������������������nak				
		if (nStartID < pFrontPort->GetNextId())
		{
			pFrontPort->MoveTo(nStartID);
		}

		return;
	}

	//���pubport�Ѿ��ﵽ�����������
	//	���������pubport����ʲôҲ�������ȴ����pubport�ṩ����
	//  ��������Ѿ�û��pubport����ǰ���pubport����
	if(m_PublishPorts.size() >= MAX_PUB_PORTS)
	{
		if (pBackPort == NULL)
		{
			if (pFrontPort == NULL)
			{
				pFrontPort = m_PublishPorts[0];
			}

			// ֻ���˲���ǰ������ֹһ�������˿��ж��������ʱ�������������������nak				
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
						//���������ﲻӦ����
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
	//�����µ�pubport
	CPublishPort *pPublishPort = new CPublishPort(m_pSendProtocol, &m_SendPackage, m_nSubjectID);
	pPublishPort->AttachFlow(m_pFlow,nStartID);
		
	for (int k=0; k<m_PublishPorts.size(); k++)
	{
		NET_STATUS_LOG3("Old Publish Ports: m_PublishPorts[%d] = [%p], startid=[%d]\n", 
			k, m_PublishPorts[k], m_PublishPorts[k]->GetNextId());
	}

	//���´�����pubport���뵽�����iλ��
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
	//���ڷ�������
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

	//����д��־	
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
