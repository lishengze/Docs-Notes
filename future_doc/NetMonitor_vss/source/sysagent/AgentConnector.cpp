/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	AgentConnector.cpp
///@brief	实现了采集代理连接并处理探针消息的类
///@history
///20080514	周建军		创建该文件
///20080623	周建军		修订注释
///20080702 晏鹤春		添加读取XML配置信息相关处理
///20081009 周建军		增加支持多级代理处理
///20090219 晏鹤春		向探针发送的配置信息中包含有业务系统名
///20090624 晏鹤春		向探针发送的配置信息中包含有Tomcat配置项
/////////////////////////////////////////////////////////////////////////
#include "AgentConnector.h"
#include "CEventProcess.h"
#include "xmlcfg.h"

//20080908 add by wu.yb for OraclePass
#include "OraclePassClient.h"

#undef SESSIONLOG_TOFILE_DEBUG
extern bool g_bProxyFlag;
extern char g_mTradeDay[9];
extern char pCounterLocation[200];
extern char pProxyLocation[200];
extern CObjectIdSession g_mObjectIdSession;
extern char g_mCfgPath[200];			//保存配置文件路径
extern CRequestInfo *GetOraclePassConf(void);
extern std::map<string, map<string, CDBConnectString> > g_OraclePass;

extern map<string, int> mapMonth;
extern map<string, int> g_mHostIdRlt;	// 保存主机名与应用ID的映射关系
extern map<string, CRequstDBConnectInfo> g_mapDBConnectInfo;	//用于保存数据库连接名与其连接信息结构的映射
extern COraclePassClient g_mOraclePassClient;					//用于保存当前所有BNS服务器IP及端口信息
extern CManageReqIDSession g_cProbeToEventReq;
extern CManageReqIDSession g_cEventToProbeReq;

extern map<CFileDescript, CFileInfo> g_mapFile;

extern CFTDCSession *g_pFtdSession;				// FTD下传到传输型采集代理请求的唯一会话
extern list<CFTDCSession *> g_mListAllSession;	// 已连接上的上传探针、采集代理链接列表
extern CFTDCSession *g_pCounterFtdSession;		// FTD下传请求到事件分析的唯一会话

// add by cao.ning
// 系统内部连接关系
extern CSysInternalTopology* g_SysInternalTopology;

#define DUP_AND_SEND_PKG	m_pkgSend.DupPackage((CPackage *)pFTDCPackage); \
	memcpy(																	\
	(char *)m_pkgSend.GetFTDCHeader(),									\
	pFTDCPackage->GetFTDCHeader(),										\
	sizeof(TFTDCHeader));												\
	if (g_pCounterFtdSession != NULL)										\
{																		\
	g_pCounterFtdSession->SendRequestPackage(&m_pkgSend);				\
}																		\
	else																	\
{																		\
	printf("DUP_AND_SEND_PKG Wrong !\n");								\
}

#define SEND_PKG			if (g_pCounterFtdSession != NULL) \
{														  \
	g_pCounterFtdSession->SendRequestPackage(&m_pkgSend); \
}														  \
	else													  \
{														  \
	printf("DUP_AND_SEND_PKG Wrong !\n");				  \
}

#ifdef PACKAGE_OUTPUT
extern CLogger *g_pPackOutput;					// 数据包输出到文件
#endif
int getTradeDayTime(char *pTradeDay)
{
	char month[3];
	char day[3];
	memset(month, 0, 3);
	memset(day, 0, 3);
	memcpy(month, pTradeDay + 4, 2);
	memcpy(day, pTradeDay + 6, 2);

	int retval = 0;
	retval |= atoi(month) << 24;
	retval |= atoi(day) << 18;
	return retval;
}

///类采集代理连接器的实现
CAgentConnector::CAgentConnector(
	CReactor *pReactor,
	bool bProbeFlag,
	int mConnectId,
	char *pLinkName,
	char *pLinkLocation,
	CEventProcess *pEventProcess) :
CAgentSessionFactory(pReactor, 10)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_mPacketRecvNum = 0;
	memset(&m_mSyslogInfo, 0, sizeof(m_mSyslogInfo));
	m_bProbeFlag = bProbeFlag;
	m_mConnectId = mConnectId;
	m_sLinkName = pLinkName;
	m_sLinkLocation = pLinkLocation;
	m_pEventProcess = pEventProcess;
}

