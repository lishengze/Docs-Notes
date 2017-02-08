/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CounterConnector.cpp
///@brief	实现了连接事件计算服务器并处理该服务器通信消息的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#include "CountConnector.h"
#include "CStatusSubscriber.h"
#include "CListSession.h"
#include "CQueryAgent.h"
#include <iostream>
using namespace std;

extern CStatusSubscriber *g_pStatusSubcriber[MAX_EVENTFLOWNUM];
extern CListSessionArray *g_pListSessionArray;
CFTDCSession *g_CountConnector = NULL;
extern int	g_FrontRange;
extern list<CFTDCSession *> g_mListAllSession;

//////////////////////////////////////////////////////////////////////////
//add by feng.q 20130130
extern map<string, CFTDRtnParticTradeOrderStatesField>	g_mapRtnPartiOrder;
extern map<string, CFTDRspQryParticTradeOrderStatesField> g_mpPartiOrderCnt;

//////////////////////////////////////////////////////////////////////////
//
// 面向计算服务器连接的类实现

//
CCountConnector::CCountConnector(CReactor *pReactor) :
	CAgentSessionFactory(pReactor, 1)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_pCountSession = NULL;
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

	time_t	timep;
	time(&timep);
	printf(
		"\t %s CCountConnector::OnSessionConnected: %0x \n",
		ctime(&timep),
		pSession);
	printf(
		"\tCountConnector::OnSessionConnected: %s\n",
		pSession->GetChannel()->GetRemoteName());
	fflush(stdout);

	m_pkgSend.PreparePackage(
			FTD_TID_ReqUserLogin,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqUserLoginField fieldLogin;
	memset(&fieldLogin, 0, sizeof(fieldLogin));
	fieldLogin.UserID = "front";
	fieldLogin.Password = "frontpd";
	FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);

	CFTDDisseminationField	fieldDissemination;
	for (int i = 0; i < MAX_EVENTFLOWNUM; i++)
	{
		printf(
			"\t Flow %d count %d\n",
			i,
			g_pStatusSubcriber[i]->GetReceivedCount());
		fflush(stdout);
		fieldDissemination.SequenceSeries = g_pStatusSubcriber[i]->GetSequenceSeries(); // GetSequenceSeries();
		fieldDissemination.SequenceNo = g_pStatusSubcriber[i]->GetReceivedCount();

		// GetReceivedCount();
		FTDC_ADD_FIELD(&m_pkgSend, &fieldDissemination);
		((CFTDCSession *)pSession)->RegisterSubscriber(g_pStatusSubcriber[i]);
	}

	((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
	g_CountConnector = (CFTDCSession *)pSession;

	m_pCountSession = (CFTDCSession *)pSession;
}

void CCountConnector::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CCountConnector::OnSessionDisconnected: %0x \n",
		ctime(&timep),
		pSession);
	fflush(stdout);
	g_CountConnector = NULL;

	m_pCountSession = NULL;
}

int CCountConnector::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	printf(
		"\tCCountConnector::HandlePackage:receive package %0x\n",
		pFTDCPackage->GetTID());
