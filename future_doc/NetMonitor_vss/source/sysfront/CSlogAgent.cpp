/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CSlogAgent.cpp
///@brief	定义了查询代理的类
///@history
///20080810	郭鹏		创建该文件
///20080810	郭鹏		修订注释
#include "CSlogAgent.h"
#include "FrontServer.h"
#include "CListSession.h"
#include "UFCopy.h"

extern map<int, list<TradeLogStrInfo> > g_mapTradeLogStr;
extern map<int, int> g_SubcriberMap;
extern CListSessionArray *g_pListSessionArray;

CSlogAgent::CSlogAgent(CReactor *pReactor) :
	CSessionFactory(pReactor, 1)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_pSlogSession = NULL;
	m_rtnCutLine.MonDate = "";
	m_rtnCutLine.OrderRttCutLine = "";
}
												 
CSession *CSlogAgent::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);
	return pSession;
}

void CSlogAgent::OnSessionConnected(CSession *pSession)
{
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CSlogAgent::OnSessionConnected: %0x \n",
		ctime(&timep),
		pSession);
	CSessionFactory::OnSessionConnected(pSession);
	m_pSlogSession = (CFTDCSession *)pSession;
	fflush(stdout);
}

void CSlogAgent::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CSlogAgent::OnSessionDisconnected: %0x \n",
		ctime(&timep),
		pSession);
	fflush(stdout);
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
	m_pSlogSession = NULL;
}

int CSlogAgent::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	pFTDCPackage->OutputHeader(g_pQryPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pQryPackOutput);
#endif
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_RspQryTradeLogTopic:
			OnRspQryTradeLogTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryFrontInfoTopic:
			OnRspQryFrontInfoTopic(pFTDCPackage, pSession);
			break;		
		case FTD_TID_RtnTradeFrontOrderRttStatTopic:
			OnRtnTradeFrontOrderRttStatTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnTradeOrderRttCutLineTopic:
			OnRtnTradeOrderRttCutLineTopic(pFTDCPackage, pSession);
		default:
			break;
	}
	return 0;
}