CSession *CAgentConnector::CreateSession(CChannel *pChannel, DWORD dwMark)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
	printf("%s\n", GetLocationName());
#endif

	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);
	return pSession;
}

void CAgentConnector::OnSessionConnected(CSession *pSession)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
	printf(
		"\tCAgentConnector::OnSessionConnected: %s\n",
		pSession->GetChannel()->GetRemoteName());
#endif
	CAgentSessionFactory::OnSessionConnected(pSession);
	g_mListAllSession.push_back((CFTDCSession *)pSession);

	time_t timep;
	time(&timep);
	printf(
		"\t CAgentConnector::OnSessionConnected: %x %s %s",
		(CFTDCSession *)pSession,
		pSession->GetChannel()->GetRemoteName(),
		ctime(&timep));
	fflush(stdout);
	m_pkgSend.PreparePackage(
		FTD_TID_RtnMonitorObjectTopic,
		FTDC_CHAIN_LAST,
		FTD_VERSION);

	CFTDRtnMonitorObjectField connName;
	connName.ObjectName = m_sLinkName.c_str();

	string tmp = m_sLinkLocation.c_str();
	if (m_bProbeFlag)
	{
		tmp.append(",sysprobe");
	}
	else
	{
		tmp.append(",sysagent");
	}

	connName.ObjectID = tmp.c_str();

	FTDC_ADD_FIELD(&m_pkgSend, &connName);
	((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);

	// add by cao.ning
	// 获取下层的探针连接关系信息
	if (g_SysInternalTopology)
		g_SysInternalTopology->OnSessionConnected(pSession);
	return;
}

void CAgentConnector::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	time_t timep;
	time(&timep);
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
	printf(
		"\t CAgentConnector::OnSessionDisconnected CFTDCSession remove %0x %s",
		(CFTDCSession *)pSession,
		ctime(&timep));
	fflush(stdout);
	g_mListAllSession.remove((CFTDCSession *)pSession);
	g_mObjectIdSession.delSession((CFTDCSession *)pSession);

	// add by cao.ning
	// 与探针的直连链路断开
	// 删除该会话对应的链路
	if (g_SysInternalTopology)
		g_SysInternalTopology->OnSessionDisconnected(pSession);

}

