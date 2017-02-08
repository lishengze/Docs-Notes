/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	AgentConnector.cpp
///@brief	ʵ���˲ɼ��������Ӳ�����̽����Ϣ����
///@history
///20080514	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
///20080702 �̺״�		��Ӷ�ȡXML������Ϣ��ش���
///20081009 �ܽ���		����֧�ֶ༶������
///20090219 �̺״�		��̽�뷢�͵�������Ϣ�а�����ҵ��ϵͳ��
///20090624 �̺״�		��̽�뷢�͵�������Ϣ�а�����Tomcat������
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
extern char g_mCfgPath[200];			//���������ļ�·��
extern CRequestInfo *GetOraclePassConf(void);
extern std::map<string, map<string, CDBConnectString> > g_OraclePass;

extern map<string, int> mapMonth;
extern map<string, int> g_mHostIdRlt;	// ������������Ӧ��ID��ӳ���ϵ
extern map<string, CRequstDBConnectInfo> g_mapDBConnectInfo;	//���ڱ������ݿ�����������������Ϣ�ṹ��ӳ��
extern COraclePassClient g_mOraclePassClient;					//���ڱ��浱ǰ����BNS������IP���˿���Ϣ
extern CManageReqIDSession g_cProbeToEventReq;
extern CManageReqIDSession g_cEventToProbeReq;

extern map<CFileDescript, CFileInfo> g_mapFile;

extern CFTDCSession *g_pFtdSession;				// FTD�´��������Ͳɼ����������Ψһ�Ự
extern list<CFTDCSession *> g_mListAllSession;	// �������ϵ��ϴ�̽�롢�ɼ����������б�
extern CFTDCSession *g_pCounterFtdSession;		// FTD�´������¼�������Ψһ�Ự

// add by cao.ning
// ϵͳ�ڲ����ӹ�ϵ
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
extern CLogger *g_pPackOutput;					// ���ݰ�������ļ�
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

///��ɼ�������������ʵ��
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
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
	printf("%s\n", GetLocationName());
#endif

	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);
	return pSession;
}

void CAgentConnector::OnSessionConnected(CSession *pSession)
{
#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
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
	// ��ȡ�²��̽�����ӹ�ϵ��Ϣ
	if (g_SysInternalTopology)
		g_SysInternalTopology->OnSessionConnected(pSession);
	return;
}

