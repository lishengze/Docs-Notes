/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	FrontServerBusiness.cpp
///@brief	实现了前置监听监控客户端连接使用的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#include "utility.h"
#include "FrontServer.h"
#include "CListSession.h"
#include "CQueryAgent.h"
#include "CSlogAgent.h"
#include "CountConnector.h"
#include "CPerformanceAnalyze.h"

extern CDataCenterManage *g_pDataCenterManage;
extern CListSessionArray *g_pListSessionArray;
extern char g_mCfgPath[200];

extern CDateType NowDate;
map<int, int> g_SubcriberMap;
extern list<CFTDRspQryFrontInfoField> g_testList;

//key:targetip
map<string, CFTDRtnNetLocalPingResultInfoField> g_localpingresult;

//key:sourceip_targetip
map<string, CFTDRtnNetRomotePingResultInfoField> g_remotepingresult;

//////////////////////////////////////////////////////////////////////////
//add by feng.q 20130130
//会员席位交易数据订阅到时候推送最新一条数据
extern map<string, CFTDRtnParticTradeOrderStatesField>	g_mapRtnPartiOrder;


// add by cao.ning 网络性能处理对象
extern CPerformanceAnalyzer* g_pPerformanceAnalyzer;

//////////////////////////////////////////////////////////////////////////
#define CHECKPKG(x)															 \
	if (m_pkgSend.Length() + sizeof(ftdRspQryField) > FTDC_PACKAGE_MAX_SIZE) \
	{																		 \
		m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);							 \
		((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);			 \
		m_pkgSend.PreparePackage(											 \
				FTD_TID_RspQry##x##Topic,									 \
				FTDC_CHAIN_LAST,											 \
				FTD_VERSION);												 \
		FTDC_ADD_FIELD(&m_pkgSend, &ftdRspQryField);						 \
	}																		 \
	else																	 \
	{																		 \
		FTDC_ADD_FIELD(&m_pkgSend, &ftdRspQryField);						 \
	}

#define CHECKRSPPKG(x)														 \
	if (m_pkgSend.Length() + sizeof(ftdRspQryField) > FTDC_PACKAGE_MAX_SIZE) \
	{																		 \
		m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);							 \
		((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);			 \
		m_pkgSend.PrepareResponse(											 \
				pPackage,													 \
				FTD_TID_RspQry##x##Topic,									 \
				FTDC_CHAIN_LAST,											 \
				FTD_VERSION);												 \
		m_pkgSend.SetRequestId(pPackage->GetRequestId());					 \
		FTDC_ADD_FIELD(&m_pkgSend, &ftdRspQryField);						 \
	}																		 \
	else																	 \
	{																		 \
		FTDC_ADD_FIELD(&m_pkgSend, &ftdRspQryField);						 \
	}

#define EVENTCOUNTERREQ(x)											  \
	{																  \
		CFTDReqQry##x##Field qryfield;								  \
		if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)		  \
		{															  \
			return;													  \
		}															  \
															          \
		TRID  rid;													  \
		rid.SessionID = pSession->GetSessionID();					  \
		rid.RequestId = pPackage->GetRequestId();					  \
		int nRid = m_Rid++;											  \
		m_vRid[nRid] = rid;											  \
		CFTDReqQry##x##Field field;									  \
		CopyReqQry##x##Entity(&field, &qryfield);					  \
		m_pkgSend.PreparePackage(									  \
				FTD_TID_ReqQry##x##Topic,							  \
				FTDC_CHAIN_LAST,									  \
				FTD_VERSION);										  \
		FTDC_ADD_FIELD(&m_pkgSend, &field);							  \
		m_pkgSend.SetRequestId(nRid);								  \
		if (m_pCountConnector->GetCountSession())					  \
		{															  \
			m_pCountConnector->GetCountSession()->SendRequestPackage( \
					&m_pkgSend);									  \
		}															  \
		else														  \
		{															  \
			m_pkgSend.PreparePackage(								  \
					FTD_TID_RspQry##x##Topic,						  \
					FTDC_CHAIN_LAST,								  \
					FTD_VERSION);									  \
			m_pkgSend.SetRequestId(pPackage->GetRequestId());		  \
			CFTDRspInfoField rspInfoField;							  \
			memset(&rspInfoField, 0, sizeof(rspInfoField));			  \
			rspInfoField.ErrorID = ERR_COUNTERUNCONNECT;			  \
			rspInfoField.ErrorMsg = "EventConnectError";			  \
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);				  \
			pSession->SendRequestPackage(&m_pkgSend);				  \
		}															  \
	}

void CFrontServer::OnReqUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqUserLoginField fieldLogin;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldLogin);
	printf(
		"\tCFrontServer::OnReqUserLogin:user=%s password=%s\n",
		(const char *)fieldLogin.UserID,
		(const char *)fieldLogin.Password);
	fflush(stdout);
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspUserLogin,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRspUserLoginField fieldRsp;
	fieldRsp.UserID = "TestUser";
	fieldRsp.ParticipantID = "TestPID";
	FTDC_ADD_FIELD(&m_pkgSend, &fieldRsp);

	CFTDRspInfoField fieldRspInfo;
	fieldRspInfo.ErrorMsg = "成功";
	fieldRspInfo.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
	pSession->SendRequestPackage(&m_pkgSend);

	printf(
		"\tCFrontServer::OnReqUserLogin CFTDCSession push_back %0x\n",
		(CFTDCSession *)pSession);
	fflush(stdout);
}

void CFrontServer::OnQryUserMgr(CFTDCPackage *pPackage, CFTDCSession *pSession)
{
}

void CFrontServer::QryUserFunc(CFTDCPackage *pPackage, CFTDCSession *pSession)
{
}

void CFrontServer::OnReqQryClientLoginTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryClientLoginField	ftdQryField;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &ftdQryField) <= 0)
	{
		return;
	}

	if ((ftdQryField.UserName == "system")
	&&	(ftdQryField.PassWord == "manager"))
	{
		m_pkgSend.PrepareResponse(
				pFTDCPackage,
				FTD_TID_RspUserLogin,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		CFTDRspQryClientLoginField	ftdRspQryField;
		ftdRspQryField.UserName = "system";
		ftdRspQryField.Privalage = "manager";
		FTDC_ADD_FIELD(&m_pkgSend, &ftdRspQryField);

		CFTDRspInfoField fieldRspInfo;
		fieldRspInfo.ErrorMsg = "成功";
		fieldRspInfo.ErrorID = 0;
		FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
	}
	else
	{
		return;
	}
}

void CFrontServer::OnReqQryLocalPingTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryNetLocalPingResultInfoField qryfield;
	FTDC_GET_SINGLE_FIELD(pPackage, &qryfield);

	if (strcmp(qryfield.TarIPADDR.getValue(), "") == 0)
	{
		qryfield.TarIPADDR.setValue("all");
        if (m_pQueryAgent->GetQuerySession())
		{
			SendReqPackageOnAgentSession(qryfield, m_pQueryAgent->GetQuerySession()
				, FTD_TID_ReqQryNetLocalPingResultInfoTopic, false);
			
			m_dwLocaPingReqID = pPackage->GetRequestId();
		}
	}
	else
	{
		//向query查询
		if (m_pQueryAgent->GetQuerySession())
		{
			SendReqPackageOnAgentSession(qryfield, m_pQueryAgent->GetQuerySession()
				, FTD_TID_ReqQryNetLocalPingResultInfoTopic, false);
		}
		else
		{
			OnSessionResponse(FTD_TID_RspQryNetLocalPingResultInfoTopic, ERR_QRYACCWRONG, "QueryConnectError");
		}
	}
}


