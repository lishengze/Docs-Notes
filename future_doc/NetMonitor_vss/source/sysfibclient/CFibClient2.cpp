/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CFibClient2.cpp
///@brief	ʵ���˶���������fibproxy�Ự���ӿͻ���
///@history	
///20080624	����		�������ļ�
///20080624	����		�޶�ע��
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

// ��ʷ�Ļ�Աϯλ���ֵ����
extern MemberSeatData  g_HistoryMemberSizeTotal_N;
extern MemberSeatData  g_HistoryUserSessionSizeTotal_N;
extern MemberSeatData  g_HistoryMemberSizeTotal_D;
extern MemberSeatData  g_HistoryUserSessionSizeTotal_D;

extern const char	*INI_FILE_NAME;

///������¼����������������
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
	//���proxy��ˮ
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
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);

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
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);

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
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
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

	time_t	timep;
	time(&timep);
	printf("datetime: %s\ng_strTryDate: %s  UserLogin.TradingDay: %s\n", ctime(&timep), g_strTryDate.c_str(), fieldUserLogin.TradingDay.getValue());

	// NS-1400���ϵͳ7*24����ģʽ�»�Աϯλ��ͳ���쳣
	//if (!g_strTryDate.empty() &&	g_strTryDate.compare( fieldUserLogin.TradingDay.getValue() ) != 0 )
	if (strcmp(g_strTryDate.c_str(), fieldUserLogin.TradingDay.getValue()) < 0)
	{
		/// ����ǰ�������Ѽ�¼��ϯλ����¼��Ϣ
		ReloadHistoryData();

		/// Mod by Henchi, 20140620
		ClearStatInfo();
		ResetSubscriber();

		/// ֪ͨ�¼�����ǰ���л�������
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
	/// ���·�����ˮ��������
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
