/////////////////////////////////////////////////////////////////////////
///@system 交易引擎系统
///@company 上海期货信息技术有限公司
///@file CDumpLog.cpp
///@brief实现了类CDumpLog
///@history 
///20041001	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "CDumpLog.h"
#include "monitorIndex.h"

///本宏控制是否使用单行方式进行输出
#define SINGLE_LINE

CSysInvalidateOrderDumpTrigger::CSysInvalidateOrderDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysInvalidateOrderDumpTrigger::~CSysInvalidateOrderDumpTrigger(void)
{
}


void CSysInvalidateOrderDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysInvalidateOrderDumpTrigger");
	pLogger->output(indent,0,"CSysInvalidateOrderDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysInvalidateOrderDumpTrigger::beforeAdd(CWriteableSysInvalidateOrder *pSysInvalidateOrder)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysInvalidateOrder,add");
		pSysInvalidateOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysInvalidateOrder\n");
		pSysInvalidateOrder->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysInvalidateOrderDumpTrigger::beforeUpdate(CSysInvalidateOrder *pSysInvalidateOrder, CWriteableSysInvalidateOrder *pNewSysInvalidateOrder)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysInvalidateOrder,upd");
		pNewSysInvalidateOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysInvalidateOrder\n");
		pNewSysInvalidateOrder->dumpDiff(m_output,pSysInvalidateOrder);
#endif
		fflush(m_output);
	}
}
	
void CSysInvalidateOrderDumpTrigger::beforeRemove(CSysInvalidateOrder *pSysInvalidateOrder)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysInvalidateOrder,del");
		pSysInvalidateOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysInvalidateOrder\n");
		pSysInvalidateOrder->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysOrderStatusDumpTrigger::CSysOrderStatusDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysOrderStatusDumpTrigger::~CSysOrderStatusDumpTrigger(void)
{
}


void CSysOrderStatusDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysOrderStatusDumpTrigger");
	pLogger->output(indent,0,"CSysOrderStatusDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysOrderStatusDumpTrigger::beforeAdd(CWriteableSysOrderStatus *pSysOrderStatus)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysOrderStatus,add");
		pSysOrderStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysOrderStatus\n");
		pSysOrderStatus->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysOrderStatusDumpTrigger::beforeUpdate(CSysOrderStatus *pSysOrderStatus, CWriteableSysOrderStatus *pNewSysOrderStatus)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysOrderStatus,upd");
		pNewSysOrderStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysOrderStatus\n");
		pNewSysOrderStatus->dumpDiff(m_output,pSysOrderStatus);
#endif
		fflush(m_output);
	}
}
	
void CSysOrderStatusDumpTrigger::beforeRemove(CSysOrderStatus *pSysOrderStatus)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysOrderStatus,del");
		pSysOrderStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysOrderStatus\n");
		pSysOrderStatus->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysBargainOrderDumpTrigger::CSysBargainOrderDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysBargainOrderDumpTrigger::~CSysBargainOrderDumpTrigger(void)
{
}


void CSysBargainOrderDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysBargainOrderDumpTrigger");
	pLogger->output(indent,0,"CSysBargainOrderDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysBargainOrderDumpTrigger::beforeAdd(CWriteableSysBargainOrder *pSysBargainOrder)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysBargainOrder,add");
		pSysBargainOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysBargainOrder\n");
		pSysBargainOrder->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysBargainOrderDumpTrigger::beforeUpdate(CSysBargainOrder *pSysBargainOrder, CWriteableSysBargainOrder *pNewSysBargainOrder)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysBargainOrder,upd");
		pNewSysBargainOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysBargainOrder\n");
		pNewSysBargainOrder->dumpDiff(m_output,pSysBargainOrder);
#endif
		fflush(m_output);
	}
}
	
void CSysBargainOrderDumpTrigger::beforeRemove(CSysBargainOrder *pSysBargainOrder)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysBargainOrder,del");
		pSysBargainOrder->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysBargainOrder\n");
		pSysBargainOrder->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysInstPropertyDumpTrigger::CSysInstPropertyDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysInstPropertyDumpTrigger::~CSysInstPropertyDumpTrigger(void)
{
}


void CSysInstPropertyDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysInstPropertyDumpTrigger");
	pLogger->output(indent,0,"CSysInstPropertyDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysInstPropertyDumpTrigger::beforeAdd(CWriteableSysInstProperty *pSysInstProperty)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysInstProperty,add");
		pSysInstProperty->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysInstProperty\n");
		pSysInstProperty->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysInstPropertyDumpTrigger::beforeUpdate(CSysInstProperty *pSysInstProperty, CWriteableSysInstProperty *pNewSysInstProperty)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysInstProperty,upd");
		pNewSysInstProperty->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysInstProperty\n");
		pNewSysInstProperty->dumpDiff(m_output,pSysInstProperty);
#endif
		fflush(m_output);
	}
}
	
void CSysInstPropertyDumpTrigger::beforeRemove(CSysInstProperty *pSysInstProperty)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysInstProperty,del");
		pSysInstProperty->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysInstProperty\n");
		pSysInstProperty->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMarginRateDumpTrigger::CSysMarginRateDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMarginRateDumpTrigger::~CSysMarginRateDumpTrigger(void)
{
}


void CSysMarginRateDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMarginRateDumpTrigger");
	pLogger->output(indent,0,"CSysMarginRateDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMarginRateDumpTrigger::beforeAdd(CWriteableSysMarginRate *pSysMarginRate)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMarginRate,add");
		pSysMarginRate->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMarginRate\n");
		pSysMarginRate->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMarginRateDumpTrigger::beforeUpdate(CSysMarginRate *pSysMarginRate, CWriteableSysMarginRate *pNewSysMarginRate)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMarginRate,upd");
		pNewSysMarginRate->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMarginRate\n");
		pNewSysMarginRate->dumpDiff(m_output,pSysMarginRate);
#endif
		fflush(m_output);
	}
}
	
void CSysMarginRateDumpTrigger::beforeRemove(CSysMarginRate *pSysMarginRate)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMarginRate,del");
		pSysMarginRate->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMarginRate\n");
		pSysMarginRate->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysPriceLimitDumpTrigger::CSysPriceLimitDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysPriceLimitDumpTrigger::~CSysPriceLimitDumpTrigger(void)
{
}


void CSysPriceLimitDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysPriceLimitDumpTrigger");
	pLogger->output(indent,0,"CSysPriceLimitDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysPriceLimitDumpTrigger::beforeAdd(CWriteableSysPriceLimit *pSysPriceLimit)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysPriceLimit,add");
		pSysPriceLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysPriceLimit\n");
		pSysPriceLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysPriceLimitDumpTrigger::beforeUpdate(CSysPriceLimit *pSysPriceLimit, CWriteableSysPriceLimit *pNewSysPriceLimit)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysPriceLimit,upd");
		pNewSysPriceLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysPriceLimit\n");
		pNewSysPriceLimit->dumpDiff(m_output,pSysPriceLimit);
#endif
		fflush(m_output);
	}
}
	
void CSysPriceLimitDumpTrigger::beforeRemove(CSysPriceLimit *pSysPriceLimit)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysPriceLimit,del");
		pSysPriceLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysPriceLimit\n");
		pSysPriceLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysPartPosiLimitDumpTrigger::CSysPartPosiLimitDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysPartPosiLimitDumpTrigger::~CSysPartPosiLimitDumpTrigger(void)
{
}


void CSysPartPosiLimitDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysPartPosiLimitDumpTrigger");
	pLogger->output(indent,0,"CSysPartPosiLimitDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysPartPosiLimitDumpTrigger::beforeAdd(CWriteableSysPartPosiLimit *pSysPartPosiLimit)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysPartPosiLimit,add");
		pSysPartPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysPartPosiLimit\n");
		pSysPartPosiLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysPartPosiLimitDumpTrigger::beforeUpdate(CSysPartPosiLimit *pSysPartPosiLimit, CWriteableSysPartPosiLimit *pNewSysPartPosiLimit)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysPartPosiLimit,upd");
		pNewSysPartPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysPartPosiLimit\n");
		pNewSysPartPosiLimit->dumpDiff(m_output,pSysPartPosiLimit);
#endif
		fflush(m_output);
	}
}
	
void CSysPartPosiLimitDumpTrigger::beforeRemove(CSysPartPosiLimit *pSysPartPosiLimit)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysPartPosiLimit,del");
		pSysPartPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysPartPosiLimit\n");
		pSysPartPosiLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysClientPosiLimitDumpTrigger::CSysClientPosiLimitDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysClientPosiLimitDumpTrigger::~CSysClientPosiLimitDumpTrigger(void)
{
}


void CSysClientPosiLimitDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysClientPosiLimitDumpTrigger");
	pLogger->output(indent,0,"CSysClientPosiLimitDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysClientPosiLimitDumpTrigger::beforeAdd(CWriteableSysClientPosiLimit *pSysClientPosiLimit)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysClientPosiLimit,add");
		pSysClientPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysClientPosiLimit\n");
		pSysClientPosiLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysClientPosiLimitDumpTrigger::beforeUpdate(CSysClientPosiLimit *pSysClientPosiLimit, CWriteableSysClientPosiLimit *pNewSysClientPosiLimit)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysClientPosiLimit,upd");
		pNewSysClientPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysClientPosiLimit\n");
		pNewSysClientPosiLimit->dumpDiff(m_output,pSysClientPosiLimit);
#endif
		fflush(m_output);
	}
}
	
void CSysClientPosiLimitDumpTrigger::beforeRemove(CSysClientPosiLimit *pSysClientPosiLimit)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysClientPosiLimit,del");
		pSysClientPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysClientPosiLimit\n");
		pSysClientPosiLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysSpecialPosiLimitDumpTrigger::CSysSpecialPosiLimitDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysSpecialPosiLimitDumpTrigger::~CSysSpecialPosiLimitDumpTrigger(void)
{
}


void CSysSpecialPosiLimitDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysSpecialPosiLimitDumpTrigger");
	pLogger->output(indent,0,"CSysSpecialPosiLimitDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysSpecialPosiLimitDumpTrigger::beforeAdd(CWriteableSysSpecialPosiLimit *pSysSpecialPosiLimit)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysSpecialPosiLimit,add");
		pSysSpecialPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysSpecialPosiLimit\n");
		pSysSpecialPosiLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysSpecialPosiLimitDumpTrigger::beforeUpdate(CSysSpecialPosiLimit *pSysSpecialPosiLimit, CWriteableSysSpecialPosiLimit *pNewSysSpecialPosiLimit)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysSpecialPosiLimit,upd");
		pNewSysSpecialPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysSpecialPosiLimit\n");
		pNewSysSpecialPosiLimit->dumpDiff(m_output,pSysSpecialPosiLimit);
#endif
		fflush(m_output);
	}
}
	
void CSysSpecialPosiLimitDumpTrigger::beforeRemove(CSysSpecialPosiLimit *pSysSpecialPosiLimit)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysSpecialPosiLimit,del");
		pSysSpecialPosiLimit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysSpecialPosiLimit\n");
		pSysSpecialPosiLimit->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysTransactionChgDumpTrigger::CSysTransactionChgDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysTransactionChgDumpTrigger::~CSysTransactionChgDumpTrigger(void)
{
}


void CSysTransactionChgDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysTransactionChgDumpTrigger");
	pLogger->output(indent,0,"CSysTransactionChgDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysTransactionChgDumpTrigger::beforeAdd(CWriteableSysTransactionChg *pSysTransactionChg)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysTransactionChg,add");
		pSysTransactionChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysTransactionChg\n");
		pSysTransactionChg->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysTransactionChgDumpTrigger::beforeUpdate(CSysTransactionChg *pSysTransactionChg, CWriteableSysTransactionChg *pNewSysTransactionChg)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysTransactionChg,upd");
		pNewSysTransactionChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysTransactionChg\n");
		pNewSysTransactionChg->dumpDiff(m_output,pSysTransactionChg);
#endif
		fflush(m_output);
	}
}
	
void CSysTransactionChgDumpTrigger::beforeRemove(CSysTransactionChg *pSysTransactionChg)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysTransactionChg,del");
		pSysTransactionChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysTransactionChg\n");
		pSysTransactionChg->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysClientChgDumpTrigger::CSysClientChgDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysClientChgDumpTrigger::~CSysClientChgDumpTrigger(void)
{
}


void CSysClientChgDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysClientChgDumpTrigger");
	pLogger->output(indent,0,"CSysClientChgDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysClientChgDumpTrigger::beforeAdd(CWriteableSysClientChg *pSysClientChg)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysClientChg,add");
		pSysClientChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysClientChg\n");
		pSysClientChg->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysClientChgDumpTrigger::beforeUpdate(CSysClientChg *pSysClientChg, CWriteableSysClientChg *pNewSysClientChg)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysClientChg,upd");
		pNewSysClientChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysClientChg\n");
		pNewSysClientChg->dumpDiff(m_output,pSysClientChg);
#endif
		fflush(m_output);
	}
}
	
void CSysClientChgDumpTrigger::beforeRemove(CSysClientChg *pSysClientChg)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysClientChg,del");
		pSysClientChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysClientChg\n");
		pSysClientChg->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysPartClientChgDumpTrigger::CSysPartClientChgDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysPartClientChgDumpTrigger::~CSysPartClientChgDumpTrigger(void)
{
}


void CSysPartClientChgDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysPartClientChgDumpTrigger");
	pLogger->output(indent,0,"CSysPartClientChgDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysPartClientChgDumpTrigger::beforeAdd(CWriteableSysPartClientChg *pSysPartClientChg)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysPartClientChg,add");
		pSysPartClientChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysPartClientChg\n");
		pSysPartClientChg->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysPartClientChgDumpTrigger::beforeUpdate(CSysPartClientChg *pSysPartClientChg, CWriteableSysPartClientChg *pNewSysPartClientChg)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysPartClientChg,upd");
		pNewSysPartClientChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysPartClientChg\n");
		pNewSysPartClientChg->dumpDiff(m_output,pSysPartClientChg);
#endif
		fflush(m_output);
	}
}
	
void CSysPartClientChgDumpTrigger::beforeRemove(CSysPartClientChg *pSysPartClientChg)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysPartClientChg,del");
		pSysPartClientChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysPartClientChg\n");
		pSysPartClientChg->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysPosiLimitChgDumpTrigger::CSysPosiLimitChgDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysPosiLimitChgDumpTrigger::~CSysPosiLimitChgDumpTrigger(void)
{
}


void CSysPosiLimitChgDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysPosiLimitChgDumpTrigger");
	pLogger->output(indent,0,"CSysPosiLimitChgDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysPosiLimitChgDumpTrigger::beforeAdd(CWriteableSysPosiLimitChg *pSysPosiLimitChg)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysPosiLimitChg,add");
		pSysPosiLimitChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysPosiLimitChg\n");
		pSysPosiLimitChg->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysPosiLimitChgDumpTrigger::beforeUpdate(CSysPosiLimitChg *pSysPosiLimitChg, CWriteableSysPosiLimitChg *pNewSysPosiLimitChg)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysPosiLimitChg,upd");
		pNewSysPosiLimitChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysPosiLimitChg\n");
		pNewSysPosiLimitChg->dumpDiff(m_output,pSysPosiLimitChg);
#endif
		fflush(m_output);
	}
}
	
void CSysPosiLimitChgDumpTrigger::beforeRemove(CSysPosiLimitChg *pSysPosiLimitChg)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysPosiLimitChg,del");
		pSysPosiLimitChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysPosiLimitChg\n");
		pSysPosiLimitChg->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysClientPosiLimitChgDumpTrigger::CSysClientPosiLimitChgDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysClientPosiLimitChgDumpTrigger::~CSysClientPosiLimitChgDumpTrigger(void)
{
}


void CSysClientPosiLimitChgDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysClientPosiLimitChgDumpTrigger");
	pLogger->output(indent,0,"CSysClientPosiLimitChgDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysClientPosiLimitChgDumpTrigger::beforeAdd(CWriteableSysClientPosiLimitChg *pSysClientPosiLimitChg)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysClientPosiLimitChg,add");
		pSysClientPosiLimitChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysClientPosiLimitChg\n");
		pSysClientPosiLimitChg->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysClientPosiLimitChgDumpTrigger::beforeUpdate(CSysClientPosiLimitChg *pSysClientPosiLimitChg, CWriteableSysClientPosiLimitChg *pNewSysClientPosiLimitChg)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysClientPosiLimitChg,upd");
		pNewSysClientPosiLimitChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysClientPosiLimitChg\n");
		pNewSysClientPosiLimitChg->dumpDiff(m_output,pSysClientPosiLimitChg);
#endif
		fflush(m_output);
	}
}
	
void CSysClientPosiLimitChgDumpTrigger::beforeRemove(CSysClientPosiLimitChg *pSysClientPosiLimitChg)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysClientPosiLimitChg,del");
		pSysClientPosiLimitChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysClientPosiLimitChg\n");
		pSysClientPosiLimitChg->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysSpecPosiLimitChgDumpTrigger::CSysSpecPosiLimitChgDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysSpecPosiLimitChgDumpTrigger::~CSysSpecPosiLimitChgDumpTrigger(void)
{
}


void CSysSpecPosiLimitChgDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysSpecPosiLimitChgDumpTrigger");
	pLogger->output(indent,0,"CSysSpecPosiLimitChgDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysSpecPosiLimitChgDumpTrigger::beforeAdd(CWriteableSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysSpecPosiLimitChg,add");
		pSysSpecPosiLimitChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysSpecPosiLimitChg\n");
		pSysSpecPosiLimitChg->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysSpecPosiLimitChgDumpTrigger::beforeUpdate(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg, CWriteableSysSpecPosiLimitChg *pNewSysSpecPosiLimitChg)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysSpecPosiLimitChg,upd");
		pNewSysSpecPosiLimitChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysSpecPosiLimitChg\n");
		pNewSysSpecPosiLimitChg->dumpDiff(m_output,pSysSpecPosiLimitChg);
#endif
		fflush(m_output);
	}
}
	
void CSysSpecPosiLimitChgDumpTrigger::beforeRemove(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysSpecPosiLimitChg,del");
		pSysSpecPosiLimitChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysSpecPosiLimitChg\n");
		pSysSpecPosiLimitChg->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysHedgeDetailChgDumpTrigger::CSysHedgeDetailChgDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysHedgeDetailChgDumpTrigger::~CSysHedgeDetailChgDumpTrigger(void)
{
}


void CSysHedgeDetailChgDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysHedgeDetailChgDumpTrigger");
	pLogger->output(indent,0,"CSysHedgeDetailChgDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysHedgeDetailChgDumpTrigger::beforeAdd(CWriteableSysHedgeDetailChg *pSysHedgeDetailChg)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysHedgeDetailChg,add");
		pSysHedgeDetailChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysHedgeDetailChg\n");
		pSysHedgeDetailChg->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysHedgeDetailChgDumpTrigger::beforeUpdate(CSysHedgeDetailChg *pSysHedgeDetailChg, CWriteableSysHedgeDetailChg *pNewSysHedgeDetailChg)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysHedgeDetailChg,upd");
		pNewSysHedgeDetailChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysHedgeDetailChg\n");
		pNewSysHedgeDetailChg->dumpDiff(m_output,pSysHedgeDetailChg);
#endif
		fflush(m_output);
	}
}
	
void CSysHedgeDetailChgDumpTrigger::beforeRemove(CSysHedgeDetailChg *pSysHedgeDetailChg)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysHedgeDetailChg,del");
		pSysHedgeDetailChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysHedgeDetailChg\n");
		pSysHedgeDetailChg->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysParticipantChgDumpTrigger::CSysParticipantChgDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysParticipantChgDumpTrigger::~CSysParticipantChgDumpTrigger(void)
{
}


void CSysParticipantChgDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysParticipantChgDumpTrigger");
	pLogger->output(indent,0,"CSysParticipantChgDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysParticipantChgDumpTrigger::beforeAdd(CWriteableSysParticipantChg *pSysParticipantChg)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysParticipantChg,add");
		pSysParticipantChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysParticipantChg\n");
		pSysParticipantChg->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysParticipantChgDumpTrigger::beforeUpdate(CSysParticipantChg *pSysParticipantChg, CWriteableSysParticipantChg *pNewSysParticipantChg)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysParticipantChg,upd");
		pNewSysParticipantChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysParticipantChg\n");
		pNewSysParticipantChg->dumpDiff(m_output,pSysParticipantChg);
