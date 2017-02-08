// XTPSubEndPoint.cpp: implementation of the CXTPSubEndPoint class.
//
// 20110901 �Ժ�� NT-0150 xtpЭ������׷�ݺͶ�������:
//                 XTP����������չͷ����չͷ��field��ʽ���ڣ�fid��һ���ض���ֵ��
//                 ��չͷ�������������ڱ�ͷ���档
//                 ��չͷ���������ӣ���Э���β�ƥ�䣬�������ŵ�����
// 20110914 ����   NT-0150 xtpЭ������׷�ݺͶ�������: �����˶���XTP����ͷ�����ͨ�÷�����ForcePushHeader��ForcePopHeader
///20120319 ����   NT-0139 �ӿ���Ӧʱ�䣺���Ӷ���xtpЭ��ľ�ȷ��������
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "XTPSubEndPoint.h"
#include "XTPPackage.h"

const DWORD NAK_TIMEOUT	= 40;				//����. ��һ��NAK���ʱ��,�Ժ�ʱ�ӱ�
const DWORD RECV_HEARTBEAT_TIMEOUT	= 1500;	//����. ����������ʱʱ��
const DWORD ACK_TIMEOUT = 200;				//����. ACK���ʱ��

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CXTPSubEndPoint::CXTPSubEndPoint(CSubscriber *pSubscriber, DWORD dwSubscriberID, CXTPSubHelper *pControlHelper)
:m_orderingQ(4000)
{
	m_pSubscriber = pSubscriber;
	m_nDisorderClock = 0;
	m_nDeliveryClock = 0;
	m_nNakInterval = NAK_TIMEOUT;
	m_pControlHelper = pControlHelper;
	m_wSubCommPhaseNo = pSubscriber->GetCommPhaseNo();
	m_dwSubscriberID = dwSubscriberID;
	m_dwLastAckClock = 0;
	m_dwGroupID = 0;
	m_orderingQ.SetStartIndex(m_pSubscriber->GetReceivedCount() + 1);
}

CXTPSubEndPoint::~CXTPSubEndPoint()
{

}

int CXTPSubEndPoint::Delivery(CXTPPackage *pXTPPackage)
{
	//����һ��������ע���ڶ��SubEndPoint�����������ͬһ��ŵı��ģ�
	//���δ��������ߣ������Ҫ�Ա��Ľ��й��ˡ�
	//����������ĵ����С�ڵ��ڶ��������յ��ı������������ñ���
	if (pXTPPackage->GetXTPHeader()->CommPhaseNo == m_pSubscriber->GetCommPhaseNo()&&
		pXTPPackage->GetXTPHeader()->SequenceNo > m_pSubscriber->GetReceivedCount())
	{
		m_pSubscriber->HandleMessage(pXTPPackage);
	}
	return 0;
}

