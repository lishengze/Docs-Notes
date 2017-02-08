/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file CMemoryDB.cpp
///@brief实现了类CMemoryDB
///@history 
///20050824	王肇东		创建该文件
///20120111 江鹏		NT-0163 kernel命令行增加指定用户密码参数
/////////////////////////////////////////////////////////////////////////

#include "CMemoryDB.h"
#include <map>
#include <string>
using namespace std;

#define MEMORYDB_ID			0
#define MAX_TABLE_COUNT		300				///引导块中每块放置的内存数据库表或者索引的数量

CMemoryDB::CMemoryDB(void)
{
	m_ExchangeDataSyncStatusFactory=NULL;
	m_SGDataSyncStatusFactory=NULL;
	m_CurrentTimeFactory=NULL;
	m_DataCenterDescFactory=NULL;
	m_ExchangeFactory=NULL;
	m_SettlementGroupFactory=NULL;
	m_MarketFactory=NULL;
	m_MarketProductFactory=NULL;
	m_MarketProductGroupFactory=NULL;
	m_MdPubStatusFactory=NULL;
	m_MarketDataTopicFactory=NULL;
	m_PartTopicSubscribeFactory=NULL;
	m_ParticipantFactory=NULL;
	m_UserFactory=NULL;
	m_ClientFactory=NULL;
	m_UserIPFactory=NULL;
	m_PartClientFactory=NULL;
	m_ClearingTradingPartFactory=NULL;
	m_AliasDefineFactory=NULL;
	m_UserFunctionRightFactory=NULL;
	m_AccountFactory=NULL;
	m_UserCommFluxFactory=NULL;
	m_MarketDataLogFactory=NULL;
	m_UserSessionFactory=NULL;
	m_MDSessionFactory=NULL;
	m_LoginInfoFactory=NULL;
	m_DepthMarketDataDetailFactory=NULL;
	m_InstrumentStatusDetailFactory=NULL;
	m_FrontStatusFactory=NULL;
	m_MaxLocalIDFactory=NULL;
	m_BulletinFactory=NULL;
	m_MarketDataModifyFactory=NULL;
	m_DepthMarketDataFactory=NULL;
	m_TopicMarketDataFactory=NULL;
	m_TopicMarketDataVersionFactory=NULL;
	m_InformationFactory=NULL;
	m_OrderCountFactory=NULL;
	m_InstrumentFactory=NULL;
	m_CombinationLegFactory=NULL;
	m_PartRoleAccountFactory=NULL;
	m_PartProductRoleFactory=NULL;
	m_PartProductRightFactory=NULL;
	m_PartInstrumentRightFactory=NULL;
	m_ClientProductRightFactory=NULL;
	m_ClientInstrumentRightFactory=NULL;
	m_PartClientProductRightFactory=NULL;
	m_PartClientInstrumentRightFactory=NULL;
	m_CurrProductPropertyFactory=NULL;
	m_CurrInstrumentPropertyFactory=NULL;
	m_CurrPriceBandingFactory=NULL;
	m_CurrMarginRateFactory=NULL;
	m_CurrMarginRateDetailFactory=NULL;
	m_CurrPartPosiLimitFactory=NULL;
	m_CurrPartPosiLimitDetailFactory=NULL;
	m_CurrClientPosiLimitFactory=NULL;
	m_CurrClientPosiLimitDetailFactory=NULL;
	m_CurrSpecialPosiLimitFactory=NULL;
	m_CurrSpecialPosiLimitDetailFactory=NULL;
	m_CurrHedgeRuleFactory=NULL;
	m_CurrTradingSegmentAttrFactory=NULL;
	m_CurrFuseFactory=NULL;
	m_TradingAccountFactory=NULL;
	m_BaseReserveAccountFactory=NULL;
	m_PartPositionFactory=NULL;
	m_ClientPositionFactory=NULL;
	m_HedgeVolumeFactory=NULL;
	m_RemainOrderFactory=NULL;
	m_MarketDataFactory=NULL;
	m_ClearingPartPositionFactory=NULL;
	m_InstrumentStatusFactory=NULL;
	m_OrderFactory=NULL;
	m_CombOrderFactory=NULL;
	m_OTCOrderFactory=NULL;
	m_ImplyOrderFactory=NULL;
	m_QuoteFactory=NULL;
	m_MBLMarketDataFactory=NULL;
	m_TradeFactory=NULL;
	m_FusePhaseFactory=NULL;
	m_ExecOrderFactory=NULL;
	m_UniPressureFactory=NULL;
	m_BasePriceLimitFactory=NULL;
	m_CreditLimitFactory=NULL;
	m_CurrInstrumentOptionFactory=NULL;
	m_ForceUserPassword.setValue(NULL);
}
	
CMemoryDB::~CMemoryDB(void)
{
	if (m_ExchangeDataSyncStatusFactory!=NULL)
		delete m_ExchangeDataSyncStatusFactory;
	if (m_SGDataSyncStatusFactory!=NULL)
		delete m_SGDataSyncStatusFactory;
	if (m_CurrentTimeFactory!=NULL)
		delete m_CurrentTimeFactory;
	if (m_DataCenterDescFactory!=NULL)
		delete m_DataCenterDescFactory;
	if (m_ExchangeFactory!=NULL)
		delete m_ExchangeFactory;
	if (m_SettlementGroupFactory!=NULL)
		delete m_SettlementGroupFactory;
	if (m_MarketFactory!=NULL)
		delete m_MarketFactory;
	if (m_MarketProductFactory!=NULL)
		delete m_MarketProductFactory;
	if (m_MarketProductGroupFactory!=NULL)
		delete m_MarketProductGroupFactory;
	if (m_MdPubStatusFactory!=NULL)
		delete m_MdPubStatusFactory;
	if (m_MarketDataTopicFactory!=NULL)
		delete m_MarketDataTopicFactory;
	if (m_PartTopicSubscribeFactory!=NULL)
		delete m_PartTopicSubscribeFactory;
	if (m_ParticipantFactory!=NULL)
		delete m_ParticipantFactory;
	if (m_UserFactory!=NULL)
		delete m_UserFactory;
	if (m_ClientFactory!=NULL)
		delete m_ClientFactory;
	if (m_UserIPFactory!=NULL)
		delete m_UserIPFactory;
	if (m_PartClientFactory!=NULL)
		delete m_PartClientFactory;
	if (m_ClearingTradingPartFactory!=NULL)
		delete m_ClearingTradingPartFactory;
	if (m_AliasDefineFactory!=NULL)
		delete m_AliasDefineFactory;
	if (m_UserFunctionRightFactory!=NULL)
		delete m_UserFunctionRightFactory;
	if (m_AccountFactory!=NULL)
		delete m_AccountFactory;
	if (m_UserCommFluxFactory!=NULL)
		delete m_UserCommFluxFactory;
	if (m_MarketDataLogFactory!=NULL)
		delete m_MarketDataLogFactory;
	if (m_UserSessionFactory!=NULL)
		delete m_UserSessionFactory;
	if (m_MDSessionFactory!=NULL)
		delete m_MDSessionFactory;
	if (m_LoginInfoFactory!=NULL)
		delete m_LoginInfoFactory;
	if (m_DepthMarketDataDetailFactory!=NULL)
		delete m_DepthMarketDataDetailFactory;
	if (m_InstrumentStatusDetailFactory!=NULL)
		delete m_InstrumentStatusDetailFactory;
	if (m_FrontStatusFactory!=NULL)
		delete m_FrontStatusFactory;
	if (m_MaxLocalIDFactory!=NULL)
		delete m_MaxLocalIDFactory;
	if (m_BulletinFactory!=NULL)
		delete m_BulletinFactory;
	if (m_MarketDataModifyFactory!=NULL)
		delete m_MarketDataModifyFactory;
	if (m_DepthMarketDataFactory!=NULL)
		delete m_DepthMarketDataFactory;
	if (m_TopicMarketDataFactory!=NULL)
		delete m_TopicMarketDataFactory;
	if (m_TopicMarketDataVersionFactory!=NULL)
		delete m_TopicMarketDataVersionFactory;
	if (m_InformationFactory!=NULL)
		delete m_InformationFactory;
	if (m_OrderCountFactory!=NULL)
		delete m_OrderCountFactory;
	if (m_InstrumentFactory!=NULL)
		delete m_InstrumentFactory;
	if (m_CombinationLegFactory!=NULL)
		delete m_CombinationLegFactory;
	if (m_PartRoleAccountFactory!=NULL)
		delete m_PartRoleAccountFactory;
	if (m_PartProductRoleFactory!=NULL)
		delete m_PartProductRoleFactory;
	if (m_PartProductRightFactory!=NULL)
		delete m_PartProductRightFactory;
	if (m_PartInstrumentRightFactory!=NULL)
		delete m_PartInstrumentRightFactory;
	if (m_ClientProductRightFactory!=NULL)
		delete m_ClientProductRightFactory;
	if (m_ClientInstrumentRightFactory!=NULL)
		delete m_ClientInstrumentRightFactory;
	if (m_PartClientProductRightFactory!=NULL)
		delete m_PartClientProductRightFactory;
	if (m_PartClientInstrumentRightFactory!=NULL)
		delete m_PartClientInstrumentRightFactory;
	if (m_CurrProductPropertyFactory!=NULL)
		delete m_CurrProductPropertyFactory;
	if (m_CurrInstrumentPropertyFactory!=NULL)
		delete m_CurrInstrumentPropertyFactory;
	if (m_CurrPriceBandingFactory!=NULL)
		delete m_CurrPriceBandingFactory;
	if (m_CurrMarginRateFactory!=NULL)
		delete m_CurrMarginRateFactory;
	if (m_CurrMarginRateDetailFactory!=NULL)
		delete m_CurrMarginRateDetailFactory;
	if (m_CurrPartPosiLimitFactory!=NULL)
		delete m_CurrPartPosiLimitFactory;
	if (m_CurrPartPosiLimitDetailFactory!=NULL)
		delete m_CurrPartPosiLimitDetailFactory;
	if (m_CurrClientPosiLimitFactory!=NULL)
		delete m_CurrClientPosiLimitFactory;
	if (m_CurrClientPosiLimitDetailFactory!=NULL)
		delete m_CurrClientPosiLimitDetailFactory;
	if (m_CurrSpecialPosiLimitFactory!=NULL)
		delete m_CurrSpecialPosiLimitFactory;
	if (m_CurrSpecialPosiLimitDetailFactory!=NULL)
		delete m_CurrSpecialPosiLimitDetailFactory;
	if (m_CurrHedgeRuleFactory!=NULL)
		delete m_CurrHedgeRuleFactory;
	if (m_CurrTradingSegmentAttrFactory!=NULL)
		delete m_CurrTradingSegmentAttrFactory;
	if (m_CurrFuseFactory!=NULL)
		delete m_CurrFuseFactory;
	if (m_TradingAccountFactory!=NULL)
		delete m_TradingAccountFactory;
	if (m_BaseReserveAccountFactory!=NULL)
		delete m_BaseReserveAccountFactory;
	if (m_PartPositionFactory!=NULL)
		delete m_PartPositionFactory;
	if (m_ClientPositionFactory!=NULL)
		delete m_ClientPositionFactory;
	if (m_HedgeVolumeFactory!=NULL)
		delete m_HedgeVolumeFactory;
	if (m_RemainOrderFactory!=NULL)
		delete m_RemainOrderFactory;
	if (m_MarketDataFactory!=NULL)
		delete m_MarketDataFactory;
	if (m_ClearingPartPositionFactory!=NULL)
		delete m_ClearingPartPositionFactory;
	if (m_InstrumentStatusFactory!=NULL)
		delete m_InstrumentStatusFactory;
	if (m_OrderFactory!=NULL)
		delete m_OrderFactory;
	if (m_CombOrderFactory!=NULL)
		delete m_CombOrderFactory;
	if (m_OTCOrderFactory!=NULL)
		delete m_OTCOrderFactory;
	if (m_ImplyOrderFactory!=NULL)
		delete m_ImplyOrderFactory;
	if (m_QuoteFactory!=NULL)
		delete m_QuoteFactory;
	if (m_MBLMarketDataFactory!=NULL)
		delete m_MBLMarketDataFactory;
	if (m_TradeFactory!=NULL)
		delete m_TradeFactory;
	if (m_FusePhaseFactory!=NULL)
		delete m_FusePhaseFactory;
	if (m_ExecOrderFactory!=NULL)
		delete m_ExecOrderFactory;
	if (m_UniPressureFactory!=NULL)
		delete m_UniPressureFactory;
	if (m_BasePriceLimitFactory!=NULL)
		delete m_BasePriceLimitFactory;
	if (m_CreditLimitFactory!=NULL)
		delete m_CreditLimitFactory;
	if (m_CurrInstrumentOptionFactory!=NULL)
		delete m_CurrInstrumentOptionFactory;
}
	
