/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	EventFrontServer.cpp
///@brief	�������¼��������������ǰ�����Ӵ������
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#include "EventFrontServer.h"
#include "EventCounterServer.h"
#include "CStatusAnalysis.h"
#include "PrjCommon.h"
#include "CRegexConfig.h"
#include "CMsgGenerator.h"

extern CEventProcess g_cEventProcess;	///ȫ�ָ澯���´������

// ��Ҫ���ⲿȫ�ֱ���
extern CDataCenter	*g_pDataCenter;		///�������Ķ����б���Ϣ
extern map<string, vector<ConfigFileInfo> > g_mapConfigFileList;
extern int	g_mConfigControlEvent;

extern int	g_mEventProcessFuzzyMatch;
extern CWarningEventManager g_warningEventManager;

extern map<string, CObjectAttrKey>	g_mapEventDelayTime;

extern CEventCounterServer	*g_counterServer;

extern CMsgGenerator g_MsgGenerator;

int g_netmonitorwarningflag = 0;
int g_unrealwarningflag = 0;

extern map<string, LinkStatusInfo>	g_mapLinkStatusInfo;

extern map<int, string> g_mapEventProcessFlag;

// ����ǰ�÷��������ӵ���ʵ��
CFrontConnector::CFrontConnector(
	CReactor *pReactor,
	unsigned int *pSyslogEventId,
	char *pFlowPath) :
	CAgentSessionFactory(pReactor, 10)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);

	char frontbuff[32];
	char oraclebuff[32];
	char slogbuff[32];

	for (int i = 0; i < MAX_EVENTFLOWNUM; i++)
	{
		sprintf(frontbuff, "frontflow%d", i);
		sprintf(oraclebuff, "oracleflow%d", i);
		sprintf(slogbuff, "slogflow%d", i);

#ifdef DEVELOP_ENV
		m_pFrontFlowArray[i] = new CCachedFileFlow(
				frontbuff,
				pFlowPath,
				true,
				50,
				32 * 1024);						//new CCachedFlow(true, 10000000, 32*1024);
		m_pOracleFlowArray[i] = new CCachedFileFlow(
				oraclebuff,
				pFlowPath,
				true,
				50,
				32 * 1024);						//new CCachedFlow(true, 10000000, 32*1024);
		m_pSlogFlowArray[i] = new CCachedFileFlow(
				slogbuff,
				pFlowPath,
				true,
				50,
				32 * 1024);	
#else
		m_pFrontFlowArray[i] = new CCachedFileFlow(
				frontbuff,
				pFlowPath,
				true,
				5000,
				32 * 1024);						//new CCachedFlow(true, 10000000, 32*1024);
		m_pOracleFlowArray[i] = new CCachedFileFlow(
				oraclebuff,
				pFlowPath,
				true,
				5000,
				32 * 1024);						//new CCachedFlow(true, 10000000, 32*1024);
		m_pSlogFlowArray[i] = new CCachedFileFlow(
				slogbuff,
				pFlowPath,
				true,
				5000,
				32 * 1024);	

#endif
	}

	m_pCurrFrontFlow = m_pFrontFlowArray[0];
	m_nFlowPosition = 0;

	m_pCurrOracleFlow = m_pOracleFlowArray[0];

	
	m_pCurrSlogFlow = m_pSlogFlowArray[0];

	SetOutputPath(TMP_DIRNAME);
}

CSession *CFrontConnector::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);

	/// Added by Henchi, 20120309
	pSession->SetCompressMethod(CRPCM_ZERO);	//����ѹ���㷨
	return pSession;
}

void CFrontConnector::OnSessionConnected(CSession *pSession)
{
	CAgentSessionFactory::OnSessionConnected(pSession);

	time_t	timep;
	time(&timep);
	printf(
		"\t%s CFrontConnector::OnSessionConnected: %0x Connected, CommonName [%s] RemoteName [%s] ==\n",
		ctime(&timep),
		(CFTDCSession *)pSession,
		pSession->GetChannel()->GetRemoteCommonName(),
		pSession->GetChannel()->GetRemoteName());
	fflush(stdout);
}

void CFrontConnector::OnSessionDisconnected(CSession *pSession, int nReason)	// �������ش������ӶϿ��¼�
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// ������ø��ദ�����ӶϿ��¼�
	time_t	timep;
	time(&timep);
	printf(
		"\t CFrontConnector::OnSessionDisconnected: %0x %s",
		(CFTDCSession *)pSession,
		ctime(&timep));
	fflush(stdout);
}

int CFrontConnector::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PRINT_DEBUG
	printf(
		"\tCFrontConnector::HandlePackage:receive package %0x\n",
		pFTDCPackage->GetTID());
