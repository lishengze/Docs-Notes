/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CounterConnector.cpp
///@brief	实现了连接事件计算服务器并处理该服务器通信消息的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#include "CounterConnector.h"
#include "CStatusSubscriber.h"

//////////////////////////////////////////////////////////////////////////
//modify @ 20120920 feng.q
//extern CStatusSubscriber     *g_pStatusSubcriber;
//extern CCachedFileFlow *g_pFlow;
extern CStatusSubscriber *g_pStatusSubcriber;
extern string g_strTradeDay;
extern bool g_bChangeCutLineNextDay;

//////////////////////////////////////////////////////////////////////////
extern CSlogQuery *g_pSlogQuery;				// Slog查询服务实例指针，切换交易日需要重新构造对象
extern CFileOperation *g_fileOperation;			// 读写文件类对象指针，切换交易日需要重新构造
extern map<string, long> g_mapFileReadSize;		// 保存每个文件已经收到的读写位置，切换交易日需要清除
extern map<string, int> g_mapSlogFileName;		// 当前正在分析的Slog文件map，切换交易日时需要重新构造
extern COrderRttAnalysis *g_OrderRttAnalysis;	// 报单相应速度分析类对象指针，切换交易日需要重新构造
extern CSlogReactor *g_pReactor;				// 全局reactor对象指针，只能一次构造
extern CDirectlySlogDecode	*g_CSlogDec;

extern map<int, int> m_mapSlogFileReadStatus;

#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pPackOutput;					// 数据包输出到文件
#endif

//
// 面向计算服务器连接的类实现

//
CCountConnector::CCountConnector(CReactor *pReactor) :
	CAgentSessionFactory(pReactor, 1)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
}

CSession *CCountConnector::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);
	return pSession;
}

void CCountConnector::OnSessionConnected(CSession *pSession)
{
	CAgentSessionFactory::OnSessionConnected(pSession);
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
	printf(
		"\tCountConnector::OnSessionConnected: %s\n",
		pSession->GetChannel()->GetRemoteName());

	m_pkgSend.PreparePackage(
			FTD_TID_ReqUserLogin,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqUserLoginField fieldLogin;
	memset(&fieldLogin, 0, sizeof(fieldLogin));
	fieldLogin.UserID = "slog";
	fieldLogin.Password = "slogpd";
	FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);

	CFTDDisseminationField	fieldDissemination;
	for (int i = 1; i < MAX_EVENTFLOWNUM + 1; i++)
	{
		printf(
			"\t Flow count %d\n",
			i,
			g_pStatusSubcriber->m_pSubEnd[i]->m_pFlow->GetCount());
		fflush(stdout);
		fieldDissemination.SequenceSeries = i;	// GetSequenceSeries();
		fieldDissemination.SequenceNo = g_pStatusSubcriber->m_pSubEnd[i]->m_pFlow->GetCount();	// GetReceivedCount();
		FTDC_ADD_FIELD(&m_pkgSend, &fieldDissemination);
		((CFTDCSession *)pSession)->RegisterSubscriber(
				g_pStatusSubcriber->m_pSubEnd[i]);
	}

	// 	printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	// 	printf("\t Flow count %d\n", g_pStatusSubcriber->GetReceivedCount());	
	// 	fieldDissemination.SequenceSeries = g_pStatusSubcriber->GetSequenceSeries();   // GetSequenceSeries();
	// 	fieldDissemination.SequenceNo =     g_pStatusSubcriber->GetReceivedCount();    // GetReceivedCount();
	// 	FTDC_ADD_FIELD(&m_pkgSend, &fieldDissemination);
	((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);

	// 	((CFTDCSession *)pSession)->RegisterSubscriber(g_pStatusSubcriber);
}

void CCountConnector::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
	printf(
		"\tCCountConnector::OnSessionDisconnected: %0x\n",
		(CFTDCSession *)pSession);
}

int CCountConnector::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	pFTDCPackage->OutputHeader(g_pPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pPackOutput);
#endif
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_RspUserLogin:
			OnRspUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTradeDayChangeTopic:
			OnReqQryTradeDayChange(pFTDCPackage, pSession);
			break;
		default:
			break;
	}

	return 0;
}

void CCountConnector::OnRspUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspInfoField fieldRspInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldRspInfo))
	{
		printf(
			"\tCCountConnector::OnRspUserLogin fieldRspInfo.ErrorMsg = %s\n",
			(const char *)fieldRspInfo.ErrorMsg);
	}

	// 	//需要切换交易日
	// 	if (fieldChange.ChangeType == TRUNCATEFLOW
	// 		&& m_strTradeDay != ""
	// 		&& fieldChange.NewDate != m_strTradeDay.data())
	// 	{
	//
	// 	}
	//
	// 	m_strTradeDay = fieldChange.NewDate.getValue();
}