void CFrontServer::OnReqQryRemotePingTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryNetRomotePingResultInfoField	qryfield;
	FTDC_GET_SINGLE_FIELD(pPackage, &qryfield);

	if (strcmp(qryfield.TarIPADDR.getValue(), "") == 0 
		&& g_remotepingresult.size() > 0)  //本地无缓存的也去query查询
	{
		//查询所有记录
		map<string, CFTDRtnNetRomotePingResultInfoField>::iterator	l_it =
			g_remotepingresult.begin();
		for (; l_it != g_remotepingresult.end(); ++l_it)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryNetRomotePingResultInfoTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());

			CFTDRspQryNetRomotePingResultInfoField	rspfield;
			CopySysRomotePingResultInfoEntity(&rspfield, &l_it->second);

			FTDC_ADD_FIELD(&m_pkgSend, &rspfield);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		OnSessionResponse(FTD_TID_RspQryNetRomotePingResultInfoTopic);
	}
	else
	{
		//向query查询
		if (m_pQueryAgent->GetQuerySession())
		{
			SendReqPackageOnAgentSession(qryfield, m_pQueryAgent->GetQuerySession()
				, FTD_TID_ReqQryNetRomotePingResultInfoTopic, false);
		}
		else
		{
			OnSessionResponse(FTD_TID_RspQryNetRomotePingResultInfoTopic
				, ERR_QRYACCWRONG, "QueryConnectError");
		}
	}
}

