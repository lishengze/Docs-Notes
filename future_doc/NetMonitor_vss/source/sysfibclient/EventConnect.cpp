#include "EventConnect.h"
#include "CFPPSubscriber.h"

///保存对事件计算服务器的连接
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
	pSession->SetCompressMethod(CRPCM_ZERO);	//设置压缩算法
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
	/// 当事件服务接入时，由登录请求报文携带TradingDay送出。
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

	///形如19800227保存日期
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

	///形如12:12:12保存当前时间
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

	///连接的时候发送一次IP段对应的名称
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

	///连接的时候发送一次托管IP段对应的名称
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
	// 发送会员席位峰值数据
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
	///初始化会员席位历史最大值数据
	// 发送会员席位峰值数据
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
	/// 事件服务并不向fibclient发起登录请求，此处代码无效
	/// 交易日信息由fibclient向event连接建立时由登录请求包携带送出
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
	fieldRspInfo.ErrorMsg = "成功";
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
	/// 不允许由事件服务来驱动fibclient更新交易日信息
	
	/// fibclient的交易日信息只能通过fibproxy或交易流水进行初始化
	/// 其所有统计数据与交易流水相关

	/// 事件服务的交易日数据可由fibclient更新
	/// 或可由自身定时器机制更新
	/// 事件服务的交易日数据与监控数据相关，与交易流水不直接相关
	/// 允许事件服务的交易日信息比交易流水更新

	/// 对于前置服务的交易日切换，可由以下情形
	/// 1. fibclient由流水中获取新交易日后通知到所有前置服务
	/// 2. 前置服务与fibclient建立连接时获取交易日信息
	/// 3. 前置服务与event建立连接时获取交易日信息
	/// 4. 事件服务发现新交易日后通知到前置服务
	/// 其中1和2的交易日控制交易流水分析数据
	/// 其中3和4的交易日控制监控信息的定时清理

#if 0
	CFTDReqQryTradeDayChangeField fieldChange;
	
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldChange);
	if (strcmp(fieldChange.ChangeType.getValue(), CHANGETRADEDAY) == 0)
	{
		if (strcmp(g_strTryDate.data(), fieldChange.NewDate.getValue()) < 0)
		{
			/// 更新前交易日已记录的席位及登录信息
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
