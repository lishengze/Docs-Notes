/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file CMemoryDB.h
///@brief定义了类CMemoryDB
///@history 
///20050824	王肇东		创建该文件
///20120111 江鹏		NT-0163 kernel命令行增加指定用户密码参数
/////////////////////////////////////////////////////////////////////////

#ifndef CMEMORYDB_H
#define CMEMORYDB_H

#include "CBaseObject.h"
#include "CConfig.h"
#include "BaseDataStruct.h"
#include "databaseFactories.h"
#include "databaseIterators.h"

struct TableStruct
{
	char tableName[100];
	int  reuseID;
};
/////////////////////////////////////////////////////////////////////////
///CMemoryDB是一个内存数据库类，包含了所有定义的表信息
///@author	王肇东
///@version	1.0,20050824
/////////////////////////////////////////////////////////////////////////
class CMemoryDB : public CBaseObject
{
public:
	///构造方法，创建内存数据库
	CMemoryDB(void);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CMemoryDB(void);
	
	virtual int isA(char *objectType);
	virtual char *getType(void);
	virtual void output(CLogger *pLogger,int indent=0);

	///进行初始化工作
	///@param	pConfig	初始化时使用的配置信息
	///@return	1表示成功，0表示失败
	virtual int init(CConfig *pConfig,IMemoryAllocator *pAllocator=NULL,bool reuse=false);
	
	///进行数据载入工作
	///@param	pConfig	载入数据时使用的配置信息
	///@return	1表示成功，0表示失败
	virtual int load(CConfig *pConfig);

	///进行数据存储工作
	///@param	pConfig	保存数据时使用的配置信息
	///@return	1表示成功，0表示失败
	virtual int save(CConfig *pConfig);
	
	///清空所有的数据
	///@return	1表示成功，0表示失败
	virtual void clear(void);
	
	///完成所有外键的连接
	virtual void linkAll(void);
	
	
	
	///交易所数据同步状态表
	CExchangeDataSyncStatusFactory *m_ExchangeDataSyncStatusFactory;
	
	///结算组数据同步状态表
	CSGDataSyncStatusFactory *m_SGDataSyncStatusFactory;
	
	///当前时间表
	CCurrentTimeFactory *m_CurrentTimeFactory;
	
	///数据中心描述表
	CDataCenterDescFactory *m_DataCenterDescFactory;
	
	///交易所表
	CExchangeFactory *m_ExchangeFactory;
	
	///结算组表
	CSettlementGroupFactory *m_SettlementGroupFactory;
	
	///市场表
	CMarketFactory *m_MarketFactory;
	
	///市场产品关联表
	CMarketProductFactory *m_MarketProductFactory;
	
	///市场产品组关联表
	CMarketProductGroupFactory *m_MarketProductGroupFactory;
	
	///行情发布状态表
	CMdPubStatusFactory *m_MdPubStatusFactory;
	
	///行情主题表
	CMarketDataTopicFactory *m_MarketDataTopicFactory;
	
	///会员订阅市场表
	CPartTopicSubscribeFactory *m_PartTopicSubscribeFactory;
	
	///会员表
	CParticipantFactory *m_ParticipantFactory;
	
	///用户表
	CUserFactory *m_UserFactory;
	
	///客户表
	CClientFactory *m_ClientFactory;
	
	///交易员IP地址表
	CUserIPFactory *m_UserIPFactory;
	
	///会员客户关系表
	CPartClientFactory *m_PartClientFactory;
	
	///结算交易会员关系表
	CClearingTradingPartFactory *m_ClearingTradingPartFactory;
	
	///别名定义表
	CAliasDefineFactory *m_AliasDefineFactory;
	
	///用户功能权限表
	CUserFunctionRightFactory *m_UserFunctionRightFactory;
	
	///资金账户表
	CAccountFactory *m_AccountFactory;
	
	///用户通讯量表
	CUserCommFluxFactory *m_UserCommFluxFactory;
	
	///行情流水表
	CMarketDataLogFactory *m_MarketDataLogFactory;
	
	///交易员在线会话表
	CUserSessionFactory *m_UserSessionFactory;
	
	///行情订阅者在线会话表
	CMDSessionFactory *m_MDSessionFactory;
	
	///用户登陆登出信息表
	CLoginInfoFactory *m_LoginInfoFactory;
	
	///深度市场行情明细表
	CDepthMarketDataDetailFactory *m_DepthMarketDataDetailFactory;
	
	///合约交易状态流水表
	CInstrumentStatusDetailFactory *m_InstrumentStatusDetailFactory;
	
	///前置状态表
	CFrontStatusFactory *m_FrontStatusFactory;
	
	///最大本地报单号表
	CMaxLocalIDFactory *m_MaxLocalIDFactory;
	
	///公告信息表
	CBulletinFactory *m_BulletinFactory;
	
	///行情变动表
	CMarketDataModifyFactory *m_MarketDataModifyFactory;
	
	///深度行情表
	CDepthMarketDataFactory *m_DepthMarketDataFactory;
	
	///分主题行情表
	CTopicMarketDataFactory *m_TopicMarketDataFactory;
	
	///分主题行情快照表
	CTopicMarketDataVersionFactory *m_TopicMarketDataVersionFactory;
	