void CFrontServer::OnReqQryTopCpuInfoTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	int g_OrderQryCount = 1;

	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryTopCpuInfoField qryfield;
	FTDC_GET_SINGLE_FIELD(pPackage, &qryfield);

	int HostName = g_StringIdMap.getStringId(qryfield.HostName.getValue());

	CSysMdbTopCpuInfo *sfield = pMemoryDB->m_SysMdbTopCpuInfoFactory->
		startFindByHostName(HostName, qryfield.StartDate, qryfield.StartTime);
	while (sfield)
	{
		if ((sfield->MonDate) > (qryfield.EndDate)
		||	(
				(sfield->MonDate) == (qryfield.EndDate) && (sfield->MonTime) >
				(qryfield.EndTime)
	))
		{
			break;
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryTopCpuInfoTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryTopCpuInfoField tfield;

		tfield.HostName = g_StringIdMap.getString(sfield->HostName);
		tfield.MonTime = sfield->MonTime;
		tfield.MonDate = sfield->MonDate;
		tfield.CPU = sfield->CPU;
		tfield.LOAD = sfield->LOAD;
		tfield.USER = sfield->USER;
		tfield.NICE = sfield->NICE;
		tfield.SYS = sfield->SYS;
		tfield.IDLE = sfield->IDLE;
		tfield.BLOCK = sfield->BLOCK;
		tfield.SWAIT = sfield->SWAIT;
		tfield.INTR = sfield->INTR;
		tfield.SSYS = sfield->SSYS;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
		sfield = pMemoryDB->m_SysMdbTopCpuInfoFactory->findNextByHostName();
#ifdef CPUMEMNETLIMET
		if (++g_OrderQryCount > MAXQRYRETURNNUM)
		{
			pMemoryDB->m_SysMdbTopCpuInfoFactory->endFindByHostName();
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryTopCpuInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());

			CFTDRspInfoField rspInfoField;
			memset(&rspInfoField, 0, sizeof(rspInfoField));
			rspInfoField.ErrorID = ERR_REACHMAXRECORDNUM;
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
			pSession->SendRequestPackage(&m_pkgSend);
			return;
		}

#endif
	}

	pMemoryDB->m_SysMdbTopCpuInfoFactory->endFindByHostName();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryTopCpuInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryTopMemInfoTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	int g_OrderQryCount = 1;

	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryTopMemInfoField qryfield;
	FTDC_GET_SINGLE_FIELD(pPackage, &qryfield);

	int HostName = g_StringIdMap.getStringId(qryfield.HostName.getValue());

	CSysMdbTopMemInfo *sfield = pMemoryDB->m_SysMdbTopMemInfoFactory->
		startFindByHostName(HostName, qryfield.StartDate, qryfield.StartTime);
	while (sfield)
	{
		if ((sfield->MonDate) > (qryfield.EndDate)
		||	(
				(sfield->MonDate) == (qryfield.EndDate) && (sfield->MonTime) >
				(qryfield.EndTime)
	))
		{
			break;
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryTopMemInfoTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryTopMemInfoField tfield;

		tfield.HostName = g_StringIdMap.getString(sfield->HostName);
		tfield.ACTIVEREAL = sfield->ACTIVEREAL;
		tfield.ACTIVEVIRTUAL = sfield->ACTIVEVIRTUAL;
		tfield.FREE = sfield->FREE;
		tfield.MonDate = sfield->MonDate;
		tfield.MonTime = sfield->MonTime;
		tfield.TOTALREAL = sfield->TOTALREAL;
		tfield.TOTALVIRTUAL = sfield->TOTALVIRTUAL;

		//printf("\n\n\n\n\n\nTOTAL MEM:%d   FREE MEM:%d\n\n\n\n\n\n\n", (const int)tfield.TOTALREAL, (const int)tfield.FREE);
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
		sfield = pMemoryDB->m_SysMdbTopMemInfoFactory->findNextByHostName();

#ifdef CPUMEMNETLIMET
		if (++g_OrderQryCount > MAXQRYRETURNNUM)
		{
			pMemoryDB->m_SysMdbTopMemInfoFactory->endFindByHostName();
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryTopMemInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());

			CFTDRspInfoField rspInfoField;
			memset(&rspInfoField, 0, sizeof(rspInfoField));
			rspInfoField.ErrorID = ERR_REACHMAXRECORDNUM;
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
			pSession->SendRequestPackage(&m_pkgSend);
			return;
		}

#endif
	}

	pMemoryDB->m_SysMdbTopMemInfoFactory->endFindByHostName();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryTopMemInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryTopProcessInfoTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryTopProcessInfoField qryfield;
	FTDC_GET_SINGLE_FIELD(pPackage, &qryfield);

	// 历史结果查询，转给sysquery
	if (qryfield.StartDate < NowDate)
	{
		if (m_pQueryAgent->GetQuerySession())
		{
			CFTDReqQryTopProcessInfoField field;
		    CopyReqQryTopProcessInfoEntity(&field, &qryfield);
			
			SendReqPackageOnAgentSession(field, m_pQueryAgent->GetQuerySession()
				, FTD_TID_ReqQryTopProcessInfoTopic, false);
		}
		else
		{
			OnSessionResponse(FTD_TID_RspQryTopProcessInfoTopic
				, ERR_QRYACCWRONG, "QueryConnectError");
		}
	}
	else if (qryfield.EndDate < NowDate)
	{
		//全是历史日期
		return;
	}

	int HostName = g_StringIdMap.getStringId(qryfield.HostName.getValue());
	int count = 0;

	CSysMdbTopProcessInfo *sfield = pMemoryDB->m_SysMdbTopProcessInfoFactory->
		startFindByHostName(HostName, qryfield.StartDate, qryfield.StartTime);
	while (sfield)
	{
		if ((sfield->MonDate) > (qryfield.EndDate)
		||	(
				(sfield->MonDate) == (qryfield.EndDate) && (sfield->MonTime) >
				(qryfield.EndTime)
	))
		{
			break;
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryTopProcessInfoTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryTopProcessInfoField tfield;

		tfield.HostName = g_StringIdMap.getString(sfield->HostName);
		tfield.MonTime = sfield->MonTime;
		tfield.MonDate = sfield->MonDate;
		tfield.CPU = sfield->CPU;
		tfield.TTY = sfield->TTY;
		tfield.PID = sfield->PID;
		tfield.USERNAME = sfield->USERNAME;
		tfield.PRI = sfield->PRI;
		tfield.NI = sfield->NI;
		tfield.SIZE = sfield->SIZE;
		tfield.RES = sfield->RES;
		tfield.STATE = sfield->STATE;
		tfield.TIME = sfield->TIME;
		tfield.pWCPU = sfield->pWCPU;
		tfield.pCPU = sfield->pCPU;
		tfield.COMMAND = sfield->COMMAND;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);

		if (++count >= 2000)
		{
			printf("%s process count to limit\n", __FUNCTION__);
			break;
		}

		sfield = pMemoryDB->m_SysMdbTopProcessInfoFactory->findNextByHostName();
	}

	pMemoryDB->m_SysMdbTopProcessInfoFactory->endFindByHostName();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryTopProcessInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryFileSystemInfoTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryFileSystemInfoField qryfield;
	FTDC_GET_SINGLE_FIELD(pPackage, &qryfield);

	int HostName = g_StringIdMap.getStringId(qryfield.HostName.getValue());

	CSysMdbFileSystemInfo *sfield = pMemoryDB->m_SysMdbFileSystemInfoFactory->
		startFindByHostName(HostName, qryfield.StartDate, qryfield.StartTime);
	while (sfield)
	{
		if ((sfield->MonDate) > (qryfield.EndDate)
		||	(
				(sfield->MonDate) == (qryfield.EndDate) && (sfield->MonTime) >
				(qryfield.EndTime)
	))
		{
			break;
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryFileSystemInfoTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryFileSystemInfoField tfield;

		tfield.HostName = g_StringIdMap.getString(sfield->HostName);
		tfield.MonTime = sfield->MonTime;
		tfield.MonDate = sfield->MonDate;
		tfield.FILESYSTEM = sfield->FILESYSTEM;
		tfield.SIZE = sfield->SIZE;
		tfield.USED = sfield->USED;
		tfield.AVAIL = sfield->AVAIL;
		tfield.pUSERD = sfield->pUSERD;
		tfield.ISIZE = sfield->ISIZE;
		tfield.IUSED = sfield->IUSED;
		tfield.IFREE = sfield->IFREE;
		tfield.pIUSED = sfield->pIUSED;
		tfield.MountedOn = sfield->MountedOn;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
		sfield = pMemoryDB->m_SysMdbFileSystemInfoFactory->findNextByHostName();
	}

	pMemoryDB->m_SysMdbFileSystemInfoFactory->endFindByHostName();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryFileSystemInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryNetworkInfoTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	int g_OrderQryCount = 1;

	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryNetworkInfoField	qryfield;
	FTDC_GET_SINGLE_FIELD(pPackage, &qryfield);

	// 历史结果查询，转给sysquery
	if (qryfield.StartDate < NowDate)
	{
		if (m_pQueryAgent->GetQuerySession())
		{
			CFTDReqQryNetworkInfoField	field;
		    CopyReqQryNetworkInfoEntity(&field, &qryfield);
			
			SendReqPackageOnAgentSession(field, m_pQueryAgent->GetQuerySession()
				, FTD_TID_ReqQryNetworkInfoTopic, false);
		}
		else
		{
			OnSessionResponse(FTD_TID_RspQryNetworkInfoTopic
				, ERR_QRYACCWRONG, "QueryConnectError");
		}
	}
	else if (qryfield.EndDate < NowDate)
	{
		//全是历史日期
		return;
	}

	int HostName = g_StringIdMap.getStringId(qryfield.HostName.getValue());

	bool isLanSearch = false;
	string	lanname;

	if (strlen(qryfield.LANNAME.getValue()) > 0)
	{
		isLanSearch = true;
		lanname = qryfield.LANNAME.getValue();
	}

	/*	
	string strHostName = qryfield.HostName.getValue();
	if(strHostName.length() > strlen(".network"))
	{
		//最后一节不是.network，lan查询
		if(strHostName.compare(strHostName.length() - strlen(".network"), strlen(".network"), ".network") != 0)
		{
			isLanSearch = true;
			size_t pos = strHostName.rfind(".");
			if(pos != string::npos)
			{
				lanname = strHostName.substr(pos + 1);
			}
		}
	}
*/
	CSysMdbNetworkInfo	*sfield = pMemoryDB->m_SysMdbNetworkInfoFactory->
		startFindByHostName(HostName, qryfield.StartDate, qryfield.StartTime);
	while (sfield)
	{
		if ((sfield->MonDate) > (qryfield.EndDate)
		||	(
				(sfield->MonDate) == (qryfield.EndDate) && (sfield->MonTime) >
				(qryfield.EndTime)
	))
		{
			break;
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryNetworkInfoTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryNetworkInfoField	tfield;

		tfield.HostName = g_StringIdMap.getString(sfield->HostName);
		tfield.MonTime = sfield->MonTime;
		tfield.MonDate = sfield->MonDate;
		tfield.LANNAME = sfield->LANNAME;
		tfield.LANSTATUS = sfield->LANSTATUS;
		tfield.IPADDRESS = sfield->IPADDRESS;
		tfield.SENDPACKETS = sfield->SENDPACKETS;
		tfield.SENDBYTES = sfield->SENDBYTES;
		tfield.RECVPACKETS = sfield->RECVPACKETS;
		tfield.RECVBYTES = sfield->RECVBYTES;

		if (isLanSearch)
		{
			if (lanname.compare(tfield.LANNAME.getValue()) == 0)
			{
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
				pSession->SendRequestPackage(&m_pkgSend);
			}
		}
		else
		{
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		sfield = pMemoryDB->m_SysMdbNetworkInfoFactory->findNextByHostName();

#ifdef CPUMEMNETLIMET
		if (++g_OrderQryCount > MAXQRYRETURNNUM)
		{
			pMemoryDB->m_SysMdbNetworkInfoFactory->endFindByHostName();
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryNetworkInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());

			CFTDRspInfoField rspInfoField;
			memset(&rspInfoField, 0, sizeof(rspInfoField));
			rspInfoField.ErrorID = ERR_REACHMAXRECORDNUM;
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
			pSession->SendRequestPackage(&m_pkgSend);
			return;
		}

#endif
	}

	pMemoryDB->m_SysMdbNetworkInfoFactory->endFindByHostName();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryNetworkInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryDiskIOTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	int g_OrderQryCount = 1;

	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryDiskIOField qryfield;
	FTDC_GET_SINGLE_FIELD(pPackage, &qryfield);

	// 历史结果查询，转给sysquery
	if (qryfield.StartDate < NowDate)
	{
		if (m_pQueryAgent->GetQuerySession())
		{
			CFTDReqQryDiskIOField field;
		    CopyReqQryDiskIOEntity(&field, &qryfield);
			
			SendReqPackageOnAgentSession(field, m_pQueryAgent->GetQuerySession()
				, FTD_TID_ReqQryDiskIOTopic, false);
		}
		else
		{
			OnSessionResponse(FTD_TID_RspQryDiskIOTopic
				, ERR_QRYACCWRONG, "QueryConnectError");
		}
	}
	else if (qryfield.EndDate < NowDate)
	{
		//全是历史日期
		return;
	}

	int HostName = g_StringIdMap.getStringId(qryfield.HostName.getValue());

	bool isPartSearch = false;
	string	partname;

	string	strHostName = qryfield.HostName.getValue();
	if (strHostName.length() > strlen(".diskio"))
	{
		//最后一节不是.diskio，part查询
		if (strHostName.compare(
				strHostName.length() - strlen(".diskio"),
			strlen(".diskio"),
			".diskio") != 0)
		{
			isPartSearch = true;

			size_t	pos = strHostName.rfind(".");
			if (pos != string::npos)
			{
				partname = strHostName.substr(pos + 1);
				HostName = g_StringIdMap.getStringId(
						strHostName.substr(0, pos).c_str());
			}
		}
	}

	CSysMdbDiskIO *sfield = pMemoryDB->m_SysMdbDiskIOFactory->
		startFindByHostName(HostName, qryfield.StartDate, qryfield.StartTime);
	while (sfield)
	{
		if ((sfield->MonDate) > (qryfield.EndDate)
		||	(
				(sfield->MonDate) == (qryfield.EndDate) && (sfield->MonTime) >
				(qryfield.EndTime)
	))
		{
			break;
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryDiskIOTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryDiskIOField tfield;

		tfield.HostName = qryfield.HostName;
		tfield.MonTime = sfield->MonTime;
		tfield.MonDate = sfield->MonDate;
		tfield.PartName = sfield->PartName;
		tfield.ReadMerges = sfield->ReadMerges;
		tfield.WriteMerges = sfield->WriteMerges;
		tfield.ReadIOs = sfield->ReadIOs;
		tfield.WriteIOs = sfield->WriteIOs;
		tfield.ReadKBs = sfield->ReadKBs;
		tfield.WriteKBs = sfield->WriteKBs;
		tfield.SizeVal = sfield->SizeVal;
		tfield.QueueVal = sfield->QueueVal;
		tfield.Svc_t = sfield->Svc_t;
		tfield.Busy = sfield->Busy;

		if (isPartSearch)
		{
			if (partname.compare(tfield.PartName.getValue()) == 0)
			{
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
				pSession->SendRequestPackage(&m_pkgSend);
			}
		}
		else
		{
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		sfield = pMemoryDB->m_SysMdbDiskIOFactory->findNextByHostName();

#ifdef CPUMEMNETLIMET
		if (++g_OrderQryCount > MAXQRYRETURNNUM)
		{
			pMemoryDB->m_SysMdbDiskIOFactory->endFindByHostName();
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryDiskIOTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());

			CFTDRspInfoField rspInfoField;
			memset(&rspInfoField, 0, sizeof(rspInfoField));
			rspInfoField.ErrorID = ERR_REACHMAXRECORDNUM;
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
			pSession->SendRequestPackage(&m_pkgSend);
			return;
		}

#endif
	}

	pMemoryDB->m_SysMdbDiskIOFactory->endFindByHostName();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryDiskIOTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryStatInfoTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	int g_OrderQryCount = 1;

	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryStatInfoField qryfield;
	FTDC_GET_SINGLE_FIELD(pPackage, &qryfield);

	// 历史结果查询，转给sysquery
	if (qryfield.StartDate < NowDate)
	{
		if (m_pQueryAgent->GetQuerySession())
		{
			CFTDReqQryTopProcessInfoField field;
		    CopyReqQryTopProcessInfoEntity(&field, &qryfield);
			
			SendReqPackageOnAgentSession(field, m_pQueryAgent->GetQuerySession()
				, FTD_TID_ReqQryStatInfoTopic, false);
		}
		else
		{
			OnSessionResponse(FTD_TID_RspQryStatInfoTopic
				, ERR_QRYACCWRONG, "QueryConnectError");
		}
	}
	else if (qryfield.EndDate < NowDate)
	{
		//全是历史日期
		return;
	}

	int HostName = g_StringIdMap.getStringId(qryfield.HostName.getValue());

	CSysMdbStatInfo *sfield = pMemoryDB->m_SysMdbStatInfoFactory->
		startFindByHostName(HostName, qryfield.StartDate, qryfield.StartTime);
	while (sfield)
	{
		if ((sfield->MonDate) > (qryfield.EndDate)
		||	(
				(sfield->MonDate) == (qryfield.EndDate) && (sfield->MonTime) >
				(qryfield.EndTime)
	))
		{
			break;
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryStatInfoTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryStatInfoField tfield;

		tfield.HostName = g_StringIdMap.getString(HostName);
		tfield.MonTime = sfield->MonTime;
		tfield.MonDate = sfield->MonDate;
		tfield.ProcRun = sfield->ProcRun;
		tfield.ProcBlk = sfield->ProcBlk;
		tfield.SwapIn = sfield->SwapIn;
		tfield.SwapOut = sfield->SwapOut;
		tfield.BlockIn = sfield->BlockIn;
		tfield.BlockOut = sfield->BlockOut;
		tfield.Inter = sfield->Inter;
		tfield.Context = sfield->Context;
		tfield.CPUUser = sfield->CPUUser;
		tfield.CPUSys = sfield->CPUSys;
		tfield.CPUIdle = sfield->CPUIdle;
		tfield.CPUIOWait = sfield->CPUIOWait;
		tfield.CPUSteal = sfield->CPUSteal;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);

		sfield = pMemoryDB->m_SysMdbStatInfoFactory->findNextByHostName();

#ifdef CPUMEMNETLIMET
		if (++g_OrderQryCount > MAXQRYRETURNNUM)
		{
			pMemoryDB->m_SysMdbStatInfoFactory->endFindByHostName();
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryStatInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());

			CFTDRspInfoField rspInfoField;
			memset(&rspInfoField, 0, sizeof(rspInfoField));
			rspInfoField.ErrorID = ERR_REACHMAXRECORDNUM;
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
			pSession->SendRequestPackage(&m_pkgSend);
			return;
		}

#endif
	}

	pMemoryDB->m_SysMdbStatInfoFactory->endFindByHostName();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryStatInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryRouterInfoTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	int g_OrderQryCount = 1;

	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryRouterInfoField qryfield;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield);

	// 历史结果查询，转给sysquery
	if (qryfield.StartDate < NowDate)
	{
		if (m_pQueryAgent->GetQuerySession())
		{
			CFTDReqQryTopProcessInfoField field;
		    CopyReqQryTopProcessInfoEntity(&field, &qryfield);
			
			SendReqPackageOnAgentSession(field, m_pQueryAgent->GetQuerySession()
				, FTD_TID_ReqQryRouterInfoTopic, false);
		}
		else
		{
			OnSessionResponse(FTD_TID_RspQryRouterInfoTopic
				, ERR_QRYACCWRONG, "QueryConnectError");
		}
	}
	else if (qryfield.EndDate < NowDate)
	{
		//全是历史日期
		return;
	}

	int HostName = g_StringIdMap.getStringId(qryfield.HostName.getValue());
	CSysMdbRouterInfo *sfield = pMemoryDB->m_SysMdbRouterInfoFactory->
		startFindByHostName(HostName, qryfield.StartDate, qryfield.StartTime);
	while (sfield)
	{
		if ((sfield->MonDate) > (qryfield.EndDate)
		||	(
				(sfield->MonDate) == (qryfield.EndDate) && (sfield->MonTime) >
				(qryfield.EndTime)
	))
		{
			break;
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryRouterInfoTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

		CFTDRspQryRouterInfoField tfield;

		tfield.HostName = g_StringIdMap.getString(sfield->SubcriberID);
		tfield.MonTime = sfield->MonTime;
		tfield.MonDate = sfield->MonDate;
		tfield.Dev = sfield->Dev;
		tfield.Destination = sfield->Destination;
		tfield.Gateway = sfield->Gateway;
		tfield.Mask = sfield->Mask;
		tfield.Flag = sfield->Flag;
		tfield.RefCnt = sfield->RefCnt;
		tfield.Use = sfield->Use;
		tfield.Metric = sfield->Metric;
		tfield.Mtu = sfield->Mtu;
		tfield.Win = sfield->Win;
		tfield.Rtt = sfield->Rtt;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
		sfield = pMemoryDB->m_SysMdbRouterInfoFactory->findNextByHostName();

#ifdef CPUMEMNETLIMET
		if (++g_OrderQryCount > MAXQRYRETURNNUM)
		{
			pMemoryDB->m_SysMdbRouterInfoFactory->endFindByHostName();
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryRouterInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());

			CFTDRspInfoField rspInfoField;
			memset(&rspInfoField, 0, sizeof(rspInfoField));
			rspInfoField.ErrorID = ERR_REACHMAXRECORDNUM;
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
			pSession->SendRequestPackage(&m_pkgSend);
			return;
		}

#endif
	}

	pMemoryDB->m_SysMdbRouterInfoFactory->endFindByHostName();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryRouterInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryMonitorObjectTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
#if 1
	CFTDReqQryMonitorObjectField ftdQryField;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &ftdQryField) <= 0)
	{
		return;
	}

	m_pkgSend.PrepareResponse(
			pPackage,
			FTD_TID_RspQryMonitorObjectTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRspQryMonitorObjectField ftdRspQryField;

	map<string, CObjectIdStatus>::iterator	mapIt;
	map<string, CObjectIdStatus> &appIdNameMap = g_pDataCenterManage->
		getAppIdNameMap();
	for (mapIt = appIdNameMap.begin(); mapIt != appIdNameMap.end(); mapIt++)
	{
		ftdRspQryField.ObjectID = mapIt->second.m_sObjectId.c_str();
		ftdRspQryField.ObjectName = mapIt->second.m_sObjectName.c_str();
		ftdRspQryField.WarningActive = mapIt->second.m_iEventFlag;
#ifdef PRINT_DEBUG
		printf("%-40s --- %s\n", mapIt->first.c_str(), mapIt->second.c_str());
#endif
		CHECKRSPPKG(MonitorObject)
	}

	pSession->SendRequestPackage(&m_pkgSend);
#endif
}

void CFrontServer::OnReqQryObjectRationalTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
#if 1
	CFTDReqQryObjectRationalField ftdQryField;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &ftdQryField) <= 0)
	{
		return;
	}

	m_pkgSend.PrepareResponse(
			pPackage,
			FTD_TID_RspQryObjectRationalTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRspQryObjectRationalField ftdRspQryField;
	map<string, string>::iterator mapIt;
	map<string, string> &appIdHostMap = g_pDataCenterManage->getAppIdHostMap();
	for (mapIt = appIdHostMap.begin(); mapIt != appIdHostMap.end(); mapIt++)
	{
		ftdRspQryField.ObjectID = mapIt->first.c_str();
		ftdRspQryField.HostObjectID = mapIt->second.c_str();

		//		CHECKPKG(ObjectRational)
		{
			if (m_pkgSend.Length() +
				sizeof(ftdRspQryField) > FTDC_PACKAGE_MAX_SIZE)
			{
				m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
				((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
				m_pkgSend.PrepareResponse(
						pPackage,
						FTD_TID_RspQryObjectRationalTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &ftdRspQryField);
			}
			else
			{
				FTDC_ADD_FIELD(&m_pkgSend, &ftdRspQryField);
			}
		}
	}

	pSession->SendRequestPackage(&m_pkgSend);
#endif
}

void CFrontServer::OnReqQryHostEnvTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryHostEnvField	ftdQryField;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &ftdQryField) <= 0)
	{
		return;
	}

	{
		m_pkgSend.PrepareResponse(
				pPackage,
				FTD_TID_RspQryHostEnvTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);

		CRspQryHostEnvCommon *pfieldCommon = pMemoryDB->
			m_RspQryHostEnvCommonFactory->startFindByHostName(
					ftdQryField.HostName);
		CTimeType TimeCommon;
		if (pfieldCommon)
		{
			TimeCommon = pfieldCommon->MonTime;
		}

		while (pfieldCommon)
		{
			if (pfieldCommon->MonTime != TimeCommon)
			{
				break;
			}

			CFTDRspQryHostEnvCommonField field;
			CopyRspQryHostEnvCommonEntity(&field, pfieldCommon);
			FTDC_ADD_FIELD(&m_pkgSend, &field);
			pfieldCommon = pMemoryDB->m_RspQryHostEnvCommonFactory->findNextByHostName();
		}

		pMemoryDB->m_RspQryHostEnvCommonFactory->endFindByHostName();
		pSession->SendRequestPackage(&m_pkgSend);
	}

	//	RSPQRYENV(Common);
	RSPQRYENV(Lan);
	RSPQRYENV(Storage);
	RSPQRYENV(IO);
	RSPQRYENV(FS);
	RSPQRYENV(Swap);
	RSPQRYENV(LanCfg);

	m_pkgSend.PreparePackage(
			FTD_TID_RspQryHostEnvTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQrySubcriberTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQrySubscriberField ftdQryField;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &ftdQryField) <= 0)
	{
		return;
	}

	printf(
		"\t\t ObjectID:==%s== KeepAlive==%d==\n",
		(const char *)ftdQryField.ObjectID,
		(const int)ftdQryField.KeepAlive);
	if (ftdQryField.KeepAlive)
	{
		g_pListSessionArray->AddSubcriberObject(
				pSession,
				(char *)ftdQryField.ObjectID.getValue());
	}
	else
	{
		g_pListSessionArray->DelSubcriberObject(
				pSession,
				(char *)ftdQryField.ObjectID.getValue());
		return;
	}

	int objectid = g_StringIdMap.getStringId(ftdQryField.ObjectID.getValue());
	map<int, int>::iterator it = g_SubcriberMap.find(objectid);

	if (it == g_SubcriberMap.end())
	{
		return;
	}
	else
	{
		switch (it->second)
		{
			case 1:
				{
					//				RTNSUBCRIBER(ObjectAttr);
					{
						list<CFTDRtnObjectAttrField> lFtd;
						list<CFTDRtnObjectAttrField>::iterator	it;
						int icount = 0;
						if (ftdQryField.ObjectNum < 0)
						{
							CSysMdbObjectAttr *sfield = pMemoryDB->
								m_SysMdbObjectAttrFactory->startFindByDsc(objectid);
							while (sfield)
							{
								{
									if (sfield->MonDate < ftdQryField.MonDate
									||	(
											sfield->MonDate == ftdQryField.MonDate
									&&	sfield->MonTime < ftdQryField.
											MonTime
								))
									{
										break;
									}
								}

								m_pkgSend.SetRequestId(pPackage->GetRequestId());

								CFTDRtnObjectAttrField	tfield;
								CopyTSysObjectAttrEntity(&tfield, sfield);
								lFtd.push_front(tfield);
								sfield = pMemoryDB->m_SysMdbObjectAttrFactory->findNextByDsc();
							}

							pMemoryDB->m_SysMdbObjectAttrFactory->endFindByDsc();
							for (it = lFtd.begin(); it != lFtd.end(); it++)
							{
								m_pkgSend.PreparePackage(
										FTD_TID_RtnObjectAttrTopic,
										FTDC_CHAIN_CONTINUE,
										FTD_VERSION);
								FTDC_ADD_FIELD(&m_pkgSend, &(*it));
								pSession->SendRequestPackage(&m_pkgSend);
							}
						}
						else if (ftdQryField.ObjectNum == 0)
						{
							return;
						}
						else
						{
							CSysMdbObjectAttr *sfield = pMemoryDB->
								m_SysMdbObjectAttrFactory->startFindByDsc(objectid);
							while (sfield)
							{
								if (icount >= ftdQryField.ObjectNum)
								{
									break;
								}

								m_pkgSend.SetRequestId(pPackage->GetRequestId());

								CFTDRtnObjectAttrField	tfield;
								CopyTSysObjectAttrEntity(&tfield, sfield);
								lFtd.push_front(tfield);
								sfield = pMemoryDB->m_SysMdbObjectAttrFactory->findNextByDsc();
								icount++;
							}

							pMemoryDB->m_SysMdbObjectAttrFactory->endFindByDsc();
							for (it = lFtd.begin(); it != lFtd.end(); it++)
							{
								m_pkgSend.PreparePackage(
										FTD_TID_RtnObjectAttrTopic,
										FTDC_CHAIN_CONTINUE,
										FTD_VERSION);
								FTDC_ADD_FIELD(&m_pkgSend, &(*it));
								pSession->SendRequestPackage(&m_pkgSend);
							}
						}
					}
				}

				break;
			case 2:
				{
					RTNSUBCRIBER(TopCpuInfo);
				}

				break;
			case 3:
				{
					RTNSUBCRIBER(TopMemInfo);
				}

				break;
			case 4:
				{
					RTNSUBCRIBER(TopProcessInfo);
				}

				break;
			case 5:
				{
					RTNSUBCRIBER(FileSystemInfo);
				}

				break;
			case 6:
				{
					RTNSUBCRIBER(NetworkInfo);
				}

				break;
			case 7:
				{
					RTNSUBCRIBER(WebAppInfo);
				}

				break;
			case 8:
				{
					RTNSUBCRIBER(MemPoolInfo);
				}

				break;
			case 9:
				{
					RTNSUBCRIBER(ConnectorInfo);
				}

				break;
			case 10:
				{
					RTNSUBCRIBER(DBQuery);
				}

				break;
			case 11:
				{
					RTNSUBCRIBER(DiskIO);
				}

				break;
			case 12:
				{
					RTNSUBCRIBER(RouterInfo);
				}

				break;
			case 13:
				{
					RTNSUBCRIBER(StatInfo);
				}

				break;
			case 14:
				{
					list<CFTDRtnTradeFrontOrderRttStatField> lFtd;
					list<CFTDRtnTradeFrontOrderRttStatField>::iterator	it;
					int icount = 0;
					if (ftdQryField.ObjectNum < 0)
					{
						CSysMdbTradeFrontOrderRttStat *sfield = pMemoryDB->
							m_SysMdbTradeFrontOrderRttStatFactory->startFindByDsc(
									objectid);
						while (sfield)
						{
							m_pkgSend.SetRequestId(pPackage->GetRequestId());

							CFTDRtnTradeFrontOrderRttStatField	tfield;
							CopyTSysTradeFrontOrderRttStatEntity(&tfield, sfield);
							lFtd.push_front(tfield);
							sfield = pMemoryDB->m_SysMdbTradeFrontOrderRttStatFactory->findNextByDsc();
						}

						pMemoryDB->m_SysMdbTradeFrontOrderRttStatFactory->endFindByDsc();
						for (it = lFtd.begin(); it != lFtd.end(); it++)
						{
							m_pkgSend.PreparePackage(
									FTD_TID_RtnTradeFrontOrderRttStatTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
							FTDC_ADD_FIELD(&m_pkgSend, &(*it));
							pSession->SendRequestPackage(&m_pkgSend);
						}
					}
					else if (ftdQryField.ObjectNum == 0)
					{
						return;
					}
					else
					{
						CSysMdbTradeFrontOrderRttStat *sfield = pMemoryDB->
							m_SysMdbTradeFrontOrderRttStatFactory->startFindByDsc(
									objectid);
						while (sfield)
						{
							if (icount >= ftdQryField.ObjectNum)
							{
								break;
							}

							m_pkgSend.SetRequestId(pPackage->GetRequestId());

							CFTDRtnTradeFrontOrderRttStatField	tfield;
							CopyTSysTradeFrontOrderRttStatEntity(&tfield, sfield);
							lFtd.push_front(tfield);
							sfield = pMemoryDB->m_SysMdbTradeFrontOrderRttStatFactory->findNextByDsc();
							icount++;
						}

						pMemoryDB->m_SysMdbTradeFrontOrderRttStatFactory->endFindByDsc();
						for (it = lFtd.begin(); it != lFtd.end(); it++)
						{
							m_pkgSend.PreparePackage(
									FTD_TID_RtnTradeFrontOrderRttStatTopic,
									FTDC_CHAIN_CONTINUE,
									FTD_VERSION);
							FTDC_ADD_FIELD(&m_pkgSend, &(*it));
							pSession->SendRequestPackage(&m_pkgSend);
						}
					}
				}

				break;

			/*		case 15:
			{
				list<CFTDRtnNetPartyLinkStatusInfoField> lFtd;
				list<CFTDRtnNetPartyLinkStatusInfoField>::iterator it;
				int icount =0;
				if(ftdQryField.ObjectNum <0)
				{
					CSysNetPartyLinkStatusInfo *sfield =pMemoryDB->m_SysNetPartyLinkStatusInfoFactory->startFindBytheAll();
					while(sfield)
					{
						m_pkgSend.SetRequestId(pPackage->GetRequestId());
						CFTDRtnNetPartyLinkStatusInfoField tfield;
						CopySysNetPartyLinkStatusInfoEntity(&tfield ,sfield);
						lFtd.push_front(tfield);
						sfield =pMemoryDB->m_SysNetPartyLinkStatusInfoFactory->findNextBytheAll();
					}
					
					pMemoryDB->m_SysNetPartyLinkStatusInfoFactory->endFindBytheAll();
					for(it =lFtd.begin(); it !=lFtd.end(); it++)
					{
						m_pkgSend.PreparePackage(FTD_TID_RtnNetPartyLinkStatusInfoTopic, FTDC_CHAIN_CONTINUE, FTD_VERSION);
						FTDC_ADD_FIELD(&m_pkgSend, &(*it));
						pSession->SendRequestPackage(&m_pkgSend);
					}
				}
				else if(ftdQryField.ObjectNum ==0)
				{
					return;
				}
				else
				{
					CSysNetPartyLinkStatusInfo *sfield =pMemoryDB->m_SysNetPartyLinkStatusInfoFactory->startFindBytheAll();
					while(sfield)
					{
						if(icount >=ftdQryField.ObjectNum)
							break;
					
						m_pkgSend.SetRequestId(pPackage->GetRequestId());
						CFTDRtnNetPartyLinkStatusInfoField tfield;
						CopySysNetPartyLinkStatusInfoEntity(&tfield ,sfield);
						lFtd.push_front(tfield);
						sfield =pMemoryDB->m_SysNetPartyLinkStatusInfoFactory->findNextBytheAll();
						icount++;
					}
					
					pMemoryDB->m_SysNetPartyLinkStatusInfoFactory->endFindBytheAll();
					for(it =lFtd.begin(); it !=lFtd.end(); it++)
					{
						m_pkgSend.PreparePackage(FTD_TID_RtnNetPartyLinkStatusInfoTopic, FTDC_CHAIN_CONTINUE, FTD_VERSION);
						FTDC_ADD_FIELD(&m_pkgSend, &(*it));
						pSession->SendRequestPackage(&m_pkgSend);
					}
				}
			}
			break;	
*/
			case 16:
				{
					map<string, CFTDRtnParticTradeOrderStatesField>::iterator
						m_Iter;
					for (m_Iter = g_mapRtnPartiOrder.begin();
						 m_Iter != g_mapRtnPartiOrder.end();
						 m_Iter++)
					{
						m_pkgSend.PreparePackage(
								FTD_TID_RtnParticTradeOrderStatesTopic,
								FTDC_CHAIN_CONTINUE,
								FTD_VERSION);
						m_pkgSend.SetRequestId(pPackage->GetRequestId());

						CFTDRtnParticTradeOrderStatesField	&rtnLatstofUser =
							m_Iter->second;

						FTDC_ADD_FIELD(&m_pkgSend, &rtnLatstofUser);
						pSession->SendRequestPackage(&m_pkgSend);
					}
				}

				/*{
					CSysParticTradeOrderStates *pfield =pMemoryDB->m_SysParticTradeOrderStatesFactory->startFindByAll();
					while(pfield)
					{
						m_pkgSend.PreparePackage(FTD_TID_RtnParticTradeOrderStatesTopic, FTDC_CHAIN_CONTINUE, FTD_VERSION);
						m_pkgSend.SetRequestId(pPackage->GetRequestId());
						CFTDRtnParticTradeOrderStatesField field;
						CopySysParticTradeOrderStatesEntity(&field,pfield);
						FTDC_ADD_FIELD(&m_pkgSend, &field);
						pSession->SendRequestPackage(&m_pkgSend);
						pfield =pMemoryDB->m_SysParticTradeOrderStatesFactory->findNextByAll();
					}
					pMemoryDB->m_SysParticTradeOrderStatesFactory->endFindByAll();
				}
				*/
				break;
			default:
				break;
		}
	}
}