int CMemoryDB::isA(char *objectType)
{
	if (!strcmp(objectType,"CMemoryDB"))
		return 1;
	return CBaseObject::isA(objectType);
}

char *CMemoryDB::getType(void)
{
	return "CMemoryDB";
}

void CMemoryDB::output(CLogger *pLogger,int indent)
{
	CHECK_TYPE("CMemoryDB");
	pLogger->output(indent,0,"CMemoryDB:");
	if (m_ExchangeDataSyncStatusFactory!=NULL)
		m_ExchangeDataSyncStatusFactory->output(pLogger,indent+1);
	if (m_SGDataSyncStatusFactory!=NULL)
		m_SGDataSyncStatusFactory->output(pLogger,indent+1);
	if (m_CurrentTimeFactory!=NULL)
		m_CurrentTimeFactory->output(pLogger,indent+1);
	if (m_DataCenterDescFactory!=NULL)
		m_DataCenterDescFactory->output(pLogger,indent+1);
	if (m_ExchangeFactory!=NULL)
		m_ExchangeFactory->output(pLogger,indent+1);
	if (m_SettlementGroupFactory!=NULL)
		m_SettlementGroupFactory->output(pLogger,indent+1);
	if (m_MarketFactory!=NULL)
		m_MarketFactory->output(pLogger,indent+1);
	if (m_MarketProductFactory!=NULL)
		m_MarketProductFactory->output(pLogger,indent+1);
	if (m_MarketProductGroupFactory!=NULL)
		m_MarketProductGroupFactory->output(pLogger,indent+1);
	if (m_MdPubStatusFactory!=NULL)
		m_MdPubStatusFactory->output(pLogger,indent+1);
	if (m_MarketDataTopicFactory!=NULL)
		m_MarketDataTopicFactory->output(pLogger,indent+1);
	if (m_PartTopicSubscribeFactory!=NULL)
		m_PartTopicSubscribeFactory->output(pLogger,indent+1);
	if (m_ParticipantFactory!=NULL)
		m_ParticipantFactory->output(pLogger,indent+1);
	if (m_UserFactory!=NULL)
		m_UserFactory->output(pLogger,indent+1);
	if (m_ClientFactory!=NULL)
		m_ClientFactory->output(pLogger,indent+1);
	if (m_UserIPFactory!=NULL)
		m_UserIPFactory->output(pLogger,indent+1);
	if (m_PartClientFactory!=NULL)
		m_PartClientFactory->output(pLogger,indent+1);
	if (m_ClearingTradingPartFactory!=NULL)
		m_ClearingTradingPartFactory->output(pLogger,indent+1);
	if (m_AliasDefineFactory!=NULL)
		m_AliasDefineFactory->output(pLogger,indent+1);
	if (m_UserFunctionRightFactory!=NULL)
		m_UserFunctionRightFactory->output(pLogger,indent+1);
	if (m_AccountFactory!=NULL)
		m_AccountFactory->output(pLogger,indent+1);
	if (m_UserCommFluxFactory!=NULL)
		m_UserCommFluxFactory->output(pLogger,indent+1);
	if (m_MarketDataLogFactory!=NULL)
		m_MarketDataLogFactory->output(pLogger,indent+1);
	if (m_UserSessionFactory!=NULL)
		m_UserSessionFactory->output(pLogger,indent+1);
	if (m_MDSessionFactory!=NULL)
		m_MDSessionFactory->output(pLogger,indent+1);
	if (m_LoginInfoFactory!=NULL)
		m_LoginInfoFactory->output(pLogger,indent+1);
	if (m_DepthMarketDataDetailFactory!=NULL)
		m_DepthMarketDataDetailFactory->output(pLogger,indent+1);
	if (m_InstrumentStatusDetailFactory!=NULL)
		m_InstrumentStatusDetailFactory->output(pLogger,indent+1);
	if (m_FrontStatusFactory!=NULL)
		m_FrontStatusFactory->output(pLogger,indent+1);
	if (m_MaxLocalIDFactory!=NULL)
		m_MaxLocalIDFactory->output(pLogger,indent+1);
	if (m_BulletinFactory!=NULL)
		m_BulletinFactory->output(pLogger,indent+1);
	if (m_MarketDataModifyFactory!=NULL)
		m_MarketDataModifyFactory->output(pLogger,indent+1);
	if (m_DepthMarketDataFactory!=NULL)
		m_DepthMarketDataFactory->output(pLogger,indent+1);
	if (m_TopicMarketDataFactory!=NULL)
		m_TopicMarketDataFactory->output(pLogger,indent+1);
	if (m_TopicMarketDataVersionFactory!=NULL)
		m_TopicMarketDataVersionFactory->output(pLogger,indent+1);
	if (m_InformationFactory!=NULL)
		m_InformationFactory->output(pLogger,indent+1);
	if (m_OrderCountFactory!=NULL)
		m_OrderCountFactory->output(pLogger,indent+1);
	if (m_InstrumentFactory!=NULL)
		m_InstrumentFactory->output(pLogger,indent+1);
	if (m_CombinationLegFactory!=NULL)
		m_CombinationLegFactory->output(pLogger,indent+1);
	if (m_PartRoleAccountFactory!=NULL)
		m_PartRoleAccountFactory->output(pLogger,indent+1);
	if (m_PartProductRoleFactory!=NULL)
		m_PartProductRoleFactory->output(pLogger,indent+1);
	if (m_PartProductRightFactory!=NULL)
		m_PartProductRightFactory->output(pLogger,indent+1);
	if (m_PartInstrumentRightFactory!=NULL)
		m_PartInstrumentRightFactory->output(pLogger,indent+1);
	if (m_ClientProductRightFactory!=NULL)
		m_ClientProductRightFactory->output(pLogger,indent+1);
	if (m_ClientInstrumentRightFactory!=NULL)
		m_ClientInstrumentRightFactory->output(pLogger,indent+1);
	if (m_PartClientProductRightFactory!=NULL)
		m_PartClientProductRightFactory->output(pLogger,indent+1);
	if (m_PartClientInstrumentRightFactory!=NULL)
		m_PartClientInstrumentRightFactory->output(pLogger,indent+1);
	if (m_CurrProductPropertyFactory!=NULL)
		m_CurrProductPropertyFactory->output(pLogger,indent+1);
	if (m_CurrInstrumentPropertyFactory!=NULL)
		m_CurrInstrumentPropertyFactory->output(pLogger,indent+1);
	if (m_CurrPriceBandingFactory!=NULL)
		m_CurrPriceBandingFactory->output(pLogger,indent+1);
	if (m_CurrMarginRateFactory!=NULL)
		m_CurrMarginRateFactory->output(pLogger,indent+1);
	if (m_CurrMarginRateDetailFactory!=NULL)
		m_CurrMarginRateDetailFactory->output(pLogger,indent+1);
	if (m_CurrPartPosiLimitFactory!=NULL)
		m_CurrPartPosiLimitFactory->output(pLogger,indent+1);
	if (m_CurrPartPosiLimitDetailFactory!=NULL)
		m_CurrPartPosiLimitDetailFactory->output(pLogger,indent+1);
	if (m_CurrClientPosiLimitFactory!=NULL)
		m_CurrClientPosiLimitFactory->output(pLogger,indent+1);
	if (m_CurrClientPosiLimitDetailFactory!=NULL)
		m_CurrClientPosiLimitDetailFactory->output(pLogger,indent+1);
	if (m_CurrSpecialPosiLimitFactory!=NULL)
		m_CurrSpecialPosiLimitFactory->output(pLogger,indent+1);
	if (m_CurrSpecialPosiLimitDetailFactory!=NULL)
		m_CurrSpecialPosiLimitDetailFactory->output(pLogger,indent+1);
	if (m_CurrHedgeRuleFactory!=NULL)
		m_CurrHedgeRuleFactory->output(pLogger,indent+1);
	if (m_CurrTradingSegmentAttrFactory!=NULL)
		m_CurrTradingSegmentAttrFactory->output(pLogger,indent+1);
	if (m_CurrFuseFactory!=NULL)
		m_CurrFuseFactory->output(pLogger,indent+1);
	if (m_TradingAccountFactory!=NULL)
		m_TradingAccountFactory->output(pLogger,indent+1);
	if (m_BaseReserveAccountFactory!=NULL)
		m_BaseReserveAccountFactory->output(pLogger,indent+1);
	if (m_PartPositionFactory!=NULL)
		m_PartPositionFactory->output(pLogger,indent+1);
	if (m_ClientPositionFactory!=NULL)
		m_ClientPositionFactory->output(pLogger,indent+1);
	if (m_HedgeVolumeFactory!=NULL)
		m_HedgeVolumeFactory->output(pLogger,indent+1);
	if (m_RemainOrderFactory!=NULL)
		m_RemainOrderFactory->output(pLogger,indent+1);
	if (m_MarketDataFactory!=NULL)
		m_MarketDataFactory->output(pLogger,indent+1);
	if (m_ClearingPartPositionFactory!=NULL)
		m_ClearingPartPositionFactory->output(pLogger,indent+1);
	if (m_InstrumentStatusFactory!=NULL)
		m_InstrumentStatusFactory->output(pLogger,indent+1);
	if (m_OrderFactory!=NULL)
		m_OrderFactory->output(pLogger,indent+1);
	if (m_CombOrderFactory!=NULL)
		m_CombOrderFactory->output(pLogger,indent+1);
	if (m_OTCOrderFactory!=NULL)
		m_OTCOrderFactory->output(pLogger,indent+1);
	if (m_ImplyOrderFactory!=NULL)
		m_ImplyOrderFactory->output(pLogger,indent+1);
	if (m_QuoteFactory!=NULL)
		m_QuoteFactory->output(pLogger,indent+1);
	if (m_MBLMarketDataFactory!=NULL)
		m_MBLMarketDataFactory->output(pLogger,indent+1);
	if (m_TradeFactory!=NULL)
		m_TradeFactory->output(pLogger,indent+1);
	if (m_FusePhaseFactory!=NULL)
		m_FusePhaseFactory->output(pLogger,indent+1);
	if (m_ExecOrderFactory!=NULL)
		m_ExecOrderFactory->output(pLogger,indent+1);
	if (m_UniPressureFactory!=NULL)
		m_UniPressureFactory->output(pLogger,indent+1);
	if (m_BasePriceLimitFactory!=NULL)
		m_BasePriceLimitFactory->output(pLogger,indent+1);
	if (m_CreditLimitFactory!=NULL)
		m_CreditLimitFactory->output(pLogger,indent+1);
	if (m_CurrInstrumentOptionFactory!=NULL)
		m_CurrInstrumentOptionFactory->output(pLogger,indent+1);
}

