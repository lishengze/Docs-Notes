// PublishPort.cpp: implementation of the CPublishPort class.
//
// 20110624 ����   NT-0139 �ӿ���Ӧʱ�䣺������֪ͨ����
// 20120319 ����   NT-0139 �ӿ���Ӧʱ�䣺���Ӷ���xtpЭ��ľ�ȷ��������
// 20120409 ����   NT-0139 �ӿ���Ӧʱ�䣺�����˶��ڷ���ʧ��ʱ�Ļ��˹���
// 20120409 ����   NT-0139 �ӿ���Ӧʱ�䣺xtpЭ���޸�Ϊ΢�뼶����
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
		//���ԭ��δ������ֱ�ӷ���
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
	
	//���ش�ʱ���ٶȺͽ��ٵ�ƽ��ֵ��Ϊ�����ٶ�
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
		pHeader->GroupID = (WORD)m_dwGroupID;		//��ʱʹ��

		// ����xtpЭ��ľ�ȷ��������
#ifdef RTT_MEASURE
		// ֻ����������ͱ���Ӧ��
		if (pHeader->Tid == 0x00001005 || pHeader->Tid == 0x00001006)
		{
			// �����չͷ�е�ǰ�úź�ǰ�����û����д����дһ��
			TXTPExtHeader* pExtHeader = m_pSendPackage->GetExtHeader();

			if (pExtHeader->CompSeqNo == 0)
			{
				// ��д��չͷ����Ϣ
				pExtHeader->FrontSubjectID = pHeader->SubjectID;
				pExtHeader->FrontSeqNo = pHeader->SequenceNo;
			}

			// ���ܳ�����������
			if (pExtHeader->FrontSeqNo < MAX_RTT_MEASURE_NUM)
			{
				// ֻ�����һ��ǰ��
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
	
	// δ����Ĵ����ȷ���	
	if (m_nBandWidth > 0)
	{
		m_nBandWidth = 0;
	}

	// ���ӵ�ǰ����ʹ�õĴ���
	m_nBandWidth += (int) (((double) (m_nTransRate * 0.001)) * nClockLapse);

	// �����ǰû�д�����
	if (m_nBandWidth <= 0)
	{
		// �����ݿɶ�ʱ֪ͨ
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

		// ���㱾�����Ĵ���
		m_nBandWidth -= (pPackage->Length() + 100);

		// ���ɰ�
		pPackage->MakePackage();

		// ���԰Ѱ��ӵ��ϲ�����
		if (!m_pCompactPackage->AppendPackage(pPackage))
		{
			// �����������
			bSendSuccess = Flush();

			if (!bSendSuccess)
			{
				// ����ʧ�ܻ��ˣ����ٷ���
				MoveTo(nNextId, CFlowReader::FROM_HEAD);

				break;
			}
			else
			{
				// ���ͳɹ�����û�м���İ��ӽ�ȥ
				nNextId = GetNextId() - 1;
				m_pCompactPackage->AppendPackage(pPackage);
			}
		}

		nSendCount ++;
	}

	// ���²���ֻ�з��ͳɹ��������ִ�У����Է�δ����İ��������ٶȡ�����֪ͨ
	if (bSendSuccess && nSendCount > 0)
	{
		// �ѿ���δ����İ����ͳ�ȥ
		if (m_pCompactPackage->Length() > 0)
		{
			bSendSuccess = Flush();

			if (!bSendSuccess)
			{
				// ����ʧ�ܻ��ˣ����ٷ���
				MoveTo(nNextId, CFlowReader::FROM_HEAD);
			}
		}

		if (bSendSuccess)
		{
			// ��������ʱ�ſ��������ٶ�
			if (m_nBandWidth <= 0)
			{	
				if (m_nTransRate < m_nDesiredTransRate)
				{
					m_nTransRate += m_nTransRateIncrease;
				}
				else
				{
					// ���������ٶ�ʱ�����ټ���
					m_nTransRate += m_nTransRateIncrease / 2;
				}
			}	
		}
	}

	// �����ݿɶ�ʱ֪ͨ
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

	// ȡ�����˿��нϿ������
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


