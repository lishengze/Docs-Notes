// OFPProtocol.cpp: implementation of the COFPProtocol class.
//
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "OFPProtocol.h"

//////////////////////////////////////////////////////////////////////

#define WRITE_TIMEOUT		20
#define READ_TIMEOUT		60
#define HEARTBEAT_TIMER		1

/** 心跳报文报文HeartBeat的报文体 */
struct TOFPHeartBeat
{
	COFPStringType <8> Date;
	COFPStringType <6> Time;
};

const int OFP_CID_HeartBeatId = 0x9999;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COFPProtocol::COFPProtocol(CReactor *pReactor, char chVersion)
:CProtocol(pReactor, OFPHLEN, new COFPPackage(), new COFPPackage())
{
	m_chVersion = chVersion;
	
	m_LastWriteTime = pReactor->Time();
	m_LastReadTime = pReactor->Time();
	m_pReactor = pReactor;

	if (chVersion == OFP_VERSION_2)
	{
		pReactor->RegisterTimer(this, HEARTBEAT_TIMER, 5000);
	}
	
	m_pkgHeartbeat.ConstructAllocate(sizeof(TOFPHeartBeat), GetHdrReserveLen());
}

COFPProtocol::~COFPProtocol()
{
	m_pReactor->RemoveTimer(this, HEARTBEAT_TIMER);
}

int COFPProtocol::Pop(CPackage *pPackage)
{
	//设置最新收到数据包的时间
	m_LastReadTime = m_pReactor->Time();

	NET_IO_LOG1("Receive OFP Package, time:%lu\n", m_LastReadTime);	

	//检查是不是心跳
	COFPPackage *pOFPPackage = (COFPPackage *)pPackage;

	if(pOFPPackage->GetCommandID() == OFP_CID_HeartBeatId)
	{
		if (m_pUpperHandler != NULL) 
		{
			return m_pUpperHandler->HandlePackage(pPackage, this);
		}
		return 0;
	} 
	else 
	{
		return CProtocol::Pop(pPackage);
	}
}

int COFPProtocol::Push(CPackage *pPackage, CProtocol *pUpper)
{
	//设置最新发送数据包的时间
	m_LastWriteTime = m_pReactor->Time();

	return CProtocol::Push(pPackage, pUpper);
}

void COFPProtocol::OnTimer(int nIDEvent)
{
	if(nIDEvent == HEARTBEAT_TIMER)
	{
		if(m_pReactor->Time()-m_LastReadTime>READ_TIMEOUT)
		{
			//心跳读超时，通知下层协议
			NET_CONNECT_LOG2("Heartbeat Receive Timeout, CurrentTime=%lu LastReadTime=%lu\n",m_pReactor->Time(),m_LastReadTime);	
			NotifyError(MSG_OFPERR_RECVHEARTBEAT, 0, this);
			return;
		}

		if(m_pReactor->Time()-m_LastWriteTime>WRITE_TIMEOUT)
		{
			NET_CONNECT_LOG0("Send Heartbeat\n");			
			//心跳读超时，发送心跳包
			if(SendHeartBeat()<0)
			{
				NotifyError(MSG_OFPERR_SENDHEARTBEAT, 0, this);
				return;
			}
		}
	}
}

void COFPProtocol::PublishSend()
{
	CPubEndPointMap::iterator pitor = m_mapPubEndPoint.Begin();
	while (!pitor.IsEnd())
	{
		(*pitor)->PublishSend();
		pitor++;
	}
}

int COFPProtocol::SendHeartBeat()
{
	int len = GetHdrReserveLen();
	
	m_pkgHeartbeat.PreparePackage(m_chVersion, 0x0550);
	m_pkgHeartbeat.SetEcho("ping","");
	m_pkgHeartbeat.SetFlowType(OFPFT_HEARTBEAT);
	m_pkgHeartbeat.SetFlowSeqNo(0);

	//设置最新发送数据包的时间
	m_LastWriteTime = m_pReactor->Time();
	
	TOFPHeartBeat HeartBeat;

	char buffer[12];
	struct tm * ptm = localtime (&m_LastWriteTime);
	sprintf(buffer,"%04d%02d%02d", ptm->tm_year+1900, ptm->tm_mon, ptm->tm_mday);
	HeartBeat.Date = (buffer);
	sprintf(buffer,"%02d%02d%02d", ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
	HeartBeat.Time = (buffer);

	OFP_ADD_BODY(m_pkgHeartbeat, HeartBeat);

	return Send(&m_pkgHeartbeat);
}

int COFPProtocol::OnRecvErrorPackage(CPackage *pPackage)
{
	NotifyError(MSG_OFPERR_BADPACKAGE, 0, this);
	return 0;
}

void COFPProtocol::Publish(CReadOnlyFlow *pFlow, WORD nSequenceSeries, int nStartId)
{
//	DEBUG_LOG2("nSequenceSeries=[%d], nStartId=[%d]\n",
//		nSequenceSeries, nStartId);
	COFPPubEndPoint *pPubEndPoint = GetPubEndPoint(nSequenceSeries);
	if (pPubEndPoint == NULL)
	{
		pPubEndPoint = new COFPPubEndPoint(pFlow, nSequenceSeries, nStartId, this);
		m_mapPubEndPoint.Insert(nSequenceSeries, pPubEndPoint);
	}
	pPubEndPoint->MoveTo(nStartId);
}

void COFPProtocol::UnPublish(WORD nSequenceSeries)
{
	COFPPubEndPoint *pPubEndPoint = GetPubEndPoint(nSequenceSeries);
	if (pPubEndPoint != NULL)
	{
		delete pPubEndPoint;
		m_mapPubEndPoint.Erase(nSequenceSeries);
	}
}

COFPPubEndPoint *COFPProtocol::GetPubEndPoint(WORD nSequenceSeries)
{
	COFPPubEndPoint **pFind = m_mapPubEndPoint.Find(nSequenceSeries);
	if (pFind != NULL)
	{
		return (*pFind);
	}
	return NULL;
}


