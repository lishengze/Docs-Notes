#include "EventConnect.h"
#include "CFPPSubscriber.h"

///������¼����������������
list<CFTDCSession *> sessionList;

extern CCachedFlow	*m_TRFlow;
extern const char	*INI_FILE_NAME;

extern list<CFTDCSession *> frontList;
extern map<CParticipantIDType, list<CUserIDType> >	g_BeijingMap;
extern map<CParticipantIDType, list<CUserIDType> >	g_PudianMap;
extern map<CParticipantIDType, list<CUserIDType> >	g_ZhangjinagMap;
extern map<int, map<CProtocolInfoType, int> > g_FrontUserIDMap;
extern map<CUserIDType, CProtocolInfoType>	g_UserProtocolMap;
extern map<int, CFTDRspQryFrontStatField> g_FrontStatMap;
extern map<string, ipLinkInfo>	g_ipLinkInfo;
extern map<string, ipLinkInfo>	g_ipLinkInfoTuoGuan;

extern map<CParticipantIDType, list<userIpInfo> > theOtherIpInfo;
extern map<CParticipantIDType, list<userIpInfo> > theOtherIpInfoMax;
extern int	theOtherOrderCount;

extern string g_strTryDate;

CStringIdMap g_mStringIDMap;

extern MemberSeatData  g_HistoryMemberSizeTotal_N;
extern MemberSeatData  g_HistoryUserSessionSizeTotal_N;
extern MemberSeatData  g_HistoryMemberSizeTotal_D;
extern MemberSeatData  g_HistoryUserSessionSizeTotal_D;

CEventConnect::CEventConnect(CReactor *pReactor) :
	CSessionFactory(pReactor, 1)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
}

int CEventConnect::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_ReqUserLogin:
			OnReqUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTradeDayChangeTopic:
			//		OnReqQryTradeDayChange(pFTDCPackage, pSession);
			break;
		default:
			break;
	}

	return 0;
}

CSession *CEventConnect::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);

	/// Added by Henchi, 20120309
	pSession->SetCompressMethod(CRPCM_ZERO);	//����ѹ���㷨
	return pSession;
}