#endif
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_ReqUserLogin:
			OnReqUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryWarningEventUpdateTopic:
			OnReqQryWarningEventUpdate(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryWarningActiveChange:
			OnReqQryWarningActiveChange(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryCPUUsageTopic:						/// ת����ѯ��̽������ô��� zhou.jj 20090616
			{
				CFTDReqQryCPUUsageField fieldInfo;
				memset(&fieldInfo, 0, sizeof(fieldInfo));
				FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

				CFTDCSession *tmpSession = m_mObjectIdSession.getObjectIdSession(
						(const char *)fieldInfo.ObjectID);
				if (tmpSession != NULL)
				{
					int nRid = m_mFrontToEventReq.putRequestId(
							pSession->GetSessionID(),
							pFTDCPackage->GetRequestId(),
							0);
					m_pkgSend.DupPackage((CPackage *)pFTDCPackage);
					memcpy(
						(char *)m_pkgSend.GetFTDCHeader(),
						pFTDCPackage->GetFTDCHeader(),
						sizeof(TFTDCHeader));
					m_pkgSend.SetRequestId(nRid);
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

		case FTD_TID_ReqQryTomcatInfoTopic: /// ת��Tomcat��ѯ���ɼ�����, henchi 20090622
			{
				CFTDReqQryTomcatInfoField fieldInfo;
				memset(&fieldInfo, 0, sizeof(fieldInfo));
				FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

				CFTDCSession *tmpSession = m_mObjectIdSession.getObjectIdSession(
						(const char *)fieldInfo.ObjectID);
				if (tmpSession != NULL)
				{
					int nRid = m_mFrontToEventReq.putRequestId(
							pSession->GetSessionID(),
							pFTDCPackage->GetRequestId(),
							0);
					m_pkgSend.DupPackage((CPackage *)pFTDCPackage);
					memcpy(
						(char *)m_pkgSend.GetFTDCHeader(),
						pFTDCPackage->GetFTDCHeader(),
						sizeof(TFTDCHeader));
					m_pkgSend.SetRequestId(nRid);
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

		case FTD_TID_ReqQryDBQueryTopic:	/// ת�����ݿ�SP��ѯ���ɼ�����, zhou.jj 20090706
			{
				CFTDReqQryDBQueryField	fieldInfo;
				memset(&fieldInfo, 0, sizeof(fieldInfo));
				FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

				CFTDCSession *tmpSession = m_mObjectIdSession.getObjectIdSession(
						(const char *)fieldInfo.ObjectID);
				if (tmpSession != NULL)
				{
					int nRid = m_mFrontToEventReq.putRequestId(
							pSession->GetSessionID(),
							pFTDCPackage->GetRequestId(),
							0);
					m_pkgSend.DupPackage((CPackage *)pFTDCPackage);
					memcpy(
						(char *)m_pkgSend.GetFTDCHeader(),
						pFTDCPackage->GetFTDCHeader(),
						sizeof(TFTDCHeader));
					m_pkgSend.SetRequestId(nRid);
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

		case FTD_TID_ReqQrySyslogEventUpdateTopic:
			OnReqQrySyslogEventUpdateTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetCfgFileTopic:
			OnReqQryNetCfgFileTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryGetFileTopic:
			OnReqQryGetFileTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetMonitorTaskResultTopic:
			OnReqNetMonitorTaskResultTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetRoomTopic:	//�澯���ſ���
			OnReqQryNetRoomTopic(pFTDCPackage, pSession);
			break;
		default:
			break;
	}

	return 0;
}

void CFrontConnector::OnReqUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
#endif

	CFTDReqUserLoginField fieldLogin;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldLogin);

	time_t	timep;
	time(&timep);
	printf(
		"\t CFrontConnector::OnReqUserLogin:user=%s password=%s  %s",
		(const char *)fieldLogin.UserID,
		(const char *)fieldLogin.Password,
		ctime(&timep));
	fflush(stdout);

	m_pkgSend.PrepareResponse(
		pFTDCPackage,
		FTD_TID_RspUserLogin,
		FTDC_CHAIN_LAST,
		FTD_VERSION);

	//FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);
	CFTDRspInfoField fieldRspInfo;
	fieldRspInfo.ErrorMsg = "�ɹ�";
	fieldRspInfo.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);

	pSession->SendRequestPackage(&m_pkgSend);

	/// Mod by Henchi, 20140620
	/// ���ڲ���ֻ��Query��Front,������SlogServer���
	/// ������Щ��������Դ�Event����ȡ���������صĽ�������Ϣ

	//if (strcmp((char *)fieldLogin.UserID.getValue(), "query") == 0)

	if (CEventCounterServer::m_mTradeDay)
	{
		m_pkgSend.PreparePackage(
			FTD_TID_ReqQryTradeDayChangeTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

		CFTDReqQryTradeDayChangeField fieldChange;
		fieldChange.ChangeType = CHANGETRADEDAY;

		sprintf(
			(char *)fieldChange.OldDate.getValue(),
			"%8d",
			CEventCounterServer::m_mTradeDay);
		sprintf(
			(char *)fieldChange.NewDate.getValue(),
			"%8d",
			CEventCounterServer::m_mTradeDay);

		FTDC_ADD_FIELD(&m_pkgSend, &fieldChange);

		pSession->SendRequestPackage(&m_pkgSend);
	}

	if (strcmp((char *)fieldLogin.UserID.getValue(), "front") == 0)
	{
		PublishFlow(pFTDCPackage, pSession, m_pFrontFlowArray);

		//���Ͷ������澯״̬��front
		m_pkgSend.PreparePackage(
			FTD_TID_RtnNetAreaTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

		CFTDRtnNetAreaField fieldobjecttree;
		memset(&fieldobjecttree, 0, sizeof(fieldobjecttree));

		map<string, CObjectIdStatus>::iterator	mapIt;
		map<string, CObjectIdStatus> &appIdNameMap = g_pDataCenter->
			getAppIdNameMap();
		for (mapIt = appIdNameMap.begin(); mapIt != appIdNameMap.end(); mapIt++)
		{
			if (m_pkgSend.Length() +
				sizeof(CFTDRtnNetAreaField) > FTDC_PACKAGE_MAX_SIZE)
			{
				m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
				m_pkgSend.MakePackage();
				m_pCurrFrontFlow->Append(
					m_pkgSend.Address(),
					m_pkgSend.Length());

				m_pkgSend.PreparePackage(
					FTD_TID_RtnNetAreaTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			}

			fieldobjecttree.ID = mapIt->second.m_iEventFlag;
			fieldobjecttree.EName = mapIt->second.m_sObjectId.c_str();
			fieldobjecttree.CName = mapIt->second.m_sObjectName.c_str();

			FTDC_ADD_FIELD(&m_pkgSend, &fieldobjecttree);
		}

		if (m_pkgSend.Length() >= sizeof(CFTDRtnNetAreaField))
		{
			m_pkgSend.MakePackage();
			m_pCurrFrontFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

	}
	else if (strcmp((char *)fieldLogin.UserID.getValue(), "query") == 0)
	{		
		PublishFlow(pFTDCPackage, pSession, m_pOracleFlowArray);
	}	
	else if (strcmp((char *)fieldLogin.UserID.getValue(), "slog") == 0)
	{
		PublishFlow(pFTDCPackage, pSession, m_pSlogFlowArray);
	}
}

void CFrontConnector::OnReqQrySyslogEventUpdateTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQrySyslogEventUpdateField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	qryfield.EvendID = *m_pSyslogEventId++;

	int nEventSeries;
	g_cEventProcess.getEventDesc(
			(const char *)qryfield.ObjectID,
			(const char *)qryfield.EventName,
			nEventSeries);
	qryfield.EventNum = nEventSeries;

	m_pkgSend.PreparePackage(FTD_TID_RtnSyslogEventTopic,FTDC_CHAIN_LAST,FTD_VERSION);	
	FTDC_ADD_FIELD(&m_pkgSend, (CFTDRtnSyslogEventField *) (&qryfield));
	
	m_pkgSend.MakePackage();
	m_pCurrFrontFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
}

void CFrontConnector::OnReqQryNetCfgFileTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetCfgFileField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		printf("get single field fail in %s\n", __FUNCTION__);
		return;
	}

	m_pkgSend.PreparePackage(
			FTD_TID_RspQryNetCfgFileTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	map<string, vector<ConfigFileInfo> >::iterator	it = g_mapConfigFileList.
		find(qryfield.ObjectID.getValue());
	if (it != g_mapConfigFileList.end())
	{
		for (int i = 0; i < it->second.size(); ++i)
		{
			CFTDRspQryNetCfgFileField field;
			memset(&field, 0, sizeof(CFTDRspQryNetCfgFileField));

			field.CfgFileName = it->second[i].filename.c_str();
			field.MonDate = it->second[i].filedate.c_str();
			field.MonTime = it->second[i].filetime.c_str();
			field.ObjectID = it->first.c_str();

			if (m_pkgSend.Length() +
				sizeof(CFTDRspQryNetCfgFileField) > FTDC_PACKAGE_MAX_SIZE)
			{
				m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
				pSession->SendRequestPackage(&m_pkgSend);

				m_pkgSend.PreparePackage(
						FTD_TID_RspQryNetCfgFileTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				m_pkgSend.SetRequestId(pPackage->GetRequestId());
			}

			FTDC_ADD_FIELD(&m_pkgSend, &field);
		}

		if (m_pkgSend.Length() >= sizeof(CFTDRspQryNetCfgFileField))
		{
			pSession->SendRequestPackage(&m_pkgSend);
		}
	}
	else
	{
		CFTDRspQryNetCfgFileField field;
		memset(&field, 0, sizeof(CFTDRspQryNetCfgFileField));

		field.CfgFileName = "";
		field.MonDate = "";
		field.MonTime = "";
		field.ObjectID = qryfield.ObjectID;

		FTDC_ADD_FIELD(&m_pkgSend, &field);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CFrontConnector::OnReqQryGetFileTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryGetFileField	qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		printf("get field fail in %s\n", __FUNCTION__);
		return;
	}

	string	strFile = m_sFilePath;

	string	filename = qryfield.FileName.getValue();

	size_t	point_pos = filename.rfind(".");
	if (point_pos == string::npos)
	{
		printf(
			"invalid file name:%s in %s, no point\n",
			filename.c_str(),
			__FUNCTION__);
		return;
	}

	size_t	time_pos = filename.rfind("_");
	if (time_pos == string::npos)
	{
		printf(
			"invalid file name:%s in %s, no time\n",
			filename.c_str(),
			__FUNCTION__);
		return;
	}

	//�ļ�ʱ��
	string	filetime = filename.substr(time_pos + 1, point_pos - time_pos - 1);

	size_t	date_pos = filename.substr(0, time_pos).rfind("_");
	if (date_pos == string::npos)
	{
		printf("invalid file name:%s in %s\n", filename.c_str(), __FUNCTION__);
		return;
	}

	//�ļ�����
	string	filedate = filename.substr(date_pos + 1, time_pos - date_pos - 1);

	//�ļ��е�objectid
	string	fileobjectid = filename.substr(0, date_pos);

	strFile += fileobjectid;

#ifdef WIN32
	strFile += "\\";
#else
	strFile += "/";
#endif
	if (strcmp(qryfield.Version.getValue(), "1") == 0)
	{
		//����ʱ����ȡ�����������ļ�����
		map<string, vector<ConfigFileInfo> >::iterator	it =
			g_mapConfigFileList.find(fileobjectid);
		if (it != g_mapConfigFileList.end())
		{
			//����beforeָ����ʱ��֮ǰ���ļ���Ϣ��afterָ����ʱ��֮����ļ���Ϣ
			int delta_before = 999999999;
			int delta_after = -999999999;

			string	filename_before;
			string	filename_after;

			struct tm m_mTime;

			m_mTime.tm_mday = atoi(filedate.c_str()) % 100;
			m_mTime.tm_mon = (atoi(filedate.c_str()) % 10000) / 100 - 1;
			m_mTime.tm_year = (atoi(filedate.c_str())) / 10000 - 1900;

			m_mTime.tm_sec = atoi(filetime.substr(4, 2).c_str());
			m_mTime.tm_min = atoi(filetime.substr(2, 2).c_str());
			m_mTime.tm_hour = atoi(filetime.substr(0, 2).c_str());

			time_t	filetime = mktime(&m_mTime);

			for (int i = 0; i < it->second.size(); ++i)
			{
				struct tm m_mTime;
				m_mTime.tm_mday = atoi(it->second[i].filedate.c_str()) % 100;
				m_mTime.tm_mon =
						(
							atoi(it->second[i].filedate.c_str()) %
							10000
						) /
						100 -
						1;
				m_mTime.tm_year = (atoi(it->second[i].filedate.c_str())) /
					10000 -
					1900;

				string	montime = it->second[i].filetime;

				m_mTime.tm_sec = atoi(montime.substr(4, 2).c_str());
				m_mTime.tm_min = atoi(montime.substr(2, 2).c_str());
				m_mTime.tm_hour = atoi(montime.substr(0, 2).c_str());

				time_t	curtime = mktime(&m_mTime);

				int diff = filetime - curtime;
				if (diff > 0)
				{
					//��ǰʱ��֮ǰ���ļ�
					if (diff < delta_before)
					{
						delta_before = diff;

						filename_before = it->second[i].filename;;
					}
				}
				else
				{
					//��ǰʱ��֮����ļ�
					if (diff > delta_after)
					{
						delta_after = diff;

						filename_after = it->second[i].filename;
					}
				}
			}

			//�·�ָ��ʱ��ǰ��������ļ�����
			string	beforeFilePath = strFile;
			beforeFilePath += filename_before;

			SendFileContent(
				beforeFilePath,
				filename_before,
				pPackage->GetRequestId(),
				pSession,
				false);

			string	afterFilePath = strFile;
			afterFilePath += filename_after;

			SendFileContent(
				afterFilePath,
				filename_after,
				pPackage->GetRequestId(),
				pSession,
				true);
		}
		else
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryGetFileTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());

			CFTDRspQryGetFileField	tfield;

			tfield.FileName.setValue(filename.c_str());
			tfield.Length.setValue(0);
			tfield.Offset.setValue(0);

			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			pSession->SendRequestPackage(&m_pkgSend);
		}
	}
	else if (strcmp(qryfield.Version.getValue(), "2") == 0)
	{
		//����ʱ����ȡ�����������ļ�����
		map<string, vector<ConfigFileInfo> >::iterator	it =
			g_mapConfigFileList.find(fileobjectid);
		if (it != g_mapConfigFileList.end())
		{
			//����beforeָ����ʱ��֮ǰ���ļ���Ϣ��afterָ����ʱ��֮����ļ���Ϣ
			int delta_before = 999999999;
			int delta_after = -999999999;

			string	filename_before;
			string	filename_after;

			struct tm m_mTime;

			m_mTime.tm_mday = atoi(filedate.c_str()) % 100;
			m_mTime.tm_mon = (atoi(filedate.c_str()) % 10000) / 100 - 1;
			m_mTime.tm_year = (atoi(filedate.c_str())) / 10000 - 1900;

			m_mTime.tm_sec = atoi(filetime.substr(4, 2).c_str());
			m_mTime.tm_min = atoi(filetime.substr(2, 2).c_str());
			m_mTime.tm_hour = atoi(filetime.substr(0, 2).c_str());

			time_t	filetime = mktime(&m_mTime);

			for (int i = 0; i < it->second.size(); ++i)
			{
				struct tm m_mTime;
				m_mTime.tm_mday = atoi(it->second[i].filedate.c_str()) % 100;
				m_mTime.tm_mon =
						(
							atoi(it->second[i].filedate.c_str()) %
							10000
						) /
						100 -
						1;
				m_mTime.tm_year = (atoi(it->second[i].filedate.c_str())) /
					10000 -
					1900;

				string	montime = it->second[i].filetime;

				m_mTime.tm_sec = atoi(montime.substr(4, 2).c_str());
				m_mTime.tm_min = atoi(montime.substr(2, 2).c_str());
				m_mTime.tm_hour = atoi(montime.substr(0, 2).c_str());

				time_t	curtime = mktime(&m_mTime);

				int diff = filetime - curtime;
				if (diff > 0)
				{
					//��ǰʱ��֮ǰ���ļ�
					if (diff < delta_before)
					{
						delta_before = diff;

						filename_before = it->second[i].filename;;
					}
				}
				else
				{
					//��ǰʱ��֮����ļ�
					if (diff > delta_after)
					{
						delta_after = diff;

						filename_after = it->second[i].filename;
					}
				}
			}

			//�·�ָ��ʱ��ǰ��������ļ�����
			string	beforeFilePath = strFile;
			beforeFilePath += filename_before;

			//����֮ǰ���ļ����Ҳ�����֮����ļ�
			if (filename_before.length() > 0)
			{
				SendFileContent(
					beforeFilePath,
					filename_before,
					pPackage->GetRequestId(),
					pSession,
					true);
			}
			else
			{
				string	afterFilePath = strFile;
				afterFilePath += filename_after;

				SendFileContent(
					afterFilePath,
					filename_after,
					pPackage->GetRequestId(),
					pSession,
					true);
			}
		}
		else
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryGetFileTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());

			CFTDRspQryGetFileField	tfield;

			tfield.FileName.setValue(filename.c_str());
			tfield.Length.setValue(0);
			tfield.Offset.setValue(0);

			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			pSession->SendRequestPackage(&m_pkgSend);
		}
	}
	else
	{
		//�����ļ�����ȡ�ļ�����
		strFile += qryfield.FileName.getValue();

		SendFileContent(strFile, filename, pPackage->GetRequestId(), pSession);
	}
}

void CFrontConnector::OnReqQryWarningEventUpdate(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryWarningEventUpdateField fieldinfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldinfo);

	if (!g_mConfigControlEvent)
	{
		bool erasemark = false;
		if (strcmp(fieldinfo.ProcessFlag.getValue(), "Y") == 0)
		{
			//���¼��Ѵ���ɾ���ڴ��е�����
			erasemark = true;
		}

		vector<CFTDRtnWarningEventField> resultFieldList;
		if (g_mEventProcessFuzzyMatch)
		{
			resultFieldList = g_warningEventManager.fuzzy_get_warning_event(
					fieldinfo.ObjectID.getValue(),
					fieldinfo.EventName.getValue(),
					erasemark);
		}
		else
		{
			resultFieldList = g_warningEventManager.exact_get_warning_event(
					fieldinfo.ObjectID.getValue(),
					fieldinfo.EventName.getValue(),
					fieldinfo.EvendID.getValue(),
					erasemark);
		}

		map<int, string>::iterator p_it = g_mapEventProcessFlag.find(fieldinfo.EventNum.getValue());
		if(p_it != g_mapEventProcessFlag.end())
		{
			p_it->second = fieldinfo.ProcessFlag;
		}
		else
		{
			g_mapEventProcessFlag[fieldinfo.EventNum.getValue()] = fieldinfo.ProcessFlag.getValue();
		}

		CFTDRtnWarningEventField eventField;
		memset(&eventField, 0, sizeof(CFTDRtnWarningEventField));

		eventField.ProcessFlag = fieldinfo.ProcessFlag;
		eventField.EventDealDes = fieldinfo.EventDealDes;		//����Ҫ������ԭʼ������
		for (int i = 0; i < resultFieldList.size(); ++i)
		{

			eventField.EvendID = resultFieldList[i].EvendID;	//eventidҪ�滻�ɱ����ĵ�id������ͻ����Ҳ�����Ӧ���¼�
			eventField.EventDes = resultFieldList[i].EventDes;
			eventField.EventName = resultFieldList[i].EventName;
			eventField.FullEventName = resultFieldList[i].FullEventName;
			eventField.EventNum = resultFieldList[i].EventNum;
			eventField.MonDate = resultFieldList[i].MonDate;
			eventField.MonTime = resultFieldList[i].MonTime;
			eventField.ObjectID = resultFieldList[i].ObjectID;
			eventField.OccurDate = resultFieldList[i].OccurDate;
			eventField.OccurTime = resultFieldList[i].OccurTime;
			eventField.WarningLevel = resultFieldList[i].WarningLevel;
			eventField.IPAddress = resultFieldList[i].IPAddress;

			m_pkgSend.PreparePackage(FTD_TID_RtnWarningEventTopic,FTDC_CHAIN_LAST,FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &eventField);

			m_pkgSend.MakePackage();
			m_pCurrFrontFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
			m_pCurrOracleFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		//�Ѵ�����¼���ɴ����л�δ����ֻ�ָ���ǰ�¼�
		if(resultFieldList.size() == 0)
		{
			//֮ǰ�Ѵ�����ɾ��������¼�
			m_pkgSend.PreparePackage(FTD_TID_RtnWarningEventTopic,FTDC_CHAIN_LAST,FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldinfo);

			m_pkgSend.MakePackage();
			m_pCurrFrontFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
			m_pCurrOracleFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		string	delay_key = fieldinfo.ObjectID.getValue();
		delay_key += ";;";
		delay_key += fieldinfo.EventName.getValue();

		if ((!fieldinfo.ActiveDate.isNull())
		&&	(!fieldinfo.ActiveTime.isNull()))
		{
			g_mapEventDelayTime[delay_key] = CObjectAttrKey(
					fieldinfo.ActiveDate.getValue(),
					fieldinfo.ActiveTime.getValue(),
					fieldinfo.ProcessFlag.getValue(),
					fieldinfo.EventDealDes.getValue());
		}
	}

	AddWarningEvent(fieldinfo);
}

void CFrontConnector::OnReqQryWarningActiveChange(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryWarningActiveChangeField	fieldinfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldinfo);

	/// Mod by Henchi, 20110413
		/// �޸ġ�ȡ���澯�����ƣ��������澯״̬��Ϣ��g_pDataCenter����
#if 0
	list<string>::iterator	itList;
	for (itList = m_cDropEventIdList.begin();
		 itList != m_cDropEventIdList.end();)
	{
		if ((*itList).find(fieldinfo.ObjectID.getValue()) != string::npos)
		{
			m_cDropEventIdList.erase(itList++);
		}
		else
		{
			itList++;
		}
	}

	if (fieldinfo.WarningActive == 0)	//�ָ��澯
	{
	}
	else
	{	//ȡ���ö���澯��������ID���ӵ������б���
		m_cDropEventIdList.push_back(fieldinfo.ObjectID.getValue());
	}

#endif

	///modified by κ��,Э�̻�����ת����config
	if (!g_mConfigControlEvent)
	{
		// �л���ǰ�ڴ��ж���澯״̬
		g_pDataCenter->UpDateObjectIdStatus(
				(char *)fieldinfo.ObjectID.getValue(),
				(int)fieldinfo.WarningActive);

		m_pkgSend.PreparePackage(
				FTD_TID_RtnWarningActiveChange,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		CFTDRtnWarningActiveChangeField *pRtnField =
			(CFTDRtnWarningActiveChangeField *) (&fieldinfo);
		FTDC_ADD_FIELD(&m_pkgSend, pRtnField);
		m_pkgSend.MakePackage();
		m_pCurrFrontFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
	}

	AddWarningEventActiveChange(fieldinfo);
}

void CFrontConnector::OnReqOrderInsert(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	printf("\tCFrontConnector::OnReqOrderInsert:\n");

	CFTDInputOrderField fieldOrder;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldOrder);
	printf(
		"\t\tCFrontConnector::OnReqOrderInsert:ParticipantID %s ClientID %s UserID %s\n",
		(const char *)fieldOrder.ParticipantID,
		(const char *)fieldOrder.ClientID,
		(const char *)fieldOrder.UserID);
	fflush(stdout);
}

void CFrontConnector::OnReqNetMonitorTaskResultTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetMonitorTaskResultField fieldInfo;
	memset(&fieldInfo, 0, sizeof(fieldInfo));

	fieldInfo.OperationType = 10;	//�ͻ���������ָ��ı��
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDReqQryNetMonitorTaskResultField::m_Describe);

	char key[1024] = { 0 };
	int taskflag = -1;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		taskflag = fieldInfo.Flag.getValue();

		//������������һ������ȫ�������ٴ���
		SNPRINTF(
			key,
			1024,
			"%s_%s",
			fieldInfo.ObjectID.getValue(),
			fieldInfo.InstructChain.getValue());

		map<string, vector<CFTDReqQryNetMonitorTaskResultField> >::iterator
			t_it = m_mapTaskResult.find(key);
		if (t_it != m_mapTaskResult.end())
		{
			t_it->second.push_back(fieldInfo);
		}
		else
		{
			vector<CFTDReqQryNetMonitorTaskResultField> taskresult;

			taskresult.push_back(fieldInfo);
			m_mapTaskResult[key] = taskresult;
		}

		itor.Next();
	}

	if (taskflag == 0)
	{
		CFTDRspQryNetMonitorTaskResultField resultField;
		memset(&resultField, 0, sizeof(resultField));

		//һ������Ľ��ȫ������
		map<string, vector<CFTDReqQryNetMonitorTaskResultField> >::iterator
			t_it = m_mapTaskResult.find(key);
		if (t_it != m_mapTaskResult.end())
		{
			if (t_it->second.size() > 0)
			{
				string	result;

				resultField.Flag = t_it->second[0].Flag;
				resultField.InstructChain = t_it->second[0].InstructChain;
				resultField.MonDate = t_it->second[0].MonDate;
				resultField.MonTime = t_it->second[0].MonTime;
				resultField.ObjectID = t_it->second[0].ObjectID;
				resultField.OperateTime = t_it->second[0].OperateTime;
				resultField.OperationType = t_it->second[0].OperationType;
				resultField.Task_ID = t_it->second[0].Task_ID;

				for (int i = 0; i < t_it->second.size(); ++i)
				{
					//��ԭ�����ԭ��
					result += t_it->second[i].ResultChain.getValue();
				}

				string	newresult;

				/*
				FILE * fp = fopen("c:\\content.txt", "wb");
				fwrite(result.c_str(), result.length(),1, fp);
				fclose(fp);
*/
				if (g_counterServer)
				{
					g_counterServer->RegularParse(
							resultField,
							result,
							newresult);
				}
				else
				{
					printf("impossible, g_counterServer NULL!\n");
				}

				//֪ͨǰ��
				if (newresult.length() == 0)
				{
					m_pkgSend.PreparePackage(
							FTD_TID_RspQryNetMonitorTaskResultTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);
					m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());				
					FTDC_ADD_FIELD(&m_pkgSend, &resultField);
					pSession->SendRequestPackage(&m_pkgSend);
				}
				else
				{
					for (int i = 0, deta = 0; i < newresult.length(); i += deta)
					{
						deta = min(
								newresult.length() - i,
								sizeof(resultField.ResultChain) - 1);
						resultField.ResultChain = (newresult.substr(i, deta)).c_str();

						m_pkgSend.PreparePackage(
								FTD_TID_RspQryNetMonitorTaskResultTopic,
								FTDC_CHAIN_CONTINUE,
								FTD_VERSION);
						m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
						FTDC_ADD_FIELD(&m_pkgSend, &resultField);
						pSession->SendRequestPackage(&m_pkgSend);
					}
				}
			}
			else
			{
				printf(
					"impossible, m_mapTaskResult->second has no data for key:%s\n",
					key);
			}

			//����������������
			m_mapTaskResult.erase(t_it);

			m_pkgSend.PreparePackage(
					FTD_TID_RspQryNetMonitorTaskResultTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
			pSession->SendRequestPackage(&m_pkgSend);
		}
		else
		{
			printf(
				"impossible, can't find info by key:%s from m_mapTaskResult\n",
				key);
		}
	}
}