int CMemoryDB::init(CConfig *pConfig,IMemoryAllocator *pAllocator,bool reuse)
{
	if(pAllocator == NULL)
	{
		pAllocator = new CNormalMemoryAllocator();
		pAllocator->init(reuse);
	}
	if(!reuse)
	{
		map<string,int> indexMap;
		pMem=new CFixMem(sizeof(TableStruct),MAX_TABLE_COUNT,pAllocator,false,MEMORYDB_ID);
		TableStruct* pStru = NULL;
		
		m_ExchangeDataSyncStatusFactory=new CExchangeDataSyncStatusFactory(pConfig,pAllocator,&indexMap);
		if (m_ExchangeDataSyncStatusFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"ExchangeDataSyncStatus");
		pStru->reuseID = m_ExchangeDataSyncStatusFactory->getReuseID();
				
		m_SGDataSyncStatusFactory=new CSGDataSyncStatusFactory(pConfig,pAllocator,&indexMap);
		if (m_SGDataSyncStatusFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SGDataSyncStatus");
		pStru->reuseID = m_SGDataSyncStatusFactory->getReuseID();
				
		m_CurrentTimeFactory=new CCurrentTimeFactory(pConfig,pAllocator,&indexMap);
		if (m_CurrentTimeFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CurrentTime");
		pStru->reuseID = m_CurrentTimeFactory->getReuseID();
				
		m_DataCenterDescFactory=new CDataCenterDescFactory(pConfig,pAllocator,&indexMap);
		if (m_DataCenterDescFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"DataCenterDesc");
		pStru->reuseID = m_DataCenterDescFactory->getReuseID();
				
		m_ExchangeFactory=new CExchangeFactory(pConfig,pAllocator,&indexMap);
		if (m_ExchangeFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"Exchange");
		pStru->reuseID = m_ExchangeFactory->getReuseID();
				
		m_SettlementGroupFactory=new CSettlementGroupFactory(pConfig,pAllocator,&indexMap);
		if (m_SettlementGroupFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SettlementGroup");
		pStru->reuseID = m_SettlementGroupFactory->getReuseID();
				
		m_MarketFactory=new CMarketFactory(pConfig,pAllocator,&indexMap);
		if (m_MarketFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"Market");
		pStru->reuseID = m_MarketFactory->getReuseID();
				
		m_MarketProductFactory=new CMarketProductFactory(pConfig,pAllocator,&indexMap);
		if (m_MarketProductFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"MarketProduct");
		pStru->reuseID = m_MarketProductFactory->getReuseID();
				
		m_MarketProductGroupFactory=new CMarketProductGroupFactory(pConfig,pAllocator,&indexMap);
		if (m_MarketProductGroupFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"MarketProductGroup");
		pStru->reuseID = m_MarketProductGroupFactory->getReuseID();
				
		m_MdPubStatusFactory=new CMdPubStatusFactory(pConfig,pAllocator,&indexMap);
		if (m_MdPubStatusFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"MdPubStatus");
		pStru->reuseID = m_MdPubStatusFactory->getReuseID();
				
		m_MarketDataTopicFactory=new CMarketDataTopicFactory(pConfig,pAllocator,&indexMap);
		if (m_MarketDataTopicFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"MarketDataTopic");
		pStru->reuseID = m_MarketDataTopicFactory->getReuseID();
				
		m_PartTopicSubscribeFactory=new CPartTopicSubscribeFactory(pConfig,pAllocator,&indexMap);
		if (m_PartTopicSubscribeFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"PartTopicSubscribe");
		pStru->reuseID = m_PartTopicSubscribeFactory->getReuseID();
				
		m_ParticipantFactory=new CParticipantFactory(pConfig,pAllocator,&indexMap);
		if (m_ParticipantFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"Participant");
		pStru->reuseID = m_ParticipantFactory->getReuseID();
				
		m_UserFactory=new CUserFactory(pConfig,pAllocator,&indexMap);
		if (m_UserFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"User");
		pStru->reuseID = m_UserFactory->getReuseID();
				
		m_ClientFactory=new CClientFactory(pConfig,pAllocator,&indexMap);
		if (m_ClientFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"Client");
		pStru->reuseID = m_ClientFactory->getReuseID();
				
		m_UserIPFactory=new CUserIPFactory(pConfig,pAllocator,&indexMap);
		if (m_UserIPFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"UserIP");
		pStru->reuseID = m_UserIPFactory->getReuseID();
				
		m_PartClientFactory=new CPartClientFactory(pConfig,pAllocator,&indexMap);
		if (m_PartClientFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"PartClient");
		pStru->reuseID = m_PartClientFactory->getReuseID();
				
		m_ClearingTradingPartFactory=new CClearingTradingPartFactory(pConfig,pAllocator,&indexMap);
		if (m_ClearingTradingPartFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"ClearingTradingPart");
		pStru->reuseID = m_ClearingTradingPartFactory->getReuseID();
				
		m_AliasDefineFactory=new CAliasDefineFactory(pConfig,pAllocator,&indexMap);
		if (m_AliasDefineFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"AliasDefine");
		pStru->reuseID = m_AliasDefineFactory->getReuseID();
				
		m_UserFunctionRightFactory=new CUserFunctionRightFactory(pConfig,pAllocator,&indexMap);
		if (m_UserFunctionRightFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"UserFunctionRight");
		pStru->reuseID = m_UserFunctionRightFactory->getReuseID();
				
		m_AccountFactory=new CAccountFactory(pConfig,pAllocator,&indexMap);
		if (m_AccountFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"Account");
		pStru->reuseID = m_AccountFactory->getReuseID();
				
		m_UserCommFluxFactory=new CUserCommFluxFactory(pConfig,pAllocator,&indexMap);
		if (m_UserCommFluxFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"UserCommFlux");
		pStru->reuseID = m_UserCommFluxFactory->getReuseID();
				
		m_MarketDataLogFactory=new CMarketDataLogFactory(pConfig,pAllocator,&indexMap);
		if (m_MarketDataLogFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"MarketDataLog");
		pStru->reuseID = m_MarketDataLogFactory->getReuseID();
				
		m_UserSessionFactory=new CUserSessionFactory(pConfig,pAllocator,&indexMap);
		if (m_UserSessionFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"UserSession");
		pStru->reuseID = m_UserSessionFactory->getReuseID();
				
		m_MDSessionFactory=new CMDSessionFactory(pConfig,pAllocator,&indexMap);
		if (m_MDSessionFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"MDSession");
		pStru->reuseID = m_MDSessionFactory->getReuseID();
				
		m_LoginInfoFactory=new CLoginInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_LoginInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"LoginInfo");
		pStru->reuseID = m_LoginInfoFactory->getReuseID();
				
		m_DepthMarketDataDetailFactory=new CDepthMarketDataDetailFactory(pConfig,pAllocator,&indexMap);
		if (m_DepthMarketDataDetailFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"DepthMarketDataDetail");
		pStru->reuseID = m_DepthMarketDataDetailFactory->getReuseID();
				
		m_InstrumentStatusDetailFactory=new CInstrumentStatusDetailFactory(pConfig,pAllocator,&indexMap);
		if (m_InstrumentStatusDetailFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"InstrumentStatusDetail");
		pStru->reuseID = m_InstrumentStatusDetailFactory->getReuseID();
				
		m_FrontStatusFactory=new CFrontStatusFactory(pConfig,pAllocator,&indexMap);
		if (m_FrontStatusFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"FrontStatus");
		pStru->reuseID = m_FrontStatusFactory->getReuseID();
				
		m_MaxLocalIDFactory=new CMaxLocalIDFactory(pConfig,pAllocator,&indexMap);
		if (m_MaxLocalIDFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"MaxLocalID");
		pStru->reuseID = m_MaxLocalIDFactory->getReuseID();
				
		m_BulletinFactory=new CBulletinFactory(pConfig,pAllocator,&indexMap);
		if (m_BulletinFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"Bulletin");
		pStru->reuseID = m_BulletinFactory->getReuseID();
				
		m_MarketDataModifyFactory=new CMarketDataModifyFactory(pConfig,pAllocator,&indexMap);
		if (m_MarketDataModifyFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"MarketDataModify");
		pStru->reuseID = m_MarketDataModifyFactory->getReuseID();
				
		m_DepthMarketDataFactory=new CDepthMarketDataFactory(pConfig,pAllocator,&indexMap);
		if (m_DepthMarketDataFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"DepthMarketData");
		pStru->reuseID = m_DepthMarketDataFactory->getReuseID();
				
		m_TopicMarketDataFactory=new CTopicMarketDataFactory(pConfig,pAllocator,&indexMap);
		if (m_TopicMarketDataFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"TopicMarketData");
		pStru->reuseID = m_TopicMarketDataFactory->getReuseID();
				
		m_TopicMarketDataVersionFactory=new CTopicMarketDataVersionFactory(pConfig,pAllocator,&indexMap);
		if (m_TopicMarketDataVersionFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"TopicMarketDataVersion");
		pStru->reuseID = m_TopicMarketDataVersionFactory->getReuseID();
				
		m_InformationFactory=new CInformationFactory(pConfig,pAllocator,&indexMap);
		if (m_InformationFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"Information");
		pStru->reuseID = m_InformationFactory->getReuseID();
				
		m_OrderCountFactory=new COrderCountFactory(pConfig,pAllocator,&indexMap);
		if (m_OrderCountFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"OrderCount");
		pStru->reuseID = m_OrderCountFactory->getReuseID();
				
		m_InstrumentFactory=new CInstrumentFactory(pConfig,pAllocator,&indexMap);
		if (m_InstrumentFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"Instrument");
		pStru->reuseID = m_InstrumentFactory->getReuseID();
				
		m_CombinationLegFactory=new CCombinationLegFactory(pConfig,pAllocator,&indexMap);
		if (m_CombinationLegFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CombinationLeg");
		pStru->reuseID = m_CombinationLegFactory->getReuseID();
				
		m_PartRoleAccountFactory=new CPartRoleAccountFactory(pConfig,pAllocator,&indexMap);
		if (m_PartRoleAccountFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"PartRoleAccount");
		pStru->reuseID = m_PartRoleAccountFactory->getReuseID();
				
		m_PartProductRoleFactory=new CPartProductRoleFactory(pConfig,pAllocator,&indexMap);
		if (m_PartProductRoleFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"PartProductRole");
		pStru->reuseID = m_PartProductRoleFactory->getReuseID();
				
		m_PartProductRightFactory=new CPartProductRightFactory(pConfig,pAllocator,&indexMap);
		if (m_PartProductRightFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"PartProductRight");
		pStru->reuseID = m_PartProductRightFactory->getReuseID();
				
		m_PartInstrumentRightFactory=new CPartInstrumentRightFactory(pConfig,pAllocator,&indexMap);
		if (m_PartInstrumentRightFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"PartInstrumentRight");
		pStru->reuseID = m_PartInstrumentRightFactory->getReuseID();
				
		m_ClientProductRightFactory=new CClientProductRightFactory(pConfig,pAllocator,&indexMap);
		if (m_ClientProductRightFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"ClientProductRight");
		pStru->reuseID = m_ClientProductRightFactory->getReuseID();
				
		m_ClientInstrumentRightFactory=new CClientInstrumentRightFactory(pConfig,pAllocator,&indexMap);
		if (m_ClientInstrumentRightFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"ClientInstrumentRight");
		pStru->reuseID = m_ClientInstrumentRightFactory->getReuseID();
				
		m_PartClientProductRightFactory=new CPartClientProductRightFactory(pConfig,pAllocator,&indexMap);
		if (m_PartClientProductRightFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"PartClientProductRight");
		pStru->reuseID = m_PartClientProductRightFactory->getReuseID();
				
		m_PartClientInstrumentRightFactory=new CPartClientInstrumentRightFactory(pConfig,pAllocator,&indexMap);
		if (m_PartClientInstrumentRightFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"PartClientInstrumentRight");
		pStru->reuseID = m_PartClientInstrumentRightFactory->getReuseID();
				
		m_CurrProductPropertyFactory=new CCurrProductPropertyFactory(pConfig,pAllocator,&indexMap);
		if (m_CurrProductPropertyFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CurrProductProperty");
		pStru->reuseID = m_CurrProductPropertyFactory->getReuseID();
				
		m_CurrInstrumentPropertyFactory=new CCurrInstrumentPropertyFactory(pConfig,pAllocator,&indexMap);
		if (m_CurrInstrumentPropertyFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CurrInstrumentProperty");
		pStru->reuseID = m_CurrInstrumentPropertyFactory->getReuseID();
				
		m_CurrPriceBandingFactory=new CCurrPriceBandingFactory(pConfig,pAllocator,&indexMap);
		if (m_CurrPriceBandingFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CurrPriceBanding");
		pStru->reuseID = m_CurrPriceBandingFactory->getReuseID();
				
		m_CurrMarginRateFactory=new CCurrMarginRateFactory(pConfig,pAllocator,&indexMap);
		if (m_CurrMarginRateFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CurrMarginRate");
		pStru->reuseID = m_CurrMarginRateFactory->getReuseID();
				
		m_CurrMarginRateDetailFactory=new CCurrMarginRateDetailFactory(pConfig,pAllocator,&indexMap);
		if (m_CurrMarginRateDetailFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CurrMarginRateDetail");
		pStru->reuseID = m_CurrMarginRateDetailFactory->getReuseID();
				
		m_CurrPartPosiLimitFactory=new CCurrPartPosiLimitFactory(pConfig,pAllocator,&indexMap);
		if (m_CurrPartPosiLimitFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CurrPartPosiLimit");
		pStru->reuseID = m_CurrPartPosiLimitFactory->getReuseID();
				
		m_CurrPartPosiLimitDetailFactory=new CCurrPartPosiLimitDetailFactory(pConfig,pAllocator,&indexMap);
		if (m_CurrPartPosiLimitDetailFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CurrPartPosiLimitDetail");
		pStru->reuseID = m_CurrPartPosiLimitDetailFactory->getReuseID();
				
		m_CurrClientPosiLimitFactory=new CCurrClientPosiLimitFactory(pConfig,pAllocator,&indexMap);
		if (m_CurrClientPosiLimitFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CurrClientPosiLimit");
		pStru->reuseID = m_CurrClientPosiLimitFactory->getReuseID();
				
		m_CurrClientPosiLimitDetailFactory=new CCurrClientPosiLimitDetailFactory(pConfig,pAllocator,&indexMap);
		if (m_CurrClientPosiLimitDetailFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CurrClientPosiLimitDetail");
		pStru->reuseID = m_CurrClientPosiLimitDetailFactory->getReuseID();
				
		m_CurrSpecialPosiLimitFactory=new CCurrSpecialPosiLimitFactory(pConfig,pAllocator,&indexMap);
		if (m_CurrSpecialPosiLimitFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CurrSpecialPosiLimit");
		pStru->reuseID = m_CurrSpecialPosiLimitFactory->getReuseID();
				
		m_CurrSpecialPosiLimitDetailFactory=new CCurrSpecialPosiLimitDetailFactory(pConfig,pAllocator,&indexMap);
		if (m_CurrSpecialPosiLimitDetailFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CurrSpecialPosiLimitDetail");
		pStru->reuseID = m_CurrSpecialPosiLimitDetailFactory->getReuseID();
				
		m_CurrHedgeRuleFactory=new CCurrHedgeRuleFactory(pConfig,pAllocator,&indexMap);
		if (m_CurrHedgeRuleFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CurrHedgeRule");
		pStru->reuseID = m_CurrHedgeRuleFactory->getReuseID();
				
		m_CurrTradingSegmentAttrFactory=new CCurrTradingSegmentAttrFactory(pConfig,pAllocator,&indexMap);
		if (m_CurrTradingSegmentAttrFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CurrTradingSegmentAttr");
		pStru->reuseID = m_CurrTradingSegmentAttrFactory->getReuseID();
				
		m_CurrFuseFactory=new CCurrFuseFactory(pConfig,pAllocator,&indexMap);
		if (m_CurrFuseFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CurrFuse");
		pStru->reuseID = m_CurrFuseFactory->getReuseID();
				
		m_TradingAccountFactory=new CTradingAccountFactory(pConfig,pAllocator,&indexMap);
		if (m_TradingAccountFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"TradingAccount");
		pStru->reuseID = m_TradingAccountFactory->getReuseID();
				
		m_BaseReserveAccountFactory=new CBaseReserveAccountFactory(pConfig,pAllocator,&indexMap);
		if (m_BaseReserveAccountFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"BaseReserveAccount");
		pStru->reuseID = m_BaseReserveAccountFactory->getReuseID();
				
		m_PartPositionFactory=new CPartPositionFactory(pConfig,pAllocator,&indexMap);
		if (m_PartPositionFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"PartPosition");
		pStru->reuseID = m_PartPositionFactory->getReuseID();
				
		m_ClientPositionFactory=new CClientPositionFactory(pConfig,pAllocator,&indexMap);
		if (m_ClientPositionFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"ClientPosition");
		pStru->reuseID = m_ClientPositionFactory->getReuseID();
				
		m_HedgeVolumeFactory=new CHedgeVolumeFactory(pConfig,pAllocator,&indexMap);
		if (m_HedgeVolumeFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"HedgeVolume");
		pStru->reuseID = m_HedgeVolumeFactory->getReuseID();
				
		m_RemainOrderFactory=new CRemainOrderFactory(pConfig,pAllocator,&indexMap);
		if (m_RemainOrderFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"RemainOrder");
		pStru->reuseID = m_RemainOrderFactory->getReuseID();
				
		m_MarketDataFactory=new CMarketDataFactory(pConfig,pAllocator,&indexMap);
		if (m_MarketDataFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"MarketData");
		pStru->reuseID = m_MarketDataFactory->getReuseID();
				
		m_ClearingPartPositionFactory=new CClearingPartPositionFactory(pConfig,pAllocator,&indexMap);
		if (m_ClearingPartPositionFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"ClearingPartPosition");
		pStru->reuseID = m_ClearingPartPositionFactory->getReuseID();
				
		m_InstrumentStatusFactory=new CInstrumentStatusFactory(pConfig,pAllocator,&indexMap);
		if (m_InstrumentStatusFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"InstrumentStatus");
		pStru->reuseID = m_InstrumentStatusFactory->getReuseID();
				
		m_OrderFactory=new COrderFactory(pConfig,pAllocator,&indexMap);
		if (m_OrderFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"Order");
		pStru->reuseID = m_OrderFactory->getReuseID();
				
		m_CombOrderFactory=new CCombOrderFactory(pConfig,pAllocator,&indexMap);
		if (m_CombOrderFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CombOrder");
		pStru->reuseID = m_CombOrderFactory->getReuseID();
				
		m_OTCOrderFactory=new COTCOrderFactory(pConfig,pAllocator,&indexMap);
		if (m_OTCOrderFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"OTCOrder");
		pStru->reuseID = m_OTCOrderFactory->getReuseID();
				
		m_ImplyOrderFactory=new CImplyOrderFactory(pConfig,pAllocator,&indexMap);
		if (m_ImplyOrderFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"ImplyOrder");
		pStru->reuseID = m_ImplyOrderFactory->getReuseID();
				
		m_QuoteFactory=new CQuoteFactory(pConfig,pAllocator,&indexMap);
		if (m_QuoteFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"Quote");
		pStru->reuseID = m_QuoteFactory->getReuseID();
				
		m_MBLMarketDataFactory=new CMBLMarketDataFactory(pConfig,pAllocator,&indexMap);
		if (m_MBLMarketDataFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"MBLMarketData");
		pStru->reuseID = m_MBLMarketDataFactory->getReuseID();
				
		m_TradeFactory=new CTradeFactory(pConfig,pAllocator,&indexMap);
		if (m_TradeFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"Trade");
		pStru->reuseID = m_TradeFactory->getReuseID();
				
		m_FusePhaseFactory=new CFusePhaseFactory(pConfig,pAllocator,&indexMap);
		if (m_FusePhaseFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"FusePhase");
		pStru->reuseID = m_FusePhaseFactory->getReuseID();
				
		m_ExecOrderFactory=new CExecOrderFactory(pConfig,pAllocator,&indexMap);
		if (m_ExecOrderFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"ExecOrder");
		pStru->reuseID = m_ExecOrderFactory->getReuseID();
				
		m_UniPressureFactory=new CUniPressureFactory(pConfig,pAllocator,&indexMap);
		if (m_UniPressureFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"UniPressure");
		pStru->reuseID = m_UniPressureFactory->getReuseID();
				
		m_BasePriceLimitFactory=new CBasePriceLimitFactory(pConfig,pAllocator,&indexMap);
		if (m_BasePriceLimitFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"BasePriceLimit");
		pStru->reuseID = m_BasePriceLimitFactory->getReuseID();
				
		m_CreditLimitFactory=new CCreditLimitFactory(pConfig,pAllocator,&indexMap);
		if (m_CreditLimitFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CreditLimit");
		pStru->reuseID = m_CreditLimitFactory->getReuseID();
				
		m_CurrInstrumentOptionFactory=new CCurrInstrumentOptionFactory(pConfig,pAllocator,&indexMap);
		if (m_CurrInstrumentOptionFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"CurrInstrumentOption");
		pStru->reuseID = m_CurrInstrumentOptionFactory->getReuseID();
				
	
		map<string,int>::iterator it = indexMap.begin();
		for(;it!=indexMap.end();it++)
		{
			pStru = (TableStruct *)pMem->alloc();
			strcpy(pStru->tableName,it->first.c_str());
			pStru->reuseID = it->second;
		}
	}
	else
	{
		pMem=new CFixMem(sizeof(TableStruct),MAX_TABLE_COUNT,pAllocator,true,MEMORYDB_ID);
		map<string,int> blockMap;
		TableStruct* pStru = NULL;
		for(int i=0;i<pMem->getCount();i++)
		{
			pStru = (TableStruct *)pMem->getObject(i);
			blockMap.insert(map<string,int>::value_type(pStru->tableName,pStru->reuseID));
		}
		map<string,int>::iterator it;
			
		it = blockMap.find("ExchangeDataSyncStatus");
		if(it == blockMap.end())
			m_ExchangeDataSyncStatusFactory=new CExchangeDataSyncStatusFactory(pConfig,pAllocator,&blockMap);
		else
			m_ExchangeDataSyncStatusFactory=new CExchangeDataSyncStatusFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_ExchangeDataSyncStatusFactory==NULL)
			return 0;
				
		it = blockMap.find("SGDataSyncStatus");
		if(it == blockMap.end())
			m_SGDataSyncStatusFactory=new CSGDataSyncStatusFactory(pConfig,pAllocator,&blockMap);
		else
			m_SGDataSyncStatusFactory=new CSGDataSyncStatusFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SGDataSyncStatusFactory==NULL)
			return 0;
				
		it = blockMap.find("CurrentTime");
		if(it == blockMap.end())
			m_CurrentTimeFactory=new CCurrentTimeFactory(pConfig,pAllocator,&blockMap);
		else
			m_CurrentTimeFactory=new CCurrentTimeFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CurrentTimeFactory==NULL)
			return 0;
				
		it = blockMap.find("DataCenterDesc");
		if(it == blockMap.end())
			m_DataCenterDescFactory=new CDataCenterDescFactory(pConfig,pAllocator,&blockMap);
		else
			m_DataCenterDescFactory=new CDataCenterDescFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_DataCenterDescFactory==NULL)
			return 0;
				
		it = blockMap.find("Exchange");
		if(it == blockMap.end())
			m_ExchangeFactory=new CExchangeFactory(pConfig,pAllocator,&blockMap);
		else
			m_ExchangeFactory=new CExchangeFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_ExchangeFactory==NULL)
			return 0;
				
		it = blockMap.find("SettlementGroup");
		if(it == blockMap.end())
			m_SettlementGroupFactory=new CSettlementGroupFactory(pConfig,pAllocator,&blockMap);
		else
			m_SettlementGroupFactory=new CSettlementGroupFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SettlementGroupFactory==NULL)
			return 0;
				
		it = blockMap.find("Market");
		if(it == blockMap.end())
			m_MarketFactory=new CMarketFactory(pConfig,pAllocator,&blockMap);
		else
			m_MarketFactory=new CMarketFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_MarketFactory==NULL)
			return 0;
				
		it = blockMap.find("MarketProduct");
		if(it == blockMap.end())
			m_MarketProductFactory=new CMarketProductFactory(pConfig,pAllocator,&blockMap);
		else
			m_MarketProductFactory=new CMarketProductFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_MarketProductFactory==NULL)
			return 0;
				
		it = blockMap.find("MarketProductGroup");
		if(it == blockMap.end())
			m_MarketProductGroupFactory=new CMarketProductGroupFactory(pConfig,pAllocator,&blockMap);
		else
			m_MarketProductGroupFactory=new CMarketProductGroupFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_MarketProductGroupFactory==NULL)
			return 0;
				
		it = blockMap.find("MdPubStatus");
		if(it == blockMap.end())
			m_MdPubStatusFactory=new CMdPubStatusFactory(pConfig,pAllocator,&blockMap);
		else
			m_MdPubStatusFactory=new CMdPubStatusFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_MdPubStatusFactory==NULL)
			return 0;
				
		it = blockMap.find("MarketDataTopic");
		if(it == blockMap.end())
			m_MarketDataTopicFactory=new CMarketDataTopicFactory(pConfig,pAllocator,&blockMap);
		else
			m_MarketDataTopicFactory=new CMarketDataTopicFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_MarketDataTopicFactory==NULL)
			return 0;
				
		it = blockMap.find("PartTopicSubscribe");
		if(it == blockMap.end())
			m_PartTopicSubscribeFactory=new CPartTopicSubscribeFactory(pConfig,pAllocator,&blockMap);
		else
			m_PartTopicSubscribeFactory=new CPartTopicSubscribeFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_PartTopicSubscribeFactory==NULL)
			return 0;
				
		it = blockMap.find("Participant");
		if(it == blockMap.end())
			m_ParticipantFactory=new CParticipantFactory(pConfig,pAllocator,&blockMap);
		else
			m_ParticipantFactory=new CParticipantFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_ParticipantFactory==NULL)
			return 0;
				
		it = blockMap.find("User");
		if(it == blockMap.end())
			m_UserFactory=new CUserFactory(pConfig,pAllocator,&blockMap);
		else
			m_UserFactory=new CUserFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_UserFactory==NULL)
			return 0;
				
		it = blockMap.find("Client");
		if(it == blockMap.end())
			m_ClientFactory=new CClientFactory(pConfig,pAllocator,&blockMap);
		else
			m_ClientFactory=new CClientFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_ClientFactory==NULL)
			return 0;
				
		it = blockMap.find("UserIP");
		if(it == blockMap.end())
			m_UserIPFactory=new CUserIPFactory(pConfig,pAllocator,&blockMap);
		else
			m_UserIPFactory=new CUserIPFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_UserIPFactory==NULL)
			return 0;
				
		it = blockMap.find("PartClient");
		if(it == blockMap.end())
			m_PartClientFactory=new CPartClientFactory(pConfig,pAllocator,&blockMap);
		else
			m_PartClientFactory=new CPartClientFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_PartClientFactory==NULL)
			return 0;
				
		it = blockMap.find("ClearingTradingPart");
		if(it == blockMap.end())
			m_ClearingTradingPartFactory=new CClearingTradingPartFactory(pConfig,pAllocator,&blockMap);
		else
			m_ClearingTradingPartFactory=new CClearingTradingPartFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_ClearingTradingPartFactory==NULL)
			return 0;
				
		it = blockMap.find("AliasDefine");
		if(it == blockMap.end())
			m_AliasDefineFactory=new CAliasDefineFactory(pConfig,pAllocator,&blockMap);
		else
			m_AliasDefineFactory=new CAliasDefineFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_AliasDefineFactory==NULL)
			return 0;
				
		it = blockMap.find("UserFunctionRight");
		if(it == blockMap.end())
			m_UserFunctionRightFactory=new CUserFunctionRightFactory(pConfig,pAllocator,&blockMap);
		else
			m_UserFunctionRightFactory=new CUserFunctionRightFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_UserFunctionRightFactory==NULL)
			return 0;
				
		it = blockMap.find("Account");
		if(it == blockMap.end())
			m_AccountFactory=new CAccountFactory(pConfig,pAllocator,&blockMap);
		else
			m_AccountFactory=new CAccountFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_AccountFactory==NULL)
			return 0;
				
		it = blockMap.find("UserCommFlux");
		if(it == blockMap.end())
			m_UserCommFluxFactory=new CUserCommFluxFactory(pConfig,pAllocator,&blockMap);
		else
			m_UserCommFluxFactory=new CUserCommFluxFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_UserCommFluxFactory==NULL)
			return 0;
				
		it = blockMap.find("MarketDataLog");
		if(it == blockMap.end())
			m_MarketDataLogFactory=new CMarketDataLogFactory(pConfig,pAllocator,&blockMap);
		else
			m_MarketDataLogFactory=new CMarketDataLogFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_MarketDataLogFactory==NULL)
			return 0;
				
		it = blockMap.find("UserSession");
		if(it == blockMap.end())
			m_UserSessionFactory=new CUserSessionFactory(pConfig,pAllocator,&blockMap);
		else
			m_UserSessionFactory=new CUserSessionFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_UserSessionFactory==NULL)
			return 0;
				
		it = blockMap.find("MDSession");
		if(it == blockMap.end())
			m_MDSessionFactory=new CMDSessionFactory(pConfig,pAllocator,&blockMap);
		else
			m_MDSessionFactory=new CMDSessionFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_MDSessionFactory==NULL)
			return 0;
				
		it = blockMap.find("LoginInfo");
		if(it == blockMap.end())
			m_LoginInfoFactory=new CLoginInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_LoginInfoFactory=new CLoginInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_LoginInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("DepthMarketDataDetail");
		if(it == blockMap.end())
			m_DepthMarketDataDetailFactory=new CDepthMarketDataDetailFactory(pConfig,pAllocator,&blockMap);
		else
			m_DepthMarketDataDetailFactory=new CDepthMarketDataDetailFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_DepthMarketDataDetailFactory==NULL)
			return 0;
				
		it = blockMap.find("InstrumentStatusDetail");
		if(it == blockMap.end())
			m_InstrumentStatusDetailFactory=new CInstrumentStatusDetailFactory(pConfig,pAllocator,&blockMap);
		else
			m_InstrumentStatusDetailFactory=new CInstrumentStatusDetailFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_InstrumentStatusDetailFactory==NULL)
			return 0;
				
		it = blockMap.find("FrontStatus");
		if(it == blockMap.end())
			m_FrontStatusFactory=new CFrontStatusFactory(pConfig,pAllocator,&blockMap);
		else
			m_FrontStatusFactory=new CFrontStatusFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_FrontStatusFactory==NULL)
			return 0;
				
		it = blockMap.find("MaxLocalID");
		if(it == blockMap.end())
			m_MaxLocalIDFactory=new CMaxLocalIDFactory(pConfig,pAllocator,&blockMap);
		else
			m_MaxLocalIDFactory=new CMaxLocalIDFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_MaxLocalIDFactory==NULL)
			return 0;
				
		it = blockMap.find("Bulletin");
		if(it == blockMap.end())
			m_BulletinFactory=new CBulletinFactory(pConfig,pAllocator,&blockMap);
		else
			m_BulletinFactory=new CBulletinFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_BulletinFactory==NULL)
			return 0;
				
		it = blockMap.find("MarketDataModify");
		if(it == blockMap.end())
			m_MarketDataModifyFactory=new CMarketDataModifyFactory(pConfig,pAllocator,&blockMap);
		else
			m_MarketDataModifyFactory=new CMarketDataModifyFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_MarketDataModifyFactory==NULL)
			return 0;
				
		it = blockMap.find("DepthMarketData");
		if(it == blockMap.end())
			m_DepthMarketDataFactory=new CDepthMarketDataFactory(pConfig,pAllocator,&blockMap);
		else
			m_DepthMarketDataFactory=new CDepthMarketDataFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_DepthMarketDataFactory==NULL)
			return 0;
				
		it = blockMap.find("TopicMarketData");
		if(it == blockMap.end())
			m_TopicMarketDataFactory=new CTopicMarketDataFactory(pConfig,pAllocator,&blockMap);
		else
			m_TopicMarketDataFactory=new CTopicMarketDataFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_TopicMarketDataFactory==NULL)
			return 0;
				
		it = blockMap.find("TopicMarketDataVersion");
		if(it == blockMap.end())
			m_TopicMarketDataVersionFactory=new CTopicMarketDataVersionFactory(pConfig,pAllocator,&blockMap);
		else
			m_TopicMarketDataVersionFactory=new CTopicMarketDataVersionFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_TopicMarketDataVersionFactory==NULL)
			return 0;
				
		it = blockMap.find("Information");
		if(it == blockMap.end())
			m_InformationFactory=new CInformationFactory(pConfig,pAllocator,&blockMap);
		else
			m_InformationFactory=new CInformationFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_InformationFactory==NULL)
			return 0;
				
		it = blockMap.find("OrderCount");
		if(it == blockMap.end())
			m_OrderCountFactory=new COrderCountFactory(pConfig,pAllocator,&blockMap);
		else
			m_OrderCountFactory=new COrderCountFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_OrderCountFactory==NULL)
			return 0;
				
		it = blockMap.find("Instrument");
		if(it == blockMap.end())
			m_InstrumentFactory=new CInstrumentFactory(pConfig,pAllocator,&blockMap);
		else
			m_InstrumentFactory=new CInstrumentFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_InstrumentFactory==NULL)
			return 0;
				
		it = blockMap.find("CombinationLeg");
		if(it == blockMap.end())
			m_CombinationLegFactory=new CCombinationLegFactory(pConfig,pAllocator,&blockMap);
		else
			m_CombinationLegFactory=new CCombinationLegFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CombinationLegFactory==NULL)
			return 0;
				
		it = blockMap.find("PartRoleAccount");
		if(it == blockMap.end())
			m_PartRoleAccountFactory=new CPartRoleAccountFactory(pConfig,pAllocator,&blockMap);
		else
			m_PartRoleAccountFactory=new CPartRoleAccountFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_PartRoleAccountFactory==NULL)
			return 0;
				
		it = blockMap.find("PartProductRole");
		if(it == blockMap.end())
			m_PartProductRoleFactory=new CPartProductRoleFactory(pConfig,pAllocator,&blockMap);
		else
			m_PartProductRoleFactory=new CPartProductRoleFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_PartProductRoleFactory==NULL)
			return 0;
				
		it = blockMap.find("PartProductRight");
		if(it == blockMap.end())
			m_PartProductRightFactory=new CPartProductRightFactory(pConfig,pAllocator,&blockMap);
		else
			m_PartProductRightFactory=new CPartProductRightFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_PartProductRightFactory==NULL)
			return 0;
				
		it = blockMap.find("PartInstrumentRight");
		if(it == blockMap.end())
			m_PartInstrumentRightFactory=new CPartInstrumentRightFactory(pConfig,pAllocator,&blockMap);
		else
			m_PartInstrumentRightFactory=new CPartInstrumentRightFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_PartInstrumentRightFactory==NULL)
			return 0;
				
		it = blockMap.find("ClientProductRight");
		if(it == blockMap.end())
			m_ClientProductRightFactory=new CClientProductRightFactory(pConfig,pAllocator,&blockMap);
		else
			m_ClientProductRightFactory=new CClientProductRightFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_ClientProductRightFactory==NULL)
			return 0;
				
		it = blockMap.find("ClientInstrumentRight");
		if(it == blockMap.end())
			m_ClientInstrumentRightFactory=new CClientInstrumentRightFactory(pConfig,pAllocator,&blockMap);
		else
			m_ClientInstrumentRightFactory=new CClientInstrumentRightFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_ClientInstrumentRightFactory==NULL)
			return 0;
				
		it = blockMap.find("PartClientProductRight");
		if(it == blockMap.end())
			m_PartClientProductRightFactory=new CPartClientProductRightFactory(pConfig,pAllocator,&blockMap);
		else
			m_PartClientProductRightFactory=new CPartClientProductRightFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_PartClientProductRightFactory==NULL)
			return 0;
				
		it = blockMap.find("PartClientInstrumentRight");
		if(it == blockMap.end())
			m_PartClientInstrumentRightFactory=new CPartClientInstrumentRightFactory(pConfig,pAllocator,&blockMap);
		else
			m_PartClientInstrumentRightFactory=new CPartClientInstrumentRightFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_PartClientInstrumentRightFactory==NULL)
			return 0;
				
		it = blockMap.find("CurrProductProperty");
		if(it == blockMap.end())
			m_CurrProductPropertyFactory=new CCurrProductPropertyFactory(pConfig,pAllocator,&blockMap);
		else
			m_CurrProductPropertyFactory=new CCurrProductPropertyFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CurrProductPropertyFactory==NULL)
			return 0;
				
		it = blockMap.find("CurrInstrumentProperty");
		if(it == blockMap.end())
			m_CurrInstrumentPropertyFactory=new CCurrInstrumentPropertyFactory(pConfig,pAllocator,&blockMap);
		else
			m_CurrInstrumentPropertyFactory=new CCurrInstrumentPropertyFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CurrInstrumentPropertyFactory==NULL)
			return 0;
				
		it = blockMap.find("CurrPriceBanding");
		if(it == blockMap.end())
			m_CurrPriceBandingFactory=new CCurrPriceBandingFactory(pConfig,pAllocator,&blockMap);
		else
			m_CurrPriceBandingFactory=new CCurrPriceBandingFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CurrPriceBandingFactory==NULL)
			return 0;
				
		it = blockMap.find("CurrMarginRate");
		if(it == blockMap.end())
			m_CurrMarginRateFactory=new CCurrMarginRateFactory(pConfig,pAllocator,&blockMap);
		else
			m_CurrMarginRateFactory=new CCurrMarginRateFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CurrMarginRateFactory==NULL)
			return 0;
				
		it = blockMap.find("CurrMarginRateDetail");
		if(it == blockMap.end())
			m_CurrMarginRateDetailFactory=new CCurrMarginRateDetailFactory(pConfig,pAllocator,&blockMap);
		else
			m_CurrMarginRateDetailFactory=new CCurrMarginRateDetailFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CurrMarginRateDetailFactory==NULL)
			return 0;
				
		it = blockMap.find("CurrPartPosiLimit");
		if(it == blockMap.end())
			m_CurrPartPosiLimitFactory=new CCurrPartPosiLimitFactory(pConfig,pAllocator,&blockMap);
		else
			m_CurrPartPosiLimitFactory=new CCurrPartPosiLimitFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CurrPartPosiLimitFactory==NULL)
			return 0;
				
		it = blockMap.find("CurrPartPosiLimitDetail");
		if(it == blockMap.end())
			m_CurrPartPosiLimitDetailFactory=new CCurrPartPosiLimitDetailFactory(pConfig,pAllocator,&blockMap);
		else
			m_CurrPartPosiLimitDetailFactory=new CCurrPartPosiLimitDetailFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CurrPartPosiLimitDetailFactory==NULL)
			return 0;
				
		it = blockMap.find("CurrClientPosiLimit");
		if(it == blockMap.end())
			m_CurrClientPosiLimitFactory=new CCurrClientPosiLimitFactory(pConfig,pAllocator,&blockMap);
		else
			m_CurrClientPosiLimitFactory=new CCurrClientPosiLimitFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CurrClientPosiLimitFactory==NULL)
			return 0;
				
		it = blockMap.find("CurrClientPosiLimitDetail");
		if(it == blockMap.end())
			m_CurrClientPosiLimitDetailFactory=new CCurrClientPosiLimitDetailFactory(pConfig,pAllocator,&blockMap);
		else
			m_CurrClientPosiLimitDetailFactory=new CCurrClientPosiLimitDetailFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CurrClientPosiLimitDetailFactory==NULL)
			return 0;
				
		it = blockMap.find("CurrSpecialPosiLimit");
		if(it == blockMap.end())
			m_CurrSpecialPosiLimitFactory=new CCurrSpecialPosiLimitFactory(pConfig,pAllocator,&blockMap);
		else
			m_CurrSpecialPosiLimitFactory=new CCurrSpecialPosiLimitFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CurrSpecialPosiLimitFactory==NULL)
			return 0;
				
		it = blockMap.find("CurrSpecialPosiLimitDetail");
		if(it == blockMap.end())
			m_CurrSpecialPosiLimitDetailFactory=new CCurrSpecialPosiLimitDetailFactory(pConfig,pAllocator,&blockMap);
		else
			m_CurrSpecialPosiLimitDetailFactory=new CCurrSpecialPosiLimitDetailFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CurrSpecialPosiLimitDetailFactory==NULL)
			return 0;
				
		it = blockMap.find("CurrHedgeRule");
		if(it == blockMap.end())
			m_CurrHedgeRuleFactory=new CCurrHedgeRuleFactory(pConfig,pAllocator,&blockMap);
		else
			m_CurrHedgeRuleFactory=new CCurrHedgeRuleFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CurrHedgeRuleFactory==NULL)
			return 0;
				
		it = blockMap.find("CurrTradingSegmentAttr");
		if(it == blockMap.end())
			m_CurrTradingSegmentAttrFactory=new CCurrTradingSegmentAttrFactory(pConfig,pAllocator,&blockMap);
		else
			m_CurrTradingSegmentAttrFactory=new CCurrTradingSegmentAttrFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CurrTradingSegmentAttrFactory==NULL)
			return 0;
				
		it = blockMap.find("CurrFuse");
		if(it == blockMap.end())
			m_CurrFuseFactory=new CCurrFuseFactory(pConfig,pAllocator,&blockMap);
		else
			m_CurrFuseFactory=new CCurrFuseFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CurrFuseFactory==NULL)
			return 0;
				
		it = blockMap.find("TradingAccount");
		if(it == blockMap.end())
			m_TradingAccountFactory=new CTradingAccountFactory(pConfig,pAllocator,&blockMap);
		else
			m_TradingAccountFactory=new CTradingAccountFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_TradingAccountFactory==NULL)
			return 0;
				
		it = blockMap.find("BaseReserveAccount");
		if(it == blockMap.end())
			m_BaseReserveAccountFactory=new CBaseReserveAccountFactory(pConfig,pAllocator,&blockMap);
		else
			m_BaseReserveAccountFactory=new CBaseReserveAccountFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_BaseReserveAccountFactory==NULL)
			return 0;
				
		it = blockMap.find("PartPosition");
		if(it == blockMap.end())
			m_PartPositionFactory=new CPartPositionFactory(pConfig,pAllocator,&blockMap);
		else
			m_PartPositionFactory=new CPartPositionFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_PartPositionFactory==NULL)
			return 0;
				
		it = blockMap.find("ClientPosition");
		if(it == blockMap.end())
			m_ClientPositionFactory=new CClientPositionFactory(pConfig,pAllocator,&blockMap);
		else
			m_ClientPositionFactory=new CClientPositionFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_ClientPositionFactory==NULL)
			return 0;
				
		it = blockMap.find("HedgeVolume");
		if(it == blockMap.end())
			m_HedgeVolumeFactory=new CHedgeVolumeFactory(pConfig,pAllocator,&blockMap);
		else
			m_HedgeVolumeFactory=new CHedgeVolumeFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_HedgeVolumeFactory==NULL)
			return 0;
				
		it = blockMap.find("RemainOrder");
		if(it == blockMap.end())
			m_RemainOrderFactory=new CRemainOrderFactory(pConfig,pAllocator,&blockMap);
		else
			m_RemainOrderFactory=new CRemainOrderFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_RemainOrderFactory==NULL)
			return 0;
				
		it = blockMap.find("MarketData");
		if(it == blockMap.end())
			m_MarketDataFactory=new CMarketDataFactory(pConfig,pAllocator,&blockMap);
		else
			m_MarketDataFactory=new CMarketDataFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_MarketDataFactory==NULL)
			return 0;
				
		it = blockMap.find("ClearingPartPosition");
		if(it == blockMap.end())
			m_ClearingPartPositionFactory=new CClearingPartPositionFactory(pConfig,pAllocator,&blockMap);
		else
			m_ClearingPartPositionFactory=new CClearingPartPositionFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_ClearingPartPositionFactory==NULL)
			return 0;
				
		it = blockMap.find("InstrumentStatus");
		if(it == blockMap.end())
			m_InstrumentStatusFactory=new CInstrumentStatusFactory(pConfig,pAllocator,&blockMap);
		else
			m_InstrumentStatusFactory=new CInstrumentStatusFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_InstrumentStatusFactory==NULL)
			return 0;
				
		it = blockMap.find("Order");
		if(it == blockMap.end())
			m_OrderFactory=new COrderFactory(pConfig,pAllocator,&blockMap);
		else
			m_OrderFactory=new COrderFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_OrderFactory==NULL)
			return 0;
				
		it = blockMap.find("CombOrder");
		if(it == blockMap.end())
			m_CombOrderFactory=new CCombOrderFactory(pConfig,pAllocator,&blockMap);
		else
			m_CombOrderFactory=new CCombOrderFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CombOrderFactory==NULL)
			return 0;
				
		it = blockMap.find("OTCOrder");
		if(it == blockMap.end())
			m_OTCOrderFactory=new COTCOrderFactory(pConfig,pAllocator,&blockMap);
		else
			m_OTCOrderFactory=new COTCOrderFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_OTCOrderFactory==NULL)
			return 0;
				
		it = blockMap.find("ImplyOrder");
		if(it == blockMap.end())
			m_ImplyOrderFactory=new CImplyOrderFactory(pConfig,pAllocator,&blockMap);
		else
			m_ImplyOrderFactory=new CImplyOrderFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_ImplyOrderFactory==NULL)
			return 0;
				
		it = blockMap.find("Quote");
		if(it == blockMap.end())
			m_QuoteFactory=new CQuoteFactory(pConfig,pAllocator,&blockMap);
		else
			m_QuoteFactory=new CQuoteFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_QuoteFactory==NULL)
			return 0;
				
		it = blockMap.find("MBLMarketData");
		if(it == blockMap.end())
			m_MBLMarketDataFactory=new CMBLMarketDataFactory(pConfig,pAllocator,&blockMap);
		else
			m_MBLMarketDataFactory=new CMBLMarketDataFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_MBLMarketDataFactory==NULL)
			return 0;
				
		it = blockMap.find("Trade");
		if(it == blockMap.end())
			m_TradeFactory=new CTradeFactory(pConfig,pAllocator,&blockMap);
		else
			m_TradeFactory=new CTradeFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_TradeFactory==NULL)
			return 0;
				
		it = blockMap.find("FusePhase");
		if(it == blockMap.end())
			m_FusePhaseFactory=new CFusePhaseFactory(pConfig,pAllocator,&blockMap);
		else
			m_FusePhaseFactory=new CFusePhaseFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_FusePhaseFactory==NULL)
			return 0;
				
		it = blockMap.find("ExecOrder");
		if(it == blockMap.end())
			m_ExecOrderFactory=new CExecOrderFactory(pConfig,pAllocator,&blockMap);
		else
			m_ExecOrderFactory=new CExecOrderFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_ExecOrderFactory==NULL)
			return 0;
				
		it = blockMap.find("UniPressure");
		if(it == blockMap.end())
			m_UniPressureFactory=new CUniPressureFactory(pConfig,pAllocator,&blockMap);
		else
			m_UniPressureFactory=new CUniPressureFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_UniPressureFactory==NULL)
			return 0;
				
		it = blockMap.find("BasePriceLimit");
		if(it == blockMap.end())
			m_BasePriceLimitFactory=new CBasePriceLimitFactory(pConfig,pAllocator,&blockMap);
		else
			m_BasePriceLimitFactory=new CBasePriceLimitFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_BasePriceLimitFactory==NULL)
			return 0;
				
		it = blockMap.find("CreditLimit");
		if(it == blockMap.end())
			m_CreditLimitFactory=new CCreditLimitFactory(pConfig,pAllocator,&blockMap);
		else
			m_CreditLimitFactory=new CCreditLimitFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CreditLimitFactory==NULL)
			return 0;
				
		it = blockMap.find("CurrInstrumentOption");
		if(it == blockMap.end())
			m_CurrInstrumentOptionFactory=new CCurrInstrumentOptionFactory(pConfig,pAllocator,&blockMap);
		else
			m_CurrInstrumentOptionFactory=new CCurrInstrumentOptionFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_CurrInstrumentOptionFactory==NULL)
			return 0;
				
	}
	return 1;
}