void CCountConnector::OnReqQryTradeDayChange(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryTradeDayChangeField fieldChange;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldChange);

	//....
	if (strcmp(fieldChange.ChangeType.getValue(), TRUNCATEFLOW) == 0)
	{
		//modify by feng.q @20120920
		// 将该对应该编号的流容易清0，向事件服务器重新订阅流
		printf("清除编号为 %s 的流数据\n", (const char *)fieldChange.OldDate);

		int nSeq = atoi((const char *)fieldChange.OldDate);
		nSeq++;
		if (nSeq > MAX_EVENTFLOWNUM)
		{
			return;
		}

		if (g_pStatusSubcriber != NULL
		&&	g_pStatusSubcriber->m_pSubEnd[nSeq] != NULL)
		{
			g_pStatusSubcriber->m_pSubEnd[nSeq]->m_pFlow->Truncate(0);
		}

		// 		if (nSeq!=g_pStatusSubcriber->GetSequenceSeries())
		// 		{
		// 			return;
		// 		}
		// 		if (g_pFlow!=NULL) g_pFlow->Truncate(0);
		m_pkgSend.PreparePackage(
				FTD_TID_ReqUserLogin,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		CFTDReqUserLoginField fieldLogin;
		memset(&fieldLogin, 0, sizeof(fieldLogin));
		fieldLogin.UserID = "slog";
		fieldLogin.Password = "querypd";
		FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);

		CFTDDisseminationField	fieldDissemination;
		fieldDissemination.SequenceSeries = nSeq;				// GetSequenceSeries();
		fieldDissemination.SequenceNo = g_pStatusSubcriber->m_pSubEnd[nSeq]->m_pFlow->GetCount();	// GetReceivedCount();
		FTDC_ADD_FIELD(&m_pkgSend, &fieldDissemination);
		((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
		((CFTDCSession *)pSession)->RegisterSubscriber(
				g_pStatusSubcriber->m_pSubEnd[nSeq]);
	}
	else if (strcmp(fieldChange.ChangeType.getValue(), CHANGETRADEDAY) == 0)						// 更换交易日处理
	{
		//1.清除本地收到的流，向事件服务器重新订阅流
		// 		if (g_pFlow!=NULL) g_pFlow->Truncate(0);
		// 		m_pkgSend.PreparePackage(FTD_TID_ReqUserLogin, FTDC_CHAIN_LAST, FTD_VERSION);
		// 		CFTDReqUserLoginField fieldLogin;
		// 		memset(&fieldLogin, 0, sizeof(fieldLogin));
		// 		fieldLogin.UserID = "query";
		// 		fieldLogin.Password = "querypd";
		// 		FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);
		// 		CFTDDisseminationField fieldDissemination;
		// 		fieldDissemination.SequenceSeries = g_pStatusSubcriber->GetSequenceSeries();   // GetSequenceSeries();
		// 		fieldDissemination.SequenceNo =     g_pStatusSubcriber->GetReceivedCount();    // GetReceivedCount();
		// 		FTDC_ADD_FIELD(&m_pkgSend, &fieldDissemination);
		// 		((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
		// 		((CFTDCSession *)pSession)->RegisterSubscriber(g_pStatusSubcriber);
		//2.清除本地的生成的Slog文件，删除文件
		if (g_strTradeDay != ""
		&&	fieldChange.NewDate != ""
		&&	g_strTradeDay != fieldChange.NewDate.getValue())
		{
			g_mapFileReadSize.clear();
			g_mapSlogFileName.clear();
			if (g_fileOperation != NULL)
			{
				delete g_fileOperation;
				g_fileOperation = new CFileOperation();
			}
			else
			{
				g_fileOperation = new CFileOperation();
			}

			//3.清除本地的Slog会话，删除保存Slog的所有信息
			if (g_OrderRttAnalysis != NULL)
			{
				delete g_OrderRttAnalysis;
				g_OrderRttAnalysis = new COrderRttAnalysis();	// 响应速度分析类对象指针
			}
			else
			{
				g_OrderRttAnalysis = new COrderRttAnalysis();
			}

			m_mapSlogFileReadStatus.clear();

			g_pReactor->Clear();

			g_CSlogDec->Clear();

			//4.清除本地保存的m_mapSlog数据包内容
			if (g_pSlogQuery != NULL)
			{
				delete g_pSlogQuery;
			}

			g_pSlogQuery = new CSlogQuery();					// 初始化查询实例指针
		}

		g_strTradeDay = fieldChange.NewDate.getValue();

		if (g_bChangeCutLineNextDay && g_pStatusSubcriber)
		{
		//	g_pStatusSubcriber->InitTradeOrderCutLine();
		}
	}
}
