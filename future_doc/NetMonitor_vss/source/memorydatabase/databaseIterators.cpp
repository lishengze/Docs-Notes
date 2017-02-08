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


CMemoryStack<CSGDataSyncStatusIteratorStartBySettlementGroupID> CSGDataSyncStatusIteratorStartBySettlementGroupID::iteratorList;
void CSGDataSyncStatusIteratorStartBySettlementGroupID::init(CSGDataSyncStatusFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CSGDataSyncStatusIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CSGDataSyncStatusIteratorStartBySettlementGroupID *CSGDataSyncStatusIteratorStartBySettlementGroupID::alloc(CSGDataSyncStatusFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CSGDataSyncStatusIteratorStartBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CSGDataSyncStatusIteratorStartBySettlementGroupID::~CSGDataSyncStatusIteratorStartBySettlementGroupID(void)
{
}

void CSGDataSyncStatusIteratorStartBySettlementGroupID::free(void)
{
	iteratorList.free(this);
}

void CSGDataSyncStatusIteratorStartBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CSGDataSyncStatusIteratorStartBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CSGDataSyncStatusIteratorStartBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSettlementGroupIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pSettlementGroupIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CSGDataSyncStatusIteratorStartBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CSGDataSyncStatus *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CSGDataSyncStatusIteratorStartBySettlementGroupID::UpdateCurrent(CWriteableSGDataSyncStatus * pStartBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CSGDataSyncStatus *)(m_pCurrent->pObject),pStartBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartBySettlementGroupIDForSGDataSyncStatus;
#endif

CSGDataSyncStatus *CSGDataSyncStatusIteratorStartBySettlementGroupID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartBySettlementGroupIDForSGDataSyncStatus++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CSGDataSyncStatus *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CSGDataSyncStatus *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CSGDataSyncStatusIteratorStartBySettlementGroupID::match(CSGDataSyncStatus *pSGDataSyncStatus)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}







CMemoryStack<CMarketProductIteratorByProductID> CMarketProductIteratorByProductID::iteratorList;
void CMarketProductIteratorByProductID::init(CMarketProductFactory *pFactory
		, const CReadOnlyProductIDType& ProductID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CMarketProductIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ProductID=ProductID.getValue();

}

CMarketProductIteratorByProductID *CMarketProductIteratorByProductID::alloc(CMarketProductFactory *pFactory
		, const CReadOnlyProductIDType& ProductID)
{
	CMarketProductIteratorByProductID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ProductID);
	return it;
}

CMarketProductIteratorByProductID::~CMarketProductIteratorByProductID(void)
{
}

void CMarketProductIteratorByProductID::free(void)
{
	iteratorList.free(this);
}

void CMarketProductIteratorByProductID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CMarketProductIteratorByProductID");
	
	char buffer[200];
	
	m_compareObject.ProductID.getString(buffer);
	pLogger->output(indent+1,0,"query ProductID=%s",buffer);
	
}

void CMarketProductIteratorByProductID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pProductIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pProductIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CMarketProductIteratorByProductID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CMarketProduct *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CMarketProductIteratorByProductID::UpdateCurrent(CWriteableMarketProduct * pByProductID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CMarketProduct *)(m_pCurrent->pObject),pByProductID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByProductIDForMarketProduct;
#endif

CMarketProduct *CMarketProductIteratorByProductID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByProductIDForMarketProduct++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CMarketProduct *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CMarketProduct *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CMarketProductIteratorByProductID::match(CMarketProduct *pMarketProduct)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pMarketProduct->ProductID.getValue(),m_compareObject.ProductID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CMarketProductGroupIteratorByProductGroupID> CMarketProductGroupIteratorByProductGroupID::iteratorList;
void CMarketProductGroupIteratorByProductGroupID::init(CMarketProductGroupFactory *pFactory
		, const CReadOnlyProductGroupIDType& ProductGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CMarketProductGroupIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ProductGroupID=ProductGroupID.getValue();

}

CMarketProductGroupIteratorByProductGroupID *CMarketProductGroupIteratorByProductGroupID::alloc(CMarketProductGroupFactory *pFactory
		, const CReadOnlyProductGroupIDType& ProductGroupID)
{
	CMarketProductGroupIteratorByProductGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ProductGroupID);
	return it;
}

CMarketProductGroupIteratorByProductGroupID::~CMarketProductGroupIteratorByProductGroupID(void)
{
}

void CMarketProductGroupIteratorByProductGroupID::free(void)
{
	iteratorList.free(this);
}

void CMarketProductGroupIteratorByProductGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CMarketProductGroupIteratorByProductGroupID");
	
	char buffer[200];
	
	m_compareObject.ProductGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query ProductGroupID=%s",buffer);
	
}

void CMarketProductGroupIteratorByProductGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pProductGroupIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pProductGroupIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CMarketProductGroupIteratorByProductGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CMarketProductGroup *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CMarketProductGroupIteratorByProductGroupID::UpdateCurrent(CWriteableMarketProductGroup * pByProductGroupID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CMarketProductGroup *)(m_pCurrent->pObject),pByProductGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByProductGroupIDForMarketProductGroup;
#endif

CMarketProductGroup *CMarketProductGroupIteratorByProductGroupID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByProductGroupIDForMarketProductGroup++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CMarketProductGroup *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CMarketProductGroup *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CMarketProductGroupIteratorByProductGroupID::match(CMarketProductGroup *pMarketProductGroup)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pMarketProductGroup->ProductGroupID.getValue(),m_compareObject.ProductGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}



CMemoryStack<CMarketDataTopicIteratorByMarketID> CMarketDataTopicIteratorByMarketID::iteratorList;
void CMarketDataTopicIteratorByMarketID::init(CMarketDataTopicFactory *pFactory
		, const CReadOnlyMarketIDType& MarketID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CMarketDataTopicIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MarketID=MarketID.getValue();

}

CMarketDataTopicIteratorByMarketID *CMarketDataTopicIteratorByMarketID::alloc(CMarketDataTopicFactory *pFactory
		, const CReadOnlyMarketIDType& MarketID)
{
	CMarketDataTopicIteratorByMarketID *it;
	it=iteratorList.alloc();
	it->init(pFactory,MarketID);
	return it;
}

CMarketDataTopicIteratorByMarketID::~CMarketDataTopicIteratorByMarketID(void)
{
}

void CMarketDataTopicIteratorByMarketID::free(void)
{
	iteratorList.free(this);
}

void CMarketDataTopicIteratorByMarketID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CMarketDataTopicIteratorByMarketID");
	
	char buffer[200];
	
	m_compareObject.MarketID.getString(buffer);
	pLogger->output(indent+1,0,"query MarketID=%s",buffer);
	
}

void CMarketDataTopicIteratorByMarketID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pMarketIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pMarketIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CMarketDataTopicIteratorByMarketID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CMarketDataTopic *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CMarketDataTopicIteratorByMarketID::UpdateCurrent(CWriteableMarketDataTopic * pByMarketID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CMarketDataTopic *)(m_pCurrent->pObject),pByMarketID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByMarketIDForMarketDataTopic;
#endif

CMarketDataTopic *CMarketDataTopicIteratorByMarketID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByMarketIDForMarketDataTopic++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CMarketDataTopic *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CMarketDataTopic *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CMarketDataTopicIteratorByMarketID::match(CMarketDataTopic *pMarketDataTopic)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pMarketDataTopic->MarketID.getValue(),m_compareObject.MarketID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CPartTopicSubscribeIteratorByPartID> CPartTopicSubscribeIteratorByPartID::iteratorList;
void CPartTopicSubscribeIteratorByPartID::init(CPartTopicSubscribeFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CPartTopicSubscribeIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID=ParticipantID.getValue();
	m_compareObject.TopicID=0;

}

CPartTopicSubscribeIteratorByPartID *CPartTopicSubscribeIteratorByPartID::alloc(CPartTopicSubscribeFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	CPartTopicSubscribeIteratorByPartID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ParticipantID);
	return it;
}

CPartTopicSubscribeIteratorByPartID::~CPartTopicSubscribeIteratorByPartID(void)
{
}

void CPartTopicSubscribeIteratorByPartID::free(void)
{
	iteratorList.free(this);
}

void CPartTopicSubscribeIteratorByPartID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CPartTopicSubscribeIteratorByPartID");
	
	char buffer[200];
	
	m_compareObject.ParticipantID.getString(buffer);
	pLogger->output(indent+1,0,"query ParticipantID=%s",buffer);
	
}

void CPartTopicSubscribeIteratorByPartID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pPartIDTopicIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pPartIDTopicIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CPartTopicSubscribeIteratorByPartID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CPartTopicSubscribe *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CPartTopicSubscribeIteratorByPartID::UpdateCurrent(CWriteablePartTopicSubscribe * pByPartID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CPartTopicSubscribe *)(m_pCurrent->pObject),pByPartID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByPartIDForPartTopicSubscribe;
#endif

CPartTopicSubscribe *CPartTopicSubscribeIteratorByPartID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByPartIDForPartTopicSubscribe++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CPartTopicSubscribe *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CPartTopicSubscribe *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CPartTopicSubscribeIteratorByPartID::match(CPartTopicSubscribe *pPartTopicSubscribe)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pPartTopicSubscribe->ParticipantID.getValue(),m_compareObject.ParticipantID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CParticipantIteratorStartByParticipantID> CParticipantIteratorStartByParticipantID::iteratorList;
void CParticipantIteratorStartByParticipantID::init(CParticipantFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CParticipantIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID=ParticipantID.getValue();

}

CParticipantIteratorStartByParticipantID *CParticipantIteratorStartByParticipantID::alloc(CParticipantFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	CParticipantIteratorStartByParticipantID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ParticipantID);
	return it;
}

CParticipantIteratorStartByParticipantID::~CParticipantIteratorStartByParticipantID(void)
{
}

void CParticipantIteratorStartByParticipantID::free(void)
{
	iteratorList.free(this);
}

void CParticipantIteratorStartByParticipantID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CParticipantIteratorStartByParticipantID");
	
	char buffer[200];
	
	m_compareObject.ParticipantID.getString(buffer);
	pLogger->output(indent+1,0,"query ParticipantID=%s",buffer);
	
}

void CParticipantIteratorStartByParticipantID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pParticipantIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pParticipantIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CParticipantIteratorStartByParticipantID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CParticipant *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CParticipantIteratorStartByParticipantID::UpdateCurrent(CWriteableParticipant * pStartByParticipantID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CParticipant *)(m_pCurrent->pObject),pStartByParticipantID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByParticipantIDForParticipant;
#endif

CParticipant *CParticipantIteratorStartByParticipantID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForParticipant++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CParticipant *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CParticipant *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CParticipantIteratorStartByParticipantID::match(CParticipant *pParticipant)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CUserIteratorStartByUserID> CUserIteratorStartByUserID::iteratorList;
void CUserIteratorStartByUserID::init(CUserFactory *pFactory
		, const CReadOnlyUserIDType& UserID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CUserIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.UserID=UserID.getValue();

}

CUserIteratorStartByUserID *CUserIteratorStartByUserID::alloc(CUserFactory *pFactory
		, const CReadOnlyUserIDType& UserID)
{
	CUserIteratorStartByUserID *it;
	it=iteratorList.alloc();
	it->init(pFactory,UserID);
	return it;
}

CUserIteratorStartByUserID::~CUserIteratorStartByUserID(void)
{
}

void CUserIteratorStartByUserID::free(void)
{
	iteratorList.free(this);
}

void CUserIteratorStartByUserID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CUserIteratorStartByUserID");
	
	char buffer[200];
	
	m_compareObject.UserID.getString(buffer);
	pLogger->output(indent+1,0,"query UserID=%s",buffer);
	
}

void CUserIteratorStartByUserID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pUserIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pUserIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CUserIteratorStartByUserID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CUser *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CUserIteratorStartByUserID::UpdateCurrent(CWriteableUser * pStartByUserID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CUser *)(m_pCurrent->pObject),pStartByUserID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByUserIDForUser;
#endif

CUser *CUserIteratorStartByUserID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByUserIDForUser++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CUser *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CUser *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CUserIteratorStartByUserID::match(CUser *pUser)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}



CMemoryStack<CUserIPIteratorByUserID> CUserIPIteratorByUserID::iteratorList;
void CUserIPIteratorByUserID::init(CUserIPFactory *pFactory
		, const CReadOnlyUserIDType& UserID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CUserIPIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.UserID=UserID.getValue();
	m_compareObject.IPAddress="";
	m_compareObject.IPMask="";

}

CUserIPIteratorByUserID *CUserIPIteratorByUserID::alloc(CUserIPFactory *pFactory
		, const CReadOnlyUserIDType& UserID)
{
	CUserIPIteratorByUserID *it;
	it=iteratorList.alloc();
	it->init(pFactory,UserID);
	return it;
}

CUserIPIteratorByUserID::~CUserIPIteratorByUserID(void)
{
}

void CUserIPIteratorByUserID::free(void)
{
	iteratorList.free(this);
}

void CUserIPIteratorByUserID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CUserIPIteratorByUserID");
	
	char buffer[200];
	
	m_compareObject.UserID.getString(buffer);
	pLogger->output(indent+1,0,"query UserID=%s",buffer);
	
}

void CUserIPIteratorByUserID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pUserIPMaskIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pUserIPMaskIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CUserIPIteratorByUserID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CUserIP *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CUserIPIteratorByUserID::UpdateCurrent(CWriteableUserIP * pByUserID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CUserIP *)(m_pCurrent->pObject),pByUserID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByUserIDForUserIP;
#endif

CUserIP *CUserIPIteratorByUserID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByUserIDForUserIP++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CUserIP *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CUserIP *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CUserIPIteratorByUserID::match(CUserIP *pUserIP)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pUserIP->UserID.getValue(),m_compareObject.UserID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CPartClientIteratorStartByParticipant> CPartClientIteratorStartByParticipant::iteratorList;
void CPartClientIteratorStartByParticipant::init(CPartClientFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CPartClientIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID=ParticipantID.getValue();
	m_compareObject.ClientID="";

}

CPartClientIteratorStartByParticipant *CPartClientIteratorStartByParticipant::alloc(CPartClientFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	CPartClientIteratorStartByParticipant *it;
	it=iteratorList.alloc();
	it->init(pFactory,ParticipantID);
	return it;
}

CPartClientIteratorStartByParticipant::~CPartClientIteratorStartByParticipant(void)
{
}

void CPartClientIteratorStartByParticipant::free(void)
{
	iteratorList.free(this);
}

void CPartClientIteratorStartByParticipant::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CPartClientIteratorStartByParticipant");
	
	char buffer[200];
	
	m_compareObject.ParticipantID.getString(buffer);
	pLogger->output(indent+1,0,"query ParticipantID=%s",buffer);
	
}

void CPartClientIteratorStartByParticipant::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pPartClientIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pPartClientIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CPartClientIteratorStartByParticipant::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CPartClient *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CPartClientIteratorStartByParticipant::UpdateCurrent(CWriteablePartClient * pStartByParticipant,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CPartClient *)(m_pCurrent->pObject),pStartByParticipant,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByParticipantForPartClient;
#endif

CPartClient *CPartClientIteratorStartByParticipant::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByParticipantForPartClient++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CPartClient *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CPartClient *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CPartClientIteratorStartByParticipant::match(CPartClient *pPartClient)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CPartClientIteratorStartByClient> CPartClientIteratorStartByClient::iteratorList;
void CPartClientIteratorStartByClient::init(CPartClientFactory *pFactory
		, const CReadOnlyClientIDType& ClientID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CPartClientIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ClientID=ClientID.getValue();

}

CPartClientIteratorStartByClient *CPartClientIteratorStartByClient::alloc(CPartClientFactory *pFactory
		, const CReadOnlyClientIDType& ClientID)
{
	CPartClientIteratorStartByClient *it;
	it=iteratorList.alloc();
	it->init(pFactory,ClientID);
	return it;
}

CPartClientIteratorStartByClient::~CPartClientIteratorStartByClient(void)
{
}

void CPartClientIteratorStartByClient::free(void)
{
	iteratorList.free(this);
}

void CPartClientIteratorStartByClient::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CPartClientIteratorStartByClient");
	
	char buffer[200];
	
	m_compareObject.ClientID.getString(buffer);
	pLogger->output(indent+1,0,"query ClientID=%s",buffer);
	
}

void CPartClientIteratorStartByClient::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pClientIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pClientIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CPartClientIteratorStartByClient::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CPartClient *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CPartClientIteratorStartByClient::UpdateCurrent(CWriteablePartClient * pStartByClient,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CPartClient *)(m_pCurrent->pObject),pStartByClient,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByClientForPartClient;
#endif

CPartClient *CPartClientIteratorStartByClient::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByClientForPartClient++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CPartClient *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CPartClient *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CPartClientIteratorStartByClient::match(CPartClient *pPartClient)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}





CMemoryStack<CAccountIteratorStartByParticipantID> CAccountIteratorStartByParticipantID::iteratorList;
void CAccountIteratorStartByParticipantID::init(CAccountFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CAccountIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID=ParticipantID.getValue();

}

CAccountIteratorStartByParticipantID *CAccountIteratorStartByParticipantID::alloc(CAccountFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	CAccountIteratorStartByParticipantID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ParticipantID);
	return it;
}

CAccountIteratorStartByParticipantID::~CAccountIteratorStartByParticipantID(void)
{
}

void CAccountIteratorStartByParticipantID::free(void)
{
	iteratorList.free(this);
}

void CAccountIteratorStartByParticipantID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CAccountIteratorStartByParticipantID");
	
	char buffer[200];
	
	m_compareObject.ParticipantID.getString(buffer);
	pLogger->output(indent+1,0,"query ParticipantID=%s",buffer);
	
}

void CAccountIteratorStartByParticipantID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pParticipantIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pParticipantIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CAccountIteratorStartByParticipantID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CAccount *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CAccountIteratorStartByParticipantID::UpdateCurrent(CWriteableAccount * pStartByParticipantID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CAccount *)(m_pCurrent->pObject),pStartByParticipantID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByParticipantIDForAccount;
#endif

CAccount *CAccountIteratorStartByParticipantID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForAccount++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CAccount *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CAccount *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CAccountIteratorStartByParticipantID::match(CAccount *pAccount)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}



CMemoryStack<CMarketDataLogIteratorByMarketDataLogNo> CMarketDataLogIteratorByMarketDataLogNo::iteratorList;
void CMarketDataLogIteratorByMarketDataLogNo::init(CMarketDataLogFactory *pFactory
		, const CReadOnlySequenceNoType& MarketDataLogNo)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CMarketDataLogIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.MarketDataLogNo=MarketDataLogNo.getValue();

}

CMarketDataLogIteratorByMarketDataLogNo *CMarketDataLogIteratorByMarketDataLogNo::alloc(CMarketDataLogFactory *pFactory
		, const CReadOnlySequenceNoType& MarketDataLogNo)
{
	CMarketDataLogIteratorByMarketDataLogNo *it;
	it=iteratorList.alloc();
	it->init(pFactory,MarketDataLogNo);
	return it;
}

CMarketDataLogIteratorByMarketDataLogNo::~CMarketDataLogIteratorByMarketDataLogNo(void)
{
}

void CMarketDataLogIteratorByMarketDataLogNo::free(void)
{
	iteratorList.free(this);
}

void CMarketDataLogIteratorByMarketDataLogNo::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CMarketDataLogIteratorByMarketDataLogNo");
	
	char buffer[200];
	
	m_compareObject.MarketDataLogNo.getString(buffer);
	pLogger->output(indent+1,0,"query MarketDataLogNo=%s",buffer);
	
}

void CMarketDataLogIteratorByMarketDataLogNo::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pMarketDataLogNoIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pMarketDataLogNoIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CMarketDataLogIteratorByMarketDataLogNo::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CMarketDataLog *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CMarketDataLogIteratorByMarketDataLogNo::UpdateCurrent(CWriteableMarketDataLog * pByMarketDataLogNo,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CMarketDataLog *)(m_pCurrent->pObject),pByMarketDataLogNo,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByMarketDataLogNoForMarketDataLog;
#endif

CMarketDataLog *CMarketDataLogIteratorByMarketDataLogNo::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByMarketDataLogNoForMarketDataLog++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CMarketDataLog *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CMarketDataLog *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CMarketDataLogIteratorByMarketDataLogNo::match(CMarketDataLog *pMarketDataLog)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CUserSessionIteratorByFrontID> CUserSessionIteratorByFrontID::iteratorList;
void CUserSessionIteratorByFrontID::init(CUserSessionFactory *pFactory
		, const CReadOnlyFrontIDType& FrontID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CUserSessionIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.FrontID=FrontID.getValue();
	m_compareObject.SessionID=1<<31;

}

CUserSessionIteratorByFrontID *CUserSessionIteratorByFrontID::alloc(CUserSessionFactory *pFactory
		, const CReadOnlyFrontIDType& FrontID)
{
	CUserSessionIteratorByFrontID *it;
	it=iteratorList.alloc();
	it->init(pFactory,FrontID);
	return it;
}

CUserSessionIteratorByFrontID::~CUserSessionIteratorByFrontID(void)
{
}

