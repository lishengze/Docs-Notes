/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CFibClient2.cpp
///@brief	实现了定义了面向fibproxy会话连接客户类
///@history	
///20080624	郭鹏		创建该文件
///20080624	郭鹏		修订注释
/////////////////////////////////////////////////////////////////////////
#include "CFibClient2.h"
#include <iostream>
using namespace std;

const int TIMER_CHECK_RESPONSE = 2;
const int INTERVAL_CHECK_RESPONSE = 1000;
const int TIMER_OURHEART = 101;

extern string g_strTryDate;

extern map<CParticipantIDType, list<CUserIDType> >	g_BeijingMap;
extern map<CParticipantIDType, list<CUserIDType> >	g_PudianMap;
extern map<CParticipantIDType, list<CUserIDType> >	g_ZhangjinagMap;
extern map<int, map<CProtocolInfoType, int> > g_FrontUserIDMap;
extern map<CUserIDType, CProtocolInfoType>	g_UserProtocolMap;
extern map<int, CFTDRspQryFrontStatField> g_FrontStatMap;
extern map<string, ipLinkInfo>	g_ipLinkInfo;
extern map<string, ipLinkInfo>	g_ipLinkInfoTuoGuan;
extern int	theOtherOrderCount;

extern map<CParticipantIDType, list<userIpInfo> > theOtherIpInfo;
extern map<CParticipantIDType, list<userIpInfo> > theOtherIpInfoMax;

// 历史的会员席位最大值数据
extern MemberSeatData  g_HistoryMemberSizeTotal_N;
extern MemberSeatData  g_HistoryUserSessionSizeTotal_N;
extern MemberSeatData  g_HistoryMemberSizeTotal_D;
extern MemberSeatData  g_HistoryUserSessionSizeTotal_D;

extern const char	*INI_FILE_NAME;

///保存对事件计算服务器的连接
extern list<CFTDCSession *> sessionList;

void CFibClient2::CreateSubscriber(WORD wTopicID)
{
	CSubscriberMap::iterator itor = m_mapSubscriber.find(wTopicID);
	CFPPSubscriber	*pSubscriber = NULL;
	if (itor == m_mapSubscriber.end())
	{
		pSubscriber = new CFPPSubscriber(wTopicID);
		m_mapSubscriber[wTopicID] = pSubscriber;
	}
	else
	{
		pSubscriber = (*itor).second;
	}
}

void CFibClient2::ResetSubscriber(void)
{
	//清除proxy流水
	CSubscriberMap::iterator itor;
	for (itor = m_mapSubscriber.begin();
		itor != m_mapSubscriber.end();
		itor++)
	{
		if (itor->second->m_pFlow)
		{
			itor->second->m_pFlow->Truncate(0);
		}
	}
}

CSession *CFibClient2::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);

	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);
	return pSession;
}

void CFibClient2::OnSessionConnected(CSession *pSession)
{
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CFibClient2::OnSessionConnected: %0x \n",
		ctime(&timep),
		pSession);
	CNsSessionFactory::OnSessionConnected(pSession);
	m_dwSessionID = pSession->GetSessionID();

	//	cout<<"session "<<pSession->GetSessionID()<<" connected!"<<endl;
	ReqLogin();

	//	KillTimer(TIMER_OURHEART);
	SetTimer(TIMER_OURHEART, 1000);
}

void CFibClient2::OnSessionDisconnected(CSession *pSession, int nReason)
{
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CFibClient2::OnSessionDisconnected: %0x \n",
		ctime(&timep),
		pSession);

	//	cout<<"session "<<pSession->GetSessionID()<<" disconnected!"<<endl;
	KillTimer(TIMER_CHECK_RESPONSE);
	KillTimer(TIMER_OURHEART);
	m_dwSessionID = 0;
	CNsSessionFactory::OnSessionDisconnected(pSession, nReason);
}

