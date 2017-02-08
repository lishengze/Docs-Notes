/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	EventCounterServer.cpp
///@brief	ʵ�����¼���������������ɼ��������Ӵ������
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#include "AgentServer.h"

extern int	g_mAgentId;
extern CManageReqIDSession	g_cProbeToEventReq;
extern CManageReqIDSession	g_cEventToProbeReq;
extern CObjectIdSession g_mObjectIdSession;

extern char g_mTradeDay[9];
extern CAgentConnector	*g_pConnector[MAXPROBECONFIGNUM];

// add by cao.ning
// ϵͳ�ڲ����ӹ�ϵ
extern CSysInternalTopology* g_SysInternalTopology;

map<CFileDescript, CFileInfo> g_mapFile;
CFTDCSession *g_pFtdSession = NULL;			// FTD�´����󵽴����Ͳɼ������Ψһ�Ự
list<CFTDCSession *> g_mListAllSession;		// �������ϵ�̽�롢�ɼ����������б�
#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pPackOutput;				// ���ݰ�������ļ�
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
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
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
		// ϵͳ�ڲ�������ϵ
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
		case FTD_TID_ReqQryCPUUsageTopic:	/// ת����ѯ��̽������ô��� zhou.jj 20090616
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

		case FTD_TID_ReqQryDBQueryTopic:	///  ת�����ݿ�SP��ѯ���ɼ�����, zhou.jj 20090706
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
				{					///session�Ѿ������ڣ�Ӧ�𵽿ͻ��˸ò�ѯ�Ѿ�����������ԭ��Ϊ�����Ѿ��Ͽ�
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

		case FTD_TID_RtnHostConfig: /// �����ɼ����ñ���㲥��
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
	pSession->SetCompressMethod(CRPCM_ZERO);	//����ѹ���㷨
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
			"\t g_pFtdSession %0x pSession %0x ���г��� %s",
			g_pFtdSession,
			(CFTDCSession *)pSession,
			ctime(&timep));
		printf(
			"\t CAgentServer::OnSessionConnected ���г���RemoteCommonName %s %s \n",
			pSession->GetChannel()->GetRemoteCommonName(),
			ctime(&timep));
		printf(
			"\t CAgentServer::OnSessionConnected ���г���RemoteName %s %s \n",
			pSession->GetChannel()->GetRemoteName(),
			ctime(&timep));
		printf(
			"\t CAgentServer::OnSessionConnected ���г��������Ͳɼ������´����ܳ��ֶ�����ӣ����ó����Ͽ������´�����! %s ",
			ctime(&timep));
		fflush(stdout);

		//g_pFtdSession = (CFTDCSession * )pSession;
		// by zhou.jj 20110111 12:32:00 �����´���������������Ͽ������´�����
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
	// ���ڴ�������ת����ʹ��AgentServer��Ϊ�ϴ��Ự
	if (g_SysInternalTopology)
		g_SysInternalTopology->SetSendSessionON(pSession);
}

void CAgentServer::OnSessionDisconnected(CSession *pSession, int nReason)	// �������ش������ӶϿ��¼�
{
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CAgentServer::OnSessionDisconnected: %0x\n",
		ctime(&timep),
		(CFTDCSession *)pSession);
	fflush(stdout);
	CSessionFactory::OnSessionDisconnected(pSession, nReason);						// ������ø��ദ�����ӶϿ��¼�
	if (g_pFtdSession == (CFTDCSession *)pSession)
	{
		g_pFtdSession = NULL;
	}
	else
	{
		printf(
			"\t g_pFtdSession %0x pSession %0x ���г����ر�����ʱ���ֶ�����ӣ����ó���! %s",
			g_pFtdSession,
			(CFTDCSession *)pSession,
			ctime(&timep));
		printf("\t �����˳������޸�������Ϣ %s\n", ctime(&timep));
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
	// ���ڴ�������ת����ʹ��AgentServer��Ϊ�ϴ��Ự
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
			m_sUpLinkName.c_str()) == 0)											//���յ����Ǵ˽ڵ�Ĳɼ���Ϣ
		{
			CFTDRspQryMonitorObjectField rspMBfield;
			CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
					&CFTDRspQryMonitorObjectField::m_Describe);
			while (!itor.IsEnd())
			{
				itor.Retrieve(&rspMBfield);

				printf(
					"\tCAgentServer::OnRspUserLogin:���Ӵ�=%s ����=%s \n",
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
									"�����Ѿ�����,���ӱ���Ϊ %s %s %s\n",
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
										"�����Ѿ�����,���ӱ��������Ӵ�����ͬ %s %s %s\n",
										rspMBfield.ObjectName.getValue(),
										pLocation,
										pType);
								}
								else
								{
									printf(
										"�����Ѿ�����,�������Ӵ���ͬ %s %s %s ֮ǰ���Ӵ� %s\n",
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
							printf("OnRspUserLogin ���ӳ����������,�˳�!!\n");
							break;
						}
					}
				}

				itor.Next();
				if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())	// �����û���¼Ӧ�����
				{
					;
				}
			}
		}
		else	//���յ�����ϢӦ��ת����������
		{
			int nRid = pFTDCPackage->GetRequestId();
			if (nRid == 0)
			{
				printf(
					" CAgentServer::OnRspUserLogin �����Ӧ��requestID %d\n",
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
			" CAgentServer::OnRspQryHostConfig �����Ӧ��requestID %d\n",
			nRid);
		return;
	}

	CTRID rid;
	g_cProbeToEventReq.getRequestId(rid, nRid, pFTDCPackage->GetChain());

	if (g_pConnector[rid.ConnectId] != NULL
	&&	g_pConnector[rid.ConnectId]->GetSession(rid.SessionID))			//�ϲ�Ự��session������
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
	if (strcmp(fieldChange.ChangeType.getValue(), CHANGETRADEDAY) == 0) // ���������մ���
	{
		//1.���ñ��ؽ�������Ϣ
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

