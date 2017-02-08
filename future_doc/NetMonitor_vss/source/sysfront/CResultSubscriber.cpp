/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CResultSubscriber.cpp
///@brief	实现了订阅交易流水处理消息的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#include "CResultSubscriber.h"
#include "CListSession.h"
#include <iostream>
using namespace std;

extern CListSessionArray *g_pListSessionArray;
extern char g_mFlowPath[200];
extern list<CFTDCSession *> g_mListAllSession;

extern CFTDRspQryTradepeakField TradepeakField1;
extern CFTDRspQryTradepeakField TradepeakField2;

extern CFTDRtnSysTimeSyncField	g_sysTimeSyncField;

//////////////////////////////////////////////////////////////////////////
//add by feng.q
extern map<string, CFTDRspQryParticTradeOrderStatesField> g_mpPartiOrderCnt;
map<string, CFTDRtnParticTradeOrderStatesField> g_mapRtnPartiOrder;

//////////////////////////////////////////////////////////////////////////
#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pClnPackOutput;	// 数据包输出到文件
extern CLogger	*g_pQryPackOutput;
extern CLogger	*g_pEntPackOutput;
extern CLogger	*g_pFibPackOutput;
#endif
extern volatile int g_Count;

///主数据中心名：
CTypeObjectIDType g_DataCenter;

///交易前置报单负载统计：
extern map<int, CFTDRspQryFrontStatField> g_FrontStatMap;

///座席登录流水
list<CFTDRtnTradeUserLoginInfoField> g_TradeUserLoginList;

///用于将FTD域写入内存数据库的宏
#define ADDSRPACKAGETOMDB(x)													 \
	{																			 \
		CWriteableSys##x mdbfield;												 \
		CopySys##x##Entity(&mdbfield, &field) pMemoryDB->m_Sys##x##Factory->add( \
				&mdbfield,														 \
				NULL);															 \
	}

#define ADDCHGTOMDB(x)													  \
	{																	  \
		CWriteableSys##x mdbtfield;										  \
		CopySys##x##Entity(												  \
			&mdbtfield,													  \
			&sfield) pMemoryDB->m_Sys##x##Factory->add(&mdbtfield, NULL); \
	}