void CUserSessionIteratorByFrontID::free(void)
{
	iteratorList.free(this);
}

void CUserSessionIteratorByFrontID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CUserSessionIteratorByFrontID");
	
	char buffer[200];
	
	m_compareObject.FrontID.getString(buffer);
	pLogger->output(indent+1,0,"query FrontID=%s",buffer);
	
}

void CUserSessionIteratorByFrontID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSessionIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pSessionIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CUserSessionIteratorByFrontID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CUserSession *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CUserSessionIteratorByFrontID::UpdateCurrent(CWriteableUserSession * pByFrontID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CUserSession *)(m_pCurrent->pObject),pByFrontID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByFrontIDForUserSession;
#endif

CUserSession *CUserSessionIteratorByFrontID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByFrontIDForUserSession++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CUserSession *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CUserSession *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CUserSessionIteratorByFrontID::match(CUserSession *pUserSession)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pUserSession->FrontID.getValue(),m_compareObject.FrontID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CUserSessionIteratorStartByUserID> CUserSessionIteratorStartByUserID::iteratorList;
void CUserSessionIteratorStartByUserID::init(CUserSessionFactory *pFactory
		, const CReadOnlyUserIDType& UserID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CUserSessionIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.UserID=UserID.getValue();

}

CUserSessionIteratorStartByUserID *CUserSessionIteratorStartByUserID::alloc(CUserSessionFactory *pFactory
		, const CReadOnlyUserIDType& UserID)
{
	CUserSessionIteratorStartByUserID *it;
	it=iteratorList.alloc();
	it->init(pFactory,UserID);
	return it;
}

CUserSessionIteratorStartByUserID::~CUserSessionIteratorStartByUserID(void)
{
}

void CUserSessionIteratorStartByUserID::free(void)
{
	iteratorList.free(this);
}

void CUserSessionIteratorStartByUserID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CUserSessionIteratorStartByUserID");
	
	char buffer[200];
	
	m_compareObject.UserID.getString(buffer);
	pLogger->output(indent+1,0,"query UserID=%s",buffer);
	
}

void CUserSessionIteratorStartByUserID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pUserIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pUserIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CUserSessionIteratorStartByUserID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CUserSession *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CUserSessionIteratorStartByUserID::UpdateCurrent(CWriteableUserSession * pStartByUserID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CUserSession *)(m_pCurrent->pObject),pStartByUserID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByUserIDForUserSession;
#endif

CUserSession *CUserSessionIteratorStartByUserID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByUserIDForUserSession++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CUserSession *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CUserSession *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CUserSessionIteratorStartByUserID::match(CUserSession *pUserSession)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}








CMemoryStack<CBulletinIteratorStartByBulletinID> CBulletinIteratorStartByBulletinID::iteratorList;
void CBulletinIteratorStartByBulletinID::init(CBulletinFactory *pFactory
		, const CReadOnlyBulletinIDType& BulletinID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CBulletinIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.BulletinID=BulletinID.getValue();
	m_compareObject.TradingDay="";
	m_compareObject.MarketID="";

}

CBulletinIteratorStartByBulletinID *CBulletinIteratorStartByBulletinID::alloc(CBulletinFactory *pFactory
		, const CReadOnlyBulletinIDType& BulletinID)
{
	CBulletinIteratorStartByBulletinID *it;
	it=iteratorList.alloc();
	it->init(pFactory,BulletinID);
	return it;
}

CBulletinIteratorStartByBulletinID::~CBulletinIteratorStartByBulletinID(void)
{
}

void CBulletinIteratorStartByBulletinID::free(void)
{
	iteratorList.free(this);
}

void CBulletinIteratorStartByBulletinID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CBulletinIteratorStartByBulletinID");
	
	char buffer[200];
	
	m_compareObject.BulletinID.getString(buffer);
	pLogger->output(indent+1,0,"query BulletinID=%s",buffer);
	
}

void CBulletinIteratorStartByBulletinID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pBulletinIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pBulletinIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CBulletinIteratorStartByBulletinID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CBulletin *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CBulletinIteratorStartByBulletinID::UpdateCurrent(CWriteableBulletin * pStartByBulletinID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CBulletin *)(m_pCurrent->pObject),pStartByBulletinID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByBulletinIDForBulletin;
#endif

CBulletin *CBulletinIteratorStartByBulletinID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByBulletinIDForBulletin++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CBulletin *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CBulletin *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CBulletinIteratorStartByBulletinID::match(CBulletin *pBulletin)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CMarketDataModifyIteratorBySettlementGroupID> CMarketDataModifyIteratorBySettlementGroupID::iteratorList;
void CMarketDataModifyIteratorBySettlementGroupID::init(CMarketDataModifyFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CMarketDataModifyIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CMarketDataModifyIteratorBySettlementGroupID *CMarketDataModifyIteratorBySettlementGroupID::alloc(CMarketDataModifyFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CMarketDataModifyIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CMarketDataModifyIteratorBySettlementGroupID::~CMarketDataModifyIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CMarketDataModifyIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CMarketDataModifyIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CMarketDataModifyIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CMarketDataModifyIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CMarketDataModify *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CMarketDataModify *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CMarketDataModifyIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CMarketDataModifyIteratorBySettlementGroupID::UpdateCurrent(CWriteableMarketDataModify * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForMarketDataModify;
#endif

CMarketDataModify *CMarketDataModifyIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CMarketDataModifyIteratorBySettlementGroupID::match(CMarketDataModify *pMarketDataModify)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pMarketDataModify->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CDepthMarketDataIteratorBySettlementGroupID> CDepthMarketDataIteratorBySettlementGroupID::iteratorList;
void CDepthMarketDataIteratorBySettlementGroupID::init(CDepthMarketDataFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CDepthMarketDataIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CDepthMarketDataIteratorBySettlementGroupID *CDepthMarketDataIteratorBySettlementGroupID::alloc(CDepthMarketDataFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CDepthMarketDataIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CDepthMarketDataIteratorBySettlementGroupID::~CDepthMarketDataIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CDepthMarketDataIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CDepthMarketDataIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CDepthMarketDataIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CDepthMarketDataIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CDepthMarketData *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CDepthMarketData *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CDepthMarketDataIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CDepthMarketDataIteratorBySettlementGroupID::UpdateCurrent(CWriteableDepthMarketData * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForDepthMarketData;
#endif

CDepthMarketData *CDepthMarketDataIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CDepthMarketDataIteratorBySettlementGroupID::match(CDepthMarketData *pDepthMarketData)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pDepthMarketData->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CTopicMarketDataIteratorByTopicID> CTopicMarketDataIteratorByTopicID::iteratorList;
void CTopicMarketDataIteratorByTopicID::init(CTopicMarketDataFactory *pFactory
		, const CReadOnlyTopicIDType& TopicID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CTopicMarketDataIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.TopicID=TopicID.getValue();
	m_compareObject.InstrumentID="";

}

CTopicMarketDataIteratorByTopicID *CTopicMarketDataIteratorByTopicID::alloc(CTopicMarketDataFactory *pFactory
		, const CReadOnlyTopicIDType& TopicID)
{
	CTopicMarketDataIteratorByTopicID *it;
	it=iteratorList.alloc();
	it->init(pFactory,TopicID);
	return it;
}

CTopicMarketDataIteratorByTopicID::~CTopicMarketDataIteratorByTopicID(void)
{
}

void CTopicMarketDataIteratorByTopicID::free(void)
{
	iteratorList.free(this);
}

void CTopicMarketDataIteratorByTopicID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CTopicMarketDataIteratorByTopicID");
	
	char buffer[200];
	
	m_compareObject.TopicID.getString(buffer);
	pLogger->output(indent+1,0,"query TopicID=%s",buffer);
	
}

void CTopicMarketDataIteratorByTopicID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pTopicAndInstrumentIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pTopicAndInstrumentIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CTopicMarketDataIteratorByTopicID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CTopicMarketData *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CTopicMarketDataIteratorByTopicID::UpdateCurrent(CWriteableTopicMarketData * pByTopicID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CTopicMarketData *)(m_pCurrent->pObject),pByTopicID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByTopicIDForTopicMarketData;
#endif

CTopicMarketData *CTopicMarketDataIteratorByTopicID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByTopicIDForTopicMarketData++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CTopicMarketData *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CTopicMarketData *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CTopicMarketDataIteratorByTopicID::match(CTopicMarketData *pTopicMarketData)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pTopicMarketData->TopicID.getValue(),m_compareObject.TopicID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CTopicMarketDataIteratorByInstrumentID> CTopicMarketDataIteratorByInstrumentID::iteratorList;
void CTopicMarketDataIteratorByInstrumentID::init(CTopicMarketDataFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CTopicMarketDataIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID=InstrumentID.getValue();

}

CTopicMarketDataIteratorByInstrumentID *CTopicMarketDataIteratorByInstrumentID::alloc(CTopicMarketDataFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	CTopicMarketDataIteratorByInstrumentID *it;
	it=iteratorList.alloc();
	it->init(pFactory,InstrumentID);
	return it;
}

CTopicMarketDataIteratorByInstrumentID::~CTopicMarketDataIteratorByInstrumentID(void)
{
}

void CTopicMarketDataIteratorByInstrumentID::free(void)
{
	iteratorList.free(this);
}

void CTopicMarketDataIteratorByInstrumentID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CTopicMarketDataIteratorByInstrumentID");
	
	char buffer[200];
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void CTopicMarketDataIteratorByInstrumentID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pInstrumentIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pInstrumentIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CTopicMarketDataIteratorByInstrumentID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CTopicMarketData *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CTopicMarketDataIteratorByInstrumentID::UpdateCurrent(CWriteableTopicMarketData * pByInstrumentID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CTopicMarketData *)(m_pCurrent->pObject),pByInstrumentID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByInstrumentIDForTopicMarketData;
#endif

CTopicMarketData *CTopicMarketDataIteratorByInstrumentID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByInstrumentIDForTopicMarketData++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CTopicMarketData *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CTopicMarketData *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CTopicMarketDataIteratorByInstrumentID::match(CTopicMarketData *pTopicMarketData)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pTopicMarketData->InstrumentID.getValue(),m_compareObject.InstrumentID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CTopicMarketDataIteratorBySettlementGroupID> CTopicMarketDataIteratorBySettlementGroupID::iteratorList;
void CTopicMarketDataIteratorBySettlementGroupID::init(CTopicMarketDataFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CTopicMarketDataIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CTopicMarketDataIteratorBySettlementGroupID *CTopicMarketDataIteratorBySettlementGroupID::alloc(CTopicMarketDataFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CTopicMarketDataIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CTopicMarketDataIteratorBySettlementGroupID::~CTopicMarketDataIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CTopicMarketDataIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CTopicMarketDataIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CTopicMarketDataIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CTopicMarketDataIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CTopicMarketData *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CTopicMarketData *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CTopicMarketDataIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CTopicMarketDataIteratorBySettlementGroupID::UpdateCurrent(CWriteableTopicMarketData * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForTopicMarketData;
#endif

CTopicMarketData *CTopicMarketDataIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CTopicMarketDataIteratorBySettlementGroupID::match(CTopicMarketData *pTopicMarketData)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pTopicMarketData->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CTopicMarketDataVersionIteratorByTopicAndVersion> CTopicMarketDataVersionIteratorByTopicAndVersion::iteratorList;
void CTopicMarketDataVersionIteratorByTopicAndVersion::init(CTopicMarketDataVersionFactory *pFactory
		, const CReadOnlyTopicIDType& TopicID, const CReadOnlySequenceNoType& Version)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CTopicMarketDataVersionIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.TopicID=TopicID.getValue();
	m_compareObject.Version=Version.getValue();

}

CTopicMarketDataVersionIteratorByTopicAndVersion *CTopicMarketDataVersionIteratorByTopicAndVersion::alloc(CTopicMarketDataVersionFactory *pFactory
		, const CReadOnlyTopicIDType& TopicID, const CReadOnlySequenceNoType& Version)
{
	CTopicMarketDataVersionIteratorByTopicAndVersion *it;
	it=iteratorList.alloc();
	it->init(pFactory,TopicID,Version);
	return it;
}

CTopicMarketDataVersionIteratorByTopicAndVersion::~CTopicMarketDataVersionIteratorByTopicAndVersion(void)
{
}

void CTopicMarketDataVersionIteratorByTopicAndVersion::free(void)
{
	iteratorList.free(this);
}

void CTopicMarketDataVersionIteratorByTopicAndVersion::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CTopicMarketDataVersionIteratorByTopicAndVersion");
	
	char buffer[200];
	
	m_compareObject.TopicID.getString(buffer);
	pLogger->output(indent+1,0,"query TopicID=%s",buffer);
	
	m_compareObject.Version.getString(buffer);
	pLogger->output(indent+1,0,"query Version=%s",buffer);
	
}

void CTopicMarketDataVersionIteratorByTopicAndVersion::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pTopicAndVersion->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pTopicAndVersion->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CTopicMarketDataVersionIteratorByTopicAndVersion::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CTopicMarketDataVersion *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CTopicMarketDataVersionIteratorByTopicAndVersion::UpdateCurrent(CWriteableTopicMarketDataVersion * pByTopicAndVersion,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CTopicMarketDataVersion *)(m_pCurrent->pObject),pByTopicAndVersion,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByTopicAndVersionForTopicMarketDataVersion;
#endif

CTopicMarketDataVersion *CTopicMarketDataVersionIteratorByTopicAndVersion::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByTopicAndVersionForTopicMarketDataVersion++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CTopicMarketDataVersion *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CTopicMarketDataVersion *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CTopicMarketDataVersionIteratorByTopicAndVersion::match(CTopicMarketDataVersion *pTopicMarketDataVersion)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pTopicMarketDataVersion->TopicID.getValue(),m_compareObject.TopicID.getValue())!=0)
	{
		return 0;
	}
	if (compare(pTopicMarketDataVersion->Version.getValue(),m_compareObject.Version.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CInformationIteratorByInformationID> CInformationIteratorByInformationID::iteratorList;
void CInformationIteratorByInformationID::init(CInformationFactory *pFactory
		, const CReadOnlyInformationIDType& InformationID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CInformationIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InformationID=InformationID.getValue();
	m_compareObject.SequenceNo=0;

}

CInformationIteratorByInformationID *CInformationIteratorByInformationID::alloc(CInformationFactory *pFactory
		, const CReadOnlyInformationIDType& InformationID)
{
	CInformationIteratorByInformationID *it;
	it=iteratorList.alloc();
	it->init(pFactory,InformationID);
	return it;
}

CInformationIteratorByInformationID::~CInformationIteratorByInformationID(void)
{
}

void CInformationIteratorByInformationID::free(void)
{
	iteratorList.free(this);
}

void CInformationIteratorByInformationID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CInformationIteratorByInformationID");
	
	char buffer[200];
	
	m_compareObject.InformationID.getString(buffer);
	pLogger->output(indent+1,0,"query InformationID=%s",buffer);
	
}

void CInformationIteratorByInformationID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pInformationIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pInformationIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CInformationIteratorByInformationID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CInformation *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CInformationIteratorByInformationID::UpdateCurrent(CWriteableInformation * pByInformationID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CInformation *)(m_pCurrent->pObject),pByInformationID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByInformationIDForInformation;
#endif

CInformation *CInformationIteratorByInformationID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByInformationIDForInformation++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CInformation *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CInformation *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CInformationIteratorByInformationID::match(CInformation *pInformation)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pInformation->InformationID.getValue(),m_compareObject.InformationID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}



CMemoryStack<CInstrumentIteratorStartByInstrumentID> CInstrumentIteratorStartByInstrumentID::iteratorList;
void CInstrumentIteratorStartByInstrumentID::init(CInstrumentFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CInstrumentIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID=InstrumentID.getValue();

}

CInstrumentIteratorStartByInstrumentID *CInstrumentIteratorStartByInstrumentID::alloc(CInstrumentFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	CInstrumentIteratorStartByInstrumentID *it;
	it=iteratorList.alloc();
	it->init(pFactory,InstrumentID);
	return it;
}

CInstrumentIteratorStartByInstrumentID::~CInstrumentIteratorStartByInstrumentID(void)
{
}

void CInstrumentIteratorStartByInstrumentID::free(void)
{
	iteratorList.free(this);
}

void CInstrumentIteratorStartByInstrumentID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CInstrumentIteratorStartByInstrumentID");
	
	char buffer[200];
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void CInstrumentIteratorStartByInstrumentID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pInstrumentIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pInstrumentIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CInstrumentIteratorStartByInstrumentID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CInstrument *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CInstrumentIteratorStartByInstrumentID::UpdateCurrent(CWriteableInstrument * pStartByInstrumentID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CInstrument *)(m_pCurrent->pObject),pStartByInstrumentID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByInstrumentIDForInstrument;
#endif

CInstrument *CInstrumentIteratorStartByInstrumentID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByInstrumentIDForInstrument++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CInstrument *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CInstrument *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CInstrumentIteratorStartByInstrumentID::match(CInstrument *pInstrument)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CInstrumentIteratorBySettlementGroupID> CInstrumentIteratorBySettlementGroupID::iteratorList;
void CInstrumentIteratorBySettlementGroupID::init(CInstrumentFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CInstrumentIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CInstrumentIteratorBySettlementGroupID *CInstrumentIteratorBySettlementGroupID::alloc(CInstrumentFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CInstrumentIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CInstrumentIteratorBySettlementGroupID::~CInstrumentIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CInstrumentIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CInstrumentIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CInstrumentIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CInstrumentIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CInstrument *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CInstrument *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CInstrumentIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CInstrumentIteratorBySettlementGroupID::UpdateCurrent(CWriteableInstrument * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForInstrument;
#endif

CInstrument *CInstrumentIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CInstrumentIteratorBySettlementGroupID::match(CInstrument *pInstrument)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pInstrument->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CInstrumentIteratorByProductID> CInstrumentIteratorByProductID::iteratorList;
void CInstrumentIteratorByProductID::init(CInstrumentFactory *pFactory
		, const CReadOnlyProductIDType& ProductID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CInstrumentIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ProductID=ProductID.getValue();

}

CInstrumentIteratorByProductID *CInstrumentIteratorByProductID::alloc(CInstrumentFactory *pFactory
		, const CReadOnlyProductIDType& ProductID)
{
	CInstrumentIteratorByProductID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ProductID);
	return it;
}

CInstrumentIteratorByProductID::~CInstrumentIteratorByProductID(void)
{
}

void CInstrumentIteratorByProductID::free(void)
{
	iteratorList.free(this);
}

void CInstrumentIteratorByProductID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CInstrumentIteratorByProductID");
	
	char buffer[200];
	
	m_compareObject.ProductID.getString(buffer);
	pLogger->output(indent+1,0,"query ProductID=%s",buffer);
	
}

void CInstrumentIteratorByProductID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pProductIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pProductIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CInstrumentIteratorByProductID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CInstrument *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CInstrumentIteratorByProductID::UpdateCurrent(CWriteableInstrument * pByProductID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CInstrument *)(m_pCurrent->pObject),pByProductID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByProductIDForInstrument;
#endif

CInstrument *CInstrumentIteratorByProductID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByProductIDForInstrument++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CInstrument *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CInstrument *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CInstrumentIteratorByProductID::match(CInstrument *pInstrument)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pInstrument->ProductID.getValue(),m_compareObject.ProductID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CInstrumentIteratorByProductGroupID> CInstrumentIteratorByProductGroupID::iteratorList;
void CInstrumentIteratorByProductGroupID::init(CInstrumentFactory *pFactory
		, const CReadOnlyProductGroupIDType& ProductGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CInstrumentIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ProductGroupID=ProductGroupID.getValue();
	m_compareObject.DeliveryYear=1900;
	m_compareObject.DeliveryMonth=1;

}

CInstrumentIteratorByProductGroupID *CInstrumentIteratorByProductGroupID::alloc(CInstrumentFactory *pFactory
		, const CReadOnlyProductGroupIDType& ProductGroupID)
{
	CInstrumentIteratorByProductGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ProductGroupID);
	return it;
}

CInstrumentIteratorByProductGroupID::~CInstrumentIteratorByProductGroupID(void)
{
}

void CInstrumentIteratorByProductGroupID::free(void)
{
	iteratorList.free(this);
}

void CInstrumentIteratorByProductGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CInstrumentIteratorByProductGroupID");
	
	char buffer[200];
	
	m_compareObject.ProductGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query ProductGroupID=%s",buffer);
	
}

void CInstrumentIteratorByProductGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pProductGroupIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pProductGroupIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CInstrumentIteratorByProductGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CInstrument *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CInstrumentIteratorByProductGroupID::UpdateCurrent(CWriteableInstrument * pByProductGroupID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CInstrument *)(m_pCurrent->pObject),pByProductGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByProductGroupIDForInstrument;
#endif

CInstrument *CInstrumentIteratorByProductGroupID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByProductGroupIDForInstrument++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CInstrument *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CInstrument *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CInstrumentIteratorByProductGroupID::match(CInstrument *pInstrument)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pInstrument->ProductGroupID.getValue(),m_compareObject.ProductGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CInstrumentIteratorByDeliveryMonth> CInstrumentIteratorByDeliveryMonth::iteratorList;
void CInstrumentIteratorByDeliveryMonth::init(CInstrumentFactory *pFactory
		, const CReadOnlyProductGroupIDType& ProductGroupID, const CReadOnlyYearType& DeliveryYear, const CReadOnlyMonthType& DeliveryMonth)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CInstrumentIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ProductGroupID=ProductGroupID.getValue();
	m_compareObject.DeliveryYear=DeliveryYear.getValue();
	m_compareObject.DeliveryMonth=DeliveryMonth.getValue();

}

CInstrumentIteratorByDeliveryMonth *CInstrumentIteratorByDeliveryMonth::alloc(CInstrumentFactory *pFactory
		, const CReadOnlyProductGroupIDType& ProductGroupID, const CReadOnlyYearType& DeliveryYear, const CReadOnlyMonthType& DeliveryMonth)
{
	CInstrumentIteratorByDeliveryMonth *it;
	it=iteratorList.alloc();
	it->init(pFactory,ProductGroupID,DeliveryYear,DeliveryMonth);
	return it;
}

CInstrumentIteratorByDeliveryMonth::~CInstrumentIteratorByDeliveryMonth(void)
{
}

void CInstrumentIteratorByDeliveryMonth::free(void)
{
	iteratorList.free(this);
}

void CInstrumentIteratorByDeliveryMonth::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CInstrumentIteratorByDeliveryMonth");
	
	char buffer[200];
	
	m_compareObject.ProductGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query ProductGroupID=%s",buffer);
	
	m_compareObject.DeliveryYear.getString(buffer);
	pLogger->output(indent+1,0,"query DeliveryYear=%s",buffer);
	
	m_compareObject.DeliveryMonth.getString(buffer);
	pLogger->output(indent+1,0,"query DeliveryMonth=%s",buffer);
	
}

void CInstrumentIteratorByDeliveryMonth::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pProductGroupIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pProductGroupIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CInstrumentIteratorByDeliveryMonth::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CInstrument *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CInstrumentIteratorByDeliveryMonth::UpdateCurrent(CWriteableInstrument * pByDeliveryMonth,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CInstrument *)(m_pCurrent->pObject),pByDeliveryMonth,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByDeliveryMonthForInstrument;
#endif

CInstrument *CInstrumentIteratorByDeliveryMonth::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByDeliveryMonthForInstrument++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CInstrument *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CInstrument *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CInstrumentIteratorByDeliveryMonth::match(CInstrument *pInstrument)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pInstrument->ProductGroupID.getValue(),m_compareObject.ProductGroupID.getValue())!=0)
	{
		return 0;
	}
	if (compare(pInstrument->DeliveryYear.getValue(),m_compareObject.DeliveryYear.getValue())!=0)
	{
		return 0;
	}
	if (compare(pInstrument->DeliveryMonth.getValue(),m_compareObject.DeliveryMonth.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CInstrumentIteratorByRevDeliveryMonth> CInstrumentIteratorByRevDeliveryMonth::iteratorList;
void CInstrumentIteratorByRevDeliveryMonth::init(CInstrumentFactory *pFactory
		, const CReadOnlyProductGroupIDType& ProductGroupID, const CReadOnlyYearType& DeliveryYear, const CReadOnlyMonthType& DeliveryMonth)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CInstrumentIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ProductGroupID=ProductGroupID.getValue();
	m_compareObject.DeliveryYear=DeliveryYear.getValue();
	m_compareObject.DeliveryMonth=DeliveryMonth.getValue();

}

CInstrumentIteratorByRevDeliveryMonth *CInstrumentIteratorByRevDeliveryMonth::alloc(CInstrumentFactory *pFactory
		, const CReadOnlyProductGroupIDType& ProductGroupID, const CReadOnlyYearType& DeliveryYear, const CReadOnlyMonthType& DeliveryMonth)
{
	CInstrumentIteratorByRevDeliveryMonth *it;
	it=iteratorList.alloc();
	it->init(pFactory,ProductGroupID,DeliveryYear,DeliveryMonth);
	return it;
}

CInstrumentIteratorByRevDeliveryMonth::~CInstrumentIteratorByRevDeliveryMonth(void)
{
}

void CInstrumentIteratorByRevDeliveryMonth::free(void)
{
	iteratorList.free(this);
}

void CInstrumentIteratorByRevDeliveryMonth::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CInstrumentIteratorByRevDeliveryMonth");
	
	char buffer[200];
	
	m_compareObject.ProductGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query ProductGroupID=%s",buffer);
	
	m_compareObject.DeliveryYear.getString(buffer);
	pLogger->output(indent+1,0,"query DeliveryYear=%s",buffer);
	
	m_compareObject.DeliveryMonth.getString(buffer);
	pLogger->output(indent+1,0,"query DeliveryMonth=%s",buffer);
	
}