void CAgentConnector::OnSessionDisconnected(CSession *pSession, int nReason)	// �������ش������ӶϿ��¼�
{
	time_t timep;
	time(&timep);
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// ������ø��ദ�����ӶϿ��¼�
	printf(
		"\t CAgentConnector::OnSessionDisconnected CFTDCSession remove %0x %s",
		(CFTDCSession *)pSession,
		ctime(&timep));
	fflush(stdout);
	g_mListAllSession.remove((CFTDCSession *)pSession);
	g_mObjectIdSession.delSession((CFTDCSession *)pSession);

	// add by cao.ning
	// ��̽���ֱ����·�Ͽ�
	// ɾ���ûỰ��Ӧ����·
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
	if (g_bProxyFlag)	// ֱ��ת�����ݰ���ע�⣺�������ڲ��ɷ����ݰ�Ӧ��ʹ��g_pFtdSession�Ự
	{
		switch (pFTDCPackage->GetTID())
		{
		case FTD_TID_ReqUserLogin:
			OnReqUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryHostConfigTopic:
			OnReqQryHostConfig(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnUpdateSysConfigTopic:	//��Ҫ���������������������Ĺ�ϵ�������
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
		// ϵͳ�ڲ�������ϵ
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
	{	// �������ݰ����ݲ�ת����ע�⣺�������ڲ��ɷ����ݰ�Ӧ��ʹ��g_pCounterFtdSession�Ự
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
		case FTD_TID_RtnUpdateSysConfigTopic:					//��Ҫ���������������������Ĺ�ϵ�������
			OnRtnUpdateSysConfig(pFTDCPackage, pSession);
			DUP_AND_SEND_PKG;
			break;
		case FTD_TID_RtnWarningEventTopic:
			OnRtnWarningEventTopic(pFTDCPackage, pSession);
			DUP_AND_SEND_PKG;
			break;

		// add by cao.ning
		// ϵͳ�ڲ�������ϵ
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
		if (fieldInfo.EventName == EVENT_DBCONNECT_ERROR)			/// ���ݿ����ӶϿ��澯�����´�BNS��ȡȻ���͸���ǰ��pSession
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

				/// �Ѿ����������������ݿ������ʵ������ʵ����IP�б�����BNS��ȡ�˱������µ�������Ϣ

				/// Added by Henchi, 20100407
				if (g_mapDBConnectInfo.find(dbName) == g_mapDBConnectInfo.end())
				{
					printf(
						"δ��ȫ��ӳ�����ҵ����ݿ����[%s]�Ĺ�������������Ϣ\n",
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
						/// ���ڲ�ȷ��̽����������ɼ������Ƿ���ȫͬ�����˴��ݲ��ж�������Ϣ�Ƿ���ȫ��������һ��
						/// һ����BNS�ɹ���ȡ������Ϣ����̽�뷢�͸���������
						if (ConnectInfo.IsValid())
						{
							ReqConnectInfo.m_ConnectInfo = ConnectInfo;
							g_mapDBConnectInfo.insert(
								make_pair(dbName, ReqConnectInfo)); // ����ȫ��ӳ��
							char szDatabase[512] = "";
							sprintf(
								szDatabase,
								"%s %s %s %d",
								ConnectInfo.m_sInstanceName.c_str(),
								ConnectInfo.m_sRacName.c_str(),
								ConnectInfo.m_sServerIP.c_str(),
								ConnectInfo.m_nServerPort);

							CFTDRspQryHostConfigField fieldHostConfig;
							fieldHostConfig.CfgType = HOSTCFG_REQTYPE_DATABASE;				// ���ݿ�������Ϣ��
							fieldHostConfig.CfgName = dbName.c_str();						// ���ݿ����
							fieldHostConfig.CfgLocation = szDatabase;						// ���ݿ����������磺"monitor1 monitor 172.16.30.124 1521"
							fieldHostConfig.CfgHostName = ConnectInfo.m_sUserName.c_str();	// ���ݿ��½�û�
							fieldHostConfig.CfgAttend = ConnectInfo.m_sPassword.c_str();	// ���ݿ��½����
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
								"δ�ܳɹ����ӵ�BNS���������޷���ȡ���ݿ�[%s]��������Ϣ��,%s,%s,%s\n",
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
					"���ݿ����ӶϿ��澯���������� dbName ������ʽ�����������Ϣ\n");
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
	{					// ͬ�ϼ��Ĵ����Ͳɼ�����Ự
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
	else				// ͬ�ϼ��������¼�����������Ự
	{
		// Ӧ��˵�¼���󣬸��������������Ҫ�ļ�����Ϣ
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
						"Warnning: δ�ҵ�%s[%s]����Ӧ��TCP���Ӵ��������˶���!\n",
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

	if (GetProbeFlag()) // ���������̽�룬�ʹ�������ȡ��̽���ip��ַ
	{
		fieldConfigInfo.CfgAttend = GetLocationName();
	}

	if (g_pFtdSession != NULL)
	{					// ͬ�ϼ��Ĵ����Ͳɼ�����Ự
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
	else if (g_pCounterFtdSession != NULL)			// ͬ�ϼ��������¼�����������Ự
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
		// ͬ�ɼ����������û�н���,Ӧ�������Ϣ���¼���̽���ɼ�����
		m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryHostConfig,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

		CFTDRspInfoField rspInfoField;
		rspInfoField.ErrorID = 1;
		rspInfoField.ErrorMsg = "��������û�н���";
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
			UPDATESYSCONFIG_HOSTIDAPPID) == 0)		//ҵ��ID������IDӰ���ϵ
		{
			g_mObjectIdSession.addObjectIdSession(
				fieldInfo.NewValue.getValue(),
				pSession);						//ҵ��ID
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
			UPDATESYSCONFIG_HOSTNAME) == 0)	//���������
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
	CFTDCSession *pSession)						//̽��ĵ�¼Ӧ��
{
#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
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

WORD CAgentConnector::GetSequenceSeries(void)	//�����
{
	return FLOWSEQUENCEDAEMON;
}

DWORD CAgentConnector::GetReceivedCount(void)	//�յ��İ�����
{
#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
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
					"�յ���ʽ��������ݰ� %s %d %d\n",
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
					"�յ���ʽ��������ݰ� %s %d %d\n",
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
			/// ����־���ֽڳ���800ʱ,�������ݿ����޷�ƥ�䵽ʱ��ʱ�����־ͷ��Ϣ.
			/// ��������Ӧֱ�Ӷ���,������������쳣.
			/// �˴���Ӽ򵥵���־ͷ��Ϣ�ж�
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
				// ��־��ʽ May 22 15:28:14 kf4640 tkernel 1[15687]: OrderSize 4
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
				/// CFTDRtnSyslogInfoField �ṹ�е�AttrType�ֶν�Я�����õ�Ӧ�������磺arb �� tkernel.1
				/// ����������Ӧ�����в��������������Ϣʱ��������־Ҳ���������е���������
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
				else if (mGlobalSeq < 0)	// mGlobalSeq С��0������������ʶ��ID���
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
					/// �����Ǻ���ҵ��ʱ�ε�ҵ���¼����Ա���������쳣��־�¼���ɵ�����ӵ��
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
						/// �����¼��������ܣ���ͬһ������ͬʱ����ͬ���¼����������ƣ������Ķ���
						/// 20150101 10:10:00 TRADE.PuDian.app.tkernel.1 XTP
						char szTmp[1024];
						sprintf(szTmp, "%s %s %s %s",
							(char *)mObjectAttrValue.MonDate.getValue(),
							mHour,
							(char *)mObjectAttrValue.ObjectID.getValue(),
							mVal
							);
						/// ��ʱ�����Ӽ�����������λ��0
						szTmp[15] = '0';
						szTmp[16] = '0';

						/// Mod by Henchi, 20150409
						/// ��Ϊ�����˶����"XTP"��"InternalError"�¼�
						if ((strncmp(mVal, "XTP", strlen("XTP")) == 0 ||
							strncmp(mVal, "InternalError", strlen("InternalError")) == 0) && !ValidEvent(szTmp))
						{
							continue;
						}

						///�����¼�����
						m_pEventProcess->putEventReport(
							(char *)mObjectAttrValue.ObjectID.getValue(),
							(char *)mObjectAttrValue.MonDate.getValue(),
							mHour,
							mVal,
							pEventDes
							);

						///��������¼��Ϣ���⴦��
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

				// ��ض��� ���ʱ�� ���ָ�� ���ֵ
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