void CFrontConnector::OnReqQryNetRoomTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetRoomField	fieldinfo;
	FTDC_GET_SINGLE_FIELD(pPackage, &fieldinfo);

	CFTDRspQryNetRoomField	tfield;
	memset(&tfield, 0, sizeof(tfield));

	if (fieldinfo.ID == -1)
	{
		//��ѯ
		tfield.ID = -2;				//������
		tfield.SysNetBuildingID = g_MsgGenerator.getNetworkEventFlag();

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryNetRoomTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);

		tfield.ID = -3;				//��ʵʱϵͳ
		tfield.SysNetBuildingID = g_MsgGenerator.getBusinessEventFlag();

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryNetRoomTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);

		tfield.ID = -4;				//ָ��
		tfield.SysNetBuildingID = g_MsgGenerator.getAttrFlag();

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryNetRoomTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	else
	{
		AddReqNetRoom(fieldinfo);
	}
}

void CFrontConnector::SetOutputPath(const char *path)
{
	if (!path)
	{
		printf("path NULL in %s\n", __FUNCTION__);
		return;
	}

	int iLen = strlen(path);
	if (iLen > 0)
	{
		m_sFilePath = path;
#ifdef WIN32
		if (*(path + iLen - 1) != '\\')
		{
			m_sFilePath.append(1, '\\');
		}

#else
		if (*(path + iLen - 1) != '/')
		{
			m_sFilePath.append(1, '/');
		}

#endif
	}
	else
	{
#ifdef WIN32
		m_sFilePath = ".\\";
#else
		m_sFilePath = "./";
#endif
	}
}