void CEventConnect::OnSessionConnected(CSession *pSession)
{
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CEventConnect::OnSessionConnected: %0x \n",
		ctime(&timep),
		pSession);
	CSessionFactory::OnSessionConnected(pSession);
	sessionList.push_back((CFTDCSession *)pSession);

	/// Added by Henchi, 20140620
	/// ���¼��������ʱ���ɵ�¼������Я��TradingDay�ͳ���
	if (strcmp(g_strTryDate.c_str(), "1000") > 0)
	{
		CFTDReqUserLoginField fieldLogin;
		fieldLogin.TradingDay = g_strTryDate.data();
		fieldLogin.Password = g_strTryDate.data();
		fieldLogin.UserID = "fibclient";

		m_pkgSend.PreparePackage(
			FTD_TID_ReqUserLogin,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);

		((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
	}

	///����19800227��������
	char theToday[10];
	{
		time_t	timep;
		time(&timep);

		struct tm tm_time;
		LocalTime(&timep, &tm_time);
		sprintf(
			theToday,
			"%04d%02d%02d",
			tm_time.tm_year + 1900,
			tm_time.tm_mon + 1,
			tm_time.tm_mday);
	}

	///����12:12:12���浱ǰʱ��
	char theTime[10];
	{
		time_t	timep;
		time(&timep);

		struct tm tm_time;
		LocalTime(&timep, &tm_time);
		sprintf(
			theTime,
			"%02d:%02d:%02d",
			tm_time.tm_hour,
			tm_time.tm_min,
			tm_time.tm_sec);
	}

	///���ӵ�ʱ����һ��IP�ζ�Ӧ������
	{
		map<string, ipLinkInfo>::iterator it = g_ipLinkInfo.begin();
		for (; it != g_ipLinkInfo.end(); it++)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnObjectAttrTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);

			CFTDRtnObjectAttrField	tfield;
			tfield.ObjectID = it->first.data();
			tfield.AttrType = APPATTRIPSCOPENAME;
			strcpy((char *)tfield.MonDate.getValue(), theToday);
			strcpy((char *)tfield.MonTime.getValue(), theTime);
			tfield.ValueType = STRING_ATTR;
			tfield.AttrValue = it->second.name.data();
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
		}
	}

	///���ӵ�ʱ����һ���й�IP�ζ�Ӧ������
	{
		map<string, ipLinkInfo>::iterator it = g_ipLinkInfoTuoGuan.begin();
		for (; it != g_ipLinkInfoTuoGuan.end(); it++)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnObjectAttrTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);

			CFTDRtnObjectAttrField	tfield;
			tfield.ObjectID = it->first.data();
			tfield.AttrType = APPATTRIPSCOPENAME;
			strcpy((char *)tfield.MonDate.getValue(), theToday);
			strcpy((char *)tfield.MonTime.getValue(), theTime);
			tfield.ValueType = STRING_ATTR;
			tfield.AttrValue = it->second.name.data();
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
		}
	}

	REPORT_EVENT(0, "MemeberSeat Info: ", "start send max member and usersession data to event when connect!");
	REPORT_EVENT(0, "MemeberSeat Info: ", "MemberSizeTotal_N:%d",g_HistoryMemberSizeTotal_N.i_count);
	REPORT_EVENT(0, "MemeberSeat Info: ", "UserSessionSizeTotal_N:%d",g_HistoryUserSessionSizeTotal_N.i_count);
	REPORT_EVENT(0, "MemeberSeat Info: ", "MemberSizeTotal_D:%d",g_HistoryMemberSizeTotal_D.i_count);
	REPORT_EVENT(0, "MemeberSeat Info: ", "UserSessionSizeTotal_D:%d",g_HistoryUserSessionSizeTotal_D.i_count);
	// ���ͻ�Աϯλ��ֵ����
	{
		m_pkgSend.PreparePackage(
			FTD_TID_RtnObjectAttrTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);
		CFTDRtnObjectAttrField	tfield;
		string name = "MemberSizeTotal_N";
		memset(&tfield, 0, sizeof(tfield));
		strcpy(
			(char *)tfield.ObjectID.getValue(),
			"TRADE.PuDian.app.Link");
		strcpy(
			(char *)tfield.AttrType.getValue(),
			name.data());
		strcpy((char *)tfield.MonDate.getValue(), g_HistoryMemberSizeTotal_N.str_date.data());
		strcpy((char *)tfield.MonTime.getValue(), g_HistoryMemberSizeTotal_N.str_time.data());
		tfield.ValueType = INT_ATTR;

		char charCount[21];
		sprintf(charCount, "%d", g_HistoryMemberSizeTotal_N.i_count);
		strcpy(
			(char *)tfield.AttrValue.getValue(),
			charCount);
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);

		m_pkgSend.PreparePackage(
			FTD_TID_RtnObjectAttrTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);
		name = "UserSessionSizeTotal_N";
		memset(&tfield, 0, sizeof(tfield));
		strcpy(
			(char *)tfield.ObjectID.getValue(),
			"TRADE.PuDian.app.Link");
		strcpy(
			(char *)tfield.AttrType.getValue(),
			name.data());
		strcpy((char *)tfield.MonDate.getValue(), g_HistoryUserSessionSizeTotal_N.str_date.data());
		strcpy((char *)tfield.MonTime.getValue(), g_HistoryUserSessionSizeTotal_N.str_time.data());
		tfield.ValueType = INT_ATTR;

		sprintf(charCount, "%d", g_HistoryUserSessionSizeTotal_N.i_count);
		strcpy(
			(char *)tfield.AttrValue.getValue(),
			charCount);
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);

		m_pkgSend.PreparePackage(
			FTD_TID_RtnObjectAttrTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);
		name = "MemberSizeTotal_D";
		memset(&tfield, 0, sizeof(tfield));
		strcpy(
			(char *)tfield.ObjectID.getValue(),
			"TRADE.PuDian.app.Link");
		strcpy(
			(char *)tfield.AttrType.getValue(),
			name.data());
		strcpy((char *)tfield.MonDate.getValue(), g_HistoryMemberSizeTotal_D.str_date.data());
		strcpy((char *)tfield.MonTime.getValue(), g_HistoryMemberSizeTotal_D.str_time.data());
		tfield.ValueType = INT_ATTR;

		sprintf(charCount, "%d", g_HistoryMemberSizeTotal_D.i_count);
		strcpy(
			(char *)tfield.AttrValue.getValue(),
			charCount);
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);

		m_pkgSend.PreparePackage(
			FTD_TID_RtnObjectAttrTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);
		name = "UserSessionSizeTotal_D";
		memset(&tfield, 0, sizeof(tfield));
		strcpy(
			(char *)tfield.ObjectID.getValue(),
			"TRADE.PuDian.app.Link");
		strcpy(
			(char *)tfield.AttrType.getValue(),
			name.data());
		strcpy((char *)tfield.MonDate.getValue(), g_HistoryUserSessionSizeTotal_D.str_date.data());
		strcpy((char *)tfield.MonTime.getValue(), g_HistoryUserSessionSizeTotal_D.str_time.data());
		tfield.ValueType = INT_ATTR;

		sprintf(charCount, "%d", g_HistoryUserSessionSizeTotal_D.i_count);
		strcpy(
			(char *)tfield.AttrValue.getValue(),
			charCount);
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);	
	}
}