///用于处理流包的宏
#define HANDLESRPACKAGE(x)												\
	{																	\
		CFTDRtn##x##Field field;										\
		m_pkgSend.PreparePackage(										\
				FTD_TID_Rtn##x##Topic,									\
				FTDC_CHAIN_LAST,										\
				FTD_VERSION);											\
		CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator( \
				&CFTDRtn##x##Field::m_Describe);						\
		while (!itor.IsEnd())											\
		{																\
			itor.Retrieve(&field);										\
			ADDSRPACKAGETOMDB(x) FTDC_ADD_FIELD(&m_pkgSend, &field);	\
			itor.Next();												\
		}																\
																 \
		if (!m_reload)													\
		{																\
			g_pListSessionArray->SendPackage(&m_pkgSend, OBJ##x);		\
		}																\
	}

/*#define HANDLESRPACKAGE(x) \
{\
	g_Count++;\
	CFTDRtn##x##Field field; \
	m_pkgSend.PreparePackage(FTD_TID_Rtn##x##Topic, FTDC_CHAIN_LAST, FTD_VERSION); \
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field);\
	ADDSRPACKAGETOMDB(x);\
	if(!m_reload)\
		g_pListSessionArray->SendPackage(&m_pkgSend, OBJ##x); \
}*/

///用于处理流包的宏
#define RELOADSRPACKAGE(x)													 \
	{																		 \
		CFTDRtn##x##Field field;											 \
		CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(		 \
				&CFTDRtn##x##Field::m_Describe);							 \
		while (!itor.IsEnd())												 \
		{																	 \
			itor.Retrieve(&field);											 \
			ADDSRPACKAGETOMDB(x) itor.Next();								 \
			if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd()) \
			{																 \
				break;														 \
			}																 \
		}																	 \
	}

///针对INIT包处理的宏
#define HANDLEINITPACKAGE(x)											\
	{																	\
		CFTDRtn##x##Field field;										\
		CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator( \
				&CFTDRtn##x##Field::m_Describe);						\
		while (!itor.IsEnd())											\
		{																\
			itor.Retrieve(&field);										\
			ADDSRPACKAGETOMDB(x) itor.Next();							\
		}																\
	}

///针对PARTICIPANT,USER,CLIENT信息的宏：
#define HANDLEPUC(x)															\
	{																			\
		CFTDRtn##x##InitField sfield;											\
		CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(			\
				&CFTDRtn##x##InitField::m_Describe);							\
		while (!itor.IsEnd())													\
		{																		\
			itor.Retrieve(&sfield);												\
			CSys##x##Init *p##x##Init = pMemoryDB->m_Sys##x##InitFactory->		\
				findByOne(sfield.x##ID);										\
			if (sfield.OperationType == 2)										\
			{																	\
				if (p##x##Init)													\
				{																\
					pMemoryDB->m_Sys##x##InitFactory->remove(p##x##Init, NULL); \
				}																\
			}																	\
			else																\
			{																	\
				CWriteableSys##x##Init	mdbfield;								\
				CopySys##x##InitEntity(&mdbfield, &sfield);						\
				pMemoryDB->m_Sys##x##InitFactory->addOrUpdate(					\
						p##x##Init,												\
						&mdbfield,												\
						NULL,													\
						false);													\
			}																	\
																	 \
			if (!m_reload)														\
			{																	\
				m_pkgSend.PreparePackage(										\
						FTD_TID_Rtn##x##InitTopic,								\
						FTDC_CHAIN_LAST,										\
						FTD_VERSION);											\
				FTDC_ADD_FIELD(&m_pkgSend, &sfield);							\
				g_pListSessionArray->SendPackage(&m_pkgSend, OBJ##x);			\
			}																	\
																	 \
			itor.Next();														\
		}																		\
	}
				
CResultSubscriber::CResultSubscriber(void)
{
	m_pFlow = new CCachedFileFlow(
			"fibResultFlow",
			g_mFlowPath,
			true,
			100,
			32 * 1024);
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_reload = false;
	printf("----- CResultSubscriber Reload Begin -----\n");
	fflush(stdout);
	ReLoad();
	printf("-----  CResultSubscriber Reload End  -----\n");
	fflush(stdout);
}

CResultSubscriber::~CResultSubscriber(void)
{
	delete m_pFlow;
}

void CResultSubscriber::SetCommPhaseNo(WORD wCommPhaseNo)
{
}

WORD CResultSubscriber::GetSequenceSeries(void) //流编号
{
	return 2;
}

DWORD CResultSubscriber::GetReceivedCount(void) //收到的包个数
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	return m_pFlow->GetCount();
}

void CResultSubscriber::HandleMessage(CFTDCPackage *pFTDCPackage)
{
#ifdef PACKAGE_OUTPUT
	pFTDCPackage->OutputHeader(g_pFibPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pFibPackOutput);
#endif
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_RtnInvalidateOrderTopic:
			HANDLESRPACKAGE(InvalidateOrder)
			/*		{
			CFTDRtnInvalidateOrderField field; 
			m_pkgSend.PreparePackage(FTD_TID_RtnInvalidateOrderTopic, FTDC_CHAIN_LAST, FTD_VERSION);
			CNamedFieldIterator itor= pFTDCPackage->GetNamedFieldIterator(&CFTDRtnInvalidateOrderField::m_Describe);
			while (!itor.IsEnd())
			{
				itor.Retrieve(&field);
				ADDSRPACKAGETOMDB(InvalidateOrder);
				FTDC_ADD_FIELD(&m_pkgSend, &field);
				itor.Next();
			}
			if(!m_reload)
			{
				g_pListSessionArray->SendPackage(&m_pkgSend, OBJInvalidateOrder); 
			}
		}*/
			break;
		case FTD_TID_RtnOrderStatusTopic:
			HANDLESRPACKAGE(OrderStatus) break;
		case FTD_TID_RtnBargainOrderTopic:
			HANDLESRPACKAGE(BargainOrder) break;
		case FTD_TID_RtnInstPropertyTopic:
			HANDLEINITPACKAGE(InstProperty)
			//		OnRtnInstPropertyTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnMarginRateTopic:
			HANDLEINITPACKAGE(MarginRate) break;
		case FTD_TID_RtnPriceLimitTopic:
			HANDLEINITPACKAGE(PriceLimit) break;
		case FTD_TID_RtnPartPosiLimitTopic:
			HANDLEINITPACKAGE(PartPosiLimit) break;
		case FTD_TID_RtnClientPosiLimitTopic:
			HANDLEINITPACKAGE(ClientPosiLimit) break;
		case FTD_TID_RtnSpecialPosiLimitTopic:
			HANDLEINITPACKAGE(SpecialPosiLimit) break;
		case FTD_TID_RtnTransactionChgTopic:
			HANDLEINITPACKAGE(TransactionChg) break;
		case FTD_TID_RtnClientChgTopic:
			HANDLEINITPACKAGE(ClientChg) break;
		case FTD_TID_RtnPartClientChgTopic:
			HANDLEINITPACKAGE(PartClientChg) break;
		case FTD_TID_RtnPosiLimitChgTopic:
			//		HANDLEINITPACKAGE(PosiLimitChg)
			OnRtnPartPosiLimitChgTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnClientPosiLimitChgTopic:
			//		HANDLEINITPACKAGE(ClientPosiLimitChg)
			OnRtnClientPosiLimitChgTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnSpecPosiLimitChgTopic:
			//		HANDLEINITPACKAGE(SpecPosiLimitChg)
			OnRtnSpecPosiLimitChgTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnHedgeDetailChgTopic:
			//		HANDLEINITPACKAGE(HedgeDetailChg)
			{
				CFTDRtnHedgeDetailChgField	field;
				CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
						&CFTDRtnHedgeDetailChgField::m_Describe);
				while (!itor.IsEnd())
				{
					itor.Retrieve(&field);
					{
						CWriteableSysHedgeDetailChg mdbfield;
						CopySysHedgeDetailChgEntity(
							&mdbfield,
							&field) pMemoryDB->m_SysHedgeDetailChgFactory->add(
								&mdbfield,
								NULL);
					}

					itor.Next();
				}
			}

			break;
		case FTD_TID_RtnParticipantChgTopic:
			HANDLEINITPACKAGE(ParticipantChg) break;
		case FTD_TID_RtnMarginRateChgTopic:
			//		HANDLEINITPACKAGE(MarginRateChg)
			OnRtnMarginRateChgTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnPriceLimitChgTopic:
			OnRtnPriceLimitChgTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnUserIpChgTopic:
			HANDLEINITPACKAGE(UserIpChg);
			break;
		case FTD_TID_RtnParticipantInitTopic:
			HANDLEPUC(Participant);
			break;
		case FTD_TID_RtnUserInitTopic:
			HANDLEPUC(User);
			break;
		case FTD_TID_RtnClientInitTopic:
			OnRtnClientInitTopic(pFTDCPackage);
			//HANDLEPUC(Client);
			break;
		case FTD_TID_RspQryTradeUserLoginInfoTopic:
			OnRspQryTradeUserLoginInfo(pFTDCPackage);
			break;
		case FTD_TID_RtnTradeUserLoginInfoTopic:
			OnRtnTradeUserLoginInfo(pFTDCPackage);
			break;
		case FTD_TID_RspQryPartTradeTopic:
			OnRspQryPartTrade(pFTDCPackage);
			break;
		case FTD_TID_RspQryFrontStat:
			OnRspQryFrontStat(pFTDCPackage);
			break;

		///因为reload是应付sysfront重启，所以对于这种全局变量的情况必须做
				///因为unload是应付sysfibclient重启，所以对于全局变量无须去做
		case FTD_TID_RtnDataCenterChgTopic:
			OnRtnDataCenterChgTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnSysTimeSyncTopic:
			OnRtnSysTimeSyncTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnParticTradeOrderStatesTopic:
			//HANDLESRPACKAGE(ParticTradeOrderStates);
			OnRtnParticTradeOrderStatesTopic(pFTDCPackage);
			break;
		case FTD_TID_RtnInstrumentStatusTopic:
			HANDLESRPACKAGE(InstrumentStatus) break;
		case FTD_TID_RtnCurrTradingSegmentAttrTopic:
			HANDLESRPACKAGE(CurrTradingSegmentAttr) break;
		default:
			break;
	}

	pFTDCPackage->Push(FTDCHLEN);
	m_pFlow->Append(pFTDCPackage->Address(), pFTDCPackage->Length());
}

void CResultSubscriber::ReLoad(void)
{
	m_reload = true;

	CFlowReader srFlowReader;
	srFlowReader.AttachFlow(m_pFlow, 0);

	CFTDCPackage *pFTDCPackage = new CFTDCPackage;
	pFTDCPackage->ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	for (;;)
	{
		pFTDCPackage->Allocate(FTDC_PACKAGE_MAX_SIZE + FTDCHLEN);
		if (!srFlowReader.GetNext(pFTDCPackage))
		{
			break;
		}

		switch (pFTDCPackage->GetTID())
		{
			case FTD_TID_RtnInvalidateOrderTopic:
				RELOADSRPACKAGE(InvalidateOrder);
				break;
			case FTD_TID_RtnOrderStatusTopic:
				RELOADSRPACKAGE(OrderStatus);
				break;
			case FTD_TID_RtnBargainOrderTopic:
				RELOADSRPACKAGE(BargainOrder);
				break;
			case FTD_TID_RtnInstPropertyTopic:
				//			OnRtnInstPropertyTopic(pFTDCPackage);
				HANDLEINITPACKAGE(InstProperty) break;
			case FTD_TID_RtnMarginRateTopic:
				HANDLEINITPACKAGE(MarginRate) break;
			case FTD_TID_RtnPriceLimitTopic:
				HANDLEINITPACKAGE(PriceLimit) break;
			case FTD_TID_RtnPartPosiLimitTopic:
				HANDLEINITPACKAGE(PartPosiLimit) break;
			case FTD_TID_RtnClientPosiLimitTopic:
				HANDLEINITPACKAGE(ClientPosiLimit) break;
			case FTD_TID_RtnSpecialPosiLimitTopic:
				HANDLEINITPACKAGE(SpecialPosiLimit) break;
			case FTD_TID_RtnTransactionChgTopic:
				HANDLEINITPACKAGE(TransactionChg) break;
			case FTD_TID_RtnClientChgTopic:
				HANDLEINITPACKAGE(ClientChg) break;
			case FTD_TID_RtnPartClientChgTopic:
				HANDLEINITPACKAGE(PartClientChg) break;
			case FTD_TID_RtnPosiLimitChgTopic:
				OnRtnPartPosiLimitChgTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnClientPosiLimitChgTopic:
				OnRtnClientPosiLimitChgTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnSpecPosiLimitChgTopic:
				OnRtnSpecPosiLimitChgTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnHedgeDetailChgTopic:
				HANDLEINITPACKAGE(HedgeDetailChg) break;
			case FTD_TID_RtnMarginRateChgTopic:
				OnRtnMarginRateChgTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnPriceLimitChgTopic:
				OnRtnPriceLimitChgTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnUserIpChgTopic:
				HANDLEINITPACKAGE(UserIpChg) break;
			case FTD_TID_RtnParticipantInitTopic:
				HANDLEPUC(Participant);
				break;
			case FTD_TID_RtnUserInitTopic:
				HANDLEPUC(User);
				break;
			case FTD_TID_RtnClientInitTopic:
				//HANDLEPUC(Client);
				OnRtnClientInitTopic(pFTDCPackage);
				break;
			case FTD_TID_RspQryTradeUserLoginInfoTopic:
				OnRspQryTradeUserLoginInfo(pFTDCPackage);
				break;
			case FTD_TID_RtnTradeUserLoginInfoTopic:
				OnRtnTradeUserLoginInfo(pFTDCPackage);
				break;
			case FTD_TID_RspQryPartTradeTopic:
				OnRspQryPartTrade(pFTDCPackage);
				break;
			case FTD_TID_RspQryFrontStat:
				OnRspQryFrontStat(pFTDCPackage);
				break;
			case FTD_TID_RtnDataCenterChgTopic:
				OnRtnDataCenterChgTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnSysTimeSyncTopic:
				OnRtnSysTimeSyncTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnParticTradeOrderStatesTopic:
				OnRtnParticTradeOrderStatesTopic(pFTDCPackage);
				break;
			case FTD_TID_RtnInstrumentStatusTopic:
				RELOADSRPACKAGE(InstrumentStatus);
				break;
			case FTD_TID_RtnCurrTradingSegmentAttrTopic:
				RELOADSRPACKAGE(CurrTradingSegmentAttr);
				break;
			default:
				break;
		}
	}

	m_reload = false;
}

void CResultSubscriber::UnLoad(void)
{
	delete m_pFlow;
	m_pFlow = new CCachedFileFlow(
			"fibResultFlow",
			g_mFlowPath,
			false,
			10000,
			32 * 1024);
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

	//	pMemoryDB->m_SysClientInitFactory->clearAll();
	pMemoryDB->m_SysTradeUserLoginInfoFactory->clearAll();
	pMemoryDB->m_SysPartTradeFactory->clearAll();
	pMemoryDB->m_SysInstrumentStatusFactory->clearAll();
	pMemoryDB->m_SysCurrTradingSegmentAttrFactory->clearAll();
}

void CResultSubscriber::OnRtnInstPropertyTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnInstPropertyField field;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnInstPropertyField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);
		{
			CSysInstProperty *pEvent = pMemoryDB->m_SysInstPropertyFactory->
				findByOne(field.InstrumentID);
			CWriteableSysInstProperty mdbfield;
			CopySysInstPropertyEntity(&mdbfield, &field);
			pMemoryDB->m_SysInstPropertyFactory->addOrUpdate(
					pEvent,
					&mdbfield,
					NULL,
					false);
		}

		itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}
}

