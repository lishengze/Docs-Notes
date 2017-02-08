/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CounterConnector.cpp
///@brief	ʵ���˲ɼ��������Ӳ�����̽����Ϣ����
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#include "CounterConnector.h"
#include "CEventProcess.h"

extern int	g_mAgentId;
extern CManageReqIDSession	g_cProbeToEventReq;
extern CManageReqIDSession	g_cEventToProbeReq;
extern CObjectIdSession g_mObjectIdSession;

extern char g_mTradeDay[9];
extern map<CFileDescript, CFileInfo> g_mapFile;
extern list<CFTDCSession *> g_mListAllSession;					// �������ϵ�̽�롢�ɼ����������б�
extern CAgentConnector	*g_pConnector[MAXPROBECONFIGNUM];
extern map<string, CRequstDBConnectInfo> g_mapDBConnectInfo;	//���ڱ������ݿ�����������������Ϣ�ṹ��ӳ��
CFTDCSession *g_pCounterFtdSession = NULL;						// FTD�´������¼�������Ψһ�Ự
void sendRspQryHostConfig(
		CFTDCPackage &m_pkgSend,
		CFTDCSession *pSession,
		char *pLocationName,
		DWORD nRequestId);
#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pPackOutput; // ���ݰ�������ļ�
#endif

// add by cao.ning
// ϵͳ�ڲ����ӹ�ϵ
extern CSysInternalTopology* g_SysInternalTopology;

// �����¼�������������ӵ���
CCounterTimmer::CCounterTimmer(
	CReactor *pReactor,
	CEventProcess *pEventProcess) :
	CEventHandler(pReactor)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	SetTimer(1, 5000);
	m_pEventProcess = pEventProcess;
}

void CCounterTimmer::OnTimer(int nIDEvent)
{
	m_pEventProcess->getPeriodStats();

	// next for eventcounter test package, add by zjj 20090328
#if 0
	CFTDRtnObjectAttrField	mRtnObject;
	mRtnObject.ObjectID = "TRADE.PuDian.app.qkernel.2";
	mRtnObject.AttrType = APPATTRCPUUSAGE;
	mRtnObject.MonDate = g_mTradeDay;

	time_t	now;
	time(&now);

	char mTime[15];
	struct tm tm_time;
	LocalTime(&now, &tm_time);
	strftime(mTime, 10, "%H:%M:%S", &tm_time);
	mRtnObject.MonTime = mTime;
	mRtnObject.AttrValue = "100.52";
	mRtnObject.ValueType = PERCENT_ATTR;
	m_pkgSend.PreparePackage(
			FTD_TID_RtnObjectAttrTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &mRtnObject);

	char mStr[200];
	sprintf(
		mStr,
		"%s %s %s %s 1",
		g_mTradeDay,
		mTime,
		"TRADE.PuDian.app.compositor.1",
		"IsActive");
	m_pkgSend.PreparePackage(
			FTD_TID_RtnSyslogInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRtnSyslogInfoField	mLogField;
	mLogField.ObjectID = "applog";
	mLogField.ContLen = strlen(mStr);
	mLogField.FileContent = mStr;
	mLogField.AttrType = "applog";
	FTDC_ADD_FIELD(&m_pkgSend, &mLogField);
#endif

	// add by zjj 20090328 end.
	return;
}

CCounterConnector::CCounterConnector(
	CReactor *pReactor,
	CEventProcess *pEventProcess) :
	CAgentSessionFactory(pReactor, 1),
	m_myTimer(pReactor, pEventProcess)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
}

CSession *CCounterConnector::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);

	/// Added by Henchi, 20120309
	pSession->SetCompressMethod(CRPCM_ZERO);	//����ѹ���㷨
	return pSession;
}