int CAgentConnector::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	pFTDCPackage->OutputHeader(g_pPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pPackOutput);
#endif
	if (g_bProxyFlag)	// 直接转发数据包，注意：本条件内部派发数据包应该使用g_pFtdSession会话
	{
		switch (pFTDCPackage->GetTID())
		{
		case FTD_TID_ReqUserLogin:
			OnReqUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryHostConfigTopic:
			OnReqQryHostConfig(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnUpdateSysConfigTopic:	//需要增加主机名所属数据中心关系变更处理
			{
				OnRtnUpdateSysConfig(pFTDCPackage, pSession);
				m_pkgSend.DupPackage((CPackage *)pFTDCPackage);
				memcpy(
					(char *)m_pkgSend.GetFTDCHeader(),
					pFTDCPackage->GetFTDCHeader(),
					sizeof(TFTDCHeader));
				if (g_pFtdSession != NULL)
				{
					g_pFtdSession->SendRequestPackage(&m_pkgSend);
				}

				break;
			}

		// add by cao.ning
		// 系统内部级联关系
		case FTD_TID_RspQrySysInternalTopologyTopic:
			if (g_SysInternalTopology)
				g_SysInternalTopology->OnRspQrySysInternalTopologyTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnSysInternalTopologyTopic:
			if (g_SysInternalTopology)
				g_SysInternalTopology->OnRtnSysInternalTopologyTopic(pFTDCPackage, pSession);
			break;
		default:
			{
				m_pkgSend.DupPackage((CPackage *)pFTDCPackage);
				memcpy(
					(char *)m_pkgSend.GetFTDCHeader(),
					pFTDCPackage->GetFTDCHeader(),
					sizeof(TFTDCHeader));
				if (g_pFtdSession != NULL)
				{
					g_pFtdSession->SendRequestPackage(&m_pkgSend);
				}

				break;
			}
		}
	}
	else
	{	// 分析数据包内容并转发，注意：本条件内部派发数据包应该使用g_pCounterFtdSession会话
		switch (pFTDCPackage->GetTID())
		{
		case FTD_TID_ReqUserLogin:
			OnReqUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryHostConfigTopic:
			OnReqQryHostConfig(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspUserLogin:
			OnRspUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnSyslogInfoTopic:
			OnRtnSyslogInfoTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnUpdateSysConfigTopic:					//需要增加主机名所属数据中心关系变更处理
			OnRtnUpdateSysConfig(pFTDCPackage, pSession);
			DUP_AND_SEND_PKG;
			break;
		case FTD_TID_RtnWarningEventTopic:
			OnRtnWarningEventTopic(pFTDCPackage, pSession);
			DUP_AND_SEND_PKG;
			break;

		// add by cao.ning
		// 系统内部级联关系
		case FTD_TID_RspQrySysInternalTopologyTopic:
			if (g_SysInternalTopology)
				g_SysInternalTopology->OnRspQrySysInternalTopologyTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnSysInternalTopologyTopic:
			if (g_SysInternalTopology)
				g_SysInternalTopology->OnRtnSysInternalTopologyTopic(pFTDCPackage, pSession);
			break;
		default:
			DUP_AND_SEND_PKG;
			break;
		}
	}

	return 0;
}

void CAgentConnector::OnRtnWarningEventTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnWarningEventField fieldInfo;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnWarningEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);
		if (fieldInfo.EventName == EVENT_DBCONNECT_ERROR)			/// 数据库连接断开告警，重新从BNS获取然后发送给当前的pSession
		{
			char buffer[256];
			strcpy(buffer, fieldInfo.EventDes.getValue());

			char *p;

			char *q;
			p = buffer;
			q = strchr(p, ' ');
			if (q != NULL)
			{
				string dbName;
				*q = '\0';
				dbName = p;

				/// 已经分析并保存了数据库别名、实例名、实例的IP列表串，从BNS获取此别名最新的连接信息

				/// Added by Henchi, 20100407
				if (g_mapDBConnectInfo.find(dbName) == g_mapDBConnectInfo.end())
				{
					printf(
						"未在全局映射中找到数据库别名[%s]的关联项，不处理此消息\n",
						dbName.c_str());
				}
				else
				{
					CRequstDBConnectInfo ReqConnectInfo = g_mapDBConnectInfo[
						dbName];
						CDBConnectInfo ConnectInfo = ReqConnectInfo.m_ConnectInfo;
						g_mOraclePassClient.GetOracleAccountInfo(
							ReqConnectInfo.m_RequestInfo,
							ConnectInfo);

						//if (ConnectInfo.IsValid() && ConnectInfo != ReqConnectInfo.m_ConnectInfo)
						/// 由于不确定探针配置项与采集代理是否完全同步，此处暂不判断连接信息是否与全局域中相一致
						/// 一旦从BNS成功获取连接信息，向探针发送该连接配置
						if (ConnectInfo.IsValid())
						{
							ReqConnectInfo.m_ConnectInfo = ConnectInfo;
							g_mapDBConnectInfo.insert(
								make_pair(dbName, ReqConnectInfo)); // 更新全局映射
							char szDatabase[512] = "";
							sprintf(
								szDatabase,
								"%s %s %s %d",
								ConnectInfo.m_sInstanceName.c_str(),
								ConnectInfo.m_sRacName.c_str(),
								ConnectInfo.m_sServerIP.c_str(),
								ConnectInfo.m_nServerPort);

							CFTDRspQryHostConfigField fieldHostConfig;
							fieldHostConfig.CfgType = HOSTCFG_REQTYPE_DATABASE;				// 数据库连接信息类
							fieldHostConfig.CfgName = dbName.c_str();						// 数据库别名
							fieldHostConfig.CfgLocation = szDatabase;						// 数据库特征串，如："monitor1 monitor 172.16.30.124 1521"
							fieldHostConfig.CfgHostName = ConnectInfo.m_sUserName.c_str();	// 数据库登陆用户
							fieldHostConfig.CfgAttend = ConnectInfo.m_sPassword.c_str();	// 数据库登陆密码
							m_pkgSend.PreparePackage(
								FTD_TID_RtnHostConfig,
								FTDC_CHAIN_LAST,
								FTD_VERSION);
							FTDC_ADD_FIELD(&m_pkgSend, &fieldHostConfig);
							pSession->SendRequestPackage(&m_pkgSend);
						}
						else
						{
							printf(
								"未能成功连接到BNS服务器，无法获取数据库[%s]的连接信息项,%s,%s,%s\n",
								dbName.c_str(),
								ReqConnectInfo.m_RequestInfo.szDBName.c_str(),
								ReqConnectInfo.m_RequestInfo.szDBUser.c_str(),
								ReqConnectInfo.m_RequestInfo.szEnv.c_str());
						}
				}
			}
			else
			{
				printf(
					"数据库连接断开告警描述不符合 dbName 描述格式，不处理此消息\n");
			}
		}

		itor.Next();
	}
}