void CSlogAgent::OnRspQryTradeLogTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession)
{
	int haveRspInfo = 0;
	int errorID = 0;
	int rID = pFTDCPackage->GetRequestId();

	CFTDRspInfoField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) > 0)
	{
		haveRspInfo = 1;
		if (qryfield.ErrorID > 0)
		{
			errorID = qryfield.ErrorID;
		}
	}

	///非正常情况
	//if(haveRspInfo ==0 ||haveRspInfo !=0&&errorID <=0 ||rID >0)
	if (rID == 0)
	{
		map<int, list<TradeLogStrInfo> >::iterator	it =
			g_mapTradeLogStr.find(qryfield.ErrorID);
		if (it != g_mapTradeLogStr.end())
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryTradeLogTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);

			CFTDRspQryTradeLogField sfield;
			CNamedFieldIterator itor = pFTDCPackage->
				GetNamedFieldIterator(
					&CFTDRspQryTradeLogField::m_Describe);
			while (!itor.IsEnd())
			{
				itor.Retrieve(&sfield);

				CFTDRspQryTradeLogField tfield;
				CopyRspQryTradeLogEntity(&tfield, &sfield);
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
				itor.Next();
			}

			list<TradeLogStrInfo>::iterator itList = it->second.begin();
			for (; itList != it->second.end(); itList++)
			{
				m_pkgSend.SetRequestId(itList->rId);
				itList->pSession->SendRequestPackage(&m_pkgSend);
				m_pkgSend.Pop(FTDCHLEN);
			}
		}
	}
	else	///正常情况
	{
		int count = 0;
		int nRid = pFTDCPackage->GetRequestId();
		map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);
		TRID rid = it->second;
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryTradeLogTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_pkgSend.SetChain(pFTDCPackage->GetChain());
		m_pkgSend.SetRequestId(rid.RequestId);

		CFTDRspInfoField rspInfoField;
		if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)
		{
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		}

		CFTDRspQryTradeLogField sfield;
		CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
				&CFTDRspQryTradeLogField::m_Describe);
		while (!itor.IsEnd())
		{
			itor.Retrieve(&sfield);
			count++;

			CFTDRspQryTradeLogField tfield;
			CopyRspQryTradeLogEntity(&tfield, &sfield);
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			itor.Next();
		}

		if (m_pFrontServer->GetSession(rid.SessionID))
		{
			(
				(CFTDCSession *)
					(m_pFrontServer->GetSession(rid.SessionID))
			)->SendRequestPackage(&m_pkgSend);
		}

		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
		{
			m_pFrontServer->m_vRid.erase(it);
		}
	}
}

				
void CSlogAgent::OnRspQryFrontInfoTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{																											
	int nRid = pFTDCPackage->GetRequestId();															
	map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);									
	TRID rid = it->second;																				
	m_pkgSend.PreparePackage(																			
			FTD_TID_RspQryFrontInfoTopic,																	
			FTDC_CHAIN_LAST,																			
			FTD_VERSION);																				
	m_pkgSend.SetChain(pFTDCPackage->GetChain());														
	m_pkgSend.SetRequestId(rid.RequestId);																
	CFTDRspInfoField rspInfoField;																		
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)											
	{																									
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);														
	}																									
																									 
	CFTDRspQryFrontInfoField sfield;																		
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(										
			&CFTDRspQryFrontInfoField::m_Describe);															
	while (!itor.IsEnd())																				
	{																									
		itor.Retrieve(&sfield);																			
		CFTDRspQryFrontInfoField tfield;																	
		CopyRspQryFrontInfoEntity(&tfield, &sfield);														
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


///前置保单响应信息
void CSlogAgent::OnRtnTradeFrontOrderRttStatTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnTradeFrontOrderRttStatField	field;
	list<int> iList;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnTradeFrontOrderRttStatField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CWriteableSysMdbTradeFrontOrderRttStat	mdbfield;

		mdbfield.SubcriberID = g_StringIdMap.getStringId(
				field.ObjectID.getValue());
		mdbfield.ObjectID = field.ObjectID.getValue();
		mdbfield.MonDate = field.MonDate;
		mdbfield.MonTime = field.MonTime;
		mdbfield.OrderCount = field.OrderCount;
		mdbfield.OrderRttSum = field.OrderRttSum;
		mdbfield.OrderMaxRtt = field.OrderMaxRtt;
		mdbfield.OrderMinRtt = field.OrderMinRtt;
		mdbfield.OrderRttSqu = field.OrderRttSqu;
		mdbfield.OrderRttCutDistrib = field.OrderRttCutDistrib;

		if (find(
				iList.begin(),
			iList.end(),
			mdbfield.SubcriberID) == iList.end())
		{
			CSysMdbTradeFrontOrderRttStat *oldfield = pMemoryDB->
				m_SysMdbTradeFrontOrderRttStatFactory->startFindByDsc(
						mdbfield.SubcriberID);
			if (oldfield)
			{
				while (oldfield)
				{
					CSysMdbTradeFrontOrderRttStat *tmpfield = pMemoryDB->
						m_SysMdbTradeFrontOrderRttStatFactory->findNextByDsc();

					if (mdbfield.MonDate == oldfield->MonDate
					&&	mdbfield.MonTime == oldfield->MonTime)
					{
						pMemoryDB->m_SysMdbTradeFrontOrderRttStatFactory->remove(
								oldfield);
					}

					oldfield = tmpfield;
				}
			}

			pMemoryDB->m_SysMdbTradeFrontOrderRttStatFactory->endFindByDsc();
			iList.push_back(mdbfield.SubcriberID);

			map<int, int>::iterator it = g_SubcriberMap.find(
					mdbfield.SubcriberID);
			if (it == g_SubcriberMap.end())
			{
				g_SubcriberMap[mdbfield.SubcriberID] = 14;
			}
		}

		pMemoryDB->m_SysMdbTradeFrontOrderRttStatFactory->add(&mdbfield, NULL);

		m_pkgSend.PreparePackage(
				FTD_TID_RtnTradeFrontOrderRttStatTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &field);
		g_pListSessionArray->SendPackage(&m_pkgSend, field.ObjectID.getValue());

		itor.Next();
	}
}

void CSlogAgent::OnRtnTradeOrderRttCutLineTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{	
	CFTDRtnTradeOrderRttCutLineField sfield;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnTradeOrderRttCutLineField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		if (sfield.MonDate == "")
		{
			CopyRtnTradeOrderRttCutLineEntity(&m_rtnCutLine, &sfield);
		}
		itor.Next();
	}
}

const CFTDRtnTradeOrderRttCutLineField& CSlogAgent::getRtnCutLine()const
{
	return m_rtnCutLine;
}

