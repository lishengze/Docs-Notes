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

///64位无符号整数比较函数
///@param	v1	整数1
///@param	v2	整数2
///@return	1表示大于，0表示等于，-1表示小于
int compare(const QWORD v1,const QWORD v2);

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

class CWriteableSysInvalidateOrder;
class CSysInvalidateOrderFactory;
class CWriteableSysOrderStatus;
class CSysOrderStatusFactory;
class CWriteableSysBargainOrder;
class CSysBargainOrderFactory;
class CWriteableSysInstProperty;
class CSysInstPropertyFactory;
class CWriteableSysMarginRate;
class CSysMarginRateFactory;
class CWriteableSysPriceLimit;
class CSysPriceLimitFactory;
class CWriteableSysPartPosiLimit;
class CSysPartPosiLimitFactory;
class CWriteableSysClientPosiLimit;
class CSysClientPosiLimitFactory;
class CWriteableSysSpecialPosiLimit;
class CSysSpecialPosiLimitFactory;
class CWriteableSysTransactionChg;
class CSysTransactionChgFactory;
class CWriteableSysClientChg;
class CSysClientChgFactory;
class CWriteableSysPartClientChg;
class CSysPartClientChgFactory;
class CWriteableSysPosiLimitChg;
class CSysPosiLimitChgFactory;
class CWriteableSysClientPosiLimitChg;
class CSysClientPosiLimitChgFactory;
class CWriteableSysSpecPosiLimitChg;
class CSysSpecPosiLimitChgFactory;
class CWriteableSysHedgeDetailChg;
class CSysHedgeDetailChgFactory;
class CWriteableSysParticipantChg;
class CSysParticipantChgFactory;
class CWriteableSysMarginRateChg;
class CSysMarginRateChgFactory;
class CWriteableSysUserIpChg;
class CSysUserIpChgFactory;
class CWriteableSysPartTrade;
class CSysPartTradeFactory;
class CWriteableSysMdbObjectAttr;
class CSysMdbObjectAttrFactory;
class CWriteableSysMdbSyslogInfo;
class CSysMdbSyslogInfoFactory;
class CWriteableSysUserInfo;
class CSysUserInfoFactory;
class CWriteableSysOnlineUserInfo;
class CSysOnlineUserInfoFactory;
class CWriteableSysWarningEvent;
class CSysWarningEventFactory;
class CWriteableSysWarningQuery;
class CSysWarningQueryFactory;
class CWriteableSyslogEvent;
class CSyslogEventFactory;
class CWriteableSysEventDescrip;
class CSysEventDescripFactory;
class CWriteableRspQryHostEnvCommon;
class CRspQryHostEnvCommonFactory;
class CWriteableRspQryHostEnvLan;
class CRspQryHostEnvLanFactory;
class CWriteableRspQryHostEnvStorage;
class CRspQryHostEnvStorageFactory;
class CWriteableRspQryHostEnvIO;
class CRspQryHostEnvIOFactory;
class CWriteableRspQryHostEnvFS;
class CRspQryHostEnvFSFactory;
class CWriteableRspQryHostEnvSwap;
class CRspQryHostEnvSwapFactory;
class CWriteableRspQryHostEnvLanCfg;
class CRspQryHostEnvLanCfgFactory;
class CWriteableSysMdbTopCpuInfo;
class CSysMdbTopCpuInfoFactory;
class CWriteableSysMdbTopMemInfo;
class CSysMdbTopMemInfoFactory;
class CWriteableSysMdbTopProcessInfo;
class CSysMdbTopProcessInfoFactory;
class CWriteableSysMdbFileSystemInfo;
class CSysMdbFileSystemInfoFactory;
class CWriteableSysMdbNetworkInfo;
class CSysMdbNetworkInfoFactory;
class CWriteableSysParticipantInit;
class CSysParticipantInitFactory;
class CWriteableSysUserInit;
class CSysUserInitFactory;
class CWriteableSysClientInit;
class CSysClientInitFactory;
class CWriteableSysTradeUserLoginInfo;
class CSysTradeUserLoginInfoFactory;
class CWriteableSysMdbWebAppInfo;
class CSysMdbWebAppInfoFactory;
class CWriteableSysMdbMemPoolInfo;
class CSysMdbMemPoolInfoFactory;
class CWriteableSysMdbConnectorInfo;
class CSysMdbConnectorInfoFactory;
class CWriteableSysMdbDBQuery;
class CSysMdbDBQueryFactory;
class CWriteableSysNetArea;
class CSysNetAreaFactory;
class CWriteableSysNetSubArea;
class CSysNetSubAreaFactory;
class CWriteableSysNetSubAreaIP;
class CSysNetSubAreaIPFactory;
class CWriteableSysNetFuncArea;
class CSysNetFuncAreaFactory;
class CWriteableSysNetDevice;
class CSysNetDeviceFactory;
class CWriteableSysNetDeviceLinked;
class CSysNetDeviceLinkedFactory;
class CWriteableSysNetOID;
class CSysNetOIDFactory;
class CWriteableSysNetDeviceType;
class CSysNetDeviceTypeFactory;
class CWriteableSysNetTimePolicy;
class CSysNetTimePolicyFactory;
class CWriteableSysNetGatherTask;
class CSysNetGatherTaskFactory;
class CWriteableSysNetDeviceCategory;
class CSysNetDeviceCategoryFactory;
class CWriteableSysNetManufactory;
class CSysNetManufactoryFactory;
class CWriteableSysNetCommunity;
class CSysNetCommunityFactory;
class CWriteableSysNetPortType;
class CSysNetPortTypeFactory;
class CWriteableSysNetInterface;
class CSysNetInterfaceFactory;
class CWriteableSysNetGeneralOID;
class CSysNetGeneralOIDFactory;
class CWriteableSysNetMonitorType;
class CSysNetMonitorTypeFactory;
class CWriteableSysNetMonitorAttrScope;
class CSysNetMonitorAttrScopeFactory;
class CWriteableSysNetMonitorAttrType;
class CSysNetMonitorAttrTypeFactory;
class CWriteableSysNetMonitorCommandType;
class CSysNetMonitorCommandTypeFactory;
class CWriteableSysNetMonitorActionGroup;
class CSysNetMonitorActionGroupFactory;
class CWriteableSysNetMonitorDeviceGroup;
class CSysNetMonitorDeviceGroupFactory;
class CWriteableSysNetMonitorTaskInfo;
class CSysNetMonitorTaskInfoFactory;
class CWriteableSysNetMonitorTaskObjectSet;
class CSysNetMonitorTaskObjectSetFactory;
class CWriteableSysNetMonitorTaskResult;
class CSysNetMonitorTaskResultFactory;
class CWriteableSysNetPartyLinkInfo;
class CSysNetPartyLinkInfoFactory;
class CWriteableSysNetDelPartyLinkInfo;
class CSysNetDelPartyLinkInfoFactory;
class CWriteableSysNetPartyLinkAddrChange;
class CSysNetPartyLinkAddrChangeFactory;
class CWriteableSysNetMonitorActionAttr;
class CSysNetMonitorActionAttrFactory;
class CWriteableSysNetModule;
class CSysNetModuleFactory;
class CWriteableSysNetEventExpr;
class CSysNetEventExprFactory;
class CWriteableSysNetEventType;
class CSysNetEventTypeFactory;
class CWriteableSysNetSubEventType;
class CSysNetSubEventTypeFactory;
class CWriteableSysNetEventLevel;
class CSysNetEventLevelFactory;
class CWriteableSysNetMonitorDeviceTask;
class CSysNetMonitorDeviceTaskFactory;
class CWriteableSysNetMonitorTaskInstAttrs;
class CSysNetMonitorTaskInstAttrsFactory;
class CWriteableSysNetBaseLine;
class CSysNetBaseLineFactory;
class CWriteableSysNetBaseLineTask;
class CSysNetBaseLineTaskFactory;
class CWriteableSysMdbNetPartyLinkStatusInfo;
class CSysMdbNetPartyLinkStatusInfoFactory;
class CWriteableSysNetMemberSDHLineInfo;
class CSysNetMemberSDHLineInfoFactory;
class CWriteableSysNetDDNLinkInfo;
class CSysNetDDNLinkInfoFactory;
class CWriteableSysNetPseudMemberLinkInfo;
class CSysNetPseudMemberLinkInfoFactory;
class CWriteableSysNetOuterDeviceInfo;
class CSysNetOuterDeviceInfoFactory;
class CWriteableSysLocalPingResultInfo;
class CSysLocalPingResultInfoFactory;
class CWriteableSysRomotePingResultInfo;
class CSysRomotePingResultInfoFactory;
class CWriteableSysParticTradeOrderStates;
class CSysParticTradeOrderStatesFactory;
class CWriteableSysMdbRouterInfo;
class CSysMdbRouterInfoFactory;
class CWriteableSysMdbDiskIO;
class CSysMdbDiskIOFactory;
class CWriteableSysMdbStatInfo;
class CSysMdbStatInfoFactory;
class CWriteableSysMdbTradeFrontOrderRttStat;
class CSysMdbTradeFrontOrderRttStatFactory;
class CWriteableSysInstrumentStatus;
class CSysInstrumentStatusFactory;
class CWriteableSysCurrTradingSegmentAttr;
class CSysCurrTradingSegmentAttrFactory;
class CWriteableSysMemberLinkCost;
class CSysMemberLinkCostFactory;
class CWriteableSysNetPartylinkMonthlyRent;
class CSysNetPartylinkMonthlyRentFactory;
class CWriteableSysNetNonPartyLinkInfo;
class CSysNetNonPartyLinkInfoFactory;

/////////////////////////////////////////////////////////////////////////
///CWriteableSysInvalidateOrder是一个存储无效报单的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysInvalidateOrder
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! ErrorMsg.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! InstrumentID.isValid())
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
		if (! VolumeCondition.isValid())
			return 0;
		if (! MinVolume.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysInvalidateOrder *pOriginal) const;
	
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
	///插入日期
	CDateType ActionDate;
	///插入时间
	CTimeType ActionTime;
	///错误信息
	CErrorMsgType ErrorMsg;
	///会员代码
	CParticipantIDType ParticipantID;
	///交易用户代码
	CUserIDType UserID;
	///客户代码
	CClientIDType ClientID;
	///合约代码
	CInstrumentIDType InstrumentID;
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
	///成交量类型
	CVolumeConditionType VolumeCondition;
	///最小成交量
	CVolumeType MinVolume;
	
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

typedef const CWriteableSysInvalidateOrder CSysInvalidateOrder;

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderActionTrigger是操作无效报单时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderActionTrigger
{
public:
	///构造方法
	CSysInvalidateOrderActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysInvalidateOrderActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysInvalidateOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysInvalidateOrder	要加入的SysInvalidateOrder
	virtual void beforeAdd(CWriteableSysInvalidateOrder *pSysInvalidateOrder)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysInvalidateOrder	已经加入的SysInvalidateOrder
	virtual void afterAdd(CSysInvalidateOrder *pSysInvalidateOrder)
	{
		return;
	}

	///更新前触发	
	///@param	pSysInvalidateOrder	被刷新的CSysInvalidateOrder
	///@param	pNewSysInvalidateOrder	新的值
	virtual void beforeUpdate(CSysInvalidateOrder *pSysInvalidateOrder, CWriteableSysInvalidateOrder *pNewSysInvalidateOrder)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysInvalidateOrder	被刷新的CSysInvalidateOrder
	virtual void afterUpdate(CSysInvalidateOrder *pSysInvalidateOrder)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysInvalidateOrder	要删除的CSysInvalidateOrder
	virtual void beforeRemove(CSysInvalidateOrder *pSysInvalidateOrder)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysInvalidateOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderCommitTrigger是确认无效报单时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderCommitTrigger
{
public:
	///构造方法
	CSysInvalidateOrderCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysInvalidateOrderCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysInvalidateOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysInvalidateOrder	已经加入的SysInvalidateOrder
	virtual void commitAdd(CSysInvalidateOrder *pSysInvalidateOrder)
	{
		return;
	}

	///更新后触发
	///@param	pSysInvalidateOrder	被刷新的CSysInvalidateOrder
	///@param	poldSysInvalidateOrder	原来的值
	virtual void commitUpdate(CSysInvalidateOrder *pSysInvalidateOrder, CWriteableSysInvalidateOrder *pOldSysInvalidateOrder)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysInvalidateOrder	已经删除的CSysInvalidateOrder
	virtual void commitRemove(CWriteableSysInvalidateOrder *pSysInvalidateOrder)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysInvalidateOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderIterator是一个对无效报单的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderIterator
{
public:
	///构造方法
	CSysInvalidateOrderIterator(void)
	{
	}

	///构造方法
	CSysInvalidateOrderIterator(CSysInvalidateOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysInvalidateOrderIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysInvalidateOrder
	///@return	下一个满足条件CSysInvalidateOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CSysInvalidateOrder *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysInvalidateOrderFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysInvalidateOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysInvalidateOrder * pSysInvalidateOrder,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysInvalidateOrderFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysOrderStatus是一个存储报单状态的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysOrderStatus
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! OrderSysID.isValid())
			return 0;
		if (! OrderLocalID.isValid())
			return 0;
		if (! InsertDate.isValid())
			return 0;
		if (! InsertTime.isValid())
			return 0;
		if (! OrderStatus.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! InstrumentID.isValid())
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
		if (! VolumeCondition.isValid())
			return 0;
		if (! MinVolume.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysOrderStatus *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///报单编号
	COrderSysIDType OrderSysID;
	///本地报单编号
	COrderLocalIDType OrderLocalID;
	///报单日期
	CDateType InsertDate;
	///插入时间
	CTimeType InsertTime;
	///报单状态
	COrderStatusType OrderStatus;
	///会员代码
	CParticipantIDType ParticipantID;
	///交易用户代码
	CUserIDType UserID;
	///客户代码
	CClientIDType ClientID;
	///合约代码
	CInstrumentIDType InstrumentID;
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
	///成交量类型
	CVolumeConditionType VolumeCondition;
	///最小成交量
	CVolumeType MinVolume;
	
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

typedef const CWriteableSysOrderStatus CSysOrderStatus;

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusActionTrigger是操作报单状态时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusActionTrigger
{
public:
	///构造方法
	CSysOrderStatusActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysOrderStatusActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysOrderStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysOrderStatus	要加入的SysOrderStatus
	virtual void beforeAdd(CWriteableSysOrderStatus *pSysOrderStatus)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysOrderStatus	已经加入的SysOrderStatus
	virtual void afterAdd(CSysOrderStatus *pSysOrderStatus)
	{
		return;
	}

	///更新前触发	
	///@param	pSysOrderStatus	被刷新的CSysOrderStatus
	///@param	pNewSysOrderStatus	新的值
	virtual void beforeUpdate(CSysOrderStatus *pSysOrderStatus, CWriteableSysOrderStatus *pNewSysOrderStatus)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysOrderStatus	被刷新的CSysOrderStatus
	virtual void afterUpdate(CSysOrderStatus *pSysOrderStatus)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysOrderStatus	要删除的CSysOrderStatus
	virtual void beforeRemove(CSysOrderStatus *pSysOrderStatus)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysOrderStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusCommitTrigger是确认报单状态时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusCommitTrigger
{
public:
	///构造方法
	CSysOrderStatusCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysOrderStatusCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysOrderStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysOrderStatus	已经加入的SysOrderStatus
	virtual void commitAdd(CSysOrderStatus *pSysOrderStatus)
	{
		return;
	}

	///更新后触发
	///@param	pSysOrderStatus	被刷新的CSysOrderStatus
	///@param	poldSysOrderStatus	原来的值
	virtual void commitUpdate(CSysOrderStatus *pSysOrderStatus, CWriteableSysOrderStatus *pOldSysOrderStatus)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysOrderStatus	已经删除的CSysOrderStatus
	virtual void commitRemove(CWriteableSysOrderStatus *pSysOrderStatus)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysOrderStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusIterator是一个对报单状态的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusIterator
{
public:
	///构造方法
	CSysOrderStatusIterator(void)
	{
	}

	///构造方法
	CSysOrderStatusIterator(CSysOrderStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysOrderStatusIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysOrderStatus
	///@return	下一个满足条件CSysOrderStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSysOrderStatus *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysOrderStatusFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysOrderStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysOrderStatus * pSysOrderStatus,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysOrderStatusFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysBargainOrder是一个存储报单成交的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysBargainOrder
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! TradeID.isValid())
			return 0;
		if (! OrderSysID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! Price.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! UserID.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysBargainOrder *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///成交日期
	CDateType ActionDate;
	///成交时间
	CTimeType ActionTime;
	///成交编号
	CTradeIDType TradeID;
	///报单编号
	COrderSysIDType OrderSysID;
	///合约代码
	CInstrumentIDType InstrumentID;
	///价格
	CPriceType Price;
	///数量
	CVolumeType Volume;
	///会员代码
	CParticipantIDType ParticipantID;
	///交易用户代码
	CUserIDType UserID;
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

typedef const CWriteableSysBargainOrder CSysBargainOrder;

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderActionTrigger是操作报单成交时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderActionTrigger
{
public:
	///构造方法
	CSysBargainOrderActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysBargainOrderActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysBargainOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysBargainOrder	要加入的SysBargainOrder
	virtual void beforeAdd(CWriteableSysBargainOrder *pSysBargainOrder)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysBargainOrder	已经加入的SysBargainOrder
	virtual void afterAdd(CSysBargainOrder *pSysBargainOrder)
	{
		return;
	}

	///更新前触发	
	///@param	pSysBargainOrder	被刷新的CSysBargainOrder
	///@param	pNewSysBargainOrder	新的值
	virtual void beforeUpdate(CSysBargainOrder *pSysBargainOrder, CWriteableSysBargainOrder *pNewSysBargainOrder)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysBargainOrder	被刷新的CSysBargainOrder
	virtual void afterUpdate(CSysBargainOrder *pSysBargainOrder)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysBargainOrder	要删除的CSysBargainOrder
	virtual void beforeRemove(CSysBargainOrder *pSysBargainOrder)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysBargainOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderCommitTrigger是确认报单成交时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderCommitTrigger
{
public:
	///构造方法
	CSysBargainOrderCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysBargainOrderCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysBargainOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysBargainOrder	已经加入的SysBargainOrder
	virtual void commitAdd(CSysBargainOrder *pSysBargainOrder)
	{
		return;
	}

	///更新后触发
	///@param	pSysBargainOrder	被刷新的CSysBargainOrder
	///@param	poldSysBargainOrder	原来的值
	virtual void commitUpdate(CSysBargainOrder *pSysBargainOrder, CWriteableSysBargainOrder *pOldSysBargainOrder)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysBargainOrder	已经删除的CSysBargainOrder
	virtual void commitRemove(CWriteableSysBargainOrder *pSysBargainOrder)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysBargainOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderIterator是一个对报单成交的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderIterator
{
public:
	///构造方法
	CSysBargainOrderIterator(void)
	{
	}

	///构造方法
	CSysBargainOrderIterator(CSysBargainOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysBargainOrderIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysBargainOrder
	///@return	下一个满足条件CSysBargainOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CSysBargainOrder *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysBargainOrderFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysBargainOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysBargainOrder * pSysBargainOrder,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysBargainOrderFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysInstProperty是一个存储合约基本属性的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysInstProperty
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! UnderlyingInstrID.isValid())
			return 0;
		if (! ProductClass.isValid())
			return 0;
		if (! PositionType.isValid())
			return 0;
		if (! VolumeMultiple.isValid())
			return 0;
		if (! UnderlyingMultiple.isValid())
			return 0;
		if (! InstLifePhase.isValid())
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
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableSysInstProperty *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///合约代码
	CInstrumentIDType InstrumentID;
	///结算组代码
	CSettlementGroupIDType SettlementGroupID;
	///基础商品代码
	CInstrumentIDType UnderlyingInstrID;
	///产品类型
	CProductClassType ProductClass;
	///持仓类型
	CPositionTypeType PositionType;
	///合约数量乘数
	CVolumeMultipleType VolumeMultiple;
	///合约基础商品乘数
	CUnderlyingMultipleType UnderlyingMultiple;
	///合约生命周期状态
	CInstLifePhaseType InstLifePhase;
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

typedef const CWriteableSysInstProperty CSysInstProperty;

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyActionTrigger是操作合约基本属性时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyActionTrigger
{
public:
	///构造方法
	CSysInstPropertyActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysInstPropertyActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysInstPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysInstProperty	要加入的SysInstProperty
	virtual void beforeAdd(CWriteableSysInstProperty *pSysInstProperty)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysInstProperty	已经加入的SysInstProperty
	virtual void afterAdd(CSysInstProperty *pSysInstProperty)
	{
		return;
	}

	///更新前触发	
	///@param	pSysInstProperty	被刷新的CSysInstProperty
	///@param	pNewSysInstProperty	新的值
	virtual void beforeUpdate(CSysInstProperty *pSysInstProperty, CWriteableSysInstProperty *pNewSysInstProperty)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysInstProperty	被刷新的CSysInstProperty
	virtual void afterUpdate(CSysInstProperty *pSysInstProperty)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysInstProperty	要删除的CSysInstProperty
	virtual void beforeRemove(CSysInstProperty *pSysInstProperty)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysInstPropertyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyCommitTrigger是确认合约基本属性时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyCommitTrigger
{
public:
	///构造方法
	CSysInstPropertyCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysInstPropertyCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysInstPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysInstProperty	已经加入的SysInstProperty
	virtual void commitAdd(CSysInstProperty *pSysInstProperty)
	{
		return;
	}

	///更新后触发
	///@param	pSysInstProperty	被刷新的CSysInstProperty
	///@param	poldSysInstProperty	原来的值
	virtual void commitUpdate(CSysInstProperty *pSysInstProperty, CWriteableSysInstProperty *pOldSysInstProperty)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysInstProperty	已经删除的CSysInstProperty
	virtual void commitRemove(CWriteableSysInstProperty *pSysInstProperty)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysInstPropertyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyIterator是一个对合约基本属性的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyIterator
{
public:
	///构造方法
	CSysInstPropertyIterator(void)
	{
	}

	///构造方法
	CSysInstPropertyIterator(CSysInstPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysInstPropertyIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysInstProperty
	///@return	下一个满足条件CSysInstProperty，如果已经没有一个满足要求了，则返回NULL
	virtual CSysInstProperty *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysInstPropertyFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysInstProperty 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysInstProperty * pSysInstProperty,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysInstPropertyFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMarginRate是一个存储合约保证金率的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMarginRate
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
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
		return 1;
	}

	///将内容写到文件中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///将内容写入文件，突出显示变化的内容
	///@param	fp	要写出的文件,NULL表示stdout
	///@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CWriteableSysMarginRate *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///合约代码
	CInstrumentIDType InstrumentID;
	///会员代码
	CParticipantIDType ParticipantID;
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

typedef const CWriteableSysMarginRate CSysMarginRate;

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateActionTrigger是操作合约保证金率时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateActionTrigger
{
public:
	///构造方法
	CSysMarginRateActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMarginRateActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMarginRateFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMarginRate	要加入的SysMarginRate
	virtual void beforeAdd(CWriteableSysMarginRate *pSysMarginRate)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMarginRate	已经加入的SysMarginRate
	virtual void afterAdd(CSysMarginRate *pSysMarginRate)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMarginRate	被刷新的CSysMarginRate
	///@param	pNewSysMarginRate	新的值
	virtual void beforeUpdate(CSysMarginRate *pSysMarginRate, CWriteableSysMarginRate *pNewSysMarginRate)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMarginRate	被刷新的CSysMarginRate
	virtual void afterUpdate(CSysMarginRate *pSysMarginRate)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMarginRate	要删除的CSysMarginRate
	virtual void beforeRemove(CSysMarginRate *pSysMarginRate)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMarginRateFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateCommitTrigger是确认合约保证金率时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateCommitTrigger
{
public:
	///构造方法
	CSysMarginRateCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMarginRateCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMarginRateFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMarginRate	已经加入的SysMarginRate
	virtual void commitAdd(CSysMarginRate *pSysMarginRate)
	{
		return;
	}

	///更新后触发
	///@param	pSysMarginRate	被刷新的CSysMarginRate
	///@param	poldSysMarginRate	原来的值
	virtual void commitUpdate(CSysMarginRate *pSysMarginRate, CWriteableSysMarginRate *pOldSysMarginRate)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMarginRate	已经删除的CSysMarginRate
	virtual void commitRemove(CWriteableSysMarginRate *pSysMarginRate)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMarginRateFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateIterator是一个对合约保证金率的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateIterator
{
public:
	///构造方法
	CSysMarginRateIterator(void)
	{
	}

	///构造方法
	CSysMarginRateIterator(CSysMarginRateFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMarginRateIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMarginRate
	///@return	下一个满足条件CSysMarginRate，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMarginRate *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMarginRateFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMarginRate 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMarginRate * pSysMarginRate,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMarginRateFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysPriceLimit是一个存储合约涨跌停板的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysPriceLimit
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! RoundingMode.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysPriceLimit *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///合约代码
	CInstrumentIDType InstrumentID;
	///取值方式
	CValueModeType ValueMode;
	///舍入方式
	CRoundingModeType RoundingMode;
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

typedef const CWriteableSysPriceLimit CSysPriceLimit;

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitActionTrigger是操作合约涨跌停板时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitActionTrigger
{
public:
	///构造方法
	CSysPriceLimitActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysPriceLimitActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysPriceLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysPriceLimit	要加入的SysPriceLimit
	virtual void beforeAdd(CWriteableSysPriceLimit *pSysPriceLimit)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysPriceLimit	已经加入的SysPriceLimit
	virtual void afterAdd(CSysPriceLimit *pSysPriceLimit)
	{
		return;
	}

	///更新前触发	
	///@param	pSysPriceLimit	被刷新的CSysPriceLimit
	///@param	pNewSysPriceLimit	新的值
	virtual void beforeUpdate(CSysPriceLimit *pSysPriceLimit, CWriteableSysPriceLimit *pNewSysPriceLimit)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysPriceLimit	被刷新的CSysPriceLimit
	virtual void afterUpdate(CSysPriceLimit *pSysPriceLimit)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysPriceLimit	要删除的CSysPriceLimit
	virtual void beforeRemove(CSysPriceLimit *pSysPriceLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysPriceLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitCommitTrigger是确认合约涨跌停板时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitCommitTrigger
{
public:
	///构造方法
	CSysPriceLimitCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysPriceLimitCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysPriceLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysPriceLimit	已经加入的SysPriceLimit
	virtual void commitAdd(CSysPriceLimit *pSysPriceLimit)
	{
		return;
	}

	///更新后触发
	///@param	pSysPriceLimit	被刷新的CSysPriceLimit
	///@param	poldSysPriceLimit	原来的值
	virtual void commitUpdate(CSysPriceLimit *pSysPriceLimit, CWriteableSysPriceLimit *pOldSysPriceLimit)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysPriceLimit	已经删除的CSysPriceLimit
	virtual void commitRemove(CWriteableSysPriceLimit *pSysPriceLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysPriceLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitIterator是一个对合约涨跌停板的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitIterator
{
public:
	///构造方法
	CSysPriceLimitIterator(void)
	{
	}

	///构造方法
	CSysPriceLimitIterator(CSysPriceLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysPriceLimitIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysPriceLimit
	///@return	下一个满足条件CSysPriceLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPriceLimit *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysPriceLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysPriceLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPriceLimit * pSysPriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysPriceLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysPartPosiLimit是一个存储会员限仓的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysPartPosiLimit
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysPartPosiLimit *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///合约代码
	CInstrumentIDType InstrumentID;
	///会员代码
	CParticipantIDType ParticipantID;
	///交易角色
	CPositionTradingRoleType TradingRole;
	///限仓起点
	CLargeVolumeType StartTotalPosition;
	///取值方式
	CValueModeType ValueMode;
	///多头限仓
	CRatioType LongPosLimit;
	///空头限仓
	CRatioType ShortPosLimit;
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

typedef const CWriteableSysPartPosiLimit CSysPartPosiLimit;

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitActionTrigger是操作会员限仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitActionTrigger
{
public:
	///构造方法
	CSysPartPosiLimitActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysPartPosiLimitActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysPartPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysPartPosiLimit	要加入的SysPartPosiLimit
	virtual void beforeAdd(CWriteableSysPartPosiLimit *pSysPartPosiLimit)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysPartPosiLimit	已经加入的SysPartPosiLimit
	virtual void afterAdd(CSysPartPosiLimit *pSysPartPosiLimit)
	{
		return;
	}

	///更新前触发	
	///@param	pSysPartPosiLimit	被刷新的CSysPartPosiLimit
	///@param	pNewSysPartPosiLimit	新的值
	virtual void beforeUpdate(CSysPartPosiLimit *pSysPartPosiLimit, CWriteableSysPartPosiLimit *pNewSysPartPosiLimit)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysPartPosiLimit	被刷新的CSysPartPosiLimit
	virtual void afterUpdate(CSysPartPosiLimit *pSysPartPosiLimit)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysPartPosiLimit	要删除的CSysPartPosiLimit
	virtual void beforeRemove(CSysPartPosiLimit *pSysPartPosiLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysPartPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitCommitTrigger是确认会员限仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitCommitTrigger
{
public:
	///构造方法
	CSysPartPosiLimitCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysPartPosiLimitCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysPartPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysPartPosiLimit	已经加入的SysPartPosiLimit
	virtual void commitAdd(CSysPartPosiLimit *pSysPartPosiLimit)
	{
		return;
	}

	///更新后触发
	///@param	pSysPartPosiLimit	被刷新的CSysPartPosiLimit
	///@param	poldSysPartPosiLimit	原来的值
	virtual void commitUpdate(CSysPartPosiLimit *pSysPartPosiLimit, CWriteableSysPartPosiLimit *pOldSysPartPosiLimit)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysPartPosiLimit	已经删除的CSysPartPosiLimit
	virtual void commitRemove(CWriteableSysPartPosiLimit *pSysPartPosiLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysPartPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitIterator是一个对会员限仓的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitIterator
{
public:
	///构造方法
	CSysPartPosiLimitIterator(void)
	{
	}

	///构造方法
	CSysPartPosiLimitIterator(CSysPartPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysPartPosiLimitIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysPartPosiLimit
	///@return	下一个满足条件CSysPartPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPartPosiLimit *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysPartPosiLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysPartPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPartPosiLimit * pSysPartPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysPartPosiLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysClientPosiLimit是一个存储客户限仓的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysClientPosiLimit
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ClientType.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysClientPosiLimit *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///合约代码
	CInstrumentIDType InstrumentID;
	///客户类型
	CClientTypeType ClientType;
	///交易角色
	CPositionTradingRoleType TradingRole;
	///限仓起点
	CLargeVolumeType StartTotalPosition;
	///取值方式
	CValueModeType ValueMode;
	///多头限仓
	CRatioType LongPosLimit;
	///空头限仓
	CRatioType ShortPosLimit;
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

typedef const CWriteableSysClientPosiLimit CSysClientPosiLimit;

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitActionTrigger是操作客户限仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitActionTrigger
{
public:
	///构造方法
	CSysClientPosiLimitActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysClientPosiLimitActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysClientPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysClientPosiLimit	要加入的SysClientPosiLimit
	virtual void beforeAdd(CWriteableSysClientPosiLimit *pSysClientPosiLimit)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysClientPosiLimit	已经加入的SysClientPosiLimit
	virtual void afterAdd(CSysClientPosiLimit *pSysClientPosiLimit)
	{
		return;
	}

	///更新前触发	
	///@param	pSysClientPosiLimit	被刷新的CSysClientPosiLimit
	///@param	pNewSysClientPosiLimit	新的值
	virtual void beforeUpdate(CSysClientPosiLimit *pSysClientPosiLimit, CWriteableSysClientPosiLimit *pNewSysClientPosiLimit)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysClientPosiLimit	被刷新的CSysClientPosiLimit
	virtual void afterUpdate(CSysClientPosiLimit *pSysClientPosiLimit)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysClientPosiLimit	要删除的CSysClientPosiLimit
	virtual void beforeRemove(CSysClientPosiLimit *pSysClientPosiLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysClientPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitCommitTrigger是确认客户限仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitCommitTrigger
{
public:
	///构造方法
	CSysClientPosiLimitCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysClientPosiLimitCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysClientPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysClientPosiLimit	已经加入的SysClientPosiLimit
	virtual void commitAdd(CSysClientPosiLimit *pSysClientPosiLimit)
	{
		return;
	}

	///更新后触发
	///@param	pSysClientPosiLimit	被刷新的CSysClientPosiLimit
	///@param	poldSysClientPosiLimit	原来的值
	virtual void commitUpdate(CSysClientPosiLimit *pSysClientPosiLimit, CWriteableSysClientPosiLimit *pOldSysClientPosiLimit)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysClientPosiLimit	已经删除的CSysClientPosiLimit
	virtual void commitRemove(CWriteableSysClientPosiLimit *pSysClientPosiLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysClientPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitIterator是一个对客户限仓的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitIterator
{
public:
	///构造方法
	CSysClientPosiLimitIterator(void)
	{
	}

	///构造方法
	CSysClientPosiLimitIterator(CSysClientPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysClientPosiLimitIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysClientPosiLimit
	///@return	下一个满足条件CSysClientPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientPosiLimit *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysClientPosiLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysClientPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientPosiLimit * pSysClientPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysClientPosiLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysSpecialPosiLimit是一个存储特殊客户限仓的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysSpecialPosiLimit
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysSpecialPosiLimit *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///合约代码
	CInstrumentIDType InstrumentID;
	///客户代码
	CClientIDType ClientID;
	///交易角色
	CPositionTradingRoleType TradingRole;
	///限仓起点
	CLargeVolumeType StartTotalPosition;
	///取值方式
	CValueModeType ValueMode;
	///多头限仓
	CRatioType LongPosLimit;
	///空头限仓
	CRatioType ShortPosLimit;
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

typedef const CWriteableSysSpecialPosiLimit CSysSpecialPosiLimit;

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitActionTrigger是操作特殊客户限仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitActionTrigger
{
public:
	///构造方法
	CSysSpecialPosiLimitActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysSpecialPosiLimitActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysSpecialPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysSpecialPosiLimit	要加入的SysSpecialPosiLimit
	virtual void beforeAdd(CWriteableSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysSpecialPosiLimit	已经加入的SysSpecialPosiLimit
	virtual void afterAdd(CSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return;
	}

	///更新前触发	
	///@param	pSysSpecialPosiLimit	被刷新的CSysSpecialPosiLimit
	///@param	pNewSysSpecialPosiLimit	新的值
	virtual void beforeUpdate(CSysSpecialPosiLimit *pSysSpecialPosiLimit, CWriteableSysSpecialPosiLimit *pNewSysSpecialPosiLimit)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysSpecialPosiLimit	被刷新的CSysSpecialPosiLimit
	virtual void afterUpdate(CSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysSpecialPosiLimit	要删除的CSysSpecialPosiLimit
	virtual void beforeRemove(CSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysSpecialPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitCommitTrigger是确认特殊客户限仓时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitCommitTrigger
{
public:
	///构造方法
	CSysSpecialPosiLimitCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysSpecialPosiLimitCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysSpecialPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysSpecialPosiLimit	已经加入的SysSpecialPosiLimit
	virtual void commitAdd(CSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return;
	}

	///更新后触发
	///@param	pSysSpecialPosiLimit	被刷新的CSysSpecialPosiLimit
	///@param	poldSysSpecialPosiLimit	原来的值
	virtual void commitUpdate(CSysSpecialPosiLimit *pSysSpecialPosiLimit, CWriteableSysSpecialPosiLimit *pOldSysSpecialPosiLimit)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysSpecialPosiLimit	已经删除的CSysSpecialPosiLimit
	virtual void commitRemove(CWriteableSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysSpecialPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitIterator是一个对特殊客户限仓的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitIterator
{
public:
	///构造方法
	CSysSpecialPosiLimitIterator(void)
	{
	}

	///构造方法
	CSysSpecialPosiLimitIterator(CSysSpecialPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysSpecialPosiLimitIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysSpecialPosiLimit
	///@return	下一个满足条件CSysSpecialPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysSpecialPosiLimit *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysSpecialPosiLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysSpecialPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysSpecialPosiLimit * pSysSpecialPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysSpecialPosiLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysTransactionChg是一个存储账户出入金查询的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysTransactionChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! BillSN.isValid())
			return 0;
		if (! ParticipantAccount.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! Amount.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysTransactionChg *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///帐户往来流水号
	CSerialNoType BillSN;
	///资金账户
	CAccountIDType ParticipantAccount;
	///会员代码
	CParticipantIDType ParticipantID;
	///发生额
	CMoneyType Amount;
	
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

typedef const CWriteableSysTransactionChg CSysTransactionChg;

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgActionTrigger是操作账户出入金查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgActionTrigger
{
public:
	///构造方法
	CSysTransactionChgActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysTransactionChgActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysTransactionChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysTransactionChg	要加入的SysTransactionChg
	virtual void beforeAdd(CWriteableSysTransactionChg *pSysTransactionChg)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysTransactionChg	已经加入的SysTransactionChg
	virtual void afterAdd(CSysTransactionChg *pSysTransactionChg)
	{
		return;
	}

	///更新前触发	
	///@param	pSysTransactionChg	被刷新的CSysTransactionChg
	///@param	pNewSysTransactionChg	新的值
	virtual void beforeUpdate(CSysTransactionChg *pSysTransactionChg, CWriteableSysTransactionChg *pNewSysTransactionChg)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysTransactionChg	被刷新的CSysTransactionChg
	virtual void afterUpdate(CSysTransactionChg *pSysTransactionChg)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysTransactionChg	要删除的CSysTransactionChg
	virtual void beforeRemove(CSysTransactionChg *pSysTransactionChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysTransactionChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgCommitTrigger是确认账户出入金查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgCommitTrigger
{
public:
	///构造方法
	CSysTransactionChgCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysTransactionChgCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysTransactionChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysTransactionChg	已经加入的SysTransactionChg
	virtual void commitAdd(CSysTransactionChg *pSysTransactionChg)
	{
		return;
	}

	///更新后触发
	///@param	pSysTransactionChg	被刷新的CSysTransactionChg
	///@param	poldSysTransactionChg	原来的值
	virtual void commitUpdate(CSysTransactionChg *pSysTransactionChg, CWriteableSysTransactionChg *pOldSysTransactionChg)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysTransactionChg	已经删除的CSysTransactionChg
	virtual void commitRemove(CWriteableSysTransactionChg *pSysTransactionChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysTransactionChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgIterator是一个对账户出入金查询的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgIterator
{
public:
	///构造方法
	CSysTransactionChgIterator(void)
	{
	}

	///构造方法
	CSysTransactionChgIterator(CSysTransactionChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysTransactionChgIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysTransactionChg
	///@return	下一个满足条件CSysTransactionChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysTransactionChg *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysTransactionChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysTransactionChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysTransactionChg * pSysTransactionChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysTransactionChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysClientChg是一个存储客户数据变动查询的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysClientChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! ClientName.isValid())
			return 0;
		if (! ClientType.isValid())
			return 0;
		if (! IsActive.isValid())
			return 0;
		if (! IdentifiedCardType.isValid())
			return 0;
		if (! IdentifiedCardNo.isValid())
			return 0;
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysClientChg *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///客户代码
	CClientIDType ClientID;
	///客户名称
	CPartyNameType ClientName;
	///客户类型
	CClientTypeType ClientType;
	///是否活跃
	CBoolType IsActive;
	///证件类型
	CIdCardTypeType IdentifiedCardType;
	///证件号码
	CIdentifiedCardNoType IdentifiedCardNo;
	///操作类型
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysClientChg CSysClientChg;

/////////////////////////////////////////////////////////////////////////
///CSysClientChgActionTrigger是操作客户数据变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgActionTrigger
{
public:
	///构造方法
	CSysClientChgActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysClientChgActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysClientChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysClientChg	要加入的SysClientChg
	virtual void beforeAdd(CWriteableSysClientChg *pSysClientChg)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysClientChg	已经加入的SysClientChg
	virtual void afterAdd(CSysClientChg *pSysClientChg)
	{
		return;
	}

	///更新前触发	
	///@param	pSysClientChg	被刷新的CSysClientChg
	///@param	pNewSysClientChg	新的值
	virtual void beforeUpdate(CSysClientChg *pSysClientChg, CWriteableSysClientChg *pNewSysClientChg)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysClientChg	被刷新的CSysClientChg
	virtual void afterUpdate(CSysClientChg *pSysClientChg)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysClientChg	要删除的CSysClientChg
	virtual void beforeRemove(CSysClientChg *pSysClientChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysClientChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgCommitTrigger是确认客户数据变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgCommitTrigger
{
public:
	///构造方法
	CSysClientChgCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysClientChgCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysClientChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysClientChg	已经加入的SysClientChg
	virtual void commitAdd(CSysClientChg *pSysClientChg)
	{
		return;
	}

	///更新后触发
	///@param	pSysClientChg	被刷新的CSysClientChg
	///@param	poldSysClientChg	原来的值
	virtual void commitUpdate(CSysClientChg *pSysClientChg, CWriteableSysClientChg *pOldSysClientChg)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysClientChg	已经删除的CSysClientChg
	virtual void commitRemove(CWriteableSysClientChg *pSysClientChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysClientChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgIterator是一个对客户数据变动查询的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgIterator
{
public:
	///构造方法
	CSysClientChgIterator(void)
	{
	}

	///构造方法
	CSysClientChgIterator(CSysClientChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysClientChgIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysClientChg
	///@return	下一个满足条件CSysClientChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientChg *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysClientChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysClientChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientChg * pSysClientChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysClientChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysPartClientChg是一个存储会员客户对照变动查询的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysPartClientChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysPartClientChg *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///客户代码
	CClientIDType ClientID;
	///会员代码
	CParticipantIDType ParticipantID;
	///操作类型
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysPartClientChg CSysPartClientChg;

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgActionTrigger是操作会员客户对照变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgActionTrigger
{
public:
	///构造方法
	CSysPartClientChgActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysPartClientChgActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysPartClientChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysPartClientChg	要加入的SysPartClientChg
	virtual void beforeAdd(CWriteableSysPartClientChg *pSysPartClientChg)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysPartClientChg	已经加入的SysPartClientChg
	virtual void afterAdd(CSysPartClientChg *pSysPartClientChg)
	{
		return;
	}

	///更新前触发	
	///@param	pSysPartClientChg	被刷新的CSysPartClientChg
	///@param	pNewSysPartClientChg	新的值
	virtual void beforeUpdate(CSysPartClientChg *pSysPartClientChg, CWriteableSysPartClientChg *pNewSysPartClientChg)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysPartClientChg	被刷新的CSysPartClientChg
	virtual void afterUpdate(CSysPartClientChg *pSysPartClientChg)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysPartClientChg	要删除的CSysPartClientChg
	virtual void beforeRemove(CSysPartClientChg *pSysPartClientChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysPartClientChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgCommitTrigger是确认会员客户对照变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgCommitTrigger
{
public:
	///构造方法
	CSysPartClientChgCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysPartClientChgCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysPartClientChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysPartClientChg	已经加入的SysPartClientChg
	virtual void commitAdd(CSysPartClientChg *pSysPartClientChg)
	{
		return;
	}

	///更新后触发
	///@param	pSysPartClientChg	被刷新的CSysPartClientChg
	///@param	poldSysPartClientChg	原来的值
	virtual void commitUpdate(CSysPartClientChg *pSysPartClientChg, CWriteableSysPartClientChg *pOldSysPartClientChg)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysPartClientChg	已经删除的CSysPartClientChg
	virtual void commitRemove(CWriteableSysPartClientChg *pSysPartClientChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysPartClientChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgIterator是一个对会员客户对照变动查询的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgIterator
{
public:
	///构造方法
	CSysPartClientChgIterator(void)
	{
	}

	///构造方法
	CSysPartClientChgIterator(CSysPartClientChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysPartClientChgIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysPartClientChg
	///@return	下一个满足条件CSysPartClientChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPartClientChg *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysPartClientChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysPartClientChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPartClientChg * pSysPartClientChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysPartClientChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysPosiLimitChg是一个存储限仓数据变动查询的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysPosiLimitChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
			return 0;
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysPosiLimitChg *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///合约代码
	CInstrumentIDType InstrumentID;
	///会员代码
	CParticipantIDType ParticipantID;
	///交易角色
	CPositionTradingRoleType TradingRole;
	///限仓起点
	CLargeVolumeType StartTotalPosition;
	///取值方式
	CValueModeType ValueMode;
	///多头限仓
	CRatioType LongPosLimit;
	///空头限仓
	CRatioType ShortPosLimit;
	///操作类型
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysPosiLimitChg CSysPosiLimitChg;

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgActionTrigger是操作限仓数据变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgActionTrigger
{
public:
	///构造方法
	CSysPosiLimitChgActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysPosiLimitChgActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysPosiLimitChg	要加入的SysPosiLimitChg
	virtual void beforeAdd(CWriteableSysPosiLimitChg *pSysPosiLimitChg)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysPosiLimitChg	已经加入的SysPosiLimitChg
	virtual void afterAdd(CSysPosiLimitChg *pSysPosiLimitChg)
	{
		return;
	}

	///更新前触发	
	///@param	pSysPosiLimitChg	被刷新的CSysPosiLimitChg
	///@param	pNewSysPosiLimitChg	新的值
	virtual void beforeUpdate(CSysPosiLimitChg *pSysPosiLimitChg, CWriteableSysPosiLimitChg *pNewSysPosiLimitChg)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysPosiLimitChg	被刷新的CSysPosiLimitChg
	virtual void afterUpdate(CSysPosiLimitChg *pSysPosiLimitChg)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysPosiLimitChg	要删除的CSysPosiLimitChg
	virtual void beforeRemove(CSysPosiLimitChg *pSysPosiLimitChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysPosiLimitChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgCommitTrigger是确认限仓数据变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgCommitTrigger
{
public:
	///构造方法
	CSysPosiLimitChgCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysPosiLimitChgCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysPosiLimitChg	已经加入的SysPosiLimitChg
	virtual void commitAdd(CSysPosiLimitChg *pSysPosiLimitChg)
	{
		return;
	}

	///更新后触发
	///@param	pSysPosiLimitChg	被刷新的CSysPosiLimitChg
	///@param	poldSysPosiLimitChg	原来的值
	virtual void commitUpdate(CSysPosiLimitChg *pSysPosiLimitChg, CWriteableSysPosiLimitChg *pOldSysPosiLimitChg)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysPosiLimitChg	已经删除的CSysPosiLimitChg
	virtual void commitRemove(CWriteableSysPosiLimitChg *pSysPosiLimitChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysPosiLimitChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgIterator是一个对限仓数据变动查询的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgIterator
{
public:
	///构造方法
	CSysPosiLimitChgIterator(void)
	{
	}

	///构造方法
	CSysPosiLimitChgIterator(CSysPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysPosiLimitChgIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysPosiLimitChg
	///@return	下一个满足条件CSysPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPosiLimitChg *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysPosiLimitChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysPosiLimitChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPosiLimitChg * pSysPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysPosiLimitChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysClientPosiLimitChg是一个存储限仓数据变动查询的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysClientPosiLimitChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ClientType.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
			return 0;
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysClientPosiLimitChg *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///合约代码
	CInstrumentIDType InstrumentID;
	///客户类型
	CClientTypeType ClientType;
	///交易角色
	CPositionTradingRoleType TradingRole;
	///限仓起点
	CLargeVolumeType StartTotalPosition;
	///取值方式
	CValueModeType ValueMode;
	///多头限仓
	CRatioType LongPosLimit;
	///空头限仓
	CRatioType ShortPosLimit;
	///操作类型
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysClientPosiLimitChg CSysClientPosiLimitChg;

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgActionTrigger是操作限仓数据变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgActionTrigger
{
public:
	///构造方法
	CSysClientPosiLimitChgActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysClientPosiLimitChgActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysClientPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysClientPosiLimitChg	要加入的SysClientPosiLimitChg
	virtual void beforeAdd(CWriteableSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysClientPosiLimitChg	已经加入的SysClientPosiLimitChg
	virtual void afterAdd(CSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return;
	}

	///更新前触发	
	///@param	pSysClientPosiLimitChg	被刷新的CSysClientPosiLimitChg
	///@param	pNewSysClientPosiLimitChg	新的值
	virtual void beforeUpdate(CSysClientPosiLimitChg *pSysClientPosiLimitChg, CWriteableSysClientPosiLimitChg *pNewSysClientPosiLimitChg)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysClientPosiLimitChg	被刷新的CSysClientPosiLimitChg
	virtual void afterUpdate(CSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysClientPosiLimitChg	要删除的CSysClientPosiLimitChg
	virtual void beforeRemove(CSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysClientPosiLimitChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgCommitTrigger是确认限仓数据变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgCommitTrigger
{
public:
	///构造方法
	CSysClientPosiLimitChgCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysClientPosiLimitChgCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysClientPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysClientPosiLimitChg	已经加入的SysClientPosiLimitChg
	virtual void commitAdd(CSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return;
	}

	///更新后触发
	///@param	pSysClientPosiLimitChg	被刷新的CSysClientPosiLimitChg
	///@param	poldSysClientPosiLimitChg	原来的值
	virtual void commitUpdate(CSysClientPosiLimitChg *pSysClientPosiLimitChg, CWriteableSysClientPosiLimitChg *pOldSysClientPosiLimitChg)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysClientPosiLimitChg	已经删除的CSysClientPosiLimitChg
	virtual void commitRemove(CWriteableSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysClientPosiLimitChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgIterator是一个对限仓数据变动查询的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgIterator
{
public:
	///构造方法
	CSysClientPosiLimitChgIterator(void)
	{
	}

	///构造方法
	CSysClientPosiLimitChgIterator(CSysClientPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysClientPosiLimitChgIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysClientPosiLimitChg
	///@return	下一个满足条件CSysClientPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientPosiLimitChg *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysClientPosiLimitChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysClientPosiLimitChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientPosiLimitChg * pSysClientPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysClientPosiLimitChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysSpecPosiLimitChg是一个存储限仓数据变动查询的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysSpecPosiLimitChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
			return 0;
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysSpecPosiLimitChg *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///合约代码
	CInstrumentIDType InstrumentID;
	///客户代码
	CClientIDType ClientID;
	///交易角色
	CPositionTradingRoleType TradingRole;
	///限仓起点
	CLargeVolumeType StartTotalPosition;
	///取值方式
	CValueModeType ValueMode;
	///多头限仓
	CRatioType LongPosLimit;
	///空头限仓
	CRatioType ShortPosLimit;
	///操作类型
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysSpecPosiLimitChg CSysSpecPosiLimitChg;

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgActionTrigger是操作限仓数据变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgActionTrigger
{
public:
	///构造方法
	CSysSpecPosiLimitChgActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysSpecPosiLimitChgActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysSpecPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysSpecPosiLimitChg	要加入的SysSpecPosiLimitChg
	virtual void beforeAdd(CWriteableSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysSpecPosiLimitChg	已经加入的SysSpecPosiLimitChg
	virtual void afterAdd(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return;
	}

	///更新前触发	
	///@param	pSysSpecPosiLimitChg	被刷新的CSysSpecPosiLimitChg
	///@param	pNewSysSpecPosiLimitChg	新的值
	virtual void beforeUpdate(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg, CWriteableSysSpecPosiLimitChg *pNewSysSpecPosiLimitChg)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysSpecPosiLimitChg	被刷新的CSysSpecPosiLimitChg
	virtual void afterUpdate(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysSpecPosiLimitChg	要删除的CSysSpecPosiLimitChg
	virtual void beforeRemove(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysSpecPosiLimitChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgCommitTrigger是确认限仓数据变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgCommitTrigger
{
public:
	///构造方法
	CSysSpecPosiLimitChgCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysSpecPosiLimitChgCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysSpecPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysSpecPosiLimitChg	已经加入的SysSpecPosiLimitChg
	virtual void commitAdd(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return;
	}

	///更新后触发
	///@param	pSysSpecPosiLimitChg	被刷新的CSysSpecPosiLimitChg
	///@param	poldSysSpecPosiLimitChg	原来的值
	virtual void commitUpdate(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg, CWriteableSysSpecPosiLimitChg *pOldSysSpecPosiLimitChg)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysSpecPosiLimitChg	已经删除的CSysSpecPosiLimitChg
	virtual void commitRemove(CWriteableSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysSpecPosiLimitChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgIterator是一个对限仓数据变动查询的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgIterator
{
public:
	///构造方法
	CSysSpecPosiLimitChgIterator(void)
	{
	}

	///构造方法
	CSysSpecPosiLimitChgIterator(CSysSpecPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysSpecPosiLimitChgIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysSpecPosiLimitChg
	///@return	下一个满足条件CSysSpecPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysSpecPosiLimitChg *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysSpecPosiLimitChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysSpecPosiLimitChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysSpecPosiLimitChg * pSysSpecPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysSpecPosiLimitChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysHedgeDetailChg是一个存储保值额度变动查询的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysHedgeDetailChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
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
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysHedgeDetailChg *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///会员代码
	CParticipantIDType ParticipantID;
	///客户代码
	CClientIDType ClientID;
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
	///操作类型
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysHedgeDetailChg CSysHedgeDetailChg;

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgActionTrigger是操作保值额度变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgActionTrigger
{
public:
	///构造方法
	CSysHedgeDetailChgActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysHedgeDetailChgActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysHedgeDetailChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysHedgeDetailChg	要加入的SysHedgeDetailChg
	virtual void beforeAdd(CWriteableSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysHedgeDetailChg	已经加入的SysHedgeDetailChg
	virtual void afterAdd(CSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return;
	}

	///更新前触发	
	///@param	pSysHedgeDetailChg	被刷新的CSysHedgeDetailChg
	///@param	pNewSysHedgeDetailChg	新的值
	virtual void beforeUpdate(CSysHedgeDetailChg *pSysHedgeDetailChg, CWriteableSysHedgeDetailChg *pNewSysHedgeDetailChg)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysHedgeDetailChg	被刷新的CSysHedgeDetailChg
	virtual void afterUpdate(CSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysHedgeDetailChg	要删除的CSysHedgeDetailChg
	virtual void beforeRemove(CSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysHedgeDetailChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgCommitTrigger是确认保值额度变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgCommitTrigger
{
public:
	///构造方法
	CSysHedgeDetailChgCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysHedgeDetailChgCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysHedgeDetailChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysHedgeDetailChg	已经加入的SysHedgeDetailChg
	virtual void commitAdd(CSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return;
	}

	///更新后触发
	///@param	pSysHedgeDetailChg	被刷新的CSysHedgeDetailChg
	///@param	poldSysHedgeDetailChg	原来的值
	virtual void commitUpdate(CSysHedgeDetailChg *pSysHedgeDetailChg, CWriteableSysHedgeDetailChg *pOldSysHedgeDetailChg)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysHedgeDetailChg	已经删除的CSysHedgeDetailChg
	virtual void commitRemove(CWriteableSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysHedgeDetailChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgIterator是一个对保值额度变动查询的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgIterator
{
public:
	///构造方法
	CSysHedgeDetailChgIterator(void)
	{
	}

	///构造方法
	CSysHedgeDetailChgIterator(CSysHedgeDetailChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysHedgeDetailChgIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysHedgeDetailChg
	///@return	下一个满足条件CSysHedgeDetailChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysHedgeDetailChg *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysHedgeDetailChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysHedgeDetailChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysHedgeDetailChg * pSysHedgeDetailChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysHedgeDetailChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysParticipantChg是一个存储会员变动查询的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysParticipantChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
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
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysParticipantChg *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
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
	///操作类型
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysParticipantChg CSysParticipantChg;

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgActionTrigger是操作会员变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgActionTrigger
{
public:
	///构造方法
	CSysParticipantChgActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysParticipantChgActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysParticipantChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysParticipantChg	要加入的SysParticipantChg
	virtual void beforeAdd(CWriteableSysParticipantChg *pSysParticipantChg)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysParticipantChg	已经加入的SysParticipantChg
	virtual void afterAdd(CSysParticipantChg *pSysParticipantChg)
	{
		return;
	}

	///更新前触发	
	///@param	pSysParticipantChg	被刷新的CSysParticipantChg
	///@param	pNewSysParticipantChg	新的值
	virtual void beforeUpdate(CSysParticipantChg *pSysParticipantChg, CWriteableSysParticipantChg *pNewSysParticipantChg)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysParticipantChg	被刷新的CSysParticipantChg
	virtual void afterUpdate(CSysParticipantChg *pSysParticipantChg)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysParticipantChg	要删除的CSysParticipantChg
	virtual void beforeRemove(CSysParticipantChg *pSysParticipantChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysParticipantChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgCommitTrigger是确认会员变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgCommitTrigger
{
public:
	///构造方法
	CSysParticipantChgCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysParticipantChgCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysParticipantChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysParticipantChg	已经加入的SysParticipantChg
	virtual void commitAdd(CSysParticipantChg *pSysParticipantChg)
	{
		return;
	}

	///更新后触发
	///@param	pSysParticipantChg	被刷新的CSysParticipantChg
	///@param	poldSysParticipantChg	原来的值
	virtual void commitUpdate(CSysParticipantChg *pSysParticipantChg, CWriteableSysParticipantChg *pOldSysParticipantChg)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysParticipantChg	已经删除的CSysParticipantChg
	virtual void commitRemove(CWriteableSysParticipantChg *pSysParticipantChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysParticipantChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgIterator是一个对会员变动查询的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgIterator
{
public:
	///构造方法
	CSysParticipantChgIterator(void)
	{
	}

	///构造方法
	CSysParticipantChgIterator(CSysParticipantChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysParticipantChgIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysParticipantChg
	///@return	下一个满足条件CSysParticipantChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysParticipantChg *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysParticipantChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysParticipantChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysParticipantChg * pSysParticipantChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysParticipantChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMarginRateChg是一个存储保证金率变动查询的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMarginRateChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
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
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMarginRateChg *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///合约代码
	CInstrumentIDType InstrumentID;
	///会员代码
	CParticipantIDType ParticipantID;
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
	///操作类型
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysMarginRateChg CSysMarginRateChg;

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgActionTrigger是操作保证金率变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgActionTrigger
{
public:
	///构造方法
	CSysMarginRateChgActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMarginRateChgActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMarginRateChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMarginRateChg	要加入的SysMarginRateChg
	virtual void beforeAdd(CWriteableSysMarginRateChg *pSysMarginRateChg)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMarginRateChg	已经加入的SysMarginRateChg
	virtual void afterAdd(CSysMarginRateChg *pSysMarginRateChg)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMarginRateChg	被刷新的CSysMarginRateChg
	///@param	pNewSysMarginRateChg	新的值
	virtual void beforeUpdate(CSysMarginRateChg *pSysMarginRateChg, CWriteableSysMarginRateChg *pNewSysMarginRateChg)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMarginRateChg	被刷新的CSysMarginRateChg
	virtual void afterUpdate(CSysMarginRateChg *pSysMarginRateChg)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMarginRateChg	要删除的CSysMarginRateChg
	virtual void beforeRemove(CSysMarginRateChg *pSysMarginRateChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMarginRateChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgCommitTrigger是确认保证金率变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgCommitTrigger
{
public:
	///构造方法
	CSysMarginRateChgCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMarginRateChgCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMarginRateChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMarginRateChg	已经加入的SysMarginRateChg
	virtual void commitAdd(CSysMarginRateChg *pSysMarginRateChg)
	{
		return;
	}

	///更新后触发
	///@param	pSysMarginRateChg	被刷新的CSysMarginRateChg
	///@param	poldSysMarginRateChg	原来的值
	virtual void commitUpdate(CSysMarginRateChg *pSysMarginRateChg, CWriteableSysMarginRateChg *pOldSysMarginRateChg)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMarginRateChg	已经删除的CSysMarginRateChg
	virtual void commitRemove(CWriteableSysMarginRateChg *pSysMarginRateChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMarginRateChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgIterator是一个对保证金率变动查询的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgIterator
{
public:
	///构造方法
	CSysMarginRateChgIterator(void)
	{
	}

	///构造方法
	CSysMarginRateChgIterator(CSysMarginRateChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMarginRateChgIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMarginRateChg
	///@return	下一个满足条件CSysMarginRateChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMarginRateChg *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMarginRateChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMarginRateChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMarginRateChg * pSysMarginRateChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMarginRateChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysUserIpChg是一个存储IP地址变动查询的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysUserIpChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! IPMask.isValid())
			return 0;
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysUserIpChg *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///交易用户代码
	CUserIDType UserID;
	///IP地址
	CIPAddressType IPAddress;
	///IP地址掩码
	CIPAddressType IPMask;
	///操作类型
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysUserIpChg CSysUserIpChg;

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgActionTrigger是操作IP地址变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgActionTrigger
{
public:
	///构造方法
	CSysUserIpChgActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysUserIpChgActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysUserIpChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysUserIpChg	要加入的SysUserIpChg
	virtual void beforeAdd(CWriteableSysUserIpChg *pSysUserIpChg)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysUserIpChg	已经加入的SysUserIpChg
	virtual void afterAdd(CSysUserIpChg *pSysUserIpChg)
	{
		return;
	}

	///更新前触发	
	///@param	pSysUserIpChg	被刷新的CSysUserIpChg
	///@param	pNewSysUserIpChg	新的值
	virtual void beforeUpdate(CSysUserIpChg *pSysUserIpChg, CWriteableSysUserIpChg *pNewSysUserIpChg)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysUserIpChg	被刷新的CSysUserIpChg
	virtual void afterUpdate(CSysUserIpChg *pSysUserIpChg)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysUserIpChg	要删除的CSysUserIpChg
	virtual void beforeRemove(CSysUserIpChg *pSysUserIpChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysUserIpChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgCommitTrigger是确认IP地址变动查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgCommitTrigger
{
public:
	///构造方法
	CSysUserIpChgCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysUserIpChgCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysUserIpChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysUserIpChg	已经加入的SysUserIpChg
	virtual void commitAdd(CSysUserIpChg *pSysUserIpChg)
	{
		return;
	}

	///更新后触发
	///@param	pSysUserIpChg	被刷新的CSysUserIpChg
	///@param	poldSysUserIpChg	原来的值
	virtual void commitUpdate(CSysUserIpChg *pSysUserIpChg, CWriteableSysUserIpChg *pOldSysUserIpChg)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysUserIpChg	已经删除的CSysUserIpChg
	virtual void commitRemove(CWriteableSysUserIpChg *pSysUserIpChg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysUserIpChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgIterator是一个对IP地址变动查询的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgIterator
{
public:
	///构造方法
	CSysUserIpChgIterator(void)
	{
	}

	///构造方法
	CSysUserIpChgIterator(CSysUserIpChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysUserIpChgIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysUserIpChg
	///@return	下一个满足条件CSysUserIpChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserIpChg *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysUserIpChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysUserIpChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserIpChg * pSysUserIpChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysUserIpChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysPartTrade是一个存储会员交易信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysPartTrade
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TotalPositiveOrder.isValid())
			return 0;
		if (! TotalNegativeOrder.isValid())
			return 0;
		if (! TotalPositiveTrade.isValid())
			return 0;
		if (! TotalNegativeTrade.isValid())
			return 0;
		if (! TotalPositivePosi.isValid())
			return 0;
		if (! TotalNegativePosi.isValid())
			return 0;
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysPartTrade *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///操作日期
	CDateType ActionDate;
	///操作时间
	CTimeType ActionTime;
	///合约代码
	CInstrumentIDType InstrumentID;
	///会员代码
	CParticipantIDType ParticipantID;
	///总报买单量
	CVolumeType TotalPositiveOrder;
	///总报单卖量
	CVolumeType TotalNegativeOrder;
	///买单总成交量
	CVolumeType TotalPositiveTrade;
	///卖单总成交量
	CVolumeType TotalNegativeTrade;
	///总多头持仓量
	CVolumeType TotalPositivePosi;
	///总空头持仓量
	CVolumeType TotalNegativePosi;
	///操作类型
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysPartTrade CSysPartTrade;

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeActionTrigger是操作会员交易信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeActionTrigger
{
public:
	///构造方法
	CSysPartTradeActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysPartTradeActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysPartTradeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysPartTrade	要加入的SysPartTrade
	virtual void beforeAdd(CWriteableSysPartTrade *pSysPartTrade)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysPartTrade	已经加入的SysPartTrade
	virtual void afterAdd(CSysPartTrade *pSysPartTrade)
	{
		return;
	}

	///更新前触发	
	///@param	pSysPartTrade	被刷新的CSysPartTrade
	///@param	pNewSysPartTrade	新的值
	virtual void beforeUpdate(CSysPartTrade *pSysPartTrade, CWriteableSysPartTrade *pNewSysPartTrade)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysPartTrade	被刷新的CSysPartTrade
	virtual void afterUpdate(CSysPartTrade *pSysPartTrade)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysPartTrade	要删除的CSysPartTrade
	virtual void beforeRemove(CSysPartTrade *pSysPartTrade)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysPartTradeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeCommitTrigger是确认会员交易信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeCommitTrigger
{
public:
	///构造方法
	CSysPartTradeCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysPartTradeCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysPartTradeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysPartTrade	已经加入的SysPartTrade
	virtual void commitAdd(CSysPartTrade *pSysPartTrade)
	{
		return;
	}

	///更新后触发
	///@param	pSysPartTrade	被刷新的CSysPartTrade
	///@param	poldSysPartTrade	原来的值
	virtual void commitUpdate(CSysPartTrade *pSysPartTrade, CWriteableSysPartTrade *pOldSysPartTrade)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysPartTrade	已经删除的CSysPartTrade
	virtual void commitRemove(CWriteableSysPartTrade *pSysPartTrade)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysPartTradeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeIterator是一个对会员交易信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeIterator
{
public:
	///构造方法
	CSysPartTradeIterator(void)
	{
	}

	///构造方法
	CSysPartTradeIterator(CSysPartTradeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysPartTradeIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysPartTrade
	///@return	下一个满足条件CSysPartTrade，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPartTrade *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysPartTradeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysPartTrade 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPartTrade * pSysPartTrade,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysPartTradeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbObjectAttr是一个存储对象状态指标的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbObjectAttr
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
		if (! SubcriberID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! AttrType.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! ValueType.isValid())
			return 0;
		if (! AttrValue.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbObjectAttr *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///订阅对象ID
	CVolumeType SubcriberID;
	///定义对象ID
	CVolumeType ObjectID;
	///监控指标类型ID
	CVolumeType AttrType;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///监控指标的值类型
	CValueTypeType ValueType;
	///监控指标的具体值
	CAttrValueType AttrValue;
	
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

typedef const CWriteableSysMdbObjectAttr CSysMdbObjectAttr;

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrActionTrigger是操作对象状态指标时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrActionTrigger
{
public:
	///构造方法
	CSysMdbObjectAttrActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbObjectAttrActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbObjectAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMdbObjectAttr	要加入的SysMdbObjectAttr
	virtual void beforeAdd(CWriteableSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMdbObjectAttr	已经加入的SysMdbObjectAttr
	virtual void afterAdd(CSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMdbObjectAttr	被刷新的CSysMdbObjectAttr
	///@param	pNewSysMdbObjectAttr	新的值
	virtual void beforeUpdate(CSysMdbObjectAttr *pSysMdbObjectAttr, CWriteableSysMdbObjectAttr *pNewSysMdbObjectAttr)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMdbObjectAttr	被刷新的CSysMdbObjectAttr
	virtual void afterUpdate(CSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMdbObjectAttr	要删除的CSysMdbObjectAttr
	virtual void beforeRemove(CSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbObjectAttrFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrCommitTrigger是确认对象状态指标时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrCommitTrigger
{
public:
	///构造方法
	CSysMdbObjectAttrCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbObjectAttrCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbObjectAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMdbObjectAttr	已经加入的SysMdbObjectAttr
	virtual void commitAdd(CSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return;
	}

	///更新后触发
	///@param	pSysMdbObjectAttr	被刷新的CSysMdbObjectAttr
	///@param	poldSysMdbObjectAttr	原来的值
	virtual void commitUpdate(CSysMdbObjectAttr *pSysMdbObjectAttr, CWriteableSysMdbObjectAttr *pOldSysMdbObjectAttr)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMdbObjectAttr	已经删除的CSysMdbObjectAttr
	virtual void commitRemove(CWriteableSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbObjectAttrFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrIterator是一个对对象状态指标的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrIterator
{
public:
	///构造方法
	CSysMdbObjectAttrIterator(void)
	{
	}

	///构造方法
	CSysMdbObjectAttrIterator(CSysMdbObjectAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbObjectAttrIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMdbObjectAttr
	///@return	下一个满足条件CSysMdbObjectAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbObjectAttr *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMdbObjectAttrFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbObjectAttr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbObjectAttr * pSysMdbObjectAttr,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMdbObjectAttrFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbSyslogInfo是一个存储日志文件内容传输信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbSyslogInfo
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
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! AttrType.isValid())
			return 0;
		if (! ContLen.isValid())
			return 0;
		if (! FileContent.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbSyslogInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///定义对象ID
	CVolumeType ObjectID;
	///监控指标类型ID
	CVolumeType AttrType;
	///文件内容长度
	CTypeContLenType ContLen;
	///文件内容
	CTypeFileContentType FileContent;
	
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

typedef const CWriteableSysMdbSyslogInfo CSysMdbSyslogInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoActionTrigger是操作日志文件内容传输信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoActionTrigger
{
public:
	///构造方法
	CSysMdbSyslogInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbSyslogInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbSyslogInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMdbSyslogInfo	要加入的SysMdbSyslogInfo
	virtual void beforeAdd(CWriteableSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMdbSyslogInfo	已经加入的SysMdbSyslogInfo
	virtual void afterAdd(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMdbSyslogInfo	被刷新的CSysMdbSyslogInfo
	///@param	pNewSysMdbSyslogInfo	新的值
	virtual void beforeUpdate(CSysMdbSyslogInfo *pSysMdbSyslogInfo, CWriteableSysMdbSyslogInfo *pNewSysMdbSyslogInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMdbSyslogInfo	被刷新的CSysMdbSyslogInfo
	virtual void afterUpdate(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMdbSyslogInfo	要删除的CSysMdbSyslogInfo
	virtual void beforeRemove(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbSyslogInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoCommitTrigger是确认日志文件内容传输信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoCommitTrigger
{
public:
	///构造方法
	CSysMdbSyslogInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbSyslogInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbSyslogInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMdbSyslogInfo	已经加入的SysMdbSyslogInfo
	virtual void commitAdd(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysMdbSyslogInfo	被刷新的CSysMdbSyslogInfo
	///@param	poldSysMdbSyslogInfo	原来的值
	virtual void commitUpdate(CSysMdbSyslogInfo *pSysMdbSyslogInfo, CWriteableSysMdbSyslogInfo *pOldSysMdbSyslogInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMdbSyslogInfo	已经删除的CSysMdbSyslogInfo
	virtual void commitRemove(CWriteableSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbSyslogInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoIterator是一个对日志文件内容传输信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoIterator
{
public:
	///构造方法
	CSysMdbSyslogInfoIterator(void)
	{
	}

	///构造方法
	CSysMdbSyslogInfoIterator(CSysMdbSyslogInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbSyslogInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMdbSyslogInfo
	///@return	下一个满足条件CSysMdbSyslogInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbSyslogInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMdbSyslogInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbSyslogInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbSyslogInfo * pSysMdbSyslogInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMdbSyslogInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysUserInfo是一个存储用户信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysUserInfo
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
		if (! USERNAME.isValid())
			return 0;
		if (! USERID.isValid())
			return 0;
		if (! GROUPNAME.isValid())
			return 0;
		if (! GROUPID.isValid())
			return 0;
		if (! HOMEPATH.isValid())
			return 0;
		if (! SHELL.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! MonDate.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysUserInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///用户名
	CTypeUserNameType USERNAME;
	///用户ID
	CVolumeType USERID;
	///用户组名
	CTypeUserNameType GROUPNAME;
	///用户组ID
	CVolumeType GROUPID;
	///HOME路径
	CTypeUserNameType HOMEPATH;
	///用户使用SHELL环境
	CTypeUserNameType SHELL;
	///定义对象名
	CTypeObjectIDType ObjectID;
	///采集的时间
	CTimeType MonTime;
	///采集的日期
	CDateType MonDate;
	
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

typedef const CWriteableSysUserInfo CSysUserInfo;

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoActionTrigger是操作用户信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoActionTrigger
{
public:
	///构造方法
	CSysUserInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysUserInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysUserInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysUserInfo	要加入的SysUserInfo
	virtual void beforeAdd(CWriteableSysUserInfo *pSysUserInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysUserInfo	已经加入的SysUserInfo
	virtual void afterAdd(CSysUserInfo *pSysUserInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysUserInfo	被刷新的CSysUserInfo
	///@param	pNewSysUserInfo	新的值
	virtual void beforeUpdate(CSysUserInfo *pSysUserInfo, CWriteableSysUserInfo *pNewSysUserInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysUserInfo	被刷新的CSysUserInfo
	virtual void afterUpdate(CSysUserInfo *pSysUserInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysUserInfo	要删除的CSysUserInfo
	virtual void beforeRemove(CSysUserInfo *pSysUserInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysUserInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoCommitTrigger是确认用户信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoCommitTrigger
{
public:
	///构造方法
	CSysUserInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysUserInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysUserInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysUserInfo	已经加入的SysUserInfo
	virtual void commitAdd(CSysUserInfo *pSysUserInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysUserInfo	被刷新的CSysUserInfo
	///@param	poldSysUserInfo	原来的值
	virtual void commitUpdate(CSysUserInfo *pSysUserInfo, CWriteableSysUserInfo *pOldSysUserInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysUserInfo	已经删除的CSysUserInfo
	virtual void commitRemove(CWriteableSysUserInfo *pSysUserInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysUserInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoIterator是一个对用户信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoIterator
{
public:
	///构造方法
	CSysUserInfoIterator(void)
	{
	}

	///构造方法
	CSysUserInfoIterator(CSysUserInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysUserInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysUserInfo
	///@return	下一个满足条件CSysUserInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysUserInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysUserInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserInfo * pSysUserInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysUserInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysOnlineUserInfo是一个存储在线用户信息查询应答的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysOnlineUserInfo
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
		if (! USERNAME.isValid())
			return 0;
		if (! TIME.isValid())
			return 0;
		if (! TTY.isValid())
			return 0;
		if (! IP.isValid())
			return 0;
		if (! CONNECTIME.isValid())
			return 0;
		if (! PID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! MonDate.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysOnlineUserInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///用户名
	CTypeUserNameType USERNAME;
	///登录时间
	CTypeUserNameType TIME;
	///终端类型
	CTypeUserNameType TTY;
	///IP地址
	CTypeUserNameType IP;
	///连接时间
	CTypeUserNameType CONNECTIME;
	///进程ID
	CVolumeType PID;
	///定义对象名
	CTypeObjectIDType ObjectID;
	///采集的时间
	CTimeType MonTime;
	///采集的日期
	CDateType MonDate;
	
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

typedef const CWriteableSysOnlineUserInfo CSysOnlineUserInfo;

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoActionTrigger是操作在线用户信息查询应答时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoActionTrigger
{
public:
	///构造方法
	CSysOnlineUserInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysOnlineUserInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysOnlineUserInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysOnlineUserInfo	要加入的SysOnlineUserInfo
	virtual void beforeAdd(CWriteableSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysOnlineUserInfo	已经加入的SysOnlineUserInfo
	virtual void afterAdd(CSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysOnlineUserInfo	被刷新的CSysOnlineUserInfo
	///@param	pNewSysOnlineUserInfo	新的值
	virtual void beforeUpdate(CSysOnlineUserInfo *pSysOnlineUserInfo, CWriteableSysOnlineUserInfo *pNewSysOnlineUserInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysOnlineUserInfo	被刷新的CSysOnlineUserInfo
	virtual void afterUpdate(CSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysOnlineUserInfo	要删除的CSysOnlineUserInfo
	virtual void beforeRemove(CSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysOnlineUserInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoCommitTrigger是确认在线用户信息查询应答时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoCommitTrigger
{
public:
	///构造方法
	CSysOnlineUserInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysOnlineUserInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysOnlineUserInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysOnlineUserInfo	已经加入的SysOnlineUserInfo
	virtual void commitAdd(CSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysOnlineUserInfo	被刷新的CSysOnlineUserInfo
	///@param	poldSysOnlineUserInfo	原来的值
	virtual void commitUpdate(CSysOnlineUserInfo *pSysOnlineUserInfo, CWriteableSysOnlineUserInfo *pOldSysOnlineUserInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysOnlineUserInfo	已经删除的CSysOnlineUserInfo
	virtual void commitRemove(CWriteableSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysOnlineUserInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoIterator是一个对在线用户信息查询应答的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoIterator
{
public:
	///构造方法
	CSysOnlineUserInfoIterator(void)
	{
	}

	///构造方法
	CSysOnlineUserInfoIterator(CSysOnlineUserInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysOnlineUserInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysOnlineUserInfo
	///@return	下一个满足条件CSysOnlineUserInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysOnlineUserInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysOnlineUserInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysOnlineUserInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysOnlineUserInfo * pSysOnlineUserInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysOnlineUserInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysWarningEvent是一个存储告警事件查询应答的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysWarningEvent
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
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! OccurDate.isValid())
			return 0;
		if (! OccurTime.isValid())
			return 0;
		if (! EvendID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! EventName.isValid())
			return 0;
		if (! EventNum.isValid())
			return 0;
		if (! EventType.isValid())
			return 0;
		if (! EventDes.isValid())
			return 0;
		if (! ProcessFlag.isValid())
			return 0;
		if (! WarningLevel.isValid())
			return 0;
		if (! EventDealDes.isValid())
			return 0;
		if (! FullEventName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysWarningEvent *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///事件发生日期
	CDateType OccurDate;
	///事件发生时间
	CTimeType OccurTime;
	///事件ID
	CVolumeType EvendID;
	///发生事件的对象ID指标
	CNetAttrTypeType ObjectID;
	///IP地址
	CIPAddressType IPAddress;
	///事件名
	CTypeObjectIDType EventName;
	///事件标签
	CVolumeType EventNum;
	///事件类型
	CVolumeType EventType;
	///事件描述
	CTypeDescriptionType EventDes;
	///清除标记
	CTypeProcessFlagType ProcessFlag;
	///警告级别
	CTypeWarningLevelType WarningLevel;
	///事件处理描述
	CTypeObjectIDType EventDealDes;
	///事件全名
	CNetAttrTypeType FullEventName;
	
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

typedef const CWriteableSysWarningEvent CSysWarningEvent;

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventActionTrigger是操作告警事件查询应答时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventActionTrigger
{
public:
	///构造方法
	CSysWarningEventActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysWarningEventActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysWarningEventFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysWarningEvent	要加入的SysWarningEvent
	virtual void beforeAdd(CWriteableSysWarningEvent *pSysWarningEvent)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysWarningEvent	已经加入的SysWarningEvent
	virtual void afterAdd(CSysWarningEvent *pSysWarningEvent)
	{
		return;
	}

	///更新前触发	
	///@param	pSysWarningEvent	被刷新的CSysWarningEvent
	///@param	pNewSysWarningEvent	新的值
	virtual void beforeUpdate(CSysWarningEvent *pSysWarningEvent, CWriteableSysWarningEvent *pNewSysWarningEvent)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysWarningEvent	被刷新的CSysWarningEvent
	virtual void afterUpdate(CSysWarningEvent *pSysWarningEvent)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysWarningEvent	要删除的CSysWarningEvent
	virtual void beforeRemove(CSysWarningEvent *pSysWarningEvent)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysWarningEventFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventCommitTrigger是确认告警事件查询应答时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventCommitTrigger
{
public:
	///构造方法
	CSysWarningEventCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysWarningEventCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysWarningEventFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysWarningEvent	已经加入的SysWarningEvent
	virtual void commitAdd(CSysWarningEvent *pSysWarningEvent)
	{
		return;
	}

	///更新后触发
	///@param	pSysWarningEvent	被刷新的CSysWarningEvent
	///@param	poldSysWarningEvent	原来的值
	virtual void commitUpdate(CSysWarningEvent *pSysWarningEvent, CWriteableSysWarningEvent *pOldSysWarningEvent)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysWarningEvent	已经删除的CSysWarningEvent
	virtual void commitRemove(CWriteableSysWarningEvent *pSysWarningEvent)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysWarningEventFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventIterator是一个对告警事件查询应答的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventIterator
{
public:
	///构造方法
	CSysWarningEventIterator(void)
	{
	}

	///构造方法
	CSysWarningEventIterator(CSysWarningEventFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysWarningEventIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysWarningEvent
	///@return	下一个满足条件CSysWarningEvent，如果已经没有一个满足要求了，则返回NULL
	virtual CSysWarningEvent *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysWarningEventFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysWarningEvent 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysWarningEvent * pSysWarningEvent,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysWarningEventFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysWarningQuery是一个存储告警明细应答的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysWarningQuery
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
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! EvendID.isValid())
			return 0;
		if (! DBQueryResult.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysWarningQuery *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///事件ID
	CVolumeType EvendID;
	///数据库查询结果
	CDBQueryResultType DBQueryResult;
	
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

typedef const CWriteableSysWarningQuery CSysWarningQuery;

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryActionTrigger是操作告警明细应答时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryActionTrigger
{
public:
	///构造方法
	CSysWarningQueryActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysWarningQueryActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysWarningQueryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysWarningQuery	要加入的SysWarningQuery
	virtual void beforeAdd(CWriteableSysWarningQuery *pSysWarningQuery)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysWarningQuery	已经加入的SysWarningQuery
	virtual void afterAdd(CSysWarningQuery *pSysWarningQuery)
	{
		return;
	}

	///更新前触发	
	///@param	pSysWarningQuery	被刷新的CSysWarningQuery
	///@param	pNewSysWarningQuery	新的值
	virtual void beforeUpdate(CSysWarningQuery *pSysWarningQuery, CWriteableSysWarningQuery *pNewSysWarningQuery)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysWarningQuery	被刷新的CSysWarningQuery
	virtual void afterUpdate(CSysWarningQuery *pSysWarningQuery)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysWarningQuery	要删除的CSysWarningQuery
	virtual void beforeRemove(CSysWarningQuery *pSysWarningQuery)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysWarningQueryFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryCommitTrigger是确认告警明细应答时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryCommitTrigger
{
public:
	///构造方法
	CSysWarningQueryCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysWarningQueryCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysWarningQueryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysWarningQuery	已经加入的SysWarningQuery
	virtual void commitAdd(CSysWarningQuery *pSysWarningQuery)
	{
		return;
	}

	///更新后触发
	///@param	pSysWarningQuery	被刷新的CSysWarningQuery
	///@param	poldSysWarningQuery	原来的值
	virtual void commitUpdate(CSysWarningQuery *pSysWarningQuery, CWriteableSysWarningQuery *pOldSysWarningQuery)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysWarningQuery	已经删除的CSysWarningQuery
	virtual void commitRemove(CWriteableSysWarningQuery *pSysWarningQuery)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysWarningQueryFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryIterator是一个对告警明细应答的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryIterator
{
public:
	///构造方法
	CSysWarningQueryIterator(void)
	{
	}

	///构造方法
	CSysWarningQueryIterator(CSysWarningQueryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysWarningQueryIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysWarningQuery
	///@return	下一个满足条件CSysWarningQuery，如果已经没有一个满足要求了，则返回NULL
	virtual CSysWarningQuery *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysWarningQueryFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysWarningQuery 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysWarningQuery * pSysWarningQuery,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysWarningQueryFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSyslogEvent是一个存储日志事件查询应答的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSyslogEvent
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
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! OccurDate.isValid())
			return 0;
		if (! OccurTime.isValid())
			return 0;
		if (! EvendID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! EventName.isValid())
			return 0;
		if (! EventNum.isValid())
			return 0;
		if (! EventType.isValid())
			return 0;
		if (! EventDes.isValid())
			return 0;
		if (! ProcessFlag.isValid())
			return 0;
		if (! WarningLevel.isValid())
			return 0;
		if (! EventDealDes.isValid())
			return 0;
		if (! FullEventName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSyslogEvent *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///事件发生日期
	CDateType OccurDate;
	///事件发生时间
	CTimeType OccurTime;
	///事件ID
	CVolumeType EvendID;
	///发生事件的对象ID指标
	CNetAttrTypeType ObjectID;
	///IP地址
	CIPAddressType IPAddress;
	///事件名
	CTypeObjectIDType EventName;
	///事件标签
	CVolumeType EventNum;
	///事件类型
	CVolumeType EventType;
	///事件描述
	CTypeDescriptionType EventDes;
	///清除标记
	CTypeProcessFlagType ProcessFlag;
	///警告级别
	CTypeWarningLevelType WarningLevel;
	///事件处理描述
	CTypeObjectIDType EventDealDes;
	///事件全名
	CNetAttrTypeType FullEventName;
	
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

typedef const CWriteableSyslogEvent CSyslogEvent;

/////////////////////////////////////////////////////////////////////////
///CSyslogEventActionTrigger是操作日志事件查询应答时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventActionTrigger
{
public:
	///构造方法
	CSyslogEventActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSyslogEventActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSyslogEventFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSyslogEvent	要加入的SyslogEvent
	virtual void beforeAdd(CWriteableSyslogEvent *pSyslogEvent)
	{
		return;
	}
	
	///加入后触发
	///@param	pSyslogEvent	已经加入的SyslogEvent
	virtual void afterAdd(CSyslogEvent *pSyslogEvent)
	{
		return;
	}

	///更新前触发	
	///@param	pSyslogEvent	被刷新的CSyslogEvent
	///@param	pNewSyslogEvent	新的值
	virtual void beforeUpdate(CSyslogEvent *pSyslogEvent, CWriteableSyslogEvent *pNewSyslogEvent)
	{
		return;
	}
	
	///更新后触发
	///@param	pSyslogEvent	被刷新的CSyslogEvent
	virtual void afterUpdate(CSyslogEvent *pSyslogEvent)
	{
		return;
	}
	
	///删除前触发
	///@param	pSyslogEvent	要删除的CSyslogEvent
	virtual void beforeRemove(CSyslogEvent *pSyslogEvent)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSyslogEventFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventCommitTrigger是确认日志事件查询应答时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventCommitTrigger
{
public:
	///构造方法
	CSyslogEventCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSyslogEventCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSyslogEventFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSyslogEvent	已经加入的SyslogEvent
	virtual void commitAdd(CSyslogEvent *pSyslogEvent)
	{
		return;
	}

	///更新后触发
	///@param	pSyslogEvent	被刷新的CSyslogEvent
	///@param	poldSyslogEvent	原来的值
	virtual void commitUpdate(CSyslogEvent *pSyslogEvent, CWriteableSyslogEvent *pOldSyslogEvent)
	{
		return;
	}
	
	///删除后触发
	///@param	pSyslogEvent	已经删除的CSyslogEvent
	virtual void commitRemove(CWriteableSyslogEvent *pSyslogEvent)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSyslogEventFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventIterator是一个对日志事件查询应答的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventIterator
{
public:
	///构造方法
	CSyslogEventIterator(void)
	{
	}

	///构造方法
	CSyslogEventIterator(CSyslogEventFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSyslogEventIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SyslogEvent
	///@return	下一个满足条件CSyslogEvent，如果已经没有一个满足要求了，则返回NULL
	virtual CSyslogEvent *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSyslogEventFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSyslogEvent 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSyslogEvent * pSyslogEvent,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSyslogEventFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysEventDescrip是一个存储事件描述查询的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysEventDescrip
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
		if (! EventDesID.isValid())
			return 0;
		if (! UserName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! EventDes.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysEventDescrip *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///处理ID号
	CEventDesIDType EventDesID;
	///事件处理人
	CTypeObjectIDType UserName;
	///事件处理日期
	CDateType MonDate;
	///事件处理时间
	CTimeType MonTime;
	///处理描述
	CDescriptionType EventDes;
	
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

typedef const CWriteableSysEventDescrip CSysEventDescrip;

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripActionTrigger是操作事件描述查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripActionTrigger
{
public:
	///构造方法
	CSysEventDescripActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysEventDescripActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysEventDescripFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysEventDescrip	要加入的SysEventDescrip
	virtual void beforeAdd(CWriteableSysEventDescrip *pSysEventDescrip)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysEventDescrip	已经加入的SysEventDescrip
	virtual void afterAdd(CSysEventDescrip *pSysEventDescrip)
	{
		return;
	}

	///更新前触发	
	///@param	pSysEventDescrip	被刷新的CSysEventDescrip
	///@param	pNewSysEventDescrip	新的值
	virtual void beforeUpdate(CSysEventDescrip *pSysEventDescrip, CWriteableSysEventDescrip *pNewSysEventDescrip)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysEventDescrip	被刷新的CSysEventDescrip
	virtual void afterUpdate(CSysEventDescrip *pSysEventDescrip)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysEventDescrip	要删除的CSysEventDescrip
	virtual void beforeRemove(CSysEventDescrip *pSysEventDescrip)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysEventDescripFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripCommitTrigger是确认事件描述查询时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripCommitTrigger
{
public:
	///构造方法
	CSysEventDescripCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysEventDescripCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysEventDescripFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysEventDescrip	已经加入的SysEventDescrip
	virtual void commitAdd(CSysEventDescrip *pSysEventDescrip)
	{
		return;
	}

	///更新后触发
	///@param	pSysEventDescrip	被刷新的CSysEventDescrip
	///@param	poldSysEventDescrip	原来的值
	virtual void commitUpdate(CSysEventDescrip *pSysEventDescrip, CWriteableSysEventDescrip *pOldSysEventDescrip)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysEventDescrip	已经删除的CSysEventDescrip
	virtual void commitRemove(CWriteableSysEventDescrip *pSysEventDescrip)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysEventDescripFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripIterator是一个对事件描述查询的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripIterator
{
public:
	///构造方法
	CSysEventDescripIterator(void)
	{
	}

	///构造方法
	CSysEventDescripIterator(CSysEventDescripFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysEventDescripIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysEventDescrip
	///@return	下一个满足条件CSysEventDescrip，如果已经没有一个满足要求了，则返回NULL
	virtual CSysEventDescrip *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysEventDescripFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysEventDescrip 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysEventDescrip * pSysEventDescrip,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysEventDescripFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableRspQryHostEnvCommon是一个存储主机环境信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableRspQryHostEnvCommon
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! HostModel.isValid())
			return 0;
		if (! MainMemory.isValid())
			return 0;
		if (! CPUVendor.isValid())
			return 0;
		if (! CPUModel.isValid())
			return 0;
		if (! CPUMHz.isValid())
			return 0;
		if (! CPUCache.isValid())
			return 0;
		if (! CPUCores.isValid())
			return 0;
		if (! Processors.isValid())
			return 0;
		if (! OsMode.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableRspQryHostEnvCommon *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///主机名称
	CTypeObjectIDType HostName;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///主机型号
	CTypeHostModelType HostModel;
	///内存大小(K)
	CVolumeType MainMemory;
	///CPU厂商
	CTypeHostModelType CPUVendor;
	///CPU型号
	CTypeHostModelType CPUModel;
	///CPU主频
	CTypeHostModelType CPUMHz;
	///CPU缓存
	CTypeHostModelType CPUCache;
	///CPU内核数
	CVolumeType CPUCores;
	///CPU个数
	CVolumeType Processors;
	///32位还是64位操作系统
	CVolumeType OsMode;
	
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

typedef const CWriteableRspQryHostEnvCommon CRspQryHostEnvCommon;

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonActionTrigger是操作主机环境信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonActionTrigger
{
public:
	///构造方法
	CRspQryHostEnvCommonActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CRspQryHostEnvCommonActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CRspQryHostEnvCommonFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pRspQryHostEnvCommon	要加入的RspQryHostEnvCommon
	virtual void beforeAdd(CWriteableRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return;
	}
	
	///加入后触发
	///@param	pRspQryHostEnvCommon	已经加入的RspQryHostEnvCommon
	virtual void afterAdd(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return;
	}

	///更新前触发	
	///@param	pRspQryHostEnvCommon	被刷新的CRspQryHostEnvCommon
	///@param	pNewRspQryHostEnvCommon	新的值
	virtual void beforeUpdate(CRspQryHostEnvCommon *pRspQryHostEnvCommon, CWriteableRspQryHostEnvCommon *pNewRspQryHostEnvCommon)
	{
		return;
	}
	
	///更新后触发
	///@param	pRspQryHostEnvCommon	被刷新的CRspQryHostEnvCommon
	virtual void afterUpdate(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return;
	}
	
	///删除前触发
	///@param	pRspQryHostEnvCommon	要删除的CRspQryHostEnvCommon
	virtual void beforeRemove(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CRspQryHostEnvCommonFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonCommitTrigger是确认主机环境信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonCommitTrigger
{
public:
	///构造方法
	CRspQryHostEnvCommonCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CRspQryHostEnvCommonCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CRspQryHostEnvCommonFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pRspQryHostEnvCommon	已经加入的RspQryHostEnvCommon
	virtual void commitAdd(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return;
	}

	///更新后触发
	///@param	pRspQryHostEnvCommon	被刷新的CRspQryHostEnvCommon
	///@param	poldRspQryHostEnvCommon	原来的值
	virtual void commitUpdate(CRspQryHostEnvCommon *pRspQryHostEnvCommon, CWriteableRspQryHostEnvCommon *pOldRspQryHostEnvCommon)
	{
		return;
	}
	
	///删除后触发
	///@param	pRspQryHostEnvCommon	已经删除的CRspQryHostEnvCommon
	virtual void commitRemove(CWriteableRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CRspQryHostEnvCommonFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonIterator是一个对主机环境信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonIterator
{
public:
	///构造方法
	CRspQryHostEnvCommonIterator(void)
	{
	}

	///构造方法
	CRspQryHostEnvCommonIterator(CRspQryHostEnvCommonFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvCommonIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个RspQryHostEnvCommon
	///@return	下一个满足条件CRspQryHostEnvCommon，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvCommon *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CRspQryHostEnvCommonFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvCommon 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvCommon * pRspQryHostEnvCommon,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CRspQryHostEnvCommonFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableRspQryHostEnvLan是一个存储主机环境Lan信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableRspQryHostEnvLan
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! LanHardwareID.isValid())
			return 0;
		if (! LanHardwareValue.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableRspQryHostEnvLan *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///主机名称
	CTypeObjectIDType HostName;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///LanID
	CTypeHostModelType LanHardwareID;
	///Mac地址
	CTypeHostModelType LanHardwareValue;
	
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

typedef const CWriteableRspQryHostEnvLan CRspQryHostEnvLan;

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanActionTrigger是操作主机环境Lan信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanActionTrigger
{
public:
	///构造方法
	CRspQryHostEnvLanActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CRspQryHostEnvLanActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CRspQryHostEnvLanFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pRspQryHostEnvLan	要加入的RspQryHostEnvLan
	virtual void beforeAdd(CWriteableRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return;
	}
	
	///加入后触发
	///@param	pRspQryHostEnvLan	已经加入的RspQryHostEnvLan
	virtual void afterAdd(CRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return;
	}

	///更新前触发	
	///@param	pRspQryHostEnvLan	被刷新的CRspQryHostEnvLan
	///@param	pNewRspQryHostEnvLan	新的值
	virtual void beforeUpdate(CRspQryHostEnvLan *pRspQryHostEnvLan, CWriteableRspQryHostEnvLan *pNewRspQryHostEnvLan)
	{
		return;
	}
	
	///更新后触发
	///@param	pRspQryHostEnvLan	被刷新的CRspQryHostEnvLan
	virtual void afterUpdate(CRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return;
	}
	
	///删除前触发
	///@param	pRspQryHostEnvLan	要删除的CRspQryHostEnvLan
	virtual void beforeRemove(CRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CRspQryHostEnvLanFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCommitTrigger是确认主机环境Lan信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCommitTrigger
{
public:
	///构造方法
	CRspQryHostEnvLanCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CRspQryHostEnvLanCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CRspQryHostEnvLanFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pRspQryHostEnvLan	已经加入的RspQryHostEnvLan
	virtual void commitAdd(CRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return;
	}

	///更新后触发
	///@param	pRspQryHostEnvLan	被刷新的CRspQryHostEnvLan
	///@param	poldRspQryHostEnvLan	原来的值
	virtual void commitUpdate(CRspQryHostEnvLan *pRspQryHostEnvLan, CWriteableRspQryHostEnvLan *pOldRspQryHostEnvLan)
	{
		return;
	}
	
	///删除后触发
	///@param	pRspQryHostEnvLan	已经删除的CRspQryHostEnvLan
	virtual void commitRemove(CWriteableRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CRspQryHostEnvLanFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanIterator是一个对主机环境Lan信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanIterator
{
public:
	///构造方法
	CRspQryHostEnvLanIterator(void)
	{
	}

	///构造方法
	CRspQryHostEnvLanIterator(CRspQryHostEnvLanFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvLanIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个RspQryHostEnvLan
	///@return	下一个满足条件CRspQryHostEnvLan，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvLan *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CRspQryHostEnvLanFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvLan 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLan * pRspQryHostEnvLan,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CRspQryHostEnvLanFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableRspQryHostEnvStorage是一个存储主机环境存储设备信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableRspQryHostEnvStorage
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! StorageDev.isValid())
			return 0;
		if (! HWPath.isValid())
			return 0;
		if (! Interface.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableRspQryHostEnvStorage *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///主机名称
	CTypeObjectIDType HostName;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///Storage Devices
	CTypeHostModelType StorageDev;
	///HW Path
	CTypeHostModelType HWPath;
	///Interface
	CTypeHostModelType Interface;
	
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

typedef const CWriteableRspQryHostEnvStorage CRspQryHostEnvStorage;

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageActionTrigger是操作主机环境存储设备信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageActionTrigger
{
public:
	///构造方法
	CRspQryHostEnvStorageActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CRspQryHostEnvStorageActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CRspQryHostEnvStorageFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pRspQryHostEnvStorage	要加入的RspQryHostEnvStorage
	virtual void beforeAdd(CWriteableRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return;
	}
	
	///加入后触发
	///@param	pRspQryHostEnvStorage	已经加入的RspQryHostEnvStorage
	virtual void afterAdd(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return;
	}

	///更新前触发	
	///@param	pRspQryHostEnvStorage	被刷新的CRspQryHostEnvStorage
	///@param	pNewRspQryHostEnvStorage	新的值
	virtual void beforeUpdate(CRspQryHostEnvStorage *pRspQryHostEnvStorage, CWriteableRspQryHostEnvStorage *pNewRspQryHostEnvStorage)
	{
		return;
	}
	
	///更新后触发
	///@param	pRspQryHostEnvStorage	被刷新的CRspQryHostEnvStorage
	virtual void afterUpdate(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return;
	}
	
	///删除前触发
	///@param	pRspQryHostEnvStorage	要删除的CRspQryHostEnvStorage
	virtual void beforeRemove(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CRspQryHostEnvStorageFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageCommitTrigger是确认主机环境存储设备信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageCommitTrigger
{
public:
	///构造方法
	CRspQryHostEnvStorageCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CRspQryHostEnvStorageCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CRspQryHostEnvStorageFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pRspQryHostEnvStorage	已经加入的RspQryHostEnvStorage
	virtual void commitAdd(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return;
	}

	///更新后触发
	///@param	pRspQryHostEnvStorage	被刷新的CRspQryHostEnvStorage
	///@param	poldRspQryHostEnvStorage	原来的值
	virtual void commitUpdate(CRspQryHostEnvStorage *pRspQryHostEnvStorage, CWriteableRspQryHostEnvStorage *pOldRspQryHostEnvStorage)
	{
		return;
	}
	
	///删除后触发
	///@param	pRspQryHostEnvStorage	已经删除的CRspQryHostEnvStorage
	virtual void commitRemove(CWriteableRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CRspQryHostEnvStorageFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageIterator是一个对主机环境存储设备信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageIterator
{
public:
	///构造方法
	CRspQryHostEnvStorageIterator(void)
	{
	}

	///构造方法
	CRspQryHostEnvStorageIterator(CRspQryHostEnvStorageFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvStorageIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个RspQryHostEnvStorage
	///@return	下一个满足条件CRspQryHostEnvStorage，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvStorage *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CRspQryHostEnvStorageFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvStorage 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvStorage * pRspQryHostEnvStorage,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CRspQryHostEnvStorageFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableRspQryHostEnvIO是一个存储主机环境IO设备信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableRspQryHostEnvIO
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! IoClass.isValid())
			return 0;
		if (! H_WPath.isValid())
			return 0;
		if (! IoDriver.isValid())
			return 0;
		if (! IoDescription.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableRspQryHostEnvIO *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///主机名称
	CTypeObjectIDType HostName;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///IO Class
	CTypeChar10Type IoClass;
	///H/W Path
	CTypeChar10Type H_WPath;
	///Driver
	CTypeChar10Type IoDriver;
	///Description
	CTypeDescriptionType IoDescription;
	
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

typedef const CWriteableRspQryHostEnvIO CRspQryHostEnvIO;

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOActionTrigger是操作主机环境IO设备信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOActionTrigger
{
public:
	///构造方法
	CRspQryHostEnvIOActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CRspQryHostEnvIOActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CRspQryHostEnvIOFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pRspQryHostEnvIO	要加入的RspQryHostEnvIO
	virtual void beforeAdd(CWriteableRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return;
	}
	
	///加入后触发
	///@param	pRspQryHostEnvIO	已经加入的RspQryHostEnvIO
	virtual void afterAdd(CRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return;
	}

	///更新前触发	
	///@param	pRspQryHostEnvIO	被刷新的CRspQryHostEnvIO
	///@param	pNewRspQryHostEnvIO	新的值
	virtual void beforeUpdate(CRspQryHostEnvIO *pRspQryHostEnvIO, CWriteableRspQryHostEnvIO *pNewRspQryHostEnvIO)
	{
		return;
	}
	
	///更新后触发
	///@param	pRspQryHostEnvIO	被刷新的CRspQryHostEnvIO
	virtual void afterUpdate(CRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return;
	}
	
	///删除前触发
	///@param	pRspQryHostEnvIO	要删除的CRspQryHostEnvIO
	virtual void beforeRemove(CRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CRspQryHostEnvIOFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOCommitTrigger是确认主机环境IO设备信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOCommitTrigger
{
public:
	///构造方法
	CRspQryHostEnvIOCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CRspQryHostEnvIOCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CRspQryHostEnvIOFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pRspQryHostEnvIO	已经加入的RspQryHostEnvIO
	virtual void commitAdd(CRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return;
	}

	///更新后触发
	///@param	pRspQryHostEnvIO	被刷新的CRspQryHostEnvIO
	///@param	poldRspQryHostEnvIO	原来的值
	virtual void commitUpdate(CRspQryHostEnvIO *pRspQryHostEnvIO, CWriteableRspQryHostEnvIO *pOldRspQryHostEnvIO)
	{
		return;
	}
	
	///删除后触发
	///@param	pRspQryHostEnvIO	已经删除的CRspQryHostEnvIO
	virtual void commitRemove(CWriteableRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CRspQryHostEnvIOFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOIterator是一个对主机环境IO设备信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOIterator
{
public:
	///构造方法
	CRspQryHostEnvIOIterator(void)
	{
	}

	///构造方法
	CRspQryHostEnvIOIterator(CRspQryHostEnvIOFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvIOIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个RspQryHostEnvIO
	///@return	下一个满足条件CRspQryHostEnvIO，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvIO *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CRspQryHostEnvIOFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvIO 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvIO * pRspQryHostEnvIO,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CRspQryHostEnvIOFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableRspQryHostEnvFS是一个存储主机环境文件系统信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableRspQryHostEnvFS
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! LVMDeviceFile.isValid())
			return 0;
		if (! MountPoint.isValid())
			return 0;
		if (! FSsize.isValid())
			return 0;
		if (! FSType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableRspQryHostEnvFS *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///主机名称
	CTypeObjectIDType HostName;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///LVM Device file
	CTypeHostModelType LVMDeviceFile;
	///mount point
	CTypeCommandType MountPoint;
	///size
	CVolumeType FSsize;
	///fs type
	CTypeChar10Type FSType;
	
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

typedef const CWriteableRspQryHostEnvFS CRspQryHostEnvFS;

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSActionTrigger是操作主机环境文件系统信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSActionTrigger
{
public:
	///构造方法
	CRspQryHostEnvFSActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CRspQryHostEnvFSActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CRspQryHostEnvFSFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pRspQryHostEnvFS	要加入的RspQryHostEnvFS
	virtual void beforeAdd(CWriteableRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return;
	}
	
	///加入后触发
	///@param	pRspQryHostEnvFS	已经加入的RspQryHostEnvFS
	virtual void afterAdd(CRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return;
	}

	///更新前触发	
	///@param	pRspQryHostEnvFS	被刷新的CRspQryHostEnvFS
	///@param	pNewRspQryHostEnvFS	新的值
	virtual void beforeUpdate(CRspQryHostEnvFS *pRspQryHostEnvFS, CWriteableRspQryHostEnvFS *pNewRspQryHostEnvFS)
	{
		return;
	}
	
	///更新后触发
	///@param	pRspQryHostEnvFS	被刷新的CRspQryHostEnvFS
	virtual void afterUpdate(CRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return;
	}
	
	///删除前触发
	///@param	pRspQryHostEnvFS	要删除的CRspQryHostEnvFS
	virtual void beforeRemove(CRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CRspQryHostEnvFSFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSCommitTrigger是确认主机环境文件系统信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSCommitTrigger
{
public:
	///构造方法
	CRspQryHostEnvFSCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CRspQryHostEnvFSCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CRspQryHostEnvFSFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pRspQryHostEnvFS	已经加入的RspQryHostEnvFS
	virtual void commitAdd(CRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return;
	}

	///更新后触发
	///@param	pRspQryHostEnvFS	被刷新的CRspQryHostEnvFS
	///@param	poldRspQryHostEnvFS	原来的值
	virtual void commitUpdate(CRspQryHostEnvFS *pRspQryHostEnvFS, CWriteableRspQryHostEnvFS *pOldRspQryHostEnvFS)
	{
		return;
	}
	
	///删除后触发
	///@param	pRspQryHostEnvFS	已经删除的CRspQryHostEnvFS
	virtual void commitRemove(CWriteableRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CRspQryHostEnvFSFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSIterator是一个对主机环境文件系统信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSIterator
{
public:
	///构造方法
	CRspQryHostEnvFSIterator(void)
	{
	}

	///构造方法
	CRspQryHostEnvFSIterator(CRspQryHostEnvFSFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvFSIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个RspQryHostEnvFS
	///@return	下一个满足条件CRspQryHostEnvFS，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvFS *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CRspQryHostEnvFSFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvFS 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvFS * pRspQryHostEnvFS,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CRspQryHostEnvFSFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableRspQryHostEnvSwap是一个存储主机环境交换分区信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableRspQryHostEnvSwap
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! type.isValid())
			return 0;
		if (! size.isValid())
			return 0;
		if (! priority.isValid())
			return 0;
		if (! location.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableRspQryHostEnvSwap *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///主机名称
	CTypeObjectIDType HostName;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///type
	CTypeChar10Type type;
	///size
	CVolumeType size;
	///priority
	CVolumeType priority;
	///device location
	CTypeHostModelType location;
	
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

typedef const CWriteableRspQryHostEnvSwap CRspQryHostEnvSwap;

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapActionTrigger是操作主机环境交换分区信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapActionTrigger
{
public:
	///构造方法
	CRspQryHostEnvSwapActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CRspQryHostEnvSwapActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CRspQryHostEnvSwapFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pRspQryHostEnvSwap	要加入的RspQryHostEnvSwap
	virtual void beforeAdd(CWriteableRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return;
	}
	
	///加入后触发
	///@param	pRspQryHostEnvSwap	已经加入的RspQryHostEnvSwap
	virtual void afterAdd(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return;
	}

	///更新前触发	
	///@param	pRspQryHostEnvSwap	被刷新的CRspQryHostEnvSwap
	///@param	pNewRspQryHostEnvSwap	新的值
	virtual void beforeUpdate(CRspQryHostEnvSwap *pRspQryHostEnvSwap, CWriteableRspQryHostEnvSwap *pNewRspQryHostEnvSwap)
	{
		return;
	}
	
	///更新后触发
	///@param	pRspQryHostEnvSwap	被刷新的CRspQryHostEnvSwap
	virtual void afterUpdate(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return;
	}
	
	///删除前触发
	///@param	pRspQryHostEnvSwap	要删除的CRspQryHostEnvSwap
	virtual void beforeRemove(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CRspQryHostEnvSwapFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapCommitTrigger是确认主机环境交换分区信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapCommitTrigger
{
public:
	///构造方法
	CRspQryHostEnvSwapCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CRspQryHostEnvSwapCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CRspQryHostEnvSwapFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pRspQryHostEnvSwap	已经加入的RspQryHostEnvSwap
	virtual void commitAdd(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return;
	}

	///更新后触发
	///@param	pRspQryHostEnvSwap	被刷新的CRspQryHostEnvSwap
	///@param	poldRspQryHostEnvSwap	原来的值
	virtual void commitUpdate(CRspQryHostEnvSwap *pRspQryHostEnvSwap, CWriteableRspQryHostEnvSwap *pOldRspQryHostEnvSwap)
	{
		return;
	}
	
	///删除后触发
	///@param	pRspQryHostEnvSwap	已经删除的CRspQryHostEnvSwap
	virtual void commitRemove(CWriteableRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CRspQryHostEnvSwapFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapIterator是一个对主机环境交换分区信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapIterator
{
public:
	///构造方法
	CRspQryHostEnvSwapIterator(void)
	{
	}

	///构造方法
	CRspQryHostEnvSwapIterator(CRspQryHostEnvSwapFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvSwapIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个RspQryHostEnvSwap
	///@return	下一个满足条件CRspQryHostEnvSwap，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvSwap *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CRspQryHostEnvSwapFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvSwap 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvSwap * pRspQryHostEnvSwap,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CRspQryHostEnvSwapFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableRspQryHostEnvLanCfg是一个存储主机环境网卡配置信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableRspQryHostEnvLanCfg
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! LanName.isValid())
			return 0;
		if (! IpAddress.isValid())
			return 0;
		if (! IpMask.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableRspQryHostEnvLanCfg *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///主机名称
	CTypeObjectIDType HostName;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	CTypeLanNameType LanName;
	CIPAddressType IpAddress;
	CIPAddressType IpMask;
	
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

typedef const CWriteableRspQryHostEnvLanCfg CRspQryHostEnvLanCfg;

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgActionTrigger是操作主机环境网卡配置信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgActionTrigger
{
public:
	///构造方法
	CRspQryHostEnvLanCfgActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CRspQryHostEnvLanCfgActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CRspQryHostEnvLanCfgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pRspQryHostEnvLanCfg	要加入的RspQryHostEnvLanCfg
	virtual void beforeAdd(CWriteableRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return;
	}
	
	///加入后触发
	///@param	pRspQryHostEnvLanCfg	已经加入的RspQryHostEnvLanCfg
	virtual void afterAdd(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return;
	}

	///更新前触发	
	///@param	pRspQryHostEnvLanCfg	被刷新的CRspQryHostEnvLanCfg
	///@param	pNewRspQryHostEnvLanCfg	新的值
	virtual void beforeUpdate(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, CWriteableRspQryHostEnvLanCfg *pNewRspQryHostEnvLanCfg)
	{
		return;
	}
	
	///更新后触发
	///@param	pRspQryHostEnvLanCfg	被刷新的CRspQryHostEnvLanCfg
	virtual void afterUpdate(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return;
	}
	
	///删除前触发
	///@param	pRspQryHostEnvLanCfg	要删除的CRspQryHostEnvLanCfg
	virtual void beforeRemove(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CRspQryHostEnvLanCfgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgCommitTrigger是确认主机环境网卡配置信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgCommitTrigger
{
public:
	///构造方法
	CRspQryHostEnvLanCfgCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CRspQryHostEnvLanCfgCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CRspQryHostEnvLanCfgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pRspQryHostEnvLanCfg	已经加入的RspQryHostEnvLanCfg
	virtual void commitAdd(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return;
	}

	///更新后触发
	///@param	pRspQryHostEnvLanCfg	被刷新的CRspQryHostEnvLanCfg
	///@param	poldRspQryHostEnvLanCfg	原来的值
	virtual void commitUpdate(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, CWriteableRspQryHostEnvLanCfg *pOldRspQryHostEnvLanCfg)
	{
		return;
	}
	
	///删除后触发
	///@param	pRspQryHostEnvLanCfg	已经删除的CRspQryHostEnvLanCfg
	virtual void commitRemove(CWriteableRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CRspQryHostEnvLanCfgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgIterator是一个对主机环境网卡配置信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgIterator
{
public:
	///构造方法
	CRspQryHostEnvLanCfgIterator(void)
	{
	}

	///构造方法
	CRspQryHostEnvLanCfgIterator(CRspQryHostEnvLanCfgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvLanCfgIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个RspQryHostEnvLanCfg
	///@return	下一个满足条件CRspQryHostEnvLanCfg，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvLanCfg *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CRspQryHostEnvLanCfgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvLanCfg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CRspQryHostEnvLanCfgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbTopCpuInfo是一个存储CPU资源使用信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbTopCpuInfo
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! CPU.isValid())
			return 0;
		if (! LOAD.isValid())
			return 0;
		if (! USER.isValid())
			return 0;
		if (! NICE.isValid())
			return 0;
		if (! SYS.isValid())
			return 0;
		if (! IDLE.isValid())
			return 0;
		if (! BLOCK.isValid())
			return 0;
		if (! SWAIT.isValid())
			return 0;
		if (! INTR.isValid())
			return 0;
		if (! SSYS.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbTopCpuInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///主机名称
	CVolumeType HostName;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///CPU的编号
	CTypeCPUIdType CPU;
	CRatioType LOAD;
	CRatioType USER;
	CRatioType NICE;
	CRatioType SYS;
	CRatioType IDLE;
	CRatioType BLOCK;
	CRatioType SWAIT;
	CRatioType INTR;
	CRatioType SSYS;
	
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

typedef const CWriteableSysMdbTopCpuInfo CSysMdbTopCpuInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoActionTrigger是操作CPU资源使用信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoActionTrigger
{
public:
	///构造方法
	CSysMdbTopCpuInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbTopCpuInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbTopCpuInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMdbTopCpuInfo	要加入的SysMdbTopCpuInfo
	virtual void beforeAdd(CWriteableSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMdbTopCpuInfo	已经加入的SysMdbTopCpuInfo
	virtual void afterAdd(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMdbTopCpuInfo	被刷新的CSysMdbTopCpuInfo
	///@param	pNewSysMdbTopCpuInfo	新的值
	virtual void beforeUpdate(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo, CWriteableSysMdbTopCpuInfo *pNewSysMdbTopCpuInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMdbTopCpuInfo	被刷新的CSysMdbTopCpuInfo
	virtual void afterUpdate(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMdbTopCpuInfo	要删除的CSysMdbTopCpuInfo
	virtual void beforeRemove(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbTopCpuInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoCommitTrigger是确认CPU资源使用信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoCommitTrigger
{
public:
	///构造方法
	CSysMdbTopCpuInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbTopCpuInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbTopCpuInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMdbTopCpuInfo	已经加入的SysMdbTopCpuInfo
	virtual void commitAdd(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysMdbTopCpuInfo	被刷新的CSysMdbTopCpuInfo
	///@param	poldSysMdbTopCpuInfo	原来的值
	virtual void commitUpdate(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo, CWriteableSysMdbTopCpuInfo *pOldSysMdbTopCpuInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMdbTopCpuInfo	已经删除的CSysMdbTopCpuInfo
	virtual void commitRemove(CWriteableSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbTopCpuInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoIterator是一个对CPU资源使用信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoIterator
{
public:
	///构造方法
	CSysMdbTopCpuInfoIterator(void)
	{
	}

	///构造方法
	CSysMdbTopCpuInfoIterator(CSysMdbTopCpuInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopCpuInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMdbTopCpuInfo
	///@return	下一个满足条件CSysMdbTopCpuInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopCpuInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMdbTopCpuInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbTopCpuInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopCpuInfo * pSysMdbTopCpuInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMdbTopCpuInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbTopMemInfo是一个存储内存资源使用信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbTopMemInfo
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! TOTALREAL.isValid())
			return 0;
		if (! ACTIVEREAL.isValid())
			return 0;
		if (! TOTALVIRTUAL.isValid())
			return 0;
		if (! ACTIVEVIRTUAL.isValid())
			return 0;
		if (! FREE.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbTopMemInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///主机名称
	CVolumeType HostName;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///Total Real Memory
	CVolumeType TOTALREAL;
	///Active Real Memory
	CVolumeType ACTIVEREAL;
	///Total Virtual Memory
	CVolumeType TOTALVIRTUAL;
	///Active Virtual Memory
	CVolumeType ACTIVEVIRTUAL;
	///Free Memory
	CVolumeType FREE;
	
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

typedef const CWriteableSysMdbTopMemInfo CSysMdbTopMemInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoActionTrigger是操作内存资源使用信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoActionTrigger
{
public:
	///构造方法
	CSysMdbTopMemInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbTopMemInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbTopMemInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMdbTopMemInfo	要加入的SysMdbTopMemInfo
	virtual void beforeAdd(CWriteableSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMdbTopMemInfo	已经加入的SysMdbTopMemInfo
	virtual void afterAdd(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMdbTopMemInfo	被刷新的CSysMdbTopMemInfo
	///@param	pNewSysMdbTopMemInfo	新的值
	virtual void beforeUpdate(CSysMdbTopMemInfo *pSysMdbTopMemInfo, CWriteableSysMdbTopMemInfo *pNewSysMdbTopMemInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMdbTopMemInfo	被刷新的CSysMdbTopMemInfo
	virtual void afterUpdate(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMdbTopMemInfo	要删除的CSysMdbTopMemInfo
	virtual void beforeRemove(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbTopMemInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoCommitTrigger是确认内存资源使用信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoCommitTrigger
{
public:
	///构造方法
	CSysMdbTopMemInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbTopMemInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbTopMemInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMdbTopMemInfo	已经加入的SysMdbTopMemInfo
	virtual void commitAdd(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysMdbTopMemInfo	被刷新的CSysMdbTopMemInfo
	///@param	poldSysMdbTopMemInfo	原来的值
	virtual void commitUpdate(CSysMdbTopMemInfo *pSysMdbTopMemInfo, CWriteableSysMdbTopMemInfo *pOldSysMdbTopMemInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMdbTopMemInfo	已经删除的CSysMdbTopMemInfo
	virtual void commitRemove(CWriteableSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbTopMemInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoIterator是一个对内存资源使用信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoIterator
{
public:
	///构造方法
	CSysMdbTopMemInfoIterator(void)
	{
	}

	///构造方法
	CSysMdbTopMemInfoIterator(CSysMdbTopMemInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopMemInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMdbTopMemInfo
	///@return	下一个满足条件CSysMdbTopMemInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopMemInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMdbTopMemInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbTopMemInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopMemInfo * pSysMdbTopMemInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMdbTopMemInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbTopProcessInfo是一个存储进程信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbTopProcessInfo
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! CPU.isValid())
			return 0;
		if (! TTY.isValid())
			return 0;
		if (! PID.isValid())
			return 0;
		if (! USERNAME.isValid())
			return 0;
		if (! PRI.isValid())
			return 0;
		if (! NI.isValid())
			return 0;
		if (! SIZE.isValid())
			return 0;
		if (! RES.isValid())
			return 0;
		if (! STATE.isValid())
			return 0;
		if (! TIME.isValid())
			return 0;
		if (! pWCPU.isValid())
			return 0;
		if (! pCPU.isValid())
			return 0;
		if (! COMMAND.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbTopProcessInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///主机名称
	CVolumeType HostName;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///处理器号
	CTypeCPUIdType CPU;
	///终端名
	CTypeChar10Type TTY;
	///进程号
	CVolumeType PID;
	///用户名
	CTypeChar10Type USERNAME;
	///任务的优先级
	CVolumeType PRI;
	///任务的nice值
	CVolumeType NI;
	///任务的代码加上数据再加上栈空间的大小
	CVolumeType SIZE;
	///任务使用的物理内存的总数量
	CVolumeType RES;
	///任务的状态
	CTypeChar10Type STATE;
	///自任务开始时使用的总CPU时间
	CTimeType TIME;
	///进程的CPU利用率权重百分比
	CRatioType pWCPU;
	///进程的原始的CPU利用率百分比
	CRatioType pCPU;
	///启动进程的命令名
	CTypeCommandType COMMAND;
	
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

typedef const CWriteableSysMdbTopProcessInfo CSysMdbTopProcessInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoActionTrigger是操作进程信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoActionTrigger
{
public:
	///构造方法
	CSysMdbTopProcessInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbTopProcessInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbTopProcessInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMdbTopProcessInfo	要加入的SysMdbTopProcessInfo
	virtual void beforeAdd(CWriteableSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMdbTopProcessInfo	已经加入的SysMdbTopProcessInfo
	virtual void afterAdd(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMdbTopProcessInfo	被刷新的CSysMdbTopProcessInfo
	///@param	pNewSysMdbTopProcessInfo	新的值
	virtual void beforeUpdate(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo, CWriteableSysMdbTopProcessInfo *pNewSysMdbTopProcessInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMdbTopProcessInfo	被刷新的CSysMdbTopProcessInfo
	virtual void afterUpdate(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMdbTopProcessInfo	要删除的CSysMdbTopProcessInfo
	virtual void beforeRemove(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbTopProcessInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoCommitTrigger是确认进程信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoCommitTrigger
{
public:
	///构造方法
	CSysMdbTopProcessInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbTopProcessInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbTopProcessInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMdbTopProcessInfo	已经加入的SysMdbTopProcessInfo
	virtual void commitAdd(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysMdbTopProcessInfo	被刷新的CSysMdbTopProcessInfo
	///@param	poldSysMdbTopProcessInfo	原来的值
	virtual void commitUpdate(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo, CWriteableSysMdbTopProcessInfo *pOldSysMdbTopProcessInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMdbTopProcessInfo	已经删除的CSysMdbTopProcessInfo
	virtual void commitRemove(CWriteableSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbTopProcessInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoIterator是一个对进程信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoIterator
{
public:
	///构造方法
	CSysMdbTopProcessInfoIterator(void)
	{
	}

	///构造方法
	CSysMdbTopProcessInfoIterator(CSysMdbTopProcessInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopProcessInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMdbTopProcessInfo
	///@return	下一个满足条件CSysMdbTopProcessInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopProcessInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMdbTopProcessInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbTopProcessInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopProcessInfo * pSysMdbTopProcessInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMdbTopProcessInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbFileSystemInfo是一个存储文件系统信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbFileSystemInfo
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! FILESYSTEM.isValid())
			return 0;
		if (! SIZE.isValid())
			return 0;
		if (! USED.isValid())
			return 0;
		if (! AVAIL.isValid())
			return 0;
		if (! pUSERD.isValid())
			return 0;
		if (! ISIZE.isValid())
			return 0;
		if (! IUSED.isValid())
			return 0;
		if (! IFREE.isValid())
			return 0;
		if (! pIUSED.isValid())
			return 0;
		if (! MountedOn.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbFileSystemInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///主机名称
	CVolumeType HostName;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///文件系统物理名
	CTypeCommandType FILESYSTEM;
	///空间总数
	CVolumeType SIZE;
	///已用空间大小
	CVolumeType USED;
	///可用空间大小
	CVolumeType AVAIL;
	///已用的百分比
	CRatioType pUSERD;
	///inode总数
	CVolumeType ISIZE;
	///已用inode大小
	CVolumeType IUSED;
	///可用inode大小
	CVolumeType IFREE;
	///已用的百分比
	CRatioType pIUSED;
	///加载位置
	CTypeCommandType MountedOn;
	
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

typedef const CWriteableSysMdbFileSystemInfo CSysMdbFileSystemInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoActionTrigger是操作文件系统信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoActionTrigger
{
public:
	///构造方法
	CSysMdbFileSystemInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbFileSystemInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbFileSystemInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMdbFileSystemInfo	要加入的SysMdbFileSystemInfo
	virtual void beforeAdd(CWriteableSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMdbFileSystemInfo	已经加入的SysMdbFileSystemInfo
	virtual void afterAdd(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMdbFileSystemInfo	被刷新的CSysMdbFileSystemInfo
	///@param	pNewSysMdbFileSystemInfo	新的值
	virtual void beforeUpdate(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo, CWriteableSysMdbFileSystemInfo *pNewSysMdbFileSystemInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMdbFileSystemInfo	被刷新的CSysMdbFileSystemInfo
	virtual void afterUpdate(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMdbFileSystemInfo	要删除的CSysMdbFileSystemInfo
	virtual void beforeRemove(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbFileSystemInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoCommitTrigger是确认文件系统信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoCommitTrigger
{
public:
	///构造方法
	CSysMdbFileSystemInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbFileSystemInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbFileSystemInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMdbFileSystemInfo	已经加入的SysMdbFileSystemInfo
	virtual void commitAdd(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysMdbFileSystemInfo	被刷新的CSysMdbFileSystemInfo
	///@param	poldSysMdbFileSystemInfo	原来的值
	virtual void commitUpdate(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo, CWriteableSysMdbFileSystemInfo *pOldSysMdbFileSystemInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMdbFileSystemInfo	已经删除的CSysMdbFileSystemInfo
	virtual void commitRemove(CWriteableSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbFileSystemInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoIterator是一个对文件系统信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoIterator
{
public:
	///构造方法
	CSysMdbFileSystemInfoIterator(void)
	{
	}

	///构造方法
	CSysMdbFileSystemInfoIterator(CSysMdbFileSystemInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbFileSystemInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMdbFileSystemInfo
	///@return	下一个满足条件CSysMdbFileSystemInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbFileSystemInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMdbFileSystemInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbFileSystemInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbFileSystemInfo * pSysMdbFileSystemInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMdbFileSystemInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbNetworkInfo是一个存储网络使用信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbNetworkInfo
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
		if (! SubcriberID.isValid())
			return 0;
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! LANNAME.isValid())
			return 0;
		if (! LANSTATUS.isValid())
			return 0;
		if (! IPADDRESS.isValid())
			return 0;
		if (! RECVBYTES.isValid())
			return 0;
		if (! RECVPACKETS.isValid())
			return 0;
		if (! RECVERRORPACKETS.isValid())
			return 0;
		if (! RECVDROPPACKETS.isValid())
			return 0;
		if (! SENDBYTES.isValid())
			return 0;
		if (! SENDPACKETS.isValid())
			return 0;
		if (! SENDERRORPACKETS.isValid())
			return 0;
		if (! SENDDROPPACKETS.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbNetworkInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///订阅对象ID
	CVolumeType SubcriberID;
	///主机名称
	CVolumeType HostName;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///网卡名
	CTypeLanNameType LANNAME;
	///网卡的up或down状态
	CTypeLanStatusType LANSTATUS;
	///网卡的ip地址
	CIPAddressType IPADDRESS;
	///网卡接收的流量
	CLargeNumberType RECVBYTES;
	///网卡接收的数据包
	CLargeNumberType RECVPACKETS;
	///网卡接收端错误数据包
	CLargeNumberType RECVERRORPACKETS;
	///网卡接收端丢失数据包
	CLargeNumberType RECVDROPPACKETS;
	///网卡发送的流量
	CLargeNumberType SENDBYTES;
	///网卡发送的数据包
	CLargeNumberType SENDPACKETS;
	///网卡发送端错误数据包
	CLargeNumberType SENDERRORPACKETS;
	///网卡发送端丢失数据包
	CLargeNumberType SENDDROPPACKETS;
	
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

typedef const CWriteableSysMdbNetworkInfo CSysMdbNetworkInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoActionTrigger是操作网络使用信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoActionTrigger
{
public:
	///构造方法
	CSysMdbNetworkInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbNetworkInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbNetworkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMdbNetworkInfo	要加入的SysMdbNetworkInfo
	virtual void beforeAdd(CWriteableSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMdbNetworkInfo	已经加入的SysMdbNetworkInfo
	virtual void afterAdd(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMdbNetworkInfo	被刷新的CSysMdbNetworkInfo
	///@param	pNewSysMdbNetworkInfo	新的值
	virtual void beforeUpdate(CSysMdbNetworkInfo *pSysMdbNetworkInfo, CWriteableSysMdbNetworkInfo *pNewSysMdbNetworkInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMdbNetworkInfo	被刷新的CSysMdbNetworkInfo
	virtual void afterUpdate(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMdbNetworkInfo	要删除的CSysMdbNetworkInfo
	virtual void beforeRemove(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbNetworkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoCommitTrigger是确认网络使用信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoCommitTrigger
{
public:
	///构造方法
	CSysMdbNetworkInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbNetworkInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbNetworkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMdbNetworkInfo	已经加入的SysMdbNetworkInfo
	virtual void commitAdd(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysMdbNetworkInfo	被刷新的CSysMdbNetworkInfo
	///@param	poldSysMdbNetworkInfo	原来的值
	virtual void commitUpdate(CSysMdbNetworkInfo *pSysMdbNetworkInfo, CWriteableSysMdbNetworkInfo *pOldSysMdbNetworkInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMdbNetworkInfo	已经删除的CSysMdbNetworkInfo
	virtual void commitRemove(CWriteableSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbNetworkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoIterator是一个对网络使用信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoIterator
{
public:
	///构造方法
	CSysMdbNetworkInfoIterator(void)
	{
	}

	///构造方法
	CSysMdbNetworkInfoIterator(CSysMdbNetworkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbNetworkInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMdbNetworkInfo
	///@return	下一个满足条件CSysMdbNetworkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbNetworkInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMdbNetworkInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbNetworkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbNetworkInfo * pSysMdbNetworkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMdbNetworkInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysParticipantInit是一个存储会员的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysParticipantInit
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
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysParticipantInit *pOriginal) const;
	
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
	///操作类型
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysParticipantInit CSysParticipantInit;

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitActionTrigger是操作会员时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitActionTrigger
{
public:
	///构造方法
	CSysParticipantInitActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysParticipantInitActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysParticipantInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysParticipantInit	要加入的SysParticipantInit
	virtual void beforeAdd(CWriteableSysParticipantInit *pSysParticipantInit)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysParticipantInit	已经加入的SysParticipantInit
	virtual void afterAdd(CSysParticipantInit *pSysParticipantInit)
	{
		return;
	}

	///更新前触发	
	///@param	pSysParticipantInit	被刷新的CSysParticipantInit
	///@param	pNewSysParticipantInit	新的值
	virtual void beforeUpdate(CSysParticipantInit *pSysParticipantInit, CWriteableSysParticipantInit *pNewSysParticipantInit)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysParticipantInit	被刷新的CSysParticipantInit
	virtual void afterUpdate(CSysParticipantInit *pSysParticipantInit)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysParticipantInit	要删除的CSysParticipantInit
	virtual void beforeRemove(CSysParticipantInit *pSysParticipantInit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysParticipantInitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitCommitTrigger是确认会员时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitCommitTrigger
{
public:
	///构造方法
	CSysParticipantInitCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysParticipantInitCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysParticipantInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysParticipantInit	已经加入的SysParticipantInit
	virtual void commitAdd(CSysParticipantInit *pSysParticipantInit)
	{
		return;
	}

	///更新后触发
	///@param	pSysParticipantInit	被刷新的CSysParticipantInit
	///@param	poldSysParticipantInit	原来的值
	virtual void commitUpdate(CSysParticipantInit *pSysParticipantInit, CWriteableSysParticipantInit *pOldSysParticipantInit)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysParticipantInit	已经删除的CSysParticipantInit
	virtual void commitRemove(CWriteableSysParticipantInit *pSysParticipantInit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysParticipantInitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitIterator是一个对会员的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitIterator
{
public:
	///构造方法
	CSysParticipantInitIterator(void)
	{
	}

	///构造方法
	CSysParticipantInitIterator(CSysParticipantInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysParticipantInitIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysParticipantInit
	///@return	下一个满足条件CSysParticipantInit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysParticipantInit *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysParticipantInitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysParticipantInit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysParticipantInit * pSysParticipantInit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysParticipantInitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysUserInit是一个存储交易用户的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysUserInit
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
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysUserInit *pOriginal) const;
	
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
	///操作类型
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysUserInit CSysUserInit;

/////////////////////////////////////////////////////////////////////////
///CSysUserInitActionTrigger是操作交易用户时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitActionTrigger
{
public:
	///构造方法
	CSysUserInitActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysUserInitActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysUserInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysUserInit	要加入的SysUserInit
	virtual void beforeAdd(CWriteableSysUserInit *pSysUserInit)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysUserInit	已经加入的SysUserInit
	virtual void afterAdd(CSysUserInit *pSysUserInit)
	{
		return;
	}

	///更新前触发	
	///@param	pSysUserInit	被刷新的CSysUserInit
	///@param	pNewSysUserInit	新的值
	virtual void beforeUpdate(CSysUserInit *pSysUserInit, CWriteableSysUserInit *pNewSysUserInit)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysUserInit	被刷新的CSysUserInit
	virtual void afterUpdate(CSysUserInit *pSysUserInit)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysUserInit	要删除的CSysUserInit
	virtual void beforeRemove(CSysUserInit *pSysUserInit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysUserInitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitCommitTrigger是确认交易用户时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitCommitTrigger
{
public:
	///构造方法
	CSysUserInitCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysUserInitCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysUserInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysUserInit	已经加入的SysUserInit
	virtual void commitAdd(CSysUserInit *pSysUserInit)
	{
		return;
	}

	///更新后触发
	///@param	pSysUserInit	被刷新的CSysUserInit
	///@param	poldSysUserInit	原来的值
	virtual void commitUpdate(CSysUserInit *pSysUserInit, CWriteableSysUserInit *pOldSysUserInit)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysUserInit	已经删除的CSysUserInit
	virtual void commitRemove(CWriteableSysUserInit *pSysUserInit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysUserInitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitIterator是一个对交易用户的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitIterator
{
public:
	///构造方法
	CSysUserInitIterator(void)
	{
	}

	///构造方法
	CSysUserInitIterator(CSysUserInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysUserInitIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysUserInit
	///@return	下一个满足条件CSysUserInit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserInit *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysUserInitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysUserInit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserInit * pSysUserInit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysUserInitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysClientInit是一个存储客户的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysClientInit
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
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysClientInit *pOriginal) const;
	
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
	///操作类型
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysClientInit CSysClientInit;

/////////////////////////////////////////////////////////////////////////
///CSysClientInitActionTrigger是操作客户时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitActionTrigger
{
public:
	///构造方法
	CSysClientInitActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysClientInitActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysClientInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysClientInit	要加入的SysClientInit
	virtual void beforeAdd(CWriteableSysClientInit *pSysClientInit)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysClientInit	已经加入的SysClientInit
	virtual void afterAdd(CSysClientInit *pSysClientInit)
	{
		return;
	}

	///更新前触发	
	///@param	pSysClientInit	被刷新的CSysClientInit
	///@param	pNewSysClientInit	新的值
	virtual void beforeUpdate(CSysClientInit *pSysClientInit, CWriteableSysClientInit *pNewSysClientInit)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysClientInit	被刷新的CSysClientInit
	virtual void afterUpdate(CSysClientInit *pSysClientInit)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysClientInit	要删除的CSysClientInit
	virtual void beforeRemove(CSysClientInit *pSysClientInit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysClientInitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitCommitTrigger是确认客户时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitCommitTrigger
{
public:
	///构造方法
	CSysClientInitCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysClientInitCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysClientInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysClientInit	已经加入的SysClientInit
	virtual void commitAdd(CSysClientInit *pSysClientInit)
	{
		return;
	}

	///更新后触发
	///@param	pSysClientInit	被刷新的CSysClientInit
	///@param	poldSysClientInit	原来的值
	virtual void commitUpdate(CSysClientInit *pSysClientInit, CWriteableSysClientInit *pOldSysClientInit)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysClientInit	已经删除的CSysClientInit
	virtual void commitRemove(CWriteableSysClientInit *pSysClientInit)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysClientInitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitIterator是一个对客户的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitIterator
{
public:
	///构造方法
	CSysClientInitIterator(void)
	{
	}

	///构造方法
	CSysClientInitIterator(CSysClientInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysClientInitIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysClientInit
	///@return	下一个满足条件CSysClientInit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientInit *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysClientInitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysClientInit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientInit * pSysClientInit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysClientInitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysTradeUserLoginInfo是一个存储交易系统登录信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysTradeUserLoginInfo
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
		if (! ObjectID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ProtocolInfo.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! FrontID.isValid())
			return 0;
		if (! UserType.isValid())
			return 0;
		if (! AccessType.isValid())
			return 0;
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! ActionFlag.isValid())
			return 0;
		if (! DataCenter.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysTradeUserLoginInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///对象ID
	CTypeObjectIDType ObjectID;
	///交易用户代码
	CUserIDType UserID;
	///会员代码
	CParticipantIDType ParticipantID;
	///协议信息
	CProtocolInfoType ProtocolInfo;
	///IP地址
	CIPAddressType IPAddress;
	///前置机编号
	CFrontIDType FrontID;
	///用户类别
	CTypeObjectIDType UserType;
	/// 接入方式
	CTypeObjectIDType AccessType;
	///登录或登出日期
	CDateType ActionDate;
	///登录或登出时间
	CTimeType ActionTime;
	///登录或登出标记
	CValueTypeType ActionFlag;
	///数据中心名
	CTypeObjectIDType DataCenter;
	
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

typedef const CWriteableSysTradeUserLoginInfo CSysTradeUserLoginInfo;

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoActionTrigger是操作交易系统登录信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoActionTrigger
{
public:
	///构造方法
	CSysTradeUserLoginInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysTradeUserLoginInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysTradeUserLoginInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysTradeUserLoginInfo	要加入的SysTradeUserLoginInfo
	virtual void beforeAdd(CWriteableSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysTradeUserLoginInfo	已经加入的SysTradeUserLoginInfo
	virtual void afterAdd(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysTradeUserLoginInfo	被刷新的CSysTradeUserLoginInfo
	///@param	pNewSysTradeUserLoginInfo	新的值
	virtual void beforeUpdate(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo, CWriteableSysTradeUserLoginInfo *pNewSysTradeUserLoginInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysTradeUserLoginInfo	被刷新的CSysTradeUserLoginInfo
	virtual void afterUpdate(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysTradeUserLoginInfo	要删除的CSysTradeUserLoginInfo
	virtual void beforeRemove(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysTradeUserLoginInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoCommitTrigger是确认交易系统登录信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoCommitTrigger
{
public:
	///构造方法
	CSysTradeUserLoginInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysTradeUserLoginInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysTradeUserLoginInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysTradeUserLoginInfo	已经加入的SysTradeUserLoginInfo
	virtual void commitAdd(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysTradeUserLoginInfo	被刷新的CSysTradeUserLoginInfo
	///@param	poldSysTradeUserLoginInfo	原来的值
	virtual void commitUpdate(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo, CWriteableSysTradeUserLoginInfo *pOldSysTradeUserLoginInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysTradeUserLoginInfo	已经删除的CSysTradeUserLoginInfo
	virtual void commitRemove(CWriteableSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysTradeUserLoginInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoIterator是一个对交易系统登录信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoIterator
{
public:
	///构造方法
	CSysTradeUserLoginInfoIterator(void)
	{
	}

	///构造方法
	CSysTradeUserLoginInfoIterator(CSysTradeUserLoginInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysTradeUserLoginInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysTradeUserLoginInfo
	///@return	下一个满足条件CSysTradeUserLoginInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysTradeUserLoginInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysTradeUserLoginInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysTradeUserLoginInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysTradeUserLoginInfo * pSysTradeUserLoginInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysTradeUserLoginInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbWebAppInfo是一个存储Web应用信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbWebAppInfo
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
		if (! ObjectID.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! AppName.isValid())
			return 0;
		if (! Status.isValid())
			return 0;
		if (! Desc.isValid())
			return 0;
		if (! StartTime.isValid())
			return 0;
		if (! ServletNum.isValid())
			return 0;
		if (! ProcessTime.isValid())
			return 0;
		if (! RequestNum.isValid())
			return 0;
		if (! ErrorNum.isValid())
			return 0;
		if (! SessionSize.isValid())
			return 0;
		if (! TimeOut.isValid())
			return 0;
		if (! JDBCUsage.isValid())
			return 0;
		if (! JSPNum.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbWebAppInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///监控对象
	CVolumeType ObjectID;
	///监控日期
	CDateType MonDate;
	///监控时间
	CTimeType MonTime;
	///Web应用名称
	CCfgNameType AppName;
	///应用运行状态
	CTypeObjectNameType Status;
	///应用描述信息
	CTypeDescriptionType Desc;
	///应用启动时间
	CTypeCurrentTimeType StartTime;
	///应用servlet数量
	CTypeChar10Type ServletNum;
	///应用处理总时长
	CTypeCommandType ProcessTime;
	///应用累计接收请求数
	CTypeCommandType RequestNum;
	///应用累计错误数
	CTypeCommandType ErrorNum;
	///应用当前会话数
	CTypeChar10Type SessionSize;
	///会话超时时长(秒)
	CTypeChar10Type TimeOut;
	///应用JDBC连接使用率
	CTypeChar10Type JDBCUsage;
	///应用JSP文件数量
	CTypeChar10Type JSPNum;
	
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

typedef const CWriteableSysMdbWebAppInfo CSysMdbWebAppInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoActionTrigger是操作Web应用信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoActionTrigger
{
public:
	///构造方法
	CSysMdbWebAppInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbWebAppInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbWebAppInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMdbWebAppInfo	要加入的SysMdbWebAppInfo
	virtual void beforeAdd(CWriteableSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMdbWebAppInfo	已经加入的SysMdbWebAppInfo
	virtual void afterAdd(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMdbWebAppInfo	被刷新的CSysMdbWebAppInfo
	///@param	pNewSysMdbWebAppInfo	新的值
	virtual void beforeUpdate(CSysMdbWebAppInfo *pSysMdbWebAppInfo, CWriteableSysMdbWebAppInfo *pNewSysMdbWebAppInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMdbWebAppInfo	被刷新的CSysMdbWebAppInfo
	virtual void afterUpdate(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMdbWebAppInfo	要删除的CSysMdbWebAppInfo
	virtual void beforeRemove(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbWebAppInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoCommitTrigger是确认Web应用信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoCommitTrigger
{
public:
	///构造方法
	CSysMdbWebAppInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbWebAppInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbWebAppInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMdbWebAppInfo	已经加入的SysMdbWebAppInfo
	virtual void commitAdd(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysMdbWebAppInfo	被刷新的CSysMdbWebAppInfo
	///@param	poldSysMdbWebAppInfo	原来的值
	virtual void commitUpdate(CSysMdbWebAppInfo *pSysMdbWebAppInfo, CWriteableSysMdbWebAppInfo *pOldSysMdbWebAppInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMdbWebAppInfo	已经删除的CSysMdbWebAppInfo
	virtual void commitRemove(CWriteableSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbWebAppInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoIterator是一个对Web应用信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoIterator
{
public:
	///构造方法
	CSysMdbWebAppInfoIterator(void)
	{
	}

	///构造方法
	CSysMdbWebAppInfoIterator(CSysMdbWebAppInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbWebAppInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMdbWebAppInfo
	///@return	下一个满足条件CSysMdbWebAppInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbWebAppInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMdbWebAppInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbWebAppInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbWebAppInfo * pSysMdbWebAppInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMdbWebAppInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbMemPoolInfo是一个存储系统内存池信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbMemPoolInfo
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
		if (! ObjectID.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! PoolName.isValid())
			return 0;
		if (! Usage.isValid())
			return 0;
		if (! committedbytes.isValid())
			return 0;
		if (! initbytes.isValid())
			return 0;
		if (! maxbytes.isValid())
			return 0;
		if (! usedbytes.isValid())
			return 0;
		if (! Type.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbMemPoolInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///监控对象
	CVolumeType ObjectID;
	///监控日期
	CDateType MonDate;
	///监控时间
	CTimeType MonTime;
	///系统属性名
	CCfgNameType PoolName;
	///系统属性名
	CTypeChar10Type Usage;
	///系统属性名
	CTypeCommandType committedbytes;
	///系统属性名
	CTypeCommandType initbytes;
	///系统属性名
	CTypeCommandType maxbytes;
	///系统属性名
	CTypeCommandType usedbytes;
	///系统属性名
	CTypeChar10Type Type;
	
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

typedef const CWriteableSysMdbMemPoolInfo CSysMdbMemPoolInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoActionTrigger是操作系统内存池信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoActionTrigger
{
public:
	///构造方法
	CSysMdbMemPoolInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbMemPoolInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbMemPoolInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMdbMemPoolInfo	要加入的SysMdbMemPoolInfo
	virtual void beforeAdd(CWriteableSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMdbMemPoolInfo	已经加入的SysMdbMemPoolInfo
	virtual void afterAdd(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMdbMemPoolInfo	被刷新的CSysMdbMemPoolInfo
	///@param	pNewSysMdbMemPoolInfo	新的值
	virtual void beforeUpdate(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo, CWriteableSysMdbMemPoolInfo *pNewSysMdbMemPoolInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMdbMemPoolInfo	被刷新的CSysMdbMemPoolInfo
	virtual void afterUpdate(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMdbMemPoolInfo	要删除的CSysMdbMemPoolInfo
	virtual void beforeRemove(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbMemPoolInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoCommitTrigger是确认系统内存池信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoCommitTrigger
{
public:
	///构造方法
	CSysMdbMemPoolInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbMemPoolInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbMemPoolInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMdbMemPoolInfo	已经加入的SysMdbMemPoolInfo
	virtual void commitAdd(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysMdbMemPoolInfo	被刷新的CSysMdbMemPoolInfo
	///@param	poldSysMdbMemPoolInfo	原来的值
	virtual void commitUpdate(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo, CWriteableSysMdbMemPoolInfo *pOldSysMdbMemPoolInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMdbMemPoolInfo	已经删除的CSysMdbMemPoolInfo
	virtual void commitRemove(CWriteableSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbMemPoolInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoIterator是一个对系统内存池信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoIterator
{
public:
	///构造方法
	CSysMdbMemPoolInfoIterator(void)
	{
	}

	///构造方法
	CSysMdbMemPoolInfoIterator(CSysMdbMemPoolInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbMemPoolInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMdbMemPoolInfo
	///@return	下一个满足条件CSysMdbMemPoolInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbMemPoolInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMdbMemPoolInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbMemPoolInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbMemPoolInfo * pSysMdbMemPoolInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMdbMemPoolInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbConnectorInfo是一个存储连接器信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbConnectorInfo
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
		if (! ObjectID.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! Name.isValid())
			return 0;
		if (! ThreadsCount.isValid())
			return 0;
		if (! BusyThreadsCount.isValid())
			return 0;
		if (! MaxThreads.isValid())
			return 0;
		if (! MaxSpareThreads.isValid())
			return 0;
		if (! MinSpareThreads.isValid())
			return 0;
		if (! MaxTime.isValid())
			return 0;
		if (! MaxProcTime.isValid())
			return 0;
		if (! RequestCount.isValid())
			return 0;
		if (! ErrorCount.isValid())
			return 0;
		if (! BytesReceived.isValid())
			return 0;
		if (! BytesSent.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbConnectorInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///监控对象
	CVolumeType ObjectID;
	///监控日期
	CDateType MonDate;
	///监控时间
	CTimeType MonTime;
	///连接器名称
	CTypeObjectNameType Name;
	///当前处理线程数
	CTypeChar10Type ThreadsCount;
	///当前繁忙线程数
	CTypeChar10Type BusyThreadsCount;
	///最大线程数
	CTypeChar10Type MaxThreads;
	///最大空闲线程数
	CTypeChar10Type MaxSpareThreads;
	///最小空闲线程数
	CTypeChar10Type MinSpareThreads;
	///最长连接时间
	CTypeCommandType MaxTime;
	///最长处理时间
	CTypeCommandType MaxProcTime;
	///累计接收请求数
	CTypeCommandType RequestCount;
	///累计错误数
	CTypeCommandType ErrorCount;
	///累计接收字节数
	CTypeChar10Type BytesReceived;
	///累计发送字节数
	CTypeChar10Type BytesSent;
	
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

typedef const CWriteableSysMdbConnectorInfo CSysMdbConnectorInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoActionTrigger是操作连接器信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoActionTrigger
{
public:
	///构造方法
	CSysMdbConnectorInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbConnectorInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbConnectorInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMdbConnectorInfo	要加入的SysMdbConnectorInfo
	virtual void beforeAdd(CWriteableSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMdbConnectorInfo	已经加入的SysMdbConnectorInfo
	virtual void afterAdd(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMdbConnectorInfo	被刷新的CSysMdbConnectorInfo
	///@param	pNewSysMdbConnectorInfo	新的值
	virtual void beforeUpdate(CSysMdbConnectorInfo *pSysMdbConnectorInfo, CWriteableSysMdbConnectorInfo *pNewSysMdbConnectorInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMdbConnectorInfo	被刷新的CSysMdbConnectorInfo
	virtual void afterUpdate(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMdbConnectorInfo	要删除的CSysMdbConnectorInfo
	virtual void beforeRemove(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbConnectorInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoCommitTrigger是确认连接器信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoCommitTrigger
{
public:
	///构造方法
	CSysMdbConnectorInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbConnectorInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbConnectorInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMdbConnectorInfo	已经加入的SysMdbConnectorInfo
	virtual void commitAdd(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysMdbConnectorInfo	被刷新的CSysMdbConnectorInfo
	///@param	poldSysMdbConnectorInfo	原来的值
	virtual void commitUpdate(CSysMdbConnectorInfo *pSysMdbConnectorInfo, CWriteableSysMdbConnectorInfo *pOldSysMdbConnectorInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMdbConnectorInfo	已经删除的CSysMdbConnectorInfo
	virtual void commitRemove(CWriteableSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbConnectorInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoIterator是一个对连接器信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoIterator
{
public:
	///构造方法
	CSysMdbConnectorInfoIterator(void)
	{
	}

	///构造方法
	CSysMdbConnectorInfoIterator(CSysMdbConnectorInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbConnectorInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMdbConnectorInfo
	///@return	下一个满足条件CSysMdbConnectorInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbConnectorInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMdbConnectorInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbConnectorInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbConnectorInfo * pSysMdbConnectorInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMdbConnectorInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbDBQuery是一个存储数据库查询应答的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbDBQuery
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
		if (! SubcriberID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! AttrType.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! DBQueryResult.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbDBQuery *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///订阅对象ID
	CVolumeType SubcriberID;
	///数据库实例对象ID
	CVolumeType ObjectID;
	///存储过程名
	CVolumeType AttrType;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///数据库查询结果
	CDBQueryResultType DBQueryResult;
	
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

typedef const CWriteableSysMdbDBQuery CSysMdbDBQuery;

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryActionTrigger是操作数据库查询应答时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryActionTrigger
{
public:
	///构造方法
	CSysMdbDBQueryActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbDBQueryActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbDBQueryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMdbDBQuery	要加入的SysMdbDBQuery
	virtual void beforeAdd(CWriteableSysMdbDBQuery *pSysMdbDBQuery)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMdbDBQuery	已经加入的SysMdbDBQuery
	virtual void afterAdd(CSysMdbDBQuery *pSysMdbDBQuery)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMdbDBQuery	被刷新的CSysMdbDBQuery
	///@param	pNewSysMdbDBQuery	新的值
	virtual void beforeUpdate(CSysMdbDBQuery *pSysMdbDBQuery, CWriteableSysMdbDBQuery *pNewSysMdbDBQuery)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMdbDBQuery	被刷新的CSysMdbDBQuery
	virtual void afterUpdate(CSysMdbDBQuery *pSysMdbDBQuery)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMdbDBQuery	要删除的CSysMdbDBQuery
	virtual void beforeRemove(CSysMdbDBQuery *pSysMdbDBQuery)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbDBQueryFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryCommitTrigger是确认数据库查询应答时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryCommitTrigger
{
public:
	///构造方法
	CSysMdbDBQueryCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbDBQueryCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbDBQueryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMdbDBQuery	已经加入的SysMdbDBQuery
	virtual void commitAdd(CSysMdbDBQuery *pSysMdbDBQuery)
	{
		return;
	}

	///更新后触发
	///@param	pSysMdbDBQuery	被刷新的CSysMdbDBQuery
	///@param	poldSysMdbDBQuery	原来的值
	virtual void commitUpdate(CSysMdbDBQuery *pSysMdbDBQuery, CWriteableSysMdbDBQuery *pOldSysMdbDBQuery)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMdbDBQuery	已经删除的CSysMdbDBQuery
	virtual void commitRemove(CWriteableSysMdbDBQuery *pSysMdbDBQuery)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbDBQueryFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryIterator是一个对数据库查询应答的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryIterator
{
public:
	///构造方法
	CSysMdbDBQueryIterator(void)
	{
	}

	///构造方法
	CSysMdbDBQueryIterator(CSysMdbDBQueryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbDBQueryIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMdbDBQuery
	///@return	下一个满足条件CSysMdbDBQuery，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbDBQuery *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMdbDBQueryFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbDBQuery 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbDBQuery * pSysMdbDBQuery,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMdbDBQueryFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetArea是一个存储网络大区划分的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetArea
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetArea *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///区域中文名
	CTypeObjectIDType CName;
	///区域英文名
	CTypeObjectIDType EName;
	
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

typedef const CWriteableSysNetArea CSysNetArea;

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaActionTrigger是操作网络大区划分时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaActionTrigger
{
public:
	///构造方法
	CSysNetAreaActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetAreaActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetArea	要加入的SysNetArea
	virtual void beforeAdd(CWriteableSysNetArea *pSysNetArea)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetArea	已经加入的SysNetArea
	virtual void afterAdd(CSysNetArea *pSysNetArea)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetArea	被刷新的CSysNetArea
	///@param	pNewSysNetArea	新的值
	virtual void beforeUpdate(CSysNetArea *pSysNetArea, CWriteableSysNetArea *pNewSysNetArea)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetArea	被刷新的CSysNetArea
	virtual void afterUpdate(CSysNetArea *pSysNetArea)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetArea	要删除的CSysNetArea
	virtual void beforeRemove(CSysNetArea *pSysNetArea)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetAreaFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaCommitTrigger是确认网络大区划分时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaCommitTrigger
{
public:
	///构造方法
	CSysNetAreaCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetAreaCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetArea	已经加入的SysNetArea
	virtual void commitAdd(CSysNetArea *pSysNetArea)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetArea	被刷新的CSysNetArea
	///@param	poldSysNetArea	原来的值
	virtual void commitUpdate(CSysNetArea *pSysNetArea, CWriteableSysNetArea *pOldSysNetArea)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetArea	已经删除的CSysNetArea
	virtual void commitRemove(CWriteableSysNetArea *pSysNetArea)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetAreaFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaIterator是一个对网络大区划分的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaIterator
{
public:
	///构造方法
	CSysNetAreaIterator(void)
	{
	}

	///构造方法
	CSysNetAreaIterator(CSysNetAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetAreaIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetArea
	///@return	下一个满足条件CSysNetArea，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetArea *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetAreaFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetArea 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetArea * pSysNetArea,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetAreaFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetSubArea是一个存储网络子区的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetSubArea
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
		if (! ID.isValid())
			return 0;
		if (! SysNetAreaID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetSubArea *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///SysNetArea
	CVolumeType SysNetAreaID;
	///区域中文名
	CTypeObjectIDType CName;
	///区域英文名
	CTypeObjectIDType EName;
	
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

typedef const CWriteableSysNetSubArea CSysNetSubArea;

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaActionTrigger是操作网络子区时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaActionTrigger
{
public:
	///构造方法
	CSysNetSubAreaActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetSubAreaActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetSubAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetSubArea	要加入的SysNetSubArea
	virtual void beforeAdd(CWriteableSysNetSubArea *pSysNetSubArea)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetSubArea	已经加入的SysNetSubArea
	virtual void afterAdd(CSysNetSubArea *pSysNetSubArea)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetSubArea	被刷新的CSysNetSubArea
	///@param	pNewSysNetSubArea	新的值
	virtual void beforeUpdate(CSysNetSubArea *pSysNetSubArea, CWriteableSysNetSubArea *pNewSysNetSubArea)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetSubArea	被刷新的CSysNetSubArea
	virtual void afterUpdate(CSysNetSubArea *pSysNetSubArea)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetSubArea	要删除的CSysNetSubArea
	virtual void beforeRemove(CSysNetSubArea *pSysNetSubArea)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetSubAreaFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaCommitTrigger是确认网络子区时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaCommitTrigger
{
public:
	///构造方法
	CSysNetSubAreaCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetSubAreaCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetSubAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetSubArea	已经加入的SysNetSubArea
	virtual void commitAdd(CSysNetSubArea *pSysNetSubArea)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetSubArea	被刷新的CSysNetSubArea
	///@param	poldSysNetSubArea	原来的值
	virtual void commitUpdate(CSysNetSubArea *pSysNetSubArea, CWriteableSysNetSubArea *pOldSysNetSubArea)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetSubArea	已经删除的CSysNetSubArea
	virtual void commitRemove(CWriteableSysNetSubArea *pSysNetSubArea)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetSubAreaFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIterator是一个对网络子区的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIterator
{
public:
	///构造方法
	CSysNetSubAreaIterator(void)
	{
	}

	///构造方法
	CSysNetSubAreaIterator(CSysNetSubAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetSubAreaIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetSubArea
	///@return	下一个满足条件CSysNetSubArea，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetSubArea *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetSubAreaFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetSubArea 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetSubArea * pSysNetSubArea,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetSubAreaFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetSubAreaIP是一个存储网络子区IP的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetSubAreaIP
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
		if (! ID.isValid())
			return 0;
		if (! SysNetSubAreaID.isValid())
			return 0;
		if (! IP.isValid())
			return 0;
		if (! Mask.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetSubAreaIP *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///SysNetSubAreaID
	CVolumeType SysNetSubAreaID;
	///ip地址
	CIPAddressType IP;
	///掩码
	CIPAddressType Mask;
	
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

typedef const CWriteableSysNetSubAreaIP CSysNetSubAreaIP;

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPActionTrigger是操作网络子区IP时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPActionTrigger
{
public:
	///构造方法
	CSysNetSubAreaIPActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetSubAreaIPActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetSubAreaIPFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetSubAreaIP	要加入的SysNetSubAreaIP
	virtual void beforeAdd(CWriteableSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetSubAreaIP	已经加入的SysNetSubAreaIP
	virtual void afterAdd(CSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetSubAreaIP	被刷新的CSysNetSubAreaIP
	///@param	pNewSysNetSubAreaIP	新的值
	virtual void beforeUpdate(CSysNetSubAreaIP *pSysNetSubAreaIP, CWriteableSysNetSubAreaIP *pNewSysNetSubAreaIP)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetSubAreaIP	被刷新的CSysNetSubAreaIP
	virtual void afterUpdate(CSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetSubAreaIP	要删除的CSysNetSubAreaIP
	virtual void beforeRemove(CSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetSubAreaIPFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPCommitTrigger是确认网络子区IP时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPCommitTrigger
{
public:
	///构造方法
	CSysNetSubAreaIPCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetSubAreaIPCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetSubAreaIPFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetSubAreaIP	已经加入的SysNetSubAreaIP
	virtual void commitAdd(CSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetSubAreaIP	被刷新的CSysNetSubAreaIP
	///@param	poldSysNetSubAreaIP	原来的值
	virtual void commitUpdate(CSysNetSubAreaIP *pSysNetSubAreaIP, CWriteableSysNetSubAreaIP *pOldSysNetSubAreaIP)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetSubAreaIP	已经删除的CSysNetSubAreaIP
	virtual void commitRemove(CWriteableSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetSubAreaIPFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPIterator是一个对网络子区IP的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPIterator
{
public:
	///构造方法
	CSysNetSubAreaIPIterator(void)
	{
	}

	///构造方法
	CSysNetSubAreaIPIterator(CSysNetSubAreaIPFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetSubAreaIPIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetSubAreaIP
	///@return	下一个满足条件CSysNetSubAreaIP，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetSubAreaIP *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetSubAreaIPFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetSubAreaIP 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetSubAreaIP * pSysNetSubAreaIP,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetSubAreaIPFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetFuncArea是一个存储职能区的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetFuncArea
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
		if (! ID.isValid())
			return 0;
		if (! SysNetSubAreaID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetFuncArea *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///SysNetSubAreaID
	CVolumeType SysNetSubAreaID;
	///区域中文名
	CTypeObjectIDType CName;
	///区域英文名
	CTypeObjectIDType EName;
	
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

typedef const CWriteableSysNetFuncArea CSysNetFuncArea;

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaActionTrigger是操作职能区时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaActionTrigger
{
public:
	///构造方法
	CSysNetFuncAreaActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetFuncAreaActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetFuncAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetFuncArea	要加入的SysNetFuncArea
	virtual void beforeAdd(CWriteableSysNetFuncArea *pSysNetFuncArea)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetFuncArea	已经加入的SysNetFuncArea
	virtual void afterAdd(CSysNetFuncArea *pSysNetFuncArea)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetFuncArea	被刷新的CSysNetFuncArea
	///@param	pNewSysNetFuncArea	新的值
	virtual void beforeUpdate(CSysNetFuncArea *pSysNetFuncArea, CWriteableSysNetFuncArea *pNewSysNetFuncArea)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetFuncArea	被刷新的CSysNetFuncArea
	virtual void afterUpdate(CSysNetFuncArea *pSysNetFuncArea)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetFuncArea	要删除的CSysNetFuncArea
	virtual void beforeRemove(CSysNetFuncArea *pSysNetFuncArea)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetFuncAreaFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaCommitTrigger是确认职能区时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaCommitTrigger
{
public:
	///构造方法
	CSysNetFuncAreaCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetFuncAreaCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetFuncAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetFuncArea	已经加入的SysNetFuncArea
	virtual void commitAdd(CSysNetFuncArea *pSysNetFuncArea)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetFuncArea	被刷新的CSysNetFuncArea
	///@param	poldSysNetFuncArea	原来的值
	virtual void commitUpdate(CSysNetFuncArea *pSysNetFuncArea, CWriteableSysNetFuncArea *pOldSysNetFuncArea)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetFuncArea	已经删除的CSysNetFuncArea
	virtual void commitRemove(CWriteableSysNetFuncArea *pSysNetFuncArea)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetFuncAreaFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaIterator是一个对职能区的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaIterator
{
public:
	///构造方法
	CSysNetFuncAreaIterator(void)
	{
	}

	///构造方法
	CSysNetFuncAreaIterator(CSysNetFuncAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetFuncAreaIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetFuncArea
	///@return	下一个满足条件CSysNetFuncArea，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetFuncArea *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetFuncAreaFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetFuncArea 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetFuncArea * pSysNetFuncArea,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetFuncAreaFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetDevice是一个存储网络设备的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetDevice
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
		if (! ID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! MonitorType_ID.isValid())
			return 0;
		if (! SysNetSubAreaID.isValid())
			return 0;
		if (! CATEGORY_ID.isValid())
			return 0;
		if (! FuctionArea.isValid())
			return 0;
		if (! IPADDR.isValid())
			return 0;
		if (! IPDECODE.isValid())
			return 0;
		if (! NAME.isValid())
			return 0;
		if (! PORTNUMBER.isValid())
			return 0;
		if (! CONFIGFILE.isValid())
			return 0;
		if (! RCOMMUNITY.isValid())
			return 0;
		if (! SNMPVERSION.isValid())
			return 0;
		if (! RAMSIZE.isValid())
			return 0;
		if (! FLASHSIZE.isValid())
			return 0;
		if (! NVRAMSIZE.isValid())
			return 0;
		if (! CABINET_ID.isValid())
			return 0;
		if (! ROOM_ID.isValid())
			return 0;
		if (! IOSVERSION_ID.isValid())
			return 0;
		if (! DESCRIPTION.isValid())
			return 0;
		if (! USERNAME.isValid())
			return 0;
		if (! PASSWD.isValid())
			return 0;
		if (! ENPASSWD.isValid())
			return 0;
		if (! MANUFACTORY_ID.isValid())
			return 0;
		if (! CFGSAVETYPE.isValid())
			return 0;
		if (! DEVICETYPE.isValid())
			return 0;
		if (! SENDSMS.isValid())
			return 0;
		if (! ISSNMP.isValid())
			return 0;
		if (! SLOTNUM.isValid())
			return 0;
		if (! ISPING.isValid())
			return 0;
		if (! IFNUM.isValid())
			return 0;
		if (! APPLICATION_ID.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetDevice *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///监控对象
	CNetObjectIDType ObjectID;
	///监控对象类型
	CVolumeType MonitorType_ID;
	///SysNetSubAreaID
	CVolumeType SysNetSubAreaID;
	///分类ID  
	CVolumeType CATEGORY_ID;
	///人为划分的职能区域  
	CTypeObjectIDType FuctionArea;
	///IP地址  
	CIPAddressType IPADDR;
	///IP码    
	CVolumeType IPDECODE;
	///设备名称 
	CNetObjectIDType NAME;
	///             
	CVolumeType PORTNUMBER;
	///          
	CTypeObjectIDType CONFIGFILE;
	///共同体名  
	CTypeObjectIDType RCOMMUNITY;
	///snmp版本     
	CVolumeType SNMPVERSION;
	///ramsize(B)   
	CVolumeType RAMSIZE;
	///falshsize(B) 
	CVolumeType FLASHSIZE;
	///nvramsize(B) 
	CVolumeType NVRAMSIZE;
	///所属机柜
	CVolumeType CABINET_ID;
	CVolumeType ROOM_ID;
	///软件版本
	CVolumeType IOSVERSION_ID;
	///系统描述
	CNetAttrTypeType DESCRIPTION;
	///登录用户名
	CTypeObjectIDType USERNAME;
	///登录密码
	CNetAttrTypeType PASSWD;
	///enable密码
	CNetAttrTypeType ENPASSWD;
	///厂商类型
	CVolumeType MANUFACTORY_ID;
	///配置备份协议
	CVolumeType CFGSAVETYPE;
	///设备型号
	CNetObjectIDType DEVICETYPE;
	///是否短信告警
	CVolumeType SENDSMS;
	///是否自动snmp探测
	CVolumeType ISSNMP;
	///槽位数
	CVolumeType SLOTNUM;
	///是否自动ping
	CVolumeType ISPING;
	///端口数量
	CVolumeType IFNUM;
	///巡检分区
	CVolumeType APPLICATION_ID;
	
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

typedef const CWriteableSysNetDevice CSysNetDevice;

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceActionTrigger是操作网络设备时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceActionTrigger
{
public:
	///构造方法
	CSysNetDeviceActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetDeviceActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetDeviceFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetDevice	要加入的SysNetDevice
	virtual void beforeAdd(CWriteableSysNetDevice *pSysNetDevice)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetDevice	已经加入的SysNetDevice
	virtual void afterAdd(CSysNetDevice *pSysNetDevice)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetDevice	被刷新的CSysNetDevice
	///@param	pNewSysNetDevice	新的值
	virtual void beforeUpdate(CSysNetDevice *pSysNetDevice, CWriteableSysNetDevice *pNewSysNetDevice)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetDevice	被刷新的CSysNetDevice
	virtual void afterUpdate(CSysNetDevice *pSysNetDevice)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetDevice	要删除的CSysNetDevice
	virtual void beforeRemove(CSysNetDevice *pSysNetDevice)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetDeviceFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCommitTrigger是确认网络设备时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCommitTrigger
{
public:
	///构造方法
	CSysNetDeviceCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetDeviceCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetDeviceFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetDevice	已经加入的SysNetDevice
	virtual void commitAdd(CSysNetDevice *pSysNetDevice)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetDevice	被刷新的CSysNetDevice
	///@param	poldSysNetDevice	原来的值
	virtual void commitUpdate(CSysNetDevice *pSysNetDevice, CWriteableSysNetDevice *pOldSysNetDevice)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetDevice	已经删除的CSysNetDevice
	virtual void commitRemove(CWriteableSysNetDevice *pSysNetDevice)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetDeviceFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceIterator是一个对网络设备的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceIterator
{
public:
	///构造方法
	CSysNetDeviceIterator(void)
	{
	}

	///构造方法
	CSysNetDeviceIterator(CSysNetDeviceFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDeviceIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetDevice
	///@return	下一个满足条件CSysNetDevice，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDevice *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetDeviceFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDevice 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDevice * pSysNetDevice,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetDeviceFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetDeviceLinked是一个存储网络设备连接关系的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetDeviceLinked
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
		if (! ID.isValid())
			return 0;
		if (! NetDeviceID.isValid())
			return 0;
		if (! NetPortID.isValid())
			return 0;
		if (! NetObjectID.isValid())
			return 0;
		if (! NetPortType.isValid())
			return 0;
		if (! LinkNetDeviceID.isValid())
			return 0;
		if (! LinkNetPortID.isValid())
			return 0;
		if (! LinkNetObjectID.isValid())
			return 0;
		if (! LinkNetPortType.isValid())
			return 0;
		if (! LinkSource.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetDeviceLinked *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///设备ID
	CVolumeType NetDeviceID;
	///设备端口ID
	CVolumeType NetPortID;
	///监控对象
	CNetObjectIDType NetObjectID;
	///监控对象端口类型
	CNetDevicePortTypeType NetPortType;
	///连接设备ID
	CVolumeType LinkNetDeviceID;
	///连接设备端口ID
	CVolumeType LinkNetPortID;
	///连接对象
	CNetObjectIDType LinkNetObjectID;
	///连接对象端口类型
	CNetDevicePortTypeType LinkNetPortType;
	///链接来源
	CVolumeType LinkSource;
	
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

typedef const CWriteableSysNetDeviceLinked CSysNetDeviceLinked;

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedActionTrigger是操作网络设备连接关系时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedActionTrigger
{
public:
	///构造方法
	CSysNetDeviceLinkedActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetDeviceLinkedActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetDeviceLinkedFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetDeviceLinked	要加入的SysNetDeviceLinked
	virtual void beforeAdd(CWriteableSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetDeviceLinked	已经加入的SysNetDeviceLinked
	virtual void afterAdd(CSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetDeviceLinked	被刷新的CSysNetDeviceLinked
	///@param	pNewSysNetDeviceLinked	新的值
	virtual void beforeUpdate(CSysNetDeviceLinked *pSysNetDeviceLinked, CWriteableSysNetDeviceLinked *pNewSysNetDeviceLinked)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetDeviceLinked	被刷新的CSysNetDeviceLinked
	virtual void afterUpdate(CSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetDeviceLinked	要删除的CSysNetDeviceLinked
	virtual void beforeRemove(CSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetDeviceLinkedFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedCommitTrigger是确认网络设备连接关系时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedCommitTrigger
{
public:
	///构造方法
	CSysNetDeviceLinkedCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetDeviceLinkedCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetDeviceLinkedFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetDeviceLinked	已经加入的SysNetDeviceLinked
	virtual void commitAdd(CSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetDeviceLinked	被刷新的CSysNetDeviceLinked
	///@param	poldSysNetDeviceLinked	原来的值
	virtual void commitUpdate(CSysNetDeviceLinked *pSysNetDeviceLinked, CWriteableSysNetDeviceLinked *pOldSysNetDeviceLinked)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetDeviceLinked	已经删除的CSysNetDeviceLinked
	virtual void commitRemove(CWriteableSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetDeviceLinkedFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedIterator是一个对网络设备连接关系的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedIterator
{
public:
	///构造方法
	CSysNetDeviceLinkedIterator(void)
	{
	}

	///构造方法
	CSysNetDeviceLinkedIterator(CSysNetDeviceLinkedFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDeviceLinkedIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetDeviceLinked
	///@return	下一个满足条件CSysNetDeviceLinked，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceLinked *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetDeviceLinkedFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDeviceLinked 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceLinked * pSysNetDeviceLinked,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetDeviceLinkedFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetOID是一个存储OID的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetOID
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
		if (! ID.isValid())
			return 0;
		if (! Manufactory.isValid())
			return 0;
		if (! DeviceType.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! OID.isValid())
			return 0;
		if (! Unit.isValid())
			return 0;
		if (! isTheTable.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetOID *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///生产商名
	CTypeObjectIDType Manufactory;
	///设备型号
	CTypeObjectIDType DeviceType;
	///OID中文名
	CTypeObjectIDType CName;
	///OID英文名
	CTypeObjectIDType EName;
	///OID
	CTypeObjectIDType OID;
	///单位
	CTypeObjectIDType Unit;
	///是否标量标志
	CVolumeType isTheTable;
	
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

typedef const CWriteableSysNetOID CSysNetOID;

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDActionTrigger是操作OID时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDActionTrigger
{
public:
	///构造方法
	CSysNetOIDActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetOIDActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetOIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetOID	要加入的SysNetOID
	virtual void beforeAdd(CWriteableSysNetOID *pSysNetOID)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetOID	已经加入的SysNetOID
	virtual void afterAdd(CSysNetOID *pSysNetOID)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetOID	被刷新的CSysNetOID
	///@param	pNewSysNetOID	新的值
	virtual void beforeUpdate(CSysNetOID *pSysNetOID, CWriteableSysNetOID *pNewSysNetOID)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetOID	被刷新的CSysNetOID
	virtual void afterUpdate(CSysNetOID *pSysNetOID)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetOID	要删除的CSysNetOID
	virtual void beforeRemove(CSysNetOID *pSysNetOID)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetOIDFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDCommitTrigger是确认OID时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDCommitTrigger
{
public:
	///构造方法
	CSysNetOIDCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetOIDCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetOIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetOID	已经加入的SysNetOID
	virtual void commitAdd(CSysNetOID *pSysNetOID)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetOID	被刷新的CSysNetOID
	///@param	poldSysNetOID	原来的值
	virtual void commitUpdate(CSysNetOID *pSysNetOID, CWriteableSysNetOID *pOldSysNetOID)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetOID	已经删除的CSysNetOID
	virtual void commitRemove(CWriteableSysNetOID *pSysNetOID)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetOIDFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDIterator是一个对OID的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDIterator
{
public:
	///构造方法
	CSysNetOIDIterator(void)
	{
	}

	///构造方法
	CSysNetOIDIterator(CSysNetOIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetOIDIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetOID
	///@return	下一个满足条件CSysNetOID，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetOID *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetOIDFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetOID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetOID * pSysNetOID,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetOIDFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetDeviceType是一个存储网络设备类型的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetDeviceType
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
		if (! ID.isValid())
			return 0;
		if (! Manufactory.isValid())
			return 0;
		if (! DeviceType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetDeviceType *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///生产商名
	CTypeObjectIDType Manufactory;
	///设备型号
	CTypeObjectIDType DeviceType;
	
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

typedef const CWriteableSysNetDeviceType CSysNetDeviceType;

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeActionTrigger是操作网络设备类型时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeActionTrigger
{
public:
	///构造方法
	CSysNetDeviceTypeActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetDeviceTypeActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetDeviceTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetDeviceType	要加入的SysNetDeviceType
	virtual void beforeAdd(CWriteableSysNetDeviceType *pSysNetDeviceType)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetDeviceType	已经加入的SysNetDeviceType
	virtual void afterAdd(CSysNetDeviceType *pSysNetDeviceType)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetDeviceType	被刷新的CSysNetDeviceType
	///@param	pNewSysNetDeviceType	新的值
	virtual void beforeUpdate(CSysNetDeviceType *pSysNetDeviceType, CWriteableSysNetDeviceType *pNewSysNetDeviceType)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetDeviceType	被刷新的CSysNetDeviceType
	virtual void afterUpdate(CSysNetDeviceType *pSysNetDeviceType)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetDeviceType	要删除的CSysNetDeviceType
	virtual void beforeRemove(CSysNetDeviceType *pSysNetDeviceType)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetDeviceTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeCommitTrigger是确认网络设备类型时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeCommitTrigger
{
public:
	///构造方法
	CSysNetDeviceTypeCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetDeviceTypeCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetDeviceTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetDeviceType	已经加入的SysNetDeviceType
	virtual void commitAdd(CSysNetDeviceType *pSysNetDeviceType)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetDeviceType	被刷新的CSysNetDeviceType
	///@param	poldSysNetDeviceType	原来的值
	virtual void commitUpdate(CSysNetDeviceType *pSysNetDeviceType, CWriteableSysNetDeviceType *pOldSysNetDeviceType)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetDeviceType	已经删除的CSysNetDeviceType
	virtual void commitRemove(CWriteableSysNetDeviceType *pSysNetDeviceType)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetDeviceTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeIterator是一个对网络设备类型的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeIterator
{
public:
	///构造方法
	CSysNetDeviceTypeIterator(void)
	{
	}

	///构造方法
	CSysNetDeviceTypeIterator(CSysNetDeviceTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDeviceTypeIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetDeviceType
	///@return	下一个满足条件CSysNetDeviceType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceType *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetDeviceTypeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDeviceType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceType * pSysNetDeviceType,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetDeviceTypeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetTimePolicy是一个存储时间策略的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetTimePolicy
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! PolicyType.isValid())
			return 0;
		if (! PolicyString.isValid())
			return 0;
		if (! TradingDay.isValid())
			return 0;
		if (! Description.isValid())
			return 0;
		if (! Operation.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetTimePolicy *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///时间策略中文名
	CTypeObjectIDType CName;
	///时间策略英文名
	CTypeObjectIDType EName;
	///策略类型
	CVolumeType PolicyType;
	///策略项配置串
	CPolicyStringTypeType PolicyString;
	///交易日限制
	CVolumeType TradingDay;
	///策略项描述
	CNetAttrTypeType Description;
	///操作类型
	CVolumeType Operation;
	
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

typedef const CWriteableSysNetTimePolicy CSysNetTimePolicy;

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyActionTrigger是操作时间策略时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyActionTrigger
{
public:
	///构造方法
	CSysNetTimePolicyActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetTimePolicyActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetTimePolicyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetTimePolicy	要加入的SysNetTimePolicy
	virtual void beforeAdd(CWriteableSysNetTimePolicy *pSysNetTimePolicy)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetTimePolicy	已经加入的SysNetTimePolicy
	virtual void afterAdd(CSysNetTimePolicy *pSysNetTimePolicy)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetTimePolicy	被刷新的CSysNetTimePolicy
	///@param	pNewSysNetTimePolicy	新的值
	virtual void beforeUpdate(CSysNetTimePolicy *pSysNetTimePolicy, CWriteableSysNetTimePolicy *pNewSysNetTimePolicy)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetTimePolicy	被刷新的CSysNetTimePolicy
	virtual void afterUpdate(CSysNetTimePolicy *pSysNetTimePolicy)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetTimePolicy	要删除的CSysNetTimePolicy
	virtual void beforeRemove(CSysNetTimePolicy *pSysNetTimePolicy)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetTimePolicyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyCommitTrigger是确认时间策略时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyCommitTrigger
{
public:
	///构造方法
	CSysNetTimePolicyCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetTimePolicyCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetTimePolicyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetTimePolicy	已经加入的SysNetTimePolicy
	virtual void commitAdd(CSysNetTimePolicy *pSysNetTimePolicy)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetTimePolicy	被刷新的CSysNetTimePolicy
	///@param	poldSysNetTimePolicy	原来的值
	virtual void commitUpdate(CSysNetTimePolicy *pSysNetTimePolicy, CWriteableSysNetTimePolicy *pOldSysNetTimePolicy)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetTimePolicy	已经删除的CSysNetTimePolicy
	virtual void commitRemove(CWriteableSysNetTimePolicy *pSysNetTimePolicy)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetTimePolicyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyIterator是一个对时间策略的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyIterator
{
public:
	///构造方法
	CSysNetTimePolicyIterator(void)
	{
	}

	///构造方法
	CSysNetTimePolicyIterator(CSysNetTimePolicyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetTimePolicyIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetTimePolicy
	///@return	下一个满足条件CSysNetTimePolicy，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetTimePolicy *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetTimePolicyFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetTimePolicy 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetTimePolicy * pSysNetTimePolicy,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetTimePolicyFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetGatherTask是一个存储采集任务的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetGatherTask
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
		if (! ID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! AttrType.isValid())
			return 0;
		if (! PolicyTypeID.isValid())
			return 0;
		if (! DataType.isValid())
			return 0;
		if (! TypeFlag.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetGatherTask *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///网络监控对象ID
	CNetObjectIDType ObjectID;
	///网络监控指标类型
	CNetAttrTypeType AttrType;
	///时间策略ID
	CVolumeType PolicyTypeID;
	///返回类型
	CVolumeType DataType;
	///类型标识
	CVolumeType TypeFlag;
	
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

typedef const CWriteableSysNetGatherTask CSysNetGatherTask;

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskActionTrigger是操作采集任务时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskActionTrigger
{
public:
	///构造方法
	CSysNetGatherTaskActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetGatherTaskActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetGatherTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetGatherTask	要加入的SysNetGatherTask
	virtual void beforeAdd(CWriteableSysNetGatherTask *pSysNetGatherTask)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetGatherTask	已经加入的SysNetGatherTask
	virtual void afterAdd(CSysNetGatherTask *pSysNetGatherTask)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetGatherTask	被刷新的CSysNetGatherTask
	///@param	pNewSysNetGatherTask	新的值
	virtual void beforeUpdate(CSysNetGatherTask *pSysNetGatherTask, CWriteableSysNetGatherTask *pNewSysNetGatherTask)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetGatherTask	被刷新的CSysNetGatherTask
	virtual void afterUpdate(CSysNetGatherTask *pSysNetGatherTask)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetGatherTask	要删除的CSysNetGatherTask
	virtual void beforeRemove(CSysNetGatherTask *pSysNetGatherTask)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetGatherTaskFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskCommitTrigger是确认采集任务时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskCommitTrigger
{
public:
	///构造方法
	CSysNetGatherTaskCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetGatherTaskCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetGatherTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetGatherTask	已经加入的SysNetGatherTask
	virtual void commitAdd(CSysNetGatherTask *pSysNetGatherTask)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetGatherTask	被刷新的CSysNetGatherTask
	///@param	poldSysNetGatherTask	原来的值
	virtual void commitUpdate(CSysNetGatherTask *pSysNetGatherTask, CWriteableSysNetGatherTask *pOldSysNetGatherTask)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetGatherTask	已经删除的CSysNetGatherTask
	virtual void commitRemove(CWriteableSysNetGatherTask *pSysNetGatherTask)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetGatherTaskFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskIterator是一个对采集任务的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskIterator
{
public:
	///构造方法
	CSysNetGatherTaskIterator(void)
	{
	}

	///构造方法
	CSysNetGatherTaskIterator(CSysNetGatherTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetGatherTaskIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetGatherTask
	///@return	下一个满足条件CSysNetGatherTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetGatherTask *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetGatherTaskFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetGatherTask 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetGatherTask * pSysNetGatherTask,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetGatherTaskFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetDeviceCategory是一个存储常用设备类别的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetDeviceCategory
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetDeviceCategory *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///类别中文名
	CTypeObjectIDType CName;
	///类别英文名
	CTypeObjectIDType EName;
	
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

typedef const CWriteableSysNetDeviceCategory CSysNetDeviceCategory;

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryActionTrigger是操作常用设备类别时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryActionTrigger
{
public:
	///构造方法
	CSysNetDeviceCategoryActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetDeviceCategoryActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetDeviceCategoryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetDeviceCategory	要加入的SysNetDeviceCategory
	virtual void beforeAdd(CWriteableSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetDeviceCategory	已经加入的SysNetDeviceCategory
	virtual void afterAdd(CSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetDeviceCategory	被刷新的CSysNetDeviceCategory
	///@param	pNewSysNetDeviceCategory	新的值
	virtual void beforeUpdate(CSysNetDeviceCategory *pSysNetDeviceCategory, CWriteableSysNetDeviceCategory *pNewSysNetDeviceCategory)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetDeviceCategory	被刷新的CSysNetDeviceCategory
	virtual void afterUpdate(CSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetDeviceCategory	要删除的CSysNetDeviceCategory
	virtual void beforeRemove(CSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetDeviceCategoryFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryCommitTrigger是确认常用设备类别时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryCommitTrigger
{
public:
	///构造方法
	CSysNetDeviceCategoryCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetDeviceCategoryCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetDeviceCategoryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetDeviceCategory	已经加入的SysNetDeviceCategory
	virtual void commitAdd(CSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetDeviceCategory	被刷新的CSysNetDeviceCategory
	///@param	poldSysNetDeviceCategory	原来的值
	virtual void commitUpdate(CSysNetDeviceCategory *pSysNetDeviceCategory, CWriteableSysNetDeviceCategory *pOldSysNetDeviceCategory)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetDeviceCategory	已经删除的CSysNetDeviceCategory
	virtual void commitRemove(CWriteableSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetDeviceCategoryFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryIterator是一个对常用设备类别的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryIterator
{
public:
	///构造方法
	CSysNetDeviceCategoryIterator(void)
	{
	}

	///构造方法
	CSysNetDeviceCategoryIterator(CSysNetDeviceCategoryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDeviceCategoryIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetDeviceCategory
	///@return	下一个满足条件CSysNetDeviceCategory，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceCategory *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetDeviceCategoryFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDeviceCategory 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceCategory * pSysNetDeviceCategory,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetDeviceCategoryFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetManufactory是一个存储设备厂商的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetManufactory
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetManufactory *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///厂商中文名
	CTypeObjectIDType CName;
	///厂商英文名
	CTypeObjectIDType EName;
	
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

typedef const CWriteableSysNetManufactory CSysNetManufactory;

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryActionTrigger是操作设备厂商时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryActionTrigger
{
public:
	///构造方法
	CSysNetManufactoryActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetManufactoryActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetManufactoryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetManufactory	要加入的SysNetManufactory
	virtual void beforeAdd(CWriteableSysNetManufactory *pSysNetManufactory)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetManufactory	已经加入的SysNetManufactory
	virtual void afterAdd(CSysNetManufactory *pSysNetManufactory)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetManufactory	被刷新的CSysNetManufactory
	///@param	pNewSysNetManufactory	新的值
	virtual void beforeUpdate(CSysNetManufactory *pSysNetManufactory, CWriteableSysNetManufactory *pNewSysNetManufactory)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetManufactory	被刷新的CSysNetManufactory
	virtual void afterUpdate(CSysNetManufactory *pSysNetManufactory)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetManufactory	要删除的CSysNetManufactory
	virtual void beforeRemove(CSysNetManufactory *pSysNetManufactory)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetManufactoryFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryCommitTrigger是确认设备厂商时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryCommitTrigger
{
public:
	///构造方法
	CSysNetManufactoryCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetManufactoryCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetManufactoryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetManufactory	已经加入的SysNetManufactory
	virtual void commitAdd(CSysNetManufactory *pSysNetManufactory)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetManufactory	被刷新的CSysNetManufactory
	///@param	poldSysNetManufactory	原来的值
	virtual void commitUpdate(CSysNetManufactory *pSysNetManufactory, CWriteableSysNetManufactory *pOldSysNetManufactory)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetManufactory	已经删除的CSysNetManufactory
	virtual void commitRemove(CWriteableSysNetManufactory *pSysNetManufactory)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetManufactoryFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryIterator是一个对设备厂商的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryIterator
{
public:
	///构造方法
	CSysNetManufactoryIterator(void)
	{
	}

	///构造方法
	CSysNetManufactoryIterator(CSysNetManufactoryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetManufactoryIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetManufactory
	///@return	下一个满足条件CSysNetManufactory，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetManufactory *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetManufactoryFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetManufactory 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetManufactory * pSysNetManufactory,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetManufactoryFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetCommunity是一个存储设备共同体的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetCommunity
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
		if (! ID.isValid())
			return 0;
		if (! IPADDR.isValid())
			return 0;
		if (! COMMUNITY.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetCommunity *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///IP地址
	CIPAddressType IPADDR;
	///共同体名
	CTypeObjectIDType COMMUNITY;
	
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

typedef const CWriteableSysNetCommunity CSysNetCommunity;

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityActionTrigger是操作设备共同体时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityActionTrigger
{
public:
	///构造方法
	CSysNetCommunityActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetCommunityActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetCommunityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetCommunity	要加入的SysNetCommunity
	virtual void beforeAdd(CWriteableSysNetCommunity *pSysNetCommunity)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetCommunity	已经加入的SysNetCommunity
	virtual void afterAdd(CSysNetCommunity *pSysNetCommunity)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetCommunity	被刷新的CSysNetCommunity
	///@param	pNewSysNetCommunity	新的值
	virtual void beforeUpdate(CSysNetCommunity *pSysNetCommunity, CWriteableSysNetCommunity *pNewSysNetCommunity)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetCommunity	被刷新的CSysNetCommunity
	virtual void afterUpdate(CSysNetCommunity *pSysNetCommunity)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetCommunity	要删除的CSysNetCommunity
	virtual void beforeRemove(CSysNetCommunity *pSysNetCommunity)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetCommunityFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityCommitTrigger是确认设备共同体时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityCommitTrigger
{
public:
	///构造方法
	CSysNetCommunityCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetCommunityCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetCommunityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetCommunity	已经加入的SysNetCommunity
	virtual void commitAdd(CSysNetCommunity *pSysNetCommunity)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetCommunity	被刷新的CSysNetCommunity
	///@param	poldSysNetCommunity	原来的值
	virtual void commitUpdate(CSysNetCommunity *pSysNetCommunity, CWriteableSysNetCommunity *pOldSysNetCommunity)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetCommunity	已经删除的CSysNetCommunity
	virtual void commitRemove(CWriteableSysNetCommunity *pSysNetCommunity)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetCommunityFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityIterator是一个对设备共同体的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityIterator
{
public:
	///构造方法
	CSysNetCommunityIterator(void)
	{
	}

	///构造方法
	CSysNetCommunityIterator(CSysNetCommunityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetCommunityIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetCommunity
	///@return	下一个满足条件CSysNetCommunity，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetCommunity *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetCommunityFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetCommunity 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetCommunity * pSysNetCommunity,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetCommunityFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetPortType是一个存储端口类型的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetPortType
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! Description.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetPortType *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///中文名
	CTypeObjectIDType CName;
	///英文名
	CTypeObjectIDType EName;
	///描述
	CTypeObjectIDType Description;
	
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

typedef const CWriteableSysNetPortType CSysNetPortType;

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeActionTrigger是操作端口类型时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeActionTrigger
{
public:
	///构造方法
	CSysNetPortTypeActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetPortTypeActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetPortTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetPortType	要加入的SysNetPortType
	virtual void beforeAdd(CWriteableSysNetPortType *pSysNetPortType)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetPortType	已经加入的SysNetPortType
	virtual void afterAdd(CSysNetPortType *pSysNetPortType)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetPortType	被刷新的CSysNetPortType
	///@param	pNewSysNetPortType	新的值
	virtual void beforeUpdate(CSysNetPortType *pSysNetPortType, CWriteableSysNetPortType *pNewSysNetPortType)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetPortType	被刷新的CSysNetPortType
	virtual void afterUpdate(CSysNetPortType *pSysNetPortType)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetPortType	要删除的CSysNetPortType
	virtual void beforeRemove(CSysNetPortType *pSysNetPortType)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetPortTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeCommitTrigger是确认端口类型时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeCommitTrigger
{
public:
	///构造方法
	CSysNetPortTypeCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetPortTypeCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetPortTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetPortType	已经加入的SysNetPortType
	virtual void commitAdd(CSysNetPortType *pSysNetPortType)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetPortType	被刷新的CSysNetPortType
	///@param	poldSysNetPortType	原来的值
	virtual void commitUpdate(CSysNetPortType *pSysNetPortType, CWriteableSysNetPortType *pOldSysNetPortType)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetPortType	已经删除的CSysNetPortType
	virtual void commitRemove(CWriteableSysNetPortType *pSysNetPortType)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetPortTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeIterator是一个对端口类型的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeIterator
{
public:
	///构造方法
	CSysNetPortTypeIterator(void)
	{
	}

	///构造方法
	CSysNetPortTypeIterator(CSysNetPortTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPortTypeIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetPortType
	///@return	下一个满足条件CSysNetPortType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPortType *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetPortTypeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPortType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPortType * pSysNetPortType,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetPortTypeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetInterface是一个存储端口的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetInterface
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
		if (! ID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! MonitorType_ID.isValid())
			return 0;
		if (! IfType.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! IpAddress.isValid())
			return 0;
		if (! IpMask.isValid())
			return 0;
		if (! IfStatus.isValid())
			return 0;
		if (! MAC.isValid())
			return 0;
		if (! DeviceID.isValid())
			return 0;
		if (! DeviceObjectID.isValid())
			return 0;
		if (! DeviceIndex.isValid())
			return 0;
		if (! isPolling.isValid())
			return 0;
		if (! Description.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetInterface *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///监控对象
	CNetObjectIDType ObjectID;
	///监控对象类型
	CVolumeType MonitorType_ID;
	///端口类型
	CVolumeType IfType;
	///端口名
	CTypeObjectIDType EName;
	///IP地址
	CIPAddressType IpAddress;
	///掩码
	CIPAddressType IpMask;
	///端口状态
	CVolumeType IfStatus;
	///物理地址
	CTypeObjectIDType MAC;
	///所属设备ID
	CVolumeType DeviceID;
	///所属设备ObjectID
	CNetObjectIDType DeviceObjectID;
	///所属设备端口索引
	CTypeObjectNameType DeviceIndex;
	///是否轮询
	CVolumeType isPolling;
	///描述
	CTypeObjectIDType Description;
	
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

typedef const CWriteableSysNetInterface CSysNetInterface;

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceActionTrigger是操作端口时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceActionTrigger
{
public:
	///构造方法
	CSysNetInterfaceActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetInterfaceActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetInterfaceFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetInterface	要加入的SysNetInterface
	virtual void beforeAdd(CWriteableSysNetInterface *pSysNetInterface)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetInterface	已经加入的SysNetInterface
	virtual void afterAdd(CSysNetInterface *pSysNetInterface)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetInterface	被刷新的CSysNetInterface
	///@param	pNewSysNetInterface	新的值
	virtual void beforeUpdate(CSysNetInterface *pSysNetInterface, CWriteableSysNetInterface *pNewSysNetInterface)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetInterface	被刷新的CSysNetInterface
	virtual void afterUpdate(CSysNetInterface *pSysNetInterface)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetInterface	要删除的CSysNetInterface
	virtual void beforeRemove(CSysNetInterface *pSysNetInterface)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetInterfaceFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceCommitTrigger是确认端口时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceCommitTrigger
{
public:
	///构造方法
	CSysNetInterfaceCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetInterfaceCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetInterfaceFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetInterface	已经加入的SysNetInterface
	virtual void commitAdd(CSysNetInterface *pSysNetInterface)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetInterface	被刷新的CSysNetInterface
	///@param	poldSysNetInterface	原来的值
	virtual void commitUpdate(CSysNetInterface *pSysNetInterface, CWriteableSysNetInterface *pOldSysNetInterface)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetInterface	已经删除的CSysNetInterface
	virtual void commitRemove(CWriteableSysNetInterface *pSysNetInterface)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetInterfaceFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceIterator是一个对端口的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceIterator
{
public:
	///构造方法
	CSysNetInterfaceIterator(void)
	{
	}

	///构造方法
	CSysNetInterfaceIterator(CSysNetInterfaceFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetInterfaceIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetInterface
	///@return	下一个满足条件CSysNetInterface，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetInterface *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetInterfaceFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetInterface 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetInterface * pSysNetInterface,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetInterfaceFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetGeneralOID是一个存储通用OID的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetGeneralOID
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! OID.isValid())
			return 0;
		if (! Unit.isValid())
			return 0;
		if (! isTheTable.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetGeneralOID *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///OID中文名
	CTypeObjectIDType CName;
	///OID英文名
	CTypeObjectIDType EName;
	///OID
	CTypeObjectIDType OID;
	///单位
	CTypeObjectIDType Unit;
	///是否标量标志
	CVolumeType isTheTable;
	
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

typedef const CWriteableSysNetGeneralOID CSysNetGeneralOID;

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDActionTrigger是操作通用OID时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDActionTrigger
{
public:
	///构造方法
	CSysNetGeneralOIDActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetGeneralOIDActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetGeneralOIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetGeneralOID	要加入的SysNetGeneralOID
	virtual void beforeAdd(CWriteableSysNetGeneralOID *pSysNetGeneralOID)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetGeneralOID	已经加入的SysNetGeneralOID
	virtual void afterAdd(CSysNetGeneralOID *pSysNetGeneralOID)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetGeneralOID	被刷新的CSysNetGeneralOID
	///@param	pNewSysNetGeneralOID	新的值
	virtual void beforeUpdate(CSysNetGeneralOID *pSysNetGeneralOID, CWriteableSysNetGeneralOID *pNewSysNetGeneralOID)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetGeneralOID	被刷新的CSysNetGeneralOID
	virtual void afterUpdate(CSysNetGeneralOID *pSysNetGeneralOID)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetGeneralOID	要删除的CSysNetGeneralOID
	virtual void beforeRemove(CSysNetGeneralOID *pSysNetGeneralOID)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetGeneralOIDFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDCommitTrigger是确认通用OID时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDCommitTrigger
{
public:
	///构造方法
	CSysNetGeneralOIDCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetGeneralOIDCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetGeneralOIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetGeneralOID	已经加入的SysNetGeneralOID
	virtual void commitAdd(CSysNetGeneralOID *pSysNetGeneralOID)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetGeneralOID	被刷新的CSysNetGeneralOID
	///@param	poldSysNetGeneralOID	原来的值
	virtual void commitUpdate(CSysNetGeneralOID *pSysNetGeneralOID, CWriteableSysNetGeneralOID *pOldSysNetGeneralOID)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetGeneralOID	已经删除的CSysNetGeneralOID
	virtual void commitRemove(CWriteableSysNetGeneralOID *pSysNetGeneralOID)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetGeneralOIDFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDIterator是一个对通用OID的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDIterator
{
public:
	///构造方法
	CSysNetGeneralOIDIterator(void)
	{
	}

	///构造方法
	CSysNetGeneralOIDIterator(CSysNetGeneralOIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetGeneralOIDIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetGeneralOID
	///@return	下一个满足条件CSysNetGeneralOID，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetGeneralOID *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetGeneralOIDFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetGeneralOID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetGeneralOID * pSysNetGeneralOID,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetGeneralOIDFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorType是一个存储监控对象类别的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorType
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorType *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///OID中文名
	CTypeObjectIDType CName;
	///OID英文名
	CTypeObjectIDType EName;
	
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

typedef const CWriteableSysNetMonitorType CSysNetMonitorType;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeActionTrigger是操作监控对象类别时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeActionTrigger
{
public:
	///构造方法
	CSysNetMonitorTypeActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorTypeActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetMonitorType	要加入的SysNetMonitorType
	virtual void beforeAdd(CWriteableSysNetMonitorType *pSysNetMonitorType)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetMonitorType	已经加入的SysNetMonitorType
	virtual void afterAdd(CSysNetMonitorType *pSysNetMonitorType)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetMonitorType	被刷新的CSysNetMonitorType
	///@param	pNewSysNetMonitorType	新的值
	virtual void beforeUpdate(CSysNetMonitorType *pSysNetMonitorType, CWriteableSysNetMonitorType *pNewSysNetMonitorType)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetMonitorType	被刷新的CSysNetMonitorType
	virtual void afterUpdate(CSysNetMonitorType *pSysNetMonitorType)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetMonitorType	要删除的CSysNetMonitorType
	virtual void beforeRemove(CSysNetMonitorType *pSysNetMonitorType)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeCommitTrigger是确认监控对象类别时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeCommitTrigger
{
public:
	///构造方法
	CSysNetMonitorTypeCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorTypeCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetMonitorType	已经加入的SysNetMonitorType
	virtual void commitAdd(CSysNetMonitorType *pSysNetMonitorType)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetMonitorType	被刷新的CSysNetMonitorType
	///@param	poldSysNetMonitorType	原来的值
	virtual void commitUpdate(CSysNetMonitorType *pSysNetMonitorType, CWriteableSysNetMonitorType *pOldSysNetMonitorType)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetMonitorType	已经删除的CSysNetMonitorType
	virtual void commitRemove(CWriteableSysNetMonitorType *pSysNetMonitorType)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeIterator是一个对监控对象类别的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeIterator
{
public:
	///构造方法
	CSysNetMonitorTypeIterator(void)
	{
	}

	///构造方法
	CSysNetMonitorTypeIterator(CSysNetMonitorTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTypeIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetMonitorType
	///@return	下一个满足条件CSysNetMonitorType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorType *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetMonitorTypeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorType * pSysNetMonitorType,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetMonitorTypeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorAttrScope是一个存储指标统表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorAttrScope
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! Comments.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorAttrScope *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///指标中文名
	CNetAttrTypeType CName;
	///指标英文名
	CNetAttrTypeType EName;
	///注释
	CNetAttrTypeType Comments;
	
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

typedef const CWriteableSysNetMonitorAttrScope CSysNetMonitorAttrScope;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeActionTrigger是操作指标统表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeActionTrigger
{
public:
	///构造方法
	CSysNetMonitorAttrScopeActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorAttrScopeActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorAttrScopeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetMonitorAttrScope	要加入的SysNetMonitorAttrScope
	virtual void beforeAdd(CWriteableSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetMonitorAttrScope	已经加入的SysNetMonitorAttrScope
	virtual void afterAdd(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetMonitorAttrScope	被刷新的CSysNetMonitorAttrScope
	///@param	pNewSysNetMonitorAttrScope	新的值
	virtual void beforeUpdate(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope, CWriteableSysNetMonitorAttrScope *pNewSysNetMonitorAttrScope)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetMonitorAttrScope	被刷新的CSysNetMonitorAttrScope
	virtual void afterUpdate(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetMonitorAttrScope	要删除的CSysNetMonitorAttrScope
	virtual void beforeRemove(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorAttrScopeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeCommitTrigger是确认指标统表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeCommitTrigger
{
public:
	///构造方法
	CSysNetMonitorAttrScopeCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorAttrScopeCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorAttrScopeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetMonitorAttrScope	已经加入的SysNetMonitorAttrScope
	virtual void commitAdd(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetMonitorAttrScope	被刷新的CSysNetMonitorAttrScope
	///@param	poldSysNetMonitorAttrScope	原来的值
	virtual void commitUpdate(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope, CWriteableSysNetMonitorAttrScope *pOldSysNetMonitorAttrScope)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetMonitorAttrScope	已经删除的CSysNetMonitorAttrScope
	virtual void commitRemove(CWriteableSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorAttrScopeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeIterator是一个对指标统表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeIterator
{
public:
	///构造方法
	CSysNetMonitorAttrScopeIterator(void)
	{
	}

	///构造方法
	CSysNetMonitorAttrScopeIterator(CSysNetMonitorAttrScopeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorAttrScopeIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetMonitorAttrScope
	///@return	下一个满足条件CSysNetMonitorAttrScope，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorAttrScope *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetMonitorAttrScopeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorAttrScope 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrScope * pSysNetMonitorAttrScope,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetMonitorAttrScopeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorAttrType是一个存储监控指标表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorAttrType
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
		if (! ID.isValid())
			return 0;
		if (! MANUFACTORY_ID.isValid())
			return 0;
		if (! MonitorType_ID.isValid())
			return 0;
		if (! AttrType_ID.isValid())
			return 0;
		if (! MANUFACTORY.isValid())
			return 0;
		if (! MonitorType.isValid())
			return 0;
		if (! AttrType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorAttrType *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///厂商类型
	CVolumeType MANUFACTORY_ID;
	///设备类别
	CVolumeType MonitorType_ID;
	///网络监控指标ID
	CVolumeType AttrType_ID;
	///厂商类型
	CTypeObjectIDType MANUFACTORY;
	///设备类别
	CTypeObjectIDType MonitorType;
	///网络监控指标
	CNetAttrTypeType AttrType;
	
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

typedef const CWriteableSysNetMonitorAttrType CSysNetMonitorAttrType;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeActionTrigger是操作监控指标表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeActionTrigger
{
public:
	///构造方法
	CSysNetMonitorAttrTypeActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorAttrTypeActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorAttrTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetMonitorAttrType	要加入的SysNetMonitorAttrType
	virtual void beforeAdd(CWriteableSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetMonitorAttrType	已经加入的SysNetMonitorAttrType
	virtual void afterAdd(CSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetMonitorAttrType	被刷新的CSysNetMonitorAttrType
	///@param	pNewSysNetMonitorAttrType	新的值
	virtual void beforeUpdate(CSysNetMonitorAttrType *pSysNetMonitorAttrType, CWriteableSysNetMonitorAttrType *pNewSysNetMonitorAttrType)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetMonitorAttrType	被刷新的CSysNetMonitorAttrType
	virtual void afterUpdate(CSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetMonitorAttrType	要删除的CSysNetMonitorAttrType
	virtual void beforeRemove(CSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorAttrTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeCommitTrigger是确认监控指标表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeCommitTrigger
{
public:
	///构造方法
	CSysNetMonitorAttrTypeCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorAttrTypeCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorAttrTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetMonitorAttrType	已经加入的SysNetMonitorAttrType
	virtual void commitAdd(CSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetMonitorAttrType	被刷新的CSysNetMonitorAttrType
	///@param	poldSysNetMonitorAttrType	原来的值
	virtual void commitUpdate(CSysNetMonitorAttrType *pSysNetMonitorAttrType, CWriteableSysNetMonitorAttrType *pOldSysNetMonitorAttrType)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetMonitorAttrType	已经删除的CSysNetMonitorAttrType
	virtual void commitRemove(CWriteableSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorAttrTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeIterator是一个对监控指标表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeIterator
{
public:
	///构造方法
	CSysNetMonitorAttrTypeIterator(void)
	{
	}

	///构造方法
	CSysNetMonitorAttrTypeIterator(CSysNetMonitorAttrTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorAttrTypeIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetMonitorAttrType
	///@return	下一个满足条件CSysNetMonitorAttrType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorAttrType *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetMonitorAttrTypeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorAttrType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrType * pSysNetMonitorAttrType,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetMonitorAttrTypeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorCommandType是一个存储监控指令表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorCommandType
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
		if (! ID.isValid())
			return 0;
		if (! Manufactory_ID.isValid())
			return 0;
		if (! MonitorType_ID.isValid())
			return 0;
		if (! DeviceModle_ID.isValid())
			return 0;
		if (! ActionGroup_ID.isValid())
			return 0;
		if (! Manufactory.isValid())
			return 0;
		if (! MonitorType.isValid())
			return 0;
		if (! DeviceModle.isValid())
			return 0;
		if (! ActionGroup.isValid())
			return 0;
		if (! Command.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorCommandType *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///厂商类型ID
	CVolumeType Manufactory_ID;
	///设备类别ID
	CVolumeType MonitorType_ID;
	///设备型号ID
	CVolumeType DeviceModle_ID;
	///动作族ID
	CVolumeType ActionGroup_ID;
	///厂商类型
	CTypeObjectIDType Manufactory;
	///设备类别
	CTypeObjectIDType MonitorType;
	///设备型号
	CTypeObjectIDType DeviceModle;
	///动作族
	CTypeObjectIDType ActionGroup;
	///指令码
	CNetAttrTypeType Command;
	
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

typedef const CWriteableSysNetMonitorCommandType CSysNetMonitorCommandType;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeActionTrigger是操作监控指令表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeActionTrigger
{
public:
	///构造方法
	CSysNetMonitorCommandTypeActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorCommandTypeActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorCommandTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetMonitorCommandType	要加入的SysNetMonitorCommandType
	virtual void beforeAdd(CWriteableSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetMonitorCommandType	已经加入的SysNetMonitorCommandType
	virtual void afterAdd(CSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetMonitorCommandType	被刷新的CSysNetMonitorCommandType
	///@param	pNewSysNetMonitorCommandType	新的值
	virtual void beforeUpdate(CSysNetMonitorCommandType *pSysNetMonitorCommandType, CWriteableSysNetMonitorCommandType *pNewSysNetMonitorCommandType)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetMonitorCommandType	被刷新的CSysNetMonitorCommandType
	virtual void afterUpdate(CSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetMonitorCommandType	要删除的CSysNetMonitorCommandType
	virtual void beforeRemove(CSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorCommandTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeCommitTrigger是确认监控指令表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeCommitTrigger
{
public:
	///构造方法
	CSysNetMonitorCommandTypeCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorCommandTypeCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorCommandTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetMonitorCommandType	已经加入的SysNetMonitorCommandType
	virtual void commitAdd(CSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetMonitorCommandType	被刷新的CSysNetMonitorCommandType
	///@param	poldSysNetMonitorCommandType	原来的值
	virtual void commitUpdate(CSysNetMonitorCommandType *pSysNetMonitorCommandType, CWriteableSysNetMonitorCommandType *pOldSysNetMonitorCommandType)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetMonitorCommandType	已经删除的CSysNetMonitorCommandType
	virtual void commitRemove(CWriteableSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorCommandTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeIterator是一个对监控指令表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeIterator
{
public:
	///构造方法
	CSysNetMonitorCommandTypeIterator(void)
	{
	}

	///构造方法
	CSysNetMonitorCommandTypeIterator(CSysNetMonitorCommandTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorCommandTypeIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetMonitorCommandType
	///@return	下一个满足条件CSysNetMonitorCommandType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorCommandType *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetMonitorCommandTypeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorCommandType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorCommandType * pSysNetMonitorCommandType,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetMonitorCommandTypeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorActionGroup是一个存储动作族表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorActionGroup
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! ActionType.isValid())
			return 0;
		if (! Comments.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorActionGroup *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///动作族中文名
	CTypeObjectIDType CName;
	///动作族英文名
	CTypeObjectIDType EName;
	///动作类型码
	CVolumeType ActionType;
	///注释
	CNetAttrTypeType Comments;
	
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

typedef const CWriteableSysNetMonitorActionGroup CSysNetMonitorActionGroup;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupActionTrigger是操作动作族表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupActionTrigger
{
public:
	///构造方法
	CSysNetMonitorActionGroupActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorActionGroupActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorActionGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetMonitorActionGroup	要加入的SysNetMonitorActionGroup
	virtual void beforeAdd(CWriteableSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetMonitorActionGroup	已经加入的SysNetMonitorActionGroup
	virtual void afterAdd(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetMonitorActionGroup	被刷新的CSysNetMonitorActionGroup
	///@param	pNewSysNetMonitorActionGroup	新的值
	virtual void beforeUpdate(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup, CWriteableSysNetMonitorActionGroup *pNewSysNetMonitorActionGroup)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetMonitorActionGroup	被刷新的CSysNetMonitorActionGroup
	virtual void afterUpdate(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetMonitorActionGroup	要删除的CSysNetMonitorActionGroup
	virtual void beforeRemove(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorActionGroupFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupCommitTrigger是确认动作族表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupCommitTrigger
{
public:
	///构造方法
	CSysNetMonitorActionGroupCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorActionGroupCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorActionGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetMonitorActionGroup	已经加入的SysNetMonitorActionGroup
	virtual void commitAdd(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetMonitorActionGroup	被刷新的CSysNetMonitorActionGroup
	///@param	poldSysNetMonitorActionGroup	原来的值
	virtual void commitUpdate(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup, CWriteableSysNetMonitorActionGroup *pOldSysNetMonitorActionGroup)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetMonitorActionGroup	已经删除的CSysNetMonitorActionGroup
	virtual void commitRemove(CWriteableSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorActionGroupFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupIterator是一个对动作族表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupIterator
{
public:
	///构造方法
	CSysNetMonitorActionGroupIterator(void)
	{
	}

	///构造方法
	CSysNetMonitorActionGroupIterator(CSysNetMonitorActionGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorActionGroupIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetMonitorActionGroup
	///@return	下一个满足条件CSysNetMonitorActionGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorActionGroup *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetMonitorActionGroupFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorActionGroup 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionGroup * pSysNetMonitorActionGroup,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetMonitorActionGroupFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorDeviceGroup是一个存储设备对象组表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorDeviceGroup
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! Condition.isValid())
			return 0;
		if (! Comments.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorDeviceGroup *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///设备对象组中文名
	CTypeObjectIDType CName;
	///设备对象组英文名
	CTypeObjectIDType EName;
	///设备过滤条件
	CNetString512Type Condition;
	///注释
	CNetAttrTypeType Comments;
	
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

typedef const CWriteableSysNetMonitorDeviceGroup CSysNetMonitorDeviceGroup;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupActionTrigger是操作设备对象组表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupActionTrigger
{
public:
	///构造方法
	CSysNetMonitorDeviceGroupActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorDeviceGroupActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorDeviceGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetMonitorDeviceGroup	要加入的SysNetMonitorDeviceGroup
	virtual void beforeAdd(CWriteableSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetMonitorDeviceGroup	已经加入的SysNetMonitorDeviceGroup
	virtual void afterAdd(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetMonitorDeviceGroup	被刷新的CSysNetMonitorDeviceGroup
	///@param	pNewSysNetMonitorDeviceGroup	新的值
	virtual void beforeUpdate(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, CWriteableSysNetMonitorDeviceGroup *pNewSysNetMonitorDeviceGroup)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetMonitorDeviceGroup	被刷新的CSysNetMonitorDeviceGroup
	virtual void afterUpdate(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetMonitorDeviceGroup	要删除的CSysNetMonitorDeviceGroup
	virtual void beforeRemove(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorDeviceGroupFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupCommitTrigger是确认设备对象组表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupCommitTrigger
{
public:
	///构造方法
	CSysNetMonitorDeviceGroupCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorDeviceGroupCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorDeviceGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetMonitorDeviceGroup	已经加入的SysNetMonitorDeviceGroup
	virtual void commitAdd(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetMonitorDeviceGroup	被刷新的CSysNetMonitorDeviceGroup
	///@param	poldSysNetMonitorDeviceGroup	原来的值
	virtual void commitUpdate(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, CWriteableSysNetMonitorDeviceGroup *pOldSysNetMonitorDeviceGroup)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetMonitorDeviceGroup	已经删除的CSysNetMonitorDeviceGroup
	virtual void commitRemove(CWriteableSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorDeviceGroupFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupIterator是一个对设备对象组表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupIterator
{
public:
	///构造方法
	CSysNetMonitorDeviceGroupIterator(void)
	{
	}

	///构造方法
	CSysNetMonitorDeviceGroupIterator(CSysNetMonitorDeviceGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorDeviceGroupIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetMonitorDeviceGroup
	///@return	下一个满足条件CSysNetMonitorDeviceGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorDeviceGroup *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetMonitorDeviceGroupFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorDeviceGroup 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetMonitorDeviceGroupFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorTaskInfo是一个存储任务信息表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorTaskInfo
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! DeviceGroup_ID.isValid())
			return 0;
		if (! ManagerGroup_ID.isValid())
			return 0;
		if (! TimePolicy_ID.isValid())
			return 0;
		if (! TaskPriority_ID.isValid())
			return 0;
		if (! OutputPolicy_ID.isValid())
			return 0;
		if (! ActionGroup_ID.isValid())
			return 0;
		if (! EventExprStr.isValid())
			return 0;
		if (! DeviceGroup.isValid())
			return 0;
		if (! ManagerGroup.isValid())
			return 0;
		if (! TimePolicy.isValid())
			return 0;
		if (! TaskPriority.isValid())
			return 0;
		if (! OutputPolicy.isValid())
			return 0;
		if (! ActionGroup.isValid())
			return 0;
		if (! ValidFlag.isValid())
			return 0;
		if (! TaskStatus.isValid())
			return 0;
		if (! Comments.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorTaskInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///任务中文名
	CTypeObjectIDType CName;
	///任务英文名
	CTypeObjectIDType EName;
	///设备对象组ID
	CVolumeType DeviceGroup_ID;
	///管理人员对象组ID
	CVolumeType ManagerGroup_ID;
	///任务时间策略ID
	CVolumeType TimePolicy_ID;
	///任务优先级ID
	CVolumeType TaskPriority_ID;
	///结果输出策略ID
	CVolumeType OutputPolicy_ID;
	///任务动作族ID
	CVolumeType ActionGroup_ID;
	///任务表达式ID联合串
	CGeneralResultType EventExprStr;
	///设备对象组
	CTypeObjectIDType DeviceGroup;
	///管理人员对象组
	CTypeObjectIDType ManagerGroup;
	///任务时间策略
	CTypeObjectIDType TimePolicy;
	///任务优先级
	CTypeObjectIDType TaskPriority;
	///结果输出策略
	CTypeObjectIDType OutputPolicy;
	///任务动作族
	CTypeObjectIDType ActionGroup;
	///任务有效性标识
	CVolumeType ValidFlag;
	///任务状态标识
	CVolumeType TaskStatus;
	///任务描述
	CNetAttrTypeType Comments;
	
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

typedef const CWriteableSysNetMonitorTaskInfo CSysNetMonitorTaskInfo;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoActionTrigger是操作任务信息表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoActionTrigger
{
public:
	///构造方法
	CSysNetMonitorTaskInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorTaskInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorTaskInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetMonitorTaskInfo	要加入的SysNetMonitorTaskInfo
	virtual void beforeAdd(CWriteableSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetMonitorTaskInfo	已经加入的SysNetMonitorTaskInfo
	virtual void afterAdd(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetMonitorTaskInfo	被刷新的CSysNetMonitorTaskInfo
	///@param	pNewSysNetMonitorTaskInfo	新的值
	virtual void beforeUpdate(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, CWriteableSysNetMonitorTaskInfo *pNewSysNetMonitorTaskInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetMonitorTaskInfo	被刷新的CSysNetMonitorTaskInfo
	virtual void afterUpdate(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetMonitorTaskInfo	要删除的CSysNetMonitorTaskInfo
	virtual void beforeRemove(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorTaskInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoCommitTrigger是确认任务信息表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoCommitTrigger
{
public:
	///构造方法
	CSysNetMonitorTaskInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorTaskInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorTaskInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetMonitorTaskInfo	已经加入的SysNetMonitorTaskInfo
	virtual void commitAdd(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetMonitorTaskInfo	被刷新的CSysNetMonitorTaskInfo
	///@param	poldSysNetMonitorTaskInfo	原来的值
	virtual void commitUpdate(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, CWriteableSysNetMonitorTaskInfo *pOldSysNetMonitorTaskInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetMonitorTaskInfo	已经删除的CSysNetMonitorTaskInfo
	virtual void commitRemove(CWriteableSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorTaskInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoIterator是一个对任务信息表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoIterator
{
public:
	///构造方法
	CSysNetMonitorTaskInfoIterator(void)
	{
	}

	///构造方法
	CSysNetMonitorTaskInfoIterator(CSysNetMonitorTaskInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetMonitorTaskInfo
	///@return	下一个满足条件CSysNetMonitorTaskInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetMonitorTaskInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorTaskInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetMonitorTaskInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorTaskObjectSet是一个存储任务对象集的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorTaskObjectSet
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
		if (! ID.isValid())
			return 0;
		if (! DeviceGroup_ID.isValid())
			return 0;
		if (! Device_ID.isValid())
			return 0;
		if (! DataCenter.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorTaskObjectSet *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///设备对象组ID
	CVolumeType DeviceGroup_ID;
	///设备ID
	CVolumeType Device_ID;
	///DataCenter
	CDataCenterFlagType DataCenter;
	
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

typedef const CWriteableSysNetMonitorTaskObjectSet CSysNetMonitorTaskObjectSet;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetActionTrigger是操作任务对象集时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetActionTrigger
{
public:
	///构造方法
	CSysNetMonitorTaskObjectSetActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorTaskObjectSetActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorTaskObjectSetFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetMonitorTaskObjectSet	要加入的SysNetMonitorTaskObjectSet
	virtual void beforeAdd(CWriteableSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetMonitorTaskObjectSet	已经加入的SysNetMonitorTaskObjectSet
	virtual void afterAdd(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetMonitorTaskObjectSet	被刷新的CSysNetMonitorTaskObjectSet
	///@param	pNewSysNetMonitorTaskObjectSet	新的值
	virtual void beforeUpdate(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, CWriteableSysNetMonitorTaskObjectSet *pNewSysNetMonitorTaskObjectSet)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetMonitorTaskObjectSet	被刷新的CSysNetMonitorTaskObjectSet
	virtual void afterUpdate(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetMonitorTaskObjectSet	要删除的CSysNetMonitorTaskObjectSet
	virtual void beforeRemove(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorTaskObjectSetFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetCommitTrigger是确认任务对象集时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetCommitTrigger
{
public:
	///构造方法
	CSysNetMonitorTaskObjectSetCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorTaskObjectSetCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorTaskObjectSetFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetMonitorTaskObjectSet	已经加入的SysNetMonitorTaskObjectSet
	virtual void commitAdd(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetMonitorTaskObjectSet	被刷新的CSysNetMonitorTaskObjectSet
	///@param	poldSysNetMonitorTaskObjectSet	原来的值
	virtual void commitUpdate(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, CWriteableSysNetMonitorTaskObjectSet *pOldSysNetMonitorTaskObjectSet)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetMonitorTaskObjectSet	已经删除的CSysNetMonitorTaskObjectSet
	virtual void commitRemove(CWriteableSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorTaskObjectSetFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetIterator是一个对任务对象集的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetIterator
{
public:
	///构造方法
	CSysNetMonitorTaskObjectSetIterator(void)
	{
	}

	///构造方法
	CSysNetMonitorTaskObjectSetIterator(CSysNetMonitorTaskObjectSetFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskObjectSetIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetMonitorTaskObjectSet
	///@return	下一个满足条件CSysNetMonitorTaskObjectSet，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskObjectSet *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetMonitorTaskObjectSetFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorTaskObjectSet 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetMonitorTaskObjectSetFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorTaskResult是一个存储任务结果表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorTaskResult
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
		if (! ObjectID.isValid())
			return 0;
		if (! Task_ID.isValid())
			return 0;
		if (! OperateTime.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! InstructChain.isValid())
			return 0;
		if (! ResultChain.isValid())
			return 0;
		if (! Flag.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorTaskResult *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///网络监控对象ID
	CNetObjectIDType ObjectID;
	///任务ID
	CVolumeType Task_ID;
	///执行次数
	CVolumeType OperateTime;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///指令串
	CNetString256Type InstructChain;
	///结果串
	CNetString1KType ResultChain;
	///任务执行标识
	CVolumeType Flag;
	
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

typedef const CWriteableSysNetMonitorTaskResult CSysNetMonitorTaskResult;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultActionTrigger是操作任务结果表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultActionTrigger
{
public:
	///构造方法
	CSysNetMonitorTaskResultActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorTaskResultActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorTaskResultFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetMonitorTaskResult	要加入的SysNetMonitorTaskResult
	virtual void beforeAdd(CWriteableSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetMonitorTaskResult	已经加入的SysNetMonitorTaskResult
	virtual void afterAdd(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetMonitorTaskResult	被刷新的CSysNetMonitorTaskResult
	///@param	pNewSysNetMonitorTaskResult	新的值
	virtual void beforeUpdate(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult, CWriteableSysNetMonitorTaskResult *pNewSysNetMonitorTaskResult)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetMonitorTaskResult	被刷新的CSysNetMonitorTaskResult
	virtual void afterUpdate(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetMonitorTaskResult	要删除的CSysNetMonitorTaskResult
	virtual void beforeRemove(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorTaskResultFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultCommitTrigger是确认任务结果表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultCommitTrigger
{
public:
	///构造方法
	CSysNetMonitorTaskResultCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorTaskResultCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorTaskResultFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetMonitorTaskResult	已经加入的SysNetMonitorTaskResult
	virtual void commitAdd(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetMonitorTaskResult	被刷新的CSysNetMonitorTaskResult
	///@param	poldSysNetMonitorTaskResult	原来的值
	virtual void commitUpdate(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult, CWriteableSysNetMonitorTaskResult *pOldSysNetMonitorTaskResult)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetMonitorTaskResult	已经删除的CSysNetMonitorTaskResult
	virtual void commitRemove(CWriteableSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorTaskResultFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultIterator是一个对任务结果表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultIterator
{
public:
	///构造方法
	CSysNetMonitorTaskResultIterator(void)
	{
	}

	///构造方法
	CSysNetMonitorTaskResultIterator(CSysNetMonitorTaskResultFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskResultIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetMonitorTaskResult
	///@return	下一个满足条件CSysNetMonitorTaskResult，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskResult *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetMonitorTaskResultFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorTaskResult 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pSysNetMonitorTaskResult,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetMonitorTaskResultFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetPartyLinkInfo是一个存储会员链路信息表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetPartyLinkInfo
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
		if (! ID.isValid())
			return 0;
		if (! MEMBER_NO.isValid())
			return 0;
		if (! MEMBER_NAME.isValid())
			return 0;
		if (! REMOTE_ADDR.isValid())
			return 0;
		if (! LOCAL_ADDR.isValid())
			return 0;
		if (! ADDRESS.isValid())
			return 0;
		if (! LINE_STATUS.isValid())
			return 0;
		if (! CONTACT.isValid())
			return 0;
		if (! TELEPHONE.isValid())
			return 0;
		if (! MOBILEPHONE.isValid())
			return 0;
		if (! EMAIL.isValid())
			return 0;
		if (! FAX.isValid())
			return 0;
		if (! PROVINCE.isValid())
			return 0;
		if (! DDN_NO.isValid())
			return 0;
		if (! IN_MODE.isValid())
			return 0;
		if (! IP_WAN.isValid())
			return 0;
		if (! IP_LAN.isValid())
			return 0;
		if (! IPADDR.isValid())
			return 0;
		if (! Interface.isValid())
			return 0;
		if (! INTERFACE_DATE.isValid())
			return 0;
		if (! SOFTWARE.isValid())
			return 0;
		if (! FEE_TYPE.isValid())
			return 0;
		if (! SERVICEPROVIDER.isValid())
			return 0;
		if (! IF_ZIYING.isValid())
			return 0;
		if (! IF_TUOGUAN.isValid())
			return 0;
		if (! HASOTHER.isValid())
			return 0;
		if (! SEAT_NO.isValid())
			return 0;
		if (! PRO.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetPartyLinkInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///会员号
	CCfgNameType MEMBER_NO;
	///会员名称
	CTypeObjectIDType MEMBER_NAME;
	///会员接入地点
	CTypeObjectIDType REMOTE_ADDR;
	///上期所接入点
	CTypeObjectIDType LOCAL_ADDR;
	///地址
	CNetAttrTypeType ADDRESS;
	///线路状态
	CCfgNameType LINE_STATUS;
	///联系人
	CCfgNameType CONTACT;
	///联系电话
	CTypeObjectIDType TELEPHONE;
	///手机号
	CTypeObjectIDType MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType EMAIL;
	///传真
	CTypeObjectIDType FAX;
	///所属省份
	CCfgNameType PROVINCE;
	///线路编号
	CTypeObjectIDType DDN_NO;
	///接入方式
	CTypeObjectIDType IN_MODE;
	///入网IP广域
	CTypeObjectIDType IP_WAN;
	///入网IP局域
	CTypeObjectIDType IP_LAN;
	///路由器网管IP
	CTypeObjectIDType IPADDR;
	///路由器端口号
	CTypeObjectIDType Interface;
	///接口开通日期
	CCfgNameType INTERFACE_DATE;
	///所用软件
	CCfgNameType SOFTWARE;
	///付费类型
	CCfgNameType FEE_TYPE;
	///运营商
	CCfgNameType SERVICEPROVIDER;
	///是否自营
	CCfgNameType IF_ZIYING;
	///是否托管
	CCfgNameType IF_TUOGUAN;
	///有无他所线路
	CCfgNameType HASOTHER;
	///席位号
	CGeneralResultType SEAT_NO;
	///备注
	CPolicyStringTypeType PRO;
	
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

typedef const CWriteableSysNetPartyLinkInfo CSysNetPartyLinkInfo;

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoActionTrigger是操作会员链路信息表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoActionTrigger
{
public:
	///构造方法
	CSysNetPartyLinkInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetPartyLinkInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetPartyLinkInfo	要加入的SysNetPartyLinkInfo
	virtual void beforeAdd(CWriteableSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetPartyLinkInfo	已经加入的SysNetPartyLinkInfo
	virtual void afterAdd(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetPartyLinkInfo	被刷新的CSysNetPartyLinkInfo
	///@param	pNewSysNetPartyLinkInfo	新的值
	virtual void beforeUpdate(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo, CWriteableSysNetPartyLinkInfo *pNewSysNetPartyLinkInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetPartyLinkInfo	被刷新的CSysNetPartyLinkInfo
	virtual void afterUpdate(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetPartyLinkInfo	要删除的CSysNetPartyLinkInfo
	virtual void beforeRemove(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetPartyLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoCommitTrigger是确认会员链路信息表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoCommitTrigger
{
public:
	///构造方法
	CSysNetPartyLinkInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetPartyLinkInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetPartyLinkInfo	已经加入的SysNetPartyLinkInfo
	virtual void commitAdd(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetPartyLinkInfo	被刷新的CSysNetPartyLinkInfo
	///@param	poldSysNetPartyLinkInfo	原来的值
	virtual void commitUpdate(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo, CWriteableSysNetPartyLinkInfo *pOldSysNetPartyLinkInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetPartyLinkInfo	已经删除的CSysNetPartyLinkInfo
	virtual void commitRemove(CWriteableSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetPartyLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoIterator是一个对会员链路信息表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoIterator
{
public:
	///构造方法
	CSysNetPartyLinkInfoIterator(void)
	{
	}

	///构造方法
	CSysNetPartyLinkInfoIterator(CSysNetPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPartyLinkInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetPartyLinkInfo
	///@return	下一个满足条件CSysNetPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartyLinkInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetPartyLinkInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPartyLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkInfo * pSysNetPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetPartyLinkInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetDelPartyLinkInfo是一个存储会员链路信息表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetDelPartyLinkInfo
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
		if (! ID.isValid())
			return 0;
		if (! MEMBER_NO.isValid())
			return 0;
		if (! MEMBER_NAME.isValid())
			return 0;
		if (! REMOTE_ADDR.isValid())
			return 0;
		if (! LOCAL_ADDR.isValid())
			return 0;
		if (! ADDRESS.isValid())
			return 0;
		if (! LINE_STATUS.isValid())
			return 0;
		if (! CONTACT.isValid())
			return 0;
		if (! TELEPHONE.isValid())
			return 0;
		if (! MOBILEPHONE.isValid())
			return 0;
		if (! EMAIL.isValid())
			return 0;
		if (! FAX.isValid())
			return 0;
		if (! PROVINCE.isValid())
			return 0;
		if (! DDN_NO.isValid())
			return 0;
		if (! IN_MODE.isValid())
			return 0;
		if (! IP_WAN.isValid())
			return 0;
		if (! IP_LAN.isValid())
			return 0;
		if (! IPADDR.isValid())
			return 0;
		if (! Interface.isValid())
			return 0;
		if (! INTERFACE_DATE.isValid())
			return 0;
		if (! SOFTWARE.isValid())
			return 0;
		if (! FEE_TYPE.isValid())
			return 0;
		if (! SERVICEPROVIDER.isValid())
			return 0;
		if (! IF_ZIYING.isValid())
			return 0;
		if (! IF_TUOGUAN.isValid())
			return 0;
		if (! HASOTHER.isValid())
			return 0;
		if (! SEAT_NO.isValid())
			return 0;
		if (! PRO.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetDelPartyLinkInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///会员号
	CCfgNameType MEMBER_NO;
	///会员名称
	CTypeObjectIDType MEMBER_NAME;
	///会员接入地点
	CTypeObjectIDType REMOTE_ADDR;
	///上期所接入点
	CTypeObjectIDType LOCAL_ADDR;
	///地址
	CNetAttrTypeType ADDRESS;
	///线路状态
	CCfgNameType LINE_STATUS;
	///联系人
	CCfgNameType CONTACT;
	///联系电话
	CTypeObjectIDType TELEPHONE;
	///手机号
	CTypeObjectIDType MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType EMAIL;
	///传真
	CTypeObjectIDType FAX;
	///所属省份
	CCfgNameType PROVINCE;
	///线路编号
	CTypeObjectIDType DDN_NO;
	///接入方式
	CTypeObjectIDType IN_MODE;
	///入网IP广域
	CTypeObjectIDType IP_WAN;
	///入网IP局域
	CTypeObjectIDType IP_LAN;
	///路由器网管IP
	CTypeObjectIDType IPADDR;
	///路由器端口号
	CTypeObjectIDType Interface;
	///接口开通日期
	CCfgNameType INTERFACE_DATE;
	///所用软件
	CCfgNameType SOFTWARE;
	///付费类型
	CCfgNameType FEE_TYPE;
	///运营商
	CCfgNameType SERVICEPROVIDER;
	///是否自营
	CCfgNameType IF_ZIYING;
	///是否托管
	CCfgNameType IF_TUOGUAN;
	///有无他所线路
	CCfgNameType HASOTHER;
	///席位号
	CGeneralResultType SEAT_NO;
	///备注
	CPolicyStringTypeType PRO;
	
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

typedef const CWriteableSysNetDelPartyLinkInfo CSysNetDelPartyLinkInfo;

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoActionTrigger是操作会员链路信息表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoActionTrigger
{
public:
	///构造方法
	CSysNetDelPartyLinkInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetDelPartyLinkInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetDelPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetDelPartyLinkInfo	要加入的SysNetDelPartyLinkInfo
	virtual void beforeAdd(CWriteableSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetDelPartyLinkInfo	已经加入的SysNetDelPartyLinkInfo
	virtual void afterAdd(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetDelPartyLinkInfo	被刷新的CSysNetDelPartyLinkInfo
	///@param	pNewSysNetDelPartyLinkInfo	新的值
	virtual void beforeUpdate(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, CWriteableSysNetDelPartyLinkInfo *pNewSysNetDelPartyLinkInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetDelPartyLinkInfo	被刷新的CSysNetDelPartyLinkInfo
	virtual void afterUpdate(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetDelPartyLinkInfo	要删除的CSysNetDelPartyLinkInfo
	virtual void beforeRemove(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetDelPartyLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoCommitTrigger是确认会员链路信息表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoCommitTrigger
{
public:
	///构造方法
	CSysNetDelPartyLinkInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetDelPartyLinkInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetDelPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetDelPartyLinkInfo	已经加入的SysNetDelPartyLinkInfo
	virtual void commitAdd(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetDelPartyLinkInfo	被刷新的CSysNetDelPartyLinkInfo
	///@param	poldSysNetDelPartyLinkInfo	原来的值
	virtual void commitUpdate(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, CWriteableSysNetDelPartyLinkInfo *pOldSysNetDelPartyLinkInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetDelPartyLinkInfo	已经删除的CSysNetDelPartyLinkInfo
	virtual void commitRemove(CWriteableSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetDelPartyLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoIterator是一个对会员链路信息表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoIterator
{
public:
	///构造方法
	CSysNetDelPartyLinkInfoIterator(void)
	{
	}

	///构造方法
	CSysNetDelPartyLinkInfoIterator(CSysNetDelPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDelPartyLinkInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetDelPartyLinkInfo
	///@return	下一个满足条件CSysNetDelPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDelPartyLinkInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetDelPartyLinkInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDelPartyLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetDelPartyLinkInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetPartyLinkAddrChange是一个存储会员链路信息表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetPartyLinkAddrChange
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
		if (! ID.isValid())
			return 0;
		if (! RelationID.isValid())
			return 0;
		if (! OLDADDRESS.isValid())
			return 0;
		if (! NEWADDRESS.isValid())
			return 0;
		if (! OPERATOR.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetPartyLinkAddrChange *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///ID
	CVolumeType RelationID;
	///变更前地址
	CNetAttrTypeType OLDADDRESS;
	///变更后地址
	CNetAttrTypeType NEWADDRESS;
	///操作人
	CCfgNameType OPERATOR;
	///修改日期
	CDateType MonDate;
	///修改时间
	CTimeType MonTime;
	
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

typedef const CWriteableSysNetPartyLinkAddrChange CSysNetPartyLinkAddrChange;

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeActionTrigger是操作会员链路信息表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeActionTrigger
{
public:
	///构造方法
	CSysNetPartyLinkAddrChangeActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetPartyLinkAddrChangeActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetPartyLinkAddrChangeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetPartyLinkAddrChange	要加入的SysNetPartyLinkAddrChange
	virtual void beforeAdd(CWriteableSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetPartyLinkAddrChange	已经加入的SysNetPartyLinkAddrChange
	virtual void afterAdd(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetPartyLinkAddrChange	被刷新的CSysNetPartyLinkAddrChange
	///@param	pNewSysNetPartyLinkAddrChange	新的值
	virtual void beforeUpdate(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, CWriteableSysNetPartyLinkAddrChange *pNewSysNetPartyLinkAddrChange)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetPartyLinkAddrChange	被刷新的CSysNetPartyLinkAddrChange
	virtual void afterUpdate(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetPartyLinkAddrChange	要删除的CSysNetPartyLinkAddrChange
	virtual void beforeRemove(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetPartyLinkAddrChangeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeCommitTrigger是确认会员链路信息表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeCommitTrigger
{
public:
	///构造方法
	CSysNetPartyLinkAddrChangeCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetPartyLinkAddrChangeCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetPartyLinkAddrChangeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetPartyLinkAddrChange	已经加入的SysNetPartyLinkAddrChange
	virtual void commitAdd(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetPartyLinkAddrChange	被刷新的CSysNetPartyLinkAddrChange
	///@param	poldSysNetPartyLinkAddrChange	原来的值
	virtual void commitUpdate(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, CWriteableSysNetPartyLinkAddrChange *pOldSysNetPartyLinkAddrChange)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetPartyLinkAddrChange	已经删除的CSysNetPartyLinkAddrChange
	virtual void commitRemove(CWriteableSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetPartyLinkAddrChangeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeIterator是一个对会员链路信息表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeIterator
{
public:
	///构造方法
	CSysNetPartyLinkAddrChangeIterator(void)
	{
	}

	///构造方法
	CSysNetPartyLinkAddrChangeIterator(CSysNetPartyLinkAddrChangeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPartyLinkAddrChangeIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetPartyLinkAddrChange
	///@return	下一个满足条件CSysNetPartyLinkAddrChange，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartyLinkAddrChange *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetPartyLinkAddrChangeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPartyLinkAddrChange 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetPartyLinkAddrChangeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorActionAttr是一个存储监控动作指标对照表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorActionAttr
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
		if (! ID.isValid())
			return 0;
		if (! ActionGroup_ID.isValid())
			return 0;
		if (! MonitorAttr_ID.isValid())
			return 0;
		if (! MonitorAttrName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorActionAttr *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///动作族ID
	CVolumeType ActionGroup_ID;
	///监控对象ID
	CVolumeType MonitorAttr_ID;
	///指标英文名
	CNetAttrTypeType MonitorAttrName;
	
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

typedef const CWriteableSysNetMonitorActionAttr CSysNetMonitorActionAttr;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrActionTrigger是操作监控动作指标对照表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrActionTrigger
{
public:
	///构造方法
	CSysNetMonitorActionAttrActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorActionAttrActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorActionAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetMonitorActionAttr	要加入的SysNetMonitorActionAttr
	virtual void beforeAdd(CWriteableSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetMonitorActionAttr	已经加入的SysNetMonitorActionAttr
	virtual void afterAdd(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetMonitorActionAttr	被刷新的CSysNetMonitorActionAttr
	///@param	pNewSysNetMonitorActionAttr	新的值
	virtual void beforeUpdate(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr, CWriteableSysNetMonitorActionAttr *pNewSysNetMonitorActionAttr)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetMonitorActionAttr	被刷新的CSysNetMonitorActionAttr
	virtual void afterUpdate(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetMonitorActionAttr	要删除的CSysNetMonitorActionAttr
	virtual void beforeRemove(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorActionAttrFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrCommitTrigger是确认监控动作指标对照表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrCommitTrigger
{
public:
	///构造方法
	CSysNetMonitorActionAttrCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorActionAttrCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorActionAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetMonitorActionAttr	已经加入的SysNetMonitorActionAttr
	virtual void commitAdd(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetMonitorActionAttr	被刷新的CSysNetMonitorActionAttr
	///@param	poldSysNetMonitorActionAttr	原来的值
	virtual void commitUpdate(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr, CWriteableSysNetMonitorActionAttr *pOldSysNetMonitorActionAttr)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetMonitorActionAttr	已经删除的CSysNetMonitorActionAttr
	virtual void commitRemove(CWriteableSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorActionAttrFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrIterator是一个对监控动作指标对照表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrIterator
{
public:
	///构造方法
	CSysNetMonitorActionAttrIterator(void)
	{
	}

	///构造方法
	CSysNetMonitorActionAttrIterator(CSysNetMonitorActionAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorActionAttrIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetMonitorActionAttr
	///@return	下一个满足条件CSysNetMonitorActionAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorActionAttr *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetMonitorActionAttrFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorActionAttr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionAttr * pSysNetMonitorActionAttr,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetMonitorActionAttrFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetModule是一个存储模块的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetModule
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
		if (! ID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! MonitorType_ID.isValid())
			return 0;
		if (! DeviceID.isValid())
			return 0;
		if (! DeviceObjectID.isValid())
			return 0;
		if (! Name.isValid())
			return 0;
		if (! Description.isValid())
			return 0;
		if (! ModuleIndex.isValid())
			return 0;
		if (! EntPhyIndex.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetModule *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///网络监控对象ID
	CNetObjectIDType ObjectID;
	///监控对象类型
	CVolumeType MonitorType_ID;
	///所属设备ID
	CVolumeType DeviceID;
	///所属设备ObjectID
	CNetObjectIDType DeviceObjectID;
	///名字
	CTypeObjectIDType Name;
	///描述
	CNetObjectIDType Description;
	///模块索引
	CVolumeType ModuleIndex;
	///物理索引
	CVolumeType EntPhyIndex;
	
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

typedef const CWriteableSysNetModule CSysNetModule;

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleActionTrigger是操作模块时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleActionTrigger
{
public:
	///构造方法
	CSysNetModuleActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetModuleActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetModuleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetModule	要加入的SysNetModule
	virtual void beforeAdd(CWriteableSysNetModule *pSysNetModule)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetModule	已经加入的SysNetModule
	virtual void afterAdd(CSysNetModule *pSysNetModule)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetModule	被刷新的CSysNetModule
	///@param	pNewSysNetModule	新的值
	virtual void beforeUpdate(CSysNetModule *pSysNetModule, CWriteableSysNetModule *pNewSysNetModule)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetModule	被刷新的CSysNetModule
	virtual void afterUpdate(CSysNetModule *pSysNetModule)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetModule	要删除的CSysNetModule
	virtual void beforeRemove(CSysNetModule *pSysNetModule)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetModuleFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleCommitTrigger是确认模块时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleCommitTrigger
{
public:
	///构造方法
	CSysNetModuleCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetModuleCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetModuleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetModule	已经加入的SysNetModule
	virtual void commitAdd(CSysNetModule *pSysNetModule)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetModule	被刷新的CSysNetModule
	///@param	poldSysNetModule	原来的值
	virtual void commitUpdate(CSysNetModule *pSysNetModule, CWriteableSysNetModule *pOldSysNetModule)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetModule	已经删除的CSysNetModule
	virtual void commitRemove(CWriteableSysNetModule *pSysNetModule)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetModuleFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleIterator是一个对模块的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleIterator
{
public:
	///构造方法
	CSysNetModuleIterator(void)
	{
	}

	///构造方法
	CSysNetModuleIterator(CSysNetModuleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetModuleIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetModule
	///@return	下一个满足条件CSysNetModule，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetModule *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetModuleFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetModule 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetModule * pSysNetModule,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetModuleFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetEventExpr是一个存储告警表达式信息表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetEventExpr
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
		if (! ID.isValid())
			return 0;
		if (! CNAME.isValid())
			return 0;
		if (! ENAME.isValid())
			return 0;
		if (! WarningLEVEL.isValid())
			return 0;
		if (! EventTypeID.isValid())
			return 0;
		if (! SubEventTypeID.isValid())
			return 0;
		if (! GIVEUPTIME.isValid())
			return 0;
		if (! CONTROL.isValid())
			return 0;
		if (! EXPR.isValid())
			return 0;
		if (! BRIEF.isValid())
			return 0;
		if (! DISCRIPTION.isValid())
			return 0;
		if (! MSGGROUP_ID.isValid())
			return 0;
		if (! ADMINGROUP_ID.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetEventExpr *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///中文事件名
	CNetObjectIDType CNAME;
	///英文事件名
	CNetObjectIDType ENAME;
	///事件级别
	CCfgNameType WarningLEVEL;
	///事件类型
	CVolumeType EventTypeID;
	///事件子类型
	CVolumeType SubEventTypeID;
	///告警间隔时间
	CVolumeType GIVEUPTIME;
	///控制定义项
	CGeneralResultType CONTROL;
	///表达式定义项
	CGeneralResultType EXPR;
	///事件简述
	CTypeObjectIDType BRIEF;
	///事件描述项
	CNetAttrTypeType DISCRIPTION;
	///消息组ID
	CVolumeType MSGGROUP_ID;
	///管理员组ID
	CVolumeType ADMINGROUP_ID;
	
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

typedef const CWriteableSysNetEventExpr CSysNetEventExpr;

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprActionTrigger是操作告警表达式信息表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprActionTrigger
{
public:
	///构造方法
	CSysNetEventExprActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetEventExprActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetEventExprFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetEventExpr	要加入的SysNetEventExpr
	virtual void beforeAdd(CWriteableSysNetEventExpr *pSysNetEventExpr)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetEventExpr	已经加入的SysNetEventExpr
	virtual void afterAdd(CSysNetEventExpr *pSysNetEventExpr)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetEventExpr	被刷新的CSysNetEventExpr
	///@param	pNewSysNetEventExpr	新的值
	virtual void beforeUpdate(CSysNetEventExpr *pSysNetEventExpr, CWriteableSysNetEventExpr *pNewSysNetEventExpr)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetEventExpr	被刷新的CSysNetEventExpr
	virtual void afterUpdate(CSysNetEventExpr *pSysNetEventExpr)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetEventExpr	要删除的CSysNetEventExpr
	virtual void beforeRemove(CSysNetEventExpr *pSysNetEventExpr)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetEventExprFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprCommitTrigger是确认告警表达式信息表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprCommitTrigger
{
public:
	///构造方法
	CSysNetEventExprCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetEventExprCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetEventExprFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetEventExpr	已经加入的SysNetEventExpr
	virtual void commitAdd(CSysNetEventExpr *pSysNetEventExpr)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetEventExpr	被刷新的CSysNetEventExpr
	///@param	poldSysNetEventExpr	原来的值
	virtual void commitUpdate(CSysNetEventExpr *pSysNetEventExpr, CWriteableSysNetEventExpr *pOldSysNetEventExpr)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetEventExpr	已经删除的CSysNetEventExpr
	virtual void commitRemove(CWriteableSysNetEventExpr *pSysNetEventExpr)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetEventExprFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprIterator是一个对告警表达式信息表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprIterator
{
public:
	///构造方法
	CSysNetEventExprIterator(void)
	{
	}

	///构造方法
	CSysNetEventExprIterator(CSysNetEventExprFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetEventExprIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetEventExpr
	///@return	下一个满足条件CSysNetEventExpr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetEventExpr *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetEventExprFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetEventExpr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetEventExpr * pSysNetEventExpr,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetEventExprFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetEventType是一个存储事件类型的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetEventType
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetEventType *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///事件类型中文名
	CTypeObjectIDType CName;
	///事件类型英文名
	CTypeObjectIDType EName;
	
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

typedef const CWriteableSysNetEventType CSysNetEventType;

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeActionTrigger是操作事件类型时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeActionTrigger
{
public:
	///构造方法
	CSysNetEventTypeActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetEventTypeActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetEventTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetEventType	要加入的SysNetEventType
	virtual void beforeAdd(CWriteableSysNetEventType *pSysNetEventType)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetEventType	已经加入的SysNetEventType
	virtual void afterAdd(CSysNetEventType *pSysNetEventType)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetEventType	被刷新的CSysNetEventType
	///@param	pNewSysNetEventType	新的值
	virtual void beforeUpdate(CSysNetEventType *pSysNetEventType, CWriteableSysNetEventType *pNewSysNetEventType)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetEventType	被刷新的CSysNetEventType
	virtual void afterUpdate(CSysNetEventType *pSysNetEventType)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetEventType	要删除的CSysNetEventType
	virtual void beforeRemove(CSysNetEventType *pSysNetEventType)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetEventTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeCommitTrigger是确认事件类型时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeCommitTrigger
{
public:
	///构造方法
	CSysNetEventTypeCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetEventTypeCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetEventTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetEventType	已经加入的SysNetEventType
	virtual void commitAdd(CSysNetEventType *pSysNetEventType)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetEventType	被刷新的CSysNetEventType
	///@param	poldSysNetEventType	原来的值
	virtual void commitUpdate(CSysNetEventType *pSysNetEventType, CWriteableSysNetEventType *pOldSysNetEventType)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetEventType	已经删除的CSysNetEventType
	virtual void commitRemove(CWriteableSysNetEventType *pSysNetEventType)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetEventTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeIterator是一个对事件类型的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeIterator
{
public:
	///构造方法
	CSysNetEventTypeIterator(void)
	{
	}

	///构造方法
	CSysNetEventTypeIterator(CSysNetEventTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetEventTypeIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetEventType
	///@return	下一个满足条件CSysNetEventType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetEventType *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetEventTypeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetEventType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetEventType * pSysNetEventType,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetEventTypeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetSubEventType是一个存储事件子类型的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetSubEventType
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetSubEventType *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///事件子类型中文名
	CTypeObjectIDType CName;
	///事件子类型英文名
	CTypeObjectIDType EName;
	
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

typedef const CWriteableSysNetSubEventType CSysNetSubEventType;

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeActionTrigger是操作事件子类型时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeActionTrigger
{
public:
	///构造方法
	CSysNetSubEventTypeActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetSubEventTypeActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetSubEventTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetSubEventType	要加入的SysNetSubEventType
	virtual void beforeAdd(CWriteableSysNetSubEventType *pSysNetSubEventType)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetSubEventType	已经加入的SysNetSubEventType
	virtual void afterAdd(CSysNetSubEventType *pSysNetSubEventType)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetSubEventType	被刷新的CSysNetSubEventType
	///@param	pNewSysNetSubEventType	新的值
	virtual void beforeUpdate(CSysNetSubEventType *pSysNetSubEventType, CWriteableSysNetSubEventType *pNewSysNetSubEventType)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetSubEventType	被刷新的CSysNetSubEventType
	virtual void afterUpdate(CSysNetSubEventType *pSysNetSubEventType)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetSubEventType	要删除的CSysNetSubEventType
	virtual void beforeRemove(CSysNetSubEventType *pSysNetSubEventType)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetSubEventTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeCommitTrigger是确认事件子类型时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeCommitTrigger
{
public:
	///构造方法
	CSysNetSubEventTypeCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetSubEventTypeCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetSubEventTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetSubEventType	已经加入的SysNetSubEventType
	virtual void commitAdd(CSysNetSubEventType *pSysNetSubEventType)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetSubEventType	被刷新的CSysNetSubEventType
	///@param	poldSysNetSubEventType	原来的值
	virtual void commitUpdate(CSysNetSubEventType *pSysNetSubEventType, CWriteableSysNetSubEventType *pOldSysNetSubEventType)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetSubEventType	已经删除的CSysNetSubEventType
	virtual void commitRemove(CWriteableSysNetSubEventType *pSysNetSubEventType)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetSubEventTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeIterator是一个对事件子类型的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeIterator
{
public:
	///构造方法
	CSysNetSubEventTypeIterator(void)
	{
	}

	///构造方法
	CSysNetSubEventTypeIterator(CSysNetSubEventTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetSubEventTypeIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetSubEventType
	///@return	下一个满足条件CSysNetSubEventType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetSubEventType *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetSubEventTypeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetSubEventType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetSubEventType * pSysNetSubEventType,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetSubEventTypeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetEventLevel是一个存储事件级别的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetEventLevel
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! DISCRIPTION.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetEventLevel *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///事件级别中文名
	CTypeObjectIDType CName;
	///事件级别英文名
	CTypeObjectIDType EName;
	///事件级别描述项
	CNetAttrTypeType DISCRIPTION;
	
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

typedef const CWriteableSysNetEventLevel CSysNetEventLevel;

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelActionTrigger是操作事件级别时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelActionTrigger
{
public:
	///构造方法
	CSysNetEventLevelActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetEventLevelActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetEventLevelFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetEventLevel	要加入的SysNetEventLevel
	virtual void beforeAdd(CWriteableSysNetEventLevel *pSysNetEventLevel)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetEventLevel	已经加入的SysNetEventLevel
	virtual void afterAdd(CSysNetEventLevel *pSysNetEventLevel)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetEventLevel	被刷新的CSysNetEventLevel
	///@param	pNewSysNetEventLevel	新的值
	virtual void beforeUpdate(CSysNetEventLevel *pSysNetEventLevel, CWriteableSysNetEventLevel *pNewSysNetEventLevel)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetEventLevel	被刷新的CSysNetEventLevel
	virtual void afterUpdate(CSysNetEventLevel *pSysNetEventLevel)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetEventLevel	要删除的CSysNetEventLevel
	virtual void beforeRemove(CSysNetEventLevel *pSysNetEventLevel)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetEventLevelFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelCommitTrigger是确认事件级别时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelCommitTrigger
{
public:
	///构造方法
	CSysNetEventLevelCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetEventLevelCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetEventLevelFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetEventLevel	已经加入的SysNetEventLevel
	virtual void commitAdd(CSysNetEventLevel *pSysNetEventLevel)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetEventLevel	被刷新的CSysNetEventLevel
	///@param	poldSysNetEventLevel	原来的值
	virtual void commitUpdate(CSysNetEventLevel *pSysNetEventLevel, CWriteableSysNetEventLevel *pOldSysNetEventLevel)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetEventLevel	已经删除的CSysNetEventLevel
	virtual void commitRemove(CWriteableSysNetEventLevel *pSysNetEventLevel)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetEventLevelFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelIterator是一个对事件级别的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelIterator
{
public:
	///构造方法
	CSysNetEventLevelIterator(void)
	{
	}

	///构造方法
	CSysNetEventLevelIterator(CSysNetEventLevelFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetEventLevelIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetEventLevel
	///@return	下一个满足条件CSysNetEventLevel，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetEventLevel *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetEventLevelFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetEventLevel 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetEventLevel * pSysNetEventLevel,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetEventLevelFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorDeviceTask是一个存储任务结果规则分析表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorDeviceTask
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
		if (! ID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! Manufactory_ID.isValid())
			return 0;
		if (! InstructChain.isValid())
			return 0;
		if (! InstructAlias.isValid())
			return 0;
		if (! InstructArgs.isValid())
			return 0;
		if (! DefParamChain.isValid())
			return 0;
		if (! Flag.isValid())
			return 0;
		if (! SecondID.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorDeviceTask *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///网络监控对象ID
	CNetObjectIDType ObjectID;
	///IP地址
	CIPAddressType IPAddress;
	///网络设备产商ID
	CVolumeType Manufactory_ID;
	///指令
	CNetString256Type InstructChain;
	///指令别名
	CNetString128Type InstructAlias;
	///指令参数串
	CNetString256Type InstructArgs;
	///指标阀值串
	CNetString2KType DefParamChain;
	///结束标志
	CVolumeType Flag;
	///PrimID
	CVolumeType SecondID;
	
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

typedef const CWriteableSysNetMonitorDeviceTask CSysNetMonitorDeviceTask;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskActionTrigger是操作任务结果规则分析表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskActionTrigger
{
public:
	///构造方法
	CSysNetMonitorDeviceTaskActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorDeviceTaskActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorDeviceTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetMonitorDeviceTask	要加入的SysNetMonitorDeviceTask
	virtual void beforeAdd(CWriteableSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetMonitorDeviceTask	已经加入的SysNetMonitorDeviceTask
	virtual void afterAdd(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetMonitorDeviceTask	被刷新的CSysNetMonitorDeviceTask
	///@param	pNewSysNetMonitorDeviceTask	新的值
	virtual void beforeUpdate(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, CWriteableSysNetMonitorDeviceTask *pNewSysNetMonitorDeviceTask)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetMonitorDeviceTask	被刷新的CSysNetMonitorDeviceTask
	virtual void afterUpdate(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetMonitorDeviceTask	要删除的CSysNetMonitorDeviceTask
	virtual void beforeRemove(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorDeviceTaskFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskCommitTrigger是确认任务结果规则分析表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskCommitTrigger
{
public:
	///构造方法
	CSysNetMonitorDeviceTaskCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorDeviceTaskCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorDeviceTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetMonitorDeviceTask	已经加入的SysNetMonitorDeviceTask
	virtual void commitAdd(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetMonitorDeviceTask	被刷新的CSysNetMonitorDeviceTask
	///@param	poldSysNetMonitorDeviceTask	原来的值
	virtual void commitUpdate(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, CWriteableSysNetMonitorDeviceTask *pOldSysNetMonitorDeviceTask)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetMonitorDeviceTask	已经删除的CSysNetMonitorDeviceTask
	virtual void commitRemove(CWriteableSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorDeviceTaskFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskIterator是一个对任务结果规则分析表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskIterator
{
public:
	///构造方法
	CSysNetMonitorDeviceTaskIterator(void)
	{
	}

	///构造方法
	CSysNetMonitorDeviceTaskIterator(CSysNetMonitorDeviceTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorDeviceTaskIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetMonitorDeviceTask
	///@return	下一个满足条件CSysNetMonitorDeviceTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorDeviceTask *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetMonitorDeviceTaskFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorDeviceTask 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetMonitorDeviceTaskFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorTaskInstAttrs是一个存储任务指令指标集表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorTaskInstAttrs
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
		if (! ID.isValid())
			return 0;
		if (! Manufactory_ID.isValid())
			return 0;
		if (! InstructAlias.isValid())
			return 0;
		if (! DEVICETYPE.isValid())
			return 0;
		if (! AttrsChain.isValid())
			return 0;
		if (! DefRegularChain.isValid())
			return 0;
		if (! DefParamChain.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorTaskInstAttrs *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///网络设备产商ID
	CVolumeType Manufactory_ID;
	///指令别名
	CNetString128Type InstructAlias;
	///设备型号
	CNetString128Type DEVICETYPE;
	///指标串
	CNetString256Type AttrsChain;
	///指标规则串
	CNetString512Type DefRegularChain;
	///指标阀值串
	CNetString2KType DefParamChain;
	
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

typedef const CWriteableSysNetMonitorTaskInstAttrs CSysNetMonitorTaskInstAttrs;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsActionTrigger是操作任务指令指标集表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsActionTrigger
{
public:
	///构造方法
	CSysNetMonitorTaskInstAttrsActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorTaskInstAttrsActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorTaskInstAttrsFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetMonitorTaskInstAttrs	要加入的SysNetMonitorTaskInstAttrs
	virtual void beforeAdd(CWriteableSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetMonitorTaskInstAttrs	已经加入的SysNetMonitorTaskInstAttrs
	virtual void afterAdd(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetMonitorTaskInstAttrs	被刷新的CSysNetMonitorTaskInstAttrs
	///@param	pNewSysNetMonitorTaskInstAttrs	新的值
	virtual void beforeUpdate(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, CWriteableSysNetMonitorTaskInstAttrs *pNewSysNetMonitorTaskInstAttrs)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetMonitorTaskInstAttrs	被刷新的CSysNetMonitorTaskInstAttrs
	virtual void afterUpdate(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetMonitorTaskInstAttrs	要删除的CSysNetMonitorTaskInstAttrs
	virtual void beforeRemove(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorTaskInstAttrsFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsCommitTrigger是确认任务指令指标集表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsCommitTrigger
{
public:
	///构造方法
	CSysNetMonitorTaskInstAttrsCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMonitorTaskInstAttrsCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMonitorTaskInstAttrsFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetMonitorTaskInstAttrs	已经加入的SysNetMonitorTaskInstAttrs
	virtual void commitAdd(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetMonitorTaskInstAttrs	被刷新的CSysNetMonitorTaskInstAttrs
	///@param	poldSysNetMonitorTaskInstAttrs	原来的值
	virtual void commitUpdate(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, CWriteableSysNetMonitorTaskInstAttrs *pOldSysNetMonitorTaskInstAttrs)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetMonitorTaskInstAttrs	已经删除的CSysNetMonitorTaskInstAttrs
	virtual void commitRemove(CWriteableSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMonitorTaskInstAttrsFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsIterator是一个对任务指令指标集表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsIterator
{
public:
	///构造方法
	CSysNetMonitorTaskInstAttrsIterator(void)
	{
	}

	///构造方法
	CSysNetMonitorTaskInstAttrsIterator(CSysNetMonitorTaskInstAttrsFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskInstAttrsIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetMonitorTaskInstAttrs
	///@return	下一个满足条件CSysNetMonitorTaskInstAttrs，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskInstAttrs *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetMonitorTaskInstAttrsFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorTaskInstAttrs 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetMonitorTaskInstAttrsFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetBaseLine是一个存储基线表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetBaseLine
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
		if (! ID.isValid())
			return 0;
		if (! MANUFACTORY_ID.isValid())
			return 0;
		if (! Name.isValid())
			return 0;
		if (! SerialUsed.isValid())
			return 0;
		if (! data.isValid())
			return 0;
		if (! memo.isValid())
			return 0;
		if (! Flag.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetBaseLine *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///厂商类型
	CVolumeType MANUFACTORY_ID;
	///基线名
	CNetObjectIDType Name;
	///设备型号
	CNetObjectIDType SerialUsed;
	///文件内容
	CbaseCommentType data;
	///备注
	CNetAttrTypeType memo;
	///结束标志
	CVolumeType Flag;
	
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

typedef const CWriteableSysNetBaseLine CSysNetBaseLine;

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineActionTrigger是操作基线表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineActionTrigger
{
public:
	///构造方法
	CSysNetBaseLineActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetBaseLineActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetBaseLineFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetBaseLine	要加入的SysNetBaseLine
	virtual void beforeAdd(CWriteableSysNetBaseLine *pSysNetBaseLine)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetBaseLine	已经加入的SysNetBaseLine
	virtual void afterAdd(CSysNetBaseLine *pSysNetBaseLine)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetBaseLine	被刷新的CSysNetBaseLine
	///@param	pNewSysNetBaseLine	新的值
	virtual void beforeUpdate(CSysNetBaseLine *pSysNetBaseLine, CWriteableSysNetBaseLine *pNewSysNetBaseLine)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetBaseLine	被刷新的CSysNetBaseLine
	virtual void afterUpdate(CSysNetBaseLine *pSysNetBaseLine)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetBaseLine	要删除的CSysNetBaseLine
	virtual void beforeRemove(CSysNetBaseLine *pSysNetBaseLine)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetBaseLineFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineCommitTrigger是确认基线表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineCommitTrigger
{
public:
	///构造方法
	CSysNetBaseLineCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetBaseLineCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetBaseLineFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetBaseLine	已经加入的SysNetBaseLine
	virtual void commitAdd(CSysNetBaseLine *pSysNetBaseLine)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetBaseLine	被刷新的CSysNetBaseLine
	///@param	poldSysNetBaseLine	原来的值
	virtual void commitUpdate(CSysNetBaseLine *pSysNetBaseLine, CWriteableSysNetBaseLine *pOldSysNetBaseLine)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetBaseLine	已经删除的CSysNetBaseLine
	virtual void commitRemove(CWriteableSysNetBaseLine *pSysNetBaseLine)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetBaseLineFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineIterator是一个对基线表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineIterator
{
public:
	///构造方法
	CSysNetBaseLineIterator(void)
	{
	}

	///构造方法
	CSysNetBaseLineIterator(CSysNetBaseLineFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetBaseLineIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetBaseLine
	///@return	下一个满足条件CSysNetBaseLine，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetBaseLine *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetBaseLineFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetBaseLine 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetBaseLine * pSysNetBaseLine,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetBaseLineFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetBaseLineTask是一个存储基线任务表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetBaseLineTask
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
		if (! ID.isValid())
			return 0;
		if (! Name.isValid())
			return 0;
		if (! BaseLineIDList.isValid())
			return 0;
		if (! DeviceIDList.isValid())
			return 0;
		if (! GenDate.isValid())
			return 0;
		if (! GenTime.isValid())
			return 0;
		if (! GenUser.isValid())
			return 0;
		if (! memo.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetBaseLineTask *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///基线任务名
	CNetObjectIDType Name;
	///基线ID列表
	CGeneralResultType BaseLineIDList;
	///设备ID列表
	CGeneralResultType DeviceIDList;
	///生成日期
	CDateType GenDate;
	///生成时间
	CTimeType GenTime;
	///生成者
	CTypeUserNameType GenUser;
	///备注
	CNetAttrTypeType memo;
	
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

typedef const CWriteableSysNetBaseLineTask CSysNetBaseLineTask;

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskActionTrigger是操作基线任务表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskActionTrigger
{
public:
	///构造方法
	CSysNetBaseLineTaskActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetBaseLineTaskActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetBaseLineTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetBaseLineTask	要加入的SysNetBaseLineTask
	virtual void beforeAdd(CWriteableSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetBaseLineTask	已经加入的SysNetBaseLineTask
	virtual void afterAdd(CSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetBaseLineTask	被刷新的CSysNetBaseLineTask
	///@param	pNewSysNetBaseLineTask	新的值
	virtual void beforeUpdate(CSysNetBaseLineTask *pSysNetBaseLineTask, CWriteableSysNetBaseLineTask *pNewSysNetBaseLineTask)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetBaseLineTask	被刷新的CSysNetBaseLineTask
	virtual void afterUpdate(CSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetBaseLineTask	要删除的CSysNetBaseLineTask
	virtual void beforeRemove(CSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetBaseLineTaskFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskCommitTrigger是确认基线任务表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskCommitTrigger
{
public:
	///构造方法
	CSysNetBaseLineTaskCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetBaseLineTaskCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetBaseLineTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetBaseLineTask	已经加入的SysNetBaseLineTask
	virtual void commitAdd(CSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetBaseLineTask	被刷新的CSysNetBaseLineTask
	///@param	poldSysNetBaseLineTask	原来的值
	virtual void commitUpdate(CSysNetBaseLineTask *pSysNetBaseLineTask, CWriteableSysNetBaseLineTask *pOldSysNetBaseLineTask)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetBaseLineTask	已经删除的CSysNetBaseLineTask
	virtual void commitRemove(CWriteableSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetBaseLineTaskFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskIterator是一个对基线任务表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskIterator
{
public:
	///构造方法
	CSysNetBaseLineTaskIterator(void)
	{
	}

	///构造方法
	CSysNetBaseLineTaskIterator(CSysNetBaseLineTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetBaseLineTaskIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetBaseLineTask
	///@return	下一个满足条件CSysNetBaseLineTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetBaseLineTask *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetBaseLineTaskFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetBaseLineTask 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetBaseLineTask * pSysNetBaseLineTask,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetBaseLineTaskFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbNetPartyLinkStatusInfo是一个存储会员链路状态信息表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbNetPartyLinkStatusInfo
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
		if (! SubcriberID.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! SEAT_NO.isValid())
			return 0;
		if (! IPADDR.isValid())
			return 0;
		if (! Interface.isValid())
			return 0;
		if (! status.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbNetPartyLinkStatusInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///订阅对象ID
	CVolumeType SubcriberID;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///席位号
	CCfgNameType SEAT_NO;
	///路由器网管IP
	CTypeObjectIDType IPADDR;
	///路由器端口号
	CTypeObjectIDType Interface;
	///链路状态
	CTypeObjectIDType status;
	
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

typedef const CWriteableSysMdbNetPartyLinkStatusInfo CSysMdbNetPartyLinkStatusInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoActionTrigger是操作会员链路状态信息表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoActionTrigger
{
public:
	///构造方法
	CSysMdbNetPartyLinkStatusInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbNetPartyLinkStatusInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbNetPartyLinkStatusInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMdbNetPartyLinkStatusInfo	要加入的SysMdbNetPartyLinkStatusInfo
	virtual void beforeAdd(CWriteableSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMdbNetPartyLinkStatusInfo	已经加入的SysMdbNetPartyLinkStatusInfo
	virtual void afterAdd(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMdbNetPartyLinkStatusInfo	被刷新的CSysMdbNetPartyLinkStatusInfo
	///@param	pNewSysMdbNetPartyLinkStatusInfo	新的值
	virtual void beforeUpdate(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, CWriteableSysMdbNetPartyLinkStatusInfo *pNewSysMdbNetPartyLinkStatusInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMdbNetPartyLinkStatusInfo	被刷新的CSysMdbNetPartyLinkStatusInfo
	virtual void afterUpdate(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMdbNetPartyLinkStatusInfo	要删除的CSysMdbNetPartyLinkStatusInfo
	virtual void beforeRemove(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbNetPartyLinkStatusInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoCommitTrigger是确认会员链路状态信息表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoCommitTrigger
{
public:
	///构造方法
	CSysMdbNetPartyLinkStatusInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbNetPartyLinkStatusInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbNetPartyLinkStatusInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMdbNetPartyLinkStatusInfo	已经加入的SysMdbNetPartyLinkStatusInfo
	virtual void commitAdd(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysMdbNetPartyLinkStatusInfo	被刷新的CSysMdbNetPartyLinkStatusInfo
	///@param	poldSysMdbNetPartyLinkStatusInfo	原来的值
	virtual void commitUpdate(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, CWriteableSysMdbNetPartyLinkStatusInfo *pOldSysMdbNetPartyLinkStatusInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMdbNetPartyLinkStatusInfo	已经删除的CSysMdbNetPartyLinkStatusInfo
	virtual void commitRemove(CWriteableSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbNetPartyLinkStatusInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoIterator是一个对会员链路状态信息表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoIterator
{
public:
	///构造方法
	CSysMdbNetPartyLinkStatusInfoIterator(void)
	{
	}

	///构造方法
	CSysMdbNetPartyLinkStatusInfoIterator(CSysMdbNetPartyLinkStatusInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbNetPartyLinkStatusInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMdbNetPartyLinkStatusInfo
	///@return	下一个满足条件CSysMdbNetPartyLinkStatusInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbNetPartyLinkStatusInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMdbNetPartyLinkStatusInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbNetPartyLinkStatusInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMdbNetPartyLinkStatusInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMemberSDHLineInfo是一个存储会员SDH线路明细表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMemberSDHLineInfo
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
		if (! ID.isValid())
			return 0;
		if (! SeqNo.isValid())
			return 0;
		if (! MemContractNo.isValid())
			return 0;
		if (! ApplyPerson.isValid())
			return 0;
		if (! MonthlyRental.isValid())
			return 0;
		if (! MemberNo.isValid())
			return 0;
		if (! ParticipantName.isValid())
			return 0;
		if (! ClientManager.isValid())
			return 0;
		if (! Bandwidth.isValid())
			return 0;
		if (! InterfaceType.isValid())
			return 0;
		if (! RemoteCircuit.isValid())
			return 0;
		if (! LocalCircuit.isValid())
			return 0;
		if (! Remark.isValid())
			return 0;
		if (! EndALineAddress.isValid())
			return 0;
		if (! EndAContact.isValid())
			return 0;
		if (! EndZLineAddress.isValid())
			return 0;
		if (! ContactName.isValid())
			return 0;
		if (! TELEPHONE.isValid())
			return 0;
		if (! MOBILEPHONE.isValid())
			return 0;
		if (! IPADDR.isValid())
			return 0;
		if (! Interface.isValid())
			return 0;
		if (! PROVINCE.isValid())
			return 0;
		if (! StartPortID.isValid())
			return 0;
		if (! StartJump.isValid())
			return 0;
		if (! LINE_STATUS.isValid())
			return 0;
		if (! DataCenterID.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMemberSDHLineInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///序列号
	CVolumeType SeqNo;
	///合同号
	CContractSeqNoType MemContractNo;
	///申请人
	CApplyPersonType ApplyPerson;
	///月租费用
	CLongVolumeType MonthlyRental;
	///会员号
	CPartyIDType MemberNo;
	///会员名称
	CParticipantNameType ParticipantName;
	///客户经理
	CNetString128Type ClientManager;
	///带宽
	CNetString128Type Bandwidth;
	///接口类
	CNetString128Type InterfaceType;
	///长途电路编码
	CNetString128Type RemoteCircuit;
	///本地电路编码
	CNetString128Type LocalCircuit;
	///备注
	CNetString128Type Remark;
	///A端接入地址
	CNetString512Type EndALineAddress;
	///A端联系人
	CNetString128Type EndAContact;
	///Z端接入地址
	CNetString512Type EndZLineAddress;
	///联系人
	CIndividualNameType ContactName;
	///联系电话
	CTypeObjectIDType TELEPHONE;
	///手机号
	CTypeObjectIDType MOBILEPHONE;
	///路由器网管IP
	CTypeObjectIDType IPADDR;
	///路由器端口号
	CTypeObjectIDType Interface;
	///所属省份
	CCfgNameType PROVINCE;
	///起始设备端口
	CNetString256Type StartPortID;
	///起始设备跳接端
	CNetString128Type StartJump;
	///线路状态
	CCfgNameType LINE_STATUS;
	///数据中心代码
	CDataCenterIDType DataCenterID;
	
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

typedef const CWriteableSysNetMemberSDHLineInfo CSysNetMemberSDHLineInfo;

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoActionTrigger是操作会员SDH线路明细表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoActionTrigger
{
public:
	///构造方法
	CSysNetMemberSDHLineInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMemberSDHLineInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMemberSDHLineInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetMemberSDHLineInfo	要加入的SysNetMemberSDHLineInfo
	virtual void beforeAdd(CWriteableSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetMemberSDHLineInfo	已经加入的SysNetMemberSDHLineInfo
	virtual void afterAdd(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetMemberSDHLineInfo	被刷新的CSysNetMemberSDHLineInfo
	///@param	pNewSysNetMemberSDHLineInfo	新的值
	virtual void beforeUpdate(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, CWriteableSysNetMemberSDHLineInfo *pNewSysNetMemberSDHLineInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetMemberSDHLineInfo	被刷新的CSysNetMemberSDHLineInfo
	virtual void afterUpdate(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetMemberSDHLineInfo	要删除的CSysNetMemberSDHLineInfo
	virtual void beforeRemove(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMemberSDHLineInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoCommitTrigger是确认会员SDH线路明细表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoCommitTrigger
{
public:
	///构造方法
	CSysNetMemberSDHLineInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetMemberSDHLineInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetMemberSDHLineInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetMemberSDHLineInfo	已经加入的SysNetMemberSDHLineInfo
	virtual void commitAdd(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetMemberSDHLineInfo	被刷新的CSysNetMemberSDHLineInfo
	///@param	poldSysNetMemberSDHLineInfo	原来的值
	virtual void commitUpdate(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, CWriteableSysNetMemberSDHLineInfo *pOldSysNetMemberSDHLineInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetMemberSDHLineInfo	已经删除的CSysNetMemberSDHLineInfo
	virtual void commitRemove(CWriteableSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetMemberSDHLineInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoIterator是一个对会员SDH线路明细表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoIterator
{
public:
	///构造方法
	CSysNetMemberSDHLineInfoIterator(void)
	{
	}

	///构造方法
	CSysNetMemberSDHLineInfoIterator(CSysNetMemberSDHLineInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMemberSDHLineInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetMemberSDHLineInfo
	///@return	下一个满足条件CSysNetMemberSDHLineInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMemberSDHLineInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetMemberSDHLineInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMemberSDHLineInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetMemberSDHLineInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetDDNLinkInfo是一个存储DDN链路信息表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetDDNLinkInfo
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
		if (! ID.isValid())
			return 0;
		if (! ClientName.isValid())
			return 0;
		if (! DDN_NO.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! Bandwidth.isValid())
			return 0;
		if (! EndAAddress.isValid())
			return 0;
		if (! EndAContactName.isValid())
			return 0;
		if (! EndZAddress.isValid())
			return 0;
		if (! EndZContactName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetDDNLinkInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///客户名称
	CPartyNameType ClientName;
	///线路编号
	CTypeObjectIDType DDN_NO;
	///业务单元
	CBusinessUnitType BusinessUnit;
	///速率
	CNetString128Type Bandwidth;
	///甲端地址
	CAddressType EndAAddress;
	///甲端联系人
	CIndividualNameType EndAContactName;
	///乙端地址
	CAddressType EndZAddress;
	///乙端联系人
	CIndividualNameType EndZContactName;
	
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

typedef const CWriteableSysNetDDNLinkInfo CSysNetDDNLinkInfo;

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoActionTrigger是操作DDN链路信息表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoActionTrigger
{
public:
	///构造方法
	CSysNetDDNLinkInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetDDNLinkInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetDDNLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetDDNLinkInfo	要加入的SysNetDDNLinkInfo
	virtual void beforeAdd(CWriteableSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetDDNLinkInfo	已经加入的SysNetDDNLinkInfo
	virtual void afterAdd(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetDDNLinkInfo	被刷新的CSysNetDDNLinkInfo
	///@param	pNewSysNetDDNLinkInfo	新的值
	virtual void beforeUpdate(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo, CWriteableSysNetDDNLinkInfo *pNewSysNetDDNLinkInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetDDNLinkInfo	被刷新的CSysNetDDNLinkInfo
	virtual void afterUpdate(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetDDNLinkInfo	要删除的CSysNetDDNLinkInfo
	virtual void beforeRemove(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetDDNLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoCommitTrigger是确认DDN链路信息表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoCommitTrigger
{
public:
	///构造方法
	CSysNetDDNLinkInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetDDNLinkInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetDDNLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetDDNLinkInfo	已经加入的SysNetDDNLinkInfo
	virtual void commitAdd(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetDDNLinkInfo	被刷新的CSysNetDDNLinkInfo
	///@param	poldSysNetDDNLinkInfo	原来的值
	virtual void commitUpdate(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo, CWriteableSysNetDDNLinkInfo *pOldSysNetDDNLinkInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetDDNLinkInfo	已经删除的CSysNetDDNLinkInfo
	virtual void commitRemove(CWriteableSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetDDNLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoIterator是一个对DDN链路信息表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoIterator
{
public:
	///构造方法
	CSysNetDDNLinkInfoIterator(void)
	{
	}

	///构造方法
	CSysNetDDNLinkInfoIterator(CSysNetDDNLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDDNLinkInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetDDNLinkInfo
	///@return	下一个满足条件CSysNetDDNLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDDNLinkInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetDDNLinkInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDDNLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDDNLinkInfo * pSysNetDDNLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetDDNLinkInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetPseudMemberLinkInfo是一个存储非会员线路使用信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetPseudMemberLinkInfo
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
		if (! ID.isValid())
			return 0;
		if (! SeqNo.isValid())
			return 0;
		if (! MemContractNo.isValid())
			return 0;
		if (! LineUsage.isValid())
			return 0;
		if (! LocalCircuit.isValid())
			return 0;
		if (! RemoteCircuit.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! Bandwidth.isValid())
			return 0;
		if (! ApplyPerson.isValid())
			return 0;
		if (! MonthlyRental.isValid())
			return 0;
		if (! EndAAddress.isValid())
			return 0;
		if (! EndAContactName.isValid())
			return 0;
		if (! EndZAddress.isValid())
			return 0;
		if (! EndZContactName.isValid())
			return 0;
		if (! Telephone.isValid())
			return 0;
		if (! LineInfo.isValid())
			return 0;
		if (! IPADDR.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetPseudMemberLinkInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///序列号
	CVolumeType SeqNo;
	///合同号
	CContractSeqNoType MemContractNo;
	///线路用途
	CNetString128Type LineUsage;
	///本地电路编码
	CNetString128Type LocalCircuit;
	///长途电路编码
	CNetString128Type RemoteCircuit;
	///业务
	CBusinessUnitType BusinessUnit;
	///速率
	CNetString128Type Bandwidth;
	///申请人
	CApplyPersonType ApplyPerson;
	///月租费用
	CLongVolumeType MonthlyRental;
	///甲端地址
	CAddressType EndAAddress;
	///甲端联系人
	CIndividualNameType EndAContactName;
	///乙端地址
	CAddressType EndZAddress;
	///乙端联系人
	CIndividualNameType EndZContactName;
	///乙端电话号码
	CTelephoneType Telephone;
	///线路信息
	CTypeObjectIDType LineInfo;
	///路由器网管IP
	CTypeObjectIDType IPADDR;
	
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

typedef const CWriteableSysNetPseudMemberLinkInfo CSysNetPseudMemberLinkInfo;

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoActionTrigger是操作非会员线路使用信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoActionTrigger
{
public:
	///构造方法
	CSysNetPseudMemberLinkInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetPseudMemberLinkInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetPseudMemberLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetPseudMemberLinkInfo	要加入的SysNetPseudMemberLinkInfo
	virtual void beforeAdd(CWriteableSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetPseudMemberLinkInfo	已经加入的SysNetPseudMemberLinkInfo
	virtual void afterAdd(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetPseudMemberLinkInfo	被刷新的CSysNetPseudMemberLinkInfo
	///@param	pNewSysNetPseudMemberLinkInfo	新的值
	virtual void beforeUpdate(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, CWriteableSysNetPseudMemberLinkInfo *pNewSysNetPseudMemberLinkInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetPseudMemberLinkInfo	被刷新的CSysNetPseudMemberLinkInfo
	virtual void afterUpdate(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetPseudMemberLinkInfo	要删除的CSysNetPseudMemberLinkInfo
	virtual void beforeRemove(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetPseudMemberLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoCommitTrigger是确认非会员线路使用信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoCommitTrigger
{
public:
	///构造方法
	CSysNetPseudMemberLinkInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetPseudMemberLinkInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetPseudMemberLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetPseudMemberLinkInfo	已经加入的SysNetPseudMemberLinkInfo
	virtual void commitAdd(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetPseudMemberLinkInfo	被刷新的CSysNetPseudMemberLinkInfo
	///@param	poldSysNetPseudMemberLinkInfo	原来的值
	virtual void commitUpdate(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, CWriteableSysNetPseudMemberLinkInfo *pOldSysNetPseudMemberLinkInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetPseudMemberLinkInfo	已经删除的CSysNetPseudMemberLinkInfo
	virtual void commitRemove(CWriteableSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetPseudMemberLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoIterator是一个对非会员线路使用信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoIterator
{
public:
	///构造方法
	CSysNetPseudMemberLinkInfoIterator(void)
	{
	}

	///构造方法
	CSysNetPseudMemberLinkInfoIterator(CSysNetPseudMemberLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPseudMemberLinkInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetPseudMemberLinkInfo
	///@return	下一个满足条件CSysNetPseudMemberLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPseudMemberLinkInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetPseudMemberLinkInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPseudMemberLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetPseudMemberLinkInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetOuterDeviceInfo是一个存储远端设备信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetOuterDeviceInfo
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
		if (! ID.isValid())
			return 0;
		if (! IPADDR.isValid())
			return 0;
		if (! NAME.isValid())
			return 0;
		if (! memo.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetOuterDeviceInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///IP地址  
	CIPAddressType IPADDR;
	///设备名称 
	CNetObjectIDType NAME;
	///备注
	CNetAttrTypeType memo;
	
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

typedef const CWriteableSysNetOuterDeviceInfo CSysNetOuterDeviceInfo;

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoActionTrigger是操作远端设备信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoActionTrigger
{
public:
	///构造方法
	CSysNetOuterDeviceInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetOuterDeviceInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetOuterDeviceInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetOuterDeviceInfo	要加入的SysNetOuterDeviceInfo
	virtual void beforeAdd(CWriteableSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetOuterDeviceInfo	已经加入的SysNetOuterDeviceInfo
	virtual void afterAdd(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetOuterDeviceInfo	被刷新的CSysNetOuterDeviceInfo
	///@param	pNewSysNetOuterDeviceInfo	新的值
	virtual void beforeUpdate(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, CWriteableSysNetOuterDeviceInfo *pNewSysNetOuterDeviceInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetOuterDeviceInfo	被刷新的CSysNetOuterDeviceInfo
	virtual void afterUpdate(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetOuterDeviceInfo	要删除的CSysNetOuterDeviceInfo
	virtual void beforeRemove(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetOuterDeviceInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoCommitTrigger是确认远端设备信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoCommitTrigger
{
public:
	///构造方法
	CSysNetOuterDeviceInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetOuterDeviceInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetOuterDeviceInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetOuterDeviceInfo	已经加入的SysNetOuterDeviceInfo
	virtual void commitAdd(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetOuterDeviceInfo	被刷新的CSysNetOuterDeviceInfo
	///@param	poldSysNetOuterDeviceInfo	原来的值
	virtual void commitUpdate(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, CWriteableSysNetOuterDeviceInfo *pOldSysNetOuterDeviceInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetOuterDeviceInfo	已经删除的CSysNetOuterDeviceInfo
	virtual void commitRemove(CWriteableSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetOuterDeviceInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoIterator是一个对远端设备信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoIterator
{
public:
	///构造方法
	CSysNetOuterDeviceInfoIterator(void)
	{
	}

	///构造方法
	CSysNetOuterDeviceInfoIterator(CSysNetOuterDeviceInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetOuterDeviceInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetOuterDeviceInfo
	///@return	下一个满足条件CSysNetOuterDeviceInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetOuterDeviceInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetOuterDeviceInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetOuterDeviceInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetOuterDeviceInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysLocalPingResultInfo是一个存储本地ping结果的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysLocalPingResultInfo
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
		if (! ID.isValid())
			return 0;
		if (! SouIPADDR.isValid())
			return 0;
		if (! SouNAME.isValid())
			return 0;
		if (! TarIPADDR.isValid())
			return 0;
		if (! TarNAME.isValid())
			return 0;
		if (! PDateSta.isValid())
			return 0;
		if (! PTimeSta.isValid())
			return 0;
		if (! ConnRate.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysLocalPingResultInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///源IP地址  
	CIPAddressType SouIPADDR;
	///源设备名称 
	CNetObjectIDType SouNAME;
	///目的IP地址  
	CIPAddressType TarIPADDR;
	///目的设备名称 
	CNetObjectIDType TarNAME;
	///生成日期
	CDateType PDateSta;
	///时间戳
	CTimeType PTimeSta;
	///连通率
	CVolumeType ConnRate;
	
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

typedef const CWriteableSysLocalPingResultInfo CSysLocalPingResultInfo;

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoActionTrigger是操作本地ping结果时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoActionTrigger
{
public:
	///构造方法
	CSysLocalPingResultInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysLocalPingResultInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysLocalPingResultInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysLocalPingResultInfo	要加入的SysLocalPingResultInfo
	virtual void beforeAdd(CWriteableSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysLocalPingResultInfo	已经加入的SysLocalPingResultInfo
	virtual void afterAdd(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysLocalPingResultInfo	被刷新的CSysLocalPingResultInfo
	///@param	pNewSysLocalPingResultInfo	新的值
	virtual void beforeUpdate(CSysLocalPingResultInfo *pSysLocalPingResultInfo, CWriteableSysLocalPingResultInfo *pNewSysLocalPingResultInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysLocalPingResultInfo	被刷新的CSysLocalPingResultInfo
	virtual void afterUpdate(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysLocalPingResultInfo	要删除的CSysLocalPingResultInfo
	virtual void beforeRemove(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysLocalPingResultInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoCommitTrigger是确认本地ping结果时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoCommitTrigger
{
public:
	///构造方法
	CSysLocalPingResultInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysLocalPingResultInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysLocalPingResultInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysLocalPingResultInfo	已经加入的SysLocalPingResultInfo
	virtual void commitAdd(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysLocalPingResultInfo	被刷新的CSysLocalPingResultInfo
	///@param	poldSysLocalPingResultInfo	原来的值
	virtual void commitUpdate(CSysLocalPingResultInfo *pSysLocalPingResultInfo, CWriteableSysLocalPingResultInfo *pOldSysLocalPingResultInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysLocalPingResultInfo	已经删除的CSysLocalPingResultInfo
	virtual void commitRemove(CWriteableSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysLocalPingResultInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoIterator是一个对本地ping结果的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoIterator
{
public:
	///构造方法
	CSysLocalPingResultInfoIterator(void)
	{
	}

	///构造方法
	CSysLocalPingResultInfoIterator(CSysLocalPingResultInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysLocalPingResultInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysLocalPingResultInfo
	///@return	下一个满足条件CSysLocalPingResultInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysLocalPingResultInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysLocalPingResultInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysLocalPingResultInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysLocalPingResultInfo * pSysLocalPingResultInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysLocalPingResultInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysRomotePingResultInfo是一个存储远程ping结果的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysRomotePingResultInfo
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
		if (! ID.isValid())
			return 0;
		if (! SouIPADDR.isValid())
			return 0;
		if (! SouNAME.isValid())
			return 0;
		if (! TarIPADDR.isValid())
			return 0;
		if (! TarNAME.isValid())
			return 0;
		if (! PDateSta.isValid())
			return 0;
		if (! PTimeSta.isValid())
			return 0;
		if (! ConnRate.isValid())
			return 0;
		if (! TimeDlyMin.isValid())
			return 0;
		if (! TimeDlyMax.isValid())
			return 0;
		if (! TimeDlyAvg.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysRomotePingResultInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///源IP地址  
	CIPAddressType SouIPADDR;
	///源设备名称 
	CNetObjectIDType SouNAME;
	///目的IP地址  
	CIPAddressType TarIPADDR;
	///目的设备名称 
	CNetObjectIDType TarNAME;
	///生成日期
	CDateType PDateSta;
	///时间戳
	CTimeType PTimeSta;
	///连通率
	CVolumeType ConnRate;
	///最小时延
	CNetString128Type TimeDlyMin;
	///最大时延
	CNetString128Type TimeDlyMax;
	///平均时延
	CNetString128Type TimeDlyAvg;
	
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

typedef const CWriteableSysRomotePingResultInfo CSysRomotePingResultInfo;

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoActionTrigger是操作远程ping结果时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoActionTrigger
{
public:
	///构造方法
	CSysRomotePingResultInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysRomotePingResultInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysRomotePingResultInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysRomotePingResultInfo	要加入的SysRomotePingResultInfo
	virtual void beforeAdd(CWriteableSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysRomotePingResultInfo	已经加入的SysRomotePingResultInfo
	virtual void afterAdd(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysRomotePingResultInfo	被刷新的CSysRomotePingResultInfo
	///@param	pNewSysRomotePingResultInfo	新的值
	virtual void beforeUpdate(CSysRomotePingResultInfo *pSysRomotePingResultInfo, CWriteableSysRomotePingResultInfo *pNewSysRomotePingResultInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysRomotePingResultInfo	被刷新的CSysRomotePingResultInfo
	virtual void afterUpdate(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysRomotePingResultInfo	要删除的CSysRomotePingResultInfo
	virtual void beforeRemove(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysRomotePingResultInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoCommitTrigger是确认远程ping结果时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoCommitTrigger
{
public:
	///构造方法
	CSysRomotePingResultInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysRomotePingResultInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysRomotePingResultInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysRomotePingResultInfo	已经加入的SysRomotePingResultInfo
	virtual void commitAdd(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysRomotePingResultInfo	被刷新的CSysRomotePingResultInfo
	///@param	poldSysRomotePingResultInfo	原来的值
	virtual void commitUpdate(CSysRomotePingResultInfo *pSysRomotePingResultInfo, CWriteableSysRomotePingResultInfo *pOldSysRomotePingResultInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysRomotePingResultInfo	已经删除的CSysRomotePingResultInfo
	virtual void commitRemove(CWriteableSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysRomotePingResultInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoIterator是一个对远程ping结果的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoIterator
{
public:
	///构造方法
	CSysRomotePingResultInfoIterator(void)
	{
	}

	///构造方法
	CSysRomotePingResultInfoIterator(CSysRomotePingResultInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysRomotePingResultInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysRomotePingResultInfo
	///@return	下一个满足条件CSysRomotePingResultInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysRomotePingResultInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysRomotePingResultInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysRomotePingResultInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysRomotePingResultInfo * pSysRomotePingResultInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysRomotePingResultInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysParticTradeOrderStates是一个存储会员席位交易状态的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysParticTradeOrderStates
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
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! StaticWidth.isValid())
			return 0;
		if (! FrontID.isValid())
			return 0;
		if (! OrderCount.isValid())
			return 0;
		if (! CancleCount.isValid())
			return 0;
		if (! QueryCount.isValid())
			return 0;
		if (! TradeCount.isValid())
			return 0;
		if (! TradeMoney.isValid())
			return 0;
		if (! OrderCntMax.isValid())
			return 0;
		if (! CancleCntMax.isValid())
			return 0;
		if (! QueryCntMax.isValid())
			return 0;
		if (! TradeCntMax.isValid())
			return 0;
		if (! TradeMoneyMax.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysParticTradeOrderStates *pOriginal) const;
	
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
	///报单统计日期
	CDateType MonDate;
	///报单统计时间
	CTimeType MonTime;
	///统计时长(sec)
	CVolumeType StaticWidth;
	///前置ID
	CVolumeType FrontID;
	///报单数
	CVolumeType OrderCount;
	///撤单数
	CVolumeType CancleCount;
	///查询数
	CVolumeType QueryCount;
	///成交数
	CVolumeType TradeCount;
	///成交金额
	CVolumeType TradeMoney;
	///最大报单数
	CVolumeType OrderCntMax;
	///最大撤单数
	CVolumeType CancleCntMax;
	///最大查询数
	CVolumeType QueryCntMax;
	///最大成交数
	CVolumeType TradeCntMax;
	///最大成交金额
	CVolumeType TradeMoneyMax;
	
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

typedef const CWriteableSysParticTradeOrderStates CSysParticTradeOrderStates;

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesActionTrigger是操作会员席位交易状态时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesActionTrigger
{
public:
	///构造方法
	CSysParticTradeOrderStatesActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysParticTradeOrderStatesActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysParticTradeOrderStatesFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysParticTradeOrderStates	要加入的SysParticTradeOrderStates
	virtual void beforeAdd(CWriteableSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysParticTradeOrderStates	已经加入的SysParticTradeOrderStates
	virtual void afterAdd(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return;
	}

	///更新前触发	
	///@param	pSysParticTradeOrderStates	被刷新的CSysParticTradeOrderStates
	///@param	pNewSysParticTradeOrderStates	新的值
	virtual void beforeUpdate(CSysParticTradeOrderStates *pSysParticTradeOrderStates, CWriteableSysParticTradeOrderStates *pNewSysParticTradeOrderStates)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysParticTradeOrderStates	被刷新的CSysParticTradeOrderStates
	virtual void afterUpdate(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysParticTradeOrderStates	要删除的CSysParticTradeOrderStates
	virtual void beforeRemove(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysParticTradeOrderStatesFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesCommitTrigger是确认会员席位交易状态时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesCommitTrigger
{
public:
	///构造方法
	CSysParticTradeOrderStatesCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysParticTradeOrderStatesCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysParticTradeOrderStatesFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysParticTradeOrderStates	已经加入的SysParticTradeOrderStates
	virtual void commitAdd(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return;
	}

	///更新后触发
	///@param	pSysParticTradeOrderStates	被刷新的CSysParticTradeOrderStates
	///@param	poldSysParticTradeOrderStates	原来的值
	virtual void commitUpdate(CSysParticTradeOrderStates *pSysParticTradeOrderStates, CWriteableSysParticTradeOrderStates *pOldSysParticTradeOrderStates)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysParticTradeOrderStates	已经删除的CSysParticTradeOrderStates
	virtual void commitRemove(CWriteableSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysParticTradeOrderStatesFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesIterator是一个对会员席位交易状态的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesIterator
{
public:
	///构造方法
	CSysParticTradeOrderStatesIterator(void)
	{
	}

	///构造方法
	CSysParticTradeOrderStatesIterator(CSysParticTradeOrderStatesFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysParticTradeOrderStatesIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysParticTradeOrderStates
	///@return	下一个满足条件CSysParticTradeOrderStates，如果已经没有一个满足要求了，则返回NULL
	virtual CSysParticTradeOrderStates *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysParticTradeOrderStatesFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysParticTradeOrderStates 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysParticTradeOrderStates * pSysParticTradeOrderStates,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysParticTradeOrderStatesFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbRouterInfo是一个存储系统路由信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbRouterInfo
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
		if (! SubcriberID.isValid())
			return 0;
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! Dev.isValid())
			return 0;
		if (! Destination.isValid())
			return 0;
		if (! Gateway.isValid())
			return 0;
		if (! Mask.isValid())
			return 0;
		if (! Flag.isValid())
			return 0;
		if (! RefCnt.isValid())
			return 0;
		if (! Use.isValid())
			return 0;
		if (! Metric.isValid())
			return 0;
		if (! Mtu.isValid())
			return 0;
		if (! Win.isValid())
			return 0;
		if (! Rtt.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbRouterInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///订阅对象ID
	CVolumeType SubcriberID;
	///主机名称
	CTypeObjectIDType HostName;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///设备接口名
	CTypeCommandType Dev;
	///目标网段ip地址
	CIPAddressType Destination;
	///网关ip地址
	CIPAddressType Gateway;
	///掩码ip地址
	CIPAddressType Mask;
	///网络状态
	CTypeLanStatusType Flag;
	///关联计数
	CVolumeType RefCnt;
	///使用计数
	CVolumeType Use;
	///metric值
	CVolumeType Metric;
	///mtu值
	CVolumeType Mtu;
	///win值
	CVolumeType Win;
	///rtt值
	CVolumeType Rtt;
	
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

typedef const CWriteableSysMdbRouterInfo CSysMdbRouterInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoActionTrigger是操作系统路由信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoActionTrigger
{
public:
	///构造方法
	CSysMdbRouterInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbRouterInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbRouterInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMdbRouterInfo	要加入的SysMdbRouterInfo
	virtual void beforeAdd(CWriteableSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMdbRouterInfo	已经加入的SysMdbRouterInfo
	virtual void afterAdd(CSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMdbRouterInfo	被刷新的CSysMdbRouterInfo
	///@param	pNewSysMdbRouterInfo	新的值
	virtual void beforeUpdate(CSysMdbRouterInfo *pSysMdbRouterInfo, CWriteableSysMdbRouterInfo *pNewSysMdbRouterInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMdbRouterInfo	被刷新的CSysMdbRouterInfo
	virtual void afterUpdate(CSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMdbRouterInfo	要删除的CSysMdbRouterInfo
	virtual void beforeRemove(CSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbRouterInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoCommitTrigger是确认系统路由信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoCommitTrigger
{
public:
	///构造方法
	CSysMdbRouterInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbRouterInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbRouterInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMdbRouterInfo	已经加入的SysMdbRouterInfo
	virtual void commitAdd(CSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysMdbRouterInfo	被刷新的CSysMdbRouterInfo
	///@param	poldSysMdbRouterInfo	原来的值
	virtual void commitUpdate(CSysMdbRouterInfo *pSysMdbRouterInfo, CWriteableSysMdbRouterInfo *pOldSysMdbRouterInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMdbRouterInfo	已经删除的CSysMdbRouterInfo
	virtual void commitRemove(CWriteableSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbRouterInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoIterator是一个对系统路由信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoIterator
{
public:
	///构造方法
	CSysMdbRouterInfoIterator(void)
	{
	}

	///构造方法
	CSysMdbRouterInfoIterator(CSysMdbRouterInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbRouterInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMdbRouterInfo
	///@return	下一个满足条件CSysMdbRouterInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbRouterInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMdbRouterInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbRouterInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbRouterInfo * pSysMdbRouterInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMdbRouterInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbDiskIO是一个存储磁盘I/O信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbDiskIO
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
		if (! SubcriberID.isValid())
			return 0;
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! PartName.isValid())
			return 0;
		if (! ReadMerges.isValid())
			return 0;
		if (! WriteMerges.isValid())
			return 0;
		if (! ReadIOs.isValid())
			return 0;
		if (! WriteIOs.isValid())
			return 0;
		if (! ReadKBs.isValid())
			return 0;
		if (! WriteKBs.isValid())
			return 0;
		if (! SizeVal.isValid())
			return 0;
		if (! QueueVal.isValid())
			return 0;
		if (! Svc_t.isValid())
			return 0;
		if (! Busy.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbDiskIO *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///订阅对象ID
	CVolumeType SubcriberID;
	///主机名称
	CTypeObjectIDType HostName;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///分区名
	CTypeCommandType PartName;
	///每秒ReadMerge数
	CPriceType ReadMerges;
	///每秒WriteMerge数
	CPriceType WriteMerges;
	///每秒ReadIO数
	CPriceType ReadIOs;
	///每秒WriteIO数
	CPriceType WriteIOs;
	///每秒Read字节数
	CPriceType ReadKBs;
	///每秒Write字节数
	CPriceType WriteKBs;
	///Size值
	CPriceType SizeVal;
	///Queue值
	CPriceType QueueVal;
	///Svc_t值
	CPriceType Svc_t;
	///繁忙百分率
	CRatioType Busy;
	
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

typedef const CWriteableSysMdbDiskIO CSysMdbDiskIO;

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOActionTrigger是操作磁盘I/O信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOActionTrigger
{
public:
	///构造方法
	CSysMdbDiskIOActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbDiskIOActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbDiskIOFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMdbDiskIO	要加入的SysMdbDiskIO
	virtual void beforeAdd(CWriteableSysMdbDiskIO *pSysMdbDiskIO)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMdbDiskIO	已经加入的SysMdbDiskIO
	virtual void afterAdd(CSysMdbDiskIO *pSysMdbDiskIO)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMdbDiskIO	被刷新的CSysMdbDiskIO
	///@param	pNewSysMdbDiskIO	新的值
	virtual void beforeUpdate(CSysMdbDiskIO *pSysMdbDiskIO, CWriteableSysMdbDiskIO *pNewSysMdbDiskIO)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMdbDiskIO	被刷新的CSysMdbDiskIO
	virtual void afterUpdate(CSysMdbDiskIO *pSysMdbDiskIO)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMdbDiskIO	要删除的CSysMdbDiskIO
	virtual void beforeRemove(CSysMdbDiskIO *pSysMdbDiskIO)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbDiskIOFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOCommitTrigger是确认磁盘I/O信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOCommitTrigger
{
public:
	///构造方法
	CSysMdbDiskIOCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbDiskIOCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbDiskIOFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMdbDiskIO	已经加入的SysMdbDiskIO
	virtual void commitAdd(CSysMdbDiskIO *pSysMdbDiskIO)
	{
		return;
	}

	///更新后触发
	///@param	pSysMdbDiskIO	被刷新的CSysMdbDiskIO
	///@param	poldSysMdbDiskIO	原来的值
	virtual void commitUpdate(CSysMdbDiskIO *pSysMdbDiskIO, CWriteableSysMdbDiskIO *pOldSysMdbDiskIO)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMdbDiskIO	已经删除的CSysMdbDiskIO
	virtual void commitRemove(CWriteableSysMdbDiskIO *pSysMdbDiskIO)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbDiskIOFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOIterator是一个对磁盘I/O信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOIterator
{
public:
	///构造方法
	CSysMdbDiskIOIterator(void)
	{
	}

	///构造方法
	CSysMdbDiskIOIterator(CSysMdbDiskIOFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbDiskIOIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMdbDiskIO
	///@return	下一个满足条件CSysMdbDiskIO，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbDiskIO *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMdbDiskIOFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbDiskIO 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbDiskIO * pSysMdbDiskIO,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMdbDiskIOFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbStatInfo是一个存储系统状态信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbStatInfo
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
		if (! SubcriberID.isValid())
			return 0;
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! ProcRun.isValid())
			return 0;
		if (! ProcBlk.isValid())
			return 0;
		if (! SwapIn.isValid())
			return 0;
		if (! SwapOut.isValid())
			return 0;
		if (! BlockIn.isValid())
			return 0;
		if (! BlockOut.isValid())
			return 0;
		if (! Inter.isValid())
			return 0;
		if (! Context.isValid())
			return 0;
		if (! CPUUser.isValid())
			return 0;
		if (! CPUSys.isValid())
			return 0;
		if (! CPUIdle.isValid())
			return 0;
		if (! CPUIOWait.isValid())
			return 0;
		if (! CPUSteal.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbStatInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///订阅对象ID
	CVolumeType SubcriberID;
	///主机名称
	CTypeObjectIDType HostName;
	///采集的日期
	CDateType MonDate;
	///采集的时间
	CTimeType MonTime;
	///活跃进程数
	CVolumeType ProcRun;
	///阻塞进程数
	CVolumeType ProcBlk;
	///每秒由磁盘进入Swap的页面数
	CVolumeType SwapIn;
	///每秒由Swap进入磁盘的页面数
	CVolumeType SwapOut;
	///每秒从块设备读入的Block数
	CVolumeType BlockIn;
	///每秒向块设备写入的Block数
	CVolumeType BlockOut;
	///每秒设备中段次数
	CVolumeType Inter;
	///每秒上下文切换次数
	CVolumeType Context;
	///用户态CPU百分率
	CRatioType CPUUser;
	///系统态CPU百分率
	CRatioType CPUSys;
	///空闲态CPU百分率
	CRatioType CPUIdle;
	///IO等待态CPU百分率
	CRatioType CPUIOWait;
	///窃取态CPU百分率
	CRatioType CPUSteal;
	
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

typedef const CWriteableSysMdbStatInfo CSysMdbStatInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoActionTrigger是操作系统状态信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoActionTrigger
{
public:
	///构造方法
	CSysMdbStatInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbStatInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbStatInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMdbStatInfo	要加入的SysMdbStatInfo
	virtual void beforeAdd(CWriteableSysMdbStatInfo *pSysMdbStatInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMdbStatInfo	已经加入的SysMdbStatInfo
	virtual void afterAdd(CSysMdbStatInfo *pSysMdbStatInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMdbStatInfo	被刷新的CSysMdbStatInfo
	///@param	pNewSysMdbStatInfo	新的值
	virtual void beforeUpdate(CSysMdbStatInfo *pSysMdbStatInfo, CWriteableSysMdbStatInfo *pNewSysMdbStatInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMdbStatInfo	被刷新的CSysMdbStatInfo
	virtual void afterUpdate(CSysMdbStatInfo *pSysMdbStatInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMdbStatInfo	要删除的CSysMdbStatInfo
	virtual void beforeRemove(CSysMdbStatInfo *pSysMdbStatInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbStatInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoCommitTrigger是确认系统状态信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoCommitTrigger
{
public:
	///构造方法
	CSysMdbStatInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbStatInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbStatInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMdbStatInfo	已经加入的SysMdbStatInfo
	virtual void commitAdd(CSysMdbStatInfo *pSysMdbStatInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysMdbStatInfo	被刷新的CSysMdbStatInfo
	///@param	poldSysMdbStatInfo	原来的值
	virtual void commitUpdate(CSysMdbStatInfo *pSysMdbStatInfo, CWriteableSysMdbStatInfo *pOldSysMdbStatInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMdbStatInfo	已经删除的CSysMdbStatInfo
	virtual void commitRemove(CWriteableSysMdbStatInfo *pSysMdbStatInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbStatInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoIterator是一个对系统状态信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoIterator
{
public:
	///构造方法
	CSysMdbStatInfoIterator(void)
	{
	}

	///构造方法
	CSysMdbStatInfoIterator(CSysMdbStatInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbStatInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMdbStatInfo
	///@return	下一个满足条件CSysMdbStatInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbStatInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMdbStatInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbStatInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbStatInfo * pSysMdbStatInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMdbStatInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbTradeFrontOrderRttStat是一个存储交易系统前置报单响应信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbTradeFrontOrderRttStat
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
		if (! SubcriberID.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! OrderCount.isValid())
			return 0;
		if (! OrderRttSum.isValid())
			return 0;
		if (! OrderMaxRtt.isValid())
			return 0;
		if (! OrderMinRtt.isValid())
			return 0;
		if (! OrderRttSqu.isValid())
			return 0;
		if (! OrderRttCutDistrib.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbTradeFrontOrderRttStat *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///订阅对象ID
	CVolumeType SubcriberID;
	///报单日期
	CDateType MonDate;
	///报单时间
	CTimeType MonTime;
	///前置对象
	CTypeObjectIDType ObjectID;
	///报单量
	CLargeNumberType OrderCount;
	///报单响应时间和
	CLargeNumberType OrderRttSum;
	///最大报单响应时间
	CVolumeType OrderMaxRtt;
	///最小报单响应时间
	CVolumeType OrderMinRtt;
	///1秒内响应时间均差
	CVolumeType OrderRttSqu;
	///1秒内响应时间分布
	CNumberListsType OrderRttCutDistrib;
	
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

typedef const CWriteableSysMdbTradeFrontOrderRttStat CSysMdbTradeFrontOrderRttStat;

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatActionTrigger是操作交易系统前置报单响应信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatActionTrigger
{
public:
	///构造方法
	CSysMdbTradeFrontOrderRttStatActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbTradeFrontOrderRttStatActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbTradeFrontOrderRttStatFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMdbTradeFrontOrderRttStat	要加入的SysMdbTradeFrontOrderRttStat
	virtual void beforeAdd(CWriteableSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMdbTradeFrontOrderRttStat	已经加入的SysMdbTradeFrontOrderRttStat
	virtual void afterAdd(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMdbTradeFrontOrderRttStat	被刷新的CSysMdbTradeFrontOrderRttStat
	///@param	pNewSysMdbTradeFrontOrderRttStat	新的值
	virtual void beforeUpdate(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, CWriteableSysMdbTradeFrontOrderRttStat *pNewSysMdbTradeFrontOrderRttStat)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMdbTradeFrontOrderRttStat	被刷新的CSysMdbTradeFrontOrderRttStat
	virtual void afterUpdate(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMdbTradeFrontOrderRttStat	要删除的CSysMdbTradeFrontOrderRttStat
	virtual void beforeRemove(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbTradeFrontOrderRttStatFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatCommitTrigger是确认交易系统前置报单响应信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatCommitTrigger
{
public:
	///构造方法
	CSysMdbTradeFrontOrderRttStatCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMdbTradeFrontOrderRttStatCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMdbTradeFrontOrderRttStatFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMdbTradeFrontOrderRttStat	已经加入的SysMdbTradeFrontOrderRttStat
	virtual void commitAdd(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return;
	}

	///更新后触发
	///@param	pSysMdbTradeFrontOrderRttStat	被刷新的CSysMdbTradeFrontOrderRttStat
	///@param	poldSysMdbTradeFrontOrderRttStat	原来的值
	virtual void commitUpdate(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, CWriteableSysMdbTradeFrontOrderRttStat *pOldSysMdbTradeFrontOrderRttStat)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMdbTradeFrontOrderRttStat	已经删除的CSysMdbTradeFrontOrderRttStat
	virtual void commitRemove(CWriteableSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMdbTradeFrontOrderRttStatFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatIterator是一个对交易系统前置报单响应信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatIterator
{
public:
	///构造方法
	CSysMdbTradeFrontOrderRttStatIterator(void)
	{
	}

	///构造方法
	CSysMdbTradeFrontOrderRttStatIterator(CSysMdbTradeFrontOrderRttStatFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTradeFrontOrderRttStatIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMdbTradeFrontOrderRttStat
	///@return	下一个满足条件CSysMdbTradeFrontOrderRttStat，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTradeFrontOrderRttStat *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMdbTradeFrontOrderRttStatFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbTradeFrontOrderRttStat 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMdbTradeFrontOrderRttStatFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysInstrumentStatus是一个存储合约状态切换的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysInstrumentStatus
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
		if (! EnterDate.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysInstrumentStatus *pOriginal) const;
	
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
	///进入本状态日期
	CDateType EnterDate;
	
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

typedef const CWriteableSysInstrumentStatus CSysInstrumentStatus;

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusActionTrigger是操作合约状态切换时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusActionTrigger
{
public:
	///构造方法
	CSysInstrumentStatusActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysInstrumentStatusActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysInstrumentStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysInstrumentStatus	要加入的SysInstrumentStatus
	virtual void beforeAdd(CWriteableSysInstrumentStatus *pSysInstrumentStatus)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysInstrumentStatus	已经加入的SysInstrumentStatus
	virtual void afterAdd(CSysInstrumentStatus *pSysInstrumentStatus)
	{
		return;
	}

	///更新前触发	
	///@param	pSysInstrumentStatus	被刷新的CSysInstrumentStatus
	///@param	pNewSysInstrumentStatus	新的值
	virtual void beforeUpdate(CSysInstrumentStatus *pSysInstrumentStatus, CWriteableSysInstrumentStatus *pNewSysInstrumentStatus)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysInstrumentStatus	被刷新的CSysInstrumentStatus
	virtual void afterUpdate(CSysInstrumentStatus *pSysInstrumentStatus)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysInstrumentStatus	要删除的CSysInstrumentStatus
	virtual void beforeRemove(CSysInstrumentStatus *pSysInstrumentStatus)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysInstrumentStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusCommitTrigger是确认合约状态切换时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusCommitTrigger
{
public:
	///构造方法
	CSysInstrumentStatusCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysInstrumentStatusCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysInstrumentStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysInstrumentStatus	已经加入的SysInstrumentStatus
	virtual void commitAdd(CSysInstrumentStatus *pSysInstrumentStatus)
	{
		return;
	}

	///更新后触发
	///@param	pSysInstrumentStatus	被刷新的CSysInstrumentStatus
	///@param	poldSysInstrumentStatus	原来的值
	virtual void commitUpdate(CSysInstrumentStatus *pSysInstrumentStatus, CWriteableSysInstrumentStatus *pOldSysInstrumentStatus)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysInstrumentStatus	已经删除的CSysInstrumentStatus
	virtual void commitRemove(CWriteableSysInstrumentStatus *pSysInstrumentStatus)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysInstrumentStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusIterator是一个对合约状态切换的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusIterator
{
public:
	///构造方法
	CSysInstrumentStatusIterator(void)
	{
	}

	///构造方法
	CSysInstrumentStatusIterator(CSysInstrumentStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysInstrumentStatusIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysInstrumentStatus
	///@return	下一个满足条件CSysInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSysInstrumentStatus *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysInstrumentStatusFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysInstrumentStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysInstrumentStatus * pSysInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysInstrumentStatusFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysCurrTradingSegmentAttr是一个存储合约交易节信息的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysCurrTradingSegmentAttr
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
		if (! AdvanceDays.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysCurrTradingSegmentAttr *pOriginal) const;
	
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
	///提前天数
	CAdvanceDaysType AdvanceDays;
	
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

typedef const CWriteableSysCurrTradingSegmentAttr CSysCurrTradingSegmentAttr;

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrActionTrigger是操作合约交易节信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrActionTrigger
{
public:
	///构造方法
	CSysCurrTradingSegmentAttrActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysCurrTradingSegmentAttrActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysCurrTradingSegmentAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysCurrTradingSegmentAttr	要加入的SysCurrTradingSegmentAttr
	virtual void beforeAdd(CWriteableSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysCurrTradingSegmentAttr	已经加入的SysCurrTradingSegmentAttr
	virtual void afterAdd(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return;
	}

	///更新前触发	
	///@param	pSysCurrTradingSegmentAttr	被刷新的CSysCurrTradingSegmentAttr
	///@param	pNewSysCurrTradingSegmentAttr	新的值
	virtual void beforeUpdate(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, CWriteableSysCurrTradingSegmentAttr *pNewSysCurrTradingSegmentAttr)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysCurrTradingSegmentAttr	被刷新的CSysCurrTradingSegmentAttr
	virtual void afterUpdate(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysCurrTradingSegmentAttr	要删除的CSysCurrTradingSegmentAttr
	virtual void beforeRemove(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysCurrTradingSegmentAttrFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrCommitTrigger是确认合约交易节信息时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrCommitTrigger
{
public:
	///构造方法
	CSysCurrTradingSegmentAttrCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysCurrTradingSegmentAttrCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysCurrTradingSegmentAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysCurrTradingSegmentAttr	已经加入的SysCurrTradingSegmentAttr
	virtual void commitAdd(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return;
	}

	///更新后触发
	///@param	pSysCurrTradingSegmentAttr	被刷新的CSysCurrTradingSegmentAttr
	///@param	poldSysCurrTradingSegmentAttr	原来的值
	virtual void commitUpdate(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, CWriteableSysCurrTradingSegmentAttr *pOldSysCurrTradingSegmentAttr)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysCurrTradingSegmentAttr	已经删除的CSysCurrTradingSegmentAttr
	virtual void commitRemove(CWriteableSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysCurrTradingSegmentAttrFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrIterator是一个对合约交易节信息的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrIterator
{
public:
	///构造方法
	CSysCurrTradingSegmentAttrIterator(void)
	{
	}

	///构造方法
	CSysCurrTradingSegmentAttrIterator(CSysCurrTradingSegmentAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysCurrTradingSegmentAttrIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysCurrTradingSegmentAttr
	///@return	下一个满足条件CSysCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysCurrTradingSegmentAttr *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysCurrTradingSegmentAttrFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysCurrTradingSegmentAttr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysCurrTradingSegmentAttrFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMemberLinkCost是一个存储会员链路费用表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMemberLinkCost
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
		if (! ID.isValid())
			return 0;
		if (! ParticipantName.isValid())
			return 0;
		if (! DDN_NO.isValid())
			return 0;
		if (! ServiceProvider.isValid())
			return 0;
		if (! Pay_Date.isValid())
			return 0;
		if (! B_Pay_Date.isValid())
			return 0;
		if (! D_Pay_Date.isValid())
			return 0;
		if (! Charge.isValid())
			return 0;
		if (! Fee_Type.isValid())
			return 0;
		if (! Pro.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMemberLinkCost *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///会员名称
	CParticipantNameType ParticipantName;
	///线路编号
	CTypeObjectIDType DDN_NO;
	///运营商
	CCfgNameType ServiceProvider;
	///付款日期
	CCfgNameType Pay_Date;
	///账期起始日期
	CCfgNameType B_Pay_Date;
	///账期终止日期
	CCfgNameType D_Pay_Date;
	///金额
	CVolumeType Charge;
	///费用类型
	CCfgNameType Fee_Type;
	///备注
	CPolicyStringTypeType Pro;
	
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

typedef const CWriteableSysMemberLinkCost CSysMemberLinkCost;

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostActionTrigger是操作会员链路费用表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostActionTrigger
{
public:
	///构造方法
	CSysMemberLinkCostActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMemberLinkCostActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMemberLinkCostFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysMemberLinkCost	要加入的SysMemberLinkCost
	virtual void beforeAdd(CWriteableSysMemberLinkCost *pSysMemberLinkCost)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysMemberLinkCost	已经加入的SysMemberLinkCost
	virtual void afterAdd(CSysMemberLinkCost *pSysMemberLinkCost)
	{
		return;
	}

	///更新前触发	
	///@param	pSysMemberLinkCost	被刷新的CSysMemberLinkCost
	///@param	pNewSysMemberLinkCost	新的值
	virtual void beforeUpdate(CSysMemberLinkCost *pSysMemberLinkCost, CWriteableSysMemberLinkCost *pNewSysMemberLinkCost)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysMemberLinkCost	被刷新的CSysMemberLinkCost
	virtual void afterUpdate(CSysMemberLinkCost *pSysMemberLinkCost)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysMemberLinkCost	要删除的CSysMemberLinkCost
	virtual void beforeRemove(CSysMemberLinkCost *pSysMemberLinkCost)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMemberLinkCostFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostCommitTrigger是确认会员链路费用表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostCommitTrigger
{
public:
	///构造方法
	CSysMemberLinkCostCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysMemberLinkCostCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysMemberLinkCostFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysMemberLinkCost	已经加入的SysMemberLinkCost
	virtual void commitAdd(CSysMemberLinkCost *pSysMemberLinkCost)
	{
		return;
	}

	///更新后触发
	///@param	pSysMemberLinkCost	被刷新的CSysMemberLinkCost
	///@param	poldSysMemberLinkCost	原来的值
	virtual void commitUpdate(CSysMemberLinkCost *pSysMemberLinkCost, CWriteableSysMemberLinkCost *pOldSysMemberLinkCost)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysMemberLinkCost	已经删除的CSysMemberLinkCost
	virtual void commitRemove(CWriteableSysMemberLinkCost *pSysMemberLinkCost)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysMemberLinkCostFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostIterator是一个对会员链路费用表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostIterator
{
public:
	///构造方法
	CSysMemberLinkCostIterator(void)
	{
	}

	///构造方法
	CSysMemberLinkCostIterator(CSysMemberLinkCostFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMemberLinkCostIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysMemberLinkCost
	///@return	下一个满足条件CSysMemberLinkCost，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMemberLinkCost *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysMemberLinkCostFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysMemberLinkCost 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMemberLinkCost * pSysMemberLinkCost,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysMemberLinkCostFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetPartylinkMonthlyRent是一个存储会员链路月租表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetPartylinkMonthlyRent
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
		if (! ID.isValid())
			return 0;
		if (! LineName.isValid())
			return 0;
		if (! DDN_NO.isValid())
			return 0;
		if (! ServiceProvider.isValid())
			return 0;
		if (! MonthlyRental.isValid())
			return 0;
		if (! Remark.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetPartylinkMonthlyRent *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///线路名称
	CParticipantNameType LineName;
	///线路编号
	CTypeObjectIDType DDN_NO;
	///运营商
	CCfgNameType ServiceProvider;
	///月租费用
	CLongVolumeType MonthlyRental;
	///备注
	CNetString128Type Remark;
	
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

typedef const CWriteableSysNetPartylinkMonthlyRent CSysNetPartylinkMonthlyRent;

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentActionTrigger是操作会员链路月租表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentActionTrigger
{
public:
	///构造方法
	CSysNetPartylinkMonthlyRentActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetPartylinkMonthlyRentActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetPartylinkMonthlyRentFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetPartylinkMonthlyRent	要加入的SysNetPartylinkMonthlyRent
	virtual void beforeAdd(CWriteableSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetPartylinkMonthlyRent	已经加入的SysNetPartylinkMonthlyRent
	virtual void afterAdd(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetPartylinkMonthlyRent	被刷新的CSysNetPartylinkMonthlyRent
	///@param	pNewSysNetPartylinkMonthlyRent	新的值
	virtual void beforeUpdate(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, CWriteableSysNetPartylinkMonthlyRent *pNewSysNetPartylinkMonthlyRent)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetPartylinkMonthlyRent	被刷新的CSysNetPartylinkMonthlyRent
	virtual void afterUpdate(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetPartylinkMonthlyRent	要删除的CSysNetPartylinkMonthlyRent
	virtual void beforeRemove(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetPartylinkMonthlyRentFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentCommitTrigger是确认会员链路月租表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentCommitTrigger
{
public:
	///构造方法
	CSysNetPartylinkMonthlyRentCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetPartylinkMonthlyRentCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetPartylinkMonthlyRentFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetPartylinkMonthlyRent	已经加入的SysNetPartylinkMonthlyRent
	virtual void commitAdd(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetPartylinkMonthlyRent	被刷新的CSysNetPartylinkMonthlyRent
	///@param	poldSysNetPartylinkMonthlyRent	原来的值
	virtual void commitUpdate(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, CWriteableSysNetPartylinkMonthlyRent *pOldSysNetPartylinkMonthlyRent)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetPartylinkMonthlyRent	已经删除的CSysNetPartylinkMonthlyRent
	virtual void commitRemove(CWriteableSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetPartylinkMonthlyRentFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentIterator是一个对会员链路月租表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentIterator
{
public:
	///构造方法
	CSysNetPartylinkMonthlyRentIterator(void)
	{
	}

	///构造方法
	CSysNetPartylinkMonthlyRentIterator(CSysNetPartylinkMonthlyRentFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPartylinkMonthlyRentIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetPartylinkMonthlyRent
	///@return	下一个满足条件CSysNetPartylinkMonthlyRent，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartylinkMonthlyRent *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetPartylinkMonthlyRentFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPartylinkMonthlyRent 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetPartylinkMonthlyRentFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetNonPartyLinkInfo是一个存储会员链路月租表的对象，可以写出。
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetNonPartyLinkInfo
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
		if (! ID.isValid())
			return 0;
		if (! MEMBER_NO.isValid())
			return 0;
		if (! MEMBER_NAME.isValid())
			return 0;
		if (! REMOTE_ADDR.isValid())
			return 0;
		if (! LOCAL_ADDR.isValid())
			return 0;
		if (! ADDRESS.isValid())
			return 0;
		if (! LINE_STATUS.isValid())
			return 0;
		if (! CONTACT.isValid())
			return 0;
		if (! TELEPHONE.isValid())
			return 0;
		if (! MOBILEPHONE.isValid())
			return 0;
		if (! EMAIL.isValid())
			return 0;
		if (! FAX.isValid())
			return 0;
		if (! PROVINCE.isValid())
			return 0;
		if (! DDN_NO.isValid())
			return 0;
		if (! IN_MODE.isValid())
			return 0;
		if (! IP_WAN.isValid())
			return 0;
		if (! IP_LAN.isValid())
			return 0;
		if (! IPADDR.isValid())
			return 0;
		if (! Interface.isValid())
			return 0;
		if (! INTERFACE_DATE.isValid())
			return 0;
		if (! SOFTWARE.isValid())
			return 0;
		if (! FEE_TYPE.isValid())
			return 0;
		if (! SERVICEPROVIDER.isValid())
			return 0;
		if (! IF_ZIYING.isValid())
			return 0;
		if (! IF_TUOGUAN.isValid())
			return 0;
		if (! HASOTHER.isValid())
			return 0;
		if (! SEAT_NO.isValid())
			return 0;
		if (! PRO.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetNonPartyLinkInfo *pOriginal) const;
	
	///将内容写到文件的一行中,用于DEBUG
	///@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp=NULL) const;

	///将内容写到一个字符串中
	///@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///会员号
	CCfgNameType MEMBER_NO;
	///会员名称
	CTypeObjectIDType MEMBER_NAME;
	///会员接入地点
	CTypeObjectIDType REMOTE_ADDR;
	///上期所接入点
	CTypeObjectIDType LOCAL_ADDR;
	///地址
	CNetAttrTypeType ADDRESS;
	///线路状态
	CCfgNameType LINE_STATUS;
	///联系人
	CCfgNameType CONTACT;
	///联系电话
	CTypeObjectIDType TELEPHONE;
	///手机号
	CTypeObjectIDType MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType EMAIL;
	///传真
	CTypeObjectIDType FAX;
	///所属省份
	CCfgNameType PROVINCE;
	///线路编号
	CTypeObjectIDType DDN_NO;
	///接入方式
	CTypeObjectIDType IN_MODE;
	///入网IP广域
	CTypeObjectIDType IP_WAN;
	///入网IP局域
	CTypeObjectIDType IP_LAN;
	///路由器网管IP
	CTypeObjectIDType IPADDR;
	///路由器端口号
	CTypeObjectIDType Interface;
	///接口开通日期
	CCfgNameType INTERFACE_DATE;
	///所用软件
	CCfgNameType SOFTWARE;
	///付费类型
	CCfgNameType FEE_TYPE;
	///运营商
	CCfgNameType SERVICEPROVIDER;
	///是否自营
	CCfgNameType IF_ZIYING;
	///是否托管
	CCfgNameType IF_TUOGUAN;
	///有无他所线路
	CCfgNameType HASOTHER;
	///席位号
	CGeneralResultType SEAT_NO;
	///备注
	CPolicyStringTypeType PRO;
	
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

typedef const CWriteableSysNetNonPartyLinkInfo CSysNetNonPartyLinkInfo;

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoActionTrigger是操作会员链路月租表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoActionTrigger
{
public:
	///构造方法
	CSysNetNonPartyLinkInfoActionTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetNonPartyLinkInfoActionTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetNonPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入前触发
	///@param	pSysNetNonPartyLinkInfo	要加入的SysNetNonPartyLinkInfo
	virtual void beforeAdd(CWriteableSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return;
	}
	
	///加入后触发
	///@param	pSysNetNonPartyLinkInfo	已经加入的SysNetNonPartyLinkInfo
	virtual void afterAdd(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return;
	}

	///更新前触发	
	///@param	pSysNetNonPartyLinkInfo	被刷新的CSysNetNonPartyLinkInfo
	///@param	pNewSysNetNonPartyLinkInfo	新的值
	virtual void beforeUpdate(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, CWriteableSysNetNonPartyLinkInfo *pNewSysNetNonPartyLinkInfo)
	{
		return;
	}
	
	///更新后触发
	///@param	pSysNetNonPartyLinkInfo	被刷新的CSysNetNonPartyLinkInfo
	virtual void afterUpdate(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return;
	}
	
	///删除前触发
	///@param	pSysNetNonPartyLinkInfo	要删除的CSysNetNonPartyLinkInfo
	virtual void beforeRemove(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetNonPartyLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoCommitTrigger是确认会员链路月租表时的触发器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoCommitTrigger
{
public:
	///构造方法
	CSysNetNonPartyLinkInfoCommitTrigger(void)
	{
	}
	
	///析构方法
	virtual ~CSysNetNonPartyLinkInfoCommitTrigger(void)
	{
	}

	///设定对应的对象工厂
	///@param	pFactory	指定的对象工厂
	void setFactory(CSysNetNonPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///加入后触发
	///@param	pSysNetNonPartyLinkInfo	已经加入的SysNetNonPartyLinkInfo
	virtual void commitAdd(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return;
	}

	///更新后触发
	///@param	pSysNetNonPartyLinkInfo	被刷新的CSysNetNonPartyLinkInfo
	///@param	poldSysNetNonPartyLinkInfo	原来的值
	virtual void commitUpdate(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, CWriteableSysNetNonPartyLinkInfo *pOldSysNetNonPartyLinkInfo)
	{
		return;
	}
	
	///删除后触发
	///@param	pSysNetNonPartyLinkInfo	已经删除的CSysNetNonPartyLinkInfo
	virtual void commitRemove(CWriteableSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return;
	}
protected:
	///该触发器对应的对象工厂
	CSysNetNonPartyLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoIterator是一个对会员链路月租表的枚举器接口
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoIterator
{
public:
	///构造方法
	CSysNetNonPartyLinkInfoIterator(void)
	{
	}

	///构造方法
	CSysNetNonPartyLinkInfoIterator(CSysNetNonPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetNonPartyLinkInfoIterator(void);
	
	///释放自己
	virtual void free(void)
	{
		delete this;
	}

	///获得下一个SysNetNonPartyLinkInfo
	///@return	下一个满足条件CSysNetNonPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetNonPartyLinkInfo *next(void)=0;
	
	///获得对应的对象工厂
	///@return	对应的对象工厂
	CSysNetNonPartyLinkInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetNonPartyLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///将本枚举器中所有内容全部输出
	///@param	output	要输出的位置
	void dump(FILE *output);

protected:
	///进行查询时使用的对象工厂
	CSysNetNonPartyLinkInfoFactory *m_Factory;	
};


#include "databaseFactories.h"

#endif