#endif
		fflush(m_output);
	}
}
	
void CSysParticipantChgDumpTrigger::beforeRemove(CSysParticipantChg *pSysParticipantChg)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysParticipantChg,del");
		pSysParticipantChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysParticipantChg\n");
		pSysParticipantChg->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMarginRateChgDumpTrigger::CSysMarginRateChgDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMarginRateChgDumpTrigger::~CSysMarginRateChgDumpTrigger(void)
{
}


void CSysMarginRateChgDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMarginRateChgDumpTrigger");
	pLogger->output(indent,0,"CSysMarginRateChgDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMarginRateChgDumpTrigger::beforeAdd(CWriteableSysMarginRateChg *pSysMarginRateChg)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMarginRateChg,add");
		pSysMarginRateChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMarginRateChg\n");
		pSysMarginRateChg->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMarginRateChgDumpTrigger::beforeUpdate(CSysMarginRateChg *pSysMarginRateChg, CWriteableSysMarginRateChg *pNewSysMarginRateChg)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMarginRateChg,upd");
		pNewSysMarginRateChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMarginRateChg\n");
		pNewSysMarginRateChg->dumpDiff(m_output,pSysMarginRateChg);
#endif
		fflush(m_output);
	}
}
	
void CSysMarginRateChgDumpTrigger::beforeRemove(CSysMarginRateChg *pSysMarginRateChg)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMarginRateChg,del");
		pSysMarginRateChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMarginRateChg\n");
		pSysMarginRateChg->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysUserIpChgDumpTrigger::CSysUserIpChgDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysUserIpChgDumpTrigger::~CSysUserIpChgDumpTrigger(void)
{
}


void CSysUserIpChgDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysUserIpChgDumpTrigger");
	pLogger->output(indent,0,"CSysUserIpChgDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysUserIpChgDumpTrigger::beforeAdd(CWriteableSysUserIpChg *pSysUserIpChg)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysUserIpChg,add");
		pSysUserIpChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysUserIpChg\n");
		pSysUserIpChg->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysUserIpChgDumpTrigger::beforeUpdate(CSysUserIpChg *pSysUserIpChg, CWriteableSysUserIpChg *pNewSysUserIpChg)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysUserIpChg,upd");
		pNewSysUserIpChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysUserIpChg\n");
		pNewSysUserIpChg->dumpDiff(m_output,pSysUserIpChg);
#endif
		fflush(m_output);
	}
}
	
void CSysUserIpChgDumpTrigger::beforeRemove(CSysUserIpChg *pSysUserIpChg)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysUserIpChg,del");
		pSysUserIpChg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysUserIpChg\n");
		pSysUserIpChg->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysPartTradeDumpTrigger::CSysPartTradeDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysPartTradeDumpTrigger::~CSysPartTradeDumpTrigger(void)
{
}


void CSysPartTradeDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysPartTradeDumpTrigger");
	pLogger->output(indent,0,"CSysPartTradeDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysPartTradeDumpTrigger::beforeAdd(CWriteableSysPartTrade *pSysPartTrade)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysPartTrade,add");
		pSysPartTrade->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysPartTrade\n");
		pSysPartTrade->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysPartTradeDumpTrigger::beforeUpdate(CSysPartTrade *pSysPartTrade, CWriteableSysPartTrade *pNewSysPartTrade)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysPartTrade,upd");
		pNewSysPartTrade->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysPartTrade\n");
		pNewSysPartTrade->dumpDiff(m_output,pSysPartTrade);
#endif
		fflush(m_output);
	}
}
	
void CSysPartTradeDumpTrigger::beforeRemove(CSysPartTrade *pSysPartTrade)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysPartTrade,del");
		pSysPartTrade->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysPartTrade\n");
		pSysPartTrade->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMdbObjectAttrDumpTrigger::CSysMdbObjectAttrDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMdbObjectAttrDumpTrigger::~CSysMdbObjectAttrDumpTrigger(void)
{
}


void CSysMdbObjectAttrDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMdbObjectAttrDumpTrigger");
	pLogger->output(indent,0,"CSysMdbObjectAttrDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMdbObjectAttrDumpTrigger::beforeAdd(CWriteableSysMdbObjectAttr *pSysMdbObjectAttr)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbObjectAttr,add");
		pSysMdbObjectAttr->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMdbObjectAttr\n");
		pSysMdbObjectAttr->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbObjectAttrDumpTrigger::beforeUpdate(CSysMdbObjectAttr *pSysMdbObjectAttr, CWriteableSysMdbObjectAttr *pNewSysMdbObjectAttr)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbObjectAttr,upd");
		pNewSysMdbObjectAttr->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMdbObjectAttr\n");
		pNewSysMdbObjectAttr->dumpDiff(m_output,pSysMdbObjectAttr);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbObjectAttrDumpTrigger::beforeRemove(CSysMdbObjectAttr *pSysMdbObjectAttr)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbObjectAttr,del");
		pSysMdbObjectAttr->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMdbObjectAttr\n");
		pSysMdbObjectAttr->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMdbSyslogInfoDumpTrigger::CSysMdbSyslogInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMdbSyslogInfoDumpTrigger::~CSysMdbSyslogInfoDumpTrigger(void)
{
}


void CSysMdbSyslogInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMdbSyslogInfoDumpTrigger");
	pLogger->output(indent,0,"CSysMdbSyslogInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMdbSyslogInfoDumpTrigger::beforeAdd(CWriteableSysMdbSyslogInfo *pSysMdbSyslogInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbSyslogInfo,add");
		pSysMdbSyslogInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMdbSyslogInfo\n");
		pSysMdbSyslogInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbSyslogInfoDumpTrigger::beforeUpdate(CSysMdbSyslogInfo *pSysMdbSyslogInfo, CWriteableSysMdbSyslogInfo *pNewSysMdbSyslogInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbSyslogInfo,upd");
		pNewSysMdbSyslogInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMdbSyslogInfo\n");
		pNewSysMdbSyslogInfo->dumpDiff(m_output,pSysMdbSyslogInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbSyslogInfoDumpTrigger::beforeRemove(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbSyslogInfo,del");
		pSysMdbSyslogInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMdbSyslogInfo\n");
		pSysMdbSyslogInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysUserInfoDumpTrigger::CSysUserInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysUserInfoDumpTrigger::~CSysUserInfoDumpTrigger(void)
{
}


void CSysUserInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysUserInfoDumpTrigger");
	pLogger->output(indent,0,"CSysUserInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysUserInfoDumpTrigger::beforeAdd(CWriteableSysUserInfo *pSysUserInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysUserInfo,add");
		pSysUserInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysUserInfo\n");
		pSysUserInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysUserInfoDumpTrigger::beforeUpdate(CSysUserInfo *pSysUserInfo, CWriteableSysUserInfo *pNewSysUserInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysUserInfo,upd");
		pNewSysUserInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysUserInfo\n");
		pNewSysUserInfo->dumpDiff(m_output,pSysUserInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysUserInfoDumpTrigger::beforeRemove(CSysUserInfo *pSysUserInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysUserInfo,del");
		pSysUserInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysUserInfo\n");
		pSysUserInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysOnlineUserInfoDumpTrigger::CSysOnlineUserInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysOnlineUserInfoDumpTrigger::~CSysOnlineUserInfoDumpTrigger(void)
{
}


void CSysOnlineUserInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysOnlineUserInfoDumpTrigger");
	pLogger->output(indent,0,"CSysOnlineUserInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysOnlineUserInfoDumpTrigger::beforeAdd(CWriteableSysOnlineUserInfo *pSysOnlineUserInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysOnlineUserInfo,add");
		pSysOnlineUserInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysOnlineUserInfo\n");
		pSysOnlineUserInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysOnlineUserInfoDumpTrigger::beforeUpdate(CSysOnlineUserInfo *pSysOnlineUserInfo, CWriteableSysOnlineUserInfo *pNewSysOnlineUserInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysOnlineUserInfo,upd");
		pNewSysOnlineUserInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysOnlineUserInfo\n");
		pNewSysOnlineUserInfo->dumpDiff(m_output,pSysOnlineUserInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysOnlineUserInfoDumpTrigger::beforeRemove(CSysOnlineUserInfo *pSysOnlineUserInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysOnlineUserInfo,del");
		pSysOnlineUserInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysOnlineUserInfo\n");
		pSysOnlineUserInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysWarningEventDumpTrigger::CSysWarningEventDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysWarningEventDumpTrigger::~CSysWarningEventDumpTrigger(void)
{
}


void CSysWarningEventDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysWarningEventDumpTrigger");
	pLogger->output(indent,0,"CSysWarningEventDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysWarningEventDumpTrigger::beforeAdd(CWriteableSysWarningEvent *pSysWarningEvent)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysWarningEvent,add");
		pSysWarningEvent->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysWarningEvent\n");
		pSysWarningEvent->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysWarningEventDumpTrigger::beforeUpdate(CSysWarningEvent *pSysWarningEvent, CWriteableSysWarningEvent *pNewSysWarningEvent)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysWarningEvent,upd");
		pNewSysWarningEvent->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysWarningEvent\n");
		pNewSysWarningEvent->dumpDiff(m_output,pSysWarningEvent);
#endif
		fflush(m_output);
	}
}
	
void CSysWarningEventDumpTrigger::beforeRemove(CSysWarningEvent *pSysWarningEvent)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysWarningEvent,del");
		pSysWarningEvent->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysWarningEvent\n");
		pSysWarningEvent->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysWarningQueryDumpTrigger::CSysWarningQueryDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysWarningQueryDumpTrigger::~CSysWarningQueryDumpTrigger(void)
{
}


void CSysWarningQueryDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysWarningQueryDumpTrigger");
	pLogger->output(indent,0,"CSysWarningQueryDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysWarningQueryDumpTrigger::beforeAdd(CWriteableSysWarningQuery *pSysWarningQuery)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysWarningQuery,add");
		pSysWarningQuery->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysWarningQuery\n");
		pSysWarningQuery->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysWarningQueryDumpTrigger::beforeUpdate(CSysWarningQuery *pSysWarningQuery, CWriteableSysWarningQuery *pNewSysWarningQuery)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysWarningQuery,upd");
		pNewSysWarningQuery->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysWarningQuery\n");
		pNewSysWarningQuery->dumpDiff(m_output,pSysWarningQuery);
#endif
		fflush(m_output);
	}
}
	
void CSysWarningQueryDumpTrigger::beforeRemove(CSysWarningQuery *pSysWarningQuery)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysWarningQuery,del");
		pSysWarningQuery->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysWarningQuery\n");
		pSysWarningQuery->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSyslogEventDumpTrigger::CSyslogEventDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSyslogEventDumpTrigger::~CSyslogEventDumpTrigger(void)
{
}


void CSyslogEventDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSyslogEventDumpTrigger");
	pLogger->output(indent,0,"CSyslogEventDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSyslogEventDumpTrigger::beforeAdd(CWriteableSyslogEvent *pSyslogEvent)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SyslogEvent,add");
		pSyslogEvent->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SyslogEvent\n");
		pSyslogEvent->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSyslogEventDumpTrigger::beforeUpdate(CSyslogEvent *pSyslogEvent, CWriteableSyslogEvent *pNewSyslogEvent)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SyslogEvent,upd");
		pNewSyslogEvent->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SyslogEvent\n");
		pNewSyslogEvent->dumpDiff(m_output,pSyslogEvent);
#endif
		fflush(m_output);
	}
}
	
void CSyslogEventDumpTrigger::beforeRemove(CSyslogEvent *pSyslogEvent)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SyslogEvent,del");
		pSyslogEvent->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SyslogEvent\n");
		pSyslogEvent->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysEventDescripDumpTrigger::CSysEventDescripDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysEventDescripDumpTrigger::~CSysEventDescripDumpTrigger(void)
{
}


void CSysEventDescripDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysEventDescripDumpTrigger");
	pLogger->output(indent,0,"CSysEventDescripDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysEventDescripDumpTrigger::beforeAdd(CWriteableSysEventDescrip *pSysEventDescrip)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysEventDescrip,add");
		pSysEventDescrip->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysEventDescrip\n");
		pSysEventDescrip->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysEventDescripDumpTrigger::beforeUpdate(CSysEventDescrip *pSysEventDescrip, CWriteableSysEventDescrip *pNewSysEventDescrip)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysEventDescrip,upd");
		pNewSysEventDescrip->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysEventDescrip\n");
		pNewSysEventDescrip->dumpDiff(m_output,pSysEventDescrip);
#endif
		fflush(m_output);
	}
}
	
void CSysEventDescripDumpTrigger::beforeRemove(CSysEventDescrip *pSysEventDescrip)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysEventDescrip,del");
		pSysEventDescrip->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysEventDescrip\n");
		pSysEventDescrip->dump(m_output);
#endif
		fflush(m_output);
	}
}

CRspQryHostEnvCommonDumpTrigger::CRspQryHostEnvCommonDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CRspQryHostEnvCommonDumpTrigger::~CRspQryHostEnvCommonDumpTrigger(void)
{
}


void CRspQryHostEnvCommonDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CRspQryHostEnvCommonDumpTrigger");
	pLogger->output(indent,0,"CRspQryHostEnvCommonDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CRspQryHostEnvCommonDumpTrigger::beforeAdd(CWriteableRspQryHostEnvCommon *pRspQryHostEnvCommon)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvCommon,add");
		pRspQryHostEnvCommon->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add RspQryHostEnvCommon\n");
		pRspQryHostEnvCommon->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CRspQryHostEnvCommonDumpTrigger::beforeUpdate(CRspQryHostEnvCommon *pRspQryHostEnvCommon, CWriteableRspQryHostEnvCommon *pNewRspQryHostEnvCommon)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvCommon,upd");
		pNewRspQryHostEnvCommon->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update RspQryHostEnvCommon\n");
		pNewRspQryHostEnvCommon->dumpDiff(m_output,pRspQryHostEnvCommon);
#endif
		fflush(m_output);
	}
}
	
void CRspQryHostEnvCommonDumpTrigger::beforeRemove(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvCommon,del");
		pRspQryHostEnvCommon->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove RspQryHostEnvCommon\n");
		pRspQryHostEnvCommon->dump(m_output);
#endif
		fflush(m_output);
	}
}

CRspQryHostEnvLanDumpTrigger::CRspQryHostEnvLanDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CRspQryHostEnvLanDumpTrigger::~CRspQryHostEnvLanDumpTrigger(void)
{
}


void CRspQryHostEnvLanDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CRspQryHostEnvLanDumpTrigger");
	pLogger->output(indent,0,"CRspQryHostEnvLanDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CRspQryHostEnvLanDumpTrigger::beforeAdd(CWriteableRspQryHostEnvLan *pRspQryHostEnvLan)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvLan,add");
		pRspQryHostEnvLan->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add RspQryHostEnvLan\n");
		pRspQryHostEnvLan->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CRspQryHostEnvLanDumpTrigger::beforeUpdate(CRspQryHostEnvLan *pRspQryHostEnvLan, CWriteableRspQryHostEnvLan *pNewRspQryHostEnvLan)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvLan,upd");
		pNewRspQryHostEnvLan->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update RspQryHostEnvLan\n");
		pNewRspQryHostEnvLan->dumpDiff(m_output,pRspQryHostEnvLan);
#endif
		fflush(m_output);
	}
}
	
void CRspQryHostEnvLanDumpTrigger::beforeRemove(CRspQryHostEnvLan *pRspQryHostEnvLan)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvLan,del");
		pRspQryHostEnvLan->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove RspQryHostEnvLan\n");
		pRspQryHostEnvLan->dump(m_output);
#endif
		fflush(m_output);
	}
}

CRspQryHostEnvStorageDumpTrigger::CRspQryHostEnvStorageDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CRspQryHostEnvStorageDumpTrigger::~CRspQryHostEnvStorageDumpTrigger(void)
{
}


void CRspQryHostEnvStorageDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CRspQryHostEnvStorageDumpTrigger");
	pLogger->output(indent,0,"CRspQryHostEnvStorageDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CRspQryHostEnvStorageDumpTrigger::beforeAdd(CWriteableRspQryHostEnvStorage *pRspQryHostEnvStorage)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvStorage,add");
		pRspQryHostEnvStorage->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add RspQryHostEnvStorage\n");
		pRspQryHostEnvStorage->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CRspQryHostEnvStorageDumpTrigger::beforeUpdate(CRspQryHostEnvStorage *pRspQryHostEnvStorage, CWriteableRspQryHostEnvStorage *pNewRspQryHostEnvStorage)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvStorage,upd");
		pNewRspQryHostEnvStorage->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update RspQryHostEnvStorage\n");
		pNewRspQryHostEnvStorage->dumpDiff(m_output,pRspQryHostEnvStorage);
#endif
		fflush(m_output);
	}
}
	
void CRspQryHostEnvStorageDumpTrigger::beforeRemove(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvStorage,del");
		pRspQryHostEnvStorage->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove RspQryHostEnvStorage\n");
		pRspQryHostEnvStorage->dump(m_output);
#endif
		fflush(m_output);
	}
}

CRspQryHostEnvIODumpTrigger::CRspQryHostEnvIODumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CRspQryHostEnvIODumpTrigger::~CRspQryHostEnvIODumpTrigger(void)
{
}


void CRspQryHostEnvIODumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CRspQryHostEnvIODumpTrigger");
	pLogger->output(indent,0,"CRspQryHostEnvIODumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CRspQryHostEnvIODumpTrigger::beforeAdd(CWriteableRspQryHostEnvIO *pRspQryHostEnvIO)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvIO,add");
		pRspQryHostEnvIO->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add RspQryHostEnvIO\n");
		pRspQryHostEnvIO->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CRspQryHostEnvIODumpTrigger::beforeUpdate(CRspQryHostEnvIO *pRspQryHostEnvIO, CWriteableRspQryHostEnvIO *pNewRspQryHostEnvIO)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvIO,upd");
		pNewRspQryHostEnvIO->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update RspQryHostEnvIO\n");
		pNewRspQryHostEnvIO->dumpDiff(m_output,pRspQryHostEnvIO);
#endif
		fflush(m_output);
	}
}
	
void CRspQryHostEnvIODumpTrigger::beforeRemove(CRspQryHostEnvIO *pRspQryHostEnvIO)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvIO,del");
		pRspQryHostEnvIO->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove RspQryHostEnvIO\n");
		pRspQryHostEnvIO->dump(m_output);
#endif
		fflush(m_output);
	}
}

CRspQryHostEnvFSDumpTrigger::CRspQryHostEnvFSDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CRspQryHostEnvFSDumpTrigger::~CRspQryHostEnvFSDumpTrigger(void)
{
}


void CRspQryHostEnvFSDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CRspQryHostEnvFSDumpTrigger");
	pLogger->output(indent,0,"CRspQryHostEnvFSDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CRspQryHostEnvFSDumpTrigger::beforeAdd(CWriteableRspQryHostEnvFS *pRspQryHostEnvFS)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvFS,add");
		pRspQryHostEnvFS->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add RspQryHostEnvFS\n");
		pRspQryHostEnvFS->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CRspQryHostEnvFSDumpTrigger::beforeUpdate(CRspQryHostEnvFS *pRspQryHostEnvFS, CWriteableRspQryHostEnvFS *pNewRspQryHostEnvFS)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvFS,upd");
		pNewRspQryHostEnvFS->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update RspQryHostEnvFS\n");
		pNewRspQryHostEnvFS->dumpDiff(m_output,pRspQryHostEnvFS);
#endif
		fflush(m_output);
	}
}
	
void CRspQryHostEnvFSDumpTrigger::beforeRemove(CRspQryHostEnvFS *pRspQryHostEnvFS)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvFS,del");
		pRspQryHostEnvFS->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove RspQryHostEnvFS\n");
		pRspQryHostEnvFS->dump(m_output);
#endif
		fflush(m_output);
	}
}

CRspQryHostEnvSwapDumpTrigger::CRspQryHostEnvSwapDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CRspQryHostEnvSwapDumpTrigger::~CRspQryHostEnvSwapDumpTrigger(void)
{
}


void CRspQryHostEnvSwapDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CRspQryHostEnvSwapDumpTrigger");
	pLogger->output(indent,0,"CRspQryHostEnvSwapDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CRspQryHostEnvSwapDumpTrigger::beforeAdd(CWriteableRspQryHostEnvSwap *pRspQryHostEnvSwap)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvSwap,add");
		pRspQryHostEnvSwap->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add RspQryHostEnvSwap\n");
		pRspQryHostEnvSwap->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CRspQryHostEnvSwapDumpTrigger::beforeUpdate(CRspQryHostEnvSwap *pRspQryHostEnvSwap, CWriteableRspQryHostEnvSwap *pNewRspQryHostEnvSwap)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvSwap,upd");
		pNewRspQryHostEnvSwap->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update RspQryHostEnvSwap\n");
		pNewRspQryHostEnvSwap->dumpDiff(m_output,pRspQryHostEnvSwap);