void CResultSubscriber::OnRtnClientInitTopic(CFTDCPackage *pFTDCPackage)
{
	{																			
		CFTDRtnClientInitField sfield;											
		CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(			
			&CFTDRtnClientInitField::m_Describe);							
		while (!itor.IsEnd())													
		{																		
			itor.Retrieve(&sfield);												
			CSysClientInit *pClientInit = pMemoryDB->m_SysClientInitFactory->findByOne(sfield.ClientID);										
			if (sfield.OperationType == 2)										
			{																	
				if (pClientInit)													
				{																
					pMemoryDB->m_SysClientInitFactory->remove(pClientInit, NULL); 
				}																
			}																	
			else																
			{																	
				CWriteableSysClientInit	mdbfield;								
				CopySysClientInitEntity(&mdbfield, &sfield);						
				pMemoryDB->m_SysClientInitFactory->addOrUpdate(					
				pClientInit,												
				&mdbfield,												
				NULL,													
				false);													
			}																	
	
			if (!m_reload)														
			{					
				CFTDRtnClientInfoField tfield;
				CopySysClientInitEntity(&tfield, &sfield);												
				m_pkgSend.PreparePackage(										
				FTD_TID_RtnClientInfoTopic,								
				FTDC_CHAIN_LAST,										
				FTD_VERSION);											
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);							
				g_pListSessionArray->SendPackage(&m_pkgSend, OBJClient);			
			}																	
	
			itor.Next();														
		}																		
	}
}
list<CUserIDType> userId_List;