int CMemoryDB::load(CConfig *pConfig)
{
	if (!m_ExchangeFactory->readCSV(pConfig))
		return 0;
	if (!m_SettlementGroupFactory->readCSV(pConfig))
		return 0;
	if (!m_MarketFactory->readCSV(pConfig))
		return 0;
	if (!m_MarketProductFactory->readCSV(pConfig))
		return 0;
	if (!m_MarketProductGroupFactory->readCSV(pConfig))
		return 0;
	if (!m_MdPubStatusFactory->readCSV(pConfig))
		return 0;
	if (!m_MarketDataTopicFactory->readCSV(pConfig))
		return 0;
	if (!m_PartTopicSubscribeFactory->readCSV(pConfig))
		return 0;
	if (!m_ParticipantFactory->readCSV(pConfig))
		return 0;
	if (!m_UserFactory->readCSV(pConfig))
		return 0;
	if (!m_ClientFactory->readCSV(pConfig))
		return 0;
	if (!m_UserIPFactory->readCSV(pConfig))
		return 0;
	if (!m_PartClientFactory->readCSV(pConfig))
		return 0;
	if (!m_ClearingTradingPartFactory->readCSV(pConfig))
		return 0;
	if (!m_AliasDefineFactory->readCSV(pConfig))
		return 0;
	if (!m_UserFunctionRightFactory->readCSV(pConfig))
		return 0;
	if (!m_AccountFactory->readCSV(pConfig))
		return 0;
	if (!m_UserCommFluxFactory->readCSV(pConfig))
		return 0;
	if (!m_InstrumentFactory->readCSV(pConfig))
		return 0;
	if (!m_CombinationLegFactory->readCSV(pConfig))
		return 0;
	if (!m_PartRoleAccountFactory->readCSV(pConfig))
		return 0;
	if (!m_PartProductRoleFactory->readCSV(pConfig))
		return 0;
	if (!m_PartProductRightFactory->readCSV(pConfig))
		return 0;
	if (!m_PartInstrumentRightFactory->readCSV(pConfig))
		return 0;
	if (!m_ClientProductRightFactory->readCSV(pConfig))
		return 0;
	if (!m_ClientInstrumentRightFactory->readCSV(pConfig))
		return 0;
	if (!m_PartClientProductRightFactory->readCSV(pConfig))
		return 0;
	if (!m_PartClientInstrumentRightFactory->readCSV(pConfig))
		return 0;
	if (!m_CurrProductPropertyFactory->readCSV(pConfig))
		return 0;
	if (!m_CurrInstrumentPropertyFactory->readCSV(pConfig))
		return 0;
	if (!m_CurrPriceBandingFactory->readCSV(pConfig))
		return 0;
	if (!m_CurrMarginRateFactory->readCSV(pConfig))
		return 0;
	if (!m_CurrMarginRateDetailFactory->readCSV(pConfig))
		return 0;
	if (!m_CurrPartPosiLimitFactory->readCSV(pConfig))
		return 0;
	if (!m_CurrPartPosiLimitDetailFactory->readCSV(pConfig))
		return 0;
	if (!m_CurrClientPosiLimitFactory->readCSV(pConfig))
		return 0;
	if (!m_CurrClientPosiLimitDetailFactory->readCSV(pConfig))
		return 0;
	if (!m_CurrSpecialPosiLimitFactory->readCSV(pConfig))
		return 0;
	if (!m_CurrSpecialPosiLimitDetailFactory->readCSV(pConfig))
		return 0;
	if (!m_CurrHedgeRuleFactory->readCSV(pConfig))
		return 0;
	if (!m_CurrTradingSegmentAttrFactory->readCSV(pConfig))
		return 0;
	if (!m_CurrFuseFactory->readCSV(pConfig))
		return 0;
	if (!m_TradingAccountFactory->readCSV(pConfig))
		return 0;
	if (!m_BaseReserveAccountFactory->readCSV(pConfig))
		return 0;
	if (!m_PartPositionFactory->readCSV(pConfig))
		return 0;
	if (!m_ClientPositionFactory->readCSV(pConfig))
		return 0;
	if (!m_HedgeVolumeFactory->readCSV(pConfig))
		return 0;
	if (!m_RemainOrderFactory->readCSV(pConfig))
		return 0;
	if (!m_MarketDataFactory->readCSV(pConfig))
		return 0;
	if (!m_CurrInstrumentOptionFactory->readCSV(pConfig))
		return 0;
	return 1;
}

