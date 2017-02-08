/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	FrontServer.cpp
///@brief	实现了前置监听监控客户端连接使用的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#pragma warning(disable : 4786)
#include "CSlogServer.h"
#include "COrderRttManager.h"
#include "CStatusSubscriber.h"
#include <FTDDataHelper.h>
#include <CDeployConfig.h>
#include <StringUtil.h>
#include <UFEntityCopy.h>

extern COrderRttAnalysis *g_OrderRttAnalysis;
extern map<CPeakKey, CFTDRtnHistoryTradePeakField>	g_mapTradePeak; // 指标历史最大值map
extern CStatusSubscriber *g_pStatusSubcriber;
extern CJudgeRun *g_pJudgeRun;		// 全局时间段判断处理对象，只能一次构造
extern int	g_nTimeZoneSec;			//换算成秒的时差

//20080714 add wu.yb
extern string g_strDbIp;
extern string g_strDbPort;
extern string g_strDbName;
extern string g_strDbUser;
extern string g_strDbPwd;
extern CSlogQuery *g_pSlogQuery;	// Slog查询服务实例指针
#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pPackOutput;		// 数据包输出到文件
#endif

//////////////////////////////////////////////////////////////////////////
//20121023 feng.q
extern COrderRttAnalysis *g_OrderRttAnalysis;

//报单响应分布，切割线
extern unsigned int g_nRttCutLine[8];

CQWordMonitorIndex* CSlogServer::m_pRtt2FrontByteMonitor = new CQWordMonitorIndex("Rtt2Front", 10);

//////////////////////////////////////////////////////////////////////////
CQueryTimmer::CQueryTimmer(CReactor *pReactor, CSlogServer *pQuery) :
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
		case 3:
			if (g_pStatusSubcriber != NULL)
			{
				time_t	timep = time((time_t *)NULL);
				timep = timep - g_nTimeZoneSec;
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

CSlogServer::CSlogServer(CReactor *pReactor) :
	CAgentSessionFactory(pReactor, 10),
	m_eventTimer(pReactor, this)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);

	//m_eventTimer.SetTimer(1, 2 * 60 * 1000);	// 每分钟统计一次前置的响应时间
	//m_eventTimer.SetTimer(2, 60 * 1000);
	m_eventTimer.SetTimer(3, 500);				// 每半秒种检查一下监控指标的消息文件输出
	m_eventTimer.SetTimer(4, 1000);				//每秒检查rtt
	if (m_pRtt2FrontByteMonitor)
	{
		m_pRtt2FrontByteMonitor->setValue(0);
	}
	else
	{
		m_pRtt2FrontByteMonitor = new CQWordMonitorIndex("Rtt2Front", 10);
	}
}

CSlogServer::~CSlogServer(void)
{
}

CSession *CSlogServer::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);

	/// Added by Henchi, 20120309
	pSession->SetCompressMethod(CRPCM_ZERO);	//设置压缩算法
	return pSession;
}

void CSlogServer::OnSessionConnected(CSession *pSession)
{
	CSessionFactory::OnSessionConnected(pSession);
	printf(
		"\tCSlogServer::OnSessionConnected: %0x\n",
		(CFTDCSession *)pSession);

	m_frontSessions.push_back((CFTDCSession *)pSession);

	CFTDCSession *pFtdSession = dynamic_cast<CFTDCSession *>(pSession);

	// 把 g_mapTradePeak 中所有的数据发送到登录的前置 20081216 by zhou.jj
	map<CPeakKey, CFTDRtnHistoryTradePeakField>::iterator mit;
	for (mit = g_mapTradePeak.begin(); mit != g_mapTradePeak.end(); mit++)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RtnHistoryTradePeakTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &(mit->second));

		//m_pkgSend.MakePackage(); 如果往流里面放数据包需要执行MakePackage操作
		pFtdSession->SendRequestPackage(&m_pkgSend);
	}

	///推送当前的统计区间
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

		//前置只有当天交易数据, 交易日为空
		rtnCutLine.MonDate = "";

		FTDC_ADD_FIELD(&m_pkgSend, &rtnCutLine);
		pFtdSession->SendRequestPackage(&m_pkgSend);
	}

	//往前置推送rtt数据
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
				rtnField.MonDate = m_Iter->second.monDate.c_str();
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

void CSlogServer::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
	printf(
		"\tCFrontServer::OnSessionDisconnected CFTDCSession remove %0x\n",
		(CFTDCSession *)pSession);
	m_frontSessions.remove((CFTDCSession *)pSession);
}

void CSlogServer::NotifyAllSession(CFTDCPackage *pkg)
{
	assert(pkg);

	list<CFTDCSession *>::iterator	it;
	for (it = m_frontSessions.begin(); it != m_frontSessions.end(); it++)
	{
		(*it)->SendRequestPackage(pkg);
		pkg->Pop(FTDCHLEN);
	}
}

int CSlogServer::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
	pFTDCPackage->OutputHeader(g_pPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pPackOutput);
#endif
	printf("\tCFrontServer::receive package TID %x\n", pFTDCPackage->GetTID());
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_ReqQryFrontInfoTopic:
			OnReqQryFrontInfo(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTradeLogTopic:
			OnReqQryTradeLog(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetDeviceLinkedTopic:
			// 由于某种原因，暂时采用了FTD_TID_ReqQryNetDeviceLinkedTopic作为queryLatestSlog的查询请求。
			OnReqQryLatestTradeLog(pFTDCPackage, pSession);
			break;
		default:
			break;
	}

	return 0;
}

void CSlogServer::OnReqQryTradeLog(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	g_pSlogQuery->querySlog(pFTDCPackage, pSession);
}


void CSlogServer::OnReqQryLatestTradeLog(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	g_pSlogQuery->queryLatestSlog(pFTDCPackage, pSession);
}

typedef struct
{
	CFTDCPackage *rsp;
	CFTDCSession *session;
	CFTDCPackage *req;
	int pkgID;
	bool findRecord;
} SearchCallBackData_T;


///查询 Front 信息
void CSlogServer::OnReqQryFrontInfo(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
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
void CSlogServer::OnReqQryFrontInfo(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);

	CFTDReqQryFrontInfoField fieldInfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);

	// 生成 CFTDRspQryFrontInfoField 并进行发送，可以一次发送最大字节数是4000==FTDC_PACKAGE_MAX_SIZE
	//连接Oracle数据库
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
			{	// 有记录数据需要处理
				FTDC_ADD_FIELD(&m_pkgSend, &rspFieldInfo);
				if (!(totalSize < (FTDC_PACKAGE_MAX_SIZE - messageSize)))
				{
					// 数据包缓冲区快满了，进行发送,每一次的数据包最大支持4000字节
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

//每秒检查一次slog分析结果
void CSlogServer::CheckTradeFrontRtt(void)
{
	//需要打包的rtt数据
	map<int, CRttReadyMap>	mapRttForRtn;

	if (g_OrderRttAnalysis->CheckRtnIsReady(mapRttForRtn))
	{
		//如果没有前置连接直接返回
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
				rspField.MonDate = m_Iter->second->monDate.c_str();
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

				m_pRtt2FrontByteMonitor->incValue(sizeof(rspField));
			}
		}
	}
}