///用户登录处理
void CResultSubscriber::OnRspQryTradeUserLoginInfo(CFTDCPackage *pFTDCPackage)
{
	CFTDRspQryTradeUserLoginInfoField field;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRspQryTradeUserLoginInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDRtnTradeUserLoginInfoField	theField;
		CopySysTradeUserLoginInfoEntity(&theField, &field);
		g_TradeUserLoginList.push_back(theField);
		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnTradeUserLoginInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &theField);

			list<CFTDCSession *>::iterator	it;
			for (it = g_mListAllSession.begin();
				 it != g_mListAllSession.end();
				 it++)
			{
				(*it)->SendRequestPackage(&m_pkgSend);
				m_pkgSend.Pop(FTDCHLEN);
			}
		}

		//		cout<<"login:    "<<field.ParticipantID<<"--"<<field.UserID<<endl;
		{
			CSysTradeUserLoginInfo	*pTradeUserLoginInfo = pMemoryDB->
				m_SysTradeUserLoginInfoFactory->findByOne(
						field.ParticipantID,
						field.UserID);
			if (pTradeUserLoginInfo)
			{
				list<CUserIDType>::iterator it = find(
						userId_List.begin(),
						userId_List.end(),
						field.UserID);
				if (it != userId_List.end())
				{
					userId_List.erase(it);
				}
			}
			else
			{
				CWriteableSysTradeUserLoginInfo mdbfield;
				CopySysTradeUserLoginInfoEntity(&mdbfield, &field);
				pMemoryDB->m_SysTradeUserLoginInfoFactory->add(&mdbfield);
			}
		}

		itor.Next();
	}
}