#endif
		fflush(m_output);
	}
}
	
void CRspQryHostEnvSwapDumpTrigger::beforeRemove(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvSwap,del");
		pRspQryHostEnvSwap->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove RspQryHostEnvSwap\n");
		pRspQryHostEnvSwap->dump(m_output);
#endif
		fflush(m_output);
	}
}

CRspQryHostEnvLanCfgDumpTrigger::CRspQryHostEnvLanCfgDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CRspQryHostEnvLanCfgDumpTrigger::~CRspQryHostEnvLanCfgDumpTrigger(void)
{
}


void CRspQryHostEnvLanCfgDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CRspQryHostEnvLanCfgDumpTrigger");
	pLogger->output(indent,0,"CRspQryHostEnvLanCfgDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CRspQryHostEnvLanCfgDumpTrigger::beforeAdd(CWriteableRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvLanCfg,add");
		pRspQryHostEnvLanCfg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add RspQryHostEnvLanCfg\n");
		pRspQryHostEnvLanCfg->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CRspQryHostEnvLanCfgDumpTrigger::beforeUpdate(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, CWriteableRspQryHostEnvLanCfg *pNewRspQryHostEnvLanCfg)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvLanCfg,upd");
		pNewRspQryHostEnvLanCfg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update RspQryHostEnvLanCfg\n");
		pNewRspQryHostEnvLanCfg->dumpDiff(m_output,pRspQryHostEnvLanCfg);
#endif
		fflush(m_output);
	}
}
	
void CRspQryHostEnvLanCfgDumpTrigger::beforeRemove(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"RspQryHostEnvLanCfg,del");
		pRspQryHostEnvLanCfg->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove RspQryHostEnvLanCfg\n");
		pRspQryHostEnvLanCfg->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMdbTopCpuInfoDumpTrigger::CSysMdbTopCpuInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMdbTopCpuInfoDumpTrigger::~CSysMdbTopCpuInfoDumpTrigger(void)
{
}


void CSysMdbTopCpuInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMdbTopCpuInfoDumpTrigger");
	pLogger->output(indent,0,"CSysMdbTopCpuInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMdbTopCpuInfoDumpTrigger::beforeAdd(CWriteableSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbTopCpuInfo,add");
		pSysMdbTopCpuInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMdbTopCpuInfo\n");
		pSysMdbTopCpuInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbTopCpuInfoDumpTrigger::beforeUpdate(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo, CWriteableSysMdbTopCpuInfo *pNewSysMdbTopCpuInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbTopCpuInfo,upd");
		pNewSysMdbTopCpuInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMdbTopCpuInfo\n");
		pNewSysMdbTopCpuInfo->dumpDiff(m_output,pSysMdbTopCpuInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbTopCpuInfoDumpTrigger::beforeRemove(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbTopCpuInfo,del");
		pSysMdbTopCpuInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMdbTopCpuInfo\n");
		pSysMdbTopCpuInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMdbTopMemInfoDumpTrigger::CSysMdbTopMemInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMdbTopMemInfoDumpTrigger::~CSysMdbTopMemInfoDumpTrigger(void)
{
}


void CSysMdbTopMemInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMdbTopMemInfoDumpTrigger");
	pLogger->output(indent,0,"CSysMdbTopMemInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMdbTopMemInfoDumpTrigger::beforeAdd(CWriteableSysMdbTopMemInfo *pSysMdbTopMemInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbTopMemInfo,add");
		pSysMdbTopMemInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMdbTopMemInfo\n");
		pSysMdbTopMemInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbTopMemInfoDumpTrigger::beforeUpdate(CSysMdbTopMemInfo *pSysMdbTopMemInfo, CWriteableSysMdbTopMemInfo *pNewSysMdbTopMemInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbTopMemInfo,upd");
		pNewSysMdbTopMemInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMdbTopMemInfo\n");
		pNewSysMdbTopMemInfo->dumpDiff(m_output,pSysMdbTopMemInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbTopMemInfoDumpTrigger::beforeRemove(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbTopMemInfo,del");
		pSysMdbTopMemInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMdbTopMemInfo\n");
		pSysMdbTopMemInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMdbTopProcessInfoDumpTrigger::CSysMdbTopProcessInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMdbTopProcessInfoDumpTrigger::~CSysMdbTopProcessInfoDumpTrigger(void)
{
}


void CSysMdbTopProcessInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMdbTopProcessInfoDumpTrigger");
	pLogger->output(indent,0,"CSysMdbTopProcessInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMdbTopProcessInfoDumpTrigger::beforeAdd(CWriteableSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbTopProcessInfo,add");
		pSysMdbTopProcessInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMdbTopProcessInfo\n");
		pSysMdbTopProcessInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbTopProcessInfoDumpTrigger::beforeUpdate(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo, CWriteableSysMdbTopProcessInfo *pNewSysMdbTopProcessInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbTopProcessInfo,upd");
		pNewSysMdbTopProcessInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMdbTopProcessInfo\n");
		pNewSysMdbTopProcessInfo->dumpDiff(m_output,pSysMdbTopProcessInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbTopProcessInfoDumpTrigger::beforeRemove(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbTopProcessInfo,del");
		pSysMdbTopProcessInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMdbTopProcessInfo\n");
		pSysMdbTopProcessInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMdbFileSystemInfoDumpTrigger::CSysMdbFileSystemInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMdbFileSystemInfoDumpTrigger::~CSysMdbFileSystemInfoDumpTrigger(void)
{
}


void CSysMdbFileSystemInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMdbFileSystemInfoDumpTrigger");
	pLogger->output(indent,0,"CSysMdbFileSystemInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMdbFileSystemInfoDumpTrigger::beforeAdd(CWriteableSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbFileSystemInfo,add");
		pSysMdbFileSystemInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMdbFileSystemInfo\n");
		pSysMdbFileSystemInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbFileSystemInfoDumpTrigger::beforeUpdate(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo, CWriteableSysMdbFileSystemInfo *pNewSysMdbFileSystemInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbFileSystemInfo,upd");
		pNewSysMdbFileSystemInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMdbFileSystemInfo\n");
		pNewSysMdbFileSystemInfo->dumpDiff(m_output,pSysMdbFileSystemInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbFileSystemInfoDumpTrigger::beforeRemove(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbFileSystemInfo,del");
		pSysMdbFileSystemInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMdbFileSystemInfo\n");
		pSysMdbFileSystemInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMdbNetworkInfoDumpTrigger::CSysMdbNetworkInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMdbNetworkInfoDumpTrigger::~CSysMdbNetworkInfoDumpTrigger(void)
{
}


void CSysMdbNetworkInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMdbNetworkInfoDumpTrigger");
	pLogger->output(indent,0,"CSysMdbNetworkInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMdbNetworkInfoDumpTrigger::beforeAdd(CWriteableSysMdbNetworkInfo *pSysMdbNetworkInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbNetworkInfo,add");
		pSysMdbNetworkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMdbNetworkInfo\n");
		pSysMdbNetworkInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbNetworkInfoDumpTrigger::beforeUpdate(CSysMdbNetworkInfo *pSysMdbNetworkInfo, CWriteableSysMdbNetworkInfo *pNewSysMdbNetworkInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbNetworkInfo,upd");
		pNewSysMdbNetworkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMdbNetworkInfo\n");
		pNewSysMdbNetworkInfo->dumpDiff(m_output,pSysMdbNetworkInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbNetworkInfoDumpTrigger::beforeRemove(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbNetworkInfo,del");
		pSysMdbNetworkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMdbNetworkInfo\n");
		pSysMdbNetworkInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysParticipantInitDumpTrigger::CSysParticipantInitDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysParticipantInitDumpTrigger::~CSysParticipantInitDumpTrigger(void)
{
}


void CSysParticipantInitDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysParticipantInitDumpTrigger");
	pLogger->output(indent,0,"CSysParticipantInitDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysParticipantInitDumpTrigger::beforeAdd(CWriteableSysParticipantInit *pSysParticipantInit)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysParticipantInit,add");
		pSysParticipantInit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysParticipantInit\n");
		pSysParticipantInit->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysParticipantInitDumpTrigger::beforeUpdate(CSysParticipantInit *pSysParticipantInit, CWriteableSysParticipantInit *pNewSysParticipantInit)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysParticipantInit,upd");
		pNewSysParticipantInit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysParticipantInit\n");
		pNewSysParticipantInit->dumpDiff(m_output,pSysParticipantInit);
#endif
		fflush(m_output);
	}
}
	
void CSysParticipantInitDumpTrigger::beforeRemove(CSysParticipantInit *pSysParticipantInit)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysParticipantInit,del");
		pSysParticipantInit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysParticipantInit\n");
		pSysParticipantInit->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysUserInitDumpTrigger::CSysUserInitDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysUserInitDumpTrigger::~CSysUserInitDumpTrigger(void)
{
}


void CSysUserInitDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysUserInitDumpTrigger");
	pLogger->output(indent,0,"CSysUserInitDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysUserInitDumpTrigger::beforeAdd(CWriteableSysUserInit *pSysUserInit)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysUserInit,add");
		pSysUserInit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysUserInit\n");
		pSysUserInit->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysUserInitDumpTrigger::beforeUpdate(CSysUserInit *pSysUserInit, CWriteableSysUserInit *pNewSysUserInit)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysUserInit,upd");
		pNewSysUserInit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysUserInit\n");
		pNewSysUserInit->dumpDiff(m_output,pSysUserInit);
#endif
		fflush(m_output);
	}
}
	
void CSysUserInitDumpTrigger::beforeRemove(CSysUserInit *pSysUserInit)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysUserInit,del");
		pSysUserInit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysUserInit\n");
		pSysUserInit->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysClientInitDumpTrigger::CSysClientInitDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysClientInitDumpTrigger::~CSysClientInitDumpTrigger(void)
{
}


void CSysClientInitDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysClientInitDumpTrigger");
	pLogger->output(indent,0,"CSysClientInitDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysClientInitDumpTrigger::beforeAdd(CWriteableSysClientInit *pSysClientInit)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysClientInit,add");
		pSysClientInit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysClientInit\n");
		pSysClientInit->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysClientInitDumpTrigger::beforeUpdate(CSysClientInit *pSysClientInit, CWriteableSysClientInit *pNewSysClientInit)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysClientInit,upd");
		pNewSysClientInit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysClientInit\n");
		pNewSysClientInit->dumpDiff(m_output,pSysClientInit);
#endif
		fflush(m_output);
	}
}
	
void CSysClientInitDumpTrigger::beforeRemove(CSysClientInit *pSysClientInit)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysClientInit,del");
		pSysClientInit->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysClientInit\n");
		pSysClientInit->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysTradeUserLoginInfoDumpTrigger::CSysTradeUserLoginInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysTradeUserLoginInfoDumpTrigger::~CSysTradeUserLoginInfoDumpTrigger(void)
{
}


void CSysTradeUserLoginInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysTradeUserLoginInfoDumpTrigger");
	pLogger->output(indent,0,"CSysTradeUserLoginInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysTradeUserLoginInfoDumpTrigger::beforeAdd(CWriteableSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysTradeUserLoginInfo,add");
		pSysTradeUserLoginInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysTradeUserLoginInfo\n");
		pSysTradeUserLoginInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysTradeUserLoginInfoDumpTrigger::beforeUpdate(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo, CWriteableSysTradeUserLoginInfo *pNewSysTradeUserLoginInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysTradeUserLoginInfo,upd");
		pNewSysTradeUserLoginInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysTradeUserLoginInfo\n");
		pNewSysTradeUserLoginInfo->dumpDiff(m_output,pSysTradeUserLoginInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysTradeUserLoginInfoDumpTrigger::beforeRemove(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysTradeUserLoginInfo,del");
		pSysTradeUserLoginInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysTradeUserLoginInfo\n");
		pSysTradeUserLoginInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMdbWebAppInfoDumpTrigger::CSysMdbWebAppInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMdbWebAppInfoDumpTrigger::~CSysMdbWebAppInfoDumpTrigger(void)
{
}


void CSysMdbWebAppInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMdbWebAppInfoDumpTrigger");
	pLogger->output(indent,0,"CSysMdbWebAppInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMdbWebAppInfoDumpTrigger::beforeAdd(CWriteableSysMdbWebAppInfo *pSysMdbWebAppInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbWebAppInfo,add");
		pSysMdbWebAppInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMdbWebAppInfo\n");
		pSysMdbWebAppInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbWebAppInfoDumpTrigger::beforeUpdate(CSysMdbWebAppInfo *pSysMdbWebAppInfo, CWriteableSysMdbWebAppInfo *pNewSysMdbWebAppInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbWebAppInfo,upd");
		pNewSysMdbWebAppInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMdbWebAppInfo\n");
		pNewSysMdbWebAppInfo->dumpDiff(m_output,pSysMdbWebAppInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbWebAppInfoDumpTrigger::beforeRemove(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbWebAppInfo,del");
		pSysMdbWebAppInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMdbWebAppInfo\n");
		pSysMdbWebAppInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMdbMemPoolInfoDumpTrigger::CSysMdbMemPoolInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMdbMemPoolInfoDumpTrigger::~CSysMdbMemPoolInfoDumpTrigger(void)
{
}


void CSysMdbMemPoolInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMdbMemPoolInfoDumpTrigger");
	pLogger->output(indent,0,"CSysMdbMemPoolInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMdbMemPoolInfoDumpTrigger::beforeAdd(CWriteableSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbMemPoolInfo,add");
		pSysMdbMemPoolInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMdbMemPoolInfo\n");
		pSysMdbMemPoolInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbMemPoolInfoDumpTrigger::beforeUpdate(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo, CWriteableSysMdbMemPoolInfo *pNewSysMdbMemPoolInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbMemPoolInfo,upd");
		pNewSysMdbMemPoolInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMdbMemPoolInfo\n");
		pNewSysMdbMemPoolInfo->dumpDiff(m_output,pSysMdbMemPoolInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbMemPoolInfoDumpTrigger::beforeRemove(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbMemPoolInfo,del");
		pSysMdbMemPoolInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMdbMemPoolInfo\n");
		pSysMdbMemPoolInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMdbConnectorInfoDumpTrigger::CSysMdbConnectorInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMdbConnectorInfoDumpTrigger::~CSysMdbConnectorInfoDumpTrigger(void)
{
}


void CSysMdbConnectorInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMdbConnectorInfoDumpTrigger");
	pLogger->output(indent,0,"CSysMdbConnectorInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMdbConnectorInfoDumpTrigger::beforeAdd(CWriteableSysMdbConnectorInfo *pSysMdbConnectorInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbConnectorInfo,add");
		pSysMdbConnectorInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMdbConnectorInfo\n");
		pSysMdbConnectorInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbConnectorInfoDumpTrigger::beforeUpdate(CSysMdbConnectorInfo *pSysMdbConnectorInfo, CWriteableSysMdbConnectorInfo *pNewSysMdbConnectorInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbConnectorInfo,upd");
		pNewSysMdbConnectorInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMdbConnectorInfo\n");
		pNewSysMdbConnectorInfo->dumpDiff(m_output,pSysMdbConnectorInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbConnectorInfoDumpTrigger::beforeRemove(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbConnectorInfo,del");
		pSysMdbConnectorInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMdbConnectorInfo\n");
		pSysMdbConnectorInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMdbDBQueryDumpTrigger::CSysMdbDBQueryDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMdbDBQueryDumpTrigger::~CSysMdbDBQueryDumpTrigger(void)
{
}


void CSysMdbDBQueryDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMdbDBQueryDumpTrigger");
	pLogger->output(indent,0,"CSysMdbDBQueryDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMdbDBQueryDumpTrigger::beforeAdd(CWriteableSysMdbDBQuery *pSysMdbDBQuery)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbDBQuery,add");
		pSysMdbDBQuery->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMdbDBQuery\n");
		pSysMdbDBQuery->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbDBQueryDumpTrigger::beforeUpdate(CSysMdbDBQuery *pSysMdbDBQuery, CWriteableSysMdbDBQuery *pNewSysMdbDBQuery)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbDBQuery,upd");
		pNewSysMdbDBQuery->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMdbDBQuery\n");
		pNewSysMdbDBQuery->dumpDiff(m_output,pSysMdbDBQuery);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbDBQueryDumpTrigger::beforeRemove(CSysMdbDBQuery *pSysMdbDBQuery)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbDBQuery,del");
		pSysMdbDBQuery->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMdbDBQuery\n");
		pSysMdbDBQuery->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetAreaDumpTrigger::CSysNetAreaDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetAreaDumpTrigger::~CSysNetAreaDumpTrigger(void)
{
}


void CSysNetAreaDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetAreaDumpTrigger");
	pLogger->output(indent,0,"CSysNetAreaDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetAreaDumpTrigger::beforeAdd(CWriteableSysNetArea *pSysNetArea)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetArea,add");
		pSysNetArea->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetArea\n");
		pSysNetArea->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetAreaDumpTrigger::beforeUpdate(CSysNetArea *pSysNetArea, CWriteableSysNetArea *pNewSysNetArea)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetArea,upd");
		pNewSysNetArea->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetArea\n");
		pNewSysNetArea->dumpDiff(m_output,pSysNetArea);
#endif
		fflush(m_output);
	}
}
	
void CSysNetAreaDumpTrigger::beforeRemove(CSysNetArea *pSysNetArea)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetArea,del");
		pSysNetArea->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetArea\n");
		pSysNetArea->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetSubAreaDumpTrigger::CSysNetSubAreaDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetSubAreaDumpTrigger::~CSysNetSubAreaDumpTrigger(void)
{
}


void CSysNetSubAreaDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetSubAreaDumpTrigger");
	pLogger->output(indent,0,"CSysNetSubAreaDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetSubAreaDumpTrigger::beforeAdd(CWriteableSysNetSubArea *pSysNetSubArea)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetSubArea,add");
		pSysNetSubArea->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetSubArea\n");
		pSysNetSubArea->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetSubAreaDumpTrigger::beforeUpdate(CSysNetSubArea *pSysNetSubArea, CWriteableSysNetSubArea *pNewSysNetSubArea)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetSubArea,upd");
		pNewSysNetSubArea->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetSubArea\n");
		pNewSysNetSubArea->dumpDiff(m_output,pSysNetSubArea);
#endif
		fflush(m_output);
	}
}
	
void CSysNetSubAreaDumpTrigger::beforeRemove(CSysNetSubArea *pSysNetSubArea)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetSubArea,del");
		pSysNetSubArea->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetSubArea\n");
		pSysNetSubArea->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetSubAreaIPDumpTrigger::CSysNetSubAreaIPDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetSubAreaIPDumpTrigger::~CSysNetSubAreaIPDumpTrigger(void)
{
}


void CSysNetSubAreaIPDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetSubAreaIPDumpTrigger");
	pLogger->output(indent,0,"CSysNetSubAreaIPDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetSubAreaIPDumpTrigger::beforeAdd(CWriteableSysNetSubAreaIP *pSysNetSubAreaIP)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetSubAreaIP,add");
		pSysNetSubAreaIP->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetSubAreaIP\n");
		pSysNetSubAreaIP->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetSubAreaIPDumpTrigger::beforeUpdate(CSysNetSubAreaIP *pSysNetSubAreaIP, CWriteableSysNetSubAreaIP *pNewSysNetSubAreaIP)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetSubAreaIP,upd");
		pNewSysNetSubAreaIP->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetSubAreaIP\n");
		pNewSysNetSubAreaIP->dumpDiff(m_output,pSysNetSubAreaIP);
#endif
		fflush(m_output);
	}
}
	
void CSysNetSubAreaIPDumpTrigger::beforeRemove(CSysNetSubAreaIP *pSysNetSubAreaIP)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetSubAreaIP,del");
		pSysNetSubAreaIP->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetSubAreaIP\n");
		pSysNetSubAreaIP->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetFuncAreaDumpTrigger::CSysNetFuncAreaDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetFuncAreaDumpTrigger::~CSysNetFuncAreaDumpTrigger(void)
{
}


void CSysNetFuncAreaDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetFuncAreaDumpTrigger");
	pLogger->output(indent,0,"CSysNetFuncAreaDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetFuncAreaDumpTrigger::beforeAdd(CWriteableSysNetFuncArea *pSysNetFuncArea)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetFuncArea,add");
		pSysNetFuncArea->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetFuncArea\n");
		pSysNetFuncArea->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetFuncAreaDumpTrigger::beforeUpdate(CSysNetFuncArea *pSysNetFuncArea, CWriteableSysNetFuncArea *pNewSysNetFuncArea)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetFuncArea,upd");
		pNewSysNetFuncArea->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetFuncArea\n");
		pNewSysNetFuncArea->dumpDiff(m_output,pSysNetFuncArea);
#endif
		fflush(m_output);
	}
}
	
void CSysNetFuncAreaDumpTrigger::beforeRemove(CSysNetFuncArea *pSysNetFuncArea)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetFuncArea,del");
		pSysNetFuncArea->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetFuncArea\n");
		pSysNetFuncArea->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetDeviceDumpTrigger::CSysNetDeviceDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetDeviceDumpTrigger::~CSysNetDeviceDumpTrigger(void)
{
}


void CSysNetDeviceDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetDeviceDumpTrigger");
	pLogger->output(indent,0,"CSysNetDeviceDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetDeviceDumpTrigger::beforeAdd(CWriteableSysNetDevice *pSysNetDevice)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDevice,add");
		pSysNetDevice->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetDevice\n");
		pSysNetDevice->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetDeviceDumpTrigger::beforeUpdate(CSysNetDevice *pSysNetDevice, CWriteableSysNetDevice *pNewSysNetDevice)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDevice,upd");
		pNewSysNetDevice->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetDevice\n");
		pNewSysNetDevice->dumpDiff(m_output,pSysNetDevice);
#endif
		fflush(m_output);
	}
}
	
void CSysNetDeviceDumpTrigger::beforeRemove(CSysNetDevice *pSysNetDevice)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDevice,del");
		pSysNetDevice->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetDevice\n");
		pSysNetDevice->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetDeviceLinkedDumpTrigger::CSysNetDeviceLinkedDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetDeviceLinkedDumpTrigger::~CSysNetDeviceLinkedDumpTrigger(void)
{
}


void CSysNetDeviceLinkedDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetDeviceLinkedDumpTrigger");
	pLogger->output(indent,0,"CSysNetDeviceLinkedDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetDeviceLinkedDumpTrigger::beforeAdd(CWriteableSysNetDeviceLinked *pSysNetDeviceLinked)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDeviceLinked,add");
		pSysNetDeviceLinked->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetDeviceLinked\n");
		pSysNetDeviceLinked->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetDeviceLinkedDumpTrigger::beforeUpdate(CSysNetDeviceLinked *pSysNetDeviceLinked, CWriteableSysNetDeviceLinked *pNewSysNetDeviceLinked)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDeviceLinked,upd");
		pNewSysNetDeviceLinked->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetDeviceLinked\n");
		pNewSysNetDeviceLinked->dumpDiff(m_output,pSysNetDeviceLinked);
#endif
		fflush(m_output);
	}
}
	
void CSysNetDeviceLinkedDumpTrigger::beforeRemove(CSysNetDeviceLinked *pSysNetDeviceLinked)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDeviceLinked,del");
		pSysNetDeviceLinked->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetDeviceLinked\n");
		pSysNetDeviceLinked->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetOIDDumpTrigger::CSysNetOIDDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetOIDDumpTrigger::~CSysNetOIDDumpTrigger(void)
{
}


void CSysNetOIDDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetOIDDumpTrigger");
	pLogger->output(indent,0,"CSysNetOIDDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetOIDDumpTrigger::beforeAdd(CWriteableSysNetOID *pSysNetOID)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetOID,add");
		pSysNetOID->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetOID\n");
		pSysNetOID->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetOIDDumpTrigger::beforeUpdate(CSysNetOID *pSysNetOID, CWriteableSysNetOID *pNewSysNetOID)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetOID,upd");
		pNewSysNetOID->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetOID\n");
		pNewSysNetOID->dumpDiff(m_output,pSysNetOID);
#endif
		fflush(m_output);
	}
}
	
void CSysNetOIDDumpTrigger::beforeRemove(CSysNetOID *pSysNetOID)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetOID,del");
		pSysNetOID->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetOID\n");
		pSysNetOID->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetDeviceTypeDumpTrigger::CSysNetDeviceTypeDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetDeviceTypeDumpTrigger::~CSysNetDeviceTypeDumpTrigger(void)
{
}


void CSysNetDeviceTypeDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetDeviceTypeDumpTrigger");
	pLogger->output(indent,0,"CSysNetDeviceTypeDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetDeviceTypeDumpTrigger::beforeAdd(CWriteableSysNetDeviceType *pSysNetDeviceType)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDeviceType,add");
		pSysNetDeviceType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetDeviceType\n");
		pSysNetDeviceType->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetDeviceTypeDumpTrigger::beforeUpdate(CSysNetDeviceType *pSysNetDeviceType, CWriteableSysNetDeviceType *pNewSysNetDeviceType)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDeviceType,upd");
		pNewSysNetDeviceType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetDeviceType\n");
		pNewSysNetDeviceType->dumpDiff(m_output,pSysNetDeviceType);
#endif
		fflush(m_output);
	}
}
	
void CSysNetDeviceTypeDumpTrigger::beforeRemove(CSysNetDeviceType *pSysNetDeviceType)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDeviceType,del");
		pSysNetDeviceType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetDeviceType\n");
		pSysNetDeviceType->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetTimePolicyDumpTrigger::CSysNetTimePolicyDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetTimePolicyDumpTrigger::~CSysNetTimePolicyDumpTrigger(void)
{
}


void CSysNetTimePolicyDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetTimePolicyDumpTrigger");
	pLogger->output(indent,0,"CSysNetTimePolicyDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetTimePolicyDumpTrigger::beforeAdd(CWriteableSysNetTimePolicy *pSysNetTimePolicy)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetTimePolicy,add");
		pSysNetTimePolicy->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetTimePolicy\n");
		pSysNetTimePolicy->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetTimePolicyDumpTrigger::beforeUpdate(CSysNetTimePolicy *pSysNetTimePolicy, CWriteableSysNetTimePolicy *pNewSysNetTimePolicy)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetTimePolicy,upd");
		pNewSysNetTimePolicy->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetTimePolicy\n");
		pNewSysNetTimePolicy->dumpDiff(m_output,pSysNetTimePolicy);
#endif
		fflush(m_output);
	}
}
	
void CSysNetTimePolicyDumpTrigger::beforeRemove(CSysNetTimePolicy *pSysNetTimePolicy)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetTimePolicy,del");
		pSysNetTimePolicy->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetTimePolicy\n");
		pSysNetTimePolicy->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetGatherTaskDumpTrigger::CSysNetGatherTaskDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetGatherTaskDumpTrigger::~CSysNetGatherTaskDumpTrigger(void)
{
}


void CSysNetGatherTaskDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetGatherTaskDumpTrigger");
	pLogger->output(indent,0,"CSysNetGatherTaskDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetGatherTaskDumpTrigger::beforeAdd(CWriteableSysNetGatherTask *pSysNetGatherTask)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetGatherTask,add");
		pSysNetGatherTask->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetGatherTask\n");
		pSysNetGatherTask->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetGatherTaskDumpTrigger::beforeUpdate(CSysNetGatherTask *pSysNetGatherTask, CWriteableSysNetGatherTask *pNewSysNetGatherTask)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetGatherTask,upd");
		pNewSysNetGatherTask->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetGatherTask\n");
		pNewSysNetGatherTask->dumpDiff(m_output,pSysNetGatherTask);
#endif
		fflush(m_output);
	}
}
	
void CSysNetGatherTaskDumpTrigger::beforeRemove(CSysNetGatherTask *pSysNetGatherTask)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetGatherTask,del");
		pSysNetGatherTask->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetGatherTask\n");
		pSysNetGatherTask->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetDeviceCategoryDumpTrigger::CSysNetDeviceCategoryDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetDeviceCategoryDumpTrigger::~CSysNetDeviceCategoryDumpTrigger(void)
{
}


void CSysNetDeviceCategoryDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetDeviceCategoryDumpTrigger");
	pLogger->output(indent,0,"CSysNetDeviceCategoryDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetDeviceCategoryDumpTrigger::beforeAdd(CWriteableSysNetDeviceCategory *pSysNetDeviceCategory)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDeviceCategory,add");
		pSysNetDeviceCategory->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetDeviceCategory\n");
		pSysNetDeviceCategory->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetDeviceCategoryDumpTrigger::beforeUpdate(CSysNetDeviceCategory *pSysNetDeviceCategory, CWriteableSysNetDeviceCategory *pNewSysNetDeviceCategory)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDeviceCategory,upd");
		pNewSysNetDeviceCategory->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetDeviceCategory\n");
		pNewSysNetDeviceCategory->dumpDiff(m_output,pSysNetDeviceCategory);
#endif
		fflush(m_output);
	}
}
	