#endif

	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_RspUserLogin:
			OnRspUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTradeDayChangeTopic:
			OnReqQryTradeDayChange(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryJDBCInfoTopic:
			QUERYRSP(JDBCInfo);
			break;
		case FTD_TID_RspQryThreadInfoTopic:
			{
				int nRid = pFTDCPackage->GetRequestId();
				map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
				TRID rid = it->second;
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryThreadInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				m_pkgSend.SetChain(pFTDCPackage->GetChain());
				m_pkgSend.SetRequestId(rid.RequestId);

				CFTDRspInfoField rspInfoField;
				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)
				{
					FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
				}

				CFTDRspQryThreadInfoField sfield;
				CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
						&CFTDRspQryThreadInfoField::m_Describe);
				while (!itor.IsEnd())
				{
					itor.Retrieve(&sfield);

					CFTDRspQryThreadInfoField tfield;
					CopyRspQryThreadInfoEntity(&tfield, &sfield);
					FTDC_ADD_FIELD(&m_pkgSend, &tfield);
					itor.Next();
					if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
					{
						break;
					}
				}

				if (m_pFrontServer->GetSession(rid.SessionID))
				{
					((CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)))->SendRequestPackage(&m_pkgSend);
				}

				if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
				{
					m_pFrontServer->m_vRid.erase(it);
				}
			}

			break;
		case FTD_TID_RspQrySessionInfoTopic:
			QUERYRSP(SessionInfo);
			break;
		case FTD_TID_RspQryFileInfoTopic:
			QUERYRSP(FileInfo);
			break;
		case FTD_TID_RspQryServletInfoTopic:
			QUERYRSP(ServletInfo);
			break;
		case FTD_TID_RspQryWebAppInfoTopic:
			QUERYRSP(WebAppInfo);
			break;
		case FTD_TID_RspQryConnectorInfoTopic:
			QUERYRSP(ConnectorInfo);
			break;
		case FTD_TID_RspQryConnectionInfoTopic:
			QUERYRSP(ConnectionInfo);
			break;
		case FTD_TID_RspQryFileContentInfoTopic:
			QUERYRSP(FileContentInfo);
			break;
		case FTD_TID_RspQryVMInfoTopic:
			QUERYRSP(VMInfo);
			break;
		case FTD_TID_RspQryPropertyInfoTopic:
			QUERYRSP(PropertyInfo);
			break;
		case FTD_TID_RspQryMemPoolInfoTopic:
			QUERYRSP(MemPoolInfo);
			break;
		case FTD_TID_RspQryDBQueryTopic:
			QUERYRSP(DBQuery);
			break;
		case FTD_TID_RspQryGetFileTopic:
			{
				int nRid = pFTDCPackage->GetRequestId();
				map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
				TRID rid = it->second;
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryGetFileTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				m_pkgSend.SetChain(pFTDCPackage->GetChain());
				m_pkgSend.SetRequestId(rid.RequestId);

				CFTDRspInfoField rspInfoField;
				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)
				{
					FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
				}

				CFTDRspQryGetFileField	sfield;
				CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
						&CFTDRspQryGetFileField::m_Describe);
				while (!itor.IsEnd())
				{
					itor.Retrieve(&sfield);

					//CopyRspQryGetFileEntity(&tfield ,&sfield);
					FTDC_ADD_FIELD(&m_pkgSend, &sfield);
					itor.Next();
					if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
					{
						break;
					}
				}

				if (m_pFrontServer->GetSession(rid.SessionID))
				{
					((CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)))->SendRequestPackage(&m_pkgSend);
				}

				if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
				{
					m_pFrontServer->m_vRid.erase(it);
				}
			}

			break;
		case FTD_TID_RspQryNetCfgFileTopic:
			{
				int nRid = pFTDCPackage->GetRequestId();
				map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
				TRID rid = it->second;
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryNetCfgFileTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				m_pkgSend.SetChain(pFTDCPackage->GetChain());
				m_pkgSend.SetRequestId(rid.RequestId);

				CFTDRspInfoField rspInfoField;
				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)
				{
					FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
				}

				CFTDRspQryNetCfgFileField sfield;
				CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
						&CFTDRspQryNetCfgFileField::m_Describe);
				while (!itor.IsEnd())
				{
					itor.Retrieve(&sfield);

					CFTDRspQryNetCfgFileField tfield;
					CopyRspQryNetCfgFileEntity(&tfield, &sfield);
					FTDC_ADD_FIELD(&m_pkgSend, &tfield);
					itor.Next();
					if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
					{
						break;
					}
				}

				if (m_pFrontServer->GetSession(rid.SessionID))
				{
					((CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)))->SendRequestPackage(&m_pkgSend);
				}

				if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
				{
					m_pFrontServer->m_vRid.erase(it);
				}
			}

			break;
		case FTD_TID_RspQryGeneralFieldTopic:
			{
				int nRid = pFTDCPackage->GetRequestId();
				map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
				TRID rid = it->second;
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryGeneralFieldTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				m_pkgSend.SetChain(pFTDCPackage->GetChain());
				m_pkgSend.SetRequestId(rid.RequestId);

				CFTDRspInfoField rspInfoField;
				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)
				{
					FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
				}

				CFTDSysGeneralFieldField sfield;
				CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
						&CFTDSysGeneralFieldField::m_Describe);
				while (!itor.IsEnd())
				{
					itor.Retrieve(&sfield);

					CFTDSysGeneralFieldField tfield;
					CopySysGeneralFieldEntity(&tfield, &sfield);
					FTDC_ADD_FIELD(&m_pkgSend, &tfield);
					itor.Next();
					if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
					{
						break;
					}
				}

				if (m_pFrontServer->GetSession(rid.SessionID))
				{
					((CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)))->SendRequestPackage(&m_pkgSend);
				}

				if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
				{
					m_pFrontServer->m_vRid.erase(it);
				}
			}

			break;
		case FTD_TID_RspQryNetMonitorTaskResultTopic:
			QUERYRSP(NetMonitorTaskResult);
			break;
		case FTD_TID_RspQryNetRoomTopic:
			{
				int nRid = pFTDCPackage->GetRequestId();
				map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
				TRID rid = it->second;
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryNetRoomTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				m_pkgSend.SetChain(pFTDCPackage->GetChain());
				m_pkgSend.SetRequestId(rid.RequestId);

				CFTDRspQryNetRoomField	sfield;
				memset(&sfield, 0, sizeof(sfield));

				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &sfield) > 0)
				{
					FTDC_ADD_FIELD(&m_pkgSend, &sfield);
				}

				if (m_pFrontServer->GetSession(rid.SessionID))
				{
					((CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)))->SendRequestPackage(&m_pkgSend);
				}

				if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
				{
					m_pFrontServer->m_vRid.erase(it);
				}
			}

			break;
		default:
			break;
	}

	return 0;
}

