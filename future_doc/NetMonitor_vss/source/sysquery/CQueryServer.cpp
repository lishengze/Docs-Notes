/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	FrontServer.cpp
///@brief	ʵ����ǰ�ü�����ؿͻ�������ʹ�õ���
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#pragma warning(disable : 4786)
#include "CQueryServer.h"
#include "COrderRttManager.h"
#include "CStatusSubscriber.h"
#include <FTDDataWrapper.h>
#include <FTDDataHelper.h>
#include <CDeployConfig.h>
#include <StringUtil.h>
#include <UFEntityCopy.h>

extern COrderRttAnalysis *g_OrderRttAnalysis;
extern map<CPeakKey, CFTDRtnHistoryTradePeakField>	g_mapTradePeak; // ָ����ʷ���ֵmap
extern CStatusSubscriber *g_pStatusSubcriber;
extern CJudgeRun *g_pJudgeRun;		// ȫ��ʱ����жϴ������ֻ��һ�ι���
extern int	g_nTimeZoneSec;			//��������ʱ��

//20080714 add wu.yb
extern string g_strDbIp;
extern string g_strDbPort;
extern string g_strDbName;
extern string g_strDbUser;
extern string g_strDbPwd;
extern CSlogQuery *g_pSlogQuery;	// Slog��ѯ����ʵ��ָ��
#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pPackOutput;		// ���ݰ�������ļ�
#endif

//////////////////////////////////////////////////////////////////////////
//20121023 feng.q
extern COrderRttAnalysis *g_OrderRttAnalysis;

//������Ӧ�ֲ����и���
extern unsigned int g_nRttCutLine[8];

//////////////////////////////////////////////////////////////////////////
CQueryTimmer::CQueryTimmer(CReactor *pReactor, CQueryServer *pQuery) :
	CEventHandler(pReactor),
	m_pQueryServer(pQuery)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
}

void CQueryTimmer::SetTimer(int nIDEvent, int nElapse)
{
	m_nEventId = nIDEvent;
	CEventHandler::SetTimer(nIDEvent, nElapse);
}

void CQueryTimmer::OnTimer(int nIDEvent)
{
	switch (nIDEvent)
	{
		case 1:
			//����ͳ�Ʋ���Ҫд�����ݿⱣ�� by zhoujianjun 20080812
			//g_OrderRttAnalysis->putRttAnalysisToDB();
			if (g_pStatusSubcriber != NULL)
			{
				g_pStatusSubcriber->UpdateParticTrade2DbByTimer();
			}

			break;
		case 2:
			break;
			if (g_pStatusSubcriber != NULL && g_pJudgeRun)
			{
				time_t	timep = time((time_t *)NULL);
				timep = timep - g_nTimeZoneSec;
				g_pStatusSubcriber->SetTryConnectDbFlag(
						true,
						g_pJudgeRun->needExcute(timep));
			}

			break;
		case 3:
			if (g_pStatusSubcriber != NULL)
			{
				time_t	timep = time((time_t *)NULL);
				timep = timep - g_nTimeZoneSec;
				g_pStatusSubcriber->CheckObjectAttrOutput(timep);
				g_pStatusSubcriber->CheckEventCount(timep);
			}

			break;
		case 4:
			if (m_pQueryServer)
			{
				m_pQueryServer->CheckTradeFrontRtt();
			}

			break;
		default:
			break;
	}

	return;
}

CQueryServer::CQueryServer(CReactor *pReactor) :
	CAgentSessionFactory(pReactor, 10),
	m_eventTimer(pReactor, this),
	m_sqlConnect(NULL)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);

	m_eventTimer.SetTimer(1, 2 * 60 * 1000);	// ÿ����ͳ��һ��ǰ�õ���Ӧʱ��
	m_eventTimer.SetTimer(2, 60 * 1000);
	m_eventTimer.SetTimer(3, 500);				// ÿ�����ּ��һ�¼��ָ�����Ϣ�ļ����
	m_eventTimer.SetTimer(4, 1000);				//ÿ����rtt
	m_hander.SetOperateMaster("CQueryServer",NULL);
	bool bRst = m_hander.Open(
			g_strDbIp,
			g_strDbPort,
			g_strDbName,
			g_strDbUser,
			g_strDbPwd);
}

CQueryServer::~CQueryServer(void)
{
	delete m_sqlConnect;
}

CSession *CQueryServer::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);

	/// Added by Henchi, 20120309
	pSession->SetCompressMethod(CRPCM_ZERO);	//����ѹ���㷨
	return pSession;
}

void CQueryServer::OnSessionConnected(CSession *pSession)
{
	CSessionFactory::OnSessionConnected(pSession);
	printf(
		"\tCCountConnector::OnSessionConnected: %0x\n",
		(CFTDCSession *)pSession);

	m_frontSessions.push_back((CFTDCSession *)pSession);

	/// ��ȡUserInfo�������
	int ret = 0;
	list<CFTDRtnSysUserField *> userList;
	ret = getUserInfoList(userList);

	CFTDCSession *pFtdSession = dynamic_cast<CFTDCSession *>(pSession);

	/// ���û����ݴ�����͸�Session
	m_pkgSend.PreparePackage(
			FTD_TID_RtnSysUser,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	list<CFTDRtnSysUserField *>::iterator it;
	for (it = userList.begin(); it != userList.end(); ++it)
	{
		if (m_pkgSend.Length() +
			sizeof(CFTDRtnSysUserField) > FTDC_PACKAGE_MAX_SIZE)
		{
			// ���ݰ������������ˣ����з���,ÿһ�ε����ݰ����֧��4000�ֽ�
			pFtdSession->SendRequestPackage(&m_pkgSend);
			m_pkgSend.PreparePackage(
					FTD_TID_RtnSysUser,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
		}

		FTDC_ADD_FIELD(&m_pkgSend, *it);
	}

	if (!userList.empty())
	{
		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		pFtdSession->SendRequestPackage(&m_pkgSend);
	}

	for (it = userList.begin(); it != userList.end(); ++it)
	{
		delete *it;
	}

	userList.clear();

	// �� g_mapTradePeak �����е����ݷ��͵���¼��ǰ�� 20081216 by zhou.jj
	map<CPeakKey, CFTDRtnHistoryTradePeakField>::iterator mit;
	for (mit = g_mapTradePeak.begin(); mit != g_mapTradePeak.end(); mit++)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RtnHistoryTradePeakTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &(mit->second));

		//m_pkgSend.MakePackage(); ���������������ݰ���Ҫִ��MakePackage����
		pFtdSession->SendRequestPackage(&m_pkgSend);
	}

	///���͵�ǰ��ͳ������
	{
		CFTDRtnTradeOrderRttCutLineField rtnCutLine;
		m_pkgSend.PreparePackage(
				FTD_TID_RtnTradeOrderRttCutLineTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		string	strTmpCutLine;
		for (int i = 0;
			 i < sizeof(g_nRttCutLine) / sizeof(unsigned int)
		 &&	 ((unsigned int) -1 != g_nRttCutLine[i]);
		 i++)
		{
			if (strTmpCutLine.length() > 0)
			{
				strTmpCutLine += ",";
			}

			char tmpnum[16];
			sprintf(tmpnum, "%u", g_nRttCutLine[i]);
			strTmpCutLine += tmpnum;
		}

		rtnCutLine.OrderRttCutLine = strTmpCutLine.data();

		//ǰ��ֻ�е��콻������, ������Ϊ��
		rtnCutLine.MonDate = "";

		FTDC_ADD_FIELD(&m_pkgSend, &rtnCutLine);
		pFtdSession->SendRequestPackage(&m_pkgSend);
	}

	//��ǰ������rtt����
	{
		map<int, CRttInSec4Front> &OrdRttMap = g_OrderRttAnalysis->
			GetOrderRttMap();
		map<int, CRttInSec4Front>::iterator m_Iter2;
		CFTDRtnTradeFrontOrderRttStatField	rtnField;
		for (m_Iter2 = OrdRttMap.begin(); m_Iter2 != OrdRttMap.end(); m_Iter2++)
		{
			CRttInSec4Front &OrderRtt = m_Iter2->second;

			map<string, CRttInSecond>::iterator m_Iter;
			for (m_Iter = OrderRtt.mapRttStatis.begin();
				 m_Iter != OrderRtt.mapRttStatis.end();
				 m_Iter++)
			{
				string	strTimeIndex = m_Iter->first;

				m_pkgSend.PreparePackage(
						FTD_TID_RtnTradeFrontOrderRttStatTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);

				memset(
					&rtnField,
					0,
					sizeof(CFTDRtnTradeFrontOrderRttStatField));

				sprintf(
					(char *)rtnField.ObjectID.getValue(),
					"%d",
					m_Iter2->first);
				rtnField.MonDate = "";
				strcpy(
					(char *)(rtnField.MonTime.getValue()),
					strTimeIndex.data());

				rtnField.OrderCount = m_Iter->second.nCount;
				rtnField.OrderRttSum = m_Iter->second.nRttSum;
				rtnField.OrderMinRtt = m_Iter->second.nMinRtt;
				rtnField.OrderMaxRtt = m_Iter->second.nMaxRtt;
				rtnField.OrderRttSqu = 0;

				sprintf(
					(char *)(rtnField.OrderRttCutDistrib.getValue()),
					"%lld;%lld;%lld;%lld;%lld;%lld;%lld;%lld",
					m_Iter->second.nDistribution[0],
					m_Iter->second.nDistribution[1],
					m_Iter->second.nDistribution[2],
					m_Iter->second.nDistribution[3],
					m_Iter->second.nDistribution[4],
					m_Iter->second.nDistribution[5],
					m_Iter->second.nDistribution[6],
					m_Iter->second.nDistribution[7]);

				FTDC_ADD_FIELD(&m_pkgSend, &rtnField);
				pFtdSession->SendRequestPackage(&m_pkgSend);
			}
		}
	}
}

void CQueryServer::OnSessionDisconnected(CSession *pSession, int nReason)	// �������ش������ӶϿ��¼�
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// ������ø��ദ�����ӶϿ��¼�
	printf(
		"\tCFrontServer::OnSessionDisconnected CFTDCSession remove %0x\n",
		(CFTDCSession *)pSession);
	m_frontSessions.remove((CFTDCSession *)pSession);
}

void CQueryServer::NotifyAllSession(CFTDCPackage *pkg)
{
	assert(pkg);

	list<CFTDCSession *>::iterator	it;
	for (it = m_frontSessions.begin(); it != m_frontSessions.end(); it++)
	{
		(*it)->SendRequestPackage(pkg);
		pkg->Pop(FTDCHLEN);
	}
}

int CQueryServer::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
	pFTDCPackage->OutputHeader(g_pPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pPackOutput);