int CMemoryDB::save(CConfig *pConfig)
{
	if (!m_ExchangeDataSyncStatusFactory->writeCSV(pConfig))
		return 0;
	if (!m_SGDataSyncStatusFactory->writeCSV(pConfig))
		return 0;
	if (!m_CurrentTimeFactory->writeCSV(pConfig))
		return 0;
	if (!m_DataCenterDescFactory->writeCSV(pConfig))
		return 0;
	if (!m_ExchangeFactory->writeCSV(pConfig))
		return 0;
	if (!m_SettlementGroupFactory->writeCSV(pConfig))
		return 0;
	if (!m_MarketFactory->writeCSV(pConfig))
		return 0;
	if (!m_MarketProductFactory->writeCSV(pConfig))
		return 0;
	if (!m_MarketProductGroupFactory->writeCSV(pConfig))
		return 0;
	if (!m_MdPubStatusFactory->writeCSV(pConfig))
		return 0;
	if (!m_MarketDataTopicFactory->writeCSV(pConfig))
		return 0;
	if (!m_PartTopicSubscribeFactory->writeCSV(pConfig))
		return 0;
	if (!m_ParticipantFactory->writeCSV(pConfig))
		return 0;
	if (!m_UserFactory->writeCSV(pConfig))
		return 0;
	if (!m_ClientFactory->writeCSV(pConfig))
		return 0;
	if (!m_UserIPFactory->writeCSV(pConfig))
		return 0;
	if (!m_PartClientFactory->writeCSV(pConfig))
		return 0;
	if (!m_ClearingTradingPartFactory->writeCSV(pConfig))
		return 0;
	if (!m_AliasDefineFactory->writeCSV(pConfig))
		return 0;
	if (!m_UserFunctionRightFactory->writeCSV(pConfig))
		return 0;
	if (!m_AccountFactory->writeCSV(pConfig))
		return 0;
	if (!m_UserCommFluxFactory->writeCSV(pConfig))
		return 0;
	if (!m_MarketDataLogFactory->writeCSV(pConfig))
		return 0;
	if (!m_UserSessionFactory->writeCSV(pConfig))
		return 0;
	if (!m_MDSessionFactory->writeCSV(pConfig))
		return 0;
	if (!m_LoginInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_DepthMarketDataDetailFactory->writeCSV(pConfig))
		return 0;
	if (!m_InstrumentStatusDetailFactory->writeCSV(pConfig))
		return 0;
	if (!m_FrontStatusFactory->writeCSV(pConfig))
		return 0;
	if (!m_MaxLocalIDFactory->writeCSV(pConfig))
		return 0;
	if (!m_BulletinFactory->writeCSV(pConfig))
		return 0;
	if (!m_MarketDataModifyFactory->writeCSV(pConfig))
		return 0;
	if (!m_DepthMarketDataFactory->writeCSV(pConfig))
		return 0;
	if (!m_TopicMarketDataFactory->writeCSV(pConfig))
		return 0;
	if (!m_TopicMarketDataVersionFactory->writeCSV(pConfig))
		return 0;
	if (!m_InformationFactory->writeCSV(pConfig))
		return 0;
	if (!m_OrderCountFactory->writeCSV(pConfig))
		return 0;
	if (!m_InstrumentFactory->writeCSV(pConfig))
		return 0;
	if (!m_CombinationLegFactory->writeCSV(pConfig))
		return 0;
	if (!m_PartRoleAccountFactory->writeCSV(pConfig))
		return 0;
	if (!m_PartProductRoleFactory->writeCSV(pConfig))
		return 0;
	if (!m_PartProductRightFactory->writeCSV(pConfig))
		return 0;
	if (!m_PartInstrumentRightFactory->writeCSV(pConfig))
		return 0;
	if (!m_ClientProductRightFactory->writeCSV(pConfig))
		return 0;
	if (!m_ClientInstrumentRightFactory->writeCSV(pConfig))
		return 0;
	if (!m_PartClientProductRightFactory->writeCSV(pConfig))
		return 0;
	if (!m_PartClientInstrumentRightFactory->writeCSV(pConfig))
		return 0;
	if (!m_CurrProductPropertyFactory->writeCSV(pConfig))
		return 0;
	if (!m_CurrInstrumentPropertyFactory->writeCSV(pConfig))
		return 0;
	if (!m_CurrPriceBandingFactory->writeCSV(pConfig))
		return 0;
	if (!m_CurrMarginRateFactory->writeCSV(pConfig))
		return 0;
	if (!m_CurrMarginRateDetailFactory->writeCSV(pConfig))
		return 0;
	if (!m_CurrPartPosiLimitFactory->writeCSV(pConfig))
		return 0;
	if (!m_CurrPartPosiLimitDetailFactory->writeCSV(pConfig))
		return 0;
	if (!m_CurrClientPosiLimitFactory->writeCSV(pConfig))
		return 0;
	if (!m_CurrClientPosiLimitDetailFactory->writeCSV(pConfig))
		return 0;
	if (!m_CurrSpecialPosiLimitFactory->writeCSV(pConfig))
		return 0;
	if (!m_CurrSpecialPosiLimitDetailFactory->writeCSV(pConfig))
		return 0;
	if (!m_CurrHedgeRuleFactory->writeCSV(pConfig))
		return 0;
	if (!m_CurrTradingSegmentAttrFactory->writeCSV(pConfig))
		return 0;
	if (!m_CurrFuseFactory->writeCSV(pConfig))
		return 0;
	if (!m_TradingAccountFactory->writeCSV(pConfig))
		return 0;
	if (!m_BaseReserveAccountFactory->writeCSV(pConfig))
		return 0;
	if (!m_PartPositionFactory->writeCSV(pConfig))
		return 0;
	if (!m_ClientPositionFactory->writeCSV(pConfig))
		return 0;
	if (!m_HedgeVolumeFactory->writeCSV(pConfig))
		return 0;
	if (!m_RemainOrderFactory->writeCSV(pConfig))
		return 0;
	if (!m_MarketDataFactory->writeCSV(pConfig))
		return 0;
	if (!m_ClearingPartPositionFactory->writeCSV(pConfig))
		return 0;
	if (!m_InstrumentStatusFactory->writeCSV(pConfig))
		return 0;
	if (!m_OrderFactory->writeCSV(pConfig))
		return 0;
	if (!m_CombOrderFactory->writeCSV(pConfig))
		return 0;
	if (!m_OTCOrderFactory->writeCSV(pConfig))
		return 0;
	if (!m_ImplyOrderFactory->writeCSV(pConfig))
		return 0;
	if (!m_QuoteFactory->writeCSV(pConfig))
		return 0;
	if (!m_MBLMarketDataFactory->writeCSV(pConfig))
		return 0;
	if (!m_TradeFactory->writeCSV(pConfig))
		return 0;
	if (!m_FusePhaseFactory->writeCSV(pConfig))
		return 0;
	if (!m_ExecOrderFactory->writeCSV(pConfig))
		return 0;
	if (!m_UniPressureFactory->writeCSV(pConfig))
		return 0;
	if (!m_BasePriceLimitFactory->writeCSV(pConfig))
		return 0;
	if (!m_CreditLimitFactory->writeCSV(pConfig))
		return 0;
	if (!m_CurrInstrumentOptionFactory->writeCSV(pConfig))
		return 0;
	return 1;
}

