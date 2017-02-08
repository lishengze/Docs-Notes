// PublishPort.cpp: implementation of the CPublishPort class.
//
// 20110624 江鹏   NT-0139 加快响应时间：增加了通知功能
// 20120319 江鹏   NT-0139 加快响应时间：增加对于xtp协议的精确度量功能
// 20120409 江鹏   NT-0139 加快响应时间：完善了对于发包失败时的回退功能
// 20120409 江鹏   NT-0139 加快响应时间：xtp协议修改为微秒级调度
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "PublishPort.h"

const DWORD SUBSCRIBER_ACK_TIME_OUT = 1000;

//////////////////////////////////////////////////////////////////////
// CPublishCompactPackage
//////////////////////////////////////////////////////////////////////
CPublishCompactPackage::CPublishCompactPackage(int nMaxLength)
{
	ConstructAllocate(nMaxLength, 1000);
	m_pBufferEnd = m_pPackageBuffer->Data()+m_pPackageBuffer->Length();
	Reset();
}
bool CPublishCompactPackage::AppendPackage(CPackage *pPackage)
{
	if (m_pTail+pPackage->Length() > m_pBufferEnd)
	{
		return false;
	}
	memcpy(m_pTail, pPackage->Address(), pPackage->Length());
	m_pTail += pPackage->Length();

	return true;
}