void CFibClient2::OnTimer(int nIDEvent)
{
	if (nIDEvent == TIMER_CHECK_RESPONSE)
	{
		RequestDirectly();
		if (m_nTimeOut < 8 * INTERVAL_CHECK_RESPONSE)
		{
			m_nTimeOut *= 2;
			KillTimer(TIMER_CHECK_RESPONSE);
			SetTimer(TIMER_CHECK_RESPONSE, m_nTimeOut);
		}
	}
	else if (nIDEvent == TIMER_OURHEART)
	{
		m_pkgSend.PreparePackage(
			FPP_TID_RspSubscribe,
			FTDC_CHAIN_LAST,
			FPP_FTD_VERSION);

		CFPPRspInfoField rspInfoField;
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);

		CFTDCSession *pSession = (CFTDCSession *)GetSession(m_dwSessionID);
		if (pSession == NULL)
		{
			return;
		}

		pSession->SendRequestPackage(&m_pkgSend);
	}

	CNsSessionFactory::OnTimer(nIDEvent);
}

int CFibClient2::HandlePackage(
							  CFTDCPackage *pFTDCPackage,
							  CFTDCSession *pSession)
{
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);

	int nRequestID = pFTDCPackage->GetRequestId();
	if (nRequestID != m_pkgRequest.GetRequestId())
	{
		NET_EXCEPTION_LOG1(
			"Receive less request id,[0x%04x]\n",
			pFTDCPackage->GetRequestId());
		FTDC_HEADER_DEBUG(pFTDCPackage);
		return 0;
	}

	CFPPRspInfoField rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) <= 0)
	{
		NET_EXCEPTION_LOG1(
			"Can't find CFPPRspInfoField,[0x%04x]\n",
			pFTDCPackage->GetTID());
		return 0;
	}

	if (rspInfoField.ErrorID == 0)
	{
		KillTimer(TIMER_CHECK_RESPONSE);
	}

	switch (pFTDCPackage->GetTID())
	{
	case FPP_TID_RspUserLogin:
		OnRspUserLogin(pFTDCPackage, pSession);
		break;
	case FPP_TID_RspSubscribe:
		OnRspSubscribe(pFTDCPackage, pSession);
		break;
	case FPP_TID_RspError:
		OnRspError(pFTDCPackage, pSession);
		break;
	default:
		break;
	}

	return 0;
}

int CFibClient2::RequestDirectly(void)
{
	NET_IO_LOG1(
		"CFibProxyClient::RequestDirectly SessionID=%d\n",
		m_dwSessionID);

	CFTDCSession *pSession = (CFTDCSession *)GetSession(m_dwSessionID);
	if (pSession == NULL)
	{
		return -1;
	}

	NET_IO_LOG0("CFibProxyClient::RequestDirectly Send\n");
	pSession->SendRequestPackage(&m_pkgRequest);
	m_pkgRequest.Pop(FTDCHLEN);
	return 0;
}

void CFibClient2::SetRetryTimer(void)
{
	KillTimer(TIMER_CHECK_RESPONSE);
	m_nTimeOut = INTERVAL_CHECK_RESPONSE;
	SetTimer(TIMER_CHECK_RESPONSE, INTERVAL_CHECK_RESPONSE);
}

void CFibClient2::ReqLogin(void)
{
	CFPPReqUserLoginField fieldUserLogin;
	fieldUserLogin.TradingDay = "";
	fieldUserLogin.UserID = m_strUserID.c_str();
	fieldUserLogin.Password = m_strPassword.c_str();
	fieldUserLogin.UserProductInfo = "FIB Proxy Client v1.0";
	m_pkgRequest.PreparePackage(
		FPP_TID_ReqUserLogin,
		FTDC_CHAIN_LAST,
		FPP_FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgRequest, &fieldUserLogin);
	m_pkgRequest.SetRequestId(++m_dwRequsetID);
	RequestDirectly();
	SetRetryTimer();
}

