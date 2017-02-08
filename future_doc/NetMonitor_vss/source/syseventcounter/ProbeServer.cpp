/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	ProbeServer.cpp
///@brief	ʵ����̽������ɼ���������ʹ�õ���
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
///20090305	�̺״�		�޸�̽�����Ϊ�������������֮ǰ����ENV����������Ϣ
#include "ProbeServer.h"

CProbeTimmer::CProbeTimmer(CReactor *pReactor) :
	CEventHandler(pReactor)
{
	m_nEventId = 0;
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
}

void CProbeTimmer::SetTimer(int nIDEvent, int nElapse)
{
	m_nEventId = nIDEvent;
	CEventHandler::SetTimer(nIDEvent, nElapse);
}

void CProbeTimmer::OnTimer(int nIDEvent)
{
#ifdef PRINT_DEBUG
	printf("CProbeTimmer::OnTimer nIDEvent %d\n", nIDEvent);
#endif
}

int CProbeTimmer::GetEventId(void)
{
	return m_nEventId;
}

CProbeServer::CProbeServer(CReactor *pReactor) :
	CSessionFactory(pReactor, 10)	//,m_timer(pReactor)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);

	//m_timer.SetTimer(1,1000);
}

int CProbeServer::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	return 0;

	//printf("\tCProbeServer::HandlePackage:Receive Package %0x\n",pFTDCPackage->GetTID());
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_ReqUserLogin:
			break;
		case FTD_TID_ReqUserLogout:
			break;
		case FTD_TID_ReqQryTradeDayChangeTopic:
			break;
		case FTD_TID_ReqQryDBQueryTopic:
			break;
		default:
			break;
	}

	return 0;
}

CSession *CProbeServer::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);

	/// Added by Henchi, 20120309
	pSession->SetCompressMethod(CRPCM_ZERO);	//����ѹ���㷨
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CProbeServer::CreateSession:CFTDCSession %0x Connected, CommonName [%s] RemoteName [%s] ==\n",
		ctime(&timep),
		pSession,
		pSession->GetChannel()->GetRemoteCommonName(),
		pSession->GetChannel()->GetRemoteName());
	fflush(stdout);
	return pSession;
}

void CProbeServer::OnSessionConnected(CSession *pSession)	// �������ش������ӶϿ��¼�
{
	CSessionFactory::OnSessionConnected(pSession);	// ������ø��ദ�����ӶϿ��¼�
	time_t	timep;
	time(&timep);
	printf(
		"\t CProbeServer::OnSessionConnected: CFTDCSession %0x  %s",
		(CFTDCSession *)pSession,
		ctime(&timep));
	fflush(stdout);

	// ����͵����ӿ��ܳ�ͨ��̽�뷢������������Ϣ
	CFTDReqQryHostConfigField fieldConfigInfo;
	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryHostConfigTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	fieldConfigInfo.CfgType = "GetProbeConfig";
	FTDC_ADD_FIELD(&m_pkgSend, &fieldConfigInfo);
	((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
}

void CProbeServer::OnSessionDisconnected(CSession *pSession, int nReason)	// �������ش������ӶϿ��¼�
{
	time_t	timep;
	time(&timep);
	printf(
		"\t CProbeServer::OnSessionDisconnected: CFTDCSession %0x Disconnected!  %s",
		(CFTDCSession *)pSession,
		ctime(&timep));
	fflush(stdout);
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// ������ø��ദ�����ӶϿ��¼�
}

/*
CSessionMap::iterator itor = m_mapSession.Begin();
while (!itor.IsEnd())
{
CSession *pTemp = *itor;
itor++;
}
*/
