/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	EventCounterServer.cpp
///@brief	实现了事件计算服务器监听采集代理连接处理的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#include "AgentServer.h"

extern int	g_mAgentId;
extern CManageReqIDSession	g_cProbeToEventReq;
extern CManageReqIDSession	g_cEventToProbeReq;
extern CObjectIdSession g_mObjectIdSession;

extern char g_mTradeDay[9];
extern CAgentConnector	*g_pConnector[MAXPROBECONFIGNUM];

// add by cao.ning
// 系统内部连接关系
extern CSysInternalTopology* g_SysInternalTopology;

map<CFileDescript, CFileInfo> g_mapFile;
CFTDCSession *g_pFtdSession = NULL;			// FTD下传请求到传输型采集代理的唯一会话
list<CFTDCSession *> g_mListAllSession;		// 已连接上的探针、采集代理链接列表
#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pPackOutput;				// 数据包输出到文件
#endif
CAgentServer::CAgentServer(CReactor *pReactor) :
	CAgentSessionFactory(pReactor, 1)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
}

int CAgentServer::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
	printf(
		"\tCEventCounterServer::receive package %0x\n",
		pFTDCPackage->GetTID());
#endif
#ifdef PACKAGE_OUTPUT
	pFTDCPackage->OutputHeader(g_pPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pPackOutput);
#endif
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_RtnMonitorObjectTopic:
			{
				CFTDRtnMonitorObjectField connName;
				FTDC_GET_SINGLE_FIELD(pFTDCPackage, &connName);
				m_pkgSend.PreparePackage(
						FTD_TID_ReqUserLogin,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &connName);
				pSession->SendRequestPackage(&m_pkgSend);
				m_sUpLinkName = connName.ObjectName.getValue();

				char *p = (char *)connName.ObjectID.getValue();
				p = strrchr(p, ',');
				if (p != NULL)
				{
					*p = '\0';
				}

				m_sUpLinkLocation = connName.ObjectID.getValue();
				break;
			}

		// add by cao.ning
		// 系统内部级联关系
		case FTD_TID_ReqQrySysInternalTopologyTopic:
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
		case FTD_TID_RspUserLogin:
			OnRspUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTradeDayChangeTopic:
			OnReqQryTradeDayChange(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryCPUUsageTopic:	/// 转发查询到探针测试用代码 zhou.jj 20090616
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

		case FTD_TID_ReqQryDBQueryTopic:	///  转发数据库SP查询到采集代理, zhou.jj 20090706
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
				{					///session已经不存在，应答到客户端该查询已经结束，错误原因为连接已经断开
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

		case FTD_TID_RtnHostConfig: /// 主机采集配置变更广播包
			{
				m_pkgSend.DupPackage((CPackage *)pFTDCPackage);
				memcpy(
					(char *)m_pkgSend.GetFTDCHeader(),
					pFTDCPackage->GetFTDCHeader(),
					sizeof(TFTDCHeader));

				list<CFTDCSession *>::iterator	it;
				for (it = g_mListAllSession.begin();
					 it != g_mListAllSession.end();
					 it++)
				{
					(*it)->SendRequestPackage(&m_pkgSend);
					m_pkgSend.Pop(FTDCHLEN);
				}
			}

		default:
			break;
	}

	return 0;
}

CSession *CAgentServer::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);

	/// Added by Henchi, 20120309
	pSession->SetCompressMethod(CRPCM_ZERO);	//设置压缩算法
	return pSession;
}