void CAgentConnector::OnReqUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	if (g_bProxyFlag)
	{					// 同上级的传输型采集代理会话
		if (g_pFtdSession != NULL)
		{
			int nRid = g_cProbeToEventReq.putRequestId(
				pSession->GetSessionID(),
				pFTDCPackage->GetRequestId(),
				m_mConnectId);
			m_pkgSend.DupPackage((CPackage *)pFTDCPackage);
			memcpy(
				(char *)m_pkgSend.GetFTDCHeader(),
				pFTDCPackage->GetFTDCHeader(),
				sizeof(TFTDCHeader));
			m_pkgSend.SetRequestId(nRid);
			g_pFtdSession->SendRequestPackage(&m_pkgSend);
		}
	}
	else				// 同上级的连接事件计算服务器会话
	{
		// 应答此登录请求，告诉下面的链接需要的级联信息
		CFTDRtnMonitorObjectField connName;
		FTDC_GET_SINGLE_FIELD(pFTDCPackage, &connName);
		m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspUserLogin,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &connName);

		CFTDRspQryMonitorObjectField rspConnName;
		CXMLConfig *pXMLCfg = new CXMLConfig(g_mCfgPath);
		list<CServerInfo> listInfo;
		if (pXMLCfg->GetAgentConnListByName(
			(char *)connName.ObjectName.getValue(),
			listInfo))
		{
			list<CServerInfo>::iterator iter;
			for (iter = listInfo.begin(); iter != listInfo.end(); iter++)
			{
				if (iter->m_sLocation.length() <= 0)
				{
					printf(
						"Warnning: 未找到%s[%s]所对应的TCP连接串，放弃此对象!\n",
						iter->m_sType.c_str(),
						iter->m_sName.c_str());
				}
				else
				{
					rspConnName.ObjectName = iter->m_sName.c_str();

					string tmp = iter->m_sLocation;
					tmp.append(",");
					tmp.append(iter->m_sType);
					rspConnName.ObjectID = tmp.c_str();
					FTDC_ADD_FIELD(&m_pkgSend, &rspConnName);
				}
			}
		}

		pSession->SendRequestPackage(&m_pkgSend);
		delete pXMLCfg;
	}
}

void CAgentConnector::OnReqQryHostConfig(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	//printf("CAgentConnector::OnReqQryHostConfig:GetLocationName : %s\n",GetLocationName());
	CFTDReqQryHostConfigField fieldConfigInfo;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldConfigInfo))
	{
		printf(
			"\tCAgentConnector::OnReqQryHostConfig [%s][%s][%s]\n",
			(const char *)fieldConfigInfo.CfgType.getValue(),
			(const char *)fieldConfigInfo.CfgName.getValue(),
			(const char *)fieldConfigInfo.CfgAttend.getValue());
		fflush(stdout);
	}

	if (GetProbeFlag()) // 如果连接是探针，就从连接中取得探针的ip地址
	{
		fieldConfigInfo.CfgAttend = GetLocationName();
	}

	if (g_pFtdSession != NULL)
	{					// 同上级的传输型采集代理会话
		int nRid = g_cProbeToEventReq.putRequestId(
			pSession->GetSessionID(),
			pFTDCPackage->GetRequestId(),
			m_mConnectId);
		m_pkgSend.PreparePackage(
			FTD_TID_ReqQryHostConfigTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &fieldConfigInfo);
		m_pkgSend.SetRequestId(nRid);
		g_pFtdSession->SendRequestPackage(&m_pkgSend);
	}
	else if (g_pCounterFtdSession != NULL)			// 同上级的连接事件计算服务器会话
	{
		int nRid = g_cProbeToEventReq.putRequestId(
			pSession->GetSessionID(),
			pFTDCPackage->GetRequestId(),
			m_mConnectId);
		m_pkgSend.PreparePackage(
			FTD_TID_ReqQryHostConfigTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &fieldConfigInfo);
		m_pkgSend.SetRequestId(nRid);
		g_pCounterFtdSession->SendRequestPackage(&m_pkgSend);
	}
	else
	{
		// 同采集代理的连接没有建立,应答错误信息到下级的探针或采集代理
		m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryHostConfig,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

		CFTDRspInfoField rspInfoField;
		rspInfoField.ErrorID = 1;
		rspInfoField.ErrorMsg = "后续连接没有建立";
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}

	return;
}

