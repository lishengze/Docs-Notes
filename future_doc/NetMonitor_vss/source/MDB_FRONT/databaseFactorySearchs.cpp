/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseFactories.pp
///@brief实现了若干个内存数据库的对象工厂
///@history 
///20060127	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "BaseDataStruct.h"
#include "databaseFactories.h"
#include "databaseResources.h"
#include "monitorIndex.h"

//#define COUNT_SEARCH
int compareForSysInsertTimeIndexinSysInvalidateOrder(const void *pV1, const void *pV2)
{
	CSysInvalidateOrder *p1,*p2;
	p1=(CSysInvalidateOrder *)pV1;
	p2=(CSysInvalidateOrder *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysInvalidateOrder=0;
#endif

CSysInvalidateOrder *CSysInvalidateOrderFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysInvalidateOrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///记录所有的查询值
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysInvalidateOrder++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysInvalidateOrder *theSysInvalidateOrder;
	compareObject.ActionTime=ActionTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByActionTime=pSysInsertTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysInvalidateOrder=(CSysInvalidateOrder *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysInvalidateOrder;
}

CSysInvalidateOrder *CSysInvalidateOrderFactory::findNextByActionTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysInvalidateOrder++;
#endif
	CSysInvalidateOrder *theSysInvalidateOrder;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByActionTime=pSysInsertTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysInvalidateOrder=(CSysInvalidateOrder *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysInvalidateOrder;
}

void CSysInvalidateOrderFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysOrderStatus(const void *pV1, const void *pV2)
{
	CSysOrderStatus *p1,*p2;
	p1=(CSysOrderStatus *)pV1;
	p2=(CSysOrderStatus *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysOrderStatus=0;
#endif

CSysOrderStatus *CSysOrderStatusFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysOrderStatus while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///记录所有的查询值
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysOrderStatus++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysOrderStatus *theSysOrderStatus;
	compareObject.ActionTime=ActionTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysOrderStatus=(CSysOrderStatus *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysOrderStatus;
}

CSysOrderStatus *CSysOrderStatusFactory::findNextByActionTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysOrderStatus++;
#endif
	CSysOrderStatus *theSysOrderStatus;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysOrderStatus=(CSysOrderStatus *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysOrderStatus;
}

void CSysOrderStatusFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysTradeTimeIndexinSysBargainOrder(const void *pV1, const void *pV2)
{
	CSysBargainOrder *p1,*p2;
	p1=(CSysBargainOrder *)pV1;
	p2=(CSysBargainOrder *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysBargainOrder=0;
#endif

CSysBargainOrder *CSysBargainOrderFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysBargainOrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///记录所有的查询值
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysBargainOrder++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysBargainOrder *theSysBargainOrder;
	compareObject.ActionTime=ActionTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByActionTime=pSysTradeTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysBargainOrder=(CSysBargainOrder *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysBargainOrder;
}

CSysBargainOrder *CSysBargainOrderFactory::findNextByActionTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysBargainOrder++;
#endif
	CSysBargainOrder *theSysBargainOrder;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByActionTime=pSysTradeTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysBargainOrder=(CSysBargainOrder *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysBargainOrder;
}

void CSysBargainOrderFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysInstrumentIDIndexinSysInstProperty(const void *pV1, const void *pV2)
{
	CSysInstProperty *p1,*p2;
	p1=(CSysInstProperty *)pV1;
	p2=(CSysInstProperty *)pV2;
	switch (compare(p1->InstrumentID.getValue(),p2->InstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysInstProperty=0;
#endif

CSysInstProperty *CSysInstPropertyFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysInstProperty while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysInstProperty++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysInstProperty *theSysInstProperty;
	compareObject.InstrumentID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysInstProperty=(CSysInstProperty *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysInstProperty;
}

CSysInstProperty *CSysInstPropertyFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysInstProperty++;
#endif
	CSysInstProperty *theSysInstProperty;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysInstProperty=(CSysInstProperty *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysInstProperty;
}

void CSysInstPropertyFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysInstProperty=0;
#endif
CSysInstProperty *CSysInstPropertyFactory::findByOne( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysInstProperty while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysInstProperty++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pSysInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysInstProperty *)(pNode->pObject);
}


int compareForSysInstrumentIDIndexinSysMarginRate(const void *pV1, const void *pV2)
{
	CSysMarginRate *p1,*p2;
	p1=(CSysMarginRate *)pV1;
	p2=(CSysMarginRate *)pV2;
	switch (compare(p1->InstrumentID.getValue(),p2->InstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->ParticipantID.getValue(),p2->ParticipantID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->TradingRole.getValue(),p2->TradingRole.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysMarginRate=0;
#endif

CSysMarginRate *CSysMarginRateFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysMarginRate while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysMarginRate++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMarginRate *theSysMarginRate;
	compareObject.InstrumentID="";
	compareObject.ParticipantID="";
	compareObject.TradingRole="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMarginRate=(CSysMarginRate *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMarginRate;
}

CSysMarginRate *CSysMarginRateFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysMarginRate++;
#endif
	CSysMarginRate *theSysMarginRate;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysMarginRate=(CSysMarginRate *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMarginRate;
}

void CSysMarginRateFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysMarginRate=0;
#endif
CSysMarginRate *CSysMarginRateFactory::findByOne( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTradingRoleType&  TradingRole)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysMarginRate while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysMarginRate++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.TradingRole=TradingRole.getValue();
	pNode=pSysInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysMarginRate *)(pNode->pObject);
}


int compareForSysInstrumentIDIndexinSysPriceLimit(const void *pV1, const void *pV2)
{
	CSysPriceLimit *p1,*p2;
	p1=(CSysPriceLimit *)pV1;
	p2=(CSysPriceLimit *)pV2;
	switch (compare(p1->InstrumentID.getValue(),p2->InstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysPriceLimit=0;
#endif

CSysPriceLimit *CSysPriceLimitFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysPriceLimit while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysPriceLimit++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysPriceLimit *theSysPriceLimit;
	compareObject.InstrumentID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysPriceLimit=(CSysPriceLimit *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysPriceLimit;
}

CSysPriceLimit *CSysPriceLimitFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysPriceLimit++;
#endif
	CSysPriceLimit *theSysPriceLimit;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysPriceLimit=(CSysPriceLimit *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysPriceLimit;
}

void CSysPriceLimitFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysPriceLimit=0;
#endif
CSysPriceLimit *CSysPriceLimitFactory::findByOne( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysPriceLimit while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysPriceLimit++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pSysInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysPriceLimit *)(pNode->pObject);
}


int compareForSysInstrumentIDIndexinSysPartPosiLimit(const void *pV1, const void *pV2)
{
	CSysPartPosiLimit *p1,*p2;
	p1=(CSysPartPosiLimit *)pV1;
	p2=(CSysPartPosiLimit *)pV2;
	switch (compare(p1->InstrumentID.getValue(),p2->InstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->ParticipantID.getValue(),p2->ParticipantID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysPartPosiLimit=0;
#endif

CSysPartPosiLimit *CSysPartPosiLimitFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysPartPosiLimit while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysPartPosiLimit++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysPartPosiLimit *theSysPartPosiLimit;
	compareObject.InstrumentID="";
	compareObject.ParticipantID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysPartPosiLimit=(CSysPartPosiLimit *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysPartPosiLimit;
}

CSysPartPosiLimit *CSysPartPosiLimitFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysPartPosiLimit++;
#endif
	CSysPartPosiLimit *theSysPartPosiLimit;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysPartPosiLimit=(CSysPartPosiLimit *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysPartPosiLimit;
}

void CSysPartPosiLimitFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysPartPosiLimit=0;
#endif
CSysPartPosiLimit *CSysPartPosiLimitFactory::findByOne( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysPartPosiLimit while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysPartPosiLimit++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ParticipantID=ParticipantID.getValue();
	pNode=pSysInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysPartPosiLimit *)(pNode->pObject);
}


int compareForSysInstrumentIDIndexinSysClientPosiLimit(const void *pV1, const void *pV2)
{
	CSysClientPosiLimit *p1,*p2;
	p1=(CSysClientPosiLimit *)pV1;
	p2=(CSysClientPosiLimit *)pV2;
	switch (compare(p1->InstrumentID.getValue(),p2->InstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->ClientType.getValue(),p2->ClientType.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysClientPosiLimit=0;
#endif

CSysClientPosiLimit *CSysClientPosiLimitFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysClientPosiLimit while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysClientPosiLimit++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysClientPosiLimit *theSysClientPosiLimit;
	compareObject.InstrumentID="";
	compareObject.ClientType=CT_Person;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysClientPosiLimit=(CSysClientPosiLimit *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysClientPosiLimit;
}

CSysClientPosiLimit *CSysClientPosiLimitFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysClientPosiLimit++;
#endif
	CSysClientPosiLimit *theSysClientPosiLimit;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysClientPosiLimit=(CSysClientPosiLimit *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysClientPosiLimit;
}

void CSysClientPosiLimitFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysClientPosiLimit=0;
#endif
CSysClientPosiLimit *CSysClientPosiLimitFactory::findByOne( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientTypeType&  ClientType)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysClientPosiLimit while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysClientPosiLimit++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ClientType=ClientType.getValue();
	pNode=pSysInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysClientPosiLimit *)(pNode->pObject);
}


int compareForSysInstrumentIDIndexinSysSpecialPosiLimit(const void *pV1, const void *pV2)
{
	CSysSpecialPosiLimit *p1,*p2;
	p1=(CSysSpecialPosiLimit *)pV1;
	p2=(CSysSpecialPosiLimit *)pV2;
	switch (compare(p1->InstrumentID.getValue(),p2->InstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->ClientID.getValue(),p2->ClientID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysSpecialPosiLimit=0;
#endif

CSysSpecialPosiLimit *CSysSpecialPosiLimitFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysSpecialPosiLimit while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysSpecialPosiLimit++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysSpecialPosiLimit *theSysSpecialPosiLimit;
	compareObject.InstrumentID="";
	compareObject.ClientID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysSpecialPosiLimit=(CSysSpecialPosiLimit *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysSpecialPosiLimit;
}

CSysSpecialPosiLimit *CSysSpecialPosiLimitFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysSpecialPosiLimit++;
#endif
	CSysSpecialPosiLimit *theSysSpecialPosiLimit;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysSpecialPosiLimit=(CSysSpecialPosiLimit *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysSpecialPosiLimit;
}

void CSysSpecialPosiLimitFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysSpecialPosiLimit=0;
#endif
CSysSpecialPosiLimit *CSysSpecialPosiLimitFactory::findByOne( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientIDType&  ClientID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysSpecialPosiLimit while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysSpecialPosiLimit++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ClientID=ClientID.getValue();
	pNode=pSysInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysSpecialPosiLimit *)(pNode->pObject);
}


int compareForSysActionTimeIndexinSysTransactionChg(const void *pV1, const void *pV2)
{
	CSysTransactionChg *p1,*p2;
	p1=(CSysTransactionChg *)pV1;
	p2=(CSysTransactionChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysTransactionChg=0;
#endif

CSysTransactionChg *CSysTransactionChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysTransactionChg while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///记录所有的查询值
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysTransactionChg++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysTransactionChg *theSysTransactionChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysTransactionChg=(CSysTransactionChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysTransactionChg;
}

CSysTransactionChg *CSysTransactionChgFactory::findNextByActionTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysTransactionChg++;
#endif
	CSysTransactionChg *theSysTransactionChg;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysTransactionChg=(CSysTransactionChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysTransactionChg;
}

void CSysTransactionChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysClientChg(const void *pV1, const void *pV2)
{
	CSysClientChg *p1,*p2;
	p1=(CSysClientChg *)pV1;
	p2=(CSysClientChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysClientChg=0;
#endif

CSysClientChg *CSysClientChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysClientChg while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///记录所有的查询值
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysClientChg++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysClientChg *theSysClientChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysClientChg=(CSysClientChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysClientChg;
}

CSysClientChg *CSysClientChgFactory::findNextByActionTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysClientChg++;
#endif
	CSysClientChg *theSysClientChg;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysClientChg=(CSysClientChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysClientChg;
}

void CSysClientChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysPartClientChg(const void *pV1, const void *pV2)
{
	CSysPartClientChg *p1,*p2;
	p1=(CSysPartClientChg *)pV1;
	p2=(CSysPartClientChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysPartClientChg=0;
#endif

CSysPartClientChg *CSysPartClientChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysPartClientChg while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///记录所有的查询值
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysPartClientChg++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysPartClientChg *theSysPartClientChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysPartClientChg=(CSysPartClientChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysPartClientChg;
}

CSysPartClientChg *CSysPartClientChgFactory::findNextByActionTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysPartClientChg++;
#endif
	CSysPartClientChg *theSysPartClientChg;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysPartClientChg=(CSysPartClientChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysPartClientChg;
}

void CSysPartClientChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysPosiLimitChg(const void *pV1, const void *pV2)
{
	CSysPosiLimitChg *p1,*p2;
	p1=(CSysPosiLimitChg *)pV1;
	p2=(CSysPosiLimitChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysPosiLimitChg=0;
#endif

CSysPosiLimitChg *CSysPosiLimitChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysPosiLimitChg while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///记录所有的查询值
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysPosiLimitChg++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysPosiLimitChg *theSysPosiLimitChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysPosiLimitChg=(CSysPosiLimitChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysPosiLimitChg;
}

CSysPosiLimitChg *CSysPosiLimitChgFactory::findNextByActionTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysPosiLimitChg++;
#endif
	CSysPosiLimitChg *theSysPosiLimitChg;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysPosiLimitChg=(CSysPosiLimitChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysPosiLimitChg;
}

void CSysPosiLimitChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysClientPosiLimitChg(const void *pV1, const void *pV2)
{
	CSysClientPosiLimitChg *p1,*p2;
	p1=(CSysClientPosiLimitChg *)pV1;
	p2=(CSysClientPosiLimitChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysClientPosiLimitChg=0;
#endif

CSysClientPosiLimitChg *CSysClientPosiLimitChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysClientPosiLimitChg while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///记录所有的查询值
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysClientPosiLimitChg++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysClientPosiLimitChg *theSysClientPosiLimitChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysClientPosiLimitChg=(CSysClientPosiLimitChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysClientPosiLimitChg;
}

CSysClientPosiLimitChg *CSysClientPosiLimitChgFactory::findNextByActionTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysClientPosiLimitChg++;
#endif
	CSysClientPosiLimitChg *theSysClientPosiLimitChg;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysClientPosiLimitChg=(CSysClientPosiLimitChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysClientPosiLimitChg;
}

void CSysClientPosiLimitChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysSpecPosiLimitChg(const void *pV1, const void *pV2)
{
	CSysSpecPosiLimitChg *p1,*p2;
	p1=(CSysSpecPosiLimitChg *)pV1;
	p2=(CSysSpecPosiLimitChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysSpecPosiLimitChg=0;
#endif

CSysSpecPosiLimitChg *CSysSpecPosiLimitChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysSpecPosiLimitChg while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///记录所有的查询值
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysSpecPosiLimitChg++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysSpecPosiLimitChg *theSysSpecPosiLimitChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysSpecPosiLimitChg=(CSysSpecPosiLimitChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysSpecPosiLimitChg;
}

CSysSpecPosiLimitChg *CSysSpecPosiLimitChgFactory::findNextByActionTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysSpecPosiLimitChg++;
#endif
	CSysSpecPosiLimitChg *theSysSpecPosiLimitChg;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysSpecPosiLimitChg=(CSysSpecPosiLimitChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysSpecPosiLimitChg;
}

void CSysSpecPosiLimitChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysHedgeDetailChg(const void *pV1, const void *pV2)
{
	CSysHedgeDetailChg *p1,*p2;
	p1=(CSysHedgeDetailChg *)pV1;
	p2=(CSysHedgeDetailChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysHedgeDetailChg=0;
#endif

CSysHedgeDetailChg *CSysHedgeDetailChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysHedgeDetailChg while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///记录所有的查询值
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysHedgeDetailChg++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysHedgeDetailChg *theSysHedgeDetailChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysHedgeDetailChg=(CSysHedgeDetailChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysHedgeDetailChg;
}

CSysHedgeDetailChg *CSysHedgeDetailChgFactory::findNextByActionTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysHedgeDetailChg++;
#endif
	CSysHedgeDetailChg *theSysHedgeDetailChg;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysHedgeDetailChg=(CSysHedgeDetailChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysHedgeDetailChg;
}

void CSysHedgeDetailChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysParticipantChg(const void *pV1, const void *pV2)
{
	CSysParticipantChg *p1,*p2;
	p1=(CSysParticipantChg *)pV1;
	p2=(CSysParticipantChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysParticipantChg=0;
#endif

CSysParticipantChg *CSysParticipantChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysParticipantChg while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///记录所有的查询值
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysParticipantChg++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysParticipantChg *theSysParticipantChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysParticipantChg=(CSysParticipantChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysParticipantChg;
}

CSysParticipantChg *CSysParticipantChgFactory::findNextByActionTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysParticipantChg++;
#endif
	CSysParticipantChg *theSysParticipantChg;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysParticipantChg=(CSysParticipantChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysParticipantChg;
}

void CSysParticipantChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysMarginRateChg(const void *pV1, const void *pV2)
{
	CSysMarginRateChg *p1,*p2;
	p1=(CSysMarginRateChg *)pV1;
	p2=(CSysMarginRateChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysMarginRateChg=0;
#endif

CSysMarginRateChg *CSysMarginRateChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysMarginRateChg while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///记录所有的查询值
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysMarginRateChg++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMarginRateChg *theSysMarginRateChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMarginRateChg=(CSysMarginRateChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMarginRateChg;
}

CSysMarginRateChg *CSysMarginRateChgFactory::findNextByActionTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysMarginRateChg++;
#endif
	CSysMarginRateChg *theSysMarginRateChg;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysMarginRateChg=(CSysMarginRateChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMarginRateChg;
}

void CSysMarginRateChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysUserIpChg(const void *pV1, const void *pV2)
{
	CSysUserIpChg *p1,*p2;
	p1=(CSysUserIpChg *)pV1;
	p2=(CSysUserIpChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysUserIpChg=0;
#endif

CSysUserIpChg *CSysUserIpChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysUserIpChg while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///记录所有的查询值
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysUserIpChg++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysUserIpChg *theSysUserIpChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysUserIpChg=(CSysUserIpChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysUserIpChg;
}

CSysUserIpChg *CSysUserIpChgFactory::findNextByActionTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysUserIpChg++;
#endif
	CSysUserIpChg *theSysUserIpChg;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysUserIpChg=(CSysUserIpChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysUserIpChg;
}

void CSysUserIpChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysPartInstrumentIndexinSysPartTrade(const void *pV1, const void *pV2)
{
	CSysPartTrade *p1,*p2;
	p1=(CSysPartTrade *)pV1;
	p2=(CSysPartTrade *)pV2;
	switch (compare(p1->ParticipantID.getValue(),p2->ParticipantID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->InstrumentID.getValue(),p2->InstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysPartTrade=0;
#endif

CSysPartTrade *CSysPartTradeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysPartTrade while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysPartTrade++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysPartTrade *theSysPartTrade;
	compareObject.ParticipantID="";
	compareObject.InstrumentID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysPartInstrumentIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysPartTrade=(CSysPartTrade *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysPartTrade;
}

CSysPartTrade *CSysPartTradeFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysPartTrade++;
#endif
	CSysPartTrade *theSysPartTrade;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysPartInstrumentIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysPartTrade=(CSysPartTrade *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysPartTrade;
}

void CSysPartTradeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysPartTrade=0;
#endif
CSysPartTrade *CSysPartTradeFactory::findByOne( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysPartTrade while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysPartTrade++;
#endif
	CAVLNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pSysPartInstrumentIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysPartTrade *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysMdbObjectAttr(const void *pV1, const void *pV2)
{
	CSysMdbObjectAttr *p1,*p2;
	p1=(CSysMdbObjectAttr *)pV1;
	p2=(CSysMdbObjectAttr *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByIDTypeForSysMdbObjectAttr=0;
#endif

CSysMdbObjectAttr *CSysMdbObjectAttrFactory::startFindByIDType( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIDType of CSysMdbObjectAttr while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByIDType!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIDType();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByIDType= SubcriberID.getValue();
	queryMonDateInSearchByIDType= MonDate.getValue();
	queryMonTimeInSearchByIDType= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbObjectAttr++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbObjectAttr *theSysMdbObjectAttr;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByIDType=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbObjectAttr=(CSysMdbObjectAttr *)(pLastFoundInSearchByIDType->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbObjectAttr->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbObjectAttr;
}

CSysMdbObjectAttr *CSysMdbObjectAttrFactory::findNextByIDType(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbObjectAttr++;
#endif
	CSysMdbObjectAttr *theSysMdbObjectAttr;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByIDType=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByIDType);
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	theSysMdbObjectAttr=(CSysMdbObjectAttr *)(pLastFoundInSearchByIDType->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbObjectAttr->SubcriberID,querySubcriberIDInSearchByIDType))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbObjectAttr;
}

void CSysMdbObjectAttrFactory::endFindByIDType(void)
{
	pLastFoundInSearchByIDType=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbObjectAttr=0;
#endif

CSysMdbObjectAttr *CSysMdbObjectAttrFactory::startFindByDsc( const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbObjectAttr while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByDsc= SubcriberID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbObjectAttr++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbObjectAttr *theSysMdbObjectAttr;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbObjectAttr=(CSysMdbObjectAttr *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbObjectAttr->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbObjectAttr;
}

CSysMdbObjectAttr *CSysMdbObjectAttrFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbObjectAttr++;
#endif
	CSysMdbObjectAttr *theSysMdbObjectAttr;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbObjectAttr=(CSysMdbObjectAttr *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbObjectAttr->SubcriberID,querySubcriberIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbObjectAttr;
}

void CSysMdbObjectAttrFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysMdbObjectAttr=0;
#endif
CSysMdbObjectAttr *CSysMdbObjectAttrFactory::findByOne( const CReadOnlyVolumeType&  SubcriberID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysMdbObjectAttr while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysMdbObjectAttr++;
#endif
	CAVLNode *pNode;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysMdbObjectAttr *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbObjectAttr=0;
#endif

CSysMdbObjectAttr *CSysMdbObjectAttrFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbObjectAttr while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbObjectAttr++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbObjectAttr *theSysMdbObjectAttr;
	compareObject.SubcriberID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbObjectAttr=(CSysMdbObjectAttr *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbObjectAttr;
}

CSysMdbObjectAttr *CSysMdbObjectAttrFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbObjectAttr++;
#endif
	CSysMdbObjectAttr *theSysMdbObjectAttr;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbObjectAttr=(CSysMdbObjectAttr *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbObjectAttr;
}

void CSysMdbObjectAttrFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbObjectAttr=0;
#endif

CSysMdbObjectAttr *CSysMdbObjectAttrFactory::startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbObjectAttr while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByDataDelete= SubcriberID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbObjectAttr++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbObjectAttr *theSysMdbObjectAttr;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbObjectAttr=(CSysMdbObjectAttr *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbObjectAttr->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbObjectAttr;
}

CSysMdbObjectAttr *CSysMdbObjectAttrFactory::findNextByDataDelete(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbObjectAttr++;
#endif
	CSysMdbObjectAttr *theSysMdbObjectAttr;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbObjectAttr=(CSysMdbObjectAttr *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbObjectAttr->SubcriberID,querySubcriberIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbObjectAttr;
}

void CSysMdbObjectAttrFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysIDTypeIndexinSysMdbSyslogInfo(const void *pV1, const void *pV2)
{
	CSysMdbSyslogInfo *p1,*p2;
	p1=(CSysMdbSyslogInfo *)pV1;
	p2=(CSysMdbSyslogInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->AttrType.getValue(),p2->AttrType.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbSyslogInfo(const void *pV1, const void *pV2)
{
	CSysMdbSyslogInfo *p1,*p2;
	p1=(CSysMdbSyslogInfo *)pV1;
	p2=(CSysMdbSyslogInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->AttrType.getValue(),p2->AttrType.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysMdbSyslogInfo=0;
#endif

CSysMdbSyslogInfo *CSysMdbSyslogInfoFactory::startFindByAll( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyVolumeType& AttrType)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysMdbSyslogInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值
	queryObjectIDInSearchByAll= ObjectID.getValue();
	queryAttrTypeInSearchByAll= AttrType.getValue();

#ifdef COUNT_SEARCH
	multiFindByAllForSysMdbSyslogInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbSyslogInfo *theSysMdbSyslogInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.AttrType=AttrType.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbSyslogInfo=(CSysMdbSyslogInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbSyslogInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByAll=NULL;
		return NULL;
	}
	if (compare(theSysMdbSyslogInfo->AttrType.getValue(),AttrType.getValue()))
	{
		pLastFoundInSearchByAll=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbSyslogInfo;
}

CSysMdbSyslogInfo *CSysMdbSyslogInfoFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysMdbSyslogInfo++;
#endif
	CSysMdbSyslogInfo *theSysMdbSyslogInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysMdbSyslogInfo=(CSysMdbSyslogInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbSyslogInfo->ObjectID,queryObjectIDInSearchByAll))
	{
		pLastFoundInSearchByAll=NULL;
		return NULL;
	}
	if (compare(theSysMdbSyslogInfo->AttrType,queryAttrTypeInSearchByAll))
	{
		pLastFoundInSearchByAll=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbSyslogInfo;
}

void CSysMdbSyslogInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbSyslogInfo=0;
#endif

CSysMdbSyslogInfo *CSysMdbSyslogInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbSyslogInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbSyslogInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbSyslogInfo *theSysMdbSyslogInfo;
	compareObject.ObjectID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbSyslogInfo=(CSysMdbSyslogInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbSyslogInfo;
}

CSysMdbSyslogInfo *CSysMdbSyslogInfoFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbSyslogInfo++;
#endif
	CSysMdbSyslogInfo *theSysMdbSyslogInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbSyslogInfo=(CSysMdbSyslogInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbSyslogInfo;
}

void CSysMdbSyslogInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbSyslogInfo=0;
#endif

CSysMdbSyslogInfo *CSysMdbSyslogInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyVolumeType& AttrType,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbSyslogInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///记录所有的查询值
	queryObjectIDInSearchByDataDelete= ObjectID.getValue();
	queryAttrTypeInSearchByDataDelete= AttrType.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbSyslogInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbSyslogInfo *theSysMdbSyslogInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.AttrType=AttrType.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDataDelete=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbSyslogInfo=(CSysMdbSyslogInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbSyslogInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}
	if (compare(theSysMdbSyslogInfo->AttrType.getValue(),AttrType.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbSyslogInfo;
}

CSysMdbSyslogInfo *CSysMdbSyslogInfoFactory::findNextByDataDelete(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbSyslogInfo++;
#endif
	CSysMdbSyslogInfo *theSysMdbSyslogInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDataDelete=pDecIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbSyslogInfo=(CSysMdbSyslogInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbSyslogInfo->ObjectID,queryObjectIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}
	if (compare(theSysMdbSyslogInfo->AttrType,queryAttrTypeInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbSyslogInfo;
}

void CSysMdbSyslogInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysHostNameIndexinSysUserInfo(const void *pV1, const void *pV2)
{
	CSysUserInfo *p1,*p2;
	p1=(CSysUserInfo *)pV1;
	p2=(CSysUserInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysUserInfo(const void *pV1, const void *pV2)
{
	CSysUserInfo *p1,*p2;
	p1=(CSysUserInfo *)pV1;
	p2=(CSysUserInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysUserInfo=0;
#endif

CSysUserInfo *CSysUserInfoFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& ObjectID,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysUserInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	queryObjectIDInSearchByHostName= ObjectID.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysUserInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysUserInfo *theSysUserInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysUserInfo=(CSysUserInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysUserInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysUserInfo;
}

CSysUserInfo *CSysUserInfoFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysUserInfo++;
#endif
	CSysUserInfo *theSysUserInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysUserInfo=(CSysUserInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysUserInfo->ObjectID,queryObjectIDInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysUserInfo;
}

void CSysUserInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysUserInfo=0;
#endif

CSysUserInfo *CSysUserInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysUserInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysUserInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysUserInfo *theSysUserInfo;
	compareObject.ObjectID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysUserInfo=(CSysUserInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysUserInfo;
}

CSysUserInfo *CSysUserInfoFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysUserInfo++;
#endif
	CSysUserInfo *theSysUserInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysUserInfo=(CSysUserInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysUserInfo;
}

void CSysUserInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysUserInfo=0;
#endif

CSysUserInfo *CSysUserInfoFactory::startFindByDsc( const CReadOnlyTypeObjectIDType& ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysUserInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	queryObjectIDInSearchByDsc= ObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysUserInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysUserInfo *theSysUserInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysUserInfo=(CSysUserInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysUserInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysUserInfo;
}

CSysUserInfo *CSysUserInfoFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysUserInfo++;
#endif
	CSysUserInfo *theSysUserInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysUserInfo=(CSysUserInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysUserInfo->ObjectID,queryObjectIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysUserInfo;
}

void CSysUserInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}

int compareForSysHostNameIndexinSysOnlineUserInfo(const void *pV1, const void *pV2)
{
	CSysOnlineUserInfo *p1,*p2;
	p1=(CSysOnlineUserInfo *)pV1;
	p2=(CSysOnlineUserInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysOnlineUserInfo(const void *pV1, const void *pV2)
{
	CSysOnlineUserInfo *p1,*p2;
	p1=(CSysOnlineUserInfo *)pV1;
	p2=(CSysOnlineUserInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysOnlineUserInfo=0;
#endif

CSysOnlineUserInfo *CSysOnlineUserInfoFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& ObjectID,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysOnlineUserInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	queryObjectIDInSearchByHostName= ObjectID.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysOnlineUserInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysOnlineUserInfo *theSysOnlineUserInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysOnlineUserInfo=(CSysOnlineUserInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysOnlineUserInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysOnlineUserInfo;
}

CSysOnlineUserInfo *CSysOnlineUserInfoFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysOnlineUserInfo++;
#endif
	CSysOnlineUserInfo *theSysOnlineUserInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysOnlineUserInfo=(CSysOnlineUserInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysOnlineUserInfo->ObjectID,queryObjectIDInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysOnlineUserInfo;
}

void CSysOnlineUserInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysOnlineUserInfo=0;
#endif

CSysOnlineUserInfo *CSysOnlineUserInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysOnlineUserInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysOnlineUserInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysOnlineUserInfo *theSysOnlineUserInfo;
	compareObject.ObjectID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysOnlineUserInfo=(CSysOnlineUserInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysOnlineUserInfo;
}

CSysOnlineUserInfo *CSysOnlineUserInfoFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysOnlineUserInfo++;
#endif
	CSysOnlineUserInfo *theSysOnlineUserInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysOnlineUserInfo=(CSysOnlineUserInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysOnlineUserInfo;
}

void CSysOnlineUserInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysOnlineUserInfo=0;
#endif

CSysOnlineUserInfo *CSysOnlineUserInfoFactory::startFindByDsc( const CReadOnlyTypeObjectIDType& ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysOnlineUserInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	queryObjectIDInSearchByDsc= ObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysOnlineUserInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysOnlineUserInfo *theSysOnlineUserInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysOnlineUserInfo=(CSysOnlineUserInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysOnlineUserInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysOnlineUserInfo;
}

CSysOnlineUserInfo *CSysOnlineUserInfoFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysOnlineUserInfo++;
#endif
	CSysOnlineUserInfo *theSysOnlineUserInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysOnlineUserInfo=(CSysOnlineUserInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysOnlineUserInfo->ObjectID,queryObjectIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysOnlineUserInfo;
}

void CSysOnlineUserInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}

int compareForSysHostNameIndexinSysWarningEvent(const void *pV1, const void *pV2)
{
	CSysWarningEvent *p1,*p2;
	p1=(CSysWarningEvent *)pV1;
	p2=(CSysWarningEvent *)pV2;
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->OccurTime.getValue(),p2->OccurTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysEventIdIndexinSysWarningEvent(const void *pV1, const void *pV2)
{
	CSysWarningEvent *p1,*p2;
	p1=(CSysWarningEvent *)pV1;
	p2=(CSysWarningEvent *)pV2;
	switch (compare(p1->EvendID.getValue(),p2->EvendID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByTimeForSysWarningEvent=0;
#endif

CSysWarningEvent *CSysWarningEventFactory::startFindByTime( const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& OccurTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTime of CSysWarningEvent while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTime();
	}

	///记录所有的查询值
	queryMonDateInSearchByTime= MonDate.getValue();
	queryOccurTimeInSearchByTime= OccurTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByTimeForSysWarningEvent++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysWarningEvent *theSysWarningEvent;
	compareObject.MonDate=MonDate.getValue();
	compareObject.OccurTime=OccurTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByTime=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysWarningEvent=(CSysWarningEvent *)(pLastFoundInSearchByTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysWarningEvent;
}

CSysWarningEvent *CSysWarningEventFactory::findNextByTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTimeForSysWarningEvent++;
#endif
	CSysWarningEvent *theSysWarningEvent;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByTime=pSysHostNameIndex->getNextNode(pLastFoundInSearchByTime);
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	theSysWarningEvent=(CSysWarningEvent *)(pLastFoundInSearchByTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysWarningEvent;
}

void CSysWarningEventFactory::endFindByTime(void)
{
	pLastFoundInSearchByTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByAllForSysWarningEvent=0;
#endif

CSysWarningEvent *CSysWarningEventFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysWarningEvent while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysWarningEvent++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysWarningEvent *theSysWarningEvent;
	compareObject.MonDate="zzzzzzzz";
	compareObject.OccurTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysWarningEvent=(CSysWarningEvent *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysWarningEvent;
}

CSysWarningEvent *CSysWarningEventFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysWarningEvent++;
#endif
	CSysWarningEvent *theSysWarningEvent;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysWarningEvent=(CSysWarningEvent *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysWarningEvent;
}

void CSysWarningEventFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByEvendIDForSysWarningEvent=0;
#endif
CSysWarningEvent *CSysWarningEventFactory::findByEvendID( const CReadOnlyVolumeType&  EvendID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByEvendID of CSysWarningEvent while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByEvendIDForSysWarningEvent++;
#endif
	CAVLNode *pNode;
	compareObject.EvendID=EvendID.getValue();
	pNode=pSysEventIdIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysWarningEvent *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByEvendIDsForSysWarningEvent=0;
#endif

CSysWarningEvent *CSysWarningEventFactory::startFindByEvendIDs( const CReadOnlyVolumeType& EvendID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByEvendIDs of CSysWarningEvent while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByEvendIDs!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByEvendIDs();
	}

	///记录所有的查询值
	queryEvendIDInSearchByEvendIDs= EvendID.getValue();

#ifdef COUNT_SEARCH
	multiFindByEvendIDsForSysWarningEvent++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysWarningEvent *theSysWarningEvent;
	compareObject.EvendID=EvendID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByEvendIDs=pSysEventIdIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByEvendIDs==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysWarningEvent=(CSysWarningEvent *)(pLastFoundInSearchByEvendIDs->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysWarningEvent->EvendID.getValue(),EvendID.getValue()))
	{
		pLastFoundInSearchByEvendIDs=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysWarningEvent;
}

CSysWarningEvent *CSysWarningEventFactory::findNextByEvendIDs(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByEvendIDs==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByEvendIDsForSysWarningEvent++;
#endif
	CSysWarningEvent *theSysWarningEvent;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByEvendIDs=pSysEventIdIndex->getNextNode(pLastFoundInSearchByEvendIDs);
	if (pLastFoundInSearchByEvendIDs==NULL)
	{
		return NULL;
	}

	theSysWarningEvent=(CSysWarningEvent *)(pLastFoundInSearchByEvendIDs->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysWarningEvent->EvendID,queryEvendIDInSearchByEvendIDs))
	{
		pLastFoundInSearchByEvendIDs=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysWarningEvent;
}

void CSysWarningEventFactory::endFindByEvendIDs(void)
{
	pLastFoundInSearchByEvendIDs=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysWarningEvent=0;
#endif

CSysWarningEvent *CSysWarningEventFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysWarningEvent while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysWarningEvent++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysWarningEvent *theSysWarningEvent;
	compareObject.EvendID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysEventIdIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysWarningEvent=(CSysWarningEvent *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysWarningEvent;
}

CSysWarningEvent *CSysWarningEventFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysWarningEvent++;
#endif
	CSysWarningEvent *theSysWarningEvent;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysEventIdIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysWarningEvent=(CSysWarningEvent *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysWarningEvent;
}

void CSysWarningEventFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinSysWarningQuery(const void *pV1, const void *pV2)
{
	CSysWarningQuery *p1,*p2;
	p1=(CSysWarningQuery *)pV1;
	p2=(CSysWarningQuery *)pV2;
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysEventIdIndexinSysWarningQuery(const void *pV1, const void *pV2)
{
	CSysWarningQuery *p1,*p2;
	p1=(CSysWarningQuery *)pV1;
	p2=(CSysWarningQuery *)pV2;
	switch (compare(p1->EvendID.getValue(),p2->EvendID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByTimeForSysWarningQuery=0;
#endif

CSysWarningQuery *CSysWarningQueryFactory::startFindByTime( const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTime of CSysWarningQuery while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTime();
	}

	///记录所有的查询值
	queryMonDateInSearchByTime= MonDate.getValue();
	queryMonTimeInSearchByTime= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByTimeForSysWarningQuery++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysWarningQuery *theSysWarningQuery;
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByTime=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysWarningQuery=(CSysWarningQuery *)(pLastFoundInSearchByTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysWarningQuery;
}

CSysWarningQuery *CSysWarningQueryFactory::findNextByTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTimeForSysWarningQuery++;
#endif
	CSysWarningQuery *theSysWarningQuery;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByTime=pSysHostNameIndex->getNextNode(pLastFoundInSearchByTime);
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	theSysWarningQuery=(CSysWarningQuery *)(pLastFoundInSearchByTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysWarningQuery;
}

void CSysWarningQueryFactory::endFindByTime(void)
{
	pLastFoundInSearchByTime=NULL;
}


#ifdef COUNT_SEARCH
int findByEvendIDForSysWarningQuery=0;
#endif
CSysWarningQuery *CSysWarningQueryFactory::findByEvendID( const CReadOnlyVolumeType&  EvendID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByEvendID of CSysWarningQuery while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByEvendIDForSysWarningQuery++;
#endif
	CAVLNode *pNode;
	compareObject.EvendID=EvendID.getValue();
	pNode=pSysEventIdIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysWarningQuery *)(pNode->pObject);
}


int compareForSysTimeIndexinSyslogEvent(const void *pV1, const void *pV2)
{
	CSyslogEvent *p1,*p2;
	p1=(CSyslogEvent *)pV1;
	p2=(CSyslogEvent *)pV2;
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->OccurTime.getValue(),p2->OccurTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysEventIdIndexinSyslogEvent(const void *pV1, const void *pV2)
{
	CSyslogEvent *p1,*p2;
	p1=(CSyslogEvent *)pV1;
	p2=(CSyslogEvent *)pV2;
	switch (compare(p1->EvendID.getValue(),p2->EvendID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByTimeForSyslogEvent=0;
#endif

CSyslogEvent *CSyslogEventFactory::startFindByTime( const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& OccurTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTime of CSyslogEvent while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTime();
	}

	///记录所有的查询值
	queryMonDateInSearchByTime= MonDate.getValue();
	queryOccurTimeInSearchByTime= OccurTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByTimeForSyslogEvent++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSyslogEvent *theSyslogEvent;
	compareObject.MonDate=MonDate.getValue();
	compareObject.OccurTime=OccurTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByTime=pSysTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSyslogEvent=(CSyslogEvent *)(pLastFoundInSearchByTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSyslogEvent;
}

CSyslogEvent *CSyslogEventFactory::findNextByTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTimeForSyslogEvent++;
#endif
	CSyslogEvent *theSyslogEvent;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByTime=pSysTimeIndex->getNextNode(pLastFoundInSearchByTime);
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	theSyslogEvent=(CSyslogEvent *)(pLastFoundInSearchByTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSyslogEvent;
}

void CSyslogEventFactory::endFindByTime(void)
{
	pLastFoundInSearchByTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSyslogEvent=0;
#endif

CSyslogEvent *CSyslogEventFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSyslogEvent while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSyslogEvent++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSyslogEvent *theSyslogEvent;
	compareObject.MonDate="zzzzzzzz";
	compareObject.OccurTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSyslogEvent=(CSyslogEvent *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSyslogEvent;
}

CSyslogEvent *CSyslogEventFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSyslogEvent++;
#endif
	CSyslogEvent *theSyslogEvent;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysTimeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSyslogEvent=(CSyslogEvent *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSyslogEvent;
}

void CSyslogEventFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByAllForSyslogEvent=0;
#endif

CSyslogEvent *CSyslogEventFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSyslogEvent while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSyslogEvent++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSyslogEvent *theSyslogEvent;
	compareObject.MonDate="zzzzzzzz";
	compareObject.OccurTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSyslogEvent=(CSyslogEvent *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSyslogEvent;
}

CSyslogEvent *CSyslogEventFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSyslogEvent++;
#endif
	CSyslogEvent *theSyslogEvent;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysTimeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSyslogEvent=(CSyslogEvent *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSyslogEvent;
}

void CSyslogEventFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByEvendIDForSyslogEvent=0;
#endif
CSyslogEvent *CSyslogEventFactory::findByEvendID( const CReadOnlyVolumeType&  EvendID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByEvendID of CSyslogEvent while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByEvendIDForSyslogEvent++;
#endif
	CAVLNode *pNode;
	compareObject.EvendID=EvendID.getValue();
	pNode=pSysEventIdIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSyslogEvent *)(pNode->pObject);
}


int compareForSysTimeIndexinSysEventDescrip(const void *pV1, const void *pV2)
{
	CSysEventDescrip *p1,*p2;
	p1=(CSysEventDescrip *)pV1;
	p2=(CSysEventDescrip *)pV2;
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysEventIdIndexinSysEventDescrip(const void *pV1, const void *pV2)
{
	CSysEventDescrip *p1,*p2;
	p1=(CSysEventDescrip *)pV1;
	p2=(CSysEventDescrip *)pV2;
	switch (compare(p1->EventDesID.getValue(),p2->EventDesID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByTimeForSysEventDescrip=0;
#endif

CSysEventDescrip *CSysEventDescripFactory::startFindByTime( const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTime of CSysEventDescrip while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTime();
	}

	///记录所有的查询值
	queryMonDateInSearchByTime= MonDate.getValue();
	queryMonTimeInSearchByTime= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByTimeForSysEventDescrip++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysEventDescrip *theSysEventDescrip;
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByTime=pSysTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysEventDescrip=(CSysEventDescrip *)(pLastFoundInSearchByTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysEventDescrip;
}

CSysEventDescrip *CSysEventDescripFactory::findNextByTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTimeForSysEventDescrip++;
#endif
	CSysEventDescrip *theSysEventDescrip;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByTime=pSysTimeIndex->getNextNode(pLastFoundInSearchByTime);
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	theSysEventDescrip=(CSysEventDescrip *)(pLastFoundInSearchByTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysEventDescrip;
}

void CSysEventDescripFactory::endFindByTime(void)
{
	pLastFoundInSearchByTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysEventDescrip=0;
#endif

CSysEventDescrip *CSysEventDescripFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysEventDescrip while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysEventDescrip++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysEventDescrip *theSysEventDescrip;
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysEventDescrip=(CSysEventDescrip *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysEventDescrip;
}

CSysEventDescrip *CSysEventDescripFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysEventDescrip++;
#endif
	CSysEventDescrip *theSysEventDescrip;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysTimeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysEventDescrip=(CSysEventDescrip *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysEventDescrip;
}

void CSysEventDescripFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByAllForSysEventDescrip=0;
#endif

CSysEventDescrip *CSysEventDescripFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysEventDescrip while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysEventDescrip++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysEventDescrip *theSysEventDescrip;
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysEventDescrip=(CSysEventDescrip *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysEventDescrip;
}

CSysEventDescrip *CSysEventDescripFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysEventDescrip++;
#endif
	CSysEventDescrip *theSysEventDescrip;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysTimeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysEventDescrip=(CSysEventDescrip *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysEventDescrip;
}

void CSysEventDescripFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByEvendIDForSysEventDescrip=0;
#endif
CSysEventDescrip *CSysEventDescripFactory::findByEvendID( const CReadOnlyEventDesIDType&  EventDesID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByEvendID of CSysEventDescrip while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByEvendIDForSysEventDescrip++;
#endif
	CAVLNode *pNode;
	compareObject.EventDesID=EventDesID.getValue();
	pNode=pSysEventIdIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysEventDescrip *)(pNode->pObject);
}


int compareForSysHostNameIndexinRspQryHostEnvCommon(const void *pV1, const void *pV2)
{
	CRspQryHostEnvCommon *p1,*p2;
	p1=(CRspQryHostEnvCommon *)pV1;
	p2=(CRspQryHostEnvCommon *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForRspQryHostEnvCommon=0;
#endif

CRspQryHostEnvCommon *CRspQryHostEnvCommonFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CRspQryHostEnvCommon while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	queryHostNameInSearchByHostName= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvCommon++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CRspQryHostEnvCommon *theRspQryHostEnvCommon;
	compareObject.HostName=HostName.getValue();
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theRspQryHostEnvCommon=(CRspQryHostEnvCommon *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theRspQryHostEnvCommon->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theRspQryHostEnvCommon;
}

CRspQryHostEnvCommon *CRspQryHostEnvCommonFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvCommon++;
#endif
	CRspQryHostEnvCommon *theRspQryHostEnvCommon;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvCommon=(CRspQryHostEnvCommon *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theRspQryHostEnvCommon->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theRspQryHostEnvCommon;
}

void CRspQryHostEnvCommonFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForRspQryHostEnvCommon=0;
#endif

CRspQryHostEnvCommon *CRspQryHostEnvCommonFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CRspQryHostEnvCommon while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvCommon++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CRspQryHostEnvCommon *theRspQryHostEnvCommon;
	compareObject.HostName="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theRspQryHostEnvCommon=(CRspQryHostEnvCommon *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theRspQryHostEnvCommon;
}

CRspQryHostEnvCommon *CRspQryHostEnvCommonFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvCommon++;
#endif
	CRspQryHostEnvCommon *theRspQryHostEnvCommon;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvCommon=(CRspQryHostEnvCommon *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theRspQryHostEnvCommon;
}

void CRspQryHostEnvCommonFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinRspQryHostEnvLan(const void *pV1, const void *pV2)
{
	CRspQryHostEnvLan *p1,*p2;
	p1=(CRspQryHostEnvLan *)pV1;
	p2=(CRspQryHostEnvLan *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForRspQryHostEnvLan=0;
#endif

CRspQryHostEnvLan *CRspQryHostEnvLanFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CRspQryHostEnvLan while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	queryHostNameInSearchByHostName= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvLan++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CRspQryHostEnvLan *theRspQryHostEnvLan;
	compareObject.HostName=HostName.getValue();
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theRspQryHostEnvLan=(CRspQryHostEnvLan *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theRspQryHostEnvLan->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theRspQryHostEnvLan;
}

CRspQryHostEnvLan *CRspQryHostEnvLanFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvLan++;
#endif
	CRspQryHostEnvLan *theRspQryHostEnvLan;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvLan=(CRspQryHostEnvLan *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theRspQryHostEnvLan->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theRspQryHostEnvLan;
}

void CRspQryHostEnvLanFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForRspQryHostEnvLan=0;
#endif

CRspQryHostEnvLan *CRspQryHostEnvLanFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CRspQryHostEnvLan while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvLan++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CRspQryHostEnvLan *theRspQryHostEnvLan;
	compareObject.HostName="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theRspQryHostEnvLan=(CRspQryHostEnvLan *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theRspQryHostEnvLan;
}

CRspQryHostEnvLan *CRspQryHostEnvLanFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvLan++;
#endif
	CRspQryHostEnvLan *theRspQryHostEnvLan;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvLan=(CRspQryHostEnvLan *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theRspQryHostEnvLan;
}

void CRspQryHostEnvLanFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinRspQryHostEnvStorage(const void *pV1, const void *pV2)
{
	CRspQryHostEnvStorage *p1,*p2;
	p1=(CRspQryHostEnvStorage *)pV1;
	p2=(CRspQryHostEnvStorage *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForRspQryHostEnvStorage=0;
#endif

CRspQryHostEnvStorage *CRspQryHostEnvStorageFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CRspQryHostEnvStorage while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	queryHostNameInSearchByHostName= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvStorage++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CRspQryHostEnvStorage *theRspQryHostEnvStorage;
	compareObject.HostName=HostName.getValue();
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theRspQryHostEnvStorage=(CRspQryHostEnvStorage *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theRspQryHostEnvStorage->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theRspQryHostEnvStorage;
}

CRspQryHostEnvStorage *CRspQryHostEnvStorageFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvStorage++;
#endif
	CRspQryHostEnvStorage *theRspQryHostEnvStorage;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvStorage=(CRspQryHostEnvStorage *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theRspQryHostEnvStorage->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theRspQryHostEnvStorage;
}

void CRspQryHostEnvStorageFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForRspQryHostEnvStorage=0;
#endif

CRspQryHostEnvStorage *CRspQryHostEnvStorageFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CRspQryHostEnvStorage while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvStorage++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CRspQryHostEnvStorage *theRspQryHostEnvStorage;
	compareObject.HostName="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theRspQryHostEnvStorage=(CRspQryHostEnvStorage *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theRspQryHostEnvStorage;
}

CRspQryHostEnvStorage *CRspQryHostEnvStorageFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvStorage++;
#endif
	CRspQryHostEnvStorage *theRspQryHostEnvStorage;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvStorage=(CRspQryHostEnvStorage *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theRspQryHostEnvStorage;
}

void CRspQryHostEnvStorageFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinRspQryHostEnvIO(const void *pV1, const void *pV2)
{
	CRspQryHostEnvIO *p1,*p2;
	p1=(CRspQryHostEnvIO *)pV1;
	p2=(CRspQryHostEnvIO *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForRspQryHostEnvIO=0;
#endif

CRspQryHostEnvIO *CRspQryHostEnvIOFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CRspQryHostEnvIO while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	queryHostNameInSearchByHostName= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvIO++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CRspQryHostEnvIO *theRspQryHostEnvIO;
	compareObject.HostName=HostName.getValue();
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theRspQryHostEnvIO=(CRspQryHostEnvIO *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theRspQryHostEnvIO->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theRspQryHostEnvIO;
}

CRspQryHostEnvIO *CRspQryHostEnvIOFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvIO++;
#endif
	CRspQryHostEnvIO *theRspQryHostEnvIO;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvIO=(CRspQryHostEnvIO *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theRspQryHostEnvIO->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theRspQryHostEnvIO;
}

void CRspQryHostEnvIOFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForRspQryHostEnvIO=0;
#endif

CRspQryHostEnvIO *CRspQryHostEnvIOFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CRspQryHostEnvIO while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvIO++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CRspQryHostEnvIO *theRspQryHostEnvIO;
	compareObject.HostName="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theRspQryHostEnvIO=(CRspQryHostEnvIO *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theRspQryHostEnvIO;
}

CRspQryHostEnvIO *CRspQryHostEnvIOFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvIO++;
#endif
	CRspQryHostEnvIO *theRspQryHostEnvIO;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvIO=(CRspQryHostEnvIO *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theRspQryHostEnvIO;
}

void CRspQryHostEnvIOFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinRspQryHostEnvFS(const void *pV1, const void *pV2)
{
	CRspQryHostEnvFS *p1,*p2;
	p1=(CRspQryHostEnvFS *)pV1;
	p2=(CRspQryHostEnvFS *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForRspQryHostEnvFS=0;
#endif

CRspQryHostEnvFS *CRspQryHostEnvFSFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CRspQryHostEnvFS while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	queryHostNameInSearchByHostName= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvFS++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CRspQryHostEnvFS *theRspQryHostEnvFS;
	compareObject.HostName=HostName.getValue();
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theRspQryHostEnvFS=(CRspQryHostEnvFS *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theRspQryHostEnvFS->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theRspQryHostEnvFS;
}

CRspQryHostEnvFS *CRspQryHostEnvFSFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvFS++;
#endif
	CRspQryHostEnvFS *theRspQryHostEnvFS;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvFS=(CRspQryHostEnvFS *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theRspQryHostEnvFS->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theRspQryHostEnvFS;
}

void CRspQryHostEnvFSFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForRspQryHostEnvFS=0;
#endif

CRspQryHostEnvFS *CRspQryHostEnvFSFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CRspQryHostEnvFS while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvFS++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CRspQryHostEnvFS *theRspQryHostEnvFS;
	compareObject.HostName="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theRspQryHostEnvFS=(CRspQryHostEnvFS *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theRspQryHostEnvFS;
}

CRspQryHostEnvFS *CRspQryHostEnvFSFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvFS++;
#endif
	CRspQryHostEnvFS *theRspQryHostEnvFS;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvFS=(CRspQryHostEnvFS *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theRspQryHostEnvFS;
}

void CRspQryHostEnvFSFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinRspQryHostEnvSwap(const void *pV1, const void *pV2)
{
	CRspQryHostEnvSwap *p1,*p2;
	p1=(CRspQryHostEnvSwap *)pV1;
	p2=(CRspQryHostEnvSwap *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForRspQryHostEnvSwap=0;
#endif

CRspQryHostEnvSwap *CRspQryHostEnvSwapFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CRspQryHostEnvSwap while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	queryHostNameInSearchByHostName= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvSwap++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CRspQryHostEnvSwap *theRspQryHostEnvSwap;
	compareObject.HostName=HostName.getValue();
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theRspQryHostEnvSwap=(CRspQryHostEnvSwap *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theRspQryHostEnvSwap->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theRspQryHostEnvSwap;
}

CRspQryHostEnvSwap *CRspQryHostEnvSwapFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvSwap++;
#endif
	CRspQryHostEnvSwap *theRspQryHostEnvSwap;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvSwap=(CRspQryHostEnvSwap *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theRspQryHostEnvSwap->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theRspQryHostEnvSwap;
}

void CRspQryHostEnvSwapFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForRspQryHostEnvSwap=0;
#endif

CRspQryHostEnvSwap *CRspQryHostEnvSwapFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CRspQryHostEnvSwap while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvSwap++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CRspQryHostEnvSwap *theRspQryHostEnvSwap;
	compareObject.HostName="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theRspQryHostEnvSwap=(CRspQryHostEnvSwap *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theRspQryHostEnvSwap;
}

CRspQryHostEnvSwap *CRspQryHostEnvSwapFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvSwap++;
#endif
	CRspQryHostEnvSwap *theRspQryHostEnvSwap;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvSwap=(CRspQryHostEnvSwap *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theRspQryHostEnvSwap;
}

void CRspQryHostEnvSwapFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinRspQryHostEnvLanCfg(const void *pV1, const void *pV2)
{
	CRspQryHostEnvLanCfg *p1,*p2;
	p1=(CRspQryHostEnvLanCfg *)pV1;
	p2=(CRspQryHostEnvLanCfg *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForRspQryHostEnvLanCfg=0;
#endif

CRspQryHostEnvLanCfg *CRspQryHostEnvLanCfgFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CRspQryHostEnvLanCfg while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	queryHostNameInSearchByHostName= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvLanCfg++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CRspQryHostEnvLanCfg *theRspQryHostEnvLanCfg;
	compareObject.HostName=HostName.getValue();
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theRspQryHostEnvLanCfg=(CRspQryHostEnvLanCfg *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theRspQryHostEnvLanCfg->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theRspQryHostEnvLanCfg;
}

CRspQryHostEnvLanCfg *CRspQryHostEnvLanCfgFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvLanCfg++;
#endif
	CRspQryHostEnvLanCfg *theRspQryHostEnvLanCfg;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvLanCfg=(CRspQryHostEnvLanCfg *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theRspQryHostEnvLanCfg->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theRspQryHostEnvLanCfg;
}

void CRspQryHostEnvLanCfgFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForRspQryHostEnvLanCfg=0;
#endif

CRspQryHostEnvLanCfg *CRspQryHostEnvLanCfgFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CRspQryHostEnvLanCfg while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvLanCfg++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CRspQryHostEnvLanCfg *theRspQryHostEnvLanCfg;
	compareObject.HostName="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theRspQryHostEnvLanCfg=(CRspQryHostEnvLanCfg *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theRspQryHostEnvLanCfg;
}

CRspQryHostEnvLanCfg *CRspQryHostEnvLanCfgFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvLanCfg++;
#endif
	CRspQryHostEnvLanCfg *theRspQryHostEnvLanCfg;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvLanCfg=(CRspQryHostEnvLanCfg *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theRspQryHostEnvLanCfg;
}

void CRspQryHostEnvLanCfgFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinSysMdbTopCpuInfo(const void *pV1, const void *pV2)
{
	CSysMdbTopCpuInfo *p1,*p2;
	p1=(CSysMdbTopCpuInfo *)pV1;
	p2=(CSysMdbTopCpuInfo *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbTopCpuInfo(const void *pV1, const void *pV2)
{
	CSysMdbTopCpuInfo *p1,*p2;
	p1=(CSysMdbTopCpuInfo *)pV1;
	p2=(CSysMdbTopCpuInfo *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysMdbTopCpuInfo=0;
#endif

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFactory::startFindByHostName( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysMdbTopCpuInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	queryHostNameInSearchByHostName= HostName.getValue();
	queryMonDateInSearchByHostName= MonDate.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbTopCpuInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbTopCpuInfo *theSysMdbTopCpuInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbTopCpuInfo=(CSysMdbTopCpuInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTopCpuInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTopCpuInfo;
}

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbTopCpuInfo++;
#endif
	CSysMdbTopCpuInfo *theSysMdbTopCpuInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysMdbTopCpuInfo=(CSysMdbTopCpuInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTopCpuInfo->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTopCpuInfo;
}

void CSysMdbTopCpuInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbTopCpuInfo=0;
#endif

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFactory::startFindByDsc( const CReadOnlyVolumeType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbTopCpuInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	queryHostNameInSearchByDsc= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTopCpuInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbTopCpuInfo *theSysMdbTopCpuInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbTopCpuInfo=(CSysMdbTopCpuInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTopCpuInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTopCpuInfo;
}

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTopCpuInfo++;
#endif
	CSysMdbTopCpuInfo *theSysMdbTopCpuInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbTopCpuInfo=(CSysMdbTopCpuInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTopCpuInfo->HostName,queryHostNameInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTopCpuInfo;
}

void CSysMdbTopCpuInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbTopCpuInfo=0;
#endif

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbTopCpuInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTopCpuInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbTopCpuInfo *theSysMdbTopCpuInfo;
	compareObject.HostName="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbTopCpuInfo=(CSysMdbTopCpuInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbTopCpuInfo;
}

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTopCpuInfo++;
#endif
	CSysMdbTopCpuInfo *theSysMdbTopCpuInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbTopCpuInfo=(CSysMdbTopCpuInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbTopCpuInfo;
}

void CSysMdbTopCpuInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbTopCpuInfo=0;
#endif

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbTopCpuInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///记录所有的查询值
	queryHostNameInSearchByDataDelete= HostName.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbTopCpuInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbTopCpuInfo *theSysMdbTopCpuInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDataDelete=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbTopCpuInfo=(CSysMdbTopCpuInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTopCpuInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTopCpuInfo;
}

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFactory::findNextByDataDelete(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbTopCpuInfo++;
#endif
	CSysMdbTopCpuInfo *theSysMdbTopCpuInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDataDelete=pDecIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbTopCpuInfo=(CSysMdbTopCpuInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTopCpuInfo->HostName,queryHostNameInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTopCpuInfo;
}

void CSysMdbTopCpuInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysHostNameIndexinSysMdbTopMemInfo(const void *pV1, const void *pV2)
{
	CSysMdbTopMemInfo *p1,*p2;
	p1=(CSysMdbTopMemInfo *)pV1;
	p2=(CSysMdbTopMemInfo *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbTopMemInfo(const void *pV1, const void *pV2)
{
	CSysMdbTopMemInfo *p1,*p2;
	p1=(CSysMdbTopMemInfo *)pV1;
	p2=(CSysMdbTopMemInfo *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysMdbTopMemInfo=0;
#endif

CSysMdbTopMemInfo *CSysMdbTopMemInfoFactory::startFindByHostName( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysMdbTopMemInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	queryHostNameInSearchByHostName= HostName.getValue();
	queryMonDateInSearchByHostName= MonDate.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbTopMemInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbTopMemInfo *theSysMdbTopMemInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbTopMemInfo=(CSysMdbTopMemInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTopMemInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTopMemInfo;
}

CSysMdbTopMemInfo *CSysMdbTopMemInfoFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbTopMemInfo++;
#endif
	CSysMdbTopMemInfo *theSysMdbTopMemInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysMdbTopMemInfo=(CSysMdbTopMemInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTopMemInfo->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTopMemInfo;
}

void CSysMdbTopMemInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbTopMemInfo=0;
#endif

CSysMdbTopMemInfo *CSysMdbTopMemInfoFactory::startFindByDsc( const CReadOnlyVolumeType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbTopMemInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	queryHostNameInSearchByDsc= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTopMemInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbTopMemInfo *theSysMdbTopMemInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbTopMemInfo=(CSysMdbTopMemInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTopMemInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTopMemInfo;
}

CSysMdbTopMemInfo *CSysMdbTopMemInfoFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTopMemInfo++;
#endif
	CSysMdbTopMemInfo *theSysMdbTopMemInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbTopMemInfo=(CSysMdbTopMemInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTopMemInfo->HostName,queryHostNameInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTopMemInfo;
}

void CSysMdbTopMemInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbTopMemInfo=0;
#endif

CSysMdbTopMemInfo *CSysMdbTopMemInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbTopMemInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTopMemInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbTopMemInfo *theSysMdbTopMemInfo;
	compareObject.HostName="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbTopMemInfo=(CSysMdbTopMemInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbTopMemInfo;
}

CSysMdbTopMemInfo *CSysMdbTopMemInfoFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTopMemInfo++;
#endif
	CSysMdbTopMemInfo *theSysMdbTopMemInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbTopMemInfo=(CSysMdbTopMemInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbTopMemInfo;
}

void CSysMdbTopMemInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbTopMemInfo=0;
#endif

CSysMdbTopMemInfo *CSysMdbTopMemInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbTopMemInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///记录所有的查询值
	queryHostNameInSearchByDataDelete= HostName.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbTopMemInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbTopMemInfo *theSysMdbTopMemInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDataDelete=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbTopMemInfo=(CSysMdbTopMemInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTopMemInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTopMemInfo;
}

CSysMdbTopMemInfo *CSysMdbTopMemInfoFactory::findNextByDataDelete(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbTopMemInfo++;
#endif
	CSysMdbTopMemInfo *theSysMdbTopMemInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDataDelete=pDecIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbTopMemInfo=(CSysMdbTopMemInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTopMemInfo->HostName,queryHostNameInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTopMemInfo;
}

void CSysMdbTopMemInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysHostNameIndexinSysMdbTopProcessInfo(const void *pV1, const void *pV2)
{
	CSysMdbTopProcessInfo *p1,*p2;
	p1=(CSysMdbTopProcessInfo *)pV1;
	p2=(CSysMdbTopProcessInfo *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbTopProcessInfo(const void *pV1, const void *pV2)
{
	CSysMdbTopProcessInfo *p1,*p2;
	p1=(CSysMdbTopProcessInfo *)pV1;
	p2=(CSysMdbTopProcessInfo *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysMdbTopProcessInfo=0;
#endif

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoFactory::startFindByHostName( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysMdbTopProcessInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	queryHostNameInSearchByHostName= HostName.getValue();
	queryMonDateInSearchByHostName= MonDate.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbTopProcessInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbTopProcessInfo *theSysMdbTopProcessInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbTopProcessInfo=(CSysMdbTopProcessInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTopProcessInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTopProcessInfo;
}

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbTopProcessInfo++;
#endif
	CSysMdbTopProcessInfo *theSysMdbTopProcessInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysMdbTopProcessInfo=(CSysMdbTopProcessInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTopProcessInfo->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTopProcessInfo;
}

void CSysMdbTopProcessInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbTopProcessInfo=0;
#endif

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoFactory::startFindByDsc( const CReadOnlyVolumeType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbTopProcessInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	queryHostNameInSearchByDsc= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTopProcessInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbTopProcessInfo *theSysMdbTopProcessInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbTopProcessInfo=(CSysMdbTopProcessInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTopProcessInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTopProcessInfo;
}

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTopProcessInfo++;
#endif
	CSysMdbTopProcessInfo *theSysMdbTopProcessInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbTopProcessInfo=(CSysMdbTopProcessInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTopProcessInfo->HostName,queryHostNameInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTopProcessInfo;
}

void CSysMdbTopProcessInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbTopProcessInfo=0;
#endif

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbTopProcessInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTopProcessInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbTopProcessInfo *theSysMdbTopProcessInfo;
	compareObject.HostName="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbTopProcessInfo=(CSysMdbTopProcessInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbTopProcessInfo;
}

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTopProcessInfo++;
#endif
	CSysMdbTopProcessInfo *theSysMdbTopProcessInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbTopProcessInfo=(CSysMdbTopProcessInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbTopProcessInfo;
}

void CSysMdbTopProcessInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinSysMdbFileSystemInfo(const void *pV1, const void *pV2)
{
	CSysMdbFileSystemInfo *p1,*p2;
	p1=(CSysMdbFileSystemInfo *)pV1;
	p2=(CSysMdbFileSystemInfo *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbFileSystemInfo(const void *pV1, const void *pV2)
{
	CSysMdbFileSystemInfo *p1,*p2;
	p1=(CSysMdbFileSystemInfo *)pV1;
	p2=(CSysMdbFileSystemInfo *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysMdbFileSystemInfo=0;
#endif

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoFactory::startFindByHostName( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysMdbFileSystemInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	queryHostNameInSearchByHostName= HostName.getValue();
	queryMonDateInSearchByHostName= MonDate.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbFileSystemInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbFileSystemInfo *theSysMdbFileSystemInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbFileSystemInfo=(CSysMdbFileSystemInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbFileSystemInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbFileSystemInfo;
}

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbFileSystemInfo++;
#endif
	CSysMdbFileSystemInfo *theSysMdbFileSystemInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysMdbFileSystemInfo=(CSysMdbFileSystemInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbFileSystemInfo->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbFileSystemInfo;
}

void CSysMdbFileSystemInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbFileSystemInfo=0;
#endif

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoFactory::startFindByDsc( const CReadOnlyVolumeType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbFileSystemInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	queryHostNameInSearchByDsc= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbFileSystemInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbFileSystemInfo *theSysMdbFileSystemInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbFileSystemInfo=(CSysMdbFileSystemInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbFileSystemInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbFileSystemInfo;
}

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbFileSystemInfo++;
#endif
	CSysMdbFileSystemInfo *theSysMdbFileSystemInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbFileSystemInfo=(CSysMdbFileSystemInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbFileSystemInfo->HostName,queryHostNameInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbFileSystemInfo;
}

void CSysMdbFileSystemInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbFileSystemInfo=0;
#endif

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbFileSystemInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbFileSystemInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbFileSystemInfo *theSysMdbFileSystemInfo;
	compareObject.HostName="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbFileSystemInfo=(CSysMdbFileSystemInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbFileSystemInfo;
}

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbFileSystemInfo++;
#endif
	CSysMdbFileSystemInfo *theSysMdbFileSystemInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbFileSystemInfo=(CSysMdbFileSystemInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbFileSystemInfo;
}

void CSysMdbFileSystemInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinSysMdbNetworkInfo(const void *pV1, const void *pV2)
{
	CSysMdbNetworkInfo *p1,*p2;
	p1=(CSysMdbNetworkInfo *)pV1;
	p2=(CSysMdbNetworkInfo *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbNetworkInfo(const void *pV1, const void *pV2)
{
	CSysMdbNetworkInfo *p1,*p2;
	p1=(CSysMdbNetworkInfo *)pV1;
	p2=(CSysMdbNetworkInfo *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysMdbNetworkInfo=0;
#endif

CSysMdbNetworkInfo *CSysMdbNetworkInfoFactory::startFindByHostName( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysMdbNetworkInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByHostName= SubcriberID.getValue();
	queryMonDateInSearchByHostName= MonDate.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbNetworkInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbNetworkInfo *theSysMdbNetworkInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbNetworkInfo=(CSysMdbNetworkInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbNetworkInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbNetworkInfo;
}

CSysMdbNetworkInfo *CSysMdbNetworkInfoFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbNetworkInfo++;
#endif
	CSysMdbNetworkInfo *theSysMdbNetworkInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysMdbNetworkInfo=(CSysMdbNetworkInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbNetworkInfo->SubcriberID,querySubcriberIDInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbNetworkInfo;
}

void CSysMdbNetworkInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbNetworkInfo=0;
#endif

CSysMdbNetworkInfo *CSysMdbNetworkInfoFactory::startFindByDsc( const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbNetworkInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByDsc= SubcriberID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbNetworkInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbNetworkInfo *theSysMdbNetworkInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbNetworkInfo=(CSysMdbNetworkInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbNetworkInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbNetworkInfo;
}

CSysMdbNetworkInfo *CSysMdbNetworkInfoFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbNetworkInfo++;
#endif
	CSysMdbNetworkInfo *theSysMdbNetworkInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbNetworkInfo=(CSysMdbNetworkInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbNetworkInfo->SubcriberID,querySubcriberIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbNetworkInfo;
}

void CSysMdbNetworkInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbNetworkInfo=0;
#endif

CSysMdbNetworkInfo *CSysMdbNetworkInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbNetworkInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbNetworkInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbNetworkInfo *theSysMdbNetworkInfo;
	compareObject.SubcriberID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbNetworkInfo=(CSysMdbNetworkInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbNetworkInfo;
}

CSysMdbNetworkInfo *CSysMdbNetworkInfoFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbNetworkInfo++;
#endif
	CSysMdbNetworkInfo *theSysMdbNetworkInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbNetworkInfo=(CSysMdbNetworkInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbNetworkInfo;
}

void CSysMdbNetworkInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbNetworkInfo=0;
#endif

CSysMdbNetworkInfo *CSysMdbNetworkInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbNetworkInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByDataDelete= SubcriberID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbNetworkInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbNetworkInfo *theSysMdbNetworkInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDataDelete=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbNetworkInfo=(CSysMdbNetworkInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbNetworkInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbNetworkInfo;
}

CSysMdbNetworkInfo *CSysMdbNetworkInfoFactory::findNextByDataDelete(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbNetworkInfo++;
#endif
	CSysMdbNetworkInfo *theSysMdbNetworkInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDataDelete=pDecIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbNetworkInfo=(CSysMdbNetworkInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbNetworkInfo->SubcriberID,querySubcriberIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbNetworkInfo;
}

void CSysMdbNetworkInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysParticipantIDIndexinSysParticipantInit(const void *pV1, const void *pV2)
{
	CSysParticipantInit *p1,*p2;
	p1=(CSysParticipantInit *)pV1;
	p2=(CSysParticipantInit *)pV2;
	switch (compare(p1->ParticipantID.getValue(),p2->ParticipantID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysParticipantInit=0;
#endif

CSysParticipantInit *CSysParticipantInitFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysParticipantInit while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysParticipantInit++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysParticipantInit *theSysParticipantInit;
	compareObject.ParticipantID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysParticipantIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysParticipantInit=(CSysParticipantInit *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysParticipantInit;
}

CSysParticipantInit *CSysParticipantInitFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysParticipantInit++;
#endif
	CSysParticipantInit *theSysParticipantInit;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysParticipantIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysParticipantInit=(CSysParticipantInit *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysParticipantInit;
}

void CSysParticipantInitFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysParticipantInit=0;
#endif
CSysParticipantInit *CSysParticipantInitFactory::findByOne( const CReadOnlyParticipantIDType&  ParticipantID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysParticipantInit while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysParticipantInit++;
#endif
	CAVLNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	pNode=pSysParticipantIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysParticipantInit *)(pNode->pObject);
}


int compareForSysUserIDIndexinSysUserInit(const void *pV1, const void *pV2)
{
	CSysUserInit *p1,*p2;
	p1=(CSysUserInit *)pV1;
	p2=(CSysUserInit *)pV2;
	switch (compare(p1->UserID.getValue(),p2->UserID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysUserInit=0;
#endif

CSysUserInit *CSysUserInitFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysUserInit while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysUserInit++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysUserInit *theSysUserInit;
	compareObject.UserID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysUserIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysUserInit=(CSysUserInit *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysUserInit;
}

CSysUserInit *CSysUserInitFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysUserInit++;
#endif
	CSysUserInit *theSysUserInit;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysUserIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysUserInit=(CSysUserInit *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysUserInit;
}

void CSysUserInitFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysUserInit=0;
#endif
CSysUserInit *CSysUserInitFactory::findByOne( const CReadOnlyUserIDType&  UserID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysUserInit while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysUserInit++;
#endif
	CAVLNode *pNode;
	compareObject.UserID=UserID.getValue();
	pNode=pSysUserIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysUserInit *)(pNode->pObject);
}


int compareForSysClientIDIndexinSysClientInit(const void *pV1, const void *pV2)
{
	CSysClientInit *p1,*p2;
	p1=(CSysClientInit *)pV1;
	p2=(CSysClientInit *)pV2;
	switch (compare(p1->ClientID.getValue(),p2->ClientID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysClientInit=0;
#endif

CSysClientInit *CSysClientInitFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysClientInit while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysClientInit++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysClientInit *theSysClientInit;
	compareObject.ClientID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysClientIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysClientInit=(CSysClientInit *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysClientInit;
}

CSysClientInit *CSysClientInitFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysClientInit++;
#endif
	CSysClientInit *theSysClientInit;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysClientIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysClientInit=(CSysClientInit *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysClientInit;
}

void CSysClientInitFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysClientInit=0;
#endif
CSysClientInit *CSysClientInitFactory::findByOne( const CReadOnlyClientIDType&  ClientID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysClientInit while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysClientInit++;
#endif
	CAVLNode *pNode;
	compareObject.ClientID=ClientID.getValue();
	pNode=pSysClientIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysClientInit *)(pNode->pObject);
}


int compareForSysTradeUserLoginInfoIndexinSysTradeUserLoginInfo(const void *pV1, const void *pV2)
{
	CSysTradeUserLoginInfo *p1,*p2;
	p1=(CSysTradeUserLoginInfo *)pV1;
	p2=(CSysTradeUserLoginInfo *)pV2;
	switch (compare(p1->ParticipantID.getValue(),p2->ParticipantID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->UserID.getValue(),p2->UserID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysTradeUserLoginInfo=0;
#endif

CSysTradeUserLoginInfo *CSysTradeUserLoginInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysTradeUserLoginInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysTradeUserLoginInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysTradeUserLoginInfo *theSysTradeUserLoginInfo;
	compareObject.ParticipantID="";
	compareObject.UserID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysTradeUserLoginInfoIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysTradeUserLoginInfo=(CSysTradeUserLoginInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysTradeUserLoginInfo;
}

CSysTradeUserLoginInfo *CSysTradeUserLoginInfoFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysTradeUserLoginInfo++;
#endif
	CSysTradeUserLoginInfo *theSysTradeUserLoginInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysTradeUserLoginInfoIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysTradeUserLoginInfo=(CSysTradeUserLoginInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysTradeUserLoginInfo;
}

void CSysTradeUserLoginInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysTradeUserLoginInfo=0;
#endif
CSysTradeUserLoginInfo *CSysTradeUserLoginInfoFactory::findByOne( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyUserIDType&  UserID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysTradeUserLoginInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysTradeUserLoginInfo++;
#endif
	CAVLNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.UserID=UserID.getValue();
	pNode=pSysTradeUserLoginInfoIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysTradeUserLoginInfo *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysMdbWebAppInfo(const void *pV1, const void *pV2)
{
	CSysMdbWebAppInfo *p1,*p2;
	p1=(CSysMdbWebAppInfo *)pV1;
	p2=(CSysMdbWebAppInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByIDTypeForSysMdbWebAppInfo=0;
#endif

CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::startFindByIDType( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIDType of CSysMdbWebAppInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByIDType!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIDType();
	}

	///记录所有的查询值
	queryObjectIDInSearchByIDType= ObjectID.getValue();
	queryMonDateInSearchByIDType= MonDate.getValue();
	queryMonTimeInSearchByIDType= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbWebAppInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbWebAppInfo *theSysMdbWebAppInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByIDType=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbWebAppInfo=(CSysMdbWebAppInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbWebAppInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbWebAppInfo;
}

CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::findNextByIDType(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbWebAppInfo++;
#endif
	CSysMdbWebAppInfo *theSysMdbWebAppInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByIDType=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByIDType);
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	theSysMdbWebAppInfo=(CSysMdbWebAppInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbWebAppInfo->ObjectID,queryObjectIDInSearchByIDType))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbWebAppInfo;
}

void CSysMdbWebAppInfoFactory::endFindByIDType(void)
{
	pLastFoundInSearchByIDType=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbWebAppInfo=0;
#endif

CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::startFindByDsc( const CReadOnlyVolumeType& ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbWebAppInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	queryObjectIDInSearchByDsc= ObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbWebAppInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbWebAppInfo *theSysMdbWebAppInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbWebAppInfo=(CSysMdbWebAppInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbWebAppInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbWebAppInfo;
}

CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbWebAppInfo++;
#endif
	CSysMdbWebAppInfo *theSysMdbWebAppInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbWebAppInfo=(CSysMdbWebAppInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbWebAppInfo->ObjectID,queryObjectIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbWebAppInfo;
}

void CSysMdbWebAppInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysMdbWebAppInfo=0;
#endif
CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::findByOne( const CReadOnlyVolumeType&  ObjectID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysMdbWebAppInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysMdbWebAppInfo++;
#endif
	CAVLNode *pNode;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysMdbWebAppInfo *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbWebAppInfo=0;
#endif

CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbWebAppInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbWebAppInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbWebAppInfo *theSysMdbWebAppInfo;
	compareObject.ObjectID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbWebAppInfo=(CSysMdbWebAppInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbWebAppInfo;
}

CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbWebAppInfo++;
#endif
	CSysMdbWebAppInfo *theSysMdbWebAppInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbWebAppInfo=(CSysMdbWebAppInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbWebAppInfo;
}

void CSysMdbWebAppInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbWebAppInfo=0;
#endif

CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbWebAppInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///记录所有的查询值
	queryObjectIDInSearchByDataDelete= ObjectID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbWebAppInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbWebAppInfo *theSysMdbWebAppInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbWebAppInfo=(CSysMdbWebAppInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbWebAppInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbWebAppInfo;
}

CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::findNextByDataDelete(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbWebAppInfo++;
#endif
	CSysMdbWebAppInfo *theSysMdbWebAppInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbWebAppInfo=(CSysMdbWebAppInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbWebAppInfo->ObjectID,queryObjectIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbWebAppInfo;
}

void CSysMdbWebAppInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysIDTypeIndexinSysMdbMemPoolInfo(const void *pV1, const void *pV2)
{
	CSysMdbMemPoolInfo *p1,*p2;
	p1=(CSysMdbMemPoolInfo *)pV1;
	p2=(CSysMdbMemPoolInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByIDTypeForSysMdbMemPoolInfo=0;
#endif

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::startFindByIDType( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIDType of CSysMdbMemPoolInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByIDType!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIDType();
	}

	///记录所有的查询值
	queryObjectIDInSearchByIDType= ObjectID.getValue();
	queryMonDateInSearchByIDType= MonDate.getValue();
	queryMonTimeInSearchByIDType= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbMemPoolInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbMemPoolInfo *theSysMdbMemPoolInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByIDType=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbMemPoolInfo=(CSysMdbMemPoolInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbMemPoolInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbMemPoolInfo;
}

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::findNextByIDType(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbMemPoolInfo++;
#endif
	CSysMdbMemPoolInfo *theSysMdbMemPoolInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByIDType=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByIDType);
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	theSysMdbMemPoolInfo=(CSysMdbMemPoolInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbMemPoolInfo->ObjectID,queryObjectIDInSearchByIDType))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbMemPoolInfo;
}

void CSysMdbMemPoolInfoFactory::endFindByIDType(void)
{
	pLastFoundInSearchByIDType=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbMemPoolInfo=0;
#endif

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::startFindByDsc( const CReadOnlyVolumeType& ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbMemPoolInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	queryObjectIDInSearchByDsc= ObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbMemPoolInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbMemPoolInfo *theSysMdbMemPoolInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbMemPoolInfo=(CSysMdbMemPoolInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbMemPoolInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbMemPoolInfo;
}

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbMemPoolInfo++;
#endif
	CSysMdbMemPoolInfo *theSysMdbMemPoolInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbMemPoolInfo=(CSysMdbMemPoolInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbMemPoolInfo->ObjectID,queryObjectIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbMemPoolInfo;
}

void CSysMdbMemPoolInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysMdbMemPoolInfo=0;
#endif
CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::findByOne( const CReadOnlyVolumeType&  ObjectID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysMdbMemPoolInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysMdbMemPoolInfo++;
#endif
	CAVLNode *pNode;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysMdbMemPoolInfo *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbMemPoolInfo=0;
#endif

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbMemPoolInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbMemPoolInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbMemPoolInfo *theSysMdbMemPoolInfo;
	compareObject.ObjectID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbMemPoolInfo=(CSysMdbMemPoolInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbMemPoolInfo;
}

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbMemPoolInfo++;
#endif
	CSysMdbMemPoolInfo *theSysMdbMemPoolInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbMemPoolInfo=(CSysMdbMemPoolInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbMemPoolInfo;
}

void CSysMdbMemPoolInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbMemPoolInfo=0;
#endif

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbMemPoolInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///记录所有的查询值
	queryObjectIDInSearchByDataDelete= ObjectID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbMemPoolInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbMemPoolInfo *theSysMdbMemPoolInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbMemPoolInfo=(CSysMdbMemPoolInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbMemPoolInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbMemPoolInfo;
}

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::findNextByDataDelete(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbMemPoolInfo++;
#endif
	CSysMdbMemPoolInfo *theSysMdbMemPoolInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbMemPoolInfo=(CSysMdbMemPoolInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbMemPoolInfo->ObjectID,queryObjectIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbMemPoolInfo;
}

void CSysMdbMemPoolInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysIDTypeIndexinSysMdbConnectorInfo(const void *pV1, const void *pV2)
{
	CSysMdbConnectorInfo *p1,*p2;
	p1=(CSysMdbConnectorInfo *)pV1;
	p2=(CSysMdbConnectorInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByIDTypeForSysMdbConnectorInfo=0;
#endif

CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::startFindByIDType( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIDType of CSysMdbConnectorInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByIDType!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIDType();
	}

	///记录所有的查询值
	queryObjectIDInSearchByIDType= ObjectID.getValue();
	queryMonDateInSearchByIDType= MonDate.getValue();
	queryMonTimeInSearchByIDType= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbConnectorInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbConnectorInfo *theSysMdbConnectorInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByIDType=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbConnectorInfo=(CSysMdbConnectorInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbConnectorInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbConnectorInfo;
}

CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::findNextByIDType(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbConnectorInfo++;
#endif
	CSysMdbConnectorInfo *theSysMdbConnectorInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByIDType=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByIDType);
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	theSysMdbConnectorInfo=(CSysMdbConnectorInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbConnectorInfo->ObjectID,queryObjectIDInSearchByIDType))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbConnectorInfo;
}

void CSysMdbConnectorInfoFactory::endFindByIDType(void)
{
	pLastFoundInSearchByIDType=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbConnectorInfo=0;
#endif

CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::startFindByDsc( const CReadOnlyVolumeType& ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbConnectorInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	queryObjectIDInSearchByDsc= ObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbConnectorInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbConnectorInfo *theSysMdbConnectorInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbConnectorInfo=(CSysMdbConnectorInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbConnectorInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbConnectorInfo;
}

CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbConnectorInfo++;
#endif
	CSysMdbConnectorInfo *theSysMdbConnectorInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbConnectorInfo=(CSysMdbConnectorInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbConnectorInfo->ObjectID,queryObjectIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbConnectorInfo;
}

void CSysMdbConnectorInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysMdbConnectorInfo=0;
#endif
CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::findByOne( const CReadOnlyVolumeType&  ObjectID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysMdbConnectorInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysMdbConnectorInfo++;
#endif
	CAVLNode *pNode;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysMdbConnectorInfo *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbConnectorInfo=0;
#endif

CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbConnectorInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbConnectorInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbConnectorInfo *theSysMdbConnectorInfo;
	compareObject.ObjectID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbConnectorInfo=(CSysMdbConnectorInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbConnectorInfo;
}

CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbConnectorInfo++;
#endif
	CSysMdbConnectorInfo *theSysMdbConnectorInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbConnectorInfo=(CSysMdbConnectorInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbConnectorInfo;
}

void CSysMdbConnectorInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbConnectorInfo=0;
#endif

CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbConnectorInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///记录所有的查询值
	queryObjectIDInSearchByDataDelete= ObjectID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbConnectorInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbConnectorInfo *theSysMdbConnectorInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbConnectorInfo=(CSysMdbConnectorInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbConnectorInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbConnectorInfo;
}

CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::findNextByDataDelete(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbConnectorInfo++;
#endif
	CSysMdbConnectorInfo *theSysMdbConnectorInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbConnectorInfo=(CSysMdbConnectorInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbConnectorInfo->ObjectID,queryObjectIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbConnectorInfo;
}

void CSysMdbConnectorInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysIDTypeIndexinSysMdbDBQuery(const void *pV1, const void *pV2)
{
	CSysMdbDBQuery *p1,*p2;
	p1=(CSysMdbDBQuery *)pV1;
	p2=(CSysMdbDBQuery *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByIDTypeForSysMdbDBQuery=0;
#endif

CSysMdbDBQuery *CSysMdbDBQueryFactory::startFindByIDType( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIDType of CSysMdbDBQuery while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByIDType!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIDType();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByIDType= SubcriberID.getValue();
	queryMonDateInSearchByIDType= MonDate.getValue();
	queryMonTimeInSearchByIDType= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbDBQuery++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbDBQuery *theSysMdbDBQuery;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByIDType=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbDBQuery=(CSysMdbDBQuery *)(pLastFoundInSearchByIDType->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbDBQuery->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbDBQuery;
}

CSysMdbDBQuery *CSysMdbDBQueryFactory::findNextByIDType(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbDBQuery++;
#endif
	CSysMdbDBQuery *theSysMdbDBQuery;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByIDType=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByIDType);
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	theSysMdbDBQuery=(CSysMdbDBQuery *)(pLastFoundInSearchByIDType->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbDBQuery->SubcriberID,querySubcriberIDInSearchByIDType))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbDBQuery;
}

void CSysMdbDBQueryFactory::endFindByIDType(void)
{
	pLastFoundInSearchByIDType=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbDBQuery=0;
#endif

CSysMdbDBQuery *CSysMdbDBQueryFactory::startFindByDsc( const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbDBQuery while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByDsc= SubcriberID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbDBQuery++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbDBQuery *theSysMdbDBQuery;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbDBQuery=(CSysMdbDBQuery *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbDBQuery->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbDBQuery;
}

CSysMdbDBQuery *CSysMdbDBQueryFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbDBQuery++;
#endif
	CSysMdbDBQuery *theSysMdbDBQuery;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbDBQuery=(CSysMdbDBQuery *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbDBQuery->SubcriberID,querySubcriberIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbDBQuery;
}

void CSysMdbDBQueryFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysMdbDBQuery=0;
#endif
CSysMdbDBQuery *CSysMdbDBQueryFactory::findByOne( const CReadOnlyVolumeType&  SubcriberID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysMdbDBQuery while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysMdbDBQuery++;
#endif
	CAVLNode *pNode;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysMdbDBQuery *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbDBQuery=0;
#endif

CSysMdbDBQuery *CSysMdbDBQueryFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbDBQuery while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbDBQuery++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbDBQuery *theSysMdbDBQuery;
	compareObject.SubcriberID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbDBQuery=(CSysMdbDBQuery *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbDBQuery;
}

CSysMdbDBQuery *CSysMdbDBQueryFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbDBQuery++;
#endif
	CSysMdbDBQuery *theSysMdbDBQuery;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbDBQuery=(CSysMdbDBQuery *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbDBQuery;
}

void CSysMdbDBQueryFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbDBQuery=0;
#endif

CSysMdbDBQuery *CSysMdbDBQueryFactory::startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbDBQuery while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByDataDelete= SubcriberID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbDBQuery++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbDBQuery *theSysMdbDBQuery;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbDBQuery=(CSysMdbDBQuery *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbDBQuery->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbDBQuery;
}

CSysMdbDBQuery *CSysMdbDBQueryFactory::findNextByDataDelete(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbDBQuery++;
#endif
	CSysMdbDBQuery *theSysMdbDBQuery;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbDBQuery=(CSysMdbDBQuery *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbDBQuery->SubcriberID,querySubcriberIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbDBQuery;
}

void CSysMdbDBQueryFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysIDTypeIndexinSysNetArea(const void *pV1, const void *pV2)
{
	CSysNetArea *p1,*p2;
	p1=(CSysNetArea *)pV1;
	p2=(CSysNetArea *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetArea=0;
#endif

CSysNetArea *CSysNetAreaFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetArea while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetArea++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetArea *theSysNetArea;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetArea=(CSysNetArea *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetArea;
}

CSysNetArea *CSysNetAreaFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetArea++;
#endif
	CSysNetArea *theSysNetArea;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetArea=(CSysNetArea *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetArea;
}

void CSysNetAreaFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetArea=0;
#endif
CSysNetArea *CSysNetAreaFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetArea while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetArea++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetArea *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetSubArea(const void *pV1, const void *pV2)
{
	CSysNetSubArea *p1,*p2;
	p1=(CSysNetSubArea *)pV1;
	p2=(CSysNetSubArea *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetSubArea=0;
#endif

CSysNetSubArea *CSysNetSubAreaFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetSubArea while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetSubArea++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetSubArea *theSysNetSubArea;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetSubArea=(CSysNetSubArea *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetSubArea;
}

CSysNetSubArea *CSysNetSubAreaFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetSubArea++;
#endif
	CSysNetSubArea *theSysNetSubArea;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetSubArea=(CSysNetSubArea *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetSubArea;
}

void CSysNetSubAreaFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetSubArea=0;
#endif
CSysNetSubArea *CSysNetSubAreaFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetSubArea while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetSubArea++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetSubArea *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetSubAreaIP(const void *pV1, const void *pV2)
{
	CSysNetSubAreaIP *p1,*p2;
	p1=(CSysNetSubAreaIP *)pV1;
	p2=(CSysNetSubAreaIP *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetSubAreaIP=0;
#endif

CSysNetSubAreaIP *CSysNetSubAreaIPFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetSubAreaIP while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetSubAreaIP++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetSubAreaIP *theSysNetSubAreaIP;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetSubAreaIP=(CSysNetSubAreaIP *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetSubAreaIP;
}

CSysNetSubAreaIP *CSysNetSubAreaIPFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetSubAreaIP++;
#endif
	CSysNetSubAreaIP *theSysNetSubAreaIP;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetSubAreaIP=(CSysNetSubAreaIP *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetSubAreaIP;
}

void CSysNetSubAreaIPFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetSubAreaIP=0;
#endif
CSysNetSubAreaIP *CSysNetSubAreaIPFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetSubAreaIP while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetSubAreaIP++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetSubAreaIP *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetFuncArea(const void *pV1, const void *pV2)
{
	CSysNetFuncArea *p1,*p2;
	p1=(CSysNetFuncArea *)pV1;
	p2=(CSysNetFuncArea *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetFuncArea=0;
#endif

CSysNetFuncArea *CSysNetFuncAreaFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetFuncArea while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetFuncArea++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetFuncArea *theSysNetFuncArea;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetFuncArea=(CSysNetFuncArea *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetFuncArea;
}

CSysNetFuncArea *CSysNetFuncAreaFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetFuncArea++;
#endif
	CSysNetFuncArea *theSysNetFuncArea;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetFuncArea=(CSysNetFuncArea *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetFuncArea;
}

void CSysNetFuncAreaFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetFuncArea=0;
#endif
CSysNetFuncArea *CSysNetFuncAreaFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetFuncArea while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetFuncArea++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetFuncArea *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetDevice(const void *pV1, const void *pV2)
{
	CSysNetDevice *p1,*p2;
	p1=(CSysNetDevice *)pV1;
	p2=(CSysNetDevice *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysIPDECODETypeIndexinSysNetDevice(const void *pV1, const void *pV2)
{
	CSysNetDevice *p1,*p2;
	p1=(CSysNetDevice *)pV1;
	p2=(CSysNetDevice *)pV2;
	switch (compare(p1->IPDECODE.getValue(),p2->IPDECODE.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysSubAreaIDTypeIndexinSysNetDevice(const void *pV1, const void *pV2)
{
	CSysNetDevice *p1,*p2;
	p1=(CSysNetDevice *)pV1;
	p2=(CSysNetDevice *)pV2;
	switch (compare(p1->SysNetSubAreaID.getValue(),p2->SysNetSubAreaID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysObjectIDTypeIndexinSysNetDevice(const void *pV1, const void *pV2)
{
	CSysNetDevice *p1,*p2;
	p1=(CSysNetDevice *)pV1;
	p2=(CSysNetDevice *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetDevice=0;
#endif

CSysNetDevice *CSysNetDeviceFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetDevice while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDevice++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetDevice *theSysNetDevice;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetDevice=(CSysNetDevice *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetDevice;
}

CSysNetDevice *CSysNetDeviceFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDevice++;
#endif
	CSysNetDevice *theSysNetDevice;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetDevice=(CSysNetDevice *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetDevice;
}

void CSysNetDeviceFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetDevice=0;
#endif
CSysNetDevice *CSysNetDeviceFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetDevice while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetDevice++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetDevice *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByIPDECODEForSysNetDevice=0;
#endif

CSysNetDevice *CSysNetDeviceFactory::startFindByIPDECODE( const CReadOnlyVolumeType& IPDECODE)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIPDECODE of CSysNetDevice while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByIPDECODE!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIPDECODE();
	}

	///记录所有的查询值
	queryIPDECODEInSearchByIPDECODE= IPDECODE.getValue();

#ifdef COUNT_SEARCH
	multiFindByIPDECODEForSysNetDevice++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetDevice *theSysNetDevice;
	compareObject.IPDECODE=IPDECODE.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByIPDECODE=pSysIPDECODETypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByIPDECODE==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetDevice=(CSysNetDevice *)(pLastFoundInSearchByIPDECODE->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetDevice->IPDECODE.getValue(),IPDECODE.getValue()))
	{
		pLastFoundInSearchByIPDECODE=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetDevice;
}

CSysNetDevice *CSysNetDeviceFactory::findNextByIPDECODE(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByIPDECODE==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIPDECODEForSysNetDevice++;
#endif
	CSysNetDevice *theSysNetDevice;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByIPDECODE=pSysIPDECODETypeIndex->getNextNode(pLastFoundInSearchByIPDECODE);
	if (pLastFoundInSearchByIPDECODE==NULL)
	{
		return NULL;
	}

	theSysNetDevice=(CSysNetDevice *)(pLastFoundInSearchByIPDECODE->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetDevice->IPDECODE,queryIPDECODEInSearchByIPDECODE))
	{
		pLastFoundInSearchByIPDECODE=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetDevice;
}

void CSysNetDeviceFactory::endFindByIPDECODE(void)
{
	pLastFoundInSearchByIPDECODE=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBySubAreaIDForSysNetDevice=0;
#endif

CSysNetDevice *CSysNetDeviceFactory::startFindBySubAreaID( const CReadOnlyVolumeType& SysNetSubAreaID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySubAreaID of CSysNetDevice while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySubAreaID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySubAreaID();
	}

	///记录所有的查询值
	querySysNetSubAreaIDInSearchBySubAreaID= SysNetSubAreaID.getValue();

#ifdef COUNT_SEARCH
	multiFindBySubAreaIDForSysNetDevice++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetDevice *theSysNetDevice;
	compareObject.SysNetSubAreaID=SysNetSubAreaID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBySubAreaID=pSysSubAreaIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBySubAreaID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetDevice=(CSysNetDevice *)(pLastFoundInSearchBySubAreaID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetDevice->SysNetSubAreaID.getValue(),SysNetSubAreaID.getValue()))
	{
		pLastFoundInSearchBySubAreaID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetDevice;
}

CSysNetDevice *CSysNetDeviceFactory::findNextBySubAreaID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySubAreaID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBySubAreaIDForSysNetDevice++;
#endif
	CSysNetDevice *theSysNetDevice;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBySubAreaID=pSysSubAreaIDTypeIndex->getNextNode(pLastFoundInSearchBySubAreaID);
	if (pLastFoundInSearchBySubAreaID==NULL)
	{
		return NULL;
	}

	theSysNetDevice=(CSysNetDevice *)(pLastFoundInSearchBySubAreaID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetDevice->SysNetSubAreaID,querySysNetSubAreaIDInSearchBySubAreaID))
	{
		pLastFoundInSearchBySubAreaID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetDevice;
}

void CSysNetDeviceFactory::endFindBySubAreaID(void)
{
	pLastFoundInSearchBySubAreaID=NULL;
}


#ifdef COUNT_SEARCH
int findByObjectIDForSysNetDevice=0;
#endif
CSysNetDevice *CSysNetDeviceFactory::findByObjectID( const CReadOnlyNetObjectIDType&  ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByObjectID of CSysNetDevice while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByObjectIDForSysNetDevice++;
#endif
	CAVLNode *pNode;
	compareObject.ObjectID=ObjectID.getValue();
	pNode=pSysObjectIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetDevice *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetDeviceLinked(const void *pV1, const void *pV2)
{
	CSysNetDeviceLinked *p1,*p2;
	p1=(CSysNetDeviceLinked *)pV1;
	p2=(CSysNetDeviceLinked *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysNetObjectIDTypeIndexinSysNetDeviceLinked(const void *pV1, const void *pV2)
{
	CSysNetDeviceLinked *p1,*p2;
	p1=(CSysNetDeviceLinked *)pV1;
	p2=(CSysNetDeviceLinked *)pV2;
	switch (compare(p1->NetObjectID.getValue(),p2->NetObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysLinkObjectIDTypeIndexinSysNetDeviceLinked(const void *pV1, const void *pV2)
{
	CSysNetDeviceLinked *p1,*p2;
	p1=(CSysNetDeviceLinked *)pV1;
	p2=(CSysNetDeviceLinked *)pV2;
	switch (compare(p1->LinkNetObjectID.getValue(),p2->LinkNetObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetDeviceLinked=0;
#endif

CSysNetDeviceLinked *CSysNetDeviceLinkedFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetDeviceLinked while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDeviceLinked++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetDeviceLinked *theSysNetDeviceLinked;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetDeviceLinked=(CSysNetDeviceLinked *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetDeviceLinked;
}

CSysNetDeviceLinked *CSysNetDeviceLinkedFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDeviceLinked++;
#endif
	CSysNetDeviceLinked *theSysNetDeviceLinked;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetDeviceLinked=(CSysNetDeviceLinked *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetDeviceLinked;
}

void CSysNetDeviceLinkedFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetDeviceLinked=0;
#endif
CSysNetDeviceLinked *CSysNetDeviceLinkedFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetDeviceLinked while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetDeviceLinked++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetDeviceLinked *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByNetObjectIDForSysNetDeviceLinked=0;
#endif

CSysNetDeviceLinked *CSysNetDeviceLinkedFactory::startFindByNetObjectID( const CReadOnlyNetObjectIDType& NetObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByNetObjectID of CSysNetDeviceLinked while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByNetObjectID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByNetObjectID();
	}

	///记录所有的查询值
	queryNetObjectIDInSearchByNetObjectID= NetObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByNetObjectIDForSysNetDeviceLinked++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetDeviceLinked *theSysNetDeviceLinked;
	compareObject.NetObjectID=NetObjectID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByNetObjectID=pSysNetObjectIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByNetObjectID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetDeviceLinked=(CSysNetDeviceLinked *)(pLastFoundInSearchByNetObjectID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetDeviceLinked->NetObjectID.getValue(),NetObjectID.getValue()))
	{
		pLastFoundInSearchByNetObjectID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetDeviceLinked;
}

CSysNetDeviceLinked *CSysNetDeviceLinkedFactory::findNextByNetObjectID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByNetObjectID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByNetObjectIDForSysNetDeviceLinked++;
#endif
	CSysNetDeviceLinked *theSysNetDeviceLinked;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByNetObjectID=pSysNetObjectIDTypeIndex->getNextNode(pLastFoundInSearchByNetObjectID);
	if (pLastFoundInSearchByNetObjectID==NULL)
	{
		return NULL;
	}

	theSysNetDeviceLinked=(CSysNetDeviceLinked *)(pLastFoundInSearchByNetObjectID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetDeviceLinked->NetObjectID,queryNetObjectIDInSearchByNetObjectID))
	{
		pLastFoundInSearchByNetObjectID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetDeviceLinked;
}

void CSysNetDeviceLinkedFactory::endFindByNetObjectID(void)
{
	pLastFoundInSearchByNetObjectID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByLinkNetObjectIDForSysNetDeviceLinked=0;
#endif

CSysNetDeviceLinked *CSysNetDeviceLinkedFactory::startFindByLinkNetObjectID( const CReadOnlyNetObjectIDType& LinkNetObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByLinkNetObjectID of CSysNetDeviceLinked while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByLinkNetObjectID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByLinkNetObjectID();
	}

	///记录所有的查询值
	queryLinkNetObjectIDInSearchByLinkNetObjectID= LinkNetObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByLinkNetObjectIDForSysNetDeviceLinked++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetDeviceLinked *theSysNetDeviceLinked;
	compareObject.LinkNetObjectID=LinkNetObjectID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByLinkNetObjectID=pSysLinkObjectIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByLinkNetObjectID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetDeviceLinked=(CSysNetDeviceLinked *)(pLastFoundInSearchByLinkNetObjectID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetDeviceLinked->LinkNetObjectID.getValue(),LinkNetObjectID.getValue()))
	{
		pLastFoundInSearchByLinkNetObjectID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetDeviceLinked;
}

CSysNetDeviceLinked *CSysNetDeviceLinkedFactory::findNextByLinkNetObjectID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByLinkNetObjectID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByLinkNetObjectIDForSysNetDeviceLinked++;
#endif
	CSysNetDeviceLinked *theSysNetDeviceLinked;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByLinkNetObjectID=pSysLinkObjectIDTypeIndex->getNextNode(pLastFoundInSearchByLinkNetObjectID);
	if (pLastFoundInSearchByLinkNetObjectID==NULL)
	{
		return NULL;
	}

	theSysNetDeviceLinked=(CSysNetDeviceLinked *)(pLastFoundInSearchByLinkNetObjectID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetDeviceLinked->LinkNetObjectID,queryLinkNetObjectIDInSearchByLinkNetObjectID))
	{
		pLastFoundInSearchByLinkNetObjectID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetDeviceLinked;
}

void CSysNetDeviceLinkedFactory::endFindByLinkNetObjectID(void)
{
	pLastFoundInSearchByLinkNetObjectID=NULL;
}

int compareForSysIDTypeIndexinSysNetOID(const void *pV1, const void *pV2)
{
	CSysNetOID *p1,*p2;
	p1=(CSysNetOID *)pV1;
	p2=(CSysNetOID *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetOID=0;
#endif

CSysNetOID *CSysNetOIDFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetOID while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetOID++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetOID *theSysNetOID;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetOID=(CSysNetOID *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetOID;
}

CSysNetOID *CSysNetOIDFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetOID++;
#endif
	CSysNetOID *theSysNetOID;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetOID=(CSysNetOID *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetOID;
}

void CSysNetOIDFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetOID=0;
#endif
CSysNetOID *CSysNetOIDFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetOID while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetOID++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetOID *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetDeviceType(const void *pV1, const void *pV2)
{
	CSysNetDeviceType *p1,*p2;
	p1=(CSysNetDeviceType *)pV1;
	p2=(CSysNetDeviceType *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetDeviceType=0;
#endif

CSysNetDeviceType *CSysNetDeviceTypeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetDeviceType while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDeviceType++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetDeviceType *theSysNetDeviceType;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetDeviceType=(CSysNetDeviceType *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetDeviceType;
}

CSysNetDeviceType *CSysNetDeviceTypeFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDeviceType++;
#endif
	CSysNetDeviceType *theSysNetDeviceType;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetDeviceType=(CSysNetDeviceType *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetDeviceType;
}

void CSysNetDeviceTypeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetDeviceType=0;
#endif
CSysNetDeviceType *CSysNetDeviceTypeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetDeviceType while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetDeviceType++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetDeviceType *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetTimePolicy(const void *pV1, const void *pV2)
{
	CSysNetTimePolicy *p1,*p2;
	p1=(CSysNetTimePolicy *)pV1;
	p2=(CSysNetTimePolicy *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetTimePolicy=0;
#endif

CSysNetTimePolicy *CSysNetTimePolicyFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetTimePolicy while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetTimePolicy++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetTimePolicy *theSysNetTimePolicy;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetTimePolicy=(CSysNetTimePolicy *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetTimePolicy;
}

CSysNetTimePolicy *CSysNetTimePolicyFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetTimePolicy++;
#endif
	CSysNetTimePolicy *theSysNetTimePolicy;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetTimePolicy=(CSysNetTimePolicy *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetTimePolicy;
}

void CSysNetTimePolicyFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetTimePolicy=0;
#endif
CSysNetTimePolicy *CSysNetTimePolicyFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetTimePolicy while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetTimePolicy++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetTimePolicy *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetGatherTask(const void *pV1, const void *pV2)
{
	CSysNetGatherTask *p1,*p2;
	p1=(CSysNetGatherTask *)pV1;
	p2=(CSysNetGatherTask *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysNetObjectIDTypeIndexinSysNetGatherTask(const void *pV1, const void *pV2)
{
	CSysNetGatherTask *p1,*p2;
	p1=(CSysNetGatherTask *)pV1;
	p2=(CSysNetGatherTask *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetGatherTask=0;
#endif

CSysNetGatherTask *CSysNetGatherTaskFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetGatherTask while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetGatherTask++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetGatherTask *theSysNetGatherTask;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetGatherTask=(CSysNetGatherTask *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetGatherTask;
}

CSysNetGatherTask *CSysNetGatherTaskFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetGatherTask++;
#endif
	CSysNetGatherTask *theSysNetGatherTask;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetGatherTask=(CSysNetGatherTask *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetGatherTask;
}

void CSysNetGatherTaskFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetGatherTask=0;
#endif
CSysNetGatherTask *CSysNetGatherTaskFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetGatherTask while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetGatherTask++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetGatherTask *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByNetObjectIDForSysNetGatherTask=0;
#endif

CSysNetGatherTask *CSysNetGatherTaskFactory::startFindByNetObjectID( const CReadOnlyNetObjectIDType& ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByNetObjectID of CSysNetGatherTask while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByNetObjectID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByNetObjectID();
	}

	///记录所有的查询值
	queryObjectIDInSearchByNetObjectID= ObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByNetObjectIDForSysNetGatherTask++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetGatherTask *theSysNetGatherTask;
	compareObject.ObjectID=ObjectID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByNetObjectID=pSysNetObjectIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByNetObjectID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetGatherTask=(CSysNetGatherTask *)(pLastFoundInSearchByNetObjectID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetGatherTask->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByNetObjectID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetGatherTask;
}

CSysNetGatherTask *CSysNetGatherTaskFactory::findNextByNetObjectID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByNetObjectID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByNetObjectIDForSysNetGatherTask++;
#endif
	CSysNetGatherTask *theSysNetGatherTask;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByNetObjectID=pSysNetObjectIDTypeIndex->getNextNode(pLastFoundInSearchByNetObjectID);
	if (pLastFoundInSearchByNetObjectID==NULL)
	{
		return NULL;
	}

	theSysNetGatherTask=(CSysNetGatherTask *)(pLastFoundInSearchByNetObjectID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetGatherTask->ObjectID,queryObjectIDInSearchByNetObjectID))
	{
		pLastFoundInSearchByNetObjectID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetGatherTask;
}

void CSysNetGatherTaskFactory::endFindByNetObjectID(void)
{
	pLastFoundInSearchByNetObjectID=NULL;
}

int compareForSysIDTypeIndexinSysNetDeviceCategory(const void *pV1, const void *pV2)
{
	CSysNetDeviceCategory *p1,*p2;
	p1=(CSysNetDeviceCategory *)pV1;
	p2=(CSysNetDeviceCategory *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetDeviceCategory=0;
#endif

CSysNetDeviceCategory *CSysNetDeviceCategoryFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetDeviceCategory while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDeviceCategory++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetDeviceCategory *theSysNetDeviceCategory;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetDeviceCategory=(CSysNetDeviceCategory *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetDeviceCategory;
}

CSysNetDeviceCategory *CSysNetDeviceCategoryFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDeviceCategory++;
#endif
	CSysNetDeviceCategory *theSysNetDeviceCategory;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetDeviceCategory=(CSysNetDeviceCategory *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetDeviceCategory;
}

void CSysNetDeviceCategoryFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetDeviceCategory=0;
#endif
CSysNetDeviceCategory *CSysNetDeviceCategoryFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetDeviceCategory while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetDeviceCategory++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetDeviceCategory *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetManufactory(const void *pV1, const void *pV2)
{
	CSysNetManufactory *p1,*p2;
	p1=(CSysNetManufactory *)pV1;
	p2=(CSysNetManufactory *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetManufactory=0;
#endif

CSysNetManufactory *CSysNetManufactoryFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetManufactory while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetManufactory++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetManufactory *theSysNetManufactory;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetManufactory=(CSysNetManufactory *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetManufactory;
}

CSysNetManufactory *CSysNetManufactoryFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetManufactory++;
#endif
	CSysNetManufactory *theSysNetManufactory;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetManufactory=(CSysNetManufactory *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetManufactory;
}

void CSysNetManufactoryFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetManufactory=0;
#endif
CSysNetManufactory *CSysNetManufactoryFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetManufactory while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetManufactory++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetManufactory *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetCommunity(const void *pV1, const void *pV2)
{
	CSysNetCommunity *p1,*p2;
	p1=(CSysNetCommunity *)pV1;
	p2=(CSysNetCommunity *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetCommunity=0;
#endif

CSysNetCommunity *CSysNetCommunityFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetCommunity while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetCommunity++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetCommunity *theSysNetCommunity;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetCommunity=(CSysNetCommunity *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetCommunity;
}

CSysNetCommunity *CSysNetCommunityFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetCommunity++;
#endif
	CSysNetCommunity *theSysNetCommunity;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetCommunity=(CSysNetCommunity *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetCommunity;
}

void CSysNetCommunityFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetCommunity=0;
#endif
CSysNetCommunity *CSysNetCommunityFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetCommunity while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetCommunity++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetCommunity *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetPortType(const void *pV1, const void *pV2)
{
	CSysNetPortType *p1,*p2;
	p1=(CSysNetPortType *)pV1;
	p2=(CSysNetPortType *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetPortType=0;
#endif

CSysNetPortType *CSysNetPortTypeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetPortType while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPortType++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetPortType *theSysNetPortType;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetPortType=(CSysNetPortType *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetPortType;
}

CSysNetPortType *CSysNetPortTypeFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPortType++;
#endif
	CSysNetPortType *theSysNetPortType;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetPortType=(CSysNetPortType *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetPortType;
}

void CSysNetPortTypeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetPortType=0;
#endif
CSysNetPortType *CSysNetPortTypeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetPortType while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetPortType++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetPortType *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetInterface(const void *pV1, const void *pV2)
{
	CSysNetInterface *p1,*p2;
	p1=(CSysNetInterface *)pV1;
	p2=(CSysNetInterface *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysDeviceIDTypeIndexinSysNetInterface(const void *pV1, const void *pV2)
{
	CSysNetInterface *p1,*p2;
	p1=(CSysNetInterface *)pV1;
	p2=(CSysNetInterface *)pV2;
	switch (compare(p1->DeviceID.getValue(),p2->DeviceID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysObjectIDTypeIndexinSysNetInterface(const void *pV1, const void *pV2)
{
	CSysNetInterface *p1,*p2;
	p1=(CSysNetInterface *)pV1;
	p2=(CSysNetInterface *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetInterface=0;
#endif

CSysNetInterface *CSysNetInterfaceFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetInterface while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetInterface++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetInterface *theSysNetInterface;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetInterface=(CSysNetInterface *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetInterface;
}

CSysNetInterface *CSysNetInterfaceFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetInterface++;
#endif
	CSysNetInterface *theSysNetInterface;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetInterface=(CSysNetInterface *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetInterface;
}

void CSysNetInterfaceFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetInterface=0;
#endif
CSysNetInterface *CSysNetInterfaceFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetInterface while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetInterface++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetInterface *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByDeviceIDForSysNetInterface=0;
#endif

CSysNetInterface *CSysNetInterfaceFactory::startFindByDeviceID( const CReadOnlyVolumeType& DeviceID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDeviceID of CSysNetInterface while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDeviceID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDeviceID();
	}

	///记录所有的查询值
	queryDeviceIDInSearchByDeviceID= DeviceID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDeviceIDForSysNetInterface++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetInterface *theSysNetInterface;
	compareObject.DeviceID=DeviceID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDeviceID=pSysDeviceIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDeviceID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetInterface=(CSysNetInterface *)(pLastFoundInSearchByDeviceID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetInterface->DeviceID.getValue(),DeviceID.getValue()))
	{
		pLastFoundInSearchByDeviceID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetInterface;
}

CSysNetInterface *CSysNetInterfaceFactory::findNextByDeviceID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDeviceID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDeviceIDForSysNetInterface++;
#endif
	CSysNetInterface *theSysNetInterface;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDeviceID=pSysDeviceIDTypeIndex->getNextNode(pLastFoundInSearchByDeviceID);
	if (pLastFoundInSearchByDeviceID==NULL)
	{
		return NULL;
	}

	theSysNetInterface=(CSysNetInterface *)(pLastFoundInSearchByDeviceID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetInterface->DeviceID,queryDeviceIDInSearchByDeviceID))
	{
		pLastFoundInSearchByDeviceID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetInterface;
}

void CSysNetInterfaceFactory::endFindByDeviceID(void)
{
	pLastFoundInSearchByDeviceID=NULL;
}


#ifdef COUNT_SEARCH
int findByObjectIDForSysNetInterface=0;
#endif
CSysNetInterface *CSysNetInterfaceFactory::findByObjectID( const CReadOnlyNetObjectIDType&  ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByObjectID of CSysNetInterface while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByObjectIDForSysNetInterface++;
#endif
	CAVLNode *pNode;
	compareObject.ObjectID=ObjectID.getValue();
	pNode=pSysObjectIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetInterface *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetGeneralOID(const void *pV1, const void *pV2)
{
	CSysNetGeneralOID *p1,*p2;
	p1=(CSysNetGeneralOID *)pV1;
	p2=(CSysNetGeneralOID *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetGeneralOID=0;
#endif

CSysNetGeneralOID *CSysNetGeneralOIDFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetGeneralOID while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetGeneralOID++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetGeneralOID *theSysNetGeneralOID;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetGeneralOID=(CSysNetGeneralOID *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetGeneralOID;
}

CSysNetGeneralOID *CSysNetGeneralOIDFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetGeneralOID++;
#endif
	CSysNetGeneralOID *theSysNetGeneralOID;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetGeneralOID=(CSysNetGeneralOID *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetGeneralOID;
}

void CSysNetGeneralOIDFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetGeneralOID=0;
#endif
CSysNetGeneralOID *CSysNetGeneralOIDFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetGeneralOID while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetGeneralOID++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetGeneralOID *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorType(const void *pV1, const void *pV2)
{
	CSysNetMonitorType *p1,*p2;
	p1=(CSysNetMonitorType *)pV1;
	p2=(CSysNetMonitorType *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorType=0;
#endif

CSysNetMonitorType *CSysNetMonitorTypeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorType while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorType++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorType *theSysNetMonitorType;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorType=(CSysNetMonitorType *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorType;
}

CSysNetMonitorType *CSysNetMonitorTypeFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorType++;
#endif
	CSysNetMonitorType *theSysNetMonitorType;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorType=(CSysNetMonitorType *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorType;
}

void CSysNetMonitorTypeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetMonitorType=0;
#endif
CSysNetMonitorType *CSysNetMonitorTypeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetMonitorType while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetMonitorType++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetMonitorType *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorAttrScope(const void *pV1, const void *pV2)
{
	CSysNetMonitorAttrScope *p1,*p2;
	p1=(CSysNetMonitorAttrScope *)pV1;
	p2=(CSysNetMonitorAttrScope *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorAttrScope=0;
#endif

CSysNetMonitorAttrScope *CSysNetMonitorAttrScopeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorAttrScope while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorAttrScope++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorAttrScope *theSysNetMonitorAttrScope;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorAttrScope=(CSysNetMonitorAttrScope *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorAttrScope;
}

CSysNetMonitorAttrScope *CSysNetMonitorAttrScopeFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorAttrScope++;
#endif
	CSysNetMonitorAttrScope *theSysNetMonitorAttrScope;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorAttrScope=(CSysNetMonitorAttrScope *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorAttrScope;
}

void CSysNetMonitorAttrScopeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetMonitorAttrScope=0;
#endif
CSysNetMonitorAttrScope *CSysNetMonitorAttrScopeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetMonitorAttrScope while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetMonitorAttrScope++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetMonitorAttrScope *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorAttrType(const void *pV1, const void *pV2)
{
	CSysNetMonitorAttrType *p1,*p2;
	p1=(CSysNetMonitorAttrType *)pV1;
	p2=(CSysNetMonitorAttrType *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorAttrType=0;
#endif

CSysNetMonitorAttrType *CSysNetMonitorAttrTypeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorAttrType while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorAttrType++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorAttrType *theSysNetMonitorAttrType;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorAttrType=(CSysNetMonitorAttrType *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorAttrType;
}

CSysNetMonitorAttrType *CSysNetMonitorAttrTypeFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorAttrType++;
#endif
	CSysNetMonitorAttrType *theSysNetMonitorAttrType;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorAttrType=(CSysNetMonitorAttrType *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorAttrType;
}

void CSysNetMonitorAttrTypeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetMonitorAttrType=0;
#endif
CSysNetMonitorAttrType *CSysNetMonitorAttrTypeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetMonitorAttrType while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetMonitorAttrType++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetMonitorAttrType *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorCommandType(const void *pV1, const void *pV2)
{
	CSysNetMonitorCommandType *p1,*p2;
	p1=(CSysNetMonitorCommandType *)pV1;
	p2=(CSysNetMonitorCommandType *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorCommandType=0;
#endif

CSysNetMonitorCommandType *CSysNetMonitorCommandTypeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorCommandType while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorCommandType++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorCommandType *theSysNetMonitorCommandType;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorCommandType=(CSysNetMonitorCommandType *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorCommandType;
}

CSysNetMonitorCommandType *CSysNetMonitorCommandTypeFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorCommandType++;
#endif
	CSysNetMonitorCommandType *theSysNetMonitorCommandType;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorCommandType=(CSysNetMonitorCommandType *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorCommandType;
}

void CSysNetMonitorCommandTypeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetMonitorCommandType=0;
#endif
CSysNetMonitorCommandType *CSysNetMonitorCommandTypeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetMonitorCommandType while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetMonitorCommandType++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetMonitorCommandType *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorActionGroup(const void *pV1, const void *pV2)
{
	CSysNetMonitorActionGroup *p1,*p2;
	p1=(CSysNetMonitorActionGroup *)pV1;
	p2=(CSysNetMonitorActionGroup *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorActionGroup=0;
#endif

CSysNetMonitorActionGroup *CSysNetMonitorActionGroupFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorActionGroup while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorActionGroup++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorActionGroup *theSysNetMonitorActionGroup;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorActionGroup=(CSysNetMonitorActionGroup *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorActionGroup;
}

CSysNetMonitorActionGroup *CSysNetMonitorActionGroupFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorActionGroup++;
#endif
	CSysNetMonitorActionGroup *theSysNetMonitorActionGroup;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorActionGroup=(CSysNetMonitorActionGroup *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorActionGroup;
}

void CSysNetMonitorActionGroupFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetMonitorActionGroup=0;
#endif
CSysNetMonitorActionGroup *CSysNetMonitorActionGroupFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetMonitorActionGroup while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetMonitorActionGroup++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetMonitorActionGroup *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorDeviceGroup(const void *pV1, const void *pV2)
{
	CSysNetMonitorDeviceGroup *p1,*p2;
	p1=(CSysNetMonitorDeviceGroup *)pV1;
	p2=(CSysNetMonitorDeviceGroup *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorDeviceGroup=0;
#endif

CSysNetMonitorDeviceGroup *CSysNetMonitorDeviceGroupFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorDeviceGroup while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorDeviceGroup++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorDeviceGroup *theSysNetMonitorDeviceGroup;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorDeviceGroup=(CSysNetMonitorDeviceGroup *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorDeviceGroup;
}

CSysNetMonitorDeviceGroup *CSysNetMonitorDeviceGroupFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorDeviceGroup++;
#endif
	CSysNetMonitorDeviceGroup *theSysNetMonitorDeviceGroup;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorDeviceGroup=(CSysNetMonitorDeviceGroup *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorDeviceGroup;
}

void CSysNetMonitorDeviceGroupFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetMonitorDeviceGroup=0;
#endif
CSysNetMonitorDeviceGroup *CSysNetMonitorDeviceGroupFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetMonitorDeviceGroup while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetMonitorDeviceGroup++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetMonitorDeviceGroup *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorTaskInfo(const void *pV1, const void *pV2)
{
	CSysNetMonitorTaskInfo *p1,*p2;
	p1=(CSysNetMonitorTaskInfo *)pV1;
	p2=(CSysNetMonitorTaskInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorTaskInfo=0;
#endif

CSysNetMonitorTaskInfo *CSysNetMonitorTaskInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorTaskInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorTaskInfo *theSysNetMonitorTaskInfo;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorTaskInfo=(CSysNetMonitorTaskInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorTaskInfo;
}

CSysNetMonitorTaskInfo *CSysNetMonitorTaskInfoFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskInfo++;
#endif
	CSysNetMonitorTaskInfo *theSysNetMonitorTaskInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskInfo=(CSysNetMonitorTaskInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorTaskInfo;
}

void CSysNetMonitorTaskInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetMonitorTaskInfo=0;
#endif
CSysNetMonitorTaskInfo *CSysNetMonitorTaskInfoFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetMonitorTaskInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetMonitorTaskInfo++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetMonitorTaskInfo *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorTaskObjectSet(const void *pV1, const void *pV2)
{
	CSysNetMonitorTaskObjectSet *p1,*p2;
	p1=(CSysNetMonitorTaskObjectSet *)pV1;
	p2=(CSysNetMonitorTaskObjectSet *)pV2;
	switch (compare(p1->DeviceGroup_ID.getValue(),p2->DeviceGroup_ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorTaskObjectSet=0;
#endif

CSysNetMonitorTaskObjectSet *CSysNetMonitorTaskObjectSetFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorTaskObjectSet while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskObjectSet++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorTaskObjectSet *theSysNetMonitorTaskObjectSet;
	compareObject.DeviceGroup_ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorTaskObjectSet=(CSysNetMonitorTaskObjectSet *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorTaskObjectSet;
}

CSysNetMonitorTaskObjectSet *CSysNetMonitorTaskObjectSetFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskObjectSet++;
#endif
	CSysNetMonitorTaskObjectSet *theSysNetMonitorTaskObjectSet;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskObjectSet=(CSysNetMonitorTaskObjectSet *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorTaskObjectSet;
}

void CSysNetMonitorTaskObjectSetFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDeviceGroup_IDForSysNetMonitorTaskObjectSet=0;
#endif

CSysNetMonitorTaskObjectSet *CSysNetMonitorTaskObjectSetFactory::startFindByDeviceGroup_ID( const CReadOnlyVolumeType& DeviceGroup_ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDeviceGroup_ID of CSysNetMonitorTaskObjectSet while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDeviceGroup_ID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDeviceGroup_ID();
	}

	///记录所有的查询值
	queryDeviceGroup_IDInSearchByDeviceGroup_ID= DeviceGroup_ID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDeviceGroup_IDForSysNetMonitorTaskObjectSet++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorTaskObjectSet *theSysNetMonitorTaskObjectSet;
	compareObject.DeviceGroup_ID=DeviceGroup_ID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDeviceGroup_ID=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDeviceGroup_ID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorTaskObjectSet=(CSysNetMonitorTaskObjectSet *)(pLastFoundInSearchByDeviceGroup_ID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetMonitorTaskObjectSet->DeviceGroup_ID.getValue(),DeviceGroup_ID.getValue()))
	{
		pLastFoundInSearchByDeviceGroup_ID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetMonitorTaskObjectSet;
}

CSysNetMonitorTaskObjectSet *CSysNetMonitorTaskObjectSetFactory::findNextByDeviceGroup_ID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDeviceGroup_ID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDeviceGroup_IDForSysNetMonitorTaskObjectSet++;
#endif
	CSysNetMonitorTaskObjectSet *theSysNetMonitorTaskObjectSet;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDeviceGroup_ID=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDeviceGroup_ID);
	if (pLastFoundInSearchByDeviceGroup_ID==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskObjectSet=(CSysNetMonitorTaskObjectSet *)(pLastFoundInSearchByDeviceGroup_ID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetMonitorTaskObjectSet->DeviceGroup_ID,queryDeviceGroup_IDInSearchByDeviceGroup_ID))
	{
		pLastFoundInSearchByDeviceGroup_ID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetMonitorTaskObjectSet;
}

void CSysNetMonitorTaskObjectSetFactory::endFindByDeviceGroup_ID(void)
{
	pLastFoundInSearchByDeviceGroup_ID=NULL;
}

int compareForSysTaskIndexinSysNetMonitorTaskResult(const void *pV1, const void *pV2)
{
	CSysNetMonitorTaskResult *p1,*p2;
	p1=(CSysNetMonitorTaskResult *)pV1;
	p2=(CSysNetMonitorTaskResult *)pV2;
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->Task_ID.getValue(),p2->Task_ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->OperateTime.getValue(),p2->OperateTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorTaskResult=0;
#endif

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorTaskResult while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskResult++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;
	compareObject.MonDate="zzzzzzzz";
	compareObject.Task_ID=-10;
	compareObject.ObjectID="";
	compareObject.OperateTime=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysTaskIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorTaskResult;
}

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskResult++;
#endif
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysTaskIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorTaskResult;
}

void CSysNetMonitorTaskResultFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByTask_IDForSysNetMonitorTaskResult=0;
#endif

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::startFindByTask_ID( const CReadOnlyDateType& MonDate,  const CReadOnlyVolumeType& Task_ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTask_ID of CSysNetMonitorTaskResult while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByTask_ID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTask_ID();
	}

	///记录所有的查询值
	queryMonDateInSearchByTask_ID= MonDate.getValue();
	queryTask_IDInSearchByTask_ID= Task_ID.getValue();

#ifdef COUNT_SEARCH
	multiFindByTask_IDForSysNetMonitorTaskResult++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;
	compareObject.MonDate=MonDate.getValue();
	compareObject.Task_ID=Task_ID.getValue();
	compareObject.ObjectID="";
	compareObject.OperateTime=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByTask_ID=pSysTaskIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByTask_ID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByTask_ID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetMonitorTaskResult->MonDate.getValue(),MonDate.getValue()))
	{
		pLastFoundInSearchByTask_ID=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->Task_ID.getValue(),Task_ID.getValue()))
	{
		pLastFoundInSearchByTask_ID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetMonitorTaskResult;
}

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::findNextByTask_ID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByTask_ID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTask_IDForSysNetMonitorTaskResult++;
#endif
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByTask_ID=pSysTaskIndex->getNextNode(pLastFoundInSearchByTask_ID);
	if (pLastFoundInSearchByTask_ID==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByTask_ID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetMonitorTaskResult->MonDate,queryMonDateInSearchByTask_ID))
	{
		pLastFoundInSearchByTask_ID=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->Task_ID,queryTask_IDInSearchByTask_ID))
	{
		pLastFoundInSearchByTask_ID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetMonitorTaskResult;
}

void CSysNetMonitorTaskResultFactory::endFindByTask_ID(void)
{
	pLastFoundInSearchByTask_ID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByOnlyDateForSysNetMonitorTaskResult=0;
#endif

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::startFindByOnlyDate( const CReadOnlyDateType& MonDate)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByOnlyDate of CSysNetMonitorTaskResult while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByOnlyDate!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByOnlyDate();
	}

	///记录所有的查询值
	queryMonDateInSearchByOnlyDate= MonDate.getValue();

#ifdef COUNT_SEARCH
	multiFindByOnlyDateForSysNetMonitorTaskResult++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;
	compareObject.MonDate=MonDate.getValue();
	compareObject.Task_ID=-10;
	compareObject.ObjectID="";
	compareObject.OperateTime=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByOnlyDate=pSysTaskIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByOnlyDate==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByOnlyDate->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetMonitorTaskResult->MonDate.getValue(),MonDate.getValue()))
	{
		pLastFoundInSearchByOnlyDate=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetMonitorTaskResult;
}

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::findNextByOnlyDate(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByOnlyDate==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByOnlyDateForSysNetMonitorTaskResult++;
#endif
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByOnlyDate=pSysTaskIndex->getNextNode(pLastFoundInSearchByOnlyDate);
	if (pLastFoundInSearchByOnlyDate==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByOnlyDate->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetMonitorTaskResult->MonDate,queryMonDateInSearchByOnlyDate))
	{
		pLastFoundInSearchByOnlyDate=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetMonitorTaskResult;
}

void CSysNetMonitorTaskResultFactory::endFindByOnlyDate(void)
{
	pLastFoundInSearchByOnlyDate=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByIDTaskTimeForSysNetMonitorTaskResult=0;
#endif

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::startFindByIDTaskTime( const CReadOnlyDateType& MonDate,  const CReadOnlyVolumeType& Task_ID,  const CReadOnlyNetObjectIDType& ObjectID,  const CReadOnlyVolumeType& OperateTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIDTaskTime of CSysNetMonitorTaskResult while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByIDTaskTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIDTaskTime();
	}

	///记录所有的查询值
	queryMonDateInSearchByIDTaskTime= MonDate.getValue();
	queryTask_IDInSearchByIDTaskTime= Task_ID.getValue();
	queryObjectIDInSearchByIDTaskTime= ObjectID.getValue();
	queryOperateTimeInSearchByIDTaskTime= OperateTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDTaskTimeForSysNetMonitorTaskResult++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;
	compareObject.MonDate=MonDate.getValue();
	compareObject.Task_ID=Task_ID.getValue();
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.OperateTime=OperateTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByIDTaskTime=pSysTaskIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByIDTaskTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByIDTaskTime->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetMonitorTaskResult->MonDate.getValue(),MonDate.getValue()))
	{
		pLastFoundInSearchByIDTaskTime=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->Task_ID.getValue(),Task_ID.getValue()))
	{
		pLastFoundInSearchByIDTaskTime=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByIDTaskTime=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->OperateTime.getValue(),OperateTime.getValue()))
	{
		pLastFoundInSearchByIDTaskTime=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetMonitorTaskResult;
}

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::findNextByIDTaskTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByIDTaskTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDTaskTimeForSysNetMonitorTaskResult++;
#endif
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByIDTaskTime=pSysTaskIndex->getNextNode(pLastFoundInSearchByIDTaskTime);
	if (pLastFoundInSearchByIDTaskTime==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByIDTaskTime->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetMonitorTaskResult->MonDate,queryMonDateInSearchByIDTaskTime))
	{
		pLastFoundInSearchByIDTaskTime=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->Task_ID,queryTask_IDInSearchByIDTaskTime))
	{
		pLastFoundInSearchByIDTaskTime=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->ObjectID,queryObjectIDInSearchByIDTaskTime))
	{
		pLastFoundInSearchByIDTaskTime=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->OperateTime,queryOperateTimeInSearchByIDTaskTime))
	{
		pLastFoundInSearchByIDTaskTime=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetMonitorTaskResult;
}

void CSysNetMonitorTaskResultFactory::endFindByIDTaskTime(void)
{
	pLastFoundInSearchByIDTaskTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysNetMonitorTaskResult=0;
#endif

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::startFindByDataDelete( const CReadOnlyDateType& MonDate,  const CReadOnlyVolumeType& Task_ID,  const CReadOnlyNetObjectIDType& ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysNetMonitorTaskResult while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///记录所有的查询值
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryTask_IDInSearchByDataDelete= Task_ID.getValue();
	queryObjectIDInSearchByDataDelete= ObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysNetMonitorTaskResult++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;
	compareObject.MonDate=MonDate.getValue();
	compareObject.Task_ID=Task_ID.getValue();
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.OperateTime=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDataDelete=pSysTaskIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetMonitorTaskResult->MonDate.getValue(),MonDate.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->Task_ID.getValue(),Task_ID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetMonitorTaskResult;
}

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::findNextByDataDelete(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysNetMonitorTaskResult++;
#endif
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDataDelete=pSysTaskIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetMonitorTaskResult->MonDate,queryMonDateInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->Task_ID,queryTask_IDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->ObjectID,queryObjectIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetMonitorTaskResult;
}

void CSysNetMonitorTaskResultFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysIDTypeIndexinSysNetPartyLinkInfo(const void *pV1, const void *pV2)
{
	CSysNetPartyLinkInfo *p1,*p2;
	p1=(CSysNetPartyLinkInfo *)pV1;
	p2=(CSysNetPartyLinkInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetPartyLinkInfo=0;
#endif

CSysNetPartyLinkInfo *CSysNetPartyLinkInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetPartyLinkInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPartyLinkInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetPartyLinkInfo *theSysNetPartyLinkInfo;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetPartyLinkInfo=(CSysNetPartyLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetPartyLinkInfo;
}

CSysNetPartyLinkInfo *CSysNetPartyLinkInfoFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPartyLinkInfo++;
#endif
	CSysNetPartyLinkInfo *theSysNetPartyLinkInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetPartyLinkInfo=(CSysNetPartyLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetPartyLinkInfo;
}

void CSysNetPartyLinkInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetPartyLinkInfo=0;
#endif
CSysNetPartyLinkInfo *CSysNetPartyLinkInfoFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetPartyLinkInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetPartyLinkInfo++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetPartyLinkInfo *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetDelPartyLinkInfo(const void *pV1, const void *pV2)
{
	CSysNetDelPartyLinkInfo *p1,*p2;
	p1=(CSysNetDelPartyLinkInfo *)pV1;
	p2=(CSysNetDelPartyLinkInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetDelPartyLinkInfo=0;
#endif

CSysNetDelPartyLinkInfo *CSysNetDelPartyLinkInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetDelPartyLinkInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDelPartyLinkInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetDelPartyLinkInfo *theSysNetDelPartyLinkInfo;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetDelPartyLinkInfo=(CSysNetDelPartyLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetDelPartyLinkInfo;
}

CSysNetDelPartyLinkInfo *CSysNetDelPartyLinkInfoFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDelPartyLinkInfo++;
#endif
	CSysNetDelPartyLinkInfo *theSysNetDelPartyLinkInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetDelPartyLinkInfo=(CSysNetDelPartyLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetDelPartyLinkInfo;
}

void CSysNetDelPartyLinkInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetDelPartyLinkInfo=0;
#endif
CSysNetDelPartyLinkInfo *CSysNetDelPartyLinkInfoFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetDelPartyLinkInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetDelPartyLinkInfo++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetDelPartyLinkInfo *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetPartyLinkAddrChange(const void *pV1, const void *pV2)
{
	CSysNetPartyLinkAddrChange *p1,*p2;
	p1=(CSysNetPartyLinkAddrChange *)pV1;
	p2=(CSysNetPartyLinkAddrChange *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetPartyLinkAddrChange=0;
#endif

CSysNetPartyLinkAddrChange *CSysNetPartyLinkAddrChangeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetPartyLinkAddrChange while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPartyLinkAddrChange++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetPartyLinkAddrChange *theSysNetPartyLinkAddrChange;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetPartyLinkAddrChange=(CSysNetPartyLinkAddrChange *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetPartyLinkAddrChange;
}

CSysNetPartyLinkAddrChange *CSysNetPartyLinkAddrChangeFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPartyLinkAddrChange++;
#endif
	CSysNetPartyLinkAddrChange *theSysNetPartyLinkAddrChange;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetPartyLinkAddrChange=(CSysNetPartyLinkAddrChange *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetPartyLinkAddrChange;
}

void CSysNetPartyLinkAddrChangeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetPartyLinkAddrChange=0;
#endif
CSysNetPartyLinkAddrChange *CSysNetPartyLinkAddrChangeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetPartyLinkAddrChange while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetPartyLinkAddrChange++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetPartyLinkAddrChange *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorActionAttr(const void *pV1, const void *pV2)
{
	CSysNetMonitorActionAttr *p1,*p2;
	p1=(CSysNetMonitorActionAttr *)pV1;
	p2=(CSysNetMonitorActionAttr *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorActionAttr=0;
#endif

CSysNetMonitorActionAttr *CSysNetMonitorActionAttrFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorActionAttr while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorActionAttr++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorActionAttr *theSysNetMonitorActionAttr;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorActionAttr=(CSysNetMonitorActionAttr *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorActionAttr;
}

CSysNetMonitorActionAttr *CSysNetMonitorActionAttrFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorActionAttr++;
#endif
	CSysNetMonitorActionAttr *theSysNetMonitorActionAttr;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorActionAttr=(CSysNetMonitorActionAttr *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorActionAttr;
}

void CSysNetMonitorActionAttrFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetMonitorActionAttr=0;
#endif
CSysNetMonitorActionAttr *CSysNetMonitorActionAttrFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetMonitorActionAttr while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetMonitorActionAttr++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetMonitorActionAttr *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetModule(const void *pV1, const void *pV2)
{
	CSysNetModule *p1,*p2;
	p1=(CSysNetModule *)pV1;
	p2=(CSysNetModule *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysDeviceIDTypeIndexinSysNetModule(const void *pV1, const void *pV2)
{
	CSysNetModule *p1,*p2;
	p1=(CSysNetModule *)pV1;
	p2=(CSysNetModule *)pV2;
	switch (compare(p1->DeviceID.getValue(),p2->DeviceID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysObjectIDTypeIndexinSysNetModule(const void *pV1, const void *pV2)
{
	CSysNetModule *p1,*p2;
	p1=(CSysNetModule *)pV1;
	p2=(CSysNetModule *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetModule=0;
#endif

CSysNetModule *CSysNetModuleFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetModule while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetModule++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetModule *theSysNetModule;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetModule=(CSysNetModule *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetModule;
}

CSysNetModule *CSysNetModuleFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetModule++;
#endif
	CSysNetModule *theSysNetModule;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetModule=(CSysNetModule *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetModule;
}

void CSysNetModuleFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetModule=0;
#endif
CSysNetModule *CSysNetModuleFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetModule while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetModule++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetModule *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByDeviceIDForSysNetModule=0;
#endif

CSysNetModule *CSysNetModuleFactory::startFindByDeviceID( const CReadOnlyVolumeType& DeviceID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDeviceID of CSysNetModule while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDeviceID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDeviceID();
	}

	///记录所有的查询值
	queryDeviceIDInSearchByDeviceID= DeviceID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDeviceIDForSysNetModule++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetModule *theSysNetModule;
	compareObject.DeviceID=DeviceID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDeviceID=pSysDeviceIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDeviceID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetModule=(CSysNetModule *)(pLastFoundInSearchByDeviceID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetModule->DeviceID.getValue(),DeviceID.getValue()))
	{
		pLastFoundInSearchByDeviceID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetModule;
}

CSysNetModule *CSysNetModuleFactory::findNextByDeviceID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDeviceID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDeviceIDForSysNetModule++;
#endif
	CSysNetModule *theSysNetModule;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDeviceID=pSysDeviceIDTypeIndex->getNextNode(pLastFoundInSearchByDeviceID);
	if (pLastFoundInSearchByDeviceID==NULL)
	{
		return NULL;
	}

	theSysNetModule=(CSysNetModule *)(pLastFoundInSearchByDeviceID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetModule->DeviceID,queryDeviceIDInSearchByDeviceID))
	{
		pLastFoundInSearchByDeviceID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetModule;
}

void CSysNetModuleFactory::endFindByDeviceID(void)
{
	pLastFoundInSearchByDeviceID=NULL;
}


#ifdef COUNT_SEARCH
int findByObjectIDForSysNetModule=0;
#endif
CSysNetModule *CSysNetModuleFactory::findByObjectID( const CReadOnlyNetObjectIDType&  ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByObjectID of CSysNetModule while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByObjectIDForSysNetModule++;
#endif
	CAVLNode *pNode;
	compareObject.ObjectID=ObjectID.getValue();
	pNode=pSysObjectIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetModule *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetEventExpr(const void *pV1, const void *pV2)
{
	CSysNetEventExpr *p1,*p2;
	p1=(CSysNetEventExpr *)pV1;
	p2=(CSysNetEventExpr *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetEventExpr=0;
#endif

CSysNetEventExpr *CSysNetEventExprFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetEventExpr while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetEventExpr++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetEventExpr *theSysNetEventExpr;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetEventExpr=(CSysNetEventExpr *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetEventExpr;
}

CSysNetEventExpr *CSysNetEventExprFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetEventExpr++;
#endif
	CSysNetEventExpr *theSysNetEventExpr;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetEventExpr=(CSysNetEventExpr *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetEventExpr;
}

void CSysNetEventExprFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetEventExpr=0;
#endif
CSysNetEventExpr *CSysNetEventExprFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetEventExpr while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetEventExpr++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetEventExpr *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetEventType(const void *pV1, const void *pV2)
{
	CSysNetEventType *p1,*p2;
	p1=(CSysNetEventType *)pV1;
	p2=(CSysNetEventType *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetEventType=0;
#endif

CSysNetEventType *CSysNetEventTypeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetEventType while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetEventType++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetEventType *theSysNetEventType;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetEventType=(CSysNetEventType *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetEventType;
}

CSysNetEventType *CSysNetEventTypeFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetEventType++;
#endif
	CSysNetEventType *theSysNetEventType;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetEventType=(CSysNetEventType *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetEventType;
}

void CSysNetEventTypeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetEventType=0;
#endif
CSysNetEventType *CSysNetEventTypeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetEventType while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetEventType++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetEventType *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetSubEventType(const void *pV1, const void *pV2)
{
	CSysNetSubEventType *p1,*p2;
	p1=(CSysNetSubEventType *)pV1;
	p2=(CSysNetSubEventType *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetSubEventType=0;
#endif

CSysNetSubEventType *CSysNetSubEventTypeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetSubEventType while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetSubEventType++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetSubEventType *theSysNetSubEventType;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetSubEventType=(CSysNetSubEventType *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetSubEventType;
}

CSysNetSubEventType *CSysNetSubEventTypeFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetSubEventType++;
#endif
	CSysNetSubEventType *theSysNetSubEventType;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetSubEventType=(CSysNetSubEventType *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetSubEventType;
}

void CSysNetSubEventTypeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetSubEventType=0;
#endif
CSysNetSubEventType *CSysNetSubEventTypeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetSubEventType while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetSubEventType++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetSubEventType *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetEventLevel(const void *pV1, const void *pV2)
{
	CSysNetEventLevel *p1,*p2;
	p1=(CSysNetEventLevel *)pV1;
	p2=(CSysNetEventLevel *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetEventLevel=0;
#endif

CSysNetEventLevel *CSysNetEventLevelFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetEventLevel while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetEventLevel++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetEventLevel *theSysNetEventLevel;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetEventLevel=(CSysNetEventLevel *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetEventLevel;
}

CSysNetEventLevel *CSysNetEventLevelFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetEventLevel++;
#endif
	CSysNetEventLevel *theSysNetEventLevel;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetEventLevel=(CSysNetEventLevel *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetEventLevel;
}

void CSysNetEventLevelFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetEventLevel=0;
#endif
CSysNetEventLevel *CSysNetEventLevelFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetEventLevel while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetEventLevel++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetEventLevel *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorDeviceTask(const void *pV1, const void *pV2)
{
	CSysNetMonitorDeviceTask *p1,*p2;
	p1=(CSysNetMonitorDeviceTask *)pV1;
	p2=(CSysNetMonitorDeviceTask *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->SecondID.getValue(),p2->SecondID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorDeviceTask=0;
#endif

CSysNetMonitorDeviceTask *CSysNetMonitorDeviceTaskFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorDeviceTask while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorDeviceTask++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorDeviceTask *theSysNetMonitorDeviceTask;
	compareObject.ID=0;
	compareObject.SecondID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorDeviceTask=(CSysNetMonitorDeviceTask *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorDeviceTask;
}

CSysNetMonitorDeviceTask *CSysNetMonitorDeviceTaskFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorDeviceTask++;
#endif
	CSysNetMonitorDeviceTask *theSysNetMonitorDeviceTask;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorDeviceTask=(CSysNetMonitorDeviceTask *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorDeviceTask;
}

void CSysNetMonitorDeviceTaskFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByIDForSysNetMonitorDeviceTask=0;
#endif

CSysNetMonitorDeviceTask *CSysNetMonitorDeviceTaskFactory::startFindByID( const CReadOnlyVolumeType& ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByID of CSysNetMonitorDeviceTask while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByID();
	}

	///记录所有的查询值
	queryIDInSearchByID= ID.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDForSysNetMonitorDeviceTask++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorDeviceTask *theSysNetMonitorDeviceTask;
	compareObject.ID=ID.getValue();
	compareObject.SecondID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByID=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorDeviceTask=(CSysNetMonitorDeviceTask *)(pLastFoundInSearchByID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetMonitorDeviceTask->ID.getValue(),ID.getValue()))
	{
		pLastFoundInSearchByID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetMonitorDeviceTask;
}

CSysNetMonitorDeviceTask *CSysNetMonitorDeviceTaskFactory::findNextByID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDForSysNetMonitorDeviceTask++;
#endif
	CSysNetMonitorDeviceTask *theSysNetMonitorDeviceTask;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByID=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByID);
	if (pLastFoundInSearchByID==NULL)
	{
		return NULL;
	}

	theSysNetMonitorDeviceTask=(CSysNetMonitorDeviceTask *)(pLastFoundInSearchByID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetMonitorDeviceTask->ID,queryIDInSearchByID))
	{
		pLastFoundInSearchByID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetMonitorDeviceTask;
}

void CSysNetMonitorDeviceTaskFactory::endFindByID(void)
{
	pLastFoundInSearchByID=NULL;
}

int compareForSysIDTypeIndexinSysNetMonitorTaskInstAttrs(const void *pV1, const void *pV2)
{
	CSysNetMonitorTaskInstAttrs *p1,*p2;
	p1=(CSysNetMonitorTaskInstAttrs *)pV1;
	p2=(CSysNetMonitorTaskInstAttrs *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorTaskInstAttrs=0;
#endif

CSysNetMonitorTaskInstAttrs *CSysNetMonitorTaskInstAttrsFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorTaskInstAttrs while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskInstAttrs++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMonitorTaskInstAttrs *theSysNetMonitorTaskInstAttrs;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMonitorTaskInstAttrs=(CSysNetMonitorTaskInstAttrs *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorTaskInstAttrs;
}

CSysNetMonitorTaskInstAttrs *CSysNetMonitorTaskInstAttrsFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskInstAttrs++;
#endif
	CSysNetMonitorTaskInstAttrs *theSysNetMonitorTaskInstAttrs;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskInstAttrs=(CSysNetMonitorTaskInstAttrs *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMonitorTaskInstAttrs;
}

void CSysNetMonitorTaskInstAttrsFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysIDTypeIndexinSysNetBaseLine(const void *pV1, const void *pV2)
{
	CSysNetBaseLine *p1,*p2;
	p1=(CSysNetBaseLine *)pV1;
	p2=(CSysNetBaseLine *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetBaseLine=0;
#endif

CSysNetBaseLine *CSysNetBaseLineFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetBaseLine while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetBaseLine++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetBaseLine *theSysNetBaseLine;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetBaseLine=(CSysNetBaseLine *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetBaseLine;
}

CSysNetBaseLine *CSysNetBaseLineFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetBaseLine++;
#endif
	CSysNetBaseLine *theSysNetBaseLine;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetBaseLine=(CSysNetBaseLine *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetBaseLine;
}

void CSysNetBaseLineFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByIDForSysNetBaseLine=0;
#endif

CSysNetBaseLine *CSysNetBaseLineFactory::startFindByID( const CReadOnlyVolumeType& ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByID of CSysNetBaseLine while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByID();
	}

	///记录所有的查询值
	queryIDInSearchByID= ID.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDForSysNetBaseLine++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetBaseLine *theSysNetBaseLine;
	compareObject.ID=ID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByID=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetBaseLine=(CSysNetBaseLine *)(pLastFoundInSearchByID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetBaseLine->ID.getValue(),ID.getValue()))
	{
		pLastFoundInSearchByID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetBaseLine;
}

CSysNetBaseLine *CSysNetBaseLineFactory::findNextByID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDForSysNetBaseLine++;
#endif
	CSysNetBaseLine *theSysNetBaseLine;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByID=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByID);
	if (pLastFoundInSearchByID==NULL)
	{
		return NULL;
	}

	theSysNetBaseLine=(CSysNetBaseLine *)(pLastFoundInSearchByID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysNetBaseLine->ID,queryIDInSearchByID))
	{
		pLastFoundInSearchByID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysNetBaseLine;
}

void CSysNetBaseLineFactory::endFindByID(void)
{
	pLastFoundInSearchByID=NULL;
}

int compareForSysIDTypeIndexinSysNetBaseLineTask(const void *pV1, const void *pV2)
{
	CSysNetBaseLineTask *p1,*p2;
	p1=(CSysNetBaseLineTask *)pV1;
	p2=(CSysNetBaseLineTask *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetBaseLineTask=0;
#endif

CSysNetBaseLineTask *CSysNetBaseLineTaskFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetBaseLineTask while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetBaseLineTask++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetBaseLineTask *theSysNetBaseLineTask;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetBaseLineTask=(CSysNetBaseLineTask *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetBaseLineTask;
}

CSysNetBaseLineTask *CSysNetBaseLineTaskFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetBaseLineTask++;
#endif
	CSysNetBaseLineTask *theSysNetBaseLineTask;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetBaseLineTask=(CSysNetBaseLineTask *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetBaseLineTask;
}

void CSysNetBaseLineTaskFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysDateTimeIndexinSysMdbNetPartyLinkStatusInfo(const void *pV1, const void *pV2)
{
	CSysMdbNetPartyLinkStatusInfo *p1,*p2;
	p1=(CSysMdbNetPartyLinkStatusInfo *)pV1;
	p2=(CSysMdbNetPartyLinkStatusInfo *)pV2;
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbNetPartyLinkStatusInfo(const void *pV1, const void *pV2)
{
	CSysMdbNetPartyLinkStatusInfo *p1,*p2;
	p1=(CSysMdbNetPartyLinkStatusInfo *)pV1;
	p2=(CSysMdbNetPartyLinkStatusInfo *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByTimeForSysMdbNetPartyLinkStatusInfo=0;
#endif

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoFactory::startFindByTime( const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTime of CSysMdbNetPartyLinkStatusInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTime();
	}

	///记录所有的查询值
	queryMonDateInSearchByTime= MonDate.getValue();
	queryMonTimeInSearchByTime= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByTimeForSysMdbNetPartyLinkStatusInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbNetPartyLinkStatusInfo *theSysMdbNetPartyLinkStatusInfo;
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByTime=pSysDateTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbNetPartyLinkStatusInfo=(CSysMdbNetPartyLinkStatusInfo *)(pLastFoundInSearchByTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbNetPartyLinkStatusInfo;
}

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoFactory::findNextByTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTimeForSysMdbNetPartyLinkStatusInfo++;
#endif
	CSysMdbNetPartyLinkStatusInfo *theSysMdbNetPartyLinkStatusInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByTime=pSysDateTimeIndex->getNextNode(pLastFoundInSearchByTime);
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	theSysMdbNetPartyLinkStatusInfo=(CSysMdbNetPartyLinkStatusInfo *)(pLastFoundInSearchByTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbNetPartyLinkStatusInfo;
}

void CSysMdbNetPartyLinkStatusInfoFactory::endFindByTime(void)
{
	pLastFoundInSearchByTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbNetPartyLinkStatusInfo=0;
#endif

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoFactory::startFindByDsc( const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbNetPartyLinkStatusInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByDsc= SubcriberID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbNetPartyLinkStatusInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbNetPartyLinkStatusInfo *theSysMdbNetPartyLinkStatusInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbNetPartyLinkStatusInfo=(CSysMdbNetPartyLinkStatusInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbNetPartyLinkStatusInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbNetPartyLinkStatusInfo;
}

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbNetPartyLinkStatusInfo++;
#endif
	CSysMdbNetPartyLinkStatusInfo *theSysMdbNetPartyLinkStatusInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbNetPartyLinkStatusInfo=(CSysMdbNetPartyLinkStatusInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbNetPartyLinkStatusInfo->SubcriberID,querySubcriberIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbNetPartyLinkStatusInfo;
}

void CSysMdbNetPartyLinkStatusInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByAllForSysMdbNetPartyLinkStatusInfo=0;
#endif

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysMdbNetPartyLinkStatusInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysMdbNetPartyLinkStatusInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbNetPartyLinkStatusInfo *theSysMdbNetPartyLinkStatusInfo;
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysDateTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbNetPartyLinkStatusInfo=(CSysMdbNetPartyLinkStatusInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbNetPartyLinkStatusInfo;
}

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysMdbNetPartyLinkStatusInfo++;
#endif
	CSysMdbNetPartyLinkStatusInfo *theSysMdbNetPartyLinkStatusInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysDateTimeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysMdbNetPartyLinkStatusInfo=(CSysMdbNetPartyLinkStatusInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbNetPartyLinkStatusInfo;
}

void CSysMdbNetPartyLinkStatusInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysIDTypeIndexinSysNetMemberSDHLineInfo(const void *pV1, const void *pV2)
{
	CSysNetMemberSDHLineInfo *p1,*p2;
	p1=(CSysNetMemberSDHLineInfo *)pV1;
	p2=(CSysNetMemberSDHLineInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMemberSDHLineInfo=0;
#endif

CSysNetMemberSDHLineInfo *CSysNetMemberSDHLineInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMemberSDHLineInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMemberSDHLineInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetMemberSDHLineInfo *theSysNetMemberSDHLineInfo;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetMemberSDHLineInfo=(CSysNetMemberSDHLineInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMemberSDHLineInfo;
}

CSysNetMemberSDHLineInfo *CSysNetMemberSDHLineInfoFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMemberSDHLineInfo++;
#endif
	CSysNetMemberSDHLineInfo *theSysNetMemberSDHLineInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMemberSDHLineInfo=(CSysNetMemberSDHLineInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetMemberSDHLineInfo;
}

void CSysNetMemberSDHLineInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysIDTypeIndexinSysNetDDNLinkInfo(const void *pV1, const void *pV2)
{
	CSysNetDDNLinkInfo *p1,*p2;
	p1=(CSysNetDDNLinkInfo *)pV1;
	p2=(CSysNetDDNLinkInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetDDNLinkInfo=0;
#endif

CSysNetDDNLinkInfo *CSysNetDDNLinkInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetDDNLinkInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDDNLinkInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetDDNLinkInfo *theSysNetDDNLinkInfo;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetDDNLinkInfo=(CSysNetDDNLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetDDNLinkInfo;
}

CSysNetDDNLinkInfo *CSysNetDDNLinkInfoFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDDNLinkInfo++;
#endif
	CSysNetDDNLinkInfo *theSysNetDDNLinkInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetDDNLinkInfo=(CSysNetDDNLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetDDNLinkInfo;
}

void CSysNetDDNLinkInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysIDTypeIndexinSysNetPseudMemberLinkInfo(const void *pV1, const void *pV2)
{
	CSysNetPseudMemberLinkInfo *p1,*p2;
	p1=(CSysNetPseudMemberLinkInfo *)pV1;
	p2=(CSysNetPseudMemberLinkInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetPseudMemberLinkInfo=0;
#endif

CSysNetPseudMemberLinkInfo *CSysNetPseudMemberLinkInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetPseudMemberLinkInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPseudMemberLinkInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetPseudMemberLinkInfo *theSysNetPseudMemberLinkInfo;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetPseudMemberLinkInfo=(CSysNetPseudMemberLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetPseudMemberLinkInfo;
}

CSysNetPseudMemberLinkInfo *CSysNetPseudMemberLinkInfoFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPseudMemberLinkInfo++;
#endif
	CSysNetPseudMemberLinkInfo *theSysNetPseudMemberLinkInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetPseudMemberLinkInfo=(CSysNetPseudMemberLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetPseudMemberLinkInfo;
}

void CSysNetPseudMemberLinkInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysIDTypeIndexinSysNetOuterDeviceInfo(const void *pV1, const void *pV2)
{
	CSysNetOuterDeviceInfo *p1,*p2;
	p1=(CSysNetOuterDeviceInfo *)pV1;
	p2=(CSysNetOuterDeviceInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetOuterDeviceInfo=0;
#endif

CSysNetOuterDeviceInfo *CSysNetOuterDeviceInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetOuterDeviceInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetOuterDeviceInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetOuterDeviceInfo *theSysNetOuterDeviceInfo;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetOuterDeviceInfo=(CSysNetOuterDeviceInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetOuterDeviceInfo;
}

CSysNetOuterDeviceInfo *CSysNetOuterDeviceInfoFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetOuterDeviceInfo++;
#endif
	CSysNetOuterDeviceInfo *theSysNetOuterDeviceInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetOuterDeviceInfo=(CSysNetOuterDeviceInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetOuterDeviceInfo;
}

void CSysNetOuterDeviceInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysIDTypeIndexinSysLocalPingResultInfo(const void *pV1, const void *pV2)
{
	CSysLocalPingResultInfo *p1,*p2;
	p1=(CSysLocalPingResultInfo *)pV1;
	p2=(CSysLocalPingResultInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysLocalPingResultInfo=0;
#endif

CSysLocalPingResultInfo *CSysLocalPingResultInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysLocalPingResultInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysLocalPingResultInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysLocalPingResultInfo *theSysLocalPingResultInfo;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysLocalPingResultInfo=(CSysLocalPingResultInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysLocalPingResultInfo;
}

CSysLocalPingResultInfo *CSysLocalPingResultInfoFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysLocalPingResultInfo++;
#endif
	CSysLocalPingResultInfo *theSysLocalPingResultInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysLocalPingResultInfo=(CSysLocalPingResultInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysLocalPingResultInfo;
}

void CSysLocalPingResultInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByIDTypeForSysLocalPingResultInfo=0;
#endif

CSysLocalPingResultInfo *CSysLocalPingResultInfoFactory::startFindByIDType( const CReadOnlyVolumeType& ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIDType of CSysLocalPingResultInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByIDType!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIDType();
	}

	///记录所有的查询值
	queryIDInSearchByIDType= ID.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysLocalPingResultInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysLocalPingResultInfo *theSysLocalPingResultInfo;
	compareObject.ID=ID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByIDType=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysLocalPingResultInfo=(CSysLocalPingResultInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysLocalPingResultInfo->ID.getValue(),ID.getValue()))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysLocalPingResultInfo;
}

CSysLocalPingResultInfo *CSysLocalPingResultInfoFactory::findNextByIDType(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysLocalPingResultInfo++;
#endif
	CSysLocalPingResultInfo *theSysLocalPingResultInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByIDType=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByIDType);
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	theSysLocalPingResultInfo=(CSysLocalPingResultInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysLocalPingResultInfo->ID,queryIDInSearchByIDType))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysLocalPingResultInfo;
}

void CSysLocalPingResultInfoFactory::endFindByIDType(void)
{
	pLastFoundInSearchByIDType=NULL;
}

int compareForSysIDTypeIndexinSysRomotePingResultInfo(const void *pV1, const void *pV2)
{
	CSysRomotePingResultInfo *p1,*p2;
	p1=(CSysRomotePingResultInfo *)pV1;
	p2=(CSysRomotePingResultInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysRomotePingResultInfo=0;
#endif

CSysRomotePingResultInfo *CSysRomotePingResultInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysRomotePingResultInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysRomotePingResultInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysRomotePingResultInfo *theSysRomotePingResultInfo;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysRomotePingResultInfo=(CSysRomotePingResultInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysRomotePingResultInfo;
}

CSysRomotePingResultInfo *CSysRomotePingResultInfoFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysRomotePingResultInfo++;
#endif
	CSysRomotePingResultInfo *theSysRomotePingResultInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysRomotePingResultInfo=(CSysRomotePingResultInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysRomotePingResultInfo;
}

void CSysRomotePingResultInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByIDTypeForSysRomotePingResultInfo=0;
#endif

CSysRomotePingResultInfo *CSysRomotePingResultInfoFactory::startFindByIDType( const CReadOnlyVolumeType& ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIDType of CSysRomotePingResultInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByIDType!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIDType();
	}

	///记录所有的查询值
	queryIDInSearchByIDType= ID.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysRomotePingResultInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysRomotePingResultInfo *theSysRomotePingResultInfo;
	compareObject.ID=ID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByIDType=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysRomotePingResultInfo=(CSysRomotePingResultInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysRomotePingResultInfo->ID.getValue(),ID.getValue()))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysRomotePingResultInfo;
}

CSysRomotePingResultInfo *CSysRomotePingResultInfoFactory::findNextByIDType(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysRomotePingResultInfo++;
#endif
	CSysRomotePingResultInfo *theSysRomotePingResultInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByIDType=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByIDType);
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	theSysRomotePingResultInfo=(CSysRomotePingResultInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysRomotePingResultInfo->ID,queryIDInSearchByIDType))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysRomotePingResultInfo;
}

void CSysRomotePingResultInfoFactory::endFindByIDType(void)
{
	pLastFoundInSearchByIDType=NULL;
}

int compareForMemUsrIndexinSysParticTradeOrderStates(const void *pV1, const void *pV2)
{
	CSysParticTradeOrderStates *p1,*p2;
	p1=(CSysParticTradeOrderStates *)pV1;
	p2=(CSysParticTradeOrderStates *)pV2;
	switch (compare(p1->ParticipantID.getValue(),p2->ParticipantID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->UserID.getValue(),p2->UserID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysParticTradeOrderStates=0;
#endif

CSysParticTradeOrderStates *CSysParticTradeOrderStatesFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysParticTradeOrderStates while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysParticTradeOrderStates++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysParticTradeOrderStates *theSysParticTradeOrderStates;
	compareObject.ParticipantID="";
	compareObject.UserID="";
	compareObject.MonDate="";
	compareObject.MonTime="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pMemUsrIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysParticTradeOrderStates=(CSysParticTradeOrderStates *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysParticTradeOrderStates;
}

CSysParticTradeOrderStates *CSysParticTradeOrderStatesFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysParticTradeOrderStates++;
#endif
	CSysParticTradeOrderStates *theSysParticTradeOrderStates;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pMemUsrIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysParticTradeOrderStates=(CSysParticTradeOrderStates *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysParticTradeOrderStates;
}

void CSysParticTradeOrderStatesFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysParticTradeOrderStates=0;
#endif
CSysParticTradeOrderStates *CSysParticTradeOrderStatesFactory::findByOne( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyUserIDType&  UserID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysParticTradeOrderStates while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysParticTradeOrderStates++;
#endif
	CAVLNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.UserID=UserID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	pNode=pMemUsrIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysParticTradeOrderStates *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByUserIDForSysParticTradeOrderStates=0;
#endif

CSysParticTradeOrderStates *CSysParticTradeOrderStatesFactory::startFindByUserID( const CReadOnlyParticipantIDType& ParticipantID,  const CReadOnlyUserIDType& UserID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByUserID of CSysParticTradeOrderStates while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByUserID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByUserID();
	}

	///记录所有的查询值
	queryParticipantIDInSearchByUserID= ParticipantID.getValue();
	queryUserIDInSearchByUserID= UserID.getValue();
	queryMonDateInSearchByUserID= MonDate.getValue();
	queryMonTimeInSearchByUserID= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByUserIDForSysParticTradeOrderStates++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysParticTradeOrderStates *theSysParticTradeOrderStates;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.UserID=UserID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByUserID=pMemUsrIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysParticTradeOrderStates=(CSysParticTradeOrderStates *)(pLastFoundInSearchByUserID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysParticTradeOrderStates->ParticipantID.getValue(),ParticipantID.getValue()))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}
	if (compare(theSysParticTradeOrderStates->UserID.getValue(),UserID.getValue()))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysParticTradeOrderStates;
}

CSysParticTradeOrderStates *CSysParticTradeOrderStatesFactory::findNextByUserID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByUserIDForSysParticTradeOrderStates++;
#endif
	CSysParticTradeOrderStates *theSysParticTradeOrderStates;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByUserID=pMemUsrIndex->getNextNode(pLastFoundInSearchByUserID);
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

	theSysParticTradeOrderStates=(CSysParticTradeOrderStates *)(pLastFoundInSearchByUserID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysParticTradeOrderStates->ParticipantID,queryParticipantIDInSearchByUserID))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}
	if (compare(theSysParticTradeOrderStates->UserID,queryUserIDInSearchByUserID))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysParticTradeOrderStates;
}

void CSysParticTradeOrderStatesFactory::endFindByUserID(void)
{
	pLastFoundInSearchByUserID=NULL;
}

int compareForSysHostNameIndexinSysMdbRouterInfo(const void *pV1, const void *pV2)
{
	CSysMdbRouterInfo *p1,*p2;
	p1=(CSysMdbRouterInfo *)pV1;
	p2=(CSysMdbRouterInfo *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbRouterInfo(const void *pV1, const void *pV2)
{
	CSysMdbRouterInfo *p1,*p2;
	p1=(CSysMdbRouterInfo *)pV1;
	p2=(CSysMdbRouterInfo *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysMdbRouterInfo=0;
#endif

CSysMdbRouterInfo *CSysMdbRouterInfoFactory::startFindByHostName( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysMdbRouterInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByHostName= SubcriberID.getValue();
	queryMonDateInSearchByHostName= MonDate.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbRouterInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbRouterInfo *theSysMdbRouterInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbRouterInfo=(CSysMdbRouterInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbRouterInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbRouterInfo;
}

CSysMdbRouterInfo *CSysMdbRouterInfoFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbRouterInfo++;
#endif
	CSysMdbRouterInfo *theSysMdbRouterInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysMdbRouterInfo=(CSysMdbRouterInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbRouterInfo->SubcriberID,querySubcriberIDInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbRouterInfo;
}

void CSysMdbRouterInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbRouterInfo=0;
#endif

CSysMdbRouterInfo *CSysMdbRouterInfoFactory::startFindByDsc( const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbRouterInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByDsc= SubcriberID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbRouterInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbRouterInfo *theSysMdbRouterInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbRouterInfo=(CSysMdbRouterInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbRouterInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbRouterInfo;
}

CSysMdbRouterInfo *CSysMdbRouterInfoFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbRouterInfo++;
#endif
	CSysMdbRouterInfo *theSysMdbRouterInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbRouterInfo=(CSysMdbRouterInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbRouterInfo->SubcriberID,querySubcriberIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbRouterInfo;
}

void CSysMdbRouterInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbRouterInfo=0;
#endif

CSysMdbRouterInfo *CSysMdbRouterInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbRouterInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbRouterInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbRouterInfo *theSysMdbRouterInfo;
	compareObject.SubcriberID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbRouterInfo=(CSysMdbRouterInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbRouterInfo;
}

CSysMdbRouterInfo *CSysMdbRouterInfoFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbRouterInfo++;
#endif
	CSysMdbRouterInfo *theSysMdbRouterInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbRouterInfo=(CSysMdbRouterInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbRouterInfo;
}

void CSysMdbRouterInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbRouterInfo=0;
#endif

CSysMdbRouterInfo *CSysMdbRouterInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbRouterInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByDataDelete= SubcriberID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbRouterInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbRouterInfo *theSysMdbRouterInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDataDelete=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbRouterInfo=(CSysMdbRouterInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbRouterInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbRouterInfo;
}

CSysMdbRouterInfo *CSysMdbRouterInfoFactory::findNextByDataDelete(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbRouterInfo++;
#endif
	CSysMdbRouterInfo *theSysMdbRouterInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDataDelete=pDecIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbRouterInfo=(CSysMdbRouterInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbRouterInfo->SubcriberID,querySubcriberIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbRouterInfo;
}

void CSysMdbRouterInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysHostNameIndexinSysMdbDiskIO(const void *pV1, const void *pV2)
{
	CSysMdbDiskIO *p1,*p2;
	p1=(CSysMdbDiskIO *)pV1;
	p2=(CSysMdbDiskIO *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbDiskIO(const void *pV1, const void *pV2)
{
	CSysMdbDiskIO *p1,*p2;
	p1=(CSysMdbDiskIO *)pV1;
	p2=(CSysMdbDiskIO *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysMdbDiskIO=0;
#endif

CSysMdbDiskIO *CSysMdbDiskIOFactory::startFindByHostName( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysMdbDiskIO while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByHostName= SubcriberID.getValue();
	queryMonDateInSearchByHostName= MonDate.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbDiskIO++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbDiskIO *theSysMdbDiskIO;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbDiskIO=(CSysMdbDiskIO *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbDiskIO->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbDiskIO;
}

CSysMdbDiskIO *CSysMdbDiskIOFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbDiskIO++;
#endif
	CSysMdbDiskIO *theSysMdbDiskIO;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysMdbDiskIO=(CSysMdbDiskIO *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbDiskIO->SubcriberID,querySubcriberIDInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbDiskIO;
}

void CSysMdbDiskIOFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbDiskIO=0;
#endif

CSysMdbDiskIO *CSysMdbDiskIOFactory::startFindByDsc( const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbDiskIO while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByDsc= SubcriberID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbDiskIO++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbDiskIO *theSysMdbDiskIO;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbDiskIO=(CSysMdbDiskIO *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbDiskIO->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbDiskIO;
}

CSysMdbDiskIO *CSysMdbDiskIOFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbDiskIO++;
#endif
	CSysMdbDiskIO *theSysMdbDiskIO;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbDiskIO=(CSysMdbDiskIO *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbDiskIO->SubcriberID,querySubcriberIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbDiskIO;
}

void CSysMdbDiskIOFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbDiskIO=0;
#endif

CSysMdbDiskIO *CSysMdbDiskIOFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbDiskIO while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbDiskIO++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbDiskIO *theSysMdbDiskIO;
	compareObject.SubcriberID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbDiskIO=(CSysMdbDiskIO *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbDiskIO;
}

CSysMdbDiskIO *CSysMdbDiskIOFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbDiskIO++;
#endif
	CSysMdbDiskIO *theSysMdbDiskIO;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbDiskIO=(CSysMdbDiskIO *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbDiskIO;
}

void CSysMdbDiskIOFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbDiskIO=0;
#endif

CSysMdbDiskIO *CSysMdbDiskIOFactory::startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbDiskIO while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByDataDelete= SubcriberID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbDiskIO++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbDiskIO *theSysMdbDiskIO;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDataDelete=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbDiskIO=(CSysMdbDiskIO *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbDiskIO->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbDiskIO;
}

CSysMdbDiskIO *CSysMdbDiskIOFactory::findNextByDataDelete(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbDiskIO++;
#endif
	CSysMdbDiskIO *theSysMdbDiskIO;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDataDelete=pDecIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbDiskIO=(CSysMdbDiskIO *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbDiskIO->SubcriberID,querySubcriberIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbDiskIO;
}

void CSysMdbDiskIOFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysHostNameIndexinSysMdbStatInfo(const void *pV1, const void *pV2)
{
	CSysMdbStatInfo *p1,*p2;
	p1=(CSysMdbStatInfo *)pV1;
	p2=(CSysMdbStatInfo *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbStatInfo(const void *pV1, const void *pV2)
{
	CSysMdbStatInfo *p1,*p2;
	p1=(CSysMdbStatInfo *)pV1;
	p2=(CSysMdbStatInfo *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysMdbStatInfo=0;
#endif

CSysMdbStatInfo *CSysMdbStatInfoFactory::startFindByHostName( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysMdbStatInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByHostName= SubcriberID.getValue();
	queryMonDateInSearchByHostName= MonDate.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbStatInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbStatInfo *theSysMdbStatInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbStatInfo=(CSysMdbStatInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbStatInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbStatInfo;
}

CSysMdbStatInfo *CSysMdbStatInfoFactory::findNextByHostName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbStatInfo++;
#endif
	CSysMdbStatInfo *theSysMdbStatInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysMdbStatInfo=(CSysMdbStatInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbStatInfo->SubcriberID,querySubcriberIDInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbStatInfo;
}

void CSysMdbStatInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbStatInfo=0;
#endif

CSysMdbStatInfo *CSysMdbStatInfoFactory::startFindByDsc( const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbStatInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByDsc= SubcriberID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbStatInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbStatInfo *theSysMdbStatInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbStatInfo=(CSysMdbStatInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbStatInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbStatInfo;
}

CSysMdbStatInfo *CSysMdbStatInfoFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbStatInfo++;
#endif
	CSysMdbStatInfo *theSysMdbStatInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbStatInfo=(CSysMdbStatInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbStatInfo->SubcriberID,querySubcriberIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbStatInfo;
}

void CSysMdbStatInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbStatInfo=0;
#endif

CSysMdbStatInfo *CSysMdbStatInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbStatInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbStatInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbStatInfo *theSysMdbStatInfo;
	compareObject.SubcriberID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbStatInfo=(CSysMdbStatInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbStatInfo;
}

CSysMdbStatInfo *CSysMdbStatInfoFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbStatInfo++;
#endif
	CSysMdbStatInfo *theSysMdbStatInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbStatInfo=(CSysMdbStatInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbStatInfo;
}

void CSysMdbStatInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbStatInfo=0;
#endif

CSysMdbStatInfo *CSysMdbStatInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbStatInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByDataDelete= SubcriberID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbStatInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbStatInfo *theSysMdbStatInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDataDelete=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbStatInfo=(CSysMdbStatInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbStatInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbStatInfo;
}

CSysMdbStatInfo *CSysMdbStatInfoFactory::findNextByDataDelete(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbStatInfo++;
#endif
	CSysMdbStatInfo *theSysMdbStatInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDataDelete=pDecIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbStatInfo=(CSysMdbStatInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbStatInfo->SubcriberID,querySubcriberIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbStatInfo;
}

void CSysMdbStatInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysHostNameIndexinSysMdbTradeFrontOrderRttStat(const void *pV1, const void *pV2)
{
	CSysMdbTradeFrontOrderRttStat *p1,*p2;
	p1=(CSysMdbTradeFrontOrderRttStat *)pV1;
	p2=(CSysMdbTradeFrontOrderRttStat *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbTradeFrontOrderRttStat(const void *pV1, const void *pV2)
{
	CSysMdbTradeFrontOrderRttStat *p1,*p2;
	p1=(CSysMdbTradeFrontOrderRttStat *)pV1;
	p2=(CSysMdbTradeFrontOrderRttStat *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByFrontIndexForSysMdbTradeFrontOrderRttStat=0;
#endif

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatFactory::startFindByFrontIndex( const CReadOnlyTypeObjectIDType& ObjectID,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByFrontIndex of CSysMdbTradeFrontOrderRttStat while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByFrontIndex!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByFrontIndex();
	}

	///记录所有的查询值
	queryObjectIDInSearchByFrontIndex= ObjectID.getValue();
	queryMonTimeInSearchByFrontIndex= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByFrontIndexForSysMdbTradeFrontOrderRttStat++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbTradeFrontOrderRttStat *theSysMdbTradeFrontOrderRttStat;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByFrontIndex=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByFrontIndex==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbTradeFrontOrderRttStat=(CSysMdbTradeFrontOrderRttStat *)(pLastFoundInSearchByFrontIndex->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTradeFrontOrderRttStat->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByFrontIndex=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTradeFrontOrderRttStat;
}

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatFactory::findNextByFrontIndex(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByFrontIndex==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByFrontIndexForSysMdbTradeFrontOrderRttStat++;
#endif
	CSysMdbTradeFrontOrderRttStat *theSysMdbTradeFrontOrderRttStat;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByFrontIndex=pSysHostNameIndex->getNextNode(pLastFoundInSearchByFrontIndex);
	if (pLastFoundInSearchByFrontIndex==NULL)
	{
		return NULL;
	}

	theSysMdbTradeFrontOrderRttStat=(CSysMdbTradeFrontOrderRttStat *)(pLastFoundInSearchByFrontIndex->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTradeFrontOrderRttStat->ObjectID,queryObjectIDInSearchByFrontIndex))
	{
		pLastFoundInSearchByFrontIndex=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTradeFrontOrderRttStat;
}

void CSysMdbTradeFrontOrderRttStatFactory::endFindByFrontIndex(void)
{
	pLastFoundInSearchByFrontIndex=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbTradeFrontOrderRttStat=0;
#endif

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatFactory::startFindByDsc( const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbTradeFrontOrderRttStat while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///记录所有的查询值
	querySubcriberIDInSearchByDsc= SubcriberID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTradeFrontOrderRttStat++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbTradeFrontOrderRttStat *theSysMdbTradeFrontOrderRttStat;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbTradeFrontOrderRttStat=(CSysMdbTradeFrontOrderRttStat *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTradeFrontOrderRttStat->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTradeFrontOrderRttStat;
}

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatFactory::findNextByDsc(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTradeFrontOrderRttStat++;
#endif
	CSysMdbTradeFrontOrderRttStat *theSysMdbTradeFrontOrderRttStat;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbTradeFrontOrderRttStat=(CSysMdbTradeFrontOrderRttStat *)(pLastFoundInSearchByDsc->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theSysMdbTradeFrontOrderRttStat->SubcriberID,querySubcriberIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///返回找到的结果
	return theSysMdbTradeFrontOrderRttStat;
}

void CSysMdbTradeFrontOrderRttStatFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbTradeFrontOrderRttStat=0;
#endif

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbTradeFrontOrderRttStat while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTradeFrontOrderRttStat++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMdbTradeFrontOrderRttStat *theSysMdbTradeFrontOrderRttStat;
	compareObject.ObjectID="";
	compareObject.MonTime="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMdbTradeFrontOrderRttStat=(CSysMdbTradeFrontOrderRttStat *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbTradeFrontOrderRttStat;
}

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTradeFrontOrderRttStat++;
#endif
	CSysMdbTradeFrontOrderRttStat *theSysMdbTradeFrontOrderRttStat;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbTradeFrontOrderRttStat=(CSysMdbTradeFrontOrderRttStat *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMdbTradeFrontOrderRttStat;
}

void CSysMdbTradeFrontOrderRttStatFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int findByTheOneForSysMdbTradeFrontOrderRttStat=0;
#endif
CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatFactory::findByTheOne( const CReadOnlyTypeObjectIDType&  ObjectID,  const CReadOnlyTimeType&  MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByTheOne of CSysMdbTradeFrontOrderRttStat while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByTheOneForSysMdbTradeFrontOrderRttStat++;
#endif
	CAVLNode *pNode;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonTime=MonTime.getValue();
	pNode=pSysHostNameIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysMdbTradeFrontOrderRttStat *)(pNode->pObject);
}


int compareForSysTradeTimeIndexinSysInstrumentStatus(const void *pV1, const void *pV2)
{
	CSysInstrumentStatus *p1,*p2;
	p1=(CSysInstrumentStatus *)pV1;
	p2=(CSysInstrumentStatus *)pV2;
	switch (compare(p1->EnterTime.getValue(),p2->EnterTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysInstrumentStatus=0;
#endif

CSysInstrumentStatus *CSysInstrumentStatusFactory::startFindByActionTime( const CReadOnlyTimeType& EnterTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysInstrumentStatus while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///记录所有的查询值
	queryEnterTimeInSearchByActionTime= EnterTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysInstrumentStatus++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysInstrumentStatus *theSysInstrumentStatus;
	compareObject.EnterTime=EnterTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByActionTime=pSysTradeTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysInstrumentStatus=(CSysInstrumentStatus *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysInstrumentStatus;
}

CSysInstrumentStatus *CSysInstrumentStatusFactory::findNextByActionTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysInstrumentStatus++;
#endif
	CSysInstrumentStatus *theSysInstrumentStatus;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByActionTime=pSysTradeTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysInstrumentStatus=(CSysInstrumentStatus *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysInstrumentStatus;
}

void CSysInstrumentStatusFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysInstrumentStatus=0;
#endif

CSysInstrumentStatus *CSysInstrumentStatusFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysInstrumentStatus while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysInstrumentStatus++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysInstrumentStatus *theSysInstrumentStatus;
	compareObject.EnterTime="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysTradeTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysInstrumentStatus=(CSysInstrumentStatus *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysInstrumentStatus;
}

CSysInstrumentStatus *CSysInstrumentStatusFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysInstrumentStatus++;
#endif
	CSysInstrumentStatus *theSysInstrumentStatus;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysTradeTimeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysInstrumentStatus=(CSysInstrumentStatus *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysInstrumentStatus;
}

void CSysInstrumentStatusFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysTradeTimeIndexinSysCurrTradingSegmentAttr(const void *pV1, const void *pV2)
{
	CSysCurrTradingSegmentAttr *p1,*p2;
	p1=(CSysCurrTradingSegmentAttr *)pV1;
	p2=(CSysCurrTradingSegmentAttr *)pV2;
	switch (compare(p1->StartTime.getValue(),p2->StartTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysCurrTradingSegmentAttr=0;
#endif

CSysCurrTradingSegmentAttr *CSysCurrTradingSegmentAttrFactory::startFindByActionTime( const CReadOnlyTimeType& StartTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysCurrTradingSegmentAttr while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///记录所有的查询值
	queryStartTimeInSearchByActionTime= StartTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysCurrTradingSegmentAttr++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysCurrTradingSegmentAttr *theSysCurrTradingSegmentAttr;
	compareObject.StartTime=StartTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByActionTime=pSysTradeTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysCurrTradingSegmentAttr=(CSysCurrTradingSegmentAttr *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysCurrTradingSegmentAttr;
}

CSysCurrTradingSegmentAttr *CSysCurrTradingSegmentAttrFactory::findNextByActionTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysCurrTradingSegmentAttr++;
#endif
	CSysCurrTradingSegmentAttr *theSysCurrTradingSegmentAttr;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByActionTime=pSysTradeTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysCurrTradingSegmentAttr=(CSysCurrTradingSegmentAttr *)(pLastFoundInSearchByActionTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysCurrTradingSegmentAttr;
}

void CSysCurrTradingSegmentAttrFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysCurrTradingSegmentAttr=0;
#endif

CSysCurrTradingSegmentAttr *CSysCurrTradingSegmentAttrFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysCurrTradingSegmentAttr while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysCurrTradingSegmentAttr++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysCurrTradingSegmentAttr *theSysCurrTradingSegmentAttr;
	compareObject.StartTime="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysTradeTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysCurrTradingSegmentAttr=(CSysCurrTradingSegmentAttr *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysCurrTradingSegmentAttr;
}

CSysCurrTradingSegmentAttr *CSysCurrTradingSegmentAttrFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysCurrTradingSegmentAttr++;
#endif
	CSysCurrTradingSegmentAttr *theSysCurrTradingSegmentAttr;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysTradeTimeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysCurrTradingSegmentAttr=(CSysCurrTradingSegmentAttr *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysCurrTradingSegmentAttr;
}

void CSysCurrTradingSegmentAttrFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysPayTimeIndexinSysMemberLinkCost(const void *pV1, const void *pV2)
{
	CSysMemberLinkCost *p1,*p2;
	p1=(CSysMemberLinkCost *)pV1;
	p2=(CSysMemberLinkCost *)pV2;
	switch (compare(p1->Pay_Date.getValue(),p2->Pay_Date.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByPayTimeForSysMemberLinkCost=0;
#endif

CSysMemberLinkCost *CSysMemberLinkCostFactory::startFindByPayTime( const CReadOnlyCfgNameType& Pay_Date)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByPayTime of CSysMemberLinkCost while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByPayTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByPayTime();
	}

	///记录所有的查询值
	queryPay_DateInSearchByPayTime= Pay_Date.getValue();

#ifdef COUNT_SEARCH
	multiFindByPayTimeForSysMemberLinkCost++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMemberLinkCost *theSysMemberLinkCost;
	compareObject.Pay_Date=Pay_Date.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByPayTime=pSysPayTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByPayTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMemberLinkCost=(CSysMemberLinkCost *)(pLastFoundInSearchByPayTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMemberLinkCost;
}

CSysMemberLinkCost *CSysMemberLinkCostFactory::findNextByPayTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByPayTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByPayTimeForSysMemberLinkCost++;
#endif
	CSysMemberLinkCost *theSysMemberLinkCost;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByPayTime=pSysPayTimeIndex->getNextNode(pLastFoundInSearchByPayTime);
	if (pLastFoundInSearchByPayTime==NULL)
	{
		return NULL;
	}

	theSysMemberLinkCost=(CSysMemberLinkCost *)(pLastFoundInSearchByPayTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMemberLinkCost;
}

void CSysMemberLinkCostFactory::endFindByPayTime(void)
{
	pLastFoundInSearchByPayTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMemberLinkCost=0;
#endif

CSysMemberLinkCost *CSysMemberLinkCostFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMemberLinkCost while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMemberLinkCost++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMemberLinkCost *theSysMemberLinkCost;
	compareObject.Pay_Date="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysPayTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMemberLinkCost=(CSysMemberLinkCost *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMemberLinkCost;
}

CSysMemberLinkCost *CSysMemberLinkCostFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMemberLinkCost++;
#endif
	CSysMemberLinkCost *theSysMemberLinkCost;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysPayTimeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMemberLinkCost=(CSysMemberLinkCost *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMemberLinkCost;
}

void CSysMemberLinkCostFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByAllForSysMemberLinkCost=0;
#endif

CSysMemberLinkCost *CSysMemberLinkCostFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysMemberLinkCost while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysMemberLinkCost++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysMemberLinkCost *theSysMemberLinkCost;
	compareObject.Pay_Date="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysPayTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysMemberLinkCost=(CSysMemberLinkCost *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMemberLinkCost;
}

CSysMemberLinkCost *CSysMemberLinkCostFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysMemberLinkCost++;
#endif
	CSysMemberLinkCost *theSysMemberLinkCost;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysPayTimeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysMemberLinkCost=(CSysMemberLinkCost *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysMemberLinkCost;
}

void CSysMemberLinkCostFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysLineNameIndexinSysNetPartylinkMonthlyRent(const void *pV1, const void *pV2)
{
	CSysNetPartylinkMonthlyRent *p1,*p2;
	p1=(CSysNetPartylinkMonthlyRent *)pV1;
	p2=(CSysNetPartylinkMonthlyRent *)pV2;
	switch (compare(p1->LineName.getValue(),p2->LineName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByLineNameForSysNetPartylinkMonthlyRent=0;
#endif

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentFactory::startFindByLineName( const CReadOnlyParticipantNameType& LineName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByLineName of CSysNetPartylinkMonthlyRent while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByLineName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByLineName();
	}

	///记录所有的查询值
	queryLineNameInSearchByLineName= LineName.getValue();

#ifdef COUNT_SEARCH
	multiFindByLineNameForSysNetPartylinkMonthlyRent++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetPartylinkMonthlyRent *theSysNetPartylinkMonthlyRent;
	compareObject.LineName=LineName.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByLineName=pSysLineNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByLineName==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetPartylinkMonthlyRent=(CSysNetPartylinkMonthlyRent *)(pLastFoundInSearchByLineName->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetPartylinkMonthlyRent;
}

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentFactory::findNextByLineName(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByLineName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByLineNameForSysNetPartylinkMonthlyRent++;
#endif
	CSysNetPartylinkMonthlyRent *theSysNetPartylinkMonthlyRent;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByLineName=pSysLineNameIndex->getNextNode(pLastFoundInSearchByLineName);
	if (pLastFoundInSearchByLineName==NULL)
	{
		return NULL;
	}

	theSysNetPartylinkMonthlyRent=(CSysNetPartylinkMonthlyRent *)(pLastFoundInSearchByLineName->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetPartylinkMonthlyRent;
}

void CSysNetPartylinkMonthlyRentFactory::endFindByLineName(void)
{
	pLastFoundInSearchByLineName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysNetPartylinkMonthlyRent=0;
#endif

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysNetPartylinkMonthlyRent while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysNetPartylinkMonthlyRent++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetPartylinkMonthlyRent *theSysNetPartylinkMonthlyRent;
	compareObject.LineName="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBytheAll=pSysLineNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetPartylinkMonthlyRent=(CSysNetPartylinkMonthlyRent *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetPartylinkMonthlyRent;
}

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentFactory::findNextBytheAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysNetPartylinkMonthlyRent++;
#endif
	CSysNetPartylinkMonthlyRent *theSysNetPartylinkMonthlyRent;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBytheAll=pSysLineNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysNetPartylinkMonthlyRent=(CSysNetPartylinkMonthlyRent *)(pLastFoundInSearchBytheAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetPartylinkMonthlyRent;
}

void CSysNetPartylinkMonthlyRentFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByAllForSysNetPartylinkMonthlyRent=0;
#endif

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetPartylinkMonthlyRent while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPartylinkMonthlyRent++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetPartylinkMonthlyRent *theSysNetPartylinkMonthlyRent;
	compareObject.LineName="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysLineNameIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetPartylinkMonthlyRent=(CSysNetPartylinkMonthlyRent *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetPartylinkMonthlyRent;
}

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPartylinkMonthlyRent++;
#endif
	CSysNetPartylinkMonthlyRent *theSysNetPartylinkMonthlyRent;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysLineNameIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetPartylinkMonthlyRent=(CSysNetPartylinkMonthlyRent *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetPartylinkMonthlyRent;
}

void CSysNetPartylinkMonthlyRentFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysIDTypeIndexinSysNetNonPartyLinkInfo(const void *pV1, const void *pV2)
{
	CSysNetNonPartyLinkInfo *p1,*p2;
	p1=(CSysNetNonPartyLinkInfo *)pV1;
	p2=(CSysNetNonPartyLinkInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetNonPartyLinkInfo=0;
#endif

CSysNetNonPartyLinkInfo *CSysNetNonPartyLinkInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetNonPartyLinkInfo while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetNonPartyLinkInfo++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSysNetNonPartyLinkInfo *theSysNetNonPartyLinkInfo;
	compareObject.ID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSysNetNonPartyLinkInfo=(CSysNetNonPartyLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetNonPartyLinkInfo;
}

CSysNetNonPartyLinkInfo *CSysNetNonPartyLinkInfoFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetNonPartyLinkInfo++;
#endif
	CSysNetNonPartyLinkInfo *theSysNetNonPartyLinkInfo;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetNonPartyLinkInfo=(CSysNetNonPartyLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSysNetNonPartyLinkInfo;
}

void CSysNetNonPartyLinkInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetNonPartyLinkInfo=0;
#endif
CSysNetNonPartyLinkInfo *CSysNetNonPartyLinkInfoFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetNonPartyLinkInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetNonPartyLinkInfo++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetNonPartyLinkInfo *)(pNode->pObject);
}


#ifdef COUNT_SEARCH
void showAllSearchCount(void)
{
	printf("\n");
	if (multiFindByActionTimeForSysInvalidateOrder !=0)
	{
		printf("\tmultiFindByActionTimeForSysInvalidateOrder:%d\n",multiFindByActionTimeForSysInvalidateOrder);
	}
	if (multiFindByActionTimeForSysOrderStatus !=0)
	{
		printf("\tmultiFindByActionTimeForSysOrderStatus:%d\n",multiFindByActionTimeForSysOrderStatus);
	}
	if (multiFindByActionTimeForSysBargainOrder !=0)
	{
		printf("\tmultiFindByActionTimeForSysBargainOrder:%d\n",multiFindByActionTimeForSysBargainOrder);
	}
	if (multiFindByAllForSysInstProperty !=0)
	{
		printf("\tmultiFindByAllForSysInstProperty:%d\n",multiFindByAllForSysInstProperty);
	}
	if (findByOneForSysInstProperty !=0)
	{
		printf("\tfindByOneForSysInstProperty:%d\n",findByOneForSysInstProperty);
	}
	if (multiFindByAllForSysMarginRate !=0)
	{
		printf("\tmultiFindByAllForSysMarginRate:%d\n",multiFindByAllForSysMarginRate);
	}
	if (findByOneForSysMarginRate !=0)
	{
		printf("\tfindByOneForSysMarginRate:%d\n",findByOneForSysMarginRate);
	}
	if (multiFindByAllForSysPriceLimit !=0)
	{
		printf("\tmultiFindByAllForSysPriceLimit:%d\n",multiFindByAllForSysPriceLimit);
	}
	if (findByOneForSysPriceLimit !=0)
	{
		printf("\tfindByOneForSysPriceLimit:%d\n",findByOneForSysPriceLimit);
	}
	if (multiFindByAllForSysPartPosiLimit !=0)
	{
		printf("\tmultiFindByAllForSysPartPosiLimit:%d\n",multiFindByAllForSysPartPosiLimit);
	}
	if (findByOneForSysPartPosiLimit !=0)
	{
		printf("\tfindByOneForSysPartPosiLimit:%d\n",findByOneForSysPartPosiLimit);
	}
	if (multiFindByAllForSysClientPosiLimit !=0)
	{
		printf("\tmultiFindByAllForSysClientPosiLimit:%d\n",multiFindByAllForSysClientPosiLimit);
	}
	if (findByOneForSysClientPosiLimit !=0)
	{
		printf("\tfindByOneForSysClientPosiLimit:%d\n",findByOneForSysClientPosiLimit);
	}
	if (multiFindByAllForSysSpecialPosiLimit !=0)
	{
		printf("\tmultiFindByAllForSysSpecialPosiLimit:%d\n",multiFindByAllForSysSpecialPosiLimit);
	}
	if (findByOneForSysSpecialPosiLimit !=0)
	{
		printf("\tfindByOneForSysSpecialPosiLimit:%d\n",findByOneForSysSpecialPosiLimit);
	}
	if (multiFindByActionTimeForSysTransactionChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysTransactionChg:%d\n",multiFindByActionTimeForSysTransactionChg);
	}
	if (multiFindByActionTimeForSysClientChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysClientChg:%d\n",multiFindByActionTimeForSysClientChg);
	}
	if (multiFindByActionTimeForSysPartClientChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysPartClientChg:%d\n",multiFindByActionTimeForSysPartClientChg);
	}
	if (multiFindByActionTimeForSysPosiLimitChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysPosiLimitChg:%d\n",multiFindByActionTimeForSysPosiLimitChg);
	}
	if (multiFindByActionTimeForSysClientPosiLimitChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysClientPosiLimitChg:%d\n",multiFindByActionTimeForSysClientPosiLimitChg);
	}
	if (multiFindByActionTimeForSysSpecPosiLimitChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysSpecPosiLimitChg:%d\n",multiFindByActionTimeForSysSpecPosiLimitChg);
	}
	if (multiFindByActionTimeForSysHedgeDetailChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysHedgeDetailChg:%d\n",multiFindByActionTimeForSysHedgeDetailChg);
	}
	if (multiFindByActionTimeForSysParticipantChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysParticipantChg:%d\n",multiFindByActionTimeForSysParticipantChg);
	}
	if (multiFindByActionTimeForSysMarginRateChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysMarginRateChg:%d\n",multiFindByActionTimeForSysMarginRateChg);
	}
	if (multiFindByActionTimeForSysUserIpChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysUserIpChg:%d\n",multiFindByActionTimeForSysUserIpChg);
	}
	if (multiFindByAllForSysPartTrade !=0)
	{
		printf("\tmultiFindByAllForSysPartTrade:%d\n",multiFindByAllForSysPartTrade);
	}
	if (findByOneForSysPartTrade !=0)
	{
		printf("\tfindByOneForSysPartTrade:%d\n",findByOneForSysPartTrade);
	}
	if (multiFindByIDTypeForSysMdbObjectAttr !=0)
	{
		printf("\tmultiFindByIDTypeForSysMdbObjectAttr:%d\n",multiFindByIDTypeForSysMdbObjectAttr);
	}
	if (multiFindByDscForSysMdbObjectAttr !=0)
	{
		printf("\tmultiFindByDscForSysMdbObjectAttr:%d\n",multiFindByDscForSysMdbObjectAttr);
	}
	if (findByOneForSysMdbObjectAttr !=0)
	{
		printf("\tfindByOneForSysMdbObjectAttr:%d\n",findByOneForSysMdbObjectAttr);
	}
	if (multiFindBytheAllForSysMdbObjectAttr !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbObjectAttr:%d\n",multiFindBytheAllForSysMdbObjectAttr);
	}
	if (multiFindByDataDeleteForSysMdbObjectAttr !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbObjectAttr:%d\n",multiFindByDataDeleteForSysMdbObjectAttr);
	}
	if (multiFindByAllForSysMdbSyslogInfo !=0)
	{
		printf("\tmultiFindByAllForSysMdbSyslogInfo:%d\n",multiFindByAllForSysMdbSyslogInfo);
	}
	if (multiFindBytheAllForSysMdbSyslogInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbSyslogInfo:%d\n",multiFindBytheAllForSysMdbSyslogInfo);
	}
	if (multiFindByDataDeleteForSysMdbSyslogInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbSyslogInfo:%d\n",multiFindByDataDeleteForSysMdbSyslogInfo);
	}
	if (multiFindByHostNameForSysUserInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysUserInfo:%d\n",multiFindByHostNameForSysUserInfo);
	}
	if (multiFindBytheAllForSysUserInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysUserInfo:%d\n",multiFindBytheAllForSysUserInfo);
	}
	if (multiFindByDscForSysUserInfo !=0)
	{
		printf("\tmultiFindByDscForSysUserInfo:%d\n",multiFindByDscForSysUserInfo);
	}
	if (multiFindByHostNameForSysOnlineUserInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysOnlineUserInfo:%d\n",multiFindByHostNameForSysOnlineUserInfo);
	}
	if (multiFindBytheAllForSysOnlineUserInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysOnlineUserInfo:%d\n",multiFindBytheAllForSysOnlineUserInfo);
	}
	if (multiFindByDscForSysOnlineUserInfo !=0)
	{
		printf("\tmultiFindByDscForSysOnlineUserInfo:%d\n",multiFindByDscForSysOnlineUserInfo);
	}
	if (multiFindByTimeForSysWarningEvent !=0)
	{
		printf("\tmultiFindByTimeForSysWarningEvent:%d\n",multiFindByTimeForSysWarningEvent);
	}
	if (multiFindByAllForSysWarningEvent !=0)
	{
		printf("\tmultiFindByAllForSysWarningEvent:%d\n",multiFindByAllForSysWarningEvent);
	}
	if (findByEvendIDForSysWarningEvent !=0)
	{
		printf("\tfindByEvendIDForSysWarningEvent:%d\n",findByEvendIDForSysWarningEvent);
	}
	if (multiFindByEvendIDsForSysWarningEvent !=0)
	{
		printf("\tmultiFindByEvendIDsForSysWarningEvent:%d\n",multiFindByEvendIDsForSysWarningEvent);
	}
	if (multiFindBytheAllForSysWarningEvent !=0)
	{
		printf("\tmultiFindBytheAllForSysWarningEvent:%d\n",multiFindBytheAllForSysWarningEvent);
	}
	if (multiFindByTimeForSysWarningQuery !=0)
	{
		printf("\tmultiFindByTimeForSysWarningQuery:%d\n",multiFindByTimeForSysWarningQuery);
	}
	if (findByEvendIDForSysWarningQuery !=0)
	{
		printf("\tfindByEvendIDForSysWarningQuery:%d\n",findByEvendIDForSysWarningQuery);
	}
	if (multiFindByTimeForSyslogEvent !=0)
	{
		printf("\tmultiFindByTimeForSyslogEvent:%d\n",multiFindByTimeForSyslogEvent);
	}
	if (multiFindBytheAllForSyslogEvent !=0)
	{
		printf("\tmultiFindBytheAllForSyslogEvent:%d\n",multiFindBytheAllForSyslogEvent);
	}
	if (multiFindByAllForSyslogEvent !=0)
	{
		printf("\tmultiFindByAllForSyslogEvent:%d\n",multiFindByAllForSyslogEvent);
	}
	if (findByEvendIDForSyslogEvent !=0)
	{
		printf("\tfindByEvendIDForSyslogEvent:%d\n",findByEvendIDForSyslogEvent);
	}
	if (multiFindByTimeForSysEventDescrip !=0)
	{
		printf("\tmultiFindByTimeForSysEventDescrip:%d\n",multiFindByTimeForSysEventDescrip);
	}
	if (multiFindBytheAllForSysEventDescrip !=0)
	{
		printf("\tmultiFindBytheAllForSysEventDescrip:%d\n",multiFindBytheAllForSysEventDescrip);
	}
	if (multiFindByAllForSysEventDescrip !=0)
	{
		printf("\tmultiFindByAllForSysEventDescrip:%d\n",multiFindByAllForSysEventDescrip);
	}
	if (findByEvendIDForSysEventDescrip !=0)
	{
		printf("\tfindByEvendIDForSysEventDescrip:%d\n",findByEvendIDForSysEventDescrip);
	}
	if (multiFindByHostNameForRspQryHostEnvCommon !=0)
	{
		printf("\tmultiFindByHostNameForRspQryHostEnvCommon:%d\n",multiFindByHostNameForRspQryHostEnvCommon);
	}
	if (multiFindBytheAllForRspQryHostEnvCommon !=0)
	{
		printf("\tmultiFindBytheAllForRspQryHostEnvCommon:%d\n",multiFindBytheAllForRspQryHostEnvCommon);
	}
	if (multiFindByHostNameForRspQryHostEnvLan !=0)
	{
		printf("\tmultiFindByHostNameForRspQryHostEnvLan:%d\n",multiFindByHostNameForRspQryHostEnvLan);
	}
	if (multiFindBytheAllForRspQryHostEnvLan !=0)
	{
		printf("\tmultiFindBytheAllForRspQryHostEnvLan:%d\n",multiFindBytheAllForRspQryHostEnvLan);
	}
	if (multiFindByHostNameForRspQryHostEnvStorage !=0)
	{
		printf("\tmultiFindByHostNameForRspQryHostEnvStorage:%d\n",multiFindByHostNameForRspQryHostEnvStorage);
	}
	if (multiFindBytheAllForRspQryHostEnvStorage !=0)
	{
		printf("\tmultiFindBytheAllForRspQryHostEnvStorage:%d\n",multiFindBytheAllForRspQryHostEnvStorage);
	}
	if (multiFindByHostNameForRspQryHostEnvIO !=0)
	{
		printf("\tmultiFindByHostNameForRspQryHostEnvIO:%d\n",multiFindByHostNameForRspQryHostEnvIO);
	}
	if (multiFindBytheAllForRspQryHostEnvIO !=0)
	{
		printf("\tmultiFindBytheAllForRspQryHostEnvIO:%d\n",multiFindBytheAllForRspQryHostEnvIO);
	}
	if (multiFindByHostNameForRspQryHostEnvFS !=0)
	{
		printf("\tmultiFindByHostNameForRspQryHostEnvFS:%d\n",multiFindByHostNameForRspQryHostEnvFS);
	}
	if (multiFindBytheAllForRspQryHostEnvFS !=0)
	{
		printf("\tmultiFindBytheAllForRspQryHostEnvFS:%d\n",multiFindBytheAllForRspQryHostEnvFS);
	}
	if (multiFindByHostNameForRspQryHostEnvSwap !=0)
	{
		printf("\tmultiFindByHostNameForRspQryHostEnvSwap:%d\n",multiFindByHostNameForRspQryHostEnvSwap);
	}
	if (multiFindBytheAllForRspQryHostEnvSwap !=0)
	{
		printf("\tmultiFindBytheAllForRspQryHostEnvSwap:%d\n",multiFindBytheAllForRspQryHostEnvSwap);
	}
	if (multiFindByHostNameForRspQryHostEnvLanCfg !=0)
	{
		printf("\tmultiFindByHostNameForRspQryHostEnvLanCfg:%d\n",multiFindByHostNameForRspQryHostEnvLanCfg);
	}
	if (multiFindBytheAllForRspQryHostEnvLanCfg !=0)
	{
		printf("\tmultiFindBytheAllForRspQryHostEnvLanCfg:%d\n",multiFindBytheAllForRspQryHostEnvLanCfg);
	}
	if (multiFindByHostNameForSysMdbTopCpuInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysMdbTopCpuInfo:%d\n",multiFindByHostNameForSysMdbTopCpuInfo);
	}
	if (multiFindByDscForSysMdbTopCpuInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbTopCpuInfo:%d\n",multiFindByDscForSysMdbTopCpuInfo);
	}
	if (multiFindBytheAllForSysMdbTopCpuInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbTopCpuInfo:%d\n",multiFindBytheAllForSysMdbTopCpuInfo);
	}
	if (multiFindByDataDeleteForSysMdbTopCpuInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbTopCpuInfo:%d\n",multiFindByDataDeleteForSysMdbTopCpuInfo);
	}
	if (multiFindByHostNameForSysMdbTopMemInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysMdbTopMemInfo:%d\n",multiFindByHostNameForSysMdbTopMemInfo);
	}
	if (multiFindByDscForSysMdbTopMemInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbTopMemInfo:%d\n",multiFindByDscForSysMdbTopMemInfo);
	}
	if (multiFindBytheAllForSysMdbTopMemInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbTopMemInfo:%d\n",multiFindBytheAllForSysMdbTopMemInfo);
	}
	if (multiFindByDataDeleteForSysMdbTopMemInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbTopMemInfo:%d\n",multiFindByDataDeleteForSysMdbTopMemInfo);
	}
	if (multiFindByHostNameForSysMdbTopProcessInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysMdbTopProcessInfo:%d\n",multiFindByHostNameForSysMdbTopProcessInfo);
	}
	if (multiFindByDscForSysMdbTopProcessInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbTopProcessInfo:%d\n",multiFindByDscForSysMdbTopProcessInfo);
	}
	if (multiFindBytheAllForSysMdbTopProcessInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbTopProcessInfo:%d\n",multiFindBytheAllForSysMdbTopProcessInfo);
	}
	if (multiFindByHostNameForSysMdbFileSystemInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysMdbFileSystemInfo:%d\n",multiFindByHostNameForSysMdbFileSystemInfo);
	}
	if (multiFindByDscForSysMdbFileSystemInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbFileSystemInfo:%d\n",multiFindByDscForSysMdbFileSystemInfo);
	}
	if (multiFindBytheAllForSysMdbFileSystemInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbFileSystemInfo:%d\n",multiFindBytheAllForSysMdbFileSystemInfo);
	}
	if (multiFindByHostNameForSysMdbNetworkInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysMdbNetworkInfo:%d\n",multiFindByHostNameForSysMdbNetworkInfo);
	}
	if (multiFindByDscForSysMdbNetworkInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbNetworkInfo:%d\n",multiFindByDscForSysMdbNetworkInfo);
	}
	if (multiFindBytheAllForSysMdbNetworkInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbNetworkInfo:%d\n",multiFindBytheAllForSysMdbNetworkInfo);
	}
	if (multiFindByDataDeleteForSysMdbNetworkInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbNetworkInfo:%d\n",multiFindByDataDeleteForSysMdbNetworkInfo);
	}
	if (multiFindByAllForSysParticipantInit !=0)
	{
		printf("\tmultiFindByAllForSysParticipantInit:%d\n",multiFindByAllForSysParticipantInit);
	}
	if (findByOneForSysParticipantInit !=0)
	{
		printf("\tfindByOneForSysParticipantInit:%d\n",findByOneForSysParticipantInit);
	}
	if (multiFindByAllForSysUserInit !=0)
	{
		printf("\tmultiFindByAllForSysUserInit:%d\n",multiFindByAllForSysUserInit);
	}
	if (findByOneForSysUserInit !=0)
	{
		printf("\tfindByOneForSysUserInit:%d\n",findByOneForSysUserInit);
	}
	if (multiFindByAllForSysClientInit !=0)
	{
		printf("\tmultiFindByAllForSysClientInit:%d\n",multiFindByAllForSysClientInit);
	}
	if (findByOneForSysClientInit !=0)
	{
		printf("\tfindByOneForSysClientInit:%d\n",findByOneForSysClientInit);
	}
	if (multiFindByAllForSysTradeUserLoginInfo !=0)
	{
		printf("\tmultiFindByAllForSysTradeUserLoginInfo:%d\n",multiFindByAllForSysTradeUserLoginInfo);
	}
	if (findByOneForSysTradeUserLoginInfo !=0)
	{
		printf("\tfindByOneForSysTradeUserLoginInfo:%d\n",findByOneForSysTradeUserLoginInfo);
	}
	if (multiFindByIDTypeForSysMdbWebAppInfo !=0)
	{
		printf("\tmultiFindByIDTypeForSysMdbWebAppInfo:%d\n",multiFindByIDTypeForSysMdbWebAppInfo);
	}
	if (multiFindByDscForSysMdbWebAppInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbWebAppInfo:%d\n",multiFindByDscForSysMdbWebAppInfo);
	}
	if (findByOneForSysMdbWebAppInfo !=0)
	{
		printf("\tfindByOneForSysMdbWebAppInfo:%d\n",findByOneForSysMdbWebAppInfo);
	}
	if (multiFindBytheAllForSysMdbWebAppInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbWebAppInfo:%d\n",multiFindBytheAllForSysMdbWebAppInfo);
	}
	if (multiFindByDataDeleteForSysMdbWebAppInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbWebAppInfo:%d\n",multiFindByDataDeleteForSysMdbWebAppInfo);
	}
	if (multiFindByIDTypeForSysMdbMemPoolInfo !=0)
	{
		printf("\tmultiFindByIDTypeForSysMdbMemPoolInfo:%d\n",multiFindByIDTypeForSysMdbMemPoolInfo);
	}
	if (multiFindByDscForSysMdbMemPoolInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbMemPoolInfo:%d\n",multiFindByDscForSysMdbMemPoolInfo);
	}
	if (findByOneForSysMdbMemPoolInfo !=0)
	{
		printf("\tfindByOneForSysMdbMemPoolInfo:%d\n",findByOneForSysMdbMemPoolInfo);
	}
	if (multiFindBytheAllForSysMdbMemPoolInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbMemPoolInfo:%d\n",multiFindBytheAllForSysMdbMemPoolInfo);
	}
	if (multiFindByDataDeleteForSysMdbMemPoolInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbMemPoolInfo:%d\n",multiFindByDataDeleteForSysMdbMemPoolInfo);
	}
	if (multiFindByIDTypeForSysMdbConnectorInfo !=0)
	{
		printf("\tmultiFindByIDTypeForSysMdbConnectorInfo:%d\n",multiFindByIDTypeForSysMdbConnectorInfo);
	}
	if (multiFindByDscForSysMdbConnectorInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbConnectorInfo:%d\n",multiFindByDscForSysMdbConnectorInfo);
	}
	if (findByOneForSysMdbConnectorInfo !=0)
	{
		printf("\tfindByOneForSysMdbConnectorInfo:%d\n",findByOneForSysMdbConnectorInfo);
	}
	if (multiFindBytheAllForSysMdbConnectorInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbConnectorInfo:%d\n",multiFindBytheAllForSysMdbConnectorInfo);
	}
	if (multiFindByDataDeleteForSysMdbConnectorInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbConnectorInfo:%d\n",multiFindByDataDeleteForSysMdbConnectorInfo);
	}
	if (multiFindByIDTypeForSysMdbDBQuery !=0)
	{
		printf("\tmultiFindByIDTypeForSysMdbDBQuery:%d\n",multiFindByIDTypeForSysMdbDBQuery);
	}
	if (multiFindByDscForSysMdbDBQuery !=0)
	{
		printf("\tmultiFindByDscForSysMdbDBQuery:%d\n",multiFindByDscForSysMdbDBQuery);
	}
	if (findByOneForSysMdbDBQuery !=0)
	{
		printf("\tfindByOneForSysMdbDBQuery:%d\n",findByOneForSysMdbDBQuery);
	}
	if (multiFindBytheAllForSysMdbDBQuery !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbDBQuery:%d\n",multiFindBytheAllForSysMdbDBQuery);
	}
	if (multiFindByDataDeleteForSysMdbDBQuery !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbDBQuery:%d\n",multiFindByDataDeleteForSysMdbDBQuery);
	}
	if (multiFindByAllForSysNetArea !=0)
	{
		printf("\tmultiFindByAllForSysNetArea:%d\n",multiFindByAllForSysNetArea);
	}
	if (findByOneForSysNetArea !=0)
	{
		printf("\tfindByOneForSysNetArea:%d\n",findByOneForSysNetArea);
	}
	if (multiFindByAllForSysNetSubArea !=0)
	{
		printf("\tmultiFindByAllForSysNetSubArea:%d\n",multiFindByAllForSysNetSubArea);
	}
	if (findByOneForSysNetSubArea !=0)
	{
		printf("\tfindByOneForSysNetSubArea:%d\n",findByOneForSysNetSubArea);
	}
	if (multiFindByAllForSysNetSubAreaIP !=0)
	{
		printf("\tmultiFindByAllForSysNetSubAreaIP:%d\n",multiFindByAllForSysNetSubAreaIP);
	}
	if (findByOneForSysNetSubAreaIP !=0)
	{
		printf("\tfindByOneForSysNetSubAreaIP:%d\n",findByOneForSysNetSubAreaIP);
	}
	if (multiFindByAllForSysNetFuncArea !=0)
	{
		printf("\tmultiFindByAllForSysNetFuncArea:%d\n",multiFindByAllForSysNetFuncArea);
	}
	if (findByOneForSysNetFuncArea !=0)
	{
		printf("\tfindByOneForSysNetFuncArea:%d\n",findByOneForSysNetFuncArea);
	}
	if (multiFindByAllForSysNetDevice !=0)
	{
		printf("\tmultiFindByAllForSysNetDevice:%d\n",multiFindByAllForSysNetDevice);
	}
	if (findByOneForSysNetDevice !=0)
	{
		printf("\tfindByOneForSysNetDevice:%d\n",findByOneForSysNetDevice);
	}
	if (multiFindByIPDECODEForSysNetDevice !=0)
	{
		printf("\tmultiFindByIPDECODEForSysNetDevice:%d\n",multiFindByIPDECODEForSysNetDevice);
	}
	if (multiFindBySubAreaIDForSysNetDevice !=0)
	{
		printf("\tmultiFindBySubAreaIDForSysNetDevice:%d\n",multiFindBySubAreaIDForSysNetDevice);
	}
	if (findByObjectIDForSysNetDevice !=0)
	{
		printf("\tfindByObjectIDForSysNetDevice:%d\n",findByObjectIDForSysNetDevice);
	}
	if (multiFindByAllForSysNetDeviceLinked !=0)
	{
		printf("\tmultiFindByAllForSysNetDeviceLinked:%d\n",multiFindByAllForSysNetDeviceLinked);
	}
	if (findByOneForSysNetDeviceLinked !=0)
	{
		printf("\tfindByOneForSysNetDeviceLinked:%d\n",findByOneForSysNetDeviceLinked);
	}
	if (multiFindByNetObjectIDForSysNetDeviceLinked !=0)
	{
		printf("\tmultiFindByNetObjectIDForSysNetDeviceLinked:%d\n",multiFindByNetObjectIDForSysNetDeviceLinked);
	}
	if (multiFindByLinkNetObjectIDForSysNetDeviceLinked !=0)
	{
		printf("\tmultiFindByLinkNetObjectIDForSysNetDeviceLinked:%d\n",multiFindByLinkNetObjectIDForSysNetDeviceLinked);
	}
	if (multiFindByAllForSysNetOID !=0)
	{
		printf("\tmultiFindByAllForSysNetOID:%d\n",multiFindByAllForSysNetOID);
	}
	if (findByOneForSysNetOID !=0)
	{
		printf("\tfindByOneForSysNetOID:%d\n",findByOneForSysNetOID);
	}
	if (multiFindByAllForSysNetDeviceType !=0)
	{
		printf("\tmultiFindByAllForSysNetDeviceType:%d\n",multiFindByAllForSysNetDeviceType);
	}
	if (findByOneForSysNetDeviceType !=0)
	{
		printf("\tfindByOneForSysNetDeviceType:%d\n",findByOneForSysNetDeviceType);
	}
	if (multiFindByAllForSysNetTimePolicy !=0)
	{
		printf("\tmultiFindByAllForSysNetTimePolicy:%d\n",multiFindByAllForSysNetTimePolicy);
	}
	if (findByOneForSysNetTimePolicy !=0)
	{
		printf("\tfindByOneForSysNetTimePolicy:%d\n",findByOneForSysNetTimePolicy);
	}
	if (multiFindByAllForSysNetGatherTask !=0)
	{
		printf("\tmultiFindByAllForSysNetGatherTask:%d\n",multiFindByAllForSysNetGatherTask);
	}
	if (findByOneForSysNetGatherTask !=0)
	{
		printf("\tfindByOneForSysNetGatherTask:%d\n",findByOneForSysNetGatherTask);
	}
	if (multiFindByNetObjectIDForSysNetGatherTask !=0)
	{
		printf("\tmultiFindByNetObjectIDForSysNetGatherTask:%d\n",multiFindByNetObjectIDForSysNetGatherTask);
	}
	if (multiFindByAllForSysNetDeviceCategory !=0)
	{
		printf("\tmultiFindByAllForSysNetDeviceCategory:%d\n",multiFindByAllForSysNetDeviceCategory);
	}
	if (findByOneForSysNetDeviceCategory !=0)
	{
		printf("\tfindByOneForSysNetDeviceCategory:%d\n",findByOneForSysNetDeviceCategory);
	}
	if (multiFindByAllForSysNetManufactory !=0)
	{
		printf("\tmultiFindByAllForSysNetManufactory:%d\n",multiFindByAllForSysNetManufactory);
	}
	if (findByOneForSysNetManufactory !=0)
	{
		printf("\tfindByOneForSysNetManufactory:%d\n",findByOneForSysNetManufactory);
	}
	if (multiFindByAllForSysNetCommunity !=0)
	{
		printf("\tmultiFindByAllForSysNetCommunity:%d\n",multiFindByAllForSysNetCommunity);
	}
	if (findByOneForSysNetCommunity !=0)
	{
		printf("\tfindByOneForSysNetCommunity:%d\n",findByOneForSysNetCommunity);
	}
	if (multiFindByAllForSysNetPortType !=0)
	{
		printf("\tmultiFindByAllForSysNetPortType:%d\n",multiFindByAllForSysNetPortType);
	}
	if (findByOneForSysNetPortType !=0)
	{
		printf("\tfindByOneForSysNetPortType:%d\n",findByOneForSysNetPortType);
	}
	if (multiFindByAllForSysNetInterface !=0)
	{
		printf("\tmultiFindByAllForSysNetInterface:%d\n",multiFindByAllForSysNetInterface);
	}
	if (findByOneForSysNetInterface !=0)
	{
		printf("\tfindByOneForSysNetInterface:%d\n",findByOneForSysNetInterface);
	}
	if (multiFindByDeviceIDForSysNetInterface !=0)
	{
		printf("\tmultiFindByDeviceIDForSysNetInterface:%d\n",multiFindByDeviceIDForSysNetInterface);
	}
	if (findByObjectIDForSysNetInterface !=0)
	{
		printf("\tfindByObjectIDForSysNetInterface:%d\n",findByObjectIDForSysNetInterface);
	}
	if (multiFindByAllForSysNetGeneralOID !=0)
	{
		printf("\tmultiFindByAllForSysNetGeneralOID:%d\n",multiFindByAllForSysNetGeneralOID);
	}
	if (findByOneForSysNetGeneralOID !=0)
	{
		printf("\tfindByOneForSysNetGeneralOID:%d\n",findByOneForSysNetGeneralOID);
	}
	if (multiFindByAllForSysNetMonitorType !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorType:%d\n",multiFindByAllForSysNetMonitorType);
	}
	if (findByOneForSysNetMonitorType !=0)
	{
		printf("\tfindByOneForSysNetMonitorType:%d\n",findByOneForSysNetMonitorType);
	}
	if (multiFindByAllForSysNetMonitorAttrScope !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorAttrScope:%d\n",multiFindByAllForSysNetMonitorAttrScope);
	}
	if (findByOneForSysNetMonitorAttrScope !=0)
	{
		printf("\tfindByOneForSysNetMonitorAttrScope:%d\n",findByOneForSysNetMonitorAttrScope);
	}
	if (multiFindByAllForSysNetMonitorAttrType !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorAttrType:%d\n",multiFindByAllForSysNetMonitorAttrType);
	}
	if (findByOneForSysNetMonitorAttrType !=0)
	{
		printf("\tfindByOneForSysNetMonitorAttrType:%d\n",findByOneForSysNetMonitorAttrType);
	}
	if (multiFindByAllForSysNetMonitorCommandType !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorCommandType:%d\n",multiFindByAllForSysNetMonitorCommandType);
	}
	if (findByOneForSysNetMonitorCommandType !=0)
	{
		printf("\tfindByOneForSysNetMonitorCommandType:%d\n",findByOneForSysNetMonitorCommandType);
	}
	if (multiFindByAllForSysNetMonitorActionGroup !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorActionGroup:%d\n",multiFindByAllForSysNetMonitorActionGroup);
	}
	if (findByOneForSysNetMonitorActionGroup !=0)
	{
		printf("\tfindByOneForSysNetMonitorActionGroup:%d\n",findByOneForSysNetMonitorActionGroup);
	}
	if (multiFindByAllForSysNetMonitorDeviceGroup !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorDeviceGroup:%d\n",multiFindByAllForSysNetMonitorDeviceGroup);
	}
	if (findByOneForSysNetMonitorDeviceGroup !=0)
	{
		printf("\tfindByOneForSysNetMonitorDeviceGroup:%d\n",findByOneForSysNetMonitorDeviceGroup);
	}
	if (multiFindByAllForSysNetMonitorTaskInfo !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorTaskInfo:%d\n",multiFindByAllForSysNetMonitorTaskInfo);
	}
	if (findByOneForSysNetMonitorTaskInfo !=0)
	{
		printf("\tfindByOneForSysNetMonitorTaskInfo:%d\n",findByOneForSysNetMonitorTaskInfo);
	}
	if (multiFindByAllForSysNetMonitorTaskObjectSet !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorTaskObjectSet:%d\n",multiFindByAllForSysNetMonitorTaskObjectSet);
	}
	if (multiFindByDeviceGroup_IDForSysNetMonitorTaskObjectSet !=0)
	{
		printf("\tmultiFindByDeviceGroup_IDForSysNetMonitorTaskObjectSet:%d\n",multiFindByDeviceGroup_IDForSysNetMonitorTaskObjectSet);
	}
	if (multiFindByAllForSysNetMonitorTaskResult !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorTaskResult:%d\n",multiFindByAllForSysNetMonitorTaskResult);
	}
	if (multiFindByTask_IDForSysNetMonitorTaskResult !=0)
	{
		printf("\tmultiFindByTask_IDForSysNetMonitorTaskResult:%d\n",multiFindByTask_IDForSysNetMonitorTaskResult);
	}
	if (multiFindByOnlyDateForSysNetMonitorTaskResult !=0)
	{
		printf("\tmultiFindByOnlyDateForSysNetMonitorTaskResult:%d\n",multiFindByOnlyDateForSysNetMonitorTaskResult);
	}
	if (multiFindByIDTaskTimeForSysNetMonitorTaskResult !=0)
	{
		printf("\tmultiFindByIDTaskTimeForSysNetMonitorTaskResult:%d\n",multiFindByIDTaskTimeForSysNetMonitorTaskResult);
	}
	if (multiFindByDataDeleteForSysNetMonitorTaskResult !=0)
	{
		printf("\tmultiFindByDataDeleteForSysNetMonitorTaskResult:%d\n",multiFindByDataDeleteForSysNetMonitorTaskResult);
	}
	if (multiFindByAllForSysNetPartyLinkInfo !=0)
	{
		printf("\tmultiFindByAllForSysNetPartyLinkInfo:%d\n",multiFindByAllForSysNetPartyLinkInfo);
	}
	if (findByOneForSysNetPartyLinkInfo !=0)
	{
		printf("\tfindByOneForSysNetPartyLinkInfo:%d\n",findByOneForSysNetPartyLinkInfo);
	}
	if (multiFindByAllForSysNetDelPartyLinkInfo !=0)
	{
		printf("\tmultiFindByAllForSysNetDelPartyLinkInfo:%d\n",multiFindByAllForSysNetDelPartyLinkInfo);
	}
	if (findByOneForSysNetDelPartyLinkInfo !=0)
	{
		printf("\tfindByOneForSysNetDelPartyLinkInfo:%d\n",findByOneForSysNetDelPartyLinkInfo);
	}
	if (multiFindByAllForSysNetPartyLinkAddrChange !=0)
	{
		printf("\tmultiFindByAllForSysNetPartyLinkAddrChange:%d\n",multiFindByAllForSysNetPartyLinkAddrChange);
	}
	if (findByOneForSysNetPartyLinkAddrChange !=0)
	{
		printf("\tfindByOneForSysNetPartyLinkAddrChange:%d\n",findByOneForSysNetPartyLinkAddrChange);
	}
	if (multiFindByAllForSysNetMonitorActionAttr !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorActionAttr:%d\n",multiFindByAllForSysNetMonitorActionAttr);
	}
	if (findByOneForSysNetMonitorActionAttr !=0)
	{
		printf("\tfindByOneForSysNetMonitorActionAttr:%d\n",findByOneForSysNetMonitorActionAttr);
	}
	if (multiFindByAllForSysNetModule !=0)
	{
		printf("\tmultiFindByAllForSysNetModule:%d\n",multiFindByAllForSysNetModule);
	}
	if (findByOneForSysNetModule !=0)
	{
		printf("\tfindByOneForSysNetModule:%d\n",findByOneForSysNetModule);
	}
	if (multiFindByDeviceIDForSysNetModule !=0)
	{
		printf("\tmultiFindByDeviceIDForSysNetModule:%d\n",multiFindByDeviceIDForSysNetModule);
	}
	if (findByObjectIDForSysNetModule !=0)
	{
		printf("\tfindByObjectIDForSysNetModule:%d\n",findByObjectIDForSysNetModule);
	}
	if (multiFindByAllForSysNetEventExpr !=0)
	{
		printf("\tmultiFindByAllForSysNetEventExpr:%d\n",multiFindByAllForSysNetEventExpr);
	}
	if (findByOneForSysNetEventExpr !=0)
	{
		printf("\tfindByOneForSysNetEventExpr:%d\n",findByOneForSysNetEventExpr);
	}
	if (multiFindByAllForSysNetEventType !=0)
	{
		printf("\tmultiFindByAllForSysNetEventType:%d\n",multiFindByAllForSysNetEventType);
	}
	if (findByOneForSysNetEventType !=0)
	{
		printf("\tfindByOneForSysNetEventType:%d\n",findByOneForSysNetEventType);
	}
	if (multiFindByAllForSysNetSubEventType !=0)
	{
		printf("\tmultiFindByAllForSysNetSubEventType:%d\n",multiFindByAllForSysNetSubEventType);
	}
	if (findByOneForSysNetSubEventType !=0)
	{
		printf("\tfindByOneForSysNetSubEventType:%d\n",findByOneForSysNetSubEventType);
	}
	if (multiFindByAllForSysNetEventLevel !=0)
	{
		printf("\tmultiFindByAllForSysNetEventLevel:%d\n",multiFindByAllForSysNetEventLevel);
	}
	if (findByOneForSysNetEventLevel !=0)
	{
		printf("\tfindByOneForSysNetEventLevel:%d\n",findByOneForSysNetEventLevel);
	}
	if (multiFindByAllForSysNetMonitorDeviceTask !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorDeviceTask:%d\n",multiFindByAllForSysNetMonitorDeviceTask);
	}
	if (multiFindByIDForSysNetMonitorDeviceTask !=0)
	{
		printf("\tmultiFindByIDForSysNetMonitorDeviceTask:%d\n",multiFindByIDForSysNetMonitorDeviceTask);
	}
	if (multiFindByAllForSysNetMonitorTaskInstAttrs !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorTaskInstAttrs:%d\n",multiFindByAllForSysNetMonitorTaskInstAttrs);
	}
	if (multiFindByAllForSysNetBaseLine !=0)
	{
		printf("\tmultiFindByAllForSysNetBaseLine:%d\n",multiFindByAllForSysNetBaseLine);
	}
	if (multiFindByIDForSysNetBaseLine !=0)
	{
		printf("\tmultiFindByIDForSysNetBaseLine:%d\n",multiFindByIDForSysNetBaseLine);
	}
	if (multiFindByAllForSysNetBaseLineTask !=0)
	{
		printf("\tmultiFindByAllForSysNetBaseLineTask:%d\n",multiFindByAllForSysNetBaseLineTask);
	}
	if (multiFindByTimeForSysMdbNetPartyLinkStatusInfo !=0)
	{
		printf("\tmultiFindByTimeForSysMdbNetPartyLinkStatusInfo:%d\n",multiFindByTimeForSysMdbNetPartyLinkStatusInfo);
	}
	if (multiFindByDscForSysMdbNetPartyLinkStatusInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbNetPartyLinkStatusInfo:%d\n",multiFindByDscForSysMdbNetPartyLinkStatusInfo);
	}
	if (multiFindByAllForSysMdbNetPartyLinkStatusInfo !=0)
	{
		printf("\tmultiFindByAllForSysMdbNetPartyLinkStatusInfo:%d\n",multiFindByAllForSysMdbNetPartyLinkStatusInfo);
	}
	if (multiFindByAllForSysNetMemberSDHLineInfo !=0)
	{
		printf("\tmultiFindByAllForSysNetMemberSDHLineInfo:%d\n",multiFindByAllForSysNetMemberSDHLineInfo);
	}
	if (multiFindByAllForSysNetDDNLinkInfo !=0)
	{
		printf("\tmultiFindByAllForSysNetDDNLinkInfo:%d\n",multiFindByAllForSysNetDDNLinkInfo);
	}
	if (multiFindByAllForSysNetPseudMemberLinkInfo !=0)
	{
		printf("\tmultiFindByAllForSysNetPseudMemberLinkInfo:%d\n",multiFindByAllForSysNetPseudMemberLinkInfo);
	}
	if (multiFindByAllForSysNetOuterDeviceInfo !=0)
	{
		printf("\tmultiFindByAllForSysNetOuterDeviceInfo:%d\n",multiFindByAllForSysNetOuterDeviceInfo);
	}
	if (multiFindByAllForSysLocalPingResultInfo !=0)
	{
		printf("\tmultiFindByAllForSysLocalPingResultInfo:%d\n",multiFindByAllForSysLocalPingResultInfo);
	}
	if (multiFindByIDTypeForSysLocalPingResultInfo !=0)
	{
		printf("\tmultiFindByIDTypeForSysLocalPingResultInfo:%d\n",multiFindByIDTypeForSysLocalPingResultInfo);
	}
	if (multiFindByAllForSysRomotePingResultInfo !=0)
	{
		printf("\tmultiFindByAllForSysRomotePingResultInfo:%d\n",multiFindByAllForSysRomotePingResultInfo);
	}
	if (multiFindByIDTypeForSysRomotePingResultInfo !=0)
	{
		printf("\tmultiFindByIDTypeForSysRomotePingResultInfo:%d\n",multiFindByIDTypeForSysRomotePingResultInfo);
	}
	if (multiFindByAllForSysParticTradeOrderStates !=0)
	{
		printf("\tmultiFindByAllForSysParticTradeOrderStates:%d\n",multiFindByAllForSysParticTradeOrderStates);
	}
	if (findByOneForSysParticTradeOrderStates !=0)
	{
		printf("\tfindByOneForSysParticTradeOrderStates:%d\n",findByOneForSysParticTradeOrderStates);
	}
	if (multiFindByUserIDForSysParticTradeOrderStates !=0)
	{
		printf("\tmultiFindByUserIDForSysParticTradeOrderStates:%d\n",multiFindByUserIDForSysParticTradeOrderStates);
	}
	if (multiFindByHostNameForSysMdbRouterInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysMdbRouterInfo:%d\n",multiFindByHostNameForSysMdbRouterInfo);
	}
	if (multiFindByDscForSysMdbRouterInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbRouterInfo:%d\n",multiFindByDscForSysMdbRouterInfo);
	}
	if (multiFindBytheAllForSysMdbRouterInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbRouterInfo:%d\n",multiFindBytheAllForSysMdbRouterInfo);
	}
	if (multiFindByDataDeleteForSysMdbRouterInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbRouterInfo:%d\n",multiFindByDataDeleteForSysMdbRouterInfo);
	}
	if (multiFindByHostNameForSysMdbDiskIO !=0)
	{
		printf("\tmultiFindByHostNameForSysMdbDiskIO:%d\n",multiFindByHostNameForSysMdbDiskIO);
	}
	if (multiFindByDscForSysMdbDiskIO !=0)
	{
		printf("\tmultiFindByDscForSysMdbDiskIO:%d\n",multiFindByDscForSysMdbDiskIO);
	}
	if (multiFindBytheAllForSysMdbDiskIO !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbDiskIO:%d\n",multiFindBytheAllForSysMdbDiskIO);
	}
	if (multiFindByDataDeleteForSysMdbDiskIO !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbDiskIO:%d\n",multiFindByDataDeleteForSysMdbDiskIO);
	}
	if (multiFindByHostNameForSysMdbStatInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysMdbStatInfo:%d\n",multiFindByHostNameForSysMdbStatInfo);
	}
	if (multiFindByDscForSysMdbStatInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbStatInfo:%d\n",multiFindByDscForSysMdbStatInfo);
	}
	if (multiFindBytheAllForSysMdbStatInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbStatInfo:%d\n",multiFindBytheAllForSysMdbStatInfo);
	}
	if (multiFindByDataDeleteForSysMdbStatInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbStatInfo:%d\n",multiFindByDataDeleteForSysMdbStatInfo);
	}
	if (multiFindByFrontIndexForSysMdbTradeFrontOrderRttStat !=0)
	{
		printf("\tmultiFindByFrontIndexForSysMdbTradeFrontOrderRttStat:%d\n",multiFindByFrontIndexForSysMdbTradeFrontOrderRttStat);
	}
	if (multiFindByDscForSysMdbTradeFrontOrderRttStat !=0)
	{
		printf("\tmultiFindByDscForSysMdbTradeFrontOrderRttStat:%d\n",multiFindByDscForSysMdbTradeFrontOrderRttStat);
	}
	if (multiFindBytheAllForSysMdbTradeFrontOrderRttStat !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbTradeFrontOrderRttStat:%d\n",multiFindBytheAllForSysMdbTradeFrontOrderRttStat);
	}
	if (findByTheOneForSysMdbTradeFrontOrderRttStat !=0)
	{
		printf("\tfindByTheOneForSysMdbTradeFrontOrderRttStat:%d\n",findByTheOneForSysMdbTradeFrontOrderRttStat);
	}
	if (multiFindByActionTimeForSysInstrumentStatus !=0)
	{
		printf("\tmultiFindByActionTimeForSysInstrumentStatus:%d\n",multiFindByActionTimeForSysInstrumentStatus);
	}
	if (multiFindBytheAllForSysInstrumentStatus !=0)
	{
		printf("\tmultiFindBytheAllForSysInstrumentStatus:%d\n",multiFindBytheAllForSysInstrumentStatus);
	}
	if (multiFindByActionTimeForSysCurrTradingSegmentAttr !=0)
	{
		printf("\tmultiFindByActionTimeForSysCurrTradingSegmentAttr:%d\n",multiFindByActionTimeForSysCurrTradingSegmentAttr);
	}
	if (multiFindBytheAllForSysCurrTradingSegmentAttr !=0)
	{
		printf("\tmultiFindBytheAllForSysCurrTradingSegmentAttr:%d\n",multiFindBytheAllForSysCurrTradingSegmentAttr);
	}
	if (multiFindByPayTimeForSysMemberLinkCost !=0)
	{
		printf("\tmultiFindByPayTimeForSysMemberLinkCost:%d\n",multiFindByPayTimeForSysMemberLinkCost);
	}
	if (multiFindBytheAllForSysMemberLinkCost !=0)
	{
		printf("\tmultiFindBytheAllForSysMemberLinkCost:%d\n",multiFindBytheAllForSysMemberLinkCost);
	}
	if (multiFindByAllForSysMemberLinkCost !=0)
	{
		printf("\tmultiFindByAllForSysMemberLinkCost:%d\n",multiFindByAllForSysMemberLinkCost);
	}
	if (multiFindByLineNameForSysNetPartylinkMonthlyRent !=0)
	{
		printf("\tmultiFindByLineNameForSysNetPartylinkMonthlyRent:%d\n",multiFindByLineNameForSysNetPartylinkMonthlyRent);
	}
	if (multiFindBytheAllForSysNetPartylinkMonthlyRent !=0)
	{
		printf("\tmultiFindBytheAllForSysNetPartylinkMonthlyRent:%d\n",multiFindBytheAllForSysNetPartylinkMonthlyRent);
	}
	if (multiFindByAllForSysNetPartylinkMonthlyRent !=0)
	{
		printf("\tmultiFindByAllForSysNetPartylinkMonthlyRent:%d\n",multiFindByAllForSysNetPartylinkMonthlyRent);
	}
	if (multiFindByAllForSysNetNonPartyLinkInfo !=0)
	{
		printf("\tmultiFindByAllForSysNetNonPartyLinkInfo:%d\n",multiFindByAllForSysNetNonPartyLinkInfo);
	}
	if (findByOneForSysNetNonPartyLinkInfo !=0)
	{
		printf("\tfindByOneForSysNetNonPartyLinkInfo:%d\n",findByOneForSysNetNonPartyLinkInfo);
	}
}

void initAllSearchCount(void)
{
	multiFindByActionTimeForSysInvalidateOrder=0;
	multiFindByActionTimeForSysOrderStatus=0;
	multiFindByActionTimeForSysBargainOrder=0;
	multiFindByAllForSysInstProperty=0;
	findByOneForSysInstProperty=0;
	multiFindByAllForSysMarginRate=0;
	findByOneForSysMarginRate=0;
	multiFindByAllForSysPriceLimit=0;
	findByOneForSysPriceLimit=0;
	multiFindByAllForSysPartPosiLimit=0;
	findByOneForSysPartPosiLimit=0;
	multiFindByAllForSysClientPosiLimit=0;
	findByOneForSysClientPosiLimit=0;
	multiFindByAllForSysSpecialPosiLimit=0;
	findByOneForSysSpecialPosiLimit=0;
	multiFindByActionTimeForSysTransactionChg=0;
	multiFindByActionTimeForSysClientChg=0;
	multiFindByActionTimeForSysPartClientChg=0;
	multiFindByActionTimeForSysPosiLimitChg=0;
	multiFindByActionTimeForSysClientPosiLimitChg=0;
	multiFindByActionTimeForSysSpecPosiLimitChg=0;
	multiFindByActionTimeForSysHedgeDetailChg=0;
	multiFindByActionTimeForSysParticipantChg=0;
	multiFindByActionTimeForSysMarginRateChg=0;
	multiFindByActionTimeForSysUserIpChg=0;
	multiFindByAllForSysPartTrade=0;
	findByOneForSysPartTrade=0;
	multiFindByIDTypeForSysMdbObjectAttr=0;
	multiFindByDscForSysMdbObjectAttr=0;
	findByOneForSysMdbObjectAttr=0;
	multiFindBytheAllForSysMdbObjectAttr=0;
	multiFindByDataDeleteForSysMdbObjectAttr=0;
	multiFindByAllForSysMdbSyslogInfo=0;
	multiFindBytheAllForSysMdbSyslogInfo=0;
	multiFindByDataDeleteForSysMdbSyslogInfo=0;
	multiFindByHostNameForSysUserInfo=0;
	multiFindBytheAllForSysUserInfo=0;
	multiFindByDscForSysUserInfo=0;
	multiFindByHostNameForSysOnlineUserInfo=0;
	multiFindBytheAllForSysOnlineUserInfo=0;
	multiFindByDscForSysOnlineUserInfo=0;
	multiFindByTimeForSysWarningEvent=0;
	multiFindByAllForSysWarningEvent=0;
	findByEvendIDForSysWarningEvent=0;
	multiFindByEvendIDsForSysWarningEvent=0;
	multiFindBytheAllForSysWarningEvent=0;
	multiFindByTimeForSysWarningQuery=0;
	findByEvendIDForSysWarningQuery=0;
	multiFindByTimeForSyslogEvent=0;
	multiFindBytheAllForSyslogEvent=0;
	multiFindByAllForSyslogEvent=0;
	findByEvendIDForSyslogEvent=0;
	multiFindByTimeForSysEventDescrip=0;
	multiFindBytheAllForSysEventDescrip=0;
	multiFindByAllForSysEventDescrip=0;
	findByEvendIDForSysEventDescrip=0;
	multiFindByHostNameForRspQryHostEnvCommon=0;
	multiFindBytheAllForRspQryHostEnvCommon=0;
	multiFindByHostNameForRspQryHostEnvLan=0;
	multiFindBytheAllForRspQryHostEnvLan=0;
	multiFindByHostNameForRspQryHostEnvStorage=0;
	multiFindBytheAllForRspQryHostEnvStorage=0;
	multiFindByHostNameForRspQryHostEnvIO=0;
	multiFindBytheAllForRspQryHostEnvIO=0;
	multiFindByHostNameForRspQryHostEnvFS=0;
	multiFindBytheAllForRspQryHostEnvFS=0;
	multiFindByHostNameForRspQryHostEnvSwap=0;
	multiFindBytheAllForRspQryHostEnvSwap=0;
	multiFindByHostNameForRspQryHostEnvLanCfg=0;
	multiFindBytheAllForRspQryHostEnvLanCfg=0;
	multiFindByHostNameForSysMdbTopCpuInfo=0;
	multiFindByDscForSysMdbTopCpuInfo=0;
	multiFindBytheAllForSysMdbTopCpuInfo=0;
	multiFindByDataDeleteForSysMdbTopCpuInfo=0;
	multiFindByHostNameForSysMdbTopMemInfo=0;
	multiFindByDscForSysMdbTopMemInfo=0;
	multiFindBytheAllForSysMdbTopMemInfo=0;
	multiFindByDataDeleteForSysMdbTopMemInfo=0;
	multiFindByHostNameForSysMdbTopProcessInfo=0;
	multiFindByDscForSysMdbTopProcessInfo=0;
	multiFindBytheAllForSysMdbTopProcessInfo=0;
	multiFindByHostNameForSysMdbFileSystemInfo=0;
	multiFindByDscForSysMdbFileSystemInfo=0;
	multiFindBytheAllForSysMdbFileSystemInfo=0;
	multiFindByHostNameForSysMdbNetworkInfo=0;
	multiFindByDscForSysMdbNetworkInfo=0;
	multiFindBytheAllForSysMdbNetworkInfo=0;
	multiFindByDataDeleteForSysMdbNetworkInfo=0;
	multiFindByAllForSysParticipantInit=0;
	findByOneForSysParticipantInit=0;
	multiFindByAllForSysUserInit=0;
	findByOneForSysUserInit=0;
	multiFindByAllForSysClientInit=0;
	findByOneForSysClientInit=0;
	multiFindByAllForSysTradeUserLoginInfo=0;
	findByOneForSysTradeUserLoginInfo=0;
	multiFindByIDTypeForSysMdbWebAppInfo=0;
	multiFindByDscForSysMdbWebAppInfo=0;
	findByOneForSysMdbWebAppInfo=0;
	multiFindBytheAllForSysMdbWebAppInfo=0;
	multiFindByDataDeleteForSysMdbWebAppInfo=0;
	multiFindByIDTypeForSysMdbMemPoolInfo=0;
	multiFindByDscForSysMdbMemPoolInfo=0;
	findByOneForSysMdbMemPoolInfo=0;
	multiFindBytheAllForSysMdbMemPoolInfo=0;
	multiFindByDataDeleteForSysMdbMemPoolInfo=0;
	multiFindByIDTypeForSysMdbConnectorInfo=0;
	multiFindByDscForSysMdbConnectorInfo=0;
	findByOneForSysMdbConnectorInfo=0;
	multiFindBytheAllForSysMdbConnectorInfo=0;
	multiFindByDataDeleteForSysMdbConnectorInfo=0;
	multiFindByIDTypeForSysMdbDBQuery=0;
	multiFindByDscForSysMdbDBQuery=0;
	findByOneForSysMdbDBQuery=0;
	multiFindBytheAllForSysMdbDBQuery=0;
	multiFindByDataDeleteForSysMdbDBQuery=0;
	multiFindByAllForSysNetArea=0;
	findByOneForSysNetArea=0;
	multiFindByAllForSysNetSubArea=0;
	findByOneForSysNetSubArea=0;
	multiFindByAllForSysNetSubAreaIP=0;
	findByOneForSysNetSubAreaIP=0;
	multiFindByAllForSysNetFuncArea=0;
	findByOneForSysNetFuncArea=0;
	multiFindByAllForSysNetDevice=0;
	findByOneForSysNetDevice=0;
	multiFindByIPDECODEForSysNetDevice=0;
	multiFindBySubAreaIDForSysNetDevice=0;
	findByObjectIDForSysNetDevice=0;
	multiFindByAllForSysNetDeviceLinked=0;
	findByOneForSysNetDeviceLinked=0;
	multiFindByNetObjectIDForSysNetDeviceLinked=0;
	multiFindByLinkNetObjectIDForSysNetDeviceLinked=0;
	multiFindByAllForSysNetOID=0;
	findByOneForSysNetOID=0;
	multiFindByAllForSysNetDeviceType=0;
	findByOneForSysNetDeviceType=0;
	multiFindByAllForSysNetTimePolicy=0;
	findByOneForSysNetTimePolicy=0;
	multiFindByAllForSysNetGatherTask=0;
	findByOneForSysNetGatherTask=0;
	multiFindByNetObjectIDForSysNetGatherTask=0;
	multiFindByAllForSysNetDeviceCategory=0;
	findByOneForSysNetDeviceCategory=0;
	multiFindByAllForSysNetManufactory=0;
	findByOneForSysNetManufactory=0;
	multiFindByAllForSysNetCommunity=0;
	findByOneForSysNetCommunity=0;
	multiFindByAllForSysNetPortType=0;
	findByOneForSysNetPortType=0;
	multiFindByAllForSysNetInterface=0;
	findByOneForSysNetInterface=0;
	multiFindByDeviceIDForSysNetInterface=0;
	findByObjectIDForSysNetInterface=0;
	multiFindByAllForSysNetGeneralOID=0;
	findByOneForSysNetGeneralOID=0;
	multiFindByAllForSysNetMonitorType=0;
	findByOneForSysNetMonitorType=0;
	multiFindByAllForSysNetMonitorAttrScope=0;
	findByOneForSysNetMonitorAttrScope=0;
	multiFindByAllForSysNetMonitorAttrType=0;
	findByOneForSysNetMonitorAttrType=0;
	multiFindByAllForSysNetMonitorCommandType=0;
	findByOneForSysNetMonitorCommandType=0;
	multiFindByAllForSysNetMonitorActionGroup=0;
	findByOneForSysNetMonitorActionGroup=0;
	multiFindByAllForSysNetMonitorDeviceGroup=0;
	findByOneForSysNetMonitorDeviceGroup=0;
	multiFindByAllForSysNetMonitorTaskInfo=0;
	findByOneForSysNetMonitorTaskInfo=0;
	multiFindByAllForSysNetMonitorTaskObjectSet=0;
	multiFindByDeviceGroup_IDForSysNetMonitorTaskObjectSet=0;
	multiFindByAllForSysNetMonitorTaskResult=0;
	multiFindByTask_IDForSysNetMonitorTaskResult=0;
	multiFindByOnlyDateForSysNetMonitorTaskResult=0;
	multiFindByIDTaskTimeForSysNetMonitorTaskResult=0;
	multiFindByDataDeleteForSysNetMonitorTaskResult=0;
	multiFindByAllForSysNetPartyLinkInfo=0;
	findByOneForSysNetPartyLinkInfo=0;
	multiFindByAllForSysNetDelPartyLinkInfo=0;
	findByOneForSysNetDelPartyLinkInfo=0;
	multiFindByAllForSysNetPartyLinkAddrChange=0;
	findByOneForSysNetPartyLinkAddrChange=0;
	multiFindByAllForSysNetMonitorActionAttr=0;
	findByOneForSysNetMonitorActionAttr=0;
	multiFindByAllForSysNetModule=0;
	findByOneForSysNetModule=0;
	multiFindByDeviceIDForSysNetModule=0;
	findByObjectIDForSysNetModule=0;
	multiFindByAllForSysNetEventExpr=0;
	findByOneForSysNetEventExpr=0;
	multiFindByAllForSysNetEventType=0;
	findByOneForSysNetEventType=0;
	multiFindByAllForSysNetSubEventType=0;
	findByOneForSysNetSubEventType=0;
	multiFindByAllForSysNetEventLevel=0;
	findByOneForSysNetEventLevel=0;
	multiFindByAllForSysNetMonitorDeviceTask=0;
	multiFindByIDForSysNetMonitorDeviceTask=0;
	multiFindByAllForSysNetMonitorTaskInstAttrs=0;
	multiFindByAllForSysNetBaseLine=0;
	multiFindByIDForSysNetBaseLine=0;
	multiFindByAllForSysNetBaseLineTask=0;
	multiFindByTimeForSysMdbNetPartyLinkStatusInfo=0;
	multiFindByDscForSysMdbNetPartyLinkStatusInfo=0;
	multiFindByAllForSysMdbNetPartyLinkStatusInfo=0;
	multiFindByAllForSysNetMemberSDHLineInfo=0;
	multiFindByAllForSysNetDDNLinkInfo=0;
	multiFindByAllForSysNetPseudMemberLinkInfo=0;
	multiFindByAllForSysNetOuterDeviceInfo=0;
	multiFindByAllForSysLocalPingResultInfo=0;
	multiFindByIDTypeForSysLocalPingResultInfo=0;
	multiFindByAllForSysRomotePingResultInfo=0;
	multiFindByIDTypeForSysRomotePingResultInfo=0;
	multiFindByAllForSysParticTradeOrderStates=0;
	findByOneForSysParticTradeOrderStates=0;
	multiFindByUserIDForSysParticTradeOrderStates=0;
	multiFindByHostNameForSysMdbRouterInfo=0;
	multiFindByDscForSysMdbRouterInfo=0;
	multiFindBytheAllForSysMdbRouterInfo=0;
	multiFindByDataDeleteForSysMdbRouterInfo=0;
	multiFindByHostNameForSysMdbDiskIO=0;
	multiFindByDscForSysMdbDiskIO=0;
	multiFindBytheAllForSysMdbDiskIO=0;
	multiFindByDataDeleteForSysMdbDiskIO=0;
	multiFindByHostNameForSysMdbStatInfo=0;
	multiFindByDscForSysMdbStatInfo=0;
	multiFindBytheAllForSysMdbStatInfo=0;
	multiFindByDataDeleteForSysMdbStatInfo=0;
	multiFindByFrontIndexForSysMdbTradeFrontOrderRttStat=0;
	multiFindByDscForSysMdbTradeFrontOrderRttStat=0;
	multiFindBytheAllForSysMdbTradeFrontOrderRttStat=0;
	findByTheOneForSysMdbTradeFrontOrderRttStat=0;
	multiFindByActionTimeForSysInstrumentStatus=0;
	multiFindBytheAllForSysInstrumentStatus=0;
	multiFindByActionTimeForSysCurrTradingSegmentAttr=0;
	multiFindBytheAllForSysCurrTradingSegmentAttr=0;
	multiFindByPayTimeForSysMemberLinkCost=0;
	multiFindBytheAllForSysMemberLinkCost=0;
	multiFindByAllForSysMemberLinkCost=0;
	multiFindByLineNameForSysNetPartylinkMonthlyRent=0;
	multiFindBytheAllForSysNetPartylinkMonthlyRent=0;
	multiFindByAllForSysNetPartylinkMonthlyRent=0;
	multiFindByAllForSysNetNonPartyLinkInfo=0;
	findByOneForSysNetNonPartyLinkInfo=0;
}
#endif
