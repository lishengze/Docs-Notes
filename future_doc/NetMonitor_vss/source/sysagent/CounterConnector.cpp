/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CounterConnector.cpp
///@brief	实现了采集代理连接并处理探针消息的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#include "CounterConnector.h"
#include "CEventProcess.h"

extern int	g_mAgentId;
extern CManageReqIDSession	g_cProbeToEventReq;
extern CManageReqIDSession	g_cEventToProbeReq;
extern CObjectIdSession g_mObjectIdSession;

extern char g_mTradeDay[9];
extern map<CFileDescript, CFileInfo> g_mapFile;
extern list<CFTDCSession *> g_mListAllSession;					// 已连接上的探针、采集代理链接列表
extern CAgentConnector	*g_pConnector[MAXPROBECONFIGNUM];
extern map<string, CRequstDBConnectInfo> g_mapDBConnectInfo;	//用于保存数据库连接名与其连接信息结构的映射
CFTDCSession *g_pCounterFtdSession = NULL;						// FTD下传请求到事件分析的唯一会话
void sendRspQryHostConfig(
		CFTDCPackage &m_pkgSend,
		CFTDCSession *pSession,
		char *pLocationName,
		DWORD nRequestId);
#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pPackOutput; // 数据包输出到文件
#endif

// add by cao.ning
// 系统内部连接关系
extern CSysInternalTopology* g_SysInternalTopology;

// 面向事件计算服务器连接的类
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
	pSession->SetCompressMethod(CRPCM_ZERO);	//设置压缩算法
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
			"\t CCounterConnector::OnSessionConnected 运行出错：采集代理连接事件计算不能出现多个连接，配置出错! %s",
			ctime(&timep));
		printf(
			"\t CCounterConnector::OnSessionConnected 运行出错：断开所有连接，请修改配置信息 %s \n",
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
	// Agent与Event建立链接，更新“系统内部连接”的通告会话
	if (g_SysInternalTopology)
		g_SysInternalTopology->SetSendSessionON(pSession);
}