#endif
	printf("\tCFrontServer::receive package TID %x\n", pFTDCPackage->GetTID());
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_ReqQryHistoryObjectAttrTopic:
			OnReqQryHistoryObjectAttr(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryWarningEventTopic:
			OnReqQryWarningEvent(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryFrontInfoTopic:
			OnReqQryFrontInfo(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTradeLogTopic:
			OnReqQryTradeLog(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetDeviceLinkedTopic:
			// ����ĳ��ԭ����ʱ������FTD_TID_ReqQryNetDeviceLinkedTopic��ΪqueryLatestSlog�Ĳ�ѯ����
			OnReqQryLatestTradeLog(pFTDCPackage, pSession);
			break;

		///20080721 add by wu.yb
		case FTD_TID_ReqQrySysUserRegisterTopic:				///�û�ע��
			OnReqQrySysUserRegister(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQrySysUserLoginTopic:					///�û���¼��ѯ
			OnReqQrySysUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQrySysUserLogoutTopic:					///�û��ǳ�
			OnReqQrySysUserLogout(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQrySysUserPasswordUpdateTopic:			///�û��޸�����
			OnReqQrySysUserPasswordUpdate(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQrySysUserDeleteTopic:					///ɾ���û�
			OnReqQrySysUserDelete(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryHistoryCpuInfoTopic:					///��ʷCpu״̬��ѯ
			OnReqQryHistoryCpuInfo(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryHistoryMemInfoTopic:					///��ʷMem״̬��ѯ
			OnReqQryHistoryMemInfo(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryHistoryNetworkInfoTopic:				///��ʷ����״̬��ѯ
			OnReqQryHistoryNetworkInfo(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryWebVisitTopic:						/// ��վ����ͳ����Ϣ��ѯ
			OnReqQryWebVisitInfo(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetMonitorTaskResultTopic:			/// ��ʷѲ������ѯ
			OnReqQryNetMonitorTaskResult(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetBaseLineResultTopic:
			OnReqQryNetBaseLineResult(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTradeFrontOrderRttStatTopic:
			OnReqQryTradeFrontOrderRttStat(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetLocalPingResultInfoTopic:
			OnReqQryNetLocalPingResult(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetRomotePingResultInfoTopic:
			OnReqQryNetRomotePingResultInfo(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryRouterInfoTopic:
			OnReqQryRouterInfoInfo(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryDiskIOTopic:
			OnReqQryDiskIOInfo(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryStatInfoTopic:
			OnReqQryStatInfoInfo(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTopProcessInfoTopic:
			OnReqQryTopProcessInfo(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTradeOrderRttCutLineTopic:
			OnReqQryOrderRttCutLine(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryParticTradeOrderStatesTopic:
			OnReqQryParticTradeOrderStates(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryPerformanceTopTopic:
			OnReqQryPerformanceTopTopic(pFTDCPackage, pSession);
			break;
		default:
			break;
	}

	return 0;
}

void CQueryServer::OnReqQryRouterInfoInfo(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryRouterInfoField req;
	CFTDRspQryRouterInfoField rsp;

	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &req);

	int totalSize = 0;
	int messageSize = sizeof(rsp);

	CFTDRspInfoField msg;
	memset(&msg, 0, sizeof(CFTDRspInfoField));

	int mPackSend = 0;
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryRouterInfoTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	try
	{
		//����Oracle���ݿ�
		if (!connectDB())
		{
			return;
		}

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);

		string	sql;
		sql = "select * from ";
		sql += "T_Routerinfo";
		sql += " where HostName = :1";
		if (req.StartDate != req.EndDate)
		{
			sql += " and (MonDate >= :2 and MonDate<= :3)  order  by MonDate, MonTime ";
			cmd.setCommandText(sql.c_str());
			cmd << req.HostName << req.StartDate << req.EndDate;
		}
		else
		{
			sql += " and MonDate= :2   order  by MonDate, MonTime ";
			cmd.setCommandText(sql.c_str());
			cmd << req.HostName << req.StartDate;
		}

		cmd.Execute();

		int cnt = 0;
		while (cmd.FetchNext())
		{
			if (mPackSend >= MAXQRYRETURNNUM)
			{
				m_pkgSend.PrepareResponse(
						pFTDCPackage,
						FTD_TID_RspQryRouterInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				msg.ErrorID = ERR_REACHMAXRECORDNUM;
				msg.ErrorMsg = "�����Ѿ��ﵽ����¼��";
				FTDC_ADD_FIELD(&m_pkgSend, &msg);
				pSession->SendRequestPackage(&m_pkgSend);
				return;
			}

			if (totalSize != 0)
			{	// �м�¼������Ҫ����
				FTDC_ADD_FIELD(&m_pkgSend, &rsp);
				if (!(totalSize < (FTDC_PACKAGE_MAX_SIZE - messageSize)))
				{
					// ���ݰ������������ˣ����з���,ÿһ�ε����ݰ����֧��4000�ֽ�
					pSession->SendRequestPackage(&m_pkgSend);
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryRouterInfoTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);

					totalSize = 0;
				}
			}

			mPackSend++;

			/// ��ȡ����
			GetRow(&cmd, (char *) &rsp, &rsp.m_Describe);
			totalSize += messageSize;
			cnt++;
		}

		if (totalSize != 0)
		{
			FTDC_ADD_FIELD(&m_pkgSend, &rsp);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		if (cnt)
		{
			msg.ErrorID = DBMSG_SUC_SUCCESS;
			msg.ErrorMsg = "db query finish";
		}
		else
		{
			msg.ErrorID = DBMSG_SUC_NORECORD;
			msg.ErrorMsg = "not exists record";
		}

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		msg.ErrorID = DBMSG_ERR_EXCEPTION;
		msg.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CQueryServer::OnReqQryDiskIOInfo(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryDiskIOField req;
	CFTDRspQryDiskIOField rsp;

	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &req);

	int totalSize = 0;
	int messageSize = sizeof(rsp);

	CFTDRspInfoField msg;
	memset(&msg, 0, sizeof(CFTDRspInfoField));

	int mPackSend = 0;
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryDiskIOTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	try
	{
		//����Oracle���ݿ�
		if (!connectDB())
		{
			return;
		}

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);

		string	sql;
		sql = "select * from ";
		sql += "T_Diskio";
		sql += " where HostName = :1";
		if (req.StartDate != req.EndDate)
		{
			sql += " and (MonDate >= :2 and MonDate<= :3) order by MonDate, MonTime ";
			cmd.setCommandText(sql.c_str());
			cmd << req.HostName << req.StartDate << req.EndDate;
		}
		else
		{
			sql += " and MonDate= :2 order  by MonDate, MonTime ";
			cmd.setCommandText(sql.c_str());
			cmd << req.HostName << req.StartDate;
		}

		cmd.Execute();

		int cnt = 0;
		while (cmd.FetchNext())
		{
			if (mPackSend >= MAXQRYRETURNNUM)
			{
				m_pkgSend.PrepareResponse(
						pFTDCPackage,
						FTD_TID_RspQryDiskIOTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				msg.ErrorID = ERR_REACHMAXRECORDNUM;
				msg.ErrorMsg = "�����Ѿ��ﵽ����¼��";
				FTDC_ADD_FIELD(&m_pkgSend, &msg);
				pSession->SendRequestPackage(&m_pkgSend);
				return;
			}

			if (totalSize != 0)
			{	// �м�¼������Ҫ����
				FTDC_ADD_FIELD(&m_pkgSend, &rsp);
				if (!(totalSize < (FTDC_PACKAGE_MAX_SIZE - messageSize)))
				{
					// ���ݰ������������ˣ����з���,ÿһ�ε����ݰ����֧��4000�ֽ�
					pSession->SendRequestPackage(&m_pkgSend);
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryDiskIOTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);

					totalSize = 0;
				}
			}

			mPackSend++;

			/// ��ȡ����
			GetRow(&cmd, (char *) &rsp, &rsp.m_Describe);
			totalSize += messageSize;
			cnt++;
		}

		if (totalSize != 0)
		{
			FTDC_ADD_FIELD(&m_pkgSend, &rsp);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		if (cnt)
		{
			msg.ErrorID = DBMSG_SUC_SUCCESS;
			msg.ErrorMsg = "db query finish";
		}
		else
		{
			msg.ErrorID = DBMSG_SUC_NORECORD;
			msg.ErrorMsg = "not exists record";
		}

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		msg.ErrorID = DBMSG_ERR_EXCEPTION;
		msg.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CQueryServer::OnReqQryStatInfoInfo(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryStatInfoField req;
	CFTDRspQryStatInfoField rsp;

	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &req);

	int totalSize = 0;
	int messageSize = sizeof(rsp);

	CFTDRspInfoField msg;
	memset(&msg, 0, sizeof(CFTDRspInfoField));

	int mPackSend = 0;
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryStatInfoTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	try
	{
		//����Oracle���ݿ�
		if (!connectDB())
		{
			return;
		}

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);

		string	sql;
		sql = "select * from ";
		sql += "T_Statinfo";
		sql += " where HostName = :1";
		if (req.StartDate != req.EndDate)
		{
			sql += " and (MonDate >= :2 and MonDate<= :3)  order  by MonDate, MonTime ";
			cmd.setCommandText(sql.c_str());
			cmd << req.HostName << req.StartDate << req.EndDate;
		}
		else
		{
			sql += " and MonDate= :2   order  by MonDate, MonTime ";
			cmd.setCommandText(sql.c_str());
			cmd << req.HostName << req.StartDate;
		}

		cmd.Execute();

		int cnt = 0;
		while (cmd.FetchNext())
		{
			if (mPackSend >= MAXQRYRETURNNUM)
			{
				m_pkgSend.PrepareResponse(
						pFTDCPackage,
						FTD_TID_RspQryStatInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				msg.ErrorID = ERR_REACHMAXRECORDNUM;
				msg.ErrorMsg = "�����Ѿ��ﵽ����¼��";
				FTDC_ADD_FIELD(&m_pkgSend, &msg);
				pSession->SendRequestPackage(&m_pkgSend);
				return;
			}

			if (totalSize != 0)
			{	// �м�¼������Ҫ����
				FTDC_ADD_FIELD(&m_pkgSend, &rsp);
				if (!(totalSize < (FTDC_PACKAGE_MAX_SIZE - messageSize)))
				{
					// ���ݰ������������ˣ����з���,ÿһ�ε����ݰ����֧��4000�ֽ�
					pSession->SendRequestPackage(&m_pkgSend);
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryStatInfoTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);

					totalSize = 0;
				}
			}

			mPackSend++;

			/// ��ȡ����
			GetRow(&cmd, (char *) &rsp, &rsp.m_Describe);
			totalSize += messageSize;
			cnt++;
		}

		if (totalSize != 0)
		{
			FTDC_ADD_FIELD(&m_pkgSend, &rsp);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		if (cnt)
		{
			msg.ErrorID = DBMSG_SUC_SUCCESS;
			msg.ErrorMsg = "db query finish";
		}
		else
		{
			msg.ErrorID = DBMSG_SUC_NORECORD;
			msg.ErrorMsg = "not exists record";
		}

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		msg.ErrorID = DBMSG_ERR_EXCEPTION;
		msg.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CQueryServer::OnReqQryTopProcessInfo(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryTopProcessInfoField req;
	CFTDRspQryTopProcessInfoField rsp;

	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &req);

	int totalSize = 0;
	int messageSize = sizeof(rsp);

	CFTDRspInfoField msg;
	memset(&msg, 0, sizeof(CFTDRspInfoField));

	int mPackSend = 0;
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryTopProcessInfoTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	try
	{
		//����Oracle���ݿ�
		if (!connectDB())
		{
			return;
		}

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);

		string	sql;
		sql = "select * from ";
		sql += "T_TopProcessInfo";
		sql += " where HostName = :1";
		if (req.StartDate != req.EndDate)
		{
			sql += " and (MonDate >= :2 and MonDate<= :3)  order  by MonDate, MonTime ";
			cmd.setCommandText(sql.c_str());
			cmd << req.HostName << req.StartDate << req.EndDate;
		}
		else
		{
			sql += " and MonDate= :2   order  by MonDate, MonTime ";
			cmd.setCommandText(sql.c_str());
			cmd << req.HostName << req.StartDate;
		}

		cmd.Execute();

		int cnt = 0;
		while (cmd.FetchNext())
		{
			if (mPackSend >= MAXQRYRETURNNUM)
			{
				m_pkgSend.PrepareResponse(
						pFTDCPackage,
						FTD_TID_RspQryTopProcessInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				msg.ErrorID = ERR_REACHMAXRECORDNUM;
				msg.ErrorMsg = "�����Ѿ��ﵽ����¼��";
				FTDC_ADD_FIELD(&m_pkgSend, &msg);
				pSession->SendRequestPackage(&m_pkgSend);
				return;
			}

			if (totalSize != 0)
			{	// �м�¼������Ҫ����
				FTDC_ADD_FIELD(&m_pkgSend, &rsp);
				if (!(totalSize < (FTDC_PACKAGE_MAX_SIZE - messageSize)))
				{
					// ���ݰ������������ˣ����з���,ÿһ�ε����ݰ����֧��4000�ֽ�
					pSession->SendRequestPackage(&m_pkgSend);
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryTopProcessInfoTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);

					totalSize = 0;
				}
			}

			mPackSend++;

			/// ��ȡ����
			GetRow(
				&cmd,
				(char *) &rsp,
				&CFTDRtnMonitorTopProcessInfoField::m_Describe);
			totalSize += messageSize;
			cnt++;
		}

		if (totalSize != 0)
		{
			FTDC_ADD_FIELD(&m_pkgSend, &rsp);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		if (cnt)
		{
			msg.ErrorID = DBMSG_SUC_SUCCESS;
			msg.ErrorMsg = "db query finish";
		}
		else
		{
			msg.ErrorID = DBMSG_SUC_NORECORD;
			msg.ErrorMsg = "not exists record";
		}

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		msg.ErrorID = DBMSG_ERR_EXCEPTION;
		msg.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CQueryServer::OnReqQryParticTradeOrderStates(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryParticTradeOrderStatesField req;
	CFTDRspQryParticTradeOrderStatesField rsp;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &req) <= 0)
	{
		return;
	}

	int totalSize = 0;
	int messageSize = sizeof(rsp);

	CFTDRspInfoField msg;
	memset(&msg, 0, sizeof(CFTDRspInfoField));

	int mPackSend = 0;
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryParticTradeOrderStatesTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	try
	{
		//����Oracle���ݿ�
		if (!connectDB())
		{
			return;
		}

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);

		string	sql;
		sql = "Select Participantid, Userid, :1 As Mondate, ' ' As Montime, 0 As Staticwidth, 0 As Frontid,  \
			Sum(Ordercount) As Ordercount, Sum(Canclecount) As Canclecount, Sum(Querycount) As Querycount, Sum(Tradecount) As Tradecount, Sum(Trademoney) As Trademoney,  \
			max(OrderCntMax) as OrderCntMax, max(CancleCntMax) as CancleCntMax, max(QueryCntMax) as QueryCntMax, max(TradeCntMax) as TradeCntMax, max(TradeMoneyMax) as TradeMoneyMax \
			From T_Syspartictradeorderstates \
			where Mondate = :2 \
			Group By Participantid, Userid";
		cmd.setCommandText(sql.c_str());
		cmd << req.MonDate;
		cmd << req.MonDate;

		cmd.Execute();

		int cnt = 0;
		while (cmd.FetchNext())
		{
			if (mPackSend >= MAXQRYRETURNNUM)
			{
				m_pkgSend.PrepareResponse(
						pFTDCPackage,
						FTD_TID_RspQryParticTradeOrderStatesTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				msg.ErrorID = ERR_REACHMAXRECORDNUM;
				msg.ErrorMsg = "�����Ѿ��ﵽ����¼��";
				FTDC_ADD_FIELD(&m_pkgSend, &msg);
				pSession->SendRequestPackage(&m_pkgSend);
				return;
			}

			if (totalSize != 0)
			{	// �м�¼������Ҫ����
				FTDC_ADD_FIELD(&m_pkgSend, &rsp);
				if (!(totalSize < (FTDC_PACKAGE_MAX_SIZE - messageSize)))
				{
					// ���ݰ������������ˣ����з���,ÿһ�ε����ݰ����֧��4000�ֽ�
					pSession->SendRequestPackage(&m_pkgSend);
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryParticTradeOrderStatesTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);

					totalSize = 0;
				}
			}

			mPackSend++;

			/// ��ȡ����
			GetRow(
				&cmd,
				(char *) &rsp,
				&CFTDRtnParticTradeOrderStatesField::m_Describe);
			totalSize += messageSize;
			cnt++;
		}

		if (totalSize != 0)
		{
			FTDC_ADD_FIELD(&m_pkgSend, &rsp);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		if (cnt)
		{
			msg.ErrorID = DBMSG_SUC_SUCCESS;
			msg.ErrorMsg = "db query finish";
		}
		else
		{
			msg.ErrorID = DBMSG_SUC_NORECORD;
			msg.ErrorMsg = "not exists record";
		}

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		msg.ErrorID = DBMSG_ERR_EXCEPTION;
		msg.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CQueryServer::OnReqQryOrderRttCutLine(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryTradeOrderRttCutLineField req;
	CFTDRspQryTradeOrderRttCutLineField rsp;

	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &req);

	CFTDRspInfoField msg;
	memset(&msg, 0, sizeof(CFTDRspInfoField));

	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryTradeOrderRttCutLineTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	try
	{
		//����Oracle���ݿ�
		if (!connectDB())
		{
			return;
		}

		bool bRstIst = false;
		if (req.OrderRttCutLine != "")
		{
			if (g_pStatusSubcriber)
			{
				bRstIst = g_pStatusSubcriber->InsertNewCutLine2DB(
						req.MonDate.getValue(),
						req.UserName.getValue(),
						req.OrderRttCutLine.getValue());
			}
		}
		else
		{
			SACommand cmd;
			cmd.setConnection(m_sqlConnect);

			string	sql;

			//��ѯ
			sql = "select * from T_SYSTRADEORDERRTTCUTLINE where MonDate <= :1 order by MonDate desc, MonTime desc";
			cmd.setCommandText(sql.c_str());
			cmd << req.MonDate;

			cmd.Execute();
			while (cmd.FetchNext())
			{
				GetRow(&cmd, (char *) &rsp, &rsp.m_Describe);

				rsp.MonDate = req.MonDate;
				FTDC_ADD_FIELD(&m_pkgSend, &rsp);
				pSession->SendRequestPackage(&m_pkgSend);
				bRstIst = true;
				break;
			}
		}

		if (bRstIst)
		{
			msg.ErrorID = DBMSG_SUC_SUCCESS;
			msg.ErrorMsg = "db query finish";
		}
		else
		{
			msg.ErrorID = DBMSG_SUC_NORECORD;
			msg.ErrorMsg = "not exists record";
		}

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		msg.ErrorID = DBMSG_ERR_EXCEPTION;
		msg.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CQueryServer::OnReqQryWebVisitInfo(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
#endif

	CFTDReqQryWebVisitField fieldInfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

#ifdef PRINT_DEBUG
	printf(
		"Get ReqDBQuery :%s %s %s %s %s %s\n",
		(char *)fieldInfo.ObjectID.getValue(),
		(char *)fieldInfo.AttrType.getValue(),
		(char *)fieldInfo.BeginDate.getValue(),
		(char *)fieldInfo.BeginTime.getValue(),
		(char *)fieldInfo.EndDate.getValue(),
		(char *)fieldInfo.EndTime.getValue());
#endif

	//����Oracle���ݿ�
	if (!connectDB())
	{
		return;
	}

	SACommand cmd;
	cmd.setConnection(m_sqlConnect);
	if (strncmp((char *)fieldInfo.AttrType.getValue(), "Daily", 5) == 0)
	{
		// ��ͳ�Ʋ�ѯ��ʱ�䲻��Ч
		cmd.setCommandText(
				"select * from t_AccessLogStatInfo where ObjectID = :1 and AttrType = :2 and (MonDate >= :3 and MonDate <= :4 ) order by MonDate, MonTime ASC");
		cmd <<
			fieldInfo.ObjectID <<
			fieldInfo.AttrType <<
			fieldInfo.BeginDate <<
			fieldInfo.EndDate;
	}
	else
	{
		cmd.setCommandText(
				"select * from t_AccessLogStatInfo where ObjectID = :1 and AttrType = :2 and (MonDate >= :3 and MonDate <= :4 )and (MonTime >= :5 and MonTime <= :6 ) order by MonDate, MonTime ASC");
		cmd <<
			fieldInfo.ObjectID <<
			fieldInfo.AttrType <<
			fieldInfo.BeginDate <<
			fieldInfo.EndDate <<
			fieldInfo.BeginTime <<
			fieldInfo.EndTime;
	}

	int totalSize = 0;
	int messageSize = sizeof(CFTDRspQryDBQueryField);

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));

	CFTDRspQryDBQueryField	rspFieldInfo;
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryDBQueryTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	int cnt = 0;
	try
	{
		cmd.Execute();
		while (cmd.FetchNext())
		{
			rspFieldInfo.ObjectID = cmd.Field("ObjectID").asString();
			rspFieldInfo.AttrType = cmd.Field("AttrType").asString();
			rspFieldInfo.MonDate = cmd.Field("MonDate").asString();
			rspFieldInfo.MonTime = cmd.Field("MonTime").asString();
			rspFieldInfo.DBQueryResult = cmd.Field("DBQueryResult").asString();

			rspFieldInfo.ObjectID.trimRight();
			rspFieldInfo.AttrType.trimRight();
			rspFieldInfo.MonDate.trimRight();
			rspFieldInfo.MonTime.trimRight();
			rspFieldInfo.DBQueryResult.trimRight();
			FTDC_ADD_FIELD(&m_pkgSend, &rspFieldInfo);
			pSession->SendRequestPackage(&m_pkgSend);
			m_pkgSend.PrepareResponse(
					pFTDCPackage,
					FTD_TID_RspQryDBQueryTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
#ifdef PRINT_DEBUG
			printf(
				"find Record: %s %s %s %s \n%s\n",
				(char *)rspFieldInfo.ObjectID.getValue(),
				(char *)rspFieldInfo.AttrType.getValue(),
				(char *)rspFieldInfo.MonDate.getValue(),
				(char *)rspFieldInfo.MonTime.getValue(),
				(char *)rspFieldInfo.DBQueryResult.getValue());
#endif
			cnt++;
		}

		if (cnt)
		{
			rspInfoField.ErrorID = DBMSG_SUC_SUCCESS;
			rspInfoField.ErrorMsg = "db query finish";
		}
		else
		{
			rspInfoField.ErrorID = DBMSG_SUC_NORECORD;
			rspInfoField.ErrorMsg = "not exists record";
		}

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		rspInfoField.ErrorID = DBMSG_ERR_EXCEPTION;
		rspInfoField.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CQueryServer::OnReqQryTradeLog(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	g_pSlogQuery->querySlog(pFTDCPackage, pSession);
}

void CQueryServer::OnReqQryLatestTradeLog(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	g_pSlogQuery->queryLatestSlog(pFTDCPackage, pSession);
}

void CQueryServer::OnReqQryHistoryObjectAttr(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryHistoryObjectAttrField fieldInfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
#endif

	// ���� CFTDRspQryHistoryObjectAttrField �����з���,����һ�η��Ͷ������ֽ�����4000
	// zhou.jj 20090805 ע�͵��öδ��룬�ͻ��������Ѿ��ֿ�objectid��attrtype
	//char tmp[65];
	//strcpy(tmp, (char *)(fieldInfo.ObjectID.getValue()) );
	//if ( strcmp( (char *)(fieldInfo.AttrType.getValue() ),"")==0 ) {
	//	///��ΪObjectID������AttrType,�������� '.'�ָ�ģ����һ����AttrType
	//	char *lastDot = strrchr(tmp,'.');
	//	if ( lastDot ) {
	//		*lastDot = '\0';
	//		fieldInfo.ObjectID = tmp;
	//		lastDot++;
	//		fieldInfo.AttrType = lastDot;
	//	}
	//}
	int totalSize = 0;
	int messageSize = sizeof(CFTDRspQryHistoryObjectAttrField);

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));

	CFTDRspQryHistoryObjectAttrField rspFieldInfo;
	int mPackSend = 0;
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryHistoryObjectAttrTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	try
	{
		//����Oracle���ݿ�
		if (!connectDB())
		{
			return;
		}

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);

		if (fieldInfo.StartDate != fieldInfo.EndDate)
		{
			cmd.setCommandText(
					"select * from t_SysHistoryObjectAttr where ObjectID= :1 and AttrType= :2 and (MonDate >= :3 and MonDate<= :4) order by MONDATE,BEGINTIME");
			cmd <<
				fieldInfo.ObjectID <<
				fieldInfo.AttrType <<
				fieldInfo.StartDate <<
				fieldInfo.EndDate;
		}
		else
		{
			cmd.setCommandText(
					"select * from t_SysHistoryObjectAttr where ObjectID= :1 and AttrType= :2 and MonDate= :3 order by MONDATE,BEGINTIME");
			cmd <<
				fieldInfo.ObjectID <<
				fieldInfo.AttrType <<
				fieldInfo.StartDate;

			// modify by zhou.jj 20090330
			//cmd.setCommandText("select * from t_SysHistoryObjectAttr where ObjectID= :1 and AttrType= :2 and MonDate= :3 and  (BeginTime>= :4 and BeginTime <= :5) ");
			//cmd << fieldInfo.ObjectID << fieldInfo.AttrType << fieldInfo.StartDate << fieldInfo.StartTime << fieldInfo.EndTime;
		}

		cmd.Execute();

		int cnt = 0;
		while (cmd.FetchNext())
		{
			if (mPackSend >= MAXQRYRETURNNUM)
			{
				m_pkgSend.PrepareResponse(
						pFTDCPackage,
						FTD_TID_RspQryHistoryObjectAttrTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				rspInfoField.ErrorID = ERR_REACHMAXRECORDNUM;
				rspInfoField.ErrorMsg = "�����Ѿ��ﵽ����¼��";
				FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
				pSession->SendRequestPackage(&m_pkgSend);
				return;
			}

			if (totalSize != 0)
			{	// �м�¼������Ҫ����
				FTDC_ADD_FIELD(&m_pkgSend, &rspFieldInfo);
				if (!(totalSize < (FTDC_PACKAGE_MAX_SIZE - messageSize)))
				{
					// ���ݰ������������ˣ����з���,ÿһ�ε����ݰ����֧��4000�ֽ�
					pSession->SendRequestPackage(&m_pkgSend);
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryHistoryObjectAttrTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);

					totalSize = 0;
				}
			}

			mPackSend++;

			rspFieldInfo.MonDate = cmd.Field("MonDate").asString();
			rspFieldInfo.BeginTime = cmd.Field("BeginTime").asString();
			rspFieldInfo.EndTime = cmd.Field("EndTime").asString();
			rspFieldInfo.ObjectID = cmd.Field("ObjectID").asString();
			rspFieldInfo.AttrType = cmd.Field("AttrType").asString();
			rspFieldInfo.ValueType = cmd.Field("ValueType").asLong();
			rspFieldInfo.FirstValue = cmd.Field("FirstValue").asNumeric();	// asDouble();
			rspFieldInfo.EndValue = cmd.Field("EndValue").asNumeric();		// asDouble();
			rspFieldInfo.AvgValue = cmd.Field("AvgValue").asNumeric();		// asDouble();
			rspFieldInfo.MinValue = cmd.Field("MinValue").asNumeric();		// asDouble();
			rspFieldInfo.MaxValue = cmd.Field("MaxValue").asNumeric();		// asDouble();
			rspFieldInfo.ValueCount = cmd.Field("ValueCount").asLong();

			rspFieldInfo.MonDate.trimRight();
			rspFieldInfo.BeginTime.trimRight();
			rspFieldInfo.EndTime.trimRight();
			rspFieldInfo.ObjectID.trimRight();
			rspFieldInfo.AttrType.trimRight();

			totalSize += messageSize;

			cnt++;
		}

		if (totalSize != 0)
		{
			//m_pkgSend.SetChain(FTDC_CHAIN_LAST);
			FTDC_ADD_FIELD(&m_pkgSend, &rspFieldInfo);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		if (cnt)
		{
			rspInfoField.ErrorID = DBMSG_SUC_SUCCESS;
			rspInfoField.ErrorMsg = "db query finish";
		}
		else
		{
			rspInfoField.ErrorID = DBMSG_SUC_NORECORD;
			rspInfoField.ErrorMsg = "not exists record";
		}

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		rspInfoField.ErrorID = DBMSG_ERR_EXCEPTION;
		rspInfoField.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

typedef struct
{
	CFTDCPackage *rsp;
	CFTDCSession *session;
	CFTDCPackage *req;
	int pkgID;
	bool findRecord;
} SearchCallBackData_T;

static void handleWarningEventResult(SACommand &records, void *data)
{
	CFTDRspQryWarningEventField field;
	CFtdData obj(&field, &CFTDRspQryWarningEventField::m_Describe);
	obj.FromDBRecord(records);

	SearchCallBackData_T *t = (SearchCallBackData_T *)data;

	AddRspWithField(t->rsp, &field, t->session, t->req, t->pkgID);

	t->findRecord = true;
}

///��ѯ�¼���Ϣ
void CQueryServer::OnReqQryWarningEvent(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryWarningEventField fieldInfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

	SACommand cmd;
	if (fieldInfo.StartDate != fieldInfo.EndDate)
	{
		cmd.setCommandText(
				"select * from t_SysWarningEvent where MonDate >= :1 and MonDate<= :2 ");
		cmd << fieldInfo.StartDate << fieldInfo.EndDate;
	}
	else
	{
		cmd.setCommandText(
				"select * from t_SysWarningEvent where MonDate= :1 and MonTime>= :2 and MonTime <= :3");
		cmd << fieldInfo.StartDate << fieldInfo.StartTime << fieldInfo.EndTime;
	}

	SearchCallBackData_T data;
	data.rsp = &m_pkgSend;
	data.session = pSession;
	data.req = pFTDCPackage;
	data.pkgID = FTD_TID_RspQryWarningEventTopic;
	data.findRecord = false;

	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryWarningEventTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	m_hander.SearchRecord(cmd, handleWarningEventResult, &data);

	pSession->SendRequestPackage(&m_pkgSend);

	CFTDRspInfoField rspInfoField;
	if (data.findRecord)
	{
		rspInfoField.ErrorID = DBMSG_SUC_SUCCESS;
		rspInfoField.ErrorMsg = "db query finish";
	}
	else
	{
		rspInfoField.ErrorID = DBMSG_SUC_NORECORD;
		rspInfoField.ErrorMsg = "not exists record";
	}

	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryWarningEventTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

static void handleNetMonitorTaskResult(SACommand &records, void *data)
{
	CFTDRspQryNetMonitorTaskResultField field;
	CFtdData obj(&field, &CFTDRspQryNetMonitorTaskResultField::m_Describe);
	obj.FromDBRecord(records);

	SearchCallBackData_T *t = (SearchCallBackData_T *)data;

	AddRspWithField(t->rsp, &field, t->session, t->req, t->pkgID);

	t->findRecord = true;
}

void CQueryServer::OnReqQryNetMonitorTaskResult(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetMonitorTaskResultField fieldInfo;
	int has_field = FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);
	if (!has_field)
	{
		return;
	}

	//�ͻ��˵�Լ��������ʷʱ��ε�����ӿ�Ϊ��MonDateΪ��ʼ���ڣ�MonTimeΪ��������
	SACommand cmd;

	if (fieldInfo.Task_ID == 0)
	{
		cmd.setCommandText(
				"select * from t_SysNetMonitorTaskResult where MonDate>= :1 and MonDate <= :2");
		cmd << fieldInfo.MonDate << fieldInfo.MonTime ; 
	}
	else if (fieldInfo.Task_ID == -1) //li.sc ����Ѳ�����Ƿ��쳣��־�ж�,ר����Է�ping��������ñȶ����� 2014.5.7
	{
		if( fieldInfo.Flag.getValue()==0 ) //ȫ�����
		{
			cmd.setCommandText(
					"select * from t_SysNetMonitorTaskResult where MonDate>= :1 and MonDate <= :2 and InstructChain not like 'Ping%' and InstructChain not like 'RunningConfig%'");
			cmd << fieldInfo.MonDate << fieldInfo.MonTime; 
		}
		else  //�쳣���
		{
			cmd.setCommandText(
					"select * from t_SysNetMonitorTaskResult where MonDate>= :1 and MonDate <= :2 and Flag= :3 and InstructChain not like 'Ping%' and InstructChain not like 'RunningConfig%'");
			cmd << fieldInfo.MonDate << fieldInfo.MonTime << (long)fieldInfo.Flag.getValue(); 
		}

	}
	else
	{
		cmd.setCommandText(
				"select * from t_SysNetMonitorTaskResult where Task_ID= :1 and MonDate>= :2 and MonDate <= :3");
		cmd <<
			(long)fieldInfo.Task_ID.getValue() <<
			fieldInfo.MonDate <<
			fieldInfo.MonTime;
	}

	SearchCallBackData_T data;
	data.rsp = &m_pkgSend;
	data.session = pSession;
	data.req = pFTDCPackage;
	data.pkgID = FTD_TID_RspQryNetMonitorTaskResultTopic;
	data.findRecord = false;

	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryNetMonitorTaskResultTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	m_hander.SearchRecord(cmd, handleNetMonitorTaskResult, &data);

	pSession->SendRequestPackage(&m_pkgSend);

	CFTDRspInfoField rspInfoField;
	if (data.findRecord)
	{
		rspInfoField.ErrorID = DBMSG_SUC_SUCCESS;
		rspInfoField.ErrorMsg = "db query finish";
	}
	else
	{
		rspInfoField.ErrorID = DBMSG_SUC_NORECORD;
		rspInfoField.ErrorMsg = "not exists record";
	}

	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryNetMonitorTaskResultTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

static void handleNetPartyLinkStatusInfo(SACommand &records, void *data)
{
	CFTDRspQryNetPartyLinkStatusInfoField field;
	CFtdData obj(&field, &CFTDRspQryNetPartyLinkStatusInfoField::m_Describe);
	obj.FromDBRecord(records);

	SearchCallBackData_T *t = (SearchCallBackData_T *)data;

	AddRspWithField(t->rsp, &field, t->session, t->req, t->pkgID);

	t->findRecord = true;
}

void CQueryServer::OnReqQryNetPartyLinkStatusInfo(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetPartyLinkStatusInfoField fieldInfo;
	int has_field = FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);
	if (!has_field)
	{
		return;
	}

	SACommand cmd;

	if (fieldInfo.KeyCompare == CT_RANGE)
	{
		vector<string>	range_value;
		if (!SplitStr(fieldInfo.KeyValue.getValue(), ";", range_value))
		{
			// invalid key value
			return;
		}

		assert(range_value.size() == 2);

		if (fieldInfo.KeyName == "MonDate")
		{
			cmd.setCommandText(
					"select * from t_SysNetPartyLinkStatusInfo where MonDate>= :1 and MonDate <= :2");
			cmd << range_value[0].c_str() << range_value[1].c_str();
		}
	}
	else if (fieldInfo.KeyCompare = CT_EQ)
	{
		if (fieldInfo.KeyName == "SEAT_NO")
		{
			cmd.setCommandText(
					"select * from t_SysNetPartyLinkStatusInfo where SEAT_NO= :1");
			cmd << fieldInfo.KeyValue.getValue();
		}
		else if (fieldInfo.KeyName == "IPADDR")
		{
			cmd.setCommandText(
					"select * from t_SysNetPartyLinkStatusInfo where IPADDR= :1");
			cmd << fieldInfo.KeyValue.getValue();
		}
		else if (fieldInfo.KeyName == "MonDate")
		{
			cmd.setCommandText(
					"select * from t_SysNetPartyLinkStatusInfo where MonDate= :1");
			cmd << fieldInfo.KeyValue.getValue();
		}
	}

	SearchCallBackData_T data;
	data.rsp = &m_pkgSend;
	data.session = pSession;
	data.req = pFTDCPackage;
	data.pkgID = FTD_TID_RspQryNetPartyLinkStatusInfoTopic;
	data.findRecord = false;

	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryNetPartyLinkStatusInfoTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	m_hander.SearchRecord(cmd, handleNetPartyLinkStatusInfo, &data);

	pSession->SendRequestPackage(&m_pkgSend);

	CFTDRspInfoField rspInfoField;
	if (data.findRecord)
	{
		rspInfoField.ErrorID = DBMSG_SUC_SUCCESS;
		rspInfoField.ErrorMsg = "db query finish";
	}
	else
	{
		rspInfoField.ErrorID = DBMSG_SUC_NORECORD;
		rspInfoField.ErrorMsg = "not exists record";
	}

	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryNetPartyLinkStatusInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

static void handleNetBaseLineResult(SACommand &records, void *data)
{
	CFTDSysNetBaseLineResultField field;
	CFtdData obj(&field, &CFTDSysNetBaseLineResultField::m_Describe);
	obj.FromDBRecord(records);

	CFTDRspQryNetBaseLineResultField rspField;
	CopySysNetBaseLineResultEntity(&rspField, &field);
	rspField.OperationType = OT_ADD;

	SearchCallBackData_T *t = (SearchCallBackData_T *)data;

	AddRspWithField(t->rsp, &rspField, t->session, t->req, t->pkgID);

	t->findRecord = true;
}

void CQueryServer::OnReqQryNetBaseLineResult(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetBaseLineResultField fieldInfo;
	int has_field = FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);
	if (!has_field)
	{
		return;
	}

	//�ͻ��˵�Լ��������ʷʱ��ε�����ӿ�Ϊ��MonDateΪ��ʼ���ڣ�MonTimeΪ��������
	SACommand cmd;

	if (fieldInfo.ID == 0)
	{
		cmd.setCommandText("select * from t_SysNetBaseLineResult");
	}
	else
	{
		cmd.setCommandText("select * from t_SysNetBaseLineResult where ID= :1");
		cmd << (long)fieldInfo.ID.getValue();
	}

	SearchCallBackData_T data;
	data.rsp = &m_pkgSend;
	data.session = pSession;
	data.req = pFTDCPackage;
	data.pkgID = FTD_TID_RspQryNetBaseLineResultTopic;
	data.findRecord = false;

	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryNetBaseLineResultTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	m_hander.SearchRecord(cmd, handleNetBaseLineResult, &data);

	pSession->SendRequestPackage(&m_pkgSend);

	CFTDRspInfoField rspInfoField;
	if (data.findRecord)
	{
		rspInfoField.ErrorID = DBMSG_SUC_SUCCESS;
		rspInfoField.ErrorMsg = "db query finish";
	}
	else
	{
		rspInfoField.ErrorID = DBMSG_SUC_NORECORD;
		rspInfoField.ErrorMsg = "not exists record";
	}

	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryNetBaseLineResultTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

///��ѯ Front ��Ϣ
void CQueryServer::OnReqQryFrontInfo(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
#endif

	CFTDReqQryFrontInfoField fieldInfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

	CFTDRspQryFrontInfoField rspFieldInfo;
	time_t	timep = time(NULL);
	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	sprintf(
		(char *)rspFieldInfo.MonDate.getValue(),
		"%02d%02d%02d",
		tm_time.tm_year + 1900,
		tm_time.tm_mon + 1,
		tm_time.tm_mday);

	map<CRttStatsKey, CRttPacketStats>	&mapRtt = g_OrderRttAnalysis->
		getRttAnalysis();
	for (map<CRttStatsKey, CRttPacketStats>::iterator it = mapRtt.begin();
		 it != mapRtt.end();
		 it++)
	{
		m_pkgSend.PrepareResponse(
				pFTDCPackage,
				FTD_TID_RspQryFrontInfoTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);

		INT64 total = it->second.m_lPacketNum[0] +
			it->second.m_lPacketNum[1] +
			it->second.m_lPacketNum[2] +
			it->second.m_lPacketNum[3] +
			it->second.m_lPacketNum[4];
		if (total == 0)
		{
			total = 1;
		}

		for (int i = 0; i < 5; i++)
		{
			rspFieldInfo.RspCondition = i;
			rspFieldInfo.ReqRate = 1.0 *
				it->second.m_lPacketNum[i] /
				total *
				100;
			sprintf(
				(char *)rspFieldInfo.FrontId.getValue(),
				"%d",
				it->first.FrontID);
			if (it->first.Version == 0)
			{
				rspFieldInfo.MonTime = "FTD";
			}
			else if (it->first.Version == 1)
			{
				rspFieldInfo.MonTime = "OFP";
			}
			else if (it->first.Version == 2)
			{
				rspFieldInfo.MonTime = "OFP2";
			}
			else
			{
				rspFieldInfo.MonTime = "UnKnow";
			}

			rspFieldInfo.ReqCount = it->second.m_lPacketNum[i];
			FTDC_ADD_FIELD(&m_pkgSend, &rspFieldInfo);
		}

		pSession->SendRequestPackage(&m_pkgSend);
	}

	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryFrontInfoTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));

	rspInfoField.ErrorID = ERR_SUCCESS;
	rspInfoField.ErrorMsg = "succ";
	m_pkgSend.SetChain(FTDC_CHAIN_LAST);
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

#if 0
void CQueryServer::OnReqQryFrontInfo(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);

	CFTDReqQryFrontInfoField fieldInfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

	// ���� CFTDRspQryFrontInfoField �����з��ͣ�����һ�η�������ֽ�����4000==FTDC_PACKAGE_MAX_SIZE
	//����Oracle���ݿ�
	if (!connectDB())
	{
		return;
	}

	SACommand cmd;
	cmd.setConnection(m_sqlConnect);
	if (fieldInfo.StartDate != fieldInfo.EndDate)
	{
		cmd.setCommandText(
				"select * from t_SysFrontInfo where MonDate >= :1 and MonDate<= :2 ");
		cmd << fieldInfo.StartDate << fieldInfo.EndDate;
	}
	else
	{
		cmd.setCommandText(
				"select * from t_SysFrontInfo where MonDate= :1 and MonTime>= :2 and MonTime <= :3");
		cmd << fieldInfo.StartDate << fieldInfo.StartTime << fieldInfo.EndTime;
	}

	int totalSize = 0;
	int messageSize = sizeof(CFTDRspQryWarningEventField);

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));

	CFTDRspQryFrontInfoField rspFieldInfo;
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryFrontInfoTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	try
	{
		cmd.Execute();
		while (cmd.FetchNext())
		{
			if (totalSize != 0)
			{	// �м�¼������Ҫ����
				FTDC_ADD_FIELD(&m_pkgSend, &rspFieldInfo);
				if (!(totalSize < (FTDC_PACKAGE_MAX_SIZE - messageSize)))
				{
					// ���ݰ������������ˣ����з���,ÿһ�ε����ݰ����֧��4000�ֽ�
					pSession->SendRequestPackage(&m_pkgSend);
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryFrontInfoTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);

					totalSize = 0;
				}
			}

			rspFieldInfo.MonDate = cmd.Field("MonDate").asString();
			rspFieldInfo.MonTime = cmd.Field("MonTime").asString();
			rspFieldInfo.FrontId = cmd.Field("FrontId").asString();
			rspFieldInfo.RspCondition = cmd.Field("RspCondition").asString();
			rspFieldInfo.ReqCount = cmd.Field("ReqCount").asLong();
			rspFieldInfo.ReqRate = cmd.Field("ReqRate").asDouble();

			totalSize += messageSize;
		}

		if (totalSize != 0)
		{
			//m_pkgSend.SetChain(FTDC_CHAIN_LAST);
			FTDC_ADD_FIELD(&m_pkgSend, &rspFieldInfo);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		rspInfoField.ErrorID = 0;
		rspInfoField.ErrorMsg = "db query finish";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		rspInfoField.ErrorID = 1;
		rspInfoField.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

#endif

///�û�ע��
void CQueryServer::OnReqQrySysUserRegister(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
#endif

	CFTDReqQrySysUserRegisterField	fieldInfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

	CFTDRspQrySysUserRegisterField	rspFieldInfo;	// Response ������Ϣ��
	CFTDRspInfoField msg;	// �����Ĵ�����ʾ��
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQrySysUserRegisterTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	/// ����û��Ƿ��Ѿ�����
	CFTDRtnSysUserField record;
	int retCode = getUserInfoSingle(record, fieldInfo.UserID.getValue());

	// ���ݿ����ʧ��
	if (1 == retCode)
	{
		msg.ErrorID = DBMSG_ERR_EXCEPTION;
		msg.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
		return;
	}
	else if (2 == retCode)
	{
		// �û�û�д��ڣ����к�������Ӳ���
	}
	else
	{
		// �û��Ѿ�����
		msg.ErrorID = DBMSG_SUC_RECORDEXISTS;
		msg.ErrorMsg = "Record alread exists!";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
		return;
	}

	int ret = 0;
	try
	{
		if (!connectDB())
		{
			return;
		}

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);
		cmd.setCommandText(
				"insert into t_SysRegisterUserInfo \
			(UserID,UserName,UserInfo,Password,Privilege, \
			EMail,EMailFlag,HomePhone,HomePhoneFlag,MobilePhone,MobilePhoneFlag) values \
			(:UserID, :UserName, :UserInfo, :Password, :Privilege, \
			 :EMail, :EMailFlag, :HomePhone, :HomePhoneFlag, :MobilePhone, :MobilePhoneFlag) ");

		cmd << SAPos("UserID") << fieldInfo.UserID;
		cmd << SAPos("UserName") << fieldInfo.UserName;
		cmd << SAPos("UserInfo") << fieldInfo.UserInfo;
		cmd << SAPos("Password") << fieldInfo.Password;
		cmd << SAPos("Privilege") << (long)fieldInfo.Privilege;

		cmd << SAPos("EMail") << fieldInfo.EMail;
		cmd << SAPos("EMailFlag") << (long)fieldInfo.EMailFlag;
		cmd << SAPos("HomePhone") << fieldInfo.HomePhone;
		cmd << SAPos("HomePhoneFlag") << (long)fieldInfo.HomePhoneFlag;
		cmd << SAPos("MobilePhone") << fieldInfo.MobilePhone;
		cmd << SAPos("MobilePhoneFlag") << (long)fieldInfo.MobilePhoneFlag;

		cmd.Execute();
		m_sqlConnect->Commit();

		rspFieldInfo.UserID = fieldInfo.UserID;
		rspFieldInfo.Privilege = fieldInfo.Privilege;
		FTDC_ADD_FIELD(&m_pkgSend, &rspFieldInfo);

		msg.ErrorID = DBMSG_SUC_SUCCESS;
		ret = 0;
		msg.ErrorMsg = "db operate finish";
		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);

		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		msg.ErrorID = DBMSG_ERR_EXCEPTION;
		ret = 1;
		msg.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}

	/// 2008.08.18 add by Solomon Wu
		/// �û�Register�ɹ�����Ҫ���û���Ϣ���͸�����Session
	//CFTDRtnSysUserField record;
	record.UserName = fieldInfo.UserName;
	record.UserID = fieldInfo.UserID;
	record.UserInfo = fieldInfo.UserInfo;
	record.Password = fieldInfo.Password;
	record.Privilege = fieldInfo.Privilege;

	record.EMail = fieldInfo.EMail;
	record.EMailFlag = fieldInfo.EMailFlag;
	record.HomePhone = fieldInfo.HomePhone;
	record.HomePhoneFlag = fieldInfo.HomePhoneFlag;
	record.MobilePhone = fieldInfo.MobilePhone;
	record.MobilePhoneFlag = fieldInfo.MobilePhoneFlag;

	if (0 == ret)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RtnSysUser,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &record);
		NotifyAllSession(&m_pkgSend);
	}
}

///�û���¼
void CQueryServer::OnReqQrySysUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
#endif

	CFTDReqQrySysUserLoginField fieldInfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

	CFTDRspQrySysUserLoginField rspFieldInfo;	// Response ������Ϣ��
	CFTDRspInfoField rspInfoField;				// �����Ľ����ʾ��
	char dateBuf[9] = { 0 };
	char timeBuf[9] = { 0 };
	time_t	timep = time(NULL);
	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	sprintf(
		dateBuf,
		"%02d%02d%02d",
		tm_time.tm_year + 1900,
		tm_time.tm_mon + 1,
		tm_time.tm_mday);
	sprintf(timeBuf, "%02d:%02d:%02d", tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec);

	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQrySysUserLoginTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	try
	{
		if (!connectDB())
		{
			return;
		}

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);
		cmd.setCommandText(
				"select Privilege from t_SysRegisterUserInfo where UserID = :1 and Password =:2 ");

		cmd << fieldInfo.UserID << fieldInfo.Password;
		cmd.Execute();

		int cnt = 0;
		while (cmd.FetchNext())
		{
			cnt++;
			rspFieldInfo.Privilege = cmd.Field(1).asLong();
		}

		if (cnt)
		{
			rspFieldInfo.LoginTime = timeBuf;
			rspFieldInfo.TradingDay = dateBuf;
			rspFieldInfo.UserID = fieldInfo.UserID;
			FTDC_ADD_FIELD(&m_pkgSend, &rspFieldInfo);

			rspInfoField.ErrorID = DBMSG_SUC_SUCCESS;
			rspInfoField.ErrorMsg = "db operation succ, finish";
		}
		else
		{
			rspInfoField.ErrorID = DBMSG_SUC_NORECORD;
			rspInfoField.ErrorMsg = "not exists the User";
		}

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		rspInfoField.ErrorID = DBMSG_ERR_EXCEPTION;
		rspInfoField.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CQueryServer::OnReqQrySysUserLogout(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
#endif

	CFTDReqQrySysUserLogoutField fieldInfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

	CFTDRspQrySysUserLogoutField rspFieldInfo;	// Response ������Ϣ��
	CFTDRspInfoField rspInfoField;				// �����Ľ����ʾ��
	
		/// QQQQ
		///����Ŀǰ��Logout��ʱ�򣬲���Ҫ�����ݿ���в���������Ͳ��ٽ��з�����
		///����ֱ�ӻ�Ӧһ�����ݰ��Ϳ�����
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQrySysUserLogoutTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);
	rspFieldInfo.UserID = fieldInfo.UserID;
	FTDC_ADD_FIELD(&m_pkgSend, &rspFieldInfo);

	rspInfoField.ErrorID = DBMSG_SUC_SUCCESS;
	rspInfoField.ErrorMsg = "db query finish";
	m_pkgSend.SetChain(FTDC_CHAIN_LAST);
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CQueryServer::OnReqQrySysUserPasswordUpdate(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
#endif

	CFTDReqQrySysUserPasswordUpdateField fieldInfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

	CFTDRspQrySysUserPasswordUpdateField rspFieldInfo;	// Response ������Ϣ��
	CFTDRspInfoField rspInfoField;						// �����Ľ����ʾ��
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQrySysUserPasswordUpdateTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	/// ����Ƿ�������Ӧ��ȷ���û���¼
	CFTDRtnSysUserField record;
	int ret = getUserInfoSingle(
			record,
			fieldInfo.UserID.getValue(),
			fieldInfo.OldPassword.getValue());

	// û�м�¼�������ݿ����ʧ��
	if (1 == ret)
	{
		rspInfoField.ErrorID = DBMSG_ERR_EXCEPTION;
		rspInfoField.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
		return;
	}
	else if (2 == ret)
	{
		rspInfoField.ErrorID = DBMSG_SUC_NORECORD;
		rspInfoField.ErrorMsg = "db succ, not exists record";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
		return;
	}

	///�޸��û�������
	try
	{
		if (!connectDB())
		{
			return;
		}

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);
		cmd.setCommandText(
				"update t_SysRegisterUserInfo set Password =:1 where UserID= :2 and Password= :3 ");

		cmd <<
			fieldInfo.NewPassword <<
			fieldInfo.UserID <<
			fieldInfo.OldPassword;
		cmd.Execute();
		m_sqlConnect->Commit();

		rspFieldInfo.UserID = fieldInfo.UserID;
		rspFieldInfo.PasswordChgMsg = "Succ";
		FTDC_ADD_FIELD(&m_pkgSend, &rspFieldInfo);

		rspInfoField.ErrorID = DBMSG_SUC_SUCCESS;
		rspInfoField.ErrorMsg = "db operation succ, finish";
		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		rspInfoField.ErrorID = DBMSG_ERR_EXCEPTION;
		rspInfoField.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
		return; //�����쳣�Ͳ�������Ĵ�����
	}

	/// 2008.08.18 add by Solomon Wu
		/// record����Ϣ��ǰ���Ѿ���������ȡ�������޸Ŀ���Ϊ���µľͿ����ˣ�
	record.Password = fieldInfo.NewPassword;

	//// ���û��������֮����Ҫ�����е�Session�����з��ʹ���
	m_pkgSend.PreparePackage(FTD_TID_RtnSysUser, FTDC_CHAIN_LAST, FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &record);
	NotifyAllSession(&m_pkgSend);
}

void CQueryServer::OnReqQrySysUserDelete(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);

	CFTDReqQrySysUserDeleteField fieldInfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

	CFTDRspQrySysUserDeleteField rspFieldInfo;	// Response ������Ϣ��
	CFTDRspInfoField rspInfoField;				// �����Ľ����ʾ
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQrySysUserDeleteTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	/// ��ɾ���û�֮ǰ������ȡ�û�����Ϣ
	CFTDRtnSysUserField record;
	int ret = 0;
	ret = getUserInfoSingle(record, fieldInfo.UserID.getValue());

	// û�м�¼�������ݿ����ʧ��
	if (1 == ret)
	{
		rspInfoField.ErrorID = DBMSG_ERR_EXCEPTION;
		rspInfoField.ErrorMsg = "DB access exception";

		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
		return;
	}
	else if (2 == ret)
	{
		rspInfoField.ErrorID = DBMSG_SUC_NORECORD;
		rspInfoField.ErrorMsg = "db succ, not exists record";

		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
		return;
	}

	try
	{
		if (!connectDB())
		{
			return;
		}

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);
		cmd.setCommandText(
				"delete from t_SysRegisterUserInfo where UserID= :1 ");

		cmd << fieldInfo.UserID;

		cmd.Execute();
		m_sqlConnect->Commit();

		rspFieldInfo.UserID = fieldInfo.UserID;
		FTDC_ADD_FIELD(&m_pkgSend, &rspFieldInfo);

		rspInfoField.ErrorID = DBMSG_SUC_SUCCESS;
		rspInfoField.ErrorMsg = "db operation succ, finish";

		//m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		ret = 1;
		rspInfoField.ErrorID = DBMSG_ERR_EXCEPTION;
		rspInfoField.ErrorMsg = "DB access exception";

		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
		return; //�����쳣�Ͳ�������Ĵ�����
	}

	/// 2008.08.18 add by Solomon Wu
		/// �ڽ����������Ļ�Ӧ����֮��������Session���з���
		/// ����ɾ���û�����Ϊ���еĻ�Ӧ��ʹ����ͬһ���ṹ�������Privilege����Ϊһ��С��0��������Ϊ���
	record.Privilege = -1;

	m_pkgSend.PreparePackage(FTD_TID_RtnSysUser, FTDC_CHAIN_LAST, FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &record);
	NotifyAllSession(&m_pkgSend);
}

///�������ݿ�
///����������ŵģ��Ͳ��ٽ������ӣ����ݿ����ͽ���֧��Oracle
bool CQueryServer::connectDB(void)
{
	//if ( m_sqlConnect != NULL && m_sqlConnect->isConnected() )
	if (NULL != m_sqlConnect)
	{
		if (isAlive(m_sqlConnect))
		{
			return true;
		}
		else
		{
			//m_sqlConnect->~SAConnection();
			delete m_sqlConnect;
			m_sqlConnect = NULL;
		}
	}

	//try {
	//	//m_con.Disconnect();
	//	m_sqlConnect->Rollback();
	//}catch(SAException &ex) {
	//}catch(...) {}
	try
	{
		m_sqlConnect = new SAConnection();
		m_sqlConnect->Connect(
				getConnectStr(g_strDbIp, g_strDbPort, g_strDbName).c_str(),
				g_strDbUser.c_str(),
				g_strDbPwd.c_str(),
				SA_Oracle_Client);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());
		try
		{
			m_sqlConnect->Rollback();
		}
		catch(SAException & x)
		{
			printf("%s\n", (const char *)x.ErrText());
		}

		delete m_sqlConnect;
		m_sqlConnect = NULL;
		return false;
	}

	return true;
}

///����ip port DababaseName ƴ�ӳ�SQAPI����������Ҫ�Ĵ�
string CQueryServer::getConnectStr(
	const string &ip,
	const string &port,
	const string &dbName) const
{
	return ip + ":" + port + "/" + dbName;
}

/// ȡ�������û�����Ϣ
/// return:
///		0 - "db query finish"; ���ʳɹ����м�¼
///		1 - "DB access exception";
///		2 - ���ݿ���ʳɹ�������û�м�¼
int CQueryServer::getUserInfoList(list<CFTDRtnSysUserField *> &userList)
{
	int totalSize = 0;
	CFTDRtnSysUserField *record;

	try
	{
		if (!connectDB())
		{
			return 1;
		}

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);
		cmd.setCommandText(
				"select trim(UserID) as UserID, \
						   trim(UserInfo) as UserInfo,	\
						   trim(UserName) as UserName,	\
						   trim(Password) as Password,	\
						   Privilege,					\
						   trim(EMail) as EMail,		\
						   EMailFlag,					\
						   trim(HomePhone) as HomePhone,\
						   HomePhoneFlag,				\
						   trim(MobilePhone) as MobilePhone,  \
						   MobilePhoneFlag				\
						   from t_SysRegisterUserInfo ");

		cmd.Execute();

		while (cmd.FetchNext())
		{
			totalSize++;
			record = new CFTDRtnSysUserField;

			record->UserID = cmd.Field("UserID").asString();
			record->UserName = cmd.Field("UserName").asString();
			record->UserInfo = cmd.Field("UserInfo").asString();
			record->Password = cmd.Field("Password").asString();
			record->Privilege = cmd.Field("Privilege").asLong();

			record->EMail = cmd.Field("EMail").asString();
			record->EMailFlag = cmd.Field("EMailFlag").asLong();
			record->HomePhone = cmd.Field("HomePhone").asString();
			record->HomePhoneFlag = cmd.Field("HomePhoneFlag").asLong();
			record->MobilePhone = cmd.Field("MobilePhone").asString();
			record->MobilePhoneFlag = cmd.Field("MobilePhoneFlag").asLong();
			userList.push_back(record);
		}

		if (totalSize == 0)
		{
			return 2;
		}
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());
		return 1;
	}

	return 0;
}

/// ȡ�õ����û�����Ϣ
/// return:
///		0 - "db query finish"; ���ʳɹ����м�¼
///		1 - "DB access exception";
///		2 - ���ݿ���ʳɹ�������û�м�¼
int CQueryServer::getUserInfoSingle(
	CFTDRtnSysUserField &record,
	const string &userID)
{
	int totalSize = 0;

	try
	{
		if (!connectDB())
		{
			return 1;
		}

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);
		cmd.setCommandText(
				"select trim(UserID) as UserID, \
						   trim(UserInfo) as UserInfo,	\
						   trim(UserName) as UserName,	\
						   trim(Password) as Password,	\
						   Privilege,					\
						   trim(EMail) as EMail,		\
						   EMailFlag,					\
						   trim(HomePhone) as HomePhone,\
						   HomePhoneFlag,				\
						   trim(MobilePhone) as MobilePhone,  \
						   MobilePhoneFlag				\
						   from t_SysRegisterUserInfo where UserID=:1");

		cmd << userID.c_str();

		cmd.Execute();

		while (cmd.FetchNext())
		{
			totalSize++;
			record.UserID = cmd.Field("UserID").asString();
			record.UserName = cmd.Field("UserName").asString();
			record.UserInfo = cmd.Field("UserInfo").asString();
			record.Password = cmd.Field("Password").asString();
			record.Privilege = cmd.Field("Privilege").asLong();

			record.EMail = cmd.Field("EMail").asString();
			record.EMailFlag = cmd.Field("EMailFlag").asLong();
			record.HomePhone = cmd.Field("HomePhone").asString();
			record.HomePhoneFlag = cmd.Field("HomePhoneFlag").asLong();
			record.MobilePhone = cmd.Field("MobilePhone").asString();
			record.MobilePhoneFlag = cmd.Field("MobilePhoneFlag").asLong();
		}

		if (totalSize == 0)
		{
			return 2;
		}
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());
		return 1;
	}

	return 0;
}

/// ȡ�õ����û�����Ϣ
/// return:
///		0 - "db query finish"; ���ʳɹ����м�¼
///		1 - "DB access exception";
///		2 - ���ݿ���ʳɹ�������û�м�¼
int CQueryServer::getUserInfoSingle(
	CFTDRtnSysUserField &record,
	const string &userID,
	const string &password)
{
	int totalSize = 0;

	try
	{
		if (!connectDB())
		{
			return 1;
		}

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);
		cmd.setCommandText(
				"select trim(UserID) as UserID, \
						   trim(UserInfo) as UserInfo,	\
						   trim(UserName) as UserName,	\
						   trim(Password) as Password,	\
						   Privilege,					\
						   trim(EMail) as EMail,  \
						   EMailFlag,  \
						   trim(HomePhone) as HomePhone,  \
						   HomePhoneFlag,  \
						   trim(MobilePhone) as MobilePhone,  \
						   MobilePhoneFlag \
						   from t_SysRegisterUserInfo where UserID=:1 and Password=:2 ");

		cmd << userID.c_str() << password.c_str();

		cmd.Execute();

		while (cmd.FetchNext())
		{
			totalSize++;
			record.UserID = cmd.Field("UserID").asString();
			record.UserName = cmd.Field("UserName").asString();
			record.UserInfo = cmd.Field("UserInfo").asString();
			record.Password = cmd.Field("Password").asString();
			record.Privilege = cmd.Field("Privilege").asLong();

			record.EMail = cmd.Field("EMail").asString();
			record.EMailFlag = cmd.Field("EMailFlag").asLong();
			record.HomePhone = cmd.Field("HomePhone").asString();
			record.HomePhoneFlag = cmd.Field("HomePhoneFlag").asLong();
			record.MobilePhone = cmd.Field("MobilePhone").asString();
			record.MobilePhoneFlag = cmd.Field("MobilePhoneFlag").asLong();
		}

		if (totalSize == 0)
		{
			return 2;
		}
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());
		return 1;
	}

	return 0;
}

//2008.09.19 add by wu.yb
///��ʷCpu״̬��ѯ
void CQueryServer::OnReqQryHistoryCpuInfo(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryHistoryCpuInfoField req;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &req);

	CFTDRspQryHistoryCpuInfoField rsp;

	int totalSize = 0;
	int messageSize = sizeof(CFTDRspQryHistoryCpuInfoField);

	CFTDRspInfoField msg;
	memset(&msg, 0, sizeof(CFTDRspInfoField));

	int mPackSend = 0;
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryHistoryCpuInfoTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	try
	{
		//����Oracle���ݿ�
		if (!connectDB())
		{
			return;
		}

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);

		if (req.StartDate != req.EndDate)
		{
			cmd.setCommandText(
					"select * from t_RspQryTopCpuInfo where HostName = :1 and (MonDate >= :2 and MonDate<= :3) ");
			cmd << req.HostName << req.StartDate << req.EndDate;
		}
		else
		{
			cmd.setCommandText(
					"select * from t_RspQryTopCpuInfo where HostName = :1 and MonDate= :2 ");
			cmd << req.HostName << req.StartDate;
		}

		cmd.Execute();

		int cnt = 0;
		while (cmd.FetchNext())
		{
			if (mPackSend >= MAXQRYRETURNNUM)
			{
				m_pkgSend.PrepareResponse(
						pFTDCPackage,
						FTD_TID_RspQryHistoryCpuInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				msg.ErrorID = ERR_REACHMAXRECORDNUM;
				msg.ErrorMsg = "�����Ѿ��ﵽ����¼��";
				FTDC_ADD_FIELD(&m_pkgSend, &msg);
				pSession->SendRequestPackage(&m_pkgSend);
				return;
			}

			if (totalSize != 0)
			{	// �м�¼������Ҫ����
				FTDC_ADD_FIELD(&m_pkgSend, &rsp);
				if (!(totalSize < (FTDC_PACKAGE_MAX_SIZE - messageSize)))
				{
					// ���ݰ������������ˣ����з���,ÿһ�ε����ݰ����֧��4000�ֽ�
					pSession->SendRequestPackage(&m_pkgSend);
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryHistoryCpuInfoTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);

					totalSize = 0;
				}
			}

			mPackSend++;

			/// ��ȡ����
			//GetRow(&cmd, (char *)&rsp, &rsp.m_Describe);
			rsp.HostName = cmd.Field("HostName").asString();
			rsp.MonDate = cmd.Field("MonDate").asString();
			rsp.MonTime = cmd.Field("MonTime").asString();
			rsp.CPU = cmd.Field("CPU").asString();
			rsp.LOAD = cmd.Field("LOAD").asDouble();
			rsp.USER = cmd.Field("USER_LOAD").asDouble();
			rsp.NICE = cmd.Field("NICE").asDouble();
			rsp.SYS = cmd.Field("SYS").asDouble();
			rsp.IDLE = cmd.Field("IDLE").asDouble();
			rsp.BLOCK = cmd.Field("BLOCK").asDouble();
			rsp.SWAIT = cmd.Field("SWAIT").asDouble();
			rsp.INTR = cmd.Field("INTR").asDouble();
			rsp.SSYS = cmd.Field("SSYS").asDouble();

			totalSize += messageSize;
			cnt++;
		}

		if (totalSize != 0)
		{
			FTDC_ADD_FIELD(&m_pkgSend, &rsp);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		if (cnt)
		{
			msg.ErrorID = DBMSG_SUC_SUCCESS;
			msg.ErrorMsg = "db query finish";
		}
		else
		{
			msg.ErrorID = DBMSG_SUC_NORECORD;
			msg.ErrorMsg = "not exists record";
		}

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		msg.ErrorID = DBMSG_ERR_EXCEPTION;
		msg.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

///��ʷMem״̬��ѯ
void CQueryServer::OnReqQryHistoryMemInfo(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	//query<CFTDReqQryHistoryMemInfoField,CFTDRspQryHistoryMemInfoField>(FTD_TID_RspQryHistoryMemInfoTopic,"t_RspQryTopMemInfo",pFTDCPackage,pSession);
	CFTDReqQryHistoryMemInfoField req;
	CFTDRspQryHistoryMemInfoField rsp;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &req);

	int totalSize = 0;
	int messageSize = sizeof(rsp);

	CFTDRspInfoField msg;
	memset(&msg, 0, sizeof(CFTDRspInfoField));

	int mPackSend = 0;
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryHistoryMemInfoTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	try
	{
		//����Oracle���ݿ�
		if (!connectDB())
		{
			return;
		}

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);

		string	sql;
		sql = "select * from ";
		sql += "t_RspQryTopMemInfo";
		sql += " where 1=1 ";
		sql += " and HostName = :1";
		if (req.StartDate != req.EndDate)
		{
			sql += " and (MonDate >= :2 and MonDate<= :3) ";
			cmd.setCommandText(sql.c_str());
			cmd << req.HostName << req.StartDate << req.EndDate;
		}
		else
		{
			sql += " and MonDate= :2  ";
			cmd.setCommandText(sql.c_str());
			cmd << req.HostName << req.StartDate;
		}

		//printf("sql command text: %s\n",sql.c_str() );
		cmd.Execute();

		int cnt = 0;
		while (cmd.FetchNext())
		{
			if (mPackSend >= MAXQRYRETURNNUM)
			{
				m_pkgSend.PrepareResponse(
						pFTDCPackage,
						FTD_TID_RspQryHistoryMemInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				msg.ErrorID = ERR_REACHMAXRECORDNUM;
				msg.ErrorMsg = "�����Ѿ��ﵽ����¼��";
				FTDC_ADD_FIELD(&m_pkgSend, &msg);
				pSession->SendRequestPackage(&m_pkgSend);
				return;
			}

			if (totalSize != 0)
			{	// �м�¼������Ҫ����
				FTDC_ADD_FIELD(&m_pkgSend, &rsp);
				if (!(totalSize < (FTDC_PACKAGE_MAX_SIZE - messageSize)))
				{
					// ���ݰ������������ˣ����з���,ÿһ�ε����ݰ����֧��4000�ֽ�
					pSession->SendRequestPackage(&m_pkgSend);
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryHistoryMemInfoTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);

					totalSize = 0;
				}
			}

			mPackSend++;

			/// ��ȡ����
			GetRow(&cmd, (char *) &rsp, &rsp.m_Describe);
			totalSize += messageSize;
			cnt++;
		}

		if (totalSize != 0)
		{
			FTDC_ADD_FIELD(&m_pkgSend, &rsp);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		if (cnt)
		{
			msg.ErrorID = DBMSG_SUC_SUCCESS;
			msg.ErrorMsg = "db query finish";
		}
		else
		{
			msg.ErrorID = DBMSG_SUC_NORECORD;
			msg.ErrorMsg = "not exists record";
		}

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		msg.ErrorID = DBMSG_ERR_EXCEPTION;
		msg.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

///��ʷ����״̬��ѯ
void CQueryServer::OnReqQryHistoryNetworkInfo(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	//query<CFTDReqQryHistoryNetworkInfoField,CFTDRspQryHistoryNetworkInfoField>(FTD_TID_RspQryHistoryNetworkInfoTopic,"t_RspQryNetworkInfo",pFTDCPackage,pSession);
	CFTDReqQryHistoryNetworkInfoField req;
	CFTDRspQryHistoryNetworkInfoField rsp;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &req);

	int totalSize = 0;
	int messageSize = sizeof(rsp);

	CFTDRspInfoField msg;
	memset(&msg, 0, sizeof(CFTDRspInfoField));

	int mPackSend = 0;
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryHistoryNetworkInfoTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	try
	{
		//����Oracle���ݿ�
		if (!connectDB())
		{
			return;
		}

		char tmpBuff[130];
		sprintf(
			tmpBuff,
			"%s.%s",
			req.HostName.getValue(),
			req.LANNAME.getValue());

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);

		string	sql;
		sql = "select * from ";
		sql += "t_RspQryNetworkInfo";
		sql += " where 1=1 ";
		sql += " and HostName = :1";
		if (req.StartDate != req.EndDate)
		{
			sql += " and (MonDate >= :2 and MonDate<= :3) ";
			cmd.setCommandText(sql.c_str());
			cmd << tmpBuff << req.StartDate << req.EndDate;
		}
		else
		{
			sql += " and MonDate= :2  ";
			cmd.setCommandText(sql.c_str());
			cmd << tmpBuff << req.StartDate;
		}

		//printf("sql command text: %s\n",sql.c_str() );
		cmd.Execute();

		int cnt = 0;
		while (cmd.FetchNext())
		{
			if (mPackSend >= MAXQRYRETURNNUM)
			{
				m_pkgSend.PrepareResponse(
						pFTDCPackage,
						FTD_TID_RspQryHistoryNetworkInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				msg.ErrorID = ERR_REACHMAXRECORDNUM;
				msg.ErrorMsg = "�����Ѿ��ﵽ����¼��";
				FTDC_ADD_FIELD(&m_pkgSend, &msg);
				pSession->SendRequestPackage(&m_pkgSend);
				return;
			}

			if (totalSize != 0)
			{	// �м�¼������Ҫ����
				FTDC_ADD_FIELD(&m_pkgSend, &rsp);
				if (!(totalSize < (FTDC_PACKAGE_MAX_SIZE - messageSize)))
				{
					// ���ݰ������������ˣ����з���,ÿһ�ε����ݰ����֧��4000�ֽ�
					pSession->SendRequestPackage(&m_pkgSend);
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryHistoryNetworkInfoTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);

					totalSize = 0;
				}
			}

			/// ��ȡ����
			mPackSend++;
			GetRow(&cmd, (char *) &rsp, &rsp.m_Describe);
			totalSize += messageSize;
			cnt++;
		}

		if (totalSize != 0)
		{
			FTDC_ADD_FIELD(&m_pkgSend, &rsp);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		if (cnt)
		{
			msg.ErrorID = DBMSG_SUC_SUCCESS;
			msg.ErrorMsg = "db query finish";
		}
		else
		{
			msg.ErrorID = DBMSG_SUC_NORECORD;
			msg.ErrorMsg = "not exists record";
		}

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		msg.ErrorID = DBMSG_ERR_EXCEPTION;
		msg.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CQueryServer::GetRow(
	SACommand *pCommand,
	char *buf,
	CFieldDescribe	*pFieldDescribe)
{
	for (int i = 0; i < pFieldDescribe->GetMemberCount(); i++)
	{
		TMemberDesc *pMemberDesc = pFieldDescribe->GetMemberDesc(i);
		char *pMember = buf + pMemberDesc->nStructOffset;
		switch (pMemberDesc->nType)
		{
			case FT_WORD:
				*((WORD *)pMember) = pCommand->Field(pMemberDesc->szName).asShort();
				break;
			case FT_DWORD:
				*((DWORD *)pMember) = pCommand->Field(pMemberDesc->szName).asLong();
				break;
			case FT_QWORD:
				*((QWORD *)pMember) = pCommand->Field(pMemberDesc->szName).asLong();
				break;
			case FT_BYTE:
				if (pCommand->Field(pMemberDesc->szName).DataType()
						== SA_dtDateTime)
				{
					SADateTime	dt = pCommand->Field(pMemberDesc->szName).asDateTime();
					sprintf(
						pMember,
						"%04d%02d%02d",
						dt.GetYear(),
						dt.GetMonth(),
						dt.GetDay());
				}
				else
				{
					strncpy(
						pMember,
						(const char *)(pCommand->Field(pMemberDesc->szName).asString()),
						pMemberDesc->nSize);
				}

				if (pMemberDesc->nSize != 1)
				{
					pMember[pMemberDesc->nSize - 1] = '\0';

					char *p = pMember + strlen(pMember);
					while (p > pMember)
					{
						p--;
						if (*p != ' ')
						{
							break;
						}

						*p = '\0';
					}
				}

				break;
			case FT_REAL4:
				*((REAL4 *)pMember) = pCommand->Field(pMemberDesc->szName).asDouble();
				break;
			case FT_REAL8:
				if (pCommand->Field(pMemberDesc->szName).isNull())
				{
					*((REAL8 *)pMember) = DOUBLE_NaN;
				}
				else
				{
					*((REAL8 *)pMember) = pCommand->Field(
							pMemberDesc->szName).asDouble();
				}

				break;
		}
	}
}

///�ú������� sysprobe->DatabaseSpiImpl.cpp->isAlive()
bool CQueryServer::isAlive(SAConnection *conn) const
{
	try
	{
		string	recStr = "select distinct 1 from user_tables";

		SACommand cmd(conn, recStr.c_str());
		cmd.Execute();
		while (cmd.FetchNext())
		{
		}
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		time_t	now;
		char tmpTime[10];
		struct tm tm_time;
		time(&now);
		
		LocalTime(&now, &tm_time);
		strftime(tmpTime, 10, "%H:%M:%S", &tm_time);
		printf("In CQueryServer::isAlive() %s\n", tmpTime);
		return false;
	}

	return true;
}

void CQueryServer::OnReqQryTradeFrontOrderRttStat(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryTradeFrontOrderRttStatField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	//��������ڣ���ѯ���ݿ�
	if (qryfield.MonDate != "")
	{
		//atoi(qryfield.ObjectID.getValue())
		CFTDRspQryTradeFrontOrderRttStatField rsp;
		int totalSize = 0;
		int messageSize = sizeof(rsp);

		CFTDRspInfoField msg;
		memset(&msg, 0, sizeof(CFTDRspInfoField));

		int mPackSend = 0;
		m_pkgSend.PrepareResponse(
				pFTDCPackage,
				FTD_TID_RspQryTradeFrontOrderRttStatTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);

		try
		{
			//����Oracle���ݿ�
			if (!connectDB())
			{
				return;
			}

			SACommand cmd;
			cmd.setConnection(m_sqlConnect);

			string	sql;
			sql = "select * from t_SysTradeFrontOrderRttStat where MonDate = :1 and ObjectID = :2 order by MonTime";
			cmd.setCommandText(sql.c_str());
			cmd << qryfield.MonDate << qryfield.ObjectID;

			cmd.Execute();

			int cnt = 0;
			while (cmd.FetchNext())
			{
				if (mPackSend >= MAXQRYRETURNNUM)
				{
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryTradeFrontOrderRttStatTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					msg.ErrorID = ERR_REACHMAXRECORDNUM;
					msg.ErrorMsg = "�����Ѿ��ﵽ����¼��";
					FTDC_ADD_FIELD(&m_pkgSend, &msg);
					pSession->SendRequestPackage(&m_pkgSend);
					return;
				}

				if (totalSize != 0)
				{	// �м�¼������Ҫ����
					FTDC_ADD_FIELD(&m_pkgSend, &rsp);
					if (!(totalSize < (FTDC_PACKAGE_MAX_SIZE - messageSize)))
					{
						// ���ݰ������������ˣ����з���,ÿһ�ε����ݰ����֧��4000�ֽ�
						pSession->SendRequestPackage(&m_pkgSend);
						m_pkgSend.PrepareResponse(
								pFTDCPackage,
								FTD_TID_RspQryTradeFrontOrderRttStatTopic,
								FTDC_CHAIN_CONTINUE,
								FTD_VERSION);

						totalSize = 0;
					}
				}

				mPackSend++;

				/// ��ȡ����
				GetRow(&cmd, (char *) &rsp, &rsp.m_Describe);
				totalSize += messageSize;
				cnt++;
			}

			if (totalSize != 0)
			{
				FTDC_ADD_FIELD(&m_pkgSend, &rsp);
				pSession->SendRequestPackage(&m_pkgSend);
			}

			if (cnt)
			{
				msg.ErrorID = DBMSG_SUC_SUCCESS;
				msg.ErrorMsg = "db query finish";
			}
			else
			{
				msg.ErrorID = DBMSG_SUC_NORECORD;
				msg.ErrorMsg = "not exists record";
			}

			m_pkgSend.SetChain(FTDC_CHAIN_LAST);
			FTDC_ADD_FIELD(&m_pkgSend, &msg);
			pSession->SendRequestPackage(&m_pkgSend);
		}
		catch(SAException & ex)
		{
			print_errmsg(
				__FILE__,
				__FUNCTION__,
				__LINE__,
				(const char *)ex.ErrText());

			msg.ErrorID = DBMSG_ERR_EXCEPTION;
			msg.ErrorMsg = "DB access exception";

			m_pkgSend.SetChain(FTDC_CHAIN_LAST);
			FTDC_ADD_FIELD(&m_pkgSend, &msg);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		return;
	}

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;

	if (CTime::INVALID_TIME == CTime::TimeToLong(
			qryfield.MonStartTime.getValue())
||	CTime::INVALID_TIME == CTime::TimeToLong(
			qryfield.MonEndTime.getValue()))
	{
		sprintf(
			(char *)rspInfoField.ErrorMsg.getValue(),
			"time error S:%s, E:%s",
			qryfield.MonStartTime.getValue(),
			qryfield.MonEndTime.getValue());
	}
	else if (NULL == g_OrderRttAnalysis)
	{
		sprintf(
			(char *)rspInfoField.ErrorMsg.getValue(),
			"g_OrderRttAnalysis is null");
	}
	else
	{
		CRttInSec4Front &OrderRtt = g_OrderRttAnalysis->GetOrderRttStatic(
				atoi(qryfield.ObjectID.getValue()));

		string	strStartTime = qryfield.MonStartTime.getValue();
		string	strEndTime = qryfield.MonEndTime.getValue();

		int nPkgSends = 0;
		map<string, CRttInSecond>::iterator m_Iter;
		for (m_Iter = OrderRtt.mapRttStatis.begin();
			 m_Iter != OrderRtt.mapRttStatis.end();
			 m_Iter++)
		{
			string	strTimeIndex = m_Iter->first;

			if (strEndTime < strTimeIndex)
			{
				break;
			}

			if (strStartTime > strTimeIndex)
			{
				continue;
			}

			m_pkgSend.PreparePackage(
					FTD_TID_RspQryTradeFrontOrderRttStatTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

			CFTDRspQryTradeFrontOrderRttStatField rspField;
			memset(&rspField, 0, sizeof(CFTDRspQryTradeFrontOrderRttStatField));

			rspField.ObjectID = qryfield.ObjectID;
			rspField.MonDate = qryfield.MonDate;
			strcpy((char *)(rspField.MonTime.getValue()), strTimeIndex.data());

			rspField.OrderCount = m_Iter->second.nCount;
			rspField.OrderRttSum = m_Iter->second.nRttSum;
			rspField.OrderMinRtt = m_Iter->second.nMinRtt;
			rspField.OrderMaxRtt = m_Iter->second.nMaxRtt;
			rspField.OrderRttSqu = 0;

			sprintf(
				(char *)(rspField.OrderRttCutDistrib.getValue()),
				"%lld;%lld;%lld;%lld;%lld;%lld;%lld;%lld",
				m_Iter->second.nDistribution[0],
				m_Iter->second.nDistribution[1],
				m_Iter->second.nDistribution[2],
				m_Iter->second.nDistribution[3],
				m_Iter->second.nDistribution[4],
				m_Iter->second.nDistribution[5],
				m_Iter->second.nDistribution[6],
				m_Iter->second.nDistribution[7]);

			FTDC_ADD_FIELD(&m_pkgSend, &rspField);
			pSession->SendRequestPackage(&m_pkgSend);
			nPkgSends++;
		}

		//û��ѯ�����ݣ� ���Ը�֪�ڴ����ܹ��ж��٣���Ӧǰ�ö�ȡ״̬
		// 		if (0 == nPkgSends)
		{
			g_OrderRttAnalysis->GetOrderRttSum(
					atoi(qryfield.ObjectID.getValue()),
					(char *)rspInfoField.ErrorMsg.getValue());

			//sprintf((char*)rspInfoField.ErrorMsg.getValue(), "no records matched!", nPkgSends);
		}

		// 		else
		// 		{
		// 			sprintf((char*)rspInfoField.ErrorMsg.getValue(), "%d records matched!", nPkgSends);
		// 		}
	}

	m_pkgSend.PreparePackage(
			FTD_TID_RspQryTradeFrontOrderRttStatTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

//ÿ����һ��slog�������
void CQueryServer::CheckTradeFrontRtt(void)
{
	//��Ҫ�����rtt����
	map<int, CRttReadyMap>	mapRttForRtn;

	if (g_OrderRttAnalysis->CheckRtnIsReady(mapRttForRtn))
	{
		//���û��ǰ������ֱ�ӷ���
		if (m_frontSessions.size() == 0)
		{
			return;
		}

		map<int, CRttReadyMap>::iterator m_Iter2;

		for (m_Iter2 = mapRttForRtn.begin();
			 m_Iter2 != mapRttForRtn.end();
			 m_Iter2++)
		{
			map<string, CRttInSecond *> &RttInFront = m_Iter2->second.
				mapRttInSec;
			if (RttInFront.size() == 0)
			{
				continue;
			}

			map<string, CRttInSecond *>::iterator m_Iter;
			for (m_Iter = RttInFront.begin();
				 m_Iter != RttInFront.end();
				 m_Iter++)
			{
				CFTDRtnTradeFrontOrderRttStatField	rspField;
				memset(
					&rspField,
					0,
					sizeof(CFTDRtnTradeFrontOrderRttStatField));

				//rspField.ObjectID = m_Iter2->first;
				sprintf(
					(char *)rspField.ObjectID.getValue(),
					"%d",
					m_Iter2->first);
				rspField.MonTime = m_Iter->first.data();

				rspField.OrderCount = m_Iter->second->nCount;
				rspField.OrderRttSum = m_Iter->second->nRttSum;
				rspField.OrderMinRtt = m_Iter->second->nMinRtt;
				rspField.OrderMaxRtt = m_Iter->second->nMaxRtt;
				rspField.OrderRttSqu = 0;

				sprintf(
					(char *)(rspField.OrderRttCutDistrib.getValue()),
					"%lld;%lld;%lld;%lld;%lld;%lld;%lld;%lld",
					m_Iter->second->nDistribution[0],
					m_Iter->second->nDistribution[1],
					m_Iter->second->nDistribution[2],
					m_Iter->second->nDistribution[3],
					m_Iter->second->nDistribution[4],
					m_Iter->second->nDistribution[5],
					m_Iter->second->nDistribution[6],
					m_Iter->second->nDistribution[7]);

				m_pkgSend.PreparePackage(
						FTD_TID_RtnTradeFrontOrderRttStatTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &rspField);
				NotifyAllSession(&m_pkgSend);
			}
		}
	}
}

void CQueryServer::OnReqQryNetLocalPingResult(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetLocalPingResultInfoField req;
	CFTDRspQryNetLocalPingResultInfoField rsp;

	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &req);

	int totalSize = 0;
	int messageSize = sizeof(rsp);

	CFTDRspInfoField msg;
	memset(&msg, 0, sizeof(CFTDRspInfoField));

	int mPackSend = 0;
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryNetLocalPingResultInfoTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	string strTarip = req.TarIPADDR.getValue();
	if (strTarip=="all")
	{
		try
		{
			//����Oracle���ݿ�
			if (!connectDB())
			{
				return;
			}

			SACommand cmd;
			cmd.setConnection(m_sqlConnect);

			cmd.setCommandText("select * from t_syslocalpingresultinfo t1, (select t.taripaddr,max(t.pdatesta||t.ptimesta) as datetime from t_syslocalpingresultinfo t group by t.taripaddr)t2 where t1.taripaddr=t2.taripaddr and (t1.pdatesta||t1.ptimesta)=t2.datetime");

			cmd.Execute();

			int cnt = 0;
			while (cmd.FetchNext())
			{
				if (mPackSend >= MAXQRYRETURNNUM)
				{
					m_pkgSend.PrepareResponse(
						pFTDCPackage,
						FTD_TID_RspQryNetLocalPingResultInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
					msg.ErrorID = ERR_REACHMAXRECORDNUM;
					msg.ErrorMsg = "�����Ѿ��ﵽ����¼��";
					FTDC_ADD_FIELD(&m_pkgSend, &msg);
					pSession->SendRequestPackage(&m_pkgSend);
					return;
				}

				if (totalSize != 0)
				{	// �м�¼������Ҫ����
					FTDC_ADD_FIELD(&m_pkgSend, &rsp);
					if (!(totalSize < (FTDC_PACKAGE_MAX_SIZE - messageSize)))
					{
						// ���ݰ������������ˣ����з���,ÿһ�ε����ݰ����֧��4000�ֽ�
						pSession->SendRequestPackage(&m_pkgSend);
						m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryNetLocalPingResultInfoTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);

						totalSize = 0;
					}
				}

				/// ��ȡ����
				mPackSend++;
				rsp.ID = cmd.Field("ID").asLong();
				rsp.SouIPADDR = cmd.Field("SouIPADDR").asString();
				rsp.SouNAME = cmd.Field("SouNAME").asString();
				rsp.TarIPADDR = cmd.Field("TarIPADDR").asString();
				rsp.TarNAME = cmd.Field("TarNAME").asString();
				rsp.PDateSta = cmd.Field("PDateSta").asString();
				rsp.PTimeSta = cmd.Field("PTimeSta").asString();
				rsp.ConnRate = cmd.Field("ConnRate").asLong();

				//GetRow(&cmd, (char *)&rsp, &CFTDSysLocalPingResultInfoField::m_Describe);
				totalSize += messageSize;
				cnt++;
			}

			if (totalSize != 0)
			{
				FTDC_ADD_FIELD(&m_pkgSend, &rsp);
				pSession->SendRequestPackage(&m_pkgSend);
			}

			if (cnt)
			{
				msg.ErrorID = DBMSG_SUC_SUCCESS;
				msg.ErrorMsg = "db query finish";
			}
			else
			{
				msg.ErrorID = DBMSG_SUC_NORECORD;
				msg.ErrorMsg = "not exists record";
			}

			m_pkgSend.SetChain(FTDC_CHAIN_LAST);
			FTDC_ADD_FIELD(&m_pkgSend, &msg);
			pSession->SendRequestPackage(&m_pkgSend);
		}
		catch(SAException & ex)
		{
			print_errmsg(
				__FILE__,
				__FUNCTION__,
				__LINE__,
				(const char *)ex.ErrText());

			msg.ErrorID = DBMSG_ERR_EXCEPTION;
			msg.ErrorMsg = "DB access exception";

			m_pkgSend.SetChain(FTDC_CHAIN_LAST);
			FTDC_ADD_FIELD(&m_pkgSend, &msg);
			pSession->SendRequestPackage(&m_pkgSend);
		}
	}
	else
	{
		string	strSip = req.SouIPADDR.getValue();
		string	strTip = req.TarIPADDR.getValue();

		if (0 == strSip.length())
		{
			msg.ErrorID = DBMSG_SUC_NORECORD;
			msg.ErrorMsg = "no source ip";

			m_pkgSend.SetChain(FTDC_CHAIN_LAST);
			FTDC_ADD_FIELD(&m_pkgSend, &msg);
			pSession->SendRequestPackage(&m_pkgSend);
			return;
		}

		if (0 == strTip.length())
		{
			msg.ErrorID = DBMSG_SUC_NORECORD;
			msg.ErrorMsg = "no target ip";

			m_pkgSend.SetChain(FTDC_CHAIN_LAST);
			FTDC_ADD_FIELD(&m_pkgSend, &msg);
			pSession->SendRequestPackage(&m_pkgSend);
			return;
		}

		string	strDate = req.PDateSta.getValue();
		string	strTime = req.PTimeSta.getValue();

		int nChkAddion = 0;
		if (0 == strDate.length())
		{
			nChkAddion++;
		}

		if (0 == strTime.length())
		{
			nChkAddion++;
		}

		//ֻ����ʱ������ڣ��Ƿ�
		if (1 == nChkAddion)
		{
			msg.ErrorID = DBMSG_SUC_NORECORD;
			msg.ErrorMsg = "miss date and time";

			m_pkgSend.SetChain(FTDC_CHAIN_LAST);
			FTDC_ADD_FIELD(&m_pkgSend, &msg);
			pSession->SendRequestPackage(&m_pkgSend);
			return;
		}

		try
		{
			//����Oracle���ݿ�
			if (!connectDB())
			{
				return;
			}

			SACommand cmd;
			cmd.setConnection(m_sqlConnect);

			//û��ʱ������ڣ��������30��
			if (2 == nChkAddion)
			{
				//////////////////////////////////////////////////////////////////////////
				//change by feng.q ���һ���µĶ���״̬
				time_t	timep;
				time(&timep);

				struct tm tm_time;
				LocalTime(&timep, &tm_time);
				char strNwDt[16];
				sprintf(
					strNwDt,
					"%4d%02d%02d",
					tm_time.tm_year + 1900,
					tm_time.tm_mon + 1,
					tm_time.tm_mday);

				CDate nwDate(strNwDt);
				if (CDate::IsValid(strNwDt))
				{
					CDate amag = nwDate - 30;
					cmd.setCommandText(
						"select * from t_SysLocalPingResultInfo where SouIPADDR = :1 and TarIPADDR = :2 and PDateSta >= :3 and connrate = 0 order by pdatesta, ptimesta");
					cmd << req.SouIPADDR << req.TarIPADDR << amag.ToString();
				}
				else
				{
					cmd.setCommandText(
						"select * from (select * from t_SysLocalPingResultInfo where SouIPADDR = :1 and TarIPADDR = :2 order by pdatesta desc, ptimesta desc) where rownum <=30 order by pdatesta, ptimesta");
					cmd << req.SouIPADDR << req.TarIPADDR;
				}

				//////////////////////////////////////////////////////////////////////////
			}
			else
			{
				cmd.setCommandText(
					"select * from t_SysLocalPingResultInfo where SouIPADDR = :1 and TarIPADDR = :2 and PDateSta >= :3 and PTimeSta >= :4 order by pdatesta, ptimesta");
				cmd <<
					req.SouIPADDR <<
					req.TarIPADDR <<
					req.PDateSta <<
					req.PTimeSta;
			}

			cmd.Execute();

			int cnt = 0;
			while (cmd.FetchNext())
			{
				if (mPackSend >= MAXQRYRETURNNUM)
				{
					m_pkgSend.PrepareResponse(
						pFTDCPackage,
						FTD_TID_RspQryNetLocalPingResultInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
					msg.ErrorID = ERR_REACHMAXRECORDNUM;
					msg.ErrorMsg = "�����Ѿ��ﵽ����¼��";
					FTDC_ADD_FIELD(&m_pkgSend, &msg);
					pSession->SendRequestPackage(&m_pkgSend);
					return;
				}

				if (totalSize != 0)
				{	// �м�¼������Ҫ����
					FTDC_ADD_FIELD(&m_pkgSend, &rsp);
					if (!(totalSize < (FTDC_PACKAGE_MAX_SIZE - messageSize)))
					{
						// ���ݰ������������ˣ����з���,ÿһ�ε����ݰ����֧��4000�ֽ�
						pSession->SendRequestPackage(&m_pkgSend);
						m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryNetLocalPingResultInfoTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);

						totalSize = 0;
					}
				}

				/// ��ȡ����
				mPackSend++;
				rsp.ID = cmd.Field("ID").asLong();
				rsp.SouIPADDR = cmd.Field("SouIPADDR").asString();
				rsp.SouNAME = cmd.Field("SouNAME").asString();
				rsp.TarIPADDR = cmd.Field("TarIPADDR").asString();
				rsp.TarNAME = cmd.Field("TarNAME").asString();
				rsp.PDateSta = cmd.Field("PDateSta").asString();
				rsp.PTimeSta = cmd.Field("PTimeSta").asString();
				rsp.ConnRate = cmd.Field("ConnRate").asLong();

				//GetRow(&cmd, (char *)&rsp, &CFTDSysLocalPingResultInfoField::m_Describe);
				totalSize += messageSize;
				cnt++;
			}

			if (totalSize != 0)
			{
				FTDC_ADD_FIELD(&m_pkgSend, &rsp);
				pSession->SendRequestPackage(&m_pkgSend);
			}

			if (cnt)
			{
				msg.ErrorID = DBMSG_SUC_SUCCESS;
				msg.ErrorMsg = "db query finish";
			}
			else
			{
				msg.ErrorID = DBMSG_SUC_NORECORD;
				msg.ErrorMsg = "not exists record";
			}

			m_pkgSend.SetChain(FTDC_CHAIN_LAST);
			FTDC_ADD_FIELD(&m_pkgSend, &msg);
			pSession->SendRequestPackage(&m_pkgSend);
		}
		catch(SAException & ex)
		{
			print_errmsg(
				__FILE__,
				__FUNCTION__,
				__LINE__,
				(const char *)ex.ErrText());

			msg.ErrorID = DBMSG_ERR_EXCEPTION;
			msg.ErrorMsg = "DB access exception";

			m_pkgSend.SetChain(FTDC_CHAIN_LAST);
			FTDC_ADD_FIELD(&m_pkgSend, &msg);
			pSession->SendRequestPackage(&m_pkgSend);
		}	
	}
}

void CQueryServer::OnReqQryNetRomotePingResultInfo(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetRomotePingResultInfoField	req;
	CFTDRspQryNetRomotePingResultInfoField	rsp;

	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &req);

	int totalSize = 0;
	int messageSize = sizeof(rsp);

	CFTDRspInfoField msg;
	memset(&msg, 0, sizeof(CFTDRspInfoField));

	string	strSip = req.SouIPADDR.getValue();
	string	strTip = req.TarIPADDR.getValue();
	if (0 == strSip.length() || 0 == strTip.length())
	{
		//msg.ErrorID = DBMSG_SUC_NORECORD;
		//msg.ErrorMsg = "no source ip";

		//m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		//FTDC_ADD_FIELD(&m_pkgSend, &msg);
		//pSession->SendRequestPackage(&m_pkgSend);
		int mPackSend = 0;
		m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryNetRomotePingResultInfoTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

		try
		{
			//����Oracle���ݿ�
			if (!connectDB())
			{
				return;
			}

			SACommand cmd;
			cmd.setConnection(m_sqlConnect);
			
			CDateType NowDate;
			time_t	timep;
			time(&timep);
			struct tm tm_time;
			LocalTime(&timep, &tm_time);
			sprintf((char *)(NowDate.getValue()),"%d%02d%02d",tm_time.tm_year + 1900,tm_time.tm_mon + 1,tm_time.tm_mday);
			cmd.setCommandText(
					"select * from t_sysromotepingresultinfo, (select max(PTIMESTA)PTIMESTA,SOUIPADDR,taripaddr from t_sysromotepingresultinfo where PDATESTA= :1 group by SOUIPADDR, taripaddr) b where t_sysromotepingresultinfo.SOUIPADDR=b.SOUIPADDR and t_sysromotepingresultinfo.taripaddr=b.taripaddr and t_sysromotepingresultinfo.PTIMESTA=b.PTIMESTA and t_sysromotepingresultinfo.PDATESTA= :2");
			cmd <<NowDate <<NowDate;

			cmd.Execute();

			int cnt = 0;
			while (cmd.FetchNext())
			{
				if (mPackSend >= MAXQRYRETURNNUM)
				{
					m_pkgSend.PrepareResponse(
						pFTDCPackage,
						FTD_TID_RspQryNetRomotePingResultInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
					msg.ErrorID = ERR_REACHMAXRECORDNUM;
					msg.ErrorMsg = "�����Ѿ��ﵽ����¼��";
					FTDC_ADD_FIELD(&m_pkgSend, &msg);
					pSession->SendRequestPackage(&m_pkgSend);
					return;
				}

				if (totalSize != 0)
				{	// �м�¼������Ҫ����
					FTDC_ADD_FIELD(&m_pkgSend, &rsp);
					if (!(totalSize < (FTDC_PACKAGE_MAX_SIZE - messageSize)))
					{
						// ���ݰ������������ˣ����з���,ÿһ�ε����ݰ����֧��4000�ֽ�
						pSession->SendRequestPackage(&m_pkgSend);
						m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryNetRomotePingResultInfoTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);

						totalSize = 0;
					}
				}

				/// ��ȡ����
				mPackSend++;
				rsp.ID = cmd.Field("ID").asLong();
				rsp.SouIPADDR = cmd.Field("SouIPADDR").asString();
				rsp.SouNAME = cmd.Field("SouNAME").asString();
				rsp.TarIPADDR = cmd.Field("TarIPADDR").asString();
				rsp.TarNAME = cmd.Field("TarNAME").asString();
				rsp.PDateSta = cmd.Field("PDateSta").asString();
				rsp.PTimeSta = cmd.Field("PTimeSta").asString();
				rsp.ConnRate = cmd.Field("ConnRate").asLong();
				rsp.TimeDlyMin = cmd.Field("TimeDlyMin").asString();
				rsp.TimeDlyMax = cmd.Field("TimeDlyMax").asString();
				rsp.TimeDlyAvg = cmd.Field("TimeDlyAvg").asString();

				//GetRow(&cmd, (char *)&rsp, &CFTDSysRomotePingResultInfoField::m_Describe);
				totalSize += messageSize;
				cnt++;
			}

			if (totalSize != 0)
			{
				FTDC_ADD_FIELD(&m_pkgSend, &rsp);
				pSession->SendRequestPackage(&m_pkgSend);
			}

			if (cnt)
			{
				msg.ErrorID = DBMSG_SUC_SUCCESS;
				msg.ErrorMsg = "db query finish";
			}
			else
			{
				msg.ErrorID = DBMSG_SUC_NORECORD;
				msg.ErrorMsg = "not exists record";
			}

			m_pkgSend.SetChain(FTDC_CHAIN_LAST);
			FTDC_ADD_FIELD(&m_pkgSend, &msg);
			pSession->SendRequestPackage(&m_pkgSend);
		}
		catch(SAException & ex)
		{
			print_errmsg(
				__FILE__,
				__FUNCTION__,
				__LINE__,
				(const char *)ex.ErrText());

			msg.ErrorID = DBMSG_ERR_EXCEPTION;
			msg.ErrorMsg = "DB access exception";

			m_pkgSend.SetChain(FTDC_CHAIN_LAST);
			FTDC_ADD_FIELD(&m_pkgSend, &msg);
			pSession->SendRequestPackage(&m_pkgSend);
		}
		return;
	}

	//if (0 == strTip.length())
	//{
	//	msg.ErrorID = DBMSG_SUC_NORECORD;
	//	msg.ErrorMsg = "no target ip";

	//	m_pkgSend.SetChain(FTDC_CHAIN_LAST);
	//	FTDC_ADD_FIELD(&m_pkgSend, &msg);
	//	pSession->SendRequestPackage(&m_pkgSend);
	//	return;
	//}

	string	strDate = req.PDateSta.getValue();
	string	strTime = req.PTimeSta.getValue();

	int nChkAddion = 0;
	if (0 == strDate.length())
	{
		nChkAddion++;
	}

	if (0 == strTime.length())
	{
		nChkAddion++;
	}

	if (1 == nChkAddion)
	{
		msg.ErrorID = DBMSG_SUC_NORECORD;
		msg.ErrorMsg = "miss date and time";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
		return;
	}

	int mPackSend = 0;
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryNetRomotePingResultInfoTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	try
	{
		//����Oracle���ݿ�
		if (!connectDB())
		{
			return;
		}

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);

		//û��ʱ������ڣ��������30��
		if (2 == nChkAddion)
		{
			cmd.setCommandText(
					"select * from (select * from t_SysRomotePingResultInfo where SouIPADDR = :1 and TarIPADDR = :2 order by pdatesta desc, ptimesta desc) where rownum <=30  order by pdatesta, ptimesta");
			cmd << req.SouIPADDR << req.TarIPADDR;
		}
		else
		{
			cmd.setCommandText(
					"select * from t_SysRomotePingResultInfo where SouIPADDR = :1 and TarIPADDR = :2 and PDateSta >= :3 and PTimeSta >= :4 order by pdatesta, ptimesta");
			cmd <<
				req.SouIPADDR <<
				req.TarIPADDR <<
				req.PDateSta <<
				req.PTimeSta;
		}

		cmd.Execute();

		int cnt = 0;
		while (cmd.FetchNext())
		{
			if (mPackSend >= MAXQRYRETURNNUM)
			{
				m_pkgSend.PrepareResponse(
						pFTDCPackage,
						FTD_TID_RspQryNetRomotePingResultInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				msg.ErrorID = ERR_REACHMAXRECORDNUM;
				msg.ErrorMsg = "�����Ѿ��ﵽ����¼��";
				FTDC_ADD_FIELD(&m_pkgSend, &msg);
				pSession->SendRequestPackage(&m_pkgSend);
				return;
			}

			if (totalSize != 0)
			{	// �м�¼������Ҫ����
				FTDC_ADD_FIELD(&m_pkgSend, &rsp);
				if (!(totalSize < (FTDC_PACKAGE_MAX_SIZE - messageSize)))
				{
					// ���ݰ������������ˣ����з���,ÿһ�ε����ݰ����֧��4000�ֽ�
					pSession->SendRequestPackage(&m_pkgSend);
					m_pkgSend.PrepareResponse(
							pFTDCPackage,
							FTD_TID_RspQryNetRomotePingResultInfoTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);

					totalSize = 0;
				}
			}

			/// ��ȡ����
			mPackSend++;
			rsp.ID = cmd.Field("ID").asLong();
			rsp.SouIPADDR = cmd.Field("SouIPADDR").asString();
			rsp.SouNAME = cmd.Field("SouNAME").asString();
			rsp.TarIPADDR = cmd.Field("TarIPADDR").asString();
			rsp.TarNAME = cmd.Field("TarNAME").asString();
			rsp.PDateSta = cmd.Field("PDateSta").asString();
			rsp.PTimeSta = cmd.Field("PTimeSta").asString();
			rsp.ConnRate = cmd.Field("ConnRate").asLong();
			rsp.TimeDlyMin = cmd.Field("TimeDlyMin").asString();
			rsp.TimeDlyMax = cmd.Field("TimeDlyMax").asString();
			rsp.TimeDlyAvg = cmd.Field("TimeDlyAvg").asString();

			//GetRow(&cmd, (char *)&rsp, &CFTDSysRomotePingResultInfoField::m_Describe);
			totalSize += messageSize;
			cnt++;
		}

		if (totalSize != 0)
		{
			FTDC_ADD_FIELD(&m_pkgSend, &rsp);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		if (cnt)
		{
			msg.ErrorID = DBMSG_SUC_SUCCESS;
			msg.ErrorMsg = "db query finish";
		}
		else
		{
			msg.ErrorID = DBMSG_SUC_NORECORD;
			msg.ErrorMsg = "not exists record";
		}

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		msg.ErrorID = DBMSG_ERR_EXCEPTION;
		msg.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &msg);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}


void Print_CFTDRspQryPerformanceTopField(CFTDReqQryPerformanceTopField &fieldInfo)
{
	string str_AttrType, str_NetSubArea, str_KeyWord;
	int int_SortValue, int_SortType, int_DuringTimeType, int_DuringTimeValue;
	char str_NetArea[10] = {0};
	char str_TopN[10] = {0};

	///���ָ������
	str_AttrType = fieldInfo.AttrType.getValue();
	///��������
	fieldInfo.NetArea.getString(str_NetArea);
	///����������
	str_NetSubArea = fieldInfo.NetSubArea.getValue();
	///��ѯ�ؼ���
	str_KeyWord = fieldInfo.KeyWord.getValue();
	///������ֵ����, 0: avgvalue, ƽ��ֵ;1: minvalue, ��Сֵ;2: maxvalue, ���ֵ
	int_SortValue = fieldInfo.SortValue.getValue();

	///��������, 1, ����ȡ��С��ǰN����; 2, ����ȡ����ǰN����
	int_SortType = fieldInfo.SortType.getValue();
	///��ѯʱ������, 1, ����; 2, Сʱ; 3, ��
	int_DuringTimeType = fieldInfo.DuringTimeType.getValue();

	///��ѯʱ��ֵ,��DuringTimeType��ϳ�Ϊ����Ĳ�ѯʱ��
	int_DuringTimeValue = fieldInfo.DuringTimeValue.getValue();
	///ǰN��ֵ
	fieldInfo.TopN.getString(str_TopN);

	printf("##############################\n\
		   \tAttrType[%s] NetArea[%s] NetSubArea[%s] KeyWord[%s] SortValue[%d] SortType[%d] DuringTimeType[%d] DuringTimeValue[%d] TopN[%s]\n\
		   ##############################\n",
		   str_AttrType.c_str(),
		   str_NetArea,
		   str_NetSubArea.c_str(),
		   str_KeyWord.c_str(),
		   int_SortValue,
		   int_SortType,
		   int_DuringTimeType,
		   int_DuringTimeValue,
		   str_TopN);
}

void CQueryServer::OnReqQryPerformanceTopTopic( /*/ ��������TopN��ѯ */ 
	CFTDCPackage *pFTDCPackage, 
	CFTDCSession *pSession )
{
	CFTDReqQryPerformanceTopField ReqField;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &ReqField);

#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
	Print_CFTDRspQryPerformanceTopField(ReqField);
#endif

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));

	string strAttrType, strNetSubArea, strKeyWord, strSortType;
	int nSortValue, nDuringTimeType, nDuringTimeValue, nTopN;
	char szNetArea[10] = {0};

	///���ָ������
	strAttrType = ReqField.AttrType.getValue();
	///��������
	ReqField.NetArea.getString(szNetArea);
	///����������
	strNetSubArea = ReqField.NetSubArea.getValue();
	///��ѯ�ؼ���
	strKeyWord = ReqField.KeyWord.getValue();
	///������ֵ����, 0: avgvalue, ƽ��ֵ;1: minvalue, ��Сֵ;2: maxvalue, ���ֵ
	nSortValue = ReqField.SortValue.getValue();
	char* SortValueEnum[3] = {"AVGVALUE", "MINVALUE", "MAXVALUE"};

	///��������, 1, ����ȡ��С��ǰN����; 2, ����ȡ����ǰN����
	strSortType = ReqField.SortType.getValue() == 2 ? " desc": "";
	
	///��ѯʱ������, 1, ����; 2, Сʱ; 3, ��
	nDuringTimeType = ReqField.DuringTimeType.getValue();
	int DuringTimeEnum[3] = {1, 60, 24 * 60};
	///��ѯʱ��ֵ,��DuringTimeType��ϳ�Ϊ����Ĳ�ѯʱ��
	nDuringTimeValue = ReqField.DuringTimeValue.getValue();
	// ���ݲ�ѯʱ��Ķ��壬�õ������ʱ�������뵱ǰʱ����ٷ���
	int nTimeOffSet_min = nDuringTimeValue * DuringTimeEnum[nDuringTimeType - 1];

	///ǰN��ֵ
	nTopN = ReqField.TopN.getValue();
/*
	// ���ڱ����ѯ����е�ʱ���ֶ�
	char _nowTime[10];
	char _nowDate[10];
	char _startTime[10];
	char _startDate[10];

	// ���ݲ��������ѯ������ʼʱ��
	time_t nNowTime = time((time_t *)NULL);		// ��ǰʱ��
	// ת��Ϊtm��ʽ������ת�����ַ���
	struct tm *tm_nowTime = localtime(&nNowTime);
	// ת��Ϊ�ַ���
	strftime(_nowTime, 10, "%H:%M:%S", tm_nowTime);
	strftime(_nowDate, 10, "%Y%m%d", tm_nowTime);

	time_t nStartTime = nNowTime;		// ��ʼʱ��
	nStartTime -= (nDuringTimeValue * DuringTimeEnum[nDuringTimeType - 1]);
	struct tm *tm_startTime = localtime(&nStartTime);
	strftime(_startTime, 10, "%H:%M:%S", tm_startTime);
	strftime(_startDate, 10, "%Y%m%d", tm_startTime);
*/
	try
	{
		//����Oracle���ݿ�
		if (!connectDB())
		{
			return;
		}

		// ���ڱ����豸�������select���
		string strSubAraeIdCmd = "select id from t_sysnetsubarea";
		if (szNetArea[0] != '0' || strNetSubArea.find("ALL") == string::npos)
		{
			strSubAraeIdCmd.append(" where ");

			if (szNetArea[0] != '0')
			{
				strSubAraeIdCmd.append("t_sysnetsubarea.sysnetareaid = ");
				strSubAraeIdCmd.append(szNetArea);
			}

			// ����������������Ϣ
			if (strNetSubArea.find("ALL") == string::npos)	// ���������ALL�ֶΣ���������������������
			{
				if (szNetArea[0] != '0')
					strSubAraeIdCmd.append(" and ");

				strSubAraeIdCmd.append("( ");	// ���ڱ������������Ƶ�SQL�ֶ�

				// �鿴�����򲿷��Ƿ��������ֶ�
				char NetSubAreaBuffer[64] = {0};
				memcpy(NetSubAreaBuffer, strNetSubArea.c_str(), strNetSubArea.size());
				char* p = strtok(NetSubAreaBuffer, ";");
				if (p != NULL)
				{
					strSubAraeIdCmd.append("t_sysnetsubarea.ename = \'");
					strSubAraeIdCmd.append(p);
					strSubAraeIdCmd.append("\' ");

					while ((p = strtok(NULL, ";")) != NULL)
					{
						strSubAraeIdCmd.append("OR t_sysnetsubarea.ename = \'");
						strSubAraeIdCmd.append(p);
						strSubAraeIdCmd.append("\' ");
					}
				}
				strSubAraeIdCmd.append(")");
			}
		}

		// ���ڱ����豸ObjectID��select�����
		char szDeviceObjectIDCmd[1024] = {0};
		sprintf(szDeviceObjectIDCmd, "select objectid from t_sysnetdevice where t_sysnetdevice.sysnetsubareaid in ( %s )",
				strSubAraeIdCmd.c_str());
		
		// ���ڱ���KeyWord��and�����
		char szKeyWordCmd[1024] = {0};
		if (!strKeyWord.empty())
			sprintf(szKeyWordCmd, " and objectid LIKE \'%%%s%%\'", strKeyWord.c_str());

		// ���ڱ���select ���������
		char szSelectSortCmd[2048] = {0};
		sprintf(szSelectSortCmd, "select begintime,objectid,%s, row_number() over (partition by objectid order by %s %s,begintime) rn from t_syshistoryobjectattr where attrtype=\'%s\' and ((sysdate - to_date(concat(mondate, begintime), 'yyyy-mm-dd hh24:mi:ss'))*24*60 <= %d) and objectid in ( %s ) %s",
							   SortValueEnum[nSortValue], SortValueEnum[nSortValue], strSortType.c_str(),
							   strAttrType.c_str(),
							   nTimeOffSet_min,
							   szDeviceObjectIDCmd, szKeyWordCmd);

		// ���ڱ���������SQL���
		char szCmd[2048] = {0};
		sprintf(szCmd, "select * from ( select objectid,%s,rn from ( %s ) where rn=1 order by %s %s ) where rownum <= %d",
					SortValueEnum[nSortValue], szSelectSortCmd, 
					SortValueEnum[nSortValue], strSortType.c_str(),
					nTopN);

		SACommand cmd;
		cmd.setConnection(m_sqlConnect);
		cmd.setCommandText(szCmd);


		// just for testing
		printf("##########\n");
		printf("%s\n", szCmd);

		cmd.Execute();

		// ������Ӧ����
		CFTDRspQryPerformanceTopField RspField;
		memset(&RspField, 0, sizeof(CFTDRspQryPerformanceTopField));
		CopyRspQryPerformanceTopEntity(&RspField, &ReqField);


		int nPacketSendCount = 0;
		m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryPerformanceTopTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

		// ����ȡ������������
		int nSendIndex = 0;
		// ������ϵ�������
		SAString sasSortRes;
		while (cmd.FetchNext())
		{
			nSendIndex++;

			// ��ȡ�õ�ObjectIDת��ΪIP��ַ
			SACommand ObjectIDtoIP_cmd;
			ObjectIDtoIP_cmd.setConnection(m_sqlConnect);
			ObjectIDtoIP_cmd.setCommandText("select IPADDR from t_sysnetdevice where ObjectID = :1");
			ObjectIDtoIP_cmd<<cmd.Field(1).asString();
			ObjectIDtoIP_cmd.Execute();

			// ���û��ȡ��IP��ַ������ObjectID��ʾ�豸
			SAString DeviceIndex = (ObjectIDtoIP_cmd.FieldCount() == 1 && ObjectIDtoIP_cmd.FetchNext()) ?
									(ObjectIDtoIP_cmd.Field(1).asString()) : (cmd.Field(1).asString());
			DeviceIndex.TrimRight();

			// ���ڱ��浥һ���������ַ���
			SAString sasTempRes;
			sasTempRes.Format("%d#", nSendIndex);
			sasTempRes += DeviceIndex;
			sasTempRes += "#";
			sasTempRes += cmd.Field(2).asString();
			sasTempRes += ";";

			// TopResult��󳤶�Ϊ256
			if (sasSortRes.GetLength() + sasTempRes.GetLength() >= 256)
			{
				RspField.TopResult = sasSortRes;
				FTDC_ADD_FIELD(&m_pkgSend, &RspField);

				// ��ս���ַ�����׼������װ��������
				memset(&RspField, 0, sizeof(CFTDRspQryPerformanceTopField));
				CopyRspQryPerformanceTopEntity(&RspField, &ReqField);
				sasSortRes.Empty();

				if (m_pkgSend.Length() + sizeof(CFTDRspQryPerformanceTopField) > FTDC_PACKAGE_MAX_SIZE)
				{
					pSession->SendRequestPackage(&m_pkgSend);
					m_pkgSend.PrepareResponse(
						pFTDCPackage,
						FTD_TID_RspQryPerformanceTopTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
				}
			}
			sasSortRes += sasTempRes;
		}

		if (!sasSortRes.IsEmpty())
		{
			RspField.TopResult = sasSortRes;
			FTDC_ADD_FIELD(&m_pkgSend, &RspField);
		}

		if (nSendIndex)
		{
			rspInfoField.ErrorID = DBMSG_SUC_SUCCESS;
			rspInfoField.ErrorMsg = "db query finish";
		}
		else
		{
			rspInfoField.ErrorID = DBMSG_SUC_NORECORD;
			rspInfoField.ErrorMsg = "not exists record";
		}

		// ���ͽ�������
		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);

	}
	catch(SAException & ex)
	{
		print_errmsg(
			__FILE__,
			__FUNCTION__,
			__LINE__,
			(const char *)ex.ErrText());

		rspInfoField.ErrorID = DBMSG_ERR_EXCEPTION;
		rspInfoField.ErrorMsg = "DB access exception";

		m_pkgSend.SetChain(FTDC_CHAIN_LAST);
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}