void CFibClient2::ReqSubscribe(void)
{
	m_pkgRequest.PreparePackage(
		FPP_TID_ReqSubscribe,
		FTDC_CHAIN_LAST,
		FPP_FTD_VERSION);

	CFPPDisseminationField	fieldDissemination;
	CSubscriberMap::iterator i = m_mapSubscriber.begin();
	for (; i != m_mapSubscriber.end(); i++)
	{
		CFPPSubscriber	*pSubscriber = (*i).second;
		pSubscriber->CreateFlow(m_strFlowPath.c_str());
		fieldDissemination.SequenceSeries = pSubscriber->GetSequenceSeries();
		fieldDissemination.SequenceNo = pSubscriber->GetReceivedCount();
		FTDC_ADD_FIELD(&m_pkgRequest, &fieldDissemination);
	}

	m_pkgRequest.SetRequestId(++m_dwRequsetID);
	RequestDirectly();
	SetRetryTimer();
}

void CFibClient2::OnRspError(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	CFPPRspInfoField fieldRspInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldRspInfo) <= 0)
	{
		return;
	}

	printf(
		"OnRspError %d %s\n",
		fieldRspInfo.ErrorID.getValue(),
		fieldRspInfo.ErrorMsg.getValue());
}

void CFibClient2::OnRspUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
	CFPPRspInfoField fieldRspInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldRspInfo) <= 0)
	{
		return;
	}

	printf("OnRspUserLogin %d %s\n",
		fieldRspInfo.ErrorID.getValue(),
		fieldRspInfo.ErrorMsg.getValue());

	CFPPRspUserLoginField fieldUserLogin;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldUserLogin);
	if (fieldRspInfo.ErrorID != 0)
	{
		return;
	}

	m_strFlowPath = m_strBaseFlowPath;

	//	m_strFlowPath += fieldUserLogin.TradingDay;
	//	m_strFlowPath += "/";
	if (::access(m_strFlowPath.c_str(), 0))
	{
		if (MKDIR(m_strFlowPath.c_str(), 0700))
		{
			printf("Failed to create dir %s, quit.\n", m_strFlowPath.c_str());
			exit(-1);
		}
	}

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

	time_t	timep;
	time(&timep);
	printf("datetime: %s\ng_strTryDate: %s  UserLogin.TradingDay: %s\n", ctime(&timep), g_strTryDate.c_str(), fieldUserLogin.TradingDay.getValue());

	// NS-1400监控系统7*24运行模式下会员席位数统计异常
	//if (!g_strTryDate.empty() &&	g_strTryDate.compare( fieldUserLogin.TradingDay.getValue() ) != 0 )
	if (strcmp(g_strTryDate.c_str(), fieldUserLogin.TradingDay.getValue()) < 0)
	{
		/// 更新前交易日已记录的席位及登录信息
		ReloadHistoryData();

		/// Mod by Henchi, 20140620
		ClearStatInfo();
		ResetSubscriber();

		/// 通知事件服务及前置切换交易日
		if (m_pEvtSrv)
		{
			m_pEvtSrv->ChangeTradeDayOnFibNotify(
				g_strTryDate,
				fieldUserLogin.TradingDay.getValue());
			m_pEvtSrv->SendMemberPeak();
		}
		if (m_pFrontSrv)
		{
			m_pFrontSrv->NotifyFrontNewTradeDay(
				g_strTryDate,
				fieldUserLogin.TradingDay.getValue());
		}

		time(&timep);
		g_strTryDate = fieldUserLogin.TradingDay.getValue();
		printf("TradingDay change to [%s] at time [%s]\n", fieldUserLogin.TradingDay.getValue(), ctime(&timep));
	}
	/// 重新发起流水订阅请求
	ReqSubscribe();
}

void CFibClient2::OnRspSubscribe(
								CFTDCPackage *pFTDCPackage,
								CFTDCSession *pSession)
{
	CFPPRspInfoField fieldRspInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldRspInfo) <= 0)
	{
		return;
	}

	printf(
		"OnRspSubscribe %d %s\n",
		fieldRspInfo.ErrorID.getValue(),
		fieldRspInfo.ErrorMsg.getValue());
	if (fieldRspInfo.ErrorID != 0)
	{
		return;
	}

	CSubscriberMap::iterator itor = m_mapSubscriber.begin();
	for (; itor != m_mapSubscriber.end(); itor++)
	{
		CFPPSubscriber	*pSubscriber = (*itor).second;
		pSession->RegisterSubscriber(pSubscriber);
	}
}