void CFrontConnector::SendFileContent(
	string	&filePath,
	string	&filename,
	DWORD requestId,
	CFTDCSession *pSession,
	bool sendLastFlag)
{
	FILE *pf = fopen(filePath.data(), "rb");
	if (pf)
	{
		int offset = 0;
		fseek(pf, offset, SEEK_SET);
		while (true)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryGetFileTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
			m_pkgSend.SetRequestId(requestId);

			CFTDRspQryGetFileField	tfield;
			int len = fread(
					(void *)(tfield.Comment.getValue()),
					1,
					sizeof(tfield.Comment),
					pf);
			if (SEEK_END == ftell(pf) || len <= 0)
			{
				if (sendLastFlag)
				{
					m_pkgSend.SetChain(FTDC_CHAIN_LAST);
				}
				else
				{
					break;
				}
			}

			tfield.FileName.setValue(filename.c_str());
			tfield.Length.setValue(len);
			tfield.Offset.setValue(offset);
			offset += len;

			if (len > 0 && SEEK_END != ftell(pf))
			{
				//���һ���������κ�����
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			}

			pSession->SendRequestPackage(&m_pkgSend);

			if (SEEK_END == ftell(pf) || len <= 0)
			{
				break;
			}
		}

		fclose(pf);
	}
	else
	{
		if (sendLastFlag)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryGetFileTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
		}
		else
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryGetFileTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
		}

		m_pkgSend.SetRequestId(requestId);

		CFTDRspQryGetFileField	tfield;

		tfield.FileName.setValue(filename.c_str());
		tfield.Length.setValue(0);
		tfield.Offset.setValue(0);

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);

		pSession->SendRequestPackage(&m_pkgSend);

		printf("file %s open fail in %s\n", filePath.c_str(), __FUNCTION__);
	}
}