///用户登出处理
void CResultSubscriber::OnRtnTradeUserLoginInfo(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnTradeUserLoginInfoField	field;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnTradeUserLoginInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDRtnTradeUserLoginInfoField	theField;
		CopySysTradeUserLoginInfoEntity(&theField, &field);
		g_TradeUserLoginList.push_back(theField);
		if (!m_reload)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnTradeUserLoginInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &theField);

			list<CFTDCSession *>::iterator	it;
			for (it = g_mListAllSession.begin();
				 it != g_mListAllSession.end();
				 it++)
			{
				(*it)->SendRequestPackage(&m_pkgSend);
				m_pkgSend.Pop(FTDCHLEN);
			}
		}

		//		cout<<"logout:    "<<field.ParticipantID<<"--"<<field.UserID<<endl;
		{
			CSysTradeUserLoginInfo	*pTradeUserLoginInfo = pMemoryDB->
				m_SysTradeUserLoginInfoFactory->findByOne(
						field.ParticipantID,
						field.UserID);
			if (pTradeUserLoginInfo)
			{
				pMemoryDB->m_SysTradeUserLoginInfoFactory->remove(
						pTradeUserLoginInfo);
			}
			else
			{
				userId_List.push_back(field.UserID);
			}
		}

		itor.Next();
	}
}