void CInstrumentIteratorByRevDeliveryMonth::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pProductGroupIDRevIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pProductGroupIDRevIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CInstrumentIteratorByRevDeliveryMonth::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CInstrument *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CInstrumentIteratorByRevDeliveryMonth::UpdateCurrent(CWriteableInstrument * pByRevDeliveryMonth,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CInstrument *)(m_pCurrent->pObject),pByRevDeliveryMonth,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByRevDeliveryMonthForInstrument;
#endif

CInstrument *CInstrumentIteratorByRevDeliveryMonth::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByRevDeliveryMonthForInstrument++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CInstrument *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CInstrument *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CInstrumentIteratorByRevDeliveryMonth::match(CInstrument *pInstrument)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pInstrument->ProductGroupID.getValue(),m_compareObject.ProductGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CCombinationLegIteratorByCombination> CCombinationLegIteratorByCombination::iteratorList;
void CCombinationLegIteratorByCombination::init(CCombinationLegFactory *pFactory
		, const CReadOnlyInstrumentIDType& CombInstrumentID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCombinationLegIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.CombInstrumentID=CombInstrumentID.getValue();
	m_compareObject.LegID=0;

}

CCombinationLegIteratorByCombination *CCombinationLegIteratorByCombination::alloc(CCombinationLegFactory *pFactory
		, const CReadOnlyInstrumentIDType& CombInstrumentID)
{
	CCombinationLegIteratorByCombination *it;
	it=iteratorList.alloc();
	it->init(pFactory,CombInstrumentID);
	return it;
}

CCombinationLegIteratorByCombination::~CCombinationLegIteratorByCombination(void)
{
}

void CCombinationLegIteratorByCombination::free(void)
{
	iteratorList.free(this);
}

void CCombinationLegIteratorByCombination::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCombinationLegIteratorByCombination");
	
	char buffer[200];
	
	m_compareObject.CombInstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query CombInstrumentID=%s",buffer);
	
}

void CCombinationLegIteratorByCombination::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pCombinationIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pCombinationIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CCombinationLegIteratorByCombination::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CCombinationLeg *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CCombinationLegIteratorByCombination::UpdateCurrent(CWriteableCombinationLeg * pByCombination,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CCombinationLeg *)(m_pCurrent->pObject),pByCombination,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByCombinationForCombinationLeg;
#endif

CCombinationLeg *CCombinationLegIteratorByCombination::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByCombinationForCombinationLeg++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CCombinationLeg *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CCombinationLeg *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CCombinationLegIteratorByCombination::match(CCombinationLeg *pCombinationLeg)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCombinationLeg->CombInstrumentID.getValue(),m_compareObject.CombInstrumentID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CCombinationLegIteratorByLeg> CCombinationLegIteratorByLeg::iteratorList;
void CCombinationLegIteratorByLeg::init(CCombinationLegFactory *pFactory
		, const CReadOnlyInstrumentIDType& LegInstrumentID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCombinationLegIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.LegInstrumentID=LegInstrumentID.getValue();
	m_compareObject.CombInstrumentID="";

}

CCombinationLegIteratorByLeg *CCombinationLegIteratorByLeg::alloc(CCombinationLegFactory *pFactory
		, const CReadOnlyInstrumentIDType& LegInstrumentID)
{
	CCombinationLegIteratorByLeg *it;
	it=iteratorList.alloc();
	it->init(pFactory,LegInstrumentID);
	return it;
}

CCombinationLegIteratorByLeg::~CCombinationLegIteratorByLeg(void)
{
}

void CCombinationLegIteratorByLeg::free(void)
{
	iteratorList.free(this);
}

void CCombinationLegIteratorByLeg::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCombinationLegIteratorByLeg");
	
	char buffer[200];
	
	m_compareObject.LegInstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query LegInstrumentID=%s",buffer);
	
}

void CCombinationLegIteratorByLeg::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pLegIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pLegIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CCombinationLegIteratorByLeg::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CCombinationLeg *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CCombinationLegIteratorByLeg::UpdateCurrent(CWriteableCombinationLeg * pByLeg,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CCombinationLeg *)(m_pCurrent->pObject),pByLeg,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByLegForCombinationLeg;
#endif

