/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	FlowConnector.cpp
///@brief	实现了连接交易流水分析服务器并处理该服务器通信消息的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#include "FlowConnector.h"
#include "CListSession.h"
#include "CResultSubscriber.h"
#include <iostream>
using namespace std;

extern CListSessionArray *g_pListSessionArray;
extern CResultSubscriber *g_pResultSubcriber;

extern CFTDRspQryTradepeakField TradepeakField1;
extern CFTDRspQryTradepeakField TradepeakField2;

///交易前置报单负载统计：
extern map<int, CFTDRspQryFrontStatField> g_FrontStatMap;

extern map<int, list<TradeLogStrInfo> > g_mapTradeLogStr;

///座席登录流水
extern list<CFTDRtnTradeUserLoginInfoField> g_TradeUserLoginList;

//
// 面向计算服务器连接的类实现

//
CFlowConnector::CFlowConnector(CReactor *pReactor) :
	CAgentSessionFactory(pReactor, 1)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_Flag = false;
	m_pFlowSession = NULL;
}

CSession *CFlowConnector::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);
	return pSession;
}

void CFlowConnector::OnSessionConnected(CSession *pSession)
{
	CAgentSessionFactory::OnSessionConnected(pSession);

	time_t	timep;
	time(&timep);
	printf(
		"\t %s CFlowConnector::OnSessionConnected: %0x \n",
		ctime(&timep),
		pSession);
	fflush(stdout);

	//if(m_Flag)
	//{
	//	g_pResultSubcriber->UnLoad();
	//}
	m_pkgSend.PreparePackage(
			FTD_TID_ReqUserLogin,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqUserLoginField fieldLogin;
	memset(&fieldLogin, 0, sizeof(fieldLogin));
	fieldLogin.UserID = "frontRes";
	fieldLogin.Password = "frontpd";
	FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);

	CFTDDisseminationField	fieldDissemination;
	printf("\t Flow count %d\n", g_pResultSubcriber->GetReceivedCount());
	fflush(stdout);
	fieldDissemination.SequenceSeries = g_pResultSubcriber->GetSequenceSeries();	// GetSequenceSeries();
	fieldDissemination.SequenceNo = g_pResultSubcriber->GetReceivedCount();			// GetReceivedCount();
	FTDC_ADD_FIELD(&m_pkgSend, &fieldDissemination);
	((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
	((CFTDCSession *)pSession)->RegisterSubscriber(g_pResultSubcriber);
	m_Flag = true;
	m_pFlowSession = (CFTDCSession *)pSession;
}

void CFlowConnector::OnSessionDisconnected(CSession *pSession, int nReason) // 子类重载处理连接断开事件
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
	time_t	timep;
	time(&timep);
	printf(
		"\t %s CFlowConnector::OnSessionDisconnected: %0x \n",
		ctime(&timep),
		pSession);
	fflush(stdout);
	m_pFlowSession = NULL;
}

int CFlowConnector::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	printf(
		"\tCFlowConnector::HandlePackage:receive package %0x\n",
		pFTDCPackage->GetTID());
	fflush(stdout);
#endif

	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_RspUserLogin:
			OnRspUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryTradepeakTopic:
			OnRspQryTradepeak(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryTradeUserLoginStatTopic:
			FLOWRSP(TradeUserLoginStat);
			break;
		case FTD_TID_ReqQryTradeDayChangeTopic:
			//			OnReqQryTradeDayChange(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryTradeLogTopic:
			{
				int rID = pFTDCPackage->GetRequestId();

				CFTDRspInfoField qryfield;
				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) > 0)
				{
					/*haveRspInfo =1;
					if(qryfield.ErrorID >0)
						errorID =qryfield.ErrorID;*/
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

						FTDC_ADD_FIELD(&m_pkgSend, &qryfield);

						list<TradeLogStrInfo>::iterator itList = it->second.begin();
						for (; itList != it->second.end(); itList++)
						{
							m_pkgSend.SetRequestId(itList->rId);
							itList->pSession->SendRequestPackage(&m_pkgSend);
							m_pkgSend.Pop(FTDCHLEN);
						}
					}
				}
				else	///正常情况，即查询状态
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

		default:
			OnDefaultProcess(pFTDCPackage, pSession);
			break;
	}

	return 0;
}