int CXTPSubEndPoint::HandlePackage(CXTPPackage *pXTPPackage, DWORD nCurrClock)
{
	if (pXTPPackage->GetXTPHeader()->CommPhaseNo < m_wSubCommPhaseNo)
	{
		//�յ���СͨѶ�׶α�ŵı��ģ�ֱ�Ӷ���
		return 0;
	}
	
	if (pXTPPackage->GetXTPHeader()->CommPhaseNo > m_wSubCommPhaseNo)
	{
		if (m_pSubscriber->CheckCommPhaseNo())
		{
			//���ڲ����ͨѶ�׶���ŵĶ����ߣ�
			//���ͨѶ�׶���Ų�һ����ֱ�Ӷ���
			return 0;
		}
		//���ڲ����ͨѶ�׶���ŵĶ����ߣ�
		//���ͨѶ�׶���ű仯������»���ķ�����ͨѶ�׶���ţ�������Ŷ�
		SetSubCommPhaseNo(pXTPPackage->GetXTPHeader()->CommPhaseNo);
		m_orderingQ.Clear();
	}
	
	//DEBUG_LOG2("[%d] [%d]\n",pXTPPackage->GetXTPHeader()->SequenceNo ,(DWORD)m_orderingQ.GetStartIndex());
	if (pXTPPackage->GetXTPHeader()->SequenceNo < (DWORD)m_orderingQ.GetStartIndex())
	{
		return 0;
	}

	// ����xtpЭ��ľ�ȷ��������
#ifdef RTT_MEASURE
	// ֻ����������ͱ���Ӧ��
	if (pXTPPackage->GetXTPHeader()->Tid == 0x00001005 || pXTPPackage->GetXTPHeader()->Tid == 0x00001006)
	{	
		// ֻ�����һ�ν���ʱ�İ�
		TXTPExtHeader* pExtHeader = pXTPPackage->GetExtHeader();

		// ���ܳ�����������
		if (pExtHeader->FrontSeqNo < MAX_RTT_MEASURE_NUM)
		{
			// ֻ�����һ��ǰ��
			if (pExtHeader->FrontSubjectID == g_FrontSubjectID)
			{
				TRttMeasure* pRttMeasure = g_RttMeasures[pExtHeader->FrontSeqNo];

				if (pRttMeasure->BeginClock == 0)
				{
					pRttMeasure->BeginClock = GetSysMicroClock();
				}
			}
		}
	}
#endif

	if (pXTPPackage->GetXTPHeader()->SequenceNo != (DWORD)m_orderingQ.GetStartIndex())
	{
		if (m_nDisorderClock == 0 && m_dwGroupID == pXTPPackage->GetGroupID())
		{
			m_nDisorderClock = nCurrClock;
			m_nNakInterval = NAK_TIMEOUT;
//			DEBUG_LOG3("Send Nak 0x%x %d %u\n", GetActiveID(), m_orderingQ.GetStartIndex(), pXTPPackage->GetXTPHeader()->SequenceNo);
			m_pControlHelper->SendNak(GetSubjectID(), 
				m_wSubCommPhaseNo, 
				m_dwSubscriberID,
				m_orderingQ.GetStartIndex() - 1);

		}
		pXTPPackage->ForcePushHeader();
		m_orderingQ.EnQueue(pXTPPackage->GetXTPHeader()->SequenceNo,
			pXTPPackage->Address(), pXTPPackage->Length());
		pXTPPackage->ForcePopHeader();

		return 0;
	}

	m_dwGroupID = pXTPPackage->GetGroupID();
	Delivery(pXTPPackage);
	m_orderingQ.DeQueue();
	int nPackageLen = 0;
	void *pPackageData = NULL;
	while ((pPackageData = m_orderingQ.QueueFront(nPackageLen)) != NULL)
	{
		//�����
		CPackageBuffer packageBuffer((char *)pPackageData, nPackageLen);
		pXTPPackage->AttachBuffer(&packageBuffer);
		pXTPPackage->ValidPackage();

		//���ϴ���
		Delivery(pXTPPackage);

		//������
		m_orderingQ.DeQueue();
		pXTPPackage->BufRelease();
	}

//	if (m_orderingQ.IsEmpty())
	{
		m_nDeliveryClock = nCurrClock;
		m_nDisorderClock = 0;
	}
	return 0;
}

void CXTPSubEndPoint::OnTimer(DWORD nCurrClock)
{	
	//��ʱ��δ�յ���������������Ϣ��׼������NAK
	if (nCurrClock - m_nDeliveryClock > RECV_HEARTBEAT_TIMEOUT)
	{
		if (m_nDisorderClock == 0)
		{
			m_nDisorderClock = nCurrClock;	
			m_nNakInterval = NAK_TIMEOUT;
		}
	}
	if (m_nDisorderClock != 0)
	{
		DWORD nClock = nCurrClock - m_nDisorderClock;
		if (nClock > m_nNakInterval)
		{
//			DEBUG_LOG3("Send Nak %d %u %u\n", GetSubjectID(),m_orderingQ.GetStartIndex(),
//				nClock);
			m_pControlHelper->SendNak(GetSubjectID(), 
				m_wSubCommPhaseNo, 
				m_dwSubscriberID,
				m_orderingQ.GetStartIndex() - 1);
			m_nDisorderClock = nCurrClock;	
			if (m_nNakInterval < 16*NAK_TIMEOUT)
			{
				m_nNakInterval *= 2;
			}
		}
	}
	//���ڷ���ACK
	if (nCurrClock-m_dwLastAckClock > ACK_TIMEOUT)
	{
//		printf("Send Ack [%x]\n", m_dwSubscriberID);
		m_pControlHelper->SendAck(GetSubjectID(), 
				m_wSubCommPhaseNo, 
				m_dwSubscriberID,
				m_orderingQ.GetStartIndex() - 1);
		m_dwLastAckClock = nCurrClock;
	}
}

void CXTPSubEndPoint::OnHeartBeat(WORD nCommPhaseNo, int nSeqNo, DWORD nCurrClock)
{
	if (nCommPhaseNo == m_wSubCommPhaseNo && nSeqNo == m_orderingQ.GetStartIndex()-1)
	{
		//�Ѿ���ȫ�����е���Ϣ
		m_nDeliveryClock = nCurrClock;
		m_nDisorderClock = 0;
	}
}

void CXTPSubEndPoint::SetSubCommPhaseNo(WORD wCommPhaseNo)
{
	if (m_wSubCommPhaseNo != wCommPhaseNo)
	{
		m_orderingQ.Clear();
		m_wSubCommPhaseNo = wCommPhaseNo;
	}
	m_pSubscriber->SetCommPhaseNo(wCommPhaseNo);
	m_nNakInterval = NAK_TIMEOUT;
}

