/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseIterators.cpp
///@brief实现了若干个内存数据库的iterator
///@history 
///20060127	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "databaseIterators.h"

//#define COUNT_SEARCH

CMemoryStack<CSysInvalidateOrderIteratorByActionTime> CSysInvalidateOrderIteratorByActionTime::iteratorList;
void CSysInvalidateOrderIteratorByActionTime::init(CSysInvalidateOrderFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysInvalidateOrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ActionTime=ActionTime.getValue();

}

CSysInvalidateOrderIteratorByActionTime *CSysInvalidateOrderIteratorByActionTime::alloc(CSysInvalidateOrderFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	CSysInvalidateOrderIteratorByActionTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,ActionTime);
	return it;
}

CSysInvalidateOrderIteratorByActionTime::~CSysInvalidateOrderIteratorByActionTime(void)
{
}

void CSysInvalidateOrderIteratorByActionTime::free(void)
{
	iteratorList.free(this);
}

void CSysInvalidateOrderIteratorByActionTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysInvalidateOrderIteratorByActionTime");
	
	char buffer[200];
	
	m_compareObject.ActionTime.getString(buffer);
	pLogger->output(indent+1,0,"query ActionTime=%s",buffer);
	
}

void CSysInvalidateOrderIteratorByActionTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysInsertTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysInsertTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysInvalidateOrderIteratorByActionTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysInvalidateOrder *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysInvalidateOrderIteratorByActionTime::UpdateCurrent(CWriteableSysInvalidateOrder * pByActionTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysInvalidateOrder *)(m_pCurrent->pObject),pByActionTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByActionTimeForSysInvalidateOrder;
#endif

CSysInvalidateOrder *CSysInvalidateOrderIteratorByActionTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysInvalidateOrder++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysInvalidateOrder *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysInvalidateOrder *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysInvalidateOrderIteratorByActionTime::match(CSysInvalidateOrder *pSysInvalidateOrder)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysOrderStatusIteratorByActionTime> CSysOrderStatusIteratorByActionTime::iteratorList;
void CSysOrderStatusIteratorByActionTime::init(CSysOrderStatusFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysOrderStatusIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ActionTime=ActionTime.getValue();

}

CSysOrderStatusIteratorByActionTime *CSysOrderStatusIteratorByActionTime::alloc(CSysOrderStatusFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	CSysOrderStatusIteratorByActionTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,ActionTime);
	return it;
}

CSysOrderStatusIteratorByActionTime::~CSysOrderStatusIteratorByActionTime(void)
{
}

void CSysOrderStatusIteratorByActionTime::free(void)
{
	iteratorList.free(this);
}

void CSysOrderStatusIteratorByActionTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysOrderStatusIteratorByActionTime");
	
	char buffer[200];
	
	m_compareObject.ActionTime.getString(buffer);
	pLogger->output(indent+1,0,"query ActionTime=%s",buffer);
	
}

void CSysOrderStatusIteratorByActionTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysActionTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysActionTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysOrderStatusIteratorByActionTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysOrderStatus *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysOrderStatusIteratorByActionTime::UpdateCurrent(CWriteableSysOrderStatus * pByActionTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysOrderStatus *)(m_pCurrent->pObject),pByActionTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByActionTimeForSysOrderStatus;
#endif

CSysOrderStatus *CSysOrderStatusIteratorByActionTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysOrderStatus++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysOrderStatus *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysOrderStatus *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysOrderStatusIteratorByActionTime::match(CSysOrderStatus *pSysOrderStatus)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysBargainOrderIteratorByActionTime> CSysBargainOrderIteratorByActionTime::iteratorList;
void CSysBargainOrderIteratorByActionTime::init(CSysBargainOrderFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysBargainOrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ActionTime=ActionTime.getValue();

}

CSysBargainOrderIteratorByActionTime *CSysBargainOrderIteratorByActionTime::alloc(CSysBargainOrderFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	CSysBargainOrderIteratorByActionTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,ActionTime);
	return it;
}

CSysBargainOrderIteratorByActionTime::~CSysBargainOrderIteratorByActionTime(void)
{
}

void CSysBargainOrderIteratorByActionTime::free(void)
{
	iteratorList.free(this);
}

void CSysBargainOrderIteratorByActionTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysBargainOrderIteratorByActionTime");
	
	char buffer[200];
	
	m_compareObject.ActionTime.getString(buffer);
	pLogger->output(indent+1,0,"query ActionTime=%s",buffer);
	
}

void CSysBargainOrderIteratorByActionTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTradeTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTradeTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysBargainOrderIteratorByActionTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysBargainOrder *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysBargainOrderIteratorByActionTime::UpdateCurrent(CWriteableSysBargainOrder * pByActionTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysBargainOrder *)(m_pCurrent->pObject),pByActionTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByActionTimeForSysBargainOrder;
#endif

CSysBargainOrder *CSysBargainOrderIteratorByActionTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysBargainOrder++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysBargainOrder *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysBargainOrder *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysBargainOrderIteratorByActionTime::match(CSysBargainOrder *pSysBargainOrder)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysInstPropertyIteratorByAll> CSysInstPropertyIteratorByAll::iteratorList;
void CSysInstPropertyIteratorByAll::init(CSysInstPropertyFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysInstPropertyIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID="";

}

CSysInstPropertyIteratorByAll *CSysInstPropertyIteratorByAll::alloc(CSysInstPropertyFactory *pFactory
		)
{
	CSysInstPropertyIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysInstPropertyIteratorByAll::~CSysInstPropertyIteratorByAll(void)
{
}

void CSysInstPropertyIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysInstPropertyIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysInstPropertyIteratorByAll");
	
	
}

void CSysInstPropertyIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysInstrumentIDIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysInstrumentIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysInstPropertyIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysInstProperty *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysInstPropertyIteratorByAll::UpdateCurrent(CWriteableSysInstProperty * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysInstProperty *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysInstProperty;
#endif

CSysInstProperty *CSysInstPropertyIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysInstProperty++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysInstProperty *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysInstProperty *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysInstPropertyIteratorByAll::match(CSysInstProperty *pSysInstProperty)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysMarginRateIteratorByAll> CSysMarginRateIteratorByAll::iteratorList;
void CSysMarginRateIteratorByAll::init(CSysMarginRateFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMarginRateIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID="";
	m_compareObject.ParticipantID="";
	m_compareObject.TradingRole="";

}

CSysMarginRateIteratorByAll *CSysMarginRateIteratorByAll::alloc(CSysMarginRateFactory *pFactory
		)
{
	CSysMarginRateIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMarginRateIteratorByAll::~CSysMarginRateIteratorByAll(void)
{
}

void CSysMarginRateIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysMarginRateIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMarginRateIteratorByAll");
	
	
}

void CSysMarginRateIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysInstrumentIDIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysInstrumentIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMarginRateIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMarginRate *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMarginRateIteratorByAll::UpdateCurrent(CWriteableSysMarginRate * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMarginRate *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysMarginRate;
#endif

CSysMarginRate *CSysMarginRateIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysMarginRate++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMarginRate *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMarginRate *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMarginRateIteratorByAll::match(CSysMarginRate *pSysMarginRate)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysPriceLimitIteratorByAll> CSysPriceLimitIteratorByAll::iteratorList;
void CSysPriceLimitIteratorByAll::init(CSysPriceLimitFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysPriceLimitIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID="";

}

CSysPriceLimitIteratorByAll *CSysPriceLimitIteratorByAll::alloc(CSysPriceLimitFactory *pFactory
		)
{
	CSysPriceLimitIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysPriceLimitIteratorByAll::~CSysPriceLimitIteratorByAll(void)
{
}

void CSysPriceLimitIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysPriceLimitIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysPriceLimitIteratorByAll");
	
	
}

void CSysPriceLimitIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysInstrumentIDIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysInstrumentIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysPriceLimitIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysPriceLimit *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysPriceLimitIteratorByAll::UpdateCurrent(CWriteableSysPriceLimit * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysPriceLimit *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysPriceLimit;
#endif

CSysPriceLimit *CSysPriceLimitIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysPriceLimit++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysPriceLimit *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysPriceLimit *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysPriceLimitIteratorByAll::match(CSysPriceLimit *pSysPriceLimit)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysPartPosiLimitIteratorByAll> CSysPartPosiLimitIteratorByAll::iteratorList;
void CSysPartPosiLimitIteratorByAll::init(CSysPartPosiLimitFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysPartPosiLimitIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID="";
	m_compareObject.ParticipantID="";

}

CSysPartPosiLimitIteratorByAll *CSysPartPosiLimitIteratorByAll::alloc(CSysPartPosiLimitFactory *pFactory
		)
{
	CSysPartPosiLimitIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysPartPosiLimitIteratorByAll::~CSysPartPosiLimitIteratorByAll(void)
{
}

void CSysPartPosiLimitIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysPartPosiLimitIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysPartPosiLimitIteratorByAll");
	
	
}

void CSysPartPosiLimitIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysInstrumentIDIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysInstrumentIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysPartPosiLimitIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysPartPosiLimit *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysPartPosiLimitIteratorByAll::UpdateCurrent(CWriteableSysPartPosiLimit * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysPartPosiLimit *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysPartPosiLimit;
#endif

CSysPartPosiLimit *CSysPartPosiLimitIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysPartPosiLimit++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysPartPosiLimit *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysPartPosiLimit *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysPartPosiLimitIteratorByAll::match(CSysPartPosiLimit *pSysPartPosiLimit)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysClientPosiLimitIteratorByAll> CSysClientPosiLimitIteratorByAll::iteratorList;
void CSysClientPosiLimitIteratorByAll::init(CSysClientPosiLimitFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysClientPosiLimitIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID="";
	m_compareObject.ClientType=CT_Person;

}

CSysClientPosiLimitIteratorByAll *CSysClientPosiLimitIteratorByAll::alloc(CSysClientPosiLimitFactory *pFactory
		)
{
	CSysClientPosiLimitIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysClientPosiLimitIteratorByAll::~CSysClientPosiLimitIteratorByAll(void)
{
}

void CSysClientPosiLimitIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysClientPosiLimitIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysClientPosiLimitIteratorByAll");
	
	
}

void CSysClientPosiLimitIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysInstrumentIDIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysInstrumentIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysClientPosiLimitIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysClientPosiLimit *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysClientPosiLimitIteratorByAll::UpdateCurrent(CWriteableSysClientPosiLimit * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysClientPosiLimit *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysClientPosiLimit;
#endif

CSysClientPosiLimit *CSysClientPosiLimitIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysClientPosiLimit++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysClientPosiLimit *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysClientPosiLimit *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysClientPosiLimitIteratorByAll::match(CSysClientPosiLimit *pSysClientPosiLimit)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysSpecialPosiLimitIteratorByAll> CSysSpecialPosiLimitIteratorByAll::iteratorList;
void CSysSpecialPosiLimitIteratorByAll::init(CSysSpecialPosiLimitFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysSpecialPosiLimitIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID="";
	m_compareObject.ClientID="";

}

CSysSpecialPosiLimitIteratorByAll *CSysSpecialPosiLimitIteratorByAll::alloc(CSysSpecialPosiLimitFactory *pFactory
		)
{
	CSysSpecialPosiLimitIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysSpecialPosiLimitIteratorByAll::~CSysSpecialPosiLimitIteratorByAll(void)
{
}

void CSysSpecialPosiLimitIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysSpecialPosiLimitIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysSpecialPosiLimitIteratorByAll");
	
	
}

void CSysSpecialPosiLimitIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysInstrumentIDIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysInstrumentIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysSpecialPosiLimitIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysSpecialPosiLimit *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysSpecialPosiLimitIteratorByAll::UpdateCurrent(CWriteableSysSpecialPosiLimit * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysSpecialPosiLimit *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysSpecialPosiLimit;
#endif

CSysSpecialPosiLimit *CSysSpecialPosiLimitIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysSpecialPosiLimit++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysSpecialPosiLimit *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysSpecialPosiLimit *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysSpecialPosiLimitIteratorByAll::match(CSysSpecialPosiLimit *pSysSpecialPosiLimit)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysTransactionChgIteratorByActionTime> CSysTransactionChgIteratorByActionTime::iteratorList;
void CSysTransactionChgIteratorByActionTime::init(CSysTransactionChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysTransactionChgIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ActionTime=ActionTime.getValue();

}

CSysTransactionChgIteratorByActionTime *CSysTransactionChgIteratorByActionTime::alloc(CSysTransactionChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	CSysTransactionChgIteratorByActionTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,ActionTime);
	return it;
}

CSysTransactionChgIteratorByActionTime::~CSysTransactionChgIteratorByActionTime(void)
{
}

void CSysTransactionChgIteratorByActionTime::free(void)
{
	iteratorList.free(this);
}

void CSysTransactionChgIteratorByActionTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysTransactionChgIteratorByActionTime");
	
	char buffer[200];
	
	m_compareObject.ActionTime.getString(buffer);
	pLogger->output(indent+1,0,"query ActionTime=%s",buffer);
	
}

void CSysTransactionChgIteratorByActionTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysActionTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysActionTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysTransactionChgIteratorByActionTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysTransactionChg *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysTransactionChgIteratorByActionTime::UpdateCurrent(CWriteableSysTransactionChg * pByActionTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysTransactionChg *)(m_pCurrent->pObject),pByActionTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByActionTimeForSysTransactionChg;
#endif

CSysTransactionChg *CSysTransactionChgIteratorByActionTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysTransactionChg++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysTransactionChg *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysTransactionChg *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysTransactionChgIteratorByActionTime::match(CSysTransactionChg *pSysTransactionChg)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysClientChgIteratorByActionTime> CSysClientChgIteratorByActionTime::iteratorList;
void CSysClientChgIteratorByActionTime::init(CSysClientChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysClientChgIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ActionTime=ActionTime.getValue();

}

CSysClientChgIteratorByActionTime *CSysClientChgIteratorByActionTime::alloc(CSysClientChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	CSysClientChgIteratorByActionTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,ActionTime);
	return it;
}

CSysClientChgIteratorByActionTime::~CSysClientChgIteratorByActionTime(void)
{
}

void CSysClientChgIteratorByActionTime::free(void)
{
	iteratorList.free(this);
}

void CSysClientChgIteratorByActionTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysClientChgIteratorByActionTime");
	
	char buffer[200];
	
	m_compareObject.ActionTime.getString(buffer);
	pLogger->output(indent+1,0,"query ActionTime=%s",buffer);
	
}

void CSysClientChgIteratorByActionTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysActionTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysActionTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysClientChgIteratorByActionTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysClientChg *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysClientChgIteratorByActionTime::UpdateCurrent(CWriteableSysClientChg * pByActionTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysClientChg *)(m_pCurrent->pObject),pByActionTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByActionTimeForSysClientChg;
#endif

CSysClientChg *CSysClientChgIteratorByActionTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysClientChg++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysClientChg *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysClientChg *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysClientChgIteratorByActionTime::match(CSysClientChg *pSysClientChg)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysPartClientChgIteratorByActionTime> CSysPartClientChgIteratorByActionTime::iteratorList;
void CSysPartClientChgIteratorByActionTime::init(CSysPartClientChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysPartClientChgIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ActionTime=ActionTime.getValue();

}

CSysPartClientChgIteratorByActionTime *CSysPartClientChgIteratorByActionTime::alloc(CSysPartClientChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	CSysPartClientChgIteratorByActionTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,ActionTime);
	return it;
}

CSysPartClientChgIteratorByActionTime::~CSysPartClientChgIteratorByActionTime(void)
{
}

void CSysPartClientChgIteratorByActionTime::free(void)
{
	iteratorList.free(this);
}

void CSysPartClientChgIteratorByActionTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysPartClientChgIteratorByActionTime");
	
	char buffer[200];
	
	m_compareObject.ActionTime.getString(buffer);
	pLogger->output(indent+1,0,"query ActionTime=%s",buffer);
	
}

void CSysPartClientChgIteratorByActionTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysActionTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysActionTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysPartClientChgIteratorByActionTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysPartClientChg *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysPartClientChgIteratorByActionTime::UpdateCurrent(CWriteableSysPartClientChg * pByActionTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysPartClientChg *)(m_pCurrent->pObject),pByActionTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByActionTimeForSysPartClientChg;
#endif

CSysPartClientChg *CSysPartClientChgIteratorByActionTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysPartClientChg++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysPartClientChg *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysPartClientChg *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysPartClientChgIteratorByActionTime::match(CSysPartClientChg *pSysPartClientChg)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysPosiLimitChgIteratorByActionTime> CSysPosiLimitChgIteratorByActionTime::iteratorList;
void CSysPosiLimitChgIteratorByActionTime::init(CSysPosiLimitChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysPosiLimitChgIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ActionTime=ActionTime.getValue();

}

CSysPosiLimitChgIteratorByActionTime *CSysPosiLimitChgIteratorByActionTime::alloc(CSysPosiLimitChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	CSysPosiLimitChgIteratorByActionTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,ActionTime);
	return it;
}

CSysPosiLimitChgIteratorByActionTime::~CSysPosiLimitChgIteratorByActionTime(void)
{
}

void CSysPosiLimitChgIteratorByActionTime::free(void)
{
	iteratorList.free(this);
}

void CSysPosiLimitChgIteratorByActionTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysPosiLimitChgIteratorByActionTime");
	
	char buffer[200];
	
	m_compareObject.ActionTime.getString(buffer);
	pLogger->output(indent+1,0,"query ActionTime=%s",buffer);
	
}

void CSysPosiLimitChgIteratorByActionTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysActionTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysActionTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysPosiLimitChgIteratorByActionTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysPosiLimitChg *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysPosiLimitChgIteratorByActionTime::UpdateCurrent(CWriteableSysPosiLimitChg * pByActionTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysPosiLimitChg *)(m_pCurrent->pObject),pByActionTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByActionTimeForSysPosiLimitChg;
#endif

CSysPosiLimitChg *CSysPosiLimitChgIteratorByActionTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysPosiLimitChg++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysPosiLimitChg *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysPosiLimitChg *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysPosiLimitChgIteratorByActionTime::match(CSysPosiLimitChg *pSysPosiLimitChg)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysClientPosiLimitChgIteratorByActionTime> CSysClientPosiLimitChgIteratorByActionTime::iteratorList;
void CSysClientPosiLimitChgIteratorByActionTime::init(CSysClientPosiLimitChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysClientPosiLimitChgIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ActionTime=ActionTime.getValue();

}

CSysClientPosiLimitChgIteratorByActionTime *CSysClientPosiLimitChgIteratorByActionTime::alloc(CSysClientPosiLimitChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	CSysClientPosiLimitChgIteratorByActionTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,ActionTime);
	return it;
}

CSysClientPosiLimitChgIteratorByActionTime::~CSysClientPosiLimitChgIteratorByActionTime(void)
{
}

void CSysClientPosiLimitChgIteratorByActionTime::free(void)
{
	iteratorList.free(this);
}

void CSysClientPosiLimitChgIteratorByActionTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysClientPosiLimitChgIteratorByActionTime");
	
	char buffer[200];
	
	m_compareObject.ActionTime.getString(buffer);
	pLogger->output(indent+1,0,"query ActionTime=%s",buffer);
	
}

void CSysClientPosiLimitChgIteratorByActionTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysActionTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysActionTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysClientPosiLimitChgIteratorByActionTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysClientPosiLimitChg *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysClientPosiLimitChgIteratorByActionTime::UpdateCurrent(CWriteableSysClientPosiLimitChg * pByActionTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysClientPosiLimitChg *)(m_pCurrent->pObject),pByActionTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByActionTimeForSysClientPosiLimitChg;
#endif

CSysClientPosiLimitChg *CSysClientPosiLimitChgIteratorByActionTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysClientPosiLimitChg++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysClientPosiLimitChg *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysClientPosiLimitChg *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysClientPosiLimitChgIteratorByActionTime::match(CSysClientPosiLimitChg *pSysClientPosiLimitChg)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysSpecPosiLimitChgIteratorByActionTime> CSysSpecPosiLimitChgIteratorByActionTime::iteratorList;
void CSysSpecPosiLimitChgIteratorByActionTime::init(CSysSpecPosiLimitChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysSpecPosiLimitChgIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ActionTime=ActionTime.getValue();

}

CSysSpecPosiLimitChgIteratorByActionTime *CSysSpecPosiLimitChgIteratorByActionTime::alloc(CSysSpecPosiLimitChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	CSysSpecPosiLimitChgIteratorByActionTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,ActionTime);
	return it;
}

CSysSpecPosiLimitChgIteratorByActionTime::~CSysSpecPosiLimitChgIteratorByActionTime(void)
{
}

void CSysSpecPosiLimitChgIteratorByActionTime::free(void)
{
	iteratorList.free(this);
}

void CSysSpecPosiLimitChgIteratorByActionTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysSpecPosiLimitChgIteratorByActionTime");
	
	char buffer[200];
	
	m_compareObject.ActionTime.getString(buffer);
	pLogger->output(indent+1,0,"query ActionTime=%s",buffer);
	
}

void CSysSpecPosiLimitChgIteratorByActionTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysActionTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysActionTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysSpecPosiLimitChgIteratorByActionTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysSpecPosiLimitChg *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysSpecPosiLimitChgIteratorByActionTime::UpdateCurrent(CWriteableSysSpecPosiLimitChg * pByActionTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysSpecPosiLimitChg *)(m_pCurrent->pObject),pByActionTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByActionTimeForSysSpecPosiLimitChg;
#endif

CSysSpecPosiLimitChg *CSysSpecPosiLimitChgIteratorByActionTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysSpecPosiLimitChg++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysSpecPosiLimitChg *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysSpecPosiLimitChg *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysSpecPosiLimitChgIteratorByActionTime::match(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysHedgeDetailChgIteratorByActionTime> CSysHedgeDetailChgIteratorByActionTime::iteratorList;
void CSysHedgeDetailChgIteratorByActionTime::init(CSysHedgeDetailChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysHedgeDetailChgIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ActionTime=ActionTime.getValue();

}

CSysHedgeDetailChgIteratorByActionTime *CSysHedgeDetailChgIteratorByActionTime::alloc(CSysHedgeDetailChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	CSysHedgeDetailChgIteratorByActionTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,ActionTime);
	return it;
}

CSysHedgeDetailChgIteratorByActionTime::~CSysHedgeDetailChgIteratorByActionTime(void)
{
}

void CSysHedgeDetailChgIteratorByActionTime::free(void)
{
	iteratorList.free(this);
}

void CSysHedgeDetailChgIteratorByActionTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysHedgeDetailChgIteratorByActionTime");
	
	char buffer[200];
	
	m_compareObject.ActionTime.getString(buffer);
	pLogger->output(indent+1,0,"query ActionTime=%s",buffer);
	
}

void CSysHedgeDetailChgIteratorByActionTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysActionTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysActionTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysHedgeDetailChgIteratorByActionTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysHedgeDetailChg *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysHedgeDetailChgIteratorByActionTime::UpdateCurrent(CWriteableSysHedgeDetailChg * pByActionTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysHedgeDetailChg *)(m_pCurrent->pObject),pByActionTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByActionTimeForSysHedgeDetailChg;
#endif

CSysHedgeDetailChg *CSysHedgeDetailChgIteratorByActionTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysHedgeDetailChg++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysHedgeDetailChg *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysHedgeDetailChg *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysHedgeDetailChgIteratorByActionTime::match(CSysHedgeDetailChg *pSysHedgeDetailChg)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysParticipantChgIteratorByActionTime> CSysParticipantChgIteratorByActionTime::iteratorList;
void CSysParticipantChgIteratorByActionTime::init(CSysParticipantChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysParticipantChgIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ActionTime=ActionTime.getValue();

}

CSysParticipantChgIteratorByActionTime *CSysParticipantChgIteratorByActionTime::alloc(CSysParticipantChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	CSysParticipantChgIteratorByActionTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,ActionTime);
	return it;
}

CSysParticipantChgIteratorByActionTime::~CSysParticipantChgIteratorByActionTime(void)
{
}

void CSysParticipantChgIteratorByActionTime::free(void)
{
	iteratorList.free(this);
}

void CSysParticipantChgIteratorByActionTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysParticipantChgIteratorByActionTime");
	
	char buffer[200];
	
	m_compareObject.ActionTime.getString(buffer);
	pLogger->output(indent+1,0,"query ActionTime=%s",buffer);
	
}

void CSysParticipantChgIteratorByActionTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysActionTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysActionTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysParticipantChgIteratorByActionTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysParticipantChg *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysParticipantChgIteratorByActionTime::UpdateCurrent(CWriteableSysParticipantChg * pByActionTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysParticipantChg *)(m_pCurrent->pObject),pByActionTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByActionTimeForSysParticipantChg;
#endif

CSysParticipantChg *CSysParticipantChgIteratorByActionTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysParticipantChg++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysParticipantChg *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysParticipantChg *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysParticipantChgIteratorByActionTime::match(CSysParticipantChg *pSysParticipantChg)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysMarginRateChgIteratorByActionTime> CSysMarginRateChgIteratorByActionTime::iteratorList;
void CSysMarginRateChgIteratorByActionTime::init(CSysMarginRateChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMarginRateChgIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ActionTime=ActionTime.getValue();

}

CSysMarginRateChgIteratorByActionTime *CSysMarginRateChgIteratorByActionTime::alloc(CSysMarginRateChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	CSysMarginRateChgIteratorByActionTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,ActionTime);
	return it;
}

CSysMarginRateChgIteratorByActionTime::~CSysMarginRateChgIteratorByActionTime(void)
{
}

void CSysMarginRateChgIteratorByActionTime::free(void)
{
	iteratorList.free(this);
}

void CSysMarginRateChgIteratorByActionTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMarginRateChgIteratorByActionTime");
	
	char buffer[200];
	
	m_compareObject.ActionTime.getString(buffer);
	pLogger->output(indent+1,0,"query ActionTime=%s",buffer);
	
}

void CSysMarginRateChgIteratorByActionTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysActionTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysActionTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMarginRateChgIteratorByActionTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMarginRateChg *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMarginRateChgIteratorByActionTime::UpdateCurrent(CWriteableSysMarginRateChg * pByActionTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMarginRateChg *)(m_pCurrent->pObject),pByActionTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByActionTimeForSysMarginRateChg;
#endif

CSysMarginRateChg *CSysMarginRateChgIteratorByActionTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysMarginRateChg++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMarginRateChg *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMarginRateChg *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMarginRateChgIteratorByActionTime::match(CSysMarginRateChg *pSysMarginRateChg)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysUserIpChgIteratorByActionTime> CSysUserIpChgIteratorByActionTime::iteratorList;
void CSysUserIpChgIteratorByActionTime::init(CSysUserIpChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysUserIpChgIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ActionTime=ActionTime.getValue();

}

CSysUserIpChgIteratorByActionTime *CSysUserIpChgIteratorByActionTime::alloc(CSysUserIpChgFactory *pFactory
		, const CReadOnlyTimeType& ActionTime)
{
	CSysUserIpChgIteratorByActionTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,ActionTime);
	return it;
}

CSysUserIpChgIteratorByActionTime::~CSysUserIpChgIteratorByActionTime(void)
{
}

void CSysUserIpChgIteratorByActionTime::free(void)
{
	iteratorList.free(this);
}

void CSysUserIpChgIteratorByActionTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysUserIpChgIteratorByActionTime");
	
	char buffer[200];
	
	m_compareObject.ActionTime.getString(buffer);
	pLogger->output(indent+1,0,"query ActionTime=%s",buffer);
	
}

void CSysUserIpChgIteratorByActionTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysActionTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysActionTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysUserIpChgIteratorByActionTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysUserIpChg *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysUserIpChgIteratorByActionTime::UpdateCurrent(CWriteableSysUserIpChg * pByActionTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysUserIpChg *)(m_pCurrent->pObject),pByActionTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByActionTimeForSysUserIpChg;
#endif

CSysUserIpChg *CSysUserIpChgIteratorByActionTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysUserIpChg++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysUserIpChg *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysUserIpChg *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysUserIpChgIteratorByActionTime::match(CSysUserIpChg *pSysUserIpChg)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysPartTradeIteratorByAll> CSysPartTradeIteratorByAll::iteratorList;
void CSysPartTradeIteratorByAll::init(CSysPartTradeFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysPartTradeIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID="";
	m_compareObject.InstrumentID="";

}

CSysPartTradeIteratorByAll *CSysPartTradeIteratorByAll::alloc(CSysPartTradeFactory *pFactory
		)
{
	CSysPartTradeIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysPartTradeIteratorByAll::~CSysPartTradeIteratorByAll(void)
{
}

void CSysPartTradeIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysPartTradeIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysPartTradeIteratorByAll");
	
	
}

void CSysPartTradeIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysPartInstrumentIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysPartInstrumentIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysPartTradeIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysPartTrade *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysPartTradeIteratorByAll::UpdateCurrent(CWriteableSysPartTrade * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysPartTrade *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysPartTrade;
#endif

CSysPartTrade *CSysPartTradeIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysPartTrade++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysPartTrade *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysPartTrade *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysPartTradeIteratorByAll::match(CSysPartTrade *pSysPartTrade)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysMdbObjectAttrIteratorByIDType> CSysMdbObjectAttrIteratorByIDType::iteratorList;
void CSysMdbObjectAttrIteratorByIDType::init(CSysMdbObjectAttrFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbObjectAttrIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbObjectAttrIteratorByIDType *CSysMdbObjectAttrIteratorByIDType::alloc(CSysMdbObjectAttrFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbObjectAttrIteratorByIDType *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID,MonDate,MonTime);
	return it;
}

CSysMdbObjectAttrIteratorByIDType::~CSysMdbObjectAttrIteratorByIDType(void)
{
}

void CSysMdbObjectAttrIteratorByIDType::free(void)
{
	iteratorList.free(this);
}

void CSysMdbObjectAttrIteratorByIDType::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbObjectAttrIteratorByIDType");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbObjectAttrIteratorByIDType::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbObjectAttrIteratorByIDType::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbObjectAttr *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbObjectAttrIteratorByIDType::UpdateCurrent(CWriteableSysMdbObjectAttr * pByIDType,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbObjectAttr *)(m_pCurrent->pObject),pByIDType,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByIDTypeForSysMdbObjectAttr;
#endif

CSysMdbObjectAttr *CSysMdbObjectAttrIteratorByIDType::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbObjectAttr++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbObjectAttr *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbObjectAttr *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbObjectAttrIteratorByIDType::match(CSysMdbObjectAttr *pSysMdbObjectAttr)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbObjectAttr->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbObjectAttrIteratorByDsc> CSysMdbObjectAttrIteratorByDsc::iteratorList;
void CSysMdbObjectAttrIteratorByDsc::init(CSysMdbObjectAttrFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbObjectAttrIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysMdbObjectAttrIteratorByDsc *CSysMdbObjectAttrIteratorByDsc::alloc(CSysMdbObjectAttrFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID)
{
	CSysMdbObjectAttrIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID);
	return it;
}

CSysMdbObjectAttrIteratorByDsc::~CSysMdbObjectAttrIteratorByDsc(void)
{
}

void CSysMdbObjectAttrIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysMdbObjectAttrIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbObjectAttrIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
}

void CSysMdbObjectAttrIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbObjectAttrIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbObjectAttr *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbObjectAttrIteratorByDsc::UpdateCurrent(CWriteableSysMdbObjectAttr * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbObjectAttr *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysMdbObjectAttr;
#endif

CSysMdbObjectAttr *CSysMdbObjectAttrIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbObjectAttr++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbObjectAttr *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbObjectAttr *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbObjectAttrIteratorByDsc::match(CSysMdbObjectAttr *pSysMdbObjectAttr)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbObjectAttr->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbObjectAttrIteratorBytheAll> CSysMdbObjectAttrIteratorBytheAll::iteratorList;
void CSysMdbObjectAttrIteratorBytheAll::init(CSysMdbObjectAttrFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbObjectAttrIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID="";

}

CSysMdbObjectAttrIteratorBytheAll *CSysMdbObjectAttrIteratorBytheAll::alloc(CSysMdbObjectAttrFactory *pFactory
		)
{
	CSysMdbObjectAttrIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMdbObjectAttrIteratorBytheAll::~CSysMdbObjectAttrIteratorBytheAll(void)
{
}

void CSysMdbObjectAttrIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbObjectAttrIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbObjectAttrIteratorBytheAll");
	
	
}

void CSysMdbObjectAttrIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbObjectAttrIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbObjectAttr *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbObjectAttrIteratorBytheAll::UpdateCurrent(CWriteableSysMdbObjectAttr * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbObjectAttr *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysMdbObjectAttr;
#endif

CSysMdbObjectAttr *CSysMdbObjectAttrIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbObjectAttr++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbObjectAttr *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbObjectAttr *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbObjectAttrIteratorBytheAll::match(CSysMdbObjectAttr *pSysMdbObjectAttr)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysMdbObjectAttrIteratorByDataDelete> CSysMdbObjectAttrIteratorByDataDelete::iteratorList;
void CSysMdbObjectAttrIteratorByDataDelete::init(CSysMdbObjectAttrFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbObjectAttrIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbObjectAttrIteratorByDataDelete *CSysMdbObjectAttrIteratorByDataDelete::alloc(CSysMdbObjectAttrFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbObjectAttrIteratorByDataDelete *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID,MonDate,MonTime);
	return it;
}

CSysMdbObjectAttrIteratorByDataDelete::~CSysMdbObjectAttrIteratorByDataDelete(void)
{
}

void CSysMdbObjectAttrIteratorByDataDelete::free(void)
{
	iteratorList.free(this);
}

void CSysMdbObjectAttrIteratorByDataDelete::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbObjectAttrIteratorByDataDelete");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbObjectAttrIteratorByDataDelete::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbObjectAttrIteratorByDataDelete::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbObjectAttr *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbObjectAttrIteratorByDataDelete::UpdateCurrent(CWriteableSysMdbObjectAttr * pByDataDelete,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbObjectAttr *)(m_pCurrent->pObject),pByDataDelete,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDataDeleteForSysMdbObjectAttr;
#endif

CSysMdbObjectAttr *CSysMdbObjectAttrIteratorByDataDelete::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbObjectAttr++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbObjectAttr *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbObjectAttr *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbObjectAttrIteratorByDataDelete::match(CSysMdbObjectAttr *pSysMdbObjectAttr)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbObjectAttr->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysMdbSyslogInfoIteratorByAll> CSysMdbSyslogInfoIteratorByAll::iteratorList;
void CSysMdbSyslogInfoIteratorByAll::init(CSysMdbSyslogInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID, const CReadOnlyVolumeType& AttrType)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbSyslogInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.AttrType=AttrType.getValue();

}

CSysMdbSyslogInfoIteratorByAll *CSysMdbSyslogInfoIteratorByAll::alloc(CSysMdbSyslogInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID, const CReadOnlyVolumeType& AttrType)
{
	CSysMdbSyslogInfoIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID,AttrType);
	return it;
}

CSysMdbSyslogInfoIteratorByAll::~CSysMdbSyslogInfoIteratorByAll(void)
{
}

void CSysMdbSyslogInfoIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbSyslogInfoIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbSyslogInfoIteratorByAll");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
	m_compareObject.AttrType.getString(buffer);
	pLogger->output(indent+1,0,"query AttrType=%s",buffer);
	
}

void CSysMdbSyslogInfoIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbSyslogInfoIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbSyslogInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbSyslogInfoIteratorByAll::UpdateCurrent(CWriteableSysMdbSyslogInfo * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbSyslogInfo *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysMdbSyslogInfo;
#endif

CSysMdbSyslogInfo *CSysMdbSyslogInfoIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysMdbSyslogInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbSyslogInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbSyslogInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbSyslogInfoIteratorByAll::match(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbSyslogInfo->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	if (compare(pSysMdbSyslogInfo->AttrType.getValue(),m_compareObject.AttrType.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbSyslogInfoIteratorBytheAll> CSysMdbSyslogInfoIteratorBytheAll::iteratorList;
void CSysMdbSyslogInfoIteratorBytheAll::init(CSysMdbSyslogInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbSyslogInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID="";

}

CSysMdbSyslogInfoIteratorBytheAll *CSysMdbSyslogInfoIteratorBytheAll::alloc(CSysMdbSyslogInfoFactory *pFactory
		)
{
	CSysMdbSyslogInfoIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMdbSyslogInfoIteratorBytheAll::~CSysMdbSyslogInfoIteratorBytheAll(void)
{
}

void CSysMdbSyslogInfoIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbSyslogInfoIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbSyslogInfoIteratorBytheAll");
	
	
}

void CSysMdbSyslogInfoIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbSyslogInfoIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbSyslogInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbSyslogInfoIteratorBytheAll::UpdateCurrent(CWriteableSysMdbSyslogInfo * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbSyslogInfo *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysMdbSyslogInfo;
#endif

CSysMdbSyslogInfo *CSysMdbSyslogInfoIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbSyslogInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbSyslogInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbSyslogInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbSyslogInfoIteratorBytheAll::match(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysMdbSyslogInfoIteratorByDataDelete> CSysMdbSyslogInfoIteratorByDataDelete::iteratorList;
void CSysMdbSyslogInfoIteratorByDataDelete::init(CSysMdbSyslogInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID, const CReadOnlyVolumeType& AttrType, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbSyslogInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.AttrType=AttrType.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbSyslogInfoIteratorByDataDelete *CSysMdbSyslogInfoIteratorByDataDelete::alloc(CSysMdbSyslogInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID, const CReadOnlyVolumeType& AttrType, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbSyslogInfoIteratorByDataDelete *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID,AttrType,MonDate,MonTime);
	return it;
}

CSysMdbSyslogInfoIteratorByDataDelete::~CSysMdbSyslogInfoIteratorByDataDelete(void)
{
}

void CSysMdbSyslogInfoIteratorByDataDelete::free(void)
{
	iteratorList.free(this);
}

void CSysMdbSyslogInfoIteratorByDataDelete::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbSyslogInfoIteratorByDataDelete");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
	m_compareObject.AttrType.getString(buffer);
	pLogger->output(indent+1,0,"query AttrType=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbSyslogInfoIteratorByDataDelete::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbSyslogInfoIteratorByDataDelete::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbSyslogInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbSyslogInfoIteratorByDataDelete::UpdateCurrent(CWriteableSysMdbSyslogInfo * pByDataDelete,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbSyslogInfo *)(m_pCurrent->pObject),pByDataDelete,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDataDeleteForSysMdbSyslogInfo;
#endif

CSysMdbSyslogInfo *CSysMdbSyslogInfoIteratorByDataDelete::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbSyslogInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbSyslogInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbSyslogInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbSyslogInfoIteratorByDataDelete::match(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbSyslogInfo->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	if (compare(pSysMdbSyslogInfo->AttrType.getValue(),m_compareObject.AttrType.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysUserInfoIteratorByHostName> CSysUserInfoIteratorByHostName::iteratorList;
void CSysUserInfoIteratorByHostName::init(CSysUserInfoFactory *pFactory
		, const CReadOnlyTypeObjectIDType& ObjectID, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysUserInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysUserInfoIteratorByHostName *CSysUserInfoIteratorByHostName::alloc(CSysUserInfoFactory *pFactory
		, const CReadOnlyTypeObjectIDType& ObjectID, const CReadOnlyTimeType& MonTime)
{
	CSysUserInfoIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID,MonTime);
	return it;
}

CSysUserInfoIteratorByHostName::~CSysUserInfoIteratorByHostName(void)
{
}

void CSysUserInfoIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CSysUserInfoIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysUserInfoIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysUserInfoIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysUserInfoIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysUserInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysUserInfoIteratorByHostName::UpdateCurrent(CWriteableSysUserInfo * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysUserInfo *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForSysUserInfo;
#endif

CSysUserInfo *CSysUserInfoIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForSysUserInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysUserInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysUserInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysUserInfoIteratorByHostName::match(CSysUserInfo *pSysUserInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysUserInfo->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysUserInfoIteratorBytheAll> CSysUserInfoIteratorBytheAll::iteratorList;
void CSysUserInfoIteratorBytheAll::init(CSysUserInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysUserInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID="";

}

CSysUserInfoIteratorBytheAll *CSysUserInfoIteratorBytheAll::alloc(CSysUserInfoFactory *pFactory
		)
{
	CSysUserInfoIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysUserInfoIteratorBytheAll::~CSysUserInfoIteratorBytheAll(void)
{
}

void CSysUserInfoIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysUserInfoIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysUserInfoIteratorBytheAll");
	
	
}

void CSysUserInfoIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysUserInfoIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysUserInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysUserInfoIteratorBytheAll::UpdateCurrent(CWriteableSysUserInfo * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysUserInfo *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysUserInfo;
#endif

CSysUserInfo *CSysUserInfoIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysUserInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysUserInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysUserInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysUserInfoIteratorBytheAll::match(CSysUserInfo *pSysUserInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysUserInfoIteratorByDsc> CSysUserInfoIteratorByDsc::iteratorList;
void CSysUserInfoIteratorByDsc::init(CSysUserInfoFactory *pFactory
		, const CReadOnlyTypeObjectIDType& ObjectID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysUserInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysUserInfoIteratorByDsc *CSysUserInfoIteratorByDsc::alloc(CSysUserInfoFactory *pFactory
		, const CReadOnlyTypeObjectIDType& ObjectID)
{
	CSysUserInfoIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID);
	return it;
}

CSysUserInfoIteratorByDsc::~CSysUserInfoIteratorByDsc(void)
{
}

void CSysUserInfoIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysUserInfoIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysUserInfoIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
}

void CSysUserInfoIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysUserInfoIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysUserInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysUserInfoIteratorByDsc::UpdateCurrent(CWriteableSysUserInfo * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysUserInfo *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysUserInfo;
#endif

CSysUserInfo *CSysUserInfoIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysUserInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysUserInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysUserInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysUserInfoIteratorByDsc::match(CSysUserInfo *pSysUserInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysUserInfo->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysOnlineUserInfoIteratorByHostName> CSysOnlineUserInfoIteratorByHostName::iteratorList;
void CSysOnlineUserInfoIteratorByHostName::init(CSysOnlineUserInfoFactory *pFactory
		, const CReadOnlyTypeObjectIDType& ObjectID, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysOnlineUserInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysOnlineUserInfoIteratorByHostName *CSysOnlineUserInfoIteratorByHostName::alloc(CSysOnlineUserInfoFactory *pFactory
		, const CReadOnlyTypeObjectIDType& ObjectID, const CReadOnlyTimeType& MonTime)
{
	CSysOnlineUserInfoIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID,MonTime);
	return it;
}

CSysOnlineUserInfoIteratorByHostName::~CSysOnlineUserInfoIteratorByHostName(void)
{
}

void CSysOnlineUserInfoIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CSysOnlineUserInfoIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysOnlineUserInfoIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysOnlineUserInfoIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysOnlineUserInfoIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysOnlineUserInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysOnlineUserInfoIteratorByHostName::UpdateCurrent(CWriteableSysOnlineUserInfo * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysOnlineUserInfo *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForSysOnlineUserInfo;
#endif

CSysOnlineUserInfo *CSysOnlineUserInfoIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForSysOnlineUserInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysOnlineUserInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysOnlineUserInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysOnlineUserInfoIteratorByHostName::match(CSysOnlineUserInfo *pSysOnlineUserInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysOnlineUserInfo->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysOnlineUserInfoIteratorBytheAll> CSysOnlineUserInfoIteratorBytheAll::iteratorList;
void CSysOnlineUserInfoIteratorBytheAll::init(CSysOnlineUserInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysOnlineUserInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID="";

}

CSysOnlineUserInfoIteratorBytheAll *CSysOnlineUserInfoIteratorBytheAll::alloc(CSysOnlineUserInfoFactory *pFactory
		)
{
	CSysOnlineUserInfoIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysOnlineUserInfoIteratorBytheAll::~CSysOnlineUserInfoIteratorBytheAll(void)
{
}

void CSysOnlineUserInfoIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysOnlineUserInfoIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysOnlineUserInfoIteratorBytheAll");
	
	
}

void CSysOnlineUserInfoIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysOnlineUserInfoIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysOnlineUserInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysOnlineUserInfoIteratorBytheAll::UpdateCurrent(CWriteableSysOnlineUserInfo * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysOnlineUserInfo *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysOnlineUserInfo;
#endif

CSysOnlineUserInfo *CSysOnlineUserInfoIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysOnlineUserInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysOnlineUserInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysOnlineUserInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysOnlineUserInfoIteratorBytheAll::match(CSysOnlineUserInfo *pSysOnlineUserInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysOnlineUserInfoIteratorByDsc> CSysOnlineUserInfoIteratorByDsc::iteratorList;
void CSysOnlineUserInfoIteratorByDsc::init(CSysOnlineUserInfoFactory *pFactory
		, const CReadOnlyTypeObjectIDType& ObjectID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysOnlineUserInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysOnlineUserInfoIteratorByDsc *CSysOnlineUserInfoIteratorByDsc::alloc(CSysOnlineUserInfoFactory *pFactory
		, const CReadOnlyTypeObjectIDType& ObjectID)
{
	CSysOnlineUserInfoIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID);
	return it;
}

CSysOnlineUserInfoIteratorByDsc::~CSysOnlineUserInfoIteratorByDsc(void)
{
}

void CSysOnlineUserInfoIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysOnlineUserInfoIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysOnlineUserInfoIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
}

void CSysOnlineUserInfoIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysOnlineUserInfoIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysOnlineUserInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysOnlineUserInfoIteratorByDsc::UpdateCurrent(CWriteableSysOnlineUserInfo * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysOnlineUserInfo *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysOnlineUserInfo;
#endif

CSysOnlineUserInfo *CSysOnlineUserInfoIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysOnlineUserInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysOnlineUserInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysOnlineUserInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysOnlineUserInfoIteratorByDsc::match(CSysOnlineUserInfo *pSysOnlineUserInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysOnlineUserInfo->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysWarningEventIteratorByTime> CSysWarningEventIteratorByTime::iteratorList;
void CSysWarningEventIteratorByTime::init(CSysWarningEventFactory *pFactory
		, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& OccurTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysWarningEventIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.OccurTime=OccurTime.getValue();

}

CSysWarningEventIteratorByTime *CSysWarningEventIteratorByTime::alloc(CSysWarningEventFactory *pFactory
		, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& OccurTime)
{
	CSysWarningEventIteratorByTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,MonDate,OccurTime);
	return it;
}

CSysWarningEventIteratorByTime::~CSysWarningEventIteratorByTime(void)
{
}

void CSysWarningEventIteratorByTime::free(void)
{
	iteratorList.free(this);
}

void CSysWarningEventIteratorByTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysWarningEventIteratorByTime");
	
	char buffer[200];
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.OccurTime.getString(buffer);
	pLogger->output(indent+1,0,"query OccurTime=%s",buffer);
	
}

void CSysWarningEventIteratorByTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysWarningEventIteratorByTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysWarningEvent *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysWarningEventIteratorByTime::UpdateCurrent(CWriteableSysWarningEvent * pByTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysWarningEvent *)(m_pCurrent->pObject),pByTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByTimeForSysWarningEvent;
#endif

CSysWarningEvent *CSysWarningEventIteratorByTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByTimeForSysWarningEvent++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysWarningEvent *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysWarningEvent *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysWarningEventIteratorByTime::match(CSysWarningEvent *pSysWarningEvent)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysWarningEventIteratorByAll> CSysWarningEventIteratorByAll::iteratorList;
void CSysWarningEventIteratorByAll::init(CSysWarningEventFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysWarningEventIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.OccurTime="zzzzzzzz";

}

CSysWarningEventIteratorByAll *CSysWarningEventIteratorByAll::alloc(CSysWarningEventFactory *pFactory
		)
{
	CSysWarningEventIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysWarningEventIteratorByAll::~CSysWarningEventIteratorByAll(void)
{
}

void CSysWarningEventIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysWarningEventIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysWarningEventIteratorByAll");
	
	
}

void CSysWarningEventIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysWarningEventIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysWarningEvent *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysWarningEventIteratorByAll::UpdateCurrent(CWriteableSysWarningEvent * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysWarningEvent *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysWarningEvent;
#endif

CSysWarningEvent *CSysWarningEventIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysWarningEvent++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysWarningEvent *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysWarningEvent *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysWarningEventIteratorByAll::match(CSysWarningEvent *pSysWarningEvent)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysWarningEventIteratorByEvendIDs> CSysWarningEventIteratorByEvendIDs::iteratorList;
void CSysWarningEventIteratorByEvendIDs::init(CSysWarningEventFactory *pFactory
		, const CReadOnlyVolumeType& EvendID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysWarningEventIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.EvendID=EvendID.getValue();

}

CSysWarningEventIteratorByEvendIDs *CSysWarningEventIteratorByEvendIDs::alloc(CSysWarningEventFactory *pFactory
		, const CReadOnlyVolumeType& EvendID)
{
	CSysWarningEventIteratorByEvendIDs *it;
	it=iteratorList.alloc();
	it->init(pFactory,EvendID);
	return it;
}

CSysWarningEventIteratorByEvendIDs::~CSysWarningEventIteratorByEvendIDs(void)
{
}

void CSysWarningEventIteratorByEvendIDs::free(void)
{
	iteratorList.free(this);
}

void CSysWarningEventIteratorByEvendIDs::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysWarningEventIteratorByEvendIDs");
	
	char buffer[200];
	
	m_compareObject.EvendID.getString(buffer);
	pLogger->output(indent+1,0,"query EvendID=%s",buffer);
	
}

void CSysWarningEventIteratorByEvendIDs::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysEventIdIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysEventIdIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysWarningEventIteratorByEvendIDs::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysWarningEvent *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysWarningEventIteratorByEvendIDs::UpdateCurrent(CWriteableSysWarningEvent * pByEvendIDs,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysWarningEvent *)(m_pCurrent->pObject),pByEvendIDs,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByEvendIDsForSysWarningEvent;
#endif

CSysWarningEvent *CSysWarningEventIteratorByEvendIDs::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByEvendIDsForSysWarningEvent++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysWarningEvent *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysWarningEvent *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysWarningEventIteratorByEvendIDs::match(CSysWarningEvent *pSysWarningEvent)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysWarningEvent->EvendID.getValue(),m_compareObject.EvendID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysWarningEventIteratorBytheAll> CSysWarningEventIteratorBytheAll::iteratorList;
void CSysWarningEventIteratorBytheAll::init(CSysWarningEventFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysWarningEventIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.EvendID=0;

}

CSysWarningEventIteratorBytheAll *CSysWarningEventIteratorBytheAll::alloc(CSysWarningEventFactory *pFactory
		)
{
	CSysWarningEventIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysWarningEventIteratorBytheAll::~CSysWarningEventIteratorBytheAll(void)
{
}

void CSysWarningEventIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysWarningEventIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysWarningEventIteratorBytheAll");
	
	
}

void CSysWarningEventIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysEventIdIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysEventIdIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysWarningEventIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysWarningEvent *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysWarningEventIteratorBytheAll::UpdateCurrent(CWriteableSysWarningEvent * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysWarningEvent *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysWarningEvent;
#endif

CSysWarningEvent *CSysWarningEventIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysWarningEvent++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysWarningEvent *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysWarningEvent *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysWarningEventIteratorBytheAll::match(CSysWarningEvent *pSysWarningEvent)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysWarningQueryIteratorByTime> CSysWarningQueryIteratorByTime::iteratorList;
void CSysWarningQueryIteratorByTime::init(CSysWarningQueryFactory *pFactory
		, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysWarningQueryIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysWarningQueryIteratorByTime *CSysWarningQueryIteratorByTime::alloc(CSysWarningQueryFactory *pFactory
		, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysWarningQueryIteratorByTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,MonDate,MonTime);
	return it;
}

CSysWarningQueryIteratorByTime::~CSysWarningQueryIteratorByTime(void)
{
}

void CSysWarningQueryIteratorByTime::free(void)
{
	iteratorList.free(this);
}

void CSysWarningQueryIteratorByTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysWarningQueryIteratorByTime");
	
	char buffer[200];
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysWarningQueryIteratorByTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysWarningQueryIteratorByTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysWarningQuery *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysWarningQueryIteratorByTime::UpdateCurrent(CWriteableSysWarningQuery * pByTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysWarningQuery *)(m_pCurrent->pObject),pByTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByTimeForSysWarningQuery;
#endif

CSysWarningQuery *CSysWarningQueryIteratorByTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByTimeForSysWarningQuery++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysWarningQuery *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysWarningQuery *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysWarningQueryIteratorByTime::match(CSysWarningQuery *pSysWarningQuery)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSyslogEventIteratorByTime> CSyslogEventIteratorByTime::iteratorList;
void CSyslogEventIteratorByTime::init(CSyslogEventFactory *pFactory
		, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& OccurTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSyslogEventIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.OccurTime=OccurTime.getValue();

}

CSyslogEventIteratorByTime *CSyslogEventIteratorByTime::alloc(CSyslogEventFactory *pFactory
		, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& OccurTime)
{
	CSyslogEventIteratorByTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,MonDate,OccurTime);
	return it;
}

CSyslogEventIteratorByTime::~CSyslogEventIteratorByTime(void)
{
}

void CSyslogEventIteratorByTime::free(void)
{
	iteratorList.free(this);
}

void CSyslogEventIteratorByTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSyslogEventIteratorByTime");
	
	char buffer[200];
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.OccurTime.getString(buffer);
	pLogger->output(indent+1,0,"query OccurTime=%s",buffer);
	
}

void CSyslogEventIteratorByTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSyslogEventIteratorByTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSyslogEvent *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSyslogEventIteratorByTime::UpdateCurrent(CWriteableSyslogEvent * pByTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSyslogEvent *)(m_pCurrent->pObject),pByTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByTimeForSyslogEvent;
#endif

CSyslogEvent *CSyslogEventIteratorByTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByTimeForSyslogEvent++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSyslogEvent *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSyslogEvent *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSyslogEventIteratorByTime::match(CSyslogEvent *pSyslogEvent)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSyslogEventIteratorBytheAll> CSyslogEventIteratorBytheAll::iteratorList;
void CSyslogEventIteratorBytheAll::init(CSyslogEventFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSyslogEventIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.OccurTime="zzzzzzzz";

}

CSyslogEventIteratorBytheAll *CSyslogEventIteratorBytheAll::alloc(CSyslogEventFactory *pFactory
		)
{
	CSyslogEventIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSyslogEventIteratorBytheAll::~CSyslogEventIteratorBytheAll(void)
{
}

void CSyslogEventIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSyslogEventIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSyslogEventIteratorBytheAll");
	
	
}

void CSyslogEventIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSyslogEventIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSyslogEvent *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSyslogEventIteratorBytheAll::UpdateCurrent(CWriteableSyslogEvent * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSyslogEvent *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSyslogEvent;
#endif

CSyslogEvent *CSyslogEventIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSyslogEvent++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSyslogEvent *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSyslogEvent *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSyslogEventIteratorBytheAll::match(CSyslogEvent *pSyslogEvent)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSyslogEventIteratorByAll> CSyslogEventIteratorByAll::iteratorList;
void CSyslogEventIteratorByAll::init(CSyslogEventFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSyslogEventIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.OccurTime="zzzzzzzz";

}

CSyslogEventIteratorByAll *CSyslogEventIteratorByAll::alloc(CSyslogEventFactory *pFactory
		)
{
	CSyslogEventIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSyslogEventIteratorByAll::~CSyslogEventIteratorByAll(void)
{
}

void CSyslogEventIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSyslogEventIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSyslogEventIteratorByAll");
	
	
}

void CSyslogEventIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSyslogEventIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSyslogEvent *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSyslogEventIteratorByAll::UpdateCurrent(CWriteableSyslogEvent * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSyslogEvent *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSyslogEvent;
#endif

CSyslogEvent *CSyslogEventIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSyslogEvent++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSyslogEvent *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSyslogEvent *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSyslogEventIteratorByAll::match(CSyslogEvent *pSyslogEvent)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysEventDescripIteratorByTime> CSysEventDescripIteratorByTime::iteratorList;
void CSysEventDescripIteratorByTime::init(CSysEventDescripFactory *pFactory
		, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysEventDescripIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysEventDescripIteratorByTime *CSysEventDescripIteratorByTime::alloc(CSysEventDescripFactory *pFactory
		, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysEventDescripIteratorByTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,MonDate,MonTime);
	return it;
}

CSysEventDescripIteratorByTime::~CSysEventDescripIteratorByTime(void)
{
}

void CSysEventDescripIteratorByTime::free(void)
{
	iteratorList.free(this);
}

void CSysEventDescripIteratorByTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysEventDescripIteratorByTime");
	
	char buffer[200];
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysEventDescripIteratorByTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysEventDescripIteratorByTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysEventDescrip *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysEventDescripIteratorByTime::UpdateCurrent(CWriteableSysEventDescrip * pByTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysEventDescrip *)(m_pCurrent->pObject),pByTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByTimeForSysEventDescrip;
#endif

CSysEventDescrip *CSysEventDescripIteratorByTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByTimeForSysEventDescrip++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysEventDescrip *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysEventDescrip *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysEventDescripIteratorByTime::match(CSysEventDescrip *pSysEventDescrip)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysEventDescripIteratorBytheAll> CSysEventDescripIteratorBytheAll::iteratorList;
void CSysEventDescripIteratorBytheAll::init(CSysEventDescripFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysEventDescripIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysEventDescripIteratorBytheAll *CSysEventDescripIteratorBytheAll::alloc(CSysEventDescripFactory *pFactory
		)
{
	CSysEventDescripIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysEventDescripIteratorBytheAll::~CSysEventDescripIteratorBytheAll(void)
{
}

void CSysEventDescripIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysEventDescripIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysEventDescripIteratorBytheAll");
	
	
}

void CSysEventDescripIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysEventDescripIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysEventDescrip *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysEventDescripIteratorBytheAll::UpdateCurrent(CWriteableSysEventDescrip * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysEventDescrip *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysEventDescrip;
#endif

CSysEventDescrip *CSysEventDescripIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysEventDescrip++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysEventDescrip *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysEventDescrip *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysEventDescripIteratorBytheAll::match(CSysEventDescrip *pSysEventDescrip)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysEventDescripIteratorByAll> CSysEventDescripIteratorByAll::iteratorList;
void CSysEventDescripIteratorByAll::init(CSysEventDescripFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysEventDescripIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysEventDescripIteratorByAll *CSysEventDescripIteratorByAll::alloc(CSysEventDescripFactory *pFactory
		)
{
	CSysEventDescripIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysEventDescripIteratorByAll::~CSysEventDescripIteratorByAll(void)
{
}

void CSysEventDescripIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysEventDescripIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysEventDescripIteratorByAll");
	
	
}

void CSysEventDescripIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysEventDescripIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysEventDescrip *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysEventDescripIteratorByAll::UpdateCurrent(CWriteableSysEventDescrip * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysEventDescrip *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysEventDescrip;
#endif

CSysEventDescrip *CSysEventDescripIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysEventDescrip++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysEventDescrip *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysEventDescrip *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysEventDescripIteratorByAll::match(CSysEventDescrip *pSysEventDescrip)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CRspQryHostEnvCommonIteratorByHostName> CRspQryHostEnvCommonIteratorByHostName::iteratorList;
void CRspQryHostEnvCommonIteratorByHostName::init(CRspQryHostEnvCommonFactory *pFactory
		, const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CRspQryHostEnvCommonIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonTime="zzzzzzzz";

}

CRspQryHostEnvCommonIteratorByHostName *CRspQryHostEnvCommonIteratorByHostName::alloc(CRspQryHostEnvCommonFactory *pFactory
		, const CReadOnlyTypeObjectIDType& HostName)
{
	CRspQryHostEnvCommonIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName);
	return it;
}

CRspQryHostEnvCommonIteratorByHostName::~CRspQryHostEnvCommonIteratorByHostName(void)
{
}

void CRspQryHostEnvCommonIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CRspQryHostEnvCommonIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CRspQryHostEnvCommonIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
}

void CRspQryHostEnvCommonIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CRspQryHostEnvCommonIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CRspQryHostEnvCommon *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CRspQryHostEnvCommonIteratorByHostName::UpdateCurrent(CWriteableRspQryHostEnvCommon * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CRspQryHostEnvCommon *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForRspQryHostEnvCommon;
#endif

CRspQryHostEnvCommon *CRspQryHostEnvCommonIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvCommon++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CRspQryHostEnvCommon *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CRspQryHostEnvCommon *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CRspQryHostEnvCommonIteratorByHostName::match(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pRspQryHostEnvCommon->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CRspQryHostEnvCommonIteratorBytheAll> CRspQryHostEnvCommonIteratorBytheAll::iteratorList;
void CRspQryHostEnvCommonIteratorBytheAll::init(CRspQryHostEnvCommonFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CRspQryHostEnvCommonIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName="";

}

CRspQryHostEnvCommonIteratorBytheAll *CRspQryHostEnvCommonIteratorBytheAll::alloc(CRspQryHostEnvCommonFactory *pFactory
		)
{
	CRspQryHostEnvCommonIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CRspQryHostEnvCommonIteratorBytheAll::~CRspQryHostEnvCommonIteratorBytheAll(void)
{
}

void CRspQryHostEnvCommonIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CRspQryHostEnvCommonIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CRspQryHostEnvCommonIteratorBytheAll");
	
	
}

void CRspQryHostEnvCommonIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CRspQryHostEnvCommonIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CRspQryHostEnvCommon *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CRspQryHostEnvCommonIteratorBytheAll::UpdateCurrent(CWriteableRspQryHostEnvCommon * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CRspQryHostEnvCommon *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForRspQryHostEnvCommon;
#endif

CRspQryHostEnvCommon *CRspQryHostEnvCommonIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvCommon++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CRspQryHostEnvCommon *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CRspQryHostEnvCommon *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CRspQryHostEnvCommonIteratorBytheAll::match(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CRspQryHostEnvLanIteratorByHostName> CRspQryHostEnvLanIteratorByHostName::iteratorList;
void CRspQryHostEnvLanIteratorByHostName::init(CRspQryHostEnvLanFactory *pFactory
		, const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CRspQryHostEnvLanIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonTime="zzzzzzzz";

}

CRspQryHostEnvLanIteratorByHostName *CRspQryHostEnvLanIteratorByHostName::alloc(CRspQryHostEnvLanFactory *pFactory
		, const CReadOnlyTypeObjectIDType& HostName)
{
	CRspQryHostEnvLanIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName);
	return it;
}

CRspQryHostEnvLanIteratorByHostName::~CRspQryHostEnvLanIteratorByHostName(void)
{
}

void CRspQryHostEnvLanIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CRspQryHostEnvLanIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CRspQryHostEnvLanIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
}

void CRspQryHostEnvLanIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CRspQryHostEnvLanIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CRspQryHostEnvLan *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CRspQryHostEnvLanIteratorByHostName::UpdateCurrent(CWriteableRspQryHostEnvLan * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CRspQryHostEnvLan *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForRspQryHostEnvLan;
#endif

CRspQryHostEnvLan *CRspQryHostEnvLanIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvLan++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CRspQryHostEnvLan *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CRspQryHostEnvLan *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CRspQryHostEnvLanIteratorByHostName::match(CRspQryHostEnvLan *pRspQryHostEnvLan)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pRspQryHostEnvLan->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CRspQryHostEnvLanIteratorBytheAll> CRspQryHostEnvLanIteratorBytheAll::iteratorList;
void CRspQryHostEnvLanIteratorBytheAll::init(CRspQryHostEnvLanFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CRspQryHostEnvLanIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName="";

}

CRspQryHostEnvLanIteratorBytheAll *CRspQryHostEnvLanIteratorBytheAll::alloc(CRspQryHostEnvLanFactory *pFactory
		)
{
	CRspQryHostEnvLanIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CRspQryHostEnvLanIteratorBytheAll::~CRspQryHostEnvLanIteratorBytheAll(void)
{
}

void CRspQryHostEnvLanIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CRspQryHostEnvLanIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CRspQryHostEnvLanIteratorBytheAll");
	
	
}

void CRspQryHostEnvLanIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CRspQryHostEnvLanIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CRspQryHostEnvLan *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CRspQryHostEnvLanIteratorBytheAll::UpdateCurrent(CWriteableRspQryHostEnvLan * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CRspQryHostEnvLan *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForRspQryHostEnvLan;
#endif

CRspQryHostEnvLan *CRspQryHostEnvLanIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvLan++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CRspQryHostEnvLan *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CRspQryHostEnvLan *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CRspQryHostEnvLanIteratorBytheAll::match(CRspQryHostEnvLan *pRspQryHostEnvLan)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CRspQryHostEnvStorageIteratorByHostName> CRspQryHostEnvStorageIteratorByHostName::iteratorList;
void CRspQryHostEnvStorageIteratorByHostName::init(CRspQryHostEnvStorageFactory *pFactory
		, const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CRspQryHostEnvStorageIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonTime="zzzzzzzz";

}

CRspQryHostEnvStorageIteratorByHostName *CRspQryHostEnvStorageIteratorByHostName::alloc(CRspQryHostEnvStorageFactory *pFactory
		, const CReadOnlyTypeObjectIDType& HostName)
{
	CRspQryHostEnvStorageIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName);
	return it;
}

CRspQryHostEnvStorageIteratorByHostName::~CRspQryHostEnvStorageIteratorByHostName(void)
{
}

void CRspQryHostEnvStorageIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CRspQryHostEnvStorageIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CRspQryHostEnvStorageIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
}

void CRspQryHostEnvStorageIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CRspQryHostEnvStorageIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CRspQryHostEnvStorage *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CRspQryHostEnvStorageIteratorByHostName::UpdateCurrent(CWriteableRspQryHostEnvStorage * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CRspQryHostEnvStorage *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForRspQryHostEnvStorage;
#endif

CRspQryHostEnvStorage *CRspQryHostEnvStorageIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvStorage++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CRspQryHostEnvStorage *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CRspQryHostEnvStorage *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CRspQryHostEnvStorageIteratorByHostName::match(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pRspQryHostEnvStorage->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CRspQryHostEnvStorageIteratorBytheAll> CRspQryHostEnvStorageIteratorBytheAll::iteratorList;
void CRspQryHostEnvStorageIteratorBytheAll::init(CRspQryHostEnvStorageFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CRspQryHostEnvStorageIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName="";

}

CRspQryHostEnvStorageIteratorBytheAll *CRspQryHostEnvStorageIteratorBytheAll::alloc(CRspQryHostEnvStorageFactory *pFactory
		)
{
	CRspQryHostEnvStorageIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CRspQryHostEnvStorageIteratorBytheAll::~CRspQryHostEnvStorageIteratorBytheAll(void)
{
}

void CRspQryHostEnvStorageIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CRspQryHostEnvStorageIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CRspQryHostEnvStorageIteratorBytheAll");
	
	
}

void CRspQryHostEnvStorageIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CRspQryHostEnvStorageIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CRspQryHostEnvStorage *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CRspQryHostEnvStorageIteratorBytheAll::UpdateCurrent(CWriteableRspQryHostEnvStorage * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CRspQryHostEnvStorage *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForRspQryHostEnvStorage;
#endif

CRspQryHostEnvStorage *CRspQryHostEnvStorageIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvStorage++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CRspQryHostEnvStorage *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CRspQryHostEnvStorage *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CRspQryHostEnvStorageIteratorBytheAll::match(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CRspQryHostEnvIOIteratorByHostName> CRspQryHostEnvIOIteratorByHostName::iteratorList;
void CRspQryHostEnvIOIteratorByHostName::init(CRspQryHostEnvIOFactory *pFactory
		, const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CRspQryHostEnvIOIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonTime="zzzzzzzz";

}

CRspQryHostEnvIOIteratorByHostName *CRspQryHostEnvIOIteratorByHostName::alloc(CRspQryHostEnvIOFactory *pFactory
		, const CReadOnlyTypeObjectIDType& HostName)
{
	CRspQryHostEnvIOIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName);
	return it;
}

CRspQryHostEnvIOIteratorByHostName::~CRspQryHostEnvIOIteratorByHostName(void)
{
}

void CRspQryHostEnvIOIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CRspQryHostEnvIOIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CRspQryHostEnvIOIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
}

void CRspQryHostEnvIOIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CRspQryHostEnvIOIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CRspQryHostEnvIO *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CRspQryHostEnvIOIteratorByHostName::UpdateCurrent(CWriteableRspQryHostEnvIO * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CRspQryHostEnvIO *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForRspQryHostEnvIO;
#endif

CRspQryHostEnvIO *CRspQryHostEnvIOIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvIO++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CRspQryHostEnvIO *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CRspQryHostEnvIO *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CRspQryHostEnvIOIteratorByHostName::match(CRspQryHostEnvIO *pRspQryHostEnvIO)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pRspQryHostEnvIO->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CRspQryHostEnvIOIteratorBytheAll> CRspQryHostEnvIOIteratorBytheAll::iteratorList;
void CRspQryHostEnvIOIteratorBytheAll::init(CRspQryHostEnvIOFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CRspQryHostEnvIOIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName="";

}

CRspQryHostEnvIOIteratorBytheAll *CRspQryHostEnvIOIteratorBytheAll::alloc(CRspQryHostEnvIOFactory *pFactory
		)
{
	CRspQryHostEnvIOIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CRspQryHostEnvIOIteratorBytheAll::~CRspQryHostEnvIOIteratorBytheAll(void)
{
}

void CRspQryHostEnvIOIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CRspQryHostEnvIOIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CRspQryHostEnvIOIteratorBytheAll");
	
	
}

void CRspQryHostEnvIOIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CRspQryHostEnvIOIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CRspQryHostEnvIO *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CRspQryHostEnvIOIteratorBytheAll::UpdateCurrent(CWriteableRspQryHostEnvIO * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CRspQryHostEnvIO *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForRspQryHostEnvIO;
#endif

CRspQryHostEnvIO *CRspQryHostEnvIOIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvIO++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CRspQryHostEnvIO *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CRspQryHostEnvIO *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CRspQryHostEnvIOIteratorBytheAll::match(CRspQryHostEnvIO *pRspQryHostEnvIO)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CRspQryHostEnvFSIteratorByHostName> CRspQryHostEnvFSIteratorByHostName::iteratorList;
void CRspQryHostEnvFSIteratorByHostName::init(CRspQryHostEnvFSFactory *pFactory
		, const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CRspQryHostEnvFSIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonTime="zzzzzzzz";

}

CRspQryHostEnvFSIteratorByHostName *CRspQryHostEnvFSIteratorByHostName::alloc(CRspQryHostEnvFSFactory *pFactory
		, const CReadOnlyTypeObjectIDType& HostName)
{
	CRspQryHostEnvFSIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName);
	return it;
}

CRspQryHostEnvFSIteratorByHostName::~CRspQryHostEnvFSIteratorByHostName(void)
{
}

void CRspQryHostEnvFSIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CRspQryHostEnvFSIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CRspQryHostEnvFSIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
}

void CRspQryHostEnvFSIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CRspQryHostEnvFSIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CRspQryHostEnvFS *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CRspQryHostEnvFSIteratorByHostName::UpdateCurrent(CWriteableRspQryHostEnvFS * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CRspQryHostEnvFS *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForRspQryHostEnvFS;
#endif

CRspQryHostEnvFS *CRspQryHostEnvFSIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvFS++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CRspQryHostEnvFS *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CRspQryHostEnvFS *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CRspQryHostEnvFSIteratorByHostName::match(CRspQryHostEnvFS *pRspQryHostEnvFS)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pRspQryHostEnvFS->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CRspQryHostEnvFSIteratorBytheAll> CRspQryHostEnvFSIteratorBytheAll::iteratorList;
void CRspQryHostEnvFSIteratorBytheAll::init(CRspQryHostEnvFSFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CRspQryHostEnvFSIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName="";

}

CRspQryHostEnvFSIteratorBytheAll *CRspQryHostEnvFSIteratorBytheAll::alloc(CRspQryHostEnvFSFactory *pFactory
		)
{
	CRspQryHostEnvFSIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CRspQryHostEnvFSIteratorBytheAll::~CRspQryHostEnvFSIteratorBytheAll(void)
{
}

void CRspQryHostEnvFSIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CRspQryHostEnvFSIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CRspQryHostEnvFSIteratorBytheAll");
	
	
}

void CRspQryHostEnvFSIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CRspQryHostEnvFSIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CRspQryHostEnvFS *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CRspQryHostEnvFSIteratorBytheAll::UpdateCurrent(CWriteableRspQryHostEnvFS * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CRspQryHostEnvFS *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForRspQryHostEnvFS;
#endif

CRspQryHostEnvFS *CRspQryHostEnvFSIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvFS++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CRspQryHostEnvFS *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CRspQryHostEnvFS *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CRspQryHostEnvFSIteratorBytheAll::match(CRspQryHostEnvFS *pRspQryHostEnvFS)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CRspQryHostEnvSwapIteratorByHostName> CRspQryHostEnvSwapIteratorByHostName::iteratorList;
void CRspQryHostEnvSwapIteratorByHostName::init(CRspQryHostEnvSwapFactory *pFactory
		, const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CRspQryHostEnvSwapIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonTime="zzzzzzzz";

}

CRspQryHostEnvSwapIteratorByHostName *CRspQryHostEnvSwapIteratorByHostName::alloc(CRspQryHostEnvSwapFactory *pFactory
		, const CReadOnlyTypeObjectIDType& HostName)
{
	CRspQryHostEnvSwapIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName);
	return it;
}

CRspQryHostEnvSwapIteratorByHostName::~CRspQryHostEnvSwapIteratorByHostName(void)
{
}

void CRspQryHostEnvSwapIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CRspQryHostEnvSwapIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CRspQryHostEnvSwapIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
}

void CRspQryHostEnvSwapIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CRspQryHostEnvSwapIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CRspQryHostEnvSwap *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CRspQryHostEnvSwapIteratorByHostName::UpdateCurrent(CWriteableRspQryHostEnvSwap * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CRspQryHostEnvSwap *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForRspQryHostEnvSwap;
#endif

CRspQryHostEnvSwap *CRspQryHostEnvSwapIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvSwap++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CRspQryHostEnvSwap *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CRspQryHostEnvSwap *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CRspQryHostEnvSwapIteratorByHostName::match(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pRspQryHostEnvSwap->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CRspQryHostEnvSwapIteratorBytheAll> CRspQryHostEnvSwapIteratorBytheAll::iteratorList;
void CRspQryHostEnvSwapIteratorBytheAll::init(CRspQryHostEnvSwapFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CRspQryHostEnvSwapIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName="";

}

CRspQryHostEnvSwapIteratorBytheAll *CRspQryHostEnvSwapIteratorBytheAll::alloc(CRspQryHostEnvSwapFactory *pFactory
		)
{
	CRspQryHostEnvSwapIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CRspQryHostEnvSwapIteratorBytheAll::~CRspQryHostEnvSwapIteratorBytheAll(void)
{
}

void CRspQryHostEnvSwapIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CRspQryHostEnvSwapIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CRspQryHostEnvSwapIteratorBytheAll");
	
	
}

void CRspQryHostEnvSwapIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CRspQryHostEnvSwapIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CRspQryHostEnvSwap *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CRspQryHostEnvSwapIteratorBytheAll::UpdateCurrent(CWriteableRspQryHostEnvSwap * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CRspQryHostEnvSwap *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForRspQryHostEnvSwap;
#endif

CRspQryHostEnvSwap *CRspQryHostEnvSwapIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvSwap++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CRspQryHostEnvSwap *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CRspQryHostEnvSwap *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CRspQryHostEnvSwapIteratorBytheAll::match(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CRspQryHostEnvLanCfgIteratorByHostName> CRspQryHostEnvLanCfgIteratorByHostName::iteratorList;
void CRspQryHostEnvLanCfgIteratorByHostName::init(CRspQryHostEnvLanCfgFactory *pFactory
		, const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CRspQryHostEnvLanCfgIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonTime="zzzzzzzz";

}

CRspQryHostEnvLanCfgIteratorByHostName *CRspQryHostEnvLanCfgIteratorByHostName::alloc(CRspQryHostEnvLanCfgFactory *pFactory
		, const CReadOnlyTypeObjectIDType& HostName)
{
	CRspQryHostEnvLanCfgIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName);
	return it;
}

CRspQryHostEnvLanCfgIteratorByHostName::~CRspQryHostEnvLanCfgIteratorByHostName(void)
{
}

void CRspQryHostEnvLanCfgIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CRspQryHostEnvLanCfgIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CRspQryHostEnvLanCfgIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
}

void CRspQryHostEnvLanCfgIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CRspQryHostEnvLanCfgIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CRspQryHostEnvLanCfg *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CRspQryHostEnvLanCfgIteratorByHostName::UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CRspQryHostEnvLanCfg *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForRspQryHostEnvLanCfg;
#endif

CRspQryHostEnvLanCfg *CRspQryHostEnvLanCfgIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvLanCfg++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CRspQryHostEnvLanCfg *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CRspQryHostEnvLanCfg *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CRspQryHostEnvLanCfgIteratorByHostName::match(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pRspQryHostEnvLanCfg->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CRspQryHostEnvLanCfgIteratorBytheAll> CRspQryHostEnvLanCfgIteratorBytheAll::iteratorList;
void CRspQryHostEnvLanCfgIteratorBytheAll::init(CRspQryHostEnvLanCfgFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CRspQryHostEnvLanCfgIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName="";

}

CRspQryHostEnvLanCfgIteratorBytheAll *CRspQryHostEnvLanCfgIteratorBytheAll::alloc(CRspQryHostEnvLanCfgFactory *pFactory
		)
{
	CRspQryHostEnvLanCfgIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CRspQryHostEnvLanCfgIteratorBytheAll::~CRspQryHostEnvLanCfgIteratorBytheAll(void)
{
}

void CRspQryHostEnvLanCfgIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CRspQryHostEnvLanCfgIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CRspQryHostEnvLanCfgIteratorBytheAll");
	
	
}

void CRspQryHostEnvLanCfgIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CRspQryHostEnvLanCfgIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CRspQryHostEnvLanCfg *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CRspQryHostEnvLanCfgIteratorBytheAll::UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CRspQryHostEnvLanCfg *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForRspQryHostEnvLanCfg;
#endif

CRspQryHostEnvLanCfg *CRspQryHostEnvLanCfgIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvLanCfg++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CRspQryHostEnvLanCfg *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CRspQryHostEnvLanCfg *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CRspQryHostEnvLanCfgIteratorBytheAll::match(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysMdbTopCpuInfoIteratorByHostName> CSysMdbTopCpuInfoIteratorByHostName::iteratorList;
void CSysMdbTopCpuInfoIteratorByHostName::init(CSysMdbTopCpuInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbTopCpuInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbTopCpuInfoIteratorByHostName *CSysMdbTopCpuInfoIteratorByHostName::alloc(CSysMdbTopCpuInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbTopCpuInfoIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName,MonDate,MonTime);
	return it;
}

CSysMdbTopCpuInfoIteratorByHostName::~CSysMdbTopCpuInfoIteratorByHostName(void)
{
}

void CSysMdbTopCpuInfoIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CSysMdbTopCpuInfoIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbTopCpuInfoIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbTopCpuInfoIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbTopCpuInfoIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbTopCpuInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbTopCpuInfoIteratorByHostName::UpdateCurrent(CWriteableSysMdbTopCpuInfo * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbTopCpuInfo *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForSysMdbTopCpuInfo;
#endif

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbTopCpuInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbTopCpuInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbTopCpuInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbTopCpuInfoIteratorByHostName::match(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbTopCpuInfo->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbTopCpuInfoIteratorByDsc> CSysMdbTopCpuInfoIteratorByDsc::iteratorList;
void CSysMdbTopCpuInfoIteratorByDsc::init(CSysMdbTopCpuInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbTopCpuInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysMdbTopCpuInfoIteratorByDsc *CSysMdbTopCpuInfoIteratorByDsc::alloc(CSysMdbTopCpuInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName)
{
	CSysMdbTopCpuInfoIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName);
	return it;
}

CSysMdbTopCpuInfoIteratorByDsc::~CSysMdbTopCpuInfoIteratorByDsc(void)
{
}

void CSysMdbTopCpuInfoIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysMdbTopCpuInfoIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbTopCpuInfoIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
}

void CSysMdbTopCpuInfoIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbTopCpuInfoIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbTopCpuInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbTopCpuInfoIteratorByDsc::UpdateCurrent(CWriteableSysMdbTopCpuInfo * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbTopCpuInfo *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysMdbTopCpuInfo;
#endif

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTopCpuInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbTopCpuInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbTopCpuInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbTopCpuInfoIteratorByDsc::match(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbTopCpuInfo->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbTopCpuInfoIteratorBytheAll> CSysMdbTopCpuInfoIteratorBytheAll::iteratorList;
void CSysMdbTopCpuInfoIteratorBytheAll::init(CSysMdbTopCpuInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbTopCpuInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName="";

}

CSysMdbTopCpuInfoIteratorBytheAll *CSysMdbTopCpuInfoIteratorBytheAll::alloc(CSysMdbTopCpuInfoFactory *pFactory
		)
{
	CSysMdbTopCpuInfoIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMdbTopCpuInfoIteratorBytheAll::~CSysMdbTopCpuInfoIteratorBytheAll(void)
{
}

void CSysMdbTopCpuInfoIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbTopCpuInfoIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbTopCpuInfoIteratorBytheAll");
	
	
}

void CSysMdbTopCpuInfoIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbTopCpuInfoIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbTopCpuInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbTopCpuInfoIteratorBytheAll::UpdateCurrent(CWriteableSysMdbTopCpuInfo * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbTopCpuInfo *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysMdbTopCpuInfo;
#endif

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTopCpuInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbTopCpuInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbTopCpuInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbTopCpuInfoIteratorBytheAll::match(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysMdbTopCpuInfoIteratorByDataDelete> CSysMdbTopCpuInfoIteratorByDataDelete::iteratorList;
void CSysMdbTopCpuInfoIteratorByDataDelete::init(CSysMdbTopCpuInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbTopCpuInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbTopCpuInfoIteratorByDataDelete *CSysMdbTopCpuInfoIteratorByDataDelete::alloc(CSysMdbTopCpuInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbTopCpuInfoIteratorByDataDelete *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName,MonDate,MonTime);
	return it;
}

CSysMdbTopCpuInfoIteratorByDataDelete::~CSysMdbTopCpuInfoIteratorByDataDelete(void)
{
}

void CSysMdbTopCpuInfoIteratorByDataDelete::free(void)
{
	iteratorList.free(this);
}

void CSysMdbTopCpuInfoIteratorByDataDelete::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbTopCpuInfoIteratorByDataDelete");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbTopCpuInfoIteratorByDataDelete::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbTopCpuInfoIteratorByDataDelete::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbTopCpuInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbTopCpuInfoIteratorByDataDelete::UpdateCurrent(CWriteableSysMdbTopCpuInfo * pByDataDelete,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbTopCpuInfo *)(m_pCurrent->pObject),pByDataDelete,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDataDeleteForSysMdbTopCpuInfo;
#endif

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoIteratorByDataDelete::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbTopCpuInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbTopCpuInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbTopCpuInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbTopCpuInfoIteratorByDataDelete::match(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbTopCpuInfo->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysMdbTopMemInfoIteratorByHostName> CSysMdbTopMemInfoIteratorByHostName::iteratorList;
void CSysMdbTopMemInfoIteratorByHostName::init(CSysMdbTopMemInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbTopMemInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbTopMemInfoIteratorByHostName *CSysMdbTopMemInfoIteratorByHostName::alloc(CSysMdbTopMemInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbTopMemInfoIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName,MonDate,MonTime);
	return it;
}

CSysMdbTopMemInfoIteratorByHostName::~CSysMdbTopMemInfoIteratorByHostName(void)
{
}

void CSysMdbTopMemInfoIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CSysMdbTopMemInfoIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbTopMemInfoIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbTopMemInfoIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbTopMemInfoIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbTopMemInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbTopMemInfoIteratorByHostName::UpdateCurrent(CWriteableSysMdbTopMemInfo * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbTopMemInfo *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForSysMdbTopMemInfo;
#endif

CSysMdbTopMemInfo *CSysMdbTopMemInfoIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbTopMemInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbTopMemInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbTopMemInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbTopMemInfoIteratorByHostName::match(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbTopMemInfo->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbTopMemInfoIteratorByDsc> CSysMdbTopMemInfoIteratorByDsc::iteratorList;
void CSysMdbTopMemInfoIteratorByDsc::init(CSysMdbTopMemInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbTopMemInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysMdbTopMemInfoIteratorByDsc *CSysMdbTopMemInfoIteratorByDsc::alloc(CSysMdbTopMemInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName)
{
	CSysMdbTopMemInfoIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName);
	return it;
}

CSysMdbTopMemInfoIteratorByDsc::~CSysMdbTopMemInfoIteratorByDsc(void)
{
}

void CSysMdbTopMemInfoIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysMdbTopMemInfoIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbTopMemInfoIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
}

void CSysMdbTopMemInfoIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbTopMemInfoIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbTopMemInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbTopMemInfoIteratorByDsc::UpdateCurrent(CWriteableSysMdbTopMemInfo * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbTopMemInfo *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysMdbTopMemInfo;
#endif

CSysMdbTopMemInfo *CSysMdbTopMemInfoIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTopMemInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbTopMemInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbTopMemInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbTopMemInfoIteratorByDsc::match(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbTopMemInfo->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbTopMemInfoIteratorBytheAll> CSysMdbTopMemInfoIteratorBytheAll::iteratorList;
void CSysMdbTopMemInfoIteratorBytheAll::init(CSysMdbTopMemInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbTopMemInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName="";

}

CSysMdbTopMemInfoIteratorBytheAll *CSysMdbTopMemInfoIteratorBytheAll::alloc(CSysMdbTopMemInfoFactory *pFactory
		)
{
	CSysMdbTopMemInfoIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMdbTopMemInfoIteratorBytheAll::~CSysMdbTopMemInfoIteratorBytheAll(void)
{
}

void CSysMdbTopMemInfoIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbTopMemInfoIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbTopMemInfoIteratorBytheAll");
	
	
}

void CSysMdbTopMemInfoIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbTopMemInfoIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbTopMemInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbTopMemInfoIteratorBytheAll::UpdateCurrent(CWriteableSysMdbTopMemInfo * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbTopMemInfo *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysMdbTopMemInfo;
#endif

CSysMdbTopMemInfo *CSysMdbTopMemInfoIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTopMemInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbTopMemInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbTopMemInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbTopMemInfoIteratorBytheAll::match(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysMdbTopMemInfoIteratorByDataDelete> CSysMdbTopMemInfoIteratorByDataDelete::iteratorList;
void CSysMdbTopMemInfoIteratorByDataDelete::init(CSysMdbTopMemInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbTopMemInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbTopMemInfoIteratorByDataDelete *CSysMdbTopMemInfoIteratorByDataDelete::alloc(CSysMdbTopMemInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbTopMemInfoIteratorByDataDelete *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName,MonDate,MonTime);
	return it;
}

CSysMdbTopMemInfoIteratorByDataDelete::~CSysMdbTopMemInfoIteratorByDataDelete(void)
{
}

void CSysMdbTopMemInfoIteratorByDataDelete::free(void)
{
	iteratorList.free(this);
}

void CSysMdbTopMemInfoIteratorByDataDelete::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbTopMemInfoIteratorByDataDelete");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbTopMemInfoIteratorByDataDelete::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbTopMemInfoIteratorByDataDelete::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbTopMemInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbTopMemInfoIteratorByDataDelete::UpdateCurrent(CWriteableSysMdbTopMemInfo * pByDataDelete,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbTopMemInfo *)(m_pCurrent->pObject),pByDataDelete,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDataDeleteForSysMdbTopMemInfo;
#endif

CSysMdbTopMemInfo *CSysMdbTopMemInfoIteratorByDataDelete::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbTopMemInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbTopMemInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbTopMemInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbTopMemInfoIteratorByDataDelete::match(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbTopMemInfo->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysMdbTopProcessInfoIteratorByHostName> CSysMdbTopProcessInfoIteratorByHostName::iteratorList;
void CSysMdbTopProcessInfoIteratorByHostName::init(CSysMdbTopProcessInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbTopProcessInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbTopProcessInfoIteratorByHostName *CSysMdbTopProcessInfoIteratorByHostName::alloc(CSysMdbTopProcessInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbTopProcessInfoIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName,MonDate,MonTime);
	return it;
}

CSysMdbTopProcessInfoIteratorByHostName::~CSysMdbTopProcessInfoIteratorByHostName(void)
{
}

void CSysMdbTopProcessInfoIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CSysMdbTopProcessInfoIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbTopProcessInfoIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbTopProcessInfoIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbTopProcessInfoIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbTopProcessInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbTopProcessInfoIteratorByHostName::UpdateCurrent(CWriteableSysMdbTopProcessInfo * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbTopProcessInfo *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForSysMdbTopProcessInfo;
#endif

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbTopProcessInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbTopProcessInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbTopProcessInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbTopProcessInfoIteratorByHostName::match(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbTopProcessInfo->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbTopProcessInfoIteratorByDsc> CSysMdbTopProcessInfoIteratorByDsc::iteratorList;
void CSysMdbTopProcessInfoIteratorByDsc::init(CSysMdbTopProcessInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbTopProcessInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysMdbTopProcessInfoIteratorByDsc *CSysMdbTopProcessInfoIteratorByDsc::alloc(CSysMdbTopProcessInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName)
{
	CSysMdbTopProcessInfoIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName);
	return it;
}

CSysMdbTopProcessInfoIteratorByDsc::~CSysMdbTopProcessInfoIteratorByDsc(void)
{
}

void CSysMdbTopProcessInfoIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysMdbTopProcessInfoIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbTopProcessInfoIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
}

void CSysMdbTopProcessInfoIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbTopProcessInfoIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbTopProcessInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbTopProcessInfoIteratorByDsc::UpdateCurrent(CWriteableSysMdbTopProcessInfo * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbTopProcessInfo *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysMdbTopProcessInfo;
#endif

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTopProcessInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbTopProcessInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbTopProcessInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbTopProcessInfoIteratorByDsc::match(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbTopProcessInfo->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbTopProcessInfoIteratorBytheAll> CSysMdbTopProcessInfoIteratorBytheAll::iteratorList;
void CSysMdbTopProcessInfoIteratorBytheAll::init(CSysMdbTopProcessInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbTopProcessInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName="";

}

CSysMdbTopProcessInfoIteratorBytheAll *CSysMdbTopProcessInfoIteratorBytheAll::alloc(CSysMdbTopProcessInfoFactory *pFactory
		)
{
	CSysMdbTopProcessInfoIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMdbTopProcessInfoIteratorBytheAll::~CSysMdbTopProcessInfoIteratorBytheAll(void)
{
}

void CSysMdbTopProcessInfoIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbTopProcessInfoIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbTopProcessInfoIteratorBytheAll");
	
	
}

void CSysMdbTopProcessInfoIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbTopProcessInfoIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbTopProcessInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbTopProcessInfoIteratorBytheAll::UpdateCurrent(CWriteableSysMdbTopProcessInfo * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbTopProcessInfo *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysMdbTopProcessInfo;
#endif

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTopProcessInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbTopProcessInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbTopProcessInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbTopProcessInfoIteratorBytheAll::match(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysMdbFileSystemInfoIteratorByHostName> CSysMdbFileSystemInfoIteratorByHostName::iteratorList;
void CSysMdbFileSystemInfoIteratorByHostName::init(CSysMdbFileSystemInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbFileSystemInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbFileSystemInfoIteratorByHostName *CSysMdbFileSystemInfoIteratorByHostName::alloc(CSysMdbFileSystemInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbFileSystemInfoIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName,MonDate,MonTime);
	return it;
}

CSysMdbFileSystemInfoIteratorByHostName::~CSysMdbFileSystemInfoIteratorByHostName(void)
{
}

void CSysMdbFileSystemInfoIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CSysMdbFileSystemInfoIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbFileSystemInfoIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbFileSystemInfoIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbFileSystemInfoIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbFileSystemInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbFileSystemInfoIteratorByHostName::UpdateCurrent(CWriteableSysMdbFileSystemInfo * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbFileSystemInfo *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForSysMdbFileSystemInfo;
#endif

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbFileSystemInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbFileSystemInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbFileSystemInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbFileSystemInfoIteratorByHostName::match(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbFileSystemInfo->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbFileSystemInfoIteratorByDsc> CSysMdbFileSystemInfoIteratorByDsc::iteratorList;
void CSysMdbFileSystemInfoIteratorByDsc::init(CSysMdbFileSystemInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbFileSystemInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName=HostName.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysMdbFileSystemInfoIteratorByDsc *CSysMdbFileSystemInfoIteratorByDsc::alloc(CSysMdbFileSystemInfoFactory *pFactory
		, const CReadOnlyVolumeType& HostName)
{
	CSysMdbFileSystemInfoIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,HostName);
	return it;
}

CSysMdbFileSystemInfoIteratorByDsc::~CSysMdbFileSystemInfoIteratorByDsc(void)
{
}

void CSysMdbFileSystemInfoIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysMdbFileSystemInfoIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbFileSystemInfoIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.HostName.getString(buffer);
	pLogger->output(indent+1,0,"query HostName=%s",buffer);
	
}

void CSysMdbFileSystemInfoIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbFileSystemInfoIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbFileSystemInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbFileSystemInfoIteratorByDsc::UpdateCurrent(CWriteableSysMdbFileSystemInfo * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbFileSystemInfo *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysMdbFileSystemInfo;
#endif

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbFileSystemInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbFileSystemInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbFileSystemInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbFileSystemInfoIteratorByDsc::match(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbFileSystemInfo->HostName.getValue(),m_compareObject.HostName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbFileSystemInfoIteratorBytheAll> CSysMdbFileSystemInfoIteratorBytheAll::iteratorList;
void CSysMdbFileSystemInfoIteratorBytheAll::init(CSysMdbFileSystemInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbFileSystemInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.HostName="";

}

CSysMdbFileSystemInfoIteratorBytheAll *CSysMdbFileSystemInfoIteratorBytheAll::alloc(CSysMdbFileSystemInfoFactory *pFactory
		)
{
	CSysMdbFileSystemInfoIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMdbFileSystemInfoIteratorBytheAll::~CSysMdbFileSystemInfoIteratorBytheAll(void)
{
}

void CSysMdbFileSystemInfoIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbFileSystemInfoIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbFileSystemInfoIteratorBytheAll");
	
	
}

void CSysMdbFileSystemInfoIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbFileSystemInfoIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbFileSystemInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbFileSystemInfoIteratorBytheAll::UpdateCurrent(CWriteableSysMdbFileSystemInfo * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbFileSystemInfo *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysMdbFileSystemInfo;
#endif

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbFileSystemInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbFileSystemInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbFileSystemInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbFileSystemInfoIteratorBytheAll::match(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysMdbNetworkInfoIteratorByHostName> CSysMdbNetworkInfoIteratorByHostName::iteratorList;
void CSysMdbNetworkInfoIteratorByHostName::init(CSysMdbNetworkInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbNetworkInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbNetworkInfoIteratorByHostName *CSysMdbNetworkInfoIteratorByHostName::alloc(CSysMdbNetworkInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbNetworkInfoIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID,MonDate,MonTime);
	return it;
}

CSysMdbNetworkInfoIteratorByHostName::~CSysMdbNetworkInfoIteratorByHostName(void)
{
}

void CSysMdbNetworkInfoIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CSysMdbNetworkInfoIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbNetworkInfoIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbNetworkInfoIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbNetworkInfoIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbNetworkInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbNetworkInfoIteratorByHostName::UpdateCurrent(CWriteableSysMdbNetworkInfo * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbNetworkInfo *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForSysMdbNetworkInfo;
#endif

CSysMdbNetworkInfo *CSysMdbNetworkInfoIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbNetworkInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbNetworkInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbNetworkInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbNetworkInfoIteratorByHostName::match(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbNetworkInfo->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbNetworkInfoIteratorByDsc> CSysMdbNetworkInfoIteratorByDsc::iteratorList;
void CSysMdbNetworkInfoIteratorByDsc::init(CSysMdbNetworkInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbNetworkInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysMdbNetworkInfoIteratorByDsc *CSysMdbNetworkInfoIteratorByDsc::alloc(CSysMdbNetworkInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID)
{
	CSysMdbNetworkInfoIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID);
	return it;
}

CSysMdbNetworkInfoIteratorByDsc::~CSysMdbNetworkInfoIteratorByDsc(void)
{
}

void CSysMdbNetworkInfoIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysMdbNetworkInfoIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbNetworkInfoIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
}

void CSysMdbNetworkInfoIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbNetworkInfoIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbNetworkInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbNetworkInfoIteratorByDsc::UpdateCurrent(CWriteableSysMdbNetworkInfo * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbNetworkInfo *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysMdbNetworkInfo;
#endif

CSysMdbNetworkInfo *CSysMdbNetworkInfoIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbNetworkInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbNetworkInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbNetworkInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbNetworkInfoIteratorByDsc::match(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbNetworkInfo->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbNetworkInfoIteratorBytheAll> CSysMdbNetworkInfoIteratorBytheAll::iteratorList;
void CSysMdbNetworkInfoIteratorBytheAll::init(CSysMdbNetworkInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbNetworkInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID="";

}

CSysMdbNetworkInfoIteratorBytheAll *CSysMdbNetworkInfoIteratorBytheAll::alloc(CSysMdbNetworkInfoFactory *pFactory
		)
{
	CSysMdbNetworkInfoIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMdbNetworkInfoIteratorBytheAll::~CSysMdbNetworkInfoIteratorBytheAll(void)
{
}

void CSysMdbNetworkInfoIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbNetworkInfoIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbNetworkInfoIteratorBytheAll");
	
	
}

void CSysMdbNetworkInfoIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbNetworkInfoIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbNetworkInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbNetworkInfoIteratorBytheAll::UpdateCurrent(CWriteableSysMdbNetworkInfo * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbNetworkInfo *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysMdbNetworkInfo;
#endif

CSysMdbNetworkInfo *CSysMdbNetworkInfoIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbNetworkInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbNetworkInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbNetworkInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbNetworkInfoIteratorBytheAll::match(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysMdbNetworkInfoIteratorByDataDelete> CSysMdbNetworkInfoIteratorByDataDelete::iteratorList;
void CSysMdbNetworkInfoIteratorByDataDelete::init(CSysMdbNetworkInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbNetworkInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbNetworkInfoIteratorByDataDelete *CSysMdbNetworkInfoIteratorByDataDelete::alloc(CSysMdbNetworkInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbNetworkInfoIteratorByDataDelete *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID,MonDate,MonTime);
	return it;
}

CSysMdbNetworkInfoIteratorByDataDelete::~CSysMdbNetworkInfoIteratorByDataDelete(void)
{
}

void CSysMdbNetworkInfoIteratorByDataDelete::free(void)
{
	iteratorList.free(this);
}

void CSysMdbNetworkInfoIteratorByDataDelete::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbNetworkInfoIteratorByDataDelete");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbNetworkInfoIteratorByDataDelete::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbNetworkInfoIteratorByDataDelete::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbNetworkInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbNetworkInfoIteratorByDataDelete::UpdateCurrent(CWriteableSysMdbNetworkInfo * pByDataDelete,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbNetworkInfo *)(m_pCurrent->pObject),pByDataDelete,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDataDeleteForSysMdbNetworkInfo;
#endif

CSysMdbNetworkInfo *CSysMdbNetworkInfoIteratorByDataDelete::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbNetworkInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbNetworkInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbNetworkInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbNetworkInfoIteratorByDataDelete::match(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbNetworkInfo->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysParticipantInitIteratorByAll> CSysParticipantInitIteratorByAll::iteratorList;
void CSysParticipantInitIteratorByAll::init(CSysParticipantInitFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysParticipantInitIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID="";

}

CSysParticipantInitIteratorByAll *CSysParticipantInitIteratorByAll::alloc(CSysParticipantInitFactory *pFactory
		)
{
	CSysParticipantInitIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysParticipantInitIteratorByAll::~CSysParticipantInitIteratorByAll(void)
{
}

void CSysParticipantInitIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysParticipantInitIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysParticipantInitIteratorByAll");
	
	
}

void CSysParticipantInitIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysParticipantIDIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysParticipantIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysParticipantInitIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysParticipantInit *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysParticipantInitIteratorByAll::UpdateCurrent(CWriteableSysParticipantInit * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysParticipantInit *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysParticipantInit;
#endif

CSysParticipantInit *CSysParticipantInitIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysParticipantInit++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysParticipantInit *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysParticipantInit *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysParticipantInitIteratorByAll::match(CSysParticipantInit *pSysParticipantInit)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysUserInitIteratorByAll> CSysUserInitIteratorByAll::iteratorList;
void CSysUserInitIteratorByAll::init(CSysUserInitFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysUserInitIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.UserID="";

}

CSysUserInitIteratorByAll *CSysUserInitIteratorByAll::alloc(CSysUserInitFactory *pFactory
		)
{
	CSysUserInitIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysUserInitIteratorByAll::~CSysUserInitIteratorByAll(void)
{
}

void CSysUserInitIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysUserInitIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysUserInitIteratorByAll");
	
	
}

void CSysUserInitIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysUserIDIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysUserIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysUserInitIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysUserInit *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysUserInitIteratorByAll::UpdateCurrent(CWriteableSysUserInit * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysUserInit *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysUserInit;
#endif

CSysUserInit *CSysUserInitIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysUserInit++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysUserInit *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysUserInit *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysUserInitIteratorByAll::match(CSysUserInit *pSysUserInit)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysClientInitIteratorByAll> CSysClientInitIteratorByAll::iteratorList;
void CSysClientInitIteratorByAll::init(CSysClientInitFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysClientInitIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ClientID="";

}

CSysClientInitIteratorByAll *CSysClientInitIteratorByAll::alloc(CSysClientInitFactory *pFactory
		)
{
	CSysClientInitIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysClientInitIteratorByAll::~CSysClientInitIteratorByAll(void)
{
}

void CSysClientInitIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysClientInitIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysClientInitIteratorByAll");
	
	
}

void CSysClientInitIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysClientIDIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysClientIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysClientInitIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysClientInit *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysClientInitIteratorByAll::UpdateCurrent(CWriteableSysClientInit * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysClientInit *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysClientInit;
#endif

CSysClientInit *CSysClientInitIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysClientInit++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysClientInit *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysClientInit *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysClientInitIteratorByAll::match(CSysClientInit *pSysClientInit)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysTradeUserLoginInfoIteratorByAll> CSysTradeUserLoginInfoIteratorByAll::iteratorList;
void CSysTradeUserLoginInfoIteratorByAll::init(CSysTradeUserLoginInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysTradeUserLoginInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID="";
	m_compareObject.UserID="";

}

CSysTradeUserLoginInfoIteratorByAll *CSysTradeUserLoginInfoIteratorByAll::alloc(CSysTradeUserLoginInfoFactory *pFactory
		)
{
	CSysTradeUserLoginInfoIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysTradeUserLoginInfoIteratorByAll::~CSysTradeUserLoginInfoIteratorByAll(void)
{
}

void CSysTradeUserLoginInfoIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysTradeUserLoginInfoIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysTradeUserLoginInfoIteratorByAll");
	
	
}

void CSysTradeUserLoginInfoIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTradeUserLoginInfoIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTradeUserLoginInfoIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysTradeUserLoginInfoIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysTradeUserLoginInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysTradeUserLoginInfoIteratorByAll::UpdateCurrent(CWriteableSysTradeUserLoginInfo * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysTradeUserLoginInfo *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysTradeUserLoginInfo;
#endif

CSysTradeUserLoginInfo *CSysTradeUserLoginInfoIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysTradeUserLoginInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysTradeUserLoginInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysTradeUserLoginInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysTradeUserLoginInfoIteratorByAll::match(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysMdbWebAppInfoIteratorByIDType> CSysMdbWebAppInfoIteratorByIDType::iteratorList;
void CSysMdbWebAppInfoIteratorByIDType::init(CSysMdbWebAppInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbWebAppInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbWebAppInfoIteratorByIDType *CSysMdbWebAppInfoIteratorByIDType::alloc(CSysMdbWebAppInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbWebAppInfoIteratorByIDType *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID,MonDate,MonTime);
	return it;
}

CSysMdbWebAppInfoIteratorByIDType::~CSysMdbWebAppInfoIteratorByIDType(void)
{
}

void CSysMdbWebAppInfoIteratorByIDType::free(void)
{
	iteratorList.free(this);
}

void CSysMdbWebAppInfoIteratorByIDType::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbWebAppInfoIteratorByIDType");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbWebAppInfoIteratorByIDType::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbWebAppInfoIteratorByIDType::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbWebAppInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbWebAppInfoIteratorByIDType::UpdateCurrent(CWriteableSysMdbWebAppInfo * pByIDType,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbWebAppInfo *)(m_pCurrent->pObject),pByIDType,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByIDTypeForSysMdbWebAppInfo;
#endif

CSysMdbWebAppInfo *CSysMdbWebAppInfoIteratorByIDType::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbWebAppInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbWebAppInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbWebAppInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbWebAppInfoIteratorByIDType::match(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbWebAppInfo->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbWebAppInfoIteratorByDsc> CSysMdbWebAppInfoIteratorByDsc::iteratorList;
void CSysMdbWebAppInfoIteratorByDsc::init(CSysMdbWebAppInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbWebAppInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysMdbWebAppInfoIteratorByDsc *CSysMdbWebAppInfoIteratorByDsc::alloc(CSysMdbWebAppInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID)
{
	CSysMdbWebAppInfoIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID);
	return it;
}

CSysMdbWebAppInfoIteratorByDsc::~CSysMdbWebAppInfoIteratorByDsc(void)
{
}

void CSysMdbWebAppInfoIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysMdbWebAppInfoIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbWebAppInfoIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
}

void CSysMdbWebAppInfoIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbWebAppInfoIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbWebAppInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbWebAppInfoIteratorByDsc::UpdateCurrent(CWriteableSysMdbWebAppInfo * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbWebAppInfo *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysMdbWebAppInfo;
#endif

CSysMdbWebAppInfo *CSysMdbWebAppInfoIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbWebAppInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbWebAppInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbWebAppInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbWebAppInfoIteratorByDsc::match(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbWebAppInfo->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbWebAppInfoIteratorBytheAll> CSysMdbWebAppInfoIteratorBytheAll::iteratorList;
void CSysMdbWebAppInfoIteratorBytheAll::init(CSysMdbWebAppInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbWebAppInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID="";

}

CSysMdbWebAppInfoIteratorBytheAll *CSysMdbWebAppInfoIteratorBytheAll::alloc(CSysMdbWebAppInfoFactory *pFactory
		)
{
	CSysMdbWebAppInfoIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMdbWebAppInfoIteratorBytheAll::~CSysMdbWebAppInfoIteratorBytheAll(void)
{
}

void CSysMdbWebAppInfoIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbWebAppInfoIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbWebAppInfoIteratorBytheAll");
	
	
}

void CSysMdbWebAppInfoIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbWebAppInfoIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbWebAppInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbWebAppInfoIteratorBytheAll::UpdateCurrent(CWriteableSysMdbWebAppInfo * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbWebAppInfo *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysMdbWebAppInfo;
#endif

CSysMdbWebAppInfo *CSysMdbWebAppInfoIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbWebAppInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbWebAppInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbWebAppInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbWebAppInfoIteratorBytheAll::match(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysMdbWebAppInfoIteratorByDataDelete> CSysMdbWebAppInfoIteratorByDataDelete::iteratorList;
void CSysMdbWebAppInfoIteratorByDataDelete::init(CSysMdbWebAppInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbWebAppInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbWebAppInfoIteratorByDataDelete *CSysMdbWebAppInfoIteratorByDataDelete::alloc(CSysMdbWebAppInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbWebAppInfoIteratorByDataDelete *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID,MonDate,MonTime);
	return it;
}

CSysMdbWebAppInfoIteratorByDataDelete::~CSysMdbWebAppInfoIteratorByDataDelete(void)
{
}

void CSysMdbWebAppInfoIteratorByDataDelete::free(void)
{
	iteratorList.free(this);
}

void CSysMdbWebAppInfoIteratorByDataDelete::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbWebAppInfoIteratorByDataDelete");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbWebAppInfoIteratorByDataDelete::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbWebAppInfoIteratorByDataDelete::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbWebAppInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbWebAppInfoIteratorByDataDelete::UpdateCurrent(CWriteableSysMdbWebAppInfo * pByDataDelete,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbWebAppInfo *)(m_pCurrent->pObject),pByDataDelete,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDataDeleteForSysMdbWebAppInfo;
#endif

CSysMdbWebAppInfo *CSysMdbWebAppInfoIteratorByDataDelete::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbWebAppInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbWebAppInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbWebAppInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbWebAppInfoIteratorByDataDelete::match(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbWebAppInfo->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysMdbMemPoolInfoIteratorByIDType> CSysMdbMemPoolInfoIteratorByIDType::iteratorList;
void CSysMdbMemPoolInfoIteratorByIDType::init(CSysMdbMemPoolInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbMemPoolInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbMemPoolInfoIteratorByIDType *CSysMdbMemPoolInfoIteratorByIDType::alloc(CSysMdbMemPoolInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbMemPoolInfoIteratorByIDType *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID,MonDate,MonTime);
	return it;
}

CSysMdbMemPoolInfoIteratorByIDType::~CSysMdbMemPoolInfoIteratorByIDType(void)
{
}

void CSysMdbMemPoolInfoIteratorByIDType::free(void)
{
	iteratorList.free(this);
}

void CSysMdbMemPoolInfoIteratorByIDType::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbMemPoolInfoIteratorByIDType");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbMemPoolInfoIteratorByIDType::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbMemPoolInfoIteratorByIDType::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbMemPoolInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbMemPoolInfoIteratorByIDType::UpdateCurrent(CWriteableSysMdbMemPoolInfo * pByIDType,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbMemPoolInfo *)(m_pCurrent->pObject),pByIDType,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByIDTypeForSysMdbMemPoolInfo;
#endif

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoIteratorByIDType::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbMemPoolInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbMemPoolInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbMemPoolInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbMemPoolInfoIteratorByIDType::match(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbMemPoolInfo->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbMemPoolInfoIteratorByDsc> CSysMdbMemPoolInfoIteratorByDsc::iteratorList;
void CSysMdbMemPoolInfoIteratorByDsc::init(CSysMdbMemPoolInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbMemPoolInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysMdbMemPoolInfoIteratorByDsc *CSysMdbMemPoolInfoIteratorByDsc::alloc(CSysMdbMemPoolInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID)
{
	CSysMdbMemPoolInfoIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID);
	return it;
}

CSysMdbMemPoolInfoIteratorByDsc::~CSysMdbMemPoolInfoIteratorByDsc(void)
{
}

void CSysMdbMemPoolInfoIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysMdbMemPoolInfoIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbMemPoolInfoIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
}

void CSysMdbMemPoolInfoIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbMemPoolInfoIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbMemPoolInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbMemPoolInfoIteratorByDsc::UpdateCurrent(CWriteableSysMdbMemPoolInfo * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbMemPoolInfo *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysMdbMemPoolInfo;
#endif

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbMemPoolInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbMemPoolInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbMemPoolInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbMemPoolInfoIteratorByDsc::match(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbMemPoolInfo->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbMemPoolInfoIteratorBytheAll> CSysMdbMemPoolInfoIteratorBytheAll::iteratorList;
void CSysMdbMemPoolInfoIteratorBytheAll::init(CSysMdbMemPoolInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbMemPoolInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID="";

}

CSysMdbMemPoolInfoIteratorBytheAll *CSysMdbMemPoolInfoIteratorBytheAll::alloc(CSysMdbMemPoolInfoFactory *pFactory
		)
{
	CSysMdbMemPoolInfoIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMdbMemPoolInfoIteratorBytheAll::~CSysMdbMemPoolInfoIteratorBytheAll(void)
{
}

void CSysMdbMemPoolInfoIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbMemPoolInfoIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbMemPoolInfoIteratorBytheAll");
	
	
}

void CSysMdbMemPoolInfoIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbMemPoolInfoIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbMemPoolInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbMemPoolInfoIteratorBytheAll::UpdateCurrent(CWriteableSysMdbMemPoolInfo * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbMemPoolInfo *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysMdbMemPoolInfo;
#endif

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbMemPoolInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbMemPoolInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbMemPoolInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbMemPoolInfoIteratorBytheAll::match(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysMdbMemPoolInfoIteratorByDataDelete> CSysMdbMemPoolInfoIteratorByDataDelete::iteratorList;
void CSysMdbMemPoolInfoIteratorByDataDelete::init(CSysMdbMemPoolInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbMemPoolInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbMemPoolInfoIteratorByDataDelete *CSysMdbMemPoolInfoIteratorByDataDelete::alloc(CSysMdbMemPoolInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbMemPoolInfoIteratorByDataDelete *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID,MonDate,MonTime);
	return it;
}

CSysMdbMemPoolInfoIteratorByDataDelete::~CSysMdbMemPoolInfoIteratorByDataDelete(void)
{
}

void CSysMdbMemPoolInfoIteratorByDataDelete::free(void)
{
	iteratorList.free(this);
}

void CSysMdbMemPoolInfoIteratorByDataDelete::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbMemPoolInfoIteratorByDataDelete");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbMemPoolInfoIteratorByDataDelete::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbMemPoolInfoIteratorByDataDelete::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbMemPoolInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbMemPoolInfoIteratorByDataDelete::UpdateCurrent(CWriteableSysMdbMemPoolInfo * pByDataDelete,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbMemPoolInfo *)(m_pCurrent->pObject),pByDataDelete,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDataDeleteForSysMdbMemPoolInfo;
#endif

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoIteratorByDataDelete::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbMemPoolInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbMemPoolInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbMemPoolInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbMemPoolInfoIteratorByDataDelete::match(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbMemPoolInfo->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysMdbConnectorInfoIteratorByIDType> CSysMdbConnectorInfoIteratorByIDType::iteratorList;
void CSysMdbConnectorInfoIteratorByIDType::init(CSysMdbConnectorInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbConnectorInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbConnectorInfoIteratorByIDType *CSysMdbConnectorInfoIteratorByIDType::alloc(CSysMdbConnectorInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbConnectorInfoIteratorByIDType *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID,MonDate,MonTime);
	return it;
}

CSysMdbConnectorInfoIteratorByIDType::~CSysMdbConnectorInfoIteratorByIDType(void)
{
}

void CSysMdbConnectorInfoIteratorByIDType::free(void)
{
	iteratorList.free(this);
}

void CSysMdbConnectorInfoIteratorByIDType::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbConnectorInfoIteratorByIDType");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbConnectorInfoIteratorByIDType::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbConnectorInfoIteratorByIDType::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbConnectorInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbConnectorInfoIteratorByIDType::UpdateCurrent(CWriteableSysMdbConnectorInfo * pByIDType,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbConnectorInfo *)(m_pCurrent->pObject),pByIDType,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByIDTypeForSysMdbConnectorInfo;
#endif

CSysMdbConnectorInfo *CSysMdbConnectorInfoIteratorByIDType::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbConnectorInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbConnectorInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbConnectorInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbConnectorInfoIteratorByIDType::match(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbConnectorInfo->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbConnectorInfoIteratorByDsc> CSysMdbConnectorInfoIteratorByDsc::iteratorList;
void CSysMdbConnectorInfoIteratorByDsc::init(CSysMdbConnectorInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbConnectorInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysMdbConnectorInfoIteratorByDsc *CSysMdbConnectorInfoIteratorByDsc::alloc(CSysMdbConnectorInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID)
{
	CSysMdbConnectorInfoIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID);
	return it;
}

CSysMdbConnectorInfoIteratorByDsc::~CSysMdbConnectorInfoIteratorByDsc(void)
{
}

void CSysMdbConnectorInfoIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysMdbConnectorInfoIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbConnectorInfoIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
}

void CSysMdbConnectorInfoIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbConnectorInfoIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbConnectorInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbConnectorInfoIteratorByDsc::UpdateCurrent(CWriteableSysMdbConnectorInfo * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbConnectorInfo *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysMdbConnectorInfo;
#endif

CSysMdbConnectorInfo *CSysMdbConnectorInfoIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbConnectorInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbConnectorInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbConnectorInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbConnectorInfoIteratorByDsc::match(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbConnectorInfo->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbConnectorInfoIteratorBytheAll> CSysMdbConnectorInfoIteratorBytheAll::iteratorList;
void CSysMdbConnectorInfoIteratorBytheAll::init(CSysMdbConnectorInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbConnectorInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID="";

}

CSysMdbConnectorInfoIteratorBytheAll *CSysMdbConnectorInfoIteratorBytheAll::alloc(CSysMdbConnectorInfoFactory *pFactory
		)
{
	CSysMdbConnectorInfoIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMdbConnectorInfoIteratorBytheAll::~CSysMdbConnectorInfoIteratorBytheAll(void)
{
}

void CSysMdbConnectorInfoIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbConnectorInfoIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbConnectorInfoIteratorBytheAll");
	
	
}

void CSysMdbConnectorInfoIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbConnectorInfoIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbConnectorInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbConnectorInfoIteratorBytheAll::UpdateCurrent(CWriteableSysMdbConnectorInfo * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbConnectorInfo *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysMdbConnectorInfo;
#endif

CSysMdbConnectorInfo *CSysMdbConnectorInfoIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbConnectorInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbConnectorInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbConnectorInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbConnectorInfoIteratorBytheAll::match(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysMdbConnectorInfoIteratorByDataDelete> CSysMdbConnectorInfoIteratorByDataDelete::iteratorList;
void CSysMdbConnectorInfoIteratorByDataDelete::init(CSysMdbConnectorInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbConnectorInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbConnectorInfoIteratorByDataDelete *CSysMdbConnectorInfoIteratorByDataDelete::alloc(CSysMdbConnectorInfoFactory *pFactory
		, const CReadOnlyVolumeType& ObjectID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbConnectorInfoIteratorByDataDelete *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID,MonDate,MonTime);
	return it;
}

CSysMdbConnectorInfoIteratorByDataDelete::~CSysMdbConnectorInfoIteratorByDataDelete(void)
{
}

void CSysMdbConnectorInfoIteratorByDataDelete::free(void)
{
	iteratorList.free(this);
}

void CSysMdbConnectorInfoIteratorByDataDelete::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbConnectorInfoIteratorByDataDelete");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbConnectorInfoIteratorByDataDelete::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbConnectorInfoIteratorByDataDelete::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbConnectorInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbConnectorInfoIteratorByDataDelete::UpdateCurrent(CWriteableSysMdbConnectorInfo * pByDataDelete,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbConnectorInfo *)(m_pCurrent->pObject),pByDataDelete,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDataDeleteForSysMdbConnectorInfo;
#endif

CSysMdbConnectorInfo *CSysMdbConnectorInfoIteratorByDataDelete::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbConnectorInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbConnectorInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbConnectorInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbConnectorInfoIteratorByDataDelete::match(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbConnectorInfo->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysMdbDBQueryIteratorByIDType> CSysMdbDBQueryIteratorByIDType::iteratorList;
void CSysMdbDBQueryIteratorByIDType::init(CSysMdbDBQueryFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbDBQueryIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbDBQueryIteratorByIDType *CSysMdbDBQueryIteratorByIDType::alloc(CSysMdbDBQueryFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbDBQueryIteratorByIDType *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID,MonDate,MonTime);
	return it;
}

CSysMdbDBQueryIteratorByIDType::~CSysMdbDBQueryIteratorByIDType(void)
{
}

void CSysMdbDBQueryIteratorByIDType::free(void)
{
	iteratorList.free(this);
}

void CSysMdbDBQueryIteratorByIDType::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbDBQueryIteratorByIDType");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbDBQueryIteratorByIDType::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbDBQueryIteratorByIDType::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbDBQuery *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbDBQueryIteratorByIDType::UpdateCurrent(CWriteableSysMdbDBQuery * pByIDType,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbDBQuery *)(m_pCurrent->pObject),pByIDType,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByIDTypeForSysMdbDBQuery;
#endif

CSysMdbDBQuery *CSysMdbDBQueryIteratorByIDType::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbDBQuery++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbDBQuery *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbDBQuery *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbDBQueryIteratorByIDType::match(CSysMdbDBQuery *pSysMdbDBQuery)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbDBQuery->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbDBQueryIteratorByDsc> CSysMdbDBQueryIteratorByDsc::iteratorList;
void CSysMdbDBQueryIteratorByDsc::init(CSysMdbDBQueryFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbDBQueryIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysMdbDBQueryIteratorByDsc *CSysMdbDBQueryIteratorByDsc::alloc(CSysMdbDBQueryFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID)
{
	CSysMdbDBQueryIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID);
	return it;
}

CSysMdbDBQueryIteratorByDsc::~CSysMdbDBQueryIteratorByDsc(void)
{
}

void CSysMdbDBQueryIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysMdbDBQueryIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbDBQueryIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
}

void CSysMdbDBQueryIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbDBQueryIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbDBQuery *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbDBQueryIteratorByDsc::UpdateCurrent(CWriteableSysMdbDBQuery * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbDBQuery *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysMdbDBQuery;
#endif

CSysMdbDBQuery *CSysMdbDBQueryIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbDBQuery++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbDBQuery *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbDBQuery *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbDBQueryIteratorByDsc::match(CSysMdbDBQuery *pSysMdbDBQuery)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbDBQuery->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbDBQueryIteratorBytheAll> CSysMdbDBQueryIteratorBytheAll::iteratorList;
void CSysMdbDBQueryIteratorBytheAll::init(CSysMdbDBQueryFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbDBQueryIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID="";

}

CSysMdbDBQueryIteratorBytheAll *CSysMdbDBQueryIteratorBytheAll::alloc(CSysMdbDBQueryFactory *pFactory
		)
{
	CSysMdbDBQueryIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMdbDBQueryIteratorBytheAll::~CSysMdbDBQueryIteratorBytheAll(void)
{
}

void CSysMdbDBQueryIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbDBQueryIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbDBQueryIteratorBytheAll");
	
	
}

void CSysMdbDBQueryIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbDBQueryIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbDBQuery *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbDBQueryIteratorBytheAll::UpdateCurrent(CWriteableSysMdbDBQuery * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbDBQuery *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysMdbDBQuery;
#endif

CSysMdbDBQuery *CSysMdbDBQueryIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbDBQuery++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbDBQuery *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbDBQuery *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbDBQueryIteratorBytheAll::match(CSysMdbDBQuery *pSysMdbDBQuery)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysMdbDBQueryIteratorByDataDelete> CSysMdbDBQueryIteratorByDataDelete::iteratorList;
void CSysMdbDBQueryIteratorByDataDelete::init(CSysMdbDBQueryFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbDBQueryIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbDBQueryIteratorByDataDelete *CSysMdbDBQueryIteratorByDataDelete::alloc(CSysMdbDBQueryFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbDBQueryIteratorByDataDelete *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID,MonDate,MonTime);
	return it;
}

CSysMdbDBQueryIteratorByDataDelete::~CSysMdbDBQueryIteratorByDataDelete(void)
{
}

void CSysMdbDBQueryIteratorByDataDelete::free(void)
{
	iteratorList.free(this);
}

void CSysMdbDBQueryIteratorByDataDelete::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbDBQueryIteratorByDataDelete");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbDBQueryIteratorByDataDelete::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbDBQueryIteratorByDataDelete::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbDBQuery *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbDBQueryIteratorByDataDelete::UpdateCurrent(CWriteableSysMdbDBQuery * pByDataDelete,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbDBQuery *)(m_pCurrent->pObject),pByDataDelete,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDataDeleteForSysMdbDBQuery;
#endif

CSysMdbDBQuery *CSysMdbDBQueryIteratorByDataDelete::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbDBQuery++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbDBQuery *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbDBQuery *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbDBQueryIteratorByDataDelete::match(CSysMdbDBQuery *pSysMdbDBQuery)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbDBQuery->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysNetAreaIteratorByAll> CSysNetAreaIteratorByAll::iteratorList;
void CSysNetAreaIteratorByAll::init(CSysNetAreaFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetAreaIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetAreaIteratorByAll *CSysNetAreaIteratorByAll::alloc(CSysNetAreaFactory *pFactory
		)
{
	CSysNetAreaIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetAreaIteratorByAll::~CSysNetAreaIteratorByAll(void)
{
}

void CSysNetAreaIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetAreaIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetAreaIteratorByAll");
	
	
}

void CSysNetAreaIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetAreaIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetArea *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetAreaIteratorByAll::UpdateCurrent(CWriteableSysNetArea * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetArea *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetArea;
#endif

CSysNetArea *CSysNetAreaIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetArea++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetArea *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetArea *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetAreaIteratorByAll::match(CSysNetArea *pSysNetArea)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetSubAreaIteratorByAll> CSysNetSubAreaIteratorByAll::iteratorList;
void CSysNetSubAreaIteratorByAll::init(CSysNetSubAreaFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetSubAreaIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetSubAreaIteratorByAll *CSysNetSubAreaIteratorByAll::alloc(CSysNetSubAreaFactory *pFactory
		)
{
	CSysNetSubAreaIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetSubAreaIteratorByAll::~CSysNetSubAreaIteratorByAll(void)
{
}

void CSysNetSubAreaIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetSubAreaIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetSubAreaIteratorByAll");
	
	
}

void CSysNetSubAreaIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetSubAreaIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetSubArea *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetSubAreaIteratorByAll::UpdateCurrent(CWriteableSysNetSubArea * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetSubArea *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetSubArea;
#endif

CSysNetSubArea *CSysNetSubAreaIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetSubArea++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetSubArea *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetSubArea *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetSubAreaIteratorByAll::match(CSysNetSubArea *pSysNetSubArea)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetSubAreaIPIteratorByAll> CSysNetSubAreaIPIteratorByAll::iteratorList;
void CSysNetSubAreaIPIteratorByAll::init(CSysNetSubAreaIPFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetSubAreaIPIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetSubAreaIPIteratorByAll *CSysNetSubAreaIPIteratorByAll::alloc(CSysNetSubAreaIPFactory *pFactory
		)
{
	CSysNetSubAreaIPIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetSubAreaIPIteratorByAll::~CSysNetSubAreaIPIteratorByAll(void)
{
}

void CSysNetSubAreaIPIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetSubAreaIPIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetSubAreaIPIteratorByAll");
	
	
}

void CSysNetSubAreaIPIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetSubAreaIPIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetSubAreaIP *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetSubAreaIPIteratorByAll::UpdateCurrent(CWriteableSysNetSubAreaIP * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetSubAreaIP *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetSubAreaIP;
#endif

CSysNetSubAreaIP *CSysNetSubAreaIPIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetSubAreaIP++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetSubAreaIP *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetSubAreaIP *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetSubAreaIPIteratorByAll::match(CSysNetSubAreaIP *pSysNetSubAreaIP)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetFuncAreaIteratorByAll> CSysNetFuncAreaIteratorByAll::iteratorList;
void CSysNetFuncAreaIteratorByAll::init(CSysNetFuncAreaFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetFuncAreaIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetFuncAreaIteratorByAll *CSysNetFuncAreaIteratorByAll::alloc(CSysNetFuncAreaFactory *pFactory
		)
{
	CSysNetFuncAreaIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetFuncAreaIteratorByAll::~CSysNetFuncAreaIteratorByAll(void)
{
}

void CSysNetFuncAreaIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetFuncAreaIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetFuncAreaIteratorByAll");
	
	
}

void CSysNetFuncAreaIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetFuncAreaIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetFuncArea *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetFuncAreaIteratorByAll::UpdateCurrent(CWriteableSysNetFuncArea * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetFuncArea *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetFuncArea;
#endif

CSysNetFuncArea *CSysNetFuncAreaIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetFuncArea++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetFuncArea *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetFuncArea *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetFuncAreaIteratorByAll::match(CSysNetFuncArea *pSysNetFuncArea)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetDeviceIteratorByAll> CSysNetDeviceIteratorByAll::iteratorList;
void CSysNetDeviceIteratorByAll::init(CSysNetDeviceFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetDeviceIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetDeviceIteratorByAll *CSysNetDeviceIteratorByAll::alloc(CSysNetDeviceFactory *pFactory
		)
{
	CSysNetDeviceIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetDeviceIteratorByAll::~CSysNetDeviceIteratorByAll(void)
{
}

void CSysNetDeviceIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetDeviceIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetDeviceIteratorByAll");
	
	
}

void CSysNetDeviceIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetDeviceIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetDevice *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetDeviceIteratorByAll::UpdateCurrent(CWriteableSysNetDevice * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetDevice *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetDevice;
#endif

CSysNetDevice *CSysNetDeviceIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDevice++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetDevice *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetDevice *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetDeviceIteratorByAll::match(CSysNetDevice *pSysNetDevice)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysNetDeviceIteratorByIPDECODE> CSysNetDeviceIteratorByIPDECODE::iteratorList;
void CSysNetDeviceIteratorByIPDECODE::init(CSysNetDeviceFactory *pFactory
		, const CReadOnlyVolumeType& IPDECODE)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetDeviceIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.IPDECODE=IPDECODE.getValue();

}

CSysNetDeviceIteratorByIPDECODE *CSysNetDeviceIteratorByIPDECODE::alloc(CSysNetDeviceFactory *pFactory
		, const CReadOnlyVolumeType& IPDECODE)
{
	CSysNetDeviceIteratorByIPDECODE *it;
	it=iteratorList.alloc();
	it->init(pFactory,IPDECODE);
	return it;
}

CSysNetDeviceIteratorByIPDECODE::~CSysNetDeviceIteratorByIPDECODE(void)
{
}

void CSysNetDeviceIteratorByIPDECODE::free(void)
{
	iteratorList.free(this);
}

void CSysNetDeviceIteratorByIPDECODE::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetDeviceIteratorByIPDECODE");
	
	char buffer[200];
	
	m_compareObject.IPDECODE.getString(buffer);
	pLogger->output(indent+1,0,"query IPDECODE=%s",buffer);
	
}

void CSysNetDeviceIteratorByIPDECODE::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIPDECODETypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIPDECODETypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetDeviceIteratorByIPDECODE::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetDevice *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetDeviceIteratorByIPDECODE::UpdateCurrent(CWriteableSysNetDevice * pByIPDECODE,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetDevice *)(m_pCurrent->pObject),pByIPDECODE,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByIPDECODEForSysNetDevice;
#endif

CSysNetDevice *CSysNetDeviceIteratorByIPDECODE::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByIPDECODEForSysNetDevice++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetDevice *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetDevice *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetDeviceIteratorByIPDECODE::match(CSysNetDevice *pSysNetDevice)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysNetDevice->IPDECODE.getValue(),m_compareObject.IPDECODE.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysNetDeviceIteratorBySubAreaID> CSysNetDeviceIteratorBySubAreaID::iteratorList;
void CSysNetDeviceIteratorBySubAreaID::init(CSysNetDeviceFactory *pFactory
		, const CReadOnlyVolumeType& SysNetSubAreaID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetDeviceIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SysNetSubAreaID=SysNetSubAreaID.getValue();

}

CSysNetDeviceIteratorBySubAreaID *CSysNetDeviceIteratorBySubAreaID::alloc(CSysNetDeviceFactory *pFactory
		, const CReadOnlyVolumeType& SysNetSubAreaID)
{
	CSysNetDeviceIteratorBySubAreaID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SysNetSubAreaID);
	return it;
}

CSysNetDeviceIteratorBySubAreaID::~CSysNetDeviceIteratorBySubAreaID(void)
{
}

void CSysNetDeviceIteratorBySubAreaID::free(void)
{
	iteratorList.free(this);
}

void CSysNetDeviceIteratorBySubAreaID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetDeviceIteratorBySubAreaID");
	
	char buffer[200];
	
	m_compareObject.SysNetSubAreaID.getString(buffer);
	pLogger->output(indent+1,0,"query SysNetSubAreaID=%s",buffer);
	
}

void CSysNetDeviceIteratorBySubAreaID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysSubAreaIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysSubAreaIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetDeviceIteratorBySubAreaID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetDevice *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetDeviceIteratorBySubAreaID::UpdateCurrent(CWriteableSysNetDevice * pBySubAreaID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetDevice *)(m_pCurrent->pObject),pBySubAreaID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySubAreaIDForSysNetDevice;
#endif

CSysNetDevice *CSysNetDeviceIteratorBySubAreaID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBySubAreaIDForSysNetDevice++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetDevice *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetDevice *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetDeviceIteratorBySubAreaID::match(CSysNetDevice *pSysNetDevice)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysNetDevice->SysNetSubAreaID.getValue(),m_compareObject.SysNetSubAreaID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysNetDeviceLinkedIteratorByAll> CSysNetDeviceLinkedIteratorByAll::iteratorList;
void CSysNetDeviceLinkedIteratorByAll::init(CSysNetDeviceLinkedFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetDeviceLinkedIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetDeviceLinkedIteratorByAll *CSysNetDeviceLinkedIteratorByAll::alloc(CSysNetDeviceLinkedFactory *pFactory
		)
{
	CSysNetDeviceLinkedIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetDeviceLinkedIteratorByAll::~CSysNetDeviceLinkedIteratorByAll(void)
{
}

void CSysNetDeviceLinkedIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetDeviceLinkedIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetDeviceLinkedIteratorByAll");
	
	
}

void CSysNetDeviceLinkedIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetDeviceLinkedIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetDeviceLinked *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetDeviceLinkedIteratorByAll::UpdateCurrent(CWriteableSysNetDeviceLinked * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetDeviceLinked *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetDeviceLinked;
#endif

CSysNetDeviceLinked *CSysNetDeviceLinkedIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDeviceLinked++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetDeviceLinked *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetDeviceLinked *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetDeviceLinkedIteratorByAll::match(CSysNetDeviceLinked *pSysNetDeviceLinked)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysNetDeviceLinkedIteratorByNetObjectID> CSysNetDeviceLinkedIteratorByNetObjectID::iteratorList;
void CSysNetDeviceLinkedIteratorByNetObjectID::init(CSysNetDeviceLinkedFactory *pFactory
		, const CReadOnlyNetObjectIDType& NetObjectID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetDeviceLinkedIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.NetObjectID=NetObjectID.getValue();

}

CSysNetDeviceLinkedIteratorByNetObjectID *CSysNetDeviceLinkedIteratorByNetObjectID::alloc(CSysNetDeviceLinkedFactory *pFactory
		, const CReadOnlyNetObjectIDType& NetObjectID)
{
	CSysNetDeviceLinkedIteratorByNetObjectID *it;
	it=iteratorList.alloc();
	it->init(pFactory,NetObjectID);
	return it;
}

CSysNetDeviceLinkedIteratorByNetObjectID::~CSysNetDeviceLinkedIteratorByNetObjectID(void)
{
}

void CSysNetDeviceLinkedIteratorByNetObjectID::free(void)
{
	iteratorList.free(this);
}

void CSysNetDeviceLinkedIteratorByNetObjectID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetDeviceLinkedIteratorByNetObjectID");
	
	char buffer[200];
	
	m_compareObject.NetObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query NetObjectID=%s",buffer);
	
}

void CSysNetDeviceLinkedIteratorByNetObjectID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysNetObjectIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysNetObjectIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetDeviceLinkedIteratorByNetObjectID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetDeviceLinked *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetDeviceLinkedIteratorByNetObjectID::UpdateCurrent(CWriteableSysNetDeviceLinked * pByNetObjectID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetDeviceLinked *)(m_pCurrent->pObject),pByNetObjectID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByNetObjectIDForSysNetDeviceLinked;
#endif

CSysNetDeviceLinked *CSysNetDeviceLinkedIteratorByNetObjectID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByNetObjectIDForSysNetDeviceLinked++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetDeviceLinked *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetDeviceLinked *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetDeviceLinkedIteratorByNetObjectID::match(CSysNetDeviceLinked *pSysNetDeviceLinked)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysNetDeviceLinked->NetObjectID.getValue(),m_compareObject.NetObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysNetDeviceLinkedIteratorByLinkNetObjectID> CSysNetDeviceLinkedIteratorByLinkNetObjectID::iteratorList;
void CSysNetDeviceLinkedIteratorByLinkNetObjectID::init(CSysNetDeviceLinkedFactory *pFactory
		, const CReadOnlyNetObjectIDType& LinkNetObjectID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetDeviceLinkedIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.LinkNetObjectID=LinkNetObjectID.getValue();

}

CSysNetDeviceLinkedIteratorByLinkNetObjectID *CSysNetDeviceLinkedIteratorByLinkNetObjectID::alloc(CSysNetDeviceLinkedFactory *pFactory
		, const CReadOnlyNetObjectIDType& LinkNetObjectID)
{
	CSysNetDeviceLinkedIteratorByLinkNetObjectID *it;
	it=iteratorList.alloc();
	it->init(pFactory,LinkNetObjectID);
	return it;
}

CSysNetDeviceLinkedIteratorByLinkNetObjectID::~CSysNetDeviceLinkedIteratorByLinkNetObjectID(void)
{
}

void CSysNetDeviceLinkedIteratorByLinkNetObjectID::free(void)
{
	iteratorList.free(this);
}

void CSysNetDeviceLinkedIteratorByLinkNetObjectID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetDeviceLinkedIteratorByLinkNetObjectID");
	
	char buffer[200];
	
	m_compareObject.LinkNetObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query LinkNetObjectID=%s",buffer);
	
}

void CSysNetDeviceLinkedIteratorByLinkNetObjectID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysLinkObjectIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysLinkObjectIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetDeviceLinkedIteratorByLinkNetObjectID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetDeviceLinked *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetDeviceLinkedIteratorByLinkNetObjectID::UpdateCurrent(CWriteableSysNetDeviceLinked * pByLinkNetObjectID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetDeviceLinked *)(m_pCurrent->pObject),pByLinkNetObjectID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByLinkNetObjectIDForSysNetDeviceLinked;
#endif

CSysNetDeviceLinked *CSysNetDeviceLinkedIteratorByLinkNetObjectID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByLinkNetObjectIDForSysNetDeviceLinked++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetDeviceLinked *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetDeviceLinked *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetDeviceLinkedIteratorByLinkNetObjectID::match(CSysNetDeviceLinked *pSysNetDeviceLinked)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysNetDeviceLinked->LinkNetObjectID.getValue(),m_compareObject.LinkNetObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysNetOIDIteratorByAll> CSysNetOIDIteratorByAll::iteratorList;
void CSysNetOIDIteratorByAll::init(CSysNetOIDFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetOIDIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetOIDIteratorByAll *CSysNetOIDIteratorByAll::alloc(CSysNetOIDFactory *pFactory
		)
{
	CSysNetOIDIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetOIDIteratorByAll::~CSysNetOIDIteratorByAll(void)
{
}

void CSysNetOIDIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetOIDIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetOIDIteratorByAll");
	
	
}

void CSysNetOIDIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetOIDIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetOID *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetOIDIteratorByAll::UpdateCurrent(CWriteableSysNetOID * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetOID *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetOID;
#endif

CSysNetOID *CSysNetOIDIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetOID++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetOID *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetOID *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetOIDIteratorByAll::match(CSysNetOID *pSysNetOID)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetDeviceTypeIteratorByAll> CSysNetDeviceTypeIteratorByAll::iteratorList;
void CSysNetDeviceTypeIteratorByAll::init(CSysNetDeviceTypeFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetDeviceTypeIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetDeviceTypeIteratorByAll *CSysNetDeviceTypeIteratorByAll::alloc(CSysNetDeviceTypeFactory *pFactory
		)
{
	CSysNetDeviceTypeIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetDeviceTypeIteratorByAll::~CSysNetDeviceTypeIteratorByAll(void)
{
}

void CSysNetDeviceTypeIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetDeviceTypeIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetDeviceTypeIteratorByAll");
	
	
}

void CSysNetDeviceTypeIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetDeviceTypeIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetDeviceType *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetDeviceTypeIteratorByAll::UpdateCurrent(CWriteableSysNetDeviceType * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetDeviceType *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetDeviceType;
#endif

CSysNetDeviceType *CSysNetDeviceTypeIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDeviceType++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetDeviceType *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetDeviceType *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetDeviceTypeIteratorByAll::match(CSysNetDeviceType *pSysNetDeviceType)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetTimePolicyIteratorByAll> CSysNetTimePolicyIteratorByAll::iteratorList;
void CSysNetTimePolicyIteratorByAll::init(CSysNetTimePolicyFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetTimePolicyIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetTimePolicyIteratorByAll *CSysNetTimePolicyIteratorByAll::alloc(CSysNetTimePolicyFactory *pFactory
		)
{
	CSysNetTimePolicyIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetTimePolicyIteratorByAll::~CSysNetTimePolicyIteratorByAll(void)
{
}

void CSysNetTimePolicyIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetTimePolicyIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetTimePolicyIteratorByAll");
	
	
}

void CSysNetTimePolicyIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetTimePolicyIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetTimePolicy *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetTimePolicyIteratorByAll::UpdateCurrent(CWriteableSysNetTimePolicy * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetTimePolicy *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetTimePolicy;
#endif

CSysNetTimePolicy *CSysNetTimePolicyIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetTimePolicy++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetTimePolicy *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetTimePolicy *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetTimePolicyIteratorByAll::match(CSysNetTimePolicy *pSysNetTimePolicy)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetGatherTaskIteratorByAll> CSysNetGatherTaskIteratorByAll::iteratorList;
void CSysNetGatherTaskIteratorByAll::init(CSysNetGatherTaskFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetGatherTaskIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetGatherTaskIteratorByAll *CSysNetGatherTaskIteratorByAll::alloc(CSysNetGatherTaskFactory *pFactory
		)
{
	CSysNetGatherTaskIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetGatherTaskIteratorByAll::~CSysNetGatherTaskIteratorByAll(void)
{
}

void CSysNetGatherTaskIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetGatherTaskIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetGatherTaskIteratorByAll");
	
	
}

void CSysNetGatherTaskIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetGatherTaskIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetGatherTask *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetGatherTaskIteratorByAll::UpdateCurrent(CWriteableSysNetGatherTask * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetGatherTask *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetGatherTask;
#endif

CSysNetGatherTask *CSysNetGatherTaskIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetGatherTask++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetGatherTask *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetGatherTask *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetGatherTaskIteratorByAll::match(CSysNetGatherTask *pSysNetGatherTask)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysNetGatherTaskIteratorByNetObjectID> CSysNetGatherTaskIteratorByNetObjectID::iteratorList;
void CSysNetGatherTaskIteratorByNetObjectID::init(CSysNetGatherTaskFactory *pFactory
		, const CReadOnlyNetObjectIDType& ObjectID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetGatherTaskIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();

}

CSysNetGatherTaskIteratorByNetObjectID *CSysNetGatherTaskIteratorByNetObjectID::alloc(CSysNetGatherTaskFactory *pFactory
		, const CReadOnlyNetObjectIDType& ObjectID)
{
	CSysNetGatherTaskIteratorByNetObjectID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID);
	return it;
}

CSysNetGatherTaskIteratorByNetObjectID::~CSysNetGatherTaskIteratorByNetObjectID(void)
{
}

void CSysNetGatherTaskIteratorByNetObjectID::free(void)
{
	iteratorList.free(this);
}

void CSysNetGatherTaskIteratorByNetObjectID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetGatherTaskIteratorByNetObjectID");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
}

void CSysNetGatherTaskIteratorByNetObjectID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysNetObjectIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysNetObjectIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetGatherTaskIteratorByNetObjectID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetGatherTask *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetGatherTaskIteratorByNetObjectID::UpdateCurrent(CWriteableSysNetGatherTask * pByNetObjectID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetGatherTask *)(m_pCurrent->pObject),pByNetObjectID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByNetObjectIDForSysNetGatherTask;
#endif

CSysNetGatherTask *CSysNetGatherTaskIteratorByNetObjectID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByNetObjectIDForSysNetGatherTask++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetGatherTask *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetGatherTask *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetGatherTaskIteratorByNetObjectID::match(CSysNetGatherTask *pSysNetGatherTask)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysNetGatherTask->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysNetDeviceCategoryIteratorByAll> CSysNetDeviceCategoryIteratorByAll::iteratorList;
void CSysNetDeviceCategoryIteratorByAll::init(CSysNetDeviceCategoryFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetDeviceCategoryIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetDeviceCategoryIteratorByAll *CSysNetDeviceCategoryIteratorByAll::alloc(CSysNetDeviceCategoryFactory *pFactory
		)
{
	CSysNetDeviceCategoryIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetDeviceCategoryIteratorByAll::~CSysNetDeviceCategoryIteratorByAll(void)
{
}

void CSysNetDeviceCategoryIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetDeviceCategoryIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetDeviceCategoryIteratorByAll");
	
	
}

void CSysNetDeviceCategoryIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetDeviceCategoryIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetDeviceCategory *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetDeviceCategoryIteratorByAll::UpdateCurrent(CWriteableSysNetDeviceCategory * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetDeviceCategory *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetDeviceCategory;
#endif

CSysNetDeviceCategory *CSysNetDeviceCategoryIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDeviceCategory++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetDeviceCategory *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetDeviceCategory *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetDeviceCategoryIteratorByAll::match(CSysNetDeviceCategory *pSysNetDeviceCategory)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetManufactoryIteratorByAll> CSysNetManufactoryIteratorByAll::iteratorList;
void CSysNetManufactoryIteratorByAll::init(CSysNetManufactoryFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetManufactoryIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetManufactoryIteratorByAll *CSysNetManufactoryIteratorByAll::alloc(CSysNetManufactoryFactory *pFactory
		)
{
	CSysNetManufactoryIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetManufactoryIteratorByAll::~CSysNetManufactoryIteratorByAll(void)
{
}

void CSysNetManufactoryIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetManufactoryIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetManufactoryIteratorByAll");
	
	
}

void CSysNetManufactoryIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetManufactoryIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetManufactory *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetManufactoryIteratorByAll::UpdateCurrent(CWriteableSysNetManufactory * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetManufactory *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetManufactory;
#endif

CSysNetManufactory *CSysNetManufactoryIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetManufactory++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetManufactory *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetManufactory *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetManufactoryIteratorByAll::match(CSysNetManufactory *pSysNetManufactory)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetCommunityIteratorByAll> CSysNetCommunityIteratorByAll::iteratorList;
void CSysNetCommunityIteratorByAll::init(CSysNetCommunityFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetCommunityIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetCommunityIteratorByAll *CSysNetCommunityIteratorByAll::alloc(CSysNetCommunityFactory *pFactory
		)
{
	CSysNetCommunityIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetCommunityIteratorByAll::~CSysNetCommunityIteratorByAll(void)
{
}

void CSysNetCommunityIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetCommunityIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetCommunityIteratorByAll");
	
	
}

void CSysNetCommunityIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetCommunityIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetCommunity *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetCommunityIteratorByAll::UpdateCurrent(CWriteableSysNetCommunity * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetCommunity *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetCommunity;
#endif

CSysNetCommunity *CSysNetCommunityIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetCommunity++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetCommunity *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetCommunity *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetCommunityIteratorByAll::match(CSysNetCommunity *pSysNetCommunity)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetPortTypeIteratorByAll> CSysNetPortTypeIteratorByAll::iteratorList;
void CSysNetPortTypeIteratorByAll::init(CSysNetPortTypeFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetPortTypeIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetPortTypeIteratorByAll *CSysNetPortTypeIteratorByAll::alloc(CSysNetPortTypeFactory *pFactory
		)
{
	CSysNetPortTypeIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetPortTypeIteratorByAll::~CSysNetPortTypeIteratorByAll(void)
{
}

void CSysNetPortTypeIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetPortTypeIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetPortTypeIteratorByAll");
	
	
}

void CSysNetPortTypeIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetPortTypeIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetPortType *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetPortTypeIteratorByAll::UpdateCurrent(CWriteableSysNetPortType * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetPortType *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetPortType;
#endif

CSysNetPortType *CSysNetPortTypeIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPortType++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetPortType *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetPortType *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetPortTypeIteratorByAll::match(CSysNetPortType *pSysNetPortType)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetInterfaceIteratorByAll> CSysNetInterfaceIteratorByAll::iteratorList;
void CSysNetInterfaceIteratorByAll::init(CSysNetInterfaceFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetInterfaceIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetInterfaceIteratorByAll *CSysNetInterfaceIteratorByAll::alloc(CSysNetInterfaceFactory *pFactory
		)
{
	CSysNetInterfaceIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetInterfaceIteratorByAll::~CSysNetInterfaceIteratorByAll(void)
{
}

void CSysNetInterfaceIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetInterfaceIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetInterfaceIteratorByAll");
	
	
}

void CSysNetInterfaceIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetInterfaceIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetInterface *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetInterfaceIteratorByAll::UpdateCurrent(CWriteableSysNetInterface * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetInterface *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetInterface;
#endif

CSysNetInterface *CSysNetInterfaceIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetInterface++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetInterface *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetInterface *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetInterfaceIteratorByAll::match(CSysNetInterface *pSysNetInterface)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysNetInterfaceIteratorByDeviceID> CSysNetInterfaceIteratorByDeviceID::iteratorList;
void CSysNetInterfaceIteratorByDeviceID::init(CSysNetInterfaceFactory *pFactory
		, const CReadOnlyVolumeType& DeviceID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetInterfaceIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.DeviceID=DeviceID.getValue();

}

CSysNetInterfaceIteratorByDeviceID *CSysNetInterfaceIteratorByDeviceID::alloc(CSysNetInterfaceFactory *pFactory
		, const CReadOnlyVolumeType& DeviceID)
{
	CSysNetInterfaceIteratorByDeviceID *it;
	it=iteratorList.alloc();
	it->init(pFactory,DeviceID);
	return it;
}

CSysNetInterfaceIteratorByDeviceID::~CSysNetInterfaceIteratorByDeviceID(void)
{
}

void CSysNetInterfaceIteratorByDeviceID::free(void)
{
	iteratorList.free(this);
}

void CSysNetInterfaceIteratorByDeviceID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetInterfaceIteratorByDeviceID");
	
	char buffer[200];
	
	m_compareObject.DeviceID.getString(buffer);
	pLogger->output(indent+1,0,"query DeviceID=%s",buffer);
	
}

void CSysNetInterfaceIteratorByDeviceID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysDeviceIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysDeviceIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetInterfaceIteratorByDeviceID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetInterface *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetInterfaceIteratorByDeviceID::UpdateCurrent(CWriteableSysNetInterface * pByDeviceID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetInterface *)(m_pCurrent->pObject),pByDeviceID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDeviceIDForSysNetInterface;
#endif

CSysNetInterface *CSysNetInterfaceIteratorByDeviceID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDeviceIDForSysNetInterface++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetInterface *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetInterface *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetInterfaceIteratorByDeviceID::match(CSysNetInterface *pSysNetInterface)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysNetInterface->DeviceID.getValue(),m_compareObject.DeviceID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysNetGeneralOIDIteratorByAll> CSysNetGeneralOIDIteratorByAll::iteratorList;
void CSysNetGeneralOIDIteratorByAll::init(CSysNetGeneralOIDFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetGeneralOIDIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetGeneralOIDIteratorByAll *CSysNetGeneralOIDIteratorByAll::alloc(CSysNetGeneralOIDFactory *pFactory
		)
{
	CSysNetGeneralOIDIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetGeneralOIDIteratorByAll::~CSysNetGeneralOIDIteratorByAll(void)
{
}

void CSysNetGeneralOIDIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetGeneralOIDIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetGeneralOIDIteratorByAll");
	
	
}

void CSysNetGeneralOIDIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetGeneralOIDIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetGeneralOID *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetGeneralOIDIteratorByAll::UpdateCurrent(CWriteableSysNetGeneralOID * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetGeneralOID *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetGeneralOID;
#endif

CSysNetGeneralOID *CSysNetGeneralOIDIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetGeneralOID++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetGeneralOID *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetGeneralOID *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetGeneralOIDIteratorByAll::match(CSysNetGeneralOID *pSysNetGeneralOID)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetMonitorTypeIteratorByAll> CSysNetMonitorTypeIteratorByAll::iteratorList;
void CSysNetMonitorTypeIteratorByAll::init(CSysNetMonitorTypeFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorTypeIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetMonitorTypeIteratorByAll *CSysNetMonitorTypeIteratorByAll::alloc(CSysNetMonitorTypeFactory *pFactory
		)
{
	CSysNetMonitorTypeIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetMonitorTypeIteratorByAll::~CSysNetMonitorTypeIteratorByAll(void)
{
}

void CSysNetMonitorTypeIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorTypeIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorTypeIteratorByAll");
	
	
}

void CSysNetMonitorTypeIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorTypeIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorType *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorTypeIteratorByAll::UpdateCurrent(CWriteableSysNetMonitorType * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorType *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetMonitorType;
#endif

CSysNetMonitorType *CSysNetMonitorTypeIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorType++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorType *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorType *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorTypeIteratorByAll::match(CSysNetMonitorType *pSysNetMonitorType)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetMonitorAttrScopeIteratorByAll> CSysNetMonitorAttrScopeIteratorByAll::iteratorList;
void CSysNetMonitorAttrScopeIteratorByAll::init(CSysNetMonitorAttrScopeFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorAttrScopeIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetMonitorAttrScopeIteratorByAll *CSysNetMonitorAttrScopeIteratorByAll::alloc(CSysNetMonitorAttrScopeFactory *pFactory
		)
{
	CSysNetMonitorAttrScopeIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetMonitorAttrScopeIteratorByAll::~CSysNetMonitorAttrScopeIteratorByAll(void)
{
}

void CSysNetMonitorAttrScopeIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorAttrScopeIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorAttrScopeIteratorByAll");
	
	
}

void CSysNetMonitorAttrScopeIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorAttrScopeIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorAttrScope *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorAttrScopeIteratorByAll::UpdateCurrent(CWriteableSysNetMonitorAttrScope * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorAttrScope *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetMonitorAttrScope;
#endif

CSysNetMonitorAttrScope *CSysNetMonitorAttrScopeIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorAttrScope++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorAttrScope *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorAttrScope *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorAttrScopeIteratorByAll::match(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetMonitorAttrTypeIteratorByAll> CSysNetMonitorAttrTypeIteratorByAll::iteratorList;
void CSysNetMonitorAttrTypeIteratorByAll::init(CSysNetMonitorAttrTypeFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorAttrTypeIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetMonitorAttrTypeIteratorByAll *CSysNetMonitorAttrTypeIteratorByAll::alloc(CSysNetMonitorAttrTypeFactory *pFactory
		)
{
	CSysNetMonitorAttrTypeIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetMonitorAttrTypeIteratorByAll::~CSysNetMonitorAttrTypeIteratorByAll(void)
{
}

void CSysNetMonitorAttrTypeIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorAttrTypeIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorAttrTypeIteratorByAll");
	
	
}

void CSysNetMonitorAttrTypeIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorAttrTypeIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorAttrType *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorAttrTypeIteratorByAll::UpdateCurrent(CWriteableSysNetMonitorAttrType * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorAttrType *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetMonitorAttrType;
#endif

CSysNetMonitorAttrType *CSysNetMonitorAttrTypeIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorAttrType++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorAttrType *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorAttrType *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorAttrTypeIteratorByAll::match(CSysNetMonitorAttrType *pSysNetMonitorAttrType)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetMonitorCommandTypeIteratorByAll> CSysNetMonitorCommandTypeIteratorByAll::iteratorList;
void CSysNetMonitorCommandTypeIteratorByAll::init(CSysNetMonitorCommandTypeFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorCommandTypeIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetMonitorCommandTypeIteratorByAll *CSysNetMonitorCommandTypeIteratorByAll::alloc(CSysNetMonitorCommandTypeFactory *pFactory
		)
{
	CSysNetMonitorCommandTypeIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetMonitorCommandTypeIteratorByAll::~CSysNetMonitorCommandTypeIteratorByAll(void)
{
}

void CSysNetMonitorCommandTypeIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorCommandTypeIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorCommandTypeIteratorByAll");
	
	
}

void CSysNetMonitorCommandTypeIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorCommandTypeIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorCommandType *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorCommandTypeIteratorByAll::UpdateCurrent(CWriteableSysNetMonitorCommandType * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorCommandType *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetMonitorCommandType;
#endif

CSysNetMonitorCommandType *CSysNetMonitorCommandTypeIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorCommandType++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorCommandType *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorCommandType *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorCommandTypeIteratorByAll::match(CSysNetMonitorCommandType *pSysNetMonitorCommandType)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetMonitorActionGroupIteratorByAll> CSysNetMonitorActionGroupIteratorByAll::iteratorList;
void CSysNetMonitorActionGroupIteratorByAll::init(CSysNetMonitorActionGroupFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorActionGroupIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetMonitorActionGroupIteratorByAll *CSysNetMonitorActionGroupIteratorByAll::alloc(CSysNetMonitorActionGroupFactory *pFactory
		)
{
	CSysNetMonitorActionGroupIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetMonitorActionGroupIteratorByAll::~CSysNetMonitorActionGroupIteratorByAll(void)
{
}

void CSysNetMonitorActionGroupIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorActionGroupIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorActionGroupIteratorByAll");
	
	
}

void CSysNetMonitorActionGroupIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorActionGroupIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorActionGroup *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorActionGroupIteratorByAll::UpdateCurrent(CWriteableSysNetMonitorActionGroup * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorActionGroup *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetMonitorActionGroup;
#endif

CSysNetMonitorActionGroup *CSysNetMonitorActionGroupIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorActionGroup++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorActionGroup *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorActionGroup *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorActionGroupIteratorByAll::match(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetMonitorDeviceGroupIteratorByAll> CSysNetMonitorDeviceGroupIteratorByAll::iteratorList;
void CSysNetMonitorDeviceGroupIteratorByAll::init(CSysNetMonitorDeviceGroupFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorDeviceGroupIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetMonitorDeviceGroupIteratorByAll *CSysNetMonitorDeviceGroupIteratorByAll::alloc(CSysNetMonitorDeviceGroupFactory *pFactory
		)
{
	CSysNetMonitorDeviceGroupIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetMonitorDeviceGroupIteratorByAll::~CSysNetMonitorDeviceGroupIteratorByAll(void)
{
}

void CSysNetMonitorDeviceGroupIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorDeviceGroupIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorDeviceGroupIteratorByAll");
	
	
}

void CSysNetMonitorDeviceGroupIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorDeviceGroupIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorDeviceGroup *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorDeviceGroupIteratorByAll::UpdateCurrent(CWriteableSysNetMonitorDeviceGroup * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorDeviceGroup *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetMonitorDeviceGroup;
#endif

CSysNetMonitorDeviceGroup *CSysNetMonitorDeviceGroupIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorDeviceGroup++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorDeviceGroup *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorDeviceGroup *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorDeviceGroupIteratorByAll::match(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetMonitorTaskInfoIteratorByAll> CSysNetMonitorTaskInfoIteratorByAll::iteratorList;
void CSysNetMonitorTaskInfoIteratorByAll::init(CSysNetMonitorTaskInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorTaskInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetMonitorTaskInfoIteratorByAll *CSysNetMonitorTaskInfoIteratorByAll::alloc(CSysNetMonitorTaskInfoFactory *pFactory
		)
{
	CSysNetMonitorTaskInfoIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetMonitorTaskInfoIteratorByAll::~CSysNetMonitorTaskInfoIteratorByAll(void)
{
}

void CSysNetMonitorTaskInfoIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorTaskInfoIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorTaskInfoIteratorByAll");
	
	
}

void CSysNetMonitorTaskInfoIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorTaskInfoIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorTaskInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorTaskInfoIteratorByAll::UpdateCurrent(CWriteableSysNetMonitorTaskInfo * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorTaskInfo *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetMonitorTaskInfo;
#endif

CSysNetMonitorTaskInfo *CSysNetMonitorTaskInfoIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorTaskInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorTaskInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorTaskInfoIteratorByAll::match(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetMonitorTaskObjectSetIteratorByAll> CSysNetMonitorTaskObjectSetIteratorByAll::iteratorList;
void CSysNetMonitorTaskObjectSetIteratorByAll::init(CSysNetMonitorTaskObjectSetFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorTaskObjectSetIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.DeviceGroup_ID=0;

}

CSysNetMonitorTaskObjectSetIteratorByAll *CSysNetMonitorTaskObjectSetIteratorByAll::alloc(CSysNetMonitorTaskObjectSetFactory *pFactory
		)
{
	CSysNetMonitorTaskObjectSetIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetMonitorTaskObjectSetIteratorByAll::~CSysNetMonitorTaskObjectSetIteratorByAll(void)
{
}

void CSysNetMonitorTaskObjectSetIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorTaskObjectSetIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorTaskObjectSetIteratorByAll");
	
	
}

void CSysNetMonitorTaskObjectSetIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorTaskObjectSetIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorTaskObjectSet *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorTaskObjectSetIteratorByAll::UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorTaskObjectSet *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetMonitorTaskObjectSet;
#endif

CSysNetMonitorTaskObjectSet *CSysNetMonitorTaskObjectSetIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskObjectSet++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorTaskObjectSet *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorTaskObjectSet *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorTaskObjectSetIteratorByAll::match(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID> CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID::iteratorList;
void CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID::init(CSysNetMonitorTaskObjectSetFactory *pFactory
		, const CReadOnlyVolumeType& DeviceGroup_ID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorTaskObjectSetIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.DeviceGroup_ID=DeviceGroup_ID.getValue();

}

CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID *CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID::alloc(CSysNetMonitorTaskObjectSetFactory *pFactory
		, const CReadOnlyVolumeType& DeviceGroup_ID)
{
	CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID *it;
	it=iteratorList.alloc();
	it->init(pFactory,DeviceGroup_ID);
	return it;
}

CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID::~CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID(void)
{
}

void CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID");
	
	char buffer[200];
	
	m_compareObject.DeviceGroup_ID.getString(buffer);
	pLogger->output(indent+1,0,"query DeviceGroup_ID=%s",buffer);
	
}

void CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorTaskObjectSet *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID::UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pByDeviceGroup_ID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorTaskObjectSet *)(m_pCurrent->pObject),pByDeviceGroup_ID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDeviceGroup_IDForSysNetMonitorTaskObjectSet;
#endif

CSysNetMonitorTaskObjectSet *CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDeviceGroup_IDForSysNetMonitorTaskObjectSet++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorTaskObjectSet *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorTaskObjectSet *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID::match(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysNetMonitorTaskObjectSet->DeviceGroup_ID.getValue(),m_compareObject.DeviceGroup_ID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysNetMonitorTaskResultIteratorByAll> CSysNetMonitorTaskResultIteratorByAll::iteratorList;
void CSysNetMonitorTaskResultIteratorByAll::init(CSysNetMonitorTaskResultFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorTaskResultIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.Task_ID=-10;
	m_compareObject.ObjectID="";
	m_compareObject.OperateTime=0;

}

CSysNetMonitorTaskResultIteratorByAll *CSysNetMonitorTaskResultIteratorByAll::alloc(CSysNetMonitorTaskResultFactory *pFactory
		)
{
	CSysNetMonitorTaskResultIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetMonitorTaskResultIteratorByAll::~CSysNetMonitorTaskResultIteratorByAll(void)
{
}

void CSysNetMonitorTaskResultIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorTaskResultIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorTaskResultIteratorByAll");
	
	
}

void CSysNetMonitorTaskResultIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTaskIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTaskIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorTaskResultIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorTaskResult *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorTaskResultIteratorByAll::UpdateCurrent(CWriteableSysNetMonitorTaskResult * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorTaskResult *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetMonitorTaskResult;
#endif

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskResult++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorTaskResult *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorTaskResult *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorTaskResultIteratorByAll::match(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysNetMonitorTaskResultIteratorByTask_ID> CSysNetMonitorTaskResultIteratorByTask_ID::iteratorList;
void CSysNetMonitorTaskResultIteratorByTask_ID::init(CSysNetMonitorTaskResultFactory *pFactory
		, const CReadOnlyDateType& MonDate, const CReadOnlyVolumeType& Task_ID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorTaskResultIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.Task_ID=Task_ID.getValue();
	m_compareObject.ObjectID="";
	m_compareObject.OperateTime=0;

}

CSysNetMonitorTaskResultIteratorByTask_ID *CSysNetMonitorTaskResultIteratorByTask_ID::alloc(CSysNetMonitorTaskResultFactory *pFactory
		, const CReadOnlyDateType& MonDate, const CReadOnlyVolumeType& Task_ID)
{
	CSysNetMonitorTaskResultIteratorByTask_ID *it;
	it=iteratorList.alloc();
	it->init(pFactory,MonDate,Task_ID);
	return it;
}

CSysNetMonitorTaskResultIteratorByTask_ID::~CSysNetMonitorTaskResultIteratorByTask_ID(void)
{
}

void CSysNetMonitorTaskResultIteratorByTask_ID::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorTaskResultIteratorByTask_ID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorTaskResultIteratorByTask_ID");
	
	char buffer[200];
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.Task_ID.getString(buffer);
	pLogger->output(indent+1,0,"query Task_ID=%s",buffer);
	
}

void CSysNetMonitorTaskResultIteratorByTask_ID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTaskIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTaskIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorTaskResultIteratorByTask_ID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorTaskResult *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorTaskResultIteratorByTask_ID::UpdateCurrent(CWriteableSysNetMonitorTaskResult * pByTask_ID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorTaskResult *)(m_pCurrent->pObject),pByTask_ID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByTask_IDForSysNetMonitorTaskResult;
#endif

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultIteratorByTask_ID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByTask_IDForSysNetMonitorTaskResult++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorTaskResult *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorTaskResult *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorTaskResultIteratorByTask_ID::match(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysNetMonitorTaskResult->MonDate.getValue(),m_compareObject.MonDate.getValue())!=0)
	{
		return 0;
	}
	if (compare(pSysNetMonitorTaskResult->Task_ID.getValue(),m_compareObject.Task_ID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysNetMonitorTaskResultIteratorByOnlyDate> CSysNetMonitorTaskResultIteratorByOnlyDate::iteratorList;
void CSysNetMonitorTaskResultIteratorByOnlyDate::init(CSysNetMonitorTaskResultFactory *pFactory
		, const CReadOnlyDateType& MonDate)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorTaskResultIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.Task_ID=-10;
	m_compareObject.ObjectID="";
	m_compareObject.OperateTime=0;

}

CSysNetMonitorTaskResultIteratorByOnlyDate *CSysNetMonitorTaskResultIteratorByOnlyDate::alloc(CSysNetMonitorTaskResultFactory *pFactory
		, const CReadOnlyDateType& MonDate)
{
	CSysNetMonitorTaskResultIteratorByOnlyDate *it;
	it=iteratorList.alloc();
	it->init(pFactory,MonDate);
	return it;
}

CSysNetMonitorTaskResultIteratorByOnlyDate::~CSysNetMonitorTaskResultIteratorByOnlyDate(void)
{
}

void CSysNetMonitorTaskResultIteratorByOnlyDate::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorTaskResultIteratorByOnlyDate::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorTaskResultIteratorByOnlyDate");
	
	char buffer[200];
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
}

void CSysNetMonitorTaskResultIteratorByOnlyDate::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTaskIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTaskIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorTaskResultIteratorByOnlyDate::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorTaskResult *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorTaskResultIteratorByOnlyDate::UpdateCurrent(CWriteableSysNetMonitorTaskResult * pByOnlyDate,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorTaskResult *)(m_pCurrent->pObject),pByOnlyDate,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByOnlyDateForSysNetMonitorTaskResult;
#endif

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultIteratorByOnlyDate::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByOnlyDateForSysNetMonitorTaskResult++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorTaskResult *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorTaskResult *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorTaskResultIteratorByOnlyDate::match(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysNetMonitorTaskResult->MonDate.getValue(),m_compareObject.MonDate.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysNetMonitorTaskResultIteratorByIDTaskTime> CSysNetMonitorTaskResultIteratorByIDTaskTime::iteratorList;
void CSysNetMonitorTaskResultIteratorByIDTaskTime::init(CSysNetMonitorTaskResultFactory *pFactory
		, const CReadOnlyDateType& MonDate, const CReadOnlyVolumeType& Task_ID, const CReadOnlyNetObjectIDType& ObjectID, const CReadOnlyVolumeType& OperateTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorTaskResultIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.Task_ID=Task_ID.getValue();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.OperateTime=OperateTime.getValue();

}

CSysNetMonitorTaskResultIteratorByIDTaskTime *CSysNetMonitorTaskResultIteratorByIDTaskTime::alloc(CSysNetMonitorTaskResultFactory *pFactory
		, const CReadOnlyDateType& MonDate, const CReadOnlyVolumeType& Task_ID, const CReadOnlyNetObjectIDType& ObjectID, const CReadOnlyVolumeType& OperateTime)
{
	CSysNetMonitorTaskResultIteratorByIDTaskTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,MonDate,Task_ID,ObjectID,OperateTime);
	return it;
}

CSysNetMonitorTaskResultIteratorByIDTaskTime::~CSysNetMonitorTaskResultIteratorByIDTaskTime(void)
{
}

void CSysNetMonitorTaskResultIteratorByIDTaskTime::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorTaskResultIteratorByIDTaskTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorTaskResultIteratorByIDTaskTime");
	
	char buffer[200];
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.Task_ID.getString(buffer);
	pLogger->output(indent+1,0,"query Task_ID=%s",buffer);
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
	m_compareObject.OperateTime.getString(buffer);
	pLogger->output(indent+1,0,"query OperateTime=%s",buffer);
	
}

void CSysNetMonitorTaskResultIteratorByIDTaskTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTaskIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTaskIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorTaskResultIteratorByIDTaskTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorTaskResult *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorTaskResultIteratorByIDTaskTime::UpdateCurrent(CWriteableSysNetMonitorTaskResult * pByIDTaskTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorTaskResult *)(m_pCurrent->pObject),pByIDTaskTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByIDTaskTimeForSysNetMonitorTaskResult;
#endif

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultIteratorByIDTaskTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByIDTaskTimeForSysNetMonitorTaskResult++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorTaskResult *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorTaskResult *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorTaskResultIteratorByIDTaskTime::match(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysNetMonitorTaskResult->MonDate.getValue(),m_compareObject.MonDate.getValue())!=0)
	{
		return 0;
	}
	if (compare(pSysNetMonitorTaskResult->Task_ID.getValue(),m_compareObject.Task_ID.getValue())!=0)
	{
		return 0;
	}
	if (compare(pSysNetMonitorTaskResult->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	if (compare(pSysNetMonitorTaskResult->OperateTime.getValue(),m_compareObject.OperateTime.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysNetMonitorTaskResultIteratorByDataDelete> CSysNetMonitorTaskResultIteratorByDataDelete::iteratorList;
void CSysNetMonitorTaskResultIteratorByDataDelete::init(CSysNetMonitorTaskResultFactory *pFactory
		, const CReadOnlyDateType& MonDate, const CReadOnlyVolumeType& Task_ID, const CReadOnlyNetObjectIDType& ObjectID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorTaskResultIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.Task_ID=Task_ID.getValue();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.OperateTime=0;

}

CSysNetMonitorTaskResultIteratorByDataDelete *CSysNetMonitorTaskResultIteratorByDataDelete::alloc(CSysNetMonitorTaskResultFactory *pFactory
		, const CReadOnlyDateType& MonDate, const CReadOnlyVolumeType& Task_ID, const CReadOnlyNetObjectIDType& ObjectID)
{
	CSysNetMonitorTaskResultIteratorByDataDelete *it;
	it=iteratorList.alloc();
	it->init(pFactory,MonDate,Task_ID,ObjectID);
	return it;
}

CSysNetMonitorTaskResultIteratorByDataDelete::~CSysNetMonitorTaskResultIteratorByDataDelete(void)
{
}

void CSysNetMonitorTaskResultIteratorByDataDelete::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorTaskResultIteratorByDataDelete::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorTaskResultIteratorByDataDelete");
	
	char buffer[200];
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.Task_ID.getString(buffer);
	pLogger->output(indent+1,0,"query Task_ID=%s",buffer);
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
}

void CSysNetMonitorTaskResultIteratorByDataDelete::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTaskIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTaskIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorTaskResultIteratorByDataDelete::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorTaskResult *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorTaskResultIteratorByDataDelete::UpdateCurrent(CWriteableSysNetMonitorTaskResult * pByDataDelete,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorTaskResult *)(m_pCurrent->pObject),pByDataDelete,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDataDeleteForSysNetMonitorTaskResult;
#endif

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultIteratorByDataDelete::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysNetMonitorTaskResult++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorTaskResult *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorTaskResult *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorTaskResultIteratorByDataDelete::match(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysNetMonitorTaskResult->MonDate.getValue(),m_compareObject.MonDate.getValue())!=0)
	{
		return 0;
	}
	if (compare(pSysNetMonitorTaskResult->Task_ID.getValue(),m_compareObject.Task_ID.getValue())!=0)
	{
		return 0;
	}
	if (compare(pSysNetMonitorTaskResult->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysNetPartyLinkInfoIteratorByAll> CSysNetPartyLinkInfoIteratorByAll::iteratorList;
void CSysNetPartyLinkInfoIteratorByAll::init(CSysNetPartyLinkInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetPartyLinkInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetPartyLinkInfoIteratorByAll *CSysNetPartyLinkInfoIteratorByAll::alloc(CSysNetPartyLinkInfoFactory *pFactory
		)
{
	CSysNetPartyLinkInfoIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetPartyLinkInfoIteratorByAll::~CSysNetPartyLinkInfoIteratorByAll(void)
{
}

void CSysNetPartyLinkInfoIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetPartyLinkInfoIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetPartyLinkInfoIteratorByAll");
	
	
}

void CSysNetPartyLinkInfoIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetPartyLinkInfoIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetPartyLinkInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetPartyLinkInfoIteratorByAll::UpdateCurrent(CWriteableSysNetPartyLinkInfo * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetPartyLinkInfo *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetPartyLinkInfo;
#endif

CSysNetPartyLinkInfo *CSysNetPartyLinkInfoIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPartyLinkInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetPartyLinkInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetPartyLinkInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetPartyLinkInfoIteratorByAll::match(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetDelPartyLinkInfoIteratorByAll> CSysNetDelPartyLinkInfoIteratorByAll::iteratorList;
void CSysNetDelPartyLinkInfoIteratorByAll::init(CSysNetDelPartyLinkInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetDelPartyLinkInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetDelPartyLinkInfoIteratorByAll *CSysNetDelPartyLinkInfoIteratorByAll::alloc(CSysNetDelPartyLinkInfoFactory *pFactory
		)
{
	CSysNetDelPartyLinkInfoIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetDelPartyLinkInfoIteratorByAll::~CSysNetDelPartyLinkInfoIteratorByAll(void)
{
}

void CSysNetDelPartyLinkInfoIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetDelPartyLinkInfoIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetDelPartyLinkInfoIteratorByAll");
	
	
}

void CSysNetDelPartyLinkInfoIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetDelPartyLinkInfoIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetDelPartyLinkInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetDelPartyLinkInfoIteratorByAll::UpdateCurrent(CWriteableSysNetDelPartyLinkInfo * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetDelPartyLinkInfo *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetDelPartyLinkInfo;
#endif

CSysNetDelPartyLinkInfo *CSysNetDelPartyLinkInfoIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDelPartyLinkInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetDelPartyLinkInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetDelPartyLinkInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetDelPartyLinkInfoIteratorByAll::match(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetPartyLinkAddrChangeIteratorByAll> CSysNetPartyLinkAddrChangeIteratorByAll::iteratorList;
void CSysNetPartyLinkAddrChangeIteratorByAll::init(CSysNetPartyLinkAddrChangeFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetPartyLinkAddrChangeIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetPartyLinkAddrChangeIteratorByAll *CSysNetPartyLinkAddrChangeIteratorByAll::alloc(CSysNetPartyLinkAddrChangeFactory *pFactory
		)
{
	CSysNetPartyLinkAddrChangeIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetPartyLinkAddrChangeIteratorByAll::~CSysNetPartyLinkAddrChangeIteratorByAll(void)
{
}

void CSysNetPartyLinkAddrChangeIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetPartyLinkAddrChangeIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetPartyLinkAddrChangeIteratorByAll");
	
	
}

void CSysNetPartyLinkAddrChangeIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetPartyLinkAddrChangeIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetPartyLinkAddrChange *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetPartyLinkAddrChangeIteratorByAll::UpdateCurrent(CWriteableSysNetPartyLinkAddrChange * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetPartyLinkAddrChange *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetPartyLinkAddrChange;
#endif

CSysNetPartyLinkAddrChange *CSysNetPartyLinkAddrChangeIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPartyLinkAddrChange++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetPartyLinkAddrChange *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetPartyLinkAddrChange *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetPartyLinkAddrChangeIteratorByAll::match(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetMonitorActionAttrIteratorByAll> CSysNetMonitorActionAttrIteratorByAll::iteratorList;
void CSysNetMonitorActionAttrIteratorByAll::init(CSysNetMonitorActionAttrFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorActionAttrIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetMonitorActionAttrIteratorByAll *CSysNetMonitorActionAttrIteratorByAll::alloc(CSysNetMonitorActionAttrFactory *pFactory
		)
{
	CSysNetMonitorActionAttrIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetMonitorActionAttrIteratorByAll::~CSysNetMonitorActionAttrIteratorByAll(void)
{
}

void CSysNetMonitorActionAttrIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorActionAttrIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorActionAttrIteratorByAll");
	
	
}

void CSysNetMonitorActionAttrIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorActionAttrIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorActionAttr *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorActionAttrIteratorByAll::UpdateCurrent(CWriteableSysNetMonitorActionAttr * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorActionAttr *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetMonitorActionAttr;
#endif

CSysNetMonitorActionAttr *CSysNetMonitorActionAttrIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorActionAttr++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorActionAttr *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorActionAttr *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorActionAttrIteratorByAll::match(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetModuleIteratorByAll> CSysNetModuleIteratorByAll::iteratorList;
void CSysNetModuleIteratorByAll::init(CSysNetModuleFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetModuleIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetModuleIteratorByAll *CSysNetModuleIteratorByAll::alloc(CSysNetModuleFactory *pFactory
		)
{
	CSysNetModuleIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetModuleIteratorByAll::~CSysNetModuleIteratorByAll(void)
{
}

void CSysNetModuleIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetModuleIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetModuleIteratorByAll");
	
	
}

void CSysNetModuleIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetModuleIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetModule *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetModuleIteratorByAll::UpdateCurrent(CWriteableSysNetModule * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetModule *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetModule;
#endif

CSysNetModule *CSysNetModuleIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetModule++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetModule *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetModule *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetModuleIteratorByAll::match(CSysNetModule *pSysNetModule)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysNetModuleIteratorByDeviceID> CSysNetModuleIteratorByDeviceID::iteratorList;
void CSysNetModuleIteratorByDeviceID::init(CSysNetModuleFactory *pFactory
		, const CReadOnlyVolumeType& DeviceID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetModuleIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.DeviceID=DeviceID.getValue();

}

CSysNetModuleIteratorByDeviceID *CSysNetModuleIteratorByDeviceID::alloc(CSysNetModuleFactory *pFactory
		, const CReadOnlyVolumeType& DeviceID)
{
	CSysNetModuleIteratorByDeviceID *it;
	it=iteratorList.alloc();
	it->init(pFactory,DeviceID);
	return it;
}

CSysNetModuleIteratorByDeviceID::~CSysNetModuleIteratorByDeviceID(void)
{
}

void CSysNetModuleIteratorByDeviceID::free(void)
{
	iteratorList.free(this);
}

void CSysNetModuleIteratorByDeviceID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetModuleIteratorByDeviceID");
	
	char buffer[200];
	
	m_compareObject.DeviceID.getString(buffer);
	pLogger->output(indent+1,0,"query DeviceID=%s",buffer);
	
}

void CSysNetModuleIteratorByDeviceID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysDeviceIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysDeviceIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetModuleIteratorByDeviceID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetModule *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetModuleIteratorByDeviceID::UpdateCurrent(CWriteableSysNetModule * pByDeviceID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetModule *)(m_pCurrent->pObject),pByDeviceID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDeviceIDForSysNetModule;
#endif

CSysNetModule *CSysNetModuleIteratorByDeviceID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDeviceIDForSysNetModule++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetModule *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetModule *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetModuleIteratorByDeviceID::match(CSysNetModule *pSysNetModule)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysNetModule->DeviceID.getValue(),m_compareObject.DeviceID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysNetEventExprIteratorByAll> CSysNetEventExprIteratorByAll::iteratorList;
void CSysNetEventExprIteratorByAll::init(CSysNetEventExprFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetEventExprIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetEventExprIteratorByAll *CSysNetEventExprIteratorByAll::alloc(CSysNetEventExprFactory *pFactory
		)
{
	CSysNetEventExprIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetEventExprIteratorByAll::~CSysNetEventExprIteratorByAll(void)
{
}

void CSysNetEventExprIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetEventExprIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetEventExprIteratorByAll");
	
	
}

void CSysNetEventExprIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetEventExprIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetEventExpr *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetEventExprIteratorByAll::UpdateCurrent(CWriteableSysNetEventExpr * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetEventExpr *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetEventExpr;
#endif

CSysNetEventExpr *CSysNetEventExprIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetEventExpr++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetEventExpr *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetEventExpr *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetEventExprIteratorByAll::match(CSysNetEventExpr *pSysNetEventExpr)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetEventTypeIteratorByAll> CSysNetEventTypeIteratorByAll::iteratorList;
void CSysNetEventTypeIteratorByAll::init(CSysNetEventTypeFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetEventTypeIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetEventTypeIteratorByAll *CSysNetEventTypeIteratorByAll::alloc(CSysNetEventTypeFactory *pFactory
		)
{
	CSysNetEventTypeIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetEventTypeIteratorByAll::~CSysNetEventTypeIteratorByAll(void)
{
}

void CSysNetEventTypeIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetEventTypeIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetEventTypeIteratorByAll");
	
	
}

void CSysNetEventTypeIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetEventTypeIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetEventType *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetEventTypeIteratorByAll::UpdateCurrent(CWriteableSysNetEventType * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetEventType *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetEventType;
#endif

CSysNetEventType *CSysNetEventTypeIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetEventType++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetEventType *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetEventType *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetEventTypeIteratorByAll::match(CSysNetEventType *pSysNetEventType)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetSubEventTypeIteratorByAll> CSysNetSubEventTypeIteratorByAll::iteratorList;
void CSysNetSubEventTypeIteratorByAll::init(CSysNetSubEventTypeFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetSubEventTypeIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetSubEventTypeIteratorByAll *CSysNetSubEventTypeIteratorByAll::alloc(CSysNetSubEventTypeFactory *pFactory
		)
{
	CSysNetSubEventTypeIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetSubEventTypeIteratorByAll::~CSysNetSubEventTypeIteratorByAll(void)
{
}

void CSysNetSubEventTypeIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetSubEventTypeIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetSubEventTypeIteratorByAll");
	
	
}

void CSysNetSubEventTypeIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetSubEventTypeIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetSubEventType *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetSubEventTypeIteratorByAll::UpdateCurrent(CWriteableSysNetSubEventType * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetSubEventType *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetSubEventType;
#endif

CSysNetSubEventType *CSysNetSubEventTypeIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetSubEventType++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetSubEventType *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetSubEventType *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetSubEventTypeIteratorByAll::match(CSysNetSubEventType *pSysNetSubEventType)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetEventLevelIteratorByAll> CSysNetEventLevelIteratorByAll::iteratorList;
void CSysNetEventLevelIteratorByAll::init(CSysNetEventLevelFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetEventLevelIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetEventLevelIteratorByAll *CSysNetEventLevelIteratorByAll::alloc(CSysNetEventLevelFactory *pFactory
		)
{
	CSysNetEventLevelIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetEventLevelIteratorByAll::~CSysNetEventLevelIteratorByAll(void)
{
}

void CSysNetEventLevelIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetEventLevelIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetEventLevelIteratorByAll");
	
	
}

void CSysNetEventLevelIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetEventLevelIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetEventLevel *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetEventLevelIteratorByAll::UpdateCurrent(CWriteableSysNetEventLevel * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetEventLevel *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetEventLevel;
#endif

CSysNetEventLevel *CSysNetEventLevelIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetEventLevel++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetEventLevel *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetEventLevel *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetEventLevelIteratorByAll::match(CSysNetEventLevel *pSysNetEventLevel)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetMonitorDeviceTaskIteratorByAll> CSysNetMonitorDeviceTaskIteratorByAll::iteratorList;
void CSysNetMonitorDeviceTaskIteratorByAll::init(CSysNetMonitorDeviceTaskFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorDeviceTaskIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;
	m_compareObject.SecondID=0;

}

CSysNetMonitorDeviceTaskIteratorByAll *CSysNetMonitorDeviceTaskIteratorByAll::alloc(CSysNetMonitorDeviceTaskFactory *pFactory
		)
{
	CSysNetMonitorDeviceTaskIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetMonitorDeviceTaskIteratorByAll::~CSysNetMonitorDeviceTaskIteratorByAll(void)
{
}

void CSysNetMonitorDeviceTaskIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorDeviceTaskIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorDeviceTaskIteratorByAll");
	
	
}

void CSysNetMonitorDeviceTaskIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorDeviceTaskIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorDeviceTask *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorDeviceTaskIteratorByAll::UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorDeviceTask *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetMonitorDeviceTask;
#endif

CSysNetMonitorDeviceTask *CSysNetMonitorDeviceTaskIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorDeviceTask++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorDeviceTask *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorDeviceTask *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorDeviceTaskIteratorByAll::match(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysNetMonitorDeviceTaskIteratorByID> CSysNetMonitorDeviceTaskIteratorByID::iteratorList;
void CSysNetMonitorDeviceTaskIteratorByID::init(CSysNetMonitorDeviceTaskFactory *pFactory
		, const CReadOnlyVolumeType& ID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorDeviceTaskIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=ID.getValue();
	m_compareObject.SecondID=0;

}

CSysNetMonitorDeviceTaskIteratorByID *CSysNetMonitorDeviceTaskIteratorByID::alloc(CSysNetMonitorDeviceTaskFactory *pFactory
		, const CReadOnlyVolumeType& ID)
{
	CSysNetMonitorDeviceTaskIteratorByID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ID);
	return it;
}

CSysNetMonitorDeviceTaskIteratorByID::~CSysNetMonitorDeviceTaskIteratorByID(void)
{
}

void CSysNetMonitorDeviceTaskIteratorByID::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorDeviceTaskIteratorByID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorDeviceTaskIteratorByID");
	
	char buffer[200];
	
	m_compareObject.ID.getString(buffer);
	pLogger->output(indent+1,0,"query ID=%s",buffer);
	
}

void CSysNetMonitorDeviceTaskIteratorByID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorDeviceTaskIteratorByID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorDeviceTask *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorDeviceTaskIteratorByID::UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pByID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorDeviceTask *)(m_pCurrent->pObject),pByID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByIDForSysNetMonitorDeviceTask;
#endif

CSysNetMonitorDeviceTask *CSysNetMonitorDeviceTaskIteratorByID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByIDForSysNetMonitorDeviceTask++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorDeviceTask *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorDeviceTask *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorDeviceTaskIteratorByID::match(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysNetMonitorDeviceTask->ID.getValue(),m_compareObject.ID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysNetMonitorTaskInstAttrsIteratorByAll> CSysNetMonitorTaskInstAttrsIteratorByAll::iteratorList;
void CSysNetMonitorTaskInstAttrsIteratorByAll::init(CSysNetMonitorTaskInstAttrsFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMonitorTaskInstAttrsIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetMonitorTaskInstAttrsIteratorByAll *CSysNetMonitorTaskInstAttrsIteratorByAll::alloc(CSysNetMonitorTaskInstAttrsFactory *pFactory
		)
{
	CSysNetMonitorTaskInstAttrsIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetMonitorTaskInstAttrsIteratorByAll::~CSysNetMonitorTaskInstAttrsIteratorByAll(void)
{
}

void CSysNetMonitorTaskInstAttrsIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetMonitorTaskInstAttrsIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMonitorTaskInstAttrsIteratorByAll");
	
	
}

void CSysNetMonitorTaskInstAttrsIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMonitorTaskInstAttrsIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMonitorTaskInstAttrs *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMonitorTaskInstAttrsIteratorByAll::UpdateCurrent(CWriteableSysNetMonitorTaskInstAttrs * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMonitorTaskInstAttrs *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetMonitorTaskInstAttrs;
#endif

CSysNetMonitorTaskInstAttrs *CSysNetMonitorTaskInstAttrsIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskInstAttrs++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMonitorTaskInstAttrs *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMonitorTaskInstAttrs *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMonitorTaskInstAttrsIteratorByAll::match(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetBaseLineIteratorByAll> CSysNetBaseLineIteratorByAll::iteratorList;
void CSysNetBaseLineIteratorByAll::init(CSysNetBaseLineFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetBaseLineIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetBaseLineIteratorByAll *CSysNetBaseLineIteratorByAll::alloc(CSysNetBaseLineFactory *pFactory
		)
{
	CSysNetBaseLineIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetBaseLineIteratorByAll::~CSysNetBaseLineIteratorByAll(void)
{
}

void CSysNetBaseLineIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetBaseLineIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetBaseLineIteratorByAll");
	
	
}

void CSysNetBaseLineIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetBaseLineIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetBaseLine *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetBaseLineIteratorByAll::UpdateCurrent(CWriteableSysNetBaseLine * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetBaseLine *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetBaseLine;
#endif

CSysNetBaseLine *CSysNetBaseLineIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetBaseLine++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetBaseLine *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetBaseLine *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetBaseLineIteratorByAll::match(CSysNetBaseLine *pSysNetBaseLine)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysNetBaseLineIteratorByID> CSysNetBaseLineIteratorByID::iteratorList;
void CSysNetBaseLineIteratorByID::init(CSysNetBaseLineFactory *pFactory
		, const CReadOnlyVolumeType& ID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetBaseLineIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=ID.getValue();

}

CSysNetBaseLineIteratorByID *CSysNetBaseLineIteratorByID::alloc(CSysNetBaseLineFactory *pFactory
		, const CReadOnlyVolumeType& ID)
{
	CSysNetBaseLineIteratorByID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ID);
	return it;
}

CSysNetBaseLineIteratorByID::~CSysNetBaseLineIteratorByID(void)
{
}

void CSysNetBaseLineIteratorByID::free(void)
{
	iteratorList.free(this);
}

void CSysNetBaseLineIteratorByID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetBaseLineIteratorByID");
	
	char buffer[200];
	
	m_compareObject.ID.getString(buffer);
	pLogger->output(indent+1,0,"query ID=%s",buffer);
	
}

void CSysNetBaseLineIteratorByID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetBaseLineIteratorByID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetBaseLine *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetBaseLineIteratorByID::UpdateCurrent(CWriteableSysNetBaseLine * pByID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetBaseLine *)(m_pCurrent->pObject),pByID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByIDForSysNetBaseLine;
#endif

CSysNetBaseLine *CSysNetBaseLineIteratorByID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByIDForSysNetBaseLine++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetBaseLine *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetBaseLine *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetBaseLineIteratorByID::match(CSysNetBaseLine *pSysNetBaseLine)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysNetBaseLine->ID.getValue(),m_compareObject.ID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysNetBaseLineTaskIteratorByAll> CSysNetBaseLineTaskIteratorByAll::iteratorList;
void CSysNetBaseLineTaskIteratorByAll::init(CSysNetBaseLineTaskFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetBaseLineTaskIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetBaseLineTaskIteratorByAll *CSysNetBaseLineTaskIteratorByAll::alloc(CSysNetBaseLineTaskFactory *pFactory
		)
{
	CSysNetBaseLineTaskIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetBaseLineTaskIteratorByAll::~CSysNetBaseLineTaskIteratorByAll(void)
{
}

void CSysNetBaseLineTaskIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetBaseLineTaskIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetBaseLineTaskIteratorByAll");
	
	
}

void CSysNetBaseLineTaskIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetBaseLineTaskIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetBaseLineTask *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetBaseLineTaskIteratorByAll::UpdateCurrent(CWriteableSysNetBaseLineTask * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetBaseLineTask *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetBaseLineTask;
#endif

CSysNetBaseLineTask *CSysNetBaseLineTaskIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetBaseLineTask++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetBaseLineTask *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetBaseLineTask *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetBaseLineTaskIteratorByAll::match(CSysNetBaseLineTask *pSysNetBaseLineTask)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysMdbNetPartyLinkStatusInfoIteratorByTime> CSysMdbNetPartyLinkStatusInfoIteratorByTime::iteratorList;
void CSysMdbNetPartyLinkStatusInfoIteratorByTime::init(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbNetPartyLinkStatusInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbNetPartyLinkStatusInfoIteratorByTime *CSysMdbNetPartyLinkStatusInfoIteratorByTime::alloc(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbNetPartyLinkStatusInfoIteratorByTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,MonDate,MonTime);
	return it;
}

CSysMdbNetPartyLinkStatusInfoIteratorByTime::~CSysMdbNetPartyLinkStatusInfoIteratorByTime(void)
{
}

void CSysMdbNetPartyLinkStatusInfoIteratorByTime::free(void)
{
	iteratorList.free(this);
}

void CSysMdbNetPartyLinkStatusInfoIteratorByTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbNetPartyLinkStatusInfoIteratorByTime");
	
	char buffer[200];
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbNetPartyLinkStatusInfoIteratorByTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysDateTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysDateTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbNetPartyLinkStatusInfoIteratorByTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbNetPartyLinkStatusInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbNetPartyLinkStatusInfoIteratorByTime::UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pByTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbNetPartyLinkStatusInfo *)(m_pCurrent->pObject),pByTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByTimeForSysMdbNetPartyLinkStatusInfo;
#endif

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoIteratorByTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByTimeForSysMdbNetPartyLinkStatusInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbNetPartyLinkStatusInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbNetPartyLinkStatusInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbNetPartyLinkStatusInfoIteratorByTime::match(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysMdbNetPartyLinkStatusInfoIteratorByDsc> CSysMdbNetPartyLinkStatusInfoIteratorByDsc::iteratorList;
void CSysMdbNetPartyLinkStatusInfoIteratorByDsc::init(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbNetPartyLinkStatusInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysMdbNetPartyLinkStatusInfoIteratorByDsc *CSysMdbNetPartyLinkStatusInfoIteratorByDsc::alloc(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID)
{
	CSysMdbNetPartyLinkStatusInfoIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID);
	return it;
}

CSysMdbNetPartyLinkStatusInfoIteratorByDsc::~CSysMdbNetPartyLinkStatusInfoIteratorByDsc(void)
{
}

void CSysMdbNetPartyLinkStatusInfoIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysMdbNetPartyLinkStatusInfoIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbNetPartyLinkStatusInfoIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
}

void CSysMdbNetPartyLinkStatusInfoIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbNetPartyLinkStatusInfoIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbNetPartyLinkStatusInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbNetPartyLinkStatusInfoIteratorByDsc::UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbNetPartyLinkStatusInfo *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysMdbNetPartyLinkStatusInfo;
#endif

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbNetPartyLinkStatusInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbNetPartyLinkStatusInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbNetPartyLinkStatusInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbNetPartyLinkStatusInfoIteratorByDsc::match(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbNetPartyLinkStatusInfo->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbNetPartyLinkStatusInfoIteratorByAll> CSysMdbNetPartyLinkStatusInfoIteratorByAll::iteratorList;
void CSysMdbNetPartyLinkStatusInfoIteratorByAll::init(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbNetPartyLinkStatusInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysMdbNetPartyLinkStatusInfoIteratorByAll *CSysMdbNetPartyLinkStatusInfoIteratorByAll::alloc(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		)
{
	CSysMdbNetPartyLinkStatusInfoIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMdbNetPartyLinkStatusInfoIteratorByAll::~CSysMdbNetPartyLinkStatusInfoIteratorByAll(void)
{
}

void CSysMdbNetPartyLinkStatusInfoIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbNetPartyLinkStatusInfoIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbNetPartyLinkStatusInfoIteratorByAll");
	
	
}

void CSysMdbNetPartyLinkStatusInfoIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysDateTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysDateTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbNetPartyLinkStatusInfoIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbNetPartyLinkStatusInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbNetPartyLinkStatusInfoIteratorByAll::UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbNetPartyLinkStatusInfo *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysMdbNetPartyLinkStatusInfo;
#endif

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysMdbNetPartyLinkStatusInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbNetPartyLinkStatusInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbNetPartyLinkStatusInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbNetPartyLinkStatusInfoIteratorByAll::match(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetMemberSDHLineInfoIteratorByAll> CSysNetMemberSDHLineInfoIteratorByAll::iteratorList;
void CSysNetMemberSDHLineInfoIteratorByAll::init(CSysNetMemberSDHLineInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetMemberSDHLineInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetMemberSDHLineInfoIteratorByAll *CSysNetMemberSDHLineInfoIteratorByAll::alloc(CSysNetMemberSDHLineInfoFactory *pFactory
		)
{
	CSysNetMemberSDHLineInfoIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetMemberSDHLineInfoIteratorByAll::~CSysNetMemberSDHLineInfoIteratorByAll(void)
{
}

void CSysNetMemberSDHLineInfoIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetMemberSDHLineInfoIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetMemberSDHLineInfoIteratorByAll");
	
	
}

void CSysNetMemberSDHLineInfoIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetMemberSDHLineInfoIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetMemberSDHLineInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetMemberSDHLineInfoIteratorByAll::UpdateCurrent(CWriteableSysNetMemberSDHLineInfo * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetMemberSDHLineInfo *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetMemberSDHLineInfo;
#endif

CSysNetMemberSDHLineInfo *CSysNetMemberSDHLineInfoIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMemberSDHLineInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetMemberSDHLineInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetMemberSDHLineInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetMemberSDHLineInfoIteratorByAll::match(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetDDNLinkInfoIteratorByAll> CSysNetDDNLinkInfoIteratorByAll::iteratorList;
void CSysNetDDNLinkInfoIteratorByAll::init(CSysNetDDNLinkInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetDDNLinkInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetDDNLinkInfoIteratorByAll *CSysNetDDNLinkInfoIteratorByAll::alloc(CSysNetDDNLinkInfoFactory *pFactory
		)
{
	CSysNetDDNLinkInfoIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetDDNLinkInfoIteratorByAll::~CSysNetDDNLinkInfoIteratorByAll(void)
{
}

void CSysNetDDNLinkInfoIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetDDNLinkInfoIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetDDNLinkInfoIteratorByAll");
	
	
}

void CSysNetDDNLinkInfoIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetDDNLinkInfoIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetDDNLinkInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetDDNLinkInfoIteratorByAll::UpdateCurrent(CWriteableSysNetDDNLinkInfo * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetDDNLinkInfo *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetDDNLinkInfo;
#endif

CSysNetDDNLinkInfo *CSysNetDDNLinkInfoIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDDNLinkInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetDDNLinkInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetDDNLinkInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetDDNLinkInfoIteratorByAll::match(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetPseudMemberLinkInfoIteratorByAll> CSysNetPseudMemberLinkInfoIteratorByAll::iteratorList;
void CSysNetPseudMemberLinkInfoIteratorByAll::init(CSysNetPseudMemberLinkInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetPseudMemberLinkInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetPseudMemberLinkInfoIteratorByAll *CSysNetPseudMemberLinkInfoIteratorByAll::alloc(CSysNetPseudMemberLinkInfoFactory *pFactory
		)
{
	CSysNetPseudMemberLinkInfoIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetPseudMemberLinkInfoIteratorByAll::~CSysNetPseudMemberLinkInfoIteratorByAll(void)
{
}

void CSysNetPseudMemberLinkInfoIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetPseudMemberLinkInfoIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetPseudMemberLinkInfoIteratorByAll");
	
	
}

void CSysNetPseudMemberLinkInfoIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetPseudMemberLinkInfoIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetPseudMemberLinkInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetPseudMemberLinkInfoIteratorByAll::UpdateCurrent(CWriteableSysNetPseudMemberLinkInfo * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetPseudMemberLinkInfo *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetPseudMemberLinkInfo;
#endif

CSysNetPseudMemberLinkInfo *CSysNetPseudMemberLinkInfoIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPseudMemberLinkInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetPseudMemberLinkInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetPseudMemberLinkInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetPseudMemberLinkInfoIteratorByAll::match(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetOuterDeviceInfoIteratorByAll> CSysNetOuterDeviceInfoIteratorByAll::iteratorList;
void CSysNetOuterDeviceInfoIteratorByAll::init(CSysNetOuterDeviceInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetOuterDeviceInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetOuterDeviceInfoIteratorByAll *CSysNetOuterDeviceInfoIteratorByAll::alloc(CSysNetOuterDeviceInfoFactory *pFactory
		)
{
	CSysNetOuterDeviceInfoIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetOuterDeviceInfoIteratorByAll::~CSysNetOuterDeviceInfoIteratorByAll(void)
{
}

void CSysNetOuterDeviceInfoIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetOuterDeviceInfoIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetOuterDeviceInfoIteratorByAll");
	
	
}

void CSysNetOuterDeviceInfoIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetOuterDeviceInfoIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetOuterDeviceInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetOuterDeviceInfoIteratorByAll::UpdateCurrent(CWriteableSysNetOuterDeviceInfo * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetOuterDeviceInfo *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetOuterDeviceInfo;
#endif

CSysNetOuterDeviceInfo *CSysNetOuterDeviceInfoIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetOuterDeviceInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetOuterDeviceInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetOuterDeviceInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetOuterDeviceInfoIteratorByAll::match(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysLocalPingResultInfoIteratorByAll> CSysLocalPingResultInfoIteratorByAll::iteratorList;
void CSysLocalPingResultInfoIteratorByAll::init(CSysLocalPingResultInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysLocalPingResultInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysLocalPingResultInfoIteratorByAll *CSysLocalPingResultInfoIteratorByAll::alloc(CSysLocalPingResultInfoFactory *pFactory
		)
{
	CSysLocalPingResultInfoIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysLocalPingResultInfoIteratorByAll::~CSysLocalPingResultInfoIteratorByAll(void)
{
}

void CSysLocalPingResultInfoIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysLocalPingResultInfoIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysLocalPingResultInfoIteratorByAll");
	
	
}

void CSysLocalPingResultInfoIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysLocalPingResultInfoIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysLocalPingResultInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysLocalPingResultInfoIteratorByAll::UpdateCurrent(CWriteableSysLocalPingResultInfo * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysLocalPingResultInfo *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysLocalPingResultInfo;
#endif

CSysLocalPingResultInfo *CSysLocalPingResultInfoIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysLocalPingResultInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysLocalPingResultInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysLocalPingResultInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysLocalPingResultInfoIteratorByAll::match(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysLocalPingResultInfoIteratorByIDType> CSysLocalPingResultInfoIteratorByIDType::iteratorList;
void CSysLocalPingResultInfoIteratorByIDType::init(CSysLocalPingResultInfoFactory *pFactory
		, const CReadOnlyVolumeType& ID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysLocalPingResultInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=ID.getValue();

}

CSysLocalPingResultInfoIteratorByIDType *CSysLocalPingResultInfoIteratorByIDType::alloc(CSysLocalPingResultInfoFactory *pFactory
		, const CReadOnlyVolumeType& ID)
{
	CSysLocalPingResultInfoIteratorByIDType *it;
	it=iteratorList.alloc();
	it->init(pFactory,ID);
	return it;
}

CSysLocalPingResultInfoIteratorByIDType::~CSysLocalPingResultInfoIteratorByIDType(void)
{
}

void CSysLocalPingResultInfoIteratorByIDType::free(void)
{
	iteratorList.free(this);
}

void CSysLocalPingResultInfoIteratorByIDType::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysLocalPingResultInfoIteratorByIDType");
	
	char buffer[200];
	
	m_compareObject.ID.getString(buffer);
	pLogger->output(indent+1,0,"query ID=%s",buffer);
	
}

void CSysLocalPingResultInfoIteratorByIDType::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysLocalPingResultInfoIteratorByIDType::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysLocalPingResultInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysLocalPingResultInfoIteratorByIDType::UpdateCurrent(CWriteableSysLocalPingResultInfo * pByIDType,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysLocalPingResultInfo *)(m_pCurrent->pObject),pByIDType,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByIDTypeForSysLocalPingResultInfo;
#endif

CSysLocalPingResultInfo *CSysLocalPingResultInfoIteratorByIDType::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysLocalPingResultInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysLocalPingResultInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysLocalPingResultInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysLocalPingResultInfoIteratorByIDType::match(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysLocalPingResultInfo->ID.getValue(),m_compareObject.ID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysRomotePingResultInfoIteratorByAll> CSysRomotePingResultInfoIteratorByAll::iteratorList;
void CSysRomotePingResultInfoIteratorByAll::init(CSysRomotePingResultInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysRomotePingResultInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysRomotePingResultInfoIteratorByAll *CSysRomotePingResultInfoIteratorByAll::alloc(CSysRomotePingResultInfoFactory *pFactory
		)
{
	CSysRomotePingResultInfoIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysRomotePingResultInfoIteratorByAll::~CSysRomotePingResultInfoIteratorByAll(void)
{
}

void CSysRomotePingResultInfoIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysRomotePingResultInfoIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysRomotePingResultInfoIteratorByAll");
	
	
}

void CSysRomotePingResultInfoIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysRomotePingResultInfoIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysRomotePingResultInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysRomotePingResultInfoIteratorByAll::UpdateCurrent(CWriteableSysRomotePingResultInfo * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysRomotePingResultInfo *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysRomotePingResultInfo;
#endif

CSysRomotePingResultInfo *CSysRomotePingResultInfoIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysRomotePingResultInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysRomotePingResultInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysRomotePingResultInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysRomotePingResultInfoIteratorByAll::match(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysRomotePingResultInfoIteratorByIDType> CSysRomotePingResultInfoIteratorByIDType::iteratorList;
void CSysRomotePingResultInfoIteratorByIDType::init(CSysRomotePingResultInfoFactory *pFactory
		, const CReadOnlyVolumeType& ID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysRomotePingResultInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=ID.getValue();

}

CSysRomotePingResultInfoIteratorByIDType *CSysRomotePingResultInfoIteratorByIDType::alloc(CSysRomotePingResultInfoFactory *pFactory
		, const CReadOnlyVolumeType& ID)
{
	CSysRomotePingResultInfoIteratorByIDType *it;
	it=iteratorList.alloc();
	it->init(pFactory,ID);
	return it;
}

CSysRomotePingResultInfoIteratorByIDType::~CSysRomotePingResultInfoIteratorByIDType(void)
{
}

void CSysRomotePingResultInfoIteratorByIDType::free(void)
{
	iteratorList.free(this);
}

void CSysRomotePingResultInfoIteratorByIDType::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysRomotePingResultInfoIteratorByIDType");
	
	char buffer[200];
	
	m_compareObject.ID.getString(buffer);
	pLogger->output(indent+1,0,"query ID=%s",buffer);
	
}

void CSysRomotePingResultInfoIteratorByIDType::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysRomotePingResultInfoIteratorByIDType::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysRomotePingResultInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysRomotePingResultInfoIteratorByIDType::UpdateCurrent(CWriteableSysRomotePingResultInfo * pByIDType,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysRomotePingResultInfo *)(m_pCurrent->pObject),pByIDType,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByIDTypeForSysRomotePingResultInfo;
#endif

CSysRomotePingResultInfo *CSysRomotePingResultInfoIteratorByIDType::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysRomotePingResultInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysRomotePingResultInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysRomotePingResultInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysRomotePingResultInfoIteratorByIDType::match(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysRomotePingResultInfo->ID.getValue(),m_compareObject.ID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysParticTradeOrderStatesIteratorByAll> CSysParticTradeOrderStatesIteratorByAll::iteratorList;
void CSysParticTradeOrderStatesIteratorByAll::init(CSysParticTradeOrderStatesFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysParticTradeOrderStatesIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID="";
	m_compareObject.UserID="";
	m_compareObject.MonDate="";
	m_compareObject.MonTime="";

}

CSysParticTradeOrderStatesIteratorByAll *CSysParticTradeOrderStatesIteratorByAll::alloc(CSysParticTradeOrderStatesFactory *pFactory
		)
{
	CSysParticTradeOrderStatesIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysParticTradeOrderStatesIteratorByAll::~CSysParticTradeOrderStatesIteratorByAll(void)
{
}

void CSysParticTradeOrderStatesIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysParticTradeOrderStatesIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysParticTradeOrderStatesIteratorByAll");
	
	
}

void CSysParticTradeOrderStatesIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pMemUsrIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pMemUsrIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysParticTradeOrderStatesIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysParticTradeOrderStates *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysParticTradeOrderStatesIteratorByAll::UpdateCurrent(CWriteableSysParticTradeOrderStates * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysParticTradeOrderStates *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysParticTradeOrderStates;
#endif

CSysParticTradeOrderStates *CSysParticTradeOrderStatesIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysParticTradeOrderStates++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysParticTradeOrderStates *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysParticTradeOrderStates *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysParticTradeOrderStatesIteratorByAll::match(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysParticTradeOrderStatesIteratorByUserID> CSysParticTradeOrderStatesIteratorByUserID::iteratorList;
void CSysParticTradeOrderStatesIteratorByUserID::init(CSysParticTradeOrderStatesFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID, const CReadOnlyUserIDType& UserID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysParticTradeOrderStatesIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID=ParticipantID.getValue();
	m_compareObject.UserID=UserID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysParticTradeOrderStatesIteratorByUserID *CSysParticTradeOrderStatesIteratorByUserID::alloc(CSysParticTradeOrderStatesFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID, const CReadOnlyUserIDType& UserID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysParticTradeOrderStatesIteratorByUserID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ParticipantID,UserID,MonDate,MonTime);
	return it;
}

CSysParticTradeOrderStatesIteratorByUserID::~CSysParticTradeOrderStatesIteratorByUserID(void)
{
}

void CSysParticTradeOrderStatesIteratorByUserID::free(void)
{
	iteratorList.free(this);
}

void CSysParticTradeOrderStatesIteratorByUserID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysParticTradeOrderStatesIteratorByUserID");
	
	char buffer[200];
	
	m_compareObject.ParticipantID.getString(buffer);
	pLogger->output(indent+1,0,"query ParticipantID=%s",buffer);
	
	m_compareObject.UserID.getString(buffer);
	pLogger->output(indent+1,0,"query UserID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysParticTradeOrderStatesIteratorByUserID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pMemUsrIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pMemUsrIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysParticTradeOrderStatesIteratorByUserID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysParticTradeOrderStates *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysParticTradeOrderStatesIteratorByUserID::UpdateCurrent(CWriteableSysParticTradeOrderStates * pByUserID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysParticTradeOrderStates *)(m_pCurrent->pObject),pByUserID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByUserIDForSysParticTradeOrderStates;
#endif

CSysParticTradeOrderStates *CSysParticTradeOrderStatesIteratorByUserID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByUserIDForSysParticTradeOrderStates++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysParticTradeOrderStates *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysParticTradeOrderStates *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysParticTradeOrderStatesIteratorByUserID::match(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysParticTradeOrderStates->ParticipantID.getValue(),m_compareObject.ParticipantID.getValue())!=0)
	{
		return 0;
	}
	if (compare(pSysParticTradeOrderStates->UserID.getValue(),m_compareObject.UserID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysMdbRouterInfoIteratorByHostName> CSysMdbRouterInfoIteratorByHostName::iteratorList;
void CSysMdbRouterInfoIteratorByHostName::init(CSysMdbRouterInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbRouterInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbRouterInfoIteratorByHostName *CSysMdbRouterInfoIteratorByHostName::alloc(CSysMdbRouterInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbRouterInfoIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID,MonDate,MonTime);
	return it;
}

CSysMdbRouterInfoIteratorByHostName::~CSysMdbRouterInfoIteratorByHostName(void)
{
}

void CSysMdbRouterInfoIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CSysMdbRouterInfoIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbRouterInfoIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbRouterInfoIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbRouterInfoIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbRouterInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbRouterInfoIteratorByHostName::UpdateCurrent(CWriteableSysMdbRouterInfo * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbRouterInfo *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForSysMdbRouterInfo;
#endif

CSysMdbRouterInfo *CSysMdbRouterInfoIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbRouterInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbRouterInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbRouterInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbRouterInfoIteratorByHostName::match(CSysMdbRouterInfo *pSysMdbRouterInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbRouterInfo->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbRouterInfoIteratorByDsc> CSysMdbRouterInfoIteratorByDsc::iteratorList;
void CSysMdbRouterInfoIteratorByDsc::init(CSysMdbRouterInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbRouterInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysMdbRouterInfoIteratorByDsc *CSysMdbRouterInfoIteratorByDsc::alloc(CSysMdbRouterInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID)
{
	CSysMdbRouterInfoIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID);
	return it;
}

CSysMdbRouterInfoIteratorByDsc::~CSysMdbRouterInfoIteratorByDsc(void)
{
}

void CSysMdbRouterInfoIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysMdbRouterInfoIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbRouterInfoIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
}

void CSysMdbRouterInfoIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbRouterInfoIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbRouterInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbRouterInfoIteratorByDsc::UpdateCurrent(CWriteableSysMdbRouterInfo * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbRouterInfo *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysMdbRouterInfo;
#endif

CSysMdbRouterInfo *CSysMdbRouterInfoIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbRouterInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbRouterInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbRouterInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbRouterInfoIteratorByDsc::match(CSysMdbRouterInfo *pSysMdbRouterInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbRouterInfo->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbRouterInfoIteratorBytheAll> CSysMdbRouterInfoIteratorBytheAll::iteratorList;
void CSysMdbRouterInfoIteratorBytheAll::init(CSysMdbRouterInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbRouterInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID="";

}

CSysMdbRouterInfoIteratorBytheAll *CSysMdbRouterInfoIteratorBytheAll::alloc(CSysMdbRouterInfoFactory *pFactory
		)
{
	CSysMdbRouterInfoIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMdbRouterInfoIteratorBytheAll::~CSysMdbRouterInfoIteratorBytheAll(void)
{
}

void CSysMdbRouterInfoIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbRouterInfoIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbRouterInfoIteratorBytheAll");
	
	
}

void CSysMdbRouterInfoIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbRouterInfoIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbRouterInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbRouterInfoIteratorBytheAll::UpdateCurrent(CWriteableSysMdbRouterInfo * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbRouterInfo *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysMdbRouterInfo;
#endif

CSysMdbRouterInfo *CSysMdbRouterInfoIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbRouterInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbRouterInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbRouterInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbRouterInfoIteratorBytheAll::match(CSysMdbRouterInfo *pSysMdbRouterInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysMdbRouterInfoIteratorByDataDelete> CSysMdbRouterInfoIteratorByDataDelete::iteratorList;
void CSysMdbRouterInfoIteratorByDataDelete::init(CSysMdbRouterInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbRouterInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbRouterInfoIteratorByDataDelete *CSysMdbRouterInfoIteratorByDataDelete::alloc(CSysMdbRouterInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbRouterInfoIteratorByDataDelete *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID,MonDate,MonTime);
	return it;
}

CSysMdbRouterInfoIteratorByDataDelete::~CSysMdbRouterInfoIteratorByDataDelete(void)
{
}

void CSysMdbRouterInfoIteratorByDataDelete::free(void)
{
	iteratorList.free(this);
}

void CSysMdbRouterInfoIteratorByDataDelete::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbRouterInfoIteratorByDataDelete");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbRouterInfoIteratorByDataDelete::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbRouterInfoIteratorByDataDelete::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbRouterInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbRouterInfoIteratorByDataDelete::UpdateCurrent(CWriteableSysMdbRouterInfo * pByDataDelete,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbRouterInfo *)(m_pCurrent->pObject),pByDataDelete,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDataDeleteForSysMdbRouterInfo;
#endif

CSysMdbRouterInfo *CSysMdbRouterInfoIteratorByDataDelete::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbRouterInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbRouterInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbRouterInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbRouterInfoIteratorByDataDelete::match(CSysMdbRouterInfo *pSysMdbRouterInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbRouterInfo->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysMdbDiskIOIteratorByHostName> CSysMdbDiskIOIteratorByHostName::iteratorList;
void CSysMdbDiskIOIteratorByHostName::init(CSysMdbDiskIOFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbDiskIOIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbDiskIOIteratorByHostName *CSysMdbDiskIOIteratorByHostName::alloc(CSysMdbDiskIOFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbDiskIOIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID,MonDate,MonTime);
	return it;
}

CSysMdbDiskIOIteratorByHostName::~CSysMdbDiskIOIteratorByHostName(void)
{
}

void CSysMdbDiskIOIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CSysMdbDiskIOIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbDiskIOIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbDiskIOIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbDiskIOIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbDiskIO *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbDiskIOIteratorByHostName::UpdateCurrent(CWriteableSysMdbDiskIO * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbDiskIO *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForSysMdbDiskIO;
#endif

CSysMdbDiskIO *CSysMdbDiskIOIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbDiskIO++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbDiskIO *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbDiskIO *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbDiskIOIteratorByHostName::match(CSysMdbDiskIO *pSysMdbDiskIO)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbDiskIO->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbDiskIOIteratorByDsc> CSysMdbDiskIOIteratorByDsc::iteratorList;
void CSysMdbDiskIOIteratorByDsc::init(CSysMdbDiskIOFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbDiskIOIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysMdbDiskIOIteratorByDsc *CSysMdbDiskIOIteratorByDsc::alloc(CSysMdbDiskIOFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID)
{
	CSysMdbDiskIOIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID);
	return it;
}

CSysMdbDiskIOIteratorByDsc::~CSysMdbDiskIOIteratorByDsc(void)
{
}

void CSysMdbDiskIOIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysMdbDiskIOIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbDiskIOIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
}

void CSysMdbDiskIOIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbDiskIOIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbDiskIO *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbDiskIOIteratorByDsc::UpdateCurrent(CWriteableSysMdbDiskIO * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbDiskIO *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysMdbDiskIO;
#endif

CSysMdbDiskIO *CSysMdbDiskIOIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbDiskIO++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbDiskIO *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbDiskIO *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbDiskIOIteratorByDsc::match(CSysMdbDiskIO *pSysMdbDiskIO)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbDiskIO->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbDiskIOIteratorBytheAll> CSysMdbDiskIOIteratorBytheAll::iteratorList;
void CSysMdbDiskIOIteratorBytheAll::init(CSysMdbDiskIOFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbDiskIOIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID="";

}

CSysMdbDiskIOIteratorBytheAll *CSysMdbDiskIOIteratorBytheAll::alloc(CSysMdbDiskIOFactory *pFactory
		)
{
	CSysMdbDiskIOIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMdbDiskIOIteratorBytheAll::~CSysMdbDiskIOIteratorBytheAll(void)
{
}

void CSysMdbDiskIOIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbDiskIOIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbDiskIOIteratorBytheAll");
	
	
}

void CSysMdbDiskIOIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbDiskIOIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbDiskIO *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbDiskIOIteratorBytheAll::UpdateCurrent(CWriteableSysMdbDiskIO * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbDiskIO *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysMdbDiskIO;
#endif

CSysMdbDiskIO *CSysMdbDiskIOIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbDiskIO++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbDiskIO *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbDiskIO *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbDiskIOIteratorBytheAll::match(CSysMdbDiskIO *pSysMdbDiskIO)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysMdbDiskIOIteratorByDataDelete> CSysMdbDiskIOIteratorByDataDelete::iteratorList;
void CSysMdbDiskIOIteratorByDataDelete::init(CSysMdbDiskIOFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbDiskIOIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbDiskIOIteratorByDataDelete *CSysMdbDiskIOIteratorByDataDelete::alloc(CSysMdbDiskIOFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbDiskIOIteratorByDataDelete *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID,MonDate,MonTime);
	return it;
}

CSysMdbDiskIOIteratorByDataDelete::~CSysMdbDiskIOIteratorByDataDelete(void)
{
}

void CSysMdbDiskIOIteratorByDataDelete::free(void)
{
	iteratorList.free(this);
}

void CSysMdbDiskIOIteratorByDataDelete::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbDiskIOIteratorByDataDelete");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbDiskIOIteratorByDataDelete::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbDiskIOIteratorByDataDelete::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbDiskIO *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbDiskIOIteratorByDataDelete::UpdateCurrent(CWriteableSysMdbDiskIO * pByDataDelete,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbDiskIO *)(m_pCurrent->pObject),pByDataDelete,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDataDeleteForSysMdbDiskIO;
#endif

CSysMdbDiskIO *CSysMdbDiskIOIteratorByDataDelete::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbDiskIO++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbDiskIO *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbDiskIO *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbDiskIOIteratorByDataDelete::match(CSysMdbDiskIO *pSysMdbDiskIO)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbDiskIO->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysMdbStatInfoIteratorByHostName> CSysMdbStatInfoIteratorByHostName::iteratorList;
void CSysMdbStatInfoIteratorByHostName::init(CSysMdbStatInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbStatInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbStatInfoIteratorByHostName *CSysMdbStatInfoIteratorByHostName::alloc(CSysMdbStatInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbStatInfoIteratorByHostName *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID,MonDate,MonTime);
	return it;
}

CSysMdbStatInfoIteratorByHostName::~CSysMdbStatInfoIteratorByHostName(void)
{
}

void CSysMdbStatInfoIteratorByHostName::free(void)
{
	iteratorList.free(this);
}

void CSysMdbStatInfoIteratorByHostName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbStatInfoIteratorByHostName");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbStatInfoIteratorByHostName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbStatInfoIteratorByHostName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbStatInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbStatInfoIteratorByHostName::UpdateCurrent(CWriteableSysMdbStatInfo * pByHostName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbStatInfo *)(m_pCurrent->pObject),pByHostName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByHostNameForSysMdbStatInfo;
#endif

CSysMdbStatInfo *CSysMdbStatInfoIteratorByHostName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbStatInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbStatInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbStatInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbStatInfoIteratorByHostName::match(CSysMdbStatInfo *pSysMdbStatInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbStatInfo->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbStatInfoIteratorByDsc> CSysMdbStatInfoIteratorByDsc::iteratorList;
void CSysMdbStatInfoIteratorByDsc::init(CSysMdbStatInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbStatInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysMdbStatInfoIteratorByDsc *CSysMdbStatInfoIteratorByDsc::alloc(CSysMdbStatInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID)
{
	CSysMdbStatInfoIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID);
	return it;
}

CSysMdbStatInfoIteratorByDsc::~CSysMdbStatInfoIteratorByDsc(void)
{
}

void CSysMdbStatInfoIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysMdbStatInfoIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbStatInfoIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
}

void CSysMdbStatInfoIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbStatInfoIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbStatInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbStatInfoIteratorByDsc::UpdateCurrent(CWriteableSysMdbStatInfo * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbStatInfo *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysMdbStatInfo;
#endif

CSysMdbStatInfo *CSysMdbStatInfoIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbStatInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbStatInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbStatInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbStatInfoIteratorByDsc::match(CSysMdbStatInfo *pSysMdbStatInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbStatInfo->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbStatInfoIteratorBytheAll> CSysMdbStatInfoIteratorBytheAll::iteratorList;
void CSysMdbStatInfoIteratorBytheAll::init(CSysMdbStatInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbStatInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID="";

}

CSysMdbStatInfoIteratorBytheAll *CSysMdbStatInfoIteratorBytheAll::alloc(CSysMdbStatInfoFactory *pFactory
		)
{
	CSysMdbStatInfoIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMdbStatInfoIteratorBytheAll::~CSysMdbStatInfoIteratorBytheAll(void)
{
}

void CSysMdbStatInfoIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbStatInfoIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbStatInfoIteratorBytheAll");
	
	
}

void CSysMdbStatInfoIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbStatInfoIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbStatInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbStatInfoIteratorBytheAll::UpdateCurrent(CWriteableSysMdbStatInfo * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbStatInfo *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysMdbStatInfo;
#endif

CSysMdbStatInfo *CSysMdbStatInfoIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbStatInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbStatInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbStatInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbStatInfoIteratorBytheAll::match(CSysMdbStatInfo *pSysMdbStatInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysMdbStatInfoIteratorByDataDelete> CSysMdbStatInfoIteratorByDataDelete::iteratorList;
void CSysMdbStatInfoIteratorByDataDelete::init(CSysMdbStatInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbStatInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate=MonDate.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbStatInfoIteratorByDataDelete *CSysMdbStatInfoIteratorByDataDelete::alloc(CSysMdbStatInfoFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID, const CReadOnlyDateType& MonDate, const CReadOnlyTimeType& MonTime)
{
	CSysMdbStatInfoIteratorByDataDelete *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID,MonDate,MonTime);
	return it;
}

CSysMdbStatInfoIteratorByDataDelete::~CSysMdbStatInfoIteratorByDataDelete(void)
{
}

void CSysMdbStatInfoIteratorByDataDelete::free(void)
{
	iteratorList.free(this);
}

void CSysMdbStatInfoIteratorByDataDelete::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbStatInfoIteratorByDataDelete");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
	m_compareObject.MonDate.getString(buffer);
	pLogger->output(indent+1,0,"query MonDate=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbStatInfoIteratorByDataDelete::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbStatInfoIteratorByDataDelete::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbStatInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbStatInfoIteratorByDataDelete::UpdateCurrent(CWriteableSysMdbStatInfo * pByDataDelete,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbStatInfo *)(m_pCurrent->pObject),pByDataDelete,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDataDeleteForSysMdbStatInfo;
#endif

CSysMdbStatInfo *CSysMdbStatInfoIteratorByDataDelete::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbStatInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbStatInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbStatInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbStatInfoIteratorByDataDelete::match(CSysMdbStatInfo *pSysMdbStatInfo)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbStatInfo->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex> CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex::iteratorList;
void CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex::init(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		, const CReadOnlyTypeObjectIDType& ObjectID, const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbTradeFrontOrderRttStatIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID=ObjectID.getValue();
	m_compareObject.MonTime=MonTime.getValue();

}

CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex *CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex::alloc(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		, const CReadOnlyTypeObjectIDType& ObjectID, const CReadOnlyTimeType& MonTime)
{
	CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex *it;
	it=iteratorList.alloc();
	it->init(pFactory,ObjectID,MonTime);
	return it;
}

CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex::~CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex(void)
{
}

void CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex::free(void)
{
	iteratorList.free(this);
}

void CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex");
	
	char buffer[200];
	
	m_compareObject.ObjectID.getString(buffer);
	pLogger->output(indent+1,0,"query ObjectID=%s",buffer);
	
	m_compareObject.MonTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonTime=%s",buffer);
	
}

void CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbTradeFrontOrderRttStat *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex::UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pByFrontIndex,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbTradeFrontOrderRttStat *)(m_pCurrent->pObject),pByFrontIndex,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByFrontIndexForSysMdbTradeFrontOrderRttStat;
#endif

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByFrontIndexForSysMdbTradeFrontOrderRttStat++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbTradeFrontOrderRttStat *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbTradeFrontOrderRttStat *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex::match(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbTradeFrontOrderRttStat->ObjectID.getValue(),m_compareObject.ObjectID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbTradeFrontOrderRttStatIteratorByDsc> CSysMdbTradeFrontOrderRttStatIteratorByDsc::iteratorList;
void CSysMdbTradeFrontOrderRttStatIteratorByDsc::init(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbTradeFrontOrderRttStatIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SubcriberID=SubcriberID.getValue();
	m_compareObject.MonDate="zzzzzzzz";
	m_compareObject.MonTime="zzzzzzzz";

}

CSysMdbTradeFrontOrderRttStatIteratorByDsc *CSysMdbTradeFrontOrderRttStatIteratorByDsc::alloc(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		, const CReadOnlyVolumeType& SubcriberID)
{
	CSysMdbTradeFrontOrderRttStatIteratorByDsc *it;
	it=iteratorList.alloc();
	it->init(pFactory,SubcriberID);
	return it;
}

CSysMdbTradeFrontOrderRttStatIteratorByDsc::~CSysMdbTradeFrontOrderRttStatIteratorByDsc(void)
{
}

void CSysMdbTradeFrontOrderRttStatIteratorByDsc::free(void)
{
	iteratorList.free(this);
}

void CSysMdbTradeFrontOrderRttStatIteratorByDsc::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbTradeFrontOrderRttStatIteratorByDsc");
	
	char buffer[200];
	
	m_compareObject.SubcriberID.getString(buffer);
	pLogger->output(indent+1,0,"query SubcriberID=%s",buffer);
	
}

void CSysMdbTradeFrontOrderRttStatIteratorByDsc::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pDecIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pDecIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbTradeFrontOrderRttStatIteratorByDsc::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbTradeFrontOrderRttStat *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbTradeFrontOrderRttStatIteratorByDsc::UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pByDsc,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbTradeFrontOrderRttStat *)(m_pCurrent->pObject),pByDsc,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDscForSysMdbTradeFrontOrderRttStat;
#endif

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatIteratorByDsc::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTradeFrontOrderRttStat++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbTradeFrontOrderRttStat *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbTradeFrontOrderRttStat *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbTradeFrontOrderRttStatIteratorByDsc::match(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pSysMdbTradeFrontOrderRttStat->SubcriberID.getValue(),m_compareObject.SubcriberID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CSysMdbTradeFrontOrderRttStatIteratorBytheAll> CSysMdbTradeFrontOrderRttStatIteratorBytheAll::iteratorList;
void CSysMdbTradeFrontOrderRttStatIteratorBytheAll::init(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMdbTradeFrontOrderRttStatIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ObjectID="";
	m_compareObject.MonTime="";

}

CSysMdbTradeFrontOrderRttStatIteratorBytheAll *CSysMdbTradeFrontOrderRttStatIteratorBytheAll::alloc(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		)
{
	CSysMdbTradeFrontOrderRttStatIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMdbTradeFrontOrderRttStatIteratorBytheAll::~CSysMdbTradeFrontOrderRttStatIteratorBytheAll(void)
{
}

void CSysMdbTradeFrontOrderRttStatIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysMdbTradeFrontOrderRttStatIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMdbTradeFrontOrderRttStatIteratorBytheAll");
	
	
}

void CSysMdbTradeFrontOrderRttStatIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysHostNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysHostNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMdbTradeFrontOrderRttStatIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMdbTradeFrontOrderRttStat *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMdbTradeFrontOrderRttStatIteratorBytheAll::UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMdbTradeFrontOrderRttStat *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysMdbTradeFrontOrderRttStat;
#endif

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTradeFrontOrderRttStat++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMdbTradeFrontOrderRttStat *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMdbTradeFrontOrderRttStat *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMdbTradeFrontOrderRttStatIteratorBytheAll::match(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysInstrumentStatusIteratorByActionTime> CSysInstrumentStatusIteratorByActionTime::iteratorList;
void CSysInstrumentStatusIteratorByActionTime::init(CSysInstrumentStatusFactory *pFactory
		, const CReadOnlyTimeType& EnterTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysInstrumentStatusIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.EnterTime=EnterTime.getValue();

}

CSysInstrumentStatusIteratorByActionTime *CSysInstrumentStatusIteratorByActionTime::alloc(CSysInstrumentStatusFactory *pFactory
		, const CReadOnlyTimeType& EnterTime)
{
	CSysInstrumentStatusIteratorByActionTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,EnterTime);
	return it;
}

CSysInstrumentStatusIteratorByActionTime::~CSysInstrumentStatusIteratorByActionTime(void)
{
}

void CSysInstrumentStatusIteratorByActionTime::free(void)
{
	iteratorList.free(this);
}

void CSysInstrumentStatusIteratorByActionTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysInstrumentStatusIteratorByActionTime");
	
	char buffer[200];
	
	m_compareObject.EnterTime.getString(buffer);
	pLogger->output(indent+1,0,"query EnterTime=%s",buffer);
	
}

void CSysInstrumentStatusIteratorByActionTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTradeTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTradeTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysInstrumentStatusIteratorByActionTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysInstrumentStatus *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysInstrumentStatusIteratorByActionTime::UpdateCurrent(CWriteableSysInstrumentStatus * pByActionTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysInstrumentStatus *)(m_pCurrent->pObject),pByActionTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByActionTimeForSysInstrumentStatus;
#endif

CSysInstrumentStatus *CSysInstrumentStatusIteratorByActionTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysInstrumentStatus++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysInstrumentStatus *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysInstrumentStatus *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysInstrumentStatusIteratorByActionTime::match(CSysInstrumentStatus *pSysInstrumentStatus)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysInstrumentStatusIteratorBytheAll> CSysInstrumentStatusIteratorBytheAll::iteratorList;
void CSysInstrumentStatusIteratorBytheAll::init(CSysInstrumentStatusFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysInstrumentStatusIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.EnterTime="";

}

CSysInstrumentStatusIteratorBytheAll *CSysInstrumentStatusIteratorBytheAll::alloc(CSysInstrumentStatusFactory *pFactory
		)
{
	CSysInstrumentStatusIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysInstrumentStatusIteratorBytheAll::~CSysInstrumentStatusIteratorBytheAll(void)
{
}

void CSysInstrumentStatusIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysInstrumentStatusIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysInstrumentStatusIteratorBytheAll");
	
	
}

void CSysInstrumentStatusIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTradeTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTradeTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysInstrumentStatusIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysInstrumentStatus *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysInstrumentStatusIteratorBytheAll::UpdateCurrent(CWriteableSysInstrumentStatus * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysInstrumentStatus *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysInstrumentStatus;
#endif

CSysInstrumentStatus *CSysInstrumentStatusIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysInstrumentStatus++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysInstrumentStatus *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysInstrumentStatus *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysInstrumentStatusIteratorBytheAll::match(CSysInstrumentStatus *pSysInstrumentStatus)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysCurrTradingSegmentAttrIteratorByActionTime> CSysCurrTradingSegmentAttrIteratorByActionTime::iteratorList;
void CSysCurrTradingSegmentAttrIteratorByActionTime::init(CSysCurrTradingSegmentAttrFactory *pFactory
		, const CReadOnlyTimeType& StartTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysCurrTradingSegmentAttrIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.StartTime=StartTime.getValue();

}

CSysCurrTradingSegmentAttrIteratorByActionTime *CSysCurrTradingSegmentAttrIteratorByActionTime::alloc(CSysCurrTradingSegmentAttrFactory *pFactory
		, const CReadOnlyTimeType& StartTime)
{
	CSysCurrTradingSegmentAttrIteratorByActionTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,StartTime);
	return it;
}

CSysCurrTradingSegmentAttrIteratorByActionTime::~CSysCurrTradingSegmentAttrIteratorByActionTime(void)
{
}

void CSysCurrTradingSegmentAttrIteratorByActionTime::free(void)
{
	iteratorList.free(this);
}

void CSysCurrTradingSegmentAttrIteratorByActionTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysCurrTradingSegmentAttrIteratorByActionTime");
	
	char buffer[200];
	
	m_compareObject.StartTime.getString(buffer);
	pLogger->output(indent+1,0,"query StartTime=%s",buffer);
	
}

void CSysCurrTradingSegmentAttrIteratorByActionTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTradeTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTradeTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysCurrTradingSegmentAttrIteratorByActionTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysCurrTradingSegmentAttr *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysCurrTradingSegmentAttrIteratorByActionTime::UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pByActionTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysCurrTradingSegmentAttr *)(m_pCurrent->pObject),pByActionTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByActionTimeForSysCurrTradingSegmentAttr;
#endif

CSysCurrTradingSegmentAttr *CSysCurrTradingSegmentAttrIteratorByActionTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysCurrTradingSegmentAttr++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysCurrTradingSegmentAttr *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysCurrTradingSegmentAttr *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysCurrTradingSegmentAttrIteratorByActionTime::match(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysCurrTradingSegmentAttrIteratorBytheAll> CSysCurrTradingSegmentAttrIteratorBytheAll::iteratorList;
void CSysCurrTradingSegmentAttrIteratorBytheAll::init(CSysCurrTradingSegmentAttrFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysCurrTradingSegmentAttrIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.StartTime="";

}

CSysCurrTradingSegmentAttrIteratorBytheAll *CSysCurrTradingSegmentAttrIteratorBytheAll::alloc(CSysCurrTradingSegmentAttrFactory *pFactory
		)
{
	CSysCurrTradingSegmentAttrIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysCurrTradingSegmentAttrIteratorBytheAll::~CSysCurrTradingSegmentAttrIteratorBytheAll(void)
{
}

void CSysCurrTradingSegmentAttrIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysCurrTradingSegmentAttrIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysCurrTradingSegmentAttrIteratorBytheAll");
	
	
}

void CSysCurrTradingSegmentAttrIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysTradeTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysTradeTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysCurrTradingSegmentAttrIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysCurrTradingSegmentAttr *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysCurrTradingSegmentAttrIteratorBytheAll::UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysCurrTradingSegmentAttr *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysCurrTradingSegmentAttr;
#endif

CSysCurrTradingSegmentAttr *CSysCurrTradingSegmentAttrIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysCurrTradingSegmentAttr++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysCurrTradingSegmentAttr *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysCurrTradingSegmentAttr *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysCurrTradingSegmentAttrIteratorBytheAll::match(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysMemberLinkCostIteratorByPayTime> CSysMemberLinkCostIteratorByPayTime::iteratorList;
void CSysMemberLinkCostIteratorByPayTime::init(CSysMemberLinkCostFactory *pFactory
		, const CReadOnlyCfgNameType& Pay_Date)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMemberLinkCostIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.Pay_Date=Pay_Date.getValue();

}

CSysMemberLinkCostIteratorByPayTime *CSysMemberLinkCostIteratorByPayTime::alloc(CSysMemberLinkCostFactory *pFactory
		, const CReadOnlyCfgNameType& Pay_Date)
{
	CSysMemberLinkCostIteratorByPayTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,Pay_Date);
	return it;
}

CSysMemberLinkCostIteratorByPayTime::~CSysMemberLinkCostIteratorByPayTime(void)
{
}

void CSysMemberLinkCostIteratorByPayTime::free(void)
{
	iteratorList.free(this);
}

void CSysMemberLinkCostIteratorByPayTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMemberLinkCostIteratorByPayTime");
	
	char buffer[200];
	
	m_compareObject.Pay_Date.getString(buffer);
	pLogger->output(indent+1,0,"query Pay_Date=%s",buffer);
	
}

void CSysMemberLinkCostIteratorByPayTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysPayTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysPayTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMemberLinkCostIteratorByPayTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMemberLinkCost *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMemberLinkCostIteratorByPayTime::UpdateCurrent(CWriteableSysMemberLinkCost * pByPayTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMemberLinkCost *)(m_pCurrent->pObject),pByPayTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByPayTimeForSysMemberLinkCost;
#endif

CSysMemberLinkCost *CSysMemberLinkCostIteratorByPayTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByPayTimeForSysMemberLinkCost++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMemberLinkCost *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMemberLinkCost *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMemberLinkCostIteratorByPayTime::match(CSysMemberLinkCost *pSysMemberLinkCost)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysMemberLinkCostIteratorBytheAll> CSysMemberLinkCostIteratorBytheAll::iteratorList;
void CSysMemberLinkCostIteratorBytheAll::init(CSysMemberLinkCostFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMemberLinkCostIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.Pay_Date="";

}

CSysMemberLinkCostIteratorBytheAll *CSysMemberLinkCostIteratorBytheAll::alloc(CSysMemberLinkCostFactory *pFactory
		)
{
	CSysMemberLinkCostIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMemberLinkCostIteratorBytheAll::~CSysMemberLinkCostIteratorBytheAll(void)
{
}

void CSysMemberLinkCostIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysMemberLinkCostIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMemberLinkCostIteratorBytheAll");
	
	
}

void CSysMemberLinkCostIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysPayTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysPayTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMemberLinkCostIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMemberLinkCost *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMemberLinkCostIteratorBytheAll::UpdateCurrent(CWriteableSysMemberLinkCost * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMemberLinkCost *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysMemberLinkCost;
#endif

CSysMemberLinkCost *CSysMemberLinkCostIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMemberLinkCost++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMemberLinkCost *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMemberLinkCost *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMemberLinkCostIteratorBytheAll::match(CSysMemberLinkCost *pSysMemberLinkCost)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysMemberLinkCostIteratorByAll> CSysMemberLinkCostIteratorByAll::iteratorList;
void CSysMemberLinkCostIteratorByAll::init(CSysMemberLinkCostFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysMemberLinkCostIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.Pay_Date="";

}

CSysMemberLinkCostIteratorByAll *CSysMemberLinkCostIteratorByAll::alloc(CSysMemberLinkCostFactory *pFactory
		)
{
	CSysMemberLinkCostIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysMemberLinkCostIteratorByAll::~CSysMemberLinkCostIteratorByAll(void)
{
}

void CSysMemberLinkCostIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysMemberLinkCostIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysMemberLinkCostIteratorByAll");
	
	
}

void CSysMemberLinkCostIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysPayTimeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysPayTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysMemberLinkCostIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysMemberLinkCost *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysMemberLinkCostIteratorByAll::UpdateCurrent(CWriteableSysMemberLinkCost * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysMemberLinkCost *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysMemberLinkCost;
#endif

CSysMemberLinkCost *CSysMemberLinkCostIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysMemberLinkCost++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysMemberLinkCost *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysMemberLinkCost *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysMemberLinkCostIteratorByAll::match(CSysMemberLinkCost *pSysMemberLinkCost)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetPartylinkMonthlyRentIteratorByLineName> CSysNetPartylinkMonthlyRentIteratorByLineName::iteratorList;
void CSysNetPartylinkMonthlyRentIteratorByLineName::init(CSysNetPartylinkMonthlyRentFactory *pFactory
		, const CReadOnlyParticipantNameType& LineName)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetPartylinkMonthlyRentIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.LineName=LineName.getValue();

}

CSysNetPartylinkMonthlyRentIteratorByLineName *CSysNetPartylinkMonthlyRentIteratorByLineName::alloc(CSysNetPartylinkMonthlyRentFactory *pFactory
		, const CReadOnlyParticipantNameType& LineName)
{
	CSysNetPartylinkMonthlyRentIteratorByLineName *it;
	it=iteratorList.alloc();
	it->init(pFactory,LineName);
	return it;
}

CSysNetPartylinkMonthlyRentIteratorByLineName::~CSysNetPartylinkMonthlyRentIteratorByLineName(void)
{
}

void CSysNetPartylinkMonthlyRentIteratorByLineName::free(void)
{
	iteratorList.free(this);
}

void CSysNetPartylinkMonthlyRentIteratorByLineName::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetPartylinkMonthlyRentIteratorByLineName");
	
	char buffer[200];
	
	m_compareObject.LineName.getString(buffer);
	pLogger->output(indent+1,0,"query LineName=%s",buffer);
	
}

void CSysNetPartylinkMonthlyRentIteratorByLineName::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysLineNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysLineNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetPartylinkMonthlyRentIteratorByLineName::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetPartylinkMonthlyRent *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetPartylinkMonthlyRentIteratorByLineName::UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pByLineName,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetPartylinkMonthlyRent *)(m_pCurrent->pObject),pByLineName,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByLineNameForSysNetPartylinkMonthlyRent;
#endif

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentIteratorByLineName::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByLineNameForSysNetPartylinkMonthlyRent++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetPartylinkMonthlyRent *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetPartylinkMonthlyRent *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetPartylinkMonthlyRentIteratorByLineName::match(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysNetPartylinkMonthlyRentIteratorBytheAll> CSysNetPartylinkMonthlyRentIteratorBytheAll::iteratorList;
void CSysNetPartylinkMonthlyRentIteratorBytheAll::init(CSysNetPartylinkMonthlyRentFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetPartylinkMonthlyRentIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.LineName="";

}

CSysNetPartylinkMonthlyRentIteratorBytheAll *CSysNetPartylinkMonthlyRentIteratorBytheAll::alloc(CSysNetPartylinkMonthlyRentFactory *pFactory
		)
{
	CSysNetPartylinkMonthlyRentIteratorBytheAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetPartylinkMonthlyRentIteratorBytheAll::~CSysNetPartylinkMonthlyRentIteratorBytheAll(void)
{
}

void CSysNetPartylinkMonthlyRentIteratorBytheAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetPartylinkMonthlyRentIteratorBytheAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetPartylinkMonthlyRentIteratorBytheAll");
	
	
}

void CSysNetPartylinkMonthlyRentIteratorBytheAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysLineNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysLineNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetPartylinkMonthlyRentIteratorBytheAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetPartylinkMonthlyRent *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetPartylinkMonthlyRentIteratorBytheAll::UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pBytheAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetPartylinkMonthlyRent *)(m_pCurrent->pObject),pBytheAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBytheAllForSysNetPartylinkMonthlyRent;
#endif

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentIteratorBytheAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBytheAllForSysNetPartylinkMonthlyRent++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetPartylinkMonthlyRent *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetPartylinkMonthlyRent *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetPartylinkMonthlyRentIteratorBytheAll::match(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CSysNetPartylinkMonthlyRentIteratorByAll> CSysNetPartylinkMonthlyRentIteratorByAll::iteratorList;
void CSysNetPartylinkMonthlyRentIteratorByAll::init(CSysNetPartylinkMonthlyRentFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetPartylinkMonthlyRentIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.LineName="";

}

CSysNetPartylinkMonthlyRentIteratorByAll *CSysNetPartylinkMonthlyRentIteratorByAll::alloc(CSysNetPartylinkMonthlyRentFactory *pFactory
		)
{
	CSysNetPartylinkMonthlyRentIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetPartylinkMonthlyRentIteratorByAll::~CSysNetPartylinkMonthlyRentIteratorByAll(void)
{
}

void CSysNetPartylinkMonthlyRentIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetPartylinkMonthlyRentIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetPartylinkMonthlyRentIteratorByAll");
	
	
}

void CSysNetPartylinkMonthlyRentIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysLineNameIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysLineNameIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetPartylinkMonthlyRentIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetPartylinkMonthlyRent *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetPartylinkMonthlyRentIteratorByAll::UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetPartylinkMonthlyRent *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetPartylinkMonthlyRent;
#endif

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPartylinkMonthlyRent++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetPartylinkMonthlyRent *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetPartylinkMonthlyRent *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetPartylinkMonthlyRentIteratorByAll::match(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CSysNetNonPartyLinkInfoIteratorByAll> CSysNetNonPartyLinkInfoIteratorByAll::iteratorList;
void CSysNetNonPartyLinkInfoIteratorByAll::init(CSysNetNonPartyLinkInfoFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSysNetNonPartyLinkInfoIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ID=0;

}

CSysNetNonPartyLinkInfoIteratorByAll *CSysNetNonPartyLinkInfoIteratorByAll::alloc(CSysNetNonPartyLinkInfoFactory *pFactory
		)
{
	CSysNetNonPartyLinkInfoIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CSysNetNonPartyLinkInfoIteratorByAll::~CSysNetNonPartyLinkInfoIteratorByAll(void)
{
}

void CSysNetNonPartyLinkInfoIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CSysNetNonPartyLinkInfoIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSysNetNonPartyLinkInfoIteratorByAll");
	
	
}

void CSysNetNonPartyLinkInfoIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSysIDTypeIndex->searchFirstGreatEqual(&m_compareObject);

		///设置非第一次标志
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///已经找到最后一个了
			m_pNext=NULL;
		}
		else
		{
			///在索引找下一个节点
			m_pNext=m_Factory->pSysIDTypeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSysNetNonPartyLinkInfoIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSysNetNonPartyLinkInfo *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSysNetNonPartyLinkInfoIteratorByAll::UpdateCurrent(CWriteableSysNetNonPartyLinkInfo * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	if (updateIndex)
	{
		///要更新索引，那就必须预取下一个
		internalGetNext();
	}
	m_Factory->update((CSysNetNonPartyLinkInfo *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForSysNetNonPartyLinkInfo;
#endif

CSysNetNonPartyLinkInfo *CSysNetNonPartyLinkInfoIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForSysNetNonPartyLinkInfo++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSysNetNonPartyLinkInfo *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSysNetNonPartyLinkInfo *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSysNetNonPartyLinkInfoIteratorByAll::match(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