void CCounterConnector::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
	time_t	timep;
	time(&timep);
	if (g_pCounterFtdSession == (CFTDCSession *)pSession)
	{
		g_pCounterFtdSession = NULL;
	}
	else
	{
		printf(
			"\t CCounterConnector::OnSessionDisconnected 运行出错：采集代理连接事件计算不能出现多个连接，配置出错! %s",
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
	// Agent与Event断开链接，更新“系统内部连接”的通告会话
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
		// 系统内部级联关系
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
		case FTD_TID_ReqQryCPUUsageTopic:						/// 转发查询到探针测试用代码 zhou.jj 20090616
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
				{	///session已经不存在，应答到客户端该查询已经结束，错误原因为连接已经断开
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryCPUUsageTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);

					CFTDRspInfoField fieldRspInfo;
					fieldRspInfo.ErrorMsg = "与探针连接断开";
					fieldRspInfo.ErrorID = ERR_PROBEUNCONNECT;
					FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
					pSession->SendRequestPackage(&m_pkgSend);
				}

				break;
			}

		case FTD_TID_ReqQryDBQueryTopic:	/// 转发数据库SP查询到采集代理, zhou.jj 20090706
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
				{	///session已经不存在，应答到客户端该查询已经结束，错误原因为连接已经断开
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryDBQueryTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);

					CFTDRspInfoField fieldRspInfo;
					fieldRspInfo.ErrorMsg = "与探针连接断开";
					fieldRspInfo.ErrorID = ERR_PROBEUNCONNECT;
					FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
					pSession->SendRequestPackage(&m_pkgSend);
				}

				break;
			}

		case FTD_TID_ReqQryTomcatInfoTopic: /// 转发Tomcat查询到JProbe, henchi 20090622
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
				{	///session已经不存在，应答到客户端该查询已经结束，错误原因为连接已经断开
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryGeneralFieldTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);

					CFTDRspInfoField fieldRspInfo;
					fieldRspInfo.ErrorMsg = "与探针连接断开";
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
	if (strcmp(fieldChange.ChangeType.getValue(), CHANGETRADEDAY) == 0)			// 更换交易日处理
	{
		//1.设置本地交易日信息
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
		//2.将本消息转发至所有下级的探针、采集代理连接
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
			" CAgentServer::OnRspQryHostConfig 错误的应答requestID %d\n",
			nRid);
		return;
	}

	CTRID rid;
	g_cProbeToEventReq.getRequestId(rid, nRid, pFTDCPackage->GetChain());

	if (g_pConnector[rid.ConnectId]->GetSession(rid.SessionID))					//上层会话的session还存在
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
			if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())	//本次应答包结束
			{
				/// Mod by Henchi, 20110325
								/// 以探针别名为关键字请求探针配置项
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
extern char g_mCfgPath[200];	//保存配置文件路径
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
				fieldHostConfig.CfgName = g_mTradeDay;					// 交易日
				fieldHostConfig.CfgLocation = pProbeCfg->GetLocation(); // 获取探针地址
				fieldHostConfig.CfgHostName = pProbeCfg->GetHostName(); // 获取主机名
								///Modify by Henchi 20090219, 附加信息域由数据中心改为系统及数据中心拼接串

				// 形式由 PuDian 改为 NGES.PuDian
				fieldHostConfig.CfgAttend = szTmp;						// 获取主机所在系统及数据中心名
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
					GetTomcatMap(); // 获取Tomcat信息
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
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_TOMCAT;						// Tomcat配置类
						fieldHostConfig.CfgName = tomcatMapIt->first.c_str();					// Tomcat别名
						fieldHostConfig.CfgLocation = szUrl;									// Tomcat JMX服务特征串，如："172.16.94.66:8999"
						fieldHostConfig.CfgHostName = tomcatMapIt->second.m_sUserName.c_str();	// JMX登陆用户
						fieldHostConfig.CfgAttend = tomcatMapIt->second.m_sPassword.c_str();	// JMX登陆密码
						CHECKHOSTCONFIGPKG;
					}
				}

				map<string, string> &TimerMap = pProbeCfg->GetTimerMap();						// 获取定时器配置信息
				map<string, string>::iterator timerMapIt;
				if (TimerMap.size())
				{
					for (timerMapIt = TimerMap.begin();
						 timerMapIt != TimerMap.end();
						 timerMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_TIMER;						// 定时器配置类
						fieldHostConfig.CfgName = timerMapIt->first.c_str();					// 定时器对象名
						fieldHostConfig.CfgLocation = "";						// 此字段留空
						fieldHostConfig.CfgHostName = "";						// 此字段留空
						fieldHostConfig.CfgAttend = timerMapIt->second.c_str(); // 定时器时间间隔(秒)
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

				// 获取存储过程配置信息
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
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_SP;			// 存储过程采样配置类
						fieldHostConfig.CfgDataCenter = AppSPMapIt->second.
							m_sEnvironment.length()
								> 0 ? AppSPMapIt->second.m_sEnvironment.c_str()
									: "";
						fieldHostConfig.CfgName = AppSPMapIt->second.m_sUserName.c_str();	// 存储过程别名
						fieldHostConfig.CfgLocation = AppSPMapIt->second.m_sIpAddr.c_str(); // 存储过程采样时间串
						sDBName = AppSPMapIt->second.m_sAlias;
						if (DBMappingMap.find(sDBName) != DBMappingMap.end())
						{
							sDBName = DBMappingMap[sDBName];			// 转义数据库别名
						}

						DatabaseMap[sDBName] = sDBName;					// 添加到数据库别名清单
						fieldHostConfig.CfgHostName = sDBName.c_str();	// 数据库别名
						fieldHostConfig.CfgAttend = szCursorType;		// 类型标识:是否为游标
						CHECKHOSTCONFIGPKG;
					}
				}

				map<string, CDBConnectString> &NodeSPMap = pProbeCfg->
					GetNodeSPMap(); // 获取存储过程配置信息
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
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_SP;						// 存储过程采样配置类
						fieldHostConfig.CfgDataCenter = NodeSPMapIt->second.
							m_sEnvironment.length()
								> 0 ? NodeSPMapIt->second.m_sEnvironment.c_str()
									: "";
						fieldHostConfig.CfgName = NodeSPMapIt->second.m_sUserName.c_str();	// 存储过程别名
						fieldHostConfig.CfgLocation = NodeSPMapIt->second.m_sIpAddr.c_str();	// 存储过程采样时间串
						sDBName = NodeSPMapIt->second.m_sAlias;
						if (DBMappingMap.find(sDBName) != DBMappingMap.end())
						{
							sDBName = DBMappingMap[sDBName];			// 转义数据库别名
						}

						DatabaseMap[sDBName] = sDBName;					// 添加到数据库别名清单
						fieldHostConfig.CfgHostName = sDBName.c_str();	// 数据库别名
						fieldHostConfig.CfgAttend = szCursorType;		// 类型标识:是否为游标
						CHECKHOSTCONFIGPKG;
					}
				}

				map<string, CDBConnectString> &DBSPMap = pProbeCfg->GetDBSPMap();

				// 获取存储过程配置信息
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
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_SP;	// 存储过程采样配置类
						fieldHostConfig.CfgDataCenter = DBSPMapIt->second.
							m_sEnvironment.length()
								> 0 ? DBSPMapIt->second.m_sEnvironment.c_str()
									: "";
						fieldHostConfig.CfgName = DBSPMapIt->second.m_sUserName.c_str();	// 存储过程别名
						fieldHostConfig.CfgLocation = DBSPMapIt->second.m_sIpAddr.c_str();	// 存储过程采样时间串
						sDBName = DBSPMapIt->second.m_sAlias;
						if (DBMappingMap.find(sDBName) != DBMappingMap.end())
						{
							sDBName = DBMappingMap[sDBName];				// 转义数据库别名
						}

						DatabaseMap[sDBName] = sDBName;						// 添加到数据库别名清单
						fieldHostConfig.CfgHostName = sDBName.c_str();		// 数据库别名
						fieldHostConfig.CfgAttend = szCursorType;			// 类型标识:是否为游标
						CHECKHOSTCONFIGPKG;
					}
				}

				map<string, CDBConnectString> &DBLogMap = pProbeCfg->GetDBLogMap();

				// 获取DBLog配置信息
				map<string, CDBConnectString>::iterator DBLogMapIt;
				if (DBLogMap.size())
				{
					for (DBLogMapIt = DBLogMap.begin();
						 DBLogMapIt != DBLogMap.end();
						 DBLogMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_DBLOG;	// DBLog采样配置类
						fieldHostConfig.CfgDataCenter = DBLogMapIt->second.
							m_sEnvironment.length()
								> 0 ? DBLogMapIt->second.m_sEnvironment.c_str()
									: "";
						fieldHostConfig.CfgName = DBLogMapIt->second.m_sUserName.c_str();	// DBLog名
						fieldHostConfig.CfgLocation = DBLogMapIt->second.m_sIpAddr.c_str(); // DBLog采样时间串
						sDBName = DBLogMapIt->second.m_sAlias;
						if (DBMappingMap.find(sDBName) != DBMappingMap.end())
						{
							sDBName = DBMappingMap[sDBName];					// 转义数据库别名
						}

						DatabaseMap[sDBName] = sDBName;							// 添加到数据库别名清单
						fieldHostConfig.CfgHostName = sDBName.c_str();			// 数据库别名
						fieldHostConfig.CfgAttend = "";							// 此处留空
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
							fieldHostConfig.CfgType = HOSTCFG_REQTYPE_DBATTR;	// 数据库监控对象信息类
							fieldHostConfig.CfgName = attrMapIt->first.c_str(); // 数据库监控对象名，如："dfmt.dfmtLen"
							fieldHostConfig.CfgLocation = AttrTimerMap[attrMapIt->first].c_str();	// 采样定时器配置项，如："08:00:00-15:00:00.120,15:00:00-15:20:00.20"
							sDBName = (*listIt).m_sDbName;
							if (DBMappingMap.find(
									sDBName) != DBMappingMap.end())
							{
								sDBName = DBMappingMap[sDBName];						// 转义数据库别名
							}

							DatabaseMap[sDBName] = sDBName;								// 添加到数据库别名清单
							fieldHostConfig.CfgHostName = sDBName.c_str();				// 数据库别名
							fieldHostConfig.CfgAttend = (*listIt).m_sTableName.c_str(); // 数据库表名，如："table1"
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

							// 添加数据库节点名，用于RAC级数据库子节点监控
							sprintf(
								szDatabase,
								"%s %s %s %d",
								DBConnectInfo.m_ConnectInfo.m_sInstanceName.c_str(),
								DBConnectInfo.m_ConnectInfo.m_sRacName.c_str(),
								DBConnectInfo.m_ConnectInfo.m_sServerIP.c_str(),
								DBConnectInfo.m_ConnectInfo.m_nServerPort);
							fieldHostConfig.CfgType = HOSTCFG_REQTYPE_DATABASE;			// 数据库连接信息类
							fieldHostConfig.CfgName = databaseMapIt->first.c_str();

							// 数据库别名
							fieldHostConfig.CfgLocation = szDatabase;					// 数据库特征串，如："monitor1 monitor 172.16.30.124 1521"
							fieldHostConfig.CfgHostName = DBConnectInfo.m_ConnectInfo.m_sUserName.c_str();	// 数据库登陆用户
							fieldHostConfig.CfgAttend = DBConnectInfo.m_ConnectInfo.m_sPassword.c_str();	// 数据库登陆密码
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

				map<string, CDBConnectString> &SANMap = pProbeCfg->GetSANMap();				// 获取SAN配置信息
				map<string, CDBConnectString>::iterator SANMapIt;
				if (SANMap.size())
				{
					for (SANMapIt = SANMap.begin();
						 SANMapIt != SANMap.end();
						 SANMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_SAN;						// SAN采样配置类
						fieldHostConfig.CfgName = SANMapIt->second.m_sAlias.c_str();		// SAN别名
						fieldHostConfig.CfgLocation = SANMapIt->second.m_sIpAddr.c_str();	// SAN采样时间串
						fieldHostConfig.CfgHostName = SANMapIt->second.m_sUserName.c_str(); // 脚本文件路径
						fieldHostConfig.CfgAttend = "";						// 此处留空
						CHECKHOSTCONFIGPKG;
					}
				}

				map<string, CDBConnectString> &FileCodeMap = pProbeCfg->
					GetFileCodeMap();										// 获取网站文件校验配置信息
				map<string, CDBConnectString>::iterator filecodeMapIt;
				if (FileCodeMap.size())
				{
					for (filecodeMapIt = FileCodeMap.begin();
						 filecodeMapIt != FileCodeMap.end();
						 filecodeMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_WEBSITE;	// 网站文件校验配置类
						fieldHostConfig.CfgName = filecodeMapIt->second.m_sAlias.c_str();			// 待校验文件路径
						fieldHostConfig.CfgLocation = filecodeMapIt->second.m_sUserName.c_str();	// 校验文件所在路径
						fieldHostConfig.CfgHostName = filecodeMapIt->second.m_sIpAddr.c_str();		// 采样时段
						fieldHostConfig.CfgAttend = ""; // 此字段留空
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
					GetWebsiteCodeMap();				// 获取网站状态码校验配置信息
				map<string, CDBConnectString>::iterator WebsiteCodeMapIt;
				if (WebsiteCodeMap.size())
				{
					for (WebsiteCodeMapIt = WebsiteCodeMap.begin();
						 WebsiteCodeMapIt != WebsiteCodeMap.end();
						 WebsiteCodeMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_WEBSITECODE;						// 网站状态码校验配置类
						fieldHostConfig.CfgName = WebsiteCodeMapIt->second.m_sAlias.c_str();		// 网站域名项
						fieldHostConfig.CfgLocation = WebsiteCodeMapIt->second.m_sUserName.c_str(); // 网站状态码校验URL
						fieldHostConfig.CfgHostName = WebsiteCodeMapIt->second.m_sIpAddr.c_str();	// 采样时段
						fieldHostConfig.CfgAttend = WebsiteCodeMapIt->second.m_sPassword.c_str();	// 网站合法状态标识码
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
					GetAccessLogMap();	// 获取网站访问日志配置信息
				map<string, CDBConnectString>::iterator AccessLogMapIt;
				if (AccessLogMap.size())
				{
					for (AccessLogMapIt = AccessLogMap.begin();
						 AccessLogMapIt != AccessLogMap.end();
						 AccessLogMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_ACCESSLOG;						// 网站访问日志配置信息类
						fieldHostConfig.CfgName = AccessLogMapIt->second.m_sAlias.c_str();			// 网站服务器名
						fieldHostConfig.CfgLocation = AccessLogMapIt->second.m_sIpAddr.c_str();		// 访问日志路径
						fieldHostConfig.CfgHostName = AccessLogMapIt->second.m_sUserName.c_str();	// 访问日志统计时段频率
						fieldHostConfig.CfgAttend = AccessLogMapIt->second.m_sPassword.c_str();		// 访问日志统计范围区间
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

				map<string, string> &ConfigMap = pProbeCfg->GetConfigMap();		// 获取主机环境配置文件信息
				map<string, string>::iterator configMapIt;
				if (ConfigMap.size())
				{
					for (configMapIt = ConfigMap.begin();
						 configMapIt != ConfigMap.end();
						 configMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_CFGFILE;		// 主机环境配置文件类
						fieldHostConfig.CfgName = configMapIt->first.c_str();	// 配置文件名
						fieldHostConfig.CfgLocation = configMapIt->second.c_str();

						// 配置文件路径
						fieldHostConfig.CfgHostName = "";						// 此字段留空
						fieldHostConfig.CfgAttend = ""; // 此字段留空
						CHECKHOSTCONFIGPKG;
#ifdef PRINT_DEBUG
						printf(
							"    %-12s --- %s\n",
							configMapIt->first.c_str(),
							configMapIt->second.c_str());
#endif
					}
				}

				map<string, string> &AppPathMap = pProbeCfg->GetAppPathMap();	// 获取应用进程所在分区信息
				map<string, string>::iterator apppathMapIt;
				if (AppPathMap.size())
				{
					for (apppathMapIt = AppPathMap.begin();
						 apppathMapIt != AppPathMap.end();
						 apppathMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_APPROOT;		// 应用进程分区类
						fieldHostConfig.CfgName = apppathMapIt->first.c_str();	// 应用进程名
						fieldHostConfig.CfgLocation = apppathMapIt->second.c_str();

						// 应用进程所在分区
						fieldHostConfig.CfgHostName = "";						// 此字段留空
						fieldHostConfig.CfgAttend = "";						// 此字段留空
						CHECKHOSTCONFIGPKG;
#ifdef PRINT_DEBUG
						printf(
							"    %-12s --- %s\n",
							apppathMapIt->first.c_str(),
							apppathMapIt->second.c_str());
#endif
					}
				}

				map<string, string> &AppLogMap = pProbeCfg->GetAppLogMap(); // 获取应用进程日志文件信息
				map<string, string>::iterator applogMapIt;
				if (AppLogMap.size())
				{
					for (applogMapIt = AppLogMap.begin();
						 applogMapIt != AppLogMap.end();
						 applogMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_APPSYSLOG;		// 应用进程日志类
						fieldHostConfig.CfgName = applogMapIt->first.c_str();		// 应用进程名
						fieldHostConfig.CfgLocation = applogMapIt->second.c_str();

						// 应用进程日志文件路径
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

				map<string, string> &SysLogMap = pProbeCfg->GetSysLogMap();			// 获取系统日志文件信息
				map<string, string>::iterator syslogMapIt;
				if (SysLogMap.size())
				{
					for (syslogMapIt = SysLogMap.begin();
						 syslogMapIt != SysLogMap.end();
						 syslogMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_SYSTEMLOG;		// 系统日志类
						fieldHostConfig.CfgName = syslogMapIt->first.c_str();		// 系统日志文件名
						fieldHostConfig.CfgLocation = syslogMapIt->second.c_str();

						// 系统日志文件路径
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

				map<string, string> &KeyFileMap = pProbeCfg->GetKeyFileMap();		// 获取关键文件信息
				map<string, string>::iterator keyfileMapIt;
				if (KeyFileMap.size())
				{
					for (keyfileMapIt = KeyFileMap.begin();
						 keyfileMapIt != KeyFileMap.end();
						 keyfileMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_KEYFILE;			// 关键文件类
						fieldHostConfig.CfgName = keyfileMapIt->first.c_str();		// 关键文件名
						fieldHostConfig.CfgLocation = keyfileMapIt->second.c_str();

						// 关键文件路径
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

				map<string, string> &SessionMap = pProbeCfg->GetSessionMap();		// 获取会话日志信息
				map<string, string>::iterator sessionMapIt;
				if (SessionMap.size())
				{
					for (sessionMapIt = SessionMap.begin();
						 sessionMapIt != SessionMap.end();
						 sessionMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_SESSIONLOG;		// 会话日志类
						fieldHostConfig.CfgName = sessionMapIt->first.c_str();		// 会话日志文件名
						fieldHostConfig.CfgLocation = sessionMapIt->second.c_str();

						// 会话日志文件路径
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

				map<string, string> &DFMTMap = pProbeCfg->GetDFMTMap();				// 获取dfmt文件信息
				map<string, string>::iterator dfmtMapIt;
				if (DFMTMap.size())
				{
					for (dfmtMapIt = DFMTMap.begin();
						 dfmtMapIt != DFMTMap.end();
						 dfmtMapIt++)
					{
						fieldHostConfig.CfgType = HOSTCFG_REQTYPE_DFMTLOG;			// DFMT文件类
						fieldHostConfig.CfgName = dfmtMapIt->first.c_str();			// DFMT文件名
						fieldHostConfig.CfgLocation = dfmtMapIt->second.c_str();	// DFMT文件路径
						fieldHostConfig.CfgHostName = "";	// 此字段留空
						fieldHostConfig.CfgAttend = "";		// 此字段留空
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