void CFlowConnector::OnRspUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	//pSession->Publish(m_myTimer.GetFlow(), 1, 0);
}

void CFlowConnector::OnDefaultProcess(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	//	for(list<CFTDCSession *>::iterator i=g_pListFrontFtdSession.begin();
	//		i!=g_pListFrontFtdSession.end();++i)
	//	{
	//		printf("\tFlowConnector::OnDefaultProcess : CFTDCSession %0x\n", (long) (*i));
	//		if(i != NULL) (*i)->SendRequestPackage(pFTDCPackage);
	//	}
}

void CFlowConnector::OnRspQryTradepeak(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	/*	CFTDRspQryTradepeakField field; 
	CNamedFieldIterator itor= pFTDCPackage->GetNamedFieldIterator(&CFTDRspQryTradepeakField::m_Describe); 
	while (!itor.IsEnd()) 
	{ 
		itor.Retrieve(&field);
		{
			if(field.Flag ==1)
				CopySysTradepeakEntity(&TradepeakField1 ,&field);
			if(field.Flag ==2)
				CopySysTradepeakEntity(&TradepeakField2 ,&field);
		}
		itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
		{
			break;
		}
	}*/
}

void CFlowConnector::OnReqQryTradeDayChange(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	cout << "收到交易日切换通知" << endl;
	pMemoryDB->m_SysBargainOrderFactory->clearAll();
	pMemoryDB->m_SysInvalidateOrderFactory->clearAll();
	pMemoryDB->m_SysOrderStatusFactory->clearAll();
	pMemoryDB->m_SysInstPropertyFactory->clearAll();
	pMemoryDB->m_SysMarginRateFactory->clearAll();
	pMemoryDB->m_SysPriceLimitFactory->clearAll();
	pMemoryDB->m_SysPartPosiLimitFactory->clearAll();
	pMemoryDB->m_SysClientPosiLimitFactory->clearAll();
	pMemoryDB->m_SysSpecialPosiLimitFactory->clearAll();
	pMemoryDB->m_SysTransactionChgFactory->clearAll();
	pMemoryDB->m_SysClientChgFactory->clearAll();
	pMemoryDB->m_SysPartClientChgFactory->clearAll();
	pMemoryDB->m_SysPosiLimitChgFactory->clearAll();
	pMemoryDB->m_SysClientPosiLimitChgFactory->clearAll();
	pMemoryDB->m_SysSpecPosiLimitChgFactory->clearAll();
	pMemoryDB->m_SysHedgeDetailChgFactory->clearAll();
	pMemoryDB->m_SysMarginRateChgFactory->clearAll();
	pMemoryDB->m_SysUserIpChgFactory->clearAll();
	pMemoryDB->m_SysParticipantInitFactory->clearAll();
	pMemoryDB->m_SysUserInitFactory->clearAll();
	pMemoryDB->m_SysTradeUserLoginInfoFactory->clearAll();
	pMemoryDB->m_SysPartTradeFactory->clearAll();

	pMemoryDB->m_SysInstrumentStatusFactory->clearAll();
	pMemoryDB->m_SysCurrTradingSegmentAttrFactory->clearAll();

	g_TradeUserLoginList.clear();
	g_FrontStatMap.clear();
	g_pResultSubcriber->m_pFlow->Truncate(0);

	m_pkgSend.PreparePackage(
			FTD_TID_ReqUserLogin,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqUserLoginField fieldLogin;
	memset(&fieldLogin, 0, sizeof(fieldLogin));
	fieldLogin.UserID = "frontRes";
	fieldLogin.Password = "frontpd";
	FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);

	CFTDDisseminationField	fieldDissemination;
	printf("\t Flow count %d\n", g_pResultSubcriber->GetReceivedCount());
	fflush(stdout);
	fieldDissemination.SequenceSeries = g_pResultSubcriber->GetSequenceSeries();	// GetSequenceSeries();
	fieldDissemination.SequenceNo = g_pResultSubcriber->GetReceivedCount();			// GetReceivedCount();
	FTDC_ADD_FIELD(&m_pkgSend, &fieldDissemination);
	((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
	((CFTDCSession *)pSession)->RegisterSubscriber(g_pResultSubcriber);
}