void CPublishCompactPackage::Reset()
{
	AllocateMax();
	Truncate(0);
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPublishPort::CPublishPort(CProtocol *pSendProtocol, CXTPPackage *pSendPackage, DWORD nSubjectID)
{
	m_pSendProtocol = pSendProtocol;
	m_pSendPackage = pSendPackage;
	m_nSubjectID = nSubjectID;
	m_nTransRateIncrease = 16;
	
	m_nTransRate = 20000;
	m_nDesiredTransRate = m_nTransRate;
	m_nBandWidth = 0;
	srand(time(NULL));
	m_dwGroupID = ((QWORD) this) + nSubjectID + rand();
	
	m_pCompactPackage = new CPublishCompactPackage(1400);
}

CPublishPort::~CPublishPort()
{
	delete m_pCompactPackage;
}

int CPublishPort::AttachFlow(CReadOnlyFlow *pFlow, int nStartId)
{
	return m_flowReader.AttachFlow(pFlow, nStartId);
}

void CPublishPort::MoveTo(int nOffset, CFlowReader::SeekFlag nSeekFlag)
{
	if ((nSeekFlag==CFlowReader::FROM_HEAD && m_flowReader.GetId()==nOffset) 
		|| (nSeekFlag==CFlowReader::FROM_HERE && nOffset==0))
	{
		//如果原地未动，则直接返回
		return;
	}
	
	m_nDesiredTransRate = m_nTransRate;	

	NET_STATUS_LOG2("Publish Port Move SubjectID=[%d] [%d]->", m_nSubjectID, m_flowReader.GetId());
	if (m_nTransRate > 100 && ((nSeekFlag ==CFlowReader::FROM_HEAD && m_flowReader.GetId()>nOffset)
			|| (nSeekFlag==CFlowReader::FROM_HERE && nOffset<0)))
	{
		m_nTransRate *= 95;
		m_nTransRate /= 100;
	}
	
	//将重传时的速度和降速的平均值做为理想速度
	m_nDesiredTransRate = (m_nDesiredTransRate+m_nTransRate)/2;
	
	m_flowReader.SetId(nOffset, nSeekFlag);
	
	NET_STATUS_LOG1("[%d]\n", m_flowReader.GetId());
}

CPackage *CPublishPort::GetNextDataPackage()
{
	m_pSendPackage->AllocateMax();
	if(m_flowReader.GetNext(m_pSendPackage))
	{
		TXTPHeader  *pHeader = m_pSendPackage->GetXTPHeader();
		pHeader->SequenceNo = m_flowReader.GetId();
		pHeader->SubjectID = m_nSubjectID;
		pHeader->CommPhaseNo = m_flowReader.GetCommPhaseNo();
		pHeader->GroupID = (WORD)m_dwGroupID;		//临时使用

		// 生成xtp协议的精确度量数据
#ifdef RTT_MEASURE
		// 只处理报单请求和报单应答
		if (pHeader->Tid == 0x00001005 || pHeader->Tid == 0x00001006)
		{
			// 如果扩展头中的前置号和前置序号没有填写则填写一下
			TXTPExtHeader* pExtHeader = m_pSendPackage->GetExtHeader();

			if (pExtHeader->CompSeqNo == 0)
			{
				// 填写扩展头的信息
				pExtHeader->FrontSubjectID = pHeader->SubjectID;
				pExtHeader->FrontSeqNo = pHeader->SequenceNo;
			}

			// 不能超过最大处理个数
			if (pExtHeader->FrontSeqNo < MAX_RTT_MEASURE_NUM)
			{
				// 只处理第一个前置
				if (pExtHeader->FrontSubjectID == g_FrontSubjectID)
				{
					TRttMeasure* pRttMeasure = g_RttMeasures[pExtHeader->FrontSeqNo];	

					if (pRttMeasure->EndClock == 0)
					{
						pRttMeasure->EndClock = GetSysMicroClock();
					}
				}
			}
		}
#endif

		return m_pSendPackage;
	}
	return NULL;
}

bool CPublishPort::Flush()
{
	int nSendRet = m_pSendProtocol->Send(m_pCompactPackage);
	m_pCompactPackage->Reset();
	return (nSendRet == 0);
}

int CPublishPort::Publish(QWORD nClockLapse)
{
	if (nClockLapse > 20000)
	{
		nClockLapse = 20000;
	}
	
	// 未用完的带宽额度放弃	
	if (m_nBandWidth > 0)
	{
		m_nBandWidth = 0;
	}

	// 增加当前可以使用的带宽
	m_nBandWidth += (int) (((double) (m_nTransRate * 0.001)) * nClockLapse);

	// 如果当前没有带宽返回
	if (m_nBandWidth <= 0)
	{
		// 有数据可读时通知
		if (m_flowReader.Available())
		{
			(m_flowReader.GetFlow())->Notify();
		}

		return 0;
	}

	int nSendCount = 0;
	bool bSendSuccess = true;
	int nNextId = GetNextId();

	while (m_nBandWidth > 0)
	{
		CPackage *pPackage = GetNextDataPackage();
		
		if (pPackage == NULL)
		{
			break;
		}

		// 计算本次消耗带宽
		m_nBandWidth -= (pPackage->Length() + 100);

		// 生成包
		pPackage->MakePackage();

		// 尝试把包加到合并包中
		if (!m_pCompactPackage->AppendPackage(pPackage))
		{
			// 如果满包则发送
			bSendSuccess = Flush();

			if (!bSendSuccess)
			{
				// 发送失败回退，不再发送
				MoveTo(nNextId, CFlowReader::FROM_HEAD);

				break;
			}
			else
			{
				// 发送成功，把没有加入的包加进去
				nNextId = GetNextId() - 1;
				m_pCompactPackage->AppendPackage(pPackage);
			}
		}

		nSendCount ++;
	}

	// 以下操作只有发送成功的情况下执行：尝试发未发完的包、增加速度、发出通知
	if (bSendSuccess && nSendCount > 0)
	{
		// 把可能未发完的包发送出去
		if (m_pCompactPackage->Length() > 0)
		{
			bSendSuccess = Flush();

			if (!bSendSuccess)
			{
				// 发送失败回退，不再发送
				MoveTo(nNextId, CFlowReader::FROM_HEAD);
			}
		}

		if (bSendSuccess)
		{
			// 当带宽不够时才考虑增加速度
			if (m_nBandWidth <= 0)
			{	
				if (m_nTransRate < m_nDesiredTransRate)
				{
					m_nTransRate += m_nTransRateIncrease;
				}
				else
				{
					// 超过理想速度时，增速减半
					m_nTransRate += m_nTransRateIncrease / 2;
				}
			}	
		}
	}

	// 有数据可读时通知
	if (m_flowReader.Available())
	{
		(m_flowReader.GetFlow())->Notify();
	}

	return nSendCount;
}

void CPublishPort::Merge(CPublishPort *pPublishPort)
{
	for(int i=0; i<pPublishPort->m_SubscirberInfos.size(); i++)
	{
		m_SubscirberInfos.push_back(pPublishPort->m_SubscirberInfos[i]);
	}

	// 取两个端口中较快的速率
	if (pPublishPort->m_nTransRate > m_nTransRate)
	{
		m_nTransRate = pPublishPort->m_nTransRate;
		m_nDesiredTransRate = pPublishPort->m_nDesiredTransRate;
		m_nBandWidth = pPublishPort->m_nBandWidth;
	}
}

bool CPublishPort::RemoveTimeoutSubscriber(DWORD dwCurrTime)
{
	vector<TSubscirberInfo>::iterator i= m_SubscirberInfos.begin();
	for (; i != m_SubscirberInfos.end(); i++)
	{
		if ((dwCurrTime-(*i).dwLastActiveTime) > SUBSCRIBER_ACK_TIME_OUT)
		{
			NET_STATUS_LOG3("RemoveTimeoutSubscriber: SubscriberID=[%x] CurrentTime=[%d] LastActiveTime=[%d]\n", (*i).dwSubscriberID, dwCurrTime, (*i).dwLastActiveTime);
			m_SubscirberInfos.erase(i);
			return true;
		}
	}
	return false;
}