void CResultSubscriber::OnRspQryPartTrade(CFTDCPackage *pFTDCPackage)
{
	CFTDRspQryPartTradeField field;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRspQryPartTradeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);
		{
			CSysPartTrade *pPartTrade = pMemoryDB->m_SysPartTradeFactory->
				findByOne(field.ParticipantID, field.InstrumentID);
			CWriteableSysPartTrade	mdbfield;
			if (pPartTrade)
			{
				pMemoryDB->m_SysPartTradeFactory->retrieve(
						pPartTrade,
						&mdbfield);
				mdbfield.TotalNegativeOrder += field.TotalNegativeOrder;
				mdbfield.TotalNegativePosi += field.TotalNegativePosi;
				mdbfield.TotalNegativeTrade += field.TotalNegativeTrade;
				mdbfield.TotalPositiveOrder += field.TotalPositiveOrder;
				mdbfield.TotalPositivePosi += field.TotalPositivePosi;
				mdbfield.TotalPositiveTrade += field.TotalPositiveTrade;
			}
			else
			{
				CopySysPartTradeEntity(&mdbfield, &field);
			}

			pMemoryDB->m_SysPartTradeFactory->addOrUpdate(
					pPartTrade,
					&mdbfield,
					NULL,
					false);
		}

		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}

		itor.Next();
	}
}

void CResultSubscriber::OnRtnMarginRateChgTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnMarginRateChgField sfield;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnMarginRateChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		ADDCHGTOMDB(MarginRateChg);

		CSysMarginRate	*pMarginRate = pMemoryDB->m_SysMarginRateFactory->
			findByOne(
				sfield.InstrumentID,
				sfield.ParticipantID,
				sfield.TradingRole);
		if (sfield.OperationType == 2)
		{
			if (pMarginRate)
			{
				pMemoryDB->m_SysMarginRateFactory->remove(pMarginRate, NULL);
			}
		}
		else
		{
			CWriteableSysMarginRate mdbfield;
			mdbfield.ActionDate = sfield.ActionDate;
			mdbfield.ActionTime = sfield.ActionTime;
			mdbfield.InstrumentID = sfield.InstrumentID;
			mdbfield.ParticipantID = sfield.ParticipantID;
			mdbfield.TradingRole = sfield.TradingRole;
			mdbfield.HedgeFlag = sfield.HedgeFlag;
			mdbfield.ValueMode = sfield.ValueMode;
			mdbfield.LongMarginRatio = sfield.LongMarginRatio;
			mdbfield.ShortMarginRatio = sfield.ShortMarginRatio;

			pMemoryDB->m_SysMarginRateFactory->addOrUpdate(
					pMarginRate,
					&mdbfield,
					NULL,
					false);
		}

		itor.Next();
	}
}

void CResultSubscriber::OnRtnPriceLimitChgTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnPriceLimitChgField sfield;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnPriceLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		CSysPriceLimit	*pPriceLimit = pMemoryDB->m_SysPriceLimitFactory->
			findByOne(sfield.InstrumentID);
		if (sfield.OperationType == 2)
		{
			if (pPriceLimit)
			{
				pMemoryDB->m_SysPriceLimitFactory->remove(pPriceLimit, NULL);
			}
		}
		else
		{
			CWriteableSysPriceLimit mdbfield;
			mdbfield.ActionDate = sfield.ActionDate;
			mdbfield.ActionTime = sfield.ActionTime;
			mdbfield.InstrumentID = sfield.InstrumentID;
			mdbfield.ValueMode = sfield.ValueMode;
			mdbfield.RoundingMode = sfield.RoundingMode;
			mdbfield.UpperLimitPrice = sfield.UpperLimitPrice;
			mdbfield.LowerLimitPrice = sfield.LowerLimitPrice;

			pMemoryDB->m_SysPriceLimitFactory->addOrUpdate(
					pPriceLimit,
					&mdbfield,
					NULL,
					false);
		}

		itor.Next();
	}
}

void CResultSubscriber::OnRtnPartPosiLimitChgTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnPosiLimitChgField sfield;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnPosiLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		ADDCHGTOMDB(PosiLimitChg);

		CSysPartPosiLimit *pPartPosiLimit = pMemoryDB->
			m_SysPartPosiLimitFactory->findByOne(
					sfield.InstrumentID,
					sfield.ParticipantID);
		if (sfield.OperationType == 2)
		{
			if (pPartPosiLimit)
			{
				pMemoryDB->m_SysPartPosiLimitFactory->remove(
						pPartPosiLimit,
						NULL);
			}
		}
		else
		{
			CWriteableSysPartPosiLimit	mdbfield;
			mdbfield.ActionDate = sfield.ActionDate;
			mdbfield.ActionTime = sfield.ActionTime;
			mdbfield.InstrumentID = sfield.InstrumentID;
			mdbfield.ParticipantID = sfield.ParticipantID;
			mdbfield.TradingRole = sfield.TradingRole;
			mdbfield.StartTotalPosition = sfield.StartTotalPosition;
			mdbfield.ValueMode = sfield.ValueMode;
			mdbfield.LongPosLimit = sfield.LongPosLimit;
			mdbfield.ShortPosLimit = sfield.ShortPosLimit;

			pMemoryDB->m_SysPartPosiLimitFactory->addOrUpdate(
					pPartPosiLimit,
					&mdbfield,
					NULL,
					false);
		}

		itor.Next();
	}
}