	///信息表
	CInformationFactory *m_InformationFactory;
	
	///报单数量表
	COrderCountFactory *m_OrderCountFactory;
	
	///合约表
	CInstrumentFactory *m_InstrumentFactory;
	
	///组合合约单腿表
	CCombinationLegFactory *m_CombinationLegFactory;
	
	///会员账户关系表
	CPartRoleAccountFactory *m_PartRoleAccountFactory;
	
	///会员产品角色表
	CPartProductRoleFactory *m_PartProductRoleFactory;
	
	///会员产品交易权限表
	CPartProductRightFactory *m_PartProductRightFactory;
	
	///会员合约交易权限表
	CPartInstrumentRightFactory *m_PartInstrumentRightFactory;
	
	///客户产品交易权限表
	CClientProductRightFactory *m_ClientProductRightFactory;
	
	///客户合约交易权限表
	CClientInstrumentRightFactory *m_ClientInstrumentRightFactory;
	
	///会员客户产品交易权限表
	CPartClientProductRightFactory *m_PartClientProductRightFactory;
	
	///会员客户合约交易权限表
	CPartClientInstrumentRightFactory *m_PartClientInstrumentRightFactory;
	
	///产品属性表
	CCurrProductPropertyFactory *m_CurrProductPropertyFactory;
	
	///合约属性表
	CCurrInstrumentPropertyFactory *m_CurrInstrumentPropertyFactory;
	
	///当前价格绑定表
	CCurrPriceBandingFactory *m_CurrPriceBandingFactory;
	
	///当天合约保证金率表
	CCurrMarginRateFactory *m_CurrMarginRateFactory;
	
	///当天合约保证金率的详细内容表
	CCurrMarginRateDetailFactory *m_CurrMarginRateDetailFactory;
	
	///当前会员合约限仓表
	CCurrPartPosiLimitFactory *m_CurrPartPosiLimitFactory;
	
	///当前会员合约限仓的详细内容表
	CCurrPartPosiLimitDetailFactory *m_CurrPartPosiLimitDetailFactory;
	
	///当前客户合约限仓表
	CCurrClientPosiLimitFactory *m_CurrClientPosiLimitFactory;
	
	///当前客户合约限仓的详细内容表
	CCurrClientPosiLimitDetailFactory *m_CurrClientPosiLimitDetailFactory;
	
	///当前特殊客户合约限仓表
	CCurrSpecialPosiLimitFactory *m_CurrSpecialPosiLimitFactory;
	
	///当前特殊客户合约限仓的详细内容表
	CCurrSpecialPosiLimitDetailFactory *m_CurrSpecialPosiLimitDetailFactory;
	
	///当前合约套期保值属性表
	CCurrHedgeRuleFactory *m_CurrHedgeRuleFactory;
	
	///当前合约交易阶段属性表
	CCurrTradingSegmentAttrFactory *m_CurrTradingSegmentAttrFactory;
	
	///当前合约熔断属性表
	CCurrFuseFactory *m_CurrFuseFactory;
	
	///交易账户表
	CTradingAccountFactory *m_TradingAccountFactory;
	
	///基本准备金账户表
	CBaseReserveAccountFactory *m_BaseReserveAccountFactory;
	
	///会员持仓表
	CPartPositionFactory *m_PartPositionFactory;
	
	///客户持仓表
	CClientPositionFactory *m_ClientPositionFactory;
	
	///保值额度量表
	CHedgeVolumeFactory *m_HedgeVolumeFactory;
	
	///历史报单表
	CRemainOrderFactory *m_RemainOrderFactory;
	
	///行情表
	CMarketDataFactory *m_MarketDataFactory;
	
	///结算会员持仓表
	CClearingPartPositionFactory *m_ClearingPartPositionFactory;
	
	///合约状态表
	CInstrumentStatusFactory *m_InstrumentStatusFactory;
	
	///报单表
	COrderFactory *m_OrderFactory;
	
	///组合报单表
	CCombOrderFactory *m_CombOrderFactory;
	
	///OTC报单表
	COTCOrderFactory *m_OTCOrderFactory;
	
	///隐式报单表
	CImplyOrderFactory *m_ImplyOrderFactory;
	
	///报价表
	CQuoteFactory *m_QuoteFactory;
	
	///分价表表
	CMBLMarketDataFactory *m_MBLMarketDataFactory;
	
	///成交表
	CTradeFactory *m_TradeFactory;
	
	///熔断阶段表
	CFusePhaseFactory *m_FusePhaseFactory;
	
	///执行宣告表
	CExecOrderFactory *m_ExecOrderFactory;
	
	///单边市情况表
	CUniPressureFactory *m_UniPressureFactory;
	
	///涨跌停板设置表
	CBasePriceLimitFactory *m_BasePriceLimitFactory;
	
	///信用限额表
	CCreditLimitFactory *m_CreditLimitFactory;
	
	///当日期货合约期权属性表
	CCurrInstrumentOptionFactory *m_CurrInstrumentOptionFactory;
	
	///由kernel强制指定的用户密码
	CPasswordType m_ForceUserPassword;
	
private:
	CFixMem *pMem;		///用来存放表的信息
};

#endif
