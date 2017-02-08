/////////////////////////////////////////////////////////////////////////
///@system 交易引擎系统
///@company 上海期货信息技术有限公司
///@file CDumpLog.h
///@brief定义了类CDumpLog
///@history 
///20041001	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef CDUMPLOG_H
#define CDUMPLOG_H

#include "CMemoryDB.h"

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusDumpTrigger是操作交易所数据同步状态时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusDumpTrigger: public CExchangeDataSyncStatusActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CExchangeDataSyncStatusDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CExchangeDataSyncStatusDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pExchangeDataSyncStatus	要加入的ExchangeDataSyncStatus
	virtual void beforeAdd(CWriteableExchangeDataSyncStatus *pExchangeDataSyncStatus);
	
	///更新前触发	
	///@param	pExchangeDataSyncStatus	被刷新的CExchangeDataSyncStatus
	///@param	pNewExchangeDataSyncStatus	新的值
	virtual void beforeUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pNewExchangeDataSyncStatus);
	
	///删除前触发
	///@param	pExchangeDataSyncStatus	要删除的CExchangeDataSyncStatus
	virtual void beforeRemove(CExchangeDataSyncStatus *pExchangeDataSyncStatus);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusDumpTrigger是操作结算组数据同步状态时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusDumpTrigger: public CSGDataSyncStatusActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSGDataSyncStatusDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSGDataSyncStatusDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSGDataSyncStatus	要加入的SGDataSyncStatus
	virtual void beforeAdd(CWriteableSGDataSyncStatus *pSGDataSyncStatus);
	
	///更新前触发	
	///@param	pSGDataSyncStatus	被刷新的CSGDataSyncStatus
	///@param	pNewSGDataSyncStatus	新的值
	virtual void beforeUpdate(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pNewSGDataSyncStatus);
	
	///删除前触发
	///@param	pSGDataSyncStatus	要删除的CSGDataSyncStatus
	virtual void beforeRemove(CSGDataSyncStatus *pSGDataSyncStatus);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeDumpTrigger是操作当前时间时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeDumpTrigger: public CCurrentTimeActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCurrentTimeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCurrentTimeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCurrentTime	要加入的CurrentTime
	virtual void beforeAdd(CWriteableCurrentTime *pCurrentTime);
	
	///更新前触发	
	///@param	pCurrentTime	被刷新的CCurrentTime
	///@param	pNewCurrentTime	新的值
	virtual void beforeUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pNewCurrentTime);
	
	///删除前触发
	///@param	pCurrentTime	要删除的CCurrentTime
	virtual void beforeRemove(CCurrentTime *pCurrentTime);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescDumpTrigger是操作数据中心描述时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescDumpTrigger: public CDataCenterDescActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CDataCenterDescDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CDataCenterDescDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pDataCenterDesc	要加入的DataCenterDesc
	virtual void beforeAdd(CWriteableDataCenterDesc *pDataCenterDesc);
	
	///更新前触发	
	///@param	pDataCenterDesc	被刷新的CDataCenterDesc
	///@param	pNewDataCenterDesc	新的值
	virtual void beforeUpdate(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pNewDataCenterDesc);
	
	///删除前触发
	///@param	pDataCenterDesc	要删除的CDataCenterDesc
	virtual void beforeRemove(CDataCenterDesc *pDataCenterDesc);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDumpTrigger是操作交易所时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDumpTrigger: public CExchangeActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CExchangeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CExchangeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pExchange	要加入的Exchange
	virtual void beforeAdd(CWriteableExchange *pExchange);
	
	///更新前触发	
	///@param	pExchange	被刷新的CExchange
	///@param	pNewExchange	新的值
	virtual void beforeUpdate(CExchange *pExchange, CWriteableExchange *pNewExchange);
	
	///删除前触发
	///@param	pExchange	要删除的CExchange
	virtual void beforeRemove(CExchange *pExchange);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupDumpTrigger是操作结算组时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupDumpTrigger: public CSettlementGroupActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSettlementGroupDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSettlementGroupDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSettlementGroup	要加入的SettlementGroup
	virtual void beforeAdd(CWriteableSettlementGroup *pSettlementGroup);
	
	///更新前触发	
	///@param	pSettlementGroup	被刷新的CSettlementGroup
	///@param	pNewSettlementGroup	新的值
	virtual void beforeUpdate(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pNewSettlementGroup);
	
	///删除前触发
	///@param	pSettlementGroup	要删除的CSettlementGroup
	virtual void beforeRemove(CSettlementGroup *pSettlementGroup);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDumpTrigger是操作市场时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDumpTrigger: public CMarketActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CMarketDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CMarketDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pMarket	要加入的Market
	virtual void beforeAdd(CWriteableMarket *pMarket);
	
	///更新前触发	
	///@param	pMarket	被刷新的CMarket
	///@param	pNewMarket	新的值
	virtual void beforeUpdate(CMarket *pMarket, CWriteableMarket *pNewMarket);
	
	///删除前触发
	///@param	pMarket	要删除的CMarket
	virtual void beforeRemove(CMarket *pMarket);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductDumpTrigger是操作市场产品关联时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductDumpTrigger: public CMarketProductActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CMarketProductDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CMarketProductDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pMarketProduct	要加入的MarketProduct
	virtual void beforeAdd(CWriteableMarketProduct *pMarketProduct);
	
	///更新前触发	
	///@param	pMarketProduct	被刷新的CMarketProduct
	///@param	pNewMarketProduct	新的值
	virtual void beforeUpdate(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pNewMarketProduct);
	
	///删除前触发
	///@param	pMarketProduct	要删除的CMarketProduct
	virtual void beforeRemove(CMarketProduct *pMarketProduct);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupDumpTrigger是操作市场产品组关联时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupDumpTrigger: public CMarketProductGroupActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CMarketProductGroupDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CMarketProductGroupDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pMarketProductGroup	要加入的MarketProductGroup
	virtual void beforeAdd(CWriteableMarketProductGroup *pMarketProductGroup);
	
	///更新前触发	
	///@param	pMarketProductGroup	被刷新的CMarketProductGroup
	///@param	pNewMarketProductGroup	新的值
	virtual void beforeUpdate(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pNewMarketProductGroup);
	
	///删除前触发
	///@param	pMarketProductGroup	要删除的CMarketProductGroup
	virtual void beforeRemove(CMarketProductGroup *pMarketProductGroup);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusDumpTrigger是操作行情发布状态时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusDumpTrigger: public CMdPubStatusActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CMdPubStatusDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CMdPubStatusDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pMdPubStatus	要加入的MdPubStatus
	virtual void beforeAdd(CWriteableMdPubStatus *pMdPubStatus);
	
	///更新前触发	
	///@param	pMdPubStatus	被刷新的CMdPubStatus
	///@param	pNewMdPubStatus	新的值
	virtual void beforeUpdate(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pNewMdPubStatus);
	
	///删除前触发
	///@param	pMdPubStatus	要删除的CMdPubStatus
	virtual void beforeRemove(CMdPubStatus *pMdPubStatus);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicDumpTrigger是操作行情主题时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicDumpTrigger: public CMarketDataTopicActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CMarketDataTopicDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CMarketDataTopicDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pMarketDataTopic	要加入的MarketDataTopic
	virtual void beforeAdd(CWriteableMarketDataTopic *pMarketDataTopic);
	
	///更新前触发	
	///@param	pMarketDataTopic	被刷新的CMarketDataTopic
	///@param	pNewMarketDataTopic	新的值
	virtual void beforeUpdate(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pNewMarketDataTopic);
	
	///删除前触发
	///@param	pMarketDataTopic	要删除的CMarketDataTopic
	virtual void beforeRemove(CMarketDataTopic *pMarketDataTopic);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeDumpTrigger是操作会员订阅市场时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeDumpTrigger: public CPartTopicSubscribeActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CPartTopicSubscribeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CPartTopicSubscribeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pPartTopicSubscribe	要加入的PartTopicSubscribe
	virtual void beforeAdd(CWriteablePartTopicSubscribe *pPartTopicSubscribe);
	
	///更新前触发	
	///@param	pPartTopicSubscribe	被刷新的CPartTopicSubscribe
	///@param	pNewPartTopicSubscribe	新的值
	virtual void beforeUpdate(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pNewPartTopicSubscribe);
	
	///删除前触发
	///@param	pPartTopicSubscribe	要删除的CPartTopicSubscribe
	virtual void beforeRemove(CPartTopicSubscribe *pPartTopicSubscribe);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CParticipantDumpTrigger是操作会员时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantDumpTrigger: public CParticipantActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CParticipantDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CParticipantDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pParticipant	要加入的Participant
	virtual void beforeAdd(CWriteableParticipant *pParticipant);
	
	///更新前触发	
	///@param	pParticipant	被刷新的CParticipant
	///@param	pNewParticipant	新的值
	virtual void beforeUpdate(CParticipant *pParticipant, CWriteableParticipant *pNewParticipant);
	
	///删除前触发
	///@param	pParticipant	要删除的CParticipant
	virtual void beforeRemove(CParticipant *pParticipant);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CUserDumpTrigger是操作用户时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserDumpTrigger: public CUserActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CUserDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CUserDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pUser	要加入的User
	virtual void beforeAdd(CWriteableUser *pUser);
	
	///更新前触发	
	///@param	pUser	被刷新的CUser
	///@param	pNewUser	新的值
	virtual void beforeUpdate(CUser *pUser, CWriteableUser *pNewUser);
	
	///删除前触发
	///@param	pUser	要删除的CUser
	virtual void beforeRemove(CUser *pUser);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CClientDumpTrigger是操作客户时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientDumpTrigger: public CClientActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CClientDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CClientDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pClient	要加入的Client
	virtual void beforeAdd(CWriteableClient *pClient);
	
	///更新前触发	
	///@param	pClient	被刷新的CClient
	///@param	pNewClient	新的值
	virtual void beforeUpdate(CClient *pClient, CWriteableClient *pNewClient);
	
	///删除前触发
	///@param	pClient	要删除的CClient
	virtual void beforeRemove(CClient *pClient);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CUserIPDumpTrigger是操作交易员IP地址时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPDumpTrigger: public CUserIPActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CUserIPDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CUserIPDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pUserIP	要加入的UserIP
	virtual void beforeAdd(CWriteableUserIP *pUserIP);
	
	///更新前触发	
	///@param	pUserIP	被刷新的CUserIP
	///@param	pNewUserIP	新的值
	virtual void beforeUpdate(CUserIP *pUserIP, CWriteableUserIP *pNewUserIP);
	
	///删除前触发
	///@param	pUserIP	要删除的CUserIP
	virtual void beforeRemove(CUserIP *pUserIP);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientDumpTrigger是操作会员客户关系时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientDumpTrigger: public CPartClientActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CPartClientDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CPartClientDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pPartClient	要加入的PartClient
	virtual void beforeAdd(CWriteablePartClient *pPartClient);
	
	///更新前触发	
	///@param	pPartClient	被刷新的CPartClient
	///@param	pNewPartClient	新的值
	virtual void beforeUpdate(CPartClient *pPartClient, CWriteablePartClient *pNewPartClient);
	
	///删除前触发
	///@param	pPartClient	要删除的CPartClient
	virtual void beforeRemove(CPartClient *pPartClient);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartDumpTrigger是操作结算交易会员关系时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartDumpTrigger: public CClearingTradingPartActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CClearingTradingPartDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CClearingTradingPartDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pClearingTradingPart	要加入的ClearingTradingPart
	virtual void beforeAdd(CWriteableClearingTradingPart *pClearingTradingPart);
	
	///更新前触发	
	///@param	pClearingTradingPart	被刷新的CClearingTradingPart
	///@param	pNewClearingTradingPart	新的值
	virtual void beforeUpdate(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pNewClearingTradingPart);
	
	///删除前触发
	///@param	pClearingTradingPart	要删除的CClearingTradingPart
	virtual void beforeRemove(CClearingTradingPart *pClearingTradingPart);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineDumpTrigger是操作别名定义时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineDumpTrigger: public CAliasDefineActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CAliasDefineDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CAliasDefineDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pAliasDefine	要加入的AliasDefine
	virtual void beforeAdd(CWriteableAliasDefine *pAliasDefine);
	
	///更新前触发	
	///@param	pAliasDefine	被刷新的CAliasDefine
	///@param	pNewAliasDefine	新的值
	virtual void beforeUpdate(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pNewAliasDefine);
	
	///删除前触发
	///@param	pAliasDefine	要删除的CAliasDefine
	virtual void beforeRemove(CAliasDefine *pAliasDefine);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightDumpTrigger是操作用户功能权限时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightDumpTrigger: public CUserFunctionRightActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CUserFunctionRightDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CUserFunctionRightDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pUserFunctionRight	要加入的UserFunctionRight
	virtual void beforeAdd(CWriteableUserFunctionRight *pUserFunctionRight);
	
	///更新前触发	
	///@param	pUserFunctionRight	被刷新的CUserFunctionRight
	///@param	pNewUserFunctionRight	新的值
	virtual void beforeUpdate(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pNewUserFunctionRight);
	
	///删除前触发
	///@param	pUserFunctionRight	要删除的CUserFunctionRight
	virtual void beforeRemove(CUserFunctionRight *pUserFunctionRight);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CAccountDumpTrigger是操作资金账户时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountDumpTrigger: public CAccountActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CAccountDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CAccountDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pAccount	要加入的Account
	virtual void beforeAdd(CWriteableAccount *pAccount);
	
	///更新前触发	
	///@param	pAccount	被刷新的CAccount
	///@param	pNewAccount	新的值
	virtual void beforeUpdate(CAccount *pAccount, CWriteableAccount *pNewAccount);
	
	///删除前触发
	///@param	pAccount	要删除的CAccount
	virtual void beforeRemove(CAccount *pAccount);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxDumpTrigger是操作用户通讯量时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxDumpTrigger: public CUserCommFluxActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CUserCommFluxDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CUserCommFluxDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pUserCommFlux	要加入的UserCommFlux
	virtual void beforeAdd(CWriteableUserCommFlux *pUserCommFlux);
	
	///更新前触发	
	///@param	pUserCommFlux	被刷新的CUserCommFlux
	///@param	pNewUserCommFlux	新的值
	virtual void beforeUpdate(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pNewUserCommFlux);
	
	///删除前触发
	///@param	pUserCommFlux	要删除的CUserCommFlux
	virtual void beforeRemove(CUserCommFlux *pUserCommFlux);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogDumpTrigger是操作行情流水时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogDumpTrigger: public CMarketDataLogActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CMarketDataLogDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CMarketDataLogDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pMarketDataLog	要加入的MarketDataLog
	virtual void beforeAdd(CWriteableMarketDataLog *pMarketDataLog);
	
	///更新前触发	
	///@param	pMarketDataLog	被刷新的CMarketDataLog
	///@param	pNewMarketDataLog	新的值
	virtual void beforeUpdate(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pNewMarketDataLog);
	
	///删除前触发
	///@param	pMarketDataLog	要删除的CMarketDataLog
	virtual void beforeRemove(CMarketDataLog *pMarketDataLog);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionDumpTrigger是操作交易员在线会话时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionDumpTrigger: public CUserSessionActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CUserSessionDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CUserSessionDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pUserSession	要加入的UserSession
	virtual void beforeAdd(CWriteableUserSession *pUserSession);
	
	///更新前触发	
	///@param	pUserSession	被刷新的CUserSession
	///@param	pNewUserSession	新的值
	virtual void beforeUpdate(CUserSession *pUserSession, CWriteableUserSession *pNewUserSession);
	
	///删除前触发
	///@param	pUserSession	要删除的CUserSession
	virtual void beforeRemove(CUserSession *pUserSession);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionDumpTrigger是操作行情订阅者在线会话时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionDumpTrigger: public CMDSessionActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CMDSessionDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CMDSessionDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pMDSession	要加入的MDSession
	virtual void beforeAdd(CWriteableMDSession *pMDSession);
	
	///更新前触发	
	///@param	pMDSession	被刷新的CMDSession
	///@param	pNewMDSession	新的值
	virtual void beforeUpdate(CMDSession *pMDSession, CWriteableMDSession *pNewMDSession);
	
	///删除前触发
	///@param	pMDSession	要删除的CMDSession
	virtual void beforeRemove(CMDSession *pMDSession);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoDumpTrigger是操作用户登陆登出信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoDumpTrigger: public CLoginInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CLoginInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CLoginInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pLoginInfo	要加入的LoginInfo
	virtual void beforeAdd(CWriteableLoginInfo *pLoginInfo);
	
	///更新前触发	
	///@param	pLoginInfo	被刷新的CLoginInfo
	///@param	pNewLoginInfo	新的值
	virtual void beforeUpdate(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pNewLoginInfo);
	
	///删除前触发
	///@param	pLoginInfo	要删除的CLoginInfo
	virtual void beforeRemove(CLoginInfo *pLoginInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailDumpTrigger是操作深度市场行情明细时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailDumpTrigger: public CDepthMarketDataDetailActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CDepthMarketDataDetailDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CDepthMarketDataDetailDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pDepthMarketDataDetail	要加入的DepthMarketDataDetail
	virtual void beforeAdd(CWriteableDepthMarketDataDetail *pDepthMarketDataDetail);
	
	///更新前触发	
	///@param	pDepthMarketDataDetail	被刷新的CDepthMarketDataDetail
	///@param	pNewDepthMarketDataDetail	新的值
	virtual void beforeUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pNewDepthMarketDataDetail);
	
	///删除前触发
	///@param	pDepthMarketDataDetail	要删除的CDepthMarketDataDetail
	virtual void beforeRemove(CDepthMarketDataDetail *pDepthMarketDataDetail);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailDumpTrigger是操作合约交易状态流水时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailDumpTrigger: public CInstrumentStatusDetailActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CInstrumentStatusDetailDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CInstrumentStatusDetailDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pInstrumentStatusDetail	要加入的InstrumentStatusDetail
	virtual void beforeAdd(CWriteableInstrumentStatusDetail *pInstrumentStatusDetail);
	
	///更新前触发	
	///@param	pInstrumentStatusDetail	被刷新的CInstrumentStatusDetail
	///@param	pNewInstrumentStatusDetail	新的值
	virtual void beforeUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pNewInstrumentStatusDetail);
	
	///删除前触发
	///@param	pInstrumentStatusDetail	要删除的CInstrumentStatusDetail
	virtual void beforeRemove(CInstrumentStatusDetail *pInstrumentStatusDetail);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusDumpTrigger是操作前置状态时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusDumpTrigger: public CFrontStatusActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CFrontStatusDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CFrontStatusDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pFrontStatus	要加入的FrontStatus
	virtual void beforeAdd(CWriteableFrontStatus *pFrontStatus);
	
	///更新前触发	
	///@param	pFrontStatus	被刷新的CFrontStatus
	///@param	pNewFrontStatus	新的值
	virtual void beforeUpdate(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pNewFrontStatus);
	
	///删除前触发
	///@param	pFrontStatus	要删除的CFrontStatus
	virtual void beforeRemove(CFrontStatus *pFrontStatus);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDDumpTrigger是操作最大本地报单号时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDDumpTrigger: public CMaxLocalIDActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CMaxLocalIDDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CMaxLocalIDDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pMaxLocalID	要加入的MaxLocalID
	virtual void beforeAdd(CWriteableMaxLocalID *pMaxLocalID);
	
	///更新前触发	
	///@param	pMaxLocalID	被刷新的CMaxLocalID
	///@param	pNewMaxLocalID	新的值
	virtual void beforeUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pNewMaxLocalID);
	
	///删除前触发
	///@param	pMaxLocalID	要删除的CMaxLocalID
	virtual void beforeRemove(CMaxLocalID *pMaxLocalID);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CBulletinDumpTrigger是操作公告信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinDumpTrigger: public CBulletinActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CBulletinDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CBulletinDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pBulletin	要加入的Bulletin
	virtual void beforeAdd(CWriteableBulletin *pBulletin);
	
	///更新前触发	
	///@param	pBulletin	被刷新的CBulletin
	///@param	pNewBulletin	新的值
	virtual void beforeUpdate(CBulletin *pBulletin, CWriteableBulletin *pNewBulletin);
	
	///删除前触发
	///@param	pBulletin	要删除的CBulletin
	virtual void beforeRemove(CBulletin *pBulletin);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyDumpTrigger是操作行情变动时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyDumpTrigger: public CMarketDataModifyActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CMarketDataModifyDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CMarketDataModifyDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pMarketDataModify	要加入的MarketDataModify
	virtual void beforeAdd(CWriteableMarketDataModify *pMarketDataModify);
	
	///更新前触发	
	///@param	pMarketDataModify	被刷新的CMarketDataModify
	///@param	pNewMarketDataModify	新的值
	virtual void beforeUpdate(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pNewMarketDataModify);
	
	///删除前触发
	///@param	pMarketDataModify	要删除的CMarketDataModify
	virtual void beforeRemove(CMarketDataModify *pMarketDataModify);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDumpTrigger是操作深度行情时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDumpTrigger: public CDepthMarketDataActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CDepthMarketDataDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CDepthMarketDataDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pDepthMarketData	要加入的DepthMarketData
	virtual void beforeAdd(CWriteableDepthMarketData *pDepthMarketData);
	
	///更新前触发	
	///@param	pDepthMarketData	被刷新的CDepthMarketData
	///@param	pNewDepthMarketData	新的值
	virtual void beforeUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pNewDepthMarketData);
	
	///删除前触发
	///@param	pDepthMarketData	要删除的CDepthMarketData
	virtual void beforeRemove(CDepthMarketData *pDepthMarketData);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataDumpTrigger是操作分主题行情时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataDumpTrigger: public CTopicMarketDataActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CTopicMarketDataDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CTopicMarketDataDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pTopicMarketData	要加入的TopicMarketData
	virtual void beforeAdd(CWriteableTopicMarketData *pTopicMarketData);
	
	///更新前触发	
	///@param	pTopicMarketData	被刷新的CTopicMarketData
	///@param	pNewTopicMarketData	新的值
	virtual void beforeUpdate(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pNewTopicMarketData);
	
	///删除前触发
	///@param	pTopicMarketData	要删除的CTopicMarketData
	virtual void beforeRemove(CTopicMarketData *pTopicMarketData);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionDumpTrigger是操作分主题行情快照时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionDumpTrigger: public CTopicMarketDataVersionActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CTopicMarketDataVersionDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CTopicMarketDataVersionDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pTopicMarketDataVersion	要加入的TopicMarketDataVersion
	virtual void beforeAdd(CWriteableTopicMarketDataVersion *pTopicMarketDataVersion);
	
	///更新前触发	
	///@param	pTopicMarketDataVersion	被刷新的CTopicMarketDataVersion
	///@param	pNewTopicMarketDataVersion	新的值
	virtual void beforeUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pNewTopicMarketDataVersion);
	
	///删除前触发
	///@param	pTopicMarketDataVersion	要删除的CTopicMarketDataVersion
	virtual void beforeRemove(CTopicMarketDataVersion *pTopicMarketDataVersion);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CInformationDumpTrigger是操作信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationDumpTrigger: public CInformationActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CInformationDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CInformationDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pInformation	要加入的Information
	virtual void beforeAdd(CWriteableInformation *pInformation);
	
	///更新前触发	
	///@param	pInformation	被刷新的CInformation
	///@param	pNewInformation	新的值
	virtual void beforeUpdate(CInformation *pInformation, CWriteableInformation *pNewInformation);
	
	///删除前触发
	///@param	pInformation	要删除的CInformation
	virtual void beforeRemove(CInformation *pInformation);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///COrderCountDumpTrigger是操作报单数量时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountDumpTrigger: public COrderCountActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	COrderCountDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~COrderCountDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pOrderCount	要加入的OrderCount
	virtual void beforeAdd(CWriteableOrderCount *pOrderCount);
	
	///更新前触发	
	///@param	pOrderCount	被刷新的COrderCount
	///@param	pNewOrderCount	新的值
	virtual void beforeUpdate(COrderCount *pOrderCount, CWriteableOrderCount *pNewOrderCount);
	
	///删除前触发
	///@param	pOrderCount	要删除的COrderCount
	virtual void beforeRemove(COrderCount *pOrderCount);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentDumpTrigger是操作合约时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentDumpTrigger: public CInstrumentActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CInstrumentDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CInstrumentDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pInstrument	要加入的Instrument
	virtual void beforeAdd(CWriteableInstrument *pInstrument);
	
	///更新前触发	
	///@param	pInstrument	被刷新的CInstrument
	///@param	pNewInstrument	新的值
	virtual void beforeUpdate(CInstrument *pInstrument, CWriteableInstrument *pNewInstrument);
	
	///删除前触发
	///@param	pInstrument	要删除的CInstrument
	virtual void beforeRemove(CInstrument *pInstrument);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegDumpTrigger是操作组合合约单腿时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegDumpTrigger: public CCombinationLegActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCombinationLegDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCombinationLegDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCombinationLeg	要加入的CombinationLeg
	virtual void beforeAdd(CWriteableCombinationLeg *pCombinationLeg);
	
	///更新前触发	
	///@param	pCombinationLeg	被刷新的CCombinationLeg
	///@param	pNewCombinationLeg	新的值
	virtual void beforeUpdate(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pNewCombinationLeg);
	
	///删除前触发
	///@param	pCombinationLeg	要删除的CCombinationLeg
	virtual void beforeRemove(CCombinationLeg *pCombinationLeg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountDumpTrigger是操作会员账户关系时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountDumpTrigger: public CPartRoleAccountActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CPartRoleAccountDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CPartRoleAccountDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pPartRoleAccount	要加入的PartRoleAccount
	virtual void beforeAdd(CWriteablePartRoleAccount *pPartRoleAccount);
	
	///更新前触发	
	///@param	pPartRoleAccount	被刷新的CPartRoleAccount
	///@param	pNewPartRoleAccount	新的值
	virtual void beforeUpdate(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pNewPartRoleAccount);
	
	///删除前触发
	///@param	pPartRoleAccount	要删除的CPartRoleAccount
	virtual void beforeRemove(CPartRoleAccount *pPartRoleAccount);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleDumpTrigger是操作会员产品角色时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleDumpTrigger: public CPartProductRoleActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CPartProductRoleDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CPartProductRoleDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pPartProductRole	要加入的PartProductRole
	virtual void beforeAdd(CWriteablePartProductRole *pPartProductRole);
	
	///更新前触发	
	///@param	pPartProductRole	被刷新的CPartProductRole
	///@param	pNewPartProductRole	新的值
	virtual void beforeUpdate(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pNewPartProductRole);
	
	///删除前触发
	///@param	pPartProductRole	要删除的CPartProductRole
	virtual void beforeRemove(CPartProductRole *pPartProductRole);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightDumpTrigger是操作会员产品交易权限时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightDumpTrigger: public CPartProductRightActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CPartProductRightDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CPartProductRightDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pPartProductRight	要加入的PartProductRight
	virtual void beforeAdd(CWriteablePartProductRight *pPartProductRight);
	
	///更新前触发	
	///@param	pPartProductRight	被刷新的CPartProductRight
	///@param	pNewPartProductRight	新的值
	virtual void beforeUpdate(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pNewPartProductRight);
	
	///删除前触发
	///@param	pPartProductRight	要删除的CPartProductRight
	virtual void beforeRemove(CPartProductRight *pPartProductRight);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightDumpTrigger是操作会员合约交易权限时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightDumpTrigger: public CPartInstrumentRightActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CPartInstrumentRightDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CPartInstrumentRightDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pPartInstrumentRight	要加入的PartInstrumentRight
	virtual void beforeAdd(CWriteablePartInstrumentRight *pPartInstrumentRight);
	
	///更新前触发	
	///@param	pPartInstrumentRight	被刷新的CPartInstrumentRight
	///@param	pNewPartInstrumentRight	新的值
	virtual void beforeUpdate(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pNewPartInstrumentRight);
	
	///删除前触发
	///@param	pPartInstrumentRight	要删除的CPartInstrumentRight
	virtual void beforeRemove(CPartInstrumentRight *pPartInstrumentRight);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightDumpTrigger是操作客户产品交易权限时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightDumpTrigger: public CClientProductRightActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CClientProductRightDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CClientProductRightDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pClientProductRight	要加入的ClientProductRight
	virtual void beforeAdd(CWriteableClientProductRight *pClientProductRight);
	
	///更新前触发	
	///@param	pClientProductRight	被刷新的CClientProductRight
	///@param	pNewClientProductRight	新的值
	virtual void beforeUpdate(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pNewClientProductRight);
	
	///删除前触发
	///@param	pClientProductRight	要删除的CClientProductRight
	virtual void beforeRemove(CClientProductRight *pClientProductRight);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightDumpTrigger是操作客户合约交易权限时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightDumpTrigger: public CClientInstrumentRightActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CClientInstrumentRightDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CClientInstrumentRightDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pClientInstrumentRight	要加入的ClientInstrumentRight
	virtual void beforeAdd(CWriteableClientInstrumentRight *pClientInstrumentRight);
	
	///更新前触发	
	///@param	pClientInstrumentRight	被刷新的CClientInstrumentRight
	///@param	pNewClientInstrumentRight	新的值
	virtual void beforeUpdate(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pNewClientInstrumentRight);
	
	///删除前触发
	///@param	pClientInstrumentRight	要删除的CClientInstrumentRight
	virtual void beforeRemove(CClientInstrumentRight *pClientInstrumentRight);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightDumpTrigger是操作会员客户产品交易权限时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightDumpTrigger: public CPartClientProductRightActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CPartClientProductRightDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CPartClientProductRightDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pPartClientProductRight	要加入的PartClientProductRight
	virtual void beforeAdd(CWriteablePartClientProductRight *pPartClientProductRight);
	
	///更新前触发	
	///@param	pPartClientProductRight	被刷新的CPartClientProductRight
	///@param	pNewPartClientProductRight	新的值
	virtual void beforeUpdate(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pNewPartClientProductRight);
	
	///删除前触发
	///@param	pPartClientProductRight	要删除的CPartClientProductRight
	virtual void beforeRemove(CPartClientProductRight *pPartClientProductRight);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightDumpTrigger是操作会员客户合约交易权限时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightDumpTrigger: public CPartClientInstrumentRightActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CPartClientInstrumentRightDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CPartClientInstrumentRightDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pPartClientInstrumentRight	要加入的PartClientInstrumentRight
	virtual void beforeAdd(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight);
	
	///更新前触发	
	///@param	pPartClientInstrumentRight	被刷新的CPartClientInstrumentRight
	///@param	pNewPartClientInstrumentRight	新的值
	virtual void beforeUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pNewPartClientInstrumentRight);
	
	///删除前触发
	///@param	pPartClientInstrumentRight	要删除的CPartClientInstrumentRight
	virtual void beforeRemove(CPartClientInstrumentRight *pPartClientInstrumentRight);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyDumpTrigger是操作产品属性时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyDumpTrigger: public CCurrProductPropertyActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCurrProductPropertyDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCurrProductPropertyDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCurrProductProperty	要加入的CurrProductProperty
	virtual void beforeAdd(CWriteableCurrProductProperty *pCurrProductProperty);
	
	///更新前触发	
	///@param	pCurrProductProperty	被刷新的CCurrProductProperty
	///@param	pNewCurrProductProperty	新的值
	virtual void beforeUpdate(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pNewCurrProductProperty);
	
	///删除前触发
	///@param	pCurrProductProperty	要删除的CCurrProductProperty
	virtual void beforeRemove(CCurrProductProperty *pCurrProductProperty);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyDumpTrigger是操作合约属性时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyDumpTrigger: public CCurrInstrumentPropertyActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCurrInstrumentPropertyDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCurrInstrumentPropertyDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCurrInstrumentProperty	要加入的CurrInstrumentProperty
	virtual void beforeAdd(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty);
	
	///更新前触发	
	///@param	pCurrInstrumentProperty	被刷新的CCurrInstrumentProperty
	///@param	pNewCurrInstrumentProperty	新的值
	virtual void beforeUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pNewCurrInstrumentProperty);
	
	///删除前触发
	///@param	pCurrInstrumentProperty	要删除的CCurrInstrumentProperty
	virtual void beforeRemove(CCurrInstrumentProperty *pCurrInstrumentProperty);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingDumpTrigger是操作当前价格绑定时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingDumpTrigger: public CCurrPriceBandingActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCurrPriceBandingDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCurrPriceBandingDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCurrPriceBanding	要加入的CurrPriceBanding
	virtual void beforeAdd(CWriteableCurrPriceBanding *pCurrPriceBanding);
	
	///更新前触发	
	///@param	pCurrPriceBanding	被刷新的CCurrPriceBanding
	///@param	pNewCurrPriceBanding	新的值
	virtual void beforeUpdate(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pNewCurrPriceBanding);
	
	///删除前触发
	///@param	pCurrPriceBanding	要删除的CCurrPriceBanding
	virtual void beforeRemove(CCurrPriceBanding *pCurrPriceBanding);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDumpTrigger是操作当天合约保证金率时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDumpTrigger: public CCurrMarginRateActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCurrMarginRateDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCurrMarginRateDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCurrMarginRate	要加入的CurrMarginRate
	virtual void beforeAdd(CWriteableCurrMarginRate *pCurrMarginRate);
	
	///更新前触发	
	///@param	pCurrMarginRate	被刷新的CCurrMarginRate
	///@param	pNewCurrMarginRate	新的值
	virtual void beforeUpdate(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pNewCurrMarginRate);
	
	///删除前触发
	///@param	pCurrMarginRate	要删除的CCurrMarginRate
	virtual void beforeRemove(CCurrMarginRate *pCurrMarginRate);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailDumpTrigger是操作当天合约保证金率的详细内容时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailDumpTrigger: public CCurrMarginRateDetailActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCurrMarginRateDetailDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCurrMarginRateDetailDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCurrMarginRateDetail	要加入的CurrMarginRateDetail
	virtual void beforeAdd(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail);
	
	///更新前触发	
	///@param	pCurrMarginRateDetail	被刷新的CCurrMarginRateDetail
	///@param	pNewCurrMarginRateDetail	新的值
	virtual void beforeUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pNewCurrMarginRateDetail);
	
	///删除前触发
	///@param	pCurrMarginRateDetail	要删除的CCurrMarginRateDetail
	virtual void beforeRemove(CCurrMarginRateDetail *pCurrMarginRateDetail);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDumpTrigger是操作当前会员合约限仓时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDumpTrigger: public CCurrPartPosiLimitActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCurrPartPosiLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCurrPartPosiLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCurrPartPosiLimit	要加入的CurrPartPosiLimit
	virtual void beforeAdd(CWriteableCurrPartPosiLimit *pCurrPartPosiLimit);
	
	///更新前触发	
	///@param	pCurrPartPosiLimit	被刷新的CCurrPartPosiLimit
	///@param	pNewCurrPartPosiLimit	新的值
	virtual void beforeUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pNewCurrPartPosiLimit);
	
	///删除前触发
	///@param	pCurrPartPosiLimit	要删除的CCurrPartPosiLimit
	virtual void beforeRemove(CCurrPartPosiLimit *pCurrPartPosiLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailDumpTrigger是操作当前会员合约限仓的详细内容时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailDumpTrigger: public CCurrPartPosiLimitDetailActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCurrPartPosiLimitDetailDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCurrPartPosiLimitDetailDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCurrPartPosiLimitDetail	要加入的CurrPartPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);
	
	///更新前触发	
	///@param	pCurrPartPosiLimitDetail	被刷新的CCurrPartPosiLimitDetail
	///@param	pNewCurrPartPosiLimitDetail	新的值
	virtual void beforeUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pNewCurrPartPosiLimitDetail);
	
	///删除前触发
	///@param	pCurrPartPosiLimitDetail	要删除的CCurrPartPosiLimitDetail
	virtual void beforeRemove(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDumpTrigger是操作当前客户合约限仓时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDumpTrigger: public CCurrClientPosiLimitActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCurrClientPosiLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCurrClientPosiLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCurrClientPosiLimit	要加入的CurrClientPosiLimit
	virtual void beforeAdd(CWriteableCurrClientPosiLimit *pCurrClientPosiLimit);
	
	///更新前触发	
	///@param	pCurrClientPosiLimit	被刷新的CCurrClientPosiLimit
	///@param	pNewCurrClientPosiLimit	新的值
	virtual void beforeUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pNewCurrClientPosiLimit);
	
	///删除前触发
	///@param	pCurrClientPosiLimit	要删除的CCurrClientPosiLimit
	virtual void beforeRemove(CCurrClientPosiLimit *pCurrClientPosiLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailDumpTrigger是操作当前客户合约限仓的详细内容时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailDumpTrigger: public CCurrClientPosiLimitDetailActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCurrClientPosiLimitDetailDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCurrClientPosiLimitDetailDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCurrClientPosiLimitDetail	要加入的CurrClientPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);
	
	///更新前触发	
	///@param	pCurrClientPosiLimitDetail	被刷新的CCurrClientPosiLimitDetail
	///@param	pNewCurrClientPosiLimitDetail	新的值
	virtual void beforeUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pNewCurrClientPosiLimitDetail);
	
	///删除前触发
	///@param	pCurrClientPosiLimitDetail	要删除的CCurrClientPosiLimitDetail
	virtual void beforeRemove(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDumpTrigger是操作当前特殊客户合约限仓时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDumpTrigger: public CCurrSpecialPosiLimitActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCurrSpecialPosiLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCurrSpecialPosiLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCurrSpecialPosiLimit	要加入的CurrSpecialPosiLimit
	virtual void beforeAdd(CWriteableCurrSpecialPosiLimit *pCurrSpecialPosiLimit);
	
	///更新前触发	
	///@param	pCurrSpecialPosiLimit	被刷新的CCurrSpecialPosiLimit
	///@param	pNewCurrSpecialPosiLimit	新的值
	virtual void beforeUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pNewCurrSpecialPosiLimit);
	
	///删除前触发
	///@param	pCurrSpecialPosiLimit	要删除的CCurrSpecialPosiLimit
	virtual void beforeRemove(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailDumpTrigger是操作当前特殊客户合约限仓的详细内容时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailDumpTrigger: public CCurrSpecialPosiLimitDetailActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCurrSpecialPosiLimitDetailDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCurrSpecialPosiLimitDetailDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCurrSpecialPosiLimitDetail	要加入的CurrSpecialPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);
	
	///更新前触发	
	///@param	pCurrSpecialPosiLimitDetail	被刷新的CCurrSpecialPosiLimitDetail
	///@param	pNewCurrSpecialPosiLimitDetail	新的值
	virtual void beforeUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pNewCurrSpecialPosiLimitDetail);
	
	///删除前触发
	///@param	pCurrSpecialPosiLimitDetail	要删除的CCurrSpecialPosiLimitDetail
	virtual void beforeRemove(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleDumpTrigger是操作当前合约套期保值属性时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleDumpTrigger: public CCurrHedgeRuleActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCurrHedgeRuleDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCurrHedgeRuleDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCurrHedgeRule	要加入的CurrHedgeRule
	virtual void beforeAdd(CWriteableCurrHedgeRule *pCurrHedgeRule);
	
	///更新前触发	
	///@param	pCurrHedgeRule	被刷新的CCurrHedgeRule
	///@param	pNewCurrHedgeRule	新的值
	virtual void beforeUpdate(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pNewCurrHedgeRule);
	
	///删除前触发
	///@param	pCurrHedgeRule	要删除的CCurrHedgeRule
	virtual void beforeRemove(CCurrHedgeRule *pCurrHedgeRule);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrDumpTrigger是操作当前合约交易阶段属性时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrDumpTrigger: public CCurrTradingSegmentAttrActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCurrTradingSegmentAttrDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCurrTradingSegmentAttrDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCurrTradingSegmentAttr	要加入的CurrTradingSegmentAttr
	virtual void beforeAdd(CWriteableCurrTradingSegmentAttr *pCurrTradingSegmentAttr);
	
	///更新前触发	
	///@param	pCurrTradingSegmentAttr	被刷新的CCurrTradingSegmentAttr
	///@param	pNewCurrTradingSegmentAttr	新的值
	virtual void beforeUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pNewCurrTradingSegmentAttr);
	
	///删除前触发
	///@param	pCurrTradingSegmentAttr	要删除的CCurrTradingSegmentAttr
	virtual void beforeRemove(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseDumpTrigger是操作当前合约熔断属性时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseDumpTrigger: public CCurrFuseActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCurrFuseDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCurrFuseDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCurrFuse	要加入的CurrFuse
	virtual void beforeAdd(CWriteableCurrFuse *pCurrFuse);
	
	///更新前触发	
	///@param	pCurrFuse	被刷新的CCurrFuse
	///@param	pNewCurrFuse	新的值
	virtual void beforeUpdate(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pNewCurrFuse);
	
	///删除前触发
	///@param	pCurrFuse	要删除的CCurrFuse
	virtual void beforeRemove(CCurrFuse *pCurrFuse);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountDumpTrigger是操作交易账户时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountDumpTrigger: public CTradingAccountActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CTradingAccountDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CTradingAccountDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pTradingAccount	要加入的TradingAccount
	virtual void beforeAdd(CWriteableTradingAccount *pTradingAccount);
	
	///更新前触发	
	///@param	pTradingAccount	被刷新的CTradingAccount
	///@param	pNewTradingAccount	新的值
	virtual void beforeUpdate(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pNewTradingAccount);
	
	///删除前触发
	///@param	pTradingAccount	要删除的CTradingAccount
	virtual void beforeRemove(CTradingAccount *pTradingAccount);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountDumpTrigger是操作基本准备金账户时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountDumpTrigger: public CBaseReserveAccountActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CBaseReserveAccountDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CBaseReserveAccountDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pBaseReserveAccount	要加入的BaseReserveAccount
	virtual void beforeAdd(CWriteableBaseReserveAccount *pBaseReserveAccount);
	
	///更新前触发	
	///@param	pBaseReserveAccount	被刷新的CBaseReserveAccount
	///@param	pNewBaseReserveAccount	新的值
	virtual void beforeUpdate(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pNewBaseReserveAccount);
	
	///删除前触发
	///@param	pBaseReserveAccount	要删除的CBaseReserveAccount
	virtual void beforeRemove(CBaseReserveAccount *pBaseReserveAccount);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionDumpTrigger是操作会员持仓时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionDumpTrigger: public CPartPositionActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CPartPositionDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CPartPositionDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pPartPosition	要加入的PartPosition
	virtual void beforeAdd(CWriteablePartPosition *pPartPosition);
	
	///更新前触发	
	///@param	pPartPosition	被刷新的CPartPosition
	///@param	pNewPartPosition	新的值
	virtual void beforeUpdate(CPartPosition *pPartPosition, CWriteablePartPosition *pNewPartPosition);
	
	///删除前触发
	///@param	pPartPosition	要删除的CPartPosition
	virtual void beforeRemove(CPartPosition *pPartPosition);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionDumpTrigger是操作客户持仓时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionDumpTrigger: public CClientPositionActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CClientPositionDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CClientPositionDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pClientPosition	要加入的ClientPosition
	virtual void beforeAdd(CWriteableClientPosition *pClientPosition);
	
	///更新前触发	
	///@param	pClientPosition	被刷新的CClientPosition
	///@param	pNewClientPosition	新的值
	virtual void beforeUpdate(CClientPosition *pClientPosition, CWriteableClientPosition *pNewClientPosition);
	
	///删除前触发
	///@param	pClientPosition	要删除的CClientPosition
	virtual void beforeRemove(CClientPosition *pClientPosition);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeDumpTrigger是操作保值额度量时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeDumpTrigger: public CHedgeVolumeActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CHedgeVolumeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CHedgeVolumeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pHedgeVolume	要加入的HedgeVolume
	virtual void beforeAdd(CWriteableHedgeVolume *pHedgeVolume);
	
	///更新前触发	
	///@param	pHedgeVolume	被刷新的CHedgeVolume
	///@param	pNewHedgeVolume	新的值
	virtual void beforeUpdate(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pNewHedgeVolume);
	
	///删除前触发
	///@param	pHedgeVolume	要删除的CHedgeVolume
	virtual void beforeRemove(CHedgeVolume *pHedgeVolume);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderDumpTrigger是操作历史报单时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderDumpTrigger: public CRemainOrderActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CRemainOrderDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CRemainOrderDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pRemainOrder	要加入的RemainOrder
	virtual void beforeAdd(CWriteableRemainOrder *pRemainOrder);
	
	///更新前触发	
	///@param	pRemainOrder	被刷新的CRemainOrder
	///@param	pNewRemainOrder	新的值
	virtual void beforeUpdate(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pNewRemainOrder);
	
	///删除前触发
	///@param	pRemainOrder	要删除的CRemainOrder
	virtual void beforeRemove(CRemainOrder *pRemainOrder);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataDumpTrigger是操作行情时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataDumpTrigger: public CMarketDataActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CMarketDataDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CMarketDataDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pMarketData	要加入的MarketData
	virtual void beforeAdd(CWriteableMarketData *pMarketData);
	
	///更新前触发	
	///@param	pMarketData	被刷新的CMarketData
	///@param	pNewMarketData	新的值
	virtual void beforeUpdate(CMarketData *pMarketData, CWriteableMarketData *pNewMarketData);
	
	///删除前触发
	///@param	pMarketData	要删除的CMarketData
	virtual void beforeRemove(CMarketData *pMarketData);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionDumpTrigger是操作结算会员持仓时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionDumpTrigger: public CClearingPartPositionActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CClearingPartPositionDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CClearingPartPositionDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pClearingPartPosition	要加入的ClearingPartPosition
	virtual void beforeAdd(CWriteableClearingPartPosition *pClearingPartPosition);
	
	///更新前触发	
	///@param	pClearingPartPosition	被刷新的CClearingPartPosition
	///@param	pNewClearingPartPosition	新的值
	virtual void beforeUpdate(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pNewClearingPartPosition);
	
	///删除前触发
	///@param	pClearingPartPosition	要删除的CClearingPartPosition
	virtual void beforeRemove(CClearingPartPosition *pClearingPartPosition);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDumpTrigger是操作合约状态时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDumpTrigger: public CInstrumentStatusActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CInstrumentStatusDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CInstrumentStatusDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pInstrumentStatus	要加入的InstrumentStatus
	virtual void beforeAdd(CWriteableInstrumentStatus *pInstrumentStatus);
	
	///更新前触发	
	///@param	pInstrumentStatus	被刷新的CInstrumentStatus
	///@param	pNewInstrumentStatus	新的值
	virtual void beforeUpdate(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pNewInstrumentStatus);
	
	///删除前触发
	///@param	pInstrumentStatus	要删除的CInstrumentStatus
	virtual void beforeRemove(CInstrumentStatus *pInstrumentStatus);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///COrderDumpTrigger是操作报单时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderDumpTrigger: public COrderActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	COrderDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~COrderDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pOrder	要加入的Order
	virtual void beforeAdd(CWriteableOrder *pOrder);
	
	///更新前触发	
	///@param	pOrder	被刷新的COrder
	///@param	pNewOrder	新的值
	virtual void beforeUpdate(COrder *pOrder, CWriteableOrder *pNewOrder);
	
	///删除前触发
	///@param	pOrder	要删除的COrder
	virtual void beforeRemove(COrder *pOrder);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderDumpTrigger是操作组合报单时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderDumpTrigger: public CCombOrderActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCombOrderDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCombOrderDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCombOrder	要加入的CombOrder
	virtual void beforeAdd(CWriteableCombOrder *pCombOrder);
	
	///更新前触发	
	///@param	pCombOrder	被刷新的CCombOrder
	///@param	pNewCombOrder	新的值
	virtual void beforeUpdate(CCombOrder *pCombOrder, CWriteableCombOrder *pNewCombOrder);
	
	///删除前触发
	///@param	pCombOrder	要删除的CCombOrder
	virtual void beforeRemove(CCombOrder *pCombOrder);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderDumpTrigger是操作OTC报单时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderDumpTrigger: public COTCOrderActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	COTCOrderDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~COTCOrderDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pOTCOrder	要加入的OTCOrder
	virtual void beforeAdd(CWriteableOTCOrder *pOTCOrder);
	
	///更新前触发	
	///@param	pOTCOrder	被刷新的COTCOrder
	///@param	pNewOTCOrder	新的值
	virtual void beforeUpdate(COTCOrder *pOTCOrder, CWriteableOTCOrder *pNewOTCOrder);
	
	///删除前触发
	///@param	pOTCOrder	要删除的COTCOrder
	virtual void beforeRemove(COTCOrder *pOTCOrder);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderDumpTrigger是操作隐式报单时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderDumpTrigger: public CImplyOrderActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CImplyOrderDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CImplyOrderDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pImplyOrder	要加入的ImplyOrder
	virtual void beforeAdd(CWriteableImplyOrder *pImplyOrder);
	
	///更新前触发	
	///@param	pImplyOrder	被刷新的CImplyOrder
	///@param	pNewImplyOrder	新的值
	virtual void beforeUpdate(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pNewImplyOrder);
	
	///删除前触发
	///@param	pImplyOrder	要删除的CImplyOrder
	virtual void beforeRemove(CImplyOrder *pImplyOrder);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CQuoteDumpTrigger是操作报价时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteDumpTrigger: public CQuoteActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CQuoteDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CQuoteDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pQuote	要加入的Quote
	virtual void beforeAdd(CWriteableQuote *pQuote);
	
	///更新前触发	
	///@param	pQuote	被刷新的CQuote
	///@param	pNewQuote	新的值
	virtual void beforeUpdate(CQuote *pQuote, CWriteableQuote *pNewQuote);
	
	///删除前触发
	///@param	pQuote	要删除的CQuote
	virtual void beforeRemove(CQuote *pQuote);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataDumpTrigger是操作分价表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataDumpTrigger: public CMBLMarketDataActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CMBLMarketDataDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CMBLMarketDataDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pMBLMarketData	要加入的MBLMarketData
	virtual void beforeAdd(CWriteableMBLMarketData *pMBLMarketData);
	
	///更新前触发	
	///@param	pMBLMarketData	被刷新的CMBLMarketData
	///@param	pNewMBLMarketData	新的值
	virtual void beforeUpdate(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pNewMBLMarketData);
	
	///删除前触发
	///@param	pMBLMarketData	要删除的CMBLMarketData
	virtual void beforeRemove(CMBLMarketData *pMBLMarketData);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CTradeDumpTrigger是操作成交时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeDumpTrigger: public CTradeActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CTradeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CTradeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pTrade	要加入的Trade
	virtual void beforeAdd(CWriteableTrade *pTrade);
	
	///更新前触发	
	///@param	pTrade	被刷新的CTrade
	///@param	pNewTrade	新的值
	virtual void beforeUpdate(CTrade *pTrade, CWriteableTrade *pNewTrade);
	
	///删除前触发
	///@param	pTrade	要删除的CTrade
	virtual void beforeRemove(CTrade *pTrade);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseDumpTrigger是操作熔断阶段时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseDumpTrigger: public CFusePhaseActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CFusePhaseDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CFusePhaseDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pFusePhase	要加入的FusePhase
	virtual void beforeAdd(CWriteableFusePhase *pFusePhase);
	
	///更新前触发	
	///@param	pFusePhase	被刷新的CFusePhase
	///@param	pNewFusePhase	新的值
	virtual void beforeUpdate(CFusePhase *pFusePhase, CWriteableFusePhase *pNewFusePhase);
	
	///删除前触发
	///@param	pFusePhase	要删除的CFusePhase
	virtual void beforeRemove(CFusePhase *pFusePhase);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderDumpTrigger是操作执行宣告时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderDumpTrigger: public CExecOrderActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CExecOrderDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CExecOrderDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pExecOrder	要加入的ExecOrder
	virtual void beforeAdd(CWriteableExecOrder *pExecOrder);
	
	///更新前触发	
	///@param	pExecOrder	被刷新的CExecOrder
	///@param	pNewExecOrder	新的值
	virtual void beforeUpdate(CExecOrder *pExecOrder, CWriteableExecOrder *pNewExecOrder);
	
	///删除前触发
	///@param	pExecOrder	要删除的CExecOrder
	virtual void beforeRemove(CExecOrder *pExecOrder);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureDumpTrigger是操作单边市情况时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureDumpTrigger: public CUniPressureActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CUniPressureDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CUniPressureDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pUniPressure	要加入的UniPressure
	virtual void beforeAdd(CWriteableUniPressure *pUniPressure);
	
	///更新前触发	
	///@param	pUniPressure	被刷新的CUniPressure
	///@param	pNewUniPressure	新的值
	virtual void beforeUpdate(CUniPressure *pUniPressure, CWriteableUniPressure *pNewUniPressure);
	
	///删除前触发
	///@param	pUniPressure	要删除的CUniPressure
	virtual void beforeRemove(CUniPressure *pUniPressure);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitDumpTrigger是操作涨跌停板设置时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitDumpTrigger: public CBasePriceLimitActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CBasePriceLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CBasePriceLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pBasePriceLimit	要加入的BasePriceLimit
	virtual void beforeAdd(CWriteableBasePriceLimit *pBasePriceLimit);
	
	///更新前触发	
	///@param	pBasePriceLimit	被刷新的CBasePriceLimit
	///@param	pNewBasePriceLimit	新的值
	virtual void beforeUpdate(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pNewBasePriceLimit);
	
	///删除前触发
	///@param	pBasePriceLimit	要删除的CBasePriceLimit
	virtual void beforeRemove(CBasePriceLimit *pBasePriceLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitDumpTrigger是操作信用限额时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitDumpTrigger: public CCreditLimitActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCreditLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCreditLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCreditLimit	要加入的CreditLimit
	virtual void beforeAdd(CWriteableCreditLimit *pCreditLimit);
	
	///更新前触发	
	///@param	pCreditLimit	被刷新的CCreditLimit
	///@param	pNewCreditLimit	新的值
	virtual void beforeUpdate(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pNewCreditLimit);
	
	///删除前触发
	///@param	pCreditLimit	要删除的CCreditLimit
	virtual void beforeRemove(CCreditLimit *pCreditLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionDumpTrigger是操作当日期货合约期权属性时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionDumpTrigger: public CCurrInstrumentOptionActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CCurrInstrumentOptionDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CCurrInstrumentOptionDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pCurrInstrumentOption	要加入的CurrInstrumentOption
	virtual void beforeAdd(CWriteableCurrInstrumentOption *pCurrInstrumentOption);
	
	///更新前触发	
	///@param	pCurrInstrumentOption	被刷新的CCurrInstrumentOption
	///@param	pNewCurrInstrumentOption	新的值
	virtual void beforeUpdate(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pNewCurrInstrumentOption);
	
	///删除前触发
	///@param	pCurrInstrumentOption	要删除的CCurrInstrumentOption
	virtual void beforeRemove(CCurrInstrumentOption *pCurrInstrumentOption);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CDumpLog是一个将所有的修改以Dump方式输出的交易引擎提醒实现
///@author	王肇东
///@version	1.0,20041001
/////////////////////////////////////////////////////////////////////////
class CDumpLog
{
public:
	///构造方法，创建一个输出器
	///@param	pDB	要输出的内存数据库
	///@param	pConfig	配置信息
	CDumpLog(CMemoryDB *pDB, CConfig *pConfig);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CDumpLog(void);

	///启动dump
	void start(void);
	
	///停止dump
	void stop(void);
	
	///是否已经启动
	///@return	1表示已经启动，0表示没有启动
	int isStarted(void);
	
	///输出信息
	///@param	format	信息格式，按照fprintf的要求
	///@param	...	信息的详细内容
	void dumpMsg(char *format,...);

private:
	///输出文件
	FILE *m_DumpOutput;
	
	///内存数据库
	CMemoryDB *m_DB;
	
	///是否已经启动
	int m_Started;
	
	CExchangeDataSyncStatusDumpTrigger *m_ExchangeDataSyncStatusTrigger;
	CSGDataSyncStatusDumpTrigger *m_SGDataSyncStatusTrigger;
	CCurrentTimeDumpTrigger *m_CurrentTimeTrigger;
	CDataCenterDescDumpTrigger *m_DataCenterDescTrigger;
	CExchangeDumpTrigger *m_ExchangeTrigger;
	CSettlementGroupDumpTrigger *m_SettlementGroupTrigger;
	CMarketDumpTrigger *m_MarketTrigger;
	CMarketProductDumpTrigger *m_MarketProductTrigger;
	CMarketProductGroupDumpTrigger *m_MarketProductGroupTrigger;
	CMdPubStatusDumpTrigger *m_MdPubStatusTrigger;
	CMarketDataTopicDumpTrigger *m_MarketDataTopicTrigger;
	CPartTopicSubscribeDumpTrigger *m_PartTopicSubscribeTrigger;
	CParticipantDumpTrigger *m_ParticipantTrigger;
	CUserDumpTrigger *m_UserTrigger;
	CClientDumpTrigger *m_ClientTrigger;
	CUserIPDumpTrigger *m_UserIPTrigger;
	CPartClientDumpTrigger *m_PartClientTrigger;
	CClearingTradingPartDumpTrigger *m_ClearingTradingPartTrigger;
	CAliasDefineDumpTrigger *m_AliasDefineTrigger;
	CUserFunctionRightDumpTrigger *m_UserFunctionRightTrigger;
	CAccountDumpTrigger *m_AccountTrigger;
	CUserCommFluxDumpTrigger *m_UserCommFluxTrigger;
	CMarketDataLogDumpTrigger *m_MarketDataLogTrigger;
	CUserSessionDumpTrigger *m_UserSessionTrigger;
	CMDSessionDumpTrigger *m_MDSessionTrigger;
	CLoginInfoDumpTrigger *m_LoginInfoTrigger;
	CDepthMarketDataDetailDumpTrigger *m_DepthMarketDataDetailTrigger;
	CInstrumentStatusDetailDumpTrigger *m_InstrumentStatusDetailTrigger;
	CFrontStatusDumpTrigger *m_FrontStatusTrigger;
	CMaxLocalIDDumpTrigger *m_MaxLocalIDTrigger;
	CBulletinDumpTrigger *m_BulletinTrigger;
	CMarketDataModifyDumpTrigger *m_MarketDataModifyTrigger;
	CDepthMarketDataDumpTrigger *m_DepthMarketDataTrigger;
	CTopicMarketDataDumpTrigger *m_TopicMarketDataTrigger;
	CTopicMarketDataVersionDumpTrigger *m_TopicMarketDataVersionTrigger;
	CInformationDumpTrigger *m_InformationTrigger;
	COrderCountDumpTrigger *m_OrderCountTrigger;
	CInstrumentDumpTrigger *m_InstrumentTrigger;
	CCombinationLegDumpTrigger *m_CombinationLegTrigger;
	CPartRoleAccountDumpTrigger *m_PartRoleAccountTrigger;
	CPartProductRoleDumpTrigger *m_PartProductRoleTrigger;
	CPartProductRightDumpTrigger *m_PartProductRightTrigger;
	CPartInstrumentRightDumpTrigger *m_PartInstrumentRightTrigger;
	CClientProductRightDumpTrigger *m_ClientProductRightTrigger;
	CClientInstrumentRightDumpTrigger *m_ClientInstrumentRightTrigger;
	CPartClientProductRightDumpTrigger *m_PartClientProductRightTrigger;
	CPartClientInstrumentRightDumpTrigger *m_PartClientInstrumentRightTrigger;
	CCurrProductPropertyDumpTrigger *m_CurrProductPropertyTrigger;
	CCurrInstrumentPropertyDumpTrigger *m_CurrInstrumentPropertyTrigger;
	CCurrPriceBandingDumpTrigger *m_CurrPriceBandingTrigger;
	CCurrMarginRateDumpTrigger *m_CurrMarginRateTrigger;
	CCurrMarginRateDetailDumpTrigger *m_CurrMarginRateDetailTrigger;
	CCurrPartPosiLimitDumpTrigger *m_CurrPartPosiLimitTrigger;
	CCurrPartPosiLimitDetailDumpTrigger *m_CurrPartPosiLimitDetailTrigger;
	CCurrClientPosiLimitDumpTrigger *m_CurrClientPosiLimitTrigger;
	CCurrClientPosiLimitDetailDumpTrigger *m_CurrClientPosiLimitDetailTrigger;
	CCurrSpecialPosiLimitDumpTrigger *m_CurrSpecialPosiLimitTrigger;
	CCurrSpecialPosiLimitDetailDumpTrigger *m_CurrSpecialPosiLimitDetailTrigger;
	CCurrHedgeRuleDumpTrigger *m_CurrHedgeRuleTrigger;
	CCurrTradingSegmentAttrDumpTrigger *m_CurrTradingSegmentAttrTrigger;
	CCurrFuseDumpTrigger *m_CurrFuseTrigger;
	CTradingAccountDumpTrigger *m_TradingAccountTrigger;
	CBaseReserveAccountDumpTrigger *m_BaseReserveAccountTrigger;
	CPartPositionDumpTrigger *m_PartPositionTrigger;
	CClientPositionDumpTrigger *m_ClientPositionTrigger;
	CHedgeVolumeDumpTrigger *m_HedgeVolumeTrigger;
	CRemainOrderDumpTrigger *m_RemainOrderTrigger;
	CMarketDataDumpTrigger *m_MarketDataTrigger;
	CClearingPartPositionDumpTrigger *m_ClearingPartPositionTrigger;
	CInstrumentStatusDumpTrigger *m_InstrumentStatusTrigger;
	COrderDumpTrigger *m_OrderTrigger;
	CCombOrderDumpTrigger *m_CombOrderTrigger;
	COTCOrderDumpTrigger *m_OTCOrderTrigger;
	CImplyOrderDumpTrigger *m_ImplyOrderTrigger;
	CQuoteDumpTrigger *m_QuoteTrigger;
	CMBLMarketDataDumpTrigger *m_MBLMarketDataTrigger;
	CTradeDumpTrigger *m_TradeTrigger;
	CFusePhaseDumpTrigger *m_FusePhaseTrigger;
	CExecOrderDumpTrigger *m_ExecOrderTrigger;
	CUniPressureDumpTrigger *m_UniPressureTrigger;
	CBasePriceLimitDumpTrigger *m_BasePriceLimitTrigger;
	CCreditLimitDumpTrigger *m_CreditLimitTrigger;
	CCurrInstrumentOptionDumpTrigger *m_CurrInstrumentOptionTrigger;
};

#endif