void CAgentConnector::OnReqUserLogout(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqUserLogoutField fieldInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo))
	{
		printf(
			"\tCAgentConnector::OnReqUserLogout fieldInfo.UserID = %s\n",
			(const char *)fieldInfo.UserID);
		fflush(stdout);
	}
}

void CAgentConnector::OnRtnUpdateSysConfig(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnUpdateSysConfigField fieldInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnUpdateSysConfigField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);
		if (strcmp(
			fieldInfo.UpdateType.getValue(),
			UPDATESYSCONFIG_HOSTIDAPPID) == 0)		//业务ID与主机ID影射关系
		{
			g_mObjectIdSession.addObjectIdSession(
				fieldInfo.NewValue.getValue(),
				pSession);						//业务ID
			if (strstr(
				fieldInfo.NewValue.getValue(),
				DOTDATACENTERTOMCATDOT) == NULL)
			{
				g_mObjectIdSession.addObjectIdSession(
					fieldInfo.OldValue.getValue(),
					pSession);
			}
		}
		else if (strcmp(
			fieldInfo.UpdateType.getValue(),
			UPDATESYSCONFIG_HOSTNAME) == 0)	//主机名变更
		{
			g_mObjectIdSession.addObjectIdSession(
				fieldInfo.NewValue.getValue(),
				pSession);
		}

		itor.Next();
	}
}

void CAgentConnector::OnRspUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)						//探针的登录应答
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif

	CFTDRspInfoField fieldRspInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldRspInfo))
	{
		printf(
			"\tCAgentConnector::OnRspUserLogin fieldRspInfo.ErrorMsg = %s\n",
			(const char *)fieldRspInfo.ErrorMsg);
		fflush(stdout);
	}
}

void CAgentConnector::SetCommPhaseNo(WORD wCommPhaseNo)
{
}

WORD CAgentConnector::GetSequenceSeries(void)	//流编号
{
	return FLOWSEQUENCEDAEMON;
}

DWORD CAgentConnector::GetReceivedCount(void)	//收到的包个数
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
	return m_mPacketRecvNum;
}