void CCounterConnector::OnSessionConnected(CSession *pSession)
{
	CAgentSessionFactory::OnSessionConnected(pSession);

	time_t	timep;
	time(&timep);
	printf(
		"\t\t CCounterConnector::OnSessionConnected SessionConnected %0x Location %s %s ",
		(CFTDCSession *)pSession,
		GetLocationName(),
		ctime(&timep));
	fflush(stdout);

	if (g_pCounterFtdSession == NULL)
	{
		g_pCounterFtdSession = (CFTDCSession *)pSession;
	}
	else
	{
		DisconnectAll(0);
		g_pCounterFtdSession = NULL;
		printf(
			"\t CCounterConnector::OnSessionConnected ���г����ɼ����������¼����㲻�ܳ��ֶ�����ӣ����ó���! %s",
			ctime(&timep));
		printf(
			"\t CCounterConnector::OnSessionConnected ���г����Ͽ��������ӣ����޸�������Ϣ %s \n",
			ctime(&timep));
		fflush(stdout);
		return;

		//exit(0);
	}

	m_pkgSend.PreparePackage(
			FTD_TID_ReqUserLogout,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqUserLogoutField	fieldInfo;
	fieldInfo.UserID = "Connect";
	fieldInfo.ParticipantID = "";
	FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

	list<CFTDCSession *>::iterator	it;
	for (it = g_mListAllSession.begin(); it != g_mListAllSession.end(); it++)
	{
		(*it)->SendRequestPackage(&m_pkgSend);
		m_pkgSend.Pop(FTDCHLEN);
	}

	g_mapFile.clear();

	// add by cao.ning
	// Agent��Event�������ӣ����¡�ϵͳ�ڲ����ӡ���ͨ��Ự
	if (g_SysInternalTopology)
		g_SysInternalTopology->SetSendSessionON(pSession);
}

void CCounterConnector::OnSessionDisconnected(CSession *pSession, int nReason)	// �������ش������ӶϿ��¼�
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// ������ø��ദ�����ӶϿ��¼�
	time_t	timep;
	time(&timep);
	if (g_pCounterFtdSession == (CFTDCSession *)pSession)
	{
		g_pCounterFtdSession = NULL;
	}
	else
	{
		printf(
			"\t CCounterConnector::OnSessionDisconnected ���г����ɼ����������¼����㲻�ܳ��ֶ�����ӣ����ó���! %s",
			ctime(&timep));
	}

	printf(
		"\t\t CCounterConnector::OnSessionDisconnected  %0x Location %s %s",
		(CFTDCSession *)pSession,
		GetLocationName(),
		ctime(&timep));
	fflush(stdout);

	m_pkgSend.PreparePackage(
			FTD_TID_ReqUserLogout,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqUserLogoutField	fieldInfo;
	fieldInfo.UserID = "Disconnect";
	fieldInfo.ParticipantID = "";
	FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

	list<CFTDCSession *>::iterator	it;
	for (it = g_mListAllSession.begin(); it != g_mListAllSession.end(); it++)
	{
		(*it)->SendRequestPackage(&m_pkgSend);
		m_pkgSend.Pop(FTDCHLEN);
	}

	// add by cao.ning
	// Agent��Event�Ͽ����ӣ����¡�ϵͳ�ڲ����ӡ���ͨ��Ự
	if (g_SysInternalTopology)
		g_SysInternalTopology->SetSendSessionOFF();
}

int CCounterConnector::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PRINT_DEBUG
	printf(
		"CCounterConnector::HandlePackage:receive package %0x\n",
		pFTDCPackage->GetTID());
#endif
#ifdef PACKAGE_OUTPUT
	pFTDCPackage->OutputHeader(g_pPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pPackOutput);
#endif
	switch (pFTDCPackage->GetTID())
	{
		// add by cao.ning
		// ϵͳ�ڲ�������ϵ
		case  FTD_TID_ReqQrySysInternalTopologyTopic:
			if (g_SysInternalTopology)
			{
				g_SysInternalTopology->OnReqQrySysInternalTopologyTopic(pFTDCPackage, pSession);
			}
			break;
		case FTD_TID_RspQryHostConfig:
			OnRspQryHostConfig(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqUserLogout:
			OnReqUserLogout(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTradeDayChangeTopic:
			OnReqQryTradeDayChange(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryCPUUsageTopic:						/// ת����ѯ��̽������ô��� zhou.jj 20090616
			{
				CFTDReqQryCPUUsageField fieldInfo;
				memset(&fieldInfo, 0, sizeof(fieldInfo));
				FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

				CFTDCSession *tmpSession = g_mObjectIdSession.getObjectIdSession(
						(const char *)fieldInfo.ObjectID);
				if (tmpSession != NULL)
				{
					m_pkgSend.DupPackage((CPackage *)pFTDCPackage);
					memcpy(
						(char *)m_pkgSend.GetFTDCHeader(),
						pFTDCPackage->GetFTDCHeader(),
						sizeof(TFTDCHeader));
					tmpSession->SendRequestPackage(&m_pkgSend);
				}
				else
				{	///session�Ѿ������ڣ�Ӧ�𵽿ͻ��˸ò�ѯ�Ѿ�����������ԭ��Ϊ�����Ѿ��Ͽ�
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryCPUUsageTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);

					CFTDRspInfoField fieldRspInfo;
					fieldRspInfo.ErrorMsg = "��̽�����ӶϿ�";
					fieldRspInfo.ErrorID = ERR_PROBEUNCONNECT;
					FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
					pSession->SendRequestPackage(&m_pkgSend);
				}

				break;
			}

		case FTD_TID_ReqQryDBQueryTopic:	/// ת�����ݿ�SP��ѯ���ɼ�����, zhou.jj 20090706
			{
				CFTDReqQryDBQueryField	fieldInfo;
				memset(&fieldInfo, 0, sizeof(fieldInfo));
				FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

				CFTDCSession *tmpSession = g_mObjectIdSession.getObjectIdSession(
						(const char *)fieldInfo.ObjectID);
				if (tmpSession != NULL)
				{
					m_pkgSend.DupPackage((CPackage *)pFTDCPackage);
					memcpy(
						(char *)m_pkgSend.GetFTDCHeader(),
						pFTDCPackage->GetFTDCHeader(),
						sizeof(TFTDCHeader));
					tmpSession->SendRequestPackage(&m_pkgSend);
				}
				else
				{	///session�Ѿ������ڣ�Ӧ�𵽿ͻ��˸ò�ѯ�Ѿ�����������ԭ��Ϊ�����Ѿ��Ͽ�
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryDBQueryTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);

					CFTDRspInfoField fieldRspInfo;
					fieldRspInfo.ErrorMsg = "��̽�����ӶϿ�";
					fieldRspInfo.ErrorID = ERR_PROBEUNCONNECT;
					FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
					pSession->SendRequestPackage(&m_pkgSend);
				}

				break;
			}

		case FTD_TID_ReqQryTomcatInfoTopic: /// ת��Tomcat��ѯ��JProbe, henchi 20090622
			{
				CFTDReqQryTomcatInfoField fieldInfo;
				memset(&fieldInfo, 0, sizeof(fieldInfo));
				FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

				CFTDCSession *tmpSession = g_mObjectIdSession.getObjectIdSession(
						(const char *)fieldInfo.ObjectID);
				if (tmpSession != NULL)
				{
					m_pkgSend.DupPackage((CPackage *)pFTDCPackage);
					memcpy(
						(char *)m_pkgSend.GetFTDCHeader(),
						pFTDCPackage->GetFTDCHeader(),
						sizeof(TFTDCHeader));
					tmpSession->SendRequestPackage(&m_pkgSend);
				}
				else
				{	///session�Ѿ������ڣ�Ӧ�𵽿ͻ��˸ò�ѯ�Ѿ�����������ԭ��Ϊ�����Ѿ��Ͽ�
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryGeneralFieldTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);

					CFTDRspInfoField fieldRspInfo;
					fieldRspInfo.ErrorMsg = "��̽�����ӶϿ�";
					fieldRspInfo.ErrorID = ERR_PROBEUNCONNECT;
					FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
					pSession->SendRequestPackage(&m_pkgSend);
				}

				break;
			}

		default:
			break;
	}

	return 0;
}

