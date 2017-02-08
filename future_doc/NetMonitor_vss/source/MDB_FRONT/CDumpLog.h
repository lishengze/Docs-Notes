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
///CSysInvalidateOrderDumpTrigger是操作无效报单时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderDumpTrigger: public CSysInvalidateOrderActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysInvalidateOrderDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysInvalidateOrderDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysInvalidateOrder	要加入的SysInvalidateOrder
	virtual void beforeAdd(CWriteableSysInvalidateOrder *pSysInvalidateOrder);
	
	///更新前触发	
	///@param	pSysInvalidateOrder	被刷新的CSysInvalidateOrder
	///@param	pNewSysInvalidateOrder	新的值
	virtual void beforeUpdate(CSysInvalidateOrder *pSysInvalidateOrder, CWriteableSysInvalidateOrder *pNewSysInvalidateOrder);
	
	///删除前触发
	///@param	pSysInvalidateOrder	要删除的CSysInvalidateOrder
	virtual void beforeRemove(CSysInvalidateOrder *pSysInvalidateOrder);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusDumpTrigger是操作报单状态时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusDumpTrigger: public CSysOrderStatusActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysOrderStatusDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysOrderStatusDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysOrderStatus	要加入的SysOrderStatus
	virtual void beforeAdd(CWriteableSysOrderStatus *pSysOrderStatus);
	
	///更新前触发	
	///@param	pSysOrderStatus	被刷新的CSysOrderStatus
	///@param	pNewSysOrderStatus	新的值
	virtual void beforeUpdate(CSysOrderStatus *pSysOrderStatus, CWriteableSysOrderStatus *pNewSysOrderStatus);
	
	///删除前触发
	///@param	pSysOrderStatus	要删除的CSysOrderStatus
	virtual void beforeRemove(CSysOrderStatus *pSysOrderStatus);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderDumpTrigger是操作报单成交时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderDumpTrigger: public CSysBargainOrderActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysBargainOrderDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysBargainOrderDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysBargainOrder	要加入的SysBargainOrder
	virtual void beforeAdd(CWriteableSysBargainOrder *pSysBargainOrder);
	
	///更新前触发	
	///@param	pSysBargainOrder	被刷新的CSysBargainOrder
	///@param	pNewSysBargainOrder	新的值
	virtual void beforeUpdate(CSysBargainOrder *pSysBargainOrder, CWriteableSysBargainOrder *pNewSysBargainOrder);
	
	///删除前触发
	///@param	pSysBargainOrder	要删除的CSysBargainOrder
	virtual void beforeRemove(CSysBargainOrder *pSysBargainOrder);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyDumpTrigger是操作合约基本属性时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyDumpTrigger: public CSysInstPropertyActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysInstPropertyDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysInstPropertyDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysInstProperty	要加入的SysInstProperty
	virtual void beforeAdd(CWriteableSysInstProperty *pSysInstProperty);
	
	///更新前触发	
	///@param	pSysInstProperty	被刷新的CSysInstProperty
	///@param	pNewSysInstProperty	新的值
	virtual void beforeUpdate(CSysInstProperty *pSysInstProperty, CWriteableSysInstProperty *pNewSysInstProperty);
	
	///删除前触发
	///@param	pSysInstProperty	要删除的CSysInstProperty
	virtual void beforeRemove(CSysInstProperty *pSysInstProperty);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateDumpTrigger是操作合约保证金率时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateDumpTrigger: public CSysMarginRateActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMarginRateDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMarginRateDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMarginRate	要加入的SysMarginRate
	virtual void beforeAdd(CWriteableSysMarginRate *pSysMarginRate);
	
	///更新前触发	
	///@param	pSysMarginRate	被刷新的CSysMarginRate
	///@param	pNewSysMarginRate	新的值
	virtual void beforeUpdate(CSysMarginRate *pSysMarginRate, CWriteableSysMarginRate *pNewSysMarginRate);
	
	///删除前触发
	///@param	pSysMarginRate	要删除的CSysMarginRate
	virtual void beforeRemove(CSysMarginRate *pSysMarginRate);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitDumpTrigger是操作合约涨跌停板时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitDumpTrigger: public CSysPriceLimitActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysPriceLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysPriceLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysPriceLimit	要加入的SysPriceLimit
	virtual void beforeAdd(CWriteableSysPriceLimit *pSysPriceLimit);
	
	///更新前触发	
	///@param	pSysPriceLimit	被刷新的CSysPriceLimit
	///@param	pNewSysPriceLimit	新的值
	virtual void beforeUpdate(CSysPriceLimit *pSysPriceLimit, CWriteableSysPriceLimit *pNewSysPriceLimit);
	
	///删除前触发
	///@param	pSysPriceLimit	要删除的CSysPriceLimit
	virtual void beforeRemove(CSysPriceLimit *pSysPriceLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitDumpTrigger是操作会员限仓时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitDumpTrigger: public CSysPartPosiLimitActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysPartPosiLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysPartPosiLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysPartPosiLimit	要加入的SysPartPosiLimit
	virtual void beforeAdd(CWriteableSysPartPosiLimit *pSysPartPosiLimit);
	
	///更新前触发	
	///@param	pSysPartPosiLimit	被刷新的CSysPartPosiLimit
	///@param	pNewSysPartPosiLimit	新的值
	virtual void beforeUpdate(CSysPartPosiLimit *pSysPartPosiLimit, CWriteableSysPartPosiLimit *pNewSysPartPosiLimit);
	
	///删除前触发
	///@param	pSysPartPosiLimit	要删除的CSysPartPosiLimit
	virtual void beforeRemove(CSysPartPosiLimit *pSysPartPosiLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitDumpTrigger是操作客户限仓时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitDumpTrigger: public CSysClientPosiLimitActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysClientPosiLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysClientPosiLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysClientPosiLimit	要加入的SysClientPosiLimit
	virtual void beforeAdd(CWriteableSysClientPosiLimit *pSysClientPosiLimit);
	
	///更新前触发	
	///@param	pSysClientPosiLimit	被刷新的CSysClientPosiLimit
	///@param	pNewSysClientPosiLimit	新的值
	virtual void beforeUpdate(CSysClientPosiLimit *pSysClientPosiLimit, CWriteableSysClientPosiLimit *pNewSysClientPosiLimit);
	
	///删除前触发
	///@param	pSysClientPosiLimit	要删除的CSysClientPosiLimit
	virtual void beforeRemove(CSysClientPosiLimit *pSysClientPosiLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitDumpTrigger是操作特殊客户限仓时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitDumpTrigger: public CSysSpecialPosiLimitActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysSpecialPosiLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysSpecialPosiLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysSpecialPosiLimit	要加入的SysSpecialPosiLimit
	virtual void beforeAdd(CWriteableSysSpecialPosiLimit *pSysSpecialPosiLimit);
	
	///更新前触发	
	///@param	pSysSpecialPosiLimit	被刷新的CSysSpecialPosiLimit
	///@param	pNewSysSpecialPosiLimit	新的值
	virtual void beforeUpdate(CSysSpecialPosiLimit *pSysSpecialPosiLimit, CWriteableSysSpecialPosiLimit *pNewSysSpecialPosiLimit);
	
	///删除前触发
	///@param	pSysSpecialPosiLimit	要删除的CSysSpecialPosiLimit
	virtual void beforeRemove(CSysSpecialPosiLimit *pSysSpecialPosiLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgDumpTrigger是操作账户出入金查询时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgDumpTrigger: public CSysTransactionChgActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysTransactionChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysTransactionChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysTransactionChg	要加入的SysTransactionChg
	virtual void beforeAdd(CWriteableSysTransactionChg *pSysTransactionChg);
	
	///更新前触发	
	///@param	pSysTransactionChg	被刷新的CSysTransactionChg
	///@param	pNewSysTransactionChg	新的值
	virtual void beforeUpdate(CSysTransactionChg *pSysTransactionChg, CWriteableSysTransactionChg *pNewSysTransactionChg);
	
	///删除前触发
	///@param	pSysTransactionChg	要删除的CSysTransactionChg
	virtual void beforeRemove(CSysTransactionChg *pSysTransactionChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgDumpTrigger是操作客户数据变动查询时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgDumpTrigger: public CSysClientChgActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysClientChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysClientChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysClientChg	要加入的SysClientChg
	virtual void beforeAdd(CWriteableSysClientChg *pSysClientChg);
	
	///更新前触发	
	///@param	pSysClientChg	被刷新的CSysClientChg
	///@param	pNewSysClientChg	新的值
	virtual void beforeUpdate(CSysClientChg *pSysClientChg, CWriteableSysClientChg *pNewSysClientChg);
	
	///删除前触发
	///@param	pSysClientChg	要删除的CSysClientChg
	virtual void beforeRemove(CSysClientChg *pSysClientChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgDumpTrigger是操作会员客户对照变动查询时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgDumpTrigger: public CSysPartClientChgActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysPartClientChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysPartClientChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysPartClientChg	要加入的SysPartClientChg
	virtual void beforeAdd(CWriteableSysPartClientChg *pSysPartClientChg);
	
	///更新前触发	
	///@param	pSysPartClientChg	被刷新的CSysPartClientChg
	///@param	pNewSysPartClientChg	新的值
	virtual void beforeUpdate(CSysPartClientChg *pSysPartClientChg, CWriteableSysPartClientChg *pNewSysPartClientChg);
	
	///删除前触发
	///@param	pSysPartClientChg	要删除的CSysPartClientChg
	virtual void beforeRemove(CSysPartClientChg *pSysPartClientChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgDumpTrigger是操作限仓数据变动查询时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgDumpTrigger: public CSysPosiLimitChgActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysPosiLimitChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysPosiLimitChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysPosiLimitChg	要加入的SysPosiLimitChg
	virtual void beforeAdd(CWriteableSysPosiLimitChg *pSysPosiLimitChg);
	
	///更新前触发	
	///@param	pSysPosiLimitChg	被刷新的CSysPosiLimitChg
	///@param	pNewSysPosiLimitChg	新的值
	virtual void beforeUpdate(CSysPosiLimitChg *pSysPosiLimitChg, CWriteableSysPosiLimitChg *pNewSysPosiLimitChg);
	
	///删除前触发
	///@param	pSysPosiLimitChg	要删除的CSysPosiLimitChg
	virtual void beforeRemove(CSysPosiLimitChg *pSysPosiLimitChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgDumpTrigger是操作限仓数据变动查询时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgDumpTrigger: public CSysClientPosiLimitChgActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysClientPosiLimitChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysClientPosiLimitChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysClientPosiLimitChg	要加入的SysClientPosiLimitChg
	virtual void beforeAdd(CWriteableSysClientPosiLimitChg *pSysClientPosiLimitChg);
	
	///更新前触发	
	///@param	pSysClientPosiLimitChg	被刷新的CSysClientPosiLimitChg
	///@param	pNewSysClientPosiLimitChg	新的值
	virtual void beforeUpdate(CSysClientPosiLimitChg *pSysClientPosiLimitChg, CWriteableSysClientPosiLimitChg *pNewSysClientPosiLimitChg);
	
	///删除前触发
	///@param	pSysClientPosiLimitChg	要删除的CSysClientPosiLimitChg
	virtual void beforeRemove(CSysClientPosiLimitChg *pSysClientPosiLimitChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgDumpTrigger是操作限仓数据变动查询时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgDumpTrigger: public CSysSpecPosiLimitChgActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysSpecPosiLimitChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysSpecPosiLimitChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysSpecPosiLimitChg	要加入的SysSpecPosiLimitChg
	virtual void beforeAdd(CWriteableSysSpecPosiLimitChg *pSysSpecPosiLimitChg);
	
	///更新前触发	
	///@param	pSysSpecPosiLimitChg	被刷新的CSysSpecPosiLimitChg
	///@param	pNewSysSpecPosiLimitChg	新的值
	virtual void beforeUpdate(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg, CWriteableSysSpecPosiLimitChg *pNewSysSpecPosiLimitChg);
	
	///删除前触发
	///@param	pSysSpecPosiLimitChg	要删除的CSysSpecPosiLimitChg
	virtual void beforeRemove(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgDumpTrigger是操作保值额度变动查询时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgDumpTrigger: public CSysHedgeDetailChgActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysHedgeDetailChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysHedgeDetailChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysHedgeDetailChg	要加入的SysHedgeDetailChg
	virtual void beforeAdd(CWriteableSysHedgeDetailChg *pSysHedgeDetailChg);
	
	///更新前触发	
	///@param	pSysHedgeDetailChg	被刷新的CSysHedgeDetailChg
	///@param	pNewSysHedgeDetailChg	新的值
	virtual void beforeUpdate(CSysHedgeDetailChg *pSysHedgeDetailChg, CWriteableSysHedgeDetailChg *pNewSysHedgeDetailChg);
	
	///删除前触发
	///@param	pSysHedgeDetailChg	要删除的CSysHedgeDetailChg
	virtual void beforeRemove(CSysHedgeDetailChg *pSysHedgeDetailChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgDumpTrigger是操作会员变动查询时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgDumpTrigger: public CSysParticipantChgActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysParticipantChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysParticipantChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysParticipantChg	要加入的SysParticipantChg
	virtual void beforeAdd(CWriteableSysParticipantChg *pSysParticipantChg);
	
	///更新前触发	
	///@param	pSysParticipantChg	被刷新的CSysParticipantChg
	///@param	pNewSysParticipantChg	新的值
	virtual void beforeUpdate(CSysParticipantChg *pSysParticipantChg, CWriteableSysParticipantChg *pNewSysParticipantChg);
	
	///删除前触发
	///@param	pSysParticipantChg	要删除的CSysParticipantChg
	virtual void beforeRemove(CSysParticipantChg *pSysParticipantChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgDumpTrigger是操作保证金率变动查询时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgDumpTrigger: public CSysMarginRateChgActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMarginRateChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMarginRateChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMarginRateChg	要加入的SysMarginRateChg
	virtual void beforeAdd(CWriteableSysMarginRateChg *pSysMarginRateChg);
	
	///更新前触发	
	///@param	pSysMarginRateChg	被刷新的CSysMarginRateChg
	///@param	pNewSysMarginRateChg	新的值
	virtual void beforeUpdate(CSysMarginRateChg *pSysMarginRateChg, CWriteableSysMarginRateChg *pNewSysMarginRateChg);
	
	///删除前触发
	///@param	pSysMarginRateChg	要删除的CSysMarginRateChg
	virtual void beforeRemove(CSysMarginRateChg *pSysMarginRateChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgDumpTrigger是操作IP地址变动查询时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgDumpTrigger: public CSysUserIpChgActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysUserIpChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysUserIpChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysUserIpChg	要加入的SysUserIpChg
	virtual void beforeAdd(CWriteableSysUserIpChg *pSysUserIpChg);
	
	///更新前触发	
	///@param	pSysUserIpChg	被刷新的CSysUserIpChg
	///@param	pNewSysUserIpChg	新的值
	virtual void beforeUpdate(CSysUserIpChg *pSysUserIpChg, CWriteableSysUserIpChg *pNewSysUserIpChg);
	
	///删除前触发
	///@param	pSysUserIpChg	要删除的CSysUserIpChg
	virtual void beforeRemove(CSysUserIpChg *pSysUserIpChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeDumpTrigger是操作会员交易信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeDumpTrigger: public CSysPartTradeActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysPartTradeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysPartTradeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysPartTrade	要加入的SysPartTrade
	virtual void beforeAdd(CWriteableSysPartTrade *pSysPartTrade);
	
	///更新前触发	
	///@param	pSysPartTrade	被刷新的CSysPartTrade
	///@param	pNewSysPartTrade	新的值
	virtual void beforeUpdate(CSysPartTrade *pSysPartTrade, CWriteableSysPartTrade *pNewSysPartTrade);
	
	///删除前触发
	///@param	pSysPartTrade	要删除的CSysPartTrade
	virtual void beforeRemove(CSysPartTrade *pSysPartTrade);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrDumpTrigger是操作对象状态指标时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrDumpTrigger: public CSysMdbObjectAttrActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMdbObjectAttrDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMdbObjectAttrDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMdbObjectAttr	要加入的SysMdbObjectAttr
	virtual void beforeAdd(CWriteableSysMdbObjectAttr *pSysMdbObjectAttr);
	
	///更新前触发	
	///@param	pSysMdbObjectAttr	被刷新的CSysMdbObjectAttr
	///@param	pNewSysMdbObjectAttr	新的值
	virtual void beforeUpdate(CSysMdbObjectAttr *pSysMdbObjectAttr, CWriteableSysMdbObjectAttr *pNewSysMdbObjectAttr);
	
	///删除前触发
	///@param	pSysMdbObjectAttr	要删除的CSysMdbObjectAttr
	virtual void beforeRemove(CSysMdbObjectAttr *pSysMdbObjectAttr);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoDumpTrigger是操作日志文件内容传输信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoDumpTrigger: public CSysMdbSyslogInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMdbSyslogInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMdbSyslogInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMdbSyslogInfo	要加入的SysMdbSyslogInfo
	virtual void beforeAdd(CWriteableSysMdbSyslogInfo *pSysMdbSyslogInfo);
	
	///更新前触发	
	///@param	pSysMdbSyslogInfo	被刷新的CSysMdbSyslogInfo
	///@param	pNewSysMdbSyslogInfo	新的值
	virtual void beforeUpdate(CSysMdbSyslogInfo *pSysMdbSyslogInfo, CWriteableSysMdbSyslogInfo *pNewSysMdbSyslogInfo);
	
	///删除前触发
	///@param	pSysMdbSyslogInfo	要删除的CSysMdbSyslogInfo
	virtual void beforeRemove(CSysMdbSyslogInfo *pSysMdbSyslogInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoDumpTrigger是操作用户信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoDumpTrigger: public CSysUserInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysUserInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysUserInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysUserInfo	要加入的SysUserInfo
	virtual void beforeAdd(CWriteableSysUserInfo *pSysUserInfo);
	
	///更新前触发	
	///@param	pSysUserInfo	被刷新的CSysUserInfo
	///@param	pNewSysUserInfo	新的值
	virtual void beforeUpdate(CSysUserInfo *pSysUserInfo, CWriteableSysUserInfo *pNewSysUserInfo);
	
	///删除前触发
	///@param	pSysUserInfo	要删除的CSysUserInfo
	virtual void beforeRemove(CSysUserInfo *pSysUserInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoDumpTrigger是操作在线用户信息查询应答时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoDumpTrigger: public CSysOnlineUserInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysOnlineUserInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysOnlineUserInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysOnlineUserInfo	要加入的SysOnlineUserInfo
	virtual void beforeAdd(CWriteableSysOnlineUserInfo *pSysOnlineUserInfo);
	
	///更新前触发	
	///@param	pSysOnlineUserInfo	被刷新的CSysOnlineUserInfo
	///@param	pNewSysOnlineUserInfo	新的值
	virtual void beforeUpdate(CSysOnlineUserInfo *pSysOnlineUserInfo, CWriteableSysOnlineUserInfo *pNewSysOnlineUserInfo);
	
	///删除前触发
	///@param	pSysOnlineUserInfo	要删除的CSysOnlineUserInfo
	virtual void beforeRemove(CSysOnlineUserInfo *pSysOnlineUserInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventDumpTrigger是操作告警事件查询应答时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventDumpTrigger: public CSysWarningEventActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysWarningEventDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysWarningEventDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysWarningEvent	要加入的SysWarningEvent
	virtual void beforeAdd(CWriteableSysWarningEvent *pSysWarningEvent);
	
	///更新前触发	
	///@param	pSysWarningEvent	被刷新的CSysWarningEvent
	///@param	pNewSysWarningEvent	新的值
	virtual void beforeUpdate(CSysWarningEvent *pSysWarningEvent, CWriteableSysWarningEvent *pNewSysWarningEvent);
	
	///删除前触发
	///@param	pSysWarningEvent	要删除的CSysWarningEvent
	virtual void beforeRemove(CSysWarningEvent *pSysWarningEvent);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryDumpTrigger是操作告警明细应答时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryDumpTrigger: public CSysWarningQueryActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysWarningQueryDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysWarningQueryDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysWarningQuery	要加入的SysWarningQuery
	virtual void beforeAdd(CWriteableSysWarningQuery *pSysWarningQuery);
	
	///更新前触发	
	///@param	pSysWarningQuery	被刷新的CSysWarningQuery
	///@param	pNewSysWarningQuery	新的值
	virtual void beforeUpdate(CSysWarningQuery *pSysWarningQuery, CWriteableSysWarningQuery *pNewSysWarningQuery);
	
	///删除前触发
	///@param	pSysWarningQuery	要删除的CSysWarningQuery
	virtual void beforeRemove(CSysWarningQuery *pSysWarningQuery);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventDumpTrigger是操作日志事件查询应答时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventDumpTrigger: public CSyslogEventActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSyslogEventDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSyslogEventDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSyslogEvent	要加入的SyslogEvent
	virtual void beforeAdd(CWriteableSyslogEvent *pSyslogEvent);
	
	///更新前触发	
	///@param	pSyslogEvent	被刷新的CSyslogEvent
	///@param	pNewSyslogEvent	新的值
	virtual void beforeUpdate(CSyslogEvent *pSyslogEvent, CWriteableSyslogEvent *pNewSyslogEvent);
	
	///删除前触发
	///@param	pSyslogEvent	要删除的CSyslogEvent
	virtual void beforeRemove(CSyslogEvent *pSyslogEvent);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripDumpTrigger是操作事件描述查询时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripDumpTrigger: public CSysEventDescripActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysEventDescripDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysEventDescripDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysEventDescrip	要加入的SysEventDescrip
	virtual void beforeAdd(CWriteableSysEventDescrip *pSysEventDescrip);
	
	///更新前触发	
	///@param	pSysEventDescrip	被刷新的CSysEventDescrip
	///@param	pNewSysEventDescrip	新的值
	virtual void beforeUpdate(CSysEventDescrip *pSysEventDescrip, CWriteableSysEventDescrip *pNewSysEventDescrip);
	
	///删除前触发
	///@param	pSysEventDescrip	要删除的CSysEventDescrip
	virtual void beforeRemove(CSysEventDescrip *pSysEventDescrip);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonDumpTrigger是操作主机环境信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonDumpTrigger: public CRspQryHostEnvCommonActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CRspQryHostEnvCommonDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CRspQryHostEnvCommonDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pRspQryHostEnvCommon	要加入的RspQryHostEnvCommon
	virtual void beforeAdd(CWriteableRspQryHostEnvCommon *pRspQryHostEnvCommon);
	
	///更新前触发	
	///@param	pRspQryHostEnvCommon	被刷新的CRspQryHostEnvCommon
	///@param	pNewRspQryHostEnvCommon	新的值
	virtual void beforeUpdate(CRspQryHostEnvCommon *pRspQryHostEnvCommon, CWriteableRspQryHostEnvCommon *pNewRspQryHostEnvCommon);
	
	///删除前触发
	///@param	pRspQryHostEnvCommon	要删除的CRspQryHostEnvCommon
	virtual void beforeRemove(CRspQryHostEnvCommon *pRspQryHostEnvCommon);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanDumpTrigger是操作主机环境Lan信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanDumpTrigger: public CRspQryHostEnvLanActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CRspQryHostEnvLanDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CRspQryHostEnvLanDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pRspQryHostEnvLan	要加入的RspQryHostEnvLan
	virtual void beforeAdd(CWriteableRspQryHostEnvLan *pRspQryHostEnvLan);
	
	///更新前触发	
	///@param	pRspQryHostEnvLan	被刷新的CRspQryHostEnvLan
	///@param	pNewRspQryHostEnvLan	新的值
	virtual void beforeUpdate(CRspQryHostEnvLan *pRspQryHostEnvLan, CWriteableRspQryHostEnvLan *pNewRspQryHostEnvLan);
	
	///删除前触发
	///@param	pRspQryHostEnvLan	要删除的CRspQryHostEnvLan
	virtual void beforeRemove(CRspQryHostEnvLan *pRspQryHostEnvLan);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageDumpTrigger是操作主机环境存储设备信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageDumpTrigger: public CRspQryHostEnvStorageActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CRspQryHostEnvStorageDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CRspQryHostEnvStorageDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pRspQryHostEnvStorage	要加入的RspQryHostEnvStorage
	virtual void beforeAdd(CWriteableRspQryHostEnvStorage *pRspQryHostEnvStorage);
	
	///更新前触发	
	///@param	pRspQryHostEnvStorage	被刷新的CRspQryHostEnvStorage
	///@param	pNewRspQryHostEnvStorage	新的值
	virtual void beforeUpdate(CRspQryHostEnvStorage *pRspQryHostEnvStorage, CWriteableRspQryHostEnvStorage *pNewRspQryHostEnvStorage);
	
	///删除前触发
	///@param	pRspQryHostEnvStorage	要删除的CRspQryHostEnvStorage
	virtual void beforeRemove(CRspQryHostEnvStorage *pRspQryHostEnvStorage);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIODumpTrigger是操作主机环境IO设备信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIODumpTrigger: public CRspQryHostEnvIOActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CRspQryHostEnvIODumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CRspQryHostEnvIODumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pRspQryHostEnvIO	要加入的RspQryHostEnvIO
	virtual void beforeAdd(CWriteableRspQryHostEnvIO *pRspQryHostEnvIO);
	
	///更新前触发	
	///@param	pRspQryHostEnvIO	被刷新的CRspQryHostEnvIO
	///@param	pNewRspQryHostEnvIO	新的值
	virtual void beforeUpdate(CRspQryHostEnvIO *pRspQryHostEnvIO, CWriteableRspQryHostEnvIO *pNewRspQryHostEnvIO);
	
	///删除前触发
	///@param	pRspQryHostEnvIO	要删除的CRspQryHostEnvIO
	virtual void beforeRemove(CRspQryHostEnvIO *pRspQryHostEnvIO);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSDumpTrigger是操作主机环境文件系统信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSDumpTrigger: public CRspQryHostEnvFSActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CRspQryHostEnvFSDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CRspQryHostEnvFSDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pRspQryHostEnvFS	要加入的RspQryHostEnvFS
	virtual void beforeAdd(CWriteableRspQryHostEnvFS *pRspQryHostEnvFS);
	
	///更新前触发	
	///@param	pRspQryHostEnvFS	被刷新的CRspQryHostEnvFS
	///@param	pNewRspQryHostEnvFS	新的值
	virtual void beforeUpdate(CRspQryHostEnvFS *pRspQryHostEnvFS, CWriteableRspQryHostEnvFS *pNewRspQryHostEnvFS);
	
	///删除前触发
	///@param	pRspQryHostEnvFS	要删除的CRspQryHostEnvFS
	virtual void beforeRemove(CRspQryHostEnvFS *pRspQryHostEnvFS);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapDumpTrigger是操作主机环境交换分区信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapDumpTrigger: public CRspQryHostEnvSwapActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CRspQryHostEnvSwapDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CRspQryHostEnvSwapDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pRspQryHostEnvSwap	要加入的RspQryHostEnvSwap
	virtual void beforeAdd(CWriteableRspQryHostEnvSwap *pRspQryHostEnvSwap);
	
	///更新前触发	
	///@param	pRspQryHostEnvSwap	被刷新的CRspQryHostEnvSwap
	///@param	pNewRspQryHostEnvSwap	新的值
	virtual void beforeUpdate(CRspQryHostEnvSwap *pRspQryHostEnvSwap, CWriteableRspQryHostEnvSwap *pNewRspQryHostEnvSwap);
	
	///删除前触发
	///@param	pRspQryHostEnvSwap	要删除的CRspQryHostEnvSwap
	virtual void beforeRemove(CRspQryHostEnvSwap *pRspQryHostEnvSwap);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgDumpTrigger是操作主机环境网卡配置信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgDumpTrigger: public CRspQryHostEnvLanCfgActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CRspQryHostEnvLanCfgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CRspQryHostEnvLanCfgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pRspQryHostEnvLanCfg	要加入的RspQryHostEnvLanCfg
	virtual void beforeAdd(CWriteableRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg);
	
	///更新前触发	
	///@param	pRspQryHostEnvLanCfg	被刷新的CRspQryHostEnvLanCfg
	///@param	pNewRspQryHostEnvLanCfg	新的值
	virtual void beforeUpdate(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, CWriteableRspQryHostEnvLanCfg *pNewRspQryHostEnvLanCfg);
	
	///删除前触发
	///@param	pRspQryHostEnvLanCfg	要删除的CRspQryHostEnvLanCfg
	virtual void beforeRemove(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoDumpTrigger是操作CPU资源使用信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoDumpTrigger: public CSysMdbTopCpuInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMdbTopCpuInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMdbTopCpuInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMdbTopCpuInfo	要加入的SysMdbTopCpuInfo
	virtual void beforeAdd(CWriteableSysMdbTopCpuInfo *pSysMdbTopCpuInfo);
	
	///更新前触发	
	///@param	pSysMdbTopCpuInfo	被刷新的CSysMdbTopCpuInfo
	///@param	pNewSysMdbTopCpuInfo	新的值
	virtual void beforeUpdate(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo, CWriteableSysMdbTopCpuInfo *pNewSysMdbTopCpuInfo);
	
	///删除前触发
	///@param	pSysMdbTopCpuInfo	要删除的CSysMdbTopCpuInfo
	virtual void beforeRemove(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoDumpTrigger是操作内存资源使用信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoDumpTrigger: public CSysMdbTopMemInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMdbTopMemInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMdbTopMemInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMdbTopMemInfo	要加入的SysMdbTopMemInfo
	virtual void beforeAdd(CWriteableSysMdbTopMemInfo *pSysMdbTopMemInfo);
	
	///更新前触发	
	///@param	pSysMdbTopMemInfo	被刷新的CSysMdbTopMemInfo
	///@param	pNewSysMdbTopMemInfo	新的值
	virtual void beforeUpdate(CSysMdbTopMemInfo *pSysMdbTopMemInfo, CWriteableSysMdbTopMemInfo *pNewSysMdbTopMemInfo);
	
	///删除前触发
	///@param	pSysMdbTopMemInfo	要删除的CSysMdbTopMemInfo
	virtual void beforeRemove(CSysMdbTopMemInfo *pSysMdbTopMemInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoDumpTrigger是操作进程信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoDumpTrigger: public CSysMdbTopProcessInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMdbTopProcessInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMdbTopProcessInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMdbTopProcessInfo	要加入的SysMdbTopProcessInfo
	virtual void beforeAdd(CWriteableSysMdbTopProcessInfo *pSysMdbTopProcessInfo);
	
	///更新前触发	
	///@param	pSysMdbTopProcessInfo	被刷新的CSysMdbTopProcessInfo
	///@param	pNewSysMdbTopProcessInfo	新的值
	virtual void beforeUpdate(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo, CWriteableSysMdbTopProcessInfo *pNewSysMdbTopProcessInfo);
	
	///删除前触发
	///@param	pSysMdbTopProcessInfo	要删除的CSysMdbTopProcessInfo
	virtual void beforeRemove(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoDumpTrigger是操作文件系统信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoDumpTrigger: public CSysMdbFileSystemInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMdbFileSystemInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMdbFileSystemInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMdbFileSystemInfo	要加入的SysMdbFileSystemInfo
	virtual void beforeAdd(CWriteableSysMdbFileSystemInfo *pSysMdbFileSystemInfo);
	
	///更新前触发	
	///@param	pSysMdbFileSystemInfo	被刷新的CSysMdbFileSystemInfo
	///@param	pNewSysMdbFileSystemInfo	新的值
	virtual void beforeUpdate(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo, CWriteableSysMdbFileSystemInfo *pNewSysMdbFileSystemInfo);
	
	///删除前触发
	///@param	pSysMdbFileSystemInfo	要删除的CSysMdbFileSystemInfo
	virtual void beforeRemove(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoDumpTrigger是操作网络使用信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoDumpTrigger: public CSysMdbNetworkInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMdbNetworkInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMdbNetworkInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMdbNetworkInfo	要加入的SysMdbNetworkInfo
	virtual void beforeAdd(CWriteableSysMdbNetworkInfo *pSysMdbNetworkInfo);
	
	///更新前触发	
	///@param	pSysMdbNetworkInfo	被刷新的CSysMdbNetworkInfo
	///@param	pNewSysMdbNetworkInfo	新的值
	virtual void beforeUpdate(CSysMdbNetworkInfo *pSysMdbNetworkInfo, CWriteableSysMdbNetworkInfo *pNewSysMdbNetworkInfo);
	
	///删除前触发
	///@param	pSysMdbNetworkInfo	要删除的CSysMdbNetworkInfo
	virtual void beforeRemove(CSysMdbNetworkInfo *pSysMdbNetworkInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitDumpTrigger是操作会员时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitDumpTrigger: public CSysParticipantInitActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysParticipantInitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysParticipantInitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysParticipantInit	要加入的SysParticipantInit
	virtual void beforeAdd(CWriteableSysParticipantInit *pSysParticipantInit);
	
	///更新前触发	
	///@param	pSysParticipantInit	被刷新的CSysParticipantInit
	///@param	pNewSysParticipantInit	新的值
	virtual void beforeUpdate(CSysParticipantInit *pSysParticipantInit, CWriteableSysParticipantInit *pNewSysParticipantInit);
	
	///删除前触发
	///@param	pSysParticipantInit	要删除的CSysParticipantInit
	virtual void beforeRemove(CSysParticipantInit *pSysParticipantInit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitDumpTrigger是操作交易用户时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitDumpTrigger: public CSysUserInitActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysUserInitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysUserInitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysUserInit	要加入的SysUserInit
	virtual void beforeAdd(CWriteableSysUserInit *pSysUserInit);
	
	///更新前触发	
	///@param	pSysUserInit	被刷新的CSysUserInit
	///@param	pNewSysUserInit	新的值
	virtual void beforeUpdate(CSysUserInit *pSysUserInit, CWriteableSysUserInit *pNewSysUserInit);
	
	///删除前触发
	///@param	pSysUserInit	要删除的CSysUserInit
	virtual void beforeRemove(CSysUserInit *pSysUserInit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitDumpTrigger是操作客户时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitDumpTrigger: public CSysClientInitActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysClientInitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysClientInitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysClientInit	要加入的SysClientInit
	virtual void beforeAdd(CWriteableSysClientInit *pSysClientInit);
	
	///更新前触发	
	///@param	pSysClientInit	被刷新的CSysClientInit
	///@param	pNewSysClientInit	新的值
	virtual void beforeUpdate(CSysClientInit *pSysClientInit, CWriteableSysClientInit *pNewSysClientInit);
	
	///删除前触发
	///@param	pSysClientInit	要删除的CSysClientInit
	virtual void beforeRemove(CSysClientInit *pSysClientInit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoDumpTrigger是操作交易系统登录信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoDumpTrigger: public CSysTradeUserLoginInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysTradeUserLoginInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysTradeUserLoginInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysTradeUserLoginInfo	要加入的SysTradeUserLoginInfo
	virtual void beforeAdd(CWriteableSysTradeUserLoginInfo *pSysTradeUserLoginInfo);
	
	///更新前触发	
	///@param	pSysTradeUserLoginInfo	被刷新的CSysTradeUserLoginInfo
	///@param	pNewSysTradeUserLoginInfo	新的值
	virtual void beforeUpdate(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo, CWriteableSysTradeUserLoginInfo *pNewSysTradeUserLoginInfo);
	
	///删除前触发
	///@param	pSysTradeUserLoginInfo	要删除的CSysTradeUserLoginInfo
	virtual void beforeRemove(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoDumpTrigger是操作Web应用信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoDumpTrigger: public CSysMdbWebAppInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMdbWebAppInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMdbWebAppInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMdbWebAppInfo	要加入的SysMdbWebAppInfo
	virtual void beforeAdd(CWriteableSysMdbWebAppInfo *pSysMdbWebAppInfo);
	
	///更新前触发	
	///@param	pSysMdbWebAppInfo	被刷新的CSysMdbWebAppInfo
	///@param	pNewSysMdbWebAppInfo	新的值
	virtual void beforeUpdate(CSysMdbWebAppInfo *pSysMdbWebAppInfo, CWriteableSysMdbWebAppInfo *pNewSysMdbWebAppInfo);
	
	///删除前触发
	///@param	pSysMdbWebAppInfo	要删除的CSysMdbWebAppInfo
	virtual void beforeRemove(CSysMdbWebAppInfo *pSysMdbWebAppInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoDumpTrigger是操作系统内存池信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoDumpTrigger: public CSysMdbMemPoolInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMdbMemPoolInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMdbMemPoolInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMdbMemPoolInfo	要加入的SysMdbMemPoolInfo
	virtual void beforeAdd(CWriteableSysMdbMemPoolInfo *pSysMdbMemPoolInfo);
	
	///更新前触发	
	///@param	pSysMdbMemPoolInfo	被刷新的CSysMdbMemPoolInfo
	///@param	pNewSysMdbMemPoolInfo	新的值
	virtual void beforeUpdate(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo, CWriteableSysMdbMemPoolInfo *pNewSysMdbMemPoolInfo);
	
	///删除前触发
	///@param	pSysMdbMemPoolInfo	要删除的CSysMdbMemPoolInfo
	virtual void beforeRemove(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoDumpTrigger是操作连接器信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoDumpTrigger: public CSysMdbConnectorInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMdbConnectorInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMdbConnectorInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMdbConnectorInfo	要加入的SysMdbConnectorInfo
	virtual void beforeAdd(CWriteableSysMdbConnectorInfo *pSysMdbConnectorInfo);
	
	///更新前触发	
	///@param	pSysMdbConnectorInfo	被刷新的CSysMdbConnectorInfo
	///@param	pNewSysMdbConnectorInfo	新的值
	virtual void beforeUpdate(CSysMdbConnectorInfo *pSysMdbConnectorInfo, CWriteableSysMdbConnectorInfo *pNewSysMdbConnectorInfo);
	
	///删除前触发
	///@param	pSysMdbConnectorInfo	要删除的CSysMdbConnectorInfo
	virtual void beforeRemove(CSysMdbConnectorInfo *pSysMdbConnectorInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryDumpTrigger是操作数据库查询应答时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryDumpTrigger: public CSysMdbDBQueryActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMdbDBQueryDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMdbDBQueryDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMdbDBQuery	要加入的SysMdbDBQuery
	virtual void beforeAdd(CWriteableSysMdbDBQuery *pSysMdbDBQuery);
	
	///更新前触发	
	///@param	pSysMdbDBQuery	被刷新的CSysMdbDBQuery
	///@param	pNewSysMdbDBQuery	新的值
	virtual void beforeUpdate(CSysMdbDBQuery *pSysMdbDBQuery, CWriteableSysMdbDBQuery *pNewSysMdbDBQuery);
	
	///删除前触发
	///@param	pSysMdbDBQuery	要删除的CSysMdbDBQuery
	virtual void beforeRemove(CSysMdbDBQuery *pSysMdbDBQuery);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaDumpTrigger是操作网络大区划分时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaDumpTrigger: public CSysNetAreaActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetAreaDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetAreaDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetArea	要加入的SysNetArea
	virtual void beforeAdd(CWriteableSysNetArea *pSysNetArea);
	
	///更新前触发	
	///@param	pSysNetArea	被刷新的CSysNetArea
	///@param	pNewSysNetArea	新的值
	virtual void beforeUpdate(CSysNetArea *pSysNetArea, CWriteableSysNetArea *pNewSysNetArea);
	
	///删除前触发
	///@param	pSysNetArea	要删除的CSysNetArea
	virtual void beforeRemove(CSysNetArea *pSysNetArea);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaDumpTrigger是操作网络子区时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaDumpTrigger: public CSysNetSubAreaActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetSubAreaDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetSubAreaDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetSubArea	要加入的SysNetSubArea
	virtual void beforeAdd(CWriteableSysNetSubArea *pSysNetSubArea);
	
	///更新前触发	
	///@param	pSysNetSubArea	被刷新的CSysNetSubArea
	///@param	pNewSysNetSubArea	新的值
	virtual void beforeUpdate(CSysNetSubArea *pSysNetSubArea, CWriteableSysNetSubArea *pNewSysNetSubArea);
	
	///删除前触发
	///@param	pSysNetSubArea	要删除的CSysNetSubArea
	virtual void beforeRemove(CSysNetSubArea *pSysNetSubArea);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPDumpTrigger是操作网络子区IP时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPDumpTrigger: public CSysNetSubAreaIPActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetSubAreaIPDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetSubAreaIPDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetSubAreaIP	要加入的SysNetSubAreaIP
	virtual void beforeAdd(CWriteableSysNetSubAreaIP *pSysNetSubAreaIP);
	
	///更新前触发	
	///@param	pSysNetSubAreaIP	被刷新的CSysNetSubAreaIP
	///@param	pNewSysNetSubAreaIP	新的值
	virtual void beforeUpdate(CSysNetSubAreaIP *pSysNetSubAreaIP, CWriteableSysNetSubAreaIP *pNewSysNetSubAreaIP);
	
	///删除前触发
	///@param	pSysNetSubAreaIP	要删除的CSysNetSubAreaIP
	virtual void beforeRemove(CSysNetSubAreaIP *pSysNetSubAreaIP);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaDumpTrigger是操作职能区时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaDumpTrigger: public CSysNetFuncAreaActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetFuncAreaDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetFuncAreaDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetFuncArea	要加入的SysNetFuncArea
	virtual void beforeAdd(CWriteableSysNetFuncArea *pSysNetFuncArea);
	
	///更新前触发	
	///@param	pSysNetFuncArea	被刷新的CSysNetFuncArea
	///@param	pNewSysNetFuncArea	新的值
	virtual void beforeUpdate(CSysNetFuncArea *pSysNetFuncArea, CWriteableSysNetFuncArea *pNewSysNetFuncArea);
	
	///删除前触发
	///@param	pSysNetFuncArea	要删除的CSysNetFuncArea
	virtual void beforeRemove(CSysNetFuncArea *pSysNetFuncArea);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceDumpTrigger是操作网络设备时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceDumpTrigger: public CSysNetDeviceActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetDeviceDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetDeviceDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetDevice	要加入的SysNetDevice
	virtual void beforeAdd(CWriteableSysNetDevice *pSysNetDevice);
	
	///更新前触发	
	///@param	pSysNetDevice	被刷新的CSysNetDevice
	///@param	pNewSysNetDevice	新的值
	virtual void beforeUpdate(CSysNetDevice *pSysNetDevice, CWriteableSysNetDevice *pNewSysNetDevice);
	
	///删除前触发
	///@param	pSysNetDevice	要删除的CSysNetDevice
	virtual void beforeRemove(CSysNetDevice *pSysNetDevice);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedDumpTrigger是操作网络设备连接关系时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedDumpTrigger: public CSysNetDeviceLinkedActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetDeviceLinkedDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetDeviceLinkedDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetDeviceLinked	要加入的SysNetDeviceLinked
	virtual void beforeAdd(CWriteableSysNetDeviceLinked *pSysNetDeviceLinked);
	
	///更新前触发	
	///@param	pSysNetDeviceLinked	被刷新的CSysNetDeviceLinked
	///@param	pNewSysNetDeviceLinked	新的值
	virtual void beforeUpdate(CSysNetDeviceLinked *pSysNetDeviceLinked, CWriteableSysNetDeviceLinked *pNewSysNetDeviceLinked);
	
	///删除前触发
	///@param	pSysNetDeviceLinked	要删除的CSysNetDeviceLinked
	virtual void beforeRemove(CSysNetDeviceLinked *pSysNetDeviceLinked);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDDumpTrigger是操作OID时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDDumpTrigger: public CSysNetOIDActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetOIDDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetOIDDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetOID	要加入的SysNetOID
	virtual void beforeAdd(CWriteableSysNetOID *pSysNetOID);
	
	///更新前触发	
	///@param	pSysNetOID	被刷新的CSysNetOID
	///@param	pNewSysNetOID	新的值
	virtual void beforeUpdate(CSysNetOID *pSysNetOID, CWriteableSysNetOID *pNewSysNetOID);
	
	///删除前触发
	///@param	pSysNetOID	要删除的CSysNetOID
	virtual void beforeRemove(CSysNetOID *pSysNetOID);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeDumpTrigger是操作网络设备类型时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeDumpTrigger: public CSysNetDeviceTypeActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetDeviceTypeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetDeviceTypeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetDeviceType	要加入的SysNetDeviceType
	virtual void beforeAdd(CWriteableSysNetDeviceType *pSysNetDeviceType);
	
	///更新前触发	
	///@param	pSysNetDeviceType	被刷新的CSysNetDeviceType
	///@param	pNewSysNetDeviceType	新的值
	virtual void beforeUpdate(CSysNetDeviceType *pSysNetDeviceType, CWriteableSysNetDeviceType *pNewSysNetDeviceType);
	
	///删除前触发
	///@param	pSysNetDeviceType	要删除的CSysNetDeviceType
	virtual void beforeRemove(CSysNetDeviceType *pSysNetDeviceType);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyDumpTrigger是操作时间策略时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyDumpTrigger: public CSysNetTimePolicyActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetTimePolicyDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetTimePolicyDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetTimePolicy	要加入的SysNetTimePolicy
	virtual void beforeAdd(CWriteableSysNetTimePolicy *pSysNetTimePolicy);
	
	///更新前触发	
	///@param	pSysNetTimePolicy	被刷新的CSysNetTimePolicy
	///@param	pNewSysNetTimePolicy	新的值
	virtual void beforeUpdate(CSysNetTimePolicy *pSysNetTimePolicy, CWriteableSysNetTimePolicy *pNewSysNetTimePolicy);
	
	///删除前触发
	///@param	pSysNetTimePolicy	要删除的CSysNetTimePolicy
	virtual void beforeRemove(CSysNetTimePolicy *pSysNetTimePolicy);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskDumpTrigger是操作采集任务时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskDumpTrigger: public CSysNetGatherTaskActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetGatherTaskDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetGatherTaskDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetGatherTask	要加入的SysNetGatherTask
	virtual void beforeAdd(CWriteableSysNetGatherTask *pSysNetGatherTask);
	
	///更新前触发	
	///@param	pSysNetGatherTask	被刷新的CSysNetGatherTask
	///@param	pNewSysNetGatherTask	新的值
	virtual void beforeUpdate(CSysNetGatherTask *pSysNetGatherTask, CWriteableSysNetGatherTask *pNewSysNetGatherTask);
	
	///删除前触发
	///@param	pSysNetGatherTask	要删除的CSysNetGatherTask
	virtual void beforeRemove(CSysNetGatherTask *pSysNetGatherTask);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryDumpTrigger是操作常用设备类别时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryDumpTrigger: public CSysNetDeviceCategoryActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetDeviceCategoryDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetDeviceCategoryDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetDeviceCategory	要加入的SysNetDeviceCategory
	virtual void beforeAdd(CWriteableSysNetDeviceCategory *pSysNetDeviceCategory);
	
	///更新前触发	
	///@param	pSysNetDeviceCategory	被刷新的CSysNetDeviceCategory
	///@param	pNewSysNetDeviceCategory	新的值
	virtual void beforeUpdate(CSysNetDeviceCategory *pSysNetDeviceCategory, CWriteableSysNetDeviceCategory *pNewSysNetDeviceCategory);
	
	///删除前触发
	///@param	pSysNetDeviceCategory	要删除的CSysNetDeviceCategory
	virtual void beforeRemove(CSysNetDeviceCategory *pSysNetDeviceCategory);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryDumpTrigger是操作设备厂商时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryDumpTrigger: public CSysNetManufactoryActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetManufactoryDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetManufactoryDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetManufactory	要加入的SysNetManufactory
	virtual void beforeAdd(CWriteableSysNetManufactory *pSysNetManufactory);
	
	///更新前触发	
	///@param	pSysNetManufactory	被刷新的CSysNetManufactory
	///@param	pNewSysNetManufactory	新的值
	virtual void beforeUpdate(CSysNetManufactory *pSysNetManufactory, CWriteableSysNetManufactory *pNewSysNetManufactory);
	
	///删除前触发
	///@param	pSysNetManufactory	要删除的CSysNetManufactory
	virtual void beforeRemove(CSysNetManufactory *pSysNetManufactory);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityDumpTrigger是操作设备共同体时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityDumpTrigger: public CSysNetCommunityActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetCommunityDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetCommunityDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetCommunity	要加入的SysNetCommunity
	virtual void beforeAdd(CWriteableSysNetCommunity *pSysNetCommunity);
	
	///更新前触发	
	///@param	pSysNetCommunity	被刷新的CSysNetCommunity
	///@param	pNewSysNetCommunity	新的值
	virtual void beforeUpdate(CSysNetCommunity *pSysNetCommunity, CWriteableSysNetCommunity *pNewSysNetCommunity);
	
	///删除前触发
	///@param	pSysNetCommunity	要删除的CSysNetCommunity
	virtual void beforeRemove(CSysNetCommunity *pSysNetCommunity);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeDumpTrigger是操作端口类型时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeDumpTrigger: public CSysNetPortTypeActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetPortTypeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetPortTypeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetPortType	要加入的SysNetPortType
	virtual void beforeAdd(CWriteableSysNetPortType *pSysNetPortType);
	
	///更新前触发	
	///@param	pSysNetPortType	被刷新的CSysNetPortType
	///@param	pNewSysNetPortType	新的值
	virtual void beforeUpdate(CSysNetPortType *pSysNetPortType, CWriteableSysNetPortType *pNewSysNetPortType);
	
	///删除前触发
	///@param	pSysNetPortType	要删除的CSysNetPortType
	virtual void beforeRemove(CSysNetPortType *pSysNetPortType);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceDumpTrigger是操作端口时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceDumpTrigger: public CSysNetInterfaceActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetInterfaceDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetInterfaceDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetInterface	要加入的SysNetInterface
	virtual void beforeAdd(CWriteableSysNetInterface *pSysNetInterface);
	
	///更新前触发	
	///@param	pSysNetInterface	被刷新的CSysNetInterface
	///@param	pNewSysNetInterface	新的值
	virtual void beforeUpdate(CSysNetInterface *pSysNetInterface, CWriteableSysNetInterface *pNewSysNetInterface);
	
	///删除前触发
	///@param	pSysNetInterface	要删除的CSysNetInterface
	virtual void beforeRemove(CSysNetInterface *pSysNetInterface);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDDumpTrigger是操作通用OID时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDDumpTrigger: public CSysNetGeneralOIDActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetGeneralOIDDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetGeneralOIDDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetGeneralOID	要加入的SysNetGeneralOID
	virtual void beforeAdd(CWriteableSysNetGeneralOID *pSysNetGeneralOID);
	
	///更新前触发	
	///@param	pSysNetGeneralOID	被刷新的CSysNetGeneralOID
	///@param	pNewSysNetGeneralOID	新的值
	virtual void beforeUpdate(CSysNetGeneralOID *pSysNetGeneralOID, CWriteableSysNetGeneralOID *pNewSysNetGeneralOID);
	
	///删除前触发
	///@param	pSysNetGeneralOID	要删除的CSysNetGeneralOID
	virtual void beforeRemove(CSysNetGeneralOID *pSysNetGeneralOID);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeDumpTrigger是操作监控对象类别时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeDumpTrigger: public CSysNetMonitorTypeActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetMonitorTypeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetMonitorTypeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetMonitorType	要加入的SysNetMonitorType
	virtual void beforeAdd(CWriteableSysNetMonitorType *pSysNetMonitorType);
	
	///更新前触发	
	///@param	pSysNetMonitorType	被刷新的CSysNetMonitorType
	///@param	pNewSysNetMonitorType	新的值
	virtual void beforeUpdate(CSysNetMonitorType *pSysNetMonitorType, CWriteableSysNetMonitorType *pNewSysNetMonitorType);
	
	///删除前触发
	///@param	pSysNetMonitorType	要删除的CSysNetMonitorType
	virtual void beforeRemove(CSysNetMonitorType *pSysNetMonitorType);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeDumpTrigger是操作指标统表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeDumpTrigger: public CSysNetMonitorAttrScopeActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetMonitorAttrScopeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetMonitorAttrScopeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetMonitorAttrScope	要加入的SysNetMonitorAttrScope
	virtual void beforeAdd(CWriteableSysNetMonitorAttrScope *pSysNetMonitorAttrScope);
	
	///更新前触发	
	///@param	pSysNetMonitorAttrScope	被刷新的CSysNetMonitorAttrScope
	///@param	pNewSysNetMonitorAttrScope	新的值
	virtual void beforeUpdate(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope, CWriteableSysNetMonitorAttrScope *pNewSysNetMonitorAttrScope);
	
	///删除前触发
	///@param	pSysNetMonitorAttrScope	要删除的CSysNetMonitorAttrScope
	virtual void beforeRemove(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeDumpTrigger是操作监控指标表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeDumpTrigger: public CSysNetMonitorAttrTypeActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetMonitorAttrTypeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetMonitorAttrTypeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetMonitorAttrType	要加入的SysNetMonitorAttrType
	virtual void beforeAdd(CWriteableSysNetMonitorAttrType *pSysNetMonitorAttrType);
	
	///更新前触发	
	///@param	pSysNetMonitorAttrType	被刷新的CSysNetMonitorAttrType
	///@param	pNewSysNetMonitorAttrType	新的值
	virtual void beforeUpdate(CSysNetMonitorAttrType *pSysNetMonitorAttrType, CWriteableSysNetMonitorAttrType *pNewSysNetMonitorAttrType);
	
	///删除前触发
	///@param	pSysNetMonitorAttrType	要删除的CSysNetMonitorAttrType
	virtual void beforeRemove(CSysNetMonitorAttrType *pSysNetMonitorAttrType);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeDumpTrigger是操作监控指令表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeDumpTrigger: public CSysNetMonitorCommandTypeActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetMonitorCommandTypeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetMonitorCommandTypeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetMonitorCommandType	要加入的SysNetMonitorCommandType
	virtual void beforeAdd(CWriteableSysNetMonitorCommandType *pSysNetMonitorCommandType);
	
	///更新前触发	
	///@param	pSysNetMonitorCommandType	被刷新的CSysNetMonitorCommandType
	///@param	pNewSysNetMonitorCommandType	新的值
	virtual void beforeUpdate(CSysNetMonitorCommandType *pSysNetMonitorCommandType, CWriteableSysNetMonitorCommandType *pNewSysNetMonitorCommandType);
	
	///删除前触发
	///@param	pSysNetMonitorCommandType	要删除的CSysNetMonitorCommandType
	virtual void beforeRemove(CSysNetMonitorCommandType *pSysNetMonitorCommandType);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupDumpTrigger是操作动作族表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupDumpTrigger: public CSysNetMonitorActionGroupActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetMonitorActionGroupDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetMonitorActionGroupDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetMonitorActionGroup	要加入的SysNetMonitorActionGroup
	virtual void beforeAdd(CWriteableSysNetMonitorActionGroup *pSysNetMonitorActionGroup);
	
	///更新前触发	
	///@param	pSysNetMonitorActionGroup	被刷新的CSysNetMonitorActionGroup
	///@param	pNewSysNetMonitorActionGroup	新的值
	virtual void beforeUpdate(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup, CWriteableSysNetMonitorActionGroup *pNewSysNetMonitorActionGroup);
	
	///删除前触发
	///@param	pSysNetMonitorActionGroup	要删除的CSysNetMonitorActionGroup
	virtual void beforeRemove(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupDumpTrigger是操作设备对象组表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupDumpTrigger: public CSysNetMonitorDeviceGroupActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetMonitorDeviceGroupDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetMonitorDeviceGroupDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetMonitorDeviceGroup	要加入的SysNetMonitorDeviceGroup
	virtual void beforeAdd(CWriteableSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup);
	
	///更新前触发	
	///@param	pSysNetMonitorDeviceGroup	被刷新的CSysNetMonitorDeviceGroup
	///@param	pNewSysNetMonitorDeviceGroup	新的值
	virtual void beforeUpdate(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, CWriteableSysNetMonitorDeviceGroup *pNewSysNetMonitorDeviceGroup);
	
	///删除前触发
	///@param	pSysNetMonitorDeviceGroup	要删除的CSysNetMonitorDeviceGroup
	virtual void beforeRemove(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoDumpTrigger是操作任务信息表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoDumpTrigger: public CSysNetMonitorTaskInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetMonitorTaskInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetMonitorTaskInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetMonitorTaskInfo	要加入的SysNetMonitorTaskInfo
	virtual void beforeAdd(CWriteableSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo);
	
	///更新前触发	
	///@param	pSysNetMonitorTaskInfo	被刷新的CSysNetMonitorTaskInfo
	///@param	pNewSysNetMonitorTaskInfo	新的值
	virtual void beforeUpdate(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, CWriteableSysNetMonitorTaskInfo *pNewSysNetMonitorTaskInfo);
	
	///删除前触发
	///@param	pSysNetMonitorTaskInfo	要删除的CSysNetMonitorTaskInfo
	virtual void beforeRemove(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetDumpTrigger是操作任务对象集时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetDumpTrigger: public CSysNetMonitorTaskObjectSetActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetMonitorTaskObjectSetDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetMonitorTaskObjectSetDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetMonitorTaskObjectSet	要加入的SysNetMonitorTaskObjectSet
	virtual void beforeAdd(CWriteableSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet);
	
	///更新前触发	
	///@param	pSysNetMonitorTaskObjectSet	被刷新的CSysNetMonitorTaskObjectSet
	///@param	pNewSysNetMonitorTaskObjectSet	新的值
	virtual void beforeUpdate(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, CWriteableSysNetMonitorTaskObjectSet *pNewSysNetMonitorTaskObjectSet);
	
	///删除前触发
	///@param	pSysNetMonitorTaskObjectSet	要删除的CSysNetMonitorTaskObjectSet
	virtual void beforeRemove(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultDumpTrigger是操作任务结果表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultDumpTrigger: public CSysNetMonitorTaskResultActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetMonitorTaskResultDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetMonitorTaskResultDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetMonitorTaskResult	要加入的SysNetMonitorTaskResult
	virtual void beforeAdd(CWriteableSysNetMonitorTaskResult *pSysNetMonitorTaskResult);
	
	///更新前触发	
	///@param	pSysNetMonitorTaskResult	被刷新的CSysNetMonitorTaskResult
	///@param	pNewSysNetMonitorTaskResult	新的值
	virtual void beforeUpdate(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult, CWriteableSysNetMonitorTaskResult *pNewSysNetMonitorTaskResult);
	
	///删除前触发
	///@param	pSysNetMonitorTaskResult	要删除的CSysNetMonitorTaskResult
	virtual void beforeRemove(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoDumpTrigger是操作会员链路信息表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoDumpTrigger: public CSysNetPartyLinkInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetPartyLinkInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetPartyLinkInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetPartyLinkInfo	要加入的SysNetPartyLinkInfo
	virtual void beforeAdd(CWriteableSysNetPartyLinkInfo *pSysNetPartyLinkInfo);
	
	///更新前触发	
	///@param	pSysNetPartyLinkInfo	被刷新的CSysNetPartyLinkInfo
	///@param	pNewSysNetPartyLinkInfo	新的值
	virtual void beforeUpdate(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo, CWriteableSysNetPartyLinkInfo *pNewSysNetPartyLinkInfo);
	
	///删除前触发
	///@param	pSysNetPartyLinkInfo	要删除的CSysNetPartyLinkInfo
	virtual void beforeRemove(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoDumpTrigger是操作会员链路信息表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoDumpTrigger: public CSysNetDelPartyLinkInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetDelPartyLinkInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetDelPartyLinkInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetDelPartyLinkInfo	要加入的SysNetDelPartyLinkInfo
	virtual void beforeAdd(CWriteableSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo);
	
	///更新前触发	
	///@param	pSysNetDelPartyLinkInfo	被刷新的CSysNetDelPartyLinkInfo
	///@param	pNewSysNetDelPartyLinkInfo	新的值
	virtual void beforeUpdate(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, CWriteableSysNetDelPartyLinkInfo *pNewSysNetDelPartyLinkInfo);
	
	///删除前触发
	///@param	pSysNetDelPartyLinkInfo	要删除的CSysNetDelPartyLinkInfo
	virtual void beforeRemove(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeDumpTrigger是操作会员链路信息表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeDumpTrigger: public CSysNetPartyLinkAddrChangeActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetPartyLinkAddrChangeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetPartyLinkAddrChangeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetPartyLinkAddrChange	要加入的SysNetPartyLinkAddrChange
	virtual void beforeAdd(CWriteableSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange);
	
	///更新前触发	
	///@param	pSysNetPartyLinkAddrChange	被刷新的CSysNetPartyLinkAddrChange
	///@param	pNewSysNetPartyLinkAddrChange	新的值
	virtual void beforeUpdate(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, CWriteableSysNetPartyLinkAddrChange *pNewSysNetPartyLinkAddrChange);
	
	///删除前触发
	///@param	pSysNetPartyLinkAddrChange	要删除的CSysNetPartyLinkAddrChange
	virtual void beforeRemove(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrDumpTrigger是操作监控动作指标对照表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrDumpTrigger: public CSysNetMonitorActionAttrActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetMonitorActionAttrDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetMonitorActionAttrDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetMonitorActionAttr	要加入的SysNetMonitorActionAttr
	virtual void beforeAdd(CWriteableSysNetMonitorActionAttr *pSysNetMonitorActionAttr);
	
	///更新前触发	
	///@param	pSysNetMonitorActionAttr	被刷新的CSysNetMonitorActionAttr
	///@param	pNewSysNetMonitorActionAttr	新的值
	virtual void beforeUpdate(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr, CWriteableSysNetMonitorActionAttr *pNewSysNetMonitorActionAttr);
	
	///删除前触发
	///@param	pSysNetMonitorActionAttr	要删除的CSysNetMonitorActionAttr
	virtual void beforeRemove(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleDumpTrigger是操作模块时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleDumpTrigger: public CSysNetModuleActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetModuleDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetModuleDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetModule	要加入的SysNetModule
	virtual void beforeAdd(CWriteableSysNetModule *pSysNetModule);
	
	///更新前触发	
	///@param	pSysNetModule	被刷新的CSysNetModule
	///@param	pNewSysNetModule	新的值
	virtual void beforeUpdate(CSysNetModule *pSysNetModule, CWriteableSysNetModule *pNewSysNetModule);
	
	///删除前触发
	///@param	pSysNetModule	要删除的CSysNetModule
	virtual void beforeRemove(CSysNetModule *pSysNetModule);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprDumpTrigger是操作告警表达式信息表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprDumpTrigger: public CSysNetEventExprActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetEventExprDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetEventExprDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetEventExpr	要加入的SysNetEventExpr
	virtual void beforeAdd(CWriteableSysNetEventExpr *pSysNetEventExpr);
	
	///更新前触发	
	///@param	pSysNetEventExpr	被刷新的CSysNetEventExpr
	///@param	pNewSysNetEventExpr	新的值
	virtual void beforeUpdate(CSysNetEventExpr *pSysNetEventExpr, CWriteableSysNetEventExpr *pNewSysNetEventExpr);
	
	///删除前触发
	///@param	pSysNetEventExpr	要删除的CSysNetEventExpr
	virtual void beforeRemove(CSysNetEventExpr *pSysNetEventExpr);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeDumpTrigger是操作事件类型时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeDumpTrigger: public CSysNetEventTypeActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetEventTypeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetEventTypeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetEventType	要加入的SysNetEventType
	virtual void beforeAdd(CWriteableSysNetEventType *pSysNetEventType);
	
	///更新前触发	
	///@param	pSysNetEventType	被刷新的CSysNetEventType
	///@param	pNewSysNetEventType	新的值
	virtual void beforeUpdate(CSysNetEventType *pSysNetEventType, CWriteableSysNetEventType *pNewSysNetEventType);
	
	///删除前触发
	///@param	pSysNetEventType	要删除的CSysNetEventType
	virtual void beforeRemove(CSysNetEventType *pSysNetEventType);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeDumpTrigger是操作事件子类型时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeDumpTrigger: public CSysNetSubEventTypeActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetSubEventTypeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetSubEventTypeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetSubEventType	要加入的SysNetSubEventType
	virtual void beforeAdd(CWriteableSysNetSubEventType *pSysNetSubEventType);
	
	///更新前触发	
	///@param	pSysNetSubEventType	被刷新的CSysNetSubEventType
	///@param	pNewSysNetSubEventType	新的值
	virtual void beforeUpdate(CSysNetSubEventType *pSysNetSubEventType, CWriteableSysNetSubEventType *pNewSysNetSubEventType);
	
	///删除前触发
	///@param	pSysNetSubEventType	要删除的CSysNetSubEventType
	virtual void beforeRemove(CSysNetSubEventType *pSysNetSubEventType);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelDumpTrigger是操作事件级别时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelDumpTrigger: public CSysNetEventLevelActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetEventLevelDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetEventLevelDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetEventLevel	要加入的SysNetEventLevel
	virtual void beforeAdd(CWriteableSysNetEventLevel *pSysNetEventLevel);
	
	///更新前触发	
	///@param	pSysNetEventLevel	被刷新的CSysNetEventLevel
	///@param	pNewSysNetEventLevel	新的值
	virtual void beforeUpdate(CSysNetEventLevel *pSysNetEventLevel, CWriteableSysNetEventLevel *pNewSysNetEventLevel);
	
	///删除前触发
	///@param	pSysNetEventLevel	要删除的CSysNetEventLevel
	virtual void beforeRemove(CSysNetEventLevel *pSysNetEventLevel);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskDumpTrigger是操作任务结果规则分析表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskDumpTrigger: public CSysNetMonitorDeviceTaskActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetMonitorDeviceTaskDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetMonitorDeviceTaskDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetMonitorDeviceTask	要加入的SysNetMonitorDeviceTask
	virtual void beforeAdd(CWriteableSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask);
	
	///更新前触发	
	///@param	pSysNetMonitorDeviceTask	被刷新的CSysNetMonitorDeviceTask
	///@param	pNewSysNetMonitorDeviceTask	新的值
	virtual void beforeUpdate(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, CWriteableSysNetMonitorDeviceTask *pNewSysNetMonitorDeviceTask);
	
	///删除前触发
	///@param	pSysNetMonitorDeviceTask	要删除的CSysNetMonitorDeviceTask
	virtual void beforeRemove(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsDumpTrigger是操作任务指令指标集表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsDumpTrigger: public CSysNetMonitorTaskInstAttrsActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetMonitorTaskInstAttrsDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetMonitorTaskInstAttrsDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetMonitorTaskInstAttrs	要加入的SysNetMonitorTaskInstAttrs
	virtual void beforeAdd(CWriteableSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs);
	
	///更新前触发	
	///@param	pSysNetMonitorTaskInstAttrs	被刷新的CSysNetMonitorTaskInstAttrs
	///@param	pNewSysNetMonitorTaskInstAttrs	新的值
	virtual void beforeUpdate(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, CWriteableSysNetMonitorTaskInstAttrs *pNewSysNetMonitorTaskInstAttrs);
	
	///删除前触发
	///@param	pSysNetMonitorTaskInstAttrs	要删除的CSysNetMonitorTaskInstAttrs
	virtual void beforeRemove(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineDumpTrigger是操作基线表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineDumpTrigger: public CSysNetBaseLineActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetBaseLineDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetBaseLineDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetBaseLine	要加入的SysNetBaseLine
	virtual void beforeAdd(CWriteableSysNetBaseLine *pSysNetBaseLine);
	
	///更新前触发	
	///@param	pSysNetBaseLine	被刷新的CSysNetBaseLine
	///@param	pNewSysNetBaseLine	新的值
	virtual void beforeUpdate(CSysNetBaseLine *pSysNetBaseLine, CWriteableSysNetBaseLine *pNewSysNetBaseLine);
	
	///删除前触发
	///@param	pSysNetBaseLine	要删除的CSysNetBaseLine
	virtual void beforeRemove(CSysNetBaseLine *pSysNetBaseLine);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskDumpTrigger是操作基线任务表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskDumpTrigger: public CSysNetBaseLineTaskActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetBaseLineTaskDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetBaseLineTaskDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetBaseLineTask	要加入的SysNetBaseLineTask
	virtual void beforeAdd(CWriteableSysNetBaseLineTask *pSysNetBaseLineTask);
	
	///更新前触发	
	///@param	pSysNetBaseLineTask	被刷新的CSysNetBaseLineTask
	///@param	pNewSysNetBaseLineTask	新的值
	virtual void beforeUpdate(CSysNetBaseLineTask *pSysNetBaseLineTask, CWriteableSysNetBaseLineTask *pNewSysNetBaseLineTask);
	
	///删除前触发
	///@param	pSysNetBaseLineTask	要删除的CSysNetBaseLineTask
	virtual void beforeRemove(CSysNetBaseLineTask *pSysNetBaseLineTask);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoDumpTrigger是操作会员链路状态信息表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoDumpTrigger: public CSysMdbNetPartyLinkStatusInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMdbNetPartyLinkStatusInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMdbNetPartyLinkStatusInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMdbNetPartyLinkStatusInfo	要加入的SysMdbNetPartyLinkStatusInfo
	virtual void beforeAdd(CWriteableSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);
	
	///更新前触发	
	///@param	pSysMdbNetPartyLinkStatusInfo	被刷新的CSysMdbNetPartyLinkStatusInfo
	///@param	pNewSysMdbNetPartyLinkStatusInfo	新的值
	virtual void beforeUpdate(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, CWriteableSysMdbNetPartyLinkStatusInfo *pNewSysMdbNetPartyLinkStatusInfo);
	
	///删除前触发
	///@param	pSysMdbNetPartyLinkStatusInfo	要删除的CSysMdbNetPartyLinkStatusInfo
	virtual void beforeRemove(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoDumpTrigger是操作会员SDH线路明细表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoDumpTrigger: public CSysNetMemberSDHLineInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetMemberSDHLineInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetMemberSDHLineInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetMemberSDHLineInfo	要加入的SysNetMemberSDHLineInfo
	virtual void beforeAdd(CWriteableSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo);
	
	///更新前触发	
	///@param	pSysNetMemberSDHLineInfo	被刷新的CSysNetMemberSDHLineInfo
	///@param	pNewSysNetMemberSDHLineInfo	新的值
	virtual void beforeUpdate(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, CWriteableSysNetMemberSDHLineInfo *pNewSysNetMemberSDHLineInfo);
	
	///删除前触发
	///@param	pSysNetMemberSDHLineInfo	要删除的CSysNetMemberSDHLineInfo
	virtual void beforeRemove(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoDumpTrigger是操作DDN链路信息表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoDumpTrigger: public CSysNetDDNLinkInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetDDNLinkInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetDDNLinkInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetDDNLinkInfo	要加入的SysNetDDNLinkInfo
	virtual void beforeAdd(CWriteableSysNetDDNLinkInfo *pSysNetDDNLinkInfo);
	
	///更新前触发	
	///@param	pSysNetDDNLinkInfo	被刷新的CSysNetDDNLinkInfo
	///@param	pNewSysNetDDNLinkInfo	新的值
	virtual void beforeUpdate(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo, CWriteableSysNetDDNLinkInfo *pNewSysNetDDNLinkInfo);
	
	///删除前触发
	///@param	pSysNetDDNLinkInfo	要删除的CSysNetDDNLinkInfo
	virtual void beforeRemove(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoDumpTrigger是操作非会员线路使用信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoDumpTrigger: public CSysNetPseudMemberLinkInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetPseudMemberLinkInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetPseudMemberLinkInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetPseudMemberLinkInfo	要加入的SysNetPseudMemberLinkInfo
	virtual void beforeAdd(CWriteableSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo);
	
	///更新前触发	
	///@param	pSysNetPseudMemberLinkInfo	被刷新的CSysNetPseudMemberLinkInfo
	///@param	pNewSysNetPseudMemberLinkInfo	新的值
	virtual void beforeUpdate(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, CWriteableSysNetPseudMemberLinkInfo *pNewSysNetPseudMemberLinkInfo);
	
	///删除前触发
	///@param	pSysNetPseudMemberLinkInfo	要删除的CSysNetPseudMemberLinkInfo
	virtual void beforeRemove(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoDumpTrigger是操作远端设备信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoDumpTrigger: public CSysNetOuterDeviceInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetOuterDeviceInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetOuterDeviceInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetOuterDeviceInfo	要加入的SysNetOuterDeviceInfo
	virtual void beforeAdd(CWriteableSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo);
	
	///更新前触发	
	///@param	pSysNetOuterDeviceInfo	被刷新的CSysNetOuterDeviceInfo
	///@param	pNewSysNetOuterDeviceInfo	新的值
	virtual void beforeUpdate(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, CWriteableSysNetOuterDeviceInfo *pNewSysNetOuterDeviceInfo);
	
	///删除前触发
	///@param	pSysNetOuterDeviceInfo	要删除的CSysNetOuterDeviceInfo
	virtual void beforeRemove(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoDumpTrigger是操作本地ping结果时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoDumpTrigger: public CSysLocalPingResultInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysLocalPingResultInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysLocalPingResultInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysLocalPingResultInfo	要加入的SysLocalPingResultInfo
	virtual void beforeAdd(CWriteableSysLocalPingResultInfo *pSysLocalPingResultInfo);
	
	///更新前触发	
	///@param	pSysLocalPingResultInfo	被刷新的CSysLocalPingResultInfo
	///@param	pNewSysLocalPingResultInfo	新的值
	virtual void beforeUpdate(CSysLocalPingResultInfo *pSysLocalPingResultInfo, CWriteableSysLocalPingResultInfo *pNewSysLocalPingResultInfo);
	
	///删除前触发
	///@param	pSysLocalPingResultInfo	要删除的CSysLocalPingResultInfo
	virtual void beforeRemove(CSysLocalPingResultInfo *pSysLocalPingResultInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoDumpTrigger是操作远程ping结果时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoDumpTrigger: public CSysRomotePingResultInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysRomotePingResultInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysRomotePingResultInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysRomotePingResultInfo	要加入的SysRomotePingResultInfo
	virtual void beforeAdd(CWriteableSysRomotePingResultInfo *pSysRomotePingResultInfo);
	
	///更新前触发	
	///@param	pSysRomotePingResultInfo	被刷新的CSysRomotePingResultInfo
	///@param	pNewSysRomotePingResultInfo	新的值
	virtual void beforeUpdate(CSysRomotePingResultInfo *pSysRomotePingResultInfo, CWriteableSysRomotePingResultInfo *pNewSysRomotePingResultInfo);
	
	///删除前触发
	///@param	pSysRomotePingResultInfo	要删除的CSysRomotePingResultInfo
	virtual void beforeRemove(CSysRomotePingResultInfo *pSysRomotePingResultInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesDumpTrigger是操作会员席位交易状态时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesDumpTrigger: public CSysParticTradeOrderStatesActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysParticTradeOrderStatesDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysParticTradeOrderStatesDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysParticTradeOrderStates	要加入的SysParticTradeOrderStates
	virtual void beforeAdd(CWriteableSysParticTradeOrderStates *pSysParticTradeOrderStates);
	
	///更新前触发	
	///@param	pSysParticTradeOrderStates	被刷新的CSysParticTradeOrderStates
	///@param	pNewSysParticTradeOrderStates	新的值
	virtual void beforeUpdate(CSysParticTradeOrderStates *pSysParticTradeOrderStates, CWriteableSysParticTradeOrderStates *pNewSysParticTradeOrderStates);
	
	///删除前触发
	///@param	pSysParticTradeOrderStates	要删除的CSysParticTradeOrderStates
	virtual void beforeRemove(CSysParticTradeOrderStates *pSysParticTradeOrderStates);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoDumpTrigger是操作系统路由信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoDumpTrigger: public CSysMdbRouterInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMdbRouterInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMdbRouterInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMdbRouterInfo	要加入的SysMdbRouterInfo
	virtual void beforeAdd(CWriteableSysMdbRouterInfo *pSysMdbRouterInfo);
	
	///更新前触发	
	///@param	pSysMdbRouterInfo	被刷新的CSysMdbRouterInfo
	///@param	pNewSysMdbRouterInfo	新的值
	virtual void beforeUpdate(CSysMdbRouterInfo *pSysMdbRouterInfo, CWriteableSysMdbRouterInfo *pNewSysMdbRouterInfo);
	
	///删除前触发
	///@param	pSysMdbRouterInfo	要删除的CSysMdbRouterInfo
	virtual void beforeRemove(CSysMdbRouterInfo *pSysMdbRouterInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIODumpTrigger是操作磁盘I/O信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIODumpTrigger: public CSysMdbDiskIOActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMdbDiskIODumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMdbDiskIODumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMdbDiskIO	要加入的SysMdbDiskIO
	virtual void beforeAdd(CWriteableSysMdbDiskIO *pSysMdbDiskIO);
	
	///更新前触发	
	///@param	pSysMdbDiskIO	被刷新的CSysMdbDiskIO
	///@param	pNewSysMdbDiskIO	新的值
	virtual void beforeUpdate(CSysMdbDiskIO *pSysMdbDiskIO, CWriteableSysMdbDiskIO *pNewSysMdbDiskIO);
	
	///删除前触发
	///@param	pSysMdbDiskIO	要删除的CSysMdbDiskIO
	virtual void beforeRemove(CSysMdbDiskIO *pSysMdbDiskIO);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoDumpTrigger是操作系统状态信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoDumpTrigger: public CSysMdbStatInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMdbStatInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMdbStatInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMdbStatInfo	要加入的SysMdbStatInfo
	virtual void beforeAdd(CWriteableSysMdbStatInfo *pSysMdbStatInfo);
	
	///更新前触发	
	///@param	pSysMdbStatInfo	被刷新的CSysMdbStatInfo
	///@param	pNewSysMdbStatInfo	新的值
	virtual void beforeUpdate(CSysMdbStatInfo *pSysMdbStatInfo, CWriteableSysMdbStatInfo *pNewSysMdbStatInfo);
	
	///删除前触发
	///@param	pSysMdbStatInfo	要删除的CSysMdbStatInfo
	virtual void beforeRemove(CSysMdbStatInfo *pSysMdbStatInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatDumpTrigger是操作交易系统前置报单响应信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatDumpTrigger: public CSysMdbTradeFrontOrderRttStatActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMdbTradeFrontOrderRttStatDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMdbTradeFrontOrderRttStatDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMdbTradeFrontOrderRttStat	要加入的SysMdbTradeFrontOrderRttStat
	virtual void beforeAdd(CWriteableSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);
	
	///更新前触发	
	///@param	pSysMdbTradeFrontOrderRttStat	被刷新的CSysMdbTradeFrontOrderRttStat
	///@param	pNewSysMdbTradeFrontOrderRttStat	新的值
	virtual void beforeUpdate(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, CWriteableSysMdbTradeFrontOrderRttStat *pNewSysMdbTradeFrontOrderRttStat);
	
	///删除前触发
	///@param	pSysMdbTradeFrontOrderRttStat	要删除的CSysMdbTradeFrontOrderRttStat
	virtual void beforeRemove(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusDumpTrigger是操作合约状态切换时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusDumpTrigger: public CSysInstrumentStatusActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysInstrumentStatusDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysInstrumentStatusDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysInstrumentStatus	要加入的SysInstrumentStatus
	virtual void beforeAdd(CWriteableSysInstrumentStatus *pSysInstrumentStatus);
	
	///更新前触发	
	///@param	pSysInstrumentStatus	被刷新的CSysInstrumentStatus
	///@param	pNewSysInstrumentStatus	新的值
	virtual void beforeUpdate(CSysInstrumentStatus *pSysInstrumentStatus, CWriteableSysInstrumentStatus *pNewSysInstrumentStatus);
	
	///删除前触发
	///@param	pSysInstrumentStatus	要删除的CSysInstrumentStatus
	virtual void beforeRemove(CSysInstrumentStatus *pSysInstrumentStatus);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrDumpTrigger是操作合约交易节信息时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrDumpTrigger: public CSysCurrTradingSegmentAttrActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysCurrTradingSegmentAttrDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysCurrTradingSegmentAttrDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysCurrTradingSegmentAttr	要加入的SysCurrTradingSegmentAttr
	virtual void beforeAdd(CWriteableSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr);
	
	///更新前触发	
	///@param	pSysCurrTradingSegmentAttr	被刷新的CSysCurrTradingSegmentAttr
	///@param	pNewSysCurrTradingSegmentAttr	新的值
	virtual void beforeUpdate(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, CWriteableSysCurrTradingSegmentAttr *pNewSysCurrTradingSegmentAttr);
	
	///删除前触发
	///@param	pSysCurrTradingSegmentAttr	要删除的CSysCurrTradingSegmentAttr
	virtual void beforeRemove(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostDumpTrigger是操作会员链路费用表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostDumpTrigger: public CSysMemberLinkCostActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysMemberLinkCostDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysMemberLinkCostDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysMemberLinkCost	要加入的SysMemberLinkCost
	virtual void beforeAdd(CWriteableSysMemberLinkCost *pSysMemberLinkCost);
	
	///更新前触发	
	///@param	pSysMemberLinkCost	被刷新的CSysMemberLinkCost
	///@param	pNewSysMemberLinkCost	新的值
	virtual void beforeUpdate(CSysMemberLinkCost *pSysMemberLinkCost, CWriteableSysMemberLinkCost *pNewSysMemberLinkCost);
	
	///删除前触发
	///@param	pSysMemberLinkCost	要删除的CSysMemberLinkCost
	virtual void beforeRemove(CSysMemberLinkCost *pSysMemberLinkCost);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentDumpTrigger是操作会员链路月租表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentDumpTrigger: public CSysNetPartylinkMonthlyRentActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetPartylinkMonthlyRentDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetPartylinkMonthlyRentDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetPartylinkMonthlyRent	要加入的SysNetPartylinkMonthlyRent
	virtual void beforeAdd(CWriteableSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);
	
	///更新前触发	
	///@param	pSysNetPartylinkMonthlyRent	被刷新的CSysNetPartylinkMonthlyRent
	///@param	pNewSysNetPartylinkMonthlyRent	新的值
	virtual void beforeUpdate(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, CWriteableSysNetPartylinkMonthlyRent *pNewSysNetPartylinkMonthlyRent);
	
	///删除前触发
	///@param	pSysNetPartylinkMonthlyRent	要删除的CSysNetPartylinkMonthlyRent
	virtual void beforeRemove(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoDumpTrigger是操作会员链路月租表时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoDumpTrigger: public CSysNetNonPartyLinkInfoActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CSysNetNonPartyLinkInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CSysNetNonPartyLinkInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pSysNetNonPartyLinkInfo	要加入的SysNetNonPartyLinkInfo
	virtual void beforeAdd(CWriteableSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo);
	
	///更新前触发	
	///@param	pSysNetNonPartyLinkInfo	被刷新的CSysNetNonPartyLinkInfo
	///@param	pNewSysNetNonPartyLinkInfo	新的值
	virtual void beforeUpdate(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, CWriteableSysNetNonPartyLinkInfo *pNewSysNetNonPartyLinkInfo);
	
	///删除前触发
	///@param	pSysNetNonPartyLinkInfo	要删除的CSysNetNonPartyLinkInfo
	virtual void beforeRemove(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo);
	
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
	
	CSysInvalidateOrderDumpTrigger *m_SysInvalidateOrderTrigger;
	CSysOrderStatusDumpTrigger *m_SysOrderStatusTrigger;
	CSysBargainOrderDumpTrigger *m_SysBargainOrderTrigger;
	CSysInstPropertyDumpTrigger *m_SysInstPropertyTrigger;
	CSysMarginRateDumpTrigger *m_SysMarginRateTrigger;
	CSysPriceLimitDumpTrigger *m_SysPriceLimitTrigger;
	CSysPartPosiLimitDumpTrigger *m_SysPartPosiLimitTrigger;
	CSysClientPosiLimitDumpTrigger *m_SysClientPosiLimitTrigger;
	CSysSpecialPosiLimitDumpTrigger *m_SysSpecialPosiLimitTrigger;
	CSysTransactionChgDumpTrigger *m_SysTransactionChgTrigger;
	CSysClientChgDumpTrigger *m_SysClientChgTrigger;
	CSysPartClientChgDumpTrigger *m_SysPartClientChgTrigger;
	CSysPosiLimitChgDumpTrigger *m_SysPosiLimitChgTrigger;
	CSysClientPosiLimitChgDumpTrigger *m_SysClientPosiLimitChgTrigger;
	CSysSpecPosiLimitChgDumpTrigger *m_SysSpecPosiLimitChgTrigger;
	CSysHedgeDetailChgDumpTrigger *m_SysHedgeDetailChgTrigger;
	CSysParticipantChgDumpTrigger *m_SysParticipantChgTrigger;
	CSysMarginRateChgDumpTrigger *m_SysMarginRateChgTrigger;
	CSysUserIpChgDumpTrigger *m_SysUserIpChgTrigger;
	CSysPartTradeDumpTrigger *m_SysPartTradeTrigger;
	CSysMdbObjectAttrDumpTrigger *m_SysMdbObjectAttrTrigger;
	CSysMdbSyslogInfoDumpTrigger *m_SysMdbSyslogInfoTrigger;
	CSysUserInfoDumpTrigger *m_SysUserInfoTrigger;
	CSysOnlineUserInfoDumpTrigger *m_SysOnlineUserInfoTrigger;
	CSysWarningEventDumpTrigger *m_SysWarningEventTrigger;
	CSysWarningQueryDumpTrigger *m_SysWarningQueryTrigger;
	CSyslogEventDumpTrigger *m_SyslogEventTrigger;
	CSysEventDescripDumpTrigger *m_SysEventDescripTrigger;
	CRspQryHostEnvCommonDumpTrigger *m_RspQryHostEnvCommonTrigger;
	CRspQryHostEnvLanDumpTrigger *m_RspQryHostEnvLanTrigger;
	CRspQryHostEnvStorageDumpTrigger *m_RspQryHostEnvStorageTrigger;
	CRspQryHostEnvIODumpTrigger *m_RspQryHostEnvIOTrigger;
	CRspQryHostEnvFSDumpTrigger *m_RspQryHostEnvFSTrigger;
	CRspQryHostEnvSwapDumpTrigger *m_RspQryHostEnvSwapTrigger;
	CRspQryHostEnvLanCfgDumpTrigger *m_RspQryHostEnvLanCfgTrigger;
	CSysMdbTopCpuInfoDumpTrigger *m_SysMdbTopCpuInfoTrigger;
	CSysMdbTopMemInfoDumpTrigger *m_SysMdbTopMemInfoTrigger;
	CSysMdbTopProcessInfoDumpTrigger *m_SysMdbTopProcessInfoTrigger;
	CSysMdbFileSystemInfoDumpTrigger *m_SysMdbFileSystemInfoTrigger;
	CSysMdbNetworkInfoDumpTrigger *m_SysMdbNetworkInfoTrigger;
	CSysParticipantInitDumpTrigger *m_SysParticipantInitTrigger;
	CSysUserInitDumpTrigger *m_SysUserInitTrigger;
	CSysClientInitDumpTrigger *m_SysClientInitTrigger;
	CSysTradeUserLoginInfoDumpTrigger *m_SysTradeUserLoginInfoTrigger;
	CSysMdbWebAppInfoDumpTrigger *m_SysMdbWebAppInfoTrigger;
	CSysMdbMemPoolInfoDumpTrigger *m_SysMdbMemPoolInfoTrigger;
	CSysMdbConnectorInfoDumpTrigger *m_SysMdbConnectorInfoTrigger;
	CSysMdbDBQueryDumpTrigger *m_SysMdbDBQueryTrigger;
	CSysNetAreaDumpTrigger *m_SysNetAreaTrigger;
	CSysNetSubAreaDumpTrigger *m_SysNetSubAreaTrigger;
	CSysNetSubAreaIPDumpTrigger *m_SysNetSubAreaIPTrigger;
	CSysNetFuncAreaDumpTrigger *m_SysNetFuncAreaTrigger;
	CSysNetDeviceDumpTrigger *m_SysNetDeviceTrigger;
	CSysNetDeviceLinkedDumpTrigger *m_SysNetDeviceLinkedTrigger;
	CSysNetOIDDumpTrigger *m_SysNetOIDTrigger;
	CSysNetDeviceTypeDumpTrigger *m_SysNetDeviceTypeTrigger;
	CSysNetTimePolicyDumpTrigger *m_SysNetTimePolicyTrigger;
	CSysNetGatherTaskDumpTrigger *m_SysNetGatherTaskTrigger;
	CSysNetDeviceCategoryDumpTrigger *m_SysNetDeviceCategoryTrigger;
	CSysNetManufactoryDumpTrigger *m_SysNetManufactoryTrigger;
	CSysNetCommunityDumpTrigger *m_SysNetCommunityTrigger;
	CSysNetPortTypeDumpTrigger *m_SysNetPortTypeTrigger;
	CSysNetInterfaceDumpTrigger *m_SysNetInterfaceTrigger;
	CSysNetGeneralOIDDumpTrigger *m_SysNetGeneralOIDTrigger;
	CSysNetMonitorTypeDumpTrigger *m_SysNetMonitorTypeTrigger;
	CSysNetMonitorAttrScopeDumpTrigger *m_SysNetMonitorAttrScopeTrigger;
	CSysNetMonitorAttrTypeDumpTrigger *m_SysNetMonitorAttrTypeTrigger;
	CSysNetMonitorCommandTypeDumpTrigger *m_SysNetMonitorCommandTypeTrigger;
	CSysNetMonitorActionGroupDumpTrigger *m_SysNetMonitorActionGroupTrigger;
	CSysNetMonitorDeviceGroupDumpTrigger *m_SysNetMonitorDeviceGroupTrigger;
	CSysNetMonitorTaskInfoDumpTrigger *m_SysNetMonitorTaskInfoTrigger;
	CSysNetMonitorTaskObjectSetDumpTrigger *m_SysNetMonitorTaskObjectSetTrigger;
	CSysNetMonitorTaskResultDumpTrigger *m_SysNetMonitorTaskResultTrigger;
	CSysNetPartyLinkInfoDumpTrigger *m_SysNetPartyLinkInfoTrigger;
	CSysNetDelPartyLinkInfoDumpTrigger *m_SysNetDelPartyLinkInfoTrigger;
	CSysNetPartyLinkAddrChangeDumpTrigger *m_SysNetPartyLinkAddrChangeTrigger;
	CSysNetMonitorActionAttrDumpTrigger *m_SysNetMonitorActionAttrTrigger;
	CSysNetModuleDumpTrigger *m_SysNetModuleTrigger;
	CSysNetEventExprDumpTrigger *m_SysNetEventExprTrigger;
	CSysNetEventTypeDumpTrigger *m_SysNetEventTypeTrigger;
	CSysNetSubEventTypeDumpTrigger *m_SysNetSubEventTypeTrigger;
	CSysNetEventLevelDumpTrigger *m_SysNetEventLevelTrigger;
	CSysNetMonitorDeviceTaskDumpTrigger *m_SysNetMonitorDeviceTaskTrigger;
	CSysNetMonitorTaskInstAttrsDumpTrigger *m_SysNetMonitorTaskInstAttrsTrigger;
	CSysNetBaseLineDumpTrigger *m_SysNetBaseLineTrigger;
	CSysNetBaseLineTaskDumpTrigger *m_SysNetBaseLineTaskTrigger;
	CSysMdbNetPartyLinkStatusInfoDumpTrigger *m_SysMdbNetPartyLinkStatusInfoTrigger;
	CSysNetMemberSDHLineInfoDumpTrigger *m_SysNetMemberSDHLineInfoTrigger;
	CSysNetDDNLinkInfoDumpTrigger *m_SysNetDDNLinkInfoTrigger;
	CSysNetPseudMemberLinkInfoDumpTrigger *m_SysNetPseudMemberLinkInfoTrigger;
	CSysNetOuterDeviceInfoDumpTrigger *m_SysNetOuterDeviceInfoTrigger;
	CSysLocalPingResultInfoDumpTrigger *m_SysLocalPingResultInfoTrigger;
	CSysRomotePingResultInfoDumpTrigger *m_SysRomotePingResultInfoTrigger;
	CSysParticTradeOrderStatesDumpTrigger *m_SysParticTradeOrderStatesTrigger;
	CSysMdbRouterInfoDumpTrigger *m_SysMdbRouterInfoTrigger;
	CSysMdbDiskIODumpTrigger *m_SysMdbDiskIOTrigger;
	CSysMdbStatInfoDumpTrigger *m_SysMdbStatInfoTrigger;
	CSysMdbTradeFrontOrderRttStatDumpTrigger *m_SysMdbTradeFrontOrderRttStatTrigger;
	CSysInstrumentStatusDumpTrigger *m_SysInstrumentStatusTrigger;
	CSysCurrTradingSegmentAttrDumpTrigger *m_SysCurrTradingSegmentAttrTrigger;
	CSysMemberLinkCostDumpTrigger *m_SysMemberLinkCostTrigger;
	CSysNetPartylinkMonthlyRentDumpTrigger *m_SysNetPartylinkMonthlyRentTrigger;
	CSysNetNonPartyLinkInfoDumpTrigger *m_SysNetNonPartyLinkInfoTrigger;
};

#endif