void CCountConnector::OnReqQryTradeDayChange(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryTradeDayChangeField fieldChange;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldChange);

	//例行清流
	if (strcmp(fieldChange.ChangeType.getValue(), TRUNCATEFLOW) == 0)
	{
		// 将该对应该编号的流容易清0
		printf("清除编号为 %s 的流数据\n", (const char *)fieldChange.OldDate);
		fflush(stdout);

		int nSeq = atoi((const char *)fieldChange.OldDate);
		if (nSeq >= MAX_EVENTFLOWNUM)
		{
			return;
		}

		g_pStatusSubcriber[nSeq]->Truncate(nSeq + 1);

		m_pkgSend.PreparePackage(
				FTD_TID_ReqUserLogin,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		CFTDReqUserLoginField fieldLogin;
		memset(&fieldLogin, 0, sizeof(fieldLogin));
		fieldLogin.UserID = "front";
		fieldLogin.Password = "frontpd";
		FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);

		CFTDDisseminationField	fieldDissemination;
		fieldDissemination.SequenceSeries = g_pStatusSubcriber[nSeq]->GetSequenceSeries();	// GetSequenceSeries();
		fieldDissemination.SequenceNo = g_pStatusSubcriber[nSeq]->GetReceivedCount();		// GetReceivedCount();
		FTDC_ADD_FIELD(&m_pkgSend, &fieldDissemination);
		((CFTDCSession *)pSession)->RegisterSubscriber(
				g_pStatusSubcriber[nSeq]);
		((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
	}
	else if (strcmp(fieldChange.ChangeType.getValue(), CHANGETRADEDAY) == 0)
	{
		if (m_sCurTradeDay.length() > 0)
		{
			if (strcmp(m_sCurTradeDay.data(),fieldChange.NewDate.getValue()) < 0)
			{
				CTimeType theTime;
				CDateType beginDate;

				time_t	timep;
				time(&timep);
				timep -= g_FrontRange * 3600;

				struct tm tm_time;
				LocalTime(&timep, &tm_time);
			
				sprintf(
					(char *)(theTime.getValue()),
					"%02d:%02d:%02d",
					tm_time.tm_hour,
					tm_time.tm_min,
					tm_time.tm_sec);
				sprintf(
					(char *)(beginDate.getValue()),
					"%d%02d%02d",
					tm_time.tm_year + 1900,
					tm_time.tm_mon + 1,
					tm_time.tm_mday);

				//清理报单响应内存数据
				CLEARMEMDB(SysMdbTradeFrontOrderRttStat);

				//清理会员交易统计
				g_mapRtnPartiOrder.clear();
				g_mpPartiOrderCnt.clear();
				RemoveOneDayFromMDB(m_sCurTradeDay.data());

				//更新成最新的交易日期
				m_sCurTradeDay = fieldChange.NewDate.getValue();

				/// Mod by Henchi, 20140620
				///切换交易日,清理FIB流和内存数据
				ClearMemeryDatabase();
			}
		}
		else
		{
			//更新成最新的交易日期
			m_sCurTradeDay = fieldChange.NewDate.getValue();
		}
	}
}

void CCountConnector::OnRspUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	//pSession->Publish(m_myTimer.GetFlow(), 1, 0);
}

void CCountConnector::RemoveOneDayFromMDB(const char *strDay)
{
	//把需要删除的内存数据库罗列在这里
	CSysParticTradeOrderStates	*sfield = pMemoryDB->
		m_SysParticTradeOrderStatesFactory->startFindByAll();
	while (sfield)
	{
		CSysParticTradeOrderStates	*tfield = pMemoryDB->
			m_SysParticTradeOrderStatesFactory->findNextByAll();
		if (sfield->MonDate == strDay)
		{
			pMemoryDB->m_SysParticTradeOrderStatesFactory->remove(sfield);
		}

		sfield = tfield;
	}
}

void CCountConnector::ClearMemeryDatabase(void)
{
	CTimeType theTime;
	CDateType beginDate;

	time_t	timep;
	time(&timep);
	timep -= g_FrontRange * 3600;

	struct tm tm_time;
	LocalTime(&timep, &tm_time);

	sprintf(
		(char *)(theTime.getValue()),
		"%02d:%02d:%02d",
		tm_time.tm_hour,
		tm_time.tm_min,
		tm_time.tm_sec);
	sprintf(
		(char *)(beginDate.getValue()),
		"%d%02d%02d",
		tm_time.tm_year + 1900,
		tm_time.tm_mon + 1,
		tm_time.tm_mday);

	printf("--- MDB CLEAR Start ---\n");

	///清理告警:
	/*CSysWarningEvent *oldField =pMemoryDB->m_SysWarningEventFactory->startFindByTime(beginDate ,theTime);
	while(oldField)
	{
		CSysWarningEvent *tmpField =pMemoryDB->m_SysWarningEventFactory->findNextByTime();
		if(oldField->ProcessFlag =="N")
		{
			bool rmFlag =false;
			CSysWarningEvent *yField =pMemoryDB->m_SysWarningEventFactory->startFindByEvendIDs(oldField->EvendID);
			while(yField)
			{
				if(yField->ProcessFlag =="Y")
				{
					rmFlag =true;
					break;
				}
				yField =pMemoryDB->m_SysWarningEventFactory->findNextByEvendIDs();
			}
			pMemoryDB->m_SysWarningEventFactory->endFindByEvendIDs();

			if(rmFlag)
			{
				pMemoryDB->m_SysWarningEventFactory->remove(oldField);
				pMemoryDB->m_SysWarningEventFactory->remove(yField);
			}
		}
		oldField =tmpField;
	}
	pMemoryDB->m_SysWarningEventFactory->endFindByTime();*/
	///清理告警明细：
	CSysWarningQuery *oldFieldQuery = pMemoryDB->m_SysWarningQueryFactory->
		startFindByTime(beginDate, theTime);
	while (oldFieldQuery)
	{
		CSysWarningQuery *tmpField = pMemoryDB->m_SysWarningQueryFactory->
			findNextByTime();
		pMemoryDB->m_SysWarningQueryFactory->remove(oldFieldQuery);
		oldFieldQuery = tmpField;
	}

	pMemoryDB->m_SysWarningQueryFactory->endFindByTime();

	///清理日志:
	CSyslogEvent *oldFieldlog = pMemoryDB->m_SyslogEventFactory->startFindByTime(
			beginDate,
			theTime);
	while (oldFieldlog)
	{
		CSyslogEvent *tmpField = pMemoryDB->m_SyslogEventFactory->findNextByTime();
		pMemoryDB->m_SyslogEventFactory->remove(oldFieldlog);
		oldFieldlog = tmpField;
	}

	pMemoryDB->m_SyslogEventFactory->endFindByTime();

	CLEARMEMDB(SysMdbObjectAttr);			
	CLEARMEMDB(SysMdbSyslogInfo);			
	//CLEARMEMDB(SysUserInfo);						
	CLEARMEMDB(SysOnlineUserInfo);			
	//CLEARMEMDB(SysWarningEvent);				
	//CLEARMEMDB(SysWarningQuery);				
	CLEARMEMDB(SyslogEvent);						
	CLEARMEMDB(SysEventDescrip);				
	CLEARMEMDB(RspQryHostEnvCommon);		
	CLEARMEMDB(RspQryHostEnvLan);			
	CLEARMEMDB(RspQryHostEnvStorage);	
	CLEARMEMDB(RspQryHostEnvIO);				
	CLEARMEMDB(RspQryHostEnvFS);				
	CLEARMEMDB(RspQryHostEnvSwap);			
	CLEARMEMDB(RspQryHostEnvLanCfg);		
	CLEARMEMDB(SysMdbTopCpuInfo);			
	CLEARMEMDB(SysMdbTopMemInfo);			
	CLEARMEMDB(SysMdbTopProcessInfo);	
	CLEARMEMDB(SysMdbFileSystemInfo);	
	CLEARMEMDB(SysMdbNetworkInfo);			
	CLEARMEMDB(SysMdbWebAppInfo);			
	CLEARMEMDB(SysMdbMemPoolInfo);			
	CLEARMEMDB(SysMdbConnectorInfo);		
	CLEARMEMDB(SysMdbDBQuery);					
	CLEARMEMDB(SysMdbRouterInfo);			
	CLEARMEMDB(SysMdbDiskIO);					
	CLEARMEMDB(SysMdbStatInfo);				
	CLEARMEMDB(SysMdbTradeFrontOrderRttStat);	

	timep += g_FrontRange * 3600;

	time_t	timep1;
	time(&timep1);
	printf("--- MDB CLEAR End [%d]s ---\n", timep1 - timep);
}

void CCountConnector::OnRspQryJDBCInfoTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	int nRid = pFTDCPackage->GetRequestId();
	map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
	TRID rid = it->second;
	if (m_pFrontServer->GetSession(rid.SessionID))
	{
		pFTDCPackage->SetRequestId(rid.RequestId);
		((CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)))->SendRequestPackage(pFTDCPackage);
	}

	if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
	{
		m_pFrontServer->m_vRid.erase(it);
	}
}