void CCounterConnector::OnReqUserLogout(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqUserLogoutField	fieldInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo))
	{
		printf(
			"\tCAgentConnector::OnReqUserLogout fieldInfo.UserID = %s\n",
			(const char *)fieldInfo.UserID);
		fflush(stdout);
		m_pkgSend.PreparePackage(
				FTD_TID_ReqUserLogout,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

		list<CFTDCSession *>::iterator	it;
		for (it = g_mListAllSession.begin();
			 it != g_mListAllSession.end();
			 it++)
		{
			(*it)->SendRequestPackage(&m_pkgSend);
			m_pkgSend.Pop(FTDCHLEN);
		}
	}
}

void CCounterConnector::OnReqQryTradeDayChange(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryTradeDayChangeField fieldChange;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldChange);

	//....
	if (strcmp(fieldChange.ChangeType.getValue(), CHANGETRADEDAY) == 0)			// ���������մ���
	{
		//1.���ñ��ؽ�������Ϣ
		time_t	timep;
		time(&timep);

		printf(
			"CCounterConnector::OnReqQryTradeDayChange TradeDay [%s]\n",
			g_mTradeDay);
			
		struct tm tm_time;
		LocalTime(&timep, &tm_time);
		sprintf(
			g_mTradeDay,
			"%04d%02d%02d",
			tm_time.tm_year + 1900,
			tm_time.tm_mon + 1,
			tm_time.tm_mday);
		
		printf(
			"CCounterConnector::OnReqQryTradeDayChange TradeDay [%s] Event TradeDay [%s]\n",
			g_mTradeDay,
			fieldChange.NewDate.getValue());

		//strcpy(g_mTradeDay, fieldChange.NewDate.getValue());
		//2.������Ϣת���������¼���̽�롢�ɼ���������
		m_pkgSend.PreparePackage(
				FTD_TID_ReqQryTradeDayChangeTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &fieldChange);

		list<CFTDCSession *>::iterator	it;
		for (it = g_mListAllSession.begin();
			 it != g_mListAllSession.end();
			 it++)
		{
			(*it)->SendRequestPackage(&m_pkgSend);
			m_pkgSend.Pop(FTDCHLEN);
		}
	}
}

void CCounterConnector::OnRspQryHostConfig(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryHostConfigField fieldRspInfo;
	int nRid = pFTDCPackage->GetRequestId();
	if (nRid == 0)
	{
		printf(
			" CAgentServer::OnRspQryHostConfig �����Ӧ��requestID %d\n",
			nRid);
		return;
	}

	CTRID rid;
	g_cProbeToEventReq.getRequestId(rid, nRid, pFTDCPackage->GetChain());

	if (g_pConnector[rid.ConnectId]->GetSession(rid.SessionID))					//�ϲ�Ự��session������
	{
		//////////////////////////////////////////////////////////////////////////
		CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
				&CFTDRspQryHostConfigField::m_Describe);
		while (!itor.IsEnd())
		{
			itor.Retrieve(&fieldRspInfo);
			g_mapFile[CFileDescript(
					string(fieldRspInfo.CfgAttend.getValue()),
					string(fieldRspInfo.CfgLocation.getValue()))] = CFileInfo(
					string(fieldRspInfo.CfgHostName.getValue()),
					string(fieldRspInfo.CfgDataCenter.getValue()));
			itor.Next();
			if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())	//����Ӧ�������
			{
				/// Mod by Henchi, 20110325
								/// ��̽�����Ϊ�ؼ�������̽��������
				//sendRspQryHostConfig(m_pkgSend, (CFTDCSession *)(g_pConnector[rid.ConnectId]->GetSession(rid.SessionID)),(char *)(fieldRspInfo.CfgAttend.getValue()), rid.RequestId);
				sendRspQryHostConfig(
					m_pkgSend,
					(CFTDCSession *)
						(
							g_pConnector[rid.ConnectId]->GetSession(
									rid.SessionID)
						),
					(char *)(fieldRspInfo.CfgName.getValue()),
					rid.RequestId);
			}
		}
	}
}

extern int	getTradeDayTime(char *pTradeDay);
extern char g_mCfgPath[200];	//���������ļ�·��
extern std::map<string, map<string, CDBConnectString> > g_OraclePass;

#define CHECKHOSTCONFIGPKG	if (m_pkgSend.Length() +									   \
								sizeof(CFTDRspQryHostConfigField) > FTDC_PACKAGE_MAX_SIZE) \
	{																					   \
		m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);										   \
		((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);						   \
		printf("-----Send a package!-----\n");											   \
		m_pkgSend.PreparePackage(														   \
				FTD_TID_RspQryHostConfig,												   \
				FTDC_CHAIN_LAST,														   \
				FTD_VERSION);															   \
		m_pkgSend.SetRequestId(nRequestId);												   \
		FTDC_ADD_FIELD(&m_pkgSend, &fieldHostConfig);									   \
	}																					   \
	else																				   \
	{																					   \
		FTDC_ADD_FIELD(&m_pkgSend, &fieldHostConfig);									   \
	}