CCombinationLeg *CCombinationLegIteratorByLeg::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByLegForCombinationLeg++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CCombinationLeg *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CCombinationLeg *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CCombinationLegIteratorByLeg::match(CCombinationLeg *pCombinationLeg)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCombinationLeg->LegInstrumentID.getValue(),m_compareObject.LegInstrumentID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CCombinationLegIteratorBySettlementGroupID> CCombinationLegIteratorBySettlementGroupID::iteratorList;
void CCombinationLegIteratorBySettlementGroupID::init(CCombinationLegFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCombinationLegIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCombinationLegIteratorBySettlementGroupID *CCombinationLegIteratorBySettlementGroupID::alloc(CCombinationLegFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCombinationLegIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCombinationLegIteratorBySettlementGroupID::~CCombinationLegIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCombinationLegIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCombinationLegIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCombinationLegIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCombinationLegIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCombinationLeg *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCombinationLeg *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCombinationLegIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCombinationLegIteratorBySettlementGroupID::UpdateCurrent(CWriteableCombinationLeg * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCombinationLeg;
#endif

CCombinationLeg *CCombinationLegIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCombinationLegIteratorBySettlementGroupID::match(CCombinationLeg *pCombinationLeg)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCombinationLeg->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CPartRoleAccountIteratorBySettlementGroupID> CPartRoleAccountIteratorBySettlementGroupID::iteratorList;
void CPartRoleAccountIteratorBySettlementGroupID::init(CPartRoleAccountFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CPartRoleAccountIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CPartRoleAccountIteratorBySettlementGroupID *CPartRoleAccountIteratorBySettlementGroupID::alloc(CPartRoleAccountFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CPartRoleAccountIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CPartRoleAccountIteratorBySettlementGroupID::~CPartRoleAccountIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CPartRoleAccountIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CPartRoleAccountIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CPartRoleAccountIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CPartRoleAccountIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CPartRoleAccount *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CPartRoleAccount *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CPartRoleAccountIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CPartRoleAccountIteratorBySettlementGroupID::UpdateCurrent(CWriteablePartRoleAccount * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForPartRoleAccount;
#endif

CPartRoleAccount *CPartRoleAccountIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CPartRoleAccountIteratorBySettlementGroupID::match(CPartRoleAccount *pPartRoleAccount)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pPartRoleAccount->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CPartRoleAccountIteratorStartByParticipantID> CPartRoleAccountIteratorStartByParticipantID::iteratorList;
void CPartRoleAccountIteratorStartByParticipantID::init(CPartRoleAccountFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CPartRoleAccountIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID=ParticipantID.getValue();
	m_compareObject.TradingRole="";
	m_compareObject.SettlementGroupID="";

}

CPartRoleAccountIteratorStartByParticipantID *CPartRoleAccountIteratorStartByParticipantID::alloc(CPartRoleAccountFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	CPartRoleAccountIteratorStartByParticipantID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ParticipantID);
	return it;
}

CPartRoleAccountIteratorStartByParticipantID::~CPartRoleAccountIteratorStartByParticipantID(void)
{
}

void CPartRoleAccountIteratorStartByParticipantID::free(void)
{
	iteratorList.free(this);
}

void CPartRoleAccountIteratorStartByParticipantID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CPartRoleAccountIteratorStartByParticipantID");
	
	char buffer[200];
	
	m_compareObject.ParticipantID.getString(buffer);
	pLogger->output(indent+1,0,"query ParticipantID=%s",buffer);
	
}

void CPartRoleAccountIteratorStartByParticipantID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pPartRoleAndSGIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pPartRoleAndSGIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CPartRoleAccountIteratorStartByParticipantID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CPartRoleAccount *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CPartRoleAccountIteratorStartByParticipantID::UpdateCurrent(CWriteablePartRoleAccount * pStartByParticipantID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CPartRoleAccount *)(m_pCurrent->pObject),pStartByParticipantID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByParticipantIDForPartRoleAccount;
#endif

CPartRoleAccount *CPartRoleAccountIteratorStartByParticipantID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForPartRoleAccount++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CPartRoleAccount *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CPartRoleAccount *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CPartRoleAccountIteratorStartByParticipantID::match(CPartRoleAccount *pPartRoleAccount)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CPartProductRoleIteratorBySettlementGroupID> CPartProductRoleIteratorBySettlementGroupID::iteratorList;
void CPartProductRoleIteratorBySettlementGroupID::init(CPartProductRoleFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CPartProductRoleIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CPartProductRoleIteratorBySettlementGroupID *CPartProductRoleIteratorBySettlementGroupID::alloc(CPartProductRoleFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CPartProductRoleIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CPartProductRoleIteratorBySettlementGroupID::~CPartProductRoleIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CPartProductRoleIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CPartProductRoleIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CPartProductRoleIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CPartProductRoleIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CPartProductRole *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CPartProductRole *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CPartProductRoleIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CPartProductRoleIteratorBySettlementGroupID::UpdateCurrent(CWriteablePartProductRole * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForPartProductRole;
#endif

CPartProductRole *CPartProductRoleIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CPartProductRoleIteratorBySettlementGroupID::match(CPartProductRole *pPartProductRole)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pPartProductRole->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CPartProductRightIteratorBySettlementGroupID> CPartProductRightIteratorBySettlementGroupID::iteratorList;
void CPartProductRightIteratorBySettlementGroupID::init(CPartProductRightFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CPartProductRightIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CPartProductRightIteratorBySettlementGroupID *CPartProductRightIteratorBySettlementGroupID::alloc(CPartProductRightFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CPartProductRightIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CPartProductRightIteratorBySettlementGroupID::~CPartProductRightIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CPartProductRightIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CPartProductRightIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CPartProductRightIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CPartProductRightIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CPartProductRight *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CPartProductRight *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CPartProductRightIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CPartProductRightIteratorBySettlementGroupID::UpdateCurrent(CWriteablePartProductRight * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForPartProductRight;
#endif

CPartProductRight *CPartProductRightIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CPartProductRightIteratorBySettlementGroupID::match(CPartProductRight *pPartProductRight)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pPartProductRight->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CPartInstrumentRightIteratorBySettlementGroupID> CPartInstrumentRightIteratorBySettlementGroupID::iteratorList;
void CPartInstrumentRightIteratorBySettlementGroupID::init(CPartInstrumentRightFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CPartInstrumentRightIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CPartInstrumentRightIteratorBySettlementGroupID *CPartInstrumentRightIteratorBySettlementGroupID::alloc(CPartInstrumentRightFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CPartInstrumentRightIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CPartInstrumentRightIteratorBySettlementGroupID::~CPartInstrumentRightIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CPartInstrumentRightIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CPartInstrumentRightIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CPartInstrumentRightIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CPartInstrumentRightIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CPartInstrumentRight *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CPartInstrumentRight *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CPartInstrumentRightIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CPartInstrumentRightIteratorBySettlementGroupID::UpdateCurrent(CWriteablePartInstrumentRight * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForPartInstrumentRight;
#endif

CPartInstrumentRight *CPartInstrumentRightIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CPartInstrumentRightIteratorBySettlementGroupID::match(CPartInstrumentRight *pPartInstrumentRight)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pPartInstrumentRight->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CClientProductRightIteratorBySettlementGroupID> CClientProductRightIteratorBySettlementGroupID::iteratorList;
void CClientProductRightIteratorBySettlementGroupID::init(CClientProductRightFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CClientProductRightIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CClientProductRightIteratorBySettlementGroupID *CClientProductRightIteratorBySettlementGroupID::alloc(CClientProductRightFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CClientProductRightIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CClientProductRightIteratorBySettlementGroupID::~CClientProductRightIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CClientProductRightIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CClientProductRightIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CClientProductRightIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CClientProductRightIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CClientProductRight *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CClientProductRight *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CClientProductRightIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CClientProductRightIteratorBySettlementGroupID::UpdateCurrent(CWriteableClientProductRight * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForClientProductRight;
#endif

CClientProductRight *CClientProductRightIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CClientProductRightIteratorBySettlementGroupID::match(CClientProductRight *pClientProductRight)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pClientProductRight->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CClientInstrumentRightIteratorBySettlementGroupID> CClientInstrumentRightIteratorBySettlementGroupID::iteratorList;
void CClientInstrumentRightIteratorBySettlementGroupID::init(CClientInstrumentRightFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CClientInstrumentRightIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CClientInstrumentRightIteratorBySettlementGroupID *CClientInstrumentRightIteratorBySettlementGroupID::alloc(CClientInstrumentRightFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CClientInstrumentRightIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CClientInstrumentRightIteratorBySettlementGroupID::~CClientInstrumentRightIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CClientInstrumentRightIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CClientInstrumentRightIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CClientInstrumentRightIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CClientInstrumentRightIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CClientInstrumentRight *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CClientInstrumentRight *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CClientInstrumentRightIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CClientInstrumentRightIteratorBySettlementGroupID::UpdateCurrent(CWriteableClientInstrumentRight * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForClientInstrumentRight;
#endif

CClientInstrumentRight *CClientInstrumentRightIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CClientInstrumentRightIteratorBySettlementGroupID::match(CClientInstrumentRight *pClientInstrumentRight)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pClientInstrumentRight->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CPartClientProductRightIteratorBySettlementGroupID> CPartClientProductRightIteratorBySettlementGroupID::iteratorList;
void CPartClientProductRightIteratorBySettlementGroupID::init(CPartClientProductRightFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CPartClientProductRightIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CPartClientProductRightIteratorBySettlementGroupID *CPartClientProductRightIteratorBySettlementGroupID::alloc(CPartClientProductRightFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CPartClientProductRightIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CPartClientProductRightIteratorBySettlementGroupID::~CPartClientProductRightIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CPartClientProductRightIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CPartClientProductRightIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CPartClientProductRightIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CPartClientProductRightIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CPartClientProductRight *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CPartClientProductRight *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CPartClientProductRightIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CPartClientProductRightIteratorBySettlementGroupID::UpdateCurrent(CWriteablePartClientProductRight * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForPartClientProductRight;
#endif

CPartClientProductRight *CPartClientProductRightIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CPartClientProductRightIteratorBySettlementGroupID::match(CPartClientProductRight *pPartClientProductRight)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pPartClientProductRight->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CPartClientInstrumentRightIteratorBySettlementGroupID> CPartClientInstrumentRightIteratorBySettlementGroupID::iteratorList;
void CPartClientInstrumentRightIteratorBySettlementGroupID::init(CPartClientInstrumentRightFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CPartClientInstrumentRightIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CPartClientInstrumentRightIteratorBySettlementGroupID *CPartClientInstrumentRightIteratorBySettlementGroupID::alloc(CPartClientInstrumentRightFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CPartClientInstrumentRightIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CPartClientInstrumentRightIteratorBySettlementGroupID::~CPartClientInstrumentRightIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CPartClientInstrumentRightIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CPartClientInstrumentRightIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CPartClientInstrumentRightIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CPartClientInstrumentRightIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CPartClientInstrumentRight *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CPartClientInstrumentRight *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CPartClientInstrumentRightIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CPartClientInstrumentRightIteratorBySettlementGroupID::UpdateCurrent(CWriteablePartClientInstrumentRight * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForPartClientInstrumentRight;
#endif

CPartClientInstrumentRight *CPartClientInstrumentRightIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CPartClientInstrumentRightIteratorBySettlementGroupID::match(CPartClientInstrumentRight *pPartClientInstrumentRight)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pPartClientInstrumentRight->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CCurrProductPropertyIteratorBySettlementGroupID> CCurrProductPropertyIteratorBySettlementGroupID::iteratorList;
void CCurrProductPropertyIteratorBySettlementGroupID::init(CCurrProductPropertyFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrProductPropertyIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCurrProductPropertyIteratorBySettlementGroupID *CCurrProductPropertyIteratorBySettlementGroupID::alloc(CCurrProductPropertyFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCurrProductPropertyIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCurrProductPropertyIteratorBySettlementGroupID::~CCurrProductPropertyIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCurrProductPropertyIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCurrProductPropertyIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrProductPropertyIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCurrProductPropertyIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCurrProductProperty *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCurrProductProperty *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCurrProductPropertyIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrProductPropertyIteratorBySettlementGroupID::UpdateCurrent(CWriteableCurrProductProperty * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCurrProductProperty;
#endif

CCurrProductProperty *CCurrProductPropertyIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCurrProductPropertyIteratorBySettlementGroupID::match(CCurrProductProperty *pCurrProductProperty)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCurrProductProperty->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CCurrInstrumentPropertyIteratorBySettlementGroupID> CCurrInstrumentPropertyIteratorBySettlementGroupID::iteratorList;
void CCurrInstrumentPropertyIteratorBySettlementGroupID::init(CCurrInstrumentPropertyFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrInstrumentPropertyIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCurrInstrumentPropertyIteratorBySettlementGroupID *CCurrInstrumentPropertyIteratorBySettlementGroupID::alloc(CCurrInstrumentPropertyFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCurrInstrumentPropertyIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCurrInstrumentPropertyIteratorBySettlementGroupID::~CCurrInstrumentPropertyIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCurrInstrumentPropertyIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCurrInstrumentPropertyIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrInstrumentPropertyIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCurrInstrumentPropertyIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCurrInstrumentProperty *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCurrInstrumentProperty *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCurrInstrumentPropertyIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrInstrumentPropertyIteratorBySettlementGroupID::UpdateCurrent(CWriteableCurrInstrumentProperty * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCurrInstrumentProperty;
#endif

CCurrInstrumentProperty *CCurrInstrumentPropertyIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCurrInstrumentPropertyIteratorBySettlementGroupID::match(CCurrInstrumentProperty *pCurrInstrumentProperty)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCurrInstrumentProperty->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CCurrPriceBandingIteratorBySettlementGroupID> CCurrPriceBandingIteratorBySettlementGroupID::iteratorList;
void CCurrPriceBandingIteratorBySettlementGroupID::init(CCurrPriceBandingFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrPriceBandingIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCurrPriceBandingIteratorBySettlementGroupID *CCurrPriceBandingIteratorBySettlementGroupID::alloc(CCurrPriceBandingFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCurrPriceBandingIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCurrPriceBandingIteratorBySettlementGroupID::~CCurrPriceBandingIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCurrPriceBandingIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCurrPriceBandingIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrPriceBandingIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCurrPriceBandingIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCurrPriceBanding *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCurrPriceBanding *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCurrPriceBandingIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrPriceBandingIteratorBySettlementGroupID::UpdateCurrent(CWriteableCurrPriceBanding * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCurrPriceBanding;
#endif

CCurrPriceBanding *CCurrPriceBandingIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCurrPriceBandingIteratorBySettlementGroupID::match(CCurrPriceBanding *pCurrPriceBanding)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCurrPriceBanding->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CCurrMarginRateIteratorBySettlementGroupID> CCurrMarginRateIteratorBySettlementGroupID::iteratorList;
void CCurrMarginRateIteratorBySettlementGroupID::init(CCurrMarginRateFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrMarginRateIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCurrMarginRateIteratorBySettlementGroupID *CCurrMarginRateIteratorBySettlementGroupID::alloc(CCurrMarginRateFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCurrMarginRateIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCurrMarginRateIteratorBySettlementGroupID::~CCurrMarginRateIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCurrMarginRateIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCurrMarginRateIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrMarginRateIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCurrMarginRateIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCurrMarginRate *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCurrMarginRate *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCurrMarginRateIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrMarginRateIteratorBySettlementGroupID::UpdateCurrent(CWriteableCurrMarginRate * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCurrMarginRate;
#endif

CCurrMarginRate *CCurrMarginRateIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCurrMarginRateIteratorBySettlementGroupID::match(CCurrMarginRate *pCurrMarginRate)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCurrMarginRate->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CCurrMarginRateDetailIteratorBySettlementGroupID> CCurrMarginRateDetailIteratorBySettlementGroupID::iteratorList;
void CCurrMarginRateDetailIteratorBySettlementGroupID::init(CCurrMarginRateDetailFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrMarginRateDetailIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCurrMarginRateDetailIteratorBySettlementGroupID *CCurrMarginRateDetailIteratorBySettlementGroupID::alloc(CCurrMarginRateDetailFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCurrMarginRateDetailIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCurrMarginRateDetailIteratorBySettlementGroupID::~CCurrMarginRateDetailIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCurrMarginRateDetailIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCurrMarginRateDetailIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrMarginRateDetailIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCurrMarginRateDetailIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCurrMarginRateDetail *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCurrMarginRateDetail *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCurrMarginRateDetailIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrMarginRateDetailIteratorBySettlementGroupID::UpdateCurrent(CWriteableCurrMarginRateDetail * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCurrMarginRateDetail;
#endif

CCurrMarginRateDetail *CCurrMarginRateDetailIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCurrMarginRateDetailIteratorBySettlementGroupID::match(CCurrMarginRateDetail *pCurrMarginRateDetail)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCurrMarginRateDetail->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CCurrPartPosiLimitIteratorBySettlementGroupID> CCurrPartPosiLimitIteratorBySettlementGroupID::iteratorList;
void CCurrPartPosiLimitIteratorBySettlementGroupID::init(CCurrPartPosiLimitFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrPartPosiLimitIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCurrPartPosiLimitIteratorBySettlementGroupID *CCurrPartPosiLimitIteratorBySettlementGroupID::alloc(CCurrPartPosiLimitFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCurrPartPosiLimitIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCurrPartPosiLimitIteratorBySettlementGroupID::~CCurrPartPosiLimitIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCurrPartPosiLimitIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCurrPartPosiLimitIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrPartPosiLimitIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCurrPartPosiLimitIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCurrPartPosiLimit *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCurrPartPosiLimit *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCurrPartPosiLimitIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrPartPosiLimitIteratorBySettlementGroupID::UpdateCurrent(CWriteableCurrPartPosiLimit * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCurrPartPosiLimit;
#endif

CCurrPartPosiLimit *CCurrPartPosiLimitIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCurrPartPosiLimitIteratorBySettlementGroupID::match(CCurrPartPosiLimit *pCurrPartPosiLimit)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCurrPartPosiLimit->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CCurrPartPosiLimitDetailIteratorBySettlementGroupID> CCurrPartPosiLimitDetailIteratorBySettlementGroupID::iteratorList;
void CCurrPartPosiLimitDetailIteratorBySettlementGroupID::init(CCurrPartPosiLimitDetailFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrPartPosiLimitDetailIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCurrPartPosiLimitDetailIteratorBySettlementGroupID *CCurrPartPosiLimitDetailIteratorBySettlementGroupID::alloc(CCurrPartPosiLimitDetailFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCurrPartPosiLimitDetailIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCurrPartPosiLimitDetailIteratorBySettlementGroupID::~CCurrPartPosiLimitDetailIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCurrPartPosiLimitDetailIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCurrPartPosiLimitDetailIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrPartPosiLimitDetailIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCurrPartPosiLimitDetailIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCurrPartPosiLimitDetail *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCurrPartPosiLimitDetail *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCurrPartPosiLimitDetailIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrPartPosiLimitDetailIteratorBySettlementGroupID::UpdateCurrent(CWriteableCurrPartPosiLimitDetail * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCurrPartPosiLimitDetail;
#endif

CCurrPartPosiLimitDetail *CCurrPartPosiLimitDetailIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCurrPartPosiLimitDetailIteratorBySettlementGroupID::match(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCurrPartPosiLimitDetail->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CCurrClientPosiLimitIteratorBySettlementGroupID> CCurrClientPosiLimitIteratorBySettlementGroupID::iteratorList;
void CCurrClientPosiLimitIteratorBySettlementGroupID::init(CCurrClientPosiLimitFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrClientPosiLimitIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCurrClientPosiLimitIteratorBySettlementGroupID *CCurrClientPosiLimitIteratorBySettlementGroupID::alloc(CCurrClientPosiLimitFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCurrClientPosiLimitIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCurrClientPosiLimitIteratorBySettlementGroupID::~CCurrClientPosiLimitIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCurrClientPosiLimitIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCurrClientPosiLimitIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrClientPosiLimitIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCurrClientPosiLimitIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCurrClientPosiLimit *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCurrClientPosiLimit *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCurrClientPosiLimitIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrClientPosiLimitIteratorBySettlementGroupID::UpdateCurrent(CWriteableCurrClientPosiLimit * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCurrClientPosiLimit;
#endif

CCurrClientPosiLimit *CCurrClientPosiLimitIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCurrClientPosiLimitIteratorBySettlementGroupID::match(CCurrClientPosiLimit *pCurrClientPosiLimit)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCurrClientPosiLimit->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CCurrClientPosiLimitDetailIteratorBySettlementGroupID> CCurrClientPosiLimitDetailIteratorBySettlementGroupID::iteratorList;
void CCurrClientPosiLimitDetailIteratorBySettlementGroupID::init(CCurrClientPosiLimitDetailFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrClientPosiLimitDetailIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCurrClientPosiLimitDetailIteratorBySettlementGroupID *CCurrClientPosiLimitDetailIteratorBySettlementGroupID::alloc(CCurrClientPosiLimitDetailFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCurrClientPosiLimitDetailIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCurrClientPosiLimitDetailIteratorBySettlementGroupID::~CCurrClientPosiLimitDetailIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCurrClientPosiLimitDetailIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCurrClientPosiLimitDetailIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrClientPosiLimitDetailIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCurrClientPosiLimitDetailIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCurrClientPosiLimitDetail *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCurrClientPosiLimitDetail *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCurrClientPosiLimitDetailIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrClientPosiLimitDetailIteratorBySettlementGroupID::UpdateCurrent(CWriteableCurrClientPosiLimitDetail * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCurrClientPosiLimitDetail;
#endif

CCurrClientPosiLimitDetail *CCurrClientPosiLimitDetailIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCurrClientPosiLimitDetailIteratorBySettlementGroupID::match(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCurrClientPosiLimitDetail->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CCurrSpecialPosiLimitIteratorBySettlementGroupID> CCurrSpecialPosiLimitIteratorBySettlementGroupID::iteratorList;
void CCurrSpecialPosiLimitIteratorBySettlementGroupID::init(CCurrSpecialPosiLimitFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrSpecialPosiLimitIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCurrSpecialPosiLimitIteratorBySettlementGroupID *CCurrSpecialPosiLimitIteratorBySettlementGroupID::alloc(CCurrSpecialPosiLimitFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCurrSpecialPosiLimitIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCurrSpecialPosiLimitIteratorBySettlementGroupID::~CCurrSpecialPosiLimitIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCurrSpecialPosiLimitIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCurrSpecialPosiLimitIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrSpecialPosiLimitIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCurrSpecialPosiLimitIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCurrSpecialPosiLimit *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCurrSpecialPosiLimit *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCurrSpecialPosiLimitIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrSpecialPosiLimitIteratorBySettlementGroupID::UpdateCurrent(CWriteableCurrSpecialPosiLimit * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCurrSpecialPosiLimit;
#endif

CCurrSpecialPosiLimit *CCurrSpecialPosiLimitIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCurrSpecialPosiLimitIteratorBySettlementGroupID::match(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCurrSpecialPosiLimit->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID> CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID::iteratorList;
void CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID::init(CCurrSpecialPosiLimitDetailFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrSpecialPosiLimitDetailIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID *CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID::alloc(CCurrSpecialPosiLimitDetailFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID::~CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCurrSpecialPosiLimitDetail *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCurrSpecialPosiLimitDetail *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID::UpdateCurrent(CWriteableCurrSpecialPosiLimitDetail * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCurrSpecialPosiLimitDetail;
#endif

CCurrSpecialPosiLimitDetail *CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID::match(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCurrSpecialPosiLimitDetail->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CCurrHedgeRuleIteratorBySettlementGroupID> CCurrHedgeRuleIteratorBySettlementGroupID::iteratorList;
void CCurrHedgeRuleIteratorBySettlementGroupID::init(CCurrHedgeRuleFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrHedgeRuleIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCurrHedgeRuleIteratorBySettlementGroupID *CCurrHedgeRuleIteratorBySettlementGroupID::alloc(CCurrHedgeRuleFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCurrHedgeRuleIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCurrHedgeRuleIteratorBySettlementGroupID::~CCurrHedgeRuleIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCurrHedgeRuleIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCurrHedgeRuleIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrHedgeRuleIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCurrHedgeRuleIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCurrHedgeRule *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCurrHedgeRule *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCurrHedgeRuleIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrHedgeRuleIteratorBySettlementGroupID::UpdateCurrent(CWriteableCurrHedgeRule * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCurrHedgeRule;
#endif

CCurrHedgeRule *CCurrHedgeRuleIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCurrHedgeRuleIteratorBySettlementGroupID::match(CCurrHedgeRule *pCurrHedgeRule)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCurrHedgeRule->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CCurrTradingSegmentAttrIteratorBySettlementGroupID> CCurrTradingSegmentAttrIteratorBySettlementGroupID::iteratorList;
void CCurrTradingSegmentAttrIteratorBySettlementGroupID::init(CCurrTradingSegmentAttrFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrTradingSegmentAttrIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCurrTradingSegmentAttrIteratorBySettlementGroupID *CCurrTradingSegmentAttrIteratorBySettlementGroupID::alloc(CCurrTradingSegmentAttrFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCurrTradingSegmentAttrIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCurrTradingSegmentAttrIteratorBySettlementGroupID::~CCurrTradingSegmentAttrIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCurrTradingSegmentAttrIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCurrTradingSegmentAttrIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrTradingSegmentAttrIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCurrTradingSegmentAttrIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCurrTradingSegmentAttr *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCurrTradingSegmentAttr *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCurrTradingSegmentAttrIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrTradingSegmentAttrIteratorBySettlementGroupID::UpdateCurrent(CWriteableCurrTradingSegmentAttr * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCurrTradingSegmentAttr;
#endif

CCurrTradingSegmentAttr *CCurrTradingSegmentAttrIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCurrTradingSegmentAttrIteratorBySettlementGroupID::match(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCurrTradingSegmentAttr->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CCurrTradingSegmentAttrIteratorByTime> CCurrTradingSegmentAttrIteratorByTime::iteratorList;
void CCurrTradingSegmentAttrIteratorByTime::init(CCurrTradingSegmentAttrFactory *pFactory
		, const CReadOnlyTimeType& StartTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrTradingSegmentAttrIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.StartTime=StartTime.getValue();
	m_compareObject.TradingSegmentSN=0;

}

CCurrTradingSegmentAttrIteratorByTime *CCurrTradingSegmentAttrIteratorByTime::alloc(CCurrTradingSegmentAttrFactory *pFactory
		, const CReadOnlyTimeType& StartTime)
{
	CCurrTradingSegmentAttrIteratorByTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,StartTime);
	return it;
}

CCurrTradingSegmentAttrIteratorByTime::~CCurrTradingSegmentAttrIteratorByTime(void)
{
}

void CCurrTradingSegmentAttrIteratorByTime::free(void)
{
	iteratorList.free(this);
}

void CCurrTradingSegmentAttrIteratorByTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrTradingSegmentAttrIteratorByTime");
	
	char buffer[200];
	
	m_compareObject.StartTime.getString(buffer);
	pLogger->output(indent+1,0,"query StartTime=%s",buffer);
	
}

void CCurrTradingSegmentAttrIteratorByTime::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pTimeIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pTimeIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CCurrTradingSegmentAttrIteratorByTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CCurrTradingSegmentAttr *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrTradingSegmentAttrIteratorByTime::UpdateCurrent(CWriteableCurrTradingSegmentAttr * pByTime,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CCurrTradingSegmentAttr *)(m_pCurrent->pObject),pByTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByTimeForCurrTradingSegmentAttr;
#endif

CCurrTradingSegmentAttr *CCurrTradingSegmentAttrIteratorByTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByTimeForCurrTradingSegmentAttr++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CCurrTradingSegmentAttr *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CCurrTradingSegmentAttr *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CCurrTradingSegmentAttrIteratorByTime::match(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CCurrTradingSegmentAttrIteratorByInstrument> CCurrTradingSegmentAttrIteratorByInstrument::iteratorList;
void CCurrTradingSegmentAttrIteratorByInstrument::init(CCurrTradingSegmentAttrFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrTradingSegmentAttrIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID=InstrumentID.getValue();
	m_compareObject.TradingSegmentSN=0;

}

CCurrTradingSegmentAttrIteratorByInstrument *CCurrTradingSegmentAttrIteratorByInstrument::alloc(CCurrTradingSegmentAttrFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	CCurrTradingSegmentAttrIteratorByInstrument *it;
	it=iteratorList.alloc();
	it->init(pFactory,InstrumentID);
	return it;
}

CCurrTradingSegmentAttrIteratorByInstrument::~CCurrTradingSegmentAttrIteratorByInstrument(void)
{
}

void CCurrTradingSegmentAttrIteratorByInstrument::free(void)
{
	iteratorList.free(this);
}

void CCurrTradingSegmentAttrIteratorByInstrument::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrTradingSegmentAttrIteratorByInstrument");
	
	char buffer[200];
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void CCurrTradingSegmentAttrIteratorByInstrument::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pInstrumentIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pInstrumentIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CCurrTradingSegmentAttrIteratorByInstrument::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CCurrTradingSegmentAttr *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrTradingSegmentAttrIteratorByInstrument::UpdateCurrent(CWriteableCurrTradingSegmentAttr * pByInstrument,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CCurrTradingSegmentAttr *)(m_pCurrent->pObject),pByInstrument,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByInstrumentForCurrTradingSegmentAttr;
#endif

CCurrTradingSegmentAttr *CCurrTradingSegmentAttrIteratorByInstrument::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByInstrumentForCurrTradingSegmentAttr++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CCurrTradingSegmentAttr *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CCurrTradingSegmentAttr *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CCurrTradingSegmentAttrIteratorByInstrument::match(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCurrTradingSegmentAttr->InstrumentID.getValue(),m_compareObject.InstrumentID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CCurrFuseIteratorBySettlementGroupID> CCurrFuseIteratorBySettlementGroupID::iteratorList;
void CCurrFuseIteratorBySettlementGroupID::init(CCurrFuseFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrFuseIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCurrFuseIteratorBySettlementGroupID *CCurrFuseIteratorBySettlementGroupID::alloc(CCurrFuseFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCurrFuseIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCurrFuseIteratorBySettlementGroupID::~CCurrFuseIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCurrFuseIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCurrFuseIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrFuseIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCurrFuseIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCurrFuse *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCurrFuse *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCurrFuseIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrFuseIteratorBySettlementGroupID::UpdateCurrent(CWriteableCurrFuse * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCurrFuse;
#endif

CCurrFuse *CCurrFuseIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCurrFuseIteratorBySettlementGroupID::match(CCurrFuse *pCurrFuse)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCurrFuse->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CTradingAccountIteratorBySettlementGroupID> CTradingAccountIteratorBySettlementGroupID::iteratorList;
void CTradingAccountIteratorBySettlementGroupID::init(CTradingAccountFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CTradingAccountIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CTradingAccountIteratorBySettlementGroupID *CTradingAccountIteratorBySettlementGroupID::alloc(CTradingAccountFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CTradingAccountIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CTradingAccountIteratorBySettlementGroupID::~CTradingAccountIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CTradingAccountIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CTradingAccountIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CTradingAccountIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CTradingAccountIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CTradingAccount *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CTradingAccount *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CTradingAccountIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CTradingAccountIteratorBySettlementGroupID::UpdateCurrent(CWriteableTradingAccount * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForTradingAccount;
#endif

CTradingAccount *CTradingAccountIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CTradingAccountIteratorBySettlementGroupID::match(CTradingAccount *pTradingAccount)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pTradingAccount->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CBaseReserveAccountIteratorBySettlementGroupID> CBaseReserveAccountIteratorBySettlementGroupID::iteratorList;
void CBaseReserveAccountIteratorBySettlementGroupID::init(CBaseReserveAccountFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CBaseReserveAccountIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CBaseReserveAccountIteratorBySettlementGroupID *CBaseReserveAccountIteratorBySettlementGroupID::alloc(CBaseReserveAccountFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CBaseReserveAccountIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CBaseReserveAccountIteratorBySettlementGroupID::~CBaseReserveAccountIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CBaseReserveAccountIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CBaseReserveAccountIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CBaseReserveAccountIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CBaseReserveAccountIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CBaseReserveAccount *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CBaseReserveAccount *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CBaseReserveAccountIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CBaseReserveAccountIteratorBySettlementGroupID::UpdateCurrent(CWriteableBaseReserveAccount * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForBaseReserveAccount;
#endif

CBaseReserveAccount *CBaseReserveAccountIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CBaseReserveAccountIteratorBySettlementGroupID::match(CBaseReserveAccount *pBaseReserveAccount)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pBaseReserveAccount->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CPartPositionIteratorStartByInstrument> CPartPositionIteratorStartByInstrument::iteratorList;
void CPartPositionIteratorStartByInstrument::init(CPartPositionFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CPartPositionIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID=InstrumentID.getValue();
	m_compareObject.ParticipantID="";
	m_compareObject.PosiDirection=PD_Net;
	m_compareObject.HedgeFlag=HF_Speculation;
	m_compareObject.TradingRole=ER_Broker;

}

CPartPositionIteratorStartByInstrument *CPartPositionIteratorStartByInstrument::alloc(CPartPositionFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	CPartPositionIteratorStartByInstrument *it;
	it=iteratorList.alloc();
	it->init(pFactory,InstrumentID);
	return it;
}

CPartPositionIteratorStartByInstrument::~CPartPositionIteratorStartByInstrument(void)
{
}

void CPartPositionIteratorStartByInstrument::free(void)
{
	iteratorList.free(this);
}

void CPartPositionIteratorStartByInstrument::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CPartPositionIteratorStartByInstrument");
	
	char buffer[200];
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void CPartPositionIteratorStartByInstrument::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pInstrumentIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pInstrumentIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CPartPositionIteratorStartByInstrument::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CPartPosition *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CPartPositionIteratorStartByInstrument::UpdateCurrent(CWriteablePartPosition * pStartByInstrument,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CPartPosition *)(m_pCurrent->pObject),pStartByInstrument,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByInstrumentForPartPosition;
#endif

CPartPosition *CPartPositionIteratorStartByInstrument::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByInstrumentForPartPosition++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CPartPosition *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CPartPosition *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CPartPositionIteratorStartByInstrument::match(CPartPosition *pPartPosition)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CPartPositionIteratorStartByParticipant> CPartPositionIteratorStartByParticipant::iteratorList;
void CPartPositionIteratorStartByParticipant::init(CPartPositionFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CPartPositionIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID=ParticipantID.getValue();
	m_compareObject.InstrumentID="";
	m_compareObject.PosiDirection=PD_Net;
	m_compareObject.HedgeFlag=HF_Speculation;
	m_compareObject.TradingRole=ER_Broker;

}

CPartPositionIteratorStartByParticipant *CPartPositionIteratorStartByParticipant::alloc(CPartPositionFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	CPartPositionIteratorStartByParticipant *it;
	it=iteratorList.alloc();
	it->init(pFactory,ParticipantID);
	return it;
}

CPartPositionIteratorStartByParticipant::~CPartPositionIteratorStartByParticipant(void)
{
}

void CPartPositionIteratorStartByParticipant::free(void)
{
	iteratorList.free(this);
}

void CPartPositionIteratorStartByParticipant::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CPartPositionIteratorStartByParticipant");
	
	char buffer[200];
	
	m_compareObject.ParticipantID.getString(buffer);
	pLogger->output(indent+1,0,"query ParticipantID=%s",buffer);
	
}

void CPartPositionIteratorStartByParticipant::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pPartInstrumentIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pPartInstrumentIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CPartPositionIteratorStartByParticipant::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CPartPosition *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CPartPositionIteratorStartByParticipant::UpdateCurrent(CWriteablePartPosition * pStartByParticipant,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CPartPosition *)(m_pCurrent->pObject),pStartByParticipant,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByParticipantForPartPosition;
#endif

CPartPosition *CPartPositionIteratorStartByParticipant::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByParticipantForPartPosition++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CPartPosition *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CPartPosition *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CPartPositionIteratorStartByParticipant::match(CPartPosition *pPartPosition)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CPartPositionIteratorBySettlementGroupID> CPartPositionIteratorBySettlementGroupID::iteratorList;
void CPartPositionIteratorBySettlementGroupID::init(CPartPositionFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CPartPositionIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CPartPositionIteratorBySettlementGroupID *CPartPositionIteratorBySettlementGroupID::alloc(CPartPositionFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CPartPositionIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CPartPositionIteratorBySettlementGroupID::~CPartPositionIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CPartPositionIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CPartPositionIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CPartPositionIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CPartPositionIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CPartPosition *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CPartPosition *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CPartPositionIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CPartPositionIteratorBySettlementGroupID::UpdateCurrent(CWriteablePartPosition * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForPartPosition;
#endif

CPartPosition *CPartPositionIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CPartPositionIteratorBySettlementGroupID::match(CPartPosition *pPartPosition)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pPartPosition->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CClientPositionIteratorByClientAndInstrument> CClientPositionIteratorByClientAndInstrument::iteratorList;
void CClientPositionIteratorByClientAndInstrument::init(CClientPositionFactory *pFactory
		, const CReadOnlyClientIDType& ClientID, const CReadOnlyInstrumentIDType& InstrumentID, const CReadOnlyPosiDirectionType& PosiDirection, const CReadOnlyHedgeFlagType& HedgeFlag)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CClientPositionIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ClientID=ClientID.getValue();
	m_compareObject.InstrumentID=InstrumentID.getValue();
	m_compareObject.PosiDirection=PosiDirection.getValue();
	m_compareObject.HedgeFlag=HedgeFlag.getValue();
	m_compareObject.ParticipantID="";

	m_compareObject.calHashClientAndInstrument();
}

CClientPositionIteratorByClientAndInstrument *CClientPositionIteratorByClientAndInstrument::alloc(CClientPositionFactory *pFactory
		, const CReadOnlyClientIDType& ClientID, const CReadOnlyInstrumentIDType& InstrumentID, const CReadOnlyPosiDirectionType& PosiDirection, const CReadOnlyHedgeFlagType& HedgeFlag)
{
	CClientPositionIteratorByClientAndInstrument *it;
	it=iteratorList.alloc();
	it->init(pFactory,ClientID,InstrumentID,PosiDirection,HedgeFlag);
	return it;
}

CClientPositionIteratorByClientAndInstrument::~CClientPositionIteratorByClientAndInstrument(void)
{
	m_Factory->endGet();
}

void CClientPositionIteratorByClientAndInstrument::free(void)
{
	iteratorList.free(this);
}

void CClientPositionIteratorByClientAndInstrument::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CClientPositionIteratorByClientAndInstrument");
	
	char buffer[200];
	
	m_compareObject.ClientID.getString(buffer);
	pLogger->output(indent+1,0,"query ClientID=%s",buffer);
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
	m_compareObject.PosiDirection.getString(buffer);
	pLogger->output(indent+1,0,"query PosiDirection=%s",buffer);
	
	m_compareObject.HedgeFlag.getString(buffer);
	pLogger->output(indent+1,0,"query HedgeFlag=%s",buffer);
	
}

void CClientPositionIteratorByClientAndInstrument::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pClientAndInstrumentHashIndex->searchFirstEqual(m_compareObject.HashClientAndInstrument);

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
			m_pNext=m_Factory->pClientAndInstrumentHashIndex->searchNextEqual(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CClientPositionIteratorByClientAndInstrument::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CClientPosition *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CClientPositionIteratorByClientAndInstrument::UpdateCurrent(CWriteableClientPosition * pByClientAndInstrument,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CClientPosition *)(m_pCurrent->pObject),pByClientAndInstrument,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByClientAndInstrumentForClientPosition;
#endif

CClientPosition *CClientPositionIteratorByClientAndInstrument::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match((CClientPosition *)(m_pCurrent->pObject)))
		{
			///符合条件，那就返回它
			return (CClientPosition *)(m_pCurrent->pObject);
		}
		///不符合，那就再看下一个		
	}
}

int CClientPositionIteratorByClientAndInstrument::match(CClientPosition *pClientPosition)
{
	///如果有一个条件不满足，则失败返回
	if (pClientPosition->HashClientAndInstrument != m_compareObject.HashClientAndInstrument)
	{
		return 0;
	}
	if (compare(pClientPosition->ClientID.getValue(),m_compareObject.ClientID.getValue())!=0)
	{
		return 0;
	}
	if (compare(pClientPosition->InstrumentID.getValue(),m_compareObject.InstrumentID.getValue())!=0)
	{
		return 0;
	}
	if (compare(pClientPosition->PosiDirection.getValue(),m_compareObject.PosiDirection.getValue())!=0)
	{
		return 0;
	}
	if (compare(pClientPosition->HedgeFlag.getValue(),m_compareObject.HedgeFlag.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CClientPositionIteratorStartByParticipant> CClientPositionIteratorStartByParticipant::iteratorList;
void CClientPositionIteratorStartByParticipant::init(CClientPositionFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CClientPositionIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID=ParticipantID.getValue();
	m_compareObject.ClientID="";
	m_compareObject.InstrumentID="";
	m_compareObject.PosiDirection=PD_Net;
	m_compareObject.HedgeFlag=HF_Speculation;

}

CClientPositionIteratorStartByParticipant *CClientPositionIteratorStartByParticipant::alloc(CClientPositionFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	CClientPositionIteratorStartByParticipant *it;
	it=iteratorList.alloc();
	it->init(pFactory,ParticipantID);
	return it;
}

CClientPositionIteratorStartByParticipant::~CClientPositionIteratorStartByParticipant(void)
{
}

void CClientPositionIteratorStartByParticipant::free(void)
{
	iteratorList.free(this);
}

void CClientPositionIteratorStartByParticipant::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CClientPositionIteratorStartByParticipant");
	
	char buffer[200];
	
	m_compareObject.ParticipantID.getString(buffer);
	pLogger->output(indent+1,0,"query ParticipantID=%s",buffer);
	
}

void CClientPositionIteratorStartByParticipant::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pPartClientAndInstumentIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pPartClientAndInstumentIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CClientPositionIteratorStartByParticipant::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CClientPosition *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CClientPositionIteratorStartByParticipant::UpdateCurrent(CWriteableClientPosition * pStartByParticipant,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CClientPosition *)(m_pCurrent->pObject),pStartByParticipant,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByParticipantForClientPosition;
#endif

CClientPosition *CClientPositionIteratorStartByParticipant::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByParticipantForClientPosition++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CClientPosition *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CClientPosition *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CClientPositionIteratorStartByParticipant::match(CClientPosition *pClientPosition)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CClientPositionIteratorStartByClient> CClientPositionIteratorStartByClient::iteratorList;
void CClientPositionIteratorStartByClient::init(CClientPositionFactory *pFactory
		, const CReadOnlyClientIDType& ClientID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CClientPositionIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ClientID=ClientID.getValue();
	m_compareObject.ParticipantID="";
	m_compareObject.InstrumentID="";
	m_compareObject.PosiDirection=PD_Net;
	m_compareObject.HedgeFlag=HF_Speculation;

}

CClientPositionIteratorStartByClient *CClientPositionIteratorStartByClient::alloc(CClientPositionFactory *pFactory
		, const CReadOnlyClientIDType& ClientID)
{
	CClientPositionIteratorStartByClient *it;
	it=iteratorList.alloc();
	it->init(pFactory,ClientID);
	return it;
}

CClientPositionIteratorStartByClient::~CClientPositionIteratorStartByClient(void)
{
}

void CClientPositionIteratorStartByClient::free(void)
{
	iteratorList.free(this);
}

void CClientPositionIteratorStartByClient::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CClientPositionIteratorStartByClient");
	
	char buffer[200];
	
	m_compareObject.ClientID.getString(buffer);
	pLogger->output(indent+1,0,"query ClientID=%s",buffer);
	
}

void CClientPositionIteratorStartByClient::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pClientAndInstumentIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pClientAndInstumentIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CClientPositionIteratorStartByClient::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CClientPosition *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CClientPositionIteratorStartByClient::UpdateCurrent(CWriteableClientPosition * pStartByClient,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CClientPosition *)(m_pCurrent->pObject),pStartByClient,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByClientForClientPosition;
#endif

CClientPosition *CClientPositionIteratorStartByClient::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByClientForClientPosition++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CClientPosition *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CClientPosition *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CClientPositionIteratorStartByClient::match(CClientPosition *pClientPosition)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CClientPositionIteratorStartByInstrument> CClientPositionIteratorStartByInstrument::iteratorList;
void CClientPositionIteratorStartByInstrument::init(CClientPositionFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CClientPositionIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID=InstrumentID.getValue();
	m_compareObject.ParticipantID="";
	m_compareObject.ClientID="";
	m_compareObject.PosiDirection=PD_Net;
	m_compareObject.HedgeFlag=HF_Speculation;

}

CClientPositionIteratorStartByInstrument *CClientPositionIteratorStartByInstrument::alloc(CClientPositionFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	CClientPositionIteratorStartByInstrument *it;
	it=iteratorList.alloc();
	it->init(pFactory,InstrumentID);
	return it;
}

CClientPositionIteratorStartByInstrument::~CClientPositionIteratorStartByInstrument(void)
{
}

void CClientPositionIteratorStartByInstrument::free(void)
{
	iteratorList.free(this);
}

void CClientPositionIteratorStartByInstrument::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CClientPositionIteratorStartByInstrument");
	
	char buffer[200];
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void CClientPositionIteratorStartByInstrument::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pInstumentIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pInstumentIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CClientPositionIteratorStartByInstrument::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CClientPosition *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CClientPositionIteratorStartByInstrument::UpdateCurrent(CWriteableClientPosition * pStartByInstrument,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CClientPosition *)(m_pCurrent->pObject),pStartByInstrument,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByInstrumentForClientPosition;
#endif

CClientPosition *CClientPositionIteratorStartByInstrument::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByInstrumentForClientPosition++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CClientPosition *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CClientPosition *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CClientPositionIteratorStartByInstrument::match(CClientPosition *pClientPosition)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CClientPositionIteratorByInstrumentID> CClientPositionIteratorByInstrumentID::iteratorList;
void CClientPositionIteratorByInstrumentID::init(CClientPositionFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CClientPositionIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID=InstrumentID.getValue();

}

CClientPositionIteratorByInstrumentID *CClientPositionIteratorByInstrumentID::alloc(CClientPositionFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	CClientPositionIteratorByInstrumentID *it;
	it=iteratorList.alloc();
	it->init(pFactory,InstrumentID);
	return it;
}

CClientPositionIteratorByInstrumentID::~CClientPositionIteratorByInstrumentID(void)
{
	m_Factory->endGet();
}

void CClientPositionIteratorByInstrumentID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CClientPositionIteratorByInstrumentID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CClientPositionIteratorByInstrumentID");
	
	char buffer[200];
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void CClientPositionIteratorByInstrumentID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CClientPosition *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CClientPosition *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CClientPositionIteratorByInstrumentID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CClientPositionIteratorByInstrumentID::UpdateCurrent(CWriteableClientPosition * pByInstrumentID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pByInstrumentID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByInstrumentIDForClientPosition;
#endif

CClientPosition *CClientPositionIteratorByInstrumentID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CClientPositionIteratorByInstrumentID::match(CClientPosition *pClientPosition)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pClientPosition->InstrumentID.getValue(),m_compareObject.InstrumentID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CClientPositionIteratorBySettlementGroupID> CClientPositionIteratorBySettlementGroupID::iteratorList;
void CClientPositionIteratorBySettlementGroupID::init(CClientPositionFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CClientPositionIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CClientPositionIteratorBySettlementGroupID *CClientPositionIteratorBySettlementGroupID::alloc(CClientPositionFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CClientPositionIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CClientPositionIteratorBySettlementGroupID::~CClientPositionIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CClientPositionIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CClientPositionIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CClientPositionIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CClientPositionIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CClientPosition *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CClientPosition *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CClientPositionIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CClientPositionIteratorBySettlementGroupID::UpdateCurrent(CWriteableClientPosition * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForClientPosition;
#endif

CClientPosition *CClientPositionIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CClientPositionIteratorBySettlementGroupID::match(CClientPosition *pClientPosition)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pClientPosition->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CHedgeVolumeIteratorBySettlementGroupID> CHedgeVolumeIteratorBySettlementGroupID::iteratorList;
void CHedgeVolumeIteratorBySettlementGroupID::init(CHedgeVolumeFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CHedgeVolumeIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CHedgeVolumeIteratorBySettlementGroupID *CHedgeVolumeIteratorBySettlementGroupID::alloc(CHedgeVolumeFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CHedgeVolumeIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CHedgeVolumeIteratorBySettlementGroupID::~CHedgeVolumeIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CHedgeVolumeIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CHedgeVolumeIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CHedgeVolumeIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CHedgeVolumeIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CHedgeVolume *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CHedgeVolume *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CHedgeVolumeIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CHedgeVolumeIteratorBySettlementGroupID::UpdateCurrent(CWriteableHedgeVolume * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForHedgeVolume;
#endif

CHedgeVolume *CHedgeVolumeIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CHedgeVolumeIteratorBySettlementGroupID::match(CHedgeVolume *pHedgeVolume)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pHedgeVolume->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CHedgeVolumeIteratorStartByPartClientAndInstrument> CHedgeVolumeIteratorStartByPartClientAndInstrument::iteratorList;
void CHedgeVolumeIteratorStartByPartClientAndInstrument::init(CHedgeVolumeFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID, const CReadOnlyClientIDType& ClientID, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CHedgeVolumeIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID=ParticipantID.getValue();
	m_compareObject.ClientID=ClientID.getValue();
	m_compareObject.InstrumentID=InstrumentID.getValue();

}

CHedgeVolumeIteratorStartByPartClientAndInstrument *CHedgeVolumeIteratorStartByPartClientAndInstrument::alloc(CHedgeVolumeFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID, const CReadOnlyClientIDType& ClientID, const CReadOnlyInstrumentIDType& InstrumentID)
{
	CHedgeVolumeIteratorStartByPartClientAndInstrument *it;
	it=iteratorList.alloc();
	it->init(pFactory,ParticipantID,ClientID,InstrumentID);
	return it;
}

CHedgeVolumeIteratorStartByPartClientAndInstrument::~CHedgeVolumeIteratorStartByPartClientAndInstrument(void)
{
}

void CHedgeVolumeIteratorStartByPartClientAndInstrument::free(void)
{
	iteratorList.free(this);
}

void CHedgeVolumeIteratorStartByPartClientAndInstrument::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CHedgeVolumeIteratorStartByPartClientAndInstrument");
	
	char buffer[200];
	
	m_compareObject.ParticipantID.getString(buffer);
	pLogger->output(indent+1,0,"query ParticipantID=%s",buffer);
	
	m_compareObject.ClientID.getString(buffer);
	pLogger->output(indent+1,0,"query ClientID=%s",buffer);
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void CHedgeVolumeIteratorStartByPartClientAndInstrument::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pPartClientAndInstrumentIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pPartClientAndInstrumentIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CHedgeVolumeIteratorStartByPartClientAndInstrument::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CHedgeVolume *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CHedgeVolumeIteratorStartByPartClientAndInstrument::UpdateCurrent(CWriteableHedgeVolume * pStartByPartClientAndInstrument,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CHedgeVolume *)(m_pCurrent->pObject),pStartByPartClientAndInstrument,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByPartClientAndInstrumentForHedgeVolume;
#endif

CHedgeVolume *CHedgeVolumeIteratorStartByPartClientAndInstrument::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByPartClientAndInstrumentForHedgeVolume++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CHedgeVolume *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CHedgeVolume *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CHedgeVolumeIteratorStartByPartClientAndInstrument::match(CHedgeVolume *pHedgeVolume)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CRemainOrderIteratorBySettlementGroupID> CRemainOrderIteratorBySettlementGroupID::iteratorList;
void CRemainOrderIteratorBySettlementGroupID::init(CRemainOrderFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CRemainOrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CRemainOrderIteratorBySettlementGroupID *CRemainOrderIteratorBySettlementGroupID::alloc(CRemainOrderFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CRemainOrderIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CRemainOrderIteratorBySettlementGroupID::~CRemainOrderIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CRemainOrderIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CRemainOrderIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CRemainOrderIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CRemainOrderIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CRemainOrder *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CRemainOrder *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CRemainOrderIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CRemainOrderIteratorBySettlementGroupID::UpdateCurrent(CWriteableRemainOrder * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForRemainOrder;
#endif

CRemainOrder *CRemainOrderIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CRemainOrderIteratorBySettlementGroupID::match(CRemainOrder *pRemainOrder)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pRemainOrder->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CRemainOrderIteratorByInstrumentID> CRemainOrderIteratorByInstrumentID::iteratorList;
void CRemainOrderIteratorByInstrumentID::init(CRemainOrderFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CRemainOrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID=InstrumentID.getValue();

}

CRemainOrderIteratorByInstrumentID *CRemainOrderIteratorByInstrumentID::alloc(CRemainOrderFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	CRemainOrderIteratorByInstrumentID *it;
	it=iteratorList.alloc();
	it->init(pFactory,InstrumentID);
	return it;
}

CRemainOrderIteratorByInstrumentID::~CRemainOrderIteratorByInstrumentID(void)
{
}

void CRemainOrderIteratorByInstrumentID::free(void)
{
	iteratorList.free(this);
}

void CRemainOrderIteratorByInstrumentID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CRemainOrderIteratorByInstrumentID");
	
	char buffer[200];
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void CRemainOrderIteratorByInstrumentID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pInstrumentIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pInstrumentIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CRemainOrderIteratorByInstrumentID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CRemainOrder *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CRemainOrderIteratorByInstrumentID::UpdateCurrent(CWriteableRemainOrder * pByInstrumentID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CRemainOrder *)(m_pCurrent->pObject),pByInstrumentID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByInstrumentIDForRemainOrder;
#endif

CRemainOrder *CRemainOrderIteratorByInstrumentID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByInstrumentIDForRemainOrder++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CRemainOrder *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CRemainOrder *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CRemainOrderIteratorByInstrumentID::match(CRemainOrder *pRemainOrder)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pRemainOrder->InstrumentID.getValue(),m_compareObject.InstrumentID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CMarketDataIteratorBySettlementGroupID> CMarketDataIteratorBySettlementGroupID::iteratorList;
void CMarketDataIteratorBySettlementGroupID::init(CMarketDataFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CMarketDataIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CMarketDataIteratorBySettlementGroupID *CMarketDataIteratorBySettlementGroupID::alloc(CMarketDataFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CMarketDataIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CMarketDataIteratorBySettlementGroupID::~CMarketDataIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CMarketDataIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CMarketDataIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CMarketDataIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CMarketDataIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CMarketData *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CMarketData *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CMarketDataIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CMarketDataIteratorBySettlementGroupID::UpdateCurrent(CWriteableMarketData * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForMarketData;
#endif

CMarketData *CMarketDataIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CMarketDataIteratorBySettlementGroupID::match(CMarketData *pMarketData)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pMarketData->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CClearingPartPositionIteratorBySettlementGroupID> CClearingPartPositionIteratorBySettlementGroupID::iteratorList;
void CClearingPartPositionIteratorBySettlementGroupID::init(CClearingPartPositionFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CClearingPartPositionIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CClearingPartPositionIteratorBySettlementGroupID *CClearingPartPositionIteratorBySettlementGroupID::alloc(CClearingPartPositionFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CClearingPartPositionIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CClearingPartPositionIteratorBySettlementGroupID::~CClearingPartPositionIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CClearingPartPositionIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CClearingPartPositionIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CClearingPartPositionIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CClearingPartPositionIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CClearingPartPosition *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CClearingPartPosition *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CClearingPartPositionIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CClearingPartPositionIteratorBySettlementGroupID::UpdateCurrent(CWriteableClearingPartPosition * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForClearingPartPosition;
#endif

CClearingPartPosition *CClearingPartPositionIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CClearingPartPositionIteratorBySettlementGroupID::match(CClearingPartPosition *pClearingPartPosition)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pClearingPartPosition->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CInstrumentStatusIteratorStartByInstrumentID> CInstrumentStatusIteratorStartByInstrumentID::iteratorList;
void CInstrumentStatusIteratorStartByInstrumentID::init(CInstrumentStatusFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CInstrumentStatusIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID=InstrumentID.getValue();

}

CInstrumentStatusIteratorStartByInstrumentID *CInstrumentStatusIteratorStartByInstrumentID::alloc(CInstrumentStatusFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	CInstrumentStatusIteratorStartByInstrumentID *it;
	it=iteratorList.alloc();
	it->init(pFactory,InstrumentID);
	return it;
}

CInstrumentStatusIteratorStartByInstrumentID::~CInstrumentStatusIteratorStartByInstrumentID(void)
{
}

void CInstrumentStatusIteratorStartByInstrumentID::free(void)
{
	iteratorList.free(this);
}

void CInstrumentStatusIteratorStartByInstrumentID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CInstrumentStatusIteratorStartByInstrumentID");
	
	char buffer[200];
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void CInstrumentStatusIteratorStartByInstrumentID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pInstrumentIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pInstrumentIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CInstrumentStatusIteratorStartByInstrumentID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CInstrumentStatus *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CInstrumentStatusIteratorStartByInstrumentID::UpdateCurrent(CWriteableInstrumentStatus * pStartByInstrumentID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CInstrumentStatus *)(m_pCurrent->pObject),pStartByInstrumentID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByInstrumentIDForInstrumentStatus;
#endif

CInstrumentStatus *CInstrumentStatusIteratorStartByInstrumentID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByInstrumentIDForInstrumentStatus++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CInstrumentStatus *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CInstrumentStatus *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CInstrumentStatusIteratorStartByInstrumentID::match(CInstrumentStatus *pInstrumentStatus)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CInstrumentStatusIteratorBySettlementGroupID> CInstrumentStatusIteratorBySettlementGroupID::iteratorList;
void CInstrumentStatusIteratorBySettlementGroupID::init(CInstrumentStatusFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CInstrumentStatusIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CInstrumentStatusIteratorBySettlementGroupID *CInstrumentStatusIteratorBySettlementGroupID::alloc(CInstrumentStatusFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CInstrumentStatusIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CInstrumentStatusIteratorBySettlementGroupID::~CInstrumentStatusIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CInstrumentStatusIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CInstrumentStatusIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CInstrumentStatusIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CInstrumentStatusIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CInstrumentStatus *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CInstrumentStatus *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CInstrumentStatusIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CInstrumentStatusIteratorBySettlementGroupID::UpdateCurrent(CWriteableInstrumentStatus * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForInstrumentStatus;
#endif

CInstrumentStatus *CInstrumentStatusIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CInstrumentStatusIteratorBySettlementGroupID::match(CInstrumentStatus *pInstrumentStatus)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pInstrumentStatus->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<COrderIteratorStartByParticipantID> COrderIteratorStartByParticipantID::iteratorList;
void COrderIteratorStartByParticipantID::init(COrderFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use COrderIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID=ParticipantID.getValue();

}

COrderIteratorStartByParticipantID *COrderIteratorStartByParticipantID::alloc(COrderFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	COrderIteratorStartByParticipantID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ParticipantID);
	return it;
}

COrderIteratorStartByParticipantID::~COrderIteratorStartByParticipantID(void)
{
}

void COrderIteratorStartByParticipantID::free(void)
{
	iteratorList.free(this);
}

void COrderIteratorStartByParticipantID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"COrderIteratorStartByParticipantID");
	
	char buffer[200];
	
	m_compareObject.ParticipantID.getString(buffer);
	pLogger->output(indent+1,0,"query ParticipantID=%s",buffer);
	
}

void COrderIteratorStartByParticipantID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pParticipantIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pParticipantIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void COrderIteratorStartByParticipantID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((COrder *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void COrderIteratorStartByParticipantID::UpdateCurrent(CWriteableOrder * pStartByParticipantID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((COrder *)(m_pCurrent->pObject),pStartByParticipantID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByParticipantIDForOrder;
#endif

COrder *COrderIteratorStartByParticipantID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForOrder++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((COrder *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (COrder *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int COrderIteratorStartByParticipantID::match(COrder *pOrder)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<COrderIteratorBySettlementGroupID> COrderIteratorBySettlementGroupID::iteratorList;
void COrderIteratorBySettlementGroupID::init(COrderFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use COrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

COrderIteratorBySettlementGroupID *COrderIteratorBySettlementGroupID::alloc(COrderFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	COrderIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

COrderIteratorBySettlementGroupID::~COrderIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void COrderIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void COrderIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"COrderIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void COrderIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(COrder *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(COrder *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void COrderIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void COrderIteratorBySettlementGroupID::UpdateCurrent(CWriteableOrder * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForOrder;
#endif

COrder *COrderIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int COrderIteratorBySettlementGroupID::match(COrder *pOrder)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pOrder->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<COrderIteratorByUserID> COrderIteratorByUserID::iteratorList;
void COrderIteratorByUserID::init(COrderFactory *pFactory
		, const CReadOnlyUserIDType& UserID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use COrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.UserID=UserID.getValue();
	m_compareObject.OrderLocalID="zzzzzzzzzzzz";

}

COrderIteratorByUserID *COrderIteratorByUserID::alloc(COrderFactory *pFactory
		, const CReadOnlyUserIDType& UserID)
{
	COrderIteratorByUserID *it;
	it=iteratorList.alloc();
	it->init(pFactory,UserID);
	return it;
}

COrderIteratorByUserID::~COrderIteratorByUserID(void)
{
}

void COrderIteratorByUserID::free(void)
{
	iteratorList.free(this);
}

void COrderIteratorByUserID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"COrderIteratorByUserID");
	
	char buffer[200];
	
	m_compareObject.UserID.getString(buffer);
	pLogger->output(indent+1,0,"query UserID=%s",buffer);
	
}

void COrderIteratorByUserID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pOrderLocalIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pOrderLocalIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void COrderIteratorByUserID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((COrder *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void COrderIteratorByUserID::UpdateCurrent(CWriteableOrder * pByUserID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((COrder *)(m_pCurrent->pObject),pByUserID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByUserIDForOrder;
#endif

COrder *COrderIteratorByUserID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByUserIDForOrder++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((COrder *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (COrder *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int COrderIteratorByUserID::match(COrder *pOrder)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pOrder->UserID.getValue(),m_compareObject.UserID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<COrderIteratorByInstrumentID> COrderIteratorByInstrumentID::iteratorList;
void COrderIteratorByInstrumentID::init(COrderFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use COrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID=InstrumentID.getValue();

}

COrderIteratorByInstrumentID *COrderIteratorByInstrumentID::alloc(COrderFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	COrderIteratorByInstrumentID *it;
	it=iteratorList.alloc();
	it->init(pFactory,InstrumentID);
	return it;
}

COrderIteratorByInstrumentID::~COrderIteratorByInstrumentID(void)
{
	m_Factory->endGet();
}

void COrderIteratorByInstrumentID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void COrderIteratorByInstrumentID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"COrderIteratorByInstrumentID");
	
	char buffer[200];
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void COrderIteratorByInstrumentID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(COrder *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(COrder *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void COrderIteratorByInstrumentID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void COrderIteratorByInstrumentID::UpdateCurrent(CWriteableOrder * pByInstrumentID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pByInstrumentID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByInstrumentIDForOrder;
#endif

COrder *COrderIteratorByInstrumentID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int COrderIteratorByInstrumentID::match(COrder *pOrder)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pOrder->InstrumentID.getValue(),m_compareObject.InstrumentID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<COrderIteratorStartByInstrumentID> COrderIteratorStartByInstrumentID::iteratorList;
void COrderIteratorStartByInstrumentID::init(COrderFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use COrderIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID=InstrumentID.getValue();

}

COrderIteratorStartByInstrumentID *COrderIteratorStartByInstrumentID::alloc(COrderFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	COrderIteratorStartByInstrumentID *it;
	it=iteratorList.alloc();
	it->init(pFactory,InstrumentID);
	return it;
}

COrderIteratorStartByInstrumentID::~COrderIteratorStartByInstrumentID(void)
{
}

void COrderIteratorStartByInstrumentID::free(void)
{
	iteratorList.free(this);
}

void COrderIteratorStartByInstrumentID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"COrderIteratorStartByInstrumentID");
	
	char buffer[200];
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void COrderIteratorStartByInstrumentID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pInstrumentIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pInstrumentIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void COrderIteratorStartByInstrumentID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((COrder *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void COrderIteratorStartByInstrumentID::UpdateCurrent(CWriteableOrder * pStartByInstrumentID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((COrder *)(m_pCurrent->pObject),pStartByInstrumentID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByInstrumentIDForOrder;
#endif

COrder *COrderIteratorStartByInstrumentID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByInstrumentIDForOrder++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((COrder *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (COrder *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int COrderIteratorStartByInstrumentID::match(COrder *pOrder)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CCombOrderIteratorStartByParticipantID> CCombOrderIteratorStartByParticipantID::iteratorList;
void CCombOrderIteratorStartByParticipantID::init(CCombOrderFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CCombOrderIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID=ParticipantID.getValue();

}

CCombOrderIteratorStartByParticipantID *CCombOrderIteratorStartByParticipantID::alloc(CCombOrderFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	CCombOrderIteratorStartByParticipantID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ParticipantID);
	return it;
}

CCombOrderIteratorStartByParticipantID::~CCombOrderIteratorStartByParticipantID(void)
{
}

void CCombOrderIteratorStartByParticipantID::free(void)
{
	iteratorList.free(this);
}

void CCombOrderIteratorStartByParticipantID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCombOrderIteratorStartByParticipantID");
	
	char buffer[200];
	
	m_compareObject.ParticipantID.getString(buffer);
	pLogger->output(indent+1,0,"query ParticipantID=%s",buffer);
	
}

void CCombOrderIteratorStartByParticipantID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pParticipantIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pParticipantIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CCombOrderIteratorStartByParticipantID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CCombOrder *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CCombOrderIteratorStartByParticipantID::UpdateCurrent(CWriteableCombOrder * pStartByParticipantID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CCombOrder *)(m_pCurrent->pObject),pStartByParticipantID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByParticipantIDForCombOrder;
#endif

CCombOrder *CCombOrderIteratorStartByParticipantID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForCombOrder++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CCombOrder *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CCombOrder *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CCombOrderIteratorStartByParticipantID::match(CCombOrder *pCombOrder)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CCombOrderIteratorBySettlementGroupID> CCombOrderIteratorBySettlementGroupID::iteratorList;
void CCombOrderIteratorBySettlementGroupID::init(CCombOrderFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCombOrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCombOrderIteratorBySettlementGroupID *CCombOrderIteratorBySettlementGroupID::alloc(CCombOrderFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCombOrderIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCombOrderIteratorBySettlementGroupID::~CCombOrderIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCombOrderIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCombOrderIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCombOrderIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCombOrderIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCombOrder *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCombOrder *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCombOrderIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCombOrderIteratorBySettlementGroupID::UpdateCurrent(CWriteableCombOrder * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCombOrder;
#endif

CCombOrder *CCombOrderIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCombOrderIteratorBySettlementGroupID::match(CCombOrder *pCombOrder)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCombOrder->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CCombOrderIteratorByUserID> CCombOrderIteratorByUserID::iteratorList;
void CCombOrderIteratorByUserID::init(CCombOrderFactory *pFactory
		, const CReadOnlyUserIDType& UserID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCombOrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.UserID=UserID.getValue();
	m_compareObject.CombOrderLocalID="zzzzzzzzzzzz";

}

CCombOrderIteratorByUserID *CCombOrderIteratorByUserID::alloc(CCombOrderFactory *pFactory
		, const CReadOnlyUserIDType& UserID)
{
	CCombOrderIteratorByUserID *it;
	it=iteratorList.alloc();
	it->init(pFactory,UserID);
	return it;
}

CCombOrderIteratorByUserID::~CCombOrderIteratorByUserID(void)
{
}

void CCombOrderIteratorByUserID::free(void)
{
	iteratorList.free(this);
}

void CCombOrderIteratorByUserID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCombOrderIteratorByUserID");
	
	char buffer[200];
	
	m_compareObject.UserID.getString(buffer);
	pLogger->output(indent+1,0,"query UserID=%s",buffer);
	
}

void CCombOrderIteratorByUserID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pCombOrderLocalIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pCombOrderLocalIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CCombOrderIteratorByUserID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CCombOrder *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CCombOrderIteratorByUserID::UpdateCurrent(CWriteableCombOrder * pByUserID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CCombOrder *)(m_pCurrent->pObject),pByUserID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByUserIDForCombOrder;
#endif

CCombOrder *CCombOrderIteratorByUserID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByUserIDForCombOrder++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CCombOrder *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CCombOrder *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CCombOrderIteratorByUserID::match(CCombOrder *pCombOrder)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCombOrder->UserID.getValue(),m_compareObject.UserID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<COTCOrderIteratorBySettlementGroupID> COTCOrderIteratorBySettlementGroupID::iteratorList;
void COTCOrderIteratorBySettlementGroupID::init(COTCOrderFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use COTCOrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

COTCOrderIteratorBySettlementGroupID *COTCOrderIteratorBySettlementGroupID::alloc(COTCOrderFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	COTCOrderIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

COTCOrderIteratorBySettlementGroupID::~COTCOrderIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void COTCOrderIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void COTCOrderIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"COTCOrderIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void COTCOrderIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(COTCOrder *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(COTCOrder *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void COTCOrderIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void COTCOrderIteratorBySettlementGroupID::UpdateCurrent(CWriteableOTCOrder * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForOTCOrder;
#endif

COTCOrder *COTCOrderIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int COTCOrderIteratorBySettlementGroupID::match(COTCOrder *pOTCOrder)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pOTCOrder->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CImplyOrderIteratorByImplyLeg> CImplyOrderIteratorByImplyLeg::iteratorList;
void CImplyOrderIteratorByImplyLeg::init(CImplyOrderFactory *pFactory
		, const CReadOnlyInstrumentIDType& CombInstrumentID, const CReadOnlyLegIDType& ImplyLegID, const CReadOnlyDirectionType& Direction)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CImplyOrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.CombInstrumentID=CombInstrumentID.getValue();
	m_compareObject.ImplyLegID=ImplyLegID.getValue();
	m_compareObject.Direction=Direction.getValue();

}

CImplyOrderIteratorByImplyLeg *CImplyOrderIteratorByImplyLeg::alloc(CImplyOrderFactory *pFactory
		, const CReadOnlyInstrumentIDType& CombInstrumentID, const CReadOnlyLegIDType& ImplyLegID, const CReadOnlyDirectionType& Direction)
{
	CImplyOrderIteratorByImplyLeg *it;
	it=iteratorList.alloc();
	it->init(pFactory,CombInstrumentID,ImplyLegID,Direction);
	return it;
}

CImplyOrderIteratorByImplyLeg::~CImplyOrderIteratorByImplyLeg(void)
{
}

void CImplyOrderIteratorByImplyLeg::free(void)
{
	iteratorList.free(this);
}

void CImplyOrderIteratorByImplyLeg::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CImplyOrderIteratorByImplyLeg");
	
	char buffer[200];
	
	m_compareObject.CombInstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query CombInstrumentID=%s",buffer);
	
	m_compareObject.ImplyLegID.getString(buffer);
	pLogger->output(indent+1,0,"query ImplyLegID=%s",buffer);
	
	m_compareObject.Direction.getString(buffer);
	pLogger->output(indent+1,0,"query Direction=%s",buffer);
	
}

void CImplyOrderIteratorByImplyLeg::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pImplyLegInstrumentIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pImplyLegInstrumentIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CImplyOrderIteratorByImplyLeg::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CImplyOrder *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CImplyOrderIteratorByImplyLeg::UpdateCurrent(CWriteableImplyOrder * pByImplyLeg,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CImplyOrder *)(m_pCurrent->pObject),pByImplyLeg,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByImplyLegForImplyOrder;
#endif

CImplyOrder *CImplyOrderIteratorByImplyLeg::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByImplyLegForImplyOrder++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CImplyOrder *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CImplyOrder *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CImplyOrderIteratorByImplyLeg::match(CImplyOrder *pImplyOrder)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pImplyOrder->CombInstrumentID.getValue(),m_compareObject.CombInstrumentID.getValue())!=0)
	{
		return 0;
	}
	if (compare(pImplyOrder->ImplyLegID.getValue(),m_compareObject.ImplyLegID.getValue())!=0)
	{
		return 0;
	}
	if (compare(pImplyOrder->Direction.getValue(),m_compareObject.Direction.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CImplyOrderIteratorByImplyOrderAndAnchorLeg> CImplyOrderIteratorByImplyOrderAndAnchorLeg::iteratorList;
void CImplyOrderIteratorByImplyOrderAndAnchorLeg::init(CImplyOrderFactory *pFactory
		, const CReadOnlyOrderSysIDType& ImplyOrderID, const CReadOnlyLegIDType& AnchorLegID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CImplyOrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ImplyOrderID=ImplyOrderID.getValue();
	m_compareObject.AnchorLegID=AnchorLegID.getValue();
	m_compareObject.Priority=0;

}

CImplyOrderIteratorByImplyOrderAndAnchorLeg *CImplyOrderIteratorByImplyOrderAndAnchorLeg::alloc(CImplyOrderFactory *pFactory
		, const CReadOnlyOrderSysIDType& ImplyOrderID, const CReadOnlyLegIDType& AnchorLegID)
{
	CImplyOrderIteratorByImplyOrderAndAnchorLeg *it;
	it=iteratorList.alloc();
	it->init(pFactory,ImplyOrderID,AnchorLegID);
	return it;
}

CImplyOrderIteratorByImplyOrderAndAnchorLeg::~CImplyOrderIteratorByImplyOrderAndAnchorLeg(void)
{
}

void CImplyOrderIteratorByImplyOrderAndAnchorLeg::free(void)
{
	iteratorList.free(this);
}

void CImplyOrderIteratorByImplyOrderAndAnchorLeg::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CImplyOrderIteratorByImplyOrderAndAnchorLeg");
	
	char buffer[200];
	
	m_compareObject.ImplyOrderID.getString(buffer);
	pLogger->output(indent+1,0,"query ImplyOrderID=%s",buffer);
	
	m_compareObject.AnchorLegID.getString(buffer);
	pLogger->output(indent+1,0,"query AnchorLegID=%s",buffer);
	
}

void CImplyOrderIteratorByImplyOrderAndAnchorLeg::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pImplyOrderAndAnchorLegIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pImplyOrderAndAnchorLegIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CImplyOrderIteratorByImplyOrderAndAnchorLeg::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CImplyOrder *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CImplyOrderIteratorByImplyOrderAndAnchorLeg::UpdateCurrent(CWriteableImplyOrder * pByImplyOrderAndAnchorLeg,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CImplyOrder *)(m_pCurrent->pObject),pByImplyOrderAndAnchorLeg,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByImplyOrderAndAnchorLegForImplyOrder;
#endif

CImplyOrder *CImplyOrderIteratorByImplyOrderAndAnchorLeg::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByImplyOrderAndAnchorLegForImplyOrder++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CImplyOrder *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CImplyOrder *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CImplyOrderIteratorByImplyOrderAndAnchorLeg::match(CImplyOrder *pImplyOrder)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pImplyOrder->ImplyOrderID.getValue(),m_compareObject.ImplyOrderID.getValue())!=0)
	{
		return 0;
	}
	if (compare(pImplyOrder->AnchorLegID.getValue(),m_compareObject.AnchorLegID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CImplyOrderIteratorByImplyOrder> CImplyOrderIteratorByImplyOrder::iteratorList;
void CImplyOrderIteratorByImplyOrder::init(CImplyOrderFactory *pFactory
		, const CReadOnlyOrderSysIDType& ImplyOrderID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CImplyOrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ImplyOrderID=ImplyOrderID.getValue();
	m_compareObject.AnchorLegID=0;
	m_compareObject.Priority=0;

}

CImplyOrderIteratorByImplyOrder *CImplyOrderIteratorByImplyOrder::alloc(CImplyOrderFactory *pFactory
		, const CReadOnlyOrderSysIDType& ImplyOrderID)
{
	CImplyOrderIteratorByImplyOrder *it;
	it=iteratorList.alloc();
	it->init(pFactory,ImplyOrderID);
	return it;
}

CImplyOrderIteratorByImplyOrder::~CImplyOrderIteratorByImplyOrder(void)
{
}

void CImplyOrderIteratorByImplyOrder::free(void)
{
	iteratorList.free(this);
}

void CImplyOrderIteratorByImplyOrder::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CImplyOrderIteratorByImplyOrder");
	
	char buffer[200];
	
	m_compareObject.ImplyOrderID.getString(buffer);
	pLogger->output(indent+1,0,"query ImplyOrderID=%s",buffer);
	
}

void CImplyOrderIteratorByImplyOrder::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pImplyOrderAndAnchorLegIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pImplyOrderAndAnchorLegIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CImplyOrderIteratorByImplyOrder::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CImplyOrder *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CImplyOrderIteratorByImplyOrder::UpdateCurrent(CWriteableImplyOrder * pByImplyOrder,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CImplyOrder *)(m_pCurrent->pObject),pByImplyOrder,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByImplyOrderForImplyOrder;
#endif

CImplyOrder *CImplyOrderIteratorByImplyOrder::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByImplyOrderForImplyOrder++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CImplyOrder *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CImplyOrder *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CImplyOrderIteratorByImplyOrder::match(CImplyOrder *pImplyOrder)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pImplyOrder->ImplyOrderID.getValue(),m_compareObject.ImplyOrderID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CQuoteIteratorByUserID> CQuoteIteratorByUserID::iteratorList;
void CQuoteIteratorByUserID::init(CQuoteFactory *pFactory
		, const CReadOnlyUserIDType& UserID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CQuoteIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.UserID=UserID.getValue();
	m_compareObject.QuoteLocalID="zzzzzzzzzzzz";

}

CQuoteIteratorByUserID *CQuoteIteratorByUserID::alloc(CQuoteFactory *pFactory
		, const CReadOnlyUserIDType& UserID)
{
	CQuoteIteratorByUserID *it;
	it=iteratorList.alloc();
	it->init(pFactory,UserID);
	return it;
}

CQuoteIteratorByUserID::~CQuoteIteratorByUserID(void)
{
}

void CQuoteIteratorByUserID::free(void)
{
	iteratorList.free(this);
}

void CQuoteIteratorByUserID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CQuoteIteratorByUserID");
	
	char buffer[200];
	
	m_compareObject.UserID.getString(buffer);
	pLogger->output(indent+1,0,"query UserID=%s",buffer);
	
}

void CQuoteIteratorByUserID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pQuoteLocalIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pQuoteLocalIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CQuoteIteratorByUserID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CQuote *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CQuoteIteratorByUserID::UpdateCurrent(CWriteableQuote * pByUserID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CQuote *)(m_pCurrent->pObject),pByUserID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByUserIDForQuote;
#endif

CQuote *CQuoteIteratorByUserID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByUserIDForQuote++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CQuote *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CQuote *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CQuoteIteratorByUserID::match(CQuote *pQuote)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pQuote->UserID.getValue(),m_compareObject.UserID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CQuoteIteratorStartByParticipantID> CQuoteIteratorStartByParticipantID::iteratorList;
void CQuoteIteratorStartByParticipantID::init(CQuoteFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CQuoteIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID=ParticipantID.getValue();
	m_compareObject.QuoteSysID="999999999999";
	m_compareObject.InstrumentID="";
	m_compareObject.ClientID="";

}

CQuoteIteratorStartByParticipantID *CQuoteIteratorStartByParticipantID::alloc(CQuoteFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	CQuoteIteratorStartByParticipantID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ParticipantID);
	return it;
}

CQuoteIteratorStartByParticipantID::~CQuoteIteratorStartByParticipantID(void)
{
}

void CQuoteIteratorStartByParticipantID::free(void)
{
	iteratorList.free(this);
}

void CQuoteIteratorStartByParticipantID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CQuoteIteratorStartByParticipantID");
	
	char buffer[200];
	
	m_compareObject.ParticipantID.getString(buffer);
	pLogger->output(indent+1,0,"query ParticipantID=%s",buffer);
	
}

void CQuoteIteratorStartByParticipantID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pPartClientAndInstrumentIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pPartClientAndInstrumentIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CQuoteIteratorStartByParticipantID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CQuote *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CQuoteIteratorStartByParticipantID::UpdateCurrent(CWriteableQuote * pStartByParticipantID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CQuote *)(m_pCurrent->pObject),pStartByParticipantID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByParticipantIDForQuote;
#endif

CQuote *CQuoteIteratorStartByParticipantID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForQuote++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CQuote *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CQuote *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CQuoteIteratorStartByParticipantID::match(CQuote *pQuote)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CQuoteIteratorBySettlementGroupID> CQuoteIteratorBySettlementGroupID::iteratorList;
void CQuoteIteratorBySettlementGroupID::init(CQuoteFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CQuoteIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CQuoteIteratorBySettlementGroupID *CQuoteIteratorBySettlementGroupID::alloc(CQuoteFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CQuoteIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CQuoteIteratorBySettlementGroupID::~CQuoteIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CQuoteIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CQuoteIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CQuoteIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CQuoteIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CQuote *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CQuote *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CQuoteIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CQuoteIteratorBySettlementGroupID::UpdateCurrent(CWriteableQuote * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForQuote;
#endif

CQuote *CQuoteIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CQuoteIteratorBySettlementGroupID::match(CQuote *pQuote)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pQuote->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CMBLMarketDataIteratorByBuyMBLData> CMBLMarketDataIteratorByBuyMBLData::iteratorList;
void CMBLMarketDataIteratorByBuyMBLData::init(CMBLMarketDataFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CMBLMarketDataIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID=InstrumentID.getValue();
	m_compareObject.Direction=D_Buy;
	m_compareObject.Price=999999999;

}

CMBLMarketDataIteratorByBuyMBLData *CMBLMarketDataIteratorByBuyMBLData::alloc(CMBLMarketDataFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	CMBLMarketDataIteratorByBuyMBLData *it;
	it=iteratorList.alloc();
	it->init(pFactory,InstrumentID);
	return it;
}

CMBLMarketDataIteratorByBuyMBLData::~CMBLMarketDataIteratorByBuyMBLData(void)
{
}

void CMBLMarketDataIteratorByBuyMBLData::free(void)
{
	iteratorList.free(this);
}

void CMBLMarketDataIteratorByBuyMBLData::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CMBLMarketDataIteratorByBuyMBLData");
	
	char buffer[200];
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void CMBLMarketDataIteratorByBuyMBLData::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pBuyMBLIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pBuyMBLIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CMBLMarketDataIteratorByBuyMBLData::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CMBLMarketData *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CMBLMarketDataIteratorByBuyMBLData::UpdateCurrent(CWriteableMBLMarketData * pByBuyMBLData,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CMBLMarketData *)(m_pCurrent->pObject),pByBuyMBLData,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByBuyMBLDataForMBLMarketData;
#endif

CMBLMarketData *CMBLMarketDataIteratorByBuyMBLData::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByBuyMBLDataForMBLMarketData++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CMBLMarketData *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CMBLMarketData *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CMBLMarketDataIteratorByBuyMBLData::match(CMBLMarketData *pMBLMarketData)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pMBLMarketData->InstrumentID.getValue(),m_compareObject.InstrumentID.getValue())!=0)
	{
		return 0;
	}
	if (compare(pMBLMarketData->Direction.getValue(),D_Buy)!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CMBLMarketDataIteratorBySellMBLData> CMBLMarketDataIteratorBySellMBLData::iteratorList;
void CMBLMarketDataIteratorBySellMBLData::init(CMBLMarketDataFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CMBLMarketDataIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID=InstrumentID.getValue();
	m_compareObject.Direction=D_Sell;
	m_compareObject.Price=-999999999;

}

CMBLMarketDataIteratorBySellMBLData *CMBLMarketDataIteratorBySellMBLData::alloc(CMBLMarketDataFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	CMBLMarketDataIteratorBySellMBLData *it;
	it=iteratorList.alloc();
	it->init(pFactory,InstrumentID);
	return it;
}

CMBLMarketDataIteratorBySellMBLData::~CMBLMarketDataIteratorBySellMBLData(void)
{
}

void CMBLMarketDataIteratorBySellMBLData::free(void)
{
	iteratorList.free(this);
}

void CMBLMarketDataIteratorBySellMBLData::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CMBLMarketDataIteratorBySellMBLData");
	
	char buffer[200];
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void CMBLMarketDataIteratorBySellMBLData::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pSellMBLIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pSellMBLIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CMBLMarketDataIteratorBySellMBLData::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CMBLMarketData *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CMBLMarketDataIteratorBySellMBLData::UpdateCurrent(CWriteableMBLMarketData * pBySellMBLData,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CMBLMarketData *)(m_pCurrent->pObject),pBySellMBLData,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySellMBLDataForMBLMarketData;
#endif

CMBLMarketData *CMBLMarketDataIteratorBySellMBLData::next(void)
{
#ifdef COUNT_SEARCH
	multiFindBySellMBLDataForMBLMarketData++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CMBLMarketData *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CMBLMarketData *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CMBLMarketDataIteratorBySellMBLData::match(CMBLMarketData *pMBLMarketData)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pMBLMarketData->InstrumentID.getValue(),m_compareObject.InstrumentID.getValue())!=0)
	{
		return 0;
	}
	if (compare(pMBLMarketData->Direction.getValue(),D_Sell)!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CMBLMarketDataIteratorStartByBuyMBLData> CMBLMarketDataIteratorStartByBuyMBLData::iteratorList;
void CMBLMarketDataIteratorStartByBuyMBLData::init(CMBLMarketDataFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CMBLMarketDataIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID=InstrumentID.getValue();
	m_compareObject.Direction=D_Buy;
	m_compareObject.Price=999999999;

}

CMBLMarketDataIteratorStartByBuyMBLData *CMBLMarketDataIteratorStartByBuyMBLData::alloc(CMBLMarketDataFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	CMBLMarketDataIteratorStartByBuyMBLData *it;
	it=iteratorList.alloc();
	it->init(pFactory,InstrumentID);
	return it;
}

CMBLMarketDataIteratorStartByBuyMBLData::~CMBLMarketDataIteratorStartByBuyMBLData(void)
{
}

void CMBLMarketDataIteratorStartByBuyMBLData::free(void)
{
	iteratorList.free(this);
}

void CMBLMarketDataIteratorStartByBuyMBLData::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CMBLMarketDataIteratorStartByBuyMBLData");
	
	char buffer[200];
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void CMBLMarketDataIteratorStartByBuyMBLData::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pQBuyMBLIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pQBuyMBLIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CMBLMarketDataIteratorStartByBuyMBLData::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CMBLMarketData *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CMBLMarketDataIteratorStartByBuyMBLData::UpdateCurrent(CWriteableMBLMarketData * pStartByBuyMBLData,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CMBLMarketData *)(m_pCurrent->pObject),pStartByBuyMBLData,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByBuyMBLDataForMBLMarketData;
#endif

CMBLMarketData *CMBLMarketDataIteratorStartByBuyMBLData::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByBuyMBLDataForMBLMarketData++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CMBLMarketData *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CMBLMarketData *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CMBLMarketDataIteratorStartByBuyMBLData::match(CMBLMarketData *pMBLMarketData)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pMBLMarketData->Direction.getValue(),D_Buy)!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CMBLMarketDataIteratorStartBySellMBLData> CMBLMarketDataIteratorStartBySellMBLData::iteratorList;
void CMBLMarketDataIteratorStartBySellMBLData::init(CMBLMarketDataFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CMBLMarketDataIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID=InstrumentID.getValue();
	m_compareObject.Direction=D_Sell;
	m_compareObject.Price=-999999999;

}

CMBLMarketDataIteratorStartBySellMBLData *CMBLMarketDataIteratorStartBySellMBLData::alloc(CMBLMarketDataFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	CMBLMarketDataIteratorStartBySellMBLData *it;
	it=iteratorList.alloc();
	it->init(pFactory,InstrumentID);
	return it;
}

CMBLMarketDataIteratorStartBySellMBLData::~CMBLMarketDataIteratorStartBySellMBLData(void)
{
}

void CMBLMarketDataIteratorStartBySellMBLData::free(void)
{
	iteratorList.free(this);
}

void CMBLMarketDataIteratorStartBySellMBLData::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CMBLMarketDataIteratorStartBySellMBLData");
	
	char buffer[200];
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void CMBLMarketDataIteratorStartBySellMBLData::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pQSellMBLIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pQSellMBLIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CMBLMarketDataIteratorStartBySellMBLData::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CMBLMarketData *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CMBLMarketDataIteratorStartBySellMBLData::UpdateCurrent(CWriteableMBLMarketData * pStartBySellMBLData,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CMBLMarketData *)(m_pCurrent->pObject),pStartBySellMBLData,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartBySellMBLDataForMBLMarketData;
#endif

CMBLMarketData *CMBLMarketDataIteratorStartBySellMBLData::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartBySellMBLDataForMBLMarketData++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CMBLMarketData *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CMBLMarketData *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CMBLMarketDataIteratorStartBySellMBLData::match(CMBLMarketData *pMBLMarketData)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pMBLMarketData->Direction.getValue(),D_Sell)!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CTradeIteratorAll> CTradeIteratorAll::iteratorList;
void CTradeIteratorAll::init(CTradeFactory *pFactory
		)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CTradeIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.TradeID="";
	m_compareObject.ParticipantID="";
	m_compareObject.ClientID="";
	m_compareObject.InstrumentID="";

}

CTradeIteratorAll *CTradeIteratorAll::alloc(CTradeFactory *pFactory
		)
{
	CTradeIteratorAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CTradeIteratorAll::~CTradeIteratorAll(void)
{
}

void CTradeIteratorAll::free(void)
{
	iteratorList.free(this);
}

void CTradeIteratorAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CTradeIteratorAll");
	
	
}

void CTradeIteratorAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pTradeIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pTradeIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CTradeIteratorAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CTrade *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CTradeIteratorAll::UpdateCurrent(CWriteableTrade * pAll,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CTrade *)(m_pCurrent->pObject),pAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindAllForTrade;
#endif

CTrade *CTradeIteratorAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindAllForTrade++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CTrade *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CTrade *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CTradeIteratorAll::match(CTrade *pTrade)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CTradeIteratorByTradeID> CTradeIteratorByTradeID::iteratorList;
void CTradeIteratorByTradeID::init(CTradeFactory *pFactory
		, const CReadOnlyTradeIDType& TradeID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CTradeIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.TradeID=TradeID.getValue();
	m_compareObject.ParticipantID="";
	m_compareObject.ClientID="";
	m_compareObject.InstrumentID="";

}

CTradeIteratorByTradeID *CTradeIteratorByTradeID::alloc(CTradeFactory *pFactory
		, const CReadOnlyTradeIDType& TradeID)
{
	CTradeIteratorByTradeID *it;
	it=iteratorList.alloc();
	it->init(pFactory,TradeID);
	return it;
}

CTradeIteratorByTradeID::~CTradeIteratorByTradeID(void)
{
}

void CTradeIteratorByTradeID::free(void)
{
	iteratorList.free(this);
}

void CTradeIteratorByTradeID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CTradeIteratorByTradeID");
	
	char buffer[200];
	
	m_compareObject.TradeID.getString(buffer);
	pLogger->output(indent+1,0,"query TradeID=%s",buffer);
	
}

void CTradeIteratorByTradeID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pTradeIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pTradeIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CTradeIteratorByTradeID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CTrade *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CTradeIteratorByTradeID::UpdateCurrent(CWriteableTrade * pByTradeID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CTrade *)(m_pCurrent->pObject),pByTradeID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByTradeIDForTrade;
#endif

CTrade *CTradeIteratorByTradeID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByTradeIDForTrade++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CTrade *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CTrade *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CTradeIteratorByTradeID::match(CTrade *pTrade)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pTrade->TradeID.getValue(),m_compareObject.TradeID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CTradeIteratorStartByPartID> CTradeIteratorStartByPartID::iteratorList;
void CTradeIteratorStartByPartID::init(CTradeFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CTradeIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID=ParticipantID.getValue();
	m_compareObject.TradeID="";
	m_compareObject.ClientID="";
	m_compareObject.InstrumentID="";

}

CTradeIteratorStartByPartID *CTradeIteratorStartByPartID::alloc(CTradeFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	CTradeIteratorStartByPartID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ParticipantID);
	return it;
}

CTradeIteratorStartByPartID::~CTradeIteratorStartByPartID(void)
{
}

void CTradeIteratorStartByPartID::free(void)
{
	iteratorList.free(this);
}

void CTradeIteratorStartByPartID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CTradeIteratorStartByPartID");
	
	char buffer[200];
	
	m_compareObject.ParticipantID.getString(buffer);
	pLogger->output(indent+1,0,"query ParticipantID=%s",buffer);
	
}

void CTradeIteratorStartByPartID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pPartIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pPartIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CTradeIteratorStartByPartID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CTrade *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CTradeIteratorStartByPartID::UpdateCurrent(CWriteableTrade * pStartByPartID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CTrade *)(m_pCurrent->pObject),pStartByPartID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByPartIDForTrade;
#endif

CTrade *CTradeIteratorStartByPartID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByPartIDForTrade++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CTrade *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CTrade *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CTradeIteratorStartByPartID::match(CTrade *pTrade)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CTradeIteratorByClientID> CTradeIteratorByClientID::iteratorList;
void CTradeIteratorByClientID::init(CTradeFactory *pFactory
		, const CReadOnlyClientIDType& ClientID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CTradeIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ClientID=ClientID.getValue();
	m_compareObject.TradeID="";

}

CTradeIteratorByClientID *CTradeIteratorByClientID::alloc(CTradeFactory *pFactory
		, const CReadOnlyClientIDType& ClientID)
{
	CTradeIteratorByClientID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ClientID);
	return it;
}

CTradeIteratorByClientID::~CTradeIteratorByClientID(void)
{
}

void CTradeIteratorByClientID::free(void)
{
	iteratorList.free(this);
}

void CTradeIteratorByClientID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CTradeIteratorByClientID");
	
	char buffer[200];
	
	m_compareObject.ClientID.getString(buffer);
	pLogger->output(indent+1,0,"query ClientID=%s",buffer);
	
}

void CTradeIteratorByClientID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pClientIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pClientIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CTradeIteratorByClientID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CTrade *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CTradeIteratorByClientID::UpdateCurrent(CWriteableTrade * pByClientID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CTrade *)(m_pCurrent->pObject),pByClientID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByClientIDForTrade;
#endif

CTrade *CTradeIteratorByClientID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByClientIDForTrade++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CTrade *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CTrade *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CTradeIteratorByClientID::match(CTrade *pTrade)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pTrade->ClientID.getValue(),m_compareObject.ClientID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CTradeIteratorStartByInstrumentID> CTradeIteratorStartByInstrumentID::iteratorList;
void CTradeIteratorStartByInstrumentID::init(CTradeFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CTradeIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.InstrumentID=InstrumentID.getValue();
	m_compareObject.TradeID="";

}

CTradeIteratorStartByInstrumentID *CTradeIteratorStartByInstrumentID::alloc(CTradeFactory *pFactory
		, const CReadOnlyInstrumentIDType& InstrumentID)
{
	CTradeIteratorStartByInstrumentID *it;
	it=iteratorList.alloc();
	it->init(pFactory,InstrumentID);
	return it;
}

CTradeIteratorStartByInstrumentID::~CTradeIteratorStartByInstrumentID(void)
{
}

void CTradeIteratorStartByInstrumentID::free(void)
{
	iteratorList.free(this);
}

void CTradeIteratorStartByInstrumentID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CTradeIteratorStartByInstrumentID");
	
	char buffer[200];
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void CTradeIteratorStartByInstrumentID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pInstrumentIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pInstrumentIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CTradeIteratorStartByInstrumentID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CTrade *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CTradeIteratorStartByInstrumentID::UpdateCurrent(CWriteableTrade * pStartByInstrumentID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CTrade *)(m_pCurrent->pObject),pStartByInstrumentID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindStartByInstrumentIDForTrade;
#endif

CTrade *CTradeIteratorStartByInstrumentID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindStartByInstrumentIDForTrade++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CTrade *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CTrade *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CTradeIteratorStartByInstrumentID::match(CTrade *pTrade)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}

CMemoryStack<CTradeIteratorBySettlementGroupID> CTradeIteratorBySettlementGroupID::iteratorList;
void CTradeIteratorBySettlementGroupID::init(CTradeFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CTradeIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CTradeIteratorBySettlementGroupID *CTradeIteratorBySettlementGroupID::alloc(CTradeFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CTradeIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CTradeIteratorBySettlementGroupID::~CTradeIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CTradeIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CTradeIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CTradeIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CTradeIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CTrade *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CTrade *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CTradeIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CTradeIteratorBySettlementGroupID::UpdateCurrent(CWriteableTrade * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForTrade;
#endif

CTrade *CTradeIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CTradeIteratorBySettlementGroupID::match(CTrade *pTrade)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pTrade->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CFusePhaseIteratorBySettlementGroupID> CFusePhaseIteratorBySettlementGroupID::iteratorList;
void CFusePhaseIteratorBySettlementGroupID::init(CFusePhaseFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CFusePhaseIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CFusePhaseIteratorBySettlementGroupID *CFusePhaseIteratorBySettlementGroupID::alloc(CFusePhaseFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CFusePhaseIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CFusePhaseIteratorBySettlementGroupID::~CFusePhaseIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CFusePhaseIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CFusePhaseIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CFusePhaseIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CFusePhaseIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CFusePhase *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CFusePhase *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CFusePhaseIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CFusePhaseIteratorBySettlementGroupID::UpdateCurrent(CWriteableFusePhase * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForFusePhase;
#endif

CFusePhase *CFusePhaseIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CFusePhaseIteratorBySettlementGroupID::match(CFusePhase *pFusePhase)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pFusePhase->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CExecOrderIteratorBySettlementGroupID> CExecOrderIteratorBySettlementGroupID::iteratorList;
void CExecOrderIteratorBySettlementGroupID::init(CExecOrderFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CExecOrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CExecOrderIteratorBySettlementGroupID *CExecOrderIteratorBySettlementGroupID::alloc(CExecOrderFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CExecOrderIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CExecOrderIteratorBySettlementGroupID::~CExecOrderIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CExecOrderIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CExecOrderIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CExecOrderIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CExecOrderIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CExecOrder *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CExecOrder *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CExecOrderIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CExecOrderIteratorBySettlementGroupID::UpdateCurrent(CWriteableExecOrder * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForExecOrder;
#endif

CExecOrder *CExecOrderIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CExecOrderIteratorBySettlementGroupID::match(CExecOrder *pExecOrder)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pExecOrder->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CExecOrderIteratorByParticipantID> CExecOrderIteratorByParticipantID::iteratorList;
void CExecOrderIteratorByParticipantID::init(CExecOrderFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CExecOrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID=ParticipantID.getValue();

}

CExecOrderIteratorByParticipantID *CExecOrderIteratorByParticipantID::alloc(CExecOrderFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	CExecOrderIteratorByParticipantID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ParticipantID);
	return it;
}

CExecOrderIteratorByParticipantID::~CExecOrderIteratorByParticipantID(void)
{
}

void CExecOrderIteratorByParticipantID::free(void)
{
	iteratorList.free(this);
}

void CExecOrderIteratorByParticipantID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CExecOrderIteratorByParticipantID");
	
	char buffer[200];
	
	m_compareObject.ParticipantID.getString(buffer);
	pLogger->output(indent+1,0,"query ParticipantID=%s",buffer);
	
}

void CExecOrderIteratorByParticipantID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pParticipantIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pParticipantIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CExecOrderIteratorByParticipantID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CExecOrder *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CExecOrderIteratorByParticipantID::UpdateCurrent(CWriteableExecOrder * pByParticipantID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CExecOrder *)(m_pCurrent->pObject),pByParticipantID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByParticipantIDForExecOrder;
#endif

CExecOrder *CExecOrderIteratorByParticipantID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByParticipantIDForExecOrder++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CExecOrder *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CExecOrder *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CExecOrderIteratorByParticipantID::match(CExecOrder *pExecOrder)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pExecOrder->ParticipantID.getValue(),m_compareObject.ParticipantID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CExecOrderIteratorByClientID> CExecOrderIteratorByClientID::iteratorList;
void CExecOrderIteratorByClientID::init(CExecOrderFactory *pFactory
		, const CReadOnlyClientIDType& ClientID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CExecOrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ClientID=ClientID.getValue();
	m_compareObject.InstrumentID="";

}

CExecOrderIteratorByClientID *CExecOrderIteratorByClientID::alloc(CExecOrderFactory *pFactory
		, const CReadOnlyClientIDType& ClientID)
{
	CExecOrderIteratorByClientID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ClientID);
	return it;
}

CExecOrderIteratorByClientID::~CExecOrderIteratorByClientID(void)
{
}

void CExecOrderIteratorByClientID::free(void)
{
	iteratorList.free(this);
}

void CExecOrderIteratorByClientID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CExecOrderIteratorByClientID");
	
	char buffer[200];
	
	m_compareObject.ClientID.getString(buffer);
	pLogger->output(indent+1,0,"query ClientID=%s",buffer);
	
}

void CExecOrderIteratorByClientID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pClientAndInstrumentIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pClientAndInstrumentIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CExecOrderIteratorByClientID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CExecOrder *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CExecOrderIteratorByClientID::UpdateCurrent(CWriteableExecOrder * pByClientID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CExecOrder *)(m_pCurrent->pObject),pByClientID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByClientIDForExecOrder;
#endif

CExecOrder *CExecOrderIteratorByClientID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByClientIDForExecOrder++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CExecOrder *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CExecOrder *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CExecOrderIteratorByClientID::match(CExecOrder *pExecOrder)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pExecOrder->ClientID.getValue(),m_compareObject.ClientID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CExecOrderIteratorByClientIDAndInstrumentID> CExecOrderIteratorByClientIDAndInstrumentID::iteratorList;
void CExecOrderIteratorByClientIDAndInstrumentID::init(CExecOrderFactory *pFactory
		, const CReadOnlyClientIDType& ClientID, const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CExecOrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ClientID=ClientID.getValue();
	m_compareObject.InstrumentID=InstrumentID.getValue();

}

CExecOrderIteratorByClientIDAndInstrumentID *CExecOrderIteratorByClientIDAndInstrumentID::alloc(CExecOrderFactory *pFactory
		, const CReadOnlyClientIDType& ClientID, const CReadOnlyInstrumentIDType& InstrumentID)
{
	CExecOrderIteratorByClientIDAndInstrumentID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ClientID,InstrumentID);
	return it;
}

CExecOrderIteratorByClientIDAndInstrumentID::~CExecOrderIteratorByClientIDAndInstrumentID(void)
{
}

void CExecOrderIteratorByClientIDAndInstrumentID::free(void)
{
	iteratorList.free(this);
}

void CExecOrderIteratorByClientIDAndInstrumentID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CExecOrderIteratorByClientIDAndInstrumentID");
	
	char buffer[200];
	
	m_compareObject.ClientID.getString(buffer);
	pLogger->output(indent+1,0,"query ClientID=%s",buffer);
	
	m_compareObject.InstrumentID.getString(buffer);
	pLogger->output(indent+1,0,"query InstrumentID=%s",buffer);
	
}

void CExecOrderIteratorByClientIDAndInstrumentID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pClientAndInstrumentIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pClientAndInstrumentIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CExecOrderIteratorByClientIDAndInstrumentID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CExecOrder *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CExecOrderIteratorByClientIDAndInstrumentID::UpdateCurrent(CWriteableExecOrder * pByClientIDAndInstrumentID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CExecOrder *)(m_pCurrent->pObject),pByClientIDAndInstrumentID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByClientIDAndInstrumentIDForExecOrder;
#endif

CExecOrder *CExecOrderIteratorByClientIDAndInstrumentID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByClientIDAndInstrumentIDForExecOrder++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CExecOrder *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CExecOrder *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CExecOrderIteratorByClientIDAndInstrumentID::match(CExecOrder *pExecOrder)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pExecOrder->ClientID.getValue(),m_compareObject.ClientID.getValue())!=0)
	{
		return 0;
	}
	if (compare(pExecOrder->InstrumentID.getValue(),m_compareObject.InstrumentID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CExecOrderIteratorByUserID> CExecOrderIteratorByUserID::iteratorList;
void CExecOrderIteratorByUserID::init(CExecOrderFactory *pFactory
		, const CReadOnlyUserIDType& UserID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CExecOrderIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.UserID=UserID.getValue();
	m_compareObject.ExecOrderLocalID="zzzzzzzzzzzz";

}

CExecOrderIteratorByUserID *CExecOrderIteratorByUserID::alloc(CExecOrderFactory *pFactory
		, const CReadOnlyUserIDType& UserID)
{
	CExecOrderIteratorByUserID *it;
	it=iteratorList.alloc();
	it->init(pFactory,UserID);
	return it;
}

CExecOrderIteratorByUserID::~CExecOrderIteratorByUserID(void)
{
}

void CExecOrderIteratorByUserID::free(void)
{
	iteratorList.free(this);
}

void CExecOrderIteratorByUserID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CExecOrderIteratorByUserID");
	
	char buffer[200];
	
	m_compareObject.UserID.getString(buffer);
	pLogger->output(indent+1,0,"query UserID=%s",buffer);
	
}

void CExecOrderIteratorByUserID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///第一次进入，在索引中寻找第一个满足条件的
		m_pNext=m_Factory->pExecOrderLocalIDIndex->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->pExecOrderLocalIDIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CExecOrderIteratorByUserID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove((CExecOrder *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CExecOrderIteratorByUserID::UpdateCurrent(CWriteableExecOrder * pByUserID,CTransaction* pTransaction, bool updateIndex)
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
	m_Factory->update((CExecOrder *)(m_pCurrent->pObject),pByUserID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByUserIDForExecOrder;
#endif

CExecOrder *CExecOrderIteratorByUserID::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByUserIDForExecOrder++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///如果没有下一个对象了，则失败返回
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CExecOrder *)(m_pCurrent->pObject)))
	{
		///符合条件，那就返回它
		return (CExecOrder *)(m_pCurrent->pObject);
	}
	
	///不符合条件，那就不用做了
	m_pCurrent=NULL;
	return NULL;
}

int CExecOrderIteratorByUserID::match(CExecOrder *pExecOrder)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pExecOrder->UserID.getValue(),m_compareObject.UserID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CUniPressureIteratorBySettlementGroupID> CUniPressureIteratorBySettlementGroupID::iteratorList;
void CUniPressureIteratorBySettlementGroupID::init(CUniPressureFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CUniPressureIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CUniPressureIteratorBySettlementGroupID *CUniPressureIteratorBySettlementGroupID::alloc(CUniPressureFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CUniPressureIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CUniPressureIteratorBySettlementGroupID::~CUniPressureIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CUniPressureIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CUniPressureIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CUniPressureIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CUniPressureIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CUniPressure *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CUniPressure *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CUniPressureIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CUniPressureIteratorBySettlementGroupID::UpdateCurrent(CWriteableUniPressure * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForUniPressure;
#endif

CUniPressure *CUniPressureIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CUniPressureIteratorBySettlementGroupID::match(CUniPressure *pUniPressure)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pUniPressure->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CBasePriceLimitIteratorBySettlementGroupID> CBasePriceLimitIteratorBySettlementGroupID::iteratorList;
void CBasePriceLimitIteratorBySettlementGroupID::init(CBasePriceLimitFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CBasePriceLimitIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CBasePriceLimitIteratorBySettlementGroupID *CBasePriceLimitIteratorBySettlementGroupID::alloc(CBasePriceLimitFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CBasePriceLimitIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CBasePriceLimitIteratorBySettlementGroupID::~CBasePriceLimitIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CBasePriceLimitIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CBasePriceLimitIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CBasePriceLimitIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CBasePriceLimitIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CBasePriceLimit *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CBasePriceLimit *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CBasePriceLimitIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CBasePriceLimitIteratorBySettlementGroupID::UpdateCurrent(CWriteableBasePriceLimit * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForBasePriceLimit;
#endif

CBasePriceLimit *CBasePriceLimitIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CBasePriceLimitIteratorBySettlementGroupID::match(CBasePriceLimit *pBasePriceLimit)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pBasePriceLimit->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


CMemoryStack<CCreditLimitIteratorBySettlementGroupID> CCreditLimitIteratorBySettlementGroupID::iteratorList;
void CCreditLimitIteratorBySettlementGroupID::init(CCreditLimitFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCreditLimitIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCreditLimitIteratorBySettlementGroupID *CCreditLimitIteratorBySettlementGroupID::alloc(CCreditLimitFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCreditLimitIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCreditLimitIteratorBySettlementGroupID::~CCreditLimitIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCreditLimitIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCreditLimitIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCreditLimitIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCreditLimitIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCreditLimit *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCreditLimit *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCreditLimitIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCreditLimitIteratorBySettlementGroupID::UpdateCurrent(CWriteableCreditLimit * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCreditLimit;
#endif

CCreditLimit *CCreditLimitIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCreditLimitIteratorBySettlementGroupID::match(CCreditLimit *pCreditLimit)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCreditLimit->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CCreditLimitIteratorAllByParticipantID> CCreditLimitIteratorAllByParticipantID::iteratorList;
void CCreditLimitIteratorAllByParticipantID::init(CCreditLimitFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CCreditLimitIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ParticipantID=ParticipantID.getValue();

}

CCreditLimitIteratorAllByParticipantID *CCreditLimitIteratorAllByParticipantID::alloc(CCreditLimitFactory *pFactory
		, const CReadOnlyParticipantIDType& ParticipantID)
{
	CCreditLimitIteratorAllByParticipantID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ParticipantID);
	return it;
}

CCreditLimitIteratorAllByParticipantID::~CCreditLimitIteratorAllByParticipantID(void)
{
	m_Factory->endGet();
}

void CCreditLimitIteratorAllByParticipantID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCreditLimitIteratorAllByParticipantID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCreditLimitIteratorAllByParticipantID");
	
	char buffer[200];
	
	m_compareObject.ParticipantID.getString(buffer);
	pLogger->output(indent+1,0,"query ParticipantID=%s",buffer);
	
}

void CCreditLimitIteratorAllByParticipantID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCreditLimit *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCreditLimit *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCreditLimitIteratorAllByParticipantID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCreditLimitIteratorAllByParticipantID::UpdateCurrent(CWriteableCreditLimit * pAllByParticipantID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pAllByParticipantID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindAllByParticipantIDForCreditLimit;
#endif

CCreditLimit *CCreditLimitIteratorAllByParticipantID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCreditLimitIteratorAllByParticipantID::match(CCreditLimit *pCreditLimit)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCreditLimit->ParticipantID.getValue(),m_compareObject.ParticipantID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CCreditLimitIteratorAllByClearingPartID> CCreditLimitIteratorAllByClearingPartID::iteratorList;
void CCreditLimitIteratorAllByClearingPartID::init(CCreditLimitFactory *pFactory
		, const CReadOnlyParticipantIDType& ClearingPartID)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CCreditLimitIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.ClearingPartID=ClearingPartID.getValue();

}

CCreditLimitIteratorAllByClearingPartID *CCreditLimitIteratorAllByClearingPartID::alloc(CCreditLimitFactory *pFactory
		, const CReadOnlyParticipantIDType& ClearingPartID)
{
	CCreditLimitIteratorAllByClearingPartID *it;
	it=iteratorList.alloc();
	it->init(pFactory,ClearingPartID);
	return it;
}

CCreditLimitIteratorAllByClearingPartID::~CCreditLimitIteratorAllByClearingPartID(void)
{
	m_Factory->endGet();
}

void CCreditLimitIteratorAllByClearingPartID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCreditLimitIteratorAllByClearingPartID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCreditLimitIteratorAllByClearingPartID");
	
	char buffer[200];
	
	m_compareObject.ClearingPartID.getString(buffer);
	pLogger->output(indent+1,0,"query ClearingPartID=%s",buffer);
	
}

void CCreditLimitIteratorAllByClearingPartID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCreditLimit *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCreditLimit *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCreditLimitIteratorAllByClearingPartID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCreditLimitIteratorAllByClearingPartID::UpdateCurrent(CWriteableCreditLimit * pAllByClearingPartID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pAllByClearingPartID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindAllByClearingPartIDForCreditLimit;
#endif

CCreditLimit *CCreditLimitIteratorAllByClearingPartID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCreditLimitIteratorAllByClearingPartID::match(CCreditLimit *pCreditLimit)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCreditLimit->ClearingPartID.getValue(),m_compareObject.ClearingPartID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CCreditLimitIteratorAll> CCreditLimitIteratorAll::iteratorList;
void CCreditLimitIteratorAll::init(CCreditLimitFactory *pFactory
		)
{
	if (runLevel<1)
	{
		RAISE_RUNTIME_ERROR("Can not use CCreditLimitIterator while run level < 1");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();

}

CCreditLimitIteratorAll *CCreditLimitIteratorAll::alloc(CCreditLimitFactory *pFactory
		)
{
	CCreditLimitIteratorAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CCreditLimitIteratorAll::~CCreditLimitIteratorAll(void)
{
	m_Factory->endGet();
}

void CCreditLimitIteratorAll::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCreditLimitIteratorAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCreditLimitIteratorAll");
	
	
}

void CCreditLimitIteratorAll::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCreditLimit *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCreditLimit *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCreditLimitIteratorAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCreditLimitIteratorAll::UpdateCurrent(CWriteableCreditLimit * pAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindAllForCreditLimit;
#endif

CCreditLimit *CCreditLimitIteratorAll::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCreditLimitIteratorAll::match(CCreditLimit *pCreditLimit)
{
	///如果有一个条件不满足，则失败返回
	return 1;
}


CMemoryStack<CCurrInstrumentOptionIteratorBySettlementGroupID> CCurrInstrumentOptionIteratorBySettlementGroupID::iteratorList;
void CCurrInstrumentOptionIteratorBySettlementGroupID::init(CCurrInstrumentOptionFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CCurrInstrumentOptionIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///根据参数和缺省值，设置用于比较的对象的各个分量
	m_compareObject.init();
	m_compareObject.SettlementGroupID=SettlementGroupID.getValue();

}

CCurrInstrumentOptionIteratorBySettlementGroupID *CCurrInstrumentOptionIteratorBySettlementGroupID::alloc(CCurrInstrumentOptionFactory *pFactory
		, const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	CCurrInstrumentOptionIteratorBySettlementGroupID *it;
	it=iteratorList.alloc();
	it->init(pFactory,SettlementGroupID);
	return it;
}

CCurrInstrumentOptionIteratorBySettlementGroupID::~CCurrInstrumentOptionIteratorBySettlementGroupID(void)
{
	m_Factory->endGet();
}

void CCurrInstrumentOptionIteratorBySettlementGroupID::free(void)
{
	m_Factory->endGet();
	iteratorList.free(this);
}

void CCurrInstrumentOptionIteratorBySettlementGroupID::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CCurrInstrumentOptionIteratorBySettlementGroupID");
	
	char buffer[200];
	
	m_compareObject.SettlementGroupID.getString(buffer);
	pLogger->output(indent+1,0,"query SettlementGroupID=%s",buffer);
	
}

void CCurrInstrumentOptionIteratorBySettlementGroupID::internalGetNext()
{
	if (m_gotNext)
	{
		///已经取过下一个了
		return;
	}
	if (m_isFirstTime)
	{
		///找到第一个对象
		m_pNext=(CCurrInstrumentOption *)(m_Factory->getFirst());
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
			///找到下一个对象
			m_pNext=(CCurrInstrumentOption *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
}


void CCurrInstrumentOptionIteratorBySettlementGroupID::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法删除
		return;
	}
	internalGetNext();
	m_Factory->remove(m_pCurrent,pTransaction);
	m_pCurrent=NULL;
}
	

void CCurrInstrumentOptionIteratorBySettlementGroupID::UpdateCurrent(CWriteableCurrInstrumentOption * pBySettlementGroupID,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///当前节点不存在，所以也无法修改
		return;
	}
	///本枚举器不需要更新索引，所以直接修改无妨
	m_Factory->update(m_pCurrent,pBySettlementGroupID,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindBySettlementGroupIDForCurrInstrumentOption;
#endif

CCurrInstrumentOption *CCurrInstrumentOptionIteratorBySettlementGroupID::next(void)
{
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///如果没有下一个对象了，则失败返回
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///符合条件，那就返回它
			return m_pCurrent;
		}
		///不符合，那就再看下一个		
	}
}

int CCurrInstrumentOptionIteratorBySettlementGroupID::match(CCurrInstrumentOption *pCurrInstrumentOption)
{
	///如果有一个条件不满足，则失败返回
	if (compare(pCurrInstrumentOption->SettlementGroupID.getValue(),m_compareObject.SettlementGroupID.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