#ifdef SESSIONLOG_TOFILE_DEBUG
int g_FileSize = 0;
#endif
void CAgentConnector::OnRtnSyslogInfoTopic(CFTDCPackage *pFTDCPackage)
{
	/*
	CFTDSysFileAccessInfoField fieldAccessInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldAccessInfo))
	{
	m_pFiler.WriteKeyValue((char *)fieldAccessInfo.ObjectID.getValue(),(long)fieldAccessInfo.FileSize.getValue(), (int)fieldAccessInfo.FileTime.getValue());
	}
	*/
	CFTDRtnSyslogInfoField fieldSyslogInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldSyslogInfo))
	{
		char *p = (char *)fieldSyslogInfo.ObjectID.getValue();

		if (strcmp(
			p + strlen(fieldSyslogInfo.ObjectID.getValue()) - strlen(
			HOSTATTRAPPLOG),
			HOSTATTRAPPLOG) == 0)
		{
			CFTDSysFileAccessInfoField fieldAccessInfo;
			char *q = strchr(p, '.');
			if (q == NULL)
			{
				printf(
					"收到格式错误的数据包 %s %d %d\n",
					(const char *)fieldAccessInfo.ObjectID,
					(const int)fieldAccessInfo.FileSize,
					(const int)fieldAccessInfo.FileTime);
				fflush(stdout);
				return;
			}

			q++;
			q = strchr(q, '.');
			if (q == NULL)
			{
				printf(
					"收到格式错误的数据包 %s %d %d\n",
					(const char *)fieldAccessInfo.ObjectID,
					(const int)fieldAccessInfo.FileSize,
					(const int)fieldAccessInfo.FileTime);
				fflush(stdout);
				return;
			}

			char mbuffer[40];
			memset(mbuffer, 0, 40);
			memcpy(mbuffer, p, MIN(39, (q - p)));
			OnRtnSyslogInfoApplog(pFTDCPackage, mbuffer);
			if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldAccessInfo))
			{
				m_pkgSend.PreparePackage(
					FTD_TID_RtnSyslogInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &fieldAccessInfo);
				SEND_PKG;
			}

			return;
		}
		else if (strcmp(
			p + strlen(fieldSyslogInfo.ObjectID.getValue()) - strlen(
			HOSTATTRSESSIONLOG),
			HOSTATTRSESSIONLOG) == 0)
		{
			DUP_AND_SEND_PKG;
			return;
		}
		else if (strcmp(
			p + strlen(fieldSyslogInfo.ObjectID.getValue()) - strlen(
			HOSTATTRSYSLOG),
			HOSTATTRSYSLOG) == 0)
		{
			DUP_AND_SEND_PKG;
			return;
		}
		else if (strcmp(
			p + strlen(fieldSyslogInfo.ObjectID.getValue()) - strlen(
			HOSTATTRKEYFILE),
			HOSTATTRKEYFILE) == 0)
		{
			DUP_AND_SEND_PKG;
			return;
		}
		else
		{
			printf(
				"\t CEventSubscriber::OnRtnSyslogInfoTopic Recv unknown Package! %s\n",
				p);
			fflush(stdout);
		}
	}
}

//#define PRINT_DEBUG
#ifdef SESSIONLOG_TOFILE_DEBUG
FILE *g_testfp = NULL;
#endif
void CAgentConnector::OnRtnSyslogInfoApplog(
	CFTDCPackage *pFTDCPackage,
	char *pDataCenter)
{
	char *mMonth;

	char *mDay;

	char *mHour;
	char *mHost;
	char *mProg;
	char *mSeq;
	char *mPar;
	char *mVal;
	int mGlobalSeq = 0;

	CFTDRtnSyslogInfoField fieldSyslogInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnSyslogInfoField::m_Describe);

	CFTDRtnObjectAttrField mObjectAttrValue;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldSyslogInfo);

		char *p;

		char *q;

		char *r;
		int i = 0, fi = 0;
		p = (char *)fieldSyslogInfo.FileContent.getValue();
		q = m_mContentBuf;
#ifdef SESSIONLOG_TOFILE_DEBUG
		//printf("CAgentConnector::OnRtnSyslogInfoApplog:fieldSyslogInfo.FileContent [==%s==]\n",p);
		if (g_testfp == NULL)
		{
			g_testfp = fopen("d:\\recv.log", "w");
		}

		int tt = fwrite(
			(char *)fieldSyslogInfo.FileContent.getValue(),
			1,
			(const int)fieldSyslogInfo.ContLen,
			g_testfp);
		fflush(g_testfp);