void CAgentServer::OnSessionConnected(CSession *pSession)
{
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CAgentServer::OnSessionConnected: %0x\n",
		ctime(&timep),
		(CFTDCSession *)pSession);
	fflush(stdout);
	CAgentSessionFactory::OnSessionConnected(pSession);
	if (g_pFtdSession == NULL)
	{
		g_pFtdSession = (CFTDCSession *)pSession;
	}
	else
	{
		printf(
			"\t g_pFtdSession %0x pSession %0x 运行出错： %s",
			g_pFtdSession,
			(CFTDCSession *)pSession,
			ctime(&timep));
		printf(
			"\t CAgentServer::OnSessionConnected 运行出错：RemoteCommonName %s %s \n",
			pSession->GetChannel()->GetRemoteCommonName(),
			ctime(&timep));
		printf(
			"\t CAgentServer::OnSessionConnected 运行出错：RemoteName %s %s \n",
			pSession->GetChannel()->GetRemoteName(),
			ctime(&timep));
		printf(
			"\t CAgentServer::OnSessionConnected 运行出错：传输型采集代理下传不能出现多个连接，配置出错，断开所有下传连接! %s ",
			ctime(&timep));
		fflush(stdout);

		//g_pFtdSession = (CFTDCSession * )pSession;
		// by zhou.jj 20110111 12:32:00 出现下传多个连接则主动断开所有下传连接
		DisconnectAll(0);
		g_pFtdSession = NULL;
		return;
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
	// 对于传输型中转代理，使用AgentServer作为上传会话
	if (g_SysInternalTopology)
		g_SysInternalTopology->SetSendSessionON(pSession);
}

void CAgentServer::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CAgentServer::OnSessionDisconnected: %0x\n",
		ctime(&timep),
		(CFTDCSession *)pSession);
	fflush(stdout);
	CSessionFactory::OnSessionDisconnected(pSession, nReason);						// 子类调用父类处理连接断开事件
	if (g_pFtdSession == (CFTDCSession *)pSession)
	{
		g_pFtdSession = NULL;
	}
	else
	{
		printf(
			"\t g_pFtdSession %0x pSession %0x 运行出错：关闭连接时出现多个连接，配置出错! %s",
			g_pFtdSession,
			(CFTDCSession *)pSession,
			ctime(&timep));
		printf("\t 程序退出，请修改配置信息 %s\n", ctime(&timep));
		fflush(stdout);
		return;

		//exit(0);
	}

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
	// 对于传输型中转代理，使用AgentServer作为上传会话
	if (g_SysInternalTopology)
		g_SysInternalTopology->SetSendSessionOFF();
}

