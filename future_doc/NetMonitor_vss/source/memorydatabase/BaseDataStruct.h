/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file BaseDataStruct.h
///@brief定义了内存数据库用的基本数据结构类，以及iterator、trigger的基类
///@history 
///20060128	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef BASEDATASTRUCT_H
#define BASEDATASTRUCT_H

#include "platform.h"
#include "CBaseObject.h"
#include "customDataType.h"
#include "CTransaction.h"

///判断结果是否满足条件
extern bool satisfy(int value,int type);

///字符串比较函数
///@param	s1	字符串1
///@param	s2	字符串2
///@return	1表示大于，0表示等于，-1表示小于
int compare(const char *s1, const char *s2);

///整数比较函数
///@param	v1	整数1
///@param	v2	整数2
///@return	1表示大于，0表示等于，-1表示小于
int compare(const int v1,const int v2);

///浮点数比较函数
///@param	v1	浮点数1
///@param	v2	浮点数2
///@return	1表示大于，0表示等于，-1表示小于
int compare(const double v1,const double v2);

///从buffer中获取下一个token，这里的token是以逗号或者换行分隔的
///在使用时，第一次应当传入指定的buffer，以后应当反复传入NULL，
///这样可以依次取出所有的token。本函数将改变buffer中的内容，叫用
///方有责任自己保护数据。本函数有重入问题，在一个取token的序列结
///束前，开始新的一个取token序列，将影响前面一个的结果。此问题和
///strtok的问题类似
///@param	buffer	要取token的buffer，NULL表示从上次取的buffer中取下一个
///@return	得到的token
char *getNextToken(char *buffer);

class CWriteableExchangeDataSyncStatus;
class CExchangeDataSyncStatusFactory;
class CWriteableSGDataSyncStatus;
class CSGDataSyncStatusFactory;
class CWriteableCurrentTime;
class CCurrentTimeFactory;
class CWriteableDataCenterDesc;
class CDataCenterDescFactory;
class CWriteableExchange;
class CExchangeFactory;
class CWriteableSettlementGroup;
class CSettlementGroupFactory;
class CWriteableMarket;
class CMarketFactory;
class CWriteableMarketProduct;
class CMarketProductFactory;
class CWriteableMarketProductGroup;
class CMarketProductGroupFactory;
class CWriteableMdPubStatus;
class CMdPubStatusFactory;
class CWriteableMarketDataTopic;
class CMarketDataTopicFactory;
class CWriteablePartTopicSubscribe;
class CPartTopicSubscribeFactory;
class CWriteableParticipant;
class CParticipantFactory;
class CWriteableUser;
class CUserFactory;
class CWriteableClient;
class CClientFactory;
class CWriteableUserIP;
class CUserIPFactory;
class CWriteablePartClient;
class CPartClientFactory;
class CWriteableClearingTradingPart;
class CClearingTradingPartFactory;
class CWriteableAliasDefine;
class CAliasDefineFactory;
class CWriteableUserFunctionRight;
class CUserFunctionRightFactory;
class CWriteableAccount;
class CAccountFactory;
class CWriteableUserCommFlux;
class CUserCommFluxFactory;
class CWriteableMarketDataLog;
class CMarketDataLogFactory;
class CWriteableUserSession;
class CUserSessionFactory;
class CWriteableMDSession;
class CMDSessionFactory;
class CWriteableLoginInfo;
class CLoginInfoFactory;
class CWriteableDepthMarketDataDetail;
class CDepthMarketDataDetailFactory;
class CWriteableInstrumentStatusDetail;
class CInstrumentStatusDetailFactory;
class CWriteableFrontStatus;
class CFrontStatusFactory;
class CWriteableMaxLocalID;
class CMaxLocalIDFactory;
class CWriteableBulletin;
class CBulletinFactory;
class CWriteableMarketDataModify;
class CMarketDataModifyFactory;
class CWriteableDepthMarketData;
class CDepthMarketDataFactory;
class CWriteableTopicMarketData;
class CTopicMarketDataFactory;
class CWriteableTopicMarketDataVersion;
class CTopicMarketDataVersionFactory;
class CWriteableInformation;
class CInformationFactory;
class CWriteableOrderCount;
class COrderCountFactory;
class CWriteableInstrument;
class CInstrumentFactory;
class CWriteableCombinationLeg;
class CCombinationLegFactory;
class CWriteablePartRoleAccount;
class CPartRoleAccountFactory;
class CWriteablePartProductRole;
class CPartProductRoleFactory;
class CWriteablePartProductRight;
class CPartProductRightFactory;
class CWriteablePartInstrumentRight;
class CPartInstrumentRightFactory;
class CWriteableClientProductRight;
class CClientProductRightFactory;
class CWriteableClientInstrumentRight;
class CClientInstrumentRightFactory;
class CWriteablePartClientProductRight;
class CPartClientProductRightFactory;
class CWriteablePartClientInstrumentRight;
class CPartClientInstrumentRightFactory;
class CWriteableCurrProductProperty;
class CCurrProductPropertyFactory;
class CWriteableCurrInstrumentProperty;
class CCurrInstrumentPropertyFactory;
class CWriteableCurrPriceBanding;
class CCurrPriceBandingFactory;
class CWriteableCurrMarginRate;
class CCurrMarginRateFactory;
class CWriteableCurrMarginRateDetail;
class CCurrMarginRateDetailFactory;
class CWriteableCurrPartPosiLimit;
class CCurrPartPosiLimitFactory;
class CWriteableCurrPartPosiLimitDetail;
class CCurrPartPosiLimitDetailFactory;
class CWriteableCurrClientPosiLimit;
class CCurrClientPosiLimitFactory;
class CWriteableCurrClientPosiLimitDetail;
class CCurrClientPosiLimitDetailFactory;
class CWriteableCurrSpecialPosiLimit;
class CCurrSpecialPosiLimitFactory;
class CWriteableCurrSpecialPosiLimitDetail;
class CCurrSpecialPosiLimitDetailFactory;
class CWriteableCurrHedgeRule;
class CCurrHedgeRuleFactory;
class CWriteableCurrTradingSegmentAttr;
class CCurrTradingSegmentAttrFactory;
class CWriteableCurrFuse;
class CCurrFuseFactory;
class CWriteableTradingAccount;
class CTradingAccountFactory;
class CWriteableBaseReserveAccount;
class CBaseReserveAccountFactory;
class CWriteablePartPosition;
class CPartPositionFactory;
class CWriteableClientPosition;
class CClientPositionFactory;
class CWriteableHedgeVolume;
class CHedgeVolumeFactory;
class CWriteableRemainOrder;
class CRemainOrderFactory;
class CWriteableMarketData;
class CMarketDataFactory;
class CWriteableClearingPartPosition;
class CClearingPartPositionFactory;
class CWriteableInstrumentStatus;
class CInstrumentStatusFactory;
class CWriteableOrder;
class COrderFactory;
class CWriteableCombOrder;
class CCombOrderFactory;
class CWriteableOTCOrder;
class COTCOrderFactory;
class CWriteableImplyOrder;
class CImplyOrderFactory;
class CWriteableQuote;
class CQuoteFactory;
class CWriteableMBLMarketData;
class CMBLMarketDataFactory;
class CWriteableTrade;
class CTradeFactory;
class CWriteableFusePhase;
class CFusePhaseFactory;
class CWriteableExecOrder;
class CExecOrderFactory;
class CWriteableUniPressure;
class CUniPressureFactory;
class CWriteableBasePriceLimit;
class CBasePriceLimitFactory;
class CWriteableCreditLimit;
class CCreditLimitFactory;
class CWriteableHedgeDetail;
class CWriteableOrderAction;
class CWriteableQuoteAction;
class CWriteableExecOrderAction;
class CWriteableAccountDeposit;
class CWriteableUpdateAllInstrumentStatus;
class CWriteableAdminOrder;
class CWriteableCommPhase;
class CWriteableCurrHedge;
class CWriteableCurrInstrumentOption;
class CCurrInstrumentOptionFactory;

/////////////////////////////////////////////////////////////////////////
///CWriteableExchangeDataSyncStatus是一个存储交易所数据同步状态的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableExchangeDataSyncStatus
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! ExchangeID.isValid())
			return 0;
		if (! ExchangeDataSyncStatus.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableExchangeDataSyncStatus *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///交易所代码
	CExchangeIDType ExchangeID;
	///交易所数据同步状态
	CExchangeDataSyncStatusType ExchangeDataSyncStatus;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableExchangeDataSyncStatus CExchangeDataSyncStatus;

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusActionTrigger是操作交易所数据同步状态时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusActionTrigger
{
public:
	///构造方法
	CExchangeDataSyncStatusActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CExchangeDataSyncStatusActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CExchangeDataSyncStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pExchangeDataSyncStatus	要加入的ExchangeDataSyncStatus
	virtual void beforeAdd(CWriteableExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return;
	}
	
	///加入后触发
	///@param	pExchangeDataSyncStatus	已经加入的ExchangeDataSyncStatus
	virtual void afterAdd(CExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return;
	}

	///更新前触发	
	///@param	pExchangeDataSyncStatus	被刷新的CExchangeDataSyncStatus
	///@param	pNewExchangeDataSyncStatus	新的值
	virtual void beforeUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pNewExchangeDataSyncStatus)
	{
		return;
	}
	
	///更新后触发
	///@param	pExchangeDataSyncStatus	被刷新的CExchangeDataSyncStatus
	virtual void afterUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return;
	}
	
	///删除前触发
	///@param	pExchangeDataSyncStatus	要删除的CExchangeDataSyncStatus
	virtual void beforeRemove(CExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CExchangeDataSyncStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusCommitTrigger是确认交易所数据同步状态时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusCommitTrigger
{
public:
	///构造方法
	CExchangeDataSyncStatusCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CExchangeDataSyncStatusCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CExchangeDataSyncStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pExchangeDataSyncStatus	已经加入的ExchangeDataSyncStatus
	virtual void commitAdd(CExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return;
	}

	///更新后触发
	///@param	pExchangeDataSyncStatus	被刷新的CExchangeDataSyncStatus
	///@param	poldExchangeDataSyncStatus	原来的值
	virtual void commitUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pOldExchangeDataSyncStatus)
	{
		return;
	}
	
	///删除后触发
	///@param	pExchangeDataSyncStatus	已经删除的CExchangeDataSyncStatus
	virtual void commitRemove(CWriteableExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CExchangeDataSyncStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusIterator是一个对交易所数据同步状态的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusIterator
{
public:
	///构造方法
	CExchangeDataSyncStatusIterator(void)
	{
	}

	///构造方法
	CExchangeDataSyncStatusIterator(CExchangeDataSyncStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CExchangeDataSyncStatusIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个ExchangeDataSyncStatus
	///@return	下一个满足条件CExchangeDataSyncStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CExchangeDataSyncStatus *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CExchangeDataSyncStatusFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pExchangeDataSyncStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExchangeDataSyncStatus * pExchangeDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CExchangeDataSyncStatusFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSGDataSyncStatus是一个存储结算组数据同步状态的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSGDataSyncStatus
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! SGDataSyncStatus.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableSGDataSyncStatus *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///交易日
	CDateType TradingDay;
	///结算编号
	CSettlementIDType SettlementID;
	///结算组数据同步状态
	CSGDataSyncStatusType SGDataSyncStatus;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableSGDataSyncStatus CSGDataSyncStatus;

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusActionTrigger是操作结算组数据同步状态时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusActionTrigger
{
public:
	///构造方法
	CSGDataSyncStatusActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSGDataSyncStatusActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSGDataSyncStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSGDataSyncStatus	要加入的SGDataSyncStatus
	virtual void beforeAdd(CWriteableSGDataSyncStatus *pSGDataSyncStatus)
	{
		return;
	}
	
	///加入后触发
	///@param	pSGDataSyncStatus	已经加入的SGDataSyncStatus
	virtual void afterAdd(CSGDataSyncStatus *pSGDataSyncStatus)
	{
		return;
	}

	///更新前触发	
	///@param	pSGDataSyncStatus	被刷新的CSGDataSyncStatus
	///@param	pNewSGDataSyncStatus	新的值
	virtual void beforeUpdate(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pNewSGDataSyncStatus)
	{
		return;
	}
	
	///更新后触发
	///@param	pSGDataSyncStatus	被刷新的CSGDataSyncStatus
	virtual void afterUpdate(CSGDataSyncStatus *pSGDataSyncStatus)
	{
		return;
	}
	
	///删除前触发
	///@param	pSGDataSyncStatus	要删除的CSGDataSyncStatus
	virtual void beforeRemove(CSGDataSyncStatus *pSGDataSyncStatus)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSGDataSyncStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusCommitTrigger是确认结算组数据同步状态时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusCommitTrigger
{
public:
	///构造方法
	CSGDataSyncStatusCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSGDataSyncStatusCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSGDataSyncStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSGDataSyncStatus	已经加入的SGDataSyncStatus
	virtual void commitAdd(CSGDataSyncStatus *pSGDataSyncStatus)
	{
		return;
	}

	///更新后触发
	///@param	pSGDataSyncStatus	被刷新的CSGDataSyncStatus
	///@param	poldSGDataSyncStatus	原来的值
	virtual void commitUpdate(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pOldSGDataSyncStatus)
	{
		return;
	}
	
	///删除后触发
	///@param	pSGDataSyncStatus	已经删除的CSGDataSyncStatus
	virtual void commitRemove(CWriteableSGDataSyncStatus *pSGDataSyncStatus)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSGDataSyncStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusIterator是一个对结算组数据同步状态的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusIterator
{
public:
	///构造方法
	CSGDataSyncStatusIterator(void)
	{
	}

	///构造方法
	CSGDataSyncStatusIterator(CSGDataSyncStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSGDataSyncStatusIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SGDataSyncStatus
	///@return	下一个满足条件CSGDataSyncStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSGDataSyncStatus *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSGDataSyncStatusFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSGDataSyncStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSGDataSyncStatus * pSGDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSGDataSyncStatusFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrentTime是一个存储当前时间的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrentTime
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! CurrDate.isValid())
			return 0;
		if (! CurrTime.isValid())
			return 0;
		if (! CurrMillisec.isValid())
			return 0;
		if (! OldTime.isValid())
			return 0;
		if (! OldMillisec.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrentTime *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///当前日期
	CDateType CurrDate;
	///当前时间
	CTimeType CurrTime;
	///当前时间（毫秒）
	CMillisecType CurrMillisec;
	///原来时间
	CTimeType OldTime;
	///原来时间（毫秒）
	CMillisecType OldMillisec;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrentTime CCurrentTime;

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeActionTrigger是操作当前时间时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeActionTrigger
{
public:
	///构造方法
	CCurrentTimeActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrentTimeActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrentTimeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCurrentTime	要加入的CurrentTime
	virtual void beforeAdd(CWriteableCurrentTime *pCurrentTime)
	{
		return;
	}
	
	///加入后触发
	///@param	pCurrentTime	已经加入的CurrentTime
	virtual void afterAdd(CCurrentTime *pCurrentTime)
	{
		return;
	}

	///更新前触发	
	///@param	pCurrentTime	被刷新的CCurrentTime
	///@param	pNewCurrentTime	新的值
	virtual void beforeUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pNewCurrentTime)
	{
		return;
	}
	
	///更新后触发
	///@param	pCurrentTime	被刷新的CCurrentTime
	virtual void afterUpdate(CCurrentTime *pCurrentTime)
	{
		return;
	}
	
	///删除前触发
	///@param	pCurrentTime	要删除的CCurrentTime
	virtual void beforeRemove(CCurrentTime *pCurrentTime)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrentTimeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeCommitTrigger是确认当前时间时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeCommitTrigger
{
public:
	///构造方法
	CCurrentTimeCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrentTimeCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrentTimeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCurrentTime	已经加入的CurrentTime
	virtual void commitAdd(CCurrentTime *pCurrentTime)
	{
		return;
	}

	///更新后触发
	///@param	pCurrentTime	被刷新的CCurrentTime
	///@param	poldCurrentTime	原来的值
	virtual void commitUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pOldCurrentTime)
	{
		return;
	}
	
	///删除后触发
	///@param	pCurrentTime	已经删除的CCurrentTime
	virtual void commitRemove(CWriteableCurrentTime *pCurrentTime)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrentTimeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeIterator是一个对当前时间的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeIterator
{
public:
	///构造方法
	CCurrentTimeIterator(void)
	{
	}

	///构造方法
	CCurrentTimeIterator(CCurrentTimeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrentTimeIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CurrentTime
	///@return	下一个满足条件CCurrentTime，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrentTime *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCurrentTimeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCurrentTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrentTime * pCurrentTime,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCurrentTimeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableDataCenterDesc是一个存储数据中心描述的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableDataCenterDesc
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! DataCenterID.isValid())
			return 0;
		if (! StartMode.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableDataCenterDesc *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///数据中心代码
	CDataCenterIDType DataCenterID;
	///启动模式
	CStartModeType StartMode;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableDataCenterDesc CDataCenterDesc;

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescActionTrigger是操作数据中心描述时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescActionTrigger
{
public:
	///构造方法
	CDataCenterDescActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CDataCenterDescActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CDataCenterDescFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pDataCenterDesc	要加入的DataCenterDesc
	virtual void beforeAdd(CWriteableDataCenterDesc *pDataCenterDesc)
	{
		return;
	}
	
	///加入后触发
	///@param	pDataCenterDesc	已经加入的DataCenterDesc
	virtual void afterAdd(CDataCenterDesc *pDataCenterDesc)
	{
		return;
	}

	///更新前触发	
	///@param	pDataCenterDesc	被刷新的CDataCenterDesc
	///@param	pNewDataCenterDesc	新的值
	virtual void beforeUpdate(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pNewDataCenterDesc)
	{
		return;
	}
	
	///更新后触发
	///@param	pDataCenterDesc	被刷新的CDataCenterDesc
	virtual void afterUpdate(CDataCenterDesc *pDataCenterDesc)
	{
		return;
	}
	
	///删除前触发
	///@param	pDataCenterDesc	要删除的CDataCenterDesc
	virtual void beforeRemove(CDataCenterDesc *pDataCenterDesc)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CDataCenterDescFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescCommitTrigger是确认数据中心描述时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescCommitTrigger
{
public:
	///构造方法
	CDataCenterDescCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CDataCenterDescCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CDataCenterDescFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pDataCenterDesc	已经加入的DataCenterDesc
	virtual void commitAdd(CDataCenterDesc *pDataCenterDesc)
	{
		return;
	}

	///更新后触发
	///@param	pDataCenterDesc	被刷新的CDataCenterDesc
	///@param	poldDataCenterDesc	原来的值
	virtual void commitUpdate(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pOldDataCenterDesc)
	{
		return;
	}
	
	///删除后触发
	///@param	pDataCenterDesc	已经删除的CDataCenterDesc
	virtual void commitRemove(CWriteableDataCenterDesc *pDataCenterDesc)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CDataCenterDescFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescIterator是一个对数据中心描述的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescIterator
{
public:
	///构造方法
	CDataCenterDescIterator(void)
	{
	}

	///构造方法
	CDataCenterDescIterator(CDataCenterDescFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CDataCenterDescIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个DataCenterDesc
	///@return	下一个满足条件CDataCenterDesc，如果已经没有一个满足要求了，则返回NULL
	virtual CDataCenterDesc *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CDataCenterDescFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pDataCenterDesc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableDataCenterDesc * pDataCenterDesc,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CDataCenterDescFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableExchange是一个存储交易所的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableExchange
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! ExchangeID.isValid())
			return 0;
		if (! ExchangeName.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableExchange *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易所代码
	CExchangeIDType ExchangeID;
	///交易所名称
	CExchangeNameType ExchangeName;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableExchange CExchange;

/////////////////////////////////////////////////////////////////////////
///CExchangeActionTrigger是操作交易所时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeActionTrigger
{
public:
	///构造方法
	CExchangeActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CExchangeActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CExchangeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pExchange	要加入的Exchange
	virtual void beforeAdd(CWriteableExchange *pExchange)
	{
		return;
	}
	
	///加入后触发
	///@param	pExchange	已经加入的Exchange
	virtual void afterAdd(CExchange *pExchange)
	{
		return;
	}

	///更新前触发	
	///@param	pExchange	被刷新的CExchange
	///@param	pNewExchange	新的值
	virtual void beforeUpdate(CExchange *pExchange, CWriteableExchange *pNewExchange)
	{
		return;
	}
	
	///更新后触发
	///@param	pExchange	被刷新的CExchange
	virtual void afterUpdate(CExchange *pExchange)
	{
		return;
	}
	
	///删除前触发
	///@param	pExchange	要删除的CExchange
	virtual void beforeRemove(CExchange *pExchange)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CExchangeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeCommitTrigger是确认交易所时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeCommitTrigger
{
public:
	///构造方法
	CExchangeCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CExchangeCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CExchangeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pExchange	已经加入的Exchange
	virtual void commitAdd(CExchange *pExchange)
	{
		return;
	}

	///更新后触发
	///@param	pExchange	被刷新的CExchange
	///@param	poldExchange	原来的值
	virtual void commitUpdate(CExchange *pExchange, CWriteableExchange *pOldExchange)
	{
		return;
	}
	
	///删除后触发
	///@param	pExchange	已经删除的CExchange
	virtual void commitRemove(CWriteableExchange *pExchange)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CExchangeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeIterator是一个对交易所的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeIterator
{
public:
	///构造方法
	CExchangeIterator(void)
	{
	}

	///构造方法
	CExchangeIterator(CExchangeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CExchangeIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个Exchange
	///@return	下一个满足条件CExchange，如果已经没有一个满足要求了，则返回NULL
	virtual CExchange *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CExchangeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pExchange 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExchange * pExchange,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CExchangeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSettlementGroup是一个存储结算组的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSettlementGroup
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementGroupName.isValid())
			return 0;
		if (! ExchangeID.isValid())
			return 0;
		if (! Currency.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableSettlementGroup *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算组名称
	CSettlementGroupNameType SettlementGroupName;
	///交易所代码
	CExchangeIDType ExchangeID;
	///币种
	CCurrencyType Currency;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableSettlementGroup CSettlementGroup;

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupActionTrigger是操作结算组时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupActionTrigger
{
public:
	///构造方法
	CSettlementGroupActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSettlementGroupActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSettlementGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSettlementGroup	要加入的SettlementGroup
	virtual void beforeAdd(CWriteableSettlementGroup *pSettlementGroup)
	{
		return;
	}
	
	///加入后触发
	///@param	pSettlementGroup	已经加入的SettlementGroup
	virtual void afterAdd(CSettlementGroup *pSettlementGroup)
	{
		return;
	}

	///更新前触发	
	///@param	pSettlementGroup	被刷新的CSettlementGroup
	///@param	pNewSettlementGroup	新的值
	virtual void beforeUpdate(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pNewSettlementGroup)
	{
		return;
	}
	
	///更新后触发
	///@param	pSettlementGroup	被刷新的CSettlementGroup
	virtual void afterUpdate(CSettlementGroup *pSettlementGroup)
	{
		return;
	}
	
	///删除前触发
	///@param	pSettlementGroup	要删除的CSettlementGroup
	virtual void beforeRemove(CSettlementGroup *pSettlementGroup)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSettlementGroupFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupCommitTrigger是确认结算组时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupCommitTrigger
{
public:
	///构造方法
	CSettlementGroupCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSettlementGroupCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSettlementGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSettlementGroup	已经加入的SettlementGroup
	virtual void commitAdd(CSettlementGroup *pSettlementGroup)
	{
		return;
	}

	///更新后触发
	///@param	pSettlementGroup	被刷新的CSettlementGroup
	///@param	poldSettlementGroup	原来的值
	virtual void commitUpdate(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pOldSettlementGroup)
	{
		return;
	}
	
	///删除后触发
	///@param	pSettlementGroup	已经删除的CSettlementGroup
	virtual void commitRemove(CWriteableSettlementGroup *pSettlementGroup)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSettlementGroupFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupIterator是一个对结算组的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupIterator
{
public:
	///构造方法
	CSettlementGroupIterator(void)
	{
	}

	///构造方法
	CSettlementGroupIterator(CSettlementGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSettlementGroupIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SettlementGroup
	///@return	下一个满足条件CSettlementGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CSettlementGroup *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSettlementGroupFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSettlementGroup 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSettlementGroup * pSettlementGroup,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSettlementGroupFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMarket是一个存储市场的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMarket
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! MarketID.isValid())
			return 0;
		if (! MarketName.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableMarket *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///市场代码
	CMarketIDType MarketID;
	///市场名称
	CMarketNameType MarketName;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMarket CMarket;

/////////////////////////////////////////////////////////////////////////
///CMarketActionTrigger是操作市场时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketActionTrigger
{
public:
	///构造方法
	CMarketActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMarketActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMarketFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pMarket	要加入的Market
	virtual void beforeAdd(CWriteableMarket *pMarket)
	{
		return;
	}
	
	///加入后触发
	///@param	pMarket	已经加入的Market
	virtual void afterAdd(CMarket *pMarket)
	{
		return;
	}

	///更新前触发	
	///@param	pMarket	被刷新的CMarket
	///@param	pNewMarket	新的值
	virtual void beforeUpdate(CMarket *pMarket, CWriteableMarket *pNewMarket)
	{
		return;
	}
	
	///更新后触发
	///@param	pMarket	被刷新的CMarket
	virtual void afterUpdate(CMarket *pMarket)
	{
		return;
	}
	
	///删除前触发
	///@param	pMarket	要删除的CMarket
	virtual void beforeRemove(CMarket *pMarket)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMarketFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketCommitTrigger是确认市场时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketCommitTrigger
{
public:
	///构造方法
	CMarketCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMarketCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMarketFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pMarket	已经加入的Market
	virtual void commitAdd(CMarket *pMarket)
	{
		return;
	}

	///更新后触发
	///@param	pMarket	被刷新的CMarket
	///@param	poldMarket	原来的值
	virtual void commitUpdate(CMarket *pMarket, CWriteableMarket *pOldMarket)
	{
		return;
	}
	
	///删除后触发
	///@param	pMarket	已经删除的CMarket
	virtual void commitRemove(CWriteableMarket *pMarket)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMarketFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketIterator是一个对市场的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketIterator
{
public:
	///构造方法
	CMarketIterator(void)
	{
	}

	///构造方法
	CMarketIterator(CMarketFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CMarketIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个Market
	///@return	下一个满足条件CMarket，如果已经没有一个满足要求了，则返回NULL
	virtual CMarket *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CMarketFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pMarket 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarket * pMarket,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CMarketFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMarketProduct是一个存储市场产品关联的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMarketProduct
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! MarketID.isValid())
			return 0;
		if (! ProductID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableMarketProduct *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///市场代码
	CMarketIDType MarketID;
	///产品代码
	CProductIDType ProductID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMarketProduct CMarketProduct;

/////////////////////////////////////////////////////////////////////////
///CMarketProductActionTrigger是操作市场产品关联时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductActionTrigger
{
public:
	///构造方法
	CMarketProductActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMarketProductActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMarketProductFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pMarketProduct	要加入的MarketProduct
	virtual void beforeAdd(CWriteableMarketProduct *pMarketProduct)
	{
		return;
	}
	
	///加入后触发
	///@param	pMarketProduct	已经加入的MarketProduct
	virtual void afterAdd(CMarketProduct *pMarketProduct)
	{
		return;
	}

	///更新前触发	
	///@param	pMarketProduct	被刷新的CMarketProduct
	///@param	pNewMarketProduct	新的值
	virtual void beforeUpdate(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pNewMarketProduct)
	{
		return;
	}
	
	///更新后触发
	///@param	pMarketProduct	被刷新的CMarketProduct
	virtual void afterUpdate(CMarketProduct *pMarketProduct)
	{
		return;
	}
	
	///删除前触发
	///@param	pMarketProduct	要删除的CMarketProduct
	virtual void beforeRemove(CMarketProduct *pMarketProduct)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMarketProductFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductCommitTrigger是确认市场产品关联时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductCommitTrigger
{
public:
	///构造方法
	CMarketProductCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMarketProductCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMarketProductFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pMarketProduct	已经加入的MarketProduct
	virtual void commitAdd(CMarketProduct *pMarketProduct)
	{
		return;
	}

	///更新后触发
	///@param	pMarketProduct	被刷新的CMarketProduct
	///@param	poldMarketProduct	原来的值
	virtual void commitUpdate(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pOldMarketProduct)
	{
		return;
	}
	
	///删除后触发
	///@param	pMarketProduct	已经删除的CMarketProduct
	virtual void commitRemove(CWriteableMarketProduct *pMarketProduct)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMarketProductFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductIterator是一个对市场产品关联的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductIterator
{
public:
	///构造方法
	CMarketProductIterator(void)
	{
	}

	///构造方法
	CMarketProductIterator(CMarketProductFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CMarketProductIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个MarketProduct
	///@return	下一个满足条件CMarketProduct，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketProduct *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CMarketProductFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pMarketProduct 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketProduct * pMarketProduct,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CMarketProductFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMarketProductGroup是一个存储市场产品组关联的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMarketProductGroup
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! MarketID.isValid())
			return 0;
		if (! ProductGroupID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableMarketProductGroup *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///市场代码
	CMarketIDType MarketID;
	///产品组代码
	CProductGroupIDType ProductGroupID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMarketProductGroup CMarketProductGroup;

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupActionTrigger是操作市场产品组关联时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupActionTrigger
{
public:
	///构造方法
	CMarketProductGroupActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMarketProductGroupActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMarketProductGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pMarketProductGroup	要加入的MarketProductGroup
	virtual void beforeAdd(CWriteableMarketProductGroup *pMarketProductGroup)
	{
		return;
	}
	
	///加入后触发
	///@param	pMarketProductGroup	已经加入的MarketProductGroup
	virtual void afterAdd(CMarketProductGroup *pMarketProductGroup)
	{
		return;
	}

	///更新前触发	
	///@param	pMarketProductGroup	被刷新的CMarketProductGroup
	///@param	pNewMarketProductGroup	新的值
	virtual void beforeUpdate(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pNewMarketProductGroup)
	{
		return;
	}
	
	///更新后触发
	///@param	pMarketProductGroup	被刷新的CMarketProductGroup
	virtual void afterUpdate(CMarketProductGroup *pMarketProductGroup)
	{
		return;
	}
	
	///删除前触发
	///@param	pMarketProductGroup	要删除的CMarketProductGroup
	virtual void beforeRemove(CMarketProductGroup *pMarketProductGroup)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMarketProductGroupFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupCommitTrigger是确认市场产品组关联时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupCommitTrigger
{
public:
	///构造方法
	CMarketProductGroupCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMarketProductGroupCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMarketProductGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pMarketProductGroup	已经加入的MarketProductGroup
	virtual void commitAdd(CMarketProductGroup *pMarketProductGroup)
	{
		return;
	}

	///更新后触发
	///@param	pMarketProductGroup	被刷新的CMarketProductGroup
	///@param	poldMarketProductGroup	原来的值
	virtual void commitUpdate(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pOldMarketProductGroup)
	{
		return;
	}
	
	///删除后触发
	///@param	pMarketProductGroup	已经删除的CMarketProductGroup
	virtual void commitRemove(CWriteableMarketProductGroup *pMarketProductGroup)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMarketProductGroupFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupIterator是一个对市场产品组关联的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupIterator
{
public:
	///构造方法
	CMarketProductGroupIterator(void)
	{
	}

	///构造方法
	CMarketProductGroupIterator(CMarketProductGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CMarketProductGroupIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个MarketProductGroup
	///@return	下一个满足条件CMarketProductGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketProductGroup *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CMarketProductGroupFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pMarketProductGroup 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketProductGroup * pMarketProductGroup,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CMarketProductGroupFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMdPubStatus是一个存储行情发布状态的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMdPubStatus
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! ProductID.isValid())
			return 0;
		if (! InstrumentStatus.isValid())
			return 0;
		if (! MdPubStatus.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableMdPubStatus *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///产品代码
	CProductIDType ProductID;
	///合约交易状态
	CInstrumentStatusType InstrumentStatus;
	///行情发布状态
	CMdPubStatusType MdPubStatus;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMdPubStatus CMdPubStatus;

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusActionTrigger是操作行情发布状态时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusActionTrigger
{
public:
	///构造方法
	CMdPubStatusActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMdPubStatusActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMdPubStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pMdPubStatus	要加入的MdPubStatus
	virtual void beforeAdd(CWriteableMdPubStatus *pMdPubStatus)
	{
		return;
	}
	
	///加入后触发
	///@param	pMdPubStatus	已经加入的MdPubStatus
	virtual void afterAdd(CMdPubStatus *pMdPubStatus)
	{
		return;
	}

	///更新前触发	
	///@param	pMdPubStatus	被刷新的CMdPubStatus
	///@param	pNewMdPubStatus	新的值
	virtual void beforeUpdate(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pNewMdPubStatus)
	{
		return;
	}
	
	///更新后触发
	///@param	pMdPubStatus	被刷新的CMdPubStatus
	virtual void afterUpdate(CMdPubStatus *pMdPubStatus)
	{
		return;
	}
	
	///删除前触发
	///@param	pMdPubStatus	要删除的CMdPubStatus
	virtual void beforeRemove(CMdPubStatus *pMdPubStatus)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMdPubStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusCommitTrigger是确认行情发布状态时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusCommitTrigger
{
public:
	///构造方法
	CMdPubStatusCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMdPubStatusCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMdPubStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pMdPubStatus	已经加入的MdPubStatus
	virtual void commitAdd(CMdPubStatus *pMdPubStatus)
	{
		return;
	}

	///更新后触发
	///@param	pMdPubStatus	被刷新的CMdPubStatus
	///@param	poldMdPubStatus	原来的值
	virtual void commitUpdate(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pOldMdPubStatus)
	{
		return;
	}
	
	///删除后触发
	///@param	pMdPubStatus	已经删除的CMdPubStatus
	virtual void commitRemove(CWriteableMdPubStatus *pMdPubStatus)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMdPubStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusIterator是一个对行情发布状态的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusIterator
{
public:
	///构造方法
	CMdPubStatusIterator(void)
	{
	}

	///构造方法
	CMdPubStatusIterator(CMdPubStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CMdPubStatusIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个MdPubStatus
	///@return	下一个满足条件CMdPubStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CMdPubStatus *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CMdPubStatusFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pMdPubStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMdPubStatus * pMdPubStatus,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CMdPubStatusFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMarketDataTopic是一个存储行情主题的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMarketDataTopic
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! NextPublishTime.isValid())
			return 0;
		if (! NextLogID.isValid())
			return 0;
		if (! TopicID.isValid())
			return 0;
		if (! TopicName.isValid())
			return 0;
		if (! MarketID.isValid())
			return 0;
		if (! SnapShotFeq.isValid())
			return 0;
		if (! MarketDataDepth.isValid())
			return 0;
		if (! DelaySeconds.isValid())
			return 0;
		if (! MarketDataMode.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableMarketDataTopic *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///下次发布行情时间
	CTimeType NextPublishTime;
	///下次要读的行情流水序号
	CSequenceNoType NextLogID;
	///主题代码
	CTopicIDType TopicID;
	///主题名称
	CTopicNameType TopicName;
	///市场代码
	CMarketIDType MarketID;
	///采样频率
	CSecondsType SnapShotFeq;
	///市场行情深度
	CMarketDataDepthType MarketDataDepth;
	///延迟秒数
	CSecondsType DelaySeconds;
	///行情模式
	CMarketDataModeType MarketDataMode;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMarketDataTopic CMarketDataTopic;

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicActionTrigger是操作行情主题时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicActionTrigger
{
public:
	///构造方法
	CMarketDataTopicActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMarketDataTopicActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMarketDataTopicFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pMarketDataTopic	要加入的MarketDataTopic
	virtual void beforeAdd(CWriteableMarketDataTopic *pMarketDataTopic)
	{
		return;
	}
	
	///加入后触发
	///@param	pMarketDataTopic	已经加入的MarketDataTopic
	virtual void afterAdd(CMarketDataTopic *pMarketDataTopic)
	{
		return;
	}

	///更新前触发	
	///@param	pMarketDataTopic	被刷新的CMarketDataTopic
	///@param	pNewMarketDataTopic	新的值
	virtual void beforeUpdate(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pNewMarketDataTopic)
	{
		return;
	}
	
	///更新后触发
	///@param	pMarketDataTopic	被刷新的CMarketDataTopic
	virtual void afterUpdate(CMarketDataTopic *pMarketDataTopic)
	{
		return;
	}
	
	///删除前触发
	///@param	pMarketDataTopic	要删除的CMarketDataTopic
	virtual void beforeRemove(CMarketDataTopic *pMarketDataTopic)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMarketDataTopicFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicCommitTrigger是确认行情主题时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicCommitTrigger
{
public:
	///构造方法
	CMarketDataTopicCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMarketDataTopicCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMarketDataTopicFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pMarketDataTopic	已经加入的MarketDataTopic
	virtual void commitAdd(CMarketDataTopic *pMarketDataTopic)
	{
		return;
	}

	///更新后触发
	///@param	pMarketDataTopic	被刷新的CMarketDataTopic
	///@param	poldMarketDataTopic	原来的值
	virtual void commitUpdate(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pOldMarketDataTopic)
	{
		return;
	}
	
	///删除后触发
	///@param	pMarketDataTopic	已经删除的CMarketDataTopic
	virtual void commitRemove(CWriteableMarketDataTopic *pMarketDataTopic)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMarketDataTopicFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicIterator是一个对行情主题的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicIterator
{
public:
	///构造方法
	CMarketDataTopicIterator(void)
	{
	}

	///构造方法
	CMarketDataTopicIterator(CMarketDataTopicFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CMarketDataTopicIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个MarketDataTopic
	///@return	下一个满足条件CMarketDataTopic，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketDataTopic *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CMarketDataTopicFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pMarketDataTopic 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketDataTopic * pMarketDataTopic,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CMarketDataTopicFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartTopicSubscribe是一个存储会员订阅市场的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartTopicSubscribe
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! ParticipantID.isValid())
			return 0;
		if (! ParticipantType.isValid())
			return 0;
		if (! TopicID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteablePartTopicSubscribe *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///参与者代码
	CParticipantIDType ParticipantID;
	///参与者类型
	CParticipantTypeType ParticipantType;
	///主题代码
	CTopicIDType TopicID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteablePartTopicSubscribe CPartTopicSubscribe;

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeActionTrigger是操作会员订阅市场时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeActionTrigger
{
public:
	///构造方法
	CPartTopicSubscribeActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartTopicSubscribeActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartTopicSubscribeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pPartTopicSubscribe	要加入的PartTopicSubscribe
	virtual void beforeAdd(CWriteablePartTopicSubscribe *pPartTopicSubscribe)
	{
		return;
	}
	
	///加入后触发
	///@param	pPartTopicSubscribe	已经加入的PartTopicSubscribe
	virtual void afterAdd(CPartTopicSubscribe *pPartTopicSubscribe)
	{
		return;
	}

	///更新前触发	
	///@param	pPartTopicSubscribe	被刷新的CPartTopicSubscribe
	///@param	pNewPartTopicSubscribe	新的值
	virtual void beforeUpdate(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pNewPartTopicSubscribe)
	{
		return;
	}
	
	///更新后触发
	///@param	pPartTopicSubscribe	被刷新的CPartTopicSubscribe
	virtual void afterUpdate(CPartTopicSubscribe *pPartTopicSubscribe)
	{
		return;
	}
	
	///删除前触发
	///@param	pPartTopicSubscribe	要删除的CPartTopicSubscribe
	virtual void beforeRemove(CPartTopicSubscribe *pPartTopicSubscribe)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartTopicSubscribeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeCommitTrigger是确认会员订阅市场时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeCommitTrigger
{
public:
	///构造方法
	CPartTopicSubscribeCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartTopicSubscribeCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartTopicSubscribeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pPartTopicSubscribe	已经加入的PartTopicSubscribe
	virtual void commitAdd(CPartTopicSubscribe *pPartTopicSubscribe)
	{
		return;
	}

	///更新后触发
	///@param	pPartTopicSubscribe	被刷新的CPartTopicSubscribe
	///@param	poldPartTopicSubscribe	原来的值
	virtual void commitUpdate(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pOldPartTopicSubscribe)
	{
		return;
	}
	
	///删除后触发
	///@param	pPartTopicSubscribe	已经删除的CPartTopicSubscribe
	virtual void commitRemove(CWriteablePartTopicSubscribe *pPartTopicSubscribe)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartTopicSubscribeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeIterator是一个对会员订阅市场的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeIterator
{
public:
	///构造方法
	CPartTopicSubscribeIterator(void)
	{
	}

	///构造方法
	CPartTopicSubscribeIterator(CPartTopicSubscribeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CPartTopicSubscribeIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个PartTopicSubscribe
	///@return	下一个满足条件CPartTopicSubscribe，如果已经没有一个满足要求了，则返回NULL
	virtual CPartTopicSubscribe *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CPartTopicSubscribeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pPartTopicSubscribe 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartTopicSubscribe * pPartTopicSubscribe,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CPartTopicSubscribeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableParticipant是一个存储会员的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableParticipant
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! ParticipantID.isValid())
			return 0;
		if (! ParticipantName.isValid())
			return 0;
		if (! ParticipantAbbr.isValid())
			return 0;
		if (! MemberType.isValid())
			return 0;
		if (! IsActive.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableParticipant *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///会员代码
	CParticipantIDType ParticipantID;
	///会员名称
	CParticipantNameType ParticipantName;
	///会员简称
	CParticipantAbbrType ParticipantAbbr;
	///会员类型
	CMemberTypeType MemberType;
	///是否活跃
	CBoolType IsActive;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	
	///构造对应的结算交易会员关系的指针
	///@param	pFactory	构造对应的结算交易会员关系的指针时，寻找的对象工厂
	///@return	找到的对应的结算交易会员关系的指针，如果找不到则返回NULL
	inline const CWriteableClearingTradingPart *linkClearingTradingPart(CClearingTradingPartFactory *pFactory) const;

	///构造对应的结算交易会员关系指针
	///@param	pClearingTradingPart	要连接到的对象
	///@return	输入的pClearingTradingPart
	const CWriteableClearingTradingPart *linkClearingTradingPart(const CWriteableClearingTradingPart *pClearingTradingPart) const
	{
		void *target=(void *)(&(this->pClearingTradingPart));
		*((const CWriteableClearingTradingPart **)target)=pClearingTradingPart;
		return pClearingTradingPart;
	}
	
	///获取对应的结算交易会员关系的指针
	///@return	找到的对应的结算交易会员关系的指针，如果找不到则返回NULL
	const CWriteableClearingTradingPart *getClearingTradingPart(void) const
	{
		return pClearingTradingPart;
	}

private:
	///对应的结算交易会员关系
	const CWriteableClearingTradingPart *pClearingTradingPart;
};

typedef const CWriteableParticipant CParticipant;

/////////////////////////////////////////////////////////////////////////
///CParticipantActionTrigger是操作会员时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantActionTrigger
{
public:
	///构造方法
	CParticipantActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CParticipantActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CParticipantFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pParticipant	要加入的Participant
	virtual void beforeAdd(CWriteableParticipant *pParticipant)
	{
		return;
	}
	
	///加入后触发
	///@param	pParticipant	已经加入的Participant
	virtual void afterAdd(CParticipant *pParticipant)
	{
		return;
	}

	///更新前触发	
	///@param	pParticipant	被刷新的CParticipant
	///@param	pNewParticipant	新的值
	virtual void beforeUpdate(CParticipant *pParticipant, CWriteableParticipant *pNewParticipant)
	{
		return;
	}
	
	///更新后触发
	///@param	pParticipant	被刷新的CParticipant
	virtual void afterUpdate(CParticipant *pParticipant)
	{
		return;
	}
	
	///删除前触发
	///@param	pParticipant	要删除的CParticipant
	virtual void beforeRemove(CParticipant *pParticipant)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CParticipantFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CParticipantCommitTrigger是确认会员时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantCommitTrigger
{
public:
	///构造方法
	CParticipantCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CParticipantCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CParticipantFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pParticipant	已经加入的Participant
	virtual void commitAdd(CParticipant *pParticipant)
	{
		return;
	}

	///更新后触发
	///@param	pParticipant	被刷新的CParticipant
	///@param	poldParticipant	原来的值
	virtual void commitUpdate(CParticipant *pParticipant, CWriteableParticipant *pOldParticipant)
	{
		return;
	}
	
	///删除后触发
	///@param	pParticipant	已经删除的CParticipant
	virtual void commitRemove(CWriteableParticipant *pParticipant)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CParticipantFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CParticipantIterator是一个对会员的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantIterator
{
public:
	///构造方法
	CParticipantIterator(void)
	{
	}

	///构造方法
	CParticipantIterator(CParticipantFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CParticipantIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个Participant
	///@return	下一个满足条件CParticipant，如果已经没有一个满足要求了，则返回NULL
	virtual CParticipant *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CParticipantFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pParticipant 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableParticipant * pParticipant,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CParticipantFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableUser是一个存储用户的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableUser
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! ParticipantID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! UserType.isValid())
			return 0;
		if (! Password.isValid())
			return 0;
		if (! IsActive.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableUser *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///会员代码
	CParticipantIDType ParticipantID;
	///交易用户代码
	CUserIDType UserID;
	///交易用户类型
	CUserTypeType UserType;
	///密码
	CPasswordType Password;
	///交易员权限
	CUserActiveType IsActive;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableUser CUser;

/////////////////////////////////////////////////////////////////////////
///CUserActionTrigger是操作用户时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserActionTrigger
{
public:
	///构造方法
	CUserActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CUserActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CUserFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pUser	要加入的User
	virtual void beforeAdd(CWriteableUser *pUser)
	{
		return;
	}
	
	///加入后触发
	///@param	pUser	已经加入的User
	virtual void afterAdd(CUser *pUser)
	{
		return;
	}

	///更新前触发	
	///@param	pUser	被刷新的CUser
	///@param	pNewUser	新的值
	virtual void beforeUpdate(CUser *pUser, CWriteableUser *pNewUser)
	{
		return;
	}
	
	///更新后触发
	///@param	pUser	被刷新的CUser
	virtual void afterUpdate(CUser *pUser)
	{
		return;
	}
	
	///删除前触发
	///@param	pUser	要删除的CUser
	virtual void beforeRemove(CUser *pUser)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CUserFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserCommitTrigger是确认用户时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommitTrigger
{
public:
	///构造方法
	CUserCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CUserCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CUserFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pUser	已经加入的User
	virtual void commitAdd(CUser *pUser)
	{
		return;
	}

	///更新后触发
	///@param	pUser	被刷新的CUser
	///@param	poldUser	原来的值
	virtual void commitUpdate(CUser *pUser, CWriteableUser *pOldUser)
	{
		return;
	}
	
	///删除后触发
	///@param	pUser	已经删除的CUser
	virtual void commitRemove(CWriteableUser *pUser)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CUserFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserIterator是一个对用户的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIterator
{
public:
	///构造方法
	CUserIterator(void)
	{
	}

	///构造方法
	CUserIterator(CUserFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CUserIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个User
	///@return	下一个满足条件CUser，如果已经没有一个满足要求了，则返回NULL
	virtual CUser *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CUserFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pUser 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUser * pUser,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CUserFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableClient是一个存储客户的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableClient
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! ClientID.isValid())
			return 0;
		if (! ClientName.isValid())
			return 0;
		if (! IdentifiedCardType.isValid())
			return 0;
		if (! IdentifiedCardNo.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! ClientType.isValid())
			return 0;
		if (! IsActive.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableClient *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///客户代码
	CClientIDType ClientID;
	///客户名称
	CPartyNameType ClientName;
	///证件类型
	CIdCardTypeType IdentifiedCardType;
	///证件号码
	CIdentifiedCardNoType IdentifiedCardNo;
	///交易角色
	CTradingRoleType TradingRole;
	///客户类型
	CClientTypeType ClientType;
	///是否活跃
	CBoolType IsActive;
	unsigned int HashClientID;
	
	///计算ClientID的hash值
	void calHashClientID(void)
	{
		unsigned key=0;
		key=ClientID.hash(key);
		HashClientID=key;
	}
	
	///根据需要情况，更新ClientID的hash值
	void updateHashClientID(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashClientID();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashClientID();
	}
	

private:
};

typedef const CWriteableClient CClient;

/////////////////////////////////////////////////////////////////////////
///CClientActionTrigger是操作客户时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientActionTrigger
{
public:
	///构造方法
	CClientActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CClientActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CClientFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pClient	要加入的Client
	virtual void beforeAdd(CWriteableClient *pClient)
	{
		return;
	}
	
	///加入后触发
	///@param	pClient	已经加入的Client
	virtual void afterAdd(CClient *pClient)
	{
		return;
	}

	///更新前触发	
	///@param	pClient	被刷新的CClient
	///@param	pNewClient	新的值
	virtual void beforeUpdate(CClient *pClient, CWriteableClient *pNewClient)
	{
		return;
	}
	
	///更新后触发
	///@param	pClient	被刷新的CClient
	virtual void afterUpdate(CClient *pClient)
	{
		return;
	}
	
	///删除前触发
	///@param	pClient	要删除的CClient
	virtual void beforeRemove(CClient *pClient)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CClientFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClientCommitTrigger是确认客户时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientCommitTrigger
{
public:
	///构造方法
	CClientCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CClientCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CClientFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pClient	已经加入的Client
	virtual void commitAdd(CClient *pClient)
	{
		return;
	}

	///更新后触发
	///@param	pClient	被刷新的CClient
	///@param	poldClient	原来的值
	virtual void commitUpdate(CClient *pClient, CWriteableClient *pOldClient)
	{
		return;
	}
	
	///删除后触发
	///@param	pClient	已经删除的CClient
	virtual void commitRemove(CWriteableClient *pClient)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CClientFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClientIterator是一个对客户的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientIterator
{
public:
	///构造方法
	CClientIterator(void)
	{
	}

	///构造方法
	CClientIterator(CClientFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CClientIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个Client
	///@return	下一个满足条件CClient，如果已经没有一个满足要求了，则返回NULL
	virtual CClient *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CClientFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pClient 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClient * pClient,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CClientFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableUserIP是一个存储交易员IP地址的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableUserIP
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! UserID.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! IPMask.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableUserIP *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易用户代码
	CUserIDType UserID;
	///IP地址
	CIPAddressType IPAddress;
	///IP地址掩码
	CIPAddressType IPMask;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableUserIP CUserIP;

/////////////////////////////////////////////////////////////////////////
///CUserIPActionTrigger是操作交易员IP地址时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPActionTrigger
{
public:
	///构造方法
	CUserIPActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CUserIPActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CUserIPFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pUserIP	要加入的UserIP
	virtual void beforeAdd(CWriteableUserIP *pUserIP)
	{
		return;
	}
	
	///加入后触发
	///@param	pUserIP	已经加入的UserIP
	virtual void afterAdd(CUserIP *pUserIP)
	{
		return;
	}

	///更新前触发	
	///@param	pUserIP	被刷新的CUserIP
	///@param	pNewUserIP	新的值
	virtual void beforeUpdate(CUserIP *pUserIP, CWriteableUserIP *pNewUserIP)
	{
		return;
	}
	
	///更新后触发
	///@param	pUserIP	被刷新的CUserIP
	virtual void afterUpdate(CUserIP *pUserIP)
	{
		return;
	}
	
	///删除前触发
	///@param	pUserIP	要删除的CUserIP
	virtual void beforeRemove(CUserIP *pUserIP)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CUserIPFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserIPCommitTrigger是确认交易员IP地址时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPCommitTrigger
{
public:
	///构造方法
	CUserIPCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CUserIPCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CUserIPFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pUserIP	已经加入的UserIP
	virtual void commitAdd(CUserIP *pUserIP)
	{
		return;
	}

	///更新后触发
	///@param	pUserIP	被刷新的CUserIP
	///@param	poldUserIP	原来的值
	virtual void commitUpdate(CUserIP *pUserIP, CWriteableUserIP *pOldUserIP)
	{
		return;
	}
	
	///删除后触发
	///@param	pUserIP	已经删除的CUserIP
	virtual void commitRemove(CWriteableUserIP *pUserIP)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CUserIPFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserIPIterator是一个对交易员IP地址的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPIterator
{
public:
	///构造方法
	CUserIPIterator(void)
	{
	}

	///构造方法
	CUserIPIterator(CUserIPFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CUserIPIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个UserIP
	///@return	下一个满足条件CUserIP，如果已经没有一个满足要求了，则返回NULL
	virtual CUserIP *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CUserIPFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pUserIP 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserIP * pUserIP,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CUserIPFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartClient是一个存储会员客户关系的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartClient
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! ClientID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteablePartClient *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///客户代码
	CClientIDType ClientID;
	///会员代码
	CParticipantIDType ParticipantID;
	unsigned int HashPartClient;
	
	///计算PartClient的hash值
	void calHashPartClient(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		key=ClientID.hash(key);
		HashPartClient=key;
	}
	
	///根据需要情况，更新PartClient的hash值
	void updateHashPartClient(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashPartClient();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashPartClient();
	}
	
	///构造对应的会员的指针
	///@param	pFactory	构造对应的会员的指针时，寻找的对象工厂
	///@return	找到的对应的会员的指针，如果找不到则返回NULL
	inline const CWriteableParticipant *linkParticipant(CParticipantFactory *pFactory) const;

	///构造对应的会员指针
	///@param	pParticipant	要连接到的对象
	///@return	输入的pParticipant
	const CWriteableParticipant *linkParticipant(const CWriteableParticipant *pParticipant) const
	{
		void *target=(void *)(&(this->pParticipant));
		*((const CWriteableParticipant **)target)=pParticipant;
		return pParticipant;
	}
	
	///获取对应的会员的指针
	///@return	找到的对应的会员的指针，如果找不到则返回NULL
	const CWriteableParticipant *getParticipant(void) const
	{
		return pParticipant;
	}
	///构造对应的客户的指针
	///@param	pFactory	构造对应的客户的指针时，寻找的对象工厂
	///@return	找到的对应的客户的指针，如果找不到则返回NULL
	inline const CWriteableClient *linkClient(CClientFactory *pFactory) const;

	///构造对应的客户指针
	///@param	pClient	要连接到的对象
	///@return	输入的pClient
	const CWriteableClient *linkClient(const CWriteableClient *pClient) const
	{
		void *target=(void *)(&(this->pClient));
		*((const CWriteableClient **)target)=pClient;
		return pClient;
	}
	
	///获取对应的客户的指针
	///@return	找到的对应的客户的指针，如果找不到则返回NULL
	const CWriteableClient *getClient(void) const
	{
		return pClient;
	}

private:
	///对应的会员
	const CWriteableParticipant *pParticipant;
	///对应的客户
	const CWriteableClient *pClient;
};

typedef const CWriteablePartClient CPartClient;

/////////////////////////////////////////////////////////////////////////
///CPartClientActionTrigger是操作会员客户关系时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientActionTrigger
{
public:
	///构造方法
	CPartClientActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartClientActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartClientFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pPartClient	要加入的PartClient
	virtual void beforeAdd(CWriteablePartClient *pPartClient)
	{
		return;
	}
	
	///加入后触发
	///@param	pPartClient	已经加入的PartClient
	virtual void afterAdd(CPartClient *pPartClient)
	{
		return;
	}

	///更新前触发	
	///@param	pPartClient	被刷新的CPartClient
	///@param	pNewPartClient	新的值
	virtual void beforeUpdate(CPartClient *pPartClient, CWriteablePartClient *pNewPartClient)
	{
		return;
	}
	
	///更新后触发
	///@param	pPartClient	被刷新的CPartClient
	virtual void afterUpdate(CPartClient *pPartClient)
	{
		return;
	}
	
	///删除前触发
	///@param	pPartClient	要删除的CPartClient
	virtual void beforeRemove(CPartClient *pPartClient)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartClientFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientCommitTrigger是确认会员客户关系时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientCommitTrigger
{
public:
	///构造方法
	CPartClientCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartClientCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartClientFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pPartClient	已经加入的PartClient
	virtual void commitAdd(CPartClient *pPartClient)
	{
		return;
	}

	///更新后触发
	///@param	pPartClient	被刷新的CPartClient
	///@param	poldPartClient	原来的值
	virtual void commitUpdate(CPartClient *pPartClient, CWriteablePartClient *pOldPartClient)
	{
		return;
	}
	
	///删除后触发
	///@param	pPartClient	已经删除的CPartClient
	virtual void commitRemove(CWriteablePartClient *pPartClient)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartClientFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientIterator是一个对会员客户关系的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientIterator
{
public:
	///构造方法
	CPartClientIterator(void)
	{
	}

	///构造方法
	CPartClientIterator(CPartClientFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CPartClientIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个PartClient
	///@return	下一个满足条件CPartClient，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClient *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CPartClientFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pPartClient 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClient * pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CPartClientFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableClearingTradingPart是一个存储结算交易会员关系的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableClearingTradingPart
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! ClearingPartID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableClearingTradingPart *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算会员
	CParticipantIDType ClearingPartID;
	///交易会员
	CParticipantIDType ParticipantID;
	unsigned int HashParticipantID;
	
	///计算ParticipantID的hash值
	void calHashParticipantID(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		HashParticipantID=key;
	}
	
	///根据需要情况，更新ParticipantID的hash值
	void updateHashParticipantID(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashParticipantID();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashParticipantID();
	}
	

private:
};

typedef const CWriteableClearingTradingPart CClearingTradingPart;

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartActionTrigger是操作结算交易会员关系时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartActionTrigger
{
public:
	///构造方法
	CClearingTradingPartActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CClearingTradingPartActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CClearingTradingPartFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pClearingTradingPart	要加入的ClearingTradingPart
	virtual void beforeAdd(CWriteableClearingTradingPart *pClearingTradingPart)
	{
		return;
	}
	
	///加入后触发
	///@param	pClearingTradingPart	已经加入的ClearingTradingPart
	virtual void afterAdd(CClearingTradingPart *pClearingTradingPart)
	{
		return;
	}

	///更新前触发	
	///@param	pClearingTradingPart	被刷新的CClearingTradingPart
	///@param	pNewClearingTradingPart	新的值
	virtual void beforeUpdate(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pNewClearingTradingPart)
	{
		return;
	}
	
	///更新后触发
	///@param	pClearingTradingPart	被刷新的CClearingTradingPart
	virtual void afterUpdate(CClearingTradingPart *pClearingTradingPart)
	{
		return;
	}
	
	///删除前触发
	///@param	pClearingTradingPart	要删除的CClearingTradingPart
	virtual void beforeRemove(CClearingTradingPart *pClearingTradingPart)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CClearingTradingPartFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartCommitTrigger是确认结算交易会员关系时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartCommitTrigger
{
public:
	///构造方法
	CClearingTradingPartCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CClearingTradingPartCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CClearingTradingPartFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pClearingTradingPart	已经加入的ClearingTradingPart
	virtual void commitAdd(CClearingTradingPart *pClearingTradingPart)
	{
		return;
	}

	///更新后触发
	///@param	pClearingTradingPart	被刷新的CClearingTradingPart
	///@param	poldClearingTradingPart	原来的值
	virtual void commitUpdate(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pOldClearingTradingPart)
	{
		return;
	}
	
	///删除后触发
	///@param	pClearingTradingPart	已经删除的CClearingTradingPart
	virtual void commitRemove(CWriteableClearingTradingPart *pClearingTradingPart)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CClearingTradingPartFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartIterator是一个对结算交易会员关系的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartIterator
{
public:
	///构造方法
	CClearingTradingPartIterator(void)
	{
	}

	///构造方法
	CClearingTradingPartIterator(CClearingTradingPartFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CClearingTradingPartIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个ClearingTradingPart
	///@return	下一个满足条件CClearingTradingPart，如果已经没有一个满足要求了，则返回NULL
	virtual CClearingTradingPart *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CClearingTradingPartFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pClearingTradingPart 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClearingTradingPart * pClearingTradingPart,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CClearingTradingPartFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableAliasDefine是一个存储别名定义的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableAliasDefine
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! StartPos.isValid())
			return 0;
		if (! Alias.isValid())
			return 0;
		if (! OriginalText.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableAliasDefine *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///起始位置
	CStartPosType StartPos;
	///别名
	CAliasType Alias;
	///原文
	COriginalTextType OriginalText;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableAliasDefine CAliasDefine;

/////////////////////////////////////////////////////////////////////////
///CAliasDefineActionTrigger是操作别名定义时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineActionTrigger
{
public:
	///构造方法
	CAliasDefineActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CAliasDefineActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CAliasDefineFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pAliasDefine	要加入的AliasDefine
	virtual void beforeAdd(CWriteableAliasDefine *pAliasDefine)
	{
		return;
	}
	
	///加入后触发
	///@param	pAliasDefine	已经加入的AliasDefine
	virtual void afterAdd(CAliasDefine *pAliasDefine)
	{
		return;
	}

	///更新前触发	
	///@param	pAliasDefine	被刷新的CAliasDefine
	///@param	pNewAliasDefine	新的值
	virtual void beforeUpdate(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pNewAliasDefine)
	{
		return;
	}
	
	///更新后触发
	///@param	pAliasDefine	被刷新的CAliasDefine
	virtual void afterUpdate(CAliasDefine *pAliasDefine)
	{
		return;
	}
	
	///删除前触发
	///@param	pAliasDefine	要删除的CAliasDefine
	virtual void beforeRemove(CAliasDefine *pAliasDefine)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CAliasDefineFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineCommitTrigger是确认别名定义时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineCommitTrigger
{
public:
	///构造方法
	CAliasDefineCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CAliasDefineCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CAliasDefineFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pAliasDefine	已经加入的AliasDefine
	virtual void commitAdd(CAliasDefine *pAliasDefine)
	{
		return;
	}

	///更新后触发
	///@param	pAliasDefine	被刷新的CAliasDefine
	///@param	poldAliasDefine	原来的值
	virtual void commitUpdate(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pOldAliasDefine)
	{
		return;
	}
	
	///删除后触发
	///@param	pAliasDefine	已经删除的CAliasDefine
	virtual void commitRemove(CWriteableAliasDefine *pAliasDefine)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CAliasDefineFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineIterator是一个对别名定义的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineIterator
{
public:
	///构造方法
	CAliasDefineIterator(void)
	{
	}

	///构造方法
	CAliasDefineIterator(CAliasDefineFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CAliasDefineIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个AliasDefine
	///@return	下一个满足条件CAliasDefine，如果已经没有一个满足要求了，则返回NULL
	virtual CAliasDefine *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CAliasDefineFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pAliasDefine 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableAliasDefine * pAliasDefine,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CAliasDefineFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableUserFunctionRight是一个存储用户功能权限的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableUserFunctionRight
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! UserID.isValid())
			return 0;
		if (! FunctionCode.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableUserFunctionRight *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易用户代码
	CUserIDType UserID;
	///功能代码
	CFunctionCodeType FunctionCode;
	unsigned int HashUserFunction;
	
	///计算UserFunction的hash值
	void calHashUserFunction(void)
	{
		unsigned key=0;
		key=UserID.hash(key);
		key=FunctionCode.hash(key);
		HashUserFunction=key;
	}
	
	///根据需要情况，更新UserFunction的hash值
	void updateHashUserFunction(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashUserFunction();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashUserFunction();
	}
	

private:
};

typedef const CWriteableUserFunctionRight CUserFunctionRight;

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightActionTrigger是操作用户功能权限时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightActionTrigger
{
public:
	///构造方法
	CUserFunctionRightActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CUserFunctionRightActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CUserFunctionRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pUserFunctionRight	要加入的UserFunctionRight
	virtual void beforeAdd(CWriteableUserFunctionRight *pUserFunctionRight)
	{
		return;
	}
	
	///加入后触发
	///@param	pUserFunctionRight	已经加入的UserFunctionRight
	virtual void afterAdd(CUserFunctionRight *pUserFunctionRight)
	{
		return;
	}

	///更新前触发	
	///@param	pUserFunctionRight	被刷新的CUserFunctionRight
	///@param	pNewUserFunctionRight	新的值
	virtual void beforeUpdate(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pNewUserFunctionRight)
	{
		return;
	}
	
	///更新后触发
	///@param	pUserFunctionRight	被刷新的CUserFunctionRight
	virtual void afterUpdate(CUserFunctionRight *pUserFunctionRight)
	{
		return;
	}
	
	///删除前触发
	///@param	pUserFunctionRight	要删除的CUserFunctionRight
	virtual void beforeRemove(CUserFunctionRight *pUserFunctionRight)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CUserFunctionRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightCommitTrigger是确认用户功能权限时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightCommitTrigger
{
public:
	///构造方法
	CUserFunctionRightCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CUserFunctionRightCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CUserFunctionRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pUserFunctionRight	已经加入的UserFunctionRight
	virtual void commitAdd(CUserFunctionRight *pUserFunctionRight)
	{
		return;
	}

	///更新后触发
	///@param	pUserFunctionRight	被刷新的CUserFunctionRight
	///@param	poldUserFunctionRight	原来的值
	virtual void commitUpdate(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pOldUserFunctionRight)
	{
		return;
	}
	
	///删除后触发
	///@param	pUserFunctionRight	已经删除的CUserFunctionRight
	virtual void commitRemove(CWriteableUserFunctionRight *pUserFunctionRight)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CUserFunctionRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightIterator是一个对用户功能权限的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightIterator
{
public:
	///构造方法
	CUserFunctionRightIterator(void)
	{
	}

	///构造方法
	CUserFunctionRightIterator(CUserFunctionRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CUserFunctionRightIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个UserFunctionRight
	///@return	下一个满足条件CUserFunctionRight，如果已经没有一个满足要求了，则返回NULL
	virtual CUserFunctionRight *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CUserFunctionRightFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pUserFunctionRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserFunctionRight * pUserFunctionRight,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CUserFunctionRightFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableAccount是一个存储资金账户的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableAccount
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! AccountID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! Currency.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableAccount *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///资金帐号
	CAccountIDType AccountID;
	///会员代码
	CParticipantIDType ParticipantID;
	///币种
	CCurrencyType Currency;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	
	///构造对应的交易账户的指针
	///@param	pFactory	构造对应的交易账户的指针时，寻找的对象工厂
	///@return	找到的对应的交易账户的指针，如果找不到则返回NULL
	inline const CWriteableTradingAccount *linkTradingAccount(CTradingAccountFactory *pFactory) const;

	///构造对应的交易账户指针
	///@param	pTradingAccount	要连接到的对象
	///@return	输入的pTradingAccount
	const CWriteableTradingAccount *linkTradingAccount(const CWriteableTradingAccount *pTradingAccount) const
	{
		void *target=(void *)(&(this->pTradingAccount));
		*((const CWriteableTradingAccount **)target)=pTradingAccount;
		return pTradingAccount;
	}
	
	///获取对应的交易账户的指针
	///@return	找到的对应的交易账户的指针，如果找不到则返回NULL
	const CWriteableTradingAccount *getTradingAccount(void) const
	{
		return pTradingAccount;
	}

private:
	///对应的交易账户
	const CWriteableTradingAccount *pTradingAccount;
};

typedef const CWriteableAccount CAccount;

/////////////////////////////////////////////////////////////////////////
///CAccountActionTrigger是操作资金账户时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountActionTrigger
{
public:
	///构造方法
	CAccountActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CAccountActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pAccount	要加入的Account
	virtual void beforeAdd(CWriteableAccount *pAccount)
	{
		return;
	}
	
	///加入后触发
	///@param	pAccount	已经加入的Account
	virtual void afterAdd(CAccount *pAccount)
	{
		return;
	}

	///更新前触发	
	///@param	pAccount	被刷新的CAccount
	///@param	pNewAccount	新的值
	virtual void beforeUpdate(CAccount *pAccount, CWriteableAccount *pNewAccount)
	{
		return;
	}
	
	///更新后触发
	///@param	pAccount	被刷新的CAccount
	virtual void afterUpdate(CAccount *pAccount)
	{
		return;
	}
	
	///删除前触发
	///@param	pAccount	要删除的CAccount
	virtual void beforeRemove(CAccount *pAccount)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CAccountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CAccountCommitTrigger是确认资金账户时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountCommitTrigger
{
public:
	///构造方法
	CAccountCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CAccountCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pAccount	已经加入的Account
	virtual void commitAdd(CAccount *pAccount)
	{
		return;
	}

	///更新后触发
	///@param	pAccount	被刷新的CAccount
	///@param	poldAccount	原来的值
	virtual void commitUpdate(CAccount *pAccount, CWriteableAccount *pOldAccount)
	{
		return;
	}
	
	///删除后触发
	///@param	pAccount	已经删除的CAccount
	virtual void commitRemove(CWriteableAccount *pAccount)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CAccountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CAccountIterator是一个对资金账户的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountIterator
{
public:
	///构造方法
	CAccountIterator(void)
	{
	}

	///构造方法
	CAccountIterator(CAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CAccountIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个Account
	///@return	下一个满足条件CAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CAccount *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CAccountFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableAccount * pAccount,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CAccountFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableUserCommFlux是一个存储用户通讯量的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableUserCommFlux
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! UserID.isValid())
			return 0;
		if (! MaxCommFlux.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableUserCommFlux *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易用户代码
	CUserIDType UserID;
	///最大通讯量
	CCommFluxType MaxCommFlux;
	unsigned int HashUserID;
	
	///计算UserID的hash值
	void calHashUserID(void)
	{
		unsigned key=0;
		key=UserID.hash(key);
		HashUserID=key;
	}
	
	///根据需要情况，更新UserID的hash值
	void updateHashUserID(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashUserID();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashUserID();
	}
	

private:
};

typedef const CWriteableUserCommFlux CUserCommFlux;

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxActionTrigger是操作用户通讯量时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxActionTrigger
{
public:
	///构造方法
	CUserCommFluxActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CUserCommFluxActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CUserCommFluxFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pUserCommFlux	要加入的UserCommFlux
	virtual void beforeAdd(CWriteableUserCommFlux *pUserCommFlux)
	{
		return;
	}
	
	///加入后触发
	///@param	pUserCommFlux	已经加入的UserCommFlux
	virtual void afterAdd(CUserCommFlux *pUserCommFlux)
	{
		return;
	}

	///更新前触发	
	///@param	pUserCommFlux	被刷新的CUserCommFlux
	///@param	pNewUserCommFlux	新的值
	virtual void beforeUpdate(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pNewUserCommFlux)
	{
		return;
	}
	
	///更新后触发
	///@param	pUserCommFlux	被刷新的CUserCommFlux
	virtual void afterUpdate(CUserCommFlux *pUserCommFlux)
	{
		return;
	}
	
	///删除前触发
	///@param	pUserCommFlux	要删除的CUserCommFlux
	virtual void beforeRemove(CUserCommFlux *pUserCommFlux)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CUserCommFluxFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxCommitTrigger是确认用户通讯量时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxCommitTrigger
{
public:
	///构造方法
	CUserCommFluxCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CUserCommFluxCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CUserCommFluxFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pUserCommFlux	已经加入的UserCommFlux
	virtual void commitAdd(CUserCommFlux *pUserCommFlux)
	{
		return;
	}

	///更新后触发
	///@param	pUserCommFlux	被刷新的CUserCommFlux
	///@param	poldUserCommFlux	原来的值
	virtual void commitUpdate(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pOldUserCommFlux)
	{
		return;
	}
	
	///删除后触发
	///@param	pUserCommFlux	已经删除的CUserCommFlux
	virtual void commitRemove(CWriteableUserCommFlux *pUserCommFlux)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CUserCommFluxFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxIterator是一个对用户通讯量的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxIterator
{
public:
	///构造方法
	CUserCommFluxIterator(void)
	{
	}

	///构造方法
	CUserCommFluxIterator(CUserCommFluxFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CUserCommFluxIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个UserCommFlux
	///@return	下一个满足条件CUserCommFlux，如果已经没有一个满足要求了，则返回NULL
	virtual CUserCommFlux *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CUserCommFluxFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pUserCommFlux 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserCommFlux * pUserCommFlux,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CUserCommFluxFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMarketDataLog是一个存储行情流水的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMarketDataLog
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! MarketDataLogNo.isValid())
			return 0;
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! LastPrice.isValid())
			return 0;
		if (! PreSettlementPrice.isValid())
			return 0;
		if (! PreClosePrice.isValid())
			return 0;
		if (! PreOpenInterest.isValid())
			return 0;
		if (! OpenPrice.isValid())
			return 0;
		if (! HighestPrice.isValid())
			return 0;
		if (! LowestPrice.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! Turnover.isValid())
			return 0;
		if (! OpenInterest.isValid())
			return 0;
		if (! ClosePrice.isValid())
			return 0;
		if (! SettlementPrice.isValid())
			return 0;
		if (! UpperLimitPrice.isValid())
			return 0;
		if (! LowerLimitPrice.isValid())
			return 0;
		if (! PreDelta.isValid())
			return 0;
		if (! CurrDelta.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		if (! UpdateMillisec.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableMarketDataLog *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///行情流水编号
	CSequenceNoType MarketDataLogNo;
	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///最新价
	CPriceType LastPrice;
	///昨结算
	CPriceType PreSettlementPrice;
	///昨收盘
	CPriceType PreClosePrice;
	///昨持仓量
	CLargeVolumeType PreOpenInterest;
	///今开盘
	CPriceType OpenPrice;
	///最高价
	CPriceType HighestPrice;
	///最低价
	CPriceType LowestPrice;
	///数量
	CVolumeType Volume;
	///成交金额
	CMoneyType Turnover;
	///持仓量
	CLargeVolumeType OpenInterest;
	///今收盘
	CPriceType ClosePrice;
	///今结算
	CPriceType SettlementPrice;
	///涨停板价
	CPriceType UpperLimitPrice;
	///跌停板价
	CPriceType LowerLimitPrice;
	///昨虚实度
	CRatioType PreDelta;
	///今虚实度
	CRatioType CurrDelta;
	///最后修改时间
	CTimeType UpdateTime;
	///最后修改毫秒
	CMillisecType UpdateMillisec;
	///合约代码
	CInstrumentIDType InstrumentID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMarketDataLog CMarketDataLog;

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogActionTrigger是操作行情流水时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogActionTrigger
{
public:
	///构造方法
	CMarketDataLogActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMarketDataLogActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMarketDataLogFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pMarketDataLog	要加入的MarketDataLog
	virtual void beforeAdd(CWriteableMarketDataLog *pMarketDataLog)
	{
		return;
	}
	
	///加入后触发
	///@param	pMarketDataLog	已经加入的MarketDataLog
	virtual void afterAdd(CMarketDataLog *pMarketDataLog)
	{
		return;
	}

	///更新前触发	
	///@param	pMarketDataLog	被刷新的CMarketDataLog
	///@param	pNewMarketDataLog	新的值
	virtual void beforeUpdate(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pNewMarketDataLog)
	{
		return;
	}
	
	///更新后触发
	///@param	pMarketDataLog	被刷新的CMarketDataLog
	virtual void afterUpdate(CMarketDataLog *pMarketDataLog)
	{
		return;
	}
	
	///删除前触发
	///@param	pMarketDataLog	要删除的CMarketDataLog
	virtual void beforeRemove(CMarketDataLog *pMarketDataLog)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMarketDataLogFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogCommitTrigger是确认行情流水时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogCommitTrigger
{
public:
	///构造方法
	CMarketDataLogCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMarketDataLogCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMarketDataLogFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pMarketDataLog	已经加入的MarketDataLog
	virtual void commitAdd(CMarketDataLog *pMarketDataLog)
	{
		return;
	}

	///更新后触发
	///@param	pMarketDataLog	被刷新的CMarketDataLog
	///@param	poldMarketDataLog	原来的值
	virtual void commitUpdate(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pOldMarketDataLog)
	{
		return;
	}
	
	///删除后触发
	///@param	pMarketDataLog	已经删除的CMarketDataLog
	virtual void commitRemove(CWriteableMarketDataLog *pMarketDataLog)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMarketDataLogFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogIterator是一个对行情流水的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogIterator
{
public:
	///构造方法
	CMarketDataLogIterator(void)
	{
	}

	///构造方法
	CMarketDataLogIterator(CMarketDataLogFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CMarketDataLogIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个MarketDataLog
	///@return	下一个满足条件CMarketDataLog，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketDataLog *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CMarketDataLogFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pMarketDataLog 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketDataLog * pMarketDataLog,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CMarketDataLogFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableUserSession是一个存储交易员在线会话的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableUserSession
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! FrontID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! UserType.isValid())
			return 0;
		if (! SessionID.isValid())
			return 0;
		if (! LoginTime.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! UserProductInfo.isValid())
			return 0;
		if (! InterfaceProductInfo.isValid())
			return 0;
		if (! ProtocolInfo.isValid())
			return 0;
		if (! SessionType.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableUserSession *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///前置编号
	CFrontIDType FrontID;
	///交易用户代码
	CUserIDType UserID;
	///交易用户类型
	CUserTypeType UserType;
	///会话编号
	CSessionIDType SessionID;
	///登录时间
	CTimeType LoginTime;
	///会员代码
	CParticipantIDType ParticipantID;
	///IP地址
	CIPAddressType IPAddress;
	///用户端产品信息
	CProductInfoType UserProductInfo;
	///接口端产品信息
	CProductInfoType InterfaceProductInfo;
	///协议信息
	CProtocolInfoType ProtocolInfo;
	///会话类型
	CSessionTypeType SessionType;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	
	///构造对应的交易员的指针
	///@param	pFactory	构造对应的交易员的指针时，寻找的对象工厂
	///@return	找到的对应的交易员的指针，如果找不到则返回NULL
	inline const CWriteableUser *linkUser(CUserFactory *pFactory) const;

	///构造对应的交易员指针
	///@param	pUser	要连接到的对象
	///@return	输入的pUser
	const CWriteableUser *linkUser(const CWriteableUser *pUser) const
	{
		void *target=(void *)(&(this->pUser));
		*((const CWriteableUser **)target)=pUser;
		return pUser;
	}
	
	///获取对应的交易员的指针
	///@return	找到的对应的交易员的指针，如果找不到则返回NULL
	const CWriteableUser *getUser(void) const
	{
		return pUser;
	}

private:
	///对应的交易员
	const CWriteableUser *pUser;
};

typedef const CWriteableUserSession CUserSession;

/////////////////////////////////////////////////////////////////////////
///CUserSessionActionTrigger是操作交易员在线会话时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionActionTrigger
{
public:
	///构造方法
	CUserSessionActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CUserSessionActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CUserSessionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pUserSession	要加入的UserSession
	virtual void beforeAdd(CWriteableUserSession *pUserSession)
	{
		return;
	}
	
	///加入后触发
	///@param	pUserSession	已经加入的UserSession
	virtual void afterAdd(CUserSession *pUserSession)
	{
		return;
	}

	///更新前触发	
	///@param	pUserSession	被刷新的CUserSession
	///@param	pNewUserSession	新的值
	virtual void beforeUpdate(CUserSession *pUserSession, CWriteableUserSession *pNewUserSession)
	{
		return;
	}
	
	///更新后触发
	///@param	pUserSession	被刷新的CUserSession
	virtual void afterUpdate(CUserSession *pUserSession)
	{
		return;
	}
	
	///删除前触发
	///@param	pUserSession	要删除的CUserSession
	virtual void beforeRemove(CUserSession *pUserSession)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CUserSessionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionCommitTrigger是确认交易员在线会话时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionCommitTrigger
{
public:
	///构造方法
	CUserSessionCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CUserSessionCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CUserSessionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pUserSession	已经加入的UserSession
	virtual void commitAdd(CUserSession *pUserSession)
	{
		return;
	}

	///更新后触发
	///@param	pUserSession	被刷新的CUserSession
	///@param	poldUserSession	原来的值
	virtual void commitUpdate(CUserSession *pUserSession, CWriteableUserSession *pOldUserSession)
	{
		return;
	}
	
	///删除后触发
	///@param	pUserSession	已经删除的CUserSession
	virtual void commitRemove(CWriteableUserSession *pUserSession)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CUserSessionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionIterator是一个对交易员在线会话的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionIterator
{
public:
	///构造方法
	CUserSessionIterator(void)
	{
	}

	///构造方法
	CUserSessionIterator(CUserSessionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CUserSessionIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个UserSession
	///@return	下一个满足条件CUserSession，如果已经没有一个满足要求了，则返回NULL
	virtual CUserSession *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CUserSessionFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pUserSession 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserSession * pUserSession,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CUserSessionFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMDSession是一个存储行情订阅者在线会话的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMDSession
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! FrontID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! UserType.isValid())
			return 0;
		if (! SessionID.isValid())
			return 0;
		if (! LoginTime.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! UserProductInfo.isValid())
			return 0;
		if (! InterfaceProductInfo.isValid())
			return 0;
		if (! ProtocolInfo.isValid())
			return 0;
		if (! SessionType.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableMDSession *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///前置编号
	CFrontIDType FrontID;
	///交易用户代码
	CUserIDType UserID;
	///交易用户类型
	CUserTypeType UserType;
	///会话编号
	CSessionIDType SessionID;
	///登录时间
	CTimeType LoginTime;
	///会员代码
	CParticipantIDType ParticipantID;
	///IP地址
	CIPAddressType IPAddress;
	///用户端产品信息
	CProductInfoType UserProductInfo;
	///接口端产品信息
	CProductInfoType InterfaceProductInfo;
	///协议信息
	CProtocolInfoType ProtocolInfo;
	///会话类型
	CSessionTypeType SessionType;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMDSession CMDSession;

/////////////////////////////////////////////////////////////////////////
///CMDSessionActionTrigger是操作行情订阅者在线会话时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionActionTrigger
{
public:
	///构造方法
	CMDSessionActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMDSessionActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMDSessionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pMDSession	要加入的MDSession
	virtual void beforeAdd(CWriteableMDSession *pMDSession)
	{
		return;
	}
	
	///加入后触发
	///@param	pMDSession	已经加入的MDSession
	virtual void afterAdd(CMDSession *pMDSession)
	{
		return;
	}

	///更新前触发	
	///@param	pMDSession	被刷新的CMDSession
	///@param	pNewMDSession	新的值
	virtual void beforeUpdate(CMDSession *pMDSession, CWriteableMDSession *pNewMDSession)
	{
		return;
	}
	
	///更新后触发
	///@param	pMDSession	被刷新的CMDSession
	virtual void afterUpdate(CMDSession *pMDSession)
	{
		return;
	}
	
	///删除前触发
	///@param	pMDSession	要删除的CMDSession
	virtual void beforeRemove(CMDSession *pMDSession)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMDSessionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionCommitTrigger是确认行情订阅者在线会话时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionCommitTrigger
{
public:
	///构造方法
	CMDSessionCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMDSessionCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMDSessionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pMDSession	已经加入的MDSession
	virtual void commitAdd(CMDSession *pMDSession)
	{
		return;
	}

	///更新后触发
	///@param	pMDSession	被刷新的CMDSession
	///@param	poldMDSession	原来的值
	virtual void commitUpdate(CMDSession *pMDSession, CWriteableMDSession *pOldMDSession)
	{
		return;
	}
	
	///删除后触发
	///@param	pMDSession	已经删除的CMDSession
	virtual void commitRemove(CWriteableMDSession *pMDSession)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMDSessionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionIterator是一个对行情订阅者在线会话的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionIterator
{
public:
	///构造方法
	CMDSessionIterator(void)
	{
	}

	///构造方法
	CMDSessionIterator(CMDSessionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CMDSessionIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个MDSession
	///@return	下一个满足条件CMDSession，如果已经没有一个满足要求了，则返回NULL
	virtual CMDSession *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CMDSessionFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pMDSession 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMDSession * pMDSession,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CMDSessionFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableLoginInfo是一个存储用户登陆登出信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableLoginInfo
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SequenceNo.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! UserProductInfo.isValid())
			return 0;
		if (! InterfaceProductInfo.isValid())
			return 0;
		if (! ProtocolInfo.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! LoginType.isValid())
			return 0;
		if (! SessionType.isValid())
			return 0;
		if (! ErrorID.isValid())
			return 0;
		if (! UpdateDate.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableLoginInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///序号
	CSequenceNoType SequenceNo;
	///交易用户代码
	CUserIDType UserID;
	///会员代码
	CParticipantIDType ParticipantID;
	///用户端产品信息
	CProductInfoType UserProductInfo;
	///接口端产品信息
	CProductInfoType InterfaceProductInfo;
	///协议信息
	CProtocolInfoType ProtocolInfo;
	///IP地址
	CIPAddressType IPAddress;
	///登录类型
	CLoginTypeType LoginType;
	///会话类型
	CSessionTypeType SessionType;
	///错误代码
	CErrorIDType ErrorID;
	///更新日期
	CDateType UpdateDate;
	///更新时间
	CTimeType UpdateTime;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableLoginInfo CLoginInfo;

/////////////////////////////////////////////////////////////////////////
///CLoginInfoActionTrigger是操作用户登陆登出信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoActionTrigger
{
public:
	///构造方法
	CLoginInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CLoginInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CLoginInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pLoginInfo	要加入的LoginInfo
	virtual void beforeAdd(CWriteableLoginInfo *pLoginInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pLoginInfo	已经加入的LoginInfo
	virtual void afterAdd(CLoginInfo *pLoginInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pLoginInfo	被刷新的CLoginInfo
	///@param	pNewLoginInfo	新的值
	virtual void beforeUpdate(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pNewLoginInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pLoginInfo	被刷新的CLoginInfo
	virtual void afterUpdate(CLoginInfo *pLoginInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pLoginInfo	要删除的CLoginInfo
	virtual void beforeRemove(CLoginInfo *pLoginInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CLoginInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoCommitTrigger是确认用户登陆登出信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoCommitTrigger
{
public:
	///构造方法
	CLoginInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CLoginInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CLoginInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pLoginInfo	已经加入的LoginInfo
	virtual void commitAdd(CLoginInfo *pLoginInfo)
	{
		return;
	}

	///更新后触发
	///@param	pLoginInfo	被刷新的CLoginInfo
	///@param	poldLoginInfo	原来的值
	virtual void commitUpdate(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pOldLoginInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pLoginInfo	已经删除的CLoginInfo
	virtual void commitRemove(CWriteableLoginInfo *pLoginInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CLoginInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoIterator是一个对用户登陆登出信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoIterator
{
public:
	///构造方法
	CLoginInfoIterator(void)
	{
	}

	///构造方法
	CLoginInfoIterator(CLoginInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CLoginInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个LoginInfo
	///@return	下一个满足条件CLoginInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CLoginInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CLoginInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pLoginInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableLoginInfo * pLoginInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CLoginInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableDepthMarketDataDetail是一个存储深度市场行情明细的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableDepthMarketDataDetail
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! LastPrice.isValid())
			return 0;
		if (! PreSettlementPrice.isValid())
			return 0;
		if (! PreClosePrice.isValid())
			return 0;
		if (! PreOpenInterest.isValid())
			return 0;
		if (! OpenPrice.isValid())
			return 0;
		if (! HighestPrice.isValid())
			return 0;
		if (! LowestPrice.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! Turnover.isValid())
			return 0;
		if (! OpenInterest.isValid())
			return 0;
		if (! ClosePrice.isValid())
			return 0;
		if (! SettlementPrice.isValid())
			return 0;
		if (! UpperLimitPrice.isValid())
			return 0;
		if (! LowerLimitPrice.isValid())
			return 0;
		if (! PreDelta.isValid())
			return 0;
		if (! CurrDelta.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		if (! UpdateMillisec.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! BidPrice1.isValid())
			return 0;
		if (! BidVolume1.isValid())
			return 0;
		if (! AskPrice1.isValid())
			return 0;
		if (! AskVolume1.isValid())
			return 0;
		if (! BidPrice2.isValid())
			return 0;
		if (! BidVolume2.isValid())
			return 0;
		if (! AskPrice2.isValid())
			return 0;
		if (! AskVolume2.isValid())
			return 0;
		if (! BidPrice3.isValid())
			return 0;
		if (! BidVolume3.isValid())
			return 0;
		if (! AskPrice3.isValid())
			return 0;
		if (! AskVolume3.isValid())
			return 0;
		if (! BidPrice4.isValid())
			return 0;
		if (! BidVolume4.isValid())
			return 0;
		if (! AskPrice4.isValid())
			return 0;
		if (! AskVolume4.isValid())
			return 0;
		if (! BidPrice5.isValid())
			return 0;
		if (! BidVolume5.isValid())
			return 0;
		if (! AskPrice5.isValid())
			return 0;
		if (! AskVolume5.isValid())
			return 0;
		if (! SequenceNo.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableDepthMarketDataDetail *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///最新价
	CPriceType LastPrice;
	///昨结算
	CPriceType PreSettlementPrice;
	///昨收盘
	CPriceType PreClosePrice;
	///昨持仓量
	CLargeVolumeType PreOpenInterest;
	///今开盘
	CPriceType OpenPrice;
	///最高价
	CPriceType HighestPrice;
	///最低价
	CPriceType LowestPrice;
	///数量
	CVolumeType Volume;
	///成交金额
	CMoneyType Turnover;
	///持仓量
	CLargeVolumeType OpenInterest;
	///今收盘
	CPriceType ClosePrice;
	///今结算
	CPriceType SettlementPrice;
	///涨停板价
	CPriceType UpperLimitPrice;
	///跌停板价
	CPriceType LowerLimitPrice;
	///昨虚实度
	CRatioType PreDelta;
	///今虚实度
	CRatioType CurrDelta;
	///最后修改时间
	CTimeType UpdateTime;
	///最后修改毫秒
	CMillisecType UpdateMillisec;
	///合约代码
	CInstrumentIDType InstrumentID;
	///申买价一
	CPriceType BidPrice1;
	///申买量一
	CVolumeType BidVolume1;
	///申卖价一
	CPriceType AskPrice1;
	///申卖量一
	CVolumeType AskVolume1;
	///申买价二
	CPriceType BidPrice2;
	///申买量二
	CVolumeType BidVolume2;
	///申卖价二
	CPriceType AskPrice2;
	///申卖量二
	CVolumeType AskVolume2;
	///申买价三
	CPriceType BidPrice3;
	///申买量三
	CVolumeType BidVolume3;
	///申卖价三
	CPriceType AskPrice3;
	///申卖量三
	CVolumeType AskVolume3;
	///申买价四
	CPriceType BidPrice4;
	///申买量四
	CVolumeType BidVolume4;
	///申卖价四
	CPriceType AskPrice4;
	///申卖量四
	CVolumeType AskVolume4;
	///申买价五
	CPriceType BidPrice5;
	///申买量五
	CVolumeType BidVolume5;
	///申卖价五
	CPriceType AskPrice5;
	///申卖量五
	CVolumeType AskVolume5;
	///序号
	CSequenceNoType SequenceNo;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableDepthMarketDataDetail CDepthMarketDataDetail;

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailActionTrigger是操作深度市场行情明细时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailActionTrigger
{
public:
	///构造方法
	CDepthMarketDataDetailActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CDepthMarketDataDetailActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CDepthMarketDataDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pDepthMarketDataDetail	要加入的DepthMarketDataDetail
	virtual void beforeAdd(CWriteableDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return;
	}
	
	///加入后触发
	///@param	pDepthMarketDataDetail	已经加入的DepthMarketDataDetail
	virtual void afterAdd(CDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return;
	}

	///更新前触发	
	///@param	pDepthMarketDataDetail	被刷新的CDepthMarketDataDetail
	///@param	pNewDepthMarketDataDetail	新的值
	virtual void beforeUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pNewDepthMarketDataDetail)
	{
		return;
	}
	
	///更新后触发
	///@param	pDepthMarketDataDetail	被刷新的CDepthMarketDataDetail
	virtual void afterUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return;
	}
	
	///删除前触发
	///@param	pDepthMarketDataDetail	要删除的CDepthMarketDataDetail
	virtual void beforeRemove(CDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CDepthMarketDataDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailCommitTrigger是确认深度市场行情明细时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailCommitTrigger
{
public:
	///构造方法
	CDepthMarketDataDetailCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CDepthMarketDataDetailCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CDepthMarketDataDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pDepthMarketDataDetail	已经加入的DepthMarketDataDetail
	virtual void commitAdd(CDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return;
	}

	///更新后触发
	///@param	pDepthMarketDataDetail	被刷新的CDepthMarketDataDetail
	///@param	poldDepthMarketDataDetail	原来的值
	virtual void commitUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pOldDepthMarketDataDetail)
	{
		return;
	}
	
	///删除后触发
	///@param	pDepthMarketDataDetail	已经删除的CDepthMarketDataDetail
	virtual void commitRemove(CWriteableDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CDepthMarketDataDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailIterator是一个对深度市场行情明细的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailIterator
{
public:
	///构造方法
	CDepthMarketDataDetailIterator(void)
	{
	}

	///构造方法
	CDepthMarketDataDetailIterator(CDepthMarketDataDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CDepthMarketDataDetailIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个DepthMarketDataDetail
	///@return	下一个满足条件CDepthMarketDataDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CDepthMarketDataDetail *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CDepthMarketDataDetailFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pDepthMarketDataDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableDepthMarketDataDetail * pDepthMarketDataDetail,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CDepthMarketDataDetailFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableInstrumentStatusDetail是一个存储合约交易状态流水的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableInstrumentStatusDetail
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! InstrumentStatus.isValid())
			return 0;
		if (! TradingSegmentSN.isValid())
			return 0;
		if (! EnterTime.isValid())
			return 0;
		if (! EnterReason.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! SequenceNo.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableInstrumentStatusDetail *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///合约交易状态
	CInstrumentStatusType InstrumentStatus;
	///交易阶段编号
	CTradingSegmentSNType TradingSegmentSN;
	///进入本状态时间
	CTimeType EnterTime;
	///进入本状态原因
	CInstStatusEnterReasonType EnterReason;
	///结算编号
	CSettlementIDType SettlementID;
	///序列号
	CSequenceNoType SequenceNo;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableInstrumentStatusDetail CInstrumentStatusDetail;

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailActionTrigger是操作合约交易状态流水时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailActionTrigger
{
public:
	///构造方法
	CInstrumentStatusDetailActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CInstrumentStatusDetailActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CInstrumentStatusDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pInstrumentStatusDetail	要加入的InstrumentStatusDetail
	virtual void beforeAdd(CWriteableInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return;
	}
	
	///加入后触发
	///@param	pInstrumentStatusDetail	已经加入的InstrumentStatusDetail
	virtual void afterAdd(CInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return;
	}

	///更新前触发	
	///@param	pInstrumentStatusDetail	被刷新的CInstrumentStatusDetail
	///@param	pNewInstrumentStatusDetail	新的值
	virtual void beforeUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pNewInstrumentStatusDetail)
	{
		return;
	}
	
	///更新后触发
	///@param	pInstrumentStatusDetail	被刷新的CInstrumentStatusDetail
	virtual void afterUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return;
	}
	
	///删除前触发
	///@param	pInstrumentStatusDetail	要删除的CInstrumentStatusDetail
	virtual void beforeRemove(CInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CInstrumentStatusDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailCommitTrigger是确认合约交易状态流水时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailCommitTrigger
{
public:
	///构造方法
	CInstrumentStatusDetailCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CInstrumentStatusDetailCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CInstrumentStatusDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pInstrumentStatusDetail	已经加入的InstrumentStatusDetail
	virtual void commitAdd(CInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return;
	}

	///更新后触发
	///@param	pInstrumentStatusDetail	被刷新的CInstrumentStatusDetail
	///@param	poldInstrumentStatusDetail	原来的值
	virtual void commitUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pOldInstrumentStatusDetail)
	{
		return;
	}
	
	///删除后触发
	///@param	pInstrumentStatusDetail	已经删除的CInstrumentStatusDetail
	virtual void commitRemove(CWriteableInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CInstrumentStatusDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailIterator是一个对合约交易状态流水的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailIterator
{
public:
	///构造方法
	CInstrumentStatusDetailIterator(void)
	{
	}

	///构造方法
	CInstrumentStatusDetailIterator(CInstrumentStatusDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CInstrumentStatusDetailIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个InstrumentStatusDetail
	///@return	下一个满足条件CInstrumentStatusDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrumentStatusDetail *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CInstrumentStatusDetailFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pInstrumentStatusDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrumentStatusDetail * pInstrumentStatusDetail,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CInstrumentStatusDetailFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableFrontStatus是一个存储前置状态的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableFrontStatus
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! FrontID.isValid())
			return 0;
		if (! LastReportTime.isValid())
			return 0;
		if (! IsActive.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableFrontStatus *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///前置编号
	CFrontIDType FrontID;
	///上次报告时间
	CTimeType LastReportTime;
	///是否活跃
	CBoolType IsActive;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableFrontStatus CFrontStatus;

/////////////////////////////////////////////////////////////////////////
///CFrontStatusActionTrigger是操作前置状态时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusActionTrigger
{
public:
	///构造方法
	CFrontStatusActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CFrontStatusActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CFrontStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pFrontStatus	要加入的FrontStatus
	virtual void beforeAdd(CWriteableFrontStatus *pFrontStatus)
	{
		return;
	}
	
	///加入后触发
	///@param	pFrontStatus	已经加入的FrontStatus
	virtual void afterAdd(CFrontStatus *pFrontStatus)
	{
		return;
	}

	///更新前触发	
	///@param	pFrontStatus	被刷新的CFrontStatus
	///@param	pNewFrontStatus	新的值
	virtual void beforeUpdate(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pNewFrontStatus)
	{
		return;
	}
	
	///更新后触发
	///@param	pFrontStatus	被刷新的CFrontStatus
	virtual void afterUpdate(CFrontStatus *pFrontStatus)
	{
		return;
	}
	
	///删除前触发
	///@param	pFrontStatus	要删除的CFrontStatus
	virtual void beforeRemove(CFrontStatus *pFrontStatus)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CFrontStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusCommitTrigger是确认前置状态时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusCommitTrigger
{
public:
	///构造方法
	CFrontStatusCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CFrontStatusCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CFrontStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pFrontStatus	已经加入的FrontStatus
	virtual void commitAdd(CFrontStatus *pFrontStatus)
	{
		return;
	}

	///更新后触发
	///@param	pFrontStatus	被刷新的CFrontStatus
	///@param	poldFrontStatus	原来的值
	virtual void commitUpdate(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pOldFrontStatus)
	{
		return;
	}
	
	///删除后触发
	///@param	pFrontStatus	已经删除的CFrontStatus
	virtual void commitRemove(CWriteableFrontStatus *pFrontStatus)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CFrontStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusIterator是一个对前置状态的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusIterator
{
public:
	///构造方法
	CFrontStatusIterator(void)
	{
	}

	///构造方法
	CFrontStatusIterator(CFrontStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CFrontStatusIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个FrontStatus
	///@return	下一个满足条件CFrontStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CFrontStatus *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CFrontStatusFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pFrontStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableFrontStatus * pFrontStatus,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CFrontStatusFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMaxLocalID是一个存储最大本地报单号的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMaxLocalID
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! UserID.isValid())
			return 0;
		if (! MaxOrderLocalID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableMaxLocalID *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易用户代码
	CUserIDType UserID;
	///最大报单本地编号
	COrderLocalIDType MaxOrderLocalID;
	unsigned int HashUserID;
	
	///计算UserID的hash值
	void calHashUserID(void)
	{
		unsigned key=0;
		key=UserID.hash(key);
		HashUserID=key;
	}
	
	///根据需要情况，更新UserID的hash值
	void updateHashUserID(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashUserID();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashUserID();
	}
	

private:
};

typedef const CWriteableMaxLocalID CMaxLocalID;

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDActionTrigger是操作最大本地报单号时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDActionTrigger
{
public:
	///构造方法
	CMaxLocalIDActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMaxLocalIDActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMaxLocalIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pMaxLocalID	要加入的MaxLocalID
	virtual void beforeAdd(CWriteableMaxLocalID *pMaxLocalID)
	{
		return;
	}
	
	///加入后触发
	///@param	pMaxLocalID	已经加入的MaxLocalID
	virtual void afterAdd(CMaxLocalID *pMaxLocalID)
	{
		return;
	}

	///更新前触发	
	///@param	pMaxLocalID	被刷新的CMaxLocalID
	///@param	pNewMaxLocalID	新的值
	virtual void beforeUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pNewMaxLocalID)
	{
		return;
	}
	
	///更新后触发
	///@param	pMaxLocalID	被刷新的CMaxLocalID
	virtual void afterUpdate(CMaxLocalID *pMaxLocalID)
	{
		return;
	}
	
	///删除前触发
	///@param	pMaxLocalID	要删除的CMaxLocalID
	virtual void beforeRemove(CMaxLocalID *pMaxLocalID)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMaxLocalIDFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDCommitTrigger是确认最大本地报单号时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDCommitTrigger
{
public:
	///构造方法
	CMaxLocalIDCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMaxLocalIDCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMaxLocalIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pMaxLocalID	已经加入的MaxLocalID
	virtual void commitAdd(CMaxLocalID *pMaxLocalID)
	{
		return;
	}

	///更新后触发
	///@param	pMaxLocalID	被刷新的CMaxLocalID
	///@param	poldMaxLocalID	原来的值
	virtual void commitUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pOldMaxLocalID)
	{
		return;
	}
	
	///删除后触发
	///@param	pMaxLocalID	已经删除的CMaxLocalID
	virtual void commitRemove(CWriteableMaxLocalID *pMaxLocalID)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMaxLocalIDFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDIterator是一个对最大本地报单号的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDIterator
{
public:
	///构造方法
	CMaxLocalIDIterator(void)
	{
	}

	///构造方法
	CMaxLocalIDIterator(CMaxLocalIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CMaxLocalIDIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个MaxLocalID
	///@return	下一个满足条件CMaxLocalID，如果已经没有一个满足要求了，则返回NULL
	virtual CMaxLocalID *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CMaxLocalIDFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pMaxLocalID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMaxLocalID * pMaxLocalID,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CMaxLocalIDFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableBulletin是一个存储公告信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableBulletin
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! BulletinID.isValid())
			return 0;
		if (! SequenceNo.isValid())
			return 0;
		if (! NewsType.isValid())
			return 0;
		if (! NewsUrgency.isValid())
			return 0;
		if (! SendTime.isValid())
			return 0;
		if (! Abstract.isValid())
			return 0;
		if (! ComeFrom.isValid())
			return 0;
		if (! Content.isValid())
			return 0;
		if (! URLLink.isValid())
			return 0;
		if (! MarketID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableBulletin *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///公告编号
	CBulletinIDType BulletinID;
	///序列号
	CSequenceNoType SequenceNo;
	///公告类型
	CNewsTypeType NewsType;
	///紧急程度
	CNewsUrgencyType NewsUrgency;
	///发送时间
	CTimeType SendTime;
	///消息摘要
	CAbstractType Abstract;
	///消息来源
	CComeFromType ComeFrom;
	///消息正文
	CContentType Content;
	///WEB地址
	CURLLinkType URLLink;
	///市场代码
	CMarketIDType MarketID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableBulletin CBulletin;

/////////////////////////////////////////////////////////////////////////
///CBulletinActionTrigger是操作公告信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinActionTrigger
{
public:
	///构造方法
	CBulletinActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CBulletinActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CBulletinFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pBulletin	要加入的Bulletin
	virtual void beforeAdd(CWriteableBulletin *pBulletin)
	{
		return;
	}
	
	///加入后触发
	///@param	pBulletin	已经加入的Bulletin
	virtual void afterAdd(CBulletin *pBulletin)
	{
		return;
	}

	///更新前触发	
	///@param	pBulletin	被刷新的CBulletin
	///@param	pNewBulletin	新的值
	virtual void beforeUpdate(CBulletin *pBulletin, CWriteableBulletin *pNewBulletin)
	{
		return;
	}
	
	///更新后触发
	///@param	pBulletin	被刷新的CBulletin
	virtual void afterUpdate(CBulletin *pBulletin)
	{
		return;
	}
	
	///删除前触发
	///@param	pBulletin	要删除的CBulletin
	virtual void beforeRemove(CBulletin *pBulletin)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CBulletinFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CBulletinCommitTrigger是确认公告信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinCommitTrigger
{
public:
	///构造方法
	CBulletinCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CBulletinCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CBulletinFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pBulletin	已经加入的Bulletin
	virtual void commitAdd(CBulletin *pBulletin)
	{
		return;
	}

	///更新后触发
	///@param	pBulletin	被刷新的CBulletin
	///@param	poldBulletin	原来的值
	virtual void commitUpdate(CBulletin *pBulletin, CWriteableBulletin *pOldBulletin)
	{
		return;
	}
	
	///删除后触发
	///@param	pBulletin	已经删除的CBulletin
	virtual void commitRemove(CWriteableBulletin *pBulletin)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CBulletinFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CBulletinIterator是一个对公告信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinIterator
{
public:
	///构造方法
	CBulletinIterator(void)
	{
	}

	///构造方法
	CBulletinIterator(CBulletinFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CBulletinIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个Bulletin
	///@return	下一个满足条件CBulletin，如果已经没有一个满足要求了，则返回NULL
	virtual CBulletin *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CBulletinFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pBulletin 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBulletin * pBulletin,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CBulletinFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMarketDataModify是一个存储行情变动的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMarketDataModify
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ModifySequence.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableMarketDataModify *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///行情变动序号
	CSequenceNoType ModifySequence;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	
	///构造对应的深度行情的指针
	///@param	pFactory	构造对应的深度行情的指针时，寻找的对象工厂
	///@return	找到的对应的深度行情的指针，如果找不到则返回NULL
	inline const CWriteableDepthMarketData *linkDepthMarketData(CDepthMarketDataFactory *pFactory) const;

	///构造对应的深度行情指针
	///@param	pDepthMarketData	要连接到的对象
	///@return	输入的pDepthMarketData
	const CWriteableDepthMarketData *linkDepthMarketData(const CWriteableDepthMarketData *pDepthMarketData) const
	{
		void *target=(void *)(&(this->pDepthMarketData));
		*((const CWriteableDepthMarketData **)target)=pDepthMarketData;
		return pDepthMarketData;
	}
	
	///获取对应的深度行情的指针
	///@return	找到的对应的深度行情的指针，如果找不到则返回NULL
	const CWriteableDepthMarketData *getDepthMarketData(void) const
	{
		return pDepthMarketData;
	}

private:
	///对应的深度行情
	const CWriteableDepthMarketData *pDepthMarketData;
};

typedef const CWriteableMarketDataModify CMarketDataModify;

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyActionTrigger是操作行情变动时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyActionTrigger
{
public:
	///构造方法
	CMarketDataModifyActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMarketDataModifyActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMarketDataModifyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pMarketDataModify	要加入的MarketDataModify
	virtual void beforeAdd(CWriteableMarketDataModify *pMarketDataModify)
	{
		return;
	}
	
	///加入后触发
	///@param	pMarketDataModify	已经加入的MarketDataModify
	virtual void afterAdd(CMarketDataModify *pMarketDataModify)
	{
		return;
	}

	///更新前触发	
	///@param	pMarketDataModify	被刷新的CMarketDataModify
	///@param	pNewMarketDataModify	新的值
	virtual void beforeUpdate(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pNewMarketDataModify)
	{
		return;
	}
	
	///更新后触发
	///@param	pMarketDataModify	被刷新的CMarketDataModify
	virtual void afterUpdate(CMarketDataModify *pMarketDataModify)
	{
		return;
	}
	
	///删除前触发
	///@param	pMarketDataModify	要删除的CMarketDataModify
	virtual void beforeRemove(CMarketDataModify *pMarketDataModify)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMarketDataModifyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyCommitTrigger是确认行情变动时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyCommitTrigger
{
public:
	///构造方法
	CMarketDataModifyCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMarketDataModifyCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMarketDataModifyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pMarketDataModify	已经加入的MarketDataModify
	virtual void commitAdd(CMarketDataModify *pMarketDataModify)
	{
		return;
	}

	///更新后触发
	///@param	pMarketDataModify	被刷新的CMarketDataModify
	///@param	poldMarketDataModify	原来的值
	virtual void commitUpdate(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pOldMarketDataModify)
	{
		return;
	}
	
	///删除后触发
	///@param	pMarketDataModify	已经删除的CMarketDataModify
	virtual void commitRemove(CWriteableMarketDataModify *pMarketDataModify)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMarketDataModifyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyIterator是一个对行情变动的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyIterator
{
public:
	///构造方法
	CMarketDataModifyIterator(void)
	{
	}

	///构造方法
	CMarketDataModifyIterator(CMarketDataModifyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CMarketDataModifyIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个MarketDataModify
	///@return	下一个满足条件CMarketDataModify，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketDataModify *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CMarketDataModifyFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pMarketDataModify 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketDataModify * pMarketDataModify,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CMarketDataModifyFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableDepthMarketData是一个存储深度行情的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableDepthMarketData
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! LastPrice.isValid())
			return 0;
		if (! PreSettlementPrice.isValid())
			return 0;
		if (! PreClosePrice.isValid())
			return 0;
		if (! PreOpenInterest.isValid())
			return 0;
		if (! OpenPrice.isValid())
			return 0;
		if (! HighestPrice.isValid())
			return 0;
		if (! LowestPrice.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! Turnover.isValid())
			return 0;
		if (! OpenInterest.isValid())
			return 0;
		if (! ClosePrice.isValid())
			return 0;
		if (! SettlementPrice.isValid())
			return 0;
		if (! UpperLimitPrice.isValid())
			return 0;
		if (! LowerLimitPrice.isValid())
			return 0;
		if (! PreDelta.isValid())
			return 0;
		if (! CurrDelta.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		if (! UpdateMillisec.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! BidPrice1.isValid())
			return 0;
		if (! BidVolume1.isValid())
			return 0;
		if (! AskPrice1.isValid())
			return 0;
		if (! AskVolume1.isValid())
			return 0;
		if (! BidPrice2.isValid())
			return 0;
		if (! BidVolume2.isValid())
			return 0;
		if (! AskPrice2.isValid())
			return 0;
		if (! AskVolume2.isValid())
			return 0;
		if (! BidPrice3.isValid())
			return 0;
		if (! BidVolume3.isValid())
			return 0;
		if (! AskPrice3.isValid())
			return 0;
		if (! AskVolume3.isValid())
			return 0;
		if (! BidPrice4.isValid())
			return 0;
		if (! BidVolume4.isValid())
			return 0;
		if (! AskPrice4.isValid())
			return 0;
		if (! AskVolume4.isValid())
			return 0;
		if (! BidPrice5.isValid())
			return 0;
		if (! BidVolume5.isValid())
			return 0;
		if (! AskPrice5.isValid())
			return 0;
		if (! AskVolume5.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableDepthMarketData *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///最新价
	CPriceType LastPrice;
	///昨结算
	CPriceType PreSettlementPrice;
	///昨收盘
	CPriceType PreClosePrice;
	///昨持仓量
	CLargeVolumeType PreOpenInterest;
	///今开盘
	CPriceType OpenPrice;
	///最高价
	CPriceType HighestPrice;
	///最低价
	CPriceType LowestPrice;
	///数量
	CVolumeType Volume;
	///成交金额
	CMoneyType Turnover;
	///持仓量
	CLargeVolumeType OpenInterest;
	///今收盘
	CPriceType ClosePrice;
	///今结算
	CPriceType SettlementPrice;
	///涨停板价
	CPriceType UpperLimitPrice;
	///跌停板价
	CPriceType LowerLimitPrice;
	///昨虚实度
	CRatioType PreDelta;
	///今虚实度
	CRatioType CurrDelta;
	///最后修改时间
	CTimeType UpdateTime;
	///最后修改毫秒
	CMillisecType UpdateMillisec;
	///合约代码
	CInstrumentIDType InstrumentID;
	///申买价一
	CPriceType BidPrice1;
	///申买量一
	CVolumeType BidVolume1;
	///申卖价一
	CPriceType AskPrice1;
	///申卖量一
	CVolumeType AskVolume1;
	///申买价二
	CPriceType BidPrice2;
	///申买量二
	CVolumeType BidVolume2;
	///申卖价二
	CPriceType AskPrice2;
	///申卖量二
	CVolumeType AskVolume2;
	///申买价三
	CPriceType BidPrice3;
	///申买量三
	CVolumeType BidVolume3;
	///申卖价三
	CPriceType AskPrice3;
	///申卖量三
	CVolumeType AskVolume3;
	///申买价四
	CPriceType BidPrice4;
	///申买量四
	CVolumeType BidVolume4;
	///申卖价四
	CPriceType AskPrice4;
	///申卖量四
	CVolumeType AskVolume4;
	///申买价五
	CPriceType BidPrice5;
	///申买量五
	CVolumeType BidVolume5;
	///申卖价五
	CPriceType AskPrice5;
	///申卖量五
	CVolumeType AskVolume5;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	
	///构造对应的合约的指针
	///@param	pFactory	构造对应的合约的指针时，寻找的对象工厂
	///@return	找到的对应的合约的指针，如果找不到则返回NULL
	inline const CWriteableInstrument *linkInstrument(CInstrumentFactory *pFactory) const;

	///构造对应的合约指针
	///@param	pInstrument	要连接到的对象
	///@return	输入的pInstrument
	const CWriteableInstrument *linkInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///获取对应的合约的指针
	///@return	找到的对应的合约的指针，如果找不到则返回NULL
	const CWriteableInstrument *getInstrument(void) const
	{
		return pInstrument;
	}

private:
	///对应的合约
	const CWriteableInstrument *pInstrument;
};

typedef const CWriteableDepthMarketData CDepthMarketData;

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataActionTrigger是操作深度行情时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataActionTrigger
{
public:
	///构造方法
	CDepthMarketDataActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CDepthMarketDataActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CDepthMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pDepthMarketData	要加入的DepthMarketData
	virtual void beforeAdd(CWriteableDepthMarketData *pDepthMarketData)
	{
		return;
	}
	
	///加入后触发
	///@param	pDepthMarketData	已经加入的DepthMarketData
	virtual void afterAdd(CDepthMarketData *pDepthMarketData)
	{
		return;
	}

	///更新前触发	
	///@param	pDepthMarketData	被刷新的CDepthMarketData
	///@param	pNewDepthMarketData	新的值
	virtual void beforeUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pNewDepthMarketData)
	{
		return;
	}
	
	///更新后触发
	///@param	pDepthMarketData	被刷新的CDepthMarketData
	virtual void afterUpdate(CDepthMarketData *pDepthMarketData)
	{
		return;
	}
	
	///删除前触发
	///@param	pDepthMarketData	要删除的CDepthMarketData
	virtual void beforeRemove(CDepthMarketData *pDepthMarketData)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CDepthMarketDataFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataCommitTrigger是确认深度行情时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataCommitTrigger
{
public:
	///构造方法
	CDepthMarketDataCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CDepthMarketDataCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CDepthMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pDepthMarketData	已经加入的DepthMarketData
	virtual void commitAdd(CDepthMarketData *pDepthMarketData)
	{
		return;
	}

	///更新后触发
	///@param	pDepthMarketData	被刷新的CDepthMarketData
	///@param	poldDepthMarketData	原来的值
	virtual void commitUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pOldDepthMarketData)
	{
		return;
	}
	
	///删除后触发
	///@param	pDepthMarketData	已经删除的CDepthMarketData
	virtual void commitRemove(CWriteableDepthMarketData *pDepthMarketData)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CDepthMarketDataFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataIterator是一个对深度行情的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataIterator
{
public:
	///构造方法
	CDepthMarketDataIterator(void)
	{
	}

	///构造方法
	CDepthMarketDataIterator(CDepthMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CDepthMarketDataIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个DepthMarketData
	///@return	下一个满足条件CDepthMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CDepthMarketData *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CDepthMarketDataFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pDepthMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableDepthMarketData * pDepthMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CDepthMarketDataFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableTopicMarketData是一个存储分主题行情的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableTopicMarketData
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TopicID.isValid())
			return 0;
		if (! SnapShotFeq.isValid())
			return 0;
		if (! MarketDataDepth.isValid())
			return 0;
		if (! MarketDataMode.isValid())
			return 0;
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! LastPrice.isValid())
			return 0;
		if (! PreSettlementPrice.isValid())
			return 0;
		if (! PreClosePrice.isValid())
			return 0;
		if (! PreOpenInterest.isValid())
			return 0;
		if (! OpenPrice.isValid())
			return 0;
		if (! HighestPrice.isValid())
			return 0;
		if (! LowestPrice.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! Turnover.isValid())
			return 0;
		if (! OpenInterest.isValid())
			return 0;
		if (! ClosePrice.isValid())
			return 0;
		if (! SettlementPrice.isValid())
			return 0;
		if (! UpperLimitPrice.isValid())
			return 0;
		if (! LowerLimitPrice.isValid())
			return 0;
		if (! PreDelta.isValid())
			return 0;
		if (! CurrDelta.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		if (! UpdateMillisec.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! BidPrice1.isValid())
			return 0;
		if (! BidVolume1.isValid())
			return 0;
		if (! AskPrice1.isValid())
			return 0;
		if (! AskVolume1.isValid())
			return 0;
		if (! BidPrice2.isValid())
			return 0;
		if (! BidVolume2.isValid())
			return 0;
		if (! AskPrice2.isValid())
			return 0;
		if (! AskVolume2.isValid())
			return 0;
		if (! BidPrice3.isValid())
			return 0;
		if (! BidVolume3.isValid())
			return 0;
		if (! AskPrice3.isValid())
			return 0;
		if (! AskVolume3.isValid())
			return 0;
		if (! BidPrice4.isValid())
			return 0;
		if (! BidVolume4.isValid())
			return 0;
		if (! AskPrice4.isValid())
			return 0;
		if (! AskVolume4.isValid())
			return 0;
		if (! BidPrice5.isValid())
			return 0;
		if (! BidVolume5.isValid())
			return 0;
		if (! AskPrice5.isValid())
			return 0;
		if (! AskVolume5.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableTopicMarketData *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///主题代码
	CTopicIDType TopicID;
	///采样频率
	CSecondsType SnapShotFeq;
	///市场行情深度
	CMarketDataDepthType MarketDataDepth;
	///行情模式
	CMarketDataModeType MarketDataMode;
	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///最新价
	CPriceType LastPrice;
	///昨结算
	CPriceType PreSettlementPrice;
	///昨收盘
	CPriceType PreClosePrice;
	///昨持仓量
	CLargeVolumeType PreOpenInterest;
	///今开盘
	CPriceType OpenPrice;
	///最高价
	CPriceType HighestPrice;
	///最低价
	CPriceType LowestPrice;
	///数量
	CVolumeType Volume;
	///成交金额
	CMoneyType Turnover;
	///持仓量
	CLargeVolumeType OpenInterest;
	///今收盘
	CPriceType ClosePrice;
	///今结算
	CPriceType SettlementPrice;
	///涨停板价
	CPriceType UpperLimitPrice;
	///跌停板价
	CPriceType LowerLimitPrice;
	///昨虚实度
	CRatioType PreDelta;
	///今虚实度
	CRatioType CurrDelta;
	///最后修改时间
	CTimeType UpdateTime;
	///最后修改毫秒
	CMillisecType UpdateMillisec;
	///合约代码
	CInstrumentIDType InstrumentID;
	///申买价一
	CPriceType BidPrice1;
	///申买量一
	CVolumeType BidVolume1;
	///申卖价一
	CPriceType AskPrice1;
	///申卖量一
	CVolumeType AskVolume1;
	///申买价二
	CPriceType BidPrice2;
	///申买量二
	CVolumeType BidVolume2;
	///申卖价二
	CPriceType AskPrice2;
	///申卖量二
	CVolumeType AskVolume2;
	///申买价三
	CPriceType BidPrice3;
	///申买量三
	CVolumeType BidVolume3;
	///申卖价三
	CPriceType AskPrice3;
	///申卖量三
	CVolumeType AskVolume3;
	///申买价四
	CPriceType BidPrice4;
	///申买量四
	CVolumeType BidVolume4;
	///申卖价四
	CPriceType AskPrice4;
	///申卖量四
	CVolumeType AskVolume4;
	///申买价五
	CPriceType BidPrice5;
	///申买量五
	CVolumeType BidVolume5;
	///申卖价五
	CPriceType AskPrice5;
	///申卖量五
	CVolumeType AskVolume5;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableTopicMarketData CTopicMarketData;

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataActionTrigger是操作分主题行情时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataActionTrigger
{
public:
	///构造方法
	CTopicMarketDataActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CTopicMarketDataActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CTopicMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pTopicMarketData	要加入的TopicMarketData
	virtual void beforeAdd(CWriteableTopicMarketData *pTopicMarketData)
	{
		return;
	}
	
	///加入后触发
	///@param	pTopicMarketData	已经加入的TopicMarketData
	virtual void afterAdd(CTopicMarketData *pTopicMarketData)
	{
		return;
	}

	///更新前触发	
	///@param	pTopicMarketData	被刷新的CTopicMarketData
	///@param	pNewTopicMarketData	新的值
	virtual void beforeUpdate(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pNewTopicMarketData)
	{
		return;
	}
	
	///更新后触发
	///@param	pTopicMarketData	被刷新的CTopicMarketData
	virtual void afterUpdate(CTopicMarketData *pTopicMarketData)
	{
		return;
	}
	
	///删除前触发
	///@param	pTopicMarketData	要删除的CTopicMarketData
	virtual void beforeRemove(CTopicMarketData *pTopicMarketData)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CTopicMarketDataFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataCommitTrigger是确认分主题行情时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataCommitTrigger
{
public:
	///构造方法
	CTopicMarketDataCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CTopicMarketDataCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CTopicMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pTopicMarketData	已经加入的TopicMarketData
	virtual void commitAdd(CTopicMarketData *pTopicMarketData)
	{
		return;
	}

	///更新后触发
	///@param	pTopicMarketData	被刷新的CTopicMarketData
	///@param	poldTopicMarketData	原来的值
	virtual void commitUpdate(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pOldTopicMarketData)
	{
		return;
	}
	
	///删除后触发
	///@param	pTopicMarketData	已经删除的CTopicMarketData
	virtual void commitRemove(CWriteableTopicMarketData *pTopicMarketData)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CTopicMarketDataFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataIterator是一个对分主题行情的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataIterator
{
public:
	///构造方法
	CTopicMarketDataIterator(void)
	{
	}

	///构造方法
	CTopicMarketDataIterator(CTopicMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CTopicMarketDataIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个TopicMarketData
	///@return	下一个满足条件CTopicMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CTopicMarketData *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CTopicMarketDataFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pTopicMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTopicMarketData * pTopicMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CTopicMarketDataFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableTopicMarketDataVersion是一个存储分主题行情快照的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableTopicMarketDataVersion
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TopicID.isValid())
			return 0;
		if (! Version.isValid())
			return 0;
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! LastPrice.isValid())
			return 0;
		if (! PreSettlementPrice.isValid())
			return 0;
		if (! PreClosePrice.isValid())
			return 0;
		if (! PreOpenInterest.isValid())
			return 0;
		if (! OpenPrice.isValid())
			return 0;
		if (! HighestPrice.isValid())
			return 0;
		if (! LowestPrice.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! Turnover.isValid())
			return 0;
		if (! OpenInterest.isValid())
			return 0;
		if (! ClosePrice.isValid())
			return 0;
		if (! SettlementPrice.isValid())
			return 0;
		if (! UpperLimitPrice.isValid())
			return 0;
		if (! LowerLimitPrice.isValid())
			return 0;
		if (! PreDelta.isValid())
			return 0;
		if (! CurrDelta.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		if (! UpdateMillisec.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! BidPrice1.isValid())
			return 0;
		if (! BidVolume1.isValid())
			return 0;
		if (! AskPrice1.isValid())
			return 0;
		if (! AskVolume1.isValid())
			return 0;
		if (! BidPrice2.isValid())
			return 0;
		if (! BidVolume2.isValid())
			return 0;
		if (! AskPrice2.isValid())
			return 0;
		if (! AskVolume2.isValid())
			return 0;
		if (! BidPrice3.isValid())
			return 0;
		if (! BidVolume3.isValid())
			return 0;
		if (! AskPrice3.isValid())
			return 0;
		if (! AskVolume3.isValid())
			return 0;
		if (! BidPrice4.isValid())
			return 0;
		if (! BidVolume4.isValid())
			return 0;
		if (! AskPrice4.isValid())
			return 0;
		if (! AskVolume4.isValid())
			return 0;
		if (! BidPrice5.isValid())
			return 0;
		if (! BidVolume5.isValid())
			return 0;
		if (! AskPrice5.isValid())
			return 0;
		if (! AskVolume5.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableTopicMarketDataVersion *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///主题代码
	CTopicIDType TopicID;
	///快照版本
	CSequenceNoType Version;
	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///最新价
	CPriceType LastPrice;
	///昨结算
	CPriceType PreSettlementPrice;
	///昨收盘
	CPriceType PreClosePrice;
	///昨持仓量
	CLargeVolumeType PreOpenInterest;
	///今开盘
	CPriceType OpenPrice;
	///最高价
	CPriceType HighestPrice;
	///最低价
	CPriceType LowestPrice;
	///数量
	CVolumeType Volume;
	///成交金额
	CMoneyType Turnover;
	///持仓量
	CLargeVolumeType OpenInterest;
	///今收盘
	CPriceType ClosePrice;
	///今结算
	CPriceType SettlementPrice;
	///涨停板价
	CPriceType UpperLimitPrice;
	///跌停板价
	CPriceType LowerLimitPrice;
	///昨虚实度
	CRatioType PreDelta;
	///今虚实度
	CRatioType CurrDelta;
	///最后修改时间
	CTimeType UpdateTime;
	///最后修改毫秒
	CMillisecType UpdateMillisec;
	///合约代码
	CInstrumentIDType InstrumentID;
	///申买价一
	CPriceType BidPrice1;
	///申买量一
	CVolumeType BidVolume1;
	///申卖价一
	CPriceType AskPrice1;
	///申卖量一
	CVolumeType AskVolume1;
	///申买价二
	CPriceType BidPrice2;
	///申买量二
	CVolumeType BidVolume2;
	///申卖价二
	CPriceType AskPrice2;
	///申卖量二
	CVolumeType AskVolume2;
	///申买价三
	CPriceType BidPrice3;
	///申买量三
	CVolumeType BidVolume3;
	///申卖价三
	CPriceType AskPrice3;
	///申卖量三
	CVolumeType AskVolume3;
	///申买价四
	CPriceType BidPrice4;
	///申买量四
	CVolumeType BidVolume4;
	///申卖价四
	CPriceType AskPrice4;
	///申卖量四
	CVolumeType AskVolume4;
	///申买价五
	CPriceType BidPrice5;
	///申买量五
	CVolumeType BidVolume5;
	///申卖价五
	CPriceType AskPrice5;
	///申卖量五
	CVolumeType AskVolume5;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableTopicMarketDataVersion CTopicMarketDataVersion;

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionActionTrigger是操作分主题行情快照时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionActionTrigger
{
public:
	///构造方法
	CTopicMarketDataVersionActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CTopicMarketDataVersionActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CTopicMarketDataVersionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pTopicMarketDataVersion	要加入的TopicMarketDataVersion
	virtual void beforeAdd(CWriteableTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return;
	}
	
	///加入后触发
	///@param	pTopicMarketDataVersion	已经加入的TopicMarketDataVersion
	virtual void afterAdd(CTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return;
	}

	///更新前触发	
	///@param	pTopicMarketDataVersion	被刷新的CTopicMarketDataVersion
	///@param	pNewTopicMarketDataVersion	新的值
	virtual void beforeUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pNewTopicMarketDataVersion)
	{
		return;
	}
	
	///更新后触发
	///@param	pTopicMarketDataVersion	被刷新的CTopicMarketDataVersion
	virtual void afterUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return;
	}
	
	///删除前触发
	///@param	pTopicMarketDataVersion	要删除的CTopicMarketDataVersion
	virtual void beforeRemove(CTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CTopicMarketDataVersionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionCommitTrigger是确认分主题行情快照时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionCommitTrigger
{
public:
	///构造方法
	CTopicMarketDataVersionCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CTopicMarketDataVersionCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CTopicMarketDataVersionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pTopicMarketDataVersion	已经加入的TopicMarketDataVersion
	virtual void commitAdd(CTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return;
	}

	///更新后触发
	///@param	pTopicMarketDataVersion	被刷新的CTopicMarketDataVersion
	///@param	poldTopicMarketDataVersion	原来的值
	virtual void commitUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pOldTopicMarketDataVersion)
	{
		return;
	}
	
	///删除后触发
	///@param	pTopicMarketDataVersion	已经删除的CTopicMarketDataVersion
	virtual void commitRemove(CWriteableTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CTopicMarketDataVersionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionIterator是一个对分主题行情快照的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionIterator
{
public:
	///构造方法
	CTopicMarketDataVersionIterator(void)
	{
	}

	///构造方法
	CTopicMarketDataVersionIterator(CTopicMarketDataVersionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CTopicMarketDataVersionIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个TopicMarketDataVersion
	///@return	下一个满足条件CTopicMarketDataVersion，如果已经没有一个满足要求了，则返回NULL
	virtual CTopicMarketDataVersion *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CTopicMarketDataVersionFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pTopicMarketDataVersion 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTopicMarketDataVersion * pTopicMarketDataVersion,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CTopicMarketDataVersionFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableInformation是一个存储信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableInformation
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! InformationID.isValid())
			return 0;
		if (! SequenceNo.isValid())
			return 0;
		if (! Content.isValid())
			return 0;
		if (! ContentLength.isValid())
			return 0;
		if (! IsAccomplished.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableInformation *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///信息编号
	CInformationIDType InformationID;
	///序列号
	CSequenceNoType SequenceNo;
	///消息正文
	CContentType Content;
	///正文长度
	CContentLengthType ContentLength;
	///是否完成
	CBoolType IsAccomplished;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableInformation CInformation;

/////////////////////////////////////////////////////////////////////////
///CInformationActionTrigger是操作信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationActionTrigger
{
public:
	///构造方法
	CInformationActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CInformationActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CInformationFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pInformation	要加入的Information
	virtual void beforeAdd(CWriteableInformation *pInformation)
	{
		return;
	}
	
	///加入后触发
	///@param	pInformation	已经加入的Information
	virtual void afterAdd(CInformation *pInformation)
	{
		return;
	}

	///更新前触发	
	///@param	pInformation	被刷新的CInformation
	///@param	pNewInformation	新的值
	virtual void beforeUpdate(CInformation *pInformation, CWriteableInformation *pNewInformation)
	{
		return;
	}
	
	///更新后触发
	///@param	pInformation	被刷新的CInformation
	virtual void afterUpdate(CInformation *pInformation)
	{
		return;
	}
	
	///删除前触发
	///@param	pInformation	要删除的CInformation
	virtual void beforeRemove(CInformation *pInformation)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CInformationFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CInformationCommitTrigger是确认信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationCommitTrigger
{
public:
	///构造方法
	CInformationCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CInformationCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CInformationFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pInformation	已经加入的Information
	virtual void commitAdd(CInformation *pInformation)
	{
		return;
	}

	///更新后触发
	///@param	pInformation	被刷新的CInformation
	///@param	poldInformation	原来的值
	virtual void commitUpdate(CInformation *pInformation, CWriteableInformation *pOldInformation)
	{
		return;
	}
	
	///删除后触发
	///@param	pInformation	已经删除的CInformation
	virtual void commitRemove(CWriteableInformation *pInformation)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CInformationFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CInformationIterator是一个对信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationIterator
{
public:
	///构造方法
	CInformationIterator(void)
	{
	}

	///构造方法
	CInformationIterator(CInformationFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CInformationIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个Information
	///@return	下一个满足条件CInformation，如果已经没有一个满足要求了，则返回NULL
	virtual CInformation *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CInformationFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pInformation 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInformation * pInformation,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CInformationFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableOrderCount是一个存储报单数量的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableOrderCount
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! ParticipantID.isValid())
			return 0;
		if (! StopOrderCount.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableOrderCount *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///会员代码
	CParticipantIDType ParticipantID;
	///止损报单数量
	COrderCountType StopOrderCount;
	unsigned int HashHashParticipantID;
	
	///计算HashParticipantID的hash值
	void calHashHashParticipantID(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		HashHashParticipantID=key;
	}
	
	///根据需要情况，更新HashParticipantID的hash值
	void updateHashHashParticipantID(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashHashParticipantID();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashHashParticipantID();
	}
	

private:
};

typedef const CWriteableOrderCount COrderCount;

/////////////////////////////////////////////////////////////////////////
///COrderCountActionTrigger是操作报单数量时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountActionTrigger
{
public:
	///构造方法
	COrderCountActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~COrderCountActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(COrderCountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pOrderCount	要加入的OrderCount
	virtual void beforeAdd(CWriteableOrderCount *pOrderCount)
	{
		return;
	}
	
	///加入后触发
	///@param	pOrderCount	已经加入的OrderCount
	virtual void afterAdd(COrderCount *pOrderCount)
	{
		return;
	}

	///更新前触发	
	///@param	pOrderCount	被刷新的COrderCount
	///@param	pNewOrderCount	新的值
	virtual void beforeUpdate(COrderCount *pOrderCount, CWriteableOrderCount *pNewOrderCount)
	{
		return;
	}
	
	///更新后触发
	///@param	pOrderCount	被刷新的COrderCount
	virtual void afterUpdate(COrderCount *pOrderCount)
	{
		return;
	}
	
	///删除前触发
	///@param	pOrderCount	要删除的COrderCount
	virtual void beforeRemove(COrderCount *pOrderCount)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	COrderCountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///COrderCountCommitTrigger是确认报单数量时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountCommitTrigger
{
public:
	///构造方法
	COrderCountCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~COrderCountCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(COrderCountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pOrderCount	已经加入的OrderCount
	virtual void commitAdd(COrderCount *pOrderCount)
	{
		return;
	}

	///更新后触发
	///@param	pOrderCount	被刷新的COrderCount
	///@param	poldOrderCount	原来的值
	virtual void commitUpdate(COrderCount *pOrderCount, CWriteableOrderCount *pOldOrderCount)
	{
		return;
	}
	
	///删除后触发
	///@param	pOrderCount	已经删除的COrderCount
	virtual void commitRemove(CWriteableOrderCount *pOrderCount)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	COrderCountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///COrderCountIterator是一个对报单数量的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountIterator
{
public:
	///构造方法
	COrderCountIterator(void)
	{
	}

	///构造方法
	COrderCountIterator(COrderCountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~COrderCountIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个OrderCount
	///@return	下一个满足条件COrderCount，如果已经没有一个满足要求了，则返回NULL
	virtual COrderCount *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	COrderCountFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pOrderCount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOrderCount * pOrderCount,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	COrderCountFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableInstrument是一个存储合约的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableInstrument
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! ProductID.isValid())
			return 0;
		if (! ProductGroupID.isValid())
			return 0;
		if (! UnderlyingInstrID.isValid())
			return 0;
		if (! ProductClass.isValid())
			return 0;
		if (! PositionType.isValid())
			return 0;
		if (! StrikePrice.isValid())
			return 0;
		if (! OptionsType.isValid())
			return 0;
		if (! VolumeMultiple.isValid())
			return 0;
		if (! UnderlyingMultiple.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! InstrumentName.isValid())
			return 0;
		if (! DeliveryYear.isValid())
			return 0;
		if (! DeliveryMonth.isValid())
			return 0;
		if (! AdvanceMonth.isValid())
			return 0;
		if (! IsTrading.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableInstrument *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///产品代码
	CProductIDType ProductID;
	///产品组代码
	CProductGroupIDType ProductGroupID;
	///基础商品代码
	CInstrumentIDType UnderlyingInstrID;
	///产品类型
	CProductClassType ProductClass;
	///持仓类型
	CPositionTypeType PositionType;
	///执行价
	CPriceType StrikePrice;
	///期权类型
	COptionsTypeType OptionsType;
	///合约数量乘数
	CVolumeMultipleType VolumeMultiple;
	///合约基础商品乘数
	CUnderlyingMultipleType UnderlyingMultiple;
	///合约代码
	CInstrumentIDType InstrumentID;
	///合约名称
	CInstrumentNameType InstrumentName;
	///交割年份
	CYearType DeliveryYear;
	///交割月
	CMonthType DeliveryMonth;
	///提前月份
	CAdvanceMonthType AdvanceMonth;
	///当前是否交易
	CBoolType IsTrading;
	unsigned int HashInstrumentID;
	
	///计算InstrumentID的hash值
	void calHashInstrumentID(void)
	{
		unsigned key=0;
		key=InstrumentID.hash(key);
		HashInstrumentID=key;
	}
	
	///根据需要情况，更新InstrumentID的hash值
	void updateHashInstrumentID(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashInstrumentID();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashInstrumentID();
	}
	
	///构造对应的基础合约的指针
	///@param	pFactory	构造对应的基础合约的指针时，寻找的对象工厂
	///@return	找到的对应的基础合约的指针，如果找不到则返回NULL
	inline const CWriteableInstrument *linkBaseInstrument(CInstrumentFactory *pFactory) const;

	///构造对应的基础合约指针
	///@param	pInstrument	要连接到的对象
	///@return	输入的pInstrument
	const CWriteableInstrument *linkBaseInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pBaseInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///获取对应的基础合约的指针
	///@return	找到的对应的基础合约的指针，如果找不到则返回NULL
	const CWriteableInstrument *getBaseInstrument(void) const
	{
		return pBaseInstrument;
	}
	///构造对应的合约属性的指针
	///@param	pFactory	构造对应的合约属性的指针时，寻找的对象工厂
	///@return	找到的对应的合约属性的指针，如果找不到则返回NULL
	inline const CWriteableCurrInstrumentProperty *linkInstrumentProperty(CCurrInstrumentPropertyFactory *pFactory) const;

	///构造对应的合约属性指针
	///@param	pCurrInstrumentProperty	要连接到的对象
	///@return	输入的pCurrInstrumentProperty
	const CWriteableCurrInstrumentProperty *linkInstrumentProperty(const CWriteableCurrInstrumentProperty *pCurrInstrumentProperty) const
	{
		void *target=(void *)(&(this->pInstrumentProperty));
		*((const CWriteableCurrInstrumentProperty **)target)=pCurrInstrumentProperty;
		return pCurrInstrumentProperty;
	}
	
	///获取对应的合约属性的指针
	///@return	找到的对应的合约属性的指针，如果找不到则返回NULL
	const CWriteableCurrInstrumentProperty *getInstrumentProperty(void) const
	{
		return pInstrumentProperty;
	}
	///构造对应的合约状态的指针
	///@param	pFactory	构造对应的合约状态的指针时，寻找的对象工厂
	///@return	找到的对应的合约状态的指针，如果找不到则返回NULL
	inline const CWriteableInstrumentStatus *linkInstrumentStatus(CInstrumentStatusFactory *pFactory) const;

	///构造对应的合约状态指针
	///@param	pInstrumentStatus	要连接到的对象
	///@return	输入的pInstrumentStatus
	const CWriteableInstrumentStatus *linkInstrumentStatus(const CWriteableInstrumentStatus *pInstrumentStatus) const
	{
		void *target=(void *)(&(this->pInstrumentStatus));
		*((const CWriteableInstrumentStatus **)target)=pInstrumentStatus;
		return pInstrumentStatus;
	}
	
	///获取对应的合约状态的指针
	///@return	找到的对应的合约状态的指针，如果找不到则返回NULL
	const CWriteableInstrumentStatus *getInstrumentStatus(void) const
	{
		return pInstrumentStatus;
	}
	///构造对应的行情的指针
	///@param	pFactory	构造对应的行情的指针时，寻找的对象工厂
	///@return	找到的对应的行情的指针，如果找不到则返回NULL
	inline const CWriteableMarketData *linkMarketData(CMarketDataFactory *pFactory) const;

	///构造对应的行情指针
	///@param	pMarketData	要连接到的对象
	///@return	输入的pMarketData
	const CWriteableMarketData *linkMarketData(const CWriteableMarketData *pMarketData) const
	{
		void *target=(void *)(&(this->pMarketData));
		*((const CWriteableMarketData **)target)=pMarketData;
		return pMarketData;
	}
	
	///获取对应的行情的指针
	///@return	找到的对应的行情的指针，如果找不到则返回NULL
	const CWriteableMarketData *getMarketData(void) const
	{
		return pMarketData;
	}
	///构造对应的套期保值规则的指针
	///@param	pFactory	构造对应的套期保值规则的指针时，寻找的对象工厂
	///@return	找到的对应的套期保值规则的指针，如果找不到则返回NULL
	inline const CWriteableCurrHedgeRule *linkCurrHedgeRule(CCurrHedgeRuleFactory *pFactory) const;

	///构造对应的套期保值规则指针
	///@param	pCurrHedgeRule	要连接到的对象
	///@return	输入的pCurrHedgeRule
	const CWriteableCurrHedgeRule *linkCurrHedgeRule(const CWriteableCurrHedgeRule *pCurrHedgeRule) const
	{
		void *target=(void *)(&(this->pCurrHedgeRule));
		*((const CWriteableCurrHedgeRule **)target)=pCurrHedgeRule;
		return pCurrHedgeRule;
	}
	
	///获取对应的套期保值规则的指针
	///@return	找到的对应的套期保值规则的指针，如果找不到则返回NULL
	const CWriteableCurrHedgeRule *getCurrHedgeRule(void) const
	{
		return pCurrHedgeRule;
	}
	///构造对应的熔断规则的指针
	///@param	pFactory	构造对应的熔断规则的指针时，寻找的对象工厂
	///@return	找到的对应的熔断规则的指针，如果找不到则返回NULL
	inline const CWriteableCurrFuse *linkCurrFuse(CCurrFuseFactory *pFactory) const;

	///构造对应的熔断规则指针
	///@param	pCurrFuse	要连接到的对象
	///@return	输入的pCurrFuse
	const CWriteableCurrFuse *linkCurrFuse(const CWriteableCurrFuse *pCurrFuse) const
	{
		void *target=(void *)(&(this->pCurrFuse));
		*((const CWriteableCurrFuse **)target)=pCurrFuse;
		return pCurrFuse;
	}
	
	///获取对应的熔断规则的指针
	///@return	找到的对应的熔断规则的指针，如果找不到则返回NULL
	const CWriteableCurrFuse *getCurrFuse(void) const
	{
		return pCurrFuse;
	}
	///构造对应的熔断状态的指针
	///@param	pFactory	构造对应的熔断状态的指针时，寻找的对象工厂
	///@return	找到的对应的熔断状态的指针，如果找不到则返回NULL
	inline const CWriteableFusePhase *linkFusePhase(CFusePhaseFactory *pFactory) const;

	///构造对应的熔断状态指针
	///@param	pFusePhase	要连接到的对象
	///@return	输入的pFusePhase
	const CWriteableFusePhase *linkFusePhase(const CWriteableFusePhase *pFusePhase) const
	{
		void *target=(void *)(&(this->pFusePhase));
		*((const CWriteableFusePhase **)target)=pFusePhase;
		return pFusePhase;
	}
	
	///获取对应的熔断状态的指针
	///@return	找到的对应的熔断状态的指针，如果找不到则返回NULL
	const CWriteableFusePhase *getFusePhase(void) const
	{
		return pFusePhase;
	}
	///构造对应的涨跌停板设置的指针
	///@param	pFactory	构造对应的涨跌停板设置的指针时，寻找的对象工厂
	///@return	找到的对应的涨跌停板设置的指针，如果找不到则返回NULL
	inline const CWriteableBasePriceLimit *linkBasePriceLimit(CBasePriceLimitFactory *pFactory) const;

	///构造对应的涨跌停板设置指针
	///@param	pBasePriceLimit	要连接到的对象
	///@return	输入的pBasePriceLimit
	const CWriteableBasePriceLimit *linkBasePriceLimit(const CWriteableBasePriceLimit *pBasePriceLimit) const
	{
		void *target=(void *)(&(this->pBasePriceLimit));
		*((const CWriteableBasePriceLimit **)target)=pBasePriceLimit;
		return pBasePriceLimit;
	}
	
	///获取对应的涨跌停板设置的指针
	///@return	找到的对应的涨跌停板设置的指针，如果找不到则返回NULL
	const CWriteableBasePriceLimit *getBasePriceLimit(void) const
	{
		return pBasePriceLimit;
	}
	///构造对应的单边市情况的指针
	///@param	pFactory	构造对应的单边市情况的指针时，寻找的对象工厂
	///@return	找到的对应的单边市情况的指针，如果找不到则返回NULL
	inline const CWriteableUniPressure *linkUniPressure(CUniPressureFactory *pFactory) const;

	///构造对应的单边市情况指针
	///@param	pUniPressure	要连接到的对象
	///@return	输入的pUniPressure
	const CWriteableUniPressure *linkUniPressure(const CWriteableUniPressure *pUniPressure) const
	{
		void *target=(void *)(&(this->pUniPressure));
		*((const CWriteableUniPressure **)target)=pUniPressure;
		return pUniPressure;
	}
	
	///获取对应的单边市情况的指针
	///@return	找到的对应的单边市情况的指针，如果找不到则返回NULL
	const CWriteableUniPressure *getUniPressure(void) const
	{
		return pUniPressure;
	}
	///构造对应的结算组同步状态的指针
	///@param	pFactory	构造对应的结算组同步状态的指针时，寻找的对象工厂
	///@return	找到的对应的结算组同步状态的指针，如果找不到则返回NULL
	inline const CWriteableSGDataSyncStatus *linkSGDataSyncStatus(CSGDataSyncStatusFactory *pFactory) const;

	///构造对应的结算组同步状态指针
	///@param	pSGDataSyncStatus	要连接到的对象
	///@return	输入的pSGDataSyncStatus
	const CWriteableSGDataSyncStatus *linkSGDataSyncStatus(const CWriteableSGDataSyncStatus *pSGDataSyncStatus) const
	{
		void *target=(void *)(&(this->pSGDataSyncStatus));
		*((const CWriteableSGDataSyncStatus **)target)=pSGDataSyncStatus;
		return pSGDataSyncStatus;
	}
	
	///获取对应的结算组同步状态的指针
	///@return	找到的对应的结算组同步状态的指针，如果找不到则返回NULL
	const CWriteableSGDataSyncStatus *getSGDataSyncStatus(void) const
	{
		return pSGDataSyncStatus;
	}

private:
	///对应的基础合约
	const CWriteableInstrument *pBaseInstrument;
	///对应的合约属性
	const CWriteableCurrInstrumentProperty *pInstrumentProperty;
	///对应的合约状态
	const CWriteableInstrumentStatus *pInstrumentStatus;
	///对应的行情
	const CWriteableMarketData *pMarketData;
	///对应的套期保值规则
	const CWriteableCurrHedgeRule *pCurrHedgeRule;
	///对应的熔断规则
	const CWriteableCurrFuse *pCurrFuse;
	///对应的熔断状态
	const CWriteableFusePhase *pFusePhase;
	///对应的涨跌停板设置
	const CWriteableBasePriceLimit *pBasePriceLimit;
	///对应的单边市情况
	const CWriteableUniPressure *pUniPressure;
	///对应的结算组同步状态
	const CWriteableSGDataSyncStatus *pSGDataSyncStatus;
};

typedef const CWriteableInstrument CInstrument;

/////////////////////////////////////////////////////////////////////////
///CInstrumentActionTrigger是操作合约时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentActionTrigger
{
public:
	///构造方法
	CInstrumentActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CInstrumentActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CInstrumentFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pInstrument	要加入的Instrument
	virtual void beforeAdd(CWriteableInstrument *pInstrument)
	{
		return;
	}
	
	///加入后触发
	///@param	pInstrument	已经加入的Instrument
	virtual void afterAdd(CInstrument *pInstrument)
	{
		return;
	}

	///更新前触发	
	///@param	pInstrument	被刷新的CInstrument
	///@param	pNewInstrument	新的值
	virtual void beforeUpdate(CInstrument *pInstrument, CWriteableInstrument *pNewInstrument)
	{
		return;
	}
	
	///更新后触发
	///@param	pInstrument	被刷新的CInstrument
	virtual void afterUpdate(CInstrument *pInstrument)
	{
		return;
	}
	
	///删除前触发
	///@param	pInstrument	要删除的CInstrument
	virtual void beforeRemove(CInstrument *pInstrument)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CInstrumentFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentCommitTrigger是确认合约时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentCommitTrigger
{
public:
	///构造方法
	CInstrumentCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CInstrumentCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CInstrumentFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pInstrument	已经加入的Instrument
	virtual void commitAdd(CInstrument *pInstrument)
	{
		return;
	}

	///更新后触发
	///@param	pInstrument	被刷新的CInstrument
	///@param	poldInstrument	原来的值
	virtual void commitUpdate(CInstrument *pInstrument, CWriteableInstrument *pOldInstrument)
	{
		return;
	}
	
	///删除后触发
	///@param	pInstrument	已经删除的CInstrument
	virtual void commitRemove(CWriteableInstrument *pInstrument)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CInstrumentFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentIterator是一个对合约的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentIterator
{
public:
	///构造方法
	CInstrumentIterator(void)
	{
	}

	///构造方法
	CInstrumentIterator(CInstrumentFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CInstrumentIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个Instrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CInstrumentFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument * pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CInstrumentFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCombinationLeg是一个存储组合合约单腿的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCombinationLeg
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! CombInstrumentID.isValid())
			return 0;
		if (! LegID.isValid())
			return 0;
		if (! LegInstrumentID.isValid())
			return 0;
		if (! Direction.isValid())
			return 0;
		if (! LegMultiple.isValid())
			return 0;
		if (! ImplyLevel.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCombinationLeg *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///组合合约代码
	CInstrumentIDType CombInstrumentID;
	///单腿编号
	CLegIDType LegID;
	///单腿合约代码
	CInstrumentIDType LegInstrumentID;
	///买卖方向
	CDirectionType Direction;
	///单腿乘数
	CLegMultipleType LegMultiple;
	///推导层数
	CImplyLevelType ImplyLevel;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	
	///构造对应的组合合约的指针
	///@param	pFactory	构造对应的组合合约的指针时，寻找的对象工厂
	///@return	找到的对应的组合合约的指针
	///@exception	如果找不到，则抛出RUNTIME_ERROR
	inline const CWriteableInstrument *linkCombinationInstrument(CInstrumentFactory *pFactory) const;

	///构造对应的组合合约指针
	///@param	pInstrument	要连接到的对象
	///@return	输入的pInstrument
	const CWriteableInstrument *linkCombinationInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pCombinationInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///获取对应的组合合约的指针
	///@return	找到的对应的组合合约的指针
	///@exception	如果找不到，则抛出RUNTIME_ERROR
	const CWriteableInstrument *getCombinationInstrument(void) const
	{
		return pCombinationInstrument;
	}
	///构造对应的单腿合约的指针
	///@param	pFactory	构造对应的单腿合约的指针时，寻找的对象工厂
	///@return	找到的对应的单腿合约的指针
	///@exception	如果找不到，则抛出RUNTIME_ERROR
	inline const CWriteableInstrument *linkLegInstrument(CInstrumentFactory *pFactory) const;

	///构造对应的单腿合约指针
	///@param	pInstrument	要连接到的对象
	///@return	输入的pInstrument
	const CWriteableInstrument *linkLegInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pLegInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///获取对应的单腿合约的指针
	///@return	找到的对应的单腿合约的指针
	///@exception	如果找不到，则抛出RUNTIME_ERROR
	const CWriteableInstrument *getLegInstrument(void) const
	{
		return pLegInstrument;
	}

private:
	///对应的组合合约
	const CWriteableInstrument *pCombinationInstrument;
	///对应的单腿合约
	const CWriteableInstrument *pLegInstrument;
};

typedef const CWriteableCombinationLeg CCombinationLeg;

/////////////////////////////////////////////////////////////////////////
///CCombinationLegActionTrigger是操作组合合约单腿时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegActionTrigger
{
public:
	///构造方法
	CCombinationLegActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCombinationLegActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCombinationLegFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCombinationLeg	要加入的CombinationLeg
	virtual void beforeAdd(CWriteableCombinationLeg *pCombinationLeg)
	{
		return;
	}
	
	///加入后触发
	///@param	pCombinationLeg	已经加入的CombinationLeg
	virtual void afterAdd(CCombinationLeg *pCombinationLeg)
	{
		return;
	}

	///更新前触发	
	///@param	pCombinationLeg	被刷新的CCombinationLeg
	///@param	pNewCombinationLeg	新的值
	virtual void beforeUpdate(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pNewCombinationLeg)
	{
		return;
	}
	
	///更新后触发
	///@param	pCombinationLeg	被刷新的CCombinationLeg
	virtual void afterUpdate(CCombinationLeg *pCombinationLeg)
	{
		return;
	}
	
	///删除前触发
	///@param	pCombinationLeg	要删除的CCombinationLeg
	virtual void beforeRemove(CCombinationLeg *pCombinationLeg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCombinationLegFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegCommitTrigger是确认组合合约单腿时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegCommitTrigger
{
public:
	///构造方法
	CCombinationLegCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCombinationLegCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCombinationLegFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCombinationLeg	已经加入的CombinationLeg
	virtual void commitAdd(CCombinationLeg *pCombinationLeg)
	{
		return;
	}

	///更新后触发
	///@param	pCombinationLeg	被刷新的CCombinationLeg
	///@param	poldCombinationLeg	原来的值
	virtual void commitUpdate(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pOldCombinationLeg)
	{
		return;
	}
	
	///删除后触发
	///@param	pCombinationLeg	已经删除的CCombinationLeg
	virtual void commitRemove(CWriteableCombinationLeg *pCombinationLeg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCombinationLegFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegIterator是一个对组合合约单腿的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegIterator
{
public:
	///构造方法
	CCombinationLegIterator(void)
	{
	}

	///构造方法
	CCombinationLegIterator(CCombinationLegFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCombinationLegIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CombinationLeg
	///@return	下一个满足条件CCombinationLeg，如果已经没有一个满足要求了，则返回NULL
	virtual CCombinationLeg *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCombinationLegFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCombinationLeg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCombinationLeg * pCombinationLeg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCombinationLegFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartRoleAccount是一个存储会员账户关系的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartRoleAccount
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! AccountID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteablePartRoleAccount *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///会员代码
	CParticipantIDType ParticipantID;
	///交易角色
	CTradingRoleType TradingRole;
	///资金帐号
	CAccountIDType AccountID;
	unsigned int HashPartRoleAndSG;
	
	///计算PartRoleAndSG的hash值
	void calHashPartRoleAndSG(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		key=TradingRole.hash(key);
		key=SettlementGroupID.hash(key);
		HashPartRoleAndSG=key;
	}
	
	///根据需要情况，更新PartRoleAndSG的hash值
	void updateHashPartRoleAndSG(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashPartRoleAndSG();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashPartRoleAndSG();
	}
	
	///构造对应的帐户的指针
	///@param	pFactory	构造对应的帐户的指针时，寻找的对象工厂
	///@return	找到的对应的帐户的指针，如果找不到则返回NULL
	inline const CWriteableTradingAccount *linkTradingAccount(CTradingAccountFactory *pFactory) const;

	///构造对应的帐户指针
	///@param	pTradingAccount	要连接到的对象
	///@return	输入的pTradingAccount
	const CWriteableTradingAccount *linkTradingAccount(const CWriteableTradingAccount *pTradingAccount) const
	{
		void *target=(void *)(&(this->pTradingAccount));
		*((const CWriteableTradingAccount **)target)=pTradingAccount;
		return pTradingAccount;
	}
	
	///获取对应的帐户的指针
	///@return	找到的对应的帐户的指针，如果找不到则返回NULL
	const CWriteableTradingAccount *getTradingAccount(void) const
	{
		return pTradingAccount;
	}

private:
	///对应的帐户
	const CWriteableTradingAccount *pTradingAccount;
};

typedef const CWriteablePartRoleAccount CPartRoleAccount;

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountActionTrigger是操作会员账户关系时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountActionTrigger
{
public:
	///构造方法
	CPartRoleAccountActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartRoleAccountActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartRoleAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pPartRoleAccount	要加入的PartRoleAccount
	virtual void beforeAdd(CWriteablePartRoleAccount *pPartRoleAccount)
	{
		return;
	}
	
	///加入后触发
	///@param	pPartRoleAccount	已经加入的PartRoleAccount
	virtual void afterAdd(CPartRoleAccount *pPartRoleAccount)
	{
		return;
	}

	///更新前触发	
	///@param	pPartRoleAccount	被刷新的CPartRoleAccount
	///@param	pNewPartRoleAccount	新的值
	virtual void beforeUpdate(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pNewPartRoleAccount)
	{
		return;
	}
	
	///更新后触发
	///@param	pPartRoleAccount	被刷新的CPartRoleAccount
	virtual void afterUpdate(CPartRoleAccount *pPartRoleAccount)
	{
		return;
	}
	
	///删除前触发
	///@param	pPartRoleAccount	要删除的CPartRoleAccount
	virtual void beforeRemove(CPartRoleAccount *pPartRoleAccount)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartRoleAccountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountCommitTrigger是确认会员账户关系时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountCommitTrigger
{
public:
	///构造方法
	CPartRoleAccountCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartRoleAccountCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartRoleAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pPartRoleAccount	已经加入的PartRoleAccount
	virtual void commitAdd(CPartRoleAccount *pPartRoleAccount)
	{
		return;
	}

	///更新后触发
	///@param	pPartRoleAccount	被刷新的CPartRoleAccount
	///@param	poldPartRoleAccount	原来的值
	virtual void commitUpdate(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pOldPartRoleAccount)
	{
		return;
	}
	
	///删除后触发
	///@param	pPartRoleAccount	已经删除的CPartRoleAccount
	virtual void commitRemove(CWriteablePartRoleAccount *pPartRoleAccount)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartRoleAccountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountIterator是一个对会员账户关系的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountIterator
{
public:
	///构造方法
	CPartRoleAccountIterator(void)
	{
	}

	///构造方法
	CPartRoleAccountIterator(CPartRoleAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CPartRoleAccountIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个PartRoleAccount
	///@return	下一个满足条件CPartRoleAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CPartRoleAccount *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CPartRoleAccountFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pPartRoleAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartRoleAccount * pPartRoleAccount,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CPartRoleAccountFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartProductRole是一个存储会员产品角色的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartProductRole
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ProductID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteablePartProductRole *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///会员代码
	CParticipantIDType ParticipantID;
	///产品代码
	CProductIDType ProductID;
	///交易角色
	CTradingRoleType TradingRole;
	unsigned int HashParticipantProductRole;
	
	///计算ParticipantProductRole的hash值
	void calHashParticipantProductRole(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		key=ProductID.hash(key);
		key=TradingRole.hash(key);
		HashParticipantProductRole=key;
	}
	
	///根据需要情况，更新ParticipantProductRole的hash值
	void updateHashParticipantProductRole(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashParticipantProductRole();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashParticipantProductRole();
	}
	

private:
};

typedef const CWriteablePartProductRole CPartProductRole;

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleActionTrigger是操作会员产品角色时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleActionTrigger
{
public:
	///构造方法
	CPartProductRoleActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartProductRoleActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartProductRoleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pPartProductRole	要加入的PartProductRole
	virtual void beforeAdd(CWriteablePartProductRole *pPartProductRole)
	{
		return;
	}
	
	///加入后触发
	///@param	pPartProductRole	已经加入的PartProductRole
	virtual void afterAdd(CPartProductRole *pPartProductRole)
	{
		return;
	}

	///更新前触发	
	///@param	pPartProductRole	被刷新的CPartProductRole
	///@param	pNewPartProductRole	新的值
	virtual void beforeUpdate(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pNewPartProductRole)
	{
		return;
	}
	
	///更新后触发
	///@param	pPartProductRole	被刷新的CPartProductRole
	virtual void afterUpdate(CPartProductRole *pPartProductRole)
	{
		return;
	}
	
	///删除前触发
	///@param	pPartProductRole	要删除的CPartProductRole
	virtual void beforeRemove(CPartProductRole *pPartProductRole)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartProductRoleFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleCommitTrigger是确认会员产品角色时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleCommitTrigger
{
public:
	///构造方法
	CPartProductRoleCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartProductRoleCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartProductRoleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pPartProductRole	已经加入的PartProductRole
	virtual void commitAdd(CPartProductRole *pPartProductRole)
	{
		return;
	}

	///更新后触发
	///@param	pPartProductRole	被刷新的CPartProductRole
	///@param	poldPartProductRole	原来的值
	virtual void commitUpdate(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pOldPartProductRole)
	{
		return;
	}
	
	///删除后触发
	///@param	pPartProductRole	已经删除的CPartProductRole
	virtual void commitRemove(CWriteablePartProductRole *pPartProductRole)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartProductRoleFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleIterator是一个对会员产品角色的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleIterator
{
public:
	///构造方法
	CPartProductRoleIterator(void)
	{
	}

	///构造方法
	CPartProductRoleIterator(CPartProductRoleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CPartProductRoleIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个PartProductRole
	///@return	下一个满足条件CPartProductRole，如果已经没有一个满足要求了，则返回NULL
	virtual CPartProductRole *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CPartProductRoleFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pPartProductRole 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartProductRole * pPartProductRole,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CPartProductRoleFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartProductRight是一个存储会员产品交易权限的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartProductRight
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! ProductID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TradingRight.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteablePartProductRight *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///产品代码
	CProductIDType ProductID;
	///会员代码
	CParticipantIDType ParticipantID;
	///交易权限
	CTradingRightType TradingRight;
	unsigned int HashParticipantAndProduct;
	
	///计算ParticipantAndProduct的hash值
	void calHashParticipantAndProduct(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		key=ProductID.hash(key);
		HashParticipantAndProduct=key;
	}
	
	///根据需要情况，更新ParticipantAndProduct的hash值
	void updateHashParticipantAndProduct(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashParticipantAndProduct();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashParticipantAndProduct();
	}
	

private:
};

typedef const CWriteablePartProductRight CPartProductRight;

/////////////////////////////////////////////////////////////////////////
///CPartProductRightActionTrigger是操作会员产品交易权限时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightActionTrigger
{
public:
	///构造方法
	CPartProductRightActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartProductRightActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pPartProductRight	要加入的PartProductRight
	virtual void beforeAdd(CWriteablePartProductRight *pPartProductRight)
	{
		return;
	}
	
	///加入后触发
	///@param	pPartProductRight	已经加入的PartProductRight
	virtual void afterAdd(CPartProductRight *pPartProductRight)
	{
		return;
	}

	///更新前触发	
	///@param	pPartProductRight	被刷新的CPartProductRight
	///@param	pNewPartProductRight	新的值
	virtual void beforeUpdate(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pNewPartProductRight)
	{
		return;
	}
	
	///更新后触发
	///@param	pPartProductRight	被刷新的CPartProductRight
	virtual void afterUpdate(CPartProductRight *pPartProductRight)
	{
		return;
	}
	
	///删除前触发
	///@param	pPartProductRight	要删除的CPartProductRight
	virtual void beforeRemove(CPartProductRight *pPartProductRight)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartProductRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightCommitTrigger是确认会员产品交易权限时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightCommitTrigger
{
public:
	///构造方法
	CPartProductRightCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartProductRightCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pPartProductRight	已经加入的PartProductRight
	virtual void commitAdd(CPartProductRight *pPartProductRight)
	{
		return;
	}

	///更新后触发
	///@param	pPartProductRight	被刷新的CPartProductRight
	///@param	poldPartProductRight	原来的值
	virtual void commitUpdate(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pOldPartProductRight)
	{
		return;
	}
	
	///删除后触发
	///@param	pPartProductRight	已经删除的CPartProductRight
	virtual void commitRemove(CWriteablePartProductRight *pPartProductRight)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartProductRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightIterator是一个对会员产品交易权限的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightIterator
{
public:
	///构造方法
	CPartProductRightIterator(void)
	{
	}

	///构造方法
	CPartProductRightIterator(CPartProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CPartProductRightIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个PartProductRight
	///@return	下一个满足条件CPartProductRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartProductRight *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CPartProductRightFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pPartProductRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartProductRight * pPartProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CPartProductRightFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartInstrumentRight是一个存储会员合约交易权限的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartInstrumentRight
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TradingRight.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteablePartInstrumentRight *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///会员代码
	CParticipantIDType ParticipantID;
	///交易权限
	CTradingRightType TradingRight;
	unsigned int HashParticipantAndInstrument;
	
	///计算ParticipantAndInstrument的hash值
	void calHashParticipantAndInstrument(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		key=InstrumentID.hash(key);
		HashParticipantAndInstrument=key;
	}
	
	///根据需要情况，更新ParticipantAndInstrument的hash值
	void updateHashParticipantAndInstrument(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashParticipantAndInstrument();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashParticipantAndInstrument();
	}
	

private:
};

typedef const CWriteablePartInstrumentRight CPartInstrumentRight;

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightActionTrigger是操作会员合约交易权限时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightActionTrigger
{
public:
	///构造方法
	CPartInstrumentRightActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartInstrumentRightActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pPartInstrumentRight	要加入的PartInstrumentRight
	virtual void beforeAdd(CWriteablePartInstrumentRight *pPartInstrumentRight)
	{
		return;
	}
	
	///加入后触发
	///@param	pPartInstrumentRight	已经加入的PartInstrumentRight
	virtual void afterAdd(CPartInstrumentRight *pPartInstrumentRight)
	{
		return;
	}

	///更新前触发	
	///@param	pPartInstrumentRight	被刷新的CPartInstrumentRight
	///@param	pNewPartInstrumentRight	新的值
	virtual void beforeUpdate(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pNewPartInstrumentRight)
	{
		return;
	}
	
	///更新后触发
	///@param	pPartInstrumentRight	被刷新的CPartInstrumentRight
	virtual void afterUpdate(CPartInstrumentRight *pPartInstrumentRight)
	{
		return;
	}
	
	///删除前触发
	///@param	pPartInstrumentRight	要删除的CPartInstrumentRight
	virtual void beforeRemove(CPartInstrumentRight *pPartInstrumentRight)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartInstrumentRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightCommitTrigger是确认会员合约交易权限时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightCommitTrigger
{
public:
	///构造方法
	CPartInstrumentRightCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartInstrumentRightCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pPartInstrumentRight	已经加入的PartInstrumentRight
	virtual void commitAdd(CPartInstrumentRight *pPartInstrumentRight)
	{
		return;
	}

	///更新后触发
	///@param	pPartInstrumentRight	被刷新的CPartInstrumentRight
	///@param	poldPartInstrumentRight	原来的值
	virtual void commitUpdate(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pOldPartInstrumentRight)
	{
		return;
	}
	
	///删除后触发
	///@param	pPartInstrumentRight	已经删除的CPartInstrumentRight
	virtual void commitRemove(CWriteablePartInstrumentRight *pPartInstrumentRight)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartInstrumentRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightIterator是一个对会员合约交易权限的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightIterator
{
public:
	///构造方法
	CPartInstrumentRightIterator(void)
	{
	}

	///构造方法
	CPartInstrumentRightIterator(CPartInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CPartInstrumentRightIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个PartInstrumentRight
	///@return	下一个满足条件CPartInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartInstrumentRight *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CPartInstrumentRightFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pPartInstrumentRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartInstrumentRight * pPartInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CPartInstrumentRightFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableClientProductRight是一个存储客户产品交易权限的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableClientProductRight
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! ProductID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! TradingRight.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableClientProductRight *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///产品代码
	CProductIDType ProductID;
	///客户代码
	CClientIDType ClientID;
	///交易权限
	CTradingRightType TradingRight;
	unsigned int HashClientAndProduct;
	
	///计算ClientAndProduct的hash值
	void calHashClientAndProduct(void)
	{
		unsigned key=0;
		key=ClientID.hash(key);
		key=ProductID.hash(key);
		HashClientAndProduct=key;
	}
	
	///根据需要情况，更新ClientAndProduct的hash值
	void updateHashClientAndProduct(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashClientAndProduct();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashClientAndProduct();
	}
	

private:
};

typedef const CWriteableClientProductRight CClientProductRight;

/////////////////////////////////////////////////////////////////////////
///CClientProductRightActionTrigger是操作客户产品交易权限时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightActionTrigger
{
public:
	///构造方法
	CClientProductRightActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CClientProductRightActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CClientProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pClientProductRight	要加入的ClientProductRight
	virtual void beforeAdd(CWriteableClientProductRight *pClientProductRight)
	{
		return;
	}
	
	///加入后触发
	///@param	pClientProductRight	已经加入的ClientProductRight
	virtual void afterAdd(CClientProductRight *pClientProductRight)
	{
		return;
	}

	///更新前触发	
	///@param	pClientProductRight	被刷新的CClientProductRight
	///@param	pNewClientProductRight	新的值
	virtual void beforeUpdate(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pNewClientProductRight)
	{
		return;
	}
	
	///更新后触发
	///@param	pClientProductRight	被刷新的CClientProductRight
	virtual void afterUpdate(CClientProductRight *pClientProductRight)
	{
		return;
	}
	
	///删除前触发
	///@param	pClientProductRight	要删除的CClientProductRight
	virtual void beforeRemove(CClientProductRight *pClientProductRight)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CClientProductRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightCommitTrigger是确认客户产品交易权限时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightCommitTrigger
{
public:
	///构造方法
	CClientProductRightCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CClientProductRightCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CClientProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pClientProductRight	已经加入的ClientProductRight
	virtual void commitAdd(CClientProductRight *pClientProductRight)
	{
		return;
	}

	///更新后触发
	///@param	pClientProductRight	被刷新的CClientProductRight
	///@param	poldClientProductRight	原来的值
	virtual void commitUpdate(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pOldClientProductRight)
	{
		return;
	}
	
	///删除后触发
	///@param	pClientProductRight	已经删除的CClientProductRight
	virtual void commitRemove(CWriteableClientProductRight *pClientProductRight)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CClientProductRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightIterator是一个对客户产品交易权限的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightIterator
{
public:
	///构造方法
	CClientProductRightIterator(void)
	{
	}

	///构造方法
	CClientProductRightIterator(CClientProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CClientProductRightIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个ClientProductRight
	///@return	下一个满足条件CClientProductRight，如果已经没有一个满足要求了，则返回NULL
	virtual CClientProductRight *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CClientProductRightFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pClientProductRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientProductRight * pClientProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CClientProductRightFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableClientInstrumentRight是一个存储客户合约交易权限的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableClientInstrumentRight
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! TradingRight.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableClientInstrumentRight *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///客户代码
	CClientIDType ClientID;
	///交易权限
	CTradingRightType TradingRight;
	unsigned int HashClientAndInstrument;
	
	///计算ClientAndInstrument的hash值
	void calHashClientAndInstrument(void)
	{
		unsigned key=0;
		key=ClientID.hash(key);
		key=InstrumentID.hash(key);
		HashClientAndInstrument=key;
	}
	
	///根据需要情况，更新ClientAndInstrument的hash值
	void updateHashClientAndInstrument(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashClientAndInstrument();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashClientAndInstrument();
	}
	

private:
};

typedef const CWriteableClientInstrumentRight CClientInstrumentRight;

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightActionTrigger是操作客户合约交易权限时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightActionTrigger
{
public:
	///构造方法
	CClientInstrumentRightActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CClientInstrumentRightActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CClientInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pClientInstrumentRight	要加入的ClientInstrumentRight
	virtual void beforeAdd(CWriteableClientInstrumentRight *pClientInstrumentRight)
	{
		return;
	}
	
	///加入后触发
	///@param	pClientInstrumentRight	已经加入的ClientInstrumentRight
	virtual void afterAdd(CClientInstrumentRight *pClientInstrumentRight)
	{
		return;
	}

	///更新前触发	
	///@param	pClientInstrumentRight	被刷新的CClientInstrumentRight
	///@param	pNewClientInstrumentRight	新的值
	virtual void beforeUpdate(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pNewClientInstrumentRight)
	{
		return;
	}
	
	///更新后触发
	///@param	pClientInstrumentRight	被刷新的CClientInstrumentRight
	virtual void afterUpdate(CClientInstrumentRight *pClientInstrumentRight)
	{
		return;
	}
	
	///删除前触发
	///@param	pClientInstrumentRight	要删除的CClientInstrumentRight
	virtual void beforeRemove(CClientInstrumentRight *pClientInstrumentRight)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CClientInstrumentRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightCommitTrigger是确认客户合约交易权限时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightCommitTrigger
{
public:
	///构造方法
	CClientInstrumentRightCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CClientInstrumentRightCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CClientInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pClientInstrumentRight	已经加入的ClientInstrumentRight
	virtual void commitAdd(CClientInstrumentRight *pClientInstrumentRight)
	{
		return;
	}

	///更新后触发
	///@param	pClientInstrumentRight	被刷新的CClientInstrumentRight
	///@param	poldClientInstrumentRight	原来的值
	virtual void commitUpdate(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pOldClientInstrumentRight)
	{
		return;
	}
	
	///删除后触发
	///@param	pClientInstrumentRight	已经删除的CClientInstrumentRight
	virtual void commitRemove(CWriteableClientInstrumentRight *pClientInstrumentRight)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CClientInstrumentRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightIterator是一个对客户合约交易权限的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightIterator
{
public:
	///构造方法
	CClientInstrumentRightIterator(void)
	{
	}

	///构造方法
	CClientInstrumentRightIterator(CClientInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CClientInstrumentRightIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个ClientInstrumentRight
	///@return	下一个满足条件CClientInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	virtual CClientInstrumentRight *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CClientInstrumentRightFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pClientInstrumentRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientInstrumentRight * pClientInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CClientInstrumentRightFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartClientProductRight是一个存储会员客户产品交易权限的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartClientProductRight
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! ProductID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! TradingRight.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteablePartClientProductRight *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///产品代码
	CProductIDType ProductID;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
	///交易权限
	CTradingRightType TradingRight;
	unsigned int HashParticipantAndClientAndProduct;
	
	///计算ParticipantAndClientAndProduct的hash值
	void calHashParticipantAndClientAndProduct(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		key=ClientID.hash(key);
		key=ProductID.hash(key);
		HashParticipantAndClientAndProduct=key;
	}
	
	///根据需要情况，更新ParticipantAndClientAndProduct的hash值
	void updateHashParticipantAndClientAndProduct(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashParticipantAndClientAndProduct();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashParticipantAndClientAndProduct();
	}
	

private:
};

typedef const CWriteablePartClientProductRight CPartClientProductRight;

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightActionTrigger是操作会员客户产品交易权限时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightActionTrigger
{
public:
	///构造方法
	CPartClientProductRightActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartClientProductRightActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartClientProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pPartClientProductRight	要加入的PartClientProductRight
	virtual void beforeAdd(CWriteablePartClientProductRight *pPartClientProductRight)
	{
		return;
	}
	
	///加入后触发
	///@param	pPartClientProductRight	已经加入的PartClientProductRight
	virtual void afterAdd(CPartClientProductRight *pPartClientProductRight)
	{
		return;
	}

	///更新前触发	
	///@param	pPartClientProductRight	被刷新的CPartClientProductRight
	///@param	pNewPartClientProductRight	新的值
	virtual void beforeUpdate(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pNewPartClientProductRight)
	{
		return;
	}
	
	///更新后触发
	///@param	pPartClientProductRight	被刷新的CPartClientProductRight
	virtual void afterUpdate(CPartClientProductRight *pPartClientProductRight)
	{
		return;
	}
	
	///删除前触发
	///@param	pPartClientProductRight	要删除的CPartClientProductRight
	virtual void beforeRemove(CPartClientProductRight *pPartClientProductRight)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartClientProductRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightCommitTrigger是确认会员客户产品交易权限时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightCommitTrigger
{
public:
	///构造方法
	CPartClientProductRightCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartClientProductRightCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartClientProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pPartClientProductRight	已经加入的PartClientProductRight
	virtual void commitAdd(CPartClientProductRight *pPartClientProductRight)
	{
		return;
	}

	///更新后触发
	///@param	pPartClientProductRight	被刷新的CPartClientProductRight
	///@param	poldPartClientProductRight	原来的值
	virtual void commitUpdate(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pOldPartClientProductRight)
	{
		return;
	}
	
	///删除后触发
	///@param	pPartClientProductRight	已经删除的CPartClientProductRight
	virtual void commitRemove(CWriteablePartClientProductRight *pPartClientProductRight)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartClientProductRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightIterator是一个对会员客户产品交易权限的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightIterator
{
public:
	///构造方法
	CPartClientProductRightIterator(void)
	{
	}

	///构造方法
	CPartClientProductRightIterator(CPartClientProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CPartClientProductRightIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个PartClientProductRight
	///@return	下一个满足条件CPartClientProductRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClientProductRight *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CPartClientProductRightFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pPartClientProductRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClientProductRight * pPartClientProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CPartClientProductRightFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartClientInstrumentRight是一个存储会员客户合约交易权限的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartClientInstrumentRight
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! TradingRight.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteablePartClientInstrumentRight *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
	///交易权限
	CTradingRightType TradingRight;
	unsigned int HashParticipantAndClientAndInstrument;
	
	///计算ParticipantAndClientAndInstrument的hash值
	void calHashParticipantAndClientAndInstrument(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		key=ClientID.hash(key);
		key=InstrumentID.hash(key);
		HashParticipantAndClientAndInstrument=key;
	}
	
	///根据需要情况，更新ParticipantAndClientAndInstrument的hash值
	void updateHashParticipantAndClientAndInstrument(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashParticipantAndClientAndInstrument();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashParticipantAndClientAndInstrument();
	}
	

private:
};

typedef const CWriteablePartClientInstrumentRight CPartClientInstrumentRight;

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightActionTrigger是操作会员客户合约交易权限时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightActionTrigger
{
public:
	///构造方法
	CPartClientInstrumentRightActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartClientInstrumentRightActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartClientInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pPartClientInstrumentRight	要加入的PartClientInstrumentRight
	virtual void beforeAdd(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return;
	}
	
	///加入后触发
	///@param	pPartClientInstrumentRight	已经加入的PartClientInstrumentRight
	virtual void afterAdd(CPartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return;
	}

	///更新前触发	
	///@param	pPartClientInstrumentRight	被刷新的CPartClientInstrumentRight
	///@param	pNewPartClientInstrumentRight	新的值
	virtual void beforeUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pNewPartClientInstrumentRight)
	{
		return;
	}
	
	///更新后触发
	///@param	pPartClientInstrumentRight	被刷新的CPartClientInstrumentRight
	virtual void afterUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return;
	}
	
	///删除前触发
	///@param	pPartClientInstrumentRight	要删除的CPartClientInstrumentRight
	virtual void beforeRemove(CPartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartClientInstrumentRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightCommitTrigger是确认会员客户合约交易权限时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightCommitTrigger
{
public:
	///构造方法
	CPartClientInstrumentRightCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartClientInstrumentRightCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartClientInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pPartClientInstrumentRight	已经加入的PartClientInstrumentRight
	virtual void commitAdd(CPartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return;
	}

	///更新后触发
	///@param	pPartClientInstrumentRight	被刷新的CPartClientInstrumentRight
	///@param	poldPartClientInstrumentRight	原来的值
	virtual void commitUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pOldPartClientInstrumentRight)
	{
		return;
	}
	
	///删除后触发
	///@param	pPartClientInstrumentRight	已经删除的CPartClientInstrumentRight
	virtual void commitRemove(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartClientInstrumentRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightIterator是一个对会员客户合约交易权限的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightIterator
{
public:
	///构造方法
	CPartClientInstrumentRightIterator(void)
	{
	}

	///构造方法
	CPartClientInstrumentRightIterator(CPartClientInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CPartClientInstrumentRightIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个PartClientInstrumentRight
	///@return	下一个满足条件CPartClientInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClientInstrumentRight *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CPartClientInstrumentRightFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pPartClientInstrumentRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClientInstrumentRight * pPartClientInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CPartClientInstrumentRightFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrProductProperty是一个存储产品属性的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrProductProperty
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! ProductID.isValid())
			return 0;
		if (! ProductLifePhase.isValid())
			return 0;
		if (! TradingModel.isValid())
			return 0;
		if (! OptionsLimitRatio.isValid())
			return 0;
		if (! OptionsMgRatio.isValid())
			return 0;
		if (! SettlePriceSeconds.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrProductProperty *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///产品代码
	CProductIDType ProductID;
	///产品生命周期状态
	CProductLifePhaseType ProductLifePhase;
	///交易模式
	CTradingModelType TradingModel;
	///期权限仓系数
	CRatioType OptionsLimitRatio;
	///期权保证金调整系数
	CRatioType OptionsMgRatio;
	///结算取样时间
	CSettlePriceSecondsType SettlePriceSeconds;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrProductProperty CCurrProductProperty;

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyActionTrigger是操作产品属性时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyActionTrigger
{
public:
	///构造方法
	CCurrProductPropertyActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrProductPropertyActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrProductPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCurrProductProperty	要加入的CurrProductProperty
	virtual void beforeAdd(CWriteableCurrProductProperty *pCurrProductProperty)
	{
		return;
	}
	
	///加入后触发
	///@param	pCurrProductProperty	已经加入的CurrProductProperty
	virtual void afterAdd(CCurrProductProperty *pCurrProductProperty)
	{
		return;
	}

	///更新前触发	
	///@param	pCurrProductProperty	被刷新的CCurrProductProperty
	///@param	pNewCurrProductProperty	新的值
	virtual void beforeUpdate(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pNewCurrProductProperty)
	{
		return;
	}
	
	///更新后触发
	///@param	pCurrProductProperty	被刷新的CCurrProductProperty
	virtual void afterUpdate(CCurrProductProperty *pCurrProductProperty)
	{
		return;
	}
	
	///删除前触发
	///@param	pCurrProductProperty	要删除的CCurrProductProperty
	virtual void beforeRemove(CCurrProductProperty *pCurrProductProperty)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrProductPropertyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyCommitTrigger是确认产品属性时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyCommitTrigger
{
public:
	///构造方法
	CCurrProductPropertyCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrProductPropertyCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrProductPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCurrProductProperty	已经加入的CurrProductProperty
	virtual void commitAdd(CCurrProductProperty *pCurrProductProperty)
	{
		return;
	}

	///更新后触发
	///@param	pCurrProductProperty	被刷新的CCurrProductProperty
	///@param	poldCurrProductProperty	原来的值
	virtual void commitUpdate(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pOldCurrProductProperty)
	{
		return;
	}
	
	///删除后触发
	///@param	pCurrProductProperty	已经删除的CCurrProductProperty
	virtual void commitRemove(CWriteableCurrProductProperty *pCurrProductProperty)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrProductPropertyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyIterator是一个对产品属性的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyIterator
{
public:
	///构造方法
	CCurrProductPropertyIterator(void)
	{
	}

	///构造方法
	CCurrProductPropertyIterator(CCurrProductPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrProductPropertyIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CurrProductProperty
	///@return	下一个满足条件CCurrProductProperty，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrProductProperty *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCurrProductPropertyFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCurrProductProperty 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrProductProperty * pCurrProductProperty,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCurrProductPropertyFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrInstrumentProperty是一个存储合约属性的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrInstrumentProperty
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! CreateDate.isValid())
			return 0;
		if (! OpenDate.isValid())
			return 0;
		if (! ExpireDate.isValid())
			return 0;
		if (! StartDelivDate.isValid())
			return 0;
		if (! EndDelivDate.isValid())
			return 0;
		if (! BasisPrice.isValid())
			return 0;
		if (! MaxMarketOrderVolume.isValid())
			return 0;
		if (! MinMarketOrderVolume.isValid())
			return 0;
		if (! MaxLimitOrderVolume.isValid())
			return 0;
		if (! MinLimitOrderVolume.isValid())
			return 0;
		if (! PriceTick.isValid())
			return 0;
		if (! AllowDelivPersonOpen.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! InstLifePhase.isValid())
			return 0;
		if (! IsFirstTradingDay.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrInstrumentProperty *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///创建日
	CDateType CreateDate;
	///上市日
	CDateType OpenDate;
	///到期日
	CDateType ExpireDate;
	///开始交割日
	CDateType StartDelivDate;
	///最后交割日
	CDateType EndDelivDate;
	///挂牌基准价
	CPriceType BasisPrice;
	///市价单最大下单量
	CVolumeType MaxMarketOrderVolume;
	///市价单最小下单量
	CVolumeType MinMarketOrderVolume;
	///限价单最大下单量
	CVolumeType MaxLimitOrderVolume;
	///限价单最小下单量
	CVolumeType MinLimitOrderVolume;
	///最小变动价位
	CPriceType PriceTick;
	///交割月自然人开仓
	CMonthCountType AllowDelivPersonOpen;
	///合约代码
	CInstrumentIDType InstrumentID;
	///合约生命周期状态
	CInstLifePhaseType InstLifePhase;
	///是否首交易日
	CBoolType IsFirstTradingDay;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrInstrumentProperty CCurrInstrumentProperty;

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyActionTrigger是操作合约属性时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyActionTrigger
{
public:
	///构造方法
	CCurrInstrumentPropertyActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrInstrumentPropertyActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrInstrumentPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCurrInstrumentProperty	要加入的CurrInstrumentProperty
	virtual void beforeAdd(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return;
	}
	
	///加入后触发
	///@param	pCurrInstrumentProperty	已经加入的CurrInstrumentProperty
	virtual void afterAdd(CCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return;
	}

	///更新前触发	
	///@param	pCurrInstrumentProperty	被刷新的CCurrInstrumentProperty
	///@param	pNewCurrInstrumentProperty	新的值
	virtual void beforeUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pNewCurrInstrumentProperty)
	{
		return;
	}
	
	///更新后触发
	///@param	pCurrInstrumentProperty	被刷新的CCurrInstrumentProperty
	virtual void afterUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return;
	}
	
	///删除前触发
	///@param	pCurrInstrumentProperty	要删除的CCurrInstrumentProperty
	virtual void beforeRemove(CCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrInstrumentPropertyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyCommitTrigger是确认合约属性时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyCommitTrigger
{
public:
	///构造方法
	CCurrInstrumentPropertyCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrInstrumentPropertyCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrInstrumentPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCurrInstrumentProperty	已经加入的CurrInstrumentProperty
	virtual void commitAdd(CCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return;
	}

	///更新后触发
	///@param	pCurrInstrumentProperty	被刷新的CCurrInstrumentProperty
	///@param	poldCurrInstrumentProperty	原来的值
	virtual void commitUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pOldCurrInstrumentProperty)
	{
		return;
	}
	
	///删除后触发
	///@param	pCurrInstrumentProperty	已经删除的CCurrInstrumentProperty
	virtual void commitRemove(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrInstrumentPropertyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyIterator是一个对合约属性的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyIterator
{
public:
	///构造方法
	CCurrInstrumentPropertyIterator(void)
	{
	}

	///构造方法
	CCurrInstrumentPropertyIterator(CCurrInstrumentPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrInstrumentPropertyIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CurrInstrumentProperty
	///@return	下一个满足条件CCurrInstrumentProperty，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrInstrumentProperty *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCurrInstrumentPropertyFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCurrInstrumentProperty 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrInstrumentProperty * pCurrInstrumentProperty,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCurrInstrumentPropertyFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrPriceBanding是一个存储当前价格绑定的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrPriceBanding
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! PriceLimitType.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! RoundingMode.isValid())
			return 0;
		if (! UpperValue.isValid())
			return 0;
		if (! LowerValue.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! TradingSegmentSN.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrPriceBanding *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///限价类型
	CPriceLimitTypeType PriceLimitType;
	///取值方式
	CValueModeType ValueMode;
	///舍入方式
	CRoundingModeType RoundingMode;
	///上限
	CPriceType UpperValue;
	///下限
	CPriceType LowerValue;
	///合约代码
	CInstrumentIDType InstrumentID;
	///交易阶段编号
	CTradingSegmentSNType TradingSegmentSN;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrPriceBanding CCurrPriceBanding;

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingActionTrigger是操作当前价格绑定时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingActionTrigger
{
public:
	///构造方法
	CCurrPriceBandingActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrPriceBandingActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrPriceBandingFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCurrPriceBanding	要加入的CurrPriceBanding
	virtual void beforeAdd(CWriteableCurrPriceBanding *pCurrPriceBanding)
	{
		return;
	}
	
	///加入后触发
	///@param	pCurrPriceBanding	已经加入的CurrPriceBanding
	virtual void afterAdd(CCurrPriceBanding *pCurrPriceBanding)
	{
		return;
	}

	///更新前触发	
	///@param	pCurrPriceBanding	被刷新的CCurrPriceBanding
	///@param	pNewCurrPriceBanding	新的值
	virtual void beforeUpdate(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pNewCurrPriceBanding)
	{
		return;
	}
	
	///更新后触发
	///@param	pCurrPriceBanding	被刷新的CCurrPriceBanding
	virtual void afterUpdate(CCurrPriceBanding *pCurrPriceBanding)
	{
		return;
	}
	
	///删除前触发
	///@param	pCurrPriceBanding	要删除的CCurrPriceBanding
	virtual void beforeRemove(CCurrPriceBanding *pCurrPriceBanding)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrPriceBandingFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingCommitTrigger是确认当前价格绑定时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingCommitTrigger
{
public:
	///构造方法
	CCurrPriceBandingCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrPriceBandingCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrPriceBandingFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCurrPriceBanding	已经加入的CurrPriceBanding
	virtual void commitAdd(CCurrPriceBanding *pCurrPriceBanding)
	{
		return;
	}

	///更新后触发
	///@param	pCurrPriceBanding	被刷新的CCurrPriceBanding
	///@param	poldCurrPriceBanding	原来的值
	virtual void commitUpdate(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pOldCurrPriceBanding)
	{
		return;
	}
	
	///删除后触发
	///@param	pCurrPriceBanding	已经删除的CCurrPriceBanding
	virtual void commitRemove(CWriteableCurrPriceBanding *pCurrPriceBanding)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrPriceBandingFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingIterator是一个对当前价格绑定的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingIterator
{
public:
	///构造方法
	CCurrPriceBandingIterator(void)
	{
	}

	///构造方法
	CCurrPriceBandingIterator(CCurrPriceBandingFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrPriceBandingIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CurrPriceBanding
	///@return	下一个满足条件CCurrPriceBanding，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrPriceBanding *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCurrPriceBandingFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCurrPriceBanding 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrPriceBanding * pCurrPriceBanding,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCurrPriceBandingFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrMarginRate是一个存储当天合约保证金率的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrMarginRate
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! MarginCalcID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrMarginRate *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///保证金算法代码
	CMarginCalcIDType MarginCalcID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///会员代码
	CParticipantIDType ParticipantID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrMarginRate CCurrMarginRate;

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateActionTrigger是操作当天合约保证金率时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateActionTrigger
{
public:
	///构造方法
	CCurrMarginRateActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrMarginRateActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrMarginRateFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCurrMarginRate	要加入的CurrMarginRate
	virtual void beforeAdd(CWriteableCurrMarginRate *pCurrMarginRate)
	{
		return;
	}
	
	///加入后触发
	///@param	pCurrMarginRate	已经加入的CurrMarginRate
	virtual void afterAdd(CCurrMarginRate *pCurrMarginRate)
	{
		return;
	}

	///更新前触发	
	///@param	pCurrMarginRate	被刷新的CCurrMarginRate
	///@param	pNewCurrMarginRate	新的值
	virtual void beforeUpdate(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pNewCurrMarginRate)
	{
		return;
	}
	
	///更新后触发
	///@param	pCurrMarginRate	被刷新的CCurrMarginRate
	virtual void afterUpdate(CCurrMarginRate *pCurrMarginRate)
	{
		return;
	}
	
	///删除前触发
	///@param	pCurrMarginRate	要删除的CCurrMarginRate
	virtual void beforeRemove(CCurrMarginRate *pCurrMarginRate)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrMarginRateFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateCommitTrigger是确认当天合约保证金率时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateCommitTrigger
{
public:
	///构造方法
	CCurrMarginRateCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrMarginRateCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrMarginRateFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCurrMarginRate	已经加入的CurrMarginRate
	virtual void commitAdd(CCurrMarginRate *pCurrMarginRate)
	{
		return;
	}

	///更新后触发
	///@param	pCurrMarginRate	被刷新的CCurrMarginRate
	///@param	poldCurrMarginRate	原来的值
	virtual void commitUpdate(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pOldCurrMarginRate)
	{
		return;
	}
	
	///删除后触发
	///@param	pCurrMarginRate	已经删除的CCurrMarginRate
	virtual void commitRemove(CWriteableCurrMarginRate *pCurrMarginRate)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrMarginRateFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateIterator是一个对当天合约保证金率的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateIterator
{
public:
	///构造方法
	CCurrMarginRateIterator(void)
	{
	}

	///构造方法
	CCurrMarginRateIterator(CCurrMarginRateFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrMarginRateIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CurrMarginRate
	///@return	下一个满足条件CCurrMarginRate，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrMarginRate *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCurrMarginRateFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCurrMarginRate 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrMarginRate * pCurrMarginRate,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCurrMarginRateFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrMarginRateDetail是一个存储当天合约保证金率的详细内容的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrMarginRateDetail
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! HedgeFlag.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongMarginRatio.isValid())
			return 0;
		if (! ShortMarginRatio.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrMarginRateDetail *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///交易角色
	CTradingRoleType TradingRole;
	///投机套保标志
	CHedgeFlagType HedgeFlag;
	///取值方式
	CValueModeType ValueMode;
	///多头保证金率
	CRatioType LongMarginRatio;
	///空头保证金率
	CRatioType ShortMarginRatio;
	///合约代码
	CInstrumentIDType InstrumentID;
	///会员代码
	CParticipantIDType ParticipantID;
	unsigned int HashInstrumentAndParticipant;
	
	///计算InstrumentAndParticipant的hash值
	void calHashInstrumentAndParticipant(void)
	{
		unsigned key=0;
		key=InstrumentID.hash(key);
		key=ParticipantID.hash(key);
		key=TradingRole.hash(key);
		key=HedgeFlag.hash(key);
		HashInstrumentAndParticipant=key;
	}
	
	///根据需要情况，更新InstrumentAndParticipant的hash值
	void updateHashInstrumentAndParticipant(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashInstrumentAndParticipant();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashInstrumentAndParticipant();
	}
	

private:
};

typedef const CWriteableCurrMarginRateDetail CCurrMarginRateDetail;

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailActionTrigger是操作当天合约保证金率的详细内容时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailActionTrigger
{
public:
	///构造方法
	CCurrMarginRateDetailActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrMarginRateDetailActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrMarginRateDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCurrMarginRateDetail	要加入的CurrMarginRateDetail
	virtual void beforeAdd(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return;
	}
	
	///加入后触发
	///@param	pCurrMarginRateDetail	已经加入的CurrMarginRateDetail
	virtual void afterAdd(CCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return;
	}

	///更新前触发	
	///@param	pCurrMarginRateDetail	被刷新的CCurrMarginRateDetail
	///@param	pNewCurrMarginRateDetail	新的值
	virtual void beforeUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pNewCurrMarginRateDetail)
	{
		return;
	}
	
	///更新后触发
	///@param	pCurrMarginRateDetail	被刷新的CCurrMarginRateDetail
	virtual void afterUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return;
	}
	
	///删除前触发
	///@param	pCurrMarginRateDetail	要删除的CCurrMarginRateDetail
	virtual void beforeRemove(CCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrMarginRateDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailCommitTrigger是确认当天合约保证金率的详细内容时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailCommitTrigger
{
public:
	///构造方法
	CCurrMarginRateDetailCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrMarginRateDetailCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrMarginRateDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCurrMarginRateDetail	已经加入的CurrMarginRateDetail
	virtual void commitAdd(CCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return;
	}

	///更新后触发
	///@param	pCurrMarginRateDetail	被刷新的CCurrMarginRateDetail
	///@param	poldCurrMarginRateDetail	原来的值
	virtual void commitUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pOldCurrMarginRateDetail)
	{
		return;
	}
	
	///删除后触发
	///@param	pCurrMarginRateDetail	已经删除的CCurrMarginRateDetail
	virtual void commitRemove(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrMarginRateDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailIterator是一个对当天合约保证金率的详细内容的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailIterator
{
public:
	///构造方法
	CCurrMarginRateDetailIterator(void)
	{
	}

	///构造方法
	CCurrMarginRateDetailIterator(CCurrMarginRateDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrMarginRateDetailIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CurrMarginRateDetail
	///@return	下一个满足条件CCurrMarginRateDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrMarginRateDetail *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCurrMarginRateDetailFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCurrMarginRateDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrMarginRateDetail * pCurrMarginRateDetail,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCurrMarginRateDetailFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrPartPosiLimit是一个存储当前会员合约限仓的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrPartPosiLimit
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! PartPosiLimitCalcID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrPartPosiLimit *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///会员限仓算法代码
	CPartPosiLimitCalcIDType PartPosiLimitCalcID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///会员代码
	CParticipantIDType ParticipantID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrPartPosiLimit CCurrPartPosiLimit;

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitActionTrigger是操作当前会员合约限仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitActionTrigger
{
public:
	///构造方法
	CCurrPartPosiLimitActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrPartPosiLimitActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrPartPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCurrPartPosiLimit	要加入的CurrPartPosiLimit
	virtual void beforeAdd(CWriteableCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return;
	}
	
	///加入后触发
	///@param	pCurrPartPosiLimit	已经加入的CurrPartPosiLimit
	virtual void afterAdd(CCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return;
	}

	///更新前触发	
	///@param	pCurrPartPosiLimit	被刷新的CCurrPartPosiLimit
	///@param	pNewCurrPartPosiLimit	新的值
	virtual void beforeUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pNewCurrPartPosiLimit)
	{
		return;
	}
	
	///更新后触发
	///@param	pCurrPartPosiLimit	被刷新的CCurrPartPosiLimit
	virtual void afterUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return;
	}
	
	///删除前触发
	///@param	pCurrPartPosiLimit	要删除的CCurrPartPosiLimit
	virtual void beforeRemove(CCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrPartPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitCommitTrigger是确认当前会员合约限仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitCommitTrigger
{
public:
	///构造方法
	CCurrPartPosiLimitCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrPartPosiLimitCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrPartPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCurrPartPosiLimit	已经加入的CurrPartPosiLimit
	virtual void commitAdd(CCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return;
	}

	///更新后触发
	///@param	pCurrPartPosiLimit	被刷新的CCurrPartPosiLimit
	///@param	poldCurrPartPosiLimit	原来的值
	virtual void commitUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pOldCurrPartPosiLimit)
	{
		return;
	}
	
	///删除后触发
	///@param	pCurrPartPosiLimit	已经删除的CCurrPartPosiLimit
	virtual void commitRemove(CWriteableCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrPartPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitIterator是一个对当前会员合约限仓的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitIterator
{
public:
	///构造方法
	CCurrPartPosiLimitIterator(void)
	{
	}

	///构造方法
	CCurrPartPosiLimitIterator(CCurrPartPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrPartPosiLimitIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CurrPartPosiLimit
	///@return	下一个满足条件CCurrPartPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrPartPosiLimit *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCurrPartPosiLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCurrPartPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimit * pCurrPartPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCurrPartPosiLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrPartPosiLimitDetail是一个存储当前会员合约限仓的详细内容的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrPartPosiLimitDetail
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrPartPosiLimitDetail *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///限仓起点
	CLargeVolumeType StartTotalPosition;
	///取值方式
	CValueModeType ValueMode;
	///多头限仓
	CRatioType LongPosLimit;
	///空头限仓
	CRatioType ShortPosLimit;
	///合约代码
	CInstrumentIDType InstrumentID;
	///会员代码
	CParticipantIDType ParticipantID;
	///交易角色
	CPositionTradingRoleType TradingRole;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrPartPosiLimitDetail CCurrPartPosiLimitDetail;

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailActionTrigger是操作当前会员合约限仓的详细内容时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailActionTrigger
{
public:
	///构造方法
	CCurrPartPosiLimitDetailActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrPartPosiLimitDetailActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrPartPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCurrPartPosiLimitDetail	要加入的CurrPartPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return;
	}
	
	///加入后触发
	///@param	pCurrPartPosiLimitDetail	已经加入的CurrPartPosiLimitDetail
	virtual void afterAdd(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return;
	}

	///更新前触发	
	///@param	pCurrPartPosiLimitDetail	被刷新的CCurrPartPosiLimitDetail
	///@param	pNewCurrPartPosiLimitDetail	新的值
	virtual void beforeUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pNewCurrPartPosiLimitDetail)
	{
		return;
	}
	
	///更新后触发
	///@param	pCurrPartPosiLimitDetail	被刷新的CCurrPartPosiLimitDetail
	virtual void afterUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return;
	}
	
	///删除前触发
	///@param	pCurrPartPosiLimitDetail	要删除的CCurrPartPosiLimitDetail
	virtual void beforeRemove(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrPartPosiLimitDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailCommitTrigger是确认当前会员合约限仓的详细内容时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailCommitTrigger
{
public:
	///构造方法
	CCurrPartPosiLimitDetailCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrPartPosiLimitDetailCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrPartPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCurrPartPosiLimitDetail	已经加入的CurrPartPosiLimitDetail
	virtual void commitAdd(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return;
	}

	///更新后触发
	///@param	pCurrPartPosiLimitDetail	被刷新的CCurrPartPosiLimitDetail
	///@param	poldCurrPartPosiLimitDetail	原来的值
	virtual void commitUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pOldCurrPartPosiLimitDetail)
	{
		return;
	}
	
	///删除后触发
	///@param	pCurrPartPosiLimitDetail	已经删除的CCurrPartPosiLimitDetail
	virtual void commitRemove(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrPartPosiLimitDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailIterator是一个对当前会员合约限仓的详细内容的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailIterator
{
public:
	///构造方法
	CCurrPartPosiLimitDetailIterator(void)
	{
	}

	///构造方法
	CCurrPartPosiLimitDetailIterator(CCurrPartPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrPartPosiLimitDetailIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CurrPartPosiLimitDetail
	///@return	下一个满足条件CCurrPartPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrPartPosiLimitDetail *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCurrPartPosiLimitDetailFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCurrPartPosiLimitDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCurrPartPosiLimitDetailFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrClientPosiLimit是一个存储当前客户合约限仓的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrClientPosiLimit
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! ClientPosiLimitCalcID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrClientPosiLimit *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///客户限仓算法代码
	CClientPosiLimitCalcIDType ClientPosiLimitCalcID;
	///合约代码
	CInstrumentIDType InstrumentID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrClientPosiLimit CCurrClientPosiLimit;

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitActionTrigger是操作当前客户合约限仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitActionTrigger
{
public:
	///构造方法
	CCurrClientPosiLimitActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrClientPosiLimitActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrClientPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCurrClientPosiLimit	要加入的CurrClientPosiLimit
	virtual void beforeAdd(CWriteableCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return;
	}
	
	///加入后触发
	///@param	pCurrClientPosiLimit	已经加入的CurrClientPosiLimit
	virtual void afterAdd(CCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return;
	}

	///更新前触发	
	///@param	pCurrClientPosiLimit	被刷新的CCurrClientPosiLimit
	///@param	pNewCurrClientPosiLimit	新的值
	virtual void beforeUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pNewCurrClientPosiLimit)
	{
		return;
	}
	
	///更新后触发
	///@param	pCurrClientPosiLimit	被刷新的CCurrClientPosiLimit
	virtual void afterUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return;
	}
	
	///删除前触发
	///@param	pCurrClientPosiLimit	要删除的CCurrClientPosiLimit
	virtual void beforeRemove(CCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrClientPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitCommitTrigger是确认当前客户合约限仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitCommitTrigger
{
public:
	///构造方法
	CCurrClientPosiLimitCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrClientPosiLimitCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrClientPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCurrClientPosiLimit	已经加入的CurrClientPosiLimit
	virtual void commitAdd(CCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return;
	}

	///更新后触发
	///@param	pCurrClientPosiLimit	被刷新的CCurrClientPosiLimit
	///@param	poldCurrClientPosiLimit	原来的值
	virtual void commitUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pOldCurrClientPosiLimit)
	{
		return;
	}
	
	///删除后触发
	///@param	pCurrClientPosiLimit	已经删除的CCurrClientPosiLimit
	virtual void commitRemove(CWriteableCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrClientPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitIterator是一个对当前客户合约限仓的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitIterator
{
public:
	///构造方法
	CCurrClientPosiLimitIterator(void)
	{
	}

	///构造方法
	CCurrClientPosiLimitIterator(CCurrClientPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrClientPosiLimitIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CurrClientPosiLimit
	///@return	下一个满足条件CCurrClientPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrClientPosiLimit *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCurrClientPosiLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCurrClientPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimit * pCurrClientPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCurrClientPosiLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrClientPosiLimitDetail是一个存储当前客户合约限仓的详细内容的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrClientPosiLimitDetail
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ClientType.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrClientPosiLimitDetail *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///限仓起点
	CLargeVolumeType StartTotalPosition;
	///取值方式
	CValueModeType ValueMode;
	///多头限仓
	CRatioType LongPosLimit;
	///空头限仓
	CRatioType ShortPosLimit;
	///合约代码
	CInstrumentIDType InstrumentID;
	///客户类型
	CClientTypeType ClientType;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrClientPosiLimitDetail CCurrClientPosiLimitDetail;

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailActionTrigger是操作当前客户合约限仓的详细内容时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailActionTrigger
{
public:
	///构造方法
	CCurrClientPosiLimitDetailActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrClientPosiLimitDetailActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrClientPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCurrClientPosiLimitDetail	要加入的CurrClientPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return;
	}
	
	///加入后触发
	///@param	pCurrClientPosiLimitDetail	已经加入的CurrClientPosiLimitDetail
	virtual void afterAdd(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return;
	}

	///更新前触发	
	///@param	pCurrClientPosiLimitDetail	被刷新的CCurrClientPosiLimitDetail
	///@param	pNewCurrClientPosiLimitDetail	新的值
	virtual void beforeUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pNewCurrClientPosiLimitDetail)
	{
		return;
	}
	
	///更新后触发
	///@param	pCurrClientPosiLimitDetail	被刷新的CCurrClientPosiLimitDetail
	virtual void afterUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return;
	}
	
	///删除前触发
	///@param	pCurrClientPosiLimitDetail	要删除的CCurrClientPosiLimitDetail
	virtual void beforeRemove(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrClientPosiLimitDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailCommitTrigger是确认当前客户合约限仓的详细内容时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailCommitTrigger
{
public:
	///构造方法
	CCurrClientPosiLimitDetailCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrClientPosiLimitDetailCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrClientPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCurrClientPosiLimitDetail	已经加入的CurrClientPosiLimitDetail
	virtual void commitAdd(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return;
	}

	///更新后触发
	///@param	pCurrClientPosiLimitDetail	被刷新的CCurrClientPosiLimitDetail
	///@param	poldCurrClientPosiLimitDetail	原来的值
	virtual void commitUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pOldCurrClientPosiLimitDetail)
	{
		return;
	}
	
	///删除后触发
	///@param	pCurrClientPosiLimitDetail	已经删除的CCurrClientPosiLimitDetail
	virtual void commitRemove(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrClientPosiLimitDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailIterator是一个对当前客户合约限仓的详细内容的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailIterator
{
public:
	///构造方法
	CCurrClientPosiLimitDetailIterator(void)
	{
	}

	///构造方法
	CCurrClientPosiLimitDetailIterator(CCurrClientPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrClientPosiLimitDetailIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CurrClientPosiLimitDetail
	///@return	下一个满足条件CCurrClientPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrClientPosiLimitDetail *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCurrClientPosiLimitDetailFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCurrClientPosiLimitDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCurrClientPosiLimitDetailFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrSpecialPosiLimit是一个存储当前特殊客户合约限仓的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrSpecialPosiLimit
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! ClientPosiLimitCalcID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrSpecialPosiLimit *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///客户限仓算法代码
	CClientPosiLimitCalcIDType ClientPosiLimitCalcID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///客户代码
	CClientIDType ClientID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrSpecialPosiLimit CCurrSpecialPosiLimit;

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitActionTrigger是操作当前特殊客户合约限仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitActionTrigger
{
public:
	///构造方法
	CCurrSpecialPosiLimitActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrSpecialPosiLimitActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrSpecialPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCurrSpecialPosiLimit	要加入的CurrSpecialPosiLimit
	virtual void beforeAdd(CWriteableCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return;
	}
	
	///加入后触发
	///@param	pCurrSpecialPosiLimit	已经加入的CurrSpecialPosiLimit
	virtual void afterAdd(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return;
	}

	///更新前触发	
	///@param	pCurrSpecialPosiLimit	被刷新的CCurrSpecialPosiLimit
	///@param	pNewCurrSpecialPosiLimit	新的值
	virtual void beforeUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pNewCurrSpecialPosiLimit)
	{
		return;
	}
	
	///更新后触发
	///@param	pCurrSpecialPosiLimit	被刷新的CCurrSpecialPosiLimit
	virtual void afterUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return;
	}
	
	///删除前触发
	///@param	pCurrSpecialPosiLimit	要删除的CCurrSpecialPosiLimit
	virtual void beforeRemove(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrSpecialPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitCommitTrigger是确认当前特殊客户合约限仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitCommitTrigger
{
public:
	///构造方法
	CCurrSpecialPosiLimitCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrSpecialPosiLimitCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrSpecialPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCurrSpecialPosiLimit	已经加入的CurrSpecialPosiLimit
	virtual void commitAdd(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return;
	}

	///更新后触发
	///@param	pCurrSpecialPosiLimit	被刷新的CCurrSpecialPosiLimit
	///@param	poldCurrSpecialPosiLimit	原来的值
	virtual void commitUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pOldCurrSpecialPosiLimit)
	{
		return;
	}
	
	///删除后触发
	///@param	pCurrSpecialPosiLimit	已经删除的CCurrSpecialPosiLimit
	virtual void commitRemove(CWriteableCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrSpecialPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitIterator是一个对当前特殊客户合约限仓的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitIterator
{
public:
	///构造方法
	CCurrSpecialPosiLimitIterator(void)
	{
	}

	///构造方法
	CCurrSpecialPosiLimitIterator(CCurrSpecialPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrSpecialPosiLimitIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CurrSpecialPosiLimit
	///@return	下一个满足条件CCurrSpecialPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrSpecialPosiLimit *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCurrSpecialPosiLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCurrSpecialPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimit * pCurrSpecialPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCurrSpecialPosiLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrSpecialPosiLimitDetail是一个存储当前特殊客户合约限仓的详细内容的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrSpecialPosiLimitDetail
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrSpecialPosiLimitDetail *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///限仓起点
	CLargeVolumeType StartTotalPosition;
	///取值方式
	CValueModeType ValueMode;
	///多头限仓
	CRatioType LongPosLimit;
	///空头限仓
	CRatioType ShortPosLimit;
	///合约代码
	CInstrumentIDType InstrumentID;
	///客户代码
	CClientIDType ClientID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrSpecialPosiLimitDetail CCurrSpecialPosiLimitDetail;

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailActionTrigger是操作当前特殊客户合约限仓的详细内容时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailActionTrigger
{
public:
	///构造方法
	CCurrSpecialPosiLimitDetailActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrSpecialPosiLimitDetailActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrSpecialPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCurrSpecialPosiLimitDetail	要加入的CurrSpecialPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return;
	}
	
	///加入后触发
	///@param	pCurrSpecialPosiLimitDetail	已经加入的CurrSpecialPosiLimitDetail
	virtual void afterAdd(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return;
	}

	///更新前触发	
	///@param	pCurrSpecialPosiLimitDetail	被刷新的CCurrSpecialPosiLimitDetail
	///@param	pNewCurrSpecialPosiLimitDetail	新的值
	virtual void beforeUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pNewCurrSpecialPosiLimitDetail)
	{
		return;
	}
	
	///更新后触发
	///@param	pCurrSpecialPosiLimitDetail	被刷新的CCurrSpecialPosiLimitDetail
	virtual void afterUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return;
	}
	
	///删除前触发
	///@param	pCurrSpecialPosiLimitDetail	要删除的CCurrSpecialPosiLimitDetail
	virtual void beforeRemove(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrSpecialPosiLimitDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailCommitTrigger是确认当前特殊客户合约限仓的详细内容时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailCommitTrigger
{
public:
	///构造方法
	CCurrSpecialPosiLimitDetailCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrSpecialPosiLimitDetailCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrSpecialPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCurrSpecialPosiLimitDetail	已经加入的CurrSpecialPosiLimitDetail
	virtual void commitAdd(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return;
	}

	///更新后触发
	///@param	pCurrSpecialPosiLimitDetail	被刷新的CCurrSpecialPosiLimitDetail
	///@param	poldCurrSpecialPosiLimitDetail	原来的值
	virtual void commitUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pOldCurrSpecialPosiLimitDetail)
	{
		return;
	}
	
	///删除后触发
	///@param	pCurrSpecialPosiLimitDetail	已经删除的CCurrSpecialPosiLimitDetail
	virtual void commitRemove(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrSpecialPosiLimitDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailIterator是一个对当前特殊客户合约限仓的详细内容的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailIterator
{
public:
	///构造方法
	CCurrSpecialPosiLimitDetailIterator(void)
	{
	}

	///构造方法
	CCurrSpecialPosiLimitDetailIterator(CCurrSpecialPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrSpecialPosiLimitDetailIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CurrSpecialPosiLimitDetail
	///@return	下一个满足条件CCurrSpecialPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrSpecialPosiLimitDetail *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCurrSpecialPosiLimitDetailFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCurrSpecialPosiLimitDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCurrSpecialPosiLimitDetailFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrHedgeRule是一个存储当前合约套期保值属性的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrHedgeRule
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! HedgeUsageType.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! HedgeCloseTodayType.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrHedgeRule *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///套保额度使用类型
	CHedgeUsageTypeType HedgeUsageType;
	///合约代码
	CInstrumentIDType InstrumentID;
	///套保额度平今仓类型
	CHedgeCloseTodayTypeType HedgeCloseTodayType;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrHedgeRule CCurrHedgeRule;

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleActionTrigger是操作当前合约套期保值属性时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleActionTrigger
{
public:
	///构造方法
	CCurrHedgeRuleActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrHedgeRuleActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrHedgeRuleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCurrHedgeRule	要加入的CurrHedgeRule
	virtual void beforeAdd(CWriteableCurrHedgeRule *pCurrHedgeRule)
	{
		return;
	}
	
	///加入后触发
	///@param	pCurrHedgeRule	已经加入的CurrHedgeRule
	virtual void afterAdd(CCurrHedgeRule *pCurrHedgeRule)
	{
		return;
	}

	///更新前触发	
	///@param	pCurrHedgeRule	被刷新的CCurrHedgeRule
	///@param	pNewCurrHedgeRule	新的值
	virtual void beforeUpdate(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pNewCurrHedgeRule)
	{
		return;
	}
	
	///更新后触发
	///@param	pCurrHedgeRule	被刷新的CCurrHedgeRule
	virtual void afterUpdate(CCurrHedgeRule *pCurrHedgeRule)
	{
		return;
	}
	
	///删除前触发
	///@param	pCurrHedgeRule	要删除的CCurrHedgeRule
	virtual void beforeRemove(CCurrHedgeRule *pCurrHedgeRule)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrHedgeRuleFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleCommitTrigger是确认当前合约套期保值属性时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleCommitTrigger
{
public:
	///构造方法
	CCurrHedgeRuleCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrHedgeRuleCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrHedgeRuleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCurrHedgeRule	已经加入的CurrHedgeRule
	virtual void commitAdd(CCurrHedgeRule *pCurrHedgeRule)
	{
		return;
	}

	///更新后触发
	///@param	pCurrHedgeRule	被刷新的CCurrHedgeRule
	///@param	poldCurrHedgeRule	原来的值
	virtual void commitUpdate(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pOldCurrHedgeRule)
	{
		return;
	}
	
	///删除后触发
	///@param	pCurrHedgeRule	已经删除的CCurrHedgeRule
	virtual void commitRemove(CWriteableCurrHedgeRule *pCurrHedgeRule)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrHedgeRuleFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleIterator是一个对当前合约套期保值属性的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleIterator
{
public:
	///构造方法
	CCurrHedgeRuleIterator(void)
	{
	}

	///构造方法
	CCurrHedgeRuleIterator(CCurrHedgeRuleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrHedgeRuleIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CurrHedgeRule
	///@return	下一个满足条件CCurrHedgeRule，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrHedgeRule *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCurrHedgeRuleFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCurrHedgeRule 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrHedgeRule * pCurrHedgeRule,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCurrHedgeRuleFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrTradingSegmentAttr是一个存储当前合约交易阶段属性的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrTradingSegmentAttr
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! TradingSegmentSN.isValid())
			return 0;
		if (! TradingSegmentName.isValid())
			return 0;
		if (! StartTime.isValid())
			return 0;
		if (! InstrumentStatus.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrTradingSegmentAttr *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///交易阶段编号
	CTradingSegmentSNType TradingSegmentSN;
	///交易阶段名称
	CTradingSegmentNameType TradingSegmentName;
	///起始时间
	CTimeType StartTime;
	///合约交易状态
	CInstrumentStatusType InstrumentStatus;
	///合约代码
	CInstrumentIDType InstrumentID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrTradingSegmentAttr CCurrTradingSegmentAttr;

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrActionTrigger是操作当前合约交易阶段属性时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrActionTrigger
{
public:
	///构造方法
	CCurrTradingSegmentAttrActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrTradingSegmentAttrActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrTradingSegmentAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCurrTradingSegmentAttr	要加入的CurrTradingSegmentAttr
	virtual void beforeAdd(CWriteableCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return;
	}
	
	///加入后触发
	///@param	pCurrTradingSegmentAttr	已经加入的CurrTradingSegmentAttr
	virtual void afterAdd(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return;
	}

	///更新前触发	
	///@param	pCurrTradingSegmentAttr	被刷新的CCurrTradingSegmentAttr
	///@param	pNewCurrTradingSegmentAttr	新的值
	virtual void beforeUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pNewCurrTradingSegmentAttr)
	{
		return;
	}
	
	///更新后触发
	///@param	pCurrTradingSegmentAttr	被刷新的CCurrTradingSegmentAttr
	virtual void afterUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return;
	}
	
	///删除前触发
	///@param	pCurrTradingSegmentAttr	要删除的CCurrTradingSegmentAttr
	virtual void beforeRemove(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrTradingSegmentAttrFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrCommitTrigger是确认当前合约交易阶段属性时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrCommitTrigger
{
public:
	///构造方法
	CCurrTradingSegmentAttrCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrTradingSegmentAttrCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrTradingSegmentAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCurrTradingSegmentAttr	已经加入的CurrTradingSegmentAttr
	virtual void commitAdd(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return;
	}

	///更新后触发
	///@param	pCurrTradingSegmentAttr	被刷新的CCurrTradingSegmentAttr
	///@param	poldCurrTradingSegmentAttr	原来的值
	virtual void commitUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pOldCurrTradingSegmentAttr)
	{
		return;
	}
	
	///删除后触发
	///@param	pCurrTradingSegmentAttr	已经删除的CCurrTradingSegmentAttr
	virtual void commitRemove(CWriteableCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrTradingSegmentAttrFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrIterator是一个对当前合约交易阶段属性的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrIterator
{
public:
	///构造方法
	CCurrTradingSegmentAttrIterator(void)
	{
	}

	///构造方法
	CCurrTradingSegmentAttrIterator(CCurrTradingSegmentAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrTradingSegmentAttrIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CurrTradingSegmentAttr
	///@return	下一个满足条件CCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrTradingSegmentAttr *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCurrTradingSegmentAttrFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCurrTradingSegmentAttr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrTradingSegmentAttr * pCurrTradingSegmentAttr,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCurrTradingSegmentAttrFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrFuse是一个存储当前合约熔断属性的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrFuse
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! PriceLimitType.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! RoundingMode.isValid())
			return 0;
		if (! UpperValue.isValid())
			return 0;
		if (! LowerValue.isValid())
			return 0;
		if (! PriceLimitDuration.isValid())
			return 0;
		if (! FuseDuration.isValid())
			return 0;
		if (! TradingFlag.isValid())
			return 0;
		if (! NoFuseTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrFuse *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///限价类型
	CPriceLimitTypeType PriceLimitType;
	///取值方式
	CValueModeType ValueMode;
	///舍入方式
	CRoundingModeType RoundingMode;
	///上限
	CPriceType UpperValue;
	///下限
	CPriceType LowerValue;
	///停板持续时间
	CDurationType PriceLimitDuration;
	///熔断期
	CDurationType FuseDuration;
	///熔断期是否交易
	CBoolType TradingFlag;
	///不启动熔断时间
	CTimeType NoFuseTime;
	///合约代码
	CInstrumentIDType InstrumentID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrFuse CCurrFuse;

/////////////////////////////////////////////////////////////////////////
///CCurrFuseActionTrigger是操作当前合约熔断属性时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseActionTrigger
{
public:
	///构造方法
	CCurrFuseActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrFuseActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrFuseFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCurrFuse	要加入的CurrFuse
	virtual void beforeAdd(CWriteableCurrFuse *pCurrFuse)
	{
		return;
	}
	
	///加入后触发
	///@param	pCurrFuse	已经加入的CurrFuse
	virtual void afterAdd(CCurrFuse *pCurrFuse)
	{
		return;
	}

	///更新前触发	
	///@param	pCurrFuse	被刷新的CCurrFuse
	///@param	pNewCurrFuse	新的值
	virtual void beforeUpdate(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pNewCurrFuse)
	{
		return;
	}
	
	///更新后触发
	///@param	pCurrFuse	被刷新的CCurrFuse
	virtual void afterUpdate(CCurrFuse *pCurrFuse)
	{
		return;
	}
	
	///删除前触发
	///@param	pCurrFuse	要删除的CCurrFuse
	virtual void beforeRemove(CCurrFuse *pCurrFuse)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrFuseFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseCommitTrigger是确认当前合约熔断属性时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseCommitTrigger
{
public:
	///构造方法
	CCurrFuseCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrFuseCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrFuseFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCurrFuse	已经加入的CurrFuse
	virtual void commitAdd(CCurrFuse *pCurrFuse)
	{
		return;
	}

	///更新后触发
	///@param	pCurrFuse	被刷新的CCurrFuse
	///@param	poldCurrFuse	原来的值
	virtual void commitUpdate(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pOldCurrFuse)
	{
		return;
	}
	
	///删除后触发
	///@param	pCurrFuse	已经删除的CCurrFuse
	virtual void commitRemove(CWriteableCurrFuse *pCurrFuse)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrFuseFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseIterator是一个对当前合约熔断属性的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseIterator
{
public:
	///构造方法
	CCurrFuseIterator(void)
	{
	}

	///构造方法
	CCurrFuseIterator(CCurrFuseFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrFuseIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CurrFuse
	///@return	下一个满足条件CCurrFuse，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrFuse *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCurrFuseFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCurrFuse 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrFuse * pCurrFuse,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCurrFuseFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableTradingAccount是一个存储交易账户的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableTradingAccount
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! PreBalance.isValid())
			return 0;
		if (! CurrMargin.isValid())
			return 0;
		if (! CloseProfit.isValid())
			return 0;
		if (! Premium.isValid())
			return 0;
		if (! Deposit.isValid())
			return 0;
		if (! Withdraw.isValid())
			return 0;
		if (! Balance.isValid())
			return 0;
		if (! Available.isValid())
			return 0;
		if (! AccountID.isValid())
			return 0;
		if (! FrozenMargin.isValid())
			return 0;
		if (! FrozenPremium.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableTradingAccount *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///上次结算准备金
	CMoneyType PreBalance;
	///当前保证金总额
	CMoneyType CurrMargin;
	///平仓盈亏
	CMoneyType CloseProfit;
	///期权权利金收支
	CMoneyType Premium;
	///入金金额
	CMoneyType Deposit;
	///出金金额
	CMoneyType Withdraw;
	///期货结算准备金
	CMoneyType Balance;
	///可提资金
	CMoneyType Available;
	///资金帐号
	CAccountIDType AccountID;
	///冻结的保证金
	CMoneyType FrozenMargin;
	///冻结的权利金
	CMoneyType FrozenPremium;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	
	///构造对应的基本准备金账户的指针
	///@param	pFactory	构造对应的基本准备金账户的指针时，寻找的对象工厂
	///@return	找到的对应的基本准备金账户的指针，如果找不到则返回NULL
	inline const CWriteableBaseReserveAccount *linkBaseReserveAccount(CBaseReserveAccountFactory *pFactory) const;

	///构造对应的基本准备金账户指针
	///@param	pBaseReserveAccount	要连接到的对象
	///@return	输入的pBaseReserveAccount
	const CWriteableBaseReserveAccount *linkBaseReserveAccount(const CWriteableBaseReserveAccount *pBaseReserveAccount) const
	{
		void *target=(void *)(&(this->pBaseReserveAccount));
		*((const CWriteableBaseReserveAccount **)target)=pBaseReserveAccount;
		return pBaseReserveAccount;
	}
	
	///获取对应的基本准备金账户的指针
	///@return	找到的对应的基本准备金账户的指针，如果找不到则返回NULL
	const CWriteableBaseReserveAccount *getBaseReserveAccount(void) const
	{
		return pBaseReserveAccount;
	}

private:
	///对应的基本准备金账户
	const CWriteableBaseReserveAccount *pBaseReserveAccount;
};

typedef const CWriteableTradingAccount CTradingAccount;

/////////////////////////////////////////////////////////////////////////
///CTradingAccountActionTrigger是操作交易账户时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountActionTrigger
{
public:
	///构造方法
	CTradingAccountActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CTradingAccountActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CTradingAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pTradingAccount	要加入的TradingAccount
	virtual void beforeAdd(CWriteableTradingAccount *pTradingAccount)
	{
		return;
	}
	
	///加入后触发
	///@param	pTradingAccount	已经加入的TradingAccount
	virtual void afterAdd(CTradingAccount *pTradingAccount)
	{
		return;
	}

	///更新前触发	
	///@param	pTradingAccount	被刷新的CTradingAccount
	///@param	pNewTradingAccount	新的值
	virtual void beforeUpdate(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pNewTradingAccount)
	{
		return;
	}
	
	///更新后触发
	///@param	pTradingAccount	被刷新的CTradingAccount
	virtual void afterUpdate(CTradingAccount *pTradingAccount)
	{
		return;
	}
	
	///删除前触发
	///@param	pTradingAccount	要删除的CTradingAccount
	virtual void beforeRemove(CTradingAccount *pTradingAccount)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CTradingAccountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountCommitTrigger是确认交易账户时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountCommitTrigger
{
public:
	///构造方法
	CTradingAccountCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CTradingAccountCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CTradingAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pTradingAccount	已经加入的TradingAccount
	virtual void commitAdd(CTradingAccount *pTradingAccount)
	{
		return;
	}

	///更新后触发
	///@param	pTradingAccount	被刷新的CTradingAccount
	///@param	poldTradingAccount	原来的值
	virtual void commitUpdate(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pOldTradingAccount)
	{
		return;
	}
	
	///删除后触发
	///@param	pTradingAccount	已经删除的CTradingAccount
	virtual void commitRemove(CWriteableTradingAccount *pTradingAccount)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CTradingAccountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountIterator是一个对交易账户的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountIterator
{
public:
	///构造方法
	CTradingAccountIterator(void)
	{
	}

	///构造方法
	CTradingAccountIterator(CTradingAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CTradingAccountIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个TradingAccount
	///@return	下一个满足条件CTradingAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CTradingAccount *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CTradingAccountFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pTradingAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTradingAccount * pTradingAccount,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CTradingAccountFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableBaseReserveAccount是一个存储基本准备金账户的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableBaseReserveAccount
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! AccountID.isValid())
			return 0;
		if (! Reserve.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableBaseReserveAccount *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///会员代码
	CParticipantIDType ParticipantID;
	///资金帐号
	CAccountIDType AccountID;
	///基本准备金
	CMoneyType Reserve;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableBaseReserveAccount CBaseReserveAccount;

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountActionTrigger是操作基本准备金账户时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountActionTrigger
{
public:
	///构造方法
	CBaseReserveAccountActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CBaseReserveAccountActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CBaseReserveAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pBaseReserveAccount	要加入的BaseReserveAccount
	virtual void beforeAdd(CWriteableBaseReserveAccount *pBaseReserveAccount)
	{
		return;
	}
	
	///加入后触发
	///@param	pBaseReserveAccount	已经加入的BaseReserveAccount
	virtual void afterAdd(CBaseReserveAccount *pBaseReserveAccount)
	{
		return;
	}

	///更新前触发	
	///@param	pBaseReserveAccount	被刷新的CBaseReserveAccount
	///@param	pNewBaseReserveAccount	新的值
	virtual void beforeUpdate(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pNewBaseReserveAccount)
	{
		return;
	}
	
	///更新后触发
	///@param	pBaseReserveAccount	被刷新的CBaseReserveAccount
	virtual void afterUpdate(CBaseReserveAccount *pBaseReserveAccount)
	{
		return;
	}
	
	///删除前触发
	///@param	pBaseReserveAccount	要删除的CBaseReserveAccount
	virtual void beforeRemove(CBaseReserveAccount *pBaseReserveAccount)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CBaseReserveAccountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountCommitTrigger是确认基本准备金账户时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountCommitTrigger
{
public:
	///构造方法
	CBaseReserveAccountCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CBaseReserveAccountCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CBaseReserveAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pBaseReserveAccount	已经加入的BaseReserveAccount
	virtual void commitAdd(CBaseReserveAccount *pBaseReserveAccount)
	{
		return;
	}

	///更新后触发
	///@param	pBaseReserveAccount	被刷新的CBaseReserveAccount
	///@param	poldBaseReserveAccount	原来的值
	virtual void commitUpdate(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pOldBaseReserveAccount)
	{
		return;
	}
	
	///删除后触发
	///@param	pBaseReserveAccount	已经删除的CBaseReserveAccount
	virtual void commitRemove(CWriteableBaseReserveAccount *pBaseReserveAccount)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CBaseReserveAccountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountIterator是一个对基本准备金账户的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountIterator
{
public:
	///构造方法
	CBaseReserveAccountIterator(void)
	{
	}

	///构造方法
	CBaseReserveAccountIterator(CBaseReserveAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CBaseReserveAccountIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个BaseReserveAccount
	///@return	下一个满足条件CBaseReserveAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CBaseReserveAccount *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CBaseReserveAccountFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pBaseReserveAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBaseReserveAccount * pBaseReserveAccount,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CBaseReserveAccountFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartPosition是一个存储会员持仓的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartPosition
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! HedgeFlag.isValid())
			return 0;
		if (! PosiDirection.isValid())
			return 0;
		if (! YdPosition.isValid())
			return 0;
		if (! Position.isValid())
			return 0;
		if (! LongFrozen.isValid())
			return 0;
		if (! ShortFrozen.isValid())
			return 0;
		if (! YdLongFrozen.isValid())
			return 0;
		if (! YdShortFrozen.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteablePartPosition *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///投机套保标志
	CHedgeFlagType HedgeFlag;
	///持仓多空方向
	CPosiDirectionType PosiDirection;
	///上日持仓
	CVolumeType YdPosition;
	///今日持仓
	CVolumeType Position;
	///多头冻结
	CVolumeType LongFrozen;
	///空头冻结
	CVolumeType ShortFrozen;
	///昨日多头冻结
	CVolumeType YdLongFrozen;
	///昨日空头冻结
	CVolumeType YdShortFrozen;
	///合约代码
	CInstrumentIDType InstrumentID;
	///会员代码
	CParticipantIDType ParticipantID;
	///交易角色
	CTradingRoleType TradingRole;
	unsigned int HashPartAndInstrument;
	
	///计算PartAndInstrument的hash值
	void calHashPartAndInstrument(void)
	{
		unsigned key=0;
		key=InstrumentID.hash(key);
		key=PosiDirection.hash(key);
		key=HedgeFlag.hash(key);
		key=ParticipantID.hash(key);
		key=TradingRole.hash(key);
		HashPartAndInstrument=key;
	}
	
	///根据需要情况，更新PartAndInstrument的hash值
	void updateHashPartAndInstrument(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashPartAndInstrument();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashPartAndInstrument();
	}
	

private:
};

typedef const CWriteablePartPosition CPartPosition;

/////////////////////////////////////////////////////////////////////////
///CPartPositionActionTrigger是操作会员持仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionActionTrigger
{
public:
	///构造方法
	CPartPositionActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartPositionActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pPartPosition	要加入的PartPosition
	virtual void beforeAdd(CWriteablePartPosition *pPartPosition)
	{
		return;
	}
	
	///加入后触发
	///@param	pPartPosition	已经加入的PartPosition
	virtual void afterAdd(CPartPosition *pPartPosition)
	{
		return;
	}

	///更新前触发	
	///@param	pPartPosition	被刷新的CPartPosition
	///@param	pNewPartPosition	新的值
	virtual void beforeUpdate(CPartPosition *pPartPosition, CWriteablePartPosition *pNewPartPosition)
	{
		return;
	}
	
	///更新后触发
	///@param	pPartPosition	被刷新的CPartPosition
	virtual void afterUpdate(CPartPosition *pPartPosition)
	{
		return;
	}
	
	///删除前触发
	///@param	pPartPosition	要删除的CPartPosition
	virtual void beforeRemove(CPartPosition *pPartPosition)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartPositionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionCommitTrigger是确认会员持仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionCommitTrigger
{
public:
	///构造方法
	CPartPositionCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CPartPositionCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CPartPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pPartPosition	已经加入的PartPosition
	virtual void commitAdd(CPartPosition *pPartPosition)
	{
		return;
	}

	///更新后触发
	///@param	pPartPosition	被刷新的CPartPosition
	///@param	poldPartPosition	原来的值
	virtual void commitUpdate(CPartPosition *pPartPosition, CWriteablePartPosition *pOldPartPosition)
	{
		return;
	}
	
	///删除后触发
	///@param	pPartPosition	已经删除的CPartPosition
	virtual void commitRemove(CWriteablePartPosition *pPartPosition)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CPartPositionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionIterator是一个对会员持仓的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionIterator
{
public:
	///构造方法
	CPartPositionIterator(void)
	{
	}

	///构造方法
	CPartPositionIterator(CPartPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CPartPositionIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个PartPosition
	///@return	下一个满足条件CPartPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CPartPosition *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CPartPositionFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pPartPosition 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartPosition * pPartPosition,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CPartPositionFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableClientPosition是一个存储客户持仓的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableClientPosition
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! HedgeFlag.isValid())
			return 0;
		if (! PosiDirection.isValid())
			return 0;
		if (! YdPosition.isValid())
			return 0;
		if (! Position.isValid())
			return 0;
		if (! LongFrozen.isValid())
			return 0;
		if (! ShortFrozen.isValid())
			return 0;
		if (! YdLongFrozen.isValid())
			return 0;
		if (! YdShortFrozen.isValid())
			return 0;
		if (! BuyTradeVolume.isValid())
			return 0;
		if (! SellTradeVolume.isValid())
			return 0;
		if (! PositionCost.isValid())
			return 0;
		if (! YdPositionCost.isValid())
			return 0;
		if (! UseMargin.isValid())
			return 0;
		if (! FrozenMargin.isValid())
			return 0;
		if (! LongFrozenMargin.isValid())
			return 0;
		if (! ShortFrozenMargin.isValid())
			return 0;
		if (! FrozenPremium.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableClientPosition *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///投机套保标志
	CHedgeFlagType HedgeFlag;
	///持仓多空方向
	CPosiDirectionType PosiDirection;
	///上日持仓
	CVolumeType YdPosition;
	///今日持仓
	CVolumeType Position;
	///多头冻结
	CVolumeType LongFrozen;
	///空头冻结
	CVolumeType ShortFrozen;
	///昨日多头冻结
	CVolumeType YdLongFrozen;
	///昨日空头冻结
	CVolumeType YdShortFrozen;
	///当日买成交量
	CVolumeType BuyTradeVolume;
	///当日卖成交量
	CVolumeType SellTradeVolume;
	///持仓成本
	CMoneyType PositionCost;
	///昨日持仓成本
	CMoneyType YdPositionCost;
	///占用的保证金
	CMoneyType UseMargin;
	///冻结的保证金
	CMoneyType FrozenMargin;
	///多头冻结的保证金
	CMoneyType LongFrozenMargin;
	///空头冻结的保证金
	CMoneyType ShortFrozenMargin;
	///冻结的权利金
	CMoneyType FrozenPremium;
	///合约代码
	CInstrumentIDType InstrumentID;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
	unsigned int HashClientAndInstrument;
	
	///计算ClientAndInstrument的hash值
	void calHashClientAndInstrument(void)
	{
		unsigned key=0;
		key=InstrumentID.hash(key);
		key=PosiDirection.hash(key);
		key=HedgeFlag.hash(key);
		key=ClientID.hash(key);
		HashClientAndInstrument=key;
	}
	
	///根据需要情况，更新ClientAndInstrument的hash值
	void updateHashClientAndInstrument(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashClientAndInstrument();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashClientAndInstrument();
	}
	
	///构造对应的信用额度的指针
	///@param	pFactory	构造对应的信用额度的指针时，寻找的对象工厂
	///@return	找到的对应的信用额度的指针，如果找不到则返回NULL
	inline const CWriteableCreditLimit *linkCreditLimit(CCreditLimitFactory *pFactory) const;

	///构造对应的信用额度指针
	///@param	pCreditLimit	要连接到的对象
	///@return	输入的pCreditLimit
	const CWriteableCreditLimit *linkCreditLimit(const CWriteableCreditLimit *pCreditLimit) const
	{
		void *target=(void *)(&(this->pCreditLimit));
		*((const CWriteableCreditLimit **)target)=pCreditLimit;
		return pCreditLimit;
	}
	
	///获取对应的信用额度的指针
	///@return	找到的对应的信用额度的指针，如果找不到则返回NULL
	const CWriteableCreditLimit *getCreditLimit(void) const
	{
		return pCreditLimit;
	}
	///构造对应的会员角色帐号的指针
	///@param	pFactory	构造对应的会员角色帐号的指针时，寻找的对象工厂
	///@return	找到的对应的会员角色帐号的指针，如果找不到则返回NULL
	inline const CWriteablePartRoleAccount *linkPartRoleAccount(CPartRoleAccountFactory *pFactory) const;

	///构造对应的会员角色帐号指针
	///@param	pPartRoleAccount	要连接到的对象
	///@return	输入的pPartRoleAccount
	const CWriteablePartRoleAccount *linkPartRoleAccount(const CWriteablePartRoleAccount *pPartRoleAccount) const
	{
		void *target=(void *)(&(this->pPartRoleAccount));
		*((const CWriteablePartRoleAccount **)target)=pPartRoleAccount;
		return pPartRoleAccount;
	}
	
	///获取对应的会员角色帐号的指针
	///@return	找到的对应的会员角色帐号的指针，如果找不到则返回NULL
	const CWriteablePartRoleAccount *getPartRoleAccount(void) const
	{
		return pPartRoleAccount;
	}

private:
	///对应的信用额度
	const CWriteableCreditLimit *pCreditLimit;
	///对应的会员角色帐号
	const CWriteablePartRoleAccount *pPartRoleAccount;
};

typedef const CWriteableClientPosition CClientPosition;

/////////////////////////////////////////////////////////////////////////
///CClientPositionActionTrigger是操作客户持仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionActionTrigger
{
public:
	///构造方法
	CClientPositionActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CClientPositionActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CClientPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pClientPosition	要加入的ClientPosition
	virtual void beforeAdd(CWriteableClientPosition *pClientPosition)
	{
		return;
	}
	
	///加入后触发
	///@param	pClientPosition	已经加入的ClientPosition
	virtual void afterAdd(CClientPosition *pClientPosition)
	{
		return;
	}

	///更新前触发	
	///@param	pClientPosition	被刷新的CClientPosition
	///@param	pNewClientPosition	新的值
	virtual void beforeUpdate(CClientPosition *pClientPosition, CWriteableClientPosition *pNewClientPosition)
	{
		return;
	}
	
	///更新后触发
	///@param	pClientPosition	被刷新的CClientPosition
	virtual void afterUpdate(CClientPosition *pClientPosition)
	{
		return;
	}
	
	///删除前触发
	///@param	pClientPosition	要删除的CClientPosition
	virtual void beforeRemove(CClientPosition *pClientPosition)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CClientPositionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionCommitTrigger是确认客户持仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionCommitTrigger
{
public:
	///构造方法
	CClientPositionCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CClientPositionCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CClientPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pClientPosition	已经加入的ClientPosition
	virtual void commitAdd(CClientPosition *pClientPosition)
	{
		return;
	}

	///更新后触发
	///@param	pClientPosition	被刷新的CClientPosition
	///@param	poldClientPosition	原来的值
	virtual void commitUpdate(CClientPosition *pClientPosition, CWriteableClientPosition *pOldClientPosition)
	{
		return;
	}
	
	///删除后触发
	///@param	pClientPosition	已经删除的CClientPosition
	virtual void commitRemove(CWriteableClientPosition *pClientPosition)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CClientPositionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionIterator是一个对客户持仓的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionIterator
{
public:
	///构造方法
	CClientPositionIterator(void)
	{
	}

	///构造方法
	CClientPositionIterator(CClientPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CClientPositionIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个ClientPosition
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CClientPosition *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CClientPositionFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pClientPosition 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientPosition * pClientPosition,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CClientPositionFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableHedgeVolume是一个存储保值额度量的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableHedgeVolume
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! LongVolumeOriginal.isValid())
			return 0;
		if (! ShortVolumeOriginal.isValid())
			return 0;
		if (! LongVolume.isValid())
			return 0;
		if (! ShortVolume.isValid())
			return 0;
		if (! LongLimit.isValid())
			return 0;
		if (! ShortLimit.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableHedgeVolume *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///多头保值额度最初申请量
	CVolumeType LongVolumeOriginal;
	///空头保值额度最初申请量
	CVolumeType ShortVolumeOriginal;
	///多头保值额度
	CVolumeType LongVolume;
	///空头保值额度
	CVolumeType ShortVolume;
	///多头限额
	CVolumeType LongLimit;
	///空头限额
	CVolumeType ShortLimit;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableHedgeVolume CHedgeVolume;

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeActionTrigger是操作保值额度量时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeActionTrigger
{
public:
	///构造方法
	CHedgeVolumeActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CHedgeVolumeActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CHedgeVolumeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pHedgeVolume	要加入的HedgeVolume
	virtual void beforeAdd(CWriteableHedgeVolume *pHedgeVolume)
	{
		return;
	}
	
	///加入后触发
	///@param	pHedgeVolume	已经加入的HedgeVolume
	virtual void afterAdd(CHedgeVolume *pHedgeVolume)
	{
		return;
	}

	///更新前触发	
	///@param	pHedgeVolume	被刷新的CHedgeVolume
	///@param	pNewHedgeVolume	新的值
	virtual void beforeUpdate(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pNewHedgeVolume)
	{
		return;
	}
	
	///更新后触发
	///@param	pHedgeVolume	被刷新的CHedgeVolume
	virtual void afterUpdate(CHedgeVolume *pHedgeVolume)
	{
		return;
	}
	
	///删除前触发
	///@param	pHedgeVolume	要删除的CHedgeVolume
	virtual void beforeRemove(CHedgeVolume *pHedgeVolume)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CHedgeVolumeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeCommitTrigger是确认保值额度量时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeCommitTrigger
{
public:
	///构造方法
	CHedgeVolumeCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CHedgeVolumeCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CHedgeVolumeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pHedgeVolume	已经加入的HedgeVolume
	virtual void commitAdd(CHedgeVolume *pHedgeVolume)
	{
		return;
	}

	///更新后触发
	///@param	pHedgeVolume	被刷新的CHedgeVolume
	///@param	poldHedgeVolume	原来的值
	virtual void commitUpdate(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pOldHedgeVolume)
	{
		return;
	}
	
	///删除后触发
	///@param	pHedgeVolume	已经删除的CHedgeVolume
	virtual void commitRemove(CWriteableHedgeVolume *pHedgeVolume)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CHedgeVolumeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeIterator是一个对保值额度量的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeIterator
{
public:
	///构造方法
	CHedgeVolumeIterator(void)
	{
	}

	///构造方法
	CHedgeVolumeIterator(CHedgeVolumeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CHedgeVolumeIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个HedgeVolume
	///@return	下一个满足条件CHedgeVolume，如果已经没有一个满足要求了，则返回NULL
	virtual CHedgeVolume *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CHedgeVolumeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pHedgeVolume 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableHedgeVolume * pHedgeVolume,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CHedgeVolumeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableRemainOrder是一个存储历史报单的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableRemainOrder
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! Tradable.isValid())
			return 0;
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! OrderSysID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! OrderPriceType.isValid())
			return 0;
		if (! Direction.isValid())
			return 0;
		if (! CombOffsetFlag.isValid())
			return 0;
		if (! CombHedgeFlag.isValid())
			return 0;
		if (! LimitPrice.isValid())
			return 0;
		if (! VolumeTotalOriginal.isValid())
			return 0;
		if (! TimeCondition.isValid())
			return 0;
		if (! GTDDate.isValid())
			return 0;
		if (! VolumeCondition.isValid())
			return 0;
		if (! MinVolume.isValid())
			return 0;
		if (! ContingentCondition.isValid())
			return 0;
		if (! StopPrice.isValid())
			return 0;
		if (! ForceCloseReason.isValid())
			return 0;
		if (! OrderLocalID.isValid())
			return 0;
		if (! IsAutoSuspend.isValid())
			return 0;
		if (! OrderSource.isValid())
			return 0;
		if (! OrderStatus.isValid())
			return 0;
		if (! OrderType.isValid())
			return 0;
		if (! VolumeTraded.isValid())
			return 0;
		if (! VolumeTotal.isValid())
			return 0;
		if (! InsertDate.isValid())
			return 0;
		if (! InsertTime.isValid())
			return 0;
		if (! ActiveTime.isValid())
			return 0;
		if (! SuspendTime.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		if (! CancelTime.isValid())
			return 0;
		if (! ActiveUserID.isValid())
			return 0;
		if (! Priority.isValid())
			return 0;
		if (! TimeSortID.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableRemainOrder *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///是否可以参加交易
	CBoolType Tradable;
	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///报单编号
	COrderSysIDType OrderSysID;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
	///交易用户代码
	CUserIDType UserID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///报单价格条件
	COrderPriceTypeType OrderPriceType;
	///买卖方向
	CDirectionType Direction;
	///组合开平标志
	CCombOffsetFlagType CombOffsetFlag;
	///组合投机套保标志
	CCombHedgeFlagType CombHedgeFlag;
	///价格
	CPriceType LimitPrice;
	///数量
	CVolumeType VolumeTotalOriginal;
	///有效期类型
	CTimeConditionType TimeCondition;
	///GTD日期
	CDateType GTDDate;
	///成交量类型
	CVolumeConditionType VolumeCondition;
	///最小成交量
	CVolumeType MinVolume;
	///触发条件
	CContingentConditionType ContingentCondition;
	///止损价
	CPriceType StopPrice;
	///强平原因
	CForceCloseReasonType ForceCloseReason;
	///本地报单编号
	COrderLocalIDType OrderLocalID;
	///自动挂起标志
	CBoolType IsAutoSuspend;
	///报单来源
	COrderSourceType OrderSource;
	///报单状态
	COrderStatusType OrderStatus;
	///报单类型
	COrderTypeType OrderType;
	///今成交数量
	CVolumeType VolumeTraded;
	///剩余数量
	CVolumeType VolumeTotal;
	///报单日期
	CDateType InsertDate;
	///插入时间
	CTimeType InsertTime;
	///激活时间
	CTimeType ActiveTime;
	///挂起时间
	CTimeType SuspendTime;
	///最后修改时间
	CTimeType UpdateTime;
	///撤销时间
	CTimeType CancelTime;
	///最后修改交易用户代码
	CUserIDType ActiveUserID;
	///优先权
	CPriorityType Priority;
	///按时间排队的序号
	CTimeSortIDType TimeSortID;
	///结算会员编号
	CParticipantIDType ClearingPartID;
	///业务单元
	CBusinessUnitType BusinessUnit;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableRemainOrder CRemainOrder;

/////////////////////////////////////////////////////////////////////////
///CRemainOrderActionTrigger是操作历史报单时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderActionTrigger
{
public:
	///构造方法
	CRemainOrderActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CRemainOrderActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CRemainOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pRemainOrder	要加入的RemainOrder
	virtual void beforeAdd(CWriteableRemainOrder *pRemainOrder)
	{
		return;
	}
	
	///加入后触发
	///@param	pRemainOrder	已经加入的RemainOrder
	virtual void afterAdd(CRemainOrder *pRemainOrder)
	{
		return;
	}

	///更新前触发	
	///@param	pRemainOrder	被刷新的CRemainOrder
	///@param	pNewRemainOrder	新的值
	virtual void beforeUpdate(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pNewRemainOrder)
	{
		return;
	}
	
	///更新后触发
	///@param	pRemainOrder	被刷新的CRemainOrder
	virtual void afterUpdate(CRemainOrder *pRemainOrder)
	{
		return;
	}
	
	///删除前触发
	///@param	pRemainOrder	要删除的CRemainOrder
	virtual void beforeRemove(CRemainOrder *pRemainOrder)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CRemainOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderCommitTrigger是确认历史报单时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderCommitTrigger
{
public:
	///构造方法
	CRemainOrderCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CRemainOrderCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CRemainOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pRemainOrder	已经加入的RemainOrder
	virtual void commitAdd(CRemainOrder *pRemainOrder)
	{
		return;
	}

	///更新后触发
	///@param	pRemainOrder	被刷新的CRemainOrder
	///@param	poldRemainOrder	原来的值
	virtual void commitUpdate(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pOldRemainOrder)
	{
		return;
	}
	
	///删除后触发
	///@param	pRemainOrder	已经删除的CRemainOrder
	virtual void commitRemove(CWriteableRemainOrder *pRemainOrder)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CRemainOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderIterator是一个对历史报单的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderIterator
{
public:
	///构造方法
	CRemainOrderIterator(void)
	{
	}

	///构造方法
	CRemainOrderIterator(CRemainOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CRemainOrderIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个RemainOrder
	///@return	下一个满足条件CRemainOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CRemainOrder *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CRemainOrderFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pRemainOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRemainOrder * pRemainOrder,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CRemainOrderFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMarketData是一个存储行情的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMarketData
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! LastPrice.isValid())
			return 0;
		if (! PreSettlementPrice.isValid())
			return 0;
		if (! PreClosePrice.isValid())
			return 0;
		if (! PreOpenInterest.isValid())
			return 0;
		if (! OpenPrice.isValid())
			return 0;
		if (! HighestPrice.isValid())
			return 0;
		if (! LowestPrice.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! Turnover.isValid())
			return 0;
		if (! OpenInterest.isValid())
			return 0;
		if (! ClosePrice.isValid())
			return 0;
		if (! SettlementPrice.isValid())
			return 0;
		if (! UpperLimitPrice.isValid())
			return 0;
		if (! LowerLimitPrice.isValid())
			return 0;
		if (! PreDelta.isValid())
			return 0;
		if (! CurrDelta.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		if (! UpdateMillisec.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! TID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableMarketData *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///最新价
	CPriceType LastPrice;
	///昨结算
	CPriceType PreSettlementPrice;
	///昨收盘
	CPriceType PreClosePrice;
	///昨持仓量
	CLargeVolumeType PreOpenInterest;
	///今开盘
	CPriceType OpenPrice;
	///最高价
	CPriceType HighestPrice;
	///最低价
	CPriceType LowestPrice;
	///数量
	CVolumeType Volume;
	///成交金额
	CMoneyType Turnover;
	///持仓量
	CLargeVolumeType OpenInterest;
	///今收盘
	CPriceType ClosePrice;
	///今结算
	CPriceType SettlementPrice;
	///涨停板价
	CPriceType UpperLimitPrice;
	///跌停板价
	CPriceType LowerLimitPrice;
	///昨虚实度
	CRatioType PreDelta;
	///今虚实度
	CRatioType CurrDelta;
	///最后修改时间
	CTimeType UpdateTime;
	///最后修改毫秒
	CMillisecType UpdateMillisec;
	///合约代码
	CInstrumentIDType InstrumentID;
	///序列号
	CSequenceNoType TID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMarketData CMarketData;

/////////////////////////////////////////////////////////////////////////
///CMarketDataActionTrigger是操作行情时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataActionTrigger
{
public:
	///构造方法
	CMarketDataActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMarketDataActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pMarketData	要加入的MarketData
	virtual void beforeAdd(CWriteableMarketData *pMarketData)
	{
		return;
	}
	
	///加入后触发
	///@param	pMarketData	已经加入的MarketData
	virtual void afterAdd(CMarketData *pMarketData)
	{
		return;
	}

	///更新前触发	
	///@param	pMarketData	被刷新的CMarketData
	///@param	pNewMarketData	新的值
	virtual void beforeUpdate(CMarketData *pMarketData, CWriteableMarketData *pNewMarketData)
	{
		return;
	}
	
	///更新后触发
	///@param	pMarketData	被刷新的CMarketData
	virtual void afterUpdate(CMarketData *pMarketData)
	{
		return;
	}
	
	///删除前触发
	///@param	pMarketData	要删除的CMarketData
	virtual void beforeRemove(CMarketData *pMarketData)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMarketDataFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataCommitTrigger是确认行情时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataCommitTrigger
{
public:
	///构造方法
	CMarketDataCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMarketDataCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pMarketData	已经加入的MarketData
	virtual void commitAdd(CMarketData *pMarketData)
	{
		return;
	}

	///更新后触发
	///@param	pMarketData	被刷新的CMarketData
	///@param	poldMarketData	原来的值
	virtual void commitUpdate(CMarketData *pMarketData, CWriteableMarketData *pOldMarketData)
	{
		return;
	}
	
	///删除后触发
	///@param	pMarketData	已经删除的CMarketData
	virtual void commitRemove(CWriteableMarketData *pMarketData)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMarketDataFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataIterator是一个对行情的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataIterator
{
public:
	///构造方法
	CMarketDataIterator(void)
	{
	}

	///构造方法
	CMarketDataIterator(CMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CMarketDataIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个MarketData
	///@return	下一个满足条件CMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketData *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CMarketDataFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketData * pMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CMarketDataFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableClearingPartPosition是一个存储结算会员持仓的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableClearingPartPosition
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! HedgeFlag.isValid())
			return 0;
		if (! PosiDirection.isValid())
			return 0;
		if (! YdPosition.isValid())
			return 0;
		if (! Position.isValid())
			return 0;
		if (! LongFrozen.isValid())
			return 0;
		if (! ShortFrozen.isValid())
			return 0;
		if (! YdLongFrozen.isValid())
			return 0;
		if (! YdShortFrozen.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableClearingPartPosition *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///投机套保标志
	CHedgeFlagType HedgeFlag;
	///持仓多空方向
	CPosiDirectionType PosiDirection;
	///上日持仓
	CVolumeType YdPosition;
	///今日持仓
	CVolumeType Position;
	///多头冻结
	CVolumeType LongFrozen;
	///空头冻结
	CVolumeType ShortFrozen;
	///昨日多头冻结
	CVolumeType YdLongFrozen;
	///昨日空头冻结
	CVolumeType YdShortFrozen;
	///合约代码
	CInstrumentIDType InstrumentID;
	///会员代码
	CParticipantIDType ParticipantID;
	///交易角色
	CTradingRoleType TradingRole;
	unsigned int HashPartAndInstrument;
	
	///计算PartAndInstrument的hash值
	void calHashPartAndInstrument(void)
	{
		unsigned key=0;
		key=InstrumentID.hash(key);
		key=PosiDirection.hash(key);
		key=HedgeFlag.hash(key);
		key=ParticipantID.hash(key);
		key=TradingRole.hash(key);
		HashPartAndInstrument=key;
	}
	
	///根据需要情况，更新PartAndInstrument的hash值
	void updateHashPartAndInstrument(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashPartAndInstrument();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashPartAndInstrument();
	}
	

private:
};

typedef const CWriteableClearingPartPosition CClearingPartPosition;

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionActionTrigger是操作结算会员持仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionActionTrigger
{
public:
	///构造方法
	CClearingPartPositionActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CClearingPartPositionActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CClearingPartPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pClearingPartPosition	要加入的ClearingPartPosition
	virtual void beforeAdd(CWriteableClearingPartPosition *pClearingPartPosition)
	{
		return;
	}
	
	///加入后触发
	///@param	pClearingPartPosition	已经加入的ClearingPartPosition
	virtual void afterAdd(CClearingPartPosition *pClearingPartPosition)
	{
		return;
	}

	///更新前触发	
	///@param	pClearingPartPosition	被刷新的CClearingPartPosition
	///@param	pNewClearingPartPosition	新的值
	virtual void beforeUpdate(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pNewClearingPartPosition)
	{
		return;
	}
	
	///更新后触发
	///@param	pClearingPartPosition	被刷新的CClearingPartPosition
	virtual void afterUpdate(CClearingPartPosition *pClearingPartPosition)
	{
		return;
	}
	
	///删除前触发
	///@param	pClearingPartPosition	要删除的CClearingPartPosition
	virtual void beforeRemove(CClearingPartPosition *pClearingPartPosition)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CClearingPartPositionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionCommitTrigger是确认结算会员持仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionCommitTrigger
{
public:
	///构造方法
	CClearingPartPositionCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CClearingPartPositionCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CClearingPartPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pClearingPartPosition	已经加入的ClearingPartPosition
	virtual void commitAdd(CClearingPartPosition *pClearingPartPosition)
	{
		return;
	}

	///更新后触发
	///@param	pClearingPartPosition	被刷新的CClearingPartPosition
	///@param	poldClearingPartPosition	原来的值
	virtual void commitUpdate(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pOldClearingPartPosition)
	{
		return;
	}
	
	///删除后触发
	///@param	pClearingPartPosition	已经删除的CClearingPartPosition
	virtual void commitRemove(CWriteableClearingPartPosition *pClearingPartPosition)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CClearingPartPositionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionIterator是一个对结算会员持仓的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionIterator
{
public:
	///构造方法
	CClearingPartPositionIterator(void)
	{
	}

	///构造方法
	CClearingPartPositionIterator(CClearingPartPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CClearingPartPositionIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个ClearingPartPosition
	///@return	下一个满足条件CClearingPartPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CClearingPartPosition *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CClearingPartPositionFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pClearingPartPosition 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClearingPartPosition * pClearingPartPosition,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CClearingPartPositionFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableInstrumentStatus是一个存储合约状态的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableInstrumentStatus
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! InstrumentStatus.isValid())
			return 0;
		if (! TradingSegmentSN.isValid())
			return 0;
		if (! EnterTime.isValid())
			return 0;
		if (! EnterReason.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableInstrumentStatus *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///合约交易状态
	CInstrumentStatusType InstrumentStatus;
	///交易阶段编号
	CTradingSegmentSNType TradingSegmentSN;
	///进入本状态时间
	CTimeType EnterTime;
	///进入本状态原因
	CInstStatusEnterReasonType EnterReason;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	
	///构造对应的合约的指针
	///@param	pFactory	构造对应的合约的指针时，寻找的对象工厂
	///@return	找到的对应的合约的指针，如果找不到则返回NULL
	inline const CWriteableInstrument *linkInstrument(CInstrumentFactory *pFactory) const;

	///构造对应的合约指针
	///@param	pInstrument	要连接到的对象
	///@return	输入的pInstrument
	const CWriteableInstrument *linkInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///获取对应的合约的指针
	///@return	找到的对应的合约的指针，如果找不到则返回NULL
	const CWriteableInstrument *getInstrument(void) const
	{
		return pInstrument;
	}
	///构造对应的价格绑定的指针
	///@param	pFactory	构造对应的价格绑定的指针时，寻找的对象工厂
	///@return	找到的对应的价格绑定的指针，如果找不到则返回NULL
	inline const CWriteableCurrPriceBanding *linkCurrPriceBanding(CCurrPriceBandingFactory *pFactory) const;

	///构造对应的价格绑定指针
	///@param	pCurrPriceBanding	要连接到的对象
	///@return	输入的pCurrPriceBanding
	const CWriteableCurrPriceBanding *linkCurrPriceBanding(const CWriteableCurrPriceBanding *pCurrPriceBanding) const
	{
		void *target=(void *)(&(this->pCurrPriceBanding));
		*((const CWriteableCurrPriceBanding **)target)=pCurrPriceBanding;
		return pCurrPriceBanding;
	}
	
	///获取对应的价格绑定的指针
	///@return	找到的对应的价格绑定的指针，如果找不到则返回NULL
	const CWriteableCurrPriceBanding *getCurrPriceBanding(void) const
	{
		return pCurrPriceBanding;
	}
	///构造对应的行情发布状态的指针
	///@param	pFactory	构造对应的行情发布状态的指针时，寻找的对象工厂
	///@return	找到的对应的行情发布状态的指针，如果找不到则返回NULL
	inline const CWriteableMdPubStatus *linkMdPubStatus(CMdPubStatusFactory *pFactory) const;

	///构造对应的行情发布状态指针
	///@param	pMdPubStatus	要连接到的对象
	///@return	输入的pMdPubStatus
	const CWriteableMdPubStatus *linkMdPubStatus(const CWriteableMdPubStatus *pMdPubStatus) const
	{
		void *target=(void *)(&(this->pMdPubStatus));
		*((const CWriteableMdPubStatus **)target)=pMdPubStatus;
		return pMdPubStatus;
	}
	
	///获取对应的行情发布状态的指针
	///@return	找到的对应的行情发布状态的指针，如果找不到则返回NULL
	const CWriteableMdPubStatus *getMdPubStatus(void) const
	{
		return pMdPubStatus;
	}

private:
	///对应的合约
	const CWriteableInstrument *pInstrument;
	///对应的价格绑定
	const CWriteableCurrPriceBanding *pCurrPriceBanding;
	///对应的行情发布状态
	const CWriteableMdPubStatus *pMdPubStatus;
};

typedef const CWriteableInstrumentStatus CInstrumentStatus;

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusActionTrigger是操作合约状态时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusActionTrigger
{
public:
	///构造方法
	CInstrumentStatusActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CInstrumentStatusActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CInstrumentStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pInstrumentStatus	要加入的InstrumentStatus
	virtual void beforeAdd(CWriteableInstrumentStatus *pInstrumentStatus)
	{
		return;
	}
	
	///加入后触发
	///@param	pInstrumentStatus	已经加入的InstrumentStatus
	virtual void afterAdd(CInstrumentStatus *pInstrumentStatus)
	{
		return;
	}

	///更新前触发	
	///@param	pInstrumentStatus	被刷新的CInstrumentStatus
	///@param	pNewInstrumentStatus	新的值
	virtual void beforeUpdate(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pNewInstrumentStatus)
	{
		return;
	}
	
	///更新后触发
	///@param	pInstrumentStatus	被刷新的CInstrumentStatus
	virtual void afterUpdate(CInstrumentStatus *pInstrumentStatus)
	{
		return;
	}
	
	///删除前触发
	///@param	pInstrumentStatus	要删除的CInstrumentStatus
	virtual void beforeRemove(CInstrumentStatus *pInstrumentStatus)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CInstrumentStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusCommitTrigger是确认合约状态时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusCommitTrigger
{
public:
	///构造方法
	CInstrumentStatusCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CInstrumentStatusCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CInstrumentStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pInstrumentStatus	已经加入的InstrumentStatus
	virtual void commitAdd(CInstrumentStatus *pInstrumentStatus)
	{
		return;
	}

	///更新后触发
	///@param	pInstrumentStatus	被刷新的CInstrumentStatus
	///@param	poldInstrumentStatus	原来的值
	virtual void commitUpdate(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pOldInstrumentStatus)
	{
		return;
	}
	
	///删除后触发
	///@param	pInstrumentStatus	已经删除的CInstrumentStatus
	virtual void commitRemove(CWriteableInstrumentStatus *pInstrumentStatus)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CInstrumentStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusIterator是一个对合约状态的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusIterator
{
public:
	///构造方法
	CInstrumentStatusIterator(void)
	{
	}

	///构造方法
	CInstrumentStatusIterator(CInstrumentStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CInstrumentStatusIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个InstrumentStatus
	///@return	下一个满足条件CInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrumentStatus *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CInstrumentStatusFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pInstrumentStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrumentStatus * pInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CInstrumentStatusFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableOrder是一个存储报单的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableOrder
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! OrderSysID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! OrderPriceType.isValid())
			return 0;
		if (! Direction.isValid())
			return 0;
		if (! CombOffsetFlag.isValid())
			return 0;
		if (! CombHedgeFlag.isValid())
			return 0;
		if (! LimitPrice.isValid())
			return 0;
		if (! VolumeTotalOriginal.isValid())
			return 0;
		if (! TimeCondition.isValid())
			return 0;
		if (! GTDDate.isValid())
			return 0;
		if (! VolumeCondition.isValid())
			return 0;
		if (! MinVolume.isValid())
			return 0;
		if (! ContingentCondition.isValid())
			return 0;
		if (! StopPrice.isValid())
			return 0;
		if (! ForceCloseReason.isValid())
			return 0;
		if (! OrderLocalID.isValid())
			return 0;
		if (! IsAutoSuspend.isValid())
			return 0;
		if (! OrderSource.isValid())
			return 0;
		if (! OrderStatus.isValid())
			return 0;
		if (! OrderType.isValid())
			return 0;
		if (! VolumeTraded.isValid())
			return 0;
		if (! VolumeTotal.isValid())
			return 0;
		if (! InsertDate.isValid())
			return 0;
		if (! InsertTime.isValid())
			return 0;
		if (! ActiveTime.isValid())
			return 0;
		if (! SuspendTime.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		if (! CancelTime.isValid())
			return 0;
		if (! ActiveUserID.isValid())
			return 0;
		if (! Priority.isValid())
			return 0;
		if (! TimeSortID.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! Tradable.isValid())
			return 0;
		if (! ImplySortID.isValid())
			return 0;
		if (! TID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableOrder *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///报单编号
	COrderSysIDType OrderSysID;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
	///交易用户代码
	CUserIDType UserID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///报单价格条件
	COrderPriceTypeType OrderPriceType;
	///买卖方向
	CDirectionType Direction;
	///组合开平标志
	CCombOffsetFlagType CombOffsetFlag;
	///组合投机套保标志
	CCombHedgeFlagType CombHedgeFlag;
	///价格
	CPriceType LimitPrice;
	///数量
	CVolumeType VolumeTotalOriginal;
	///有效期类型
	CTimeConditionType TimeCondition;
	///GTD日期
	CDateType GTDDate;
	///成交量类型
	CVolumeConditionType VolumeCondition;
	///最小成交量
	CVolumeType MinVolume;
	///触发条件
	CContingentConditionType ContingentCondition;
	///止损价
	CPriceType StopPrice;
	///强平原因
	CForceCloseReasonType ForceCloseReason;
	///本地报单编号
	COrderLocalIDType OrderLocalID;
	///自动挂起标志
	CBoolType IsAutoSuspend;
	///报单来源
	COrderSourceType OrderSource;
	///报单状态
	COrderStatusType OrderStatus;
	///报单类型
	COrderTypeType OrderType;
	///今成交数量
	CVolumeType VolumeTraded;
	///剩余数量
	CVolumeType VolumeTotal;
	///报单日期
	CDateType InsertDate;
	///插入时间
	CTimeType InsertTime;
	///激活时间
	CTimeType ActiveTime;
	///挂起时间
	CTimeType SuspendTime;
	///最后修改时间
	CTimeType UpdateTime;
	///撤销时间
	CTimeType CancelTime;
	///最后修改交易用户代码
	CUserIDType ActiveUserID;
	///优先权
	CPriorityType Priority;
	///按时间排队的序号
	CTimeSortIDType TimeSortID;
	///结算会员编号
	CParticipantIDType ClearingPartID;
	///业务单元
	CBusinessUnitType BusinessUnit;
	///是否可以参加交易
	CBoolType Tradable;
	///隐式推导时的次序
	CTimeSortIDType ImplySortID;
	///序列号
	CSequenceNoType TID;
	unsigned int HashOrderSysID;
	
	///计算OrderSysID的hash值
	void calHashOrderSysID(void)
	{
		unsigned key=0;
		key=OrderSysID.hash(key);
		HashOrderSysID=key;
	}
	
	///根据需要情况，更新OrderSysID的hash值
	void updateHashOrderSysID(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashOrderSysID();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashOrderSysID();
	}
	
	///构造对应的合约的指针
	///@param	pFactory	构造对应的合约的指针时，寻找的对象工厂
	///@return	找到的对应的合约的指针，如果找不到则返回NULL
	inline const CWriteableInstrument *linkInstrument(CInstrumentFactory *pFactory) const;

	///构造对应的合约指针
	///@param	pInstrument	要连接到的对象
	///@return	输入的pInstrument
	const CWriteableInstrument *linkInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///获取对应的合约的指针
	///@return	找到的对应的合约的指针，如果找不到则返回NULL
	const CWriteableInstrument *getInstrument(void) const
	{
		return pInstrument;
	}
	///构造指定的会员客户的指针
	///@param	pFactory	构造指定的会员客户的指针时，寻找的对象工厂
	///@return	找到的指定的会员客户的指针，如果找不到则返回NULL
	inline const CWriteablePartClient *linkPartClient(CPartClientFactory *pFactory) const;

	///构造指定的会员客户指针
	///@param	pPartClient	要连接到的对象
	///@return	输入的pPartClient
	const CWriteablePartClient *linkPartClient(const CWriteablePartClient *pPartClient) const
	{
		void *target=(void *)(&(this->pPartClient));
		*((const CWriteablePartClient **)target)=pPartClient;
		return pPartClient;
	}
	
	///获取指定的会员客户的指针
	///@return	找到的指定的会员客户的指针，如果找不到则返回NULL
	const CWriteablePartClient *getPartClient(void) const
	{
		return pPartClient;
	}
	///构造对应的客户持仓的指针
	///@param	pFactory	构造对应的客户持仓的指针时，寻找的对象工厂
	///@return	找到的对应的客户持仓的指针，如果找不到则返回NULL
	inline const CWriteableClientPosition *linkClientPosition(CClientPositionFactory *pFactory) const;

	///构造对应的客户持仓指针
	///@param	pClientPosition	要连接到的对象
	///@return	输入的pClientPosition
	const CWriteableClientPosition *linkClientPosition(const CWriteableClientPosition *pClientPosition) const
	{
		void *target=(void *)(&(this->pClientPosition));
		*((const CWriteableClientPosition **)target)=pClientPosition;
		return pClientPosition;
	}
	
	///获取对应的客户持仓的指针
	///@return	找到的对应的客户持仓的指针，如果找不到则返回NULL
	const CWriteableClientPosition *getClientPosition(void) const
	{
		return pClientPosition;
	}

private:
	///对应的合约
	const CWriteableInstrument *pInstrument;
	///指定的会员客户
	const CWriteablePartClient *pPartClient;
	///对应的客户持仓
	const CWriteableClientPosition *pClientPosition;
};

typedef const CWriteableOrder COrder;

/////////////////////////////////////////////////////////////////////////
///COrderActionTrigger是操作报单时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderActionTrigger
{
public:
	///构造方法
	COrderActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~COrderActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(COrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pOrder	要加入的Order
	virtual void beforeAdd(CWriteableOrder *pOrder)
	{
		return;
	}
	
	///加入后触发
	///@param	pOrder	已经加入的Order
	virtual void afterAdd(COrder *pOrder)
	{
		return;
	}

	///更新前触发	
	///@param	pOrder	被刷新的COrder
	///@param	pNewOrder	新的值
	virtual void beforeUpdate(COrder *pOrder, CWriteableOrder *pNewOrder)
	{
		return;
	}
	
	///更新后触发
	///@param	pOrder	被刷新的COrder
	virtual void afterUpdate(COrder *pOrder)
	{
		return;
	}
	
	///删除前触发
	///@param	pOrder	要删除的COrder
	virtual void beforeRemove(COrder *pOrder)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	COrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///COrderCommitTrigger是确认报单时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCommitTrigger
{
public:
	///构造方法
	COrderCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~COrderCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(COrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pOrder	已经加入的Order
	virtual void commitAdd(COrder *pOrder)
	{
		return;
	}

	///更新后触发
	///@param	pOrder	被刷新的COrder
	///@param	poldOrder	原来的值
	virtual void commitUpdate(COrder *pOrder, CWriteableOrder *pOldOrder)
	{
		return;
	}
	
	///删除后触发
	///@param	pOrder	已经删除的COrder
	virtual void commitRemove(CWriteableOrder *pOrder)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	COrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///COrderIterator是一个对报单的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderIterator
{
public:
	///构造方法
	COrderIterator(void)
	{
	}

	///构造方法
	COrderIterator(COrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~COrderIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个Order
	///@return	下一个满足条件COrder，如果已经没有一个满足要求了，则返回NULL
	virtual COrder *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	COrderFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOrder * pOrder,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	COrderFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCombOrder是一个存储组合报单的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCombOrder
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! CombOrderSysID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! LimitPrice.isValid())
			return 0;
		if (! VolumeTotalOriginal.isValid())
			return 0;
		if (! CombOrderLocalID.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! InstrumentID1.isValid())
			return 0;
		if (! Direction1.isValid())
			return 0;
		if (! LegMultiple1.isValid())
			return 0;
		if (! OffsetFlag1.isValid())
			return 0;
		if (! HedgeFlag1.isValid())
			return 0;
		if (! InstrumentID2.isValid())
			return 0;
		if (! Direction2.isValid())
			return 0;
		if (! LegMultiple2.isValid())
			return 0;
		if (! OffsetFlag2.isValid())
			return 0;
		if (! HedgeFlag2.isValid())
			return 0;
		if (! InstrumentID3.isValid())
			return 0;
		if (! Direction3.isValid())
			return 0;
		if (! LegMultiple3.isValid())
			return 0;
		if (! OffsetFlag3.isValid())
			return 0;
		if (! HedgeFlag3.isValid())
			return 0;
		if (! InstrumentID4.isValid())
			return 0;
		if (! Direction4.isValid())
			return 0;
		if (! LegMultiple4.isValid())
			return 0;
		if (! OffsetFlag4.isValid())
			return 0;
		if (! HedgeFlag4.isValid())
			return 0;
		if (! OrderSource.isValid())
			return 0;
		if (! VolumeTraded.isValid())
			return 0;
		if (! VolumeTotal.isValid())
			return 0;
		if (! InsertDate.isValid())
			return 0;
		if (! InsertTime.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCombOrder *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///组合报单编号
	COrderSysIDType CombOrderSysID;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
	///交易用户代码
	CUserIDType UserID;
	///价格
	CPriceType LimitPrice;
	///数量
	CVolumeType VolumeTotalOriginal;
	///本地报单编号
	COrderLocalIDType CombOrderLocalID;
	///业务单元
	CBusinessUnitType BusinessUnit;
	///合约代码1
	CInstrumentIDType InstrumentID1;
	///买卖方向1
	CDirectionType Direction1;
	///分腿乘数1
	CLegMultipleType LegMultiple1;
	///开平标志1
	COffsetFlagType OffsetFlag1;
	///投机套保标志1
	CHedgeFlagType HedgeFlag1;
	///合约代码2
	CInstrumentIDType InstrumentID2;
	///买卖方向2
	CDirectionType Direction2;
	///分腿乘数2
	CLegMultipleType LegMultiple2;
	///开平标志2
	COffsetFlagType OffsetFlag2;
	///投机套保标志2
	CHedgeFlagType HedgeFlag2;
	///合约代码3
	CInstrumentIDType InstrumentID3;
	///买卖方向3
	CDirectionType Direction3;
	///分腿乘数3
	CLegMultipleType LegMultiple3;
	///开平标志3
	COffsetFlagType OffsetFlag3;
	///投机套保标志3
	CHedgeFlagType HedgeFlag3;
	///合约代码4
	CInstrumentIDType InstrumentID4;
	///买卖方向4
	CDirectionType Direction4;
	///分腿乘数4
	CLegMultipleType LegMultiple4;
	///开平标志4
	COffsetFlagType OffsetFlag4;
	///投机套保标志4
	CHedgeFlagType HedgeFlag4;
	///报单来源
	COrderSourceType OrderSource;
	///今成交数量
	CVolumeType VolumeTraded;
	///剩余数量
	CVolumeType VolumeTotal;
	///报单日期
	CDateType InsertDate;
	///插入时间
	CTimeType InsertTime;
	///结算会员编号
	CParticipantIDType ClearingPartID;
	unsigned int HashCombOrderSysID;
	
	///计算CombOrderSysID的hash值
	void calHashCombOrderSysID(void)
	{
		unsigned key=0;
		key=CombOrderSysID.hash(key);
		HashCombOrderSysID=key;
	}
	
	///根据需要情况，更新CombOrderSysID的hash值
	void updateHashCombOrderSysID(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashCombOrderSysID();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashCombOrderSysID();
	}
	
	///构造指定的会员客户的指针
	///@param	pFactory	构造指定的会员客户的指针时，寻找的对象工厂
	///@return	找到的指定的会员客户的指针，如果找不到则返回NULL
	inline const CWriteablePartClient *linkPartClient(CPartClientFactory *pFactory) const;

	///构造指定的会员客户指针
	///@param	pPartClient	要连接到的对象
	///@return	输入的pPartClient
	const CWriteablePartClient *linkPartClient(const CWriteablePartClient *pPartClient) const
	{
		void *target=(void *)(&(this->pPartClient));
		*((const CWriteablePartClient **)target)=pPartClient;
		return pPartClient;
	}
	
	///获取指定的会员客户的指针
	///@return	找到的指定的会员客户的指针，如果找不到则返回NULL
	const CWriteablePartClient *getPartClient(void) const
	{
		return pPartClient;
	}
	///构造对应的合约1的指针
	///@param	pFactory	构造对应的合约1的指针时，寻找的对象工厂
	///@return	找到的对应的合约1的指针，如果找不到则返回NULL
	inline const CWriteableInstrument *linkInstrument1(CInstrumentFactory *pFactory) const;

	///构造对应的合约1指针
	///@param	pInstrument	要连接到的对象
	///@return	输入的pInstrument
	const CWriteableInstrument *linkInstrument1(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument1));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///获取对应的合约1的指针
	///@return	找到的对应的合约1的指针，如果找不到则返回NULL
	const CWriteableInstrument *getInstrument1(void) const
	{
		return pInstrument1;
	}
	///构造对应的合约2的指针
	///@param	pFactory	构造对应的合约2的指针时，寻找的对象工厂
	///@return	找到的对应的合约2的指针，如果找不到则返回NULL
	inline const CWriteableInstrument *linkInstrument2(CInstrumentFactory *pFactory) const;

	///构造对应的合约2指针
	///@param	pInstrument	要连接到的对象
	///@return	输入的pInstrument
	const CWriteableInstrument *linkInstrument2(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument2));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///获取对应的合约2的指针
	///@return	找到的对应的合约2的指针，如果找不到则返回NULL
	const CWriteableInstrument *getInstrument2(void) const
	{
		return pInstrument2;
	}
	///构造对应的合约3的指针
	///@param	pFactory	构造对应的合约3的指针时，寻找的对象工厂
	///@return	找到的对应的合约3的指针，如果找不到则返回NULL
	inline const CWriteableInstrument *linkInstrument3(CInstrumentFactory *pFactory) const;

	///构造对应的合约3指针
	///@param	pInstrument	要连接到的对象
	///@return	输入的pInstrument
	const CWriteableInstrument *linkInstrument3(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument3));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///获取对应的合约3的指针
	///@return	找到的对应的合约3的指针，如果找不到则返回NULL
	const CWriteableInstrument *getInstrument3(void) const
	{
		return pInstrument3;
	}
	///构造对应的合约4的指针
	///@param	pFactory	构造对应的合约4的指针时，寻找的对象工厂
	///@return	找到的对应的合约4的指针，如果找不到则返回NULL
	inline const CWriteableInstrument *linkInstrument4(CInstrumentFactory *pFactory) const;

	///构造对应的合约4指针
	///@param	pInstrument	要连接到的对象
	///@return	输入的pInstrument
	const CWriteableInstrument *linkInstrument4(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument4));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///获取对应的合约4的指针
	///@return	找到的对应的合约4的指针，如果找不到则返回NULL
	const CWriteableInstrument *getInstrument4(void) const
	{
		return pInstrument4;
	}

private:
	///指定的会员客户
	const CWriteablePartClient *pPartClient;
	///对应的合约1
	const CWriteableInstrument *pInstrument1;
	///对应的合约2
	const CWriteableInstrument *pInstrument2;
	///对应的合约3
	const CWriteableInstrument *pInstrument3;
	///对应的合约4
	const CWriteableInstrument *pInstrument4;
};

typedef const CWriteableCombOrder CCombOrder;

/////////////////////////////////////////////////////////////////////////
///CCombOrderActionTrigger是操作组合报单时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderActionTrigger
{
public:
	///构造方法
	CCombOrderActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCombOrderActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCombOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCombOrder	要加入的CombOrder
	virtual void beforeAdd(CWriteableCombOrder *pCombOrder)
	{
		return;
	}
	
	///加入后触发
	///@param	pCombOrder	已经加入的CombOrder
	virtual void afterAdd(CCombOrder *pCombOrder)
	{
		return;
	}

	///更新前触发	
	///@param	pCombOrder	被刷新的CCombOrder
	///@param	pNewCombOrder	新的值
	virtual void beforeUpdate(CCombOrder *pCombOrder, CWriteableCombOrder *pNewCombOrder)
	{
		return;
	}
	
	///更新后触发
	///@param	pCombOrder	被刷新的CCombOrder
	virtual void afterUpdate(CCombOrder *pCombOrder)
	{
		return;
	}
	
	///删除前触发
	///@param	pCombOrder	要删除的CCombOrder
	virtual void beforeRemove(CCombOrder *pCombOrder)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCombOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderCommitTrigger是确认组合报单时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderCommitTrigger
{
public:
	///构造方法
	CCombOrderCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCombOrderCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCombOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCombOrder	已经加入的CombOrder
	virtual void commitAdd(CCombOrder *pCombOrder)
	{
		return;
	}

	///更新后触发
	///@param	pCombOrder	被刷新的CCombOrder
	///@param	poldCombOrder	原来的值
	virtual void commitUpdate(CCombOrder *pCombOrder, CWriteableCombOrder *pOldCombOrder)
	{
		return;
	}
	
	///删除后触发
	///@param	pCombOrder	已经删除的CCombOrder
	virtual void commitRemove(CWriteableCombOrder *pCombOrder)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCombOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderIterator是一个对组合报单的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderIterator
{
public:
	///构造方法
	CCombOrderIterator(void)
	{
	}

	///构造方法
	CCombOrderIterator(CCombOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCombOrderIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CombOrder
	///@return	下一个满足条件CCombOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CCombOrder *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCombOrderFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCombOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCombOrder * pCombOrder,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCombOrderFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableOTCOrder是一个存储OTC报单的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableOTCOrder
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! OTCOrderSysID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! Direction.isValid())
			return 0;
		if (! OffsetFlag.isValid())
			return 0;
		if (! HedgeFlag.isValid())
			return 0;
		if (! Price.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! OtherParticipantID.isValid())
			return 0;
		if (! OtherClientID.isValid())
			return 0;
		if (! OtherUserID.isValid())
			return 0;
		if (! OtherOffsetFlag.isValid())
			return 0;
		if (! OtherHedgeFlag.isValid())
			return 0;
		if (! OTCOrderLocalID.isValid())
			return 0;
		if (! OTCOrderStatus.isValid())
			return 0;
		if (! InsertTime.isValid())
			return 0;
		if (! CancelTime.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		if (! OtherClearingPartID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableOTCOrder *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///OTC报单编号
	COTCOrderSysIDType OTCOrderSysID;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
	///交易用户代码
	CUserIDType UserID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///买卖方向
	CDirectionType Direction;
	///开平标志
	COffsetFlagType OffsetFlag;
	///投机套保标志
	CHedgeFlagType HedgeFlag;
	///价格
	CPriceType Price;
	///数量
	CVolumeType Volume;
	///对手方会员代码
	CParticipantIDType OtherParticipantID;
	///对手方客户代码
	CClientIDType OtherClientID;
	///对手方交易用户代码
	CUserIDType OtherUserID;
	///对手方开平标志
	COffsetFlagType OtherOffsetFlag;
	///对手方套保标志
	CHedgeFlagType OtherHedgeFlag;
	///本地OTC报单编号
	COrderLocalIDType OTCOrderLocalID;
	///OTC报单状态
	COTCOrderStatusType OTCOrderStatus;
	///插入时间
	CTimeType InsertTime;
	///撤销时间
	CTimeType CancelTime;
	///结算会员编号
	CParticipantIDType ClearingPartID;
	///对手方结算会员编号
	CParticipantIDType OtherClearingPartID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	
	///构造对应的合约的指针
	///@param	pFactory	构造对应的合约的指针时，寻找的对象工厂
	///@return	找到的对应的合约的指针，如果找不到则返回NULL
	inline const CWriteableInstrument *linkInstrument(CInstrumentFactory *pFactory) const;

	///构造对应的合约指针
	///@param	pInstrument	要连接到的对象
	///@return	输入的pInstrument
	const CWriteableInstrument *linkInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///获取对应的合约的指针
	///@return	找到的对应的合约的指针，如果找不到则返回NULL
	const CWriteableInstrument *getInstrument(void) const
	{
		return pInstrument;
	}

private:
	///对应的合约
	const CWriteableInstrument *pInstrument;
};

typedef const CWriteableOTCOrder COTCOrder;

/////////////////////////////////////////////////////////////////////////
///COTCOrderActionTrigger是操作OTC报单时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderActionTrigger
{
public:
	///构造方法
	COTCOrderActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~COTCOrderActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(COTCOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pOTCOrder	要加入的OTCOrder
	virtual void beforeAdd(CWriteableOTCOrder *pOTCOrder)
	{
		return;
	}
	
	///加入后触发
	///@param	pOTCOrder	已经加入的OTCOrder
	virtual void afterAdd(COTCOrder *pOTCOrder)
	{
		return;
	}

	///更新前触发	
	///@param	pOTCOrder	被刷新的COTCOrder
	///@param	pNewOTCOrder	新的值
	virtual void beforeUpdate(COTCOrder *pOTCOrder, CWriteableOTCOrder *pNewOTCOrder)
	{
		return;
	}
	
	///更新后触发
	///@param	pOTCOrder	被刷新的COTCOrder
	virtual void afterUpdate(COTCOrder *pOTCOrder)
	{
		return;
	}
	
	///删除前触发
	///@param	pOTCOrder	要删除的COTCOrder
	virtual void beforeRemove(COTCOrder *pOTCOrder)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	COTCOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderCommitTrigger是确认OTC报单时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderCommitTrigger
{
public:
	///构造方法
	COTCOrderCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~COTCOrderCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(COTCOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pOTCOrder	已经加入的OTCOrder
	virtual void commitAdd(COTCOrder *pOTCOrder)
	{
		return;
	}

	///更新后触发
	///@param	pOTCOrder	被刷新的COTCOrder
	///@param	poldOTCOrder	原来的值
	virtual void commitUpdate(COTCOrder *pOTCOrder, CWriteableOTCOrder *pOldOTCOrder)
	{
		return;
	}
	
	///删除后触发
	///@param	pOTCOrder	已经删除的COTCOrder
	virtual void commitRemove(CWriteableOTCOrder *pOTCOrder)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	COTCOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderIterator是一个对OTC报单的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderIterator
{
public:
	///构造方法
	COTCOrderIterator(void)
	{
	}

	///构造方法
	COTCOrderIterator(COTCOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~COTCOrderIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个OTCOrder
	///@return	下一个满足条件COTCOrder，如果已经没有一个满足要求了，则返回NULL
	virtual COTCOrder *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	COTCOrderFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pOTCOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOTCOrder * pOTCOrder,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	COTCOrderFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableImplyOrder是一个存储隐式报单的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableImplyOrder
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! AnchorOrderID.isValid())
			return 0;
		if (! ImplyOrderID.isValid())
			return 0;
		if (! CombInstrumentID.isValid())
			return 0;
		if (! AnchorLegID.isValid())
			return 0;
		if (! ImplyLegID.isValid())
			return 0;
		if (! Direction.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! Priority.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableImplyOrder *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///锚报单号
	COrderSysIDType AnchorOrderID;
	///派生报单号
	COrderSysIDType ImplyOrderID;
	///组合合约代码
	CInstrumentIDType CombInstrumentID;
	///锚报单单腿编号
	CLegIDType AnchorLegID;
	///派生报单单腿编号
	CLegIDType ImplyLegID;
	///买卖方向
	CDirectionType Direction;
	///数量
	CVolumeType Volume;
	///优先权
	CPriorityType Priority;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableImplyOrder CImplyOrder;

/////////////////////////////////////////////////////////////////////////
///CImplyOrderActionTrigger是操作隐式报单时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderActionTrigger
{
public:
	///构造方法
	CImplyOrderActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CImplyOrderActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CImplyOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pImplyOrder	要加入的ImplyOrder
	virtual void beforeAdd(CWriteableImplyOrder *pImplyOrder)
	{
		return;
	}
	
	///加入后触发
	///@param	pImplyOrder	已经加入的ImplyOrder
	virtual void afterAdd(CImplyOrder *pImplyOrder)
	{
		return;
	}

	///更新前触发	
	///@param	pImplyOrder	被刷新的CImplyOrder
	///@param	pNewImplyOrder	新的值
	virtual void beforeUpdate(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pNewImplyOrder)
	{
		return;
	}
	
	///更新后触发
	///@param	pImplyOrder	被刷新的CImplyOrder
	virtual void afterUpdate(CImplyOrder *pImplyOrder)
	{
		return;
	}
	
	///删除前触发
	///@param	pImplyOrder	要删除的CImplyOrder
	virtual void beforeRemove(CImplyOrder *pImplyOrder)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CImplyOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderCommitTrigger是确认隐式报单时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderCommitTrigger
{
public:
	///构造方法
	CImplyOrderCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CImplyOrderCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CImplyOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pImplyOrder	已经加入的ImplyOrder
	virtual void commitAdd(CImplyOrder *pImplyOrder)
	{
		return;
	}

	///更新后触发
	///@param	pImplyOrder	被刷新的CImplyOrder
	///@param	poldImplyOrder	原来的值
	virtual void commitUpdate(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pOldImplyOrder)
	{
		return;
	}
	
	///删除后触发
	///@param	pImplyOrder	已经删除的CImplyOrder
	virtual void commitRemove(CWriteableImplyOrder *pImplyOrder)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CImplyOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderIterator是一个对隐式报单的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderIterator
{
public:
	///构造方法
	CImplyOrderIterator(void)
	{
	}

	///构造方法
	CImplyOrderIterator(CImplyOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CImplyOrderIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个ImplyOrder
	///@return	下一个满足条件CImplyOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CImplyOrder *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CImplyOrderFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pImplyOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableImplyOrder * pImplyOrder,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CImplyOrderFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableQuote是一个存储报价的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableQuote
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! QuoteSysID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! QuoteLocalID.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! BidCombOffsetFlag.isValid())
			return 0;
		if (! BidCombHedgeFlag.isValid())
			return 0;
		if (! BidPrice.isValid())
			return 0;
		if (! AskCombOffsetFlag.isValid())
			return 0;
		if (! AskCombHedgeFlag.isValid())
			return 0;
		if (! AskPrice.isValid())
			return 0;
		if (! InsertTime.isValid())
			return 0;
		if (! CancelTime.isValid())
			return 0;
		if (! TradeTime.isValid())
			return 0;
		if (! BidOrderSysID.isValid())
			return 0;
		if (! AskOrderSysID.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableQuote *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///报价编号
	CQuoteSysIDType QuoteSysID;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
	///交易用户代码
	CUserIDType UserID;
	///数量
	CVolumeType Volume;
	///合约代码
	CInstrumentIDType InstrumentID;
	///本地报价编号
	COrderLocalIDType QuoteLocalID;
	///业务单元
	CBusinessUnitType BusinessUnit;
	///买方组合开平标志
	CCombOffsetFlagType BidCombOffsetFlag;
	///买方组合套保标志
	CCombHedgeFlagType BidCombHedgeFlag;
	///买方价格
	CPriceType BidPrice;
	///卖方组合开平标志
	CCombOffsetFlagType AskCombOffsetFlag;
	///卖方组合套保标志
	CCombHedgeFlagType AskCombHedgeFlag;
	///卖方价格
	CPriceType AskPrice;
	///插入时间
	CTimeType InsertTime;
	///撤销时间
	CTimeType CancelTime;
	///成交时间
	CTimeType TradeTime;
	///买方报单编号
	COrderSysIDType BidOrderSysID;
	///卖方报单编号
	COrderSysIDType AskOrderSysID;
	///结算会员编号
	CParticipantIDType ClearingPartID;
	unsigned int HashAskOrderSysIDHashKey;
	
	///计算AskOrderSysIDHashKey的hash值
	void calHashAskOrderSysIDHashKey(void)
	{
		unsigned key=0;
		key=AskOrderSysID.hash(key);
		HashAskOrderSysIDHashKey=key;
	}
	
	///根据需要情况，更新AskOrderSysIDHashKey的hash值
	void updateHashAskOrderSysIDHashKey(void)
	{
	}
	unsigned int HashBidOrderSysIDHashKey;
	
	///计算BidOrderSysIDHashKey的hash值
	void calHashBidOrderSysIDHashKey(void)
	{
		unsigned key=0;
		key=BidOrderSysID.hash(key);
		HashBidOrderSysIDHashKey=key;
	}
	
	///根据需要情况，更新BidOrderSysIDHashKey的hash值
	void updateHashBidOrderSysIDHashKey(void)
	{
	}
	
	///计算所有的hash值
	void calAllHash(void)
	{
		calHashAskOrderSysIDHashKey();
		calHashBidOrderSysIDHashKey();
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
		updateHashAskOrderSysIDHashKey();
		updateHashBidOrderSysIDHashKey();
	}
	
	///构造对应的合约的指针
	///@param	pFactory	构造对应的合约的指针时，寻找的对象工厂
	///@return	找到的对应的合约的指针，如果找不到则返回NULL
	inline const CWriteableInstrument *linkInstrument(CInstrumentFactory *pFactory) const;

	///构造对应的合约指针
	///@param	pInstrument	要连接到的对象
	///@return	输入的pInstrument
	const CWriteableInstrument *linkInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///获取对应的合约的指针
	///@return	找到的对应的合约的指针，如果找不到则返回NULL
	const CWriteableInstrument *getInstrument(void) const
	{
		return pInstrument;
	}
	///构造指定的会员客户的指针
	///@param	pFactory	构造指定的会员客户的指针时，寻找的对象工厂
	///@return	找到的指定的会员客户的指针，如果找不到则返回NULL
	inline const CWriteablePartClient *linkPartClient(CPartClientFactory *pFactory) const;

	///构造指定的会员客户指针
	///@param	pPartClient	要连接到的对象
	///@return	输入的pPartClient
	const CWriteablePartClient *linkPartClient(const CWriteablePartClient *pPartClient) const
	{
		void *target=(void *)(&(this->pPartClient));
		*((const CWriteablePartClient **)target)=pPartClient;
		return pPartClient;
	}
	
	///获取指定的会员客户的指针
	///@return	找到的指定的会员客户的指针，如果找不到则返回NULL
	const CWriteablePartClient *getPartClient(void) const
	{
		return pPartClient;
	}

private:
	///对应的合约
	const CWriteableInstrument *pInstrument;
	///指定的会员客户
	const CWriteablePartClient *pPartClient;
};

typedef const CWriteableQuote CQuote;

/////////////////////////////////////////////////////////////////////////
///CQuoteActionTrigger是操作报价时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteActionTrigger
{
public:
	///构造方法
	CQuoteActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CQuoteActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CQuoteFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pQuote	要加入的Quote
	virtual void beforeAdd(CWriteableQuote *pQuote)
	{
		return;
	}
	
	///加入后触发
	///@param	pQuote	已经加入的Quote
	virtual void afterAdd(CQuote *pQuote)
	{
		return;
	}

	///更新前触发	
	///@param	pQuote	被刷新的CQuote
	///@param	pNewQuote	新的值
	virtual void beforeUpdate(CQuote *pQuote, CWriteableQuote *pNewQuote)
	{
		return;
	}
	
	///更新后触发
	///@param	pQuote	被刷新的CQuote
	virtual void afterUpdate(CQuote *pQuote)
	{
		return;
	}
	
	///删除前触发
	///@param	pQuote	要删除的CQuote
	virtual void beforeRemove(CQuote *pQuote)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CQuoteFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CQuoteCommitTrigger是确认报价时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteCommitTrigger
{
public:
	///构造方法
	CQuoteCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CQuoteCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CQuoteFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pQuote	已经加入的Quote
	virtual void commitAdd(CQuote *pQuote)
	{
		return;
	}

	///更新后触发
	///@param	pQuote	被刷新的CQuote
	///@param	poldQuote	原来的值
	virtual void commitUpdate(CQuote *pQuote, CWriteableQuote *pOldQuote)
	{
		return;
	}
	
	///删除后触发
	///@param	pQuote	已经删除的CQuote
	virtual void commitRemove(CWriteableQuote *pQuote)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CQuoteFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CQuoteIterator是一个对报价的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteIterator
{
public:
	///构造方法
	CQuoteIterator(void)
	{
	}

	///构造方法
	CQuoteIterator(CQuoteFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CQuoteIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个Quote
	///@return	下一个满足条件CQuote，如果已经没有一个满足要求了，则返回NULL
	virtual CQuote *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CQuoteFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pQuote 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableQuote * pQuote,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CQuoteFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMBLMarketData是一个存储分价表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMBLMarketData
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! InstrumentID.isValid())
			return 0;
		if (! Direction.isValid())
			return 0;
		if (! Price.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableMBLMarketData *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///合约代码
	CInstrumentIDType InstrumentID;
	///买卖方向
	CDirectionType Direction;
	///价格
	CPriceType Price;
	///数量
	CVolumeType Volume;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMBLMarketData CMBLMarketData;

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataActionTrigger是操作分价表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataActionTrigger
{
public:
	///构造方法
	CMBLMarketDataActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMBLMarketDataActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMBLMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pMBLMarketData	要加入的MBLMarketData
	virtual void beforeAdd(CWriteableMBLMarketData *pMBLMarketData)
	{
		return;
	}
	
	///加入后触发
	///@param	pMBLMarketData	已经加入的MBLMarketData
	virtual void afterAdd(CMBLMarketData *pMBLMarketData)
	{
		return;
	}

	///更新前触发	
	///@param	pMBLMarketData	被刷新的CMBLMarketData
	///@param	pNewMBLMarketData	新的值
	virtual void beforeUpdate(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pNewMBLMarketData)
	{
		return;
	}
	
	///更新后触发
	///@param	pMBLMarketData	被刷新的CMBLMarketData
	virtual void afterUpdate(CMBLMarketData *pMBLMarketData)
	{
		return;
	}
	
	///删除前触发
	///@param	pMBLMarketData	要删除的CMBLMarketData
	virtual void beforeRemove(CMBLMarketData *pMBLMarketData)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMBLMarketDataFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataCommitTrigger是确认分价表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataCommitTrigger
{
public:
	///构造方法
	CMBLMarketDataCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CMBLMarketDataCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CMBLMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pMBLMarketData	已经加入的MBLMarketData
	virtual void commitAdd(CMBLMarketData *pMBLMarketData)
	{
		return;
	}

	///更新后触发
	///@param	pMBLMarketData	被刷新的CMBLMarketData
	///@param	poldMBLMarketData	原来的值
	virtual void commitUpdate(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pOldMBLMarketData)
	{
		return;
	}
	
	///删除后触发
	///@param	pMBLMarketData	已经删除的CMBLMarketData
	virtual void commitRemove(CWriteableMBLMarketData *pMBLMarketData)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CMBLMarketDataFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataIterator是一个对分价表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataIterator
{
public:
	///构造方法
	CMBLMarketDataIterator(void)
	{
	}

	///构造方法
	CMBLMarketDataIterator(CMBLMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CMBLMarketDataIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个MBLMarketData
	///@return	下一个满足条件CMBLMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CMBLMarketData *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CMBLMarketDataFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pMBLMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMBLMarketData * pMBLMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CMBLMarketDataFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableTrade是一个存储成交的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableTrade
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! TradeID.isValid())
			return 0;
		if (! Direction.isValid())
			return 0;
		if (! OrderSysID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! AccountID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! OffsetFlag.isValid())
			return 0;
		if (! HedgeFlag.isValid())
			return 0;
		if (! Price.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! TradeTime.isValid())
			return 0;
		if (! TradeType.isValid())
			return 0;
		if (! PriceSource.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! OrderLocalID.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! TID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableTrade *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///成交编号
	CTradeIDType TradeID;
	///买卖方向
	CDirectionType Direction;
	///报单编号
	COrderSysIDType OrderSysID;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
	///交易角色
	CTradingRoleType TradingRole;
	///资金帐号
	CAccountIDType AccountID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///开平标志
	COffsetFlagType OffsetFlag;
	///投机套保标志
	CHedgeFlagType HedgeFlag;
	///价格
	CPriceType Price;
	///数量
	CVolumeType Volume;
	///成交时间
	CTimeType TradeTime;
	///成交类型
	CTradeTypeType TradeType;
	///成交价来源
	CPriceSourceType PriceSource;
	///交易用户代码
	CUserIDType UserID;
	///本地报单编号
	COrderLocalIDType OrderLocalID;
	///结算会员编号
	CParticipantIDType ClearingPartID;
	///业务单元
	CBusinessUnitType BusinessUnit;
	///序列号
	CSequenceNoType TID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	
	///构造对应的合约的指针
	///@param	pFactory	构造对应的合约的指针时，寻找的对象工厂
	///@return	找到的对应的合约的指针，如果找不到则返回NULL
	inline const CWriteableInstrument *linkInstrument(CInstrumentFactory *pFactory) const;

	///构造对应的合约指针
	///@param	pInstrument	要连接到的对象
	///@return	输入的pInstrument
	const CWriteableInstrument *linkInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///获取对应的合约的指针
	///@return	找到的对应的合约的指针，如果找不到则返回NULL
	const CWriteableInstrument *getInstrument(void) const
	{
		return pInstrument;
	}
	///构造指定的会员客户的指针
	///@param	pFactory	构造指定的会员客户的指针时，寻找的对象工厂
	///@return	找到的指定的会员客户的指针，如果找不到则返回NULL
	inline const CWriteablePartClient *linkPartClient(CPartClientFactory *pFactory) const;

	///构造指定的会员客户指针
	///@param	pPartClient	要连接到的对象
	///@return	输入的pPartClient
	const CWriteablePartClient *linkPartClient(const CWriteablePartClient *pPartClient) const
	{
		void *target=(void *)(&(this->pPartClient));
		*((const CWriteablePartClient **)target)=pPartClient;
		return pPartClient;
	}
	
	///获取指定的会员客户的指针
	///@return	找到的指定的会员客户的指针，如果找不到则返回NULL
	const CWriteablePartClient *getPartClient(void) const
	{
		return pPartClient;
	}

private:
	///对应的合约
	const CWriteableInstrument *pInstrument;
	///指定的会员客户
	const CWriteablePartClient *pPartClient;
};

typedef const CWriteableTrade CTrade;

/////////////////////////////////////////////////////////////////////////
///CTradeActionTrigger是操作成交时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeActionTrigger
{
public:
	///构造方法
	CTradeActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CTradeActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CTradeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pTrade	要加入的Trade
	virtual void beforeAdd(CWriteableTrade *pTrade)
	{
		return;
	}
	
	///加入后触发
	///@param	pTrade	已经加入的Trade
	virtual void afterAdd(CTrade *pTrade)
	{
		return;
	}

	///更新前触发	
	///@param	pTrade	被刷新的CTrade
	///@param	pNewTrade	新的值
	virtual void beforeUpdate(CTrade *pTrade, CWriteableTrade *pNewTrade)
	{
		return;
	}
	
	///更新后触发
	///@param	pTrade	被刷新的CTrade
	virtual void afterUpdate(CTrade *pTrade)
	{
		return;
	}
	
	///删除前触发
	///@param	pTrade	要删除的CTrade
	virtual void beforeRemove(CTrade *pTrade)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CTradeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CTradeCommitTrigger是确认成交时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeCommitTrigger
{
public:
	///构造方法
	CTradeCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CTradeCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CTradeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pTrade	已经加入的Trade
	virtual void commitAdd(CTrade *pTrade)
	{
		return;
	}

	///更新后触发
	///@param	pTrade	被刷新的CTrade
	///@param	poldTrade	原来的值
	virtual void commitUpdate(CTrade *pTrade, CWriteableTrade *pOldTrade)
	{
		return;
	}
	
	///删除后触发
	///@param	pTrade	已经删除的CTrade
	virtual void commitRemove(CWriteableTrade *pTrade)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CTradeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CTradeIterator是一个对成交的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeIterator
{
public:
	///构造方法
	CTradeIterator(void)
	{
	}

	///构造方法
	CTradeIterator(CTradeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CTradeIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个Trade
	///@return	下一个满足条件CTrade，如果已经没有一个满足要求了，则返回NULL
	virtual CTrade *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CTradeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pTrade 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTrade * pTrade,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CTradeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableFusePhase是一个存储熔断阶段的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableFusePhase
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! FuseStatus.isValid())
			return 0;
		if (! EnterTime.isValid())
			return 0;
		if (! ExpectLeaveTime.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableFusePhase *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///熔断状态
	CFuseStatusType FuseStatus;
	///进入本状态时间
	CTimeType EnterTime;
	///计划离开时间
	CTimeType ExpectLeaveTime;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	
	///构造对应的合约的指针
	///@param	pFactory	构造对应的合约的指针时，寻找的对象工厂
	///@return	找到的对应的合约的指针，如果找不到则返回NULL
	inline const CWriteableInstrument *linkInstrument(CInstrumentFactory *pFactory) const;

	///构造对应的合约指针
	///@param	pInstrument	要连接到的对象
	///@return	输入的pInstrument
	const CWriteableInstrument *linkInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///获取对应的合约的指针
	///@return	找到的对应的合约的指针，如果找不到则返回NULL
	const CWriteableInstrument *getInstrument(void) const
	{
		return pInstrument;
	}

private:
	///对应的合约
	const CWriteableInstrument *pInstrument;
};

typedef const CWriteableFusePhase CFusePhase;

/////////////////////////////////////////////////////////////////////////
///CFusePhaseActionTrigger是操作熔断阶段时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseActionTrigger
{
public:
	///构造方法
	CFusePhaseActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CFusePhaseActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CFusePhaseFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pFusePhase	要加入的FusePhase
	virtual void beforeAdd(CWriteableFusePhase *pFusePhase)
	{
		return;
	}
	
	///加入后触发
	///@param	pFusePhase	已经加入的FusePhase
	virtual void afterAdd(CFusePhase *pFusePhase)
	{
		return;
	}

	///更新前触发	
	///@param	pFusePhase	被刷新的CFusePhase
	///@param	pNewFusePhase	新的值
	virtual void beforeUpdate(CFusePhase *pFusePhase, CWriteableFusePhase *pNewFusePhase)
	{
		return;
	}
	
	///更新后触发
	///@param	pFusePhase	被刷新的CFusePhase
	virtual void afterUpdate(CFusePhase *pFusePhase)
	{
		return;
	}
	
	///删除前触发
	///@param	pFusePhase	要删除的CFusePhase
	virtual void beforeRemove(CFusePhase *pFusePhase)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CFusePhaseFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseCommitTrigger是确认熔断阶段时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseCommitTrigger
{
public:
	///构造方法
	CFusePhaseCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CFusePhaseCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CFusePhaseFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pFusePhase	已经加入的FusePhase
	virtual void commitAdd(CFusePhase *pFusePhase)
	{
		return;
	}

	///更新后触发
	///@param	pFusePhase	被刷新的CFusePhase
	///@param	poldFusePhase	原来的值
	virtual void commitUpdate(CFusePhase *pFusePhase, CWriteableFusePhase *pOldFusePhase)
	{
		return;
	}
	
	///删除后触发
	///@param	pFusePhase	已经删除的CFusePhase
	virtual void commitRemove(CWriteableFusePhase *pFusePhase)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CFusePhaseFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseIterator是一个对熔断阶段的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseIterator
{
public:
	///构造方法
	CFusePhaseIterator(void)
	{
	}

	///构造方法
	CFusePhaseIterator(CFusePhaseFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CFusePhaseIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个FusePhase
	///@return	下一个满足条件CFusePhase，如果已经没有一个满足要求了，则返回NULL
	virtual CFusePhase *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CFusePhaseFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pFusePhase 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableFusePhase * pFusePhase,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CFusePhaseFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableExecOrder是一个存储执行宣告的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableExecOrder
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! ExecOrderLocalID.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! ExecOrderSysID.isValid())
			return 0;
		if (! InsertDate.isValid())
			return 0;
		if (! InsertTime.isValid())
			return 0;
		if (! CancelTime.isValid())
			return 0;
		if (! ExecResult.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableExecOrder *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///合约编号
	CInstrumentIDType InstrumentID;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
	///交易用户代码
	CUserIDType UserID;
	///本地执行宣告编号
	COrderLocalIDType ExecOrderLocalID;
	///数量
	CVolumeType Volume;
	///业务单元
	CBusinessUnitType BusinessUnit;
	///执行宣告编号
	CExecOrderSysIDType ExecOrderSysID;
	///报单日期
	CDateType InsertDate;
	///插入时间
	CTimeType InsertTime;
	///撤销时间
	CTimeType CancelTime;
	///执行结果
	CExecResultType ExecResult;
	///结算会员编号
	CParticipantIDType ClearingPartID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	
	///构造指定的会员客户的指针
	///@param	pFactory	构造指定的会员客户的指针时，寻找的对象工厂
	///@return	找到的指定的会员客户的指针，如果找不到则返回NULL
	inline const CWriteablePartClient *linkPartClient(CPartClientFactory *pFactory) const;

	///构造指定的会员客户指针
	///@param	pPartClient	要连接到的对象
	///@return	输入的pPartClient
	const CWriteablePartClient *linkPartClient(const CWriteablePartClient *pPartClient) const
	{
		void *target=(void *)(&(this->pPartClient));
		*((const CWriteablePartClient **)target)=pPartClient;
		return pPartClient;
	}
	
	///获取指定的会员客户的指针
	///@return	找到的指定的会员客户的指针，如果找不到则返回NULL
	const CWriteablePartClient *getPartClient(void) const
	{
		return pPartClient;
	}
	///构造对应的合约的指针
	///@param	pFactory	构造对应的合约的指针时，寻找的对象工厂
	///@return	找到的对应的合约的指针，如果找不到则返回NULL
	inline const CWriteableInstrument *linkInstrument(CInstrumentFactory *pFactory) const;

	///构造对应的合约指针
	///@param	pInstrument	要连接到的对象
	///@return	输入的pInstrument
	const CWriteableInstrument *linkInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///获取对应的合约的指针
	///@return	找到的对应的合约的指针，如果找不到则返回NULL
	const CWriteableInstrument *getInstrument(void) const
	{
		return pInstrument;
	}

private:
	///指定的会员客户
	const CWriteablePartClient *pPartClient;
	///对应的合约
	const CWriteableInstrument *pInstrument;
};

typedef const CWriteableExecOrder CExecOrder;

/////////////////////////////////////////////////////////////////////////
///CExecOrderActionTrigger是操作执行宣告时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderActionTrigger
{
public:
	///构造方法
	CExecOrderActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CExecOrderActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CExecOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pExecOrder	要加入的ExecOrder
	virtual void beforeAdd(CWriteableExecOrder *pExecOrder)
	{
		return;
	}
	
	///加入后触发
	///@param	pExecOrder	已经加入的ExecOrder
	virtual void afterAdd(CExecOrder *pExecOrder)
	{
		return;
	}

	///更新前触发	
	///@param	pExecOrder	被刷新的CExecOrder
	///@param	pNewExecOrder	新的值
	virtual void beforeUpdate(CExecOrder *pExecOrder, CWriteableExecOrder *pNewExecOrder)
	{
		return;
	}
	
	///更新后触发
	///@param	pExecOrder	被刷新的CExecOrder
	virtual void afterUpdate(CExecOrder *pExecOrder)
	{
		return;
	}
	
	///删除前触发
	///@param	pExecOrder	要删除的CExecOrder
	virtual void beforeRemove(CExecOrder *pExecOrder)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CExecOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderCommitTrigger是确认执行宣告时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderCommitTrigger
{
public:
	///构造方法
	CExecOrderCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CExecOrderCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CExecOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pExecOrder	已经加入的ExecOrder
	virtual void commitAdd(CExecOrder *pExecOrder)
	{
		return;
	}

	///更新后触发
	///@param	pExecOrder	被刷新的CExecOrder
	///@param	poldExecOrder	原来的值
	virtual void commitUpdate(CExecOrder *pExecOrder, CWriteableExecOrder *pOldExecOrder)
	{
		return;
	}
	
	///删除后触发
	///@param	pExecOrder	已经删除的CExecOrder
	virtual void commitRemove(CWriteableExecOrder *pExecOrder)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CExecOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderIterator是一个对执行宣告的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderIterator
{
public:
	///构造方法
	CExecOrderIterator(void)
	{
	}

	///构造方法
	CExecOrderIterator(CExecOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CExecOrderIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个ExecOrder
	///@return	下一个满足条件CExecOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CExecOrder *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CExecOrderFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pExecOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExecOrder * pExecOrder,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CExecOrderFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableUniPressure是一个存储单边市情况的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableUniPressure
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! UpperPressureStartTime.isValid())
			return 0;
		if (! LowerPressureStartTime.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableUniPressure *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///涨压力开始时间
	CTimeType UpperPressureStartTime;
	///跌压力开始时间
	CTimeType LowerPressureStartTime;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableUniPressure CUniPressure;

/////////////////////////////////////////////////////////////////////////
///CUniPressureActionTrigger是操作单边市情况时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureActionTrigger
{
public:
	///构造方法
	CUniPressureActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CUniPressureActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CUniPressureFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pUniPressure	要加入的UniPressure
	virtual void beforeAdd(CWriteableUniPressure *pUniPressure)
	{
		return;
	}
	
	///加入后触发
	///@param	pUniPressure	已经加入的UniPressure
	virtual void afterAdd(CUniPressure *pUniPressure)
	{
		return;
	}

	///更新前触发	
	///@param	pUniPressure	被刷新的CUniPressure
	///@param	pNewUniPressure	新的值
	virtual void beforeUpdate(CUniPressure *pUniPressure, CWriteableUniPressure *pNewUniPressure)
	{
		return;
	}
	
	///更新后触发
	///@param	pUniPressure	被刷新的CUniPressure
	virtual void afterUpdate(CUniPressure *pUniPressure)
	{
		return;
	}
	
	///删除前触发
	///@param	pUniPressure	要删除的CUniPressure
	virtual void beforeRemove(CUniPressure *pUniPressure)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CUniPressureFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureCommitTrigger是确认单边市情况时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureCommitTrigger
{
public:
	///构造方法
	CUniPressureCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CUniPressureCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CUniPressureFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pUniPressure	已经加入的UniPressure
	virtual void commitAdd(CUniPressure *pUniPressure)
	{
		return;
	}

	///更新后触发
	///@param	pUniPressure	被刷新的CUniPressure
	///@param	poldUniPressure	原来的值
	virtual void commitUpdate(CUniPressure *pUniPressure, CWriteableUniPressure *pOldUniPressure)
	{
		return;
	}
	
	///删除后触发
	///@param	pUniPressure	已经删除的CUniPressure
	virtual void commitRemove(CWriteableUniPressure *pUniPressure)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CUniPressureFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureIterator是一个对单边市情况的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureIterator
{
public:
	///构造方法
	CUniPressureIterator(void)
	{
	}

	///构造方法
	CUniPressureIterator(CUniPressureFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CUniPressureIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个UniPressure
	///@return	下一个满足条件CUniPressure，如果已经没有一个满足要求了，则返回NULL
	virtual CUniPressure *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CUniPressureFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pUniPressure 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUniPressure * pUniPressure,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CUniPressureFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableBasePriceLimit是一个存储涨跌停板设置的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableBasePriceLimit
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! UpperLimitPrice.isValid())
			return 0;
		if (! LowerLimitPrice.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableBasePriceLimit *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///涨停板价
	CPriceType UpperLimitPrice;
	///跌停板价
	CPriceType LowerLimitPrice;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableBasePriceLimit CBasePriceLimit;

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitActionTrigger是操作涨跌停板设置时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitActionTrigger
{
public:
	///构造方法
	CBasePriceLimitActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CBasePriceLimitActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CBasePriceLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pBasePriceLimit	要加入的BasePriceLimit
	virtual void beforeAdd(CWriteableBasePriceLimit *pBasePriceLimit)
	{
		return;
	}
	
	///加入后触发
	///@param	pBasePriceLimit	已经加入的BasePriceLimit
	virtual void afterAdd(CBasePriceLimit *pBasePriceLimit)
	{
		return;
	}

	///更新前触发	
	///@param	pBasePriceLimit	被刷新的CBasePriceLimit
	///@param	pNewBasePriceLimit	新的值
	virtual void beforeUpdate(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pNewBasePriceLimit)
	{
		return;
	}
	
	///更新后触发
	///@param	pBasePriceLimit	被刷新的CBasePriceLimit
	virtual void afterUpdate(CBasePriceLimit *pBasePriceLimit)
	{
		return;
	}
	
	///删除前触发
	///@param	pBasePriceLimit	要删除的CBasePriceLimit
	virtual void beforeRemove(CBasePriceLimit *pBasePriceLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CBasePriceLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitCommitTrigger是确认涨跌停板设置时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitCommitTrigger
{
public:
	///构造方法
	CBasePriceLimitCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CBasePriceLimitCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CBasePriceLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pBasePriceLimit	已经加入的BasePriceLimit
	virtual void commitAdd(CBasePriceLimit *pBasePriceLimit)
	{
		return;
	}

	///更新后触发
	///@param	pBasePriceLimit	被刷新的CBasePriceLimit
	///@param	poldBasePriceLimit	原来的值
	virtual void commitUpdate(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pOldBasePriceLimit)
	{
		return;
	}
	
	///删除后触发
	///@param	pBasePriceLimit	已经删除的CBasePriceLimit
	virtual void commitRemove(CWriteableBasePriceLimit *pBasePriceLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CBasePriceLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitIterator是一个对涨跌停板设置的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitIterator
{
public:
	///构造方法
	CBasePriceLimitIterator(void)
	{
	}

	///构造方法
	CBasePriceLimitIterator(CBasePriceLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CBasePriceLimitIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个BasePriceLimit
	///@return	下一个满足条件CBasePriceLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CBasePriceLimit *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CBasePriceLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pBasePriceLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBasePriceLimit * pBasePriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CBasePriceLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCreditLimit是一个存储信用限额的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCreditLimit
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! PreBalance.isValid())
			return 0;
		if (! CurrMargin.isValid())
			return 0;
		if (! CloseProfit.isValid())
			return 0;
		if (! Premium.isValid())
			return 0;
		if (! Deposit.isValid())
			return 0;
		if (! Withdraw.isValid())
			return 0;
		if (! Balance.isValid())
			return 0;
		if (! Available.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		if (! FrozenMargin.isValid())
			return 0;
		if (! FrozenPremium.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCreditLimit *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///上次结算准备金
	CMoneyType PreBalance;
	///当前保证金总额
	CMoneyType CurrMargin;
	///平仓盈亏
	CMoneyType CloseProfit;
	///期权权利金收支
	CMoneyType Premium;
	///入金金额
	CMoneyType Deposit;
	///出金金额
	CMoneyType Withdraw;
	///期货结算准备金
	CMoneyType Balance;
	///可提资金
	CMoneyType Available;
	///交易会员编号
	CParticipantIDType ParticipantID;
	///结算会员编号
	CParticipantIDType ClearingPartID;
	///冻结的保证金
	CMoneyType FrozenMargin;
	///冻结的权利金
	CMoneyType FrozenPremium;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCreditLimit CCreditLimit;

/////////////////////////////////////////////////////////////////////////
///CCreditLimitActionTrigger是操作信用限额时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitActionTrigger
{
public:
	///构造方法
	CCreditLimitActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCreditLimitActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCreditLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCreditLimit	要加入的CreditLimit
	virtual void beforeAdd(CWriteableCreditLimit *pCreditLimit)
	{
		return;
	}
	
	///加入后触发
	///@param	pCreditLimit	已经加入的CreditLimit
	virtual void afterAdd(CCreditLimit *pCreditLimit)
	{
		return;
	}

	///更新前触发	
	///@param	pCreditLimit	被刷新的CCreditLimit
	///@param	pNewCreditLimit	新的值
	virtual void beforeUpdate(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pNewCreditLimit)
	{
		return;
	}
	
	///更新后触发
	///@param	pCreditLimit	被刷新的CCreditLimit
	virtual void afterUpdate(CCreditLimit *pCreditLimit)
	{
		return;
	}
	
	///删除前触发
	///@param	pCreditLimit	要删除的CCreditLimit
	virtual void beforeRemove(CCreditLimit *pCreditLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCreditLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitCommitTrigger是确认信用限额时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitCommitTrigger
{
public:
	///构造方法
	CCreditLimitCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCreditLimitCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCreditLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCreditLimit	已经加入的CreditLimit
	virtual void commitAdd(CCreditLimit *pCreditLimit)
	{
		return;
	}

	///更新后触发
	///@param	pCreditLimit	被刷新的CCreditLimit
	///@param	poldCreditLimit	原来的值
	virtual void commitUpdate(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pOldCreditLimit)
	{
		return;
	}
	
	///删除后触发
	///@param	pCreditLimit	已经删除的CCreditLimit
	virtual void commitRemove(CWriteableCreditLimit *pCreditLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCreditLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitIterator是一个对信用限额的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitIterator
{
public:
	///构造方法
	CCreditLimitIterator(void)
	{
	}

	///构造方法
	CCreditLimitIterator(CCreditLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCreditLimitIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CreditLimit
	///@return	下一个满足条件CCreditLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCreditLimit *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCreditLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCreditLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCreditLimit * pCreditLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCreditLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableHedgeDetail是一个存储保值额度明细的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableHedgeDetail
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! HedgeQuotaSN.isValid())
			return 0;
		if (! OperatorID.isValid())
			return 0;
		if (! Time.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! PosiDirection.isValid())
			return 0;
		if (! TradingVolume.isValid())
			return 0;
		if (! HedgeQuota.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableHedgeDetail *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///流水号
	CSerialNoType HedgeQuotaSN;
	///用户代码
	COperatorIDType OperatorID;
	///时间
	CTimeType Time;
	///合约代码
	CInstrumentIDType InstrumentID;
	///持仓多空方向
	CPosiDirectionType PosiDirection;
	///发生额
	CVolumeType TradingVolume;
	///保值额度
	CVolumeType HedgeQuota;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableHedgeDetail CHedgeDetail;

/////////////////////////////////////////////////////////////////////////
///CWriteableOrderAction是一个存储报单操作的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableOrderAction
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! OrderSysID.isValid())
			return 0;
		if (! OrderLocalID.isValid())
			return 0;
		if (! ActionFlag.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! LimitPrice.isValid())
			return 0;
		if (! VolumeChange.isValid())
			return 0;
		if (! ActionLocalID.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! ActionSource.isValid())
			return 0;
		if (! Tradable.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableOrderAction *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///报单编号
	COrderSysIDType OrderSysID;
	///本地报单编号
	COrderLocalIDType OrderLocalID;
	///报单操作标志
	CActionFlagType ActionFlag;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
	///交易用户代码
	CUserIDType UserID;
	///价格
	CPriceType LimitPrice;
	///数量变化
	CVolumeType VolumeChange;
	///操作本地编号
	COrderLocalIDType ActionLocalID;
	///业务单元
	CBusinessUnitType BusinessUnit;
	///操作来源
	CActionSourceType ActionSource;
	///是否可以参加交易
	CBoolType Tradable;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	
	///构造对应的报单的指针
	///@param	pFactory	构造对应的报单的指针时，寻找的对象工厂
	///@return	找到的对应的报单的指针，如果找不到则返回NULL
	inline const CWriteableOrder *linkOrder(COrderFactory *pFactory) const;

	///构造对应的报单指针
	///@param	pOrder	要连接到的对象
	///@return	输入的pOrder
	const CWriteableOrder *linkOrder(const CWriteableOrder *pOrder) const
	{
		void *target=(void *)(&(this->pOrder));
		*((const CWriteableOrder **)target)=pOrder;
		return pOrder;
	}
	
	///获取对应的报单的指针
	///@return	找到的对应的报单的指针，如果找不到则返回NULL
	const CWriteableOrder *getOrder(void) const
	{
		return pOrder;
	}

private:
	///对应的报单
	const CWriteableOrder *pOrder;
};

typedef const CWriteableOrderAction COrderAction;

/////////////////////////////////////////////////////////////////////////
///CWriteableQuoteAction是一个存储报价操作的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableQuoteAction
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! QuoteSysID.isValid())
			return 0;
		if (! QuoteLocalID.isValid())
			return 0;
		if (! ActionFlag.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! ActionLocalID.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! ActionSource.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableQuoteAction *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///报价编号
	CQuoteSysIDType QuoteSysID;
	///本地报价编号
	COrderLocalIDType QuoteLocalID;
	///报单操作标志
	CActionFlagType ActionFlag;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
	///交易用户代码
	CUserIDType UserID;
	///操作本地编号
	COrderLocalIDType ActionLocalID;
	///业务单元
	CBusinessUnitType BusinessUnit;
	///操作来源
	CActionSourceType ActionSource;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	
	///构造对应的报价的指针
	///@param	pFactory	构造对应的报价的指针时，寻找的对象工厂
	///@return	找到的对应的报价的指针，如果找不到则返回NULL
	inline const CWriteableQuote *linkQuote(CQuoteFactory *pFactory) const;

	///构造对应的报价指针
	///@param	pQuote	要连接到的对象
	///@return	输入的pQuote
	const CWriteableQuote *linkQuote(const CWriteableQuote *pQuote) const
	{
		void *target=(void *)(&(this->pQuote));
		*((const CWriteableQuote **)target)=pQuote;
		return pQuote;
	}
	
	///获取对应的报价的指针
	///@return	找到的对应的报价的指针，如果找不到则返回NULL
	const CWriteableQuote *getQuote(void) const
	{
		return pQuote;
	}

private:
	///对应的报价
	const CWriteableQuote *pQuote;
};

typedef const CWriteableQuoteAction CQuoteAction;

/////////////////////////////////////////////////////////////////////////
///CWriteableExecOrderAction是一个存储执行宣告操作的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableExecOrderAction
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! ExecOrderSysID.isValid())
			return 0;
		if (! ExecOrderLocalID.isValid())
			return 0;
		if (! ActionFlag.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! ActionLocalID.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! ActionSource.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableExecOrderAction *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///执行宣告编号
	CExecOrderSysIDType ExecOrderSysID;
	///本地执行宣告编号
	COrderLocalIDType ExecOrderLocalID;
	///报单操作标志
	CActionFlagType ActionFlag;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
	///交易用户代码
	CUserIDType UserID;
	///操作本地编号
	COrderLocalIDType ActionLocalID;
	///业务单元
	CBusinessUnitType BusinessUnit;
	///操作来源
	CActionSourceType ActionSource;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	
	///构造对应的执行宣告的指针
	///@param	pFactory	构造对应的执行宣告的指针时，寻找的对象工厂
	///@return	找到的对应的执行宣告的指针，如果找不到则返回NULL
	inline const CWriteableExecOrder *linkExecOrder(CExecOrderFactory *pFactory) const;

	///构造对应的执行宣告指针
	///@param	pExecOrder	要连接到的对象
	///@return	输入的pExecOrder
	const CWriteableExecOrder *linkExecOrder(const CWriteableExecOrder *pExecOrder) const
	{
		void *target=(void *)(&(this->pExecOrder));
		*((const CWriteableExecOrder **)target)=pExecOrder;
		return pExecOrder;
	}
	
	///获取对应的执行宣告的指针
	///@return	找到的对应的执行宣告的指针，如果找不到则返回NULL
	const CWriteableExecOrder *getExecOrder(void) const
	{
		return pExecOrder;
	}

private:
	///对应的执行宣告
	const CWriteableExecOrder *pExecOrder;
};

typedef const CWriteableExecOrderAction CExecOrderAction;

/////////////////////////////////////////////////////////////////////////
///CWriteableAccountDeposit是一个存储会员资金帐户入金的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableAccountDeposit
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! Account.isValid())
			return 0;
		if (! Deposit.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableAccountDeposit *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///资金账号
	CAccountIDType Account;
	///入金金额
	CMoneyType Deposit;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableAccountDeposit CAccountDeposit;

/////////////////////////////////////////////////////////////////////////
///CWriteableUpdateAllInstrumentStatus是一个存储调整所有合约状态的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableUpdateAllInstrumentStatus
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentStatus.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableUpdateAllInstrumentStatus *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///合约状态
	CInstrumentStatusType InstrumentStatus;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableUpdateAllInstrumentStatus CUpdateAllInstrumentStatus;

/////////////////////////////////////////////////////////////////////////
///CWriteableAdminOrder是一个存储管理报单的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableAdminOrder
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! InstrumentID.isValid())
			return 0;
		if (! AdminOrderCommand.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! Amount.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableAdminOrder *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///合约代码
	CInstrumentIDType InstrumentID;
	///管理报单命令
	CAdminOrderCommandFlagType AdminOrderCommand;
	///结算会员编号
	CParticipantIDType ClearingPartID;
	///交易会员编号
	CParticipantIDType ParticipantID;
	///金额
	CMoneyType Amount;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableAdminOrder CAdminOrder;

/////////////////////////////////////////////////////////////////////////
///CWriteableCommPhase是一个存储通讯阶段的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCommPhase
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! CommPhaseNo.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCommPhase *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///通讯时段号
	CCommPhaseNoType CommPhaseNo;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCommPhase CCommPhase;

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrHedge是一个存储当前保值额度的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrHedge
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! HedgeQuotaSN.isValid())
			return 0;
		if (! OperatorID.isValid())
			return 0;
		if (! Time.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! PosiDirection.isValid())
			return 0;
		if (! CurrVolume.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrHedge *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///交易日
	CDateType TradingDay;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///结算编号
	CSettlementIDType SettlementID;
	///流水号
	CSerialNoType HedgeQuotaSN;
	///用户代码
	COperatorIDType OperatorID;
	///时间
	CTimeType Time;
	///合约代码
	CInstrumentIDType InstrumentID;
	///持仓多空方向
	CPosiDirectionType PosiDirection;
	///当前保值额度
	CVolumeType CurrVolume;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrHedge CCurrHedge;

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrInstrumentOption是一个存储当日期货合约期权属性的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrInstrumentOption
{
public:
	///向CSV文件中写出标题行
	///@param	output	要写出的文件
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///初始化操作，将所有的字段清空
	void init(void);
	
	///从文件读入
	///@param	input	读入的文件
	///@return	1表示读入成功，0表示读入失败
	int read(FILE *input);
	
	///向文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;
	
	///从CSV文件读入
	///@param	input	读入的文件
	///@param	pNames	各个字段的名称，如果为NULL，则顺序读出
	///@return	1表示读入成功，0表示读入失败
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///向CSV文件写出
	///@param	output 写出的文件
	///@return	1表时写出成功，0表示写出失败
	int writeCSV(FILE *output) const;

	///检查数据的合法性
	///@return	1表示合法，0表示不合法
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! OptPostLimitRatio.isValid())
			return 0;
		if (! UniPostLimitRatio.isValid())
			return 0;
		if (! MiniMargin.isValid())
			return 0;
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableCurrInstrumentOption *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///同标的期权的合并持仓倍数
	CRatioType OptPostLimitRatio;
	///期货和同标的期权的合并持仓倍数
	CRatioType UniPostLimitRatio;
	///单位（手）期权合约最小保证金
	CMoneyType MiniMargin;
	
	///计算所有的hash值
	void calAllHash(void)
	{
	}
	
	///更新所有的hash值
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrInstrumentOption CCurrInstrumentOption;

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionActionTrigger是操作当日期货合约期权属性时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionActionTrigger
{
public:
	///构造方法
	CCurrInstrumentOptionActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrInstrumentOptionActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrInstrumentOptionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pCurrInstrumentOption	要加入的CurrInstrumentOption
	virtual void beforeAdd(CWriteableCurrInstrumentOption *pCurrInstrumentOption)
	{
		return;
	}
	
	///加入后触发
	///@param	pCurrInstrumentOption	已经加入的CurrInstrumentOption
	virtual void afterAdd(CCurrInstrumentOption *pCurrInstrumentOption)
	{
		return;
	}

	///更新前触发	
	///@param	pCurrInstrumentOption	被刷新的CCurrInstrumentOption
	///@param	pNewCurrInstrumentOption	新的值
	virtual void beforeUpdate(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pNewCurrInstrumentOption)
	{
		return;
	}
	
	///更新后触发
	///@param	pCurrInstrumentOption	被刷新的CCurrInstrumentOption
	virtual void afterUpdate(CCurrInstrumentOption *pCurrInstrumentOption)
	{
		return;
	}
	
	///删除前触发
	///@param	pCurrInstrumentOption	要删除的CCurrInstrumentOption
	virtual void beforeRemove(CCurrInstrumentOption *pCurrInstrumentOption)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrInstrumentOptionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionCommitTrigger是确认当日期货合约期权属性时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionCommitTrigger
{
public:
	///构造方法
	CCurrInstrumentOptionCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CCurrInstrumentOptionCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CCurrInstrumentOptionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pCurrInstrumentOption	已经加入的CurrInstrumentOption
	virtual void commitAdd(CCurrInstrumentOption *pCurrInstrumentOption)
	{
		return;
	}

	///更新后触发
	///@param	pCurrInstrumentOption	被刷新的CCurrInstrumentOption
	///@param	poldCurrInstrumentOption	原来的值
	virtual void commitUpdate(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pOldCurrInstrumentOption)
	{
		return;
	}
	
	///删除后触发
	///@param	pCurrInstrumentOption	已经删除的CCurrInstrumentOption
	virtual void commitRemove(CWriteableCurrInstrumentOption *pCurrInstrumentOption)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CCurrInstrumentOptionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionIterator是一个对当日期货合约期权属性的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionIterator
{
public:
	///构造方法
	CCurrInstrumentOptionIterator(void)
	{
	}

	///构造方法
	CCurrInstrumentOptionIterator(CCurrInstrumentOptionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrInstrumentOptionIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个CurrInstrumentOption
	///@return	下一个满足条件CCurrInstrumentOption，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrInstrumentOption *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CCurrInstrumentOptionFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pCurrInstrumentOption 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrInstrumentOption * pCurrInstrumentOption,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CCurrInstrumentOptionFactory *m_Factory;	
};


#include "databaseFactories.h"

const CWriteableClearingTradingPart *CWriteableParticipant::linkClearingTradingPart(CClearingTradingPartFactory *pFactory) const
{
	void *target=(void *)(&pClearingTradingPart);
	*((const CWriteableClearingTradingPart **)target)=pFactory->findByParticipant(ParticipantID);
	return pClearingTradingPart;
}

const CWriteableParticipant *CWriteablePartClient::linkParticipant(CParticipantFactory *pFactory) const
{
	void *target=(void *)(&pParticipant);
	*((const CWriteableParticipant **)target)=pFactory->findByParticipantID(ParticipantID);
	return pParticipant;
}

const CWriteableClient *CWriteablePartClient::linkClient(CClientFactory *pFactory) const
{
	void *target=(void *)(&pClient);
	*((const CWriteableClient **)target)=pFactory->findByClientID(ClientID);
	return pClient;
}

const CWriteableTradingAccount *CWriteableAccount::linkTradingAccount(CTradingAccountFactory *pFactory) const
{
	void *target=(void *)(&pTradingAccount);
	*((const CWriteableTradingAccount **)target)=pFactory->findByAccountID(AccountID);
	return pTradingAccount;
}

const CWriteableUser *CWriteableUserSession::linkUser(CUserFactory *pFactory) const
{
	void *target=(void *)(&pUser);
	*((const CWriteableUser **)target)=pFactory->findByUserID(UserID);
	return pUser;
}

const CWriteableDepthMarketData *CWriteableMarketDataModify::linkDepthMarketData(CDepthMarketDataFactory *pFactory) const
{
	void *target=(void *)(&pDepthMarketData);
	*((const CWriteableDepthMarketData **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pDepthMarketData;
}

const CWriteableInstrument *CWriteableDepthMarketData::linkInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrument;
}

const CWriteableInstrument *CWriteableInstrument::linkBaseInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pBaseInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(UnderlyingInstrID);
	return pBaseInstrument;
}

const CWriteableCurrInstrumentProperty *CWriteableInstrument::linkInstrumentProperty(CCurrInstrumentPropertyFactory *pFactory) const
{
	void *target=(void *)(&pInstrumentProperty);
	*((const CWriteableCurrInstrumentProperty **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrumentProperty;
}

const CWriteableInstrumentStatus *CWriteableInstrument::linkInstrumentStatus(CInstrumentStatusFactory *pFactory) const
{
	void *target=(void *)(&pInstrumentStatus);
	*((const CWriteableInstrumentStatus **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrumentStatus;
}

const CWriteableMarketData *CWriteableInstrument::linkMarketData(CMarketDataFactory *pFactory) const
{
	void *target=(void *)(&pMarketData);
	*((const CWriteableMarketData **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pMarketData;
}

const CWriteableCurrHedgeRule *CWriteableInstrument::linkCurrHedgeRule(CCurrHedgeRuleFactory *pFactory) const
{
	void *target=(void *)(&pCurrHedgeRule);
	*((const CWriteableCurrHedgeRule **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pCurrHedgeRule;
}

const CWriteableCurrFuse *CWriteableInstrument::linkCurrFuse(CCurrFuseFactory *pFactory) const
{
	void *target=(void *)(&pCurrFuse);
	*((const CWriteableCurrFuse **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pCurrFuse;
}

const CWriteableFusePhase *CWriteableInstrument::linkFusePhase(CFusePhaseFactory *pFactory) const
{
	void *target=(void *)(&pFusePhase);
	*((const CWriteableFusePhase **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pFusePhase;
}

const CWriteableBasePriceLimit *CWriteableInstrument::linkBasePriceLimit(CBasePriceLimitFactory *pFactory) const
{
	void *target=(void *)(&pBasePriceLimit);
	*((const CWriteableBasePriceLimit **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pBasePriceLimit;
}

const CWriteableUniPressure *CWriteableInstrument::linkUniPressure(CUniPressureFactory *pFactory) const
{
	void *target=(void *)(&pUniPressure);
	*((const CWriteableUniPressure **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pUniPressure;
}

const CWriteableSGDataSyncStatus *CWriteableInstrument::linkSGDataSyncStatus(CSGDataSyncStatusFactory *pFactory) const
{
	void *target=(void *)(&pSGDataSyncStatus);
	*((const CWriteableSGDataSyncStatus **)target)=pFactory->findBySettlementGroupID(SettlementGroupID);
	return pSGDataSyncStatus;
}

const CWriteableInstrument *CWriteableCombinationLeg::linkCombinationInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pCombinationInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(CombInstrumentID);
	if (pCombinationInstrument==NULL)
	{
		RAISE_RUNTIME_ERROR("can not link CombinationInstrument in CombinationLeg");
	}
	return pCombinationInstrument;
}

const CWriteableInstrument *CWriteableCombinationLeg::linkLegInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pLegInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(LegInstrumentID);
	if (pLegInstrument==NULL)
	{
		RAISE_RUNTIME_ERROR("can not link LegInstrument in CombinationLeg");
	}
	return pLegInstrument;
}

const CWriteableTradingAccount *CWriteablePartRoleAccount::linkTradingAccount(CTradingAccountFactory *pFactory) const
{
	void *target=(void *)(&pTradingAccount);
	*((const CWriteableTradingAccount **)target)=pFactory->findByAccountID(AccountID);
	return pTradingAccount;
}

const CWriteableBaseReserveAccount *CWriteableTradingAccount::linkBaseReserveAccount(CBaseReserveAccountFactory *pFactory) const
{
	void *target=(void *)(&pBaseReserveAccount);
	*((const CWriteableBaseReserveAccount **)target)=pFactory->findByAccountID(AccountID);
	return pBaseReserveAccount;
}

const CWriteableCreditLimit *CWriteableClientPosition::linkCreditLimit(CCreditLimitFactory *pFactory) const
{
	void *target=(void *)(&pCreditLimit);
	*((const CWriteableCreditLimit **)target)=pFactory->findByParticipantID(SettlementGroupID,ParticipantID);
	return pCreditLimit;
}

const CWriteablePartRoleAccount *CWriteableClientPosition::linkPartRoleAccount(CPartRoleAccountFactory *pFactory) const
{
	void *target=(void *)(&pPartRoleAccount);
	*((const CWriteablePartRoleAccount **)target)=pFactory->findByPartRoleAndSG("",ER_Broker,"");
	return pPartRoleAccount;
}

const CWriteableInstrument *CWriteableInstrumentStatus::linkInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrument;
}

const CWriteableCurrPriceBanding *CWriteableInstrumentStatus::linkCurrPriceBanding(CCurrPriceBandingFactory *pFactory) const
{
	void *target=(void *)(&pCurrPriceBanding);
	*((const CWriteableCurrPriceBanding **)target)=pFactory->findByInstrumentAndSegment(InstrumentID,TradingSegmentSN);
	return pCurrPriceBanding;
}

const CWriteableMdPubStatus *CWriteableInstrumentStatus::linkMdPubStatus(CMdPubStatusFactory *pFactory) const
{
	void *target=(void *)(&pMdPubStatus);
	*((const CWriteableMdPubStatus **)target)=pFactory->findByProductIDInstrumentStatus(getInstrument()->ProductID,InstrumentStatus);
	return pMdPubStatus;
}

const CWriteableInstrument *CWriteableOrder::linkInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrument;
}

const CWriteablePartClient *CWriteableOrder::linkPartClient(CPartClientFactory *pFactory) const
{
	void *target=(void *)(&pPartClient);
	*((const CWriteablePartClient **)target)=pFactory->findByPartClient(ParticipantID,ClientID);
	return pPartClient;
}

const CWriteableClientPosition *CWriteableOrder::linkClientPosition(CClientPositionFactory *pFactory) const
{
	void *target=(void *)(&pClientPosition);
	*((const CWriteableClientPosition **)target)=pFactory->findByPartClientAndInstrument(ParticipantID,ClientID,InstrumentID,PD_Net,HF_Speculation);
	return pClientPosition;
}

const CWriteablePartClient *CWriteableCombOrder::linkPartClient(CPartClientFactory *pFactory) const
{
	void *target=(void *)(&pPartClient);
	*((const CWriteablePartClient **)target)=pFactory->findByPartClient(ParticipantID,ClientID);
	return pPartClient;
}

const CWriteableInstrument *CWriteableCombOrder::linkInstrument1(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument1);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID1);
	return pInstrument1;
}

const CWriteableInstrument *CWriteableCombOrder::linkInstrument2(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument2);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID2);
	return pInstrument2;
}

const CWriteableInstrument *CWriteableCombOrder::linkInstrument3(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument3);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID3);
	return pInstrument3;
}

const CWriteableInstrument *CWriteableCombOrder::linkInstrument4(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument4);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID4);
	return pInstrument4;
}

const CWriteableInstrument *CWriteableOTCOrder::linkInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrument;
}

const CWriteableInstrument *CWriteableQuote::linkInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrument;
}

const CWriteablePartClient *CWriteableQuote::linkPartClient(CPartClientFactory *pFactory) const
{
	void *target=(void *)(&pPartClient);
	*((const CWriteablePartClient **)target)=pFactory->findByPartClient(ParticipantID,ClientID);
	return pPartClient;
}

const CWriteableInstrument *CWriteableTrade::linkInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrument;
}

const CWriteablePartClient *CWriteableTrade::linkPartClient(CPartClientFactory *pFactory) const
{
	void *target=(void *)(&pPartClient);
	*((const CWriteablePartClient **)target)=pFactory->findByPartClient(ParticipantID,ClientID);
	return pPartClient;
}

const CWriteableInstrument *CWriteableFusePhase::linkInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrument;
}

const CWriteablePartClient *CWriteableExecOrder::linkPartClient(CPartClientFactory *pFactory) const
{
	void *target=(void *)(&pPartClient);
	*((const CWriteablePartClient **)target)=pFactory->findByPartClient(ParticipantID,ClientID);
	return pPartClient;
}

const CWriteableInstrument *CWriteableExecOrder::linkInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrument;
}

const CWriteableOrder *CWriteableOrderAction::linkOrder(COrderFactory *pFactory) const
{
	void *target=(void *)(&pOrder);
	*((const CWriteableOrder **)target)=pFactory->findByOrderID(OrderSysID);
	return pOrder;
}

const CWriteableQuote *CWriteableQuoteAction::linkQuote(CQuoteFactory *pFactory) const
{
	void *target=(void *)(&pQuote);
	*((const CWriteableQuote **)target)=pFactory->findByQuoteID(QuoteSysID);
	return pQuote;
}

const CWriteableExecOrder *CWriteableExecOrderAction::linkExecOrder(CExecOrderFactory *pFactory) const
{
	void *target=(void *)(&pExecOrder);
	*((const CWriteableExecOrder **)target)=pFactory->findByExecOrderID(ExecOrderSysID);
	return pExecOrder;
}

#endif