#endif
		while (i < (const int)fieldSyslogInfo.ContLen)
		{
			while ((*p != '\n') && (i < (const int)fieldSyslogInfo.ContLen))
			{
				*q = *p;
				q++;
				p++;
				i++;
			}

			*q = '\0';
			p++;
			q++;
			i++;
			q = m_mContentBuf;

			/// Mod by Henchi, 20110325
			/// 当日志行字节超过800时,后续数据可能无法匹配到时期时间等日志头信息.
			/// 这种数据应直接丢弃,避免后续处理异常.
			/// 此处添加简单的日志头信息判断
			if (m_mContentBuf[0] != NULL
				&&	(
				(
				m_mContentBuf[15] == ' '
				&&	m_mContentBuf[12] == ':'
				&&	m_mContentBuf[9] == ':'
				)
				||	(
				m_mContentBuf[16] == ' '
				&&	m_mContentBuf[13] == ':'
				&&	m_mContentBuf[10] == ':'
				)
				))
			{
				// 日志格式 May 22 15:28:14 kf4640 tkernel 1[15687]: OrderSize 4
#ifdef SESSIONLOG_TOFILE_DEBUG
				printf("m_mContentBuf:[--%s--]\n", m_mContentBuf);
#endif
				mMonth = m_mContentBuf;
				mDay = strchr(m_mContentBuf, ' ');
				if (mDay == NULL)
				{
					continue;
				}

				*mDay = '\0';
				mDay++;
				mHour = strchr(mDay, ' ');
				if (mHour == NULL)
				{
					continue;
				}

				*mHour = '\0';
				mHour++;
				mHost = strchr(mHour, ' ');
				if (mHost == NULL)
				{
					continue;
				}

				*mHost = '\0';
				mHost++;
				mProg = strchr(mHost, ' ');
				if (mProg == NULL)
				{
					continue;
				}

				*mProg = '\0';
				mProg++;
				mSeq = strchr(mProg, ' ');
				if (mSeq == NULL)
				{
					continue;
				}

				*mSeq = '\0';
				mSeq++;
				mPar = strchr(mSeq, ' ');
				if (mPar == NULL)
				{
					continue;
				}

				*mPar = '\0';
				mPar++;
				mVal = strchr(mPar, ' ');
				if (mVal == NULL)
				{
					continue;
				}

				*mVal = '\0';
				mVal++;


				/// Mod by Henchi, 20140625
				/// CFTDRtnSyslogInfoField 结构中的AttrType字段将携带配置的应用名，如：arb 、 tkernel.1
				/// 当遇到配置应用名中不包含标号内容信息时，解析日志也不分析其中的启动参数
				if (strchr((char *)fieldSyslogInfo.AttrType.getValue(), '.') == NULL)
				{
					mGlobalSeq = 0;
				}
				else
				{
					r = strchr(mSeq, '[');
					if (r != NULL)
					{
						*r = '\0';
						mGlobalSeq = atoi(mSeq);
					}
					else
					{
						mGlobalSeq = 0;
					}
				}

				getDateFromMonDay(
					(char *)mObjectAttrValue.MonDate.getValue(),
					atoi(g_mTradeDay),
					mapMonth[mMonth],
					atoi(mDay));

				if (mGlobalSeq == 0)
				{
					sprintf(
						(char *)mObjectAttrValue.ObjectID.getValue(),
						"%s.%s.%s",
						pDataCenter,
						DATACENTERAPP,
						mProg);
				}
				else if (mGlobalSeq < 0)	// mGlobalSeq 小于0，根据主机名识别ID编号
				{
					sprintf(
						(char *)mObjectAttrValue.ObjectID.getValue(),
						"%s.%s.%s.%d",
						pDataCenter,
						DATACENTERAPP,
						mProg,
						g_mHostIdRlt[mHost]);
				}
				else if (mGlobalSeq > 0)
				{
					sprintf(
						(char *)mObjectAttrValue.ObjectID.getValue(),
						"%s.%s.%s.%d",
						pDataCenter,
						DATACENTERAPP,
						mProg,
						mGlobalSeq);
				}

				if (strcmp(mPar, "event") == 0)
				{

					char * pEventDes = strchr(mVal, ' ');

					if (pEventDes != NULL)
					{
						*pEventDes = '\0';
						pEventDes++;
					}

#if 0
					/// Added by Henchi, 20150327
					/// 丢弃非核心业务时段的业务事件，以避免因过量异常日志事件造成的数据拥塞
					if ((strcmp(mHour, "02:45:00") < 0
						|| (strcmp(mHour, "07:45:00") > 0
						&& strcmp(mHour, "16:45:00") < 0)
						|| strcmp(mHour, "19:45:00") >0
						) ||
						(strncmp(mVal, "Redo", strlen("Redo")) == 0 ||
						strncmp(mVal, "LoginSuccess", strlen("LoginSuccess")) == 0)
						)
#endif
					{
						/// Added by Henchi, 20150327
						/// 增加事件计数功能，对同一对象相同时间内同名事件数量作限制，超出的丢弃
						/// 20150101 10:10:00 TRADE.PuDian.app.tkernel.1 XTP
						char szTmp[1024];
						sprintf(szTmp, "%s %s %s %s",
							(char *)mObjectAttrValue.MonDate.getValue(),
							mHour,
							(char *)mObjectAttrValue.ObjectID.getValue(),
							mVal
							);
						/// 暂时按分钟计数，将秒数位置0
						szTmp[15] = '0';
						szTmp[16] = '0';

						/// Mod by Henchi, 20150409
						/// 改为仅过滤多余的"XTP"和"InternalError"事件
						if ((strncmp(mVal, "XTP", strlen("XTP")) == 0 ||
							strncmp(mVal, "InternalError", strlen("InternalError")) == 0) && !ValidEvent(szTmp))
						{
							continue;
						}

						///增加事件处理
						m_pEventProcess->putEventReport(
							(char *)mObjectAttrValue.ObjectID.getValue(),
							(char *)mObjectAttrValue.MonDate.getValue(),
							mHour,
							mVal,
							pEventDes
							);

						///针对行情登录信息特殊处理
						if (strcmp(mProg, "mdkernel") == 0)
						{
							if (strcmp(mVal, "MdLogin") == 0)
							{
								m_pEventProcess->processMdLoginSuccess(pDataCenter, mProg, mGlobalSeq, pEventDes);
							}
							else if (strcmp(mVal, "MdLogout") == 0)
							{
								m_pEventProcess->processMdLogOutSuccess(
							  	pDataCenter,
							  	mProg,
							  	mGlobalSeq,
							  	pEventDes);
							}
						}
						continue;
					}
				}

				mObjectAttrValue.MonTime = mHour;
				mObjectAttrValue.AttrType = mPar;
				mObjectAttrValue.AttrValue = mVal;
				mObjectAttrValue.ValueType = 0;

				// 监控对象 监控时间 监控指标 监控值
				m_pkgSend.PreparePackage(
					FTD_TID_RtnObjectAttrTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &mObjectAttrValue);
				SEND_PKG;
			}
		}				//while (i<(const int)fieldSyslogInfo.ContLen) end;

		itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}					// while (!itor.IsEnd()) end
}