void CAgentServer::OnReqUserLogout(
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

extern CAgentConnector	*g_pConnector[MAXPROBECONFIGNUM];
extern SysReactor g_cReactor;
extern CEventProcess *pEventProcess;

void CAgentServer::OnRspUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnMonitorObjectField rtnConnName;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rtnConnName))
	{
		printf(
			"\tCAgentServer::OnRspUserLogin  %s %s\n",
			(const char *)rtnConnName.ObjectID,
			(const char *)rtnConnName.ObjectName);
		fflush(stdout);

		if (strcmp(
				rtnConnName.ObjectName.getValue(),
			m_sUpLinkName.c_str()) == 0)											//接收到的是此节点的采集信息
		{
			CFTDRspQryMonitorObjectField rspMBfield;
			CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
					&CFTDRspQryMonitorObjectField::m_Describe);
			while (!itor.IsEnd())
			{
				itor.Retrieve(&rspMBfield);

				printf(
					"\tCAgentServer::OnRspUserLogin:连接串=%s 别名=%s \n",
					(const char *)rspMBfield.ObjectID,
					(const char *)rspMBfield.ObjectName);
				fflush(stdout);

				char *pLocation = (char *)rspMBfield.ObjectID.getValue();
				char *pType = strrchr(pLocation, ',');
				if (pType != NULL)
				{
					*pType = '\0';
					pType++;

					bool bCreateFlag = true;

					for (int i = 0; i < MAXPROBECONFIGNUM; i++)
					{
						if (g_pConnector[i] != NULL)
						{
							if (strcmp(
									rspMBfield.ObjectName.getValue(),
								g_pConnector[i]->m_sLinkName.c_str()) == 0)
							{
								printf(
									"连接已经建立,连接别名为 %s %s %s\n",
									rspMBfield.ObjectName.getValue(),
									pLocation,
									pType);
								if (strcmp(
										pLocation,
									g_pConnector[i]->
										m_sLinkLocation.c_str()) == 0)
								{
									bCreateFlag = false;
									printf(
										"连接已经建立,连接别名和连接串均相同 %s %s %s\n",
										rspMBfield.ObjectName.getValue(),
										pLocation,
										pType);
								}
								else
								{
									printf(
										"连接已经建立,但是连接串不同 %s %s %s 之前连接串 %s\n",
										rspMBfield.ObjectName.getValue(),
										pLocation,
										pType,
										g_pConnector[i]->m_sLinkLocation.
											c_str());
									delete g_pConnector[i];
									g_pConnector[i] = NULL;
								}
							}
						}
					}

					for (int i = 0; i < MAXPROBECONFIGNUM && bCreateFlag; i++)
					{
						if (g_pConnector[i] == NULL)
						{
							if (strcmp(pType, "sysagent") == 0)
							{
								g_pConnector[i] = new CAgentConnector(
										&g_cReactor,
										false,
										i,
										(char *)(rspMBfield.ObjectName.getValue()),
										pLocation,
										pEventProcess);
							}
							else
							{
								g_pConnector[i] = new CAgentConnector(
										&g_cReactor,
										true,
										i,
										(char *)(rspMBfield.ObjectName.getValue()),
										pLocation,
										pEventProcess);
							}

							g_pConnector[i]->RegisterConnecter(pLocation);
							g_pConnector[i]->Start();
							break;
						}
						else if (i == MAXPROBECONFIGNUM - 1)
						{
							printf("OnRspUserLogin 连接超过最大限制,退出!!\n");
							break;
						}
					}
				}

				itor.Next();
				if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())	// 本次用户登录应答结束
				{
					;
				}
			}
		}
		else	//接收到的信息应该转发给请求者
		{
			int nRid = pFTDCPackage->GetRequestId();
			if (nRid == 0)
			{
				printf(
					" CAgentServer::OnRspUserLogin 错误的应答requestID %d\n",
					nRid);
				return;
			}

			CTRID rid;
			g_cProbeToEventReq.getRequestId(
					rid,
					nRid,
					pFTDCPackage->GetChain());
			m_pkgSend.PreparePackage(
					FTD_TID_RspUserLogin,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.DupPackage((CPackage *)pFTDCPackage);
			memcpy(
				(char *)m_pkgSend.GetFTDCHeader(),
				pFTDCPackage->GetFTDCHeader(),
				sizeof(TFTDCHeader));
			m_pkgSend.SetRequestId(rid.RequestId);

			if ((g_pConnector[rid.ConnectId]->GetSession(rid.SessionID)) != NULL)
			{
				(
					(CFTDCSession *)
						(g_pConnector[rid.ConnectId]->GetSession(rid.SessionID))
				)->SendRequestPackage(&m_pkgSend);
			}
		}
	}
}

void CAgentServer::OnRspQryHostConfig(
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

	if (g_pConnector[rid.ConnectId] != NULL
	&&	g_pConnector[rid.ConnectId]->GetSession(rid.SessionID))			//上层会话的session还存在
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryHostConfig,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_pkgSend.DupPackage((CPackage *)pFTDCPackage);
		memcpy(
			(char *)m_pkgSend.GetFTDCHeader(),
			pFTDCPackage->GetFTDCHeader(),
			sizeof(TFTDCHeader));
		m_pkgSend.SetRequestId(rid.RequestId);

		if ((g_pConnector[rid.ConnectId]->GetSession(rid.SessionID)) != NULL)
		{
			(
				(CFTDCSession *)
					(g_pConnector[rid.ConnectId]->GetSession(rid.SessionID))
			)->SendRequestPackage(&m_pkgSend);
		}
	}
}

void CAgentServer::OnReqQryTradeDayChange(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryTradeDayChangeField fieldChange;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldChange);

	//....
	if (strcmp(fieldChange.ChangeType.getValue(), CHANGETRADEDAY) == 0) // 更换交易日处理
	{
		//1.设置本地交易日信息
		time_t	timep;
		time(&timep);

		printf(
			"CAgentServer::OnReqQryTradeDayChange TradeDay [%s]\n",
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
			"CAgentServer::OnReqQryTradeDayChange TradeDay [%s] Event TradeDay [%s]\n",
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