void CMemoryDB::clear(void)
{
	m_ExchangeDataSyncStatusFactory->clearAll();
	m_SGDataSyncStatusFactory->clearAll();
	m_CurrentTimeFactory->clearAll();
	m_DataCenterDescFactory->clearAll();
	m_ExchangeFactory->clearAll();
	m_SettlementGroupFactory->clearAll();
	m_MarketFactory->clearAll();
	m_MarketProductFactory->clearAll();
	m_MarketProductGroupFactory->clearAll();
	m_MdPubStatusFactory->clearAll();
	m_MarketDataTopicFactory->clearAll();
	m_PartTopicSubscribeFactory->clearAll();
	m_ParticipantFactory->clearAll();
	m_UserFactory->clearAll();
	m_ClientFactory->clearAll();
	m_UserIPFactory->clearAll();
	m_PartClientFactory->clearAll();
	m_ClearingTradingPartFactory->clearAll();
	m_AliasDefineFactory->clearAll();
	m_UserFunctionRightFactory->clearAll();
	m_AccountFactory->clearAll();
	m_UserCommFluxFactory->clearAll();
	m_MarketDataLogFactory->clearAll();
	m_UserSessionFactory->clearAll();
	m_MDSessionFactory->clearAll();
	m_LoginInfoFactory->clearAll();
	m_DepthMarketDataDetailFactory->clearAll();
	m_InstrumentStatusDetailFactory->clearAll();
	m_FrontStatusFactory->clearAll();
	m_MaxLocalIDFactory->clearAll();
	m_BulletinFactory->clearAll();
	m_MarketDataModifyFactory->clearAll();
	m_DepthMarketDataFactory->clearAll();
	m_TopicMarketDataFactory->clearAll();
	m_TopicMarketDataVersionFactory->clearAll();
	m_InformationFactory->clearAll();
	m_OrderCountFactory->clearAll();
	m_InstrumentFactory->clearAll();
	m_CombinationLegFactory->clearAll();
	m_PartRoleAccountFactory->clearAll();
	m_PartProductRoleFactory->clearAll();
	m_PartProductRightFactory->clearAll();
	m_PartInstrumentRightFactory->clearAll();
	m_ClientProductRightFactory->clearAll();
	m_ClientInstrumentRightFactory->clearAll();
	m_PartClientProductRightFactory->clearAll();
	m_PartClientInstrumentRightFactory->clearAll();
	m_CurrProductPropertyFactory->clearAll();
	m_CurrInstrumentPropertyFactory->clearAll();
	m_CurrPriceBandingFactory->clearAll();
	m_CurrMarginRateFactory->clearAll();
	m_CurrMarginRateDetailFactory->clearAll();
	m_CurrPartPosiLimitFactory->clearAll();
	m_CurrPartPosiLimitDetailFactory->clearAll();
	m_CurrClientPosiLimitFactory->clearAll();
	m_CurrClientPosiLimitDetailFactory->clearAll();
	m_CurrSpecialPosiLimitFactory->clearAll();
	m_CurrSpecialPosiLimitDetailFactory->clearAll();
	m_CurrHedgeRuleFactory->clearAll();
	m_CurrTradingSegmentAttrFactory->clearAll();
	m_CurrFuseFactory->clearAll();
	m_TradingAccountFactory->clearAll();
	m_BaseReserveAccountFactory->clearAll();
	m_PartPositionFactory->clearAll();
	m_ClientPositionFactory->clearAll();
	m_HedgeVolumeFactory->clearAll();
	m_RemainOrderFactory->clearAll();
	m_MarketDataFactory->clearAll();
	m_ClearingPartPositionFactory->clearAll();
	m_InstrumentStatusFactory->clearAll();
	m_OrderFactory->clearAll();
	m_CombOrderFactory->clearAll();
	m_OTCOrderFactory->clearAll();
	m_ImplyOrderFactory->clearAll();
	m_QuoteFactory->clearAll();
	m_MBLMarketDataFactory->clearAll();
	m_TradeFactory->clearAll();
	m_FusePhaseFactory->clearAll();
	m_ExecOrderFactory->clearAll();
	m_UniPressureFactory->clearAll();
	m_BasePriceLimitFactory->clearAll();
	m_CreditLimitFactory->clearAll();
	m_CurrInstrumentOptionFactory->clearAll();
	m_ForceUserPassword.clear();
}

void CMemoryDB::linkAll(void)
{
	m_ParticipantFactory->linkAllClearingTradingPart(m_ClearingTradingPartFactory);
	m_PartClientFactory->linkAllParticipant(m_ParticipantFactory);
	m_PartClientFactory->linkAllClient(m_ClientFactory);
	m_AccountFactory->linkAllTradingAccount(m_TradingAccountFactory);
	m_UserSessionFactory->linkAllUser(m_UserFactory);
	m_MarketDataModifyFactory->linkAllDepthMarketData(m_DepthMarketDataFactory);
	m_DepthMarketDataFactory->linkAllInstrument(m_InstrumentFactory);
	m_InstrumentFactory->linkAllBaseInstrument(m_InstrumentFactory);
	m_InstrumentFactory->linkAllInstrumentProperty(m_CurrInstrumentPropertyFactory);
	m_InstrumentFactory->linkAllInstrumentStatus(m_InstrumentStatusFactory);
	m_InstrumentFactory->linkAllMarketData(m_MarketDataFactory);
	m_InstrumentFactory->linkAllCurrHedgeRule(m_CurrHedgeRuleFactory);
	m_InstrumentFactory->linkAllCurrFuse(m_CurrFuseFactory);
	m_InstrumentFactory->linkAllFusePhase(m_FusePhaseFactory);
	m_InstrumentFactory->linkAllBasePriceLimit(m_BasePriceLimitFactory);
	m_InstrumentFactory->linkAllUniPressure(m_UniPressureFactory);
	m_InstrumentFactory->linkAllSGDataSyncStatus(m_SGDataSyncStatusFactory);
	m_CombinationLegFactory->linkAllCombinationInstrument(m_InstrumentFactory);
	m_CombinationLegFactory->linkAllLegInstrument(m_InstrumentFactory);
	m_PartRoleAccountFactory->linkAllTradingAccount(m_TradingAccountFactory);
	m_TradingAccountFactory->linkAllBaseReserveAccount(m_BaseReserveAccountFactory);
	m_ClientPositionFactory->linkAllCreditLimit(m_CreditLimitFactory);
	m_ClientPositionFactory->linkAllPartRoleAccount(m_PartRoleAccountFactory);
	m_InstrumentStatusFactory->linkAllInstrument(m_InstrumentFactory);
	m_InstrumentStatusFactory->linkAllCurrPriceBanding(m_CurrPriceBandingFactory);
	m_InstrumentStatusFactory->linkAllMdPubStatus(m_MdPubStatusFactory);
	m_OrderFactory->linkAllInstrument(m_InstrumentFactory);
	m_OrderFactory->linkAllPartClient(m_PartClientFactory);
	m_OrderFactory->linkAllClientPosition(m_ClientPositionFactory);
	m_CombOrderFactory->linkAllPartClient(m_PartClientFactory);
	m_CombOrderFactory->linkAllInstrument1(m_InstrumentFactory);
	m_CombOrderFactory->linkAllInstrument2(m_InstrumentFactory);
	m_CombOrderFactory->linkAllInstrument3(m_InstrumentFactory);
	m_CombOrderFactory->linkAllInstrument4(m_InstrumentFactory);
	m_OTCOrderFactory->linkAllInstrument(m_InstrumentFactory);
	m_QuoteFactory->linkAllInstrument(m_InstrumentFactory);
	m_QuoteFactory->linkAllPartClient(m_PartClientFactory);
	m_TradeFactory->linkAllInstrument(m_InstrumentFactory);
	m_TradeFactory->linkAllPartClient(m_PartClientFactory);
	m_FusePhaseFactory->linkAllInstrument(m_InstrumentFactory);
	m_ExecOrderFactory->linkAllPartClient(m_PartClientFactory);
	m_ExecOrderFactory->linkAllInstrument(m_InstrumentFactory);
}