void CAgentConnector::OnRtnSyslogInfoSlog(
	CFTDCPackage *pFTDCPackage,
	char *pDataCenter)
{
#ifdef SESSIONLOG_TOFILE_DEBUG
	int i = 0;
	CFTDRtnSyslogInfoField fieldSyslogInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnSyslogInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		i++;
		itor.Retrieve(&fieldSyslogInfo);
#ifdef SESSIONLOG_TOFILE_DEBUG
		//printf("CAgentConnector::OnRtnSyslogInfoApplog:fieldSyslogInfo.FileContent [==%s==]\n",p);
		if (g_testfp == NULL)
		{
			g_testfp = fopen("d:\\recv.log", "wb");
		}

		int tt = fwrite(
			(char *)fieldSyslogInfo.FileContent.getValue(),
			1,
			(const int)fieldSyslogInfo.ContLen,
			g_testfp);
		fflush(g_testfp);
#endif
		itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}					// while (!itor.IsEnd()) end
#endif
}

void CAgentConnector::OnRtnSyslogInfoSyslog(
	CFTDCPackage *pFTDCPackage,
	char *pDataCenter)
{
#ifdef PRINT_DEBUG
	int i = 0;
	CFTDRtnSyslogInfoField fieldSyslogInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnSyslogInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		i++;
		itor.Retrieve(&fieldSyslogInfo);
		itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}					// while (!itor.IsEnd()) end
#endif
}

void CAgentConnector::OnRtnSyslogInfoKeyfile(
	CFTDCPackage *pFTDCPackage,
	char *pDataCenter)
{
#ifdef PRINT_DEBUG
	int i = 0;
	CFTDRtnSyslogInfoField fieldSyslogInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnSyslogInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		i++;
		itor.Retrieve(&fieldSyslogInfo);
		itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}					// while (!itor.IsEnd()) end
#endif
}

//#define PRINT_DEBUG
void CAgentConnector::HandleMessage(CFTDCPackage *pFTDCPackage)
{
	switch (pFTDCPackage->GetTID())
	{
#ifdef PRINT_DEBUG
	case FTD_TID_RtnNetworkInfoTopic:
		printf("recv package network\n");
		break;
#endif
	case FTD_TID_RtnSyslogInfoTopic:
#ifdef PACKAGE_OUTPUT
		pFTDCPackage->OutputHeader(g_pPackOutput);
		FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pPackOutput);
#endif
		OnRtnSyslogInfoTopic(pFTDCPackage);
		break;
	default:
		break;
	}
}
