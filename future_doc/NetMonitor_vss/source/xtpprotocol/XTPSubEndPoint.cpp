// XTPSubEndPoint.cpp: implementation of the CXTPSubEndPoint class.
//
// 20110901 赵鸿昊 NT-0150 xtp协议增加追溯和度量功能:
//                 XTP报文增加扩展头。扩展头以field形式存在，fid是一个特定的值。
//                 扩展头如果存在则紧跟在报头后面。
//                 扩展头的内容庞杂，与协议层次不匹配，不是最优的做法
// 20110914 江鹏   NT-0150 xtp协议增加追溯和度量功能: 增加了对于XTP报文头处理的通用方法，ForcePushHeader和ForcePopHeader
///20120319 江鹏   NT-0139 加快响应时间：增加对于xtp协议的精确度量功能
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "XTPSubEndPoint.h"
#include "XTPPackage.h"

const DWORD NAK_TIMEOUT	= 40;				//毫秒. 第一次NAK间隔时间,以后超时加倍
const DWORD RECV_HEARTBEAT_TIMEOUT	= 1500;	//毫秒. 接收心跳超时时间
const DWORD ACK_TIMEOUT = 200;				//毫秒. ACK间隔时间

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
	//对于一个订阅者注册在多个SubEndPoint的情况，对于同一序号的报文，
	//会多次触发订阅者，这就需要对报文进行过滤。
	//即：如果报文的序号小于等于订阅者已收到的报文数，则丢弃该报文
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
		//收到较小通讯阶段编号的报文，直接丢弃
		return 0;
	}
	
	if (pXTPPackage->GetXTPHeader()->CommPhaseNo > m_wSubCommPhaseNo)
	{
		if (m_pSubscriber->CheckCommPhaseNo())
		{
			//对于不检查通讯阶段序号的订阅者，
			//如果通讯阶段序号不一致则直接丢弃
			return 0;
		}
		//对于不检查通讯阶段序号的订阅者，
		//如果通讯阶段序号变化，则更新缓存的发布方通讯阶段序号，且清空排队
		SetSubCommPhaseNo(pXTPPackage->GetXTPHeader()->CommPhaseNo);
		m_orderingQ.Clear();
	}
	
	//DEBUG_LOG2("[%d] [%d]\n",pXTPPackage->GetXTPHeader()->SequenceNo ,(DWORD)m_orderingQ.GetStartIndex());
	if (pXTPPackage->GetXTPHeader()->SequenceNo < (DWORD)m_orderingQ.GetStartIndex())
	{
		return 0;
	}

	// 生成xtp协议的精确度量数据
#ifdef RTT_MEASURE
	// 只处理报单请求和报单应答
	if (pXTPPackage->GetXTPHeader()->Tid == 0x00001005 || pXTPPackage->GetXTPHeader()->Tid == 0x00001006)
	{	
		// 只处理第一次进入时的包
		TXTPExtHeader* pExtHeader = pXTPPackage->GetExtHeader();

		// 不能超过最大处理个数
		if (pExtHeader->FrontSeqNo < MAX_RTT_MEASURE_NUM)
		{
			// 只处理第一个前置
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
		//构造包
		CPackageBuffer packageBuffer((char *)pPackageData, nPackageLen);
		pXTPPackage->AttachBuffer(&packageBuffer);
		pXTPPackage->ValidPackage();

		//向上传送
		Delivery(pXTPPackage);

		//出队列
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
	//长时间未收到心跳或正常的消息，准备发出NAK
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
	//定期发出ACK
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
		//已经收全了所有的消息
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