void ReloadHistoryData()
{
	try
	{
		REPORT_EVENT(0, "MemeberSeat Info: ", "prepare reload data when day change!");
		CConfig cfg(INI_FILE_NAME);
		char *pszMemberDataPath = cfg.getConfig("MemberSeatPath");
		string strMemberData = pszMemberDataPath;
		strMemberData += "/MemberSeat.xml";
		CXMLDoc* pData = new CXMLDoc();
		pData->read((char*)(strMemberData.data()));

		CXMLNode* pDataRoot = pData->getRootNode();
		CXMLNodeList *pNodeList = pDataRoot->getNodeList();
		for (int i = 0; i < pNodeList->size(); i++)
		{
			CXMLNode *pNodeCur = (*pNodeList)[i];
			string name = pNodeCur->findProperty("name");
			if (name == "MemberSizeTotal_N")
			{
				g_HistoryMemberSizeTotal_N.str_date = pNodeCur->findProperty("Date");
				g_HistoryMemberSizeTotal_N.str_time = pNodeCur->findProperty("Time");
				g_HistoryMemberSizeTotal_N.i_count = atoi(pNodeCur->findProperty("Count"));
			}
			else if (name == "UserSessionSizeTotal_N")
			{
				g_HistoryUserSessionSizeTotal_N.str_date = pNodeCur->findProperty("Date");
				g_HistoryUserSessionSizeTotal_N.str_time = pNodeCur->findProperty("Time");
				g_HistoryUserSessionSizeTotal_N.i_count = atoi(pNodeCur->findProperty("Count"));
			}
			else if (name == "MemberSizeTotal_D")
			{
				g_HistoryMemberSizeTotal_D.str_date = pNodeCur->findProperty("Date");
				g_HistoryMemberSizeTotal_D.str_time = pNodeCur->findProperty("Time");
				g_HistoryMemberSizeTotal_D.i_count = atoi(pNodeCur->findProperty("Count"));
			}
			else if (name == "UserSessionSizeTotal_D")
			{
				g_HistoryUserSessionSizeTotal_D.str_date = pNodeCur->findProperty("Date");
				g_HistoryUserSessionSizeTotal_D.str_time = pNodeCur->findProperty("Time");
				g_HistoryUserSessionSizeTotal_D.i_count = atoi(pNodeCur->findProperty("Count"));
			}
		}

		REPORT_EVENT(0, "MemeberSeat Info: ", "MemberSizeTotal_N:%d", g_HistoryMemberSizeTotal_N.i_count);
		REPORT_EVENT(0, "MemeberSeat Info: ", "UserSessionSizeTotal_N:%d", g_HistoryUserSessionSizeTotal_N.i_count);
		REPORT_EVENT(0, "MemeberSeat Info: ", "MemberSizeTotal_D:%d", g_HistoryMemberSizeTotal_D.i_count);
		REPORT_EVENT(0, "MemeberSeat Info: ", "UserSessionSizeTotal_D:%d", g_HistoryUserSessionSizeTotal_D.i_count);
	}
	catch (CRuntimeError * e)
	{
		printf(
			"Error While load DeployConfig info:\nLINE[%d]:%s\n",
			e->GetLineNo(),
			e->GetMsg());

		REPORT_EVENT(0, "MemeberSeat Info: ", "failed to read history data when day change!");
	}

	REPORT_EVENT(0, "MemeberSeat Info: ", "send data to event when day change!");
}