//内存数据库更改标注一：
void CFrontServer::OnReqQryObjectAttrTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryObjectAttrField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	if ((strcmp(qryfield.StartTime.getValue(), "") == 0)
	||	(strcmp(qryfield.EndTime.getValue(), "") == 0))
	{
		qryfield.StartTime = "00:00:00";
		qryfield.EndTime = "zzzzzzzz";
	}

	int objectid = 0;

	//	int attrtype =0;
	list<CFTDRspQryObjectAttrField> lFtd;

	//	g_StringIdMap.getStringSubIdRFromDot(objectid,attrtype,qryfield.ObjectID.getValue());
	string	str = qryfield.ObjectID.getValue();
	str += ".";
	str += qryfield.AttrType.getValue();
	objectid = g_StringIdMap.getStringId(str.data());

	CSysMdbObjectAttr *sfield = pMemoryDB->m_SysMdbObjectAttrFactory->
		startFindByIDType(objectid, qryfield.EndDate, qryfield.EndTime);
	while (sfield)
	{
		if ((sfield->MonDate) < (qryfield.StartDate)
		||	(
				(sfield->MonDate) == (qryfield.StartDate)
		&&	(sfield->MonTime) < (qryfield.StartTime)
		))
		{
			break;
		}

		CFTDRspQryObjectAttrField tfield;

		tfield.ObjectID = g_StringIdMap.getString(sfield->ObjectID);
		tfield.AttrType = g_StringIdMap.getString(sfield->AttrType);
		tfield.AttrValue = sfield->AttrValue;
		tfield.MonTime = sfield->MonTime;
		tfield.MonDate = sfield->MonDate;
		tfield.ValueType = sfield->ValueType;

		lFtd.push_front(tfield);

		sfield = pMemoryDB->m_SysMdbObjectAttrFactory->findNextByIDType();
	}

	pMemoryDB->m_SysMdbObjectAttrFactory->endFindByIDType();

	list<CFTDRspQryObjectAttrField>::iterator it;
	for (it = lFtd.begin(); it != lFtd.end(); it++)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryObjectAttrTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());
		FTDC_ADD_FIELD(&m_pkgSend, &(*it));
		pSession->SendRequestPackage(&m_pkgSend);
	}

	m_pkgSend.PreparePackage(
			FTD_TID_RspQryObjectAttrTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQrySyslogInfoTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQrySyslogInfoField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	int objectid = 0;
	int attrtype = 0;

	/*
	string scr =qryfield.FileName.getValue();
	string sub =HOSTATTRSYSLOG;
	int pos =scr.find(sub);
	if(pos == string::npos)
	{ 
		sub =HOSTATTRKEYFILE; 
		pos =scr.find(sub);
		if(pos == string::npos)
			return;
	}
	string str1 =scr.substr(0 ,pos-sub.size());
	string str2 =scr.substr(pos -sub.size() +1 ,scr.size());
*/
	objectid = g_StringIdMap.getStringId(qryfield.FileName.getValue());
	attrtype = g_StringIdMap.getStringId(qryfield.subFileName.getValue());

	CSysMdbSyslogInfo *sfield = pMemoryDB->m_SysMdbSyslogInfoFactory->
		startFindByAll(objectid, attrtype);
	while (sfield)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQrySyslogInfoTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQrySyslogInfoField tfield;

		tfield.ObjectID = g_StringIdMap.getString(sfield->ObjectID);
		tfield.AttrType = g_StringIdMap.getString(sfield->AttrType);
		tfield.MonDate = sfield->MonDate;
		tfield.MonTime = sfield->MonTime;
		tfield.ContLen = sfield->ContLen;
		tfield.FileContent = sfield->FileContent;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
		sfield = pMemoryDB->m_SysMdbSyslogInfoFactory->findNextByAll();
	}

	pMemoryDB->m_SysMdbSyslogInfoFactory->endFindByAll();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQrySyslogInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryUserInfoTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryUserInfoField qryfield;
	FTDC_GET_SINGLE_FIELD(pPackage, &qryfield);

	CSysUserInfo *sfield = pMemoryDB->m_SysUserInfoFactory->startFindByHostName(
			qryfield.ObjectID,
			qryfield.StartTime);
	while (sfield)
	{
		if ((sfield->MonTime) > (qryfield.EndTime))
		{
			break;
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryUserInfoTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryUserInfoField tfield;

		CopySysUserInfoEntity(&tfield, sfield);

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
		sfield = pMemoryDB->m_SysUserInfoFactory->findNextByHostName();
	}

	pMemoryDB->m_SysUserInfoFactory->endFindByHostName();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryUserInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryOnlineUserInfoTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryOnlineUserInfoField qryfield;
	FTDC_GET_SINGLE_FIELD(pPackage, &qryfield);

	CSysOnlineUserInfo	*sfield = pMemoryDB->m_SysOnlineUserInfoFactory->
		startFindByHostName(qryfield.ObjectID, qryfield.StartTime);
	while (sfield)
	{
		if ((sfield->MonTime) > (qryfield.EndTime))
		{
			break;
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryOnlineUserInfoTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryOnlineUserInfoField tfield;

		CopySysOnlineUserInfoEntity(&tfield, sfield);

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
		sfield = pMemoryDB->m_SysOnlineUserInfoFactory->findNextByHostName();
	}

	pMemoryDB->m_SysOnlineUserInfoFactory->endFindByHostName();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryOnlineUserInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryWarningEventTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryWarningEventField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	CDateType theDate;
	time_t	timep;
	time(&timep);

	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	sprintf(
		(char *)(theDate.getValue()),
		"%d%02d%02d",
		tm_time.tm_year + 1900,
		tm_time.tm_mon + 1,
		tm_time.tm_mday);

	if (strcmp(qryfield.StartDate.getValue(), theDate.getValue()) < 0)
	{
		CFTDReqQryWarningEventField field;
		CopyReqQryWarningEventEntity(&field, &qryfield);
		m_pkgSend.PreparePackage(
				FTD_TID_ReqQryWarningEventTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &field);
		m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());

#ifdef PACKAGE_OUTPUT
		m_pkgSend.OutputHeader(g_pFwdPackOutput);
		FTDC_DEBUG_BODY(m_pkgSend.GetTID(), &m_pkgSend, g_pFwdPackOutput);
#endif
		if (m_pQueryAgent->GetQuerySession())
		{
			m_pQueryAgent->GetQuerySession()->SendRequestPackage(&m_pkgSend);
		}
		else
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryWarningEventTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());

			CFTDRspInfoField rspInfoField;
			memset(&rspInfoField, 0, sizeof(rspInfoField));
			rspInfoField.ErrorID = ERR_QRYACCWRONG;
			rspInfoField.ErrorMsg = "QueryConnectError";
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
			pSession->SendRequestPackage(&m_pkgSend);
		}
	}
	else if (strcmp(qryfield.StartDate.getValue(), theDate.getValue()) > 0)
	{
		return;
	}
	else
	{
		list<CFTDRspQryWarningEventField> theList;
		CSysWarningEvent *sfield = pMemoryDB->m_SysWarningEventFactory->
			startFindByTime(theDate, qryfield.EndTime);
		while (sfield)
		{
			if ((sfield->OccurTime) < (qryfield.StartTime))
			{
				break;
			}
			if (sfield->MonDate < qryfield.StartDate)
			{
				sfield = pMemoryDB->m_SysWarningEventFactory->findNextByTime();
				continue;
			}

			///以下三项为空的情况下，默认为不包括"info"的全集
						///告警级别要排除"info"集合
			if (qryfield.WarningLevel != "")
			{
				if (qryfield.WarningLevel != sfield->WarningLevel.getValue())
				{
					sfield = pMemoryDB->m_SysWarningEventFactory->findNextByTime();
					continue;
				}
			}

			/*
			else
			{
				if(sfield->WarningLevel !="notify" && sfield->WarningLevel !="warning" && sfield->WarningLevel !="error" && sfield->WarningLevel !="fatal")
				{
					sfield =pMemoryDB->m_SysWarningEventFactory->findNextByTime();
					continue;
				}
			}
*/
			if (qryfield.EventName != "")
			{
				if (qryfield.EventName != sfield->EventName.getValue())
				{
					sfield = pMemoryDB->m_SysWarningEventFactory->findNextByTime();
					continue;
				}
			}

			if (qryfield.ObjectID != "")
			{
				if (qryfield.ObjectID != sfield->ObjectID.getValue())
				{
					sfield = pMemoryDB->m_SysWarningEventFactory->findNextByTime();
					continue;
				}
			}

			CFTDRspQryWarningEventField tfield;
			CopySysWarningEventEntity(&tfield, sfield);
			theList.push_front(tfield);
			sfield = pMemoryDB->m_SysWarningEventFactory->findNextByTime();
		}

		pMemoryDB->m_SysWarningEventFactory->endFindByTime();
		if (pSession)
		{
			list<CFTDRspQryWarningEventField>::iterator it = theList.begin();
			for (; it != theList.end(); it++)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryWarningEventTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
				m_pkgSend.SetRequestId(pPackage->GetRequestId());
				FTDC_ADD_FIELD(&m_pkgSend, &(*it));
				pSession->SendRequestPackage(&m_pkgSend);
			}
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryWarningEventTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspInfoField rspInfoField;
		memset(&rspInfoField, 0, sizeof(rspInfoField));
		rspInfoField.ErrorID = 0;
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CFrontServer::OnReqQryHistoryObjectAttrTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryHistoryObjectAttrField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	CDateType theDate;
	time_t	timep;
	time(&timep);

	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	sprintf(
		(char *)(theDate.getValue()),
		"%d%02d%02d",
		tm_time.tm_year + 1900,
		tm_time.tm_mon + 1,
		tm_time.tm_mday);

	if (strcmp(qryfield.StartDate.getValue(), theDate.getValue()) < 0)
	{
		if (m_pQueryAgent->GetQuerySession())
		{
			CFTDReqQryHistoryObjectAttrField field;
		    CopyReqQryHistoryObjectAttrEntity(&field, &qryfield);
			
			SendReqPackageOnAgentSession(field, m_pQueryAgent->GetQuerySession()
				, FTD_TID_ReqQryHistoryObjectAttrTopic, true);
		}
		else
		{
			OnSessionResponse(FTD_TID_RspQryHistoryObjectAttrTopic
				, ERR_QRYACCWRONG, "QueryConnectError");
		}
	}
	else
	{
		OnSessionResponse(FTD_TID_RspQryHistoryObjectAttrTopic
				, 0, "wrongday");
	}
}

void CFrontServer::OnReqQryFrontInfoTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryFrontInfoField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	if (m_pSlogAgent->GetSlogSession())
	{
		CFTDReqQryFrontInfoField field;
	    CopyReqQryFrontInfoEntity(&field, &qryfield);
			
		SendReqPackageOnAgentSession(field, m_pSlogAgent->GetSlogSession()
			, FTD_TID_ReqQryFrontInfoTopic, true);
	}
	else
	{
		OnSessionResponse(FTD_TID_RspQryFrontInfoTopic
			, ERR_QRYACCWRONG, "SLogError");
	}
}

void CFrontServer::OnReqQryTradeLogTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryTradeLogField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}
	if (m_pSlogAgent->GetSlogSession())
	{		
		
		CFTDReqQryTradeLogField field;
		CopyReqQryTradeLogEntity(&field, &qryfield); 
		SendReqPackageOnAgentSession(field, m_pSlogAgent->GetSlogSession(), FTD_TID_ReqQryTradeLogTopic, false);
	}
	else
	{
		OnSessionResponse(FTD_TID_RspQryTradeLogTopic, ERR_QRYACCWRONG, "SlogConnectError");
	}
}

void CFrontServer::OnReqQryParticipantInitTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryParticipantInitField	qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	CSysParticipantInit *sfield = pMemoryDB->m_SysParticipantInitFactory->
		startFindByAll();
	while (sfield)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryParticipantInitTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryParticipantInitField	tfield;

		CopySysParticipantInitEntity(&tfield, sfield);

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
		sfield = pMemoryDB->m_SysParticipantInitFactory->findNextByAll();
	}

	pMemoryDB->m_SysParticipantInitFactory->endFindByAll();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryParticipantInitTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryUserInitTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryUserInitField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	CSysUserInit *sfield = pMemoryDB->m_SysUserInitFactory->startFindByAll();
	while (sfield)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryUserInitTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryUserInitField tfield;

		CopySysUserInitEntity(&tfield, sfield);

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
		sfield = pMemoryDB->m_SysUserInitFactory->findNextByAll();
	}

	pMemoryDB->m_SysUserInitFactory->endFindByAll();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryUserInitTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryTradeUserLoginInfoTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryTradeUserLoginInfoField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	CSysTradeUserLoginInfo	*sfield = pMemoryDB->
		m_SysTradeUserLoginInfoFactory->startFindByAll();
	while (sfield)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryTradeUserLoginInfoTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryTradeUserLoginInfoField tfield;

		CopySysTradeUserLoginInfoEntity(&tfield, sfield);

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
		sfield = pMemoryDB->m_SysTradeUserLoginInfoFactory->findNextByAll();
	}

	pMemoryDB->m_SysTradeUserLoginInfoFactory->endFindByAll();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryTradeUserLoginInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnPartTradeTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryPartTradeField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	CSysPartTrade *sfield = pMemoryDB->m_SysPartTradeFactory->startFindByAll();
	while (sfield)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryPartTradeTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryPartTradeField tfield;

		CopySysPartTradeEntity(&tfield, sfield);

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
		sfield = pMemoryDB->m_SysPartTradeFactory->findNextByAll();
	}

	pMemoryDB->m_SysPartTradeFactory->endFindByAll();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryPartTradeTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryPerformanceTopTopic( 
	CFTDCPackage *pPackage, 
	CFTDCSession *pSession )
{
	CFTDReqQryPerformanceTopField QryField;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &QryField) <= 0)
		return;

	int nOperationType = QryField.OperationType.getValue();

	switch (nOperationType)
	{
	case PA_HISTORY:	// 查询历史性能，则向Query请求
		{
			if (m_pQueryAgent->GetQuerySession())
			{
				CFTDReqQryPerformanceTopField field;
			    CopySysPerformanceTopEntity(&field, &QryField);
			
				SendReqPackageOnAgentSession(field, m_pQueryAgent->GetQuerySession()
					, FTD_TID_ReqQryPerformanceTopTopic, false);
			}
			else
			{
				OnSessionResponse(FTD_TID_RspQryPerformanceTopTopic
					, ERR_QRYACCWRONG, "QueryConnectError");
			}
			break;
		}
	case PA_ADD_REALTIME_SUB:	// 查询实时性能，在Front本地处理
		{
			if (g_pPerformanceAnalyzer)
			{
				// 查询实时信息，增加一个订阅
				if (!g_pPerformanceAnalyzer->AddSubscription(QryField, pSession))
				{				
					// 订阅错误，订阅设备为空
					OnSessionResponse(FTD_TID_RspQryPerformanceTopTopic
						, ERR_QRYACCWRONG, "Performance Analyze subscription is null.");
				}
			}
			else
			{
				// 性能分析未启用
				OnSessionResponse(FTD_TID_RspQryPerformanceTopTopic
						, ERR_QRYACCWRONG, "Performance Analyze is not enabled.");
			}
			break;
		}
	case PA_DEL_REALTIME_SUB:	// 取消一个订阅信息
		{
			if (g_pPerformanceAnalyzer)
			{
				g_pPerformanceAnalyzer->DelSubscription(QryField, pSession);
			}
			break;
		}
	default:
		// 未定义的操作类型
		OnSessionResponse(FTD_TID_RspQryPerformanceTopTopic
						, ERR_QRYACCWRONG, "Unknown Operation Type.");
	}

}