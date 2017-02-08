/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CQueryAgent.cpp
///@brief	定义了查询代理的类
///@history
///20080810	郭鹏		创建该文件
///20080810	郭鹏		修订注释
#include "CQueryAgent.h"
#include "FrontServer.h"
#include "CListSession.h"
#include <iostream>
using namespace std;

#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pClnPackOutput;	// 数据包输出到文件
extern CLogger	*g_pQryPackOutput;
extern CLogger	*g_pEntPackOutput;
extern CLogger	*g_pFibPackOutput;
#endif
extern CListSessionArray *g_pListSessionArray;
extern list<CFTDCSession *> g_mListAllSession;

extern CXMLDoc	*pXMLDoc;

//extern CXMLNode *pXMLRootNode;
extern char *g_mXMLPath;

extern map<int, list<TradeLogStrInfo> > g_mapTradeLogStr;

extern list<CFTDRtnHistoryTradePeakField> list_HistoryTradePeak;

extern CTimeType theTime;
extern map<int, int> g_SubcriberMap;

//key:targetip
extern map<string, CFTDRtnNetLocalPingResultInfoField>	g_localpingresult;

map<string, CFTDRspQryNetLocalPingResultInfoField>	g_localpingqueryresult;

//////////////////////////////////////////////////////////////////////////
CQueryAgent::CQueryAgent(CReactor *pReactor) :
	CSessionFactory(pReactor, 1)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_bLoginFlag = false;
	m_pQuerySession = NULL;
}

#define MACRTN2FRONT(x)													\
	{																	\
		CFTDRtn##x##Field fieldInfo;									\
		CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator( \
				&CFTDRtn##x##Field::m_Describe);						\
		while (!itor.IsEnd())											\
		{																\
			itor.Retrieve(&fieldInfo);									\
			m_pkgSend.PreparePackage(									\
					FTD_TID_Rtn##x##Topic,								\
					FTDC_CHAIN_LAST,									\
					FTD_VERSION);										\
			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);						\
			list<CFTDCSession *>::iterator	it;							\
			for (it = g_mListAllSession.begin();						\
				 it != g_mListAllSession.end();							\
				 it++)													\
			{															\
				(*it)->SendRequestPackage(&m_pkgSend);					\
				m_pkgSend.Pop(FTDCHLEN);								\
			}															\
															 \
			itor.Next();												\
		}																\
	}
																	 
CSession *CQueryAgent::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);
	return pSession;
}

void CQueryAgent::OnSessionConnected(CSession *pSession)
{
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CQueryAgent::OnSessionConnected: %0x \n",
		ctime(&timep),
		pSession);
	CSessionFactory::OnSessionConnected(pSession);
	m_pQuerySession = (CFTDCSession *)pSession;
	cout << "Query Connect OK!" << endl;
	fflush(stdout);
}

void CQueryAgent::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CQueryAgent::OnSessionDisconnected: %0x \n",
		ctime(&timep),
		pSession);
	fflush(stdout);
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
	m_pQuerySession = NULL;
}

int CQueryAgent::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	pFTDCPackage->OutputHeader(g_pQryPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pQryPackOutput);
#endif
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_RspQryWarningEventTopic:
			OnRspQryWarningEventTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryHistoryObjectAttrTopic:
			QUERYRSP(HistoryObjectAttr);
			break;
		case FTD_TID_RspQrySysUserLoginTopic:
			//		OnRspQrySysUserLoginTopic(pFTDCPackage,pSession);
			break;
		case FTD_TID_RspQrySysUserLogoutTopic:
			//		OnRspQrySysUserLogoutTopic(pFTDCPackage,pSession);
			break;
		case FTD_TID_RspQrySysUserPasswordUpdateTopic:
			QUERYRSP(SysUserPasswordUpdate);
			break;
		case FTD_TID_RspQrySysUserRegisterTopic:
			//		QUERYRSP(SysUserRegister);
			{
				int nRid = pFTDCPackage->GetRequestId();
				map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
				TRID rid = it->second;
				m_pkgSend.PreparePackage(
						FTD_TID_RspQrySysUserRegisterTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				m_pkgSend.SetChain(pFTDCPackage->GetChain());
				m_pkgSend.SetRequestId(rid.RequestId);

				CFTDRspInfoField rspInfoField;
				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)
				{
					FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
				}

				CFTDRspQrySysUserRegisterField	sfield;
				CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
						&CFTDRspQrySysUserRegisterField::m_Describe);
				while (!itor.IsEnd())
				{
					itor.Retrieve(&sfield);

					CFTDRspQrySysUserRegisterField	tfield;
					CopyRspQrySysUserRegisterEntity(&tfield, &sfield);
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
		case FTD_TID_RspQrySysUserDeleteTopic:
			QUERYRSP(SysUserDelete);
			break;
		case FTD_TID_RspQryTradeFrontOrderRttStatTopic:
			QUERYRSP(TradeFrontOrderRttStat);
			break;
		case FTD_TID_RtnSysUser:
			OnRtnSysUser(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryHistoryCpuInfoTopic:
			//		QUERYRSP(HistoryCpuInfo);
			{
				int nRid = pFTDCPackage->GetRequestId();
				map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
				TRID rid = it->second;
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryHistoryCpuInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				m_pkgSend.SetChain(pFTDCPackage->GetChain());
				m_pkgSend.SetRequestId(rid.RequestId);

				CFTDRspInfoField rspInfoField;
				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)
				{
					FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
				}

				CFTDRspQryHistoryCpuInfoField sfield;
				CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
						&CFTDRspQryHistoryCpuInfoField::m_Describe);
				while (!itor.IsEnd())
				{
					itor.Retrieve(&sfield);

					CFTDRspQryHistoryCpuInfoField tfield;
					CopyRspQryHistoryCpuInfoEntity(&tfield, &sfield);
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
		case FTD_TID_RspQryHistoryMemInfoTopic:
			QUERYRSP(HistoryMemInfo);
			break;
		case FTD_TID_RspQryHistoryNetworkInfoTopic:
			QUERYRSP(HistoryNetworkInfo);
			break;
		case FTD_TID_RtnHistoryTradePeakTopic:
			OnRtnHistoryTradePeakTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQrySyslogEventTopic:
			OnRspQrySyslogEventTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryDBQueryTopic:
			QUERYRSP(DBQuery);
			break;
		case FTD_TID_RspQryNetMonitorTaskStatusResultTopic:
			QUERYRSP(NetMonitorTaskStatusResult);
			break;
		case FTD_TID_RspQryNetMonitorTaskResultTopic:
			QUERYRSP(NetMonitorTaskResult);
			break;
		case FTD_TID_RspQryNetBaseLineResultTopic:
			QUERYRSP(NetBaseLineResult);
			break;
		case FTD_TID_RspQryNetLocalPingResultInfoTopic:
			//QUERYRSP(NetLocalPingResultInfo);
			{																										
				int nRid = pFTDCPackage->GetRequestId();															
				map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);									
				TRID rid = it->second;																																																											
			
				CFTDRspQryNetLocalPingResultInfoField sfield;																		
				CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(										
					&CFTDRspQryNetLocalPingResultInfoField::m_Describe);															
				while (!itor.IsEnd())																				
				{																									
					itor.Retrieve(&sfield);																			
					CFTDRspQryNetLocalPingResultInfoField tfield;																	
					CopyRspQryNetLocalPingResultInfoEntity(&tfield, &sfield);
					if (tfield.TarIPADDR.getValue() != "")
					{
						g_localpingqueryresult[tfield.TarIPADDR.getValue()] = tfield;																							
					}													
					itor.Next();																				
					if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())								
					{																								
						break;																						
					}																								
				}																									
			
				if (m_pFrontServer->GetSession(rid.SessionID))														
				{		
					if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
					{
						// 首先发送数据库数据
						map<string, CFTDRspQryNetLocalPingResultInfoField>::iterator it_query = g_localpingqueryresult.begin();
						for (; it_query != g_localpingqueryresult.end(); ++it_query)
						{
							m_pkgSend.PreparePackage(																			
								FTD_TID_RspQryNetLocalPingResultInfoTopic,																	
								FTDC_CHAIN_CONTINUE,																			
								FTD_VERSION);																				
							m_pkgSend.SetRequestId(rid.RequestId);

							FTDC_ADD_FIELD(&m_pkgSend, &it_query->second);
							((CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)))->SendRequestPackage(&m_pkgSend); 
						}
						
						//将缓冲区列表的数据加载发送过去
						if (rid.RequestId==m_pFrontServer->m_dwLocaPingReqID)
						{
							
							map<string, CFTDRtnNetLocalPingResultInfoField>::iterator l_it =
								g_localpingresult.begin();
							for (; l_it != g_localpingresult.end(); ++l_it)
							{
								m_pkgSend.PreparePackage(																			
									FTD_TID_RspQryNetLocalPingResultInfoTopic,																	
									FTDC_CHAIN_CONTINUE,																			
									FTD_VERSION);
								m_pkgSend.SetRequestId(rid.RequestId);	
								CFTDRspQryNetLocalPingResultInfoField rspfield;
								CopySysLocalPingResultInfoEntity(&rspfield, &l_it->second);

								FTDC_ADD_FIELD(&m_pkgSend, &rspfield);
								((CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)))->SendRequestPackage(&m_pkgSend);
							}
						}

						// 此处补发一个last包
						m_pkgSend.PreparePackage(
							FTD_TID_RspQryNetLocalPingResultInfoTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
						m_pkgSend.SetRequestId(rid.RequestId);

						CFTDRspInfoField rspInfoField;
						memset(&rspInfoField, 0, sizeof(rspInfoField));
						rspInfoField.ErrorID = 0;
						FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
						((CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)))->SendRequestPackage(&m_pkgSend); 

						// 清除缓冲数据
						m_pFrontServer->m_vRid.erase(it);
						g_localpingqueryresult.clear();	
					}
						
				}																																																	
			}
			break;
		case FTD_TID_RspQryNetRomotePingResultInfoTopic:
			QUERYRSP(NetRomotePingResultInfo);
			break;
		case FTD_TID_RspQryDiskIOTopic:
			QUERYRSP(DiskIO);
			break;
		case FTD_TID_RspQryStatInfoTopic:
			QUERYRSP(StatInfo);
			break;
		case FTD_TID_RspQryRouterInfoTopic:
			QUERYRSP(RouterInfo);
			break;
		case FTD_TID_RspQryTopProcessInfoTopic:
			QUERYRSP(TopProcessInfo);
			break;
		case FTD_TID_RspQryNetworkInfoTopic:
			QUERYRSP(NetworkInfo);
			break;
		case FTD_TID_RspQryTradeOrderRttCutLineTopic:
			QUERYRSP(TradeOrderRttCutLine);
			break;
		case FTD_TID_RspQryParticTradeOrderStatesTopic:
			QUERYRSP(ParticTradeOrderStates);
			break;
		case FTD_TID_RspQryPerformanceTopTopic:
			OnRspQryPerformanceTopTopic(pFTDCPackage, pSession);
			break;
		default:
			{
				/*
			int nRid =pFTDCPackage->GetRequestId();
			map<int ,TRID>::iterator it =m_pFrontServer->m_vRid.find(nRid);
			TRID rid =it->second;
			m_pkgSend.PreparePackage(pFTDCPackage->GetTID(), pFTDCPackage->GetChain(), pFTDCPackage->GetVersion());
			m_pkgSend.SetRequestId(rid.RequestId);
			CFTDRspInfoField rspInfoField;
			if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField)>0)
			{
				FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
			}
			if(m_pFrontServer->GetSession(rid.SessionID))
			{
				((CFTDCSession *)(m_pFrontServer->GetSession(rid.SessionID)))->SendRequestPackage(&m_pkgSend);
			}
			if(pFTDCPackage->GetChain() ==FTDC_CHAIN_LAST)
			m_pFrontServer->m_vRid.erase(it);
*/
			}

			break;
	}

	return 0;
}

void CQueryAgent::OnRspQryWarningEventTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	int nRid = pFTDCPackage->GetRequestId();
	map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
	TRID rid = it->second;
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryWarningEventTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetChain(pFTDCPackage->GetChain());
	m_pkgSend.SetRequestId(rid.RequestId);

	CFTDRspInfoField rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)
	{
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	}

	CFTDRspQryWarningEventField sfield;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRspQryWarningEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		CFTDRspQryWarningEventField tfield;
		CopyRspQryWarningEventEntity(&tfield, &sfield);
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

void CQueryAgent::OnRspQryHistoryObjectAttrTopic(
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

void CQueryAgent::OnRspQryFrontInfoTopic(
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

void CQueryAgent::OnRspQrySysUserLoginTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	int nRid = pFTDCPackage->GetRequestId();
	map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
	TRID rid = it->second;
	m_pkgSend.PreparePackage(
			FTD_TID_RspQrySysUserLoginTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetChain(pFTDCPackage->GetChain());
	m_pkgSend.SetRequestId(rid.RequestId);

	CFTDRspInfoField rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)
	{
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	}

	CFTDRspQrySysUserLoginField sfield;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRspQrySysUserLoginField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		CFTDRspQrySysUserLoginField tfield;
		CopyRspQrySysUserLoginEntity(&tfield, &sfield);
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
		if (rspInfoField.ErrorID == 0)
		{
			g_mListAllSession.push_back(
					(CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)));
		}

		OnClientInit(
			(CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)));
	}

	if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
	{
		m_pFrontServer->m_vRid.erase(it);
	}
}

void CQueryAgent::OnRspQrySysUserLogoutTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	int nRid = pFTDCPackage->GetRequestId();
	map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
	TRID rid = it->second;
	m_pkgSend.PreparePackage(
			FTD_TID_RspQrySysUserLogoutTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetChain(pFTDCPackage->GetChain());
	m_pkgSend.SetRequestId(rid.RequestId);

	CFTDRspInfoField rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)
	{
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	}

	CFTDRspQrySysUserLogoutField sfield;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRspQrySysUserLogoutField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		CFTDRspQrySysUserLogoutField tfield;
		CopyRspQrySysUserLogoutEntity(&tfield, &sfield);
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
		g_pListSessionArray->DelFTDSession(
				(CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)));
		g_mListAllSession.remove(
				(CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)));
	}

	if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
	{
		m_pFrontServer->m_vRid.erase(it);
	}
}

void CQueryAgent::OnClientInit(CFTDCSession *pSession)
{
	list<CFTDRtnWarningEventField>	theList;
	CSysWarningEvent *sfield = pMemoryDB->m_SysWarningEventFactory->
		startFindByAll();
	while (sfield)
	{
		if (sfield->WarningLevel == "info")
		{
			sfield = pMemoryDB->m_SysWarningEventFactory->findNextByAll();
			continue;
		}

		CFTDRtnWarningEventField tfield;
		CopySysWarningEventEntity(&tfield, sfield);
		theList.push_front(tfield);
		sfield = pMemoryDB->m_SysWarningEventFactory->findNextByAll();
	}

	pMemoryDB->m_SysWarningEventFactory->endFindByAll();
	if (pSession)
	{
		list<CFTDRtnWarningEventField>::iterator it = theList.begin();
		for (; it != theList.end(); it++)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnWarningEventTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &(*it));
			pSession->SendRequestPackage(&m_pkgSend);
		}
	}
}

void CQueryAgent::OnRtnSysUser(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnSysUserField::m_Describe);
	if (!itor.IsEnd())
	{
		if (pXMLDoc == NULL)
		{
			pXMLDoc = new CXMLDoc();

			CXMLNode *pXMLRootNode = new CXMLNode();
			pXMLDoc->setVersion("1.0");
			pXMLDoc->setEncoding("GB2312");
			pXMLRootNode->setNodeType(XMLTag);
			pXMLRootNode->setName("UserInfo");
			pXMLDoc->setRootNode(pXMLRootNode);
		}
	}

	while (!itor.IsEnd())
	{
		CFTDRtnSysUserField sfield;
		itor.Retrieve(&sfield);

		CXMLNode *pXMLRootNode = new CXMLNode();
		pXMLRootNode = pXMLDoc->getRootNode();

		CXMLNodeList *pNodeList = pXMLRootNode->getNodeList();

		if (sfield.Privilege < 0)
		{
			if (pNodeList == NULL)
			{
				return;
			}
			else
			{
				CXMLNodeList::iterator	it;
				for (it = pNodeList->begin(); it != pNodeList->end(); it++)
				{
					if ((
							strcmp(
							(*it)->findProperty("UserID"),
						sfield.UserID.getValue()) == 0
					))
					{
						pNodeList->erase(it);
						break;
					}
				}
			}
		}
		else
		{
			if (pNodeList == NULL)
			{
				CXMLNode *pXMLNode = new CXMLNode();
				pXMLNode->setName("UserInfo");
				pXMLNode->setNodeType(XMLTag);
				pXMLNode->addProperty(
						"UserID",
						(char *)(sfield.UserID.getValue()));
				pXMLNode->addProperty(
						"UserName",
						(char *)(sfield.UserName.getValue()));
				pXMLNode->addProperty(
						"Password",
						(char *)(sfield.Password.getValue()));
				pXMLNode->addProperty(
						"UserInfo",
						(char *)(sfield.UserInfo.getValue()));

				pXMLNode->addProperty(
						"EMail",
						(char *)(sfield.EMail.getValue()));
				pXMLNode->addProperty(
						"HomePhone",
						(char *)(sfield.HomePhone.getValue()));
				pXMLNode->addProperty(
						"MobilePhone",
						(char *)(sfield.MobilePhone.getValue()));

				pXMLNode->addProperty("Privilege", sfield.Privilege);
				pXMLNode->addProperty("EMailFlag", sfield.EMailFlag);
				pXMLNode->addProperty("HomePhoneFlag", sfield.HomePhoneFlag);
				pXMLNode->addProperty(
						"MobilePhoneFlag",
						sfield.MobilePhoneFlag);
				pXMLRootNode->addNode(pXMLNode);
			}
			else
			{
				CXMLNodeList::iterator	it;
				for (it = pNodeList->begin(); it != pNodeList->end(); it++)
				{
					if ((
							strcmp(
							(*it)->findProperty("UserID"),
						sfield.UserID.getValue()) == 0
					))
					{
						(*it)->setProperty(
								"UserName",
								(char *)(sfield.UserName.getValue()));
						(*it)->setProperty(
								"Password",
								(char *)(sfield.Password.getValue()));
						(*it)->setProperty(
								"UserInfo",
								(char *)(sfield.UserInfo.getValue()));

						char tmp[10] = "";
						sprintf(tmp, "%d", (const int)(sfield.Privilege));
						(*it)->setProperty("Privilege", tmp);

						sprintf(tmp, "%d", (const int)(sfield.EMailFlag));
						(*it)->setProperty("EMailFlag", tmp);
						sprintf(tmp, "%d", (const int)(sfield.HomePhoneFlag));
						(*it)->setProperty("HomePhoneFlag", tmp);
						sprintf(tmp, "%d", (const int)(sfield.MobilePhoneFlag));
						(*it)->setProperty("MobilePhoneFlag", tmp);
						(*it)->setProperty(
								"EMail",
								(char *)(sfield.EMail.getValue()));
						(*it)->setProperty(
								"HomePhone",
								(char *)(sfield.HomePhone.getValue()));
						(*it)->setProperty(
								"MobilePhone",
								(char *)(sfield.MobilePhone.getValue()));
						break;
					}
				}

				if (it == pNodeList->end())
				{
					CXMLNode *pXMLNode = new CXMLNode();
					pXMLNode->setName("UserInfo");
					pXMLNode->setNodeType(XMLTag);
					pXMLNode->addProperty(
							"UserID",
							(char *)(sfield.UserID.getValue()));
					pXMLNode->addProperty(
							"UserName",
							(char *)(sfield.UserName.getValue()));
					pXMLNode->addProperty(
							"Password",
							(char *)(sfield.Password.getValue()));
					pXMLNode->addProperty(
							"UserInfo",
							(char *)(sfield.UserInfo.getValue()));
					pXMLNode->addProperty("Privilege", sfield.Privilege);

					pXMLNode->addProperty("EMailFlag", sfield.EMailFlag);
					pXMLNode->addProperty(
							"HomePhoneFlag",
							sfield.HomePhoneFlag);
					pXMLNode->addProperty(
							"MobilePhoneFlag",
							sfield.MobilePhoneFlag);

					pXMLNode->addProperty(
							"EMail",
							(char *)(sfield.EMail.getValue()));
					pXMLNode->addProperty(
							"HomePhone",
							(char *)(sfield.HomePhone.getValue()));
					pXMLNode->addProperty(
							"MobilePhone",
							(char *)(sfield.MobilePhone.getValue()));
					pXMLRootNode->addNode(pXMLNode);
				}
			}
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RtnSysUser,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &sfield);

		list<CFTDCSession *>::iterator	itSession;
		for (itSession = g_mListAllSession.begin();
			 itSession != g_mListAllSession.end();
			 itSession++)
		{
			(*itSession)->SendRequestPackage(&m_pkgSend);
			m_pkgSend.Pop(FTDCHLEN);
		}

		itor.Next();
	}

	pXMLDoc->write(g_mXMLPath);
}

void CQueryAgent::OnRtnHistoryTradePeakTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnHistoryTradePeakField fieldInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnHistoryTradePeakField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		list<CFTDRtnHistoryTradePeakField>::iterator it = list_HistoryTradePeak.
			begin();
		for (; it != list_HistoryTradePeak.end(); it++)
		{
			if ((fieldInfo.ObjectID == (*it).ObjectID)
			&&	(fieldInfo.AttrType == (*it).AttrType)
			&&	(fieldInfo.RltAttrType == (*it).RltAttrType))
			{
				*it = fieldInfo;
				break;
			}
		}

		if (it == list_HistoryTradePeak.end())
		{
			list_HistoryTradePeak.push_back(fieldInfo);
		}

		itor.Next();
	}
}

void CQueryAgent::OnRspQrySyslogEventTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	int nRid = pFTDCPackage->GetRequestId();
	map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
	TRID rid = it->second;
	m_pkgSend.PreparePackage(
			FTD_TID_RspQrySyslogEventTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetChain(pFTDCPackage->GetChain());
	m_pkgSend.SetRequestId(rid.RequestId);

	CFTDRspInfoField rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)
	{
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	}

	CFTDRspQrySyslogEventField	sfield;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRspQrySyslogEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		CFTDRspQrySyslogEventField	tfield;
		CopyRspQryWarningEventEntity(&tfield, &sfield);
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

void CQueryAgent::OnRspQryPerformanceTopTopic( 
	CFTDCPackage *pFTDCPackage, 
	CFTDCSession *pSession )
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