void CEventConnect::SendMemberPeak()
{
	///��ʼ����Աϯλ��ʷ���ֵ����
	// ���ͻ�Աϯλ��ֵ����
	{
		m_pkgSend.PreparePackage(
			FTD_TID_RtnObjectAttrTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);
		CFTDRtnObjectAttrField	tfield;
		string name = "MemberSizeTotal_N";
		memset(&tfield, 0, sizeof(tfield));
		strcpy(
			(char *)tfield.ObjectID.getValue(),
			"TRADE.PuDian.app.Link");
		strcpy(
			(char *)tfield.AttrType.getValue(),
			name.data());
		strcpy((char *)tfield.MonDate.getValue(), g_HistoryMemberSizeTotal_N.str_date.data());
		strcpy((char *)tfield.MonTime.getValue(), g_HistoryMemberSizeTotal_N.str_time.data());
		tfield.ValueType = INT_ATTR;

		char charCount[21];
		sprintf(charCount, "%d", g_HistoryMemberSizeTotal_N.i_count);
		strcpy(
			(char *)tfield.AttrValue.getValue(),
			charCount);
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		for (list < CFTDCSession * >::iterator listit =
			sessionList.begin();
			listit != sessionList.end();
		listit++)
		{
			(*listit)->SendRequestPackage(&m_pkgSend);
			m_pkgSend.Pop(FTDCHLEN);
		}

		m_pkgSend.PreparePackage(
			FTD_TID_RtnObjectAttrTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);
		name = "UserSessionSizeTotal_N";
		memset(&tfield, 0, sizeof(tfield));
		strcpy(
			(char *)tfield.ObjectID.getValue(),
			"TRADE.PuDian.app.Link");
		strcpy(
			(char *)tfield.AttrType.getValue(),
			name.data());
		strcpy((char *)tfield.MonDate.getValue(), g_HistoryUserSessionSizeTotal_N.str_date.data());
		strcpy((char *)tfield.MonTime.getValue(), g_HistoryUserSessionSizeTotal_N.str_time.data());
		tfield.ValueType = INT_ATTR;

		sprintf(charCount, "%d", g_HistoryUserSessionSizeTotal_N.i_count);
		strcpy(
			(char *)tfield.AttrValue.getValue(),
			charCount);
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		for (list < CFTDCSession * >::iterator listit =
			sessionList.begin();
			listit != sessionList.end();
		listit++)
		{
			(*listit)->SendRequestPackage(&m_pkgSend);
			m_pkgSend.Pop(FTDCHLEN);
		}

		m_pkgSend.PreparePackage(
			FTD_TID_RtnObjectAttrTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);
		name = "MemberSizeTotal_D";
		memset(&tfield, 0, sizeof(tfield));
		strcpy(
			(char *)tfield.ObjectID.getValue(),
			"TRADE.PuDian.app.Link");
		strcpy(
			(char *)tfield.AttrType.getValue(),
			name.data());
		strcpy((char *)tfield.MonDate.getValue(), g_HistoryMemberSizeTotal_D.str_date.data());
		strcpy((char *)tfield.MonTime.getValue(), g_HistoryMemberSizeTotal_D.str_time.data());
		tfield.ValueType = INT_ATTR;

		sprintf(charCount, "%d", g_HistoryMemberSizeTotal_D.i_count);
		strcpy(
			(char *)tfield.AttrValue.getValue(),
			charCount);
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		for (list < CFTDCSession * >::iterator listit =
			sessionList.begin();
			listit != sessionList.end();
		listit++)
		{
			(*listit)->SendRequestPackage(&m_pkgSend);
			m_pkgSend.Pop(FTDCHLEN);
		}

		m_pkgSend.PreparePackage(
			FTD_TID_RtnObjectAttrTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);
		name = "UserSessionSizeTotal_D";
		memset(&tfield, 0, sizeof(tfield));
		strcpy(
			(char *)tfield.ObjectID.getValue(),
			"TRADE.PuDian.app.Link");
		strcpy(
			(char *)tfield.AttrType.getValue(),
			name.data());
		strcpy((char *)tfield.MonDate.getValue(), g_HistoryUserSessionSizeTotal_D.str_date.data());
		strcpy((char *)tfield.MonTime.getValue(), g_HistoryUserSessionSizeTotal_D.str_time.data());
		tfield.ValueType = INT_ATTR;

		sprintf(charCount, "%d", g_HistoryUserSessionSizeTotal_D.i_count);
		strcpy(
			(char *)tfield.AttrValue.getValue(),
			charCount);
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		for (list < CFTDCSession * >::iterator listit =
			sessionList.begin();
			listit != sessionList.end();
		listit++)
		{
			(*listit)->SendRequestPackage(&m_pkgSend);
			m_pkgSend.Pop(FTDCHLEN);
		}
	}
}

