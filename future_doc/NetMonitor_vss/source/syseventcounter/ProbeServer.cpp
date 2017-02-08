/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	ProbeServer.cpp
///@brief	实现了探针监听采集代理连接使用的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
///20090305	晏鹤春		修改探针机制为于主机名变更包之前发送ENV主机环境信息
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
	pSession->SetCompressMethod(CRPCM_ZERO);	//设置压缩算法
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

void CProbeServer::OnSessionConnected(CSession *pSession)	// 子类重载处理连接断开事件
{
	CSessionFactory::OnSessionConnected(pSession);	// 子类调用父类处理连接断开事件
	time_t	timep;
	time(&timep);
	printf(
		"\t CProbeServer::OnSessionConnected: CFTDCSession %0x  %s",
		(CFTDCSession *)pSession,
		ctime(&timep));
	fflush(stdout);

	// 向后发送的连接可能畅通，探针发送请求配置信息
	CFTDReqQryHostConfigField fieldConfigInfo;
	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryHostConfigTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	fieldConfigInfo.CfgType = "GetProbeConfig";
	FTDC_ADD_FIELD(&m_pkgSend, &fieldConfigInfo);
	((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
}

void CProbeServer::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	time_t	timep;
	time(&timep);
	printf(
		"\t CProbeServer::OnSessionDisconnected: CFTDCSession %0x Disconnected!  %s",
		(CFTDCSession *)pSession,
		ctime(&timep));
	fflush(stdout);
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
}

/*
CSessionMap::iterator itor = m_mapSession.Begin();
while (!itor.IsEnd())
{
CSession *pTemp = *itor;
itor++;
}
*/