void CResultSubscriber::OnRtnClientPosiLimitChgTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnClientPosiLimitChgField	sfield;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnClientPosiLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		ADDCHGTOMDB(ClientPosiLimitChg);

		CSysClientPosiLimit *pClientPosiLimit = pMemoryDB->
			m_SysClientPosiLimitFactory->findByOne(
					sfield.InstrumentID,
					sfield.ClientType);
		if (sfield.OperationType == 2)
		{
			if (pClientPosiLimit)
			{
				pMemoryDB->m_SysClientPosiLimitFactory->remove(
						pClientPosiLimit,
						NULL);
			}
		}
		else
		{
			CWriteableSysClientPosiLimit mdbfield;
			mdbfield.ActionDate = sfield.ActionDate;
			mdbfield.ActionTime = sfield.ActionTime;
			mdbfield.InstrumentID = sfield.InstrumentID;
			mdbfield.ClientType = sfield.ClientType;
			mdbfield.TradingRole = sfield.TradingRole;
			mdbfield.StartTotalPosition = sfield.StartTotalPosition;
			mdbfield.ValueMode = sfield.ValueMode;
			mdbfield.LongPosLimit = sfield.LongPosLimit;
			mdbfield.ShortPosLimit = sfield.ShortPosLimit;

			pMemoryDB->m_SysClientPosiLimitFactory->addOrUpdate(
					pClientPosiLimit,
					&mdbfield,
					NULL,
					false);
		}

		itor.Next();
	}
}

void CResultSubscriber::OnRtnSpecPosiLimitChgTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnSpecPosiLimitChgField sfield;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnSpecPosiLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		ADDCHGTOMDB(SpecPosiLimitChg);

		CSysSpecialPosiLimit *pSpecialPosiLimit = pMemoryDB->
			m_SysSpecialPosiLimitFactory->findByOne(
					sfield.InstrumentID,
					sfield.ClientID);
		if (sfield.OperationType == 2)
		{
			if (pSpecialPosiLimit)
			{
				pMemoryDB->m_SysSpecialPosiLimitFactory->remove(
						pSpecialPosiLimit,
						NULL);
			}
		}
		else
		{
			CWriteableSysSpecialPosiLimit mdbfield;
			mdbfield.ActionDate = sfield.ActionDate;
			mdbfield.ActionTime = sfield.ActionTime;
			mdbfield.InstrumentID = sfield.InstrumentID;
			mdbfield.ClientID = sfield.ClientID;
			mdbfield.TradingRole = sfield.TradingRole;
			mdbfield.StartTotalPosition = sfield.StartTotalPosition;
			mdbfield.ValueMode = sfield.ValueMode;
			mdbfield.LongPosLimit = sfield.LongPosLimit;
			mdbfield.ShortPosLimit = sfield.ShortPosLimit;

			pMemoryDB->m_SysSpecialPosiLimitFactory->addOrUpdate(
					pSpecialPosiLimit,
					&mdbfield,
					NULL,
					false);
		}

		itor.Next();
	}
}

void CResultSubscriber::OnRspQryFrontStat(CFTDCPackage *pFTDCPackage)
{
	CFTDRspQryFrontStatField sfield;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRspQryFrontStatField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		map<int, CFTDRspQryFrontStatField>::iterator itFront = g_FrontStatMap.
			find(sfield.FrontID);
		if (itFront == g_FrontStatMap.end())
		{
			CFTDRspQryFrontStatField tfield;
			CopySysFrontStatEntity(&tfield, &sfield);
			g_FrontStatMap[sfield.FrontID] = tfield;
		}
		else
		{
			CopySysFrontStatEntity(&((*itFront).second), &sfield);
		}

		itor.Next();
	}
}

void CResultSubscriber::OnRtnDataCenterChgTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnDataCenterChgField sfield;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnDataCenterChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		{
			g_DataCenter = sfield.DataCenterID;

			///因为front重启客户端需要重连，那么只在连的时候告诉他们最终主数据中心即可:
			if (!m_reload)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RtnDataCenterChgTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &sfield);

				list<CFTDCSession *>::iterator	it;
				for (it = g_mListAllSession.begin();
					 it != g_mListAllSession.end();
					 it++)
				{
					(*it)->SendRequestPackage(&m_pkgSend);
					m_pkgSend.Pop(FTDCHLEN);
				}
			}
		}

		itor.Next();
	}
}

void CResultSubscriber::OnRtnSysTimeSyncTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnSysTimeSyncField sfield;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnSysTimeSyncField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		g_sysTimeSyncField.MonDate = sfield.MonDate;
		g_sysTimeSyncField.MonTime = sfield.MonTime;
	}
}