void CEventConnect::OnSessionDisconnected(CSession *pSession, int nReason)
{
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CEventConnect::OnSessionDisconnected: %0x \n",
		ctime(&timep),
		pSession);
	CSessionFactory::OnSessionDisconnected(pSession, nReason);
	sessionList.remove((CFTDCSession *)pSession);
}

void CEventConnect::OnReqUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	/// Del by Henchi, 20140620
	/// �¼����񲢲���fibclient�����¼���󣬴˴�������Ч
	/// ��������Ϣ��fibclient��event���ӽ���ʱ�ɵ�¼�����Я���ͳ�
#if 0
	CFTDReqUserLoginField fieldLogin;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldLogin);
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspUserLogin,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);

	CFTDReqQryTradeDayChangeField tfield;
	memset(&tfield, 0, sizeof(tfield));
	tfield.ChangeType = CHANGETRADEDAY;
	tfield.NewDate = g_strTryDate.data();
	FTDC_ADD_FIELD(&m_pkgSend, &tfield);

	CFTDRspInfoField fieldRspInfo;
	fieldRspInfo.ErrorMsg = "�ɹ�";
	fieldRspInfo.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
	pSession->SendRequestPackage(&m_pkgSend);
#endif
}

CIPAnalysis::CIPAnalysis(char *pConfigPath)
{
	int i;
	char path[100];
	sprintf(path, "%s/%s", pConfigPath, "SystemConfig.xml");

	CXMLDoc *pXMLDoc;
	CXMLNode *pXMLRoot;
	pXMLDoc = new CXMLDoc();
	pXMLDoc->read(path);
	pXMLRoot = pXMLDoc->getRootNode();

	XMLNodeType NodeType = XMLTag;
	CXMLNode *pNode = pXMLRoot->findNode(
			NodeType,
			"SessionIpConfig",
			NULL,
			NULL);
	if (pNode == NULL)
	{
		printf("Can not find <SessionIpConfig> in file %s\n", path);
		exit(0);
	}

	CXMLNodeList *pNodeList = pNode->getNodeList();

	for (i = 0; i < pNodeList->size(); i++)
	{
		CXMLNode *pNodeAttr = (*pNodeList)[i];
		int m = g_mStringIDMap.getStringId(pNodeAttr->findProperty("name"));
		CXMLNodeList *pNodeIpList = pNodeAttr->getNodeList();
		for (int j = 0; j < pNodeIpList->size(); j++)
		{
			CXMLNode *pNodeIp = (*pNodeIpList)[j];
			m_mapIpType[string(pNodeIp->findProperty("value"))] = m;
		}
	}

	delete pXMLDoc;
}

