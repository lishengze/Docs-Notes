// NsSessionFactory.cpp: implementation of the CNsSessionFactory class.
//
///20080727 赵鸿昊 NT-0048 : 配合CSessionFactory的修改，注册地址时增加标记参数，
///                在连接成功时会返回，以区分通过不同地址创建的连接
// 20081230 赵鸿昊 NT-0042 ：改为随机连接FENS，逐个连接前置。
///20080318 武玉波 NT-0097：在不提供front地址的时候，跳过延时
//					直接使用NameServer获取Front，建立连接
///20100512 赵鸿昊 NT-0103 客户端断线后重连优化：将NT-0097所做的延时判断逻辑移入
///                CSessionFactory
///20110509 江鹏   NT-0131 UserAPI功能完善
///20121010 孙尧宇 NT-0131 UserAPI功能完善，避免fens挂死的方法不再使用超时重连，而使用NsSession定时Disconnect，以免同时发起两个fens连接
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "NsSessionFactory.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNsSessionFactory::CNsSessionFactory(CReactor *pReactor, int nMaxSession)
:CSessionFactory(pReactor, nMaxSession)
{
	m_bInQueryNs = false;
	m_pNsSession = NULL;
	m_pNsConnecterManager = new CConnecterManager(&m_reactorConnect, this);
	SetConnectMode(false);
}

CNsSessionFactory::~CNsSessionFactory()
{

}
void CNsSessionFactory::NsDisconnect(CChannel *pChannel)
{
	if (m_pNsConnecterManager != NULL)
	{
		m_pNsConnecterManager->OnDiscconnected(pChannel);
	}
	m_pNsSession=NULL;
}
void CNsSessionFactory::RegisterNameServer(char *location, DWORD dwMark)
{
 	CSessionConnecter *pConnecter = new CSessionConnecter(location, dwMark);
	m_pNsConnecterManager->AppendConnecter(pConnecter);

	// 在使用fens时直接清除用户设置的前置地址
	m_pConnecterManager->Clear();
}

int CNsSessionFactory::HandlePackage(CNsPackage *pNsPackage, CNsSession *pSession)
{
	char *p = pNsPackage->Address();
	char seps[] = "\r\n";
	m_pConnecterManager->Clear();
	// 20071128_赵鸿昊 使用strtok可能不安全，自已解析。
	char *token = p;
	for (int i=0; i<pNsPackage->Length(); i++,p++)
	{
		if (strchr(seps, *p))
		{
			if (token != NULL)
			{
				*p = '\0';
				RegisterConnecter(token);
				token = NULL;
			}
		}
		else
		{
			if (token == NULL)
			{
				token = p;
			}
		}
	}
	m_pNsConnecterManager->OnDiscconnected(m_pNsSession->GetChannel());
	m_pNsSession->Disconnect(0);
	m_pNsSession = NULL;


//	m_pNsConnecterManager->CancelConnect();
	// 20071128_赵鸿昊 UM_CONNECT_LOOP事件导致NS状态切换，因此，该事件必须
	//                 在一个循环中只出现一次，否则切不到下一个状态。
//	SendEvent(UM_CONNECT_LOOP, 0, NULL);
	return -1;
}

void CNsSessionFactory::OnTimer(int nIDEvent)
{
	if (nIDEvent == TIMER_ID_CONNECT)
	{
		if (m_bInQueryNs)
		{
			KillTimer(TIMER_ID_CONNECT);
			if (m_pNsSession == NULL && !m_pNsConnecterManager->IsConnecting())
			{
				//  随机连接
				m_pNsConnecterManager->Connect(true);
			}
			return;
		}
	}

	CSessionFactory::OnTimer(nIDEvent);
}

int CNsSessionFactory::HandleEvent(int nEventID, DWORD dwParam, void *pParam)
{
	switch(nEventID) {
	case UM_CONNECT_RESULT:
		if(m_bInQueryNs)
		{
			CChannel *pChannel = (CChannel *)pParam;
			
			if (pChannel != NULL)
			{
				m_pNsConnecterManager->OnConnected(pChannel);
				m_pNsSession = new CNsSession(m_pReactor, pChannel);
				m_pNsSession->RegisterFactory(this);
				m_pReactor->RegisterIO(m_pNsSession);
				//m_pNsSession->RegisterSessionCallback(this);//为了避免将OnDisconnection传递给客户端应用，不能写这一句
				m_pNsSession->RegisterPackageHandler(this);
			}
			else
			{
				// 此处连接fens失败，清空当前的连接器
				m_pConnecterManager->Clear();
			}

			if (m_pNsSession == NULL)
			{
				// 尝试下一个连接
				m_pNsConnecterManager->ConnectNext();
			}
			else
			{
				m_pNsConnecterManager->CancelConnect();
			}
			return 0;
		}
		break;
	case UM_CONNECT_LOOP:
		//20071128_赵鸿昊 每次都直接调用OnTimer会导致在Linux下重连太频繁。	
		m_bInQueryNs = !m_bInQueryNs;

		if (m_bInQueryNs) // 2
		{
			OnTimer(TIMER_ID_CONNECT);
			return 0;
		}
		break;
	default:
		break;
	}
	return CSessionFactory::HandleEvent(nEventID, dwParam, pParam);
}
