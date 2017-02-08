// NsSessionFactory.cpp: implementation of the CNsSessionFactory class.
//
///20080727 �Ժ�� NT-0048 : ���CSessionFactory���޸ģ�ע���ַʱ���ӱ�ǲ�����
///                �����ӳɹ�ʱ�᷵�أ�������ͨ����ͬ��ַ����������
// 20081230 �Ժ�� NT-0042 ����Ϊ�������FENS���������ǰ�á�
///20080318 ���� NT-0097���ڲ��ṩfront��ַ��ʱ��������ʱ
//					ֱ��ʹ��NameServer��ȡFront����������
///20100512 �Ժ�� NT-0103 �ͻ��˶��ߺ������Ż�����NT-0097��������ʱ�ж��߼�����
///                CSessionFactory
///20110509 ����   NT-0131 UserAPI��������
///20121010 ��Ң�� NT-0131 UserAPI�������ƣ�����fens�����ķ�������ʹ�ó�ʱ��������ʹ��NsSession��ʱDisconnect������ͬʱ��������fens����
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

	// ��ʹ��fensʱֱ������û����õ�ǰ�õ�ַ
	m_pConnecterManager->Clear();
}

int CNsSessionFactory::HandlePackage(CNsPackage *pNsPackage, CNsSession *pSession)
{
	char *p = pNsPackage->Address();
	char seps[] = "\r\n";
	m_pConnecterManager->Clear();
	// 20071128_�Ժ�� ʹ��strtok���ܲ���ȫ�����ѽ�����
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
	// 20071128_�Ժ�� UM_CONNECT_LOOP�¼�����NS״̬�л�����ˣ����¼�����
	//                 ��һ��ѭ����ֻ����һ�Σ������в�����һ��״̬��
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
				//  �������
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
				//m_pNsSession->RegisterSessionCallback(this);//Ϊ�˱��⽫OnDisconnection���ݸ��ͻ���Ӧ�ã�����д��һ��
				m_pNsSession->RegisterPackageHandler(this);
			}
			else
			{
				// �˴�����fensʧ�ܣ���յ�ǰ��������
				m_pConnecterManager->Clear();
			}

			if (m_pNsSession == NULL)
			{
				// ������һ������
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
		//20071128_�Ժ�� ÿ�ζ�ֱ�ӵ���OnTimer�ᵼ����Linux������̫Ƶ����	
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