int CIPAnalysis::getIpTypeID(char *pIpAddr)
{
	for (map<string, int>::iterator it = m_mapIpType.begin();
		 it != m_mapIpType.end();
		 it++)
	{
		if (memcmp(pIpAddr, it->first.c_str(), it->first.size()) == 0)
		{
			return it->second;
		}
	}

	return 0;
}

bool CIPAnalysis::init(void)
{
	return true;
}

void CEventConnect::OnReqQryTradeDayChange(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	/// Mod by Henchi, 20140620
	/// ���������¼�����������fibclient���½�������Ϣ
	
	/// fibclient�Ľ�������Ϣֻ��ͨ��fibproxy������ˮ���г�ʼ��
	/// ������ͳ�������뽻����ˮ���

	/// �¼�����Ľ��������ݿ���fibclient����
	/// ���������ʱ�����Ƹ���
	/// �¼�����Ľ�������������������أ��뽻����ˮ��ֱ�����
	/// �����¼�����Ľ�������Ϣ�Ƚ�����ˮ����

	/// ����ǰ�÷���Ľ������л���������������
	/// 1. fibclient����ˮ�л�ȡ�½����պ�֪ͨ������ǰ�÷���
	/// 2. ǰ�÷�����fibclient��������ʱ��ȡ��������Ϣ
	/// 3. ǰ�÷�����event��������ʱ��ȡ��������Ϣ
	/// 4. �¼��������½����պ�֪ͨ��ǰ�÷���
	/// ����1��2�Ľ����տ��ƽ�����ˮ��������
	/// ����3��4�Ľ����տ��Ƽ����Ϣ�Ķ�ʱ����

#if 0
	CFTDReqQryTradeDayChangeField fieldChange;
	
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldChange);
	if (strcmp(fieldChange.ChangeType.getValue(), CHANGETRADEDAY) == 0)
	{
		if (strcmp(g_strTryDate.data(), fieldChange.NewDate.getValue()) < 0)
		{
			/// ����ǰ�������Ѽ�¼��ϯλ����¼��Ϣ
			ReloadHistoryData();
			SendMemberPeak();
			ClearStatInfo();

			time_t	timep;
			time(&timep);
			g_strTryDate = fieldChange.NewDate.getValue();
			printf("TradingDay change to [%s] at time [%s]\n", g_strTryDate.data(), ctime(&timep));
		}
	}
#endif
}

void CEventConnect::ChangeTradeDayOnFibNotify(
	string	strOldDay,
	string	strNewDay)
{
	m_pkgSend.PreparePackage(
		FTD_TID_ReqQryTradeDayChangeTopic,
		FTDC_CHAIN_LAST,
		FTD_VERSION);

	CFTDReqQryTradeDayChangeField tfield;
	memset(&tfield, 0, sizeof(tfield));
	tfield.ChangeType = CHANGETRADEDAY;
	strcpy((char *)tfield.OldDate.getValue(), strOldDay.data());
	strcpy((char *)tfield.NewDate.getValue(), strNewDay.data());
	FTDC_ADD_FIELD(&m_pkgSend, &tfield);

	list<CFTDCSession *>::iterator	it = sessionList.begin();
	for (; it != sessionList.end(); it++)
	{
		(*it)->SendRequestPackage(&m_pkgSend);
		m_pkgSend.Pop(FTDCHLEN);
	}
}