void CResultSubscriber::OnRtnParticTradeOrderStatesTopic(
	CFTDCPackage *pFTDCPackage)
{
	CFTDRtnParticTradeOrderStatesField	field;
	m_pkgSend.PreparePackage(
			FTD_TID_RtnParticTradeOrderStatesTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnParticTradeOrderStatesField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		if (field.StaticWidth < 1)
		{
			field.StaticWidth = 1;
		}

		string	strPi = field.ParticipantID.getValue();
		strPi.append(":");
		strPi.append(field.UserID.getValue());

		//map<string, CFTDRspQryParticTradeOrderStatesField>
		if (g_mpPartiOrderCnt.find(strPi) == g_mpPartiOrderCnt.end())
		{
			CFTDRspQryParticTradeOrderStatesField &tField = g_mpPartiOrderCnt[
				strPi];

			memset(&tField, 0, sizeof(tField));

			tField.ParticipantID = field.ParticipantID;
			tField.UserID = field.UserID;
			tField.FrontID = field.FrontID;
			tField.MonDate = field.MonDate;
			tField.MonTime = field.MonTime;
		}

		//统计会员报单
		{
			CFTDRspQryParticTradeOrderStatesField &tField = g_mpPartiOrderCnt[
				strPi];
			tField.OrderCount += field.OrderCount;
			tField.CancleCount += field.CancleCount;
			tField.TradeCount += field.TradeCount;
			tField.TradeMoney += field.TradeMoney;

			if (tField.OrderCntMax < field.OrderCount)
			{
				tField.OrderCntMax = field.OrderCount;
			}

			if (tField.CancleCntMax < field.CancleCount)
			{
				tField.CancleCntMax = field.CancleCount;
			}

			if (tField.QueryCntMax < field.QueryCount)
			{
				tField.QueryCntMax = field.QueryCount;
			}

			if (tField.TradeCntMax < field.TradeCount)
			{
				tField.TradeCntMax = field.TradeCount;
			}

			if (tField.TradeMoneyMax < field.TradeMoney)
			{
				tField.TradeMoneyMax = field.TradeMoney;
			}
		}

		//更新会员席位的最后一个交易数据
		{
			CFTDRtnParticTradeOrderStatesField	&rtnLatstofUser =
				g_mapRtnPartiOrder[strPi];
			CopyRtnParticTradeOrderStatesEntity(&rtnLatstofUser, &field);
			rtnLatstofUser.StaticWidth = 0;
		}

		CSysParticTradeOrderStates	*pPartiTime = pMemoryDB->
			m_SysParticTradeOrderStatesFactory->findByOne(
					field.ParticipantID,
					field.UserID,
					field.MonDate,
					field.MonTime);

		if (pPartiTime == NULL)
		{
			CWriteableSysParticTradeOrderStates mdbfield;
			CopySysParticTradeOrderStatesEntity(&mdbfield, &field);
			pMemoryDB->m_SysParticTradeOrderStatesFactory->add(&mdbfield, NULL);
		}
		else
		{
			CWriteableSysParticTradeOrderStates mdbfield;
			CopySysParticTradeOrderStatesEntity(&mdbfield, pPartiTime);

			mdbfield.OrderCount += field.OrderCount;
			mdbfield.CancleCount += field.CancleCount;
			mdbfield.TradeCount += field.TradeCount;
			mdbfield.TradeMoney += field.TradeMoney;

			if (pPartiTime->OrderCntMax < field.OrderCntMax)
			{
				mdbfield.OrderCntMax = field.OrderCntMax;
			}

			if (pPartiTime->CancleCntMax < field.CancleCntMax)
			{
				mdbfield.CancleCntMax = field.CancleCntMax;
			}

			if (pPartiTime->QueryCntMax < field.QueryCntMax)
			{
				mdbfield.QueryCntMax = field.QueryCntMax;
			}

			if (pPartiTime->TradeCntMax < field.TradeCntMax)
			{
				mdbfield.TradeCntMax = field.TradeCntMax;
			}

			if (pPartiTime->TradeMoneyMax < field.TradeMoneyMax)
			{
				mdbfield.TradeMoneyMax = field.TradeMoneyMax;
			}

			pMemoryDB->m_SysParticTradeOrderStatesFactory->update(
					pPartiTime,
					&mdbfield,
					NULL,
					false);
		}

		FTDC_ADD_FIELD(&m_pkgSend, &field);
		itor.Next();
	}

	if (!m_reload)
	{
		g_pListSessionArray->SendPackage(&m_pkgSend, OBJParticTradeOrderStates);
	}
}
