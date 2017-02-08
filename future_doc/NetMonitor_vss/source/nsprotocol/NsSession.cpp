// NsSession.cpp: implementation of the CNsSession class.
//
///20121010 孙尧宇 NT-0131 UserAPI功能完善，避免fens挂死的方法不再使用超时重连，而使用NsSession定时Disconnect，以免同时发起两个fens连接
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "NsSession.h"
#include "NsSessionFactory.h"
// 超时检测定时器
const int TIMER_ID_TIMEOUT_CHECK = 222;
const int TIMER_INTERVAL_TIMEOUT_CHECK = 3000;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNsSession::CNsSession(CReactor *pReactor,CChannel *pChannel)
:CSession(pReactor, pChannel, NS_PACKAGE_MAX_SIZE)
{
	m_pNsProtocol = new CNsProtocol(pReactor);
	m_pNsProtocol->AttachLower(m_pChannelProtocol, 0);
	m_pNsProtocol->RegisterErrorHandler(this);
	m_pNsProtocol->RegisterUpperHandler(this);

	m_pPackageHandler = NULL;
	m_pNsSessionFactory=NULL;
}

CNsSession::~CNsSession()
{
}
void CNsSession::RegisterFactory(CNsSessionFactory *pNsSessionFactory)
{
	m_pNsSessionFactory=pNsSessionFactory;
	SetTimer(TIMER_ID_TIMEOUT_CHECK, TIMER_INTERVAL_TIMEOUT_CHECK);
}
void CNsSession::RegisterPackageHandler(CNsSessionCallback *pPackageHandler)
{
	m_pPackageHandler = pPackageHandler;
}

int CNsSession::HandlePackage(CPackage *pPackage,CProtocol *pProtocol)
{
	if (pProtocol == m_pNsProtocol)
	{
		CNsPackage *pNsPacakge = (CNsPackage *)pPackage;
		if (m_pPackageHandler == NULL)
		{
			return 0;
		}
		return m_pPackageHandler->HandlePackage(pNsPacakge, this);
	}
	return 0;
}

void CNsSession::Send(CNsPackage *pPackage)
{
	m_pNsProtocol->Send(pPackage);
}
void CNsSession::OnTimer(int nIDEvent)
{
	if(nIDEvent==TIMER_ID_TIMEOUT_CHECK)
	{
		CChannel *pChannel=this->GetChannel();
		if(m_pNsSessionFactory!=NULL)
		{
			m_pNsSessionFactory->NsDisconnect(pChannel);
		}
		Disconnect(0);
	}
}