bool CEventProcess::getEventDesc(
	const char	*pObjectId,
	const char	*pEventName,
	int &nEventSeries)
{
	map<CEventAttrKey, int>::iterator it = m_mapEventDesc.find(
			CEventAttrKey(pObjectId, pEventName));
	if (it != m_mapEventDesc.end())
	{
		nEventSeries = it->second;
	}
	else
	{
		m_mEventSeries++;
		nEventSeries = m_mEventSeries;
		m_mapEventDesc[CEventAttrKey(pObjectId, pEventName)] = m_mEventSeries;
	}

	return true;
}

void CFrontConnector::OnReqQryGetFileTopic(void)
{
	CFTDReqQryGetFileField	qryfield;

	qryfield.Version = "1";
	qryfield.FileName = "ZhangJ.WG.T-WG3750-B1-2N401_20111220_183759.txt";

	string	strFile = "c:\\tmp_event";

	string	filename = qryfield.FileName.getValue();

	size_t	point_pos = filename.rfind(".");
	if (point_pos == string::npos)
	{
		printf(
			"invalid file name:%s in %s, no point\n",
			filename.c_str(),
			__FUNCTION__);
		return;
	}

	size_t	time_pos = filename.rfind("_");
	if (time_pos == string::npos)
	{
		printf(
			"invalid file name:%s in %s, no time\n",
			filename.c_str(),
			__FUNCTION__);
		return;
	}

	//�ļ�ʱ��
	string	filetime = filename.substr(time_pos + 1, point_pos - time_pos - 1);

	size_t	date_pos = filename.substr(0, time_pos).rfind("_");
	if (date_pos == string::npos)
	{
		printf("invalid file name:%s in %s\n", filename.c_str(), __FUNCTION__);
		return;
	}

	//�ļ�����
	string	filedate = filename.substr(date_pos + 1, time_pos - date_pos - 1);

	//�ļ��е�objectid
	string	fileobjectid = filename.substr(0, date_pos);

	strFile += fileobjectid;

#ifdef WIN32
	strFile += "\\";
#else
	strFile += "/";
#endif
	if (strcmp(qryfield.Version.getValue(), "0") == 0)
	{
		//�����ļ�����ȡ�ļ�����
		strFile += qryfield.FileName.getValue();

		//SendFileContent(strFile, qryfield.FileName.getValue(), pPackage->GetRequestId(), pSession);
	}
	else if (strcmp(qryfield.Version.getValue(), "1") == 0)
	{
		//����ʱ����ȡ�����������ļ�����
		map<string, vector<ConfigFileInfo> >::iterator	it =
			g_mapConfigFileList.find(fileobjectid);
		if (it != g_mapConfigFileList.end())
		{
			//����beforeָ����ʱ��֮ǰ���ļ���Ϣ��afterָ����ʱ��֮����ļ���Ϣ
			int delta_before = 999999999;
			int delta_after = -999999999;

			string	date_before;
			string	date_after;

			string	time_before;
			string	time_after;

			struct tm m_mTime;

			m_mTime.tm_mday = atoi(filedate.c_str()) % 100;
			m_mTime.tm_mon = (atoi(filedate.c_str()) % 10000) / 100 - 1;
			m_mTime.tm_year = (atoi(filedate.c_str())) / 10000 - 1900;

			m_mTime.tm_sec = atoi(filetime.substr(4, 2).c_str());
			m_mTime.tm_min = atoi(filetime.substr(2, 2).c_str());
			m_mTime.tm_hour = atoi(filetime.substr(0, 2).c_str());

			printf(
				"%d %d %d %d %d %d\n",
				m_mTime.tm_year,
				m_mTime.tm_mon,
				m_mTime.tm_mday,
				m_mTime.tm_hour,
				m_mTime.tm_min,
				m_mTime.tm_sec);

			time_t	filetimevalue = mktime(&m_mTime);

			for (int i = 0; i < it->second.size(); ++i)
			{
				struct tm m_mTime;

				m_mTime.tm_mday = atoi(it->second[i].filedate.c_str()) % 100;
				m_mTime.tm_mon =
						(
							atoi(it->second[i].filedate.c_str()) %
							10000
						) /
						100 -
						1;
				m_mTime.tm_year = (atoi(it->second[i].filedate.c_str())) /
					10000 -
					1900;

				string	montime = it->second[i].filetime;

				m_mTime.tm_sec = atoi(montime.substr(4, 2).c_str());
				m_mTime.tm_min = atoi(montime.substr(2, 2).c_str());
				m_mTime.tm_hour = atoi(montime.substr(0, 2).c_str());

				printf(
					"----%d %d %d %d %d %d\n",
					m_mTime.tm_year,
					m_mTime.tm_mon,
					m_mTime.tm_mday,
					m_mTime.tm_hour,
					m_mTime.tm_min,
					m_mTime.tm_sec);

				time_t	curtimevalue = mktime(&m_mTime);

				int diff = filetimevalue - curtimevalue;
				if (diff > 0)
				{
					//��ǰʱ��֮ǰ���ļ�
					if (diff < delta_before)
					{
						delta_before = diff;

						date_before = it->second[i].filedate;
						time_before = it->second[i].filetime;
					}
				}
				else
				{
					//��ǰʱ��֮����ļ�
					if (diff > delta_after)
					{
						delta_after = diff;

						date_after = it->second[i].filedate;
						time_after = it->second[i].filetime;
					}
				}
			}

			//�·�ָ��ʱ��ǰ��������ļ�����
			string	beforeFileName;
			beforeFileName += fileobjectid;
			beforeFileName += "_";
			beforeFileName += date_before;
			beforeFileName += "_";
			beforeFileName += time_before;
			beforeFileName += ".txt";

			string	beforeFilePath = strFile;
			beforeFilePath += beforeFileName;

			//SendFileContent(beforeFilePath, beforeFileName, pPackage->GetRequestId(), pSession);
			string	afterFileName;
			afterFileName += fileobjectid;
			afterFileName += "_";
			afterFileName += date_after;
			afterFileName += "_";
			afterFileName += time_after;
			afterFileName += ".txt";

			string	afterFilePath = strFile;
			afterFilePath += afterFileName;

			//SendFileContent(afterFilePath, afterFileName, pPackage->GetRequestId(), pSession);			
		}
		else
		{
			//m_pkgSend.PreparePackage(FTD_TID_RspQryGetFileTopic, FTDC_CHAIN_LAST, FTD_VERSION);
			//m_pkgSend.SetRequestId(pPackage->GetRequestId());
			CFTDRspQryGetFileField	tfield;

			tfield.FileName.setValue(filename.c_str());
			tfield.Length.setValue(0);
			tfield.Offset.setValue(0);

			//pSession->SendRequestPackage(&m_pkgSend);
		}
	}
	else
	{
		printf(
			"invalid version value:%s in %s for filename\n",
			qryfield.Version.getValue(),
			__FUNCTION__,
			qryfield.FileName.getValue());
	}
}

void CFrontConnector::PublishFlow(CFTDCPackage *pFTDCPackage
			             , CFTDCSession *pSession
			             , CCachedFileFlow** cacheFileFlowArray)
{	
		CFTDDisseminationField	fieldDissemination;
		CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
				&CFTDDisseminationField::m_Describe);
		while (!itor.IsEnd())
		{
			itor.Retrieve(&fieldDissemination);
			if (fieldDissemination.SequenceSeries <= MAX_EVENTFLOWNUM)
			{
				pSession->Publish(
						cacheFileFlowArray[fieldDissemination.SequenceSeries - 1],
						fieldDissemination.SequenceSeries,
						fieldDissemination.SequenceNo);
			}

			itor.Next();
			if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
			{
				break;
			}
		}	// while (!itor.IsEnd()) end
}