void sendRspQryHostConfig(
	CFTDCPackage &m_pkgSend,
	CFTDCSession *pSession,
	char *pLocationName,
	DWORD nRequestId)
{
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryHostConfig,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(nRequestId);

	//CFTDReqUserLoginField fieldLogin;
	//memset(&fieldLogin, 0, sizeof(fieldLogin));
	//fieldLogin.UserID = "agent";
	//fieldLogin.Password = "agentpd";
		////20100325 by zhou.jj
		////if (pProxyLocation[0]!='\0')
		////{
		////	fieldLogin.ProtocolInfo = pProxyLocation;
		////} else {
		////	fieldLogin.ProtocolInfo = pCounterLocation;
		////}
	//FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);
	int mReadFirstTime = getTradeDayTime(g_mTradeDay);
	long mHaveRead = 0;
	int mReadTime = 0;

	if (pLocationName)
	{
		CXMLConfig	*pXMLCfg = new CXMLConfig(g_mCfgPath);
		if (pXMLCfg)
		{
			CXMLConfig::CProbeConfig * pProbeCfg = pXMLCfg->GetProbeConfigN(
					pLocationName);
			if (pProbeCfg)
			{
				CFTDRspQryHostConfigField fieldHostConfig;

				///Add by Henchi 20090219
				char szTmp[33];
				sprintf(
					szTmp,
					"%s.%s",
					pProbeCfg->GetSystem(),
					pProbeCfg->GetDataCenter());

				fieldHostConfig.CfgType = HOSTCFG_REQTYPE_HOST;
				fieldHostConfig.CfgName = g_mTradeDay;					// ������
				fieldHostConfig.CfgLocation = pProbeCfg->GetLocation(); // ��ȡ̽���ַ
				fieldHostConfig.CfgHostName = pProbeCfg->GetHostName(); // ��ȡ������
								///Modify by Henchi 20090219, ������Ϣ�����������ĸ�Ϊϵͳ����������ƴ�Ӵ�

				// ��ʽ�� PuDian ��Ϊ NGES.PuDian
				fieldHostConfig.CfgAttend = szTmp;						// ��ȡ��������ϵͳ������������
				CHECKHOSTCONFIGPKG;

#ifdef PRINT_DEBUG
				printf(
					"\nTradeDate :%s\n",
					(const char *)fieldHostConfig.CfgName);
				printf(
					"Location  :%s\n",
					(const char *)fieldHostConfig.CfgLocation);
				printf(
					"HostName  :%s\n",
					(const char *)fieldHostConfig.CfgHostName);
				printf(
					"DataCenter:%s\n",
					(const char *)fieldHostConfig.CfgAttend);
#endif

				// Added by Henchi, 20090624
				map<string, CDBConnectString> &TomcatMap = pProbeCfg->
					GetTomcatMap(); // ��ȡTomcat��Ϣ
				map<string, CDBConnectString>::iterator tomcatMapIt;
				if (TomcatMap.size())
				{
					char szUrl[64];
					for (tomcatMapIt = TomcatMap.begin();
						 tomcatMapIt != TomcatMap.end();
						 tomcatMapIt++)
					{
						memset(szUrl, 0x00, sizeof(szUrl));
						sprintf(
							szUrl,
							"%s:%d",
							tomcatMapIt->second.m_sIpAddr.c_str(),
							tomcatMapIt->second.m_nPort);
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_TOMCAT;						// Tomcat������
						fieldHostConfig.CfgName = tomcatMapIt->first.c_str();					// Tomcat����
						fieldHostConfig.CfgLocation = szUrl;									// Tomcat JMX�������������磺"172.16.94.66:8999"
						fieldHostConfig.CfgHostName = tomcatMapIt->second.m_sUserName.c_str();	// JMX��½�û�
						fieldHostConfig.CfgAttend = tomcatMapIt->second.m_sPassword.c_str();	// JMX��½����
						CHECKHOSTCONFIGPKG;
					}
				}

				map<string, string> &TimerMap = pProbeCfg->GetTimerMap();						// ��ȡ��ʱ��������Ϣ
				map<string, string>::iterator timerMapIt;
				if (TimerMap.size())
				{
					for (timerMapIt = TimerMap.begin();
						 timerMapIt != TimerMap.end();
						 timerMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_TIMER;						// ��ʱ��������
						fieldHostConfig.CfgName = timerMapIt->first.c_str();					// ��ʱ��������
						fieldHostConfig.CfgLocation = "";						// ���ֶ�����
						fieldHostConfig.CfgHostName = "";						// ���ֶ�����
						fieldHostConfig.CfgAttend = timerMapIt->second.c_str(); // ��ʱ��ʱ����(��)
						CHECKHOSTCONFIGPKG;
#ifdef PRINT_DEBUG
						printf(
							"    %-12s --- %s\n",
							timerMapIt->first.c_str(),
							timerMapIt->second.c_str());
#endif
					}
				}

				// Add by Henchi, 20100330
				map<string, string> &DBMappingMap = pProbeCfg->GetDBMappingMap();
				map<string, string> DatabaseMap;

				// Mod by Henchi, 20090709
				map<string, CDBConnectString> &AppSPMap = pProbeCfg->GetAppSPMap();

				// ��ȡ�洢����������Ϣ
				map<string, CDBConnectString>::iterator AppSPMapIt;
				string sDBName = "";

				if (AppSPMap.size())
				{
					char szCursorType[64];
					for (AppSPMapIt = AppSPMap.begin();
						 AppSPMapIt != AppSPMap.end();
						 AppSPMapIt++)
					{
						sprintf(
							szCursorType,
							"%s:%s",
							AppSPMapIt->second.m_sPassword.c_str(),
							DATACENTERAPP);
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_SP;			// �洢���̲���������
						fieldHostConfig.CfgDataCenter = AppSPMapIt->second.
							m_sEnvironment.length()
								> 0 ? AppSPMapIt->second.m_sEnvironment.c_str()
									: "";
						fieldHostConfig.CfgName = AppSPMapIt->second.m_sUserName.c_str();	// �洢���̱���
						fieldHostConfig.CfgLocation = AppSPMapIt->second.m_sIpAddr.c_str(); // �洢���̲���ʱ�䴮
						sDBName = AppSPMapIt->second.m_sAlias;
						if (DBMappingMap.find(sDBName) != DBMappingMap.end())
						{
							sDBName = DBMappingMap[sDBName];			// ת�����ݿ����
						}

						DatabaseMap[sDBName] = sDBName;					// ��ӵ����ݿ�����嵥
						fieldHostConfig.CfgHostName = sDBName.c_str();	// ���ݿ����
						fieldHostConfig.CfgAttend = szCursorType;		// ���ͱ�ʶ:�Ƿ�Ϊ�α�
						CHECKHOSTCONFIGPKG;
					}
				}

				map<string, CDBConnectString> &NodeSPMap = pProbeCfg->
					GetNodeSPMap(); // ��ȡ�洢����������Ϣ
				map<string, CDBConnectString>::iterator NodeSPMapIt;
				if (NodeSPMap.size())
				{
					char szCursorType[64];
					for (NodeSPMapIt = NodeSPMap.begin();
						 NodeSPMapIt != NodeSPMap.end();
						 NodeSPMapIt++)
					{
						sprintf(
							szCursorType,
							"%s:%s",
							NodeSPMapIt->second.m_sPassword.c_str(),
							DATACENTERDBNODE);
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_SP;						// �洢���̲���������
						fieldHostConfig.CfgDataCenter = NodeSPMapIt->second.
							m_sEnvironment.length()
								> 0 ? NodeSPMapIt->second.m_sEnvironment.c_str()
									: "";
						fieldHostConfig.CfgName = NodeSPMapIt->second.m_sUserName.c_str();	// �洢���̱���
						fieldHostConfig.CfgLocation = NodeSPMapIt->second.m_sIpAddr.c_str();	// �洢���̲���ʱ�䴮
						sDBName = NodeSPMapIt->second.m_sAlias;
						if (DBMappingMap.find(sDBName) != DBMappingMap.end())
						{
							sDBName = DBMappingMap[sDBName];			// ת�����ݿ����
						}

						DatabaseMap[sDBName] = sDBName;					// ��ӵ����ݿ�����嵥
						fieldHostConfig.CfgHostName = sDBName.c_str();	// ���ݿ����
						fieldHostConfig.CfgAttend = szCursorType;		// ���ͱ�ʶ:�Ƿ�Ϊ�α�
						CHECKHOSTCONFIGPKG;
					}
				}

				map<string, CDBConnectString> &DBSPMap = pProbeCfg->GetDBSPMap();

				// ��ȡ�洢����������Ϣ
				map<string, CDBConnectString>::iterator DBSPMapIt;
				if (DBSPMap.size())
				{
					char szCursorType[64];
					for (DBSPMapIt = DBSPMap.begin();
						 DBSPMapIt != DBSPMap.end();
						 DBSPMapIt++)
					{
						sprintf(
							szCursorType,
							"%s:%s",
							DBSPMapIt->second.m_sPassword.c_str(),
							DATACENTERDB);
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_SP;	// �洢���̲���������
						fieldHostConfig.CfgDataCenter = DBSPMapIt->second.
							m_sEnvironment.length()
								> 0 ? DBSPMapIt->second.m_sEnvironment.c_str()
									: "";
						fieldHostConfig.CfgName = DBSPMapIt->second.m_sUserName.c_str();	// �洢���̱���
						fieldHostConfig.CfgLocation = DBSPMapIt->second.m_sIpAddr.c_str();	// �洢���̲���ʱ�䴮
						sDBName = DBSPMapIt->second.m_sAlias;
						if (DBMappingMap.find(sDBName) != DBMappingMap.end())
						{
							sDBName = DBMappingMap[sDBName];				// ת�����ݿ����
						}

						DatabaseMap[sDBName] = sDBName;						// ��ӵ����ݿ�����嵥
						fieldHostConfig.CfgHostName = sDBName.c_str();		// ���ݿ����
						fieldHostConfig.CfgAttend = szCursorType;			// ���ͱ�ʶ:�Ƿ�Ϊ�α�
						CHECKHOSTCONFIGPKG;
					}
				}

				map<string, CDBConnectString> &DBLogMap = pProbeCfg->GetDBLogMap();

				// ��ȡDBLog������Ϣ
				map<string, CDBConnectString>::iterator DBLogMapIt;
				if (DBLogMap.size())
				{
					for (DBLogMapIt = DBLogMap.begin();
						 DBLogMapIt != DBLogMap.end();
						 DBLogMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_DBLOG;	// DBLog����������
						fieldHostConfig.CfgDataCenter = DBLogMapIt->second.
							m_sEnvironment.length()
								> 0 ? DBLogMapIt->second.m_sEnvironment.c_str()
									: "";
						fieldHostConfig.CfgName = DBLogMapIt->second.m_sUserName.c_str();	// DBLog��
						fieldHostConfig.CfgLocation = DBLogMapIt->second.m_sIpAddr.c_str(); // DBLog����ʱ�䴮
						sDBName = DBLogMapIt->second.m_sAlias;
						if (DBMappingMap.find(sDBName) != DBMappingMap.end())
						{
							sDBName = DBMappingMap[sDBName];					// ת�����ݿ����
						}

						DatabaseMap[sDBName] = sDBName;							// ��ӵ����ݿ�����嵥
						fieldHostConfig.CfgHostName = sDBName.c_str();			// ���ݿ����
						fieldHostConfig.CfgAttend = "";							// �˴�����
						CHECKHOSTCONFIGPKG;
					}
				}

				map<string, listTDB> &AttrMap = pProbeCfg->GetAttrMap();
				map<string, string> &AttrTimerMap = pProbeCfg->GetAttrTimerMap();
				map<string, listTDB>::iterator	attrMapIt;
				if (AttrMap.size())
				{
					for (attrMapIt = AttrMap.begin();
						 attrMapIt != AttrMap.end();
						 attrMapIt++)
					{
						listTDB &tableinfoList = attrMapIt->second;
						listTDB::iterator listIt;
						for (listIt = tableinfoList.begin();
							 listIt != tableinfoList.end();
							 listIt++)
						{
							fieldHostConfig.CfgType = HOSTCFG_REQTYPE_DBATTR;	// ���ݿ��ض�����Ϣ��
							fieldHostConfig.CfgName = attrMapIt->first.c_str(); // ���ݿ��ض��������磺"dfmt.dfmtLen"
							fieldHostConfig.CfgLocation = AttrTimerMap[attrMapIt->first].c_str();	// ������ʱ��������磺"08:00:00-15:00:00.120,15:00:00-15:20:00.20"
							sDBName = (*listIt).m_sDbName;
							if (DBMappingMap.find(
									sDBName) != DBMappingMap.end())
							{
								sDBName = DBMappingMap[sDBName];						// ת�����ݿ����
							}

							DatabaseMap[sDBName] = sDBName;								// ��ӵ����ݿ�����嵥
							fieldHostConfig.CfgHostName = sDBName.c_str();				// ���ݿ����
							fieldHostConfig.CfgAttend = (*listIt).m_sTableName.c_str(); // ���ݿ�������磺"table1"
							CHECKHOSTCONFIGPKG;

							printf(
								"    %-12s --- %s %s %s \n",
								(const char *)fieldHostConfig.CfgName,
								(const char *)fieldHostConfig.CfgLocation,
								(const char *)fieldHostConfig.CfgHostName,
								(const char *)fieldHostConfig.CfgAttend);
							fflush(stdout);
#ifdef PRINT_DEBUG
#endif
						}
					}
				}

				// Mod by Henchi, 20100330
				if (DatabaseMap.size())
				{
					char szDatabase[512];
					map<string, string>::iterator databaseMapIt;
					for (databaseMapIt = DatabaseMap.begin();
						 databaseMapIt != DatabaseMap.end();
						 databaseMapIt++)
					{
						// Added by Henchi, 20100329
						if (g_mapDBConnectInfo.find(
								databaseMapIt->first) != g_mapDBConnectInfo.end())
						{
							memset(szDatabase, 0x00, sizeof(szDatabase));

							CRequstDBConnectInfo &DBConnectInfo =
								g_mapDBConnectInfo[databaseMapIt->first];

							// ������ݿ�ڵ���������RAC�����ݿ��ӽڵ���
							sprintf(
								szDatabase,
								"%s %s %s %d",
								DBConnectInfo.m_ConnectInfo.m_sInstanceName.c_str(),
								DBConnectInfo.m_ConnectInfo.m_sRacName.c_str(),
								DBConnectInfo.m_ConnectInfo.m_sServerIP.c_str(),
								DBConnectInfo.m_ConnectInfo.m_nServerPort);
							fieldHostConfig.CfgType = HOSTCFG_REQTYPE_DATABASE;			// ���ݿ�������Ϣ��
							fieldHostConfig.CfgName = databaseMapIt->first.c_str();

							// ���ݿ����
							fieldHostConfig.CfgLocation = szDatabase;					// ���ݿ����������磺"monitor1 monitor 172.16.30.124 1521"
							fieldHostConfig.CfgHostName = DBConnectInfo.m_ConnectInfo.m_sUserName.c_str();	// ���ݿ��½�û�
							fieldHostConfig.CfgAttend = DBConnectInfo.m_ConnectInfo.m_sPassword.c_str();	// ���ݿ��½����
							CHECKHOSTCONFIGPKG;

							printf(
								"    %-12s --- %s %s %s \n",
								(const char *)fieldHostConfig.CfgName,
								(const char *)fieldHostConfig.CfgLocation,
								(const char *)fieldHostConfig.CfgHostName,
								(const char *)fieldHostConfig.CfgAttend);
							fflush(stdout);
#ifdef PRINT_DEBUG
#endif
						}
					}
				}

				map<string, CDBConnectString> &SANMap = pProbeCfg->GetSANMap();				// ��ȡSAN������Ϣ
				map<string, CDBConnectString>::iterator SANMapIt;
				if (SANMap.size())
				{
					for (SANMapIt = SANMap.begin();
						 SANMapIt != SANMap.end();
						 SANMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_SAN;						// SAN����������
						fieldHostConfig.CfgName = SANMapIt->second.m_sAlias.c_str();		// SAN����
						fieldHostConfig.CfgLocation = SANMapIt->second.m_sIpAddr.c_str();	// SAN����ʱ�䴮
						fieldHostConfig.CfgHostName = SANMapIt->second.m_sUserName.c_str(); // �ű��ļ�·��
						fieldHostConfig.CfgAttend = "";						// �˴�����
						CHECKHOSTCONFIGPKG;
					}
				}

				map<string, CDBConnectString> &FileCodeMap = pProbeCfg->
					GetFileCodeMap();										// ��ȡ��վ�ļ�У��������Ϣ
				map<string, CDBConnectString>::iterator filecodeMapIt;
				if (FileCodeMap.size())
				{
					for (filecodeMapIt = FileCodeMap.begin();
						 filecodeMapIt != FileCodeMap.end();
						 filecodeMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_WEBSITE;	// ��վ�ļ�У��������
						fieldHostConfig.CfgName = filecodeMapIt->second.m_sAlias.c_str();			// ��У���ļ�·��
						fieldHostConfig.CfgLocation = filecodeMapIt->second.m_sUserName.c_str();	// У���ļ�����·��
						fieldHostConfig.CfgHostName = filecodeMapIt->second.m_sIpAddr.c_str();		// ����ʱ��
						fieldHostConfig.CfgAttend = ""; // ���ֶ�����
						CHECKHOSTCONFIGPKG;
#ifdef PRINT_DEBUG
						printf(
							"    %-40s --- %s %s\n",
							filecodeMapIt->second.m_sAlias.c_str(),
							filecodeMapIt->second.m_sAlias.c_str(),
							filecodeMapIt->second.m_sIpAddr.c_str());
#endif
					}
				}

				map<string, CDBConnectString> &WebsiteCodeMap = pProbeCfg->
					GetWebsiteCodeMap();				// ��ȡ��վ״̬��У��������Ϣ
				map<string, CDBConnectString>::iterator WebsiteCodeMapIt;
				if (WebsiteCodeMap.size())
				{
					for (WebsiteCodeMapIt = WebsiteCodeMap.begin();
						 WebsiteCodeMapIt != WebsiteCodeMap.end();
						 WebsiteCodeMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_WEBSITECODE;						// ��վ״̬��У��������
						fieldHostConfig.CfgName = WebsiteCodeMapIt->second.m_sAlias.c_str();		// ��վ������
						fieldHostConfig.CfgLocation = WebsiteCodeMapIt->second.m_sUserName.c_str(); // ��վ״̬��У��URL
						fieldHostConfig.CfgHostName = WebsiteCodeMapIt->second.m_sIpAddr.c_str();	// ����ʱ��
						fieldHostConfig.CfgAttend = WebsiteCodeMapIt->second.m_sPassword.c_str();	// ��վ�Ϸ�״̬��ʶ��
						CHECKHOSTCONFIGPKG;
#ifdef PRINT_DEBUG
						printf(
							"    %-40s --- %s %s %s \n",
							WebsiteCodeMapIt->second.m_sAlias.c_str(),
							WebsiteCodeMapIt->second.m_sAlias.c_str(),
							WebsiteCodeMapIt->second.m_sIpAddr.c_str(),
							WebsiteCodeMapIt->second.m_sPassword.c_str());
#endif
					}
				}

				map<string, CDBConnectString> &AccessLogMap = pProbeCfg->
					GetAccessLogMap();	// ��ȡ��վ������־������Ϣ
				map<string, CDBConnectString>::iterator AccessLogMapIt;
				if (AccessLogMap.size())
				{
					for (AccessLogMapIt = AccessLogMap.begin();
						 AccessLogMapIt != AccessLogMap.end();
						 AccessLogMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_ACCESSLOG;						// ��վ������־������Ϣ��
						fieldHostConfig.CfgName = AccessLogMapIt->second.m_sAlias.c_str();			// ��վ��������
						fieldHostConfig.CfgLocation = AccessLogMapIt->second.m_sIpAddr.c_str();		// ������־·��
						fieldHostConfig.CfgHostName = AccessLogMapIt->second.m_sUserName.c_str();	// ������־ͳ��ʱ��Ƶ��
						fieldHostConfig.CfgAttend = AccessLogMapIt->second.m_sPassword.c_str();		// ������־ͳ�Ʒ�Χ����
						CHECKHOSTCONFIGPKG;
#ifdef PRINT_DEBUG
						printf(
							"    %-40s --- %s %s %s \n",
							AccessLogMapIt->second.m_sAlias.c_str(),
							AccessLogMapIt->second.m_sIpAddr.c_str(),
							AccessLogMapIt->second.m_sUserName.c_str(),
							AccessLogMapIt->second.m_sPassword.c_str());
#endif
					}
				}

				map<string, string> &ConfigMap = pProbeCfg->GetConfigMap();		// ��ȡ�������������ļ���Ϣ
				map<string, string>::iterator configMapIt;
				if (ConfigMap.size())
				{
					for (configMapIt = ConfigMap.begin();
						 configMapIt != ConfigMap.end();
						 configMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_CFGFILE;		// �������������ļ���
						fieldHostConfig.CfgName = configMapIt->first.c_str();	// �����ļ���
						fieldHostConfig.CfgLocation = configMapIt->second.c_str();

						// �����ļ�·��
						fieldHostConfig.CfgHostName = "";						// ���ֶ�����
						fieldHostConfig.CfgAttend = ""; // ���ֶ�����
						CHECKHOSTCONFIGPKG;
#ifdef PRINT_DEBUG
						printf(
							"    %-12s --- %s\n",
							configMapIt->first.c_str(),
							configMapIt->second.c_str());
#endif
					}
				}

				map<string, string> &AppPathMap = pProbeCfg->GetAppPathMap();	// ��ȡӦ�ý������ڷ�����Ϣ
				map<string, string>::iterator apppathMapIt;
				if (AppPathMap.size())
				{
					for (apppathMapIt = AppPathMap.begin();
						 apppathMapIt != AppPathMap.end();
						 apppathMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_APPROOT;		// Ӧ�ý��̷�����
						fieldHostConfig.CfgName = apppathMapIt->first.c_str();	// Ӧ�ý�����
						fieldHostConfig.CfgLocation = apppathMapIt->second.c_str();

						// Ӧ�ý������ڷ���
						fieldHostConfig.CfgHostName = "";						// ���ֶ�����
						fieldHostConfig.CfgAttend = "";						// ���ֶ�����
						CHECKHOSTCONFIGPKG;
#ifdef PRINT_DEBUG
						printf(
							"    %-12s --- %s\n",
							apppathMapIt->first.c_str(),
							apppathMapIt->second.c_str());
#endif
					}
				}

				map<string, string> &AppLogMap = pProbeCfg->GetAppLogMap(); // ��ȡӦ�ý�����־�ļ���Ϣ
				map<string, string>::iterator applogMapIt;
				if (AppLogMap.size())
				{
					for (applogMapIt = AppLogMap.begin();
						 applogMapIt != AppLogMap.end();
						 applogMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_APPSYSLOG;		// Ӧ�ý�����־��
						fieldHostConfig.CfgName = applogMapIt->first.c_str();		// Ӧ�ý�����
						fieldHostConfig.CfgLocation = applogMapIt->second.c_str();

						// Ӧ�ý�����־�ļ�·��
						mHaveRead = 0;
						mReadTime = 0;

						CFileInfo agent = g_mapFile[CFileDescript(
								string(pProbeCfg->GetLocation()),
								string(applogMapIt->first.c_str()))];
						if (agent.m_pos.empty())
						{
							sprintf(
								(char *)fieldHostConfig.CfgHostName.getValue(),
								"%ld",
								mHaveRead);
						}
						else
						{
							fieldHostConfig.CfgHostName = agent.m_pos.c_str();
						}

						if (!agent.m_time.empty())
						{
							if (atoi(agent.m_time.c_str()) < mReadFirstTime)
							{
								sprintf(
									(char *)fieldHostConfig.CfgAttend.getValue(),
									"%d",
									mReadFirstTime);
							}
							else
							{
								fieldHostConfig.CfgAttend = agent.m_time.c_str();
							}
						}
						else
						{
							sprintf(
								(char *)fieldHostConfig.CfgAttend.getValue(),
								"%d",
								mReadFirstTime);
						}

						CHECKHOSTCONFIGPKG;
#ifdef PRINT_DEBUG
						printf("    %s\n", applogMapIt->second.c_str());
#endif
					}
				}

				map<string, string> &SysLogMap = pProbeCfg->GetSysLogMap();			// ��ȡϵͳ��־�ļ���Ϣ
				map<string, string>::iterator syslogMapIt;
				if (SysLogMap.size())
				{
					for (syslogMapIt = SysLogMap.begin();
						 syslogMapIt != SysLogMap.end();
						 syslogMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_SYSTEMLOG;		// ϵͳ��־��
						fieldHostConfig.CfgName = syslogMapIt->first.c_str();		// ϵͳ��־�ļ���
						fieldHostConfig.CfgLocation = syslogMapIt->second.c_str();

						// ϵͳ��־�ļ�·��
						mHaveRead = 0;
						mReadTime = 0;

						CFileInfo agent = g_mapFile[CFileDescript(
								string(pProbeCfg->GetLocation()),
								string(syslogMapIt->first.c_str()))];
						if (agent.m_pos.empty())
						{
							sprintf(
								(char *)fieldHostConfig.CfgHostName.getValue(),
								"%ld",
								mHaveRead);
						}
						else
						{
							fieldHostConfig.CfgHostName = agent.m_pos.c_str();
						}

						if (!agent.m_time.empty())
						{
							if (atoi(agent.m_time.c_str()) < mReadFirstTime)
							{
								sprintf(
									(char *)fieldHostConfig.CfgAttend.getValue(),
									"%d",
									mReadFirstTime);
							}
							else
							{
								fieldHostConfig.CfgAttend = agent.m_time.c_str();
							}
						}
						else
						{
							sprintf(
								(char *)fieldHostConfig.CfgAttend.getValue(),
								"%d",
								mReadFirstTime);
						}

						CHECKHOSTCONFIGPKG;
#ifdef PRINT_DEBUG
						printf(
							"    %-12s --- %s\n",
							syslogMapIt->first.c_str(),
							syslogMapIt->second.c_str());
#endif
					}
				}

				map<string, string> &KeyFileMap = pProbeCfg->GetKeyFileMap();		// ��ȡ�ؼ��ļ���Ϣ
				map<string, string>::iterator keyfileMapIt;
				if (KeyFileMap.size())
				{
					for (keyfileMapIt = KeyFileMap.begin();
						 keyfileMapIt != KeyFileMap.end();
						 keyfileMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_KEYFILE;			// �ؼ��ļ���
						fieldHostConfig.CfgName = keyfileMapIt->first.c_str();		// �ؼ��ļ���
						fieldHostConfig.CfgLocation = keyfileMapIt->second.c_str();

						// �ؼ��ļ�·��
						mHaveRead = 0;
						mReadTime = 0;

						CFileInfo agent = g_mapFile[CFileDescript(
								string(pProbeCfg->GetLocation()),
								string(keyfileMapIt->first.c_str()))];
						if (agent.m_pos.empty())
						{
							sprintf(
								(char *)fieldHostConfig.CfgHostName.getValue(),
								"%ld",
								mHaveRead);
						}
						else
						{
							fieldHostConfig.CfgHostName = agent.m_pos.c_str();
						}

						if (!agent.m_time.empty())
						{
							if (atoi(agent.m_time.c_str()) < mReadFirstTime)
							{
								sprintf(
									(char *)fieldHostConfig.CfgAttend.getValue(),
									"%d",
									mReadFirstTime);
							}
							else
							{
								fieldHostConfig.CfgAttend = agent.m_time.c_str();
							}
						}
						else
						{
							sprintf(
								(char *)fieldHostConfig.CfgAttend.getValue(),
								"%d",
								mReadFirstTime);
						}

						CHECKHOSTCONFIGPKG;
#ifdef PRINT_DEBUG
						printf(
							"    %-12s --- %s\n",
							keyfileMapIt->first.c_str(),
							keyfileMapIt->second.c_str());
#endif
					}
				}

				map<string, string> &SessionMap = pProbeCfg->GetSessionMap();		// ��ȡ�Ự��־��Ϣ
				map<string, string>::iterator sessionMapIt;
				if (SessionMap.size())
				{
					for (sessionMapIt = SessionMap.begin();
						 sessionMapIt != SessionMap.end();
						 sessionMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_SESSIONLOG;		// �Ự��־��
						fieldHostConfig.CfgName = sessionMapIt->first.c_str();		// �Ự��־�ļ���
						fieldHostConfig.CfgLocation = sessionMapIt->second.c_str();

						// �Ự��־�ļ�·��
						mHaveRead = 0;
						mReadTime = 0;

						CFileInfo agent = g_mapFile[CFileDescript(
								string(pProbeCfg->GetLocation()),
								string(sessionMapIt->first.c_str()))];
						if (agent.m_pos.empty())
						{
							sprintf(
								(char *)fieldHostConfig.CfgHostName.getValue(),
								"%ld",
								mHaveRead);
						}
						else
						{
							fieldHostConfig.CfgHostName = agent.m_pos.c_str();
						}

						if (!agent.m_time.empty())
						{
							if (atoi(agent.m_time.c_str()) < mReadFirstTime)
							{
								sprintf(
									(char *)fieldHostConfig.CfgAttend.getValue(),
									"%d",
									mReadFirstTime);
							}
							else
							{
								fieldHostConfig.CfgAttend = agent.m_time.c_str();
							}
						}
						else
						{
							sprintf(
								(char *)fieldHostConfig.CfgAttend.getValue(),
								"%d",
								mReadFirstTime);
						}

						CHECKHOSTCONFIGPKG;
#ifdef PRINT_DEBUG
						printf(
							"    %-12s --- %s\n",
							sessionMapIt->first.c_str(),
							sessionMapIt->second.c_str());
#endif
					}
				}

				map<string, string> &DFMTMap = pProbeCfg->GetDFMTMap();				// ��ȡdfmt�ļ���Ϣ
				map<string, string>::iterator dfmtMapIt;
				if (DFMTMap.size())
				{
					for (dfmtMapIt = DFMTMap.begin();
						 dfmtMapIt != DFMTMap.end();
						 dfmtMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_DFMTLOG;			// DFMT�ļ���
						fieldHostConfig.CfgName = dfmtMapIt->first.c_str();			// DFMT�ļ���
						fieldHostConfig.CfgLocation = dfmtMapIt->second.c_str();	// DFMT�ļ�·��
						fieldHostConfig.CfgHostName = "";	// ���ֶ�����
						fieldHostConfig.CfgAttend = "";		// ���ֶ�����
						CHECKHOSTCONFIGPKG;
#ifdef PRINT_DEBUG
						printf(
							"    %-12s --- %s\n",
							dfmtMapIt->first.c_str(),
							dfmtMapIt->second.c_str());
#endif
					}
				}

				delete pProbeCfg;
				pProbeCfg = NULL;
			}

			delete pXMLCfg;
			pXMLCfg = NULL;
		}
	}

	pSession->SendRequestPackage(&m_pkgSend);
}