void CSysNetDeviceCategoryDumpTrigger::beforeRemove(CSysNetDeviceCategory *pSysNetDeviceCategory)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDeviceCategory,del");
		pSysNetDeviceCategory->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetDeviceCategory\n");
		pSysNetDeviceCategory->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetManufactoryDumpTrigger::CSysNetManufactoryDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetManufactoryDumpTrigger::~CSysNetManufactoryDumpTrigger(void)
{
}


void CSysNetManufactoryDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetManufactoryDumpTrigger");
	pLogger->output(indent,0,"CSysNetManufactoryDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetManufactoryDumpTrigger::beforeAdd(CWriteableSysNetManufactory *pSysNetManufactory)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetManufactory,add");
		pSysNetManufactory->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetManufactory\n");
		pSysNetManufactory->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetManufactoryDumpTrigger::beforeUpdate(CSysNetManufactory *pSysNetManufactory, CWriteableSysNetManufactory *pNewSysNetManufactory)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetManufactory,upd");
		pNewSysNetManufactory->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetManufactory\n");
		pNewSysNetManufactory->dumpDiff(m_output,pSysNetManufactory);
#endif
		fflush(m_output);
	}
}
	
void CSysNetManufactoryDumpTrigger::beforeRemove(CSysNetManufactory *pSysNetManufactory)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetManufactory,del");
		pSysNetManufactory->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetManufactory\n");
		pSysNetManufactory->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetCommunityDumpTrigger::CSysNetCommunityDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetCommunityDumpTrigger::~CSysNetCommunityDumpTrigger(void)
{
}


void CSysNetCommunityDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetCommunityDumpTrigger");
	pLogger->output(indent,0,"CSysNetCommunityDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetCommunityDumpTrigger::beforeAdd(CWriteableSysNetCommunity *pSysNetCommunity)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetCommunity,add");
		pSysNetCommunity->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetCommunity\n");
		pSysNetCommunity->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetCommunityDumpTrigger::beforeUpdate(CSysNetCommunity *pSysNetCommunity, CWriteableSysNetCommunity *pNewSysNetCommunity)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetCommunity,upd");
		pNewSysNetCommunity->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetCommunity\n");
		pNewSysNetCommunity->dumpDiff(m_output,pSysNetCommunity);
#endif
		fflush(m_output);
	}
}
	
void CSysNetCommunityDumpTrigger::beforeRemove(CSysNetCommunity *pSysNetCommunity)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetCommunity,del");
		pSysNetCommunity->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetCommunity\n");
		pSysNetCommunity->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetPortTypeDumpTrigger::CSysNetPortTypeDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetPortTypeDumpTrigger::~CSysNetPortTypeDumpTrigger(void)
{
}


void CSysNetPortTypeDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetPortTypeDumpTrigger");
	pLogger->output(indent,0,"CSysNetPortTypeDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetPortTypeDumpTrigger::beforeAdd(CWriteableSysNetPortType *pSysNetPortType)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetPortType,add");
		pSysNetPortType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetPortType\n");
		pSysNetPortType->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetPortTypeDumpTrigger::beforeUpdate(CSysNetPortType *pSysNetPortType, CWriteableSysNetPortType *pNewSysNetPortType)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetPortType,upd");
		pNewSysNetPortType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetPortType\n");
		pNewSysNetPortType->dumpDiff(m_output,pSysNetPortType);
#endif
		fflush(m_output);
	}
}
	
void CSysNetPortTypeDumpTrigger::beforeRemove(CSysNetPortType *pSysNetPortType)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetPortType,del");
		pSysNetPortType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetPortType\n");
		pSysNetPortType->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetInterfaceDumpTrigger::CSysNetInterfaceDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetInterfaceDumpTrigger::~CSysNetInterfaceDumpTrigger(void)
{
}


void CSysNetInterfaceDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetInterfaceDumpTrigger");
	pLogger->output(indent,0,"CSysNetInterfaceDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetInterfaceDumpTrigger::beforeAdd(CWriteableSysNetInterface *pSysNetInterface)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetInterface,add");
		pSysNetInterface->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetInterface\n");
		pSysNetInterface->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetInterfaceDumpTrigger::beforeUpdate(CSysNetInterface *pSysNetInterface, CWriteableSysNetInterface *pNewSysNetInterface)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetInterface,upd");
		pNewSysNetInterface->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetInterface\n");
		pNewSysNetInterface->dumpDiff(m_output,pSysNetInterface);
#endif
		fflush(m_output);
	}
}
	
void CSysNetInterfaceDumpTrigger::beforeRemove(CSysNetInterface *pSysNetInterface)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetInterface,del");
		pSysNetInterface->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetInterface\n");
		pSysNetInterface->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetGeneralOIDDumpTrigger::CSysNetGeneralOIDDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetGeneralOIDDumpTrigger::~CSysNetGeneralOIDDumpTrigger(void)
{
}


void CSysNetGeneralOIDDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetGeneralOIDDumpTrigger");
	pLogger->output(indent,0,"CSysNetGeneralOIDDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetGeneralOIDDumpTrigger::beforeAdd(CWriteableSysNetGeneralOID *pSysNetGeneralOID)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetGeneralOID,add");
		pSysNetGeneralOID->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetGeneralOID\n");
		pSysNetGeneralOID->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetGeneralOIDDumpTrigger::beforeUpdate(CSysNetGeneralOID *pSysNetGeneralOID, CWriteableSysNetGeneralOID *pNewSysNetGeneralOID)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetGeneralOID,upd");
		pNewSysNetGeneralOID->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetGeneralOID\n");
		pNewSysNetGeneralOID->dumpDiff(m_output,pSysNetGeneralOID);
#endif
		fflush(m_output);
	}
}
	
void CSysNetGeneralOIDDumpTrigger::beforeRemove(CSysNetGeneralOID *pSysNetGeneralOID)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetGeneralOID,del");
		pSysNetGeneralOID->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetGeneralOID\n");
		pSysNetGeneralOID->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetMonitorTypeDumpTrigger::CSysNetMonitorTypeDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetMonitorTypeDumpTrigger::~CSysNetMonitorTypeDumpTrigger(void)
{
}


void CSysNetMonitorTypeDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetMonitorTypeDumpTrigger");
	pLogger->output(indent,0,"CSysNetMonitorTypeDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetMonitorTypeDumpTrigger::beforeAdd(CWriteableSysNetMonitorType *pSysNetMonitorType)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorType,add");
		pSysNetMonitorType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetMonitorType\n");
		pSysNetMonitorType->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorTypeDumpTrigger::beforeUpdate(CSysNetMonitorType *pSysNetMonitorType, CWriteableSysNetMonitorType *pNewSysNetMonitorType)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorType,upd");
		pNewSysNetMonitorType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetMonitorType\n");
		pNewSysNetMonitorType->dumpDiff(m_output,pSysNetMonitorType);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorTypeDumpTrigger::beforeRemove(CSysNetMonitorType *pSysNetMonitorType)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorType,del");
		pSysNetMonitorType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetMonitorType\n");
		pSysNetMonitorType->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetMonitorAttrScopeDumpTrigger::CSysNetMonitorAttrScopeDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetMonitorAttrScopeDumpTrigger::~CSysNetMonitorAttrScopeDumpTrigger(void)
{
}


void CSysNetMonitorAttrScopeDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetMonitorAttrScopeDumpTrigger");
	pLogger->output(indent,0,"CSysNetMonitorAttrScopeDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetMonitorAttrScopeDumpTrigger::beforeAdd(CWriteableSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorAttrScope,add");
		pSysNetMonitorAttrScope->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetMonitorAttrScope\n");
		pSysNetMonitorAttrScope->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorAttrScopeDumpTrigger::beforeUpdate(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope, CWriteableSysNetMonitorAttrScope *pNewSysNetMonitorAttrScope)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorAttrScope,upd");
		pNewSysNetMonitorAttrScope->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetMonitorAttrScope\n");
		pNewSysNetMonitorAttrScope->dumpDiff(m_output,pSysNetMonitorAttrScope);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorAttrScopeDumpTrigger::beforeRemove(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorAttrScope,del");
		pSysNetMonitorAttrScope->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetMonitorAttrScope\n");
		pSysNetMonitorAttrScope->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetMonitorAttrTypeDumpTrigger::CSysNetMonitorAttrTypeDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetMonitorAttrTypeDumpTrigger::~CSysNetMonitorAttrTypeDumpTrigger(void)
{
}


void CSysNetMonitorAttrTypeDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetMonitorAttrTypeDumpTrigger");
	pLogger->output(indent,0,"CSysNetMonitorAttrTypeDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetMonitorAttrTypeDumpTrigger::beforeAdd(CWriteableSysNetMonitorAttrType *pSysNetMonitorAttrType)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorAttrType,add");
		pSysNetMonitorAttrType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetMonitorAttrType\n");
		pSysNetMonitorAttrType->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorAttrTypeDumpTrigger::beforeUpdate(CSysNetMonitorAttrType *pSysNetMonitorAttrType, CWriteableSysNetMonitorAttrType *pNewSysNetMonitorAttrType)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorAttrType,upd");
		pNewSysNetMonitorAttrType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetMonitorAttrType\n");
		pNewSysNetMonitorAttrType->dumpDiff(m_output,pSysNetMonitorAttrType);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorAttrTypeDumpTrigger::beforeRemove(CSysNetMonitorAttrType *pSysNetMonitorAttrType)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorAttrType,del");
		pSysNetMonitorAttrType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetMonitorAttrType\n");
		pSysNetMonitorAttrType->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetMonitorCommandTypeDumpTrigger::CSysNetMonitorCommandTypeDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetMonitorCommandTypeDumpTrigger::~CSysNetMonitorCommandTypeDumpTrigger(void)
{
}


void CSysNetMonitorCommandTypeDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetMonitorCommandTypeDumpTrigger");
	pLogger->output(indent,0,"CSysNetMonitorCommandTypeDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetMonitorCommandTypeDumpTrigger::beforeAdd(CWriteableSysNetMonitorCommandType *pSysNetMonitorCommandType)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorCommandType,add");
		pSysNetMonitorCommandType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetMonitorCommandType\n");
		pSysNetMonitorCommandType->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorCommandTypeDumpTrigger::beforeUpdate(CSysNetMonitorCommandType *pSysNetMonitorCommandType, CWriteableSysNetMonitorCommandType *pNewSysNetMonitorCommandType)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorCommandType,upd");
		pNewSysNetMonitorCommandType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetMonitorCommandType\n");
		pNewSysNetMonitorCommandType->dumpDiff(m_output,pSysNetMonitorCommandType);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorCommandTypeDumpTrigger::beforeRemove(CSysNetMonitorCommandType *pSysNetMonitorCommandType)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorCommandType,del");
		pSysNetMonitorCommandType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetMonitorCommandType\n");
		pSysNetMonitorCommandType->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetMonitorActionGroupDumpTrigger::CSysNetMonitorActionGroupDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetMonitorActionGroupDumpTrigger::~CSysNetMonitorActionGroupDumpTrigger(void)
{
}


void CSysNetMonitorActionGroupDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetMonitorActionGroupDumpTrigger");
	pLogger->output(indent,0,"CSysNetMonitorActionGroupDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetMonitorActionGroupDumpTrigger::beforeAdd(CWriteableSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorActionGroup,add");
		pSysNetMonitorActionGroup->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetMonitorActionGroup\n");
		pSysNetMonitorActionGroup->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorActionGroupDumpTrigger::beforeUpdate(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup, CWriteableSysNetMonitorActionGroup *pNewSysNetMonitorActionGroup)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorActionGroup,upd");
		pNewSysNetMonitorActionGroup->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetMonitorActionGroup\n");
		pNewSysNetMonitorActionGroup->dumpDiff(m_output,pSysNetMonitorActionGroup);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorActionGroupDumpTrigger::beforeRemove(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorActionGroup,del");
		pSysNetMonitorActionGroup->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetMonitorActionGroup\n");
		pSysNetMonitorActionGroup->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetMonitorDeviceGroupDumpTrigger::CSysNetMonitorDeviceGroupDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetMonitorDeviceGroupDumpTrigger::~CSysNetMonitorDeviceGroupDumpTrigger(void)
{
}


void CSysNetMonitorDeviceGroupDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetMonitorDeviceGroupDumpTrigger");
	pLogger->output(indent,0,"CSysNetMonitorDeviceGroupDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetMonitorDeviceGroupDumpTrigger::beforeAdd(CWriteableSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorDeviceGroup,add");
		pSysNetMonitorDeviceGroup->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetMonitorDeviceGroup\n");
		pSysNetMonitorDeviceGroup->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorDeviceGroupDumpTrigger::beforeUpdate(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, CWriteableSysNetMonitorDeviceGroup *pNewSysNetMonitorDeviceGroup)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorDeviceGroup,upd");
		pNewSysNetMonitorDeviceGroup->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetMonitorDeviceGroup\n");
		pNewSysNetMonitorDeviceGroup->dumpDiff(m_output,pSysNetMonitorDeviceGroup);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorDeviceGroupDumpTrigger::beforeRemove(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorDeviceGroup,del");
		pSysNetMonitorDeviceGroup->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetMonitorDeviceGroup\n");
		pSysNetMonitorDeviceGroup->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetMonitorTaskInfoDumpTrigger::CSysNetMonitorTaskInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetMonitorTaskInfoDumpTrigger::~CSysNetMonitorTaskInfoDumpTrigger(void)
{
}


void CSysNetMonitorTaskInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetMonitorTaskInfoDumpTrigger");
	pLogger->output(indent,0,"CSysNetMonitorTaskInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetMonitorTaskInfoDumpTrigger::beforeAdd(CWriteableSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorTaskInfo,add");
		pSysNetMonitorTaskInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetMonitorTaskInfo\n");
		pSysNetMonitorTaskInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorTaskInfoDumpTrigger::beforeUpdate(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, CWriteableSysNetMonitorTaskInfo *pNewSysNetMonitorTaskInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorTaskInfo,upd");
		pNewSysNetMonitorTaskInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetMonitorTaskInfo\n");
		pNewSysNetMonitorTaskInfo->dumpDiff(m_output,pSysNetMonitorTaskInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorTaskInfoDumpTrigger::beforeRemove(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorTaskInfo,del");
		pSysNetMonitorTaskInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetMonitorTaskInfo\n");
		pSysNetMonitorTaskInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetMonitorTaskObjectSetDumpTrigger::CSysNetMonitorTaskObjectSetDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetMonitorTaskObjectSetDumpTrigger::~CSysNetMonitorTaskObjectSetDumpTrigger(void)
{
}


void CSysNetMonitorTaskObjectSetDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetMonitorTaskObjectSetDumpTrigger");
	pLogger->output(indent,0,"CSysNetMonitorTaskObjectSetDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetMonitorTaskObjectSetDumpTrigger::beforeAdd(CWriteableSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorTaskObjectSet,add");
		pSysNetMonitorTaskObjectSet->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetMonitorTaskObjectSet\n");
		pSysNetMonitorTaskObjectSet->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorTaskObjectSetDumpTrigger::beforeUpdate(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, CWriteableSysNetMonitorTaskObjectSet *pNewSysNetMonitorTaskObjectSet)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorTaskObjectSet,upd");
		pNewSysNetMonitorTaskObjectSet->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetMonitorTaskObjectSet\n");
		pNewSysNetMonitorTaskObjectSet->dumpDiff(m_output,pSysNetMonitorTaskObjectSet);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorTaskObjectSetDumpTrigger::beforeRemove(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorTaskObjectSet,del");
		pSysNetMonitorTaskObjectSet->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetMonitorTaskObjectSet\n");
		pSysNetMonitorTaskObjectSet->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetMonitorTaskResultDumpTrigger::CSysNetMonitorTaskResultDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetMonitorTaskResultDumpTrigger::~CSysNetMonitorTaskResultDumpTrigger(void)
{
}


void CSysNetMonitorTaskResultDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetMonitorTaskResultDumpTrigger");
	pLogger->output(indent,0,"CSysNetMonitorTaskResultDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetMonitorTaskResultDumpTrigger::beforeAdd(CWriteableSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorTaskResult,add");
		pSysNetMonitorTaskResult->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetMonitorTaskResult\n");
		pSysNetMonitorTaskResult->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorTaskResultDumpTrigger::beforeUpdate(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult, CWriteableSysNetMonitorTaskResult *pNewSysNetMonitorTaskResult)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorTaskResult,upd");
		pNewSysNetMonitorTaskResult->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetMonitorTaskResult\n");
		pNewSysNetMonitorTaskResult->dumpDiff(m_output,pSysNetMonitorTaskResult);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorTaskResultDumpTrigger::beforeRemove(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorTaskResult,del");
		pSysNetMonitorTaskResult->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetMonitorTaskResult\n");
		pSysNetMonitorTaskResult->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetPartyLinkInfoDumpTrigger::CSysNetPartyLinkInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetPartyLinkInfoDumpTrigger::~CSysNetPartyLinkInfoDumpTrigger(void)
{
}


void CSysNetPartyLinkInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetPartyLinkInfoDumpTrigger");
	pLogger->output(indent,0,"CSysNetPartyLinkInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetPartyLinkInfoDumpTrigger::beforeAdd(CWriteableSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetPartyLinkInfo,add");
		pSysNetPartyLinkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetPartyLinkInfo\n");
		pSysNetPartyLinkInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetPartyLinkInfoDumpTrigger::beforeUpdate(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo, CWriteableSysNetPartyLinkInfo *pNewSysNetPartyLinkInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetPartyLinkInfo,upd");
		pNewSysNetPartyLinkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetPartyLinkInfo\n");
		pNewSysNetPartyLinkInfo->dumpDiff(m_output,pSysNetPartyLinkInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysNetPartyLinkInfoDumpTrigger::beforeRemove(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetPartyLinkInfo,del");
		pSysNetPartyLinkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetPartyLinkInfo\n");
		pSysNetPartyLinkInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetDelPartyLinkInfoDumpTrigger::CSysNetDelPartyLinkInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetDelPartyLinkInfoDumpTrigger::~CSysNetDelPartyLinkInfoDumpTrigger(void)
{
}


void CSysNetDelPartyLinkInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetDelPartyLinkInfoDumpTrigger");
	pLogger->output(indent,0,"CSysNetDelPartyLinkInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetDelPartyLinkInfoDumpTrigger::beforeAdd(CWriteableSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDelPartyLinkInfo,add");
		pSysNetDelPartyLinkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetDelPartyLinkInfo\n");
		pSysNetDelPartyLinkInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetDelPartyLinkInfoDumpTrigger::beforeUpdate(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, CWriteableSysNetDelPartyLinkInfo *pNewSysNetDelPartyLinkInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDelPartyLinkInfo,upd");
		pNewSysNetDelPartyLinkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetDelPartyLinkInfo\n");
		pNewSysNetDelPartyLinkInfo->dumpDiff(m_output,pSysNetDelPartyLinkInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysNetDelPartyLinkInfoDumpTrigger::beforeRemove(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDelPartyLinkInfo,del");
		pSysNetDelPartyLinkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetDelPartyLinkInfo\n");
		pSysNetDelPartyLinkInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetPartyLinkAddrChangeDumpTrigger::CSysNetPartyLinkAddrChangeDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetPartyLinkAddrChangeDumpTrigger::~CSysNetPartyLinkAddrChangeDumpTrigger(void)
{
}


void CSysNetPartyLinkAddrChangeDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetPartyLinkAddrChangeDumpTrigger");
	pLogger->output(indent,0,"CSysNetPartyLinkAddrChangeDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetPartyLinkAddrChangeDumpTrigger::beforeAdd(CWriteableSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetPartyLinkAddrChange,add");
		pSysNetPartyLinkAddrChange->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetPartyLinkAddrChange\n");
		pSysNetPartyLinkAddrChange->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetPartyLinkAddrChangeDumpTrigger::beforeUpdate(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, CWriteableSysNetPartyLinkAddrChange *pNewSysNetPartyLinkAddrChange)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetPartyLinkAddrChange,upd");
		pNewSysNetPartyLinkAddrChange->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetPartyLinkAddrChange\n");
		pNewSysNetPartyLinkAddrChange->dumpDiff(m_output,pSysNetPartyLinkAddrChange);
#endif
		fflush(m_output);
	}
}
	
void CSysNetPartyLinkAddrChangeDumpTrigger::beforeRemove(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetPartyLinkAddrChange,del");
		pSysNetPartyLinkAddrChange->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetPartyLinkAddrChange\n");
		pSysNetPartyLinkAddrChange->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetMonitorActionAttrDumpTrigger::CSysNetMonitorActionAttrDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetMonitorActionAttrDumpTrigger::~CSysNetMonitorActionAttrDumpTrigger(void)
{
}


void CSysNetMonitorActionAttrDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetMonitorActionAttrDumpTrigger");
	pLogger->output(indent,0,"CSysNetMonitorActionAttrDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetMonitorActionAttrDumpTrigger::beforeAdd(CWriteableSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorActionAttr,add");
		pSysNetMonitorActionAttr->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetMonitorActionAttr\n");
		pSysNetMonitorActionAttr->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorActionAttrDumpTrigger::beforeUpdate(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr, CWriteableSysNetMonitorActionAttr *pNewSysNetMonitorActionAttr)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorActionAttr,upd");
		pNewSysNetMonitorActionAttr->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetMonitorActionAttr\n");
		pNewSysNetMonitorActionAttr->dumpDiff(m_output,pSysNetMonitorActionAttr);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorActionAttrDumpTrigger::beforeRemove(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorActionAttr,del");
		pSysNetMonitorActionAttr->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetMonitorActionAttr\n");
		pSysNetMonitorActionAttr->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetModuleDumpTrigger::CSysNetModuleDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetModuleDumpTrigger::~CSysNetModuleDumpTrigger(void)
{
}


void CSysNetModuleDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetModuleDumpTrigger");
	pLogger->output(indent,0,"CSysNetModuleDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetModuleDumpTrigger::beforeAdd(CWriteableSysNetModule *pSysNetModule)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetModule,add");
		pSysNetModule->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetModule\n");
		pSysNetModule->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetModuleDumpTrigger::beforeUpdate(CSysNetModule *pSysNetModule, CWriteableSysNetModule *pNewSysNetModule)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetModule,upd");
		pNewSysNetModule->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetModule\n");
		pNewSysNetModule->dumpDiff(m_output,pSysNetModule);
#endif
		fflush(m_output);
	}
}
	
void CSysNetModuleDumpTrigger::beforeRemove(CSysNetModule *pSysNetModule)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetModule,del");
		pSysNetModule->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetModule\n");
		pSysNetModule->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetEventExprDumpTrigger::CSysNetEventExprDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetEventExprDumpTrigger::~CSysNetEventExprDumpTrigger(void)
{
}


void CSysNetEventExprDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetEventExprDumpTrigger");
	pLogger->output(indent,0,"CSysNetEventExprDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetEventExprDumpTrigger::beforeAdd(CWriteableSysNetEventExpr *pSysNetEventExpr)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetEventExpr,add");
		pSysNetEventExpr->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetEventExpr\n");
		pSysNetEventExpr->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetEventExprDumpTrigger::beforeUpdate(CSysNetEventExpr *pSysNetEventExpr, CWriteableSysNetEventExpr *pNewSysNetEventExpr)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetEventExpr,upd");
		pNewSysNetEventExpr->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetEventExpr\n");
		pNewSysNetEventExpr->dumpDiff(m_output,pSysNetEventExpr);
#endif
		fflush(m_output);
	}
}
	
void CSysNetEventExprDumpTrigger::beforeRemove(CSysNetEventExpr *pSysNetEventExpr)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetEventExpr,del");
		pSysNetEventExpr->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetEventExpr\n");
		pSysNetEventExpr->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetEventTypeDumpTrigger::CSysNetEventTypeDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetEventTypeDumpTrigger::~CSysNetEventTypeDumpTrigger(void)
{
}


void CSysNetEventTypeDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetEventTypeDumpTrigger");
	pLogger->output(indent,0,"CSysNetEventTypeDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetEventTypeDumpTrigger::beforeAdd(CWriteableSysNetEventType *pSysNetEventType)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetEventType,add");
		pSysNetEventType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetEventType\n");
		pSysNetEventType->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetEventTypeDumpTrigger::beforeUpdate(CSysNetEventType *pSysNetEventType, CWriteableSysNetEventType *pNewSysNetEventType)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetEventType,upd");
		pNewSysNetEventType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetEventType\n");
		pNewSysNetEventType->dumpDiff(m_output,pSysNetEventType);
#endif
		fflush(m_output);
	}
}
	
void CSysNetEventTypeDumpTrigger::beforeRemove(CSysNetEventType *pSysNetEventType)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetEventType,del");
		pSysNetEventType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetEventType\n");
		pSysNetEventType->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetSubEventTypeDumpTrigger::CSysNetSubEventTypeDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetSubEventTypeDumpTrigger::~CSysNetSubEventTypeDumpTrigger(void)
{
}


void CSysNetSubEventTypeDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetSubEventTypeDumpTrigger");
	pLogger->output(indent,0,"CSysNetSubEventTypeDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetSubEventTypeDumpTrigger::beforeAdd(CWriteableSysNetSubEventType *pSysNetSubEventType)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetSubEventType,add");
		pSysNetSubEventType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetSubEventType\n");
		pSysNetSubEventType->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetSubEventTypeDumpTrigger::beforeUpdate(CSysNetSubEventType *pSysNetSubEventType, CWriteableSysNetSubEventType *pNewSysNetSubEventType)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetSubEventType,upd");
		pNewSysNetSubEventType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetSubEventType\n");
		pNewSysNetSubEventType->dumpDiff(m_output,pSysNetSubEventType);
#endif
		fflush(m_output);
	}
}
	
void CSysNetSubEventTypeDumpTrigger::beforeRemove(CSysNetSubEventType *pSysNetSubEventType)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetSubEventType,del");
		pSysNetSubEventType->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetSubEventType\n");
		pSysNetSubEventType->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetEventLevelDumpTrigger::CSysNetEventLevelDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetEventLevelDumpTrigger::~CSysNetEventLevelDumpTrigger(void)
{
}


void CSysNetEventLevelDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetEventLevelDumpTrigger");
	pLogger->output(indent,0,"CSysNetEventLevelDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetEventLevelDumpTrigger::beforeAdd(CWriteableSysNetEventLevel *pSysNetEventLevel)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetEventLevel,add");
		pSysNetEventLevel->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetEventLevel\n");
		pSysNetEventLevel->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetEventLevelDumpTrigger::beforeUpdate(CSysNetEventLevel *pSysNetEventLevel, CWriteableSysNetEventLevel *pNewSysNetEventLevel)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetEventLevel,upd");
		pNewSysNetEventLevel->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetEventLevel\n");
		pNewSysNetEventLevel->dumpDiff(m_output,pSysNetEventLevel);
#endif
		fflush(m_output);
	}
}
	
void CSysNetEventLevelDumpTrigger::beforeRemove(CSysNetEventLevel *pSysNetEventLevel)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetEventLevel,del");
		pSysNetEventLevel->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetEventLevel\n");
		pSysNetEventLevel->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetMonitorDeviceTaskDumpTrigger::CSysNetMonitorDeviceTaskDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetMonitorDeviceTaskDumpTrigger::~CSysNetMonitorDeviceTaskDumpTrigger(void)
{
}


void CSysNetMonitorDeviceTaskDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetMonitorDeviceTaskDumpTrigger");
	pLogger->output(indent,0,"CSysNetMonitorDeviceTaskDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetMonitorDeviceTaskDumpTrigger::beforeAdd(CWriteableSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorDeviceTask,add");
		pSysNetMonitorDeviceTask->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetMonitorDeviceTask\n");
		pSysNetMonitorDeviceTask->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorDeviceTaskDumpTrigger::beforeUpdate(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, CWriteableSysNetMonitorDeviceTask *pNewSysNetMonitorDeviceTask)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorDeviceTask,upd");
		pNewSysNetMonitorDeviceTask->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetMonitorDeviceTask\n");
		pNewSysNetMonitorDeviceTask->dumpDiff(m_output,pSysNetMonitorDeviceTask);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorDeviceTaskDumpTrigger::beforeRemove(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorDeviceTask,del");
		pSysNetMonitorDeviceTask->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetMonitorDeviceTask\n");
		pSysNetMonitorDeviceTask->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetMonitorTaskInstAttrsDumpTrigger::CSysNetMonitorTaskInstAttrsDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetMonitorTaskInstAttrsDumpTrigger::~CSysNetMonitorTaskInstAttrsDumpTrigger(void)
{
}


void CSysNetMonitorTaskInstAttrsDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetMonitorTaskInstAttrsDumpTrigger");
	pLogger->output(indent,0,"CSysNetMonitorTaskInstAttrsDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetMonitorTaskInstAttrsDumpTrigger::beforeAdd(CWriteableSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorTaskInstAttrs,add");
		pSysNetMonitorTaskInstAttrs->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetMonitorTaskInstAttrs\n");
		pSysNetMonitorTaskInstAttrs->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorTaskInstAttrsDumpTrigger::beforeUpdate(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, CWriteableSysNetMonitorTaskInstAttrs *pNewSysNetMonitorTaskInstAttrs)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorTaskInstAttrs,upd");
		pNewSysNetMonitorTaskInstAttrs->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetMonitorTaskInstAttrs\n");
		pNewSysNetMonitorTaskInstAttrs->dumpDiff(m_output,pSysNetMonitorTaskInstAttrs);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMonitorTaskInstAttrsDumpTrigger::beforeRemove(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMonitorTaskInstAttrs,del");
		pSysNetMonitorTaskInstAttrs->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetMonitorTaskInstAttrs\n");
		pSysNetMonitorTaskInstAttrs->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetBaseLineDumpTrigger::CSysNetBaseLineDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetBaseLineDumpTrigger::~CSysNetBaseLineDumpTrigger(void)
{
}


void CSysNetBaseLineDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetBaseLineDumpTrigger");
	pLogger->output(indent,0,"CSysNetBaseLineDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetBaseLineDumpTrigger::beforeAdd(CWriteableSysNetBaseLine *pSysNetBaseLine)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetBaseLine,add");
		pSysNetBaseLine->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetBaseLine\n");
		pSysNetBaseLine->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetBaseLineDumpTrigger::beforeUpdate(CSysNetBaseLine *pSysNetBaseLine, CWriteableSysNetBaseLine *pNewSysNetBaseLine)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetBaseLine,upd");
		pNewSysNetBaseLine->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetBaseLine\n");
		pNewSysNetBaseLine->dumpDiff(m_output,pSysNetBaseLine);
#endif
		fflush(m_output);
	}
}
	
void CSysNetBaseLineDumpTrigger::beforeRemove(CSysNetBaseLine *pSysNetBaseLine)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetBaseLine,del");
		pSysNetBaseLine->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetBaseLine\n");
		pSysNetBaseLine->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetBaseLineTaskDumpTrigger::CSysNetBaseLineTaskDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetBaseLineTaskDumpTrigger::~CSysNetBaseLineTaskDumpTrigger(void)
{
}


void CSysNetBaseLineTaskDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetBaseLineTaskDumpTrigger");
	pLogger->output(indent,0,"CSysNetBaseLineTaskDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetBaseLineTaskDumpTrigger::beforeAdd(CWriteableSysNetBaseLineTask *pSysNetBaseLineTask)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetBaseLineTask,add");
		pSysNetBaseLineTask->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetBaseLineTask\n");
		pSysNetBaseLineTask->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetBaseLineTaskDumpTrigger::beforeUpdate(CSysNetBaseLineTask *pSysNetBaseLineTask, CWriteableSysNetBaseLineTask *pNewSysNetBaseLineTask)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetBaseLineTask,upd");
		pNewSysNetBaseLineTask->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetBaseLineTask\n");
		pNewSysNetBaseLineTask->dumpDiff(m_output,pSysNetBaseLineTask);
#endif
		fflush(m_output);
	}
}
	
void CSysNetBaseLineTaskDumpTrigger::beforeRemove(CSysNetBaseLineTask *pSysNetBaseLineTask)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetBaseLineTask,del");
		pSysNetBaseLineTask->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetBaseLineTask\n");
		pSysNetBaseLineTask->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMdbNetPartyLinkStatusInfoDumpTrigger::CSysMdbNetPartyLinkStatusInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMdbNetPartyLinkStatusInfoDumpTrigger::~CSysMdbNetPartyLinkStatusInfoDumpTrigger(void)
{
}


void CSysMdbNetPartyLinkStatusInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMdbNetPartyLinkStatusInfoDumpTrigger");
	pLogger->output(indent,0,"CSysMdbNetPartyLinkStatusInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMdbNetPartyLinkStatusInfoDumpTrigger::beforeAdd(CWriteableSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbNetPartyLinkStatusInfo,add");
		pSysMdbNetPartyLinkStatusInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMdbNetPartyLinkStatusInfo\n");
		pSysMdbNetPartyLinkStatusInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbNetPartyLinkStatusInfoDumpTrigger::beforeUpdate(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, CWriteableSysMdbNetPartyLinkStatusInfo *pNewSysMdbNetPartyLinkStatusInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbNetPartyLinkStatusInfo,upd");
		pNewSysMdbNetPartyLinkStatusInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMdbNetPartyLinkStatusInfo\n");
		pNewSysMdbNetPartyLinkStatusInfo->dumpDiff(m_output,pSysMdbNetPartyLinkStatusInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbNetPartyLinkStatusInfoDumpTrigger::beforeRemove(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbNetPartyLinkStatusInfo,del");
		pSysMdbNetPartyLinkStatusInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMdbNetPartyLinkStatusInfo\n");
		pSysMdbNetPartyLinkStatusInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetMemberSDHLineInfoDumpTrigger::CSysNetMemberSDHLineInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetMemberSDHLineInfoDumpTrigger::~CSysNetMemberSDHLineInfoDumpTrigger(void)
{
}


void CSysNetMemberSDHLineInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetMemberSDHLineInfoDumpTrigger");
	pLogger->output(indent,0,"CSysNetMemberSDHLineInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetMemberSDHLineInfoDumpTrigger::beforeAdd(CWriteableSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMemberSDHLineInfo,add");
		pSysNetMemberSDHLineInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetMemberSDHLineInfo\n");
		pSysNetMemberSDHLineInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMemberSDHLineInfoDumpTrigger::beforeUpdate(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, CWriteableSysNetMemberSDHLineInfo *pNewSysNetMemberSDHLineInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMemberSDHLineInfo,upd");
		pNewSysNetMemberSDHLineInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetMemberSDHLineInfo\n");
		pNewSysNetMemberSDHLineInfo->dumpDiff(m_output,pSysNetMemberSDHLineInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysNetMemberSDHLineInfoDumpTrigger::beforeRemove(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetMemberSDHLineInfo,del");
		pSysNetMemberSDHLineInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetMemberSDHLineInfo\n");
		pSysNetMemberSDHLineInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetDDNLinkInfoDumpTrigger::CSysNetDDNLinkInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetDDNLinkInfoDumpTrigger::~CSysNetDDNLinkInfoDumpTrigger(void)
{
}


void CSysNetDDNLinkInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetDDNLinkInfoDumpTrigger");
	pLogger->output(indent,0,"CSysNetDDNLinkInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetDDNLinkInfoDumpTrigger::beforeAdd(CWriteableSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDDNLinkInfo,add");
		pSysNetDDNLinkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetDDNLinkInfo\n");
		pSysNetDDNLinkInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetDDNLinkInfoDumpTrigger::beforeUpdate(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo, CWriteableSysNetDDNLinkInfo *pNewSysNetDDNLinkInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDDNLinkInfo,upd");
		pNewSysNetDDNLinkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetDDNLinkInfo\n");
		pNewSysNetDDNLinkInfo->dumpDiff(m_output,pSysNetDDNLinkInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysNetDDNLinkInfoDumpTrigger::beforeRemove(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetDDNLinkInfo,del");
		pSysNetDDNLinkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetDDNLinkInfo\n");
		pSysNetDDNLinkInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetPseudMemberLinkInfoDumpTrigger::CSysNetPseudMemberLinkInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetPseudMemberLinkInfoDumpTrigger::~CSysNetPseudMemberLinkInfoDumpTrigger(void)
{
}


void CSysNetPseudMemberLinkInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetPseudMemberLinkInfoDumpTrigger");
	pLogger->output(indent,0,"CSysNetPseudMemberLinkInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetPseudMemberLinkInfoDumpTrigger::beforeAdd(CWriteableSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetPseudMemberLinkInfo,add");
		pSysNetPseudMemberLinkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetPseudMemberLinkInfo\n");
		pSysNetPseudMemberLinkInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetPseudMemberLinkInfoDumpTrigger::beforeUpdate(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, CWriteableSysNetPseudMemberLinkInfo *pNewSysNetPseudMemberLinkInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetPseudMemberLinkInfo,upd");
		pNewSysNetPseudMemberLinkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetPseudMemberLinkInfo\n");
		pNewSysNetPseudMemberLinkInfo->dumpDiff(m_output,pSysNetPseudMemberLinkInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysNetPseudMemberLinkInfoDumpTrigger::beforeRemove(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetPseudMemberLinkInfo,del");
		pSysNetPseudMemberLinkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetPseudMemberLinkInfo\n");
		pSysNetPseudMemberLinkInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetOuterDeviceInfoDumpTrigger::CSysNetOuterDeviceInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetOuterDeviceInfoDumpTrigger::~CSysNetOuterDeviceInfoDumpTrigger(void)
{
}


void CSysNetOuterDeviceInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetOuterDeviceInfoDumpTrigger");
	pLogger->output(indent,0,"CSysNetOuterDeviceInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetOuterDeviceInfoDumpTrigger::beforeAdd(CWriteableSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetOuterDeviceInfo,add");
		pSysNetOuterDeviceInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetOuterDeviceInfo\n");
		pSysNetOuterDeviceInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetOuterDeviceInfoDumpTrigger::beforeUpdate(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, CWriteableSysNetOuterDeviceInfo *pNewSysNetOuterDeviceInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetOuterDeviceInfo,upd");
		pNewSysNetOuterDeviceInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetOuterDeviceInfo\n");
		pNewSysNetOuterDeviceInfo->dumpDiff(m_output,pSysNetOuterDeviceInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysNetOuterDeviceInfoDumpTrigger::beforeRemove(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetOuterDeviceInfo,del");
		pSysNetOuterDeviceInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetOuterDeviceInfo\n");
		pSysNetOuterDeviceInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysLocalPingResultInfoDumpTrigger::CSysLocalPingResultInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysLocalPingResultInfoDumpTrigger::~CSysLocalPingResultInfoDumpTrigger(void)
{
}


void CSysLocalPingResultInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysLocalPingResultInfoDumpTrigger");
	pLogger->output(indent,0,"CSysLocalPingResultInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysLocalPingResultInfoDumpTrigger::beforeAdd(CWriteableSysLocalPingResultInfo *pSysLocalPingResultInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysLocalPingResultInfo,add");
		pSysLocalPingResultInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysLocalPingResultInfo\n");
		pSysLocalPingResultInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysLocalPingResultInfoDumpTrigger::beforeUpdate(CSysLocalPingResultInfo *pSysLocalPingResultInfo, CWriteableSysLocalPingResultInfo *pNewSysLocalPingResultInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysLocalPingResultInfo,upd");
		pNewSysLocalPingResultInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysLocalPingResultInfo\n");
		pNewSysLocalPingResultInfo->dumpDiff(m_output,pSysLocalPingResultInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysLocalPingResultInfoDumpTrigger::beforeRemove(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysLocalPingResultInfo,del");
		pSysLocalPingResultInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysLocalPingResultInfo\n");
		pSysLocalPingResultInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysRomotePingResultInfoDumpTrigger::CSysRomotePingResultInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysRomotePingResultInfoDumpTrigger::~CSysRomotePingResultInfoDumpTrigger(void)
{
}


void CSysRomotePingResultInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysRomotePingResultInfoDumpTrigger");
	pLogger->output(indent,0,"CSysRomotePingResultInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysRomotePingResultInfoDumpTrigger::beforeAdd(CWriteableSysRomotePingResultInfo *pSysRomotePingResultInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysRomotePingResultInfo,add");
		pSysRomotePingResultInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysRomotePingResultInfo\n");
		pSysRomotePingResultInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysRomotePingResultInfoDumpTrigger::beforeUpdate(CSysRomotePingResultInfo *pSysRomotePingResultInfo, CWriteableSysRomotePingResultInfo *pNewSysRomotePingResultInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysRomotePingResultInfo,upd");
		pNewSysRomotePingResultInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysRomotePingResultInfo\n");
		pNewSysRomotePingResultInfo->dumpDiff(m_output,pSysRomotePingResultInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysRomotePingResultInfoDumpTrigger::beforeRemove(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysRomotePingResultInfo,del");
		pSysRomotePingResultInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysRomotePingResultInfo\n");
		pSysRomotePingResultInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysParticTradeOrderStatesDumpTrigger::CSysParticTradeOrderStatesDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysParticTradeOrderStatesDumpTrigger::~CSysParticTradeOrderStatesDumpTrigger(void)
{
}


void CSysParticTradeOrderStatesDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysParticTradeOrderStatesDumpTrigger");
	pLogger->output(indent,0,"CSysParticTradeOrderStatesDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysParticTradeOrderStatesDumpTrigger::beforeAdd(CWriteableSysParticTradeOrderStates *pSysParticTradeOrderStates)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysParticTradeOrderStates,add");
		pSysParticTradeOrderStates->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysParticTradeOrderStates\n");
		pSysParticTradeOrderStates->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysParticTradeOrderStatesDumpTrigger::beforeUpdate(CSysParticTradeOrderStates *pSysParticTradeOrderStates, CWriteableSysParticTradeOrderStates *pNewSysParticTradeOrderStates)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysParticTradeOrderStates,upd");
		pNewSysParticTradeOrderStates->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysParticTradeOrderStates\n");
		pNewSysParticTradeOrderStates->dumpDiff(m_output,pSysParticTradeOrderStates);
#endif
		fflush(m_output);
	}
}
	
void CSysParticTradeOrderStatesDumpTrigger::beforeRemove(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysParticTradeOrderStates,del");
		pSysParticTradeOrderStates->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysParticTradeOrderStates\n");
		pSysParticTradeOrderStates->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMdbRouterInfoDumpTrigger::CSysMdbRouterInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMdbRouterInfoDumpTrigger::~CSysMdbRouterInfoDumpTrigger(void)
{
}


void CSysMdbRouterInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMdbRouterInfoDumpTrigger");
	pLogger->output(indent,0,"CSysMdbRouterInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMdbRouterInfoDumpTrigger::beforeAdd(CWriteableSysMdbRouterInfo *pSysMdbRouterInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbRouterInfo,add");
		pSysMdbRouterInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMdbRouterInfo\n");
		pSysMdbRouterInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbRouterInfoDumpTrigger::beforeUpdate(CSysMdbRouterInfo *pSysMdbRouterInfo, CWriteableSysMdbRouterInfo *pNewSysMdbRouterInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbRouterInfo,upd");
		pNewSysMdbRouterInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMdbRouterInfo\n");
		pNewSysMdbRouterInfo->dumpDiff(m_output,pSysMdbRouterInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbRouterInfoDumpTrigger::beforeRemove(CSysMdbRouterInfo *pSysMdbRouterInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbRouterInfo,del");
		pSysMdbRouterInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMdbRouterInfo\n");
		pSysMdbRouterInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMdbDiskIODumpTrigger::CSysMdbDiskIODumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMdbDiskIODumpTrigger::~CSysMdbDiskIODumpTrigger(void)
{
}


void CSysMdbDiskIODumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMdbDiskIODumpTrigger");
	pLogger->output(indent,0,"CSysMdbDiskIODumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMdbDiskIODumpTrigger::beforeAdd(CWriteableSysMdbDiskIO *pSysMdbDiskIO)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbDiskIO,add");
		pSysMdbDiskIO->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMdbDiskIO\n");
		pSysMdbDiskIO->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbDiskIODumpTrigger::beforeUpdate(CSysMdbDiskIO *pSysMdbDiskIO, CWriteableSysMdbDiskIO *pNewSysMdbDiskIO)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbDiskIO,upd");
		pNewSysMdbDiskIO->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMdbDiskIO\n");
		pNewSysMdbDiskIO->dumpDiff(m_output,pSysMdbDiskIO);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbDiskIODumpTrigger::beforeRemove(CSysMdbDiskIO *pSysMdbDiskIO)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbDiskIO,del");
		pSysMdbDiskIO->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMdbDiskIO\n");
		pSysMdbDiskIO->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMdbStatInfoDumpTrigger::CSysMdbStatInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMdbStatInfoDumpTrigger::~CSysMdbStatInfoDumpTrigger(void)
{
}


void CSysMdbStatInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMdbStatInfoDumpTrigger");
	pLogger->output(indent,0,"CSysMdbStatInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMdbStatInfoDumpTrigger::beforeAdd(CWriteableSysMdbStatInfo *pSysMdbStatInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbStatInfo,add");
		pSysMdbStatInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMdbStatInfo\n");
		pSysMdbStatInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbStatInfoDumpTrigger::beforeUpdate(CSysMdbStatInfo *pSysMdbStatInfo, CWriteableSysMdbStatInfo *pNewSysMdbStatInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbStatInfo,upd");
		pNewSysMdbStatInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMdbStatInfo\n");
		pNewSysMdbStatInfo->dumpDiff(m_output,pSysMdbStatInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbStatInfoDumpTrigger::beforeRemove(CSysMdbStatInfo *pSysMdbStatInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbStatInfo,del");
		pSysMdbStatInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMdbStatInfo\n");
		pSysMdbStatInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMdbTradeFrontOrderRttStatDumpTrigger::CSysMdbTradeFrontOrderRttStatDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMdbTradeFrontOrderRttStatDumpTrigger::~CSysMdbTradeFrontOrderRttStatDumpTrigger(void)
{
}


void CSysMdbTradeFrontOrderRttStatDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMdbTradeFrontOrderRttStatDumpTrigger");
	pLogger->output(indent,0,"CSysMdbTradeFrontOrderRttStatDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMdbTradeFrontOrderRttStatDumpTrigger::beforeAdd(CWriteableSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbTradeFrontOrderRttStat,add");
		pSysMdbTradeFrontOrderRttStat->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMdbTradeFrontOrderRttStat\n");
		pSysMdbTradeFrontOrderRttStat->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbTradeFrontOrderRttStatDumpTrigger::beforeUpdate(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, CWriteableSysMdbTradeFrontOrderRttStat *pNewSysMdbTradeFrontOrderRttStat)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbTradeFrontOrderRttStat,upd");
		pNewSysMdbTradeFrontOrderRttStat->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMdbTradeFrontOrderRttStat\n");
		pNewSysMdbTradeFrontOrderRttStat->dumpDiff(m_output,pSysMdbTradeFrontOrderRttStat);
#endif
		fflush(m_output);
	}
}
	
void CSysMdbTradeFrontOrderRttStatDumpTrigger::beforeRemove(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMdbTradeFrontOrderRttStat,del");
		pSysMdbTradeFrontOrderRttStat->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMdbTradeFrontOrderRttStat\n");
		pSysMdbTradeFrontOrderRttStat->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysInstrumentStatusDumpTrigger::CSysInstrumentStatusDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysInstrumentStatusDumpTrigger::~CSysInstrumentStatusDumpTrigger(void)
{
}


void CSysInstrumentStatusDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysInstrumentStatusDumpTrigger");
	pLogger->output(indent,0,"CSysInstrumentStatusDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysInstrumentStatusDumpTrigger::beforeAdd(CWriteableSysInstrumentStatus *pSysInstrumentStatus)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysInstrumentStatus,add");
		pSysInstrumentStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysInstrumentStatus\n");
		pSysInstrumentStatus->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysInstrumentStatusDumpTrigger::beforeUpdate(CSysInstrumentStatus *pSysInstrumentStatus, CWriteableSysInstrumentStatus *pNewSysInstrumentStatus)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysInstrumentStatus,upd");
		pNewSysInstrumentStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysInstrumentStatus\n");
		pNewSysInstrumentStatus->dumpDiff(m_output,pSysInstrumentStatus);
#endif
		fflush(m_output);
	}
}
	
void CSysInstrumentStatusDumpTrigger::beforeRemove(CSysInstrumentStatus *pSysInstrumentStatus)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysInstrumentStatus,del");
		pSysInstrumentStatus->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysInstrumentStatus\n");
		pSysInstrumentStatus->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysCurrTradingSegmentAttrDumpTrigger::CSysCurrTradingSegmentAttrDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysCurrTradingSegmentAttrDumpTrigger::~CSysCurrTradingSegmentAttrDumpTrigger(void)
{
}


void CSysCurrTradingSegmentAttrDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysCurrTradingSegmentAttrDumpTrigger");
	pLogger->output(indent,0,"CSysCurrTradingSegmentAttrDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysCurrTradingSegmentAttrDumpTrigger::beforeAdd(CWriteableSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysCurrTradingSegmentAttr,add");
		pSysCurrTradingSegmentAttr->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysCurrTradingSegmentAttr\n");
		pSysCurrTradingSegmentAttr->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysCurrTradingSegmentAttrDumpTrigger::beforeUpdate(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, CWriteableSysCurrTradingSegmentAttr *pNewSysCurrTradingSegmentAttr)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysCurrTradingSegmentAttr,upd");
		pNewSysCurrTradingSegmentAttr->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysCurrTradingSegmentAttr\n");
		pNewSysCurrTradingSegmentAttr->dumpDiff(m_output,pSysCurrTradingSegmentAttr);
#endif
		fflush(m_output);
	}
}
	
void CSysCurrTradingSegmentAttrDumpTrigger::beforeRemove(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysCurrTradingSegmentAttr,del");
		pSysCurrTradingSegmentAttr->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysCurrTradingSegmentAttr\n");
		pSysCurrTradingSegmentAttr->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysMemberLinkCostDumpTrigger::CSysMemberLinkCostDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysMemberLinkCostDumpTrigger::~CSysMemberLinkCostDumpTrigger(void)
{
}


void CSysMemberLinkCostDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysMemberLinkCostDumpTrigger");
	pLogger->output(indent,0,"CSysMemberLinkCostDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysMemberLinkCostDumpTrigger::beforeAdd(CWriteableSysMemberLinkCost *pSysMemberLinkCost)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMemberLinkCost,add");
		pSysMemberLinkCost->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysMemberLinkCost\n");
		pSysMemberLinkCost->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysMemberLinkCostDumpTrigger::beforeUpdate(CSysMemberLinkCost *pSysMemberLinkCost, CWriteableSysMemberLinkCost *pNewSysMemberLinkCost)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMemberLinkCost,upd");
		pNewSysMemberLinkCost->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysMemberLinkCost\n");
		pNewSysMemberLinkCost->dumpDiff(m_output,pSysMemberLinkCost);
#endif
		fflush(m_output);
	}
}
	
void CSysMemberLinkCostDumpTrigger::beforeRemove(CSysMemberLinkCost *pSysMemberLinkCost)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysMemberLinkCost,del");
		pSysMemberLinkCost->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysMemberLinkCost\n");
		pSysMemberLinkCost->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetPartylinkMonthlyRentDumpTrigger::CSysNetPartylinkMonthlyRentDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetPartylinkMonthlyRentDumpTrigger::~CSysNetPartylinkMonthlyRentDumpTrigger(void)
{
}


void CSysNetPartylinkMonthlyRentDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetPartylinkMonthlyRentDumpTrigger");
	pLogger->output(indent,0,"CSysNetPartylinkMonthlyRentDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetPartylinkMonthlyRentDumpTrigger::beforeAdd(CWriteableSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetPartylinkMonthlyRent,add");
		pSysNetPartylinkMonthlyRent->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetPartylinkMonthlyRent\n");
		pSysNetPartylinkMonthlyRent->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetPartylinkMonthlyRentDumpTrigger::beforeUpdate(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, CWriteableSysNetPartylinkMonthlyRent *pNewSysNetPartylinkMonthlyRent)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetPartylinkMonthlyRent,upd");
		pNewSysNetPartylinkMonthlyRent->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetPartylinkMonthlyRent\n");
		pNewSysNetPartylinkMonthlyRent->dumpDiff(m_output,pSysNetPartylinkMonthlyRent);
#endif
		fflush(m_output);
	}
}
	
void CSysNetPartylinkMonthlyRentDumpTrigger::beforeRemove(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetPartylinkMonthlyRent,del");
		pSysNetPartylinkMonthlyRent->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetPartylinkMonthlyRent\n");
		pSysNetPartylinkMonthlyRent->dump(m_output);
#endif
		fflush(m_output);
	}
}

CSysNetNonPartyLinkInfoDumpTrigger::CSysNetNonPartyLinkInfoDumpTrigger(FILE *output, int flag)
{
	m_output=output;
	m_flag=flag;
}

CSysNetNonPartyLinkInfoDumpTrigger::~CSysNetNonPartyLinkInfoDumpTrigger(void)
{
}


void CSysNetNonPartyLinkInfoDumpTrigger::output(CLogger *pLogger,int indent)
{
	//CHECK_TYPE("CSysNetNonPartyLinkInfoDumpTrigger");
	pLogger->output(indent,0,"CSysNetNonPartyLinkInfoDumpTrigger:flag=");
	if (m_flag&CREATE_ACTION)
		pLogger->output("CREATE ");
	if (m_flag&UPDATE_ACTION)
		pLogger->output("UPDATE ");
	if (m_flag&DELETE_ACTION)
		pLogger->output("DELETE ");
}

void CSysNetNonPartyLinkInfoDumpTrigger::beforeAdd(CWriteableSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
{
	if (m_flag&CREATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetNonPartyLinkInfo,add");
		pSysNetNonPartyLinkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Add SysNetNonPartyLinkInfo\n");
		pSysNetNonPartyLinkInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}
	
void CSysNetNonPartyLinkInfoDumpTrigger::beforeUpdate(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, CWriteableSysNetNonPartyLinkInfo *pNewSysNetNonPartyLinkInfo)
{
	if (m_flag&UPDATE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetNonPartyLinkInfo,upd");
		pNewSysNetNonPartyLinkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Update SysNetNonPartyLinkInfo\n");
		pNewSysNetNonPartyLinkInfo->dumpDiff(m_output,pSysNetNonPartyLinkInfo);
#endif
		fflush(m_output);
	}
}
	
void CSysNetNonPartyLinkInfoDumpTrigger::beforeRemove(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
{
	if (m_flag&DELETE_ACTION)
	{
#ifdef SINGLE_LINE
		fprintf(m_output,"SysNetNonPartyLinkInfo,del");
		pSysNetNonPartyLinkInfo->dumpInLine(m_output);
		fprintf(m_output,"\n");
#else
		fprintf(m_output,"Remove SysNetNonPartyLinkInfo\n");
		pSysNetNonPartyLinkInfo->dump(m_output);
#endif
		fflush(m_output);
	}
}

CDumpLog::CDumpLog(CMemoryDB *pDB, CConfig *pConfig)
{
	char *fileName=pConfig->getConfig("DumpOutput");
	if (*fileName=='\0')
	{
		m_DumpOutput=NULL;
		return;
	}
	if (!strcmp(fileName,"stdout"))
	{
		m_DumpOutput=stdout;
	}
	else if (!strcmp(fileName,"stderr"))
	{
		m_DumpOutput=stderr;
	}
	else
	{
		m_DumpOutput=mfopen(fileName,"wt");
	}
	if (m_DumpOutput==NULL)
	{
		REPORT_EVENT(LOG_INFO,"EnvError","write dump file failed");
		return;
	}
	m_DB=pDB;
	m_Started=0;

	m_SysInvalidateOrderTrigger=new CSysInvalidateOrderDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysOrderStatusTrigger=new CSysOrderStatusDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysBargainOrderTrigger=new CSysBargainOrderDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysInstPropertyTrigger=new CSysInstPropertyDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMarginRateTrigger=new CSysMarginRateDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysPriceLimitTrigger=new CSysPriceLimitDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysPartPosiLimitTrigger=new CSysPartPosiLimitDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysClientPosiLimitTrigger=new CSysClientPosiLimitDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysSpecialPosiLimitTrigger=new CSysSpecialPosiLimitDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysTransactionChgTrigger=new CSysTransactionChgDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysClientChgTrigger=new CSysClientChgDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysPartClientChgTrigger=new CSysPartClientChgDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysPosiLimitChgTrigger=new CSysPosiLimitChgDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysClientPosiLimitChgTrigger=new CSysClientPosiLimitChgDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysSpecPosiLimitChgTrigger=new CSysSpecPosiLimitChgDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysHedgeDetailChgTrigger=new CSysHedgeDetailChgDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysParticipantChgTrigger=new CSysParticipantChgDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMarginRateChgTrigger=new CSysMarginRateChgDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysUserIpChgTrigger=new CSysUserIpChgDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysPartTradeTrigger=new CSysPartTradeDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMdbObjectAttrTrigger=new CSysMdbObjectAttrDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMdbSyslogInfoTrigger=new CSysMdbSyslogInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysUserInfoTrigger=new CSysUserInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysOnlineUserInfoTrigger=new CSysOnlineUserInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysWarningEventTrigger=new CSysWarningEventDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysWarningQueryTrigger=new CSysWarningQueryDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SyslogEventTrigger=new CSyslogEventDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysEventDescripTrigger=new CSysEventDescripDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_RspQryHostEnvCommonTrigger=new CRspQryHostEnvCommonDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_RspQryHostEnvLanTrigger=new CRspQryHostEnvLanDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_RspQryHostEnvStorageTrigger=new CRspQryHostEnvStorageDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_RspQryHostEnvIOTrigger=new CRspQryHostEnvIODumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_RspQryHostEnvFSTrigger=new CRspQryHostEnvFSDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_RspQryHostEnvSwapTrigger=new CRspQryHostEnvSwapDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_RspQryHostEnvLanCfgTrigger=new CRspQryHostEnvLanCfgDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMdbTopCpuInfoTrigger=new CSysMdbTopCpuInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMdbTopMemInfoTrigger=new CSysMdbTopMemInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMdbTopProcessInfoTrigger=new CSysMdbTopProcessInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMdbFileSystemInfoTrigger=new CSysMdbFileSystemInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMdbNetworkInfoTrigger=new CSysMdbNetworkInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysParticipantInitTrigger=new CSysParticipantInitDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysUserInitTrigger=new CSysUserInitDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysClientInitTrigger=new CSysClientInitDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysTradeUserLoginInfoTrigger=new CSysTradeUserLoginInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMdbWebAppInfoTrigger=new CSysMdbWebAppInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMdbMemPoolInfoTrigger=new CSysMdbMemPoolInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMdbConnectorInfoTrigger=new CSysMdbConnectorInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMdbDBQueryTrigger=new CSysMdbDBQueryDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetAreaTrigger=new CSysNetAreaDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetSubAreaTrigger=new CSysNetSubAreaDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetSubAreaIPTrigger=new CSysNetSubAreaIPDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetFuncAreaTrigger=new CSysNetFuncAreaDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetDeviceTrigger=new CSysNetDeviceDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetDeviceLinkedTrigger=new CSysNetDeviceLinkedDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetOIDTrigger=new CSysNetOIDDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetDeviceTypeTrigger=new CSysNetDeviceTypeDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetTimePolicyTrigger=new CSysNetTimePolicyDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetGatherTaskTrigger=new CSysNetGatherTaskDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetDeviceCategoryTrigger=new CSysNetDeviceCategoryDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetManufactoryTrigger=new CSysNetManufactoryDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetCommunityTrigger=new CSysNetCommunityDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetPortTypeTrigger=new CSysNetPortTypeDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetInterfaceTrigger=new CSysNetInterfaceDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetGeneralOIDTrigger=new CSysNetGeneralOIDDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetMonitorTypeTrigger=new CSysNetMonitorTypeDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetMonitorAttrScopeTrigger=new CSysNetMonitorAttrScopeDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetMonitorAttrTypeTrigger=new CSysNetMonitorAttrTypeDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetMonitorCommandTypeTrigger=new CSysNetMonitorCommandTypeDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetMonitorActionGroupTrigger=new CSysNetMonitorActionGroupDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetMonitorDeviceGroupTrigger=new CSysNetMonitorDeviceGroupDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetMonitorTaskInfoTrigger=new CSysNetMonitorTaskInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetMonitorTaskObjectSetTrigger=new CSysNetMonitorTaskObjectSetDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetMonitorTaskResultTrigger=new CSysNetMonitorTaskResultDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetPartyLinkInfoTrigger=new CSysNetPartyLinkInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetDelPartyLinkInfoTrigger=new CSysNetDelPartyLinkInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetPartyLinkAddrChangeTrigger=new CSysNetPartyLinkAddrChangeDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetMonitorActionAttrTrigger=new CSysNetMonitorActionAttrDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetModuleTrigger=new CSysNetModuleDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetEventExprTrigger=new CSysNetEventExprDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetEventTypeTrigger=new CSysNetEventTypeDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetSubEventTypeTrigger=new CSysNetSubEventTypeDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetEventLevelTrigger=new CSysNetEventLevelDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetMonitorDeviceTaskTrigger=new CSysNetMonitorDeviceTaskDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetMonitorTaskInstAttrsTrigger=new CSysNetMonitorTaskInstAttrsDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetBaseLineTrigger=new CSysNetBaseLineDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetBaseLineTaskTrigger=new CSysNetBaseLineTaskDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMdbNetPartyLinkStatusInfoTrigger=new CSysMdbNetPartyLinkStatusInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetMemberSDHLineInfoTrigger=new CSysNetMemberSDHLineInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetDDNLinkInfoTrigger=new CSysNetDDNLinkInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetPseudMemberLinkInfoTrigger=new CSysNetPseudMemberLinkInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetOuterDeviceInfoTrigger=new CSysNetOuterDeviceInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysLocalPingResultInfoTrigger=new CSysLocalPingResultInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysRomotePingResultInfoTrigger=new CSysRomotePingResultInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysParticTradeOrderStatesTrigger=new CSysParticTradeOrderStatesDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMdbRouterInfoTrigger=new CSysMdbRouterInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMdbDiskIOTrigger=new CSysMdbDiskIODumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMdbStatInfoTrigger=new CSysMdbStatInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMdbTradeFrontOrderRttStatTrigger=new CSysMdbTradeFrontOrderRttStatDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysInstrumentStatusTrigger=new CSysInstrumentStatusDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysCurrTradingSegmentAttrTrigger=new CSysCurrTradingSegmentAttrDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysMemberLinkCostTrigger=new CSysMemberLinkCostDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetPartylinkMonthlyRentTrigger=new CSysNetPartylinkMonthlyRentDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
	m_SysNetNonPartyLinkInfoTrigger=new CSysNetNonPartyLinkInfoDumpTrigger(m_DumpOutput,CREATE_ACTION|UPDATE_ACTION|DELETE_ACTION);
}

CDumpLog::~CDumpLog(void)
{
	stop();
	if (m_DumpOutput==NULL)
	{
		return;
	}
	delete m_SysInvalidateOrderTrigger;
	delete m_SysOrderStatusTrigger;
	delete m_SysBargainOrderTrigger;
	delete m_SysInstPropertyTrigger;
	delete m_SysMarginRateTrigger;
	delete m_SysPriceLimitTrigger;
	delete m_SysPartPosiLimitTrigger;
	delete m_SysClientPosiLimitTrigger;
	delete m_SysSpecialPosiLimitTrigger;
	delete m_SysTransactionChgTrigger;
	delete m_SysClientChgTrigger;
	delete m_SysPartClientChgTrigger;
	delete m_SysPosiLimitChgTrigger;
	delete m_SysClientPosiLimitChgTrigger;
	delete m_SysSpecPosiLimitChgTrigger;
	delete m_SysHedgeDetailChgTrigger;
	delete m_SysParticipantChgTrigger;
	delete m_SysMarginRateChgTrigger;
	delete m_SysUserIpChgTrigger;
	delete m_SysPartTradeTrigger;
	delete m_SysMdbObjectAttrTrigger;
	delete m_SysMdbSyslogInfoTrigger;
	delete m_SysUserInfoTrigger;
	delete m_SysOnlineUserInfoTrigger;
	delete m_SysWarningEventTrigger;
	delete m_SysWarningQueryTrigger;
	delete m_SyslogEventTrigger;
	delete m_SysEventDescripTrigger;
	delete m_RspQryHostEnvCommonTrigger;
	delete m_RspQryHostEnvLanTrigger;
	delete m_RspQryHostEnvStorageTrigger;
	delete m_RspQryHostEnvIOTrigger;
	delete m_RspQryHostEnvFSTrigger;
	delete m_RspQryHostEnvSwapTrigger;
	delete m_RspQryHostEnvLanCfgTrigger;
	delete m_SysMdbTopCpuInfoTrigger;
	delete m_SysMdbTopMemInfoTrigger;
	delete m_SysMdbTopProcessInfoTrigger;
	delete m_SysMdbFileSystemInfoTrigger;
	delete m_SysMdbNetworkInfoTrigger;
	delete m_SysParticipantInitTrigger;
	delete m_SysUserInitTrigger;
	delete m_SysClientInitTrigger;
	delete m_SysTradeUserLoginInfoTrigger;
	delete m_SysMdbWebAppInfoTrigger;
	delete m_SysMdbMemPoolInfoTrigger;
	delete m_SysMdbConnectorInfoTrigger;
	delete m_SysMdbDBQueryTrigger;
	delete m_SysNetAreaTrigger;
	delete m_SysNetSubAreaTrigger;
	delete m_SysNetSubAreaIPTrigger;
	delete m_SysNetFuncAreaTrigger;
	delete m_SysNetDeviceTrigger;
	delete m_SysNetDeviceLinkedTrigger;
	delete m_SysNetOIDTrigger;
	delete m_SysNetDeviceTypeTrigger;
	delete m_SysNetTimePolicyTrigger;
	delete m_SysNetGatherTaskTrigger;
	delete m_SysNetDeviceCategoryTrigger;
	delete m_SysNetManufactoryTrigger;
	delete m_SysNetCommunityTrigger;
	delete m_SysNetPortTypeTrigger;
	delete m_SysNetInterfaceTrigger;
	delete m_SysNetGeneralOIDTrigger;
	delete m_SysNetMonitorTypeTrigger;
	delete m_SysNetMonitorAttrScopeTrigger;
	delete m_SysNetMonitorAttrTypeTrigger;
	delete m_SysNetMonitorCommandTypeTrigger;
	delete m_SysNetMonitorActionGroupTrigger;
	delete m_SysNetMonitorDeviceGroupTrigger;
	delete m_SysNetMonitorTaskInfoTrigger;
	delete m_SysNetMonitorTaskObjectSetTrigger;
	delete m_SysNetMonitorTaskResultTrigger;
	delete m_SysNetPartyLinkInfoTrigger;
	delete m_SysNetDelPartyLinkInfoTrigger;
	delete m_SysNetPartyLinkAddrChangeTrigger;
	delete m_SysNetMonitorActionAttrTrigger;
	delete m_SysNetModuleTrigger;
	delete m_SysNetEventExprTrigger;
	delete m_SysNetEventTypeTrigger;
	delete m_SysNetSubEventTypeTrigger;
	delete m_SysNetEventLevelTrigger;
	delete m_SysNetMonitorDeviceTaskTrigger;
	delete m_SysNetMonitorTaskInstAttrsTrigger;
	delete m_SysNetBaseLineTrigger;
	delete m_SysNetBaseLineTaskTrigger;
	delete m_SysMdbNetPartyLinkStatusInfoTrigger;
	delete m_SysNetMemberSDHLineInfoTrigger;
	delete m_SysNetDDNLinkInfoTrigger;
	delete m_SysNetPseudMemberLinkInfoTrigger;
	delete m_SysNetOuterDeviceInfoTrigger;
	delete m_SysLocalPingResultInfoTrigger;
	delete m_SysRomotePingResultInfoTrigger;
	delete m_SysParticTradeOrderStatesTrigger;
	delete m_SysMdbRouterInfoTrigger;
	delete m_SysMdbDiskIOTrigger;
	delete m_SysMdbStatInfoTrigger;
	delete m_SysMdbTradeFrontOrderRttStatTrigger;
	delete m_SysInstrumentStatusTrigger;
	delete m_SysCurrTradingSegmentAttrTrigger;
	delete m_SysMemberLinkCostTrigger;
	delete m_SysNetPartylinkMonthlyRentTrigger;
	delete m_SysNetNonPartyLinkInfoTrigger;
	if ((m_DumpOutput!=NULL)&&(m_DumpOutput!=stdout)&&(m_DumpOutput!=stderr))
	{
		fclose(m_DumpOutput);
	}
}

int CDumpLog::isStarted(void)
{
	return m_Started;
}

void CDumpLog::start(void)
{
	if (m_Started)
	{
		return;
	}
	if (m_DumpOutput==NULL)
	{
		return;
	}
	m_DB->m_SysInvalidateOrderFactory->addActionTrigger(m_SysInvalidateOrderTrigger);
	m_DB->m_SysOrderStatusFactory->addActionTrigger(m_SysOrderStatusTrigger);
	m_DB->m_SysBargainOrderFactory->addActionTrigger(m_SysBargainOrderTrigger);
	m_DB->m_SysInstPropertyFactory->addActionTrigger(m_SysInstPropertyTrigger);
	m_DB->m_SysMarginRateFactory->addActionTrigger(m_SysMarginRateTrigger);
	m_DB->m_SysPriceLimitFactory->addActionTrigger(m_SysPriceLimitTrigger);
	m_DB->m_SysPartPosiLimitFactory->addActionTrigger(m_SysPartPosiLimitTrigger);
	m_DB->m_SysClientPosiLimitFactory->addActionTrigger(m_SysClientPosiLimitTrigger);
	m_DB->m_SysSpecialPosiLimitFactory->addActionTrigger(m_SysSpecialPosiLimitTrigger);
	m_DB->m_SysTransactionChgFactory->addActionTrigger(m_SysTransactionChgTrigger);
	m_DB->m_SysClientChgFactory->addActionTrigger(m_SysClientChgTrigger);
	m_DB->m_SysPartClientChgFactory->addActionTrigger(m_SysPartClientChgTrigger);
	m_DB->m_SysPosiLimitChgFactory->addActionTrigger(m_SysPosiLimitChgTrigger);
	m_DB->m_SysClientPosiLimitChgFactory->addActionTrigger(m_SysClientPosiLimitChgTrigger);
	m_DB->m_SysSpecPosiLimitChgFactory->addActionTrigger(m_SysSpecPosiLimitChgTrigger);
	m_DB->m_SysHedgeDetailChgFactory->addActionTrigger(m_SysHedgeDetailChgTrigger);
	m_DB->m_SysParticipantChgFactory->addActionTrigger(m_SysParticipantChgTrigger);
	m_DB->m_SysMarginRateChgFactory->addActionTrigger(m_SysMarginRateChgTrigger);
	m_DB->m_SysUserIpChgFactory->addActionTrigger(m_SysUserIpChgTrigger);
	m_DB->m_SysPartTradeFactory->addActionTrigger(m_SysPartTradeTrigger);
	m_DB->m_SysMdbObjectAttrFactory->addActionTrigger(m_SysMdbObjectAttrTrigger);
	m_DB->m_SysMdbSyslogInfoFactory->addActionTrigger(m_SysMdbSyslogInfoTrigger);
	m_DB->m_SysUserInfoFactory->addActionTrigger(m_SysUserInfoTrigger);
	m_DB->m_SysOnlineUserInfoFactory->addActionTrigger(m_SysOnlineUserInfoTrigger);
	m_DB->m_SysWarningEventFactory->addActionTrigger(m_SysWarningEventTrigger);
	m_DB->m_SysWarningQueryFactory->addActionTrigger(m_SysWarningQueryTrigger);
	m_DB->m_SyslogEventFactory->addActionTrigger(m_SyslogEventTrigger);
	m_DB->m_SysEventDescripFactory->addActionTrigger(m_SysEventDescripTrigger);
	m_DB->m_RspQryHostEnvCommonFactory->addActionTrigger(m_RspQryHostEnvCommonTrigger);
	m_DB->m_RspQryHostEnvLanFactory->addActionTrigger(m_RspQryHostEnvLanTrigger);
	m_DB->m_RspQryHostEnvStorageFactory->addActionTrigger(m_RspQryHostEnvStorageTrigger);
	m_DB->m_RspQryHostEnvIOFactory->addActionTrigger(m_RspQryHostEnvIOTrigger);
	m_DB->m_RspQryHostEnvFSFactory->addActionTrigger(m_RspQryHostEnvFSTrigger);
	m_DB->m_RspQryHostEnvSwapFactory->addActionTrigger(m_RspQryHostEnvSwapTrigger);
	m_DB->m_RspQryHostEnvLanCfgFactory->addActionTrigger(m_RspQryHostEnvLanCfgTrigger);
	m_DB->m_SysMdbTopCpuInfoFactory->addActionTrigger(m_SysMdbTopCpuInfoTrigger);
	m_DB->m_SysMdbTopMemInfoFactory->addActionTrigger(m_SysMdbTopMemInfoTrigger);
	m_DB->m_SysMdbTopProcessInfoFactory->addActionTrigger(m_SysMdbTopProcessInfoTrigger);
	m_DB->m_SysMdbFileSystemInfoFactory->addActionTrigger(m_SysMdbFileSystemInfoTrigger);
	m_DB->m_SysMdbNetworkInfoFactory->addActionTrigger(m_SysMdbNetworkInfoTrigger);
	m_DB->m_SysParticipantInitFactory->addActionTrigger(m_SysParticipantInitTrigger);
	m_DB->m_SysUserInitFactory->addActionTrigger(m_SysUserInitTrigger);
	m_DB->m_SysClientInitFactory->addActionTrigger(m_SysClientInitTrigger);
	m_DB->m_SysTradeUserLoginInfoFactory->addActionTrigger(m_SysTradeUserLoginInfoTrigger);
	m_DB->m_SysMdbWebAppInfoFactory->addActionTrigger(m_SysMdbWebAppInfoTrigger);
	m_DB->m_SysMdbMemPoolInfoFactory->addActionTrigger(m_SysMdbMemPoolInfoTrigger);
	m_DB->m_SysMdbConnectorInfoFactory->addActionTrigger(m_SysMdbConnectorInfoTrigger);
	m_DB->m_SysMdbDBQueryFactory->addActionTrigger(m_SysMdbDBQueryTrigger);
	m_DB->m_SysNetAreaFactory->addActionTrigger(m_SysNetAreaTrigger);
	m_DB->m_SysNetSubAreaFactory->addActionTrigger(m_SysNetSubAreaTrigger);
	m_DB->m_SysNetSubAreaIPFactory->addActionTrigger(m_SysNetSubAreaIPTrigger);
	m_DB->m_SysNetFuncAreaFactory->addActionTrigger(m_SysNetFuncAreaTrigger);
	m_DB->m_SysNetDeviceFactory->addActionTrigger(m_SysNetDeviceTrigger);
	m_DB->m_SysNetDeviceLinkedFactory->addActionTrigger(m_SysNetDeviceLinkedTrigger);
	m_DB->m_SysNetOIDFactory->addActionTrigger(m_SysNetOIDTrigger);
	m_DB->m_SysNetDeviceTypeFactory->addActionTrigger(m_SysNetDeviceTypeTrigger);
	m_DB->m_SysNetTimePolicyFactory->addActionTrigger(m_SysNetTimePolicyTrigger);
	m_DB->m_SysNetGatherTaskFactory->addActionTrigger(m_SysNetGatherTaskTrigger);
	m_DB->m_SysNetDeviceCategoryFactory->addActionTrigger(m_SysNetDeviceCategoryTrigger);
	m_DB->m_SysNetManufactoryFactory->addActionTrigger(m_SysNetManufactoryTrigger);
	m_DB->m_SysNetCommunityFactory->addActionTrigger(m_SysNetCommunityTrigger);
	m_DB->m_SysNetPortTypeFactory->addActionTrigger(m_SysNetPortTypeTrigger);
	m_DB->m_SysNetInterfaceFactory->addActionTrigger(m_SysNetInterfaceTrigger);
	m_DB->m_SysNetGeneralOIDFactory->addActionTrigger(m_SysNetGeneralOIDTrigger);
	m_DB->m_SysNetMonitorTypeFactory->addActionTrigger(m_SysNetMonitorTypeTrigger);
	m_DB->m_SysNetMonitorAttrScopeFactory->addActionTrigger(m_SysNetMonitorAttrScopeTrigger);
	m_DB->m_SysNetMonitorAttrTypeFactory->addActionTrigger(m_SysNetMonitorAttrTypeTrigger);
	m_DB->m_SysNetMonitorCommandTypeFactory->addActionTrigger(m_SysNetMonitorCommandTypeTrigger);
	m_DB->m_SysNetMonitorActionGroupFactory->addActionTrigger(m_SysNetMonitorActionGroupTrigger);
	m_DB->m_SysNetMonitorDeviceGroupFactory->addActionTrigger(m_SysNetMonitorDeviceGroupTrigger);
	m_DB->m_SysNetMonitorTaskInfoFactory->addActionTrigger(m_SysNetMonitorTaskInfoTrigger);
	m_DB->m_SysNetMonitorTaskObjectSetFactory->addActionTrigger(m_SysNetMonitorTaskObjectSetTrigger);
	m_DB->m_SysNetMonitorTaskResultFactory->addActionTrigger(m_SysNetMonitorTaskResultTrigger);
	m_DB->m_SysNetPartyLinkInfoFactory->addActionTrigger(m_SysNetPartyLinkInfoTrigger);
	m_DB->m_SysNetDelPartyLinkInfoFactory->addActionTrigger(m_SysNetDelPartyLinkInfoTrigger);
	m_DB->m_SysNetPartyLinkAddrChangeFactory->addActionTrigger(m_SysNetPartyLinkAddrChangeTrigger);
	m_DB->m_SysNetMonitorActionAttrFactory->addActionTrigger(m_SysNetMonitorActionAttrTrigger);
	m_DB->m_SysNetModuleFactory->addActionTrigger(m_SysNetModuleTrigger);
	m_DB->m_SysNetEventExprFactory->addActionTrigger(m_SysNetEventExprTrigger);
	m_DB->m_SysNetEventTypeFactory->addActionTrigger(m_SysNetEventTypeTrigger);
	m_DB->m_SysNetSubEventTypeFactory->addActionTrigger(m_SysNetSubEventTypeTrigger);
	m_DB->m_SysNetEventLevelFactory->addActionTrigger(m_SysNetEventLevelTrigger);
	m_DB->m_SysNetMonitorDeviceTaskFactory->addActionTrigger(m_SysNetMonitorDeviceTaskTrigger);
	m_DB->m_SysNetMonitorTaskInstAttrsFactory->addActionTrigger(m_SysNetMonitorTaskInstAttrsTrigger);
	m_DB->m_SysNetBaseLineFactory->addActionTrigger(m_SysNetBaseLineTrigger);
	m_DB->m_SysNetBaseLineTaskFactory->addActionTrigger(m_SysNetBaseLineTaskTrigger);
	m_DB->m_SysMdbNetPartyLinkStatusInfoFactory->addActionTrigger(m_SysMdbNetPartyLinkStatusInfoTrigger);
	m_DB->m_SysNetMemberSDHLineInfoFactory->addActionTrigger(m_SysNetMemberSDHLineInfoTrigger);
	m_DB->m_SysNetDDNLinkInfoFactory->addActionTrigger(m_SysNetDDNLinkInfoTrigger);
	m_DB->m_SysNetPseudMemberLinkInfoFactory->addActionTrigger(m_SysNetPseudMemberLinkInfoTrigger);
	m_DB->m_SysNetOuterDeviceInfoFactory->addActionTrigger(m_SysNetOuterDeviceInfoTrigger);
	m_DB->m_SysLocalPingResultInfoFactory->addActionTrigger(m_SysLocalPingResultInfoTrigger);
	m_DB->m_SysRomotePingResultInfoFactory->addActionTrigger(m_SysRomotePingResultInfoTrigger);
	m_DB->m_SysParticTradeOrderStatesFactory->addActionTrigger(m_SysParticTradeOrderStatesTrigger);
	m_DB->m_SysMdbRouterInfoFactory->addActionTrigger(m_SysMdbRouterInfoTrigger);
	m_DB->m_SysMdbDiskIOFactory->addActionTrigger(m_SysMdbDiskIOTrigger);
	m_DB->m_SysMdbStatInfoFactory->addActionTrigger(m_SysMdbStatInfoTrigger);
	m_DB->m_SysMdbTradeFrontOrderRttStatFactory->addActionTrigger(m_SysMdbTradeFrontOrderRttStatTrigger);
	m_DB->m_SysInstrumentStatusFactory->addActionTrigger(m_SysInstrumentStatusTrigger);
	m_DB->m_SysCurrTradingSegmentAttrFactory->addActionTrigger(m_SysCurrTradingSegmentAttrTrigger);
	m_DB->m_SysMemberLinkCostFactory->addActionTrigger(m_SysMemberLinkCostTrigger);
	m_DB->m_SysNetPartylinkMonthlyRentFactory->addActionTrigger(m_SysNetPartylinkMonthlyRentTrigger);
	m_DB->m_SysNetNonPartyLinkInfoFactory->addActionTrigger(m_SysNetNonPartyLinkInfoTrigger);
}

void CDumpLog::stop()
{
	if (!m_Started)
	{
		return;
	}
	if (m_DumpOutput==NULL)
	{
		return;
	}
	m_DB->m_SysInvalidateOrderFactory->removeActionTrigger(m_SysInvalidateOrderTrigger);
	m_DB->m_SysOrderStatusFactory->removeActionTrigger(m_SysOrderStatusTrigger);
	m_DB->m_SysBargainOrderFactory->removeActionTrigger(m_SysBargainOrderTrigger);
	m_DB->m_SysInstPropertyFactory->removeActionTrigger(m_SysInstPropertyTrigger);
	m_DB->m_SysMarginRateFactory->removeActionTrigger(m_SysMarginRateTrigger);
	m_DB->m_SysPriceLimitFactory->removeActionTrigger(m_SysPriceLimitTrigger);
	m_DB->m_SysPartPosiLimitFactory->removeActionTrigger(m_SysPartPosiLimitTrigger);
	m_DB->m_SysClientPosiLimitFactory->removeActionTrigger(m_SysClientPosiLimitTrigger);
	m_DB->m_SysSpecialPosiLimitFactory->removeActionTrigger(m_SysSpecialPosiLimitTrigger);
	m_DB->m_SysTransactionChgFactory->removeActionTrigger(m_SysTransactionChgTrigger);
	m_DB->m_SysClientChgFactory->removeActionTrigger(m_SysClientChgTrigger);
	m_DB->m_SysPartClientChgFactory->removeActionTrigger(m_SysPartClientChgTrigger);
	m_DB->m_SysPosiLimitChgFactory->removeActionTrigger(m_SysPosiLimitChgTrigger);
	m_DB->m_SysClientPosiLimitChgFactory->removeActionTrigger(m_SysClientPosiLimitChgTrigger);
	m_DB->m_SysSpecPosiLimitChgFactory->removeActionTrigger(m_SysSpecPosiLimitChgTrigger);
	m_DB->m_SysHedgeDetailChgFactory->removeActionTrigger(m_SysHedgeDetailChgTrigger);
	m_DB->m_SysParticipantChgFactory->removeActionTrigger(m_SysParticipantChgTrigger);
	m_DB->m_SysMarginRateChgFactory->removeActionTrigger(m_SysMarginRateChgTrigger);
	m_DB->m_SysUserIpChgFactory->removeActionTrigger(m_SysUserIpChgTrigger);
	m_DB->m_SysPartTradeFactory->removeActionTrigger(m_SysPartTradeTrigger);
	m_DB->m_SysMdbObjectAttrFactory->removeActionTrigger(m_SysMdbObjectAttrTrigger);
	m_DB->m_SysMdbSyslogInfoFactory->removeActionTrigger(m_SysMdbSyslogInfoTrigger);
	m_DB->m_SysUserInfoFactory->removeActionTrigger(m_SysUserInfoTrigger);
	m_DB->m_SysOnlineUserInfoFactory->removeActionTrigger(m_SysOnlineUserInfoTrigger);
	m_DB->m_SysWarningEventFactory->removeActionTrigger(m_SysWarningEventTrigger);
	m_DB->m_SysWarningQueryFactory->removeActionTrigger(m_SysWarningQueryTrigger);
	m_DB->m_SyslogEventFactory->removeActionTrigger(m_SyslogEventTrigger);
	m_DB->m_SysEventDescripFactory->removeActionTrigger(m_SysEventDescripTrigger);
	m_DB->m_RspQryHostEnvCommonFactory->removeActionTrigger(m_RspQryHostEnvCommonTrigger);
	m_DB->m_RspQryHostEnvLanFactory->removeActionTrigger(m_RspQryHostEnvLanTrigger);
	m_DB->m_RspQryHostEnvStorageFactory->removeActionTrigger(m_RspQryHostEnvStorageTrigger);
	m_DB->m_RspQryHostEnvIOFactory->removeActionTrigger(m_RspQryHostEnvIOTrigger);
	m_DB->m_RspQryHostEnvFSFactory->removeActionTrigger(m_RspQryHostEnvFSTrigger);
	m_DB->m_RspQryHostEnvSwapFactory->removeActionTrigger(m_RspQryHostEnvSwapTrigger);
	m_DB->m_RspQryHostEnvLanCfgFactory->removeActionTrigger(m_RspQryHostEnvLanCfgTrigger);
	m_DB->m_SysMdbTopCpuInfoFactory->removeActionTrigger(m_SysMdbTopCpuInfoTrigger);
	m_DB->m_SysMdbTopMemInfoFactory->removeActionTrigger(m_SysMdbTopMemInfoTrigger);
	m_DB->m_SysMdbTopProcessInfoFactory->removeActionTrigger(m_SysMdbTopProcessInfoTrigger);
	m_DB->m_SysMdbFileSystemInfoFactory->removeActionTrigger(m_SysMdbFileSystemInfoTrigger);
	m_DB->m_SysMdbNetworkInfoFactory->removeActionTrigger(m_SysMdbNetworkInfoTrigger);
	m_DB->m_SysParticipantInitFactory->removeActionTrigger(m_SysParticipantInitTrigger);
	m_DB->m_SysUserInitFactory->removeActionTrigger(m_SysUserInitTrigger);
	m_DB->m_SysClientInitFactory->removeActionTrigger(m_SysClientInitTrigger);
	m_DB->m_SysTradeUserLoginInfoFactory->removeActionTrigger(m_SysTradeUserLoginInfoTrigger);
	m_DB->m_SysMdbWebAppInfoFactory->removeActionTrigger(m_SysMdbWebAppInfoTrigger);
	m_DB->m_SysMdbMemPoolInfoFactory->removeActionTrigger(m_SysMdbMemPoolInfoTrigger);
	m_DB->m_SysMdbConnectorInfoFactory->removeActionTrigger(m_SysMdbConnectorInfoTrigger);
	m_DB->m_SysMdbDBQueryFactory->removeActionTrigger(m_SysMdbDBQueryTrigger);
	m_DB->m_SysNetAreaFactory->removeActionTrigger(m_SysNetAreaTrigger);
	m_DB->m_SysNetSubAreaFactory->removeActionTrigger(m_SysNetSubAreaTrigger);
	m_DB->m_SysNetSubAreaIPFactory->removeActionTrigger(m_SysNetSubAreaIPTrigger);
	m_DB->m_SysNetFuncAreaFactory->removeActionTrigger(m_SysNetFuncAreaTrigger);
	m_DB->m_SysNetDeviceFactory->removeActionTrigger(m_SysNetDeviceTrigger);
	m_DB->m_SysNetDeviceLinkedFactory->removeActionTrigger(m_SysNetDeviceLinkedTrigger);
	m_DB->m_SysNetOIDFactory->removeActionTrigger(m_SysNetOIDTrigger);
	m_DB->m_SysNetDeviceTypeFactory->removeActionTrigger(m_SysNetDeviceTypeTrigger);
	m_DB->m_SysNetTimePolicyFactory->removeActionTrigger(m_SysNetTimePolicyTrigger);
	m_DB->m_SysNetGatherTaskFactory->removeActionTrigger(m_SysNetGatherTaskTrigger);
	m_DB->m_SysNetDeviceCategoryFactory->removeActionTrigger(m_SysNetDeviceCategoryTrigger);
	m_DB->m_SysNetManufactoryFactory->removeActionTrigger(m_SysNetManufactoryTrigger);
	m_DB->m_SysNetCommunityFactory->removeActionTrigger(m_SysNetCommunityTrigger);
	m_DB->m_SysNetPortTypeFactory->removeActionTrigger(m_SysNetPortTypeTrigger);
	m_DB->m_SysNetInterfaceFactory->removeActionTrigger(m_SysNetInterfaceTrigger);
	m_DB->m_SysNetGeneralOIDFactory->removeActionTrigger(m_SysNetGeneralOIDTrigger);
	m_DB->m_SysNetMonitorTypeFactory->removeActionTrigger(m_SysNetMonitorTypeTrigger);
	m_DB->m_SysNetMonitorAttrScopeFactory->removeActionTrigger(m_SysNetMonitorAttrScopeTrigger);
	m_DB->m_SysNetMonitorAttrTypeFactory->removeActionTrigger(m_SysNetMonitorAttrTypeTrigger);
	m_DB->m_SysNetMonitorCommandTypeFactory->removeActionTrigger(m_SysNetMonitorCommandTypeTrigger);
	m_DB->m_SysNetMonitorActionGroupFactory->removeActionTrigger(m_SysNetMonitorActionGroupTrigger);
	m_DB->m_SysNetMonitorDeviceGroupFactory->removeActionTrigger(m_SysNetMonitorDeviceGroupTrigger);
	m_DB->m_SysNetMonitorTaskInfoFactory->removeActionTrigger(m_SysNetMonitorTaskInfoTrigger);
	m_DB->m_SysNetMonitorTaskObjectSetFactory->removeActionTrigger(m_SysNetMonitorTaskObjectSetTrigger);
	m_DB->m_SysNetMonitorTaskResultFactory->removeActionTrigger(m_SysNetMonitorTaskResultTrigger);
	m_DB->m_SysNetPartyLinkInfoFactory->removeActionTrigger(m_SysNetPartyLinkInfoTrigger);
	m_DB->m_SysNetDelPartyLinkInfoFactory->removeActionTrigger(m_SysNetDelPartyLinkInfoTrigger);
	m_DB->m_SysNetPartyLinkAddrChangeFactory->removeActionTrigger(m_SysNetPartyLinkAddrChangeTrigger);
	m_DB->m_SysNetMonitorActionAttrFactory->removeActionTrigger(m_SysNetMonitorActionAttrTrigger);
	m_DB->m_SysNetModuleFactory->removeActionTrigger(m_SysNetModuleTrigger);
	m_DB->m_SysNetEventExprFactory->removeActionTrigger(m_SysNetEventExprTrigger);
	m_DB->m_SysNetEventTypeFactory->removeActionTrigger(m_SysNetEventTypeTrigger);
	m_DB->m_SysNetSubEventTypeFactory->removeActionTrigger(m_SysNetSubEventTypeTrigger);
	m_DB->m_SysNetEventLevelFactory->removeActionTrigger(m_SysNetEventLevelTrigger);
	m_DB->m_SysNetMonitorDeviceTaskFactory->removeActionTrigger(m_SysNetMonitorDeviceTaskTrigger);
	m_DB->m_SysNetMonitorTaskInstAttrsFactory->removeActionTrigger(m_SysNetMonitorTaskInstAttrsTrigger);
	m_DB->m_SysNetBaseLineFactory->removeActionTrigger(m_SysNetBaseLineTrigger);
	m_DB->m_SysNetBaseLineTaskFactory->removeActionTrigger(m_SysNetBaseLineTaskTrigger);
	m_DB->m_SysMdbNetPartyLinkStatusInfoFactory->removeActionTrigger(m_SysMdbNetPartyLinkStatusInfoTrigger);
	m_DB->m_SysNetMemberSDHLineInfoFactory->removeActionTrigger(m_SysNetMemberSDHLineInfoTrigger);
	m_DB->m_SysNetDDNLinkInfoFactory->removeActionTrigger(m_SysNetDDNLinkInfoTrigger);
	m_DB->m_SysNetPseudMemberLinkInfoFactory->removeActionTrigger(m_SysNetPseudMemberLinkInfoTrigger);
	m_DB->m_SysNetOuterDeviceInfoFactory->removeActionTrigger(m_SysNetOuterDeviceInfoTrigger);
	m_DB->m_SysLocalPingResultInfoFactory->removeActionTrigger(m_SysLocalPingResultInfoTrigger);
	m_DB->m_SysRomotePingResultInfoFactory->removeActionTrigger(m_SysRomotePingResultInfoTrigger);
	m_DB->m_SysParticTradeOrderStatesFactory->removeActionTrigger(m_SysParticTradeOrderStatesTrigger);
	m_DB->m_SysMdbRouterInfoFactory->removeActionTrigger(m_SysMdbRouterInfoTrigger);
	m_DB->m_SysMdbDiskIOFactory->removeActionTrigger(m_SysMdbDiskIOTrigger);
	m_DB->m_SysMdbStatInfoFactory->removeActionTrigger(m_SysMdbStatInfoTrigger);
	m_DB->m_SysMdbTradeFrontOrderRttStatFactory->removeActionTrigger(m_SysMdbTradeFrontOrderRttStatTrigger);
	m_DB->m_SysInstrumentStatusFactory->removeActionTrigger(m_SysInstrumentStatusTrigger);
	m_DB->m_SysCurrTradingSegmentAttrFactory->removeActionTrigger(m_SysCurrTradingSegmentAttrTrigger);
	m_DB->m_SysMemberLinkCostFactory->removeActionTrigger(m_SysMemberLinkCostTrigger);
	m_DB->m_SysNetPartylinkMonthlyRentFactory->removeActionTrigger(m_SysNetPartylinkMonthlyRentTrigger);
	m_DB->m_SysNetNonPartyLinkInfoFactory->removeActionTrigger(m_SysNetNonPartyLinkInfoTrigger);
}

void CDumpLog::dumpMsg(char *format,...)
{
	va_list v;
	
	if (!m_Started)
	{
		return;
	}
	
	va_start(v,format);
	vfprintf(m_DumpOutput,format,v);
	va_end(v);
	fflush(m_DumpOutput);
}

