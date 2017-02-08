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
int compareForExchangeIDIndexinExchangeDataSyncStatus(const void *pV1, const void *pV2)
{
	CExchangeDataSyncStatus *p1,*p2;
	p1=(CExchangeDataSyncStatus *)pV1;
	p2=(CExchangeDataSyncStatus *)pV2;
	switch (compare(p1->ExchangeID.getValue(),p2->ExchangeID.getValue()))
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
int findByExchangeIDForExchangeDataSyncStatus=0;
#endif
CExchangeDataSyncStatus *CExchangeDataSyncStatusFactory::findByExchangeID( const CReadOnlyExchangeIDType&  ExchangeID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByExchangeID of CExchangeDataSyncStatus while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByExchangeIDForExchangeDataSyncStatus++;
#endif
	CAVLNode *pNode;
	compareObject.ExchangeID=ExchangeID.getValue();
	pNode=pExchangeIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CExchangeDataSyncStatus *)(pNode->pObject);
}


int compareForSettlementGroupIDIndexinSGDataSyncStatus(const void *pV1, const void *pV2)
{
	CSGDataSyncStatus *p1,*p2;
	p1=(CSGDataSyncStatus *)pV1;
	p2=(CSGDataSyncStatus *)pV2;
	switch (compare(p1->SettlementGroupID.getValue(),p2->SettlementGroupID.getValue()))
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
int findBySettlementGroupIDForSGDataSyncStatus=0;
#endif
CSGDataSyncStatus *CSGDataSyncStatusFactory::findBySettlementGroupID( const CReadOnlySettlementGroupIDType&  SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findBySettlementGroupID of CSGDataSyncStatus while run level < 0");
	}
#ifdef COUNT_SEARCH
	findBySettlementGroupIDForSGDataSyncStatus++;
#endif
	CAVLNode *pNode;
	compareObject.SettlementGroupID=SettlementGroupID.getValue();
	pNode=pSettlementGroupIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSGDataSyncStatus *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindStartBySettlementGroupIDForSGDataSyncStatus=0;
#endif

CSGDataSyncStatus *CSGDataSyncStatusFactory::startFindStartBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartBySettlementGroupID of CSGDataSyncStatus while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchStartBySettlementGroupID= SettlementGroupID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartBySettlementGroupIDForSGDataSyncStatus++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CSGDataSyncStatus *theSGDataSyncStatus;
	compareObject.SettlementGroupID=SettlementGroupID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartBySettlementGroupID=pSettlementGroupIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theSGDataSyncStatus=(CSGDataSyncStatus *)(pLastFoundInSearchStartBySettlementGroupID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSGDataSyncStatus;
}

CSGDataSyncStatus *CSGDataSyncStatusFactory::findNextStartBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartBySettlementGroupID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartBySettlementGroupIDForSGDataSyncStatus++;
#endif
	CSGDataSyncStatus *theSGDataSyncStatus;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartBySettlementGroupID=pSettlementGroupIDIndex->getNextNode(pLastFoundInSearchStartBySettlementGroupID);
	if (pLastFoundInSearchStartBySettlementGroupID==NULL)
	{
		return NULL;
	}

	theSGDataSyncStatus=(CSGDataSyncStatus *)(pLastFoundInSearchStartBySettlementGroupID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theSGDataSyncStatus;
}

void CSGDataSyncStatusFactory::endFindStartBySettlementGroupID(void)
{
	pLastFoundInSearchStartBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByExchangeIDForExchange=0;
#endif
CExchange *CExchangeFactory::findByExchangeID( const CReadOnlyExchangeIDType&  ExchangeID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByExchangeID of CExchange while run level < 0");
	}
	CExchange *theExchange;
	for (theExchange=(CExchange *)(pMem->getFirst());
		theExchange!=NULL;
		theExchange=(CExchange *)(pMem->getNext()))
	{
		if (compare(theExchange->ExchangeID.getValue(),ExchangeID.getValue())!=0)
		{
			continue;
		}
		return theExchange;
	}
	return NULL;
}


int compareForSettlementGroupIDIndexinSettlementGroup(const void *pV1, const void *pV2)
{
	CSettlementGroup *p1,*p2;
	p1=(CSettlementGroup *)pV1;
	p2=(CSettlementGroup *)pV2;
	switch (compare(p1->SettlementGroupID.getValue(),p2->SettlementGroupID.getValue()))
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
int findBySettlementGroupIDForSettlementGroup=0;
#endif
CSettlementGroup *CSettlementGroupFactory::findBySettlementGroupID( const CReadOnlySettlementGroupIDType&  SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findBySettlementGroupID of CSettlementGroup while run level < 0");
	}
#ifdef COUNT_SEARCH
	findBySettlementGroupIDForSettlementGroup++;
#endif
	CAVLNode *pNode;
	compareObject.SettlementGroupID=SettlementGroupID.getValue();
	pNode=pSettlementGroupIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSettlementGroup *)(pNode->pObject);
}


int compareForMarketIDIndexinMarket(const void *pV1, const void *pV2)
{
	CMarket *p1,*p2;
	p1=(CMarket *)pV1;
	p2=(CMarket *)pV2;
	switch (compare(p1->MarketID.getValue(),p2->MarketID.getValue()))
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
int findByMarketIDForMarket=0;
#endif
CMarket *CMarketFactory::findByMarketID( const CReadOnlyMarketIDType&  MarketID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByMarketID of CMarket while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByMarketIDForMarket++;
#endif
	CAVLNode *pNode;
	compareObject.MarketID=MarketID.getValue();
	pNode=pMarketIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CMarket *)(pNode->pObject);
}


int compareForProductIDIndexinMarketProduct(const void *pV1, const void *pV2)
{
	CMarketProduct *p1,*p2;
	p1=(CMarketProduct *)pV1;
	p2=(CMarketProduct *)pV2;
	switch (compare(p1->ProductID.getValue(),p2->ProductID.getValue()))
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
int multiFindByProductIDForMarketProduct=0;
#endif

CMarketProduct *CMarketProductFactory::startFindByProductID( const CReadOnlyProductIDType& ProductID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByProductID of CMarketProduct while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByProductID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByProductID();
	}

	///记录所有的查询值
	queryProductIDInSearchByProductID= ProductID.getValue();

#ifdef COUNT_SEARCH
	multiFindByProductIDForMarketProduct++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CMarketProduct *theMarketProduct;
	compareObject.ProductID=ProductID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByProductID=pProductIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByProductID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theMarketProduct=(CMarketProduct *)(pLastFoundInSearchByProductID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theMarketProduct->ProductID.getValue(),ProductID.getValue()))
	{
		pLastFoundInSearchByProductID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theMarketProduct;
}

CMarketProduct *CMarketProductFactory::findNextByProductID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByProductID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByProductIDForMarketProduct++;
#endif
	CMarketProduct *theMarketProduct;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByProductID=pProductIDIndex->getNextNode(pLastFoundInSearchByProductID);
	if (pLastFoundInSearchByProductID==NULL)
	{
		return NULL;
	}

	theMarketProduct=(CMarketProduct *)(pLastFoundInSearchByProductID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theMarketProduct->ProductID,queryProductIDInSearchByProductID))
	{
		pLastFoundInSearchByProductID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theMarketProduct;
}

void CMarketProductFactory::endFindByProductID(void)
{
	pLastFoundInSearchByProductID=NULL;
}

int compareForProductGroupIDIndexinMarketProductGroup(const void *pV1, const void *pV2)
{
	CMarketProductGroup *p1,*p2;
	p1=(CMarketProductGroup *)pV1;
	p2=(CMarketProductGroup *)pV2;
	switch (compare(p1->ProductGroupID.getValue(),p2->ProductGroupID.getValue()))
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
int multiFindByProductGroupIDForMarketProductGroup=0;
#endif

CMarketProductGroup *CMarketProductGroupFactory::startFindByProductGroupID( const CReadOnlyProductGroupIDType& ProductGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByProductGroupID of CMarketProductGroup while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByProductGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByProductGroupID();
	}

	///记录所有的查询值
	queryProductGroupIDInSearchByProductGroupID= ProductGroupID.getValue();

#ifdef COUNT_SEARCH
	multiFindByProductGroupIDForMarketProductGroup++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CMarketProductGroup *theMarketProductGroup;
	compareObject.ProductGroupID=ProductGroupID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByProductGroupID=pProductGroupIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByProductGroupID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theMarketProductGroup=(CMarketProductGroup *)(pLastFoundInSearchByProductGroupID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theMarketProductGroup->ProductGroupID.getValue(),ProductGroupID.getValue()))
	{
		pLastFoundInSearchByProductGroupID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theMarketProductGroup;
}

CMarketProductGroup *CMarketProductGroupFactory::findNextByProductGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByProductGroupID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByProductGroupIDForMarketProductGroup++;
#endif
	CMarketProductGroup *theMarketProductGroup;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByProductGroupID=pProductGroupIDIndex->getNextNode(pLastFoundInSearchByProductGroupID);
	if (pLastFoundInSearchByProductGroupID==NULL)
	{
		return NULL;
	}

	theMarketProductGroup=(CMarketProductGroup *)(pLastFoundInSearchByProductGroupID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theMarketProductGroup->ProductGroupID,queryProductGroupIDInSearchByProductGroupID))
	{
		pLastFoundInSearchByProductGroupID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theMarketProductGroup;
}

void CMarketProductGroupFactory::endFindByProductGroupID(void)
{
	pLastFoundInSearchByProductGroupID=NULL;
}

int compareForProductIDInstrumentStatusIndexinMdPubStatus(const void *pV1, const void *pV2)
{
	CMdPubStatus *p1,*p2;
	p1=(CMdPubStatus *)pV1;
	p2=(CMdPubStatus *)pV2;
	switch (compare(p1->ProductID.getValue(),p2->ProductID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->InstrumentStatus.getValue(),p2->InstrumentStatus.getValue()))
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
int findByProductIDInstrumentStatusForMdPubStatus=0;
#endif
CMdPubStatus *CMdPubStatusFactory::findByProductIDInstrumentStatus( const CReadOnlyProductIDType&  ProductID,  const CReadOnlyInstrumentStatusType&  InstrumentStatus)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByProductIDInstrumentStatus of CMdPubStatus while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByProductIDInstrumentStatusForMdPubStatus++;
#endif
	CAVLNode *pNode;
	compareObject.ProductID=ProductID.getValue();
	compareObject.InstrumentStatus=InstrumentStatus.getValue();
	pNode=pProductIDInstrumentStatusIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CMdPubStatus *)(pNode->pObject);
}


int compareForTopicIDIndexinMarketDataTopic(const void *pV1, const void *pV2)
{
	CMarketDataTopic *p1,*p2;
	p1=(CMarketDataTopic *)pV1;
	p2=(CMarketDataTopic *)pV2;
	switch (compare(p1->TopicID.getValue(),p2->TopicID.getValue()))
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
int compareForMarketIDIndexinMarketDataTopic(const void *pV1, const void *pV2)
{
	CMarketDataTopic *p1,*p2;
	p1=(CMarketDataTopic *)pV1;
	p2=(CMarketDataTopic *)pV2;
	switch (compare(p1->MarketID.getValue(),p2->MarketID.getValue()))
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
int findByTopicIDForMarketDataTopic=0;
#endif
CMarketDataTopic *CMarketDataTopicFactory::findByTopicID( const CReadOnlyTopicIDType&  TopicID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByTopicID of CMarketDataTopic while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByTopicIDForMarketDataTopic++;
#endif
	CAVLNode *pNode;
	compareObject.TopicID=TopicID.getValue();
	pNode=pTopicIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CMarketDataTopic *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByMarketIDForMarketDataTopic=0;
#endif

CMarketDataTopic *CMarketDataTopicFactory::startFindByMarketID( const CReadOnlyMarketIDType& MarketID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByMarketID of CMarketDataTopic while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByMarketID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByMarketID();
	}

	///记录所有的查询值
	queryMarketIDInSearchByMarketID= MarketID.getValue();

#ifdef COUNT_SEARCH
	multiFindByMarketIDForMarketDataTopic++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CMarketDataTopic *theMarketDataTopic;
	compareObject.MarketID=MarketID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByMarketID=pMarketIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByMarketID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theMarketDataTopic=(CMarketDataTopic *)(pLastFoundInSearchByMarketID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theMarketDataTopic->MarketID.getValue(),MarketID.getValue()))
	{
		pLastFoundInSearchByMarketID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theMarketDataTopic;
}

CMarketDataTopic *CMarketDataTopicFactory::findNextByMarketID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByMarketID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByMarketIDForMarketDataTopic++;
#endif
	CMarketDataTopic *theMarketDataTopic;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByMarketID=pMarketIDIndex->getNextNode(pLastFoundInSearchByMarketID);
	if (pLastFoundInSearchByMarketID==NULL)
	{
		return NULL;
	}

	theMarketDataTopic=(CMarketDataTopic *)(pLastFoundInSearchByMarketID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theMarketDataTopic->MarketID,queryMarketIDInSearchByMarketID))
	{
		pLastFoundInSearchByMarketID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theMarketDataTopic;
}

void CMarketDataTopicFactory::endFindByMarketID(void)
{
	pLastFoundInSearchByMarketID=NULL;
}

int compareForPartIDTopicIDIndexinPartTopicSubscribe(const void *pV1, const void *pV2)
{
	CPartTopicSubscribe *p1,*p2;
	p1=(CPartTopicSubscribe *)pV1;
	p2=(CPartTopicSubscribe *)pV2;
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
	switch (compare(p1->TopicID.getValue(),p2->TopicID.getValue()))
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
int findByPartIDTopicIDForPartTopicSubscribe=0;
#endif
CPartTopicSubscribe *CPartTopicSubscribeFactory::findByPartIDTopicID( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTopicIDType&  TopicID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByPartIDTopicID of CPartTopicSubscribe while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByPartIDTopicIDForPartTopicSubscribe++;
#endif
	CAVLNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.TopicID=TopicID.getValue();
	pNode=pPartIDTopicIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CPartTopicSubscribe *)(pNode->pObject);
}

CPartTopicSubscribe *CPartTopicSubscribeFactory::findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTopicIDType&  TopicID)
{
	return findByPartIDTopicID(ParticipantID, TopicID);
}
	
CPartTopicSubscribe *CPartTopicSubscribeFactory::findByPK(CWriteablePartTopicSubscribe *pPartTopicSubscribe)
{
	return findByPK(
		pPartTopicSubscribe->ParticipantID
		,
		pPartTopicSubscribe->TopicID
		);
}

bool CPartTopicSubscribeFactory::retrieveByPK(CWriteablePartTopicSubscribe *pPartTopicSubscribe)
{
	CPartTopicSubscribe *pOriginalPartTopicSubscribe;
	pOriginalPartTopicSubscribe=findByPK(pPartTopicSubscribe);
	if (pOriginalPartTopicSubscribe==NULL)
	{
		return false;
	}
	retrieve(pOriginalPartTopicSubscribe,pPartTopicSubscribe);
	return true;
}

CPartTopicSubscribe *CPartTopicSubscribeFactory::addByPK(CWriteablePartTopicSubscribe *pPartTopicSubscribe, CTransaction *pTransaction)
{
	CPartTopicSubscribe *pOriginalPartTopicSubscribe;
	pOriginalPartTopicSubscribe=findByPK(pPartTopicSubscribe);
	if (pOriginalPartTopicSubscribe != NULL)
	{
		return NULL;
	}
	return add(pPartTopicSubscribe,pTransaction);
}

bool CPartTopicSubscribeFactory::updateByPK(CWriteablePartTopicSubscribe *pPartTopicSubscribe, CTransaction *pTransaction, bool updateIndex)
{
	CPartTopicSubscribe *pOriginalPartTopicSubscribe;
	pOriginalPartTopicSubscribe=findByPK(pPartTopicSubscribe);
	if (pOriginalPartTopicSubscribe==NULL)
	{
		return false;
	}
	pPartTopicSubscribe->calAllHash();
	update(pOriginalPartTopicSubscribe,pPartTopicSubscribe,pTransaction,updateIndex);
	return true;
}

bool CPartTopicSubscribeFactory::removeByPK(CWriteablePartTopicSubscribe *pPartTopicSubscribe, CTransaction *pTransaction)
{
	CPartTopicSubscribe *pOriginalPartTopicSubscribe;
	pOriginalPartTopicSubscribe=findByPK(pPartTopicSubscribe);
	if (pOriginalPartTopicSubscribe==NULL)
	{
		return false;
	}
	remove(pOriginalPartTopicSubscribe,pTransaction);
	return true;
}



#ifdef COUNT_SEARCH
int multiFindByPartIDForPartTopicSubscribe=0;
#endif

CPartTopicSubscribe *CPartTopicSubscribeFactory::startFindByPartID( const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByPartID of CPartTopicSubscribe while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByPartID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByPartID();
	}

	///记录所有的查询值
	queryParticipantIDInSearchByPartID= ParticipantID.getValue();

#ifdef COUNT_SEARCH
	multiFindByPartIDForPartTopicSubscribe++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CPartTopicSubscribe *thePartTopicSubscribe;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.TopicID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByPartID=pPartIDTopicIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByPartID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	thePartTopicSubscribe=(CPartTopicSubscribe *)(pLastFoundInSearchByPartID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(thePartTopicSubscribe->ParticipantID.getValue(),ParticipantID.getValue()))
	{
		pLastFoundInSearchByPartID=NULL;
		return NULL;
	}

	///返回找到的结果
	return thePartTopicSubscribe;
}

CPartTopicSubscribe *CPartTopicSubscribeFactory::findNextByPartID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByPartID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByPartIDForPartTopicSubscribe++;
#endif
	CPartTopicSubscribe *thePartTopicSubscribe;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByPartID=pPartIDTopicIDIndex->getNextNode(pLastFoundInSearchByPartID);
	if (pLastFoundInSearchByPartID==NULL)
	{
		return NULL;
	}

	thePartTopicSubscribe=(CPartTopicSubscribe *)(pLastFoundInSearchByPartID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(thePartTopicSubscribe->ParticipantID,queryParticipantIDInSearchByPartID))
	{
		pLastFoundInSearchByPartID=NULL;
		return NULL;
	}

	///返回找到的结果
	return thePartTopicSubscribe;
}

void CPartTopicSubscribeFactory::endFindByPartID(void)
{
	pLastFoundInSearchByPartID=NULL;
}

int compareForParticipantIDIndexinParticipant(const void *pV1, const void *pV2)
{
	CParticipant *p1,*p2;
	p1=(CParticipant *)pV1;
	p2=(CParticipant *)pV2;
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
int findByParticipantIDForParticipant=0;
#endif
CParticipant *CParticipantFactory::findByParticipantID( const CReadOnlyParticipantIDType&  ParticipantID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByParticipantID of CParticipant while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByParticipantIDForParticipant++;
#endif
	CAVLNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	pNode=pParticipantIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CParticipant *)(pNode->pObject);
}

CParticipant *CParticipantFactory::findByPK( const CReadOnlyParticipantIDType&  ParticipantID)
{
	return findByParticipantID(ParticipantID);
}
	
CParticipant *CParticipantFactory::findByPK(CWriteableParticipant *pParticipant)
{
	return findByPK(
		pParticipant->ParticipantID
		);
}

bool CParticipantFactory::retrieveByPK(CWriteableParticipant *pParticipant)
{
	CParticipant *pOriginalParticipant;
	pOriginalParticipant=findByPK(pParticipant);
	if (pOriginalParticipant==NULL)
	{
		return false;
	}
	retrieve(pOriginalParticipant,pParticipant);
	return true;
}

CParticipant *CParticipantFactory::addByPK(CWriteableParticipant *pParticipant, CTransaction *pTransaction)
{
	CParticipant *pOriginalParticipant;
	pOriginalParticipant=findByPK(pParticipant);
	if (pOriginalParticipant != NULL)
	{
		return NULL;
	}
	return add(pParticipant,pTransaction);
}

bool CParticipantFactory::updateByPK(CWriteableParticipant *pParticipant, CTransaction *pTransaction, bool updateIndex)
{
	CParticipant *pOriginalParticipant;
	pOriginalParticipant=findByPK(pParticipant);
	if (pOriginalParticipant==NULL)
	{
		return false;
	}
	pParticipant->calAllHash();
	update(pOriginalParticipant,pParticipant,pTransaction,updateIndex);
	return true;
}

bool CParticipantFactory::removeByPK(CWriteableParticipant *pParticipant, CTransaction *pTransaction)
{
	CParticipant *pOriginalParticipant;
	pOriginalParticipant=findByPK(pParticipant);
	if (pOriginalParticipant==NULL)
	{
		return false;
	}
	remove(pOriginalParticipant,pTransaction);
	return true;
}



#ifdef COUNT_SEARCH
int multiFindStartByParticipantIDForParticipant=0;
#endif

CParticipant *CParticipantFactory::startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByParticipantID of CParticipant while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByParticipantID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByParticipantID();
	}

	///记录所有的查询值
	queryParticipantIDInSearchStartByParticipantID= ParticipantID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForParticipant++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CParticipant *theParticipant;
	compareObject.ParticipantID=ParticipantID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByParticipantID=pParticipantIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theParticipant=(CParticipant *)(pLastFoundInSearchStartByParticipantID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theParticipant;
}

CParticipant *CParticipantFactory::findNextStartByParticipantID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForParticipant++;
#endif
	CParticipant *theParticipant;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByParticipantID=pParticipantIDIndex->getNextNode(pLastFoundInSearchStartByParticipantID);
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

	theParticipant=(CParticipant *)(pLastFoundInSearchStartByParticipantID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theParticipant;
}

void CParticipantFactory::endFindStartByParticipantID(void)
{
	pLastFoundInSearchStartByParticipantID=NULL;
}

int compareForUserIDIndexinUser(const void *pV1, const void *pV2)
{
	CUser *p1,*p2;
	p1=(CUser *)pV1;
	p2=(CUser *)pV2;
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
int findByUserIDForUser=0;
#endif
CUser *CUserFactory::findByUserID( const CReadOnlyUserIDType&  UserID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByUserID of CUser while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByUserIDForUser++;
#endif
	CAVLNode *pNode;
	compareObject.UserID=UserID.getValue();
	pNode=pUserIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CUser *)(pNode->pObject);
}

CUser *CUserFactory::findByPK( const CReadOnlyUserIDType&  UserID)
{
	return findByUserID(UserID);
}
	
CUser *CUserFactory::findByPK(CWriteableUser *pUser)
{
	return findByPK(
		pUser->UserID
		);
}

bool CUserFactory::retrieveByPK(CWriteableUser *pUser)
{
	CUser *pOriginalUser;
	pOriginalUser=findByPK(pUser);
	if (pOriginalUser==NULL)
	{
		return false;
	}
	retrieve(pOriginalUser,pUser);
	return true;
}

CUser *CUserFactory::addByPK(CWriteableUser *pUser, CTransaction *pTransaction)
{
	CUser *pOriginalUser;
	pOriginalUser=findByPK(pUser);
	if (pOriginalUser != NULL)
	{
		return NULL;
	}
	return add(pUser,pTransaction);
}

bool CUserFactory::updateByPK(CWriteableUser *pUser, CTransaction *pTransaction, bool updateIndex)
{
	CUser *pOriginalUser;
	pOriginalUser=findByPK(pUser);
	if (pOriginalUser==NULL)
	{
		return false;
	}
	pUser->calAllHash();
	update(pOriginalUser,pUser,pTransaction,updateIndex);
	return true;
}

bool CUserFactory::removeByPK(CWriteableUser *pUser, CTransaction *pTransaction)
{
	CUser *pOriginalUser;
	pOriginalUser=findByPK(pUser);
	if (pOriginalUser==NULL)
	{
		return false;
	}
	remove(pOriginalUser,pTransaction);
	return true;
}



#ifdef COUNT_SEARCH
int multiFindStartByUserIDForUser=0;
#endif

CUser *CUserFactory::startFindStartByUserID( const CReadOnlyUserIDType& UserID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByUserID of CUser while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByUserID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByUserID();
	}

	///记录所有的查询值
	queryUserIDInSearchStartByUserID= UserID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByUserIDForUser++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CUser *theUser;
	compareObject.UserID=UserID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByUserID=pUserIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByUserID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theUser=(CUser *)(pLastFoundInSearchStartByUserID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theUser;
}

CUser *CUserFactory::findNextStartByUserID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByUserID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByUserIDForUser++;
#endif
	CUser *theUser;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByUserID=pUserIDIndex->getNextNode(pLastFoundInSearchStartByUserID);
	if (pLastFoundInSearchStartByUserID==NULL)
	{
		return NULL;
	}

	theUser=(CUser *)(pLastFoundInSearchStartByUserID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theUser;
}

void CUserFactory::endFindStartByUserID(void)
{
	pLastFoundInSearchStartByUserID=NULL;
}


#ifdef COUNT_SEARCH
int findByClientIDForClient=0;
#endif
CClient *CClientFactory::findByClientID( const CReadOnlyClientIDType&  ClientID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByClientID of CClient while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.ClientID=ClientID.getValue();
	
	compareObject.calHashClientID();
	for (pNode=pClientIDHashIndex->searchFirstEqual(compareObject.HashClientID);
		pNode!=NULL;
		pNode=pClientIDHashIndex->searchNextEqual(pNode))
	{
		if (((CClient *)(pNode->pObject))->HashClientID != compareObject.HashClientID)
		{
			continue;
		}
		if (compare(((CClient *)(pNode->pObject))->ClientID.getValue(),ClientID.getValue())!=0)
		{
			continue;
		}
		return (CClient *)(pNode->pObject);
	}
	return NULL;
}

CClient *CClientFactory::findByPK( const CReadOnlyClientIDType&  ClientID)
{
	return findByClientID(ClientID);
}
	
CClient *CClientFactory::findByPK(CWriteableClient *pClient)
{
	return findByPK(
		pClient->ClientID
		);
}

bool CClientFactory::retrieveByPK(CWriteableClient *pClient)
{
	CClient *pOriginalClient;
	pOriginalClient=findByPK(pClient);
	if (pOriginalClient==NULL)
	{
		return false;
	}
	retrieve(pOriginalClient,pClient);
	return true;
}

CClient *CClientFactory::addByPK(CWriteableClient *pClient, CTransaction *pTransaction)
{
	CClient *pOriginalClient;
	pOriginalClient=findByPK(pClient);
	if (pOriginalClient != NULL)
	{
		return NULL;
	}
	return add(pClient,pTransaction);
}

bool CClientFactory::updateByPK(CWriteableClient *pClient, CTransaction *pTransaction, bool updateIndex)
{
	CClient *pOriginalClient;
	pOriginalClient=findByPK(pClient);
	if (pOriginalClient==NULL)
	{
		return false;
	}
	pClient->calAllHash();
	update(pOriginalClient,pClient,pTransaction,updateIndex);
	return true;
}

bool CClientFactory::removeByPK(CWriteableClient *pClient, CTransaction *pTransaction)
{
	CClient *pOriginalClient;
	pOriginalClient=findByPK(pClient);
	if (pOriginalClient==NULL)
	{
		return false;
	}
	remove(pOriginalClient,pTransaction);
	return true;
}


int compareForUserIPMaskIndexinUserIP(const void *pV1, const void *pV2)
{
	CUserIP *p1,*p2;
	p1=(CUserIP *)pV1;
	p2=(CUserIP *)pV2;
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
	switch (compare(p1->IPAddress.getValue(),p2->IPAddress.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->IPMask.getValue(),p2->IPMask.getValue()))
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
int multiFindByUserIDForUserIP=0;
#endif

CUserIP *CUserIPFactory::startFindByUserID( const CReadOnlyUserIDType& UserID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByUserID of CUserIP while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByUserID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByUserID();
	}

	///记录所有的查询值
	queryUserIDInSearchByUserID= UserID.getValue();

#ifdef COUNT_SEARCH
	multiFindByUserIDForUserIP++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CUserIP *theUserIP;
	compareObject.UserID=UserID.getValue();
	compareObject.IPAddress="";
	compareObject.IPMask="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByUserID=pUserIPMaskIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theUserIP=(CUserIP *)(pLastFoundInSearchByUserID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theUserIP->UserID.getValue(),UserID.getValue()))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theUserIP;
}

CUserIP *CUserIPFactory::findNextByUserID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByUserIDForUserIP++;
#endif
	CUserIP *theUserIP;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByUserID=pUserIPMaskIndex->getNextNode(pLastFoundInSearchByUserID);
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

	theUserIP=(CUserIP *)(pLastFoundInSearchByUserID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theUserIP->UserID,queryUserIDInSearchByUserID))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theUserIP;
}

void CUserIPFactory::endFindByUserID(void)
{
	pLastFoundInSearchByUserID=NULL;
}


#ifdef COUNT_SEARCH
int findByUserIPAndMaskForUserIP=0;
#endif
CUserIP *CUserIPFactory::findByUserIPAndMask( const CReadOnlyUserIDType&  UserID,  const CReadOnlyIPAddressType&  IPAddress,  const CReadOnlyIPAddressType&  IPMask)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByUserIPAndMask of CUserIP while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByUserIPAndMaskForUserIP++;
#endif
	CAVLNode *pNode;
	compareObject.UserID=UserID.getValue();
	compareObject.IPAddress=IPAddress.getValue();
	compareObject.IPMask=IPMask.getValue();
	pNode=pUserIPMaskIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CUserIP *)(pNode->pObject);
}

CUserIP *CUserIPFactory::findByPK( const CReadOnlyUserIDType&  UserID,  const CReadOnlyIPAddressType&  IPAddress,  const CReadOnlyIPAddressType&  IPMask)
{
	return findByUserIPAndMask(UserID, IPAddress, IPMask);
}
	
CUserIP *CUserIPFactory::findByPK(CWriteableUserIP *pUserIP)
{
	return findByPK(
		pUserIP->UserID
		,
		pUserIP->IPAddress
		,
		pUserIP->IPMask
		);
}

bool CUserIPFactory::retrieveByPK(CWriteableUserIP *pUserIP)
{
	CUserIP *pOriginalUserIP;
	pOriginalUserIP=findByPK(pUserIP);
	if (pOriginalUserIP==NULL)
	{
		return false;
	}
	retrieve(pOriginalUserIP,pUserIP);
	return true;
}

CUserIP *CUserIPFactory::addByPK(CWriteableUserIP *pUserIP, CTransaction *pTransaction)
{
	CUserIP *pOriginalUserIP;
	pOriginalUserIP=findByPK(pUserIP);
	if (pOriginalUserIP != NULL)
	{
		return NULL;
	}
	return add(pUserIP,pTransaction);
}

bool CUserIPFactory::updateByPK(CWriteableUserIP *pUserIP, CTransaction *pTransaction, bool updateIndex)
{
	CUserIP *pOriginalUserIP;
	pOriginalUserIP=findByPK(pUserIP);
	if (pOriginalUserIP==NULL)
	{
		return false;
	}
	pUserIP->calAllHash();
	update(pOriginalUserIP,pUserIP,pTransaction,updateIndex);
	return true;
}

bool CUserIPFactory::removeByPK(CWriteableUserIP *pUserIP, CTransaction *pTransaction)
{
	CUserIP *pOriginalUserIP;
	pOriginalUserIP=findByPK(pUserIP);
	if (pOriginalUserIP==NULL)
	{
		return false;
	}
	remove(pOriginalUserIP,pTransaction);
	return true;
}


int compareForPartClientIndexinPartClient(const void *pV1, const void *pV2)
{
	CPartClient *p1,*p2;
	p1=(CPartClient *)pV1;
	p2=(CPartClient *)pV2;
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
int compareForClientIndexinPartClient(const void *pV1, const void *pV2)
{
	CPartClient *p1,*p2;
	p1=(CPartClient *)pV1;
	p2=(CPartClient *)pV2;
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
int findByPartClientForPartClient=0;
#endif
CPartClient *CPartClientFactory::findByPartClient( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByPartClient of CPartClient while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.ClientID=ClientID.getValue();
	
	compareObject.calHashPartClient();
	for (pNode=pPartClientHashIndex->searchFirstEqual(compareObject.HashPartClient);
		pNode!=NULL;
		pNode=pPartClientHashIndex->searchNextEqual(pNode))
	{
		if (((CPartClient *)(pNode->pObject))->HashPartClient != compareObject.HashPartClient)
		{
			continue;
		}
		if (compare(((CPartClient *)(pNode->pObject))->ParticipantID.getValue(),ParticipantID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CPartClient *)(pNode->pObject))->ClientID.getValue(),ClientID.getValue())!=0)
		{
			continue;
		}
		return (CPartClient *)(pNode->pObject);
	}
	return NULL;
}

CPartClient *CPartClientFactory::findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID)
{
	return findByPartClient(ParticipantID, ClientID);
}
	
CPartClient *CPartClientFactory::findByPK(CWriteablePartClient *pPartClient)
{
	return findByPK(
		pPartClient->ParticipantID
		,
		pPartClient->ClientID
		);
}

bool CPartClientFactory::retrieveByPK(CWriteablePartClient *pPartClient)
{
	CPartClient *pOriginalPartClient;
	pOriginalPartClient=findByPK(pPartClient);
	if (pOriginalPartClient==NULL)
	{
		return false;
	}
	retrieve(pOriginalPartClient,pPartClient);
	return true;
}

CPartClient *CPartClientFactory::addByPK(CWriteablePartClient *pPartClient, CTransaction *pTransaction)
{
	CPartClient *pOriginalPartClient;
	pOriginalPartClient=findByPK(pPartClient);
	if (pOriginalPartClient != NULL)
	{
		return NULL;
	}
	return add(pPartClient,pTransaction);
}

bool CPartClientFactory::updateByPK(CWriteablePartClient *pPartClient, CTransaction *pTransaction, bool updateIndex)
{
	CPartClient *pOriginalPartClient;
	pOriginalPartClient=findByPK(pPartClient);
	if (pOriginalPartClient==NULL)
	{
		return false;
	}
	pPartClient->calAllHash();
	update(pOriginalPartClient,pPartClient,pTransaction,updateIndex);
	return true;
}

bool CPartClientFactory::removeByPK(CWriteablePartClient *pPartClient, CTransaction *pTransaction)
{
	CPartClient *pOriginalPartClient;
	pOriginalPartClient=findByPK(pPartClient);
	if (pOriginalPartClient==NULL)
	{
		return false;
	}
	remove(pOriginalPartClient,pTransaction);
	return true;
}



#ifdef COUNT_SEARCH
int multiFindStartByParticipantForPartClient=0;
#endif

CPartClient *CPartClientFactory::startFindStartByParticipant( const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByParticipant of CPartClient while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByParticipant!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByParticipant();
	}

	///记录所有的查询值
	queryParticipantIDInSearchStartByParticipant= ParticipantID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByParticipantForPartClient++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CPartClient *thePartClient;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.ClientID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByParticipant=pPartClientIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByParticipant==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	thePartClient=(CPartClient *)(pLastFoundInSearchStartByParticipant->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return thePartClient;
}

CPartClient *CPartClientFactory::findNextStartByParticipant(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByParticipant==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByParticipantForPartClient++;
#endif
	CPartClient *thePartClient;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByParticipant=pPartClientIndex->getNextNode(pLastFoundInSearchStartByParticipant);
	if (pLastFoundInSearchStartByParticipant==NULL)
	{
		return NULL;
	}

	thePartClient=(CPartClient *)(pLastFoundInSearchStartByParticipant->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return thePartClient;
}

void CPartClientFactory::endFindStartByParticipant(void)
{
	pLastFoundInSearchStartByParticipant=NULL;
}


#ifdef COUNT_SEARCH
int multiFindStartByClientForPartClient=0;
#endif

CPartClient *CPartClientFactory::startFindStartByClient( const CReadOnlyClientIDType& ClientID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByClient of CPartClient while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByClient!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByClient();
	}

	///记录所有的查询值
	queryClientIDInSearchStartByClient= ClientID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByClientForPartClient++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CPartClient *thePartClient;
	compareObject.ClientID=ClientID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByClient=pClientIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByClient==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	thePartClient=(CPartClient *)(pLastFoundInSearchStartByClient->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return thePartClient;
}

CPartClient *CPartClientFactory::findNextStartByClient(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByClient==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByClientForPartClient++;
#endif
	CPartClient *thePartClient;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByClient=pClientIndex->getNextNode(pLastFoundInSearchStartByClient);
	if (pLastFoundInSearchStartByClient==NULL)
	{
		return NULL;
	}

	thePartClient=(CPartClient *)(pLastFoundInSearchStartByClient->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return thePartClient;
}

void CPartClientFactory::endFindStartByClient(void)
{
	pLastFoundInSearchStartByClient=NULL;
}


#ifdef COUNT_SEARCH
int findByParticipantForClearingTradingPart=0;
#endif
CClearingTradingPart *CClearingTradingPartFactory::findByParticipant( const CReadOnlyParticipantIDType&  ParticipantID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByParticipant of CClearingTradingPart while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	
	compareObject.calHashParticipantID();
	for (pNode=pParticipantIDHashIndex->searchFirstEqual(compareObject.HashParticipantID);
		pNode!=NULL;
		pNode=pParticipantIDHashIndex->searchNextEqual(pNode))
	{
		if (((CClearingTradingPart *)(pNode->pObject))->HashParticipantID != compareObject.HashParticipantID)
		{
			continue;
		}
		if (compare(((CClearingTradingPart *)(pNode->pObject))->ParticipantID.getValue(),ParticipantID.getValue())!=0)
		{
			continue;
		}
		return (CClearingTradingPart *)(pNode->pObject);
	}
	return NULL;
}

CClearingTradingPart *CClearingTradingPartFactory::findByPK( const CReadOnlyParticipantIDType&  ParticipantID)
{
	return findByParticipant(ParticipantID);
}
	
CClearingTradingPart *CClearingTradingPartFactory::findByPK(CWriteableClearingTradingPart *pClearingTradingPart)
{
	return findByPK(
		pClearingTradingPart->ParticipantID
		);
}

bool CClearingTradingPartFactory::retrieveByPK(CWriteableClearingTradingPart *pClearingTradingPart)
{
	CClearingTradingPart *pOriginalClearingTradingPart;
	pOriginalClearingTradingPart=findByPK(pClearingTradingPart);
	if (pOriginalClearingTradingPart==NULL)
	{
		return false;
	}
	retrieve(pOriginalClearingTradingPart,pClearingTradingPart);
	return true;
}

CClearingTradingPart *CClearingTradingPartFactory::addByPK(CWriteableClearingTradingPart *pClearingTradingPart, CTransaction *pTransaction)
{
	CClearingTradingPart *pOriginalClearingTradingPart;
	pOriginalClearingTradingPart=findByPK(pClearingTradingPart);
	if (pOriginalClearingTradingPart != NULL)
	{
		return NULL;
	}
	return add(pClearingTradingPart,pTransaction);
}

bool CClearingTradingPartFactory::updateByPK(CWriteableClearingTradingPart *pClearingTradingPart, CTransaction *pTransaction, bool updateIndex)
{
	CClearingTradingPart *pOriginalClearingTradingPart;
	pOriginalClearingTradingPart=findByPK(pClearingTradingPart);
	if (pOriginalClearingTradingPart==NULL)
	{
		return false;
	}
	pClearingTradingPart->calAllHash();
	update(pOriginalClearingTradingPart,pClearingTradingPart,pTransaction,updateIndex);
	return true;
}

bool CClearingTradingPartFactory::removeByPK(CWriteableClearingTradingPart *pClearingTradingPart, CTransaction *pTransaction)
{
	CClearingTradingPart *pOriginalClearingTradingPart;
	pOriginalClearingTradingPart=findByPK(pClearingTradingPart);
	if (pOriginalClearingTradingPart==NULL)
	{
		return false;
	}
	remove(pOriginalClearingTradingPart,pTransaction);
	return true;
}



#ifdef COUNT_SEARCH
int findByUserFunctionForUserFunctionRight=0;
#endif
CUserFunctionRight *CUserFunctionRightFactory::findByUserFunction( const CReadOnlyUserIDType&  UserID,  const CReadOnlyFunctionCodeType&  FunctionCode)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByUserFunction of CUserFunctionRight while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.UserID=UserID.getValue();
	compareObject.FunctionCode=FunctionCode.getValue();
	
	compareObject.calHashUserFunction();
	for (pNode=pUserFunctionHashIndex->searchFirstEqual(compareObject.HashUserFunction);
		pNode!=NULL;
		pNode=pUserFunctionHashIndex->searchNextEqual(pNode))
	{
		if (((CUserFunctionRight *)(pNode->pObject))->HashUserFunction != compareObject.HashUserFunction)
		{
			continue;
		}
		if (compare(((CUserFunctionRight *)(pNode->pObject))->UserID.getValue(),UserID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CUserFunctionRight *)(pNode->pObject))->FunctionCode.getValue(),FunctionCode.getValue())!=0)
		{
			continue;
		}
		return (CUserFunctionRight *)(pNode->pObject);
	}
	return NULL;
}


int compareForAccountIDIndexinAccount(const void *pV1, const void *pV2)
{
	CAccount *p1,*p2;
	p1=(CAccount *)pV1;
	p2=(CAccount *)pV2;
	switch (compare(p1->AccountID.getValue(),p2->AccountID.getValue()))
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
int compareForParticipantIDIndexinAccount(const void *pV1, const void *pV2)
{
	CAccount *p1,*p2;
	p1=(CAccount *)pV1;
	p2=(CAccount *)pV2;
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
int findByAccountIDForAccount=0;
#endif
CAccount *CAccountFactory::findByAccountID( const CReadOnlyAccountIDType&  AccountID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByAccountID of CAccount while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByAccountIDForAccount++;
#endif
	CAVLNode *pNode;
	compareObject.AccountID=AccountID.getValue();
	pNode=pAccountIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CAccount *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindStartByParticipantIDForAccount=0;
#endif

CAccount *CAccountFactory::startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByParticipantID of CAccount while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByParticipantID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByParticipantID();
	}

	///记录所有的查询值
	queryParticipantIDInSearchStartByParticipantID= ParticipantID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForAccount++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CAccount *theAccount;
	compareObject.ParticipantID=ParticipantID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByParticipantID=pParticipantIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theAccount=(CAccount *)(pLastFoundInSearchStartByParticipantID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theAccount;
}

CAccount *CAccountFactory::findNextStartByParticipantID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForAccount++;
#endif
	CAccount *theAccount;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByParticipantID=pParticipantIDIndex->getNextNode(pLastFoundInSearchStartByParticipantID);
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

	theAccount=(CAccount *)(pLastFoundInSearchStartByParticipantID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theAccount;
}

void CAccountFactory::endFindStartByParticipantID(void)
{
	pLastFoundInSearchStartByParticipantID=NULL;
}


#ifdef COUNT_SEARCH
int findByUserIDForUserCommFlux=0;
#endif
CUserCommFlux *CUserCommFluxFactory::findByUserID( const CReadOnlyUserIDType&  UserID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByUserID of CUserCommFlux while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.UserID=UserID.getValue();
	
	compareObject.calHashUserID();
	for (pNode=pUserIDHashIndex->searchFirstEqual(compareObject.HashUserID);
		pNode!=NULL;
		pNode=pUserIDHashIndex->searchNextEqual(pNode))
	{
		if (((CUserCommFlux *)(pNode->pObject))->HashUserID != compareObject.HashUserID)
		{
			continue;
		}
		if (compare(((CUserCommFlux *)(pNode->pObject))->UserID.getValue(),UserID.getValue())!=0)
		{
			continue;
		}
		return (CUserCommFlux *)(pNode->pObject);
	}
	return NULL;
}


int compareForMarketDataLogNoIndexinMarketDataLog(const void *pV1, const void *pV2)
{
	CMarketDataLog *p1,*p2;
	p1=(CMarketDataLog *)pV1;
	p2=(CMarketDataLog *)pV2;
	switch (compare(p1->MarketDataLogNo.getValue(),p2->MarketDataLogNo.getValue()))
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
int multiFindByMarketDataLogNoForMarketDataLog=0;
#endif

CMarketDataLog *CMarketDataLogFactory::startFindByMarketDataLogNo( const CReadOnlySequenceNoType& MarketDataLogNo)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByMarketDataLogNo of CMarketDataLog while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByMarketDataLogNo!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByMarketDataLogNo();
	}

	///记录所有的查询值
	queryMarketDataLogNoInSearchByMarketDataLogNo= MarketDataLogNo.getValue();

#ifdef COUNT_SEARCH
	multiFindByMarketDataLogNoForMarketDataLog++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CMarketDataLog *theMarketDataLog;
	compareObject.MarketDataLogNo=MarketDataLogNo.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByMarketDataLogNo=pMarketDataLogNoIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByMarketDataLogNo==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theMarketDataLog=(CMarketDataLog *)(pLastFoundInSearchByMarketDataLogNo->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theMarketDataLog;
}

CMarketDataLog *CMarketDataLogFactory::findNextByMarketDataLogNo(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByMarketDataLogNo==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByMarketDataLogNoForMarketDataLog++;
#endif
	CMarketDataLog *theMarketDataLog;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByMarketDataLogNo=pMarketDataLogNoIndex->getNextNode(pLastFoundInSearchByMarketDataLogNo);
	if (pLastFoundInSearchByMarketDataLogNo==NULL)
	{
		return NULL;
	}

	theMarketDataLog=(CMarketDataLog *)(pLastFoundInSearchByMarketDataLogNo->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theMarketDataLog;
}

void CMarketDataLogFactory::endFindByMarketDataLogNo(void)
{
	pLastFoundInSearchByMarketDataLogNo=NULL;
}


#ifdef COUNT_SEARCH
int findMaxMarketDataLogNoForMarketDataLog=0;
#endif
CMarketDataLog *CMarketDataLogFactory::findMaxMarketDataLogNo()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findMaxMarketDataLogNo of CMarketDataLog while run level < 0");
	}
#ifdef COUNT_SEARCH
	findMaxMarketDataLogNoForMarketDataLog++;
#endif
	CAVLNode *pNode;
	compareObject.MarketDataLogNo="zzzzzzzz";
	pNode=pMarketDataLogNoIndex->searchFirstGreatEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CMarketDataLog *)(pNode->pObject);
}


int compareForSessionIDIndexinUserSession(const void *pV1, const void *pV2)
{
	CUserSession *p1,*p2;
	p1=(CUserSession *)pV1;
	p2=(CUserSession *)pV2;
	switch (compare(p1->FrontID.getValue(),p2->FrontID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->SessionID.getValue(),p2->SessionID.getValue()))
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
int compareForUserIndexinUserSession(const void *pV1, const void *pV2)
{
	CUserSession *p1,*p2;
	p1=(CUserSession *)pV1;
	p2=(CUserSession *)pV2;
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
int findBySessionIDForUserSession=0;
#endif
CUserSession *CUserSessionFactory::findBySessionID( const CReadOnlySessionIDType&  SessionID,  const CReadOnlyFrontIDType&  FrontID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findBySessionID of CUserSession while run level < 0");
	}
#ifdef COUNT_SEARCH
	findBySessionIDForUserSession++;
#endif
	CAVLNode *pNode;
	compareObject.SessionID=SessionID.getValue();
	compareObject.FrontID=FrontID.getValue();
	pNode=pSessionIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CUserSession *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByFrontIDForUserSession=0;
#endif

CUserSession *CUserSessionFactory::startFindByFrontID( const CReadOnlyFrontIDType& FrontID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByFrontID of CUserSession while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByFrontID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByFrontID();
	}

	///记录所有的查询值
	queryFrontIDInSearchByFrontID= FrontID.getValue();

#ifdef COUNT_SEARCH
	multiFindByFrontIDForUserSession++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CUserSession *theUserSession;
	compareObject.FrontID=FrontID.getValue();
	compareObject.SessionID=1<<31;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByFrontID=pSessionIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByFrontID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theUserSession=(CUserSession *)(pLastFoundInSearchByFrontID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theUserSession->FrontID.getValue(),FrontID.getValue()))
	{
		pLastFoundInSearchByFrontID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theUserSession;
}

CUserSession *CUserSessionFactory::findNextByFrontID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByFrontID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByFrontIDForUserSession++;
#endif
	CUserSession *theUserSession;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByFrontID=pSessionIDIndex->getNextNode(pLastFoundInSearchByFrontID);
	if (pLastFoundInSearchByFrontID==NULL)
	{
		return NULL;
	}

	theUserSession=(CUserSession *)(pLastFoundInSearchByFrontID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theUserSession->FrontID,queryFrontIDInSearchByFrontID))
	{
		pLastFoundInSearchByFrontID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theUserSession;
}

void CUserSessionFactory::endFindByFrontID(void)
{
	pLastFoundInSearchByFrontID=NULL;
}


#ifdef COUNT_SEARCH
int findByUserIDForUserSession=0;
#endif
CUserSession *CUserSessionFactory::findByUserID( const CReadOnlyUserIDType&  UserID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByUserID of CUserSession while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByUserIDForUserSession++;
#endif
	CAVLNode *pNode;
	compareObject.UserID=UserID.getValue();
	pNode=pUserIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CUserSession *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindStartByUserIDForUserSession=0;
#endif

CUserSession *CUserSessionFactory::startFindStartByUserID( const CReadOnlyUserIDType& UserID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByUserID of CUserSession while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByUserID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByUserID();
	}

	///记录所有的查询值
	queryUserIDInSearchStartByUserID= UserID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByUserIDForUserSession++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CUserSession *theUserSession;
	compareObject.UserID=UserID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByUserID=pUserIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByUserID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theUserSession=(CUserSession *)(pLastFoundInSearchStartByUserID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theUserSession;
}

CUserSession *CUserSessionFactory::findNextStartByUserID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByUserID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByUserIDForUserSession++;
#endif
	CUserSession *theUserSession;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByUserID=pUserIndex->getNextNode(pLastFoundInSearchStartByUserID);
	if (pLastFoundInSearchStartByUserID==NULL)
	{
		return NULL;
	}

	theUserSession=(CUserSession *)(pLastFoundInSearchStartByUserID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theUserSession;
}

void CUserSessionFactory::endFindStartByUserID(void)
{
	pLastFoundInSearchStartByUserID=NULL;
}

int compareForSessionIDIndexinMDSession(const void *pV1, const void *pV2)
{
	CMDSession *p1,*p2;
	p1=(CMDSession *)pV1;
	p2=(CMDSession *)pV2;
	switch (compare(p1->SessionID.getValue(),p2->SessionID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->FrontID.getValue(),p2->FrontID.getValue()))
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
int compareForUserIndexinMDSession(const void *pV1, const void *pV2)
{
	CMDSession *p1,*p2;
	p1=(CMDSession *)pV1;
	p2=(CMDSession *)pV2;
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
int findBySessionIDForMDSession=0;
#endif
CMDSession *CMDSessionFactory::findBySessionID( const CReadOnlySessionIDType&  SessionID,  const CReadOnlyFrontIDType&  FrontID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findBySessionID of CMDSession while run level < 0");
	}
#ifdef COUNT_SEARCH
	findBySessionIDForMDSession++;
#endif
	CAVLNode *pNode;
	compareObject.SessionID=SessionID.getValue();
	compareObject.FrontID=FrontID.getValue();
	pNode=pSessionIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CMDSession *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int findByUserIDForMDSession=0;
#endif
CMDSession *CMDSessionFactory::findByUserID( const CReadOnlyUserIDType&  UserID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByUserID of CMDSession while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByUserIDForMDSession++;
#endif
	CAVLNode *pNode;
	compareObject.UserID=UserID.getValue();
	pNode=pUserIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CMDSession *)(pNode->pObject);
}


int compareForPrimaryKeyIndexinLoginInfo(const void *pV1, const void *pV2)
{
	CLoginInfo *p1,*p2;
	p1=(CLoginInfo *)pV1;
	p2=(CLoginInfo *)pV2;
	switch (compare(p1->TradingDay.getValue(),p2->TradingDay.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->SequenceNo.getValue(),p2->SequenceNo.getValue()))
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
int findByPrimaryKeyForLoginInfo=0;
#endif
CLoginInfo *CLoginInfoFactory::findByPrimaryKey( const CReadOnlyDateType&  TradingDay,  const CReadOnlySequenceNoType&  SequenceNo)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByPrimaryKey of CLoginInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByPrimaryKeyForLoginInfo++;
#endif
	CAVLNode *pNode;
	compareObject.TradingDay=TradingDay.getValue();
	compareObject.SequenceNo=SequenceNo.getValue();
	pNode=pPrimaryKeyIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CLoginInfo *)(pNode->pObject);
}


int compareForPrimaryKeyIndexinDepthMarketDataDetail(const void *pV1, const void *pV2)
{
	CDepthMarketDataDetail *p1,*p2;
	p1=(CDepthMarketDataDetail *)pV1;
	p2=(CDepthMarketDataDetail *)pV2;
	switch (compare(p1->TradingDay.getValue(),p2->TradingDay.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->SettlementGroupID.getValue(),p2->SettlementGroupID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->SettlementID.getValue(),p2->SettlementID.getValue()))
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
	switch (compare(p1->SequenceNo.getValue(),p2->SequenceNo.getValue()))
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
int findByPrimaryKeyForDepthMarketDataDetail=0;
#endif
CDepthMarketDataDetail *CDepthMarketDataDetailFactory::findByPrimaryKey( const CReadOnlyDateType&  TradingDay,  const CReadOnlySettlementGroupIDType&  SettlementGroupID,  const CReadOnlySettlementIDType&  SettlementID,  const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlySequenceNoType&  SequenceNo)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByPrimaryKey of CDepthMarketDataDetail while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByPrimaryKeyForDepthMarketDataDetail++;
#endif
	CAVLNode *pNode;
	compareObject.TradingDay=TradingDay.getValue();
	compareObject.SettlementGroupID=SettlementGroupID.getValue();
	compareObject.SettlementID=SettlementID.getValue();
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.SequenceNo=SequenceNo.getValue();
	pNode=pPrimaryKeyIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CDepthMarketDataDetail *)(pNode->pObject);
}


int compareForFrontIDIndexinFrontStatus(const void *pV1, const void *pV2)
{
	CFrontStatus *p1,*p2;
	p1=(CFrontStatus *)pV1;
	p2=(CFrontStatus *)pV2;
	switch (compare(p1->FrontID.getValue(),p2->FrontID.getValue()))
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
int findByFrontIDForFrontStatus=0;
#endif
CFrontStatus *CFrontStatusFactory::findByFrontID( const CReadOnlyFrontIDType&  FrontID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByFrontID of CFrontStatus while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByFrontIDForFrontStatus++;
#endif
	CAVLNode *pNode;
	compareObject.FrontID=FrontID.getValue();
	pNode=pFrontIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CFrontStatus *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int findByUserIDForMaxLocalID=0;
#endif
CMaxLocalID *CMaxLocalIDFactory::findByUserID( const CReadOnlyUserIDType&  UserID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByUserID of CMaxLocalID while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.UserID=UserID.getValue();
	
	compareObject.calHashUserID();
	for (pNode=pUserIDHashIndex->searchFirstEqual(compareObject.HashUserID);
		pNode!=NULL;
		pNode=pUserIDHashIndex->searchNextEqual(pNode))
	{
		if (((CMaxLocalID *)(pNode->pObject))->HashUserID != compareObject.HashUserID)
		{
			continue;
		}
		if (compare(((CMaxLocalID *)(pNode->pObject))->UserID.getValue(),UserID.getValue())!=0)
		{
			continue;
		}
		return (CMaxLocalID *)(pNode->pObject);
	}
	return NULL;
}


int compareForBulletinIDIndexinBulletin(const void *pV1, const void *pV2)
{
	CBulletin *p1,*p2;
	p1=(CBulletin *)pV1;
	p2=(CBulletin *)pV2;
	switch (compare(p1->BulletinID.getValue(),p2->BulletinID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->TradingDay.getValue(),p2->TradingDay.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MarketID.getValue(),p2->MarketID.getValue()))
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
int findByBulletinIDForBulletin=0;
#endif
CBulletin *CBulletinFactory::findByBulletinID( const CReadOnlyBulletinIDType&  BulletinID,  const CReadOnlyDateType&  TradingDay,  const CReadOnlyMarketIDType&  MarketID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByBulletinID of CBulletin while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByBulletinIDForBulletin++;
#endif
	CAVLNode *pNode;
	compareObject.BulletinID=BulletinID.getValue();
	compareObject.TradingDay=TradingDay.getValue();
	compareObject.MarketID=MarketID.getValue();
	pNode=pBulletinIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CBulletin *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindStartByBulletinIDForBulletin=0;
#endif

CBulletin *CBulletinFactory::startFindStartByBulletinID( const CReadOnlyBulletinIDType& BulletinID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByBulletinID of CBulletin while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByBulletinID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByBulletinID();
	}

	///记录所有的查询值
	queryBulletinIDInSearchStartByBulletinID= BulletinID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByBulletinIDForBulletin++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CBulletin *theBulletin;
	compareObject.BulletinID=BulletinID.getValue();
	compareObject.TradingDay="";
	compareObject.MarketID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByBulletinID=pBulletinIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByBulletinID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theBulletin=(CBulletin *)(pLastFoundInSearchStartByBulletinID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theBulletin;
}

CBulletin *CBulletinFactory::findNextStartByBulletinID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByBulletinID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByBulletinIDForBulletin++;
#endif
	CBulletin *theBulletin;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByBulletinID=pBulletinIDIndex->getNextNode(pLastFoundInSearchStartByBulletinID);
	if (pLastFoundInSearchStartByBulletinID==NULL)
	{
		return NULL;
	}

	theBulletin=(CBulletin *)(pLastFoundInSearchStartByBulletinID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theBulletin;
}

void CBulletinFactory::endFindStartByBulletinID(void)
{
	pLastFoundInSearchStartByBulletinID=NULL;
}

int compareForInstrumentIDIndexinMarketDataModify(const void *pV1, const void *pV2)
{
	CMarketDataModify *p1,*p2;
	p1=(CMarketDataModify *)pV1;
	p2=(CMarketDataModify *)pV2;
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
int multiFindBySettlementGroupIDForMarketDataModify=0;
#endif

CMarketDataModify *CMarketDataModifyFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CMarketDataModify while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CMarketDataModify *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CMarketDataModify *CMarketDataModifyFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CMarketDataModify *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CMarketDataModifyFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentIDForMarketDataModify=0;
#endif
CMarketDataModify *CMarketDataModifyFactory::findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentID of CMarketDataModify while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentIDForMarketDataModify++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CMarketDataModify *)(pNode->pObject);
}


int compareForInstrumentIDIndexinDepthMarketData(const void *pV1, const void *pV2)
{
	CDepthMarketData *p1,*p2;
	p1=(CDepthMarketData *)pV1;
	p2=(CDepthMarketData *)pV2;
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
int multiFindBySettlementGroupIDForDepthMarketData=0;
#endif

CDepthMarketData *CDepthMarketDataFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CDepthMarketData while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CDepthMarketData *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CDepthMarketData *CDepthMarketDataFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CDepthMarketData *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CDepthMarketDataFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentIDForDepthMarketData=0;
#endif
CDepthMarketData *CDepthMarketDataFactory::findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentID of CDepthMarketData while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentIDForDepthMarketData++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CDepthMarketData *)(pNode->pObject);
}


int compareForTopicAndInstrumentIndexinTopicMarketData(const void *pV1, const void *pV2)
{
	CTopicMarketData *p1,*p2;
	p1=(CTopicMarketData *)pV1;
	p2=(CTopicMarketData *)pV2;
	switch (compare(p1->TopicID.getValue(),p2->TopicID.getValue()))
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
int compareForInstrumentIndexinTopicMarketData(const void *pV1, const void *pV2)
{
	CTopicMarketData *p1,*p2;
	p1=(CTopicMarketData *)pV1;
	p2=(CTopicMarketData *)pV2;
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
int findByTopicAndInstrumentForTopicMarketData=0;
#endif
CTopicMarketData *CTopicMarketDataFactory::findByTopicAndInstrument( const CReadOnlyTopicIDType&  TopicID,  const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByTopicAndInstrument of CTopicMarketData while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByTopicAndInstrumentForTopicMarketData++;
#endif
	CAVLNode *pNode;
	compareObject.TopicID=TopicID.getValue();
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pTopicAndInstrumentIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CTopicMarketData *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByTopicIDForTopicMarketData=0;
#endif

CTopicMarketData *CTopicMarketDataFactory::startFindByTopicID( const CReadOnlyTopicIDType& TopicID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTopicID of CTopicMarketData while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByTopicID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTopicID();
	}

	///记录所有的查询值
	queryTopicIDInSearchByTopicID= TopicID.getValue();

#ifdef COUNT_SEARCH
	multiFindByTopicIDForTopicMarketData++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CTopicMarketData *theTopicMarketData;
	compareObject.TopicID=TopicID.getValue();
	compareObject.InstrumentID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByTopicID=pTopicAndInstrumentIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByTopicID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theTopicMarketData=(CTopicMarketData *)(pLastFoundInSearchByTopicID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theTopicMarketData->TopicID.getValue(),TopicID.getValue()))
	{
		pLastFoundInSearchByTopicID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theTopicMarketData;
}

CTopicMarketData *CTopicMarketDataFactory::findNextByTopicID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByTopicID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTopicIDForTopicMarketData++;
#endif
	CTopicMarketData *theTopicMarketData;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByTopicID=pTopicAndInstrumentIndex->getNextNode(pLastFoundInSearchByTopicID);
	if (pLastFoundInSearchByTopicID==NULL)
	{
		return NULL;
	}

	theTopicMarketData=(CTopicMarketData *)(pLastFoundInSearchByTopicID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theTopicMarketData->TopicID,queryTopicIDInSearchByTopicID))
	{
		pLastFoundInSearchByTopicID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theTopicMarketData;
}

void CTopicMarketDataFactory::endFindByTopicID(void)
{
	pLastFoundInSearchByTopicID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByInstrumentIDForTopicMarketData=0;
#endif

CTopicMarketData *CTopicMarketDataFactory::startFindByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByInstrumentID of CTopicMarketData while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByInstrumentID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByInstrumentID();
	}

	///记录所有的查询值
	queryInstrumentIDInSearchByInstrumentID= InstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindByInstrumentIDForTopicMarketData++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CTopicMarketData *theTopicMarketData;
	compareObject.InstrumentID=InstrumentID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByInstrumentID=pInstrumentIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByInstrumentID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theTopicMarketData=(CTopicMarketData *)(pLastFoundInSearchByInstrumentID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theTopicMarketData->InstrumentID.getValue(),InstrumentID.getValue()))
	{
		pLastFoundInSearchByInstrumentID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theTopicMarketData;
}

CTopicMarketData *CTopicMarketDataFactory::findNextByInstrumentID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByInstrumentID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByInstrumentIDForTopicMarketData++;
#endif
	CTopicMarketData *theTopicMarketData;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByInstrumentID=pInstrumentIndex->getNextNode(pLastFoundInSearchByInstrumentID);
	if (pLastFoundInSearchByInstrumentID==NULL)
	{
		return NULL;
	}

	theTopicMarketData=(CTopicMarketData *)(pLastFoundInSearchByInstrumentID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theTopicMarketData->InstrumentID,queryInstrumentIDInSearchByInstrumentID))
	{
		pLastFoundInSearchByInstrumentID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theTopicMarketData;
}

void CTopicMarketDataFactory::endFindByInstrumentID(void)
{
	pLastFoundInSearchByInstrumentID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForTopicMarketData=0;
#endif

CTopicMarketData *CTopicMarketDataFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CTopicMarketData while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CTopicMarketData *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CTopicMarketData *CTopicMarketDataFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CTopicMarketData *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CTopicMarketDataFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}

int compareForTopicAndVersioninTopicMarketDataVersion(const void *pV1, const void *pV2)
{
	CTopicMarketDataVersion *p1,*p2;
	p1=(CTopicMarketDataVersion *)pV1;
	p2=(CTopicMarketDataVersion *)pV2;
	switch (compare(p1->TopicID.getValue(),p2->TopicID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->Version.getValue(),p2->Version.getValue()))
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
int multiFindByTopicAndVersionForTopicMarketDataVersion=0;
#endif

CTopicMarketDataVersion *CTopicMarketDataVersionFactory::startFindByTopicAndVersion( const CReadOnlyTopicIDType& TopicID,  const CReadOnlySequenceNoType& Version)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTopicAndVersion of CTopicMarketDataVersion while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByTopicAndVersion!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTopicAndVersion();
	}

	///记录所有的查询值
	queryTopicIDInSearchByTopicAndVersion= TopicID.getValue();
	queryVersionInSearchByTopicAndVersion= Version.getValue();

#ifdef COUNT_SEARCH
	multiFindByTopicAndVersionForTopicMarketDataVersion++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CTopicMarketDataVersion *theTopicMarketDataVersion;
	compareObject.TopicID=TopicID.getValue();
	compareObject.Version=Version.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByTopicAndVersion=pTopicAndVersion->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByTopicAndVersion==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theTopicMarketDataVersion=(CTopicMarketDataVersion *)(pLastFoundInSearchByTopicAndVersion->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theTopicMarketDataVersion->TopicID.getValue(),TopicID.getValue()))
	{
		pLastFoundInSearchByTopicAndVersion=NULL;
		return NULL;
	}
	if (compare(theTopicMarketDataVersion->Version.getValue(),Version.getValue()))
	{
		pLastFoundInSearchByTopicAndVersion=NULL;
		return NULL;
	}

	///返回找到的结果
	return theTopicMarketDataVersion;
}

CTopicMarketDataVersion *CTopicMarketDataVersionFactory::findNextByTopicAndVersion(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByTopicAndVersion==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTopicAndVersionForTopicMarketDataVersion++;
#endif
	CTopicMarketDataVersion *theTopicMarketDataVersion;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByTopicAndVersion=pTopicAndVersion->getNextNode(pLastFoundInSearchByTopicAndVersion);
	if (pLastFoundInSearchByTopicAndVersion==NULL)
	{
		return NULL;
	}

	theTopicMarketDataVersion=(CTopicMarketDataVersion *)(pLastFoundInSearchByTopicAndVersion->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theTopicMarketDataVersion->TopicID,queryTopicIDInSearchByTopicAndVersion))
	{
		pLastFoundInSearchByTopicAndVersion=NULL;
		return NULL;
	}
	if (compare(theTopicMarketDataVersion->Version,queryVersionInSearchByTopicAndVersion))
	{
		pLastFoundInSearchByTopicAndVersion=NULL;
		return NULL;
	}

	///返回找到的结果
	return theTopicMarketDataVersion;
}

void CTopicMarketDataVersionFactory::endFindByTopicAndVersion(void)
{
	pLastFoundInSearchByTopicAndVersion=NULL;
}

int compareForInformationIDIndexinInformation(const void *pV1, const void *pV2)
{
	CInformation *p1,*p2;
	p1=(CInformation *)pV1;
	p2=(CInformation *)pV2;
	switch (compare(p1->InformationID.getValue(),p2->InformationID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->SequenceNo.getValue(),p2->SequenceNo.getValue()))
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
int compareForInformationIDLastIndexinInformation(const void *pV1, const void *pV2)
{
	CInformation *p1,*p2;
	p1=(CInformation *)pV1;
	p2=(CInformation *)pV2;
	switch (compare(p1->InformationID.getValue(),p2->InformationID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->SequenceNo.getValue(),p2->SequenceNo.getValue()))
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
int multiFindByInformationIDForInformation=0;
#endif

CInformation *CInformationFactory::startFindByInformationID( const CReadOnlyInformationIDType& InformationID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByInformationID of CInformation while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByInformationID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByInformationID();
	}

	///记录所有的查询值
	queryInformationIDInSearchByInformationID= InformationID.getValue();

#ifdef COUNT_SEARCH
	multiFindByInformationIDForInformation++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CInformation *theInformation;
	compareObject.InformationID=InformationID.getValue();
	compareObject.SequenceNo=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByInformationID=pInformationIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByInformationID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theInformation=(CInformation *)(pLastFoundInSearchByInformationID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theInformation->InformationID.getValue(),InformationID.getValue()))
	{
		pLastFoundInSearchByInformationID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theInformation;
}

CInformation *CInformationFactory::findNextByInformationID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByInformationID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByInformationIDForInformation++;
#endif
	CInformation *theInformation;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByInformationID=pInformationIDIndex->getNextNode(pLastFoundInSearchByInformationID);
	if (pLastFoundInSearchByInformationID==NULL)
	{
		return NULL;
	}

	theInformation=(CInformation *)(pLastFoundInSearchByInformationID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theInformation->InformationID,queryInformationIDInSearchByInformationID))
	{
		pLastFoundInSearchByInformationID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theInformation;
}

void CInformationFactory::endFindByInformationID(void)
{
	pLastFoundInSearchByInformationID=NULL;
}


#ifdef COUNT_SEARCH
int findLastInInformationIDForInformation=0;
#endif
CInformation *CInformationFactory::findLastInInformationID( const CReadOnlyInformationIDType&  InformationID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findLastInInformationID of CInformation while run level < 0");
	}
#ifdef COUNT_SEARCH
	findLastInInformationIDForInformation++;
#endif
	CAVLNode *pNode;
	compareObject.InformationID=InformationID.getValue();
	compareObject.SequenceNo=999999;
	pNode=pInformationIDLastIndex->searchFirstGreatEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	if (compare(((CInformation *)(pNode->pObject))->InformationID.getValue(),InformationID.getValue())!=0)
	{
		return NULL;
	}
	return (CInformation *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int findByParticipantIDForOrderCount=0;
#endif
COrderCount *COrderCountFactory::findByParticipantID( const CReadOnlyParticipantIDType&  ParticipantID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByParticipantID of COrderCount while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	
	compareObject.calHashHashParticipantID();
	for (pNode=pHashParticipantIDIndex->searchFirstEqual(compareObject.HashHashParticipantID);
		pNode!=NULL;
		pNode=pHashParticipantIDIndex->searchNextEqual(pNode))
	{
		if (((COrderCount *)(pNode->pObject))->HashHashParticipantID != compareObject.HashHashParticipantID)
		{
			continue;
		}
		if (compare(((COrderCount *)(pNode->pObject))->ParticipantID.getValue(),ParticipantID.getValue())!=0)
		{
			continue;
		}
		return (COrderCount *)(pNode->pObject);
	}
	return NULL;
}


int compareForInstrumentIDIndexinInstrument(const void *pV1, const void *pV2)
{
	CInstrument *p1,*p2;
	p1=(CInstrument *)pV1;
	p2=(CInstrument *)pV2;
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
int compareForProductIDIndexinInstrument(const void *pV1, const void *pV2)
{
	CInstrument *p1,*p2;
	p1=(CInstrument *)pV1;
	p2=(CInstrument *)pV2;
	switch (compare(p1->ProductID.getValue(),p2->ProductID.getValue()))
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
int compareForProductGroupIDIndexinInstrument(const void *pV1, const void *pV2)
{
	CInstrument *p1,*p2;
	p1=(CInstrument *)pV1;
	p2=(CInstrument *)pV2;
	switch (compare(p1->ProductGroupID.getValue(),p2->ProductGroupID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->DeliveryYear.getValue(),p2->DeliveryYear.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->DeliveryMonth.getValue(),p2->DeliveryMonth.getValue()))
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
int compareForProductGroupIDRevIndexinInstrument(const void *pV1, const void *pV2)
{
	CInstrument *p1,*p2;
	p1=(CInstrument *)pV1;
	p2=(CInstrument *)pV2;
	switch (compare(p1->ProductGroupID.getValue(),p2->ProductGroupID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->DeliveryYear.getValue(),p2->DeliveryYear.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->DeliveryMonth.getValue(),p2->DeliveryMonth.getValue()))
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
int findByInstrumentIDForInstrument=0;
#endif
CInstrument *CInstrumentFactory::findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentID of CInstrument while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	
	compareObject.calHashInstrumentID();
	for (pNode=pInstrumentIDHashIndex->searchFirstEqual(compareObject.HashInstrumentID);
		pNode!=NULL;
		pNode=pInstrumentIDHashIndex->searchNextEqual(pNode))
	{
		if (((CInstrument *)(pNode->pObject))->HashInstrumentID != compareObject.HashInstrumentID)
		{
			continue;
		}
		if (compare(((CInstrument *)(pNode->pObject))->InstrumentID.getValue(),InstrumentID.getValue())!=0)
		{
			continue;
		}
		return (CInstrument *)(pNode->pObject);
	}
	return NULL;
}



#ifdef COUNT_SEARCH
int multiFindStartByInstrumentIDForInstrument=0;
#endif

CInstrument *CInstrumentFactory::startFindStartByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByInstrumentID of CInstrument while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByInstrumentID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByInstrumentID();
	}

	///记录所有的查询值
	queryInstrumentIDInSearchStartByInstrumentID= InstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByInstrumentIDForInstrument++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CInstrument *theInstrument;
	compareObject.InstrumentID=InstrumentID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByInstrumentID=pInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByInstrumentID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theInstrument=(CInstrument *)(pLastFoundInSearchStartByInstrumentID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theInstrument;
}

CInstrument *CInstrumentFactory::findNextStartByInstrumentID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByInstrumentID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByInstrumentIDForInstrument++;
#endif
	CInstrument *theInstrument;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByInstrumentID=pInstrumentIDIndex->getNextNode(pLastFoundInSearchStartByInstrumentID);
	if (pLastFoundInSearchStartByInstrumentID==NULL)
	{
		return NULL;
	}

	theInstrument=(CInstrument *)(pLastFoundInSearchStartByInstrumentID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theInstrument;
}

void CInstrumentFactory::endFindStartByInstrumentID(void)
{
	pLastFoundInSearchStartByInstrumentID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForInstrument=0;
#endif

CInstrument *CInstrumentFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CInstrument while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CInstrument *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CInstrument *CInstrumentFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CInstrument *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CInstrumentFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByProductIDForInstrument=0;
#endif

CInstrument *CInstrumentFactory::startFindByProductID( const CReadOnlyProductIDType& ProductID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByProductID of CInstrument while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByProductID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByProductID();
	}

	///记录所有的查询值
	queryProductIDInSearchByProductID= ProductID.getValue();

#ifdef COUNT_SEARCH
	multiFindByProductIDForInstrument++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CInstrument *theInstrument;
	compareObject.ProductID=ProductID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByProductID=pProductIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByProductID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theInstrument=(CInstrument *)(pLastFoundInSearchByProductID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theInstrument->ProductID.getValue(),ProductID.getValue()))
	{
		pLastFoundInSearchByProductID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theInstrument;
}

CInstrument *CInstrumentFactory::findNextByProductID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByProductID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByProductIDForInstrument++;
#endif
	CInstrument *theInstrument;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByProductID=pProductIDIndex->getNextNode(pLastFoundInSearchByProductID);
	if (pLastFoundInSearchByProductID==NULL)
	{
		return NULL;
	}

	theInstrument=(CInstrument *)(pLastFoundInSearchByProductID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theInstrument->ProductID,queryProductIDInSearchByProductID))
	{
		pLastFoundInSearchByProductID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theInstrument;
}

void CInstrumentFactory::endFindByProductID(void)
{
	pLastFoundInSearchByProductID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByProductGroupIDForInstrument=0;
#endif

CInstrument *CInstrumentFactory::startFindByProductGroupID( const CReadOnlyProductGroupIDType& ProductGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByProductGroupID of CInstrument while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByProductGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByProductGroupID();
	}

	///记录所有的查询值
	queryProductGroupIDInSearchByProductGroupID= ProductGroupID.getValue();

#ifdef COUNT_SEARCH
	multiFindByProductGroupIDForInstrument++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CInstrument *theInstrument;
	compareObject.ProductGroupID=ProductGroupID.getValue();
	compareObject.DeliveryYear=1900;
	compareObject.DeliveryMonth=1;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByProductGroupID=pProductGroupIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByProductGroupID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theInstrument=(CInstrument *)(pLastFoundInSearchByProductGroupID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theInstrument->ProductGroupID.getValue(),ProductGroupID.getValue()))
	{
		pLastFoundInSearchByProductGroupID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theInstrument;
}

CInstrument *CInstrumentFactory::findNextByProductGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByProductGroupID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByProductGroupIDForInstrument++;
#endif
	CInstrument *theInstrument;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByProductGroupID=pProductGroupIDIndex->getNextNode(pLastFoundInSearchByProductGroupID);
	if (pLastFoundInSearchByProductGroupID==NULL)
	{
		return NULL;
	}

	theInstrument=(CInstrument *)(pLastFoundInSearchByProductGroupID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theInstrument->ProductGroupID,queryProductGroupIDInSearchByProductGroupID))
	{
		pLastFoundInSearchByProductGroupID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theInstrument;
}

void CInstrumentFactory::endFindByProductGroupID(void)
{
	pLastFoundInSearchByProductGroupID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDeliveryMonthForInstrument=0;
#endif

CInstrument *CInstrumentFactory::startFindByDeliveryMonth( const CReadOnlyProductGroupIDType& ProductGroupID,  const CReadOnlyYearType& DeliveryYear,  const CReadOnlyMonthType& DeliveryMonth)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDeliveryMonth of CInstrument while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByDeliveryMonth!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDeliveryMonth();
	}

	///记录所有的查询值
	queryProductGroupIDInSearchByDeliveryMonth= ProductGroupID.getValue();
	queryDeliveryYearInSearchByDeliveryMonth= DeliveryYear.getValue();
	queryDeliveryMonthInSearchByDeliveryMonth= DeliveryMonth.getValue();

#ifdef COUNT_SEARCH
	multiFindByDeliveryMonthForInstrument++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CInstrument *theInstrument;
	compareObject.ProductGroupID=ProductGroupID.getValue();
	compareObject.DeliveryYear=DeliveryYear.getValue();
	compareObject.DeliveryMonth=DeliveryMonth.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByDeliveryMonth=pProductGroupIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByDeliveryMonth==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theInstrument=(CInstrument *)(pLastFoundInSearchByDeliveryMonth->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theInstrument->ProductGroupID.getValue(),ProductGroupID.getValue()))
	{
		pLastFoundInSearchByDeliveryMonth=NULL;
		return NULL;
	}
	if (compare(theInstrument->DeliveryYear.getValue(),DeliveryYear.getValue()))
	{
		pLastFoundInSearchByDeliveryMonth=NULL;
		return NULL;
	}
	if (compare(theInstrument->DeliveryMonth.getValue(),DeliveryMonth.getValue()))
	{
		pLastFoundInSearchByDeliveryMonth=NULL;
		return NULL;
	}

	///返回找到的结果
	return theInstrument;
}

CInstrument *CInstrumentFactory::findNextByDeliveryMonth(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByDeliveryMonth==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDeliveryMonthForInstrument++;
#endif
	CInstrument *theInstrument;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByDeliveryMonth=pProductGroupIDIndex->getNextNode(pLastFoundInSearchByDeliveryMonth);
	if (pLastFoundInSearchByDeliveryMonth==NULL)
	{
		return NULL;
	}

	theInstrument=(CInstrument *)(pLastFoundInSearchByDeliveryMonth->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theInstrument->ProductGroupID,queryProductGroupIDInSearchByDeliveryMonth))
	{
		pLastFoundInSearchByDeliveryMonth=NULL;
		return NULL;
	}
	if (compare(theInstrument->DeliveryYear,queryDeliveryYearInSearchByDeliveryMonth))
	{
		pLastFoundInSearchByDeliveryMonth=NULL;
		return NULL;
	}
	if (compare(theInstrument->DeliveryMonth,queryDeliveryMonthInSearchByDeliveryMonth))
	{
		pLastFoundInSearchByDeliveryMonth=NULL;
		return NULL;
	}

	///返回找到的结果
	return theInstrument;
}

void CInstrumentFactory::endFindByDeliveryMonth(void)
{
	pLastFoundInSearchByDeliveryMonth=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByRevDeliveryMonthForInstrument=0;
#endif

CInstrument *CInstrumentFactory::startFindByRevDeliveryMonth( const CReadOnlyProductGroupIDType& ProductGroupID,  const CReadOnlyYearType& DeliveryYear,  const CReadOnlyMonthType& DeliveryMonth)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByRevDeliveryMonth of CInstrument while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByRevDeliveryMonth!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByRevDeliveryMonth();
	}

	///记录所有的查询值
	queryProductGroupIDInSearchByRevDeliveryMonth= ProductGroupID.getValue();
	queryDeliveryYearInSearchByRevDeliveryMonth= DeliveryYear.getValue();
	queryDeliveryMonthInSearchByRevDeliveryMonth= DeliveryMonth.getValue();

#ifdef COUNT_SEARCH
	multiFindByRevDeliveryMonthForInstrument++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CInstrument *theInstrument;
	compareObject.ProductGroupID=ProductGroupID.getValue();
	compareObject.DeliveryYear=DeliveryYear.getValue();
	compareObject.DeliveryMonth=DeliveryMonth.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByRevDeliveryMonth=pProductGroupIDRevIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByRevDeliveryMonth==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theInstrument=(CInstrument *)(pLastFoundInSearchByRevDeliveryMonth->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theInstrument->ProductGroupID.getValue(),ProductGroupID.getValue()))
	{
		pLastFoundInSearchByRevDeliveryMonth=NULL;
		return NULL;
	}

	///返回找到的结果
	return theInstrument;
}

CInstrument *CInstrumentFactory::findNextByRevDeliveryMonth(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByRevDeliveryMonth==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByRevDeliveryMonthForInstrument++;
#endif
	CInstrument *theInstrument;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByRevDeliveryMonth=pProductGroupIDRevIndex->getNextNode(pLastFoundInSearchByRevDeliveryMonth);
	if (pLastFoundInSearchByRevDeliveryMonth==NULL)
	{
		return NULL;
	}

	theInstrument=(CInstrument *)(pLastFoundInSearchByRevDeliveryMonth->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theInstrument->ProductGroupID,queryProductGroupIDInSearchByRevDeliveryMonth))
	{
		pLastFoundInSearchByRevDeliveryMonth=NULL;
		return NULL;
	}

	///返回找到的结果
	return theInstrument;
}

void CInstrumentFactory::endFindByRevDeliveryMonth(void)
{
	pLastFoundInSearchByRevDeliveryMonth=NULL;
}

int compareForCombinationIndexinCombinationLeg(const void *pV1, const void *pV2)
{
	CCombinationLeg *p1,*p2;
	p1=(CCombinationLeg *)pV1;
	p2=(CCombinationLeg *)pV2;
	switch (compare(p1->CombInstrumentID.getValue(),p2->CombInstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->LegID.getValue(),p2->LegID.getValue()))
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
int compareForLegIndexinCombinationLeg(const void *pV1, const void *pV2)
{
	CCombinationLeg *p1,*p2;
	p1=(CCombinationLeg *)pV1;
	p2=(CCombinationLeg *)pV2;
	switch (compare(p1->LegInstrumentID.getValue(),p2->LegInstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->CombInstrumentID.getValue(),p2->CombInstrumentID.getValue()))
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
int multiFindByCombinationForCombinationLeg=0;
#endif

CCombinationLeg *CCombinationLegFactory::startFindByCombination( const CReadOnlyInstrumentIDType& CombInstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByCombination of CCombinationLeg while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByCombination!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByCombination();
	}

	///记录所有的查询值
	queryCombInstrumentIDInSearchByCombination= CombInstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindByCombinationForCombinationLeg++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CCombinationLeg *theCombinationLeg;
	compareObject.CombInstrumentID=CombInstrumentID.getValue();
	compareObject.LegID=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByCombination=pCombinationIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByCombination==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theCombinationLeg=(CCombinationLeg *)(pLastFoundInSearchByCombination->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theCombinationLeg->CombInstrumentID.getValue(),CombInstrumentID.getValue()))
	{
		pLastFoundInSearchByCombination=NULL;
		return NULL;
	}

	///返回找到的结果
	return theCombinationLeg;
}

CCombinationLeg *CCombinationLegFactory::findNextByCombination(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByCombination==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByCombinationForCombinationLeg++;
#endif
	CCombinationLeg *theCombinationLeg;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByCombination=pCombinationIndex->getNextNode(pLastFoundInSearchByCombination);
	if (pLastFoundInSearchByCombination==NULL)
	{
		return NULL;
	}

	theCombinationLeg=(CCombinationLeg *)(pLastFoundInSearchByCombination->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theCombinationLeg->CombInstrumentID,queryCombInstrumentIDInSearchByCombination))
	{
		pLastFoundInSearchByCombination=NULL;
		return NULL;
	}

	///返回找到的结果
	return theCombinationLeg;
}

void CCombinationLegFactory::endFindByCombination(void)
{
	pLastFoundInSearchByCombination=NULL;
}


#ifdef COUNT_SEARCH
int findByCombinationLegIDForCombinationLeg=0;
#endif
CCombinationLeg *CCombinationLegFactory::findByCombinationLegID( const CReadOnlyInstrumentIDType&  CombInstrumentID,  const CReadOnlyLegIDType&  LegID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByCombinationLegID of CCombinationLeg while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByCombinationLegIDForCombinationLeg++;
#endif
	CAVLNode *pNode;
	compareObject.CombInstrumentID=CombInstrumentID.getValue();
	compareObject.LegID=LegID.getValue();
	pNode=pCombinationIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CCombinationLeg *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByLegForCombinationLeg=0;
#endif

CCombinationLeg *CCombinationLegFactory::startFindByLeg( const CReadOnlyInstrumentIDType& LegInstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByLeg of CCombinationLeg while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByLeg!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByLeg();
	}

	///记录所有的查询值
	queryLegInstrumentIDInSearchByLeg= LegInstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindByLegForCombinationLeg++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CCombinationLeg *theCombinationLeg;
	compareObject.LegInstrumentID=LegInstrumentID.getValue();
	compareObject.CombInstrumentID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByLeg=pLegIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByLeg==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theCombinationLeg=(CCombinationLeg *)(pLastFoundInSearchByLeg->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theCombinationLeg->LegInstrumentID.getValue(),LegInstrumentID.getValue()))
	{
		pLastFoundInSearchByLeg=NULL;
		return NULL;
	}

	///返回找到的结果
	return theCombinationLeg;
}

CCombinationLeg *CCombinationLegFactory::findNextByLeg(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByLeg==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByLegForCombinationLeg++;
#endif
	CCombinationLeg *theCombinationLeg;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByLeg=pLegIndex->getNextNode(pLastFoundInSearchByLeg);
	if (pLastFoundInSearchByLeg==NULL)
	{
		return NULL;
	}

	theCombinationLeg=(CCombinationLeg *)(pLastFoundInSearchByLeg->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theCombinationLeg->LegInstrumentID,queryLegInstrumentIDInSearchByLeg))
	{
		pLastFoundInSearchByLeg=NULL;
		return NULL;
	}

	///返回找到的结果
	return theCombinationLeg;
}

void CCombinationLegFactory::endFindByLeg(void)
{
	pLastFoundInSearchByLeg=NULL;
}


#ifdef COUNT_SEARCH
int findByCombinationAndLegForCombinationLeg=0;
#endif
CCombinationLeg *CCombinationLegFactory::findByCombinationAndLeg( const CReadOnlyInstrumentIDType&  CombInstrumentID,  const CReadOnlyInstrumentIDType&  LegInstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByCombinationAndLeg of CCombinationLeg while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByCombinationAndLegForCombinationLeg++;
#endif
	CAVLNode *pNode;
	compareObject.CombInstrumentID=CombInstrumentID.getValue();
	compareObject.LegInstrumentID=LegInstrumentID.getValue();
	pNode=pLegIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CCombinationLeg *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForCombinationLeg=0;
#endif

CCombinationLeg *CCombinationLegFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCombinationLeg while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCombinationLeg *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCombinationLeg *CCombinationLegFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCombinationLeg *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCombinationLegFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}

int compareForPartRoleAndSGIndexinPartRoleAccount(const void *pV1, const void *pV2)
{
	CPartRoleAccount *p1,*p2;
	p1=(CPartRoleAccount *)pV1;
	p2=(CPartRoleAccount *)pV2;
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
	switch (compare(p1->SettlementGroupID.getValue(),p2->SettlementGroupID.getValue()))
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
int findByPartRoleAndSGForPartRoleAccount=0;
#endif
CPartRoleAccount *CPartRoleAccountFactory::findByPartRoleAndSG( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTradingRoleType&  TradingRole,  const CReadOnlySettlementGroupIDType&  SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByPartRoleAndSG of CPartRoleAccount while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.TradingRole=TradingRole.getValue();
	compareObject.SettlementGroupID=SettlementGroupID.getValue();
	
	compareObject.calHashPartRoleAndSG();
	for (pNode=pPartRoleAndSGHashIndex->searchFirstEqual(compareObject.HashPartRoleAndSG);
		pNode!=NULL;
		pNode=pPartRoleAndSGHashIndex->searchNextEqual(pNode))
	{
		if (((CPartRoleAccount *)(pNode->pObject))->HashPartRoleAndSG != compareObject.HashPartRoleAndSG)
		{
			continue;
		}
		if (compare(((CPartRoleAccount *)(pNode->pObject))->ParticipantID.getValue(),ParticipantID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CPartRoleAccount *)(pNode->pObject))->TradingRole.getValue(),TradingRole.getValue())!=0)
		{
			continue;
		}
		if (compare(((CPartRoleAccount *)(pNode->pObject))->SettlementGroupID.getValue(),SettlementGroupID.getValue())!=0)
		{
			continue;
		}
		return (CPartRoleAccount *)(pNode->pObject);
	}
	return NULL;
}



#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForPartRoleAccount=0;
#endif

CPartRoleAccount *CPartRoleAccountFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CPartRoleAccount while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CPartRoleAccount *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CPartRoleAccount *CPartRoleAccountFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CPartRoleAccount *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CPartRoleAccountFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindStartByParticipantIDForPartRoleAccount=0;
#endif

CPartRoleAccount *CPartRoleAccountFactory::startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByParticipantID of CPartRoleAccount while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByParticipantID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByParticipantID();
	}

	///记录所有的查询值
	queryParticipantIDInSearchStartByParticipantID= ParticipantID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForPartRoleAccount++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CPartRoleAccount *thePartRoleAccount;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.TradingRole="";
	compareObject.SettlementGroupID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByParticipantID=pPartRoleAndSGIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	thePartRoleAccount=(CPartRoleAccount *)(pLastFoundInSearchStartByParticipantID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return thePartRoleAccount;
}

CPartRoleAccount *CPartRoleAccountFactory::findNextStartByParticipantID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForPartRoleAccount++;
#endif
	CPartRoleAccount *thePartRoleAccount;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByParticipantID=pPartRoleAndSGIndex->getNextNode(pLastFoundInSearchStartByParticipantID);
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

	thePartRoleAccount=(CPartRoleAccount *)(pLastFoundInSearchStartByParticipantID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return thePartRoleAccount;
}

void CPartRoleAccountFactory::endFindStartByParticipantID(void)
{
	pLastFoundInSearchStartByParticipantID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForPartProductRole=0;
#endif

CPartProductRole *CPartProductRoleFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CPartProductRole while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CPartProductRole *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CPartProductRole *CPartProductRoleFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CPartProductRole *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CPartProductRoleFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByParticipantProductRoleForPartProductRole=0;
#endif
CPartProductRole *CPartProductRoleFactory::findByParticipantProductRole( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyProductIDType&  ProductID,  const CReadOnlyTradingRoleType&  TradingRole)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByParticipantProductRole of CPartProductRole while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.ProductID=ProductID.getValue();
	compareObject.TradingRole=TradingRole.getValue();
	
	compareObject.calHashParticipantProductRole();
	for (pNode=pParticipantProductRoleHashIndex->searchFirstEqual(compareObject.HashParticipantProductRole);
		pNode!=NULL;
		pNode=pParticipantProductRoleHashIndex->searchNextEqual(pNode))
	{
		if (((CPartProductRole *)(pNode->pObject))->HashParticipantProductRole != compareObject.HashParticipantProductRole)
		{
			continue;
		}
		if (compare(((CPartProductRole *)(pNode->pObject))->ParticipantID.getValue(),ParticipantID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CPartProductRole *)(pNode->pObject))->ProductID.getValue(),ProductID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CPartProductRole *)(pNode->pObject))->TradingRole.getValue(),TradingRole.getValue())!=0)
		{
			continue;
		}
		return (CPartProductRole *)(pNode->pObject);
	}
	return NULL;
}



#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForPartProductRight=0;
#endif

CPartProductRight *CPartProductRightFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CPartProductRight while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CPartProductRight *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CPartProductRight *CPartProductRightFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CPartProductRight *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CPartProductRightFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByParticipantAndProductForPartProductRight=0;
#endif
CPartProductRight *CPartProductRightFactory::findByParticipantAndProduct( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyProductIDType&  ProductID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByParticipantAndProduct of CPartProductRight while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.ProductID=ProductID.getValue();
	
	compareObject.calHashParticipantAndProduct();
	for (pNode=pParticipantAndProductHashIndex->searchFirstEqual(compareObject.HashParticipantAndProduct);
		pNode!=NULL;
		pNode=pParticipantAndProductHashIndex->searchNextEqual(pNode))
	{
		if (((CPartProductRight *)(pNode->pObject))->HashParticipantAndProduct != compareObject.HashParticipantAndProduct)
		{
			continue;
		}
		if (compare(((CPartProductRight *)(pNode->pObject))->ParticipantID.getValue(),ParticipantID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CPartProductRight *)(pNode->pObject))->ProductID.getValue(),ProductID.getValue())!=0)
		{
			continue;
		}
		return (CPartProductRight *)(pNode->pObject);
	}
	return NULL;
}

CPartProductRight *CPartProductRightFactory::findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyProductIDType&  ProductID)
{
	return findByParticipantAndProduct(ParticipantID, ProductID);
}
	
CPartProductRight *CPartProductRightFactory::findByPK(CWriteablePartProductRight *pPartProductRight)
{
	return findByPK(
		pPartProductRight->ParticipantID
		,
		pPartProductRight->ProductID
		);
}

bool CPartProductRightFactory::retrieveByPK(CWriteablePartProductRight *pPartProductRight)
{
	CPartProductRight *pOriginalPartProductRight;
	pOriginalPartProductRight=findByPK(pPartProductRight);
	if (pOriginalPartProductRight==NULL)
	{
		return false;
	}
	retrieve(pOriginalPartProductRight,pPartProductRight);
	return true;
}

CPartProductRight *CPartProductRightFactory::addByPK(CWriteablePartProductRight *pPartProductRight, CTransaction *pTransaction)
{
	CPartProductRight *pOriginalPartProductRight;
	pOriginalPartProductRight=findByPK(pPartProductRight);
	if (pOriginalPartProductRight != NULL)
	{
		return NULL;
	}
	return add(pPartProductRight,pTransaction);
}

bool CPartProductRightFactory::updateByPK(CWriteablePartProductRight *pPartProductRight, CTransaction *pTransaction, bool updateIndex)
{
	CPartProductRight *pOriginalPartProductRight;
	pOriginalPartProductRight=findByPK(pPartProductRight);
	if (pOriginalPartProductRight==NULL)
	{
		return false;
	}
	pPartProductRight->calAllHash();
	update(pOriginalPartProductRight,pPartProductRight,pTransaction,updateIndex);
	return true;
}

bool CPartProductRightFactory::removeByPK(CWriteablePartProductRight *pPartProductRight, CTransaction *pTransaction)
{
	CPartProductRight *pOriginalPartProductRight;
	pOriginalPartProductRight=findByPK(pPartProductRight);
	if (pOriginalPartProductRight==NULL)
	{
		return false;
	}
	remove(pOriginalPartProductRight,pTransaction);
	return true;
}



#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForPartInstrumentRight=0;
#endif

CPartInstrumentRight *CPartInstrumentRightFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CPartInstrumentRight while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CPartInstrumentRight *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CPartInstrumentRight *CPartInstrumentRightFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CPartInstrumentRight *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CPartInstrumentRightFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByParticipantAndInstrumentForPartInstrumentRight=0;
#endif
CPartInstrumentRight *CPartInstrumentRightFactory::findByParticipantAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByParticipantAndInstrument of CPartInstrumentRight while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.InstrumentID=InstrumentID.getValue();
	
	compareObject.calHashParticipantAndInstrument();
	for (pNode=pParticipantAndInstrumentHashIndex->searchFirstEqual(compareObject.HashParticipantAndInstrument);
		pNode!=NULL;
		pNode=pParticipantAndInstrumentHashIndex->searchNextEqual(pNode))
	{
		if (((CPartInstrumentRight *)(pNode->pObject))->HashParticipantAndInstrument != compareObject.HashParticipantAndInstrument)
		{
			continue;
		}
		if (compare(((CPartInstrumentRight *)(pNode->pObject))->ParticipantID.getValue(),ParticipantID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CPartInstrumentRight *)(pNode->pObject))->InstrumentID.getValue(),InstrumentID.getValue())!=0)
		{
			continue;
		}
		return (CPartInstrumentRight *)(pNode->pObject);
	}
	return NULL;
}

CPartInstrumentRight *CPartInstrumentRightFactory::findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyInstrumentIDType&  InstrumentID)
{
	return findByParticipantAndInstrument(ParticipantID, InstrumentID);
}
	
CPartInstrumentRight *CPartInstrumentRightFactory::findByPK(CWriteablePartInstrumentRight *pPartInstrumentRight)
{
	return findByPK(
		pPartInstrumentRight->ParticipantID
		,
		pPartInstrumentRight->InstrumentID
		);
}

bool CPartInstrumentRightFactory::retrieveByPK(CWriteablePartInstrumentRight *pPartInstrumentRight)
{
	CPartInstrumentRight *pOriginalPartInstrumentRight;
	pOriginalPartInstrumentRight=findByPK(pPartInstrumentRight);
	if (pOriginalPartInstrumentRight==NULL)
	{
		return false;
	}
	retrieve(pOriginalPartInstrumentRight,pPartInstrumentRight);
	return true;
}

CPartInstrumentRight *CPartInstrumentRightFactory::addByPK(CWriteablePartInstrumentRight *pPartInstrumentRight, CTransaction *pTransaction)
{
	CPartInstrumentRight *pOriginalPartInstrumentRight;
	pOriginalPartInstrumentRight=findByPK(pPartInstrumentRight);
	if (pOriginalPartInstrumentRight != NULL)
	{
		return NULL;
	}
	return add(pPartInstrumentRight,pTransaction);
}

bool CPartInstrumentRightFactory::updateByPK(CWriteablePartInstrumentRight *pPartInstrumentRight, CTransaction *pTransaction, bool updateIndex)
{
	CPartInstrumentRight *pOriginalPartInstrumentRight;
	pOriginalPartInstrumentRight=findByPK(pPartInstrumentRight);
	if (pOriginalPartInstrumentRight==NULL)
	{
		return false;
	}
	pPartInstrumentRight->calAllHash();
	update(pOriginalPartInstrumentRight,pPartInstrumentRight,pTransaction,updateIndex);
	return true;
}

bool CPartInstrumentRightFactory::removeByPK(CWriteablePartInstrumentRight *pPartInstrumentRight, CTransaction *pTransaction)
{
	CPartInstrumentRight *pOriginalPartInstrumentRight;
	pOriginalPartInstrumentRight=findByPK(pPartInstrumentRight);
	if (pOriginalPartInstrumentRight==NULL)
	{
		return false;
	}
	remove(pOriginalPartInstrumentRight,pTransaction);
	return true;
}



#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForClientProductRight=0;
#endif

CClientProductRight *CClientProductRightFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CClientProductRight while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CClientProductRight *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CClientProductRight *CClientProductRightFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CClientProductRight *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CClientProductRightFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByClientAndProductForClientProductRight=0;
#endif
CClientProductRight *CClientProductRightFactory::findByClientAndProduct( const CReadOnlyClientIDType&  ClientID,  const CReadOnlyProductIDType&  ProductID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByClientAndProduct of CClientProductRight while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.ClientID=ClientID.getValue();
	compareObject.ProductID=ProductID.getValue();
	
	compareObject.calHashClientAndProduct();
	for (pNode=pClientAndProductHashIndex->searchFirstEqual(compareObject.HashClientAndProduct);
		pNode!=NULL;
		pNode=pClientAndProductHashIndex->searchNextEqual(pNode))
	{
		if (((CClientProductRight *)(pNode->pObject))->HashClientAndProduct != compareObject.HashClientAndProduct)
		{
			continue;
		}
		if (compare(((CClientProductRight *)(pNode->pObject))->ClientID.getValue(),ClientID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CClientProductRight *)(pNode->pObject))->ProductID.getValue(),ProductID.getValue())!=0)
		{
			continue;
		}
		return (CClientProductRight *)(pNode->pObject);
	}
	return NULL;
}

CClientProductRight *CClientProductRightFactory::findByPK( const CReadOnlyClientIDType&  ClientID,  const CReadOnlyProductIDType&  ProductID)
{
	return findByClientAndProduct(ClientID, ProductID);
}
	
CClientProductRight *CClientProductRightFactory::findByPK(CWriteableClientProductRight *pClientProductRight)
{
	return findByPK(
		pClientProductRight->ClientID
		,
		pClientProductRight->ProductID
		);
}

bool CClientProductRightFactory::retrieveByPK(CWriteableClientProductRight *pClientProductRight)
{
	CClientProductRight *pOriginalClientProductRight;
	pOriginalClientProductRight=findByPK(pClientProductRight);
	if (pOriginalClientProductRight==NULL)
	{
		return false;
	}
	retrieve(pOriginalClientProductRight,pClientProductRight);
	return true;
}

CClientProductRight *CClientProductRightFactory::addByPK(CWriteableClientProductRight *pClientProductRight, CTransaction *pTransaction)
{
	CClientProductRight *pOriginalClientProductRight;
	pOriginalClientProductRight=findByPK(pClientProductRight);
	if (pOriginalClientProductRight != NULL)
	{
		return NULL;
	}
	return add(pClientProductRight,pTransaction);
}

bool CClientProductRightFactory::updateByPK(CWriteableClientProductRight *pClientProductRight, CTransaction *pTransaction, bool updateIndex)
{
	CClientProductRight *pOriginalClientProductRight;
	pOriginalClientProductRight=findByPK(pClientProductRight);
	if (pOriginalClientProductRight==NULL)
	{
		return false;
	}
	pClientProductRight->calAllHash();
	update(pOriginalClientProductRight,pClientProductRight,pTransaction,updateIndex);
	return true;
}

bool CClientProductRightFactory::removeByPK(CWriteableClientProductRight *pClientProductRight, CTransaction *pTransaction)
{
	CClientProductRight *pOriginalClientProductRight;
	pOriginalClientProductRight=findByPK(pClientProductRight);
	if (pOriginalClientProductRight==NULL)
	{
		return false;
	}
	remove(pOriginalClientProductRight,pTransaction);
	return true;
}



#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForClientInstrumentRight=0;
#endif

CClientInstrumentRight *CClientInstrumentRightFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CClientInstrumentRight while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CClientInstrumentRight *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CClientInstrumentRight *CClientInstrumentRightFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CClientInstrumentRight *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CClientInstrumentRightFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByClientAndInstrumentForClientInstrumentRight=0;
#endif
CClientInstrumentRight *CClientInstrumentRightFactory::findByClientAndInstrument( const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByClientAndInstrument of CClientInstrumentRight while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.ClientID=ClientID.getValue();
	compareObject.InstrumentID=InstrumentID.getValue();
	
	compareObject.calHashClientAndInstrument();
	for (pNode=pClientAndInstrumentHashIndex->searchFirstEqual(compareObject.HashClientAndInstrument);
		pNode!=NULL;
		pNode=pClientAndInstrumentHashIndex->searchNextEqual(pNode))
	{
		if (((CClientInstrumentRight *)(pNode->pObject))->HashClientAndInstrument != compareObject.HashClientAndInstrument)
		{
			continue;
		}
		if (compare(((CClientInstrumentRight *)(pNode->pObject))->ClientID.getValue(),ClientID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CClientInstrumentRight *)(pNode->pObject))->InstrumentID.getValue(),InstrumentID.getValue())!=0)
		{
			continue;
		}
		return (CClientInstrumentRight *)(pNode->pObject);
	}
	return NULL;
}

CClientInstrumentRight *CClientInstrumentRightFactory::findByPK( const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID)
{
	return findByClientAndInstrument(ClientID, InstrumentID);
}
	
CClientInstrumentRight *CClientInstrumentRightFactory::findByPK(CWriteableClientInstrumentRight *pClientInstrumentRight)
{
	return findByPK(
		pClientInstrumentRight->ClientID
		,
		pClientInstrumentRight->InstrumentID
		);
}

bool CClientInstrumentRightFactory::retrieveByPK(CWriteableClientInstrumentRight *pClientInstrumentRight)
{
	CClientInstrumentRight *pOriginalClientInstrumentRight;
	pOriginalClientInstrumentRight=findByPK(pClientInstrumentRight);
	if (pOriginalClientInstrumentRight==NULL)
	{
		return false;
	}
	retrieve(pOriginalClientInstrumentRight,pClientInstrumentRight);
	return true;
}

CClientInstrumentRight *CClientInstrumentRightFactory::addByPK(CWriteableClientInstrumentRight *pClientInstrumentRight, CTransaction *pTransaction)
{
	CClientInstrumentRight *pOriginalClientInstrumentRight;
	pOriginalClientInstrumentRight=findByPK(pClientInstrumentRight);
	if (pOriginalClientInstrumentRight != NULL)
	{
		return NULL;
	}
	return add(pClientInstrumentRight,pTransaction);
}

bool CClientInstrumentRightFactory::updateByPK(CWriteableClientInstrumentRight *pClientInstrumentRight, CTransaction *pTransaction, bool updateIndex)
{
	CClientInstrumentRight *pOriginalClientInstrumentRight;
	pOriginalClientInstrumentRight=findByPK(pClientInstrumentRight);
	if (pOriginalClientInstrumentRight==NULL)
	{
		return false;
	}
	pClientInstrumentRight->calAllHash();
	update(pOriginalClientInstrumentRight,pClientInstrumentRight,pTransaction,updateIndex);
	return true;
}

bool CClientInstrumentRightFactory::removeByPK(CWriteableClientInstrumentRight *pClientInstrumentRight, CTransaction *pTransaction)
{
	CClientInstrumentRight *pOriginalClientInstrumentRight;
	pOriginalClientInstrumentRight=findByPK(pClientInstrumentRight);
	if (pOriginalClientInstrumentRight==NULL)
	{
		return false;
	}
	remove(pOriginalClientInstrumentRight,pTransaction);
	return true;
}



#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForPartClientProductRight=0;
#endif

CPartClientProductRight *CPartClientProductRightFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CPartClientProductRight while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CPartClientProductRight *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CPartClientProductRight *CPartClientProductRightFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CPartClientProductRight *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CPartClientProductRightFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByParticipantAndClientAndProductForPartClientProductRight=0;
#endif
CPartClientProductRight *CPartClientProductRightFactory::findByParticipantAndClientAndProduct( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyProductIDType&  ProductID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByParticipantAndClientAndProduct of CPartClientProductRight while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.ClientID=ClientID.getValue();
	compareObject.ProductID=ProductID.getValue();
	
	compareObject.calHashParticipantAndClientAndProduct();
	for (pNode=pParticipantAndClientAndProductHashIndex->searchFirstEqual(compareObject.HashParticipantAndClientAndProduct);
		pNode!=NULL;
		pNode=pParticipantAndClientAndProductHashIndex->searchNextEqual(pNode))
	{
		if (((CPartClientProductRight *)(pNode->pObject))->HashParticipantAndClientAndProduct != compareObject.HashParticipantAndClientAndProduct)
		{
			continue;
		}
		if (compare(((CPartClientProductRight *)(pNode->pObject))->ParticipantID.getValue(),ParticipantID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CPartClientProductRight *)(pNode->pObject))->ClientID.getValue(),ClientID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CPartClientProductRight *)(pNode->pObject))->ProductID.getValue(),ProductID.getValue())!=0)
		{
			continue;
		}
		return (CPartClientProductRight *)(pNode->pObject);
	}
	return NULL;
}

CPartClientProductRight *CPartClientProductRightFactory::findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyProductIDType&  ProductID)
{
	return findByParticipantAndClientAndProduct(ParticipantID, ClientID, ProductID);
}
	
CPartClientProductRight *CPartClientProductRightFactory::findByPK(CWriteablePartClientProductRight *pPartClientProductRight)
{
	return findByPK(
		pPartClientProductRight->ParticipantID
		,
		pPartClientProductRight->ClientID
		,
		pPartClientProductRight->ProductID
		);
}

bool CPartClientProductRightFactory::retrieveByPK(CWriteablePartClientProductRight *pPartClientProductRight)
{
	CPartClientProductRight *pOriginalPartClientProductRight;
	pOriginalPartClientProductRight=findByPK(pPartClientProductRight);
	if (pOriginalPartClientProductRight==NULL)
	{
		return false;
	}
	retrieve(pOriginalPartClientProductRight,pPartClientProductRight);
	return true;
}

CPartClientProductRight *CPartClientProductRightFactory::addByPK(CWriteablePartClientProductRight *pPartClientProductRight, CTransaction *pTransaction)
{
	CPartClientProductRight *pOriginalPartClientProductRight;
	pOriginalPartClientProductRight=findByPK(pPartClientProductRight);
	if (pOriginalPartClientProductRight != NULL)
	{
		return NULL;
	}
	return add(pPartClientProductRight,pTransaction);
}

bool CPartClientProductRightFactory::updateByPK(CWriteablePartClientProductRight *pPartClientProductRight, CTransaction *pTransaction, bool updateIndex)
{
	CPartClientProductRight *pOriginalPartClientProductRight;
	pOriginalPartClientProductRight=findByPK(pPartClientProductRight);
	if (pOriginalPartClientProductRight==NULL)
	{
		return false;
	}
	pPartClientProductRight->calAllHash();
	update(pOriginalPartClientProductRight,pPartClientProductRight,pTransaction,updateIndex);
	return true;
}

bool CPartClientProductRightFactory::removeByPK(CWriteablePartClientProductRight *pPartClientProductRight, CTransaction *pTransaction)
{
	CPartClientProductRight *pOriginalPartClientProductRight;
	pOriginalPartClientProductRight=findByPK(pPartClientProductRight);
	if (pOriginalPartClientProductRight==NULL)
	{
		return false;
	}
	remove(pOriginalPartClientProductRight,pTransaction);
	return true;
}



#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForPartClientInstrumentRight=0;
#endif

CPartClientInstrumentRight *CPartClientInstrumentRightFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CPartClientInstrumentRight while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CPartClientInstrumentRight *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CPartClientInstrumentRight *CPartClientInstrumentRightFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CPartClientInstrumentRight *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CPartClientInstrumentRightFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByParticipantAndClientAndInstrumentForPartClientInstrumentRight=0;
#endif
CPartClientInstrumentRight *CPartClientInstrumentRightFactory::findByParticipantAndClientAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByParticipantAndClientAndInstrument of CPartClientInstrumentRight while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.ClientID=ClientID.getValue();
	compareObject.InstrumentID=InstrumentID.getValue();
	
	compareObject.calHashParticipantAndClientAndInstrument();
	for (pNode=pParticipantAndClientAndInstrumentHashIndex->searchFirstEqual(compareObject.HashParticipantAndClientAndInstrument);
		pNode!=NULL;
		pNode=pParticipantAndClientAndInstrumentHashIndex->searchNextEqual(pNode))
	{
		if (((CPartClientInstrumentRight *)(pNode->pObject))->HashParticipantAndClientAndInstrument != compareObject.HashParticipantAndClientAndInstrument)
		{
			continue;
		}
		if (compare(((CPartClientInstrumentRight *)(pNode->pObject))->ParticipantID.getValue(),ParticipantID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CPartClientInstrumentRight *)(pNode->pObject))->ClientID.getValue(),ClientID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CPartClientInstrumentRight *)(pNode->pObject))->InstrumentID.getValue(),InstrumentID.getValue())!=0)
		{
			continue;
		}
		return (CPartClientInstrumentRight *)(pNode->pObject);
	}
	return NULL;
}

CPartClientInstrumentRight *CPartClientInstrumentRightFactory::findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID)
{
	return findByParticipantAndClientAndInstrument(ParticipantID, ClientID, InstrumentID);
}
	
CPartClientInstrumentRight *CPartClientInstrumentRightFactory::findByPK(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight)
{
	return findByPK(
		pPartClientInstrumentRight->ParticipantID
		,
		pPartClientInstrumentRight->ClientID
		,
		pPartClientInstrumentRight->InstrumentID
		);
}

bool CPartClientInstrumentRightFactory::retrieveByPK(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight)
{
	CPartClientInstrumentRight *pOriginalPartClientInstrumentRight;
	pOriginalPartClientInstrumentRight=findByPK(pPartClientInstrumentRight);
	if (pOriginalPartClientInstrumentRight==NULL)
	{
		return false;
	}
	retrieve(pOriginalPartClientInstrumentRight,pPartClientInstrumentRight);
	return true;
}

CPartClientInstrumentRight *CPartClientInstrumentRightFactory::addByPK(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight, CTransaction *pTransaction)
{
	CPartClientInstrumentRight *pOriginalPartClientInstrumentRight;
	pOriginalPartClientInstrumentRight=findByPK(pPartClientInstrumentRight);
	if (pOriginalPartClientInstrumentRight != NULL)
	{
		return NULL;
	}
	return add(pPartClientInstrumentRight,pTransaction);
}

bool CPartClientInstrumentRightFactory::updateByPK(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight, CTransaction *pTransaction, bool updateIndex)
{
	CPartClientInstrumentRight *pOriginalPartClientInstrumentRight;
	pOriginalPartClientInstrumentRight=findByPK(pPartClientInstrumentRight);
	if (pOriginalPartClientInstrumentRight==NULL)
	{
		return false;
	}
	pPartClientInstrumentRight->calAllHash();
	update(pOriginalPartClientInstrumentRight,pPartClientInstrumentRight,pTransaction,updateIndex);
	return true;
}

bool CPartClientInstrumentRightFactory::removeByPK(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight, CTransaction *pTransaction)
{
	CPartClientInstrumentRight *pOriginalPartClientInstrumentRight;
	pOriginalPartClientInstrumentRight=findByPK(pPartClientInstrumentRight);
	if (pOriginalPartClientInstrumentRight==NULL)
	{
		return false;
	}
	remove(pOriginalPartClientInstrumentRight,pTransaction);
	return true;
}


int compareForProductIDIndexinCurrProductProperty(const void *pV1, const void *pV2)
{
	CCurrProductProperty *p1,*p2;
	p1=(CCurrProductProperty *)pV1;
	p2=(CCurrProductProperty *)pV2;
	switch (compare(p1->ProductID.getValue(),p2->ProductID.getValue()))
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
int multiFindBySettlementGroupIDForCurrProductProperty=0;
#endif

CCurrProductProperty *CCurrProductPropertyFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCurrProductProperty while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCurrProductProperty *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCurrProductProperty *CCurrProductPropertyFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCurrProductProperty *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCurrProductPropertyFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByProductIDForCurrProductProperty=0;
#endif
CCurrProductProperty *CCurrProductPropertyFactory::findByProductID( const CReadOnlyProductIDType&  ProductID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByProductID of CCurrProductProperty while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByProductIDForCurrProductProperty++;
#endif
	CAVLNode *pNode;
	compareObject.ProductID=ProductID.getValue();
	pNode=pProductIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CCurrProductProperty *)(pNode->pObject);
}


int compareForInstrumentIDIndexinCurrInstrumentProperty(const void *pV1, const void *pV2)
{
	CCurrInstrumentProperty *p1,*p2;
	p1=(CCurrInstrumentProperty *)pV1;
	p2=(CCurrInstrumentProperty *)pV2;
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
int multiFindBySettlementGroupIDForCurrInstrumentProperty=0;
#endif

CCurrInstrumentProperty *CCurrInstrumentPropertyFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCurrInstrumentProperty while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCurrInstrumentProperty *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCurrInstrumentProperty *CCurrInstrumentPropertyFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCurrInstrumentProperty *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCurrInstrumentPropertyFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentIDForCurrInstrumentProperty=0;
#endif
CCurrInstrumentProperty *CCurrInstrumentPropertyFactory::findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentID of CCurrInstrumentProperty while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentIDForCurrInstrumentProperty++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CCurrInstrumentProperty *)(pNode->pObject);
}


int compareForInstrumentAndSegmentIndexinCurrPriceBanding(const void *pV1, const void *pV2)
{
	CCurrPriceBanding *p1,*p2;
	p1=(CCurrPriceBanding *)pV1;
	p2=(CCurrPriceBanding *)pV2;
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
	switch (compare(p1->TradingSegmentSN.getValue(),p2->TradingSegmentSN.getValue()))
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
int multiFindBySettlementGroupIDForCurrPriceBanding=0;
#endif

CCurrPriceBanding *CCurrPriceBandingFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCurrPriceBanding while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCurrPriceBanding *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCurrPriceBanding *CCurrPriceBandingFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCurrPriceBanding *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCurrPriceBandingFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentAndSegmentForCurrPriceBanding=0;
#endif
CCurrPriceBanding *CCurrPriceBandingFactory::findByInstrumentAndSegment( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyTradingSegmentSNType&  TradingSegmentSN)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentAndSegment of CCurrPriceBanding while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentAndSegmentForCurrPriceBanding++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.TradingSegmentSN=TradingSegmentSN.getValue();
	pNode=pInstrumentAndSegmentIndex->searchFirstGreatEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	if (compare(((CCurrPriceBanding *)(pNode->pObject))->InstrumentID.getValue(),InstrumentID.getValue())!=0)
	{
		return NULL;
	}
	return (CCurrPriceBanding *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int findByInstrumentAndOneSegmentForCurrPriceBanding=0;
#endif
CCurrPriceBanding *CCurrPriceBandingFactory::findByInstrumentAndOneSegment( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyTradingSegmentSNType&  TradingSegmentSN)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentAndOneSegment of CCurrPriceBanding while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentAndOneSegmentForCurrPriceBanding++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.TradingSegmentSN=TradingSegmentSN.getValue();
	pNode=pInstrumentAndSegmentIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CCurrPriceBanding *)(pNode->pObject);
}

CCurrPriceBanding *CCurrPriceBandingFactory::findByPK( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyTradingSegmentSNType&  TradingSegmentSN)
{
	return findByInstrumentAndOneSegment(InstrumentID, TradingSegmentSN);
}
	
CCurrPriceBanding *CCurrPriceBandingFactory::findByPK(CWriteableCurrPriceBanding *pCurrPriceBanding)
{
	return findByPK(
		pCurrPriceBanding->InstrumentID
		,
		pCurrPriceBanding->TradingSegmentSN
		);
}

bool CCurrPriceBandingFactory::retrieveByPK(CWriteableCurrPriceBanding *pCurrPriceBanding)
{
	CCurrPriceBanding *pOriginalCurrPriceBanding;
	pOriginalCurrPriceBanding=findByPK(pCurrPriceBanding);
	if (pOriginalCurrPriceBanding==NULL)
	{
		return false;
	}
	retrieve(pOriginalCurrPriceBanding,pCurrPriceBanding);
	return true;
}

CCurrPriceBanding *CCurrPriceBandingFactory::addByPK(CWriteableCurrPriceBanding *pCurrPriceBanding, CTransaction *pTransaction)
{
	CCurrPriceBanding *pOriginalCurrPriceBanding;
	pOriginalCurrPriceBanding=findByPK(pCurrPriceBanding);
	if (pOriginalCurrPriceBanding != NULL)
	{
		return NULL;
	}
	return add(pCurrPriceBanding,pTransaction);
}

bool CCurrPriceBandingFactory::updateByPK(CWriteableCurrPriceBanding *pCurrPriceBanding, CTransaction *pTransaction, bool updateIndex)
{
	CCurrPriceBanding *pOriginalCurrPriceBanding;
	pOriginalCurrPriceBanding=findByPK(pCurrPriceBanding);
	if (pOriginalCurrPriceBanding==NULL)
	{
		return false;
	}
	pCurrPriceBanding->calAllHash();
	update(pOriginalCurrPriceBanding,pCurrPriceBanding,pTransaction,updateIndex);
	return true;
}

bool CCurrPriceBandingFactory::removeByPK(CWriteableCurrPriceBanding *pCurrPriceBanding, CTransaction *pTransaction)
{
	CCurrPriceBanding *pOriginalCurrPriceBanding;
	pOriginalCurrPriceBanding=findByPK(pCurrPriceBanding);
	if (pOriginalCurrPriceBanding==NULL)
	{
		return false;
	}
	remove(pOriginalCurrPriceBanding,pTransaction);
	return true;
}



#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForCurrMarginRate=0;
#endif

CCurrMarginRate *CCurrMarginRateFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCurrMarginRate while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCurrMarginRate *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCurrMarginRate *CCurrMarginRateFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCurrMarginRate *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCurrMarginRateFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentAndPartForCurrMarginRate=0;
#endif
CCurrMarginRate *CCurrMarginRateFactory::findByInstrumentAndPart( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentAndPart of CCurrMarginRate while run level < 0");
	}
	CCurrMarginRate *theCurrMarginRate;
	for (theCurrMarginRate=(CCurrMarginRate *)(pMem->getFirst());
		theCurrMarginRate!=NULL;
		theCurrMarginRate=(CCurrMarginRate *)(pMem->getNext()))
	{
		if (compare(theCurrMarginRate->InstrumentID.getValue(),InstrumentID.getValue())!=0)
		{
			continue;
		}
		if (compare(theCurrMarginRate->ParticipantID.getValue(),ParticipantID.getValue())!=0)
		{
			continue;
		}
		return theCurrMarginRate;
	}
	return NULL;
}



#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForCurrMarginRateDetail=0;
#endif

CCurrMarginRateDetail *CCurrMarginRateDetailFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCurrMarginRateDetail while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCurrMarginRateDetail *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCurrMarginRateDetail *CCurrMarginRateDetailFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCurrMarginRateDetail *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCurrMarginRateDetailFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentAndParticipantForCurrMarginRateDetail=0;
#endif
CCurrMarginRateDetail *CCurrMarginRateDetailFactory::findByInstrumentAndParticipant( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTradingRoleType&  TradingRole,  const CReadOnlyHedgeFlagType&  HedgeFlag)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentAndParticipant of CCurrMarginRateDetail while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.TradingRole=TradingRole.getValue();
	compareObject.HedgeFlag=HedgeFlag.getValue();
	
	compareObject.calHashInstrumentAndParticipant();
	for (pNode=pInstrumentAndParticipantHashIndex->searchFirstEqual(compareObject.HashInstrumentAndParticipant);
		pNode!=NULL;
		pNode=pInstrumentAndParticipantHashIndex->searchNextEqual(pNode))
	{
		if (((CCurrMarginRateDetail *)(pNode->pObject))->HashInstrumentAndParticipant != compareObject.HashInstrumentAndParticipant)
		{
			continue;
		}
		if (compare(((CCurrMarginRateDetail *)(pNode->pObject))->InstrumentID.getValue(),InstrumentID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CCurrMarginRateDetail *)(pNode->pObject))->ParticipantID.getValue(),ParticipantID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CCurrMarginRateDetail *)(pNode->pObject))->TradingRole.getValue(),TradingRole.getValue())!=0)
		{
			continue;
		}
		if (compare(((CCurrMarginRateDetail *)(pNode->pObject))->HedgeFlag.getValue(),HedgeFlag.getValue())!=0)
		{
			continue;
		}
		return (CCurrMarginRateDetail *)(pNode->pObject);
	}
	return NULL;
}

CCurrMarginRateDetail *CCurrMarginRateDetailFactory::findByPK( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTradingRoleType&  TradingRole,  const CReadOnlyHedgeFlagType&  HedgeFlag)
{
	return findByInstrumentAndParticipant(InstrumentID, ParticipantID, TradingRole, HedgeFlag);
}
	
CCurrMarginRateDetail *CCurrMarginRateDetailFactory::findByPK(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail)
{
	return findByPK(
		pCurrMarginRateDetail->InstrumentID
		,
		pCurrMarginRateDetail->ParticipantID
		,
		pCurrMarginRateDetail->TradingRole
		,
		pCurrMarginRateDetail->HedgeFlag
		);
}

bool CCurrMarginRateDetailFactory::retrieveByPK(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail)
{
	CCurrMarginRateDetail *pOriginalCurrMarginRateDetail;
	pOriginalCurrMarginRateDetail=findByPK(pCurrMarginRateDetail);
	if (pOriginalCurrMarginRateDetail==NULL)
	{
		return false;
	}
	retrieve(pOriginalCurrMarginRateDetail,pCurrMarginRateDetail);
	return true;
}

CCurrMarginRateDetail *CCurrMarginRateDetailFactory::addByPK(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail, CTransaction *pTransaction)
{
	CCurrMarginRateDetail *pOriginalCurrMarginRateDetail;
	pOriginalCurrMarginRateDetail=findByPK(pCurrMarginRateDetail);
	if (pOriginalCurrMarginRateDetail != NULL)
	{
		return NULL;
	}
	return add(pCurrMarginRateDetail,pTransaction);
}

bool CCurrMarginRateDetailFactory::updateByPK(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail, CTransaction *pTransaction, bool updateIndex)
{
	CCurrMarginRateDetail *pOriginalCurrMarginRateDetail;
	pOriginalCurrMarginRateDetail=findByPK(pCurrMarginRateDetail);
	if (pOriginalCurrMarginRateDetail==NULL)
	{
		return false;
	}
	pCurrMarginRateDetail->calAllHash();
	update(pOriginalCurrMarginRateDetail,pCurrMarginRateDetail,pTransaction,updateIndex);
	return true;
}

bool CCurrMarginRateDetailFactory::removeByPK(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail, CTransaction *pTransaction)
{
	CCurrMarginRateDetail *pOriginalCurrMarginRateDetail;
	pOriginalCurrMarginRateDetail=findByPK(pCurrMarginRateDetail);
	if (pOriginalCurrMarginRateDetail==NULL)
	{
		return false;
	}
	remove(pOriginalCurrMarginRateDetail,pTransaction);
	return true;
}



#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForCurrPartPosiLimit=0;
#endif

CCurrPartPosiLimit *CCurrPartPosiLimitFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCurrPartPosiLimit while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCurrPartPosiLimit *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCurrPartPosiLimit *CCurrPartPosiLimitFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCurrPartPosiLimit *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCurrPartPosiLimitFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentAndPartForCurrPartPosiLimit=0;
#endif
CCurrPartPosiLimit *CCurrPartPosiLimitFactory::findByInstrumentAndPart( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentAndPart of CCurrPartPosiLimit while run level < 0");
	}
	CCurrPartPosiLimit *theCurrPartPosiLimit;
	for (theCurrPartPosiLimit=(CCurrPartPosiLimit *)(pMem->getFirst());
		theCurrPartPosiLimit!=NULL;
		theCurrPartPosiLimit=(CCurrPartPosiLimit *)(pMem->getNext()))
	{
		if (compare(theCurrPartPosiLimit->InstrumentID.getValue(),InstrumentID.getValue())!=0)
		{
			continue;
		}
		if (compare(theCurrPartPosiLimit->ParticipantID.getValue(),ParticipantID.getValue())!=0)
		{
			continue;
		}
		return theCurrPartPosiLimit;
	}
	return NULL;
}


int compareForInstrumentAndPartIndexinCurrPartPosiLimitDetail(const void *pV1, const void *pV2)
{
	CCurrPartPosiLimitDetail *p1,*p2;
	p1=(CCurrPartPosiLimitDetail *)pV1;
	p2=(CCurrPartPosiLimitDetail *)pV2;
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
	switch (compare(p1->StartTotalPosition.getValue(),p2->StartTotalPosition.getValue()))
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
int multiFindBySettlementGroupIDForCurrPartPosiLimitDetail=0;
#endif

CCurrPartPosiLimitDetail *CCurrPartPosiLimitDetailFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCurrPartPosiLimitDetail while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCurrPartPosiLimitDetail *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCurrPartPosiLimitDetail *CCurrPartPosiLimitDetailFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCurrPartPosiLimitDetail *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCurrPartPosiLimitDetailFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentAndPartForCurrPartPosiLimitDetail=0;
#endif
CCurrPartPosiLimitDetail *CCurrPartPosiLimitDetailFactory::findByInstrumentAndPart( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyPositionTradingRoleType&  TradingRole,  const CReadOnlyLargeVolumeType&  StartTotalPosition)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentAndPart of CCurrPartPosiLimitDetail while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentAndPartForCurrPartPosiLimitDetail++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.TradingRole=TradingRole.getValue();
	compareObject.StartTotalPosition=StartTotalPosition.getValue();
	pNode=pInstrumentAndPartIndex->searchFirstGreatEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	if (compare(((CCurrPartPosiLimitDetail *)(pNode->pObject))->InstrumentID.getValue(),InstrumentID.getValue())!=0)
	{
		return NULL;
	}
	if (compare(((CCurrPartPosiLimitDetail *)(pNode->pObject))->ParticipantID.getValue(),ParticipantID.getValue())!=0)
	{
		return NULL;
	}
	if (compare(((CCurrPartPosiLimitDetail *)(pNode->pObject))->TradingRole.getValue(),TradingRole.getValue())!=0)
	{
		return NULL;
	}
	return (CCurrPartPosiLimitDetail *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int findByInstrumentPartAndStartPositionForCurrPartPosiLimitDetail=0;
#endif
CCurrPartPosiLimitDetail *CCurrPartPosiLimitDetailFactory::findByInstrumentPartAndStartPosition( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyPositionTradingRoleType&  TradingRole,  const CReadOnlyLargeVolumeType&  StartTotalPosition)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentPartAndStartPosition of CCurrPartPosiLimitDetail while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentPartAndStartPositionForCurrPartPosiLimitDetail++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.TradingRole=TradingRole.getValue();
	compareObject.StartTotalPosition=StartTotalPosition.getValue();
	pNode=pInstrumentAndPartIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CCurrPartPosiLimitDetail *)(pNode->pObject);
}

CCurrPartPosiLimitDetail *CCurrPartPosiLimitDetailFactory::findByPK( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyPositionTradingRoleType&  TradingRole,  const CReadOnlyLargeVolumeType&  StartTotalPosition)
{
	return findByInstrumentPartAndStartPosition(InstrumentID, ParticipantID, TradingRole, StartTotalPosition);
}
	
CCurrPartPosiLimitDetail *CCurrPartPosiLimitDetailFactory::findByPK(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
{
	return findByPK(
		pCurrPartPosiLimitDetail->InstrumentID
		,
		pCurrPartPosiLimitDetail->ParticipantID
		,
		pCurrPartPosiLimitDetail->TradingRole
		,
		pCurrPartPosiLimitDetail->StartTotalPosition
		);
}

bool CCurrPartPosiLimitDetailFactory::retrieveByPK(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
{
	CCurrPartPosiLimitDetail *pOriginalCurrPartPosiLimitDetail;
	pOriginalCurrPartPosiLimitDetail=findByPK(pCurrPartPosiLimitDetail);
	if (pOriginalCurrPartPosiLimitDetail==NULL)
	{
		return false;
	}
	retrieve(pOriginalCurrPartPosiLimitDetail,pCurrPartPosiLimitDetail);
	return true;
}

CCurrPartPosiLimitDetail *CCurrPartPosiLimitDetailFactory::addByPK(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CTransaction *pTransaction)
{
	CCurrPartPosiLimitDetail *pOriginalCurrPartPosiLimitDetail;
	pOriginalCurrPartPosiLimitDetail=findByPK(pCurrPartPosiLimitDetail);
	if (pOriginalCurrPartPosiLimitDetail != NULL)
	{
		return NULL;
	}
	return add(pCurrPartPosiLimitDetail,pTransaction);
}

bool CCurrPartPosiLimitDetailFactory::updateByPK(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CTransaction *pTransaction, bool updateIndex)
{
	CCurrPartPosiLimitDetail *pOriginalCurrPartPosiLimitDetail;
	pOriginalCurrPartPosiLimitDetail=findByPK(pCurrPartPosiLimitDetail);
	if (pOriginalCurrPartPosiLimitDetail==NULL)
	{
		return false;
	}
	pCurrPartPosiLimitDetail->calAllHash();
	update(pOriginalCurrPartPosiLimitDetail,pCurrPartPosiLimitDetail,pTransaction,updateIndex);
	return true;
}

bool CCurrPartPosiLimitDetailFactory::removeByPK(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CTransaction *pTransaction)
{
	CCurrPartPosiLimitDetail *pOriginalCurrPartPosiLimitDetail;
	pOriginalCurrPartPosiLimitDetail=findByPK(pCurrPartPosiLimitDetail);
	if (pOriginalCurrPartPosiLimitDetail==NULL)
	{
		return false;
	}
	remove(pOriginalCurrPartPosiLimitDetail,pTransaction);
	return true;
}



#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForCurrClientPosiLimit=0;
#endif

CCurrClientPosiLimit *CCurrClientPosiLimitFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCurrClientPosiLimit while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCurrClientPosiLimit *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCurrClientPosiLimit *CCurrClientPosiLimitFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCurrClientPosiLimit *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCurrClientPosiLimitFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}

int compareForInstrumentAndClientTypeIndexinCurrClientPosiLimitDetail(const void *pV1, const void *pV2)
{
	CCurrClientPosiLimitDetail *p1,*p2;
	p1=(CCurrClientPosiLimitDetail *)pV1;
	p2=(CCurrClientPosiLimitDetail *)pV2;
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
	switch (compare(p1->StartTotalPosition.getValue(),p2->StartTotalPosition.getValue()))
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
int multiFindBySettlementGroupIDForCurrClientPosiLimitDetail=0;
#endif

CCurrClientPosiLimitDetail *CCurrClientPosiLimitDetailFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCurrClientPosiLimitDetail while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCurrClientPosiLimitDetail *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCurrClientPosiLimitDetail *CCurrClientPosiLimitDetailFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCurrClientPosiLimitDetail *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCurrClientPosiLimitDetailFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentAndClientTypeForCurrClientPosiLimitDetail=0;
#endif
CCurrClientPosiLimitDetail *CCurrClientPosiLimitDetailFactory::findByInstrumentAndClientType( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientTypeType&  ClientType,  const CReadOnlyLargeVolumeType&  StartTotalPosition)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentAndClientType of CCurrClientPosiLimitDetail while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentAndClientTypeForCurrClientPosiLimitDetail++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ClientType=ClientType.getValue();
	compareObject.StartTotalPosition=StartTotalPosition.getValue();
	pNode=pInstrumentAndClientTypeIndex->searchFirstGreatEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	if (compare(((CCurrClientPosiLimitDetail *)(pNode->pObject))->InstrumentID.getValue(),InstrumentID.getValue())!=0)
	{
		return NULL;
	}
	if (compare(((CCurrClientPosiLimitDetail *)(pNode->pObject))->ClientType.getValue(),ClientType.getValue())!=0)
	{
		return NULL;
	}
	return (CCurrClientPosiLimitDetail *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int findByInstrumentClientTypeAndStartPositionForCurrClientPosiLimitDetail=0;
#endif
CCurrClientPosiLimitDetail *CCurrClientPosiLimitDetailFactory::findByInstrumentClientTypeAndStartPosition( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientTypeType&  ClientType,  const CReadOnlyLargeVolumeType&  StartTotalPosition)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentClientTypeAndStartPosition of CCurrClientPosiLimitDetail while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentClientTypeAndStartPositionForCurrClientPosiLimitDetail++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ClientType=ClientType.getValue();
	compareObject.StartTotalPosition=StartTotalPosition.getValue();
	pNode=pInstrumentAndClientTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CCurrClientPosiLimitDetail *)(pNode->pObject);
}

CCurrClientPosiLimitDetail *CCurrClientPosiLimitDetailFactory::findByPK( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientTypeType&  ClientType,  const CReadOnlyLargeVolumeType&  StartTotalPosition)
{
	return findByInstrumentClientTypeAndStartPosition(InstrumentID, ClientType, StartTotalPosition);
}
	
CCurrClientPosiLimitDetail *CCurrClientPosiLimitDetailFactory::findByPK(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
{
	return findByPK(
		pCurrClientPosiLimitDetail->InstrumentID
		,
		pCurrClientPosiLimitDetail->ClientType
		,
		pCurrClientPosiLimitDetail->StartTotalPosition
		);
}

bool CCurrClientPosiLimitDetailFactory::retrieveByPK(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
{
	CCurrClientPosiLimitDetail *pOriginalCurrClientPosiLimitDetail;
	pOriginalCurrClientPosiLimitDetail=findByPK(pCurrClientPosiLimitDetail);
	if (pOriginalCurrClientPosiLimitDetail==NULL)
	{
		return false;
	}
	retrieve(pOriginalCurrClientPosiLimitDetail,pCurrClientPosiLimitDetail);
	return true;
}

CCurrClientPosiLimitDetail *CCurrClientPosiLimitDetailFactory::addByPK(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CTransaction *pTransaction)
{
	CCurrClientPosiLimitDetail *pOriginalCurrClientPosiLimitDetail;
	pOriginalCurrClientPosiLimitDetail=findByPK(pCurrClientPosiLimitDetail);
	if (pOriginalCurrClientPosiLimitDetail != NULL)
	{
		return NULL;
	}
	return add(pCurrClientPosiLimitDetail,pTransaction);
}

bool CCurrClientPosiLimitDetailFactory::updateByPK(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CTransaction *pTransaction, bool updateIndex)
{
	CCurrClientPosiLimitDetail *pOriginalCurrClientPosiLimitDetail;
	pOriginalCurrClientPosiLimitDetail=findByPK(pCurrClientPosiLimitDetail);
	if (pOriginalCurrClientPosiLimitDetail==NULL)
	{
		return false;
	}
	pCurrClientPosiLimitDetail->calAllHash();
	update(pOriginalCurrClientPosiLimitDetail,pCurrClientPosiLimitDetail,pTransaction,updateIndex);
	return true;
}

bool CCurrClientPosiLimitDetailFactory::removeByPK(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CTransaction *pTransaction)
{
	CCurrClientPosiLimitDetail *pOriginalCurrClientPosiLimitDetail;
	pOriginalCurrClientPosiLimitDetail=findByPK(pCurrClientPosiLimitDetail);
	if (pOriginalCurrClientPosiLimitDetail==NULL)
	{
		return false;
	}
	remove(pOriginalCurrClientPosiLimitDetail,pTransaction);
	return true;
}



#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForCurrSpecialPosiLimit=0;
#endif

CCurrSpecialPosiLimit *CCurrSpecialPosiLimitFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCurrSpecialPosiLimit while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCurrSpecialPosiLimit *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCurrSpecialPosiLimit *CCurrSpecialPosiLimitFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCurrSpecialPosiLimit *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCurrSpecialPosiLimitFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}

int compareForInstrumentAndClientIndexinCurrSpecialPosiLimitDetail(const void *pV1, const void *pV2)
{
	CCurrSpecialPosiLimitDetail *p1,*p2;
	p1=(CCurrSpecialPosiLimitDetail *)pV1;
	p2=(CCurrSpecialPosiLimitDetail *)pV2;
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
	switch (compare(p1->StartTotalPosition.getValue(),p2->StartTotalPosition.getValue()))
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
int multiFindBySettlementGroupIDForCurrSpecialPosiLimitDetail=0;
#endif

CCurrSpecialPosiLimitDetail *CCurrSpecialPosiLimitDetailFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCurrSpecialPosiLimitDetail while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCurrSpecialPosiLimitDetail *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCurrSpecialPosiLimitDetail *CCurrSpecialPosiLimitDetailFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCurrSpecialPosiLimitDetail *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCurrSpecialPosiLimitDetailFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentAndClientForCurrSpecialPosiLimitDetail=0;
#endif
CCurrSpecialPosiLimitDetail *CCurrSpecialPosiLimitDetailFactory::findByInstrumentAndClient( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyLargeVolumeType&  StartTotalPosition)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentAndClient of CCurrSpecialPosiLimitDetail while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentAndClientForCurrSpecialPosiLimitDetail++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ClientID=ClientID.getValue();
	compareObject.StartTotalPosition=StartTotalPosition.getValue();
	pNode=pInstrumentAndClientIndex->searchFirstGreatEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	if (compare(((CCurrSpecialPosiLimitDetail *)(pNode->pObject))->InstrumentID.getValue(),InstrumentID.getValue())!=0)
	{
		return NULL;
	}
	if (compare(((CCurrSpecialPosiLimitDetail *)(pNode->pObject))->ClientID.getValue(),ClientID.getValue())!=0)
	{
		return NULL;
	}
	return (CCurrSpecialPosiLimitDetail *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int findByInstrumentClientAndStartPositionForCurrSpecialPosiLimitDetail=0;
#endif
CCurrSpecialPosiLimitDetail *CCurrSpecialPosiLimitDetailFactory::findByInstrumentClientAndStartPosition( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyLargeVolumeType&  StartTotalPosition)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentClientAndStartPosition of CCurrSpecialPosiLimitDetail while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentClientAndStartPositionForCurrSpecialPosiLimitDetail++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ClientID=ClientID.getValue();
	compareObject.StartTotalPosition=StartTotalPosition.getValue();
	pNode=pInstrumentAndClientIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CCurrSpecialPosiLimitDetail *)(pNode->pObject);
}

CCurrSpecialPosiLimitDetail *CCurrSpecialPosiLimitDetailFactory::findByPK( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyLargeVolumeType&  StartTotalPosition)
{
	return findByInstrumentClientAndStartPosition(InstrumentID, ClientID, StartTotalPosition);
}
	
CCurrSpecialPosiLimitDetail *CCurrSpecialPosiLimitDetailFactory::findByPK(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
{
	return findByPK(
		pCurrSpecialPosiLimitDetail->InstrumentID
		,
		pCurrSpecialPosiLimitDetail->ClientID
		,
		pCurrSpecialPosiLimitDetail->StartTotalPosition
		);
}

bool CCurrSpecialPosiLimitDetailFactory::retrieveByPK(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
{
	CCurrSpecialPosiLimitDetail *pOriginalCurrSpecialPosiLimitDetail;
	pOriginalCurrSpecialPosiLimitDetail=findByPK(pCurrSpecialPosiLimitDetail);
	if (pOriginalCurrSpecialPosiLimitDetail==NULL)
	{
		return false;
	}
	retrieve(pOriginalCurrSpecialPosiLimitDetail,pCurrSpecialPosiLimitDetail);
	return true;
}

CCurrSpecialPosiLimitDetail *CCurrSpecialPosiLimitDetailFactory::addByPK(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CTransaction *pTransaction)
{
	CCurrSpecialPosiLimitDetail *pOriginalCurrSpecialPosiLimitDetail;
	pOriginalCurrSpecialPosiLimitDetail=findByPK(pCurrSpecialPosiLimitDetail);
	if (pOriginalCurrSpecialPosiLimitDetail != NULL)
	{
		return NULL;
	}
	return add(pCurrSpecialPosiLimitDetail,pTransaction);
}

bool CCurrSpecialPosiLimitDetailFactory::updateByPK(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CTransaction *pTransaction, bool updateIndex)
{
	CCurrSpecialPosiLimitDetail *pOriginalCurrSpecialPosiLimitDetail;
	pOriginalCurrSpecialPosiLimitDetail=findByPK(pCurrSpecialPosiLimitDetail);
	if (pOriginalCurrSpecialPosiLimitDetail==NULL)
	{
		return false;
	}
	pCurrSpecialPosiLimitDetail->calAllHash();
	update(pOriginalCurrSpecialPosiLimitDetail,pCurrSpecialPosiLimitDetail,pTransaction,updateIndex);
	return true;
}

bool CCurrSpecialPosiLimitDetailFactory::removeByPK(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CTransaction *pTransaction)
{
	CCurrSpecialPosiLimitDetail *pOriginalCurrSpecialPosiLimitDetail;
	pOriginalCurrSpecialPosiLimitDetail=findByPK(pCurrSpecialPosiLimitDetail);
	if (pOriginalCurrSpecialPosiLimitDetail==NULL)
	{
		return false;
	}
	remove(pOriginalCurrSpecialPosiLimitDetail,pTransaction);
	return true;
}


int compareForInstrumentIDIndexinCurrHedgeRule(const void *pV1, const void *pV2)
{
	CCurrHedgeRule *p1,*p2;
	p1=(CCurrHedgeRule *)pV1;
	p2=(CCurrHedgeRule *)pV2;
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
int multiFindBySettlementGroupIDForCurrHedgeRule=0;
#endif

CCurrHedgeRule *CCurrHedgeRuleFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCurrHedgeRule while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCurrHedgeRule *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCurrHedgeRule *CCurrHedgeRuleFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCurrHedgeRule *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCurrHedgeRuleFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentIDForCurrHedgeRule=0;
#endif
CCurrHedgeRule *CCurrHedgeRuleFactory::findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentID of CCurrHedgeRule while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentIDForCurrHedgeRule++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CCurrHedgeRule *)(pNode->pObject);
}


int compareForTimeIndexinCurrTradingSegmentAttr(const void *pV1, const void *pV2)
{
	CCurrTradingSegmentAttr *p1,*p2;
	p1=(CCurrTradingSegmentAttr *)pV1;
	p2=(CCurrTradingSegmentAttr *)pV2;
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
	switch (compare(p1->TradingSegmentSN.getValue(),p2->TradingSegmentSN.getValue()))
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
int compareForInstrumentIndexinCurrTradingSegmentAttr(const void *pV1, const void *pV2)
{
	CCurrTradingSegmentAttr *p1,*p2;
	p1=(CCurrTradingSegmentAttr *)pV1;
	p2=(CCurrTradingSegmentAttr *)pV2;
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
	switch (compare(p1->TradingSegmentSN.getValue(),p2->TradingSegmentSN.getValue()))
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
int multiFindBySettlementGroupIDForCurrTradingSegmentAttr=0;
#endif

CCurrTradingSegmentAttr *CCurrTradingSegmentAttrFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCurrTradingSegmentAttr while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCurrTradingSegmentAttr *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCurrTradingSegmentAttr *CCurrTradingSegmentAttrFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCurrTradingSegmentAttr *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCurrTradingSegmentAttrFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByTimeForCurrTradingSegmentAttr=0;
#endif

CCurrTradingSegmentAttr *CCurrTradingSegmentAttrFactory::startFindByTime( const CReadOnlyTimeType& StartTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTime of CCurrTradingSegmentAttr while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTime();
	}

	///记录所有的查询值
	queryStartTimeInSearchByTime= StartTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByTimeForCurrTradingSegmentAttr++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CCurrTradingSegmentAttr *theCurrTradingSegmentAttr;
	compareObject.StartTime=StartTime.getValue();
	compareObject.TradingSegmentSN=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByTime=pTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theCurrTradingSegmentAttr=(CCurrTradingSegmentAttr *)(pLastFoundInSearchByTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theCurrTradingSegmentAttr;
}

CCurrTradingSegmentAttr *CCurrTradingSegmentAttrFactory::findNextByTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTimeForCurrTradingSegmentAttr++;
#endif
	CCurrTradingSegmentAttr *theCurrTradingSegmentAttr;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByTime=pTimeIndex->getNextNode(pLastFoundInSearchByTime);
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	theCurrTradingSegmentAttr=(CCurrTradingSegmentAttr *)(pLastFoundInSearchByTime->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theCurrTradingSegmentAttr;
}

void CCurrTradingSegmentAttrFactory::endFindByTime(void)
{
	pLastFoundInSearchByTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByInstrumentForCurrTradingSegmentAttr=0;
#endif

CCurrTradingSegmentAttr *CCurrTradingSegmentAttrFactory::startFindByInstrument( const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByInstrument of CCurrTradingSegmentAttr while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByInstrument!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByInstrument();
	}

	///记录所有的查询值
	queryInstrumentIDInSearchByInstrument= InstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindByInstrumentForCurrTradingSegmentAttr++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CCurrTradingSegmentAttr *theCurrTradingSegmentAttr;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.TradingSegmentSN=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByInstrument=pInstrumentIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByInstrument==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theCurrTradingSegmentAttr=(CCurrTradingSegmentAttr *)(pLastFoundInSearchByInstrument->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theCurrTradingSegmentAttr->InstrumentID.getValue(),InstrumentID.getValue()))
	{
		pLastFoundInSearchByInstrument=NULL;
		return NULL;
	}

	///返回找到的结果
	return theCurrTradingSegmentAttr;
}

CCurrTradingSegmentAttr *CCurrTradingSegmentAttrFactory::findNextByInstrument(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByInstrument==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByInstrumentForCurrTradingSegmentAttr++;
#endif
	CCurrTradingSegmentAttr *theCurrTradingSegmentAttr;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByInstrument=pInstrumentIndex->getNextNode(pLastFoundInSearchByInstrument);
	if (pLastFoundInSearchByInstrument==NULL)
	{
		return NULL;
	}

	theCurrTradingSegmentAttr=(CCurrTradingSegmentAttr *)(pLastFoundInSearchByInstrument->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theCurrTradingSegmentAttr->InstrumentID,queryInstrumentIDInSearchByInstrument))
	{
		pLastFoundInSearchByInstrument=NULL;
		return NULL;
	}

	///返回找到的结果
	return theCurrTradingSegmentAttr;
}

void CCurrTradingSegmentAttrFactory::endFindByInstrument(void)
{
	pLastFoundInSearchByInstrument=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentAndSegementForCurrTradingSegmentAttr=0;
#endif
CCurrTradingSegmentAttr *CCurrTradingSegmentAttrFactory::findByInstrumentAndSegement( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyTradingSegmentSNType&  TradingSegmentSN)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentAndSegement of CCurrTradingSegmentAttr while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentAndSegementForCurrTradingSegmentAttr++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.TradingSegmentSN=TradingSegmentSN.getValue();
	pNode=pInstrumentIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CCurrTradingSegmentAttr *)(pNode->pObject);
}


int compareForInstrumentIDIndexinCurrFuse(const void *pV1, const void *pV2)
{
	CCurrFuse *p1,*p2;
	p1=(CCurrFuse *)pV1;
	p2=(CCurrFuse *)pV2;
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
int multiFindBySettlementGroupIDForCurrFuse=0;
#endif

CCurrFuse *CCurrFuseFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCurrFuse while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCurrFuse *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCurrFuse *CCurrFuseFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCurrFuse *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCurrFuseFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentIDForCurrFuse=0;
#endif
CCurrFuse *CCurrFuseFactory::findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentID of CCurrFuse while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentIDForCurrFuse++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CCurrFuse *)(pNode->pObject);
}

CCurrFuse *CCurrFuseFactory::findByPK( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	return findByInstrumentID(InstrumentID);
}
	
CCurrFuse *CCurrFuseFactory::findByPK(CWriteableCurrFuse *pCurrFuse)
{
	return findByPK(
		pCurrFuse->InstrumentID
		);
}

bool CCurrFuseFactory::retrieveByPK(CWriteableCurrFuse *pCurrFuse)
{
	CCurrFuse *pOriginalCurrFuse;
	pOriginalCurrFuse=findByPK(pCurrFuse);
	if (pOriginalCurrFuse==NULL)
	{
		return false;
	}
	retrieve(pOriginalCurrFuse,pCurrFuse);
	return true;
}

CCurrFuse *CCurrFuseFactory::addByPK(CWriteableCurrFuse *pCurrFuse, CTransaction *pTransaction)
{
	CCurrFuse *pOriginalCurrFuse;
	pOriginalCurrFuse=findByPK(pCurrFuse);
	if (pOriginalCurrFuse != NULL)
	{
		return NULL;
	}
	return add(pCurrFuse,pTransaction);
}

bool CCurrFuseFactory::updateByPK(CWriteableCurrFuse *pCurrFuse, CTransaction *pTransaction, bool updateIndex)
{
	CCurrFuse *pOriginalCurrFuse;
	pOriginalCurrFuse=findByPK(pCurrFuse);
	if (pOriginalCurrFuse==NULL)
	{
		return false;
	}
	pCurrFuse->calAllHash();
	update(pOriginalCurrFuse,pCurrFuse,pTransaction,updateIndex);
	return true;
}

bool CCurrFuseFactory::removeByPK(CWriteableCurrFuse *pCurrFuse, CTransaction *pTransaction)
{
	CCurrFuse *pOriginalCurrFuse;
	pOriginalCurrFuse=findByPK(pCurrFuse);
	if (pOriginalCurrFuse==NULL)
	{
		return false;
	}
	remove(pOriginalCurrFuse,pTransaction);
	return true;
}


int compareForAccountIDIndexinTradingAccount(const void *pV1, const void *pV2)
{
	CTradingAccount *p1,*p2;
	p1=(CTradingAccount *)pV1;
	p2=(CTradingAccount *)pV2;
	switch (compare(p1->AccountID.getValue(),p2->AccountID.getValue()))
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
int multiFindBySettlementGroupIDForTradingAccount=0;
#endif

CTradingAccount *CTradingAccountFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CTradingAccount while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CTradingAccount *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CTradingAccount *CTradingAccountFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CTradingAccount *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CTradingAccountFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByAccountIDForTradingAccount=0;
#endif
CTradingAccount *CTradingAccountFactory::findByAccountID( const CReadOnlyAccountIDType&  AccountID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByAccountID of CTradingAccount while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByAccountIDForTradingAccount++;
#endif
	CAVLNode *pNode;
	compareObject.AccountID=AccountID.getValue();
	pNode=pAccountIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CTradingAccount *)(pNode->pObject);
}


int compareForAccountIDIndexinBaseReserveAccount(const void *pV1, const void *pV2)
{
	CBaseReserveAccount *p1,*p2;
	p1=(CBaseReserveAccount *)pV1;
	p2=(CBaseReserveAccount *)pV2;
	switch (compare(p1->AccountID.getValue(),p2->AccountID.getValue()))
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
int multiFindBySettlementGroupIDForBaseReserveAccount=0;
#endif

CBaseReserveAccount *CBaseReserveAccountFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CBaseReserveAccount while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CBaseReserveAccount *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CBaseReserveAccount *CBaseReserveAccountFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CBaseReserveAccount *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CBaseReserveAccountFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByAccountIDForBaseReserveAccount=0;
#endif
CBaseReserveAccount *CBaseReserveAccountFactory::findByAccountID( const CReadOnlyAccountIDType&  AccountID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByAccountID of CBaseReserveAccount while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByAccountIDForBaseReserveAccount++;
#endif
	CAVLNode *pNode;
	compareObject.AccountID=AccountID.getValue();
	pNode=pAccountIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CBaseReserveAccount *)(pNode->pObject);
}


int compareForInstrumentIndexinPartPosition(const void *pV1, const void *pV2)
{
	CPartPosition *p1,*p2;
	p1=(CPartPosition *)pV1;
	p2=(CPartPosition *)pV2;
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
	switch (compare(p1->PosiDirection.getValue(),p2->PosiDirection.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->HedgeFlag.getValue(),p2->HedgeFlag.getValue()))
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
int compareForPartInstrumentIndexinPartPosition(const void *pV1, const void *pV2)
{
	CPartPosition *p1,*p2;
	p1=(CPartPosition *)pV1;
	p2=(CPartPosition *)pV2;
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
	switch (compare(p1->PosiDirection.getValue(),p2->PosiDirection.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->HedgeFlag.getValue(),p2->HedgeFlag.getValue()))
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
int findByPartAndInstrumentForPartPosition=0;
#endif
CPartPosition *CPartPositionFactory::findByPartAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyPosiDirectionType&  PosiDirection,  const CReadOnlyHedgeFlagType&  HedgeFlag,  const CReadOnlyTradingRoleType&  TradingRole)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByPartAndInstrument of CPartPosition while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.PosiDirection=PosiDirection.getValue();
	compareObject.HedgeFlag=HedgeFlag.getValue();
	compareObject.TradingRole=TradingRole.getValue();
	
	compareObject.calHashPartAndInstrument();
	for (pNode=pPartAndInstrumentHashIndex->searchFirstEqual(compareObject.HashPartAndInstrument);
		pNode!=NULL;
		pNode=pPartAndInstrumentHashIndex->searchNextEqual(pNode))
	{
		if (((CPartPosition *)(pNode->pObject))->HashPartAndInstrument != compareObject.HashPartAndInstrument)
		{
			continue;
		}
		if (compare(((CPartPosition *)(pNode->pObject))->ParticipantID.getValue(),ParticipantID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CPartPosition *)(pNode->pObject))->InstrumentID.getValue(),InstrumentID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CPartPosition *)(pNode->pObject))->PosiDirection.getValue(),PosiDirection.getValue())!=0)
		{
			continue;
		}
		if (compare(((CPartPosition *)(pNode->pObject))->HedgeFlag.getValue(),HedgeFlag.getValue())!=0)
		{
			continue;
		}
		if (compare(((CPartPosition *)(pNode->pObject))->TradingRole.getValue(),TradingRole.getValue())!=0)
		{
			continue;
		}
		return (CPartPosition *)(pNode->pObject);
	}
	return NULL;
}



#ifdef COUNT_SEARCH
int multiFindStartByInstrumentForPartPosition=0;
#endif

CPartPosition *CPartPositionFactory::startFindStartByInstrument( const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByInstrument of CPartPosition while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByInstrument!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByInstrument();
	}

	///记录所有的查询值
	queryInstrumentIDInSearchStartByInstrument= InstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByInstrumentForPartPosition++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CPartPosition *thePartPosition;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ParticipantID="";
	compareObject.PosiDirection=PD_Net;
	compareObject.HedgeFlag=HF_Speculation;
	compareObject.TradingRole=ER_Broker;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByInstrument=pInstrumentIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByInstrument==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	thePartPosition=(CPartPosition *)(pLastFoundInSearchStartByInstrument->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return thePartPosition;
}

CPartPosition *CPartPositionFactory::findNextStartByInstrument(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByInstrument==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByInstrumentForPartPosition++;
#endif
	CPartPosition *thePartPosition;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByInstrument=pInstrumentIndex->getNextNode(pLastFoundInSearchStartByInstrument);
	if (pLastFoundInSearchStartByInstrument==NULL)
	{
		return NULL;
	}

	thePartPosition=(CPartPosition *)(pLastFoundInSearchStartByInstrument->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return thePartPosition;
}

void CPartPositionFactory::endFindStartByInstrument(void)
{
	pLastFoundInSearchStartByInstrument=NULL;
}


#ifdef COUNT_SEARCH
int multiFindStartByParticipantForPartPosition=0;
#endif

CPartPosition *CPartPositionFactory::startFindStartByParticipant( const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByParticipant of CPartPosition while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByParticipant!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByParticipant();
	}

	///记录所有的查询值
	queryParticipantIDInSearchStartByParticipant= ParticipantID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByParticipantForPartPosition++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CPartPosition *thePartPosition;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.InstrumentID="";
	compareObject.PosiDirection=PD_Net;
	compareObject.HedgeFlag=HF_Speculation;
	compareObject.TradingRole=ER_Broker;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByParticipant=pPartInstrumentIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByParticipant==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	thePartPosition=(CPartPosition *)(pLastFoundInSearchStartByParticipant->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return thePartPosition;
}

CPartPosition *CPartPositionFactory::findNextStartByParticipant(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByParticipant==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByParticipantForPartPosition++;
#endif
	CPartPosition *thePartPosition;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByParticipant=pPartInstrumentIndex->getNextNode(pLastFoundInSearchStartByParticipant);
	if (pLastFoundInSearchStartByParticipant==NULL)
	{
		return NULL;
	}

	thePartPosition=(CPartPosition *)(pLastFoundInSearchStartByParticipant->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return thePartPosition;
}

void CPartPositionFactory::endFindStartByParticipant(void)
{
	pLastFoundInSearchStartByParticipant=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForPartPosition=0;
#endif

CPartPosition *CPartPositionFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CPartPosition while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CPartPosition *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CPartPosition *CPartPositionFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CPartPosition *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CPartPositionFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}

int compareForPartClientAndInstumentIndexinClientPosition(const void *pV1, const void *pV2)
{
	CClientPosition *p1,*p2;
	p1=(CClientPosition *)pV1;
	p2=(CClientPosition *)pV2;
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
	switch (compare(p1->PosiDirection.getValue(),p2->PosiDirection.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->HedgeFlag.getValue(),p2->HedgeFlag.getValue()))
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
int compareForClientAndInstumentIndexinClientPosition(const void *pV1, const void *pV2)
{
	CClientPosition *p1,*p2;
	p1=(CClientPosition *)pV1;
	p2=(CClientPosition *)pV2;
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
	switch (compare(p1->PosiDirection.getValue(),p2->PosiDirection.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->HedgeFlag.getValue(),p2->HedgeFlag.getValue()))
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
int compareForInstumentIndexinClientPosition(const void *pV1, const void *pV2)
{
	CClientPosition *p1,*p2;
	p1=(CClientPosition *)pV1;
	p2=(CClientPosition *)pV2;
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
	switch (compare(p1->PosiDirection.getValue(),p2->PosiDirection.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->HedgeFlag.getValue(),p2->HedgeFlag.getValue()))
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
int findByPartClientAndInstrumentForClientPosition=0;
#endif
CClientPosition *CClientPositionFactory::findByPartClientAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyPosiDirectionType&  PosiDirection,  const CReadOnlyHedgeFlagType&  HedgeFlag)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByPartClientAndInstrument of CClientPosition while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.ClientID=ClientID.getValue();
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.PosiDirection=PosiDirection.getValue();
	compareObject.HedgeFlag=HedgeFlag.getValue();
	
	compareObject.calHashClientAndInstrument();
	for (pNode=pClientAndInstrumentHashIndex->searchFirstEqual(compareObject.HashClientAndInstrument);
		pNode!=NULL;
		pNode=pClientAndInstrumentHashIndex->searchNextEqual(pNode))
	{
		if (((CClientPosition *)(pNode->pObject))->HashClientAndInstrument != compareObject.HashClientAndInstrument)
		{
			continue;
		}
		if (compare(((CClientPosition *)(pNode->pObject))->ParticipantID.getValue(),ParticipantID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CClientPosition *)(pNode->pObject))->ClientID.getValue(),ClientID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CClientPosition *)(pNode->pObject))->InstrumentID.getValue(),InstrumentID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CClientPosition *)(pNode->pObject))->PosiDirection.getValue(),PosiDirection.getValue())!=0)
		{
			continue;
		}
		if (compare(((CClientPosition *)(pNode->pObject))->HedgeFlag.getValue(),HedgeFlag.getValue())!=0)
		{
			continue;
		}
		return (CClientPosition *)(pNode->pObject);
	}
	return NULL;
}



#ifdef COUNT_SEARCH
int multiFindByClientAndInstrumentForClientPosition=0;
#endif

CClientPosition *CClientPositionFactory::startFindByClientAndInstrument( const CReadOnlyClientIDType& ClientID,  const CReadOnlyInstrumentIDType& InstrumentID,  const CReadOnlyPosiDirectionType& PosiDirection,  const CReadOnlyHedgeFlagType& HedgeFlag)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByClientAndInstrument of CClientPosition while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByClientAndInstrument!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByClientAndInstrument();
	}

	///记录所有的查询值
	queryClientIDInSearchByClientAndInstrument= ClientID.getValue();
	queryInstrumentIDInSearchByClientAndInstrument= InstrumentID.getValue();
	queryPosiDirectionInSearchByClientAndInstrument= PosiDirection.getValue();
	queryHedgeFlagInSearchByClientAndInstrument= HedgeFlag.getValue();

	CClientPosition *theClientPosition;
	compareObject.ClientID=ClientID.getValue();
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.PosiDirection=PosiDirection.getValue();
	compareObject.HedgeFlag=HedgeFlag.getValue();
	compareObject.ParticipantID="";
	
	compareObject.calHashClientAndInstrument();

	
	for (pLastFoundInSearchByClientAndInstrument=pClientAndInstrumentHashIndex->searchFirstEqual(compareObject.HashClientAndInstrument);
		pLastFoundInSearchByClientAndInstrument !=NULL;
		pLastFoundInSearchByClientAndInstrument=pClientAndInstrumentHashIndex->searchNextEqual(pLastFoundInSearchByClientAndInstrument))
	{
		theClientPosition=(CClientPosition *)(pLastFoundInSearchByClientAndInstrument->pObject);
		if (theClientPosition->HashClientAndInstrument != compareObject.HashClientAndInstrument)
		{
			continue;
		}
		if (compare(theClientPosition->ClientID.getValue(),ClientID.getValue())!=0)
		{
			continue;
		}
		if (compare(theClientPosition->InstrumentID.getValue(),InstrumentID.getValue())!=0)
		{
			continue;
		}
		if (compare(theClientPosition->PosiDirection.getValue(),PosiDirection.getValue())!=0)
		{
			continue;
		}
		if (compare(theClientPosition->HedgeFlag.getValue(),HedgeFlag.getValue())!=0)
		{
			continue;
		}
		return theClientPosition;
	}
	return NULL;
}

CClientPosition *CClientPositionFactory::findNextByClientAndInstrument(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByClientAndInstrument==NULL)
	{
		return NULL;
	}

	CClientPosition *theClientPosition;
	

	
	for (;;)
	{
		pLastFoundInSearchByClientAndInstrument=pClientAndInstrumentHashIndex->searchNextEqual(pLastFoundInSearchByClientAndInstrument);
		if (pLastFoundInSearchByClientAndInstrument==NULL)
		{
			return NULL;
		}
		theClientPosition=(CClientPosition *)(pLastFoundInSearchByClientAndInstrument->pObject);
		if (theClientPosition->HashClientAndInstrument != compareObject.HashClientAndInstrument)
		{
			continue;
		}
		if (compare(theClientPosition->ClientID.getValue(),compareObject.ClientID.getValue())!=0)
		{
			continue;
		}
		if (compare(theClientPosition->InstrumentID.getValue(),compareObject.InstrumentID.getValue())!=0)
		{
			continue;
		}
		if (compare(theClientPosition->PosiDirection.getValue(),compareObject.PosiDirection.getValue())!=0)
		{
			continue;
		}
		if (compare(theClientPosition->HedgeFlag.getValue(),compareObject.HedgeFlag.getValue())!=0)
		{
			continue;
		}
		return theClientPosition;
	}
	return NULL;
}

void CClientPositionFactory::endFindByClientAndInstrument(void)
{
	pLastFoundInSearchByClientAndInstrument=NULL;
}


#ifdef COUNT_SEARCH
int multiFindStartByParticipantForClientPosition=0;
#endif

CClientPosition *CClientPositionFactory::startFindStartByParticipant( const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByParticipant of CClientPosition while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByParticipant!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByParticipant();
	}

	///记录所有的查询值
	queryParticipantIDInSearchStartByParticipant= ParticipantID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByParticipantForClientPosition++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CClientPosition *theClientPosition;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.ClientID="";
	compareObject.InstrumentID="";
	compareObject.PosiDirection=PD_Net;
	compareObject.HedgeFlag=HF_Speculation;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByParticipant=pPartClientAndInstumentIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByParticipant==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theClientPosition=(CClientPosition *)(pLastFoundInSearchStartByParticipant->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theClientPosition;
}

CClientPosition *CClientPositionFactory::findNextStartByParticipant(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByParticipant==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByParticipantForClientPosition++;
#endif
	CClientPosition *theClientPosition;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByParticipant=pPartClientAndInstumentIndex->getNextNode(pLastFoundInSearchStartByParticipant);
	if (pLastFoundInSearchStartByParticipant==NULL)
	{
		return NULL;
	}

	theClientPosition=(CClientPosition *)(pLastFoundInSearchStartByParticipant->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theClientPosition;
}

void CClientPositionFactory::endFindStartByParticipant(void)
{
	pLastFoundInSearchStartByParticipant=NULL;
}


#ifdef COUNT_SEARCH
int multiFindStartByClientForClientPosition=0;
#endif

CClientPosition *CClientPositionFactory::startFindStartByClient( const CReadOnlyClientIDType& ClientID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByClient of CClientPosition while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByClient!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByClient();
	}

	///记录所有的查询值
	queryClientIDInSearchStartByClient= ClientID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByClientForClientPosition++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CClientPosition *theClientPosition;
	compareObject.ClientID=ClientID.getValue();
	compareObject.ParticipantID="";
	compareObject.InstrumentID="";
	compareObject.PosiDirection=PD_Net;
	compareObject.HedgeFlag=HF_Speculation;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByClient=pClientAndInstumentIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByClient==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theClientPosition=(CClientPosition *)(pLastFoundInSearchStartByClient->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theClientPosition;
}

CClientPosition *CClientPositionFactory::findNextStartByClient(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByClient==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByClientForClientPosition++;
#endif
	CClientPosition *theClientPosition;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByClient=pClientAndInstumentIndex->getNextNode(pLastFoundInSearchStartByClient);
	if (pLastFoundInSearchStartByClient==NULL)
	{
		return NULL;
	}

	theClientPosition=(CClientPosition *)(pLastFoundInSearchStartByClient->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theClientPosition;
}

void CClientPositionFactory::endFindStartByClient(void)
{
	pLastFoundInSearchStartByClient=NULL;
}


#ifdef COUNT_SEARCH
int multiFindStartByInstrumentForClientPosition=0;
#endif

CClientPosition *CClientPositionFactory::startFindStartByInstrument( const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByInstrument of CClientPosition while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByInstrument!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByInstrument();
	}

	///记录所有的查询值
	queryInstrumentIDInSearchStartByInstrument= InstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByInstrumentForClientPosition++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CClientPosition *theClientPosition;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ParticipantID="";
	compareObject.ClientID="";
	compareObject.PosiDirection=PD_Net;
	compareObject.HedgeFlag=HF_Speculation;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByInstrument=pInstumentIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByInstrument==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theClientPosition=(CClientPosition *)(pLastFoundInSearchStartByInstrument->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theClientPosition;
}

CClientPosition *CClientPositionFactory::findNextStartByInstrument(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByInstrument==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByInstrumentForClientPosition++;
#endif
	CClientPosition *theClientPosition;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByInstrument=pInstumentIndex->getNextNode(pLastFoundInSearchStartByInstrument);
	if (pLastFoundInSearchStartByInstrument==NULL)
	{
		return NULL;
	}

	theClientPosition=(CClientPosition *)(pLastFoundInSearchStartByInstrument->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theClientPosition;
}

void CClientPositionFactory::endFindStartByInstrument(void)
{
	pLastFoundInSearchStartByInstrument=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByInstrumentIDForClientPosition=0;
#endif

CClientPosition *CClientPositionFactory::startFindByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByInstrumentID of CClientPosition while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByInstrumentID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByInstrumentID();
	}

	///记录所有的查询值
	queryInstrumentIDInSearchByInstrumentID= InstrumentID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchByInstrumentID=(CClientPosition *)(pMem->getFirst());
	
	if (pLastFoundInSearchByInstrumentID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextByInstrumentID来寻找下一个
	if (compare(pLastFoundInSearchByInstrumentID->InstrumentID.getValue(),InstrumentID.getValue()))
	{
		return findNextByInstrumentID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchByInstrumentID;
}

CClientPosition *CClientPositionFactory::findNextByInstrumentID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByInstrumentID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchByInstrumentID=(CClientPosition *)(pMem->getNext());
		if (pLastFoundInSearchByInstrumentID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchByInstrumentID->InstrumentID,queryInstrumentIDInSearchByInstrumentID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchByInstrumentID;
	}
}

void CClientPositionFactory::endFindByInstrumentID(void)
{
	pLastFoundInSearchByInstrumentID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForClientPosition=0;
#endif

CClientPosition *CClientPositionFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CClientPosition while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CClientPosition *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CClientPosition *CClientPositionFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CClientPosition *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CClientPositionFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}

int compareForPartClientAndInstrumentIndexinHedgeVolume(const void *pV1, const void *pV2)
{
	CHedgeVolume *p1,*p2;
	p1=(CHedgeVolume *)pV1;
	p2=(CHedgeVolume *)pV2;
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
int multiFindBySettlementGroupIDForHedgeVolume=0;
#endif

CHedgeVolume *CHedgeVolumeFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CHedgeVolume while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CHedgeVolume *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CHedgeVolume *CHedgeVolumeFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CHedgeVolume *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CHedgeVolumeFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentPartClientForHedgeVolume=0;
#endif
CHedgeVolume *CHedgeVolumeFactory::findByInstrumentPartClient( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentPartClient of CHedgeVolume while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentPartClientForHedgeVolume++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.ClientID=ClientID.getValue();
	pNode=pPartClientAndInstrumentIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CHedgeVolume *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindStartByPartClientAndInstrumentForHedgeVolume=0;
#endif

CHedgeVolume *CHedgeVolumeFactory::startFindStartByPartClientAndInstrument( const CReadOnlyParticipantIDType& ParticipantID,  const CReadOnlyClientIDType& ClientID,  const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByPartClientAndInstrument of CHedgeVolume while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByPartClientAndInstrument!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByPartClientAndInstrument();
	}

	///记录所有的查询值
	queryParticipantIDInSearchStartByPartClientAndInstrument= ParticipantID.getValue();
	queryClientIDInSearchStartByPartClientAndInstrument= ClientID.getValue();
	queryInstrumentIDInSearchStartByPartClientAndInstrument= InstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByPartClientAndInstrumentForHedgeVolume++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CHedgeVolume *theHedgeVolume;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.ClientID=ClientID.getValue();
	compareObject.InstrumentID=InstrumentID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByPartClientAndInstrument=pPartClientAndInstrumentIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByPartClientAndInstrument==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theHedgeVolume=(CHedgeVolume *)(pLastFoundInSearchStartByPartClientAndInstrument->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theHedgeVolume;
}

CHedgeVolume *CHedgeVolumeFactory::findNextStartByPartClientAndInstrument(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByPartClientAndInstrument==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByPartClientAndInstrumentForHedgeVolume++;
#endif
	CHedgeVolume *theHedgeVolume;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByPartClientAndInstrument=pPartClientAndInstrumentIndex->getNextNode(pLastFoundInSearchStartByPartClientAndInstrument);
	if (pLastFoundInSearchStartByPartClientAndInstrument==NULL)
	{
		return NULL;
	}

	theHedgeVolume=(CHedgeVolume *)(pLastFoundInSearchStartByPartClientAndInstrument->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theHedgeVolume;
}

void CHedgeVolumeFactory::endFindStartByPartClientAndInstrument(void)
{
	pLastFoundInSearchStartByPartClientAndInstrument=NULL;
}

int compareForInstrumentIDIndexinRemainOrder(const void *pV1, const void *pV2)
{
	CRemainOrder *p1,*p2;
	p1=(CRemainOrder *)pV1;
	p2=(CRemainOrder *)pV2;
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
int multiFindBySettlementGroupIDForRemainOrder=0;
#endif

CRemainOrder *CRemainOrderFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CRemainOrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CRemainOrder *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CRemainOrder *CRemainOrderFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CRemainOrder *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CRemainOrderFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByInstrumentIDForRemainOrder=0;
#endif

CRemainOrder *CRemainOrderFactory::startFindByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByInstrumentID of CRemainOrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByInstrumentID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByInstrumentID();
	}

	///记录所有的查询值
	queryInstrumentIDInSearchByInstrumentID= InstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindByInstrumentIDForRemainOrder++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CRemainOrder *theRemainOrder;
	compareObject.InstrumentID=InstrumentID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByInstrumentID=pInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByInstrumentID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theRemainOrder=(CRemainOrder *)(pLastFoundInSearchByInstrumentID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theRemainOrder->InstrumentID.getValue(),InstrumentID.getValue()))
	{
		pLastFoundInSearchByInstrumentID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theRemainOrder;
}

CRemainOrder *CRemainOrderFactory::findNextByInstrumentID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByInstrumentID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByInstrumentIDForRemainOrder++;
#endif
	CRemainOrder *theRemainOrder;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByInstrumentID=pInstrumentIDIndex->getNextNode(pLastFoundInSearchByInstrumentID);
	if (pLastFoundInSearchByInstrumentID==NULL)
	{
		return NULL;
	}

	theRemainOrder=(CRemainOrder *)(pLastFoundInSearchByInstrumentID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theRemainOrder->InstrumentID,queryInstrumentIDInSearchByInstrumentID))
	{
		pLastFoundInSearchByInstrumentID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theRemainOrder;
}

void CRemainOrderFactory::endFindByInstrumentID(void)
{
	pLastFoundInSearchByInstrumentID=NULL;
}

int compareForInstrumentIDIndexinMarketData(const void *pV1, const void *pV2)
{
	CMarketData *p1,*p2;
	p1=(CMarketData *)pV1;
	p2=(CMarketData *)pV2;
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
int multiFindBySettlementGroupIDForMarketData=0;
#endif

CMarketData *CMarketDataFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CMarketData while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CMarketData *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CMarketData *CMarketDataFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CMarketData *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CMarketDataFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentIDForMarketData=0;
#endif
CMarketData *CMarketDataFactory::findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentID of CMarketData while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentIDForMarketData++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CMarketData *)(pNode->pObject);
}

CMarketData *CMarketDataFactory::findByPK( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	return findByInstrumentID(InstrumentID);
}
	
CMarketData *CMarketDataFactory::findByPK(CWriteableMarketData *pMarketData)
{
	return findByPK(
		pMarketData->InstrumentID
		);
}

bool CMarketDataFactory::retrieveByPK(CWriteableMarketData *pMarketData)
{
	CMarketData *pOriginalMarketData;
	pOriginalMarketData=findByPK(pMarketData);
	if (pOriginalMarketData==NULL)
	{
		return false;
	}
	retrieve(pOriginalMarketData,pMarketData);
	return true;
}

CMarketData *CMarketDataFactory::addByPK(CWriteableMarketData *pMarketData, CTransaction *pTransaction)
{
	CMarketData *pOriginalMarketData;
	pOriginalMarketData=findByPK(pMarketData);
	if (pOriginalMarketData != NULL)
	{
		return NULL;
	}
	return add(pMarketData,pTransaction);
}

bool CMarketDataFactory::updateByPK(CWriteableMarketData *pMarketData, CTransaction *pTransaction, bool updateIndex)
{
	CMarketData *pOriginalMarketData;
	pOriginalMarketData=findByPK(pMarketData);
	if (pOriginalMarketData==NULL)
	{
		return false;
	}
	pMarketData->calAllHash();
	update(pOriginalMarketData,pMarketData,pTransaction,updateIndex);
	return true;
}

bool CMarketDataFactory::removeByPK(CWriteableMarketData *pMarketData, CTransaction *pTransaction)
{
	CMarketData *pOriginalMarketData;
	pOriginalMarketData=findByPK(pMarketData);
	if (pOriginalMarketData==NULL)
	{
		return false;
	}
	remove(pOriginalMarketData,pTransaction);
	return true;
}



#ifdef COUNT_SEARCH
int findByPartAndInstrumentForClearingPartPosition=0;
#endif
CClearingPartPosition *CClearingPartPositionFactory::findByPartAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyPosiDirectionType&  PosiDirection,  const CReadOnlyHedgeFlagType&  HedgeFlag,  const CReadOnlyTradingRoleType&  TradingRole)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByPartAndInstrument of CClearingPartPosition while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.PosiDirection=PosiDirection.getValue();
	compareObject.HedgeFlag=HedgeFlag.getValue();
	compareObject.TradingRole=TradingRole.getValue();
	
	compareObject.calHashPartAndInstrument();
	for (pNode=pPartAndInstrumentHashIndex->searchFirstEqual(compareObject.HashPartAndInstrument);
		pNode!=NULL;
		pNode=pPartAndInstrumentHashIndex->searchNextEqual(pNode))
	{
		if (((CClearingPartPosition *)(pNode->pObject))->HashPartAndInstrument != compareObject.HashPartAndInstrument)
		{
			continue;
		}
		if (compare(((CClearingPartPosition *)(pNode->pObject))->ParticipantID.getValue(),ParticipantID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CClearingPartPosition *)(pNode->pObject))->InstrumentID.getValue(),InstrumentID.getValue())!=0)
		{
			continue;
		}
		if (compare(((CClearingPartPosition *)(pNode->pObject))->PosiDirection.getValue(),PosiDirection.getValue())!=0)
		{
			continue;
		}
		if (compare(((CClearingPartPosition *)(pNode->pObject))->HedgeFlag.getValue(),HedgeFlag.getValue())!=0)
		{
			continue;
		}
		if (compare(((CClearingPartPosition *)(pNode->pObject))->TradingRole.getValue(),TradingRole.getValue())!=0)
		{
			continue;
		}
		return (CClearingPartPosition *)(pNode->pObject);
	}
	return NULL;
}



#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForClearingPartPosition=0;
#endif

CClearingPartPosition *CClearingPartPositionFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CClearingPartPosition while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CClearingPartPosition *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CClearingPartPosition *CClearingPartPositionFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CClearingPartPosition *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CClearingPartPositionFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}

int compareForInstrumentIDIndexinInstrumentStatus(const void *pV1, const void *pV2)
{
	CInstrumentStatus *p1,*p2;
	p1=(CInstrumentStatus *)pV1;
	p2=(CInstrumentStatus *)pV2;
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
int findByInstrumentIDForInstrumentStatus=0;
#endif
CInstrumentStatus *CInstrumentStatusFactory::findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentID of CInstrumentStatus while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentIDForInstrumentStatus++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CInstrumentStatus *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindStartByInstrumentIDForInstrumentStatus=0;
#endif

CInstrumentStatus *CInstrumentStatusFactory::startFindStartByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByInstrumentID of CInstrumentStatus while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByInstrumentID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByInstrumentID();
	}

	///记录所有的查询值
	queryInstrumentIDInSearchStartByInstrumentID= InstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByInstrumentIDForInstrumentStatus++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CInstrumentStatus *theInstrumentStatus;
	compareObject.InstrumentID=InstrumentID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByInstrumentID=pInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByInstrumentID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theInstrumentStatus=(CInstrumentStatus *)(pLastFoundInSearchStartByInstrumentID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theInstrumentStatus;
}

CInstrumentStatus *CInstrumentStatusFactory::findNextStartByInstrumentID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByInstrumentID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByInstrumentIDForInstrumentStatus++;
#endif
	CInstrumentStatus *theInstrumentStatus;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByInstrumentID=pInstrumentIDIndex->getNextNode(pLastFoundInSearchStartByInstrumentID);
	if (pLastFoundInSearchStartByInstrumentID==NULL)
	{
		return NULL;
	}

	theInstrumentStatus=(CInstrumentStatus *)(pLastFoundInSearchStartByInstrumentID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theInstrumentStatus;
}

void CInstrumentStatusFactory::endFindStartByInstrumentID(void)
{
	pLastFoundInSearchStartByInstrumentID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForInstrumentStatus=0;
#endif

CInstrumentStatus *CInstrumentStatusFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CInstrumentStatus while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CInstrumentStatus *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CInstrumentStatus *CInstrumentStatusFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CInstrumentStatus *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CInstrumentStatusFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}

int compareForParticipantIDIndexinOrder(const void *pV1, const void *pV2)
{
	COrder *p1,*p2;
	p1=(COrder *)pV1;
	p2=(COrder *)pV2;
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
int compareForOrderLocalIDIndexinOrder(const void *pV1, const void *pV2)
{
	COrder *p1,*p2;
	p1=(COrder *)pV1;
	p2=(COrder *)pV2;
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
	switch (compare(p1->OrderLocalID.getValue(),p2->OrderLocalID.getValue()))
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
int compareForInstrumentIDIndexinOrder(const void *pV1, const void *pV2)
{
	COrder *p1,*p2;
	p1=(COrder *)pV1;
	p2=(COrder *)pV2;
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
int findByOrderIDForOrder=0;
#endif
COrder *COrderFactory::findByOrderID( const CReadOnlyOrderSysIDType&  OrderSysID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOrderID of COrder while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.OrderSysID=OrderSysID.getValue();
	
	compareObject.calHashOrderSysID();
	for (pNode=pOrderSysIDHashIndex->searchFirstEqual(compareObject.HashOrderSysID);
		pNode!=NULL;
		pNode=pOrderSysIDHashIndex->searchNextEqual(pNode))
	{
		if (((COrder *)(pNode->pObject))->HashOrderSysID != compareObject.HashOrderSysID)
		{
			continue;
		}
		if (compare(((COrder *)(pNode->pObject))->OrderSysID.getValue(),OrderSysID.getValue())!=0)
		{
			continue;
		}
		return (COrder *)(pNode->pObject);
	}
	return NULL;
}



#ifdef COUNT_SEARCH
int multiFindStartByParticipantIDForOrder=0;
#endif

COrder *COrderFactory::startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByParticipantID of COrder while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByParticipantID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByParticipantID();
	}

	///记录所有的查询值
	queryParticipantIDInSearchStartByParticipantID= ParticipantID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForOrder++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	COrder *theOrder;
	compareObject.ParticipantID=ParticipantID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByParticipantID=pParticipantIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theOrder=(COrder *)(pLastFoundInSearchStartByParticipantID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theOrder;
}

COrder *COrderFactory::findNextStartByParticipantID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForOrder++;
#endif
	COrder *theOrder;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByParticipantID=pParticipantIDIndex->getNextNode(pLastFoundInSearchStartByParticipantID);
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

	theOrder=(COrder *)(pLastFoundInSearchStartByParticipantID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theOrder;
}

void COrderFactory::endFindStartByParticipantID(void)
{
	pLastFoundInSearchStartByParticipantID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForOrder=0;
#endif

COrder *COrderFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of COrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(COrder *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

COrder *COrderFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(COrder *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void COrderFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByOrderLocalIDForOrder=0;
#endif
COrder *COrderFactory::findByOrderLocalID( const CReadOnlyUserIDType&  UserID,  const CReadOnlyOrderLocalIDType&  OrderLocalID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOrderLocalID of COrder while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOrderLocalIDForOrder++;
#endif
	CAVLNode *pNode;
	compareObject.UserID=UserID.getValue();
	compareObject.OrderLocalID=OrderLocalID.getValue();
	pNode=pOrderLocalIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (COrder *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByUserIDForOrder=0;
#endif

COrder *COrderFactory::startFindByUserID( const CReadOnlyUserIDType& UserID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByUserID of COrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByUserID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByUserID();
	}

	///记录所有的查询值
	queryUserIDInSearchByUserID= UserID.getValue();

#ifdef COUNT_SEARCH
	multiFindByUserIDForOrder++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	COrder *theOrder;
	compareObject.UserID=UserID.getValue();
	compareObject.OrderLocalID="zzzzzzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByUserID=pOrderLocalIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theOrder=(COrder *)(pLastFoundInSearchByUserID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theOrder->UserID.getValue(),UserID.getValue()))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theOrder;
}

COrder *COrderFactory::findNextByUserID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByUserIDForOrder++;
#endif
	COrder *theOrder;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByUserID=pOrderLocalIDIndex->getNextNode(pLastFoundInSearchByUserID);
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

	theOrder=(COrder *)(pLastFoundInSearchByUserID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theOrder->UserID,queryUserIDInSearchByUserID))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theOrder;
}

void COrderFactory::endFindByUserID(void)
{
	pLastFoundInSearchByUserID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByInstrumentIDForOrder=0;
#endif

COrder *COrderFactory::startFindByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByInstrumentID of COrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByInstrumentID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByInstrumentID();
	}

	///记录所有的查询值
	queryInstrumentIDInSearchByInstrumentID= InstrumentID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchByInstrumentID=(COrder *)(pMem->getFirst());
	
	if (pLastFoundInSearchByInstrumentID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextByInstrumentID来寻找下一个
	if (compare(pLastFoundInSearchByInstrumentID->InstrumentID.getValue(),InstrumentID.getValue()))
	{
		return findNextByInstrumentID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchByInstrumentID;
}

COrder *COrderFactory::findNextByInstrumentID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByInstrumentID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchByInstrumentID=(COrder *)(pMem->getNext());
		if (pLastFoundInSearchByInstrumentID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchByInstrumentID->InstrumentID,queryInstrumentIDInSearchByInstrumentID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchByInstrumentID;
	}
}

void COrderFactory::endFindByInstrumentID(void)
{
	pLastFoundInSearchByInstrumentID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindStartByInstrumentIDForOrder=0;
#endif

COrder *COrderFactory::startFindStartByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByInstrumentID of COrder while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByInstrumentID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByInstrumentID();
	}

	///记录所有的查询值
	queryInstrumentIDInSearchStartByInstrumentID= InstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByInstrumentIDForOrder++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	COrder *theOrder;
	compareObject.InstrumentID=InstrumentID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByInstrumentID=pInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByInstrumentID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theOrder=(COrder *)(pLastFoundInSearchStartByInstrumentID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theOrder;
}

COrder *COrderFactory::findNextStartByInstrumentID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByInstrumentID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByInstrumentIDForOrder++;
#endif
	COrder *theOrder;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByInstrumentID=pInstrumentIDIndex->getNextNode(pLastFoundInSearchStartByInstrumentID);
	if (pLastFoundInSearchStartByInstrumentID==NULL)
	{
		return NULL;
	}

	theOrder=(COrder *)(pLastFoundInSearchStartByInstrumentID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theOrder;
}

void COrderFactory::endFindStartByInstrumentID(void)
{
	pLastFoundInSearchStartByInstrumentID=NULL;
}

int compareForParticipantIDIndexinCombOrder(const void *pV1, const void *pV2)
{
	CCombOrder *p1,*p2;
	p1=(CCombOrder *)pV1;
	p2=(CCombOrder *)pV2;
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
int compareForCombOrderLocalIDIndexinCombOrder(const void *pV1, const void *pV2)
{
	CCombOrder *p1,*p2;
	p1=(CCombOrder *)pV1;
	p2=(CCombOrder *)pV2;
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
	switch (compare(p1->CombOrderLocalID.getValue(),p2->CombOrderLocalID.getValue()))
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
int findByCombOrderIDForCombOrder=0;
#endif
CCombOrder *CCombOrderFactory::findByCombOrderID( const CReadOnlyOrderSysIDType&  CombOrderSysID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByCombOrderID of CCombOrder while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.CombOrderSysID=CombOrderSysID.getValue();
	
	compareObject.calHashCombOrderSysID();
	for (pNode=pCombOrderSysIDHashIndex->searchFirstEqual(compareObject.HashCombOrderSysID);
		pNode!=NULL;
		pNode=pCombOrderSysIDHashIndex->searchNextEqual(pNode))
	{
		if (((CCombOrder *)(pNode->pObject))->HashCombOrderSysID != compareObject.HashCombOrderSysID)
		{
			continue;
		}
		if (compare(((CCombOrder *)(pNode->pObject))->CombOrderSysID.getValue(),CombOrderSysID.getValue())!=0)
		{
			continue;
		}
		return (CCombOrder *)(pNode->pObject);
	}
	return NULL;
}



#ifdef COUNT_SEARCH
int multiFindStartByParticipantIDForCombOrder=0;
#endif

CCombOrder *CCombOrderFactory::startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByParticipantID of CCombOrder while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByParticipantID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByParticipantID();
	}

	///记录所有的查询值
	queryParticipantIDInSearchStartByParticipantID= ParticipantID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForCombOrder++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CCombOrder *theCombOrder;
	compareObject.ParticipantID=ParticipantID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByParticipantID=pParticipantIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theCombOrder=(CCombOrder *)(pLastFoundInSearchStartByParticipantID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theCombOrder;
}

CCombOrder *CCombOrderFactory::findNextStartByParticipantID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForCombOrder++;
#endif
	CCombOrder *theCombOrder;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByParticipantID=pParticipantIDIndex->getNextNode(pLastFoundInSearchStartByParticipantID);
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

	theCombOrder=(CCombOrder *)(pLastFoundInSearchStartByParticipantID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theCombOrder;
}

void CCombOrderFactory::endFindStartByParticipantID(void)
{
	pLastFoundInSearchStartByParticipantID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForCombOrder=0;
#endif

CCombOrder *CCombOrderFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCombOrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCombOrder *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCombOrder *CCombOrderFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCombOrder *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCombOrderFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByCombOrderLocalIDForCombOrder=0;
#endif
CCombOrder *CCombOrderFactory::findByCombOrderLocalID( const CReadOnlyUserIDType&  UserID,  const CReadOnlyOrderLocalIDType&  CombOrderLocalID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByCombOrderLocalID of CCombOrder while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByCombOrderLocalIDForCombOrder++;
#endif
	CAVLNode *pNode;
	compareObject.UserID=UserID.getValue();
	compareObject.CombOrderLocalID=CombOrderLocalID.getValue();
	pNode=pCombOrderLocalIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CCombOrder *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByUserIDForCombOrder=0;
#endif

CCombOrder *CCombOrderFactory::startFindByUserID( const CReadOnlyUserIDType& UserID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByUserID of CCombOrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByUserID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByUserID();
	}

	///记录所有的查询值
	queryUserIDInSearchByUserID= UserID.getValue();

#ifdef COUNT_SEARCH
	multiFindByUserIDForCombOrder++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CCombOrder *theCombOrder;
	compareObject.UserID=UserID.getValue();
	compareObject.CombOrderLocalID="zzzzzzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByUserID=pCombOrderLocalIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theCombOrder=(CCombOrder *)(pLastFoundInSearchByUserID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theCombOrder->UserID.getValue(),UserID.getValue()))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theCombOrder;
}

CCombOrder *CCombOrderFactory::findNextByUserID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByUserIDForCombOrder++;
#endif
	CCombOrder *theCombOrder;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByUserID=pCombOrderLocalIDIndex->getNextNode(pLastFoundInSearchByUserID);
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

	theCombOrder=(CCombOrder *)(pLastFoundInSearchByUserID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theCombOrder->UserID,queryUserIDInSearchByUserID))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theCombOrder;
}

void CCombOrderFactory::endFindByUserID(void)
{
	pLastFoundInSearchByUserID=NULL;
}

int compareForOTCOrderIDIndexinOTCOrder(const void *pV1, const void *pV2)
{
	COTCOrder *p1,*p2;
	p1=(COTCOrder *)pV1;
	p2=(COTCOrder *)pV2;
	switch (compare(p1->OTCOrderSysID.getValue(),p2->OTCOrderSysID.getValue()))
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
int compareForOTCOrderLocalIDIndexinOTCOrder(const void *pV1, const void *pV2)
{
	COTCOrder *p1,*p2;
	p1=(COTCOrder *)pV1;
	p2=(COTCOrder *)pV2;
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
	switch (compare(p1->OTCOrderLocalID.getValue(),p2->OTCOrderLocalID.getValue()))
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
int findByOTCOrderLocalIDForOTCOrder=0;
#endif
COTCOrder *COTCOrderFactory::findByOTCOrderLocalID( const CReadOnlyUserIDType&  UserID,  const CReadOnlyOrderLocalIDType&  OTCOrderLocalID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOTCOrderLocalID of COTCOrder while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOTCOrderLocalIDForOTCOrder++;
#endif
	CAVLNode *pNode;
	compareObject.UserID=UserID.getValue();
	compareObject.OTCOrderLocalID=OTCOrderLocalID.getValue();
	pNode=pOTCOrderLocalIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (COTCOrder *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int findByOTCOrderIDForOTCOrder=0;
#endif
COTCOrder *COTCOrderFactory::findByOTCOrderID( const CReadOnlyOTCOrderSysIDType&  OTCOrderSysID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOTCOrderID of COTCOrder while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOTCOrderIDForOTCOrder++;
#endif
	CAVLNode *pNode;
	compareObject.OTCOrderSysID=OTCOrderSysID.getValue();
	pNode=pOTCOrderIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (COTCOrder *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForOTCOrder=0;
#endif

COTCOrder *COTCOrderFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of COTCOrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(COTCOrder *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

COTCOrder *COTCOrderFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(COTCOrder *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void COTCOrderFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}

int compareForImplyLegInstrumentIndexinImplyOrder(const void *pV1, const void *pV2)
{
	CImplyOrder *p1,*p2;
	p1=(CImplyOrder *)pV1;
	p2=(CImplyOrder *)pV2;
	switch (compare(p1->CombInstrumentID.getValue(),p2->CombInstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->ImplyLegID.getValue(),p2->ImplyLegID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->Direction.getValue(),p2->Direction.getValue()))
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
int compareForImplyOrderAndAnchorLegIndexinImplyOrder(const void *pV1, const void *pV2)
{
	CImplyOrder *p1,*p2;
	p1=(CImplyOrder *)pV1;
	p2=(CImplyOrder *)pV2;
	switch (compare(p1->ImplyOrderID.getValue(),p2->ImplyOrderID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->AnchorLegID.getValue(),p2->AnchorLegID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->Priority.getValue(),p2->Priority.getValue()))
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
int multiFindByImplyLegForImplyOrder=0;
#endif

CImplyOrder *CImplyOrderFactory::startFindByImplyLeg( const CReadOnlyInstrumentIDType& CombInstrumentID,  const CReadOnlyLegIDType& ImplyLegID,  const CReadOnlyDirectionType& Direction)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByImplyLeg of CImplyOrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByImplyLeg!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByImplyLeg();
	}

	///记录所有的查询值
	queryCombInstrumentIDInSearchByImplyLeg= CombInstrumentID.getValue();
	queryImplyLegIDInSearchByImplyLeg= ImplyLegID.getValue();
	queryDirectionInSearchByImplyLeg= Direction.getValue();

#ifdef COUNT_SEARCH
	multiFindByImplyLegForImplyOrder++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CImplyOrder *theImplyOrder;
	compareObject.CombInstrumentID=CombInstrumentID.getValue();
	compareObject.ImplyLegID=ImplyLegID.getValue();
	compareObject.Direction=Direction.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByImplyLeg=pImplyLegInstrumentIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByImplyLeg==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theImplyOrder=(CImplyOrder *)(pLastFoundInSearchByImplyLeg->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theImplyOrder->CombInstrumentID.getValue(),CombInstrumentID.getValue()))
	{
		pLastFoundInSearchByImplyLeg=NULL;
		return NULL;
	}
	if (compare(theImplyOrder->ImplyLegID.getValue(),ImplyLegID.getValue()))
	{
		pLastFoundInSearchByImplyLeg=NULL;
		return NULL;
	}
	if (compare(theImplyOrder->Direction.getValue(),Direction.getValue()))
	{
		pLastFoundInSearchByImplyLeg=NULL;
		return NULL;
	}

	///返回找到的结果
	return theImplyOrder;
}

CImplyOrder *CImplyOrderFactory::findNextByImplyLeg(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByImplyLeg==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByImplyLegForImplyOrder++;
#endif
	CImplyOrder *theImplyOrder;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByImplyLeg=pImplyLegInstrumentIndex->getNextNode(pLastFoundInSearchByImplyLeg);
	if (pLastFoundInSearchByImplyLeg==NULL)
	{
		return NULL;
	}

	theImplyOrder=(CImplyOrder *)(pLastFoundInSearchByImplyLeg->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theImplyOrder->CombInstrumentID,queryCombInstrumentIDInSearchByImplyLeg))
	{
		pLastFoundInSearchByImplyLeg=NULL;
		return NULL;
	}
	if (compare(theImplyOrder->ImplyLegID,queryImplyLegIDInSearchByImplyLeg))
	{
		pLastFoundInSearchByImplyLeg=NULL;
		return NULL;
	}
	if (compare(theImplyOrder->Direction,queryDirectionInSearchByImplyLeg))
	{
		pLastFoundInSearchByImplyLeg=NULL;
		return NULL;
	}

	///返回找到的结果
	return theImplyOrder;
}

void CImplyOrderFactory::endFindByImplyLeg(void)
{
	pLastFoundInSearchByImplyLeg=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByImplyOrderAndAnchorLegForImplyOrder=0;
#endif

CImplyOrder *CImplyOrderFactory::startFindByImplyOrderAndAnchorLeg( const CReadOnlyOrderSysIDType& ImplyOrderID,  const CReadOnlyLegIDType& AnchorLegID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByImplyOrderAndAnchorLeg of CImplyOrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByImplyOrderAndAnchorLeg!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByImplyOrderAndAnchorLeg();
	}

	///记录所有的查询值
	queryImplyOrderIDInSearchByImplyOrderAndAnchorLeg= ImplyOrderID.getValue();
	queryAnchorLegIDInSearchByImplyOrderAndAnchorLeg= AnchorLegID.getValue();

#ifdef COUNT_SEARCH
	multiFindByImplyOrderAndAnchorLegForImplyOrder++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CImplyOrder *theImplyOrder;
	compareObject.ImplyOrderID=ImplyOrderID.getValue();
	compareObject.AnchorLegID=AnchorLegID.getValue();
	compareObject.Priority=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByImplyOrderAndAnchorLeg=pImplyOrderAndAnchorLegIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByImplyOrderAndAnchorLeg==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theImplyOrder=(CImplyOrder *)(pLastFoundInSearchByImplyOrderAndAnchorLeg->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theImplyOrder->ImplyOrderID.getValue(),ImplyOrderID.getValue()))
	{
		pLastFoundInSearchByImplyOrderAndAnchorLeg=NULL;
		return NULL;
	}
	if (compare(theImplyOrder->AnchorLegID.getValue(),AnchorLegID.getValue()))
	{
		pLastFoundInSearchByImplyOrderAndAnchorLeg=NULL;
		return NULL;
	}

	///返回找到的结果
	return theImplyOrder;
}

CImplyOrder *CImplyOrderFactory::findNextByImplyOrderAndAnchorLeg(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByImplyOrderAndAnchorLeg==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByImplyOrderAndAnchorLegForImplyOrder++;
#endif
	CImplyOrder *theImplyOrder;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByImplyOrderAndAnchorLeg=pImplyOrderAndAnchorLegIndex->getNextNode(pLastFoundInSearchByImplyOrderAndAnchorLeg);
	if (pLastFoundInSearchByImplyOrderAndAnchorLeg==NULL)
	{
		return NULL;
	}

	theImplyOrder=(CImplyOrder *)(pLastFoundInSearchByImplyOrderAndAnchorLeg->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theImplyOrder->ImplyOrderID,queryImplyOrderIDInSearchByImplyOrderAndAnchorLeg))
	{
		pLastFoundInSearchByImplyOrderAndAnchorLeg=NULL;
		return NULL;
	}
	if (compare(theImplyOrder->AnchorLegID,queryAnchorLegIDInSearchByImplyOrderAndAnchorLeg))
	{
		pLastFoundInSearchByImplyOrderAndAnchorLeg=NULL;
		return NULL;
	}

	///返回找到的结果
	return theImplyOrder;
}

void CImplyOrderFactory::endFindByImplyOrderAndAnchorLeg(void)
{
	pLastFoundInSearchByImplyOrderAndAnchorLeg=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByImplyOrderForImplyOrder=0;
#endif

CImplyOrder *CImplyOrderFactory::startFindByImplyOrder( const CReadOnlyOrderSysIDType& ImplyOrderID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByImplyOrder of CImplyOrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByImplyOrder!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByImplyOrder();
	}

	///记录所有的查询值
	queryImplyOrderIDInSearchByImplyOrder= ImplyOrderID.getValue();

#ifdef COUNT_SEARCH
	multiFindByImplyOrderForImplyOrder++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CImplyOrder *theImplyOrder;
	compareObject.ImplyOrderID=ImplyOrderID.getValue();
	compareObject.AnchorLegID=0;
	compareObject.Priority=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByImplyOrder=pImplyOrderAndAnchorLegIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByImplyOrder==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theImplyOrder=(CImplyOrder *)(pLastFoundInSearchByImplyOrder->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theImplyOrder->ImplyOrderID.getValue(),ImplyOrderID.getValue()))
	{
		pLastFoundInSearchByImplyOrder=NULL;
		return NULL;
	}

	///返回找到的结果
	return theImplyOrder;
}

CImplyOrder *CImplyOrderFactory::findNextByImplyOrder(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByImplyOrder==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByImplyOrderForImplyOrder++;
#endif
	CImplyOrder *theImplyOrder;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByImplyOrder=pImplyOrderAndAnchorLegIndex->getNextNode(pLastFoundInSearchByImplyOrder);
	if (pLastFoundInSearchByImplyOrder==NULL)
	{
		return NULL;
	}

	theImplyOrder=(CImplyOrder *)(pLastFoundInSearchByImplyOrder->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theImplyOrder->ImplyOrderID,queryImplyOrderIDInSearchByImplyOrder))
	{
		pLastFoundInSearchByImplyOrder=NULL;
		return NULL;
	}

	///返回找到的结果
	return theImplyOrder;
}

void CImplyOrderFactory::endFindByImplyOrder(void)
{
	pLastFoundInSearchByImplyOrder=NULL;
}

int compareForQuoteIDIndexinQuote(const void *pV1, const void *pV2)
{
	CQuote *p1,*p2;
	p1=(CQuote *)pV1;
	p2=(CQuote *)pV2;
	switch (compare(p1->QuoteSysID.getValue(),p2->QuoteSysID.getValue()))
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
int compareForPartClientAndInstrumentIndexinQuote(const void *pV1, const void *pV2)
{
	CQuote *p1,*p2;
	p1=(CQuote *)pV1;
	p2=(CQuote *)pV2;
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
	switch (compare(p1->QuoteSysID.getValue(),p2->QuoteSysID.getValue()))
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
int compareForQuoteLocalIDIndexinQuote(const void *pV1, const void *pV2)
{
	CQuote *p1,*p2;
	p1=(CQuote *)pV1;
	p2=(CQuote *)pV2;
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
	switch (compare(p1->QuoteLocalID.getValue(),p2->QuoteLocalID.getValue()))
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
int findByQuoteIDForQuote=0;
#endif
CQuote *CQuoteFactory::findByQuoteID( const CReadOnlyQuoteSysIDType&  QuoteSysID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByQuoteID of CQuote while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByQuoteIDForQuote++;
#endif
	CAVLNode *pNode;
	compareObject.QuoteSysID=QuoteSysID.getValue();
	pNode=pQuoteIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CQuote *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int findByQuoteLocalIDForQuote=0;
#endif
CQuote *CQuoteFactory::findByQuoteLocalID( const CReadOnlyUserIDType&  UserID,  const CReadOnlyOrderLocalIDType&  QuoteLocalID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByQuoteLocalID of CQuote while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByQuoteLocalIDForQuote++;
#endif
	CAVLNode *pNode;
	compareObject.UserID=UserID.getValue();
	compareObject.QuoteLocalID=QuoteLocalID.getValue();
	pNode=pQuoteLocalIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CQuote *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByUserIDForQuote=0;
#endif

CQuote *CQuoteFactory::startFindByUserID( const CReadOnlyUserIDType& UserID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByUserID of CQuote while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByUserID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByUserID();
	}

	///记录所有的查询值
	queryUserIDInSearchByUserID= UserID.getValue();

#ifdef COUNT_SEARCH
	multiFindByUserIDForQuote++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CQuote *theQuote;
	compareObject.UserID=UserID.getValue();
	compareObject.QuoteLocalID="zzzzzzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByUserID=pQuoteLocalIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theQuote=(CQuote *)(pLastFoundInSearchByUserID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theQuote->UserID.getValue(),UserID.getValue()))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theQuote;
}

CQuote *CQuoteFactory::findNextByUserID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByUserIDForQuote++;
#endif
	CQuote *theQuote;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByUserID=pQuoteLocalIDIndex->getNextNode(pLastFoundInSearchByUserID);
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

	theQuote=(CQuote *)(pLastFoundInSearchByUserID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theQuote->UserID,queryUserIDInSearchByUserID))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theQuote;
}

void CQuoteFactory::endFindByUserID(void)
{
	pLastFoundInSearchByUserID=NULL;
}


#ifdef COUNT_SEARCH
int findByPartClientAndInstrumentForQuote=0;
#endif
CQuote *CQuoteFactory::findByPartClientAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByPartClientAndInstrument of CQuote while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByPartClientAndInstrumentForQuote++;
#endif
	CAVLNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.ClientID=ClientID.getValue();
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.QuoteSysID="999999999999";
	pNode=pPartClientAndInstrumentIndex->searchFirstGreatEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	if (compare(((CQuote *)(pNode->pObject))->ParticipantID.getValue(),ParticipantID.getValue())!=0)
	{
		return NULL;
	}
	if (compare(((CQuote *)(pNode->pObject))->ClientID.getValue(),ClientID.getValue())!=0)
	{
		return NULL;
	}
	if (compare(((CQuote *)(pNode->pObject))->InstrumentID.getValue(),InstrumentID.getValue())!=0)
	{
		return NULL;
	}
	return (CQuote *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindStartByParticipantIDForQuote=0;
#endif

CQuote *CQuoteFactory::startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByParticipantID of CQuote while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByParticipantID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByParticipantID();
	}

	///记录所有的查询值
	queryParticipantIDInSearchStartByParticipantID= ParticipantID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForQuote++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CQuote *theQuote;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.QuoteSysID="999999999999";
	compareObject.InstrumentID="";
	compareObject.ClientID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByParticipantID=pPartClientAndInstrumentIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theQuote=(CQuote *)(pLastFoundInSearchStartByParticipantID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theQuote;
}

CQuote *CQuoteFactory::findNextStartByParticipantID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByParticipantIDForQuote++;
#endif
	CQuote *theQuote;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByParticipantID=pPartClientAndInstrumentIndex->getNextNode(pLastFoundInSearchStartByParticipantID);
	if (pLastFoundInSearchStartByParticipantID==NULL)
	{
		return NULL;
	}

	theQuote=(CQuote *)(pLastFoundInSearchStartByParticipantID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theQuote;
}

void CQuoteFactory::endFindStartByParticipantID(void)
{
	pLastFoundInSearchStartByParticipantID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForQuote=0;
#endif

CQuote *CQuoteFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CQuote while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CQuote *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CQuote *CQuoteFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CQuote *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CQuoteFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByAskOrderForQuote=0;
#endif
CQuote *CQuoteFactory::findByAskOrder( const CReadOnlyOrderSysIDType&  AskOrderSysID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByAskOrder of CQuote while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.AskOrderSysID=AskOrderSysID.getValue();
	
	compareObject.calHashAskOrderSysIDHashKey();
	for (pNode=pAskOrderHashIndex->searchFirstEqual(compareObject.HashAskOrderSysIDHashKey);
		pNode!=NULL;
		pNode=pAskOrderHashIndex->searchNextEqual(pNode))
	{
		if (((CQuote *)(pNode->pObject))->HashAskOrderSysIDHashKey != compareObject.HashAskOrderSysIDHashKey)
		{
			continue;
		}
		if (compare(((CQuote *)(pNode->pObject))->AskOrderSysID.getValue(),AskOrderSysID.getValue())!=0)
		{
			continue;
		}
		return (CQuote *)(pNode->pObject);
	}
	return NULL;
}



#ifdef COUNT_SEARCH
int findByBidOrderForQuote=0;
#endif
CQuote *CQuoteFactory::findByBidOrder( const CReadOnlyOrderSysIDType&  BidOrderSysID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByBidOrder of CQuote while run level < 0");
	}
	CHashIndexNode *pNode;
	compareObject.BidOrderSysID=BidOrderSysID.getValue();
	
	compareObject.calHashBidOrderSysIDHashKey();
	for (pNode=pBidOrderHashIndex->searchFirstEqual(compareObject.HashBidOrderSysIDHashKey);
		pNode!=NULL;
		pNode=pBidOrderHashIndex->searchNextEqual(pNode))
	{
		if (((CQuote *)(pNode->pObject))->HashBidOrderSysIDHashKey != compareObject.HashBidOrderSysIDHashKey)
		{
			continue;
		}
		if (compare(((CQuote *)(pNode->pObject))->BidOrderSysID.getValue(),BidOrderSysID.getValue())!=0)
		{
			continue;
		}
		return (CQuote *)(pNode->pObject);
	}
	return NULL;
}


int compareForBuyMBLIndexinMBLMarketData(const void *pV1, const void *pV2)
{
	CMBLMarketData *p1,*p2;
	p1=(CMBLMarketData *)pV1;
	p2=(CMBLMarketData *)pV2;
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
	switch (compare(p1->Direction.getValue(),p2->Direction.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->Price.getValue(),p2->Price.getValue()))
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
int compareForSellMBLIndexinMBLMarketData(const void *pV1, const void *pV2)
{
	CMBLMarketData *p1,*p2;
	p1=(CMBLMarketData *)pV1;
	p2=(CMBLMarketData *)pV2;
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
	switch (compare(p1->Direction.getValue(),p2->Direction.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->Price.getValue(),p2->Price.getValue()))
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
int compareForQBuyMBLIndexinMBLMarketData(const void *pV1, const void *pV2)
{
	CMBLMarketData *p1,*p2;
	p1=(CMBLMarketData *)pV1;
	p2=(CMBLMarketData *)pV2;
	switch (compare(p1->Direction.getValue(),p2->Direction.getValue()))
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
	switch (compare(p1->Price.getValue(),p2->Price.getValue()))
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
int compareForQSellMBLIndexinMBLMarketData(const void *pV1, const void *pV2)
{
	CMBLMarketData *p1,*p2;
	p1=(CMBLMarketData *)pV1;
	p2=(CMBLMarketData *)pV2;
	switch (compare(p1->Direction.getValue(),p2->Direction.getValue()))
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
	switch (compare(p1->Price.getValue(),p2->Price.getValue()))
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
int multiFindByBuyMBLDataForMBLMarketData=0;
#endif

CMBLMarketData *CMBLMarketDataFactory::startFindByBuyMBLData( const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByBuyMBLData of CMBLMarketData while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByBuyMBLData!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByBuyMBLData();
	}

	///记录所有的查询值
	queryInstrumentIDInSearchByBuyMBLData= InstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindByBuyMBLDataForMBLMarketData++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CMBLMarketData *theMBLMarketData;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.Direction=D_Buy;
	compareObject.Price=999999999;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByBuyMBLData=pBuyMBLIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByBuyMBLData==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theMBLMarketData=(CMBLMarketData *)(pLastFoundInSearchByBuyMBLData->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theMBLMarketData->InstrumentID.getValue(),InstrumentID.getValue()))
	{
		pLastFoundInSearchByBuyMBLData=NULL;
		return NULL;
	}
	if (compare(theMBLMarketData->Direction,D_Buy))
	{
		pLastFoundInSearchByBuyMBLData=NULL;
		return NULL;
	}

	///返回找到的结果
	return theMBLMarketData;
}

CMBLMarketData *CMBLMarketDataFactory::findNextByBuyMBLData(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByBuyMBLData==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByBuyMBLDataForMBLMarketData++;
#endif
	CMBLMarketData *theMBLMarketData;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByBuyMBLData=pBuyMBLIndex->getNextNode(pLastFoundInSearchByBuyMBLData);
	if (pLastFoundInSearchByBuyMBLData==NULL)
	{
		return NULL;
	}

	theMBLMarketData=(CMBLMarketData *)(pLastFoundInSearchByBuyMBLData->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theMBLMarketData->InstrumentID,queryInstrumentIDInSearchByBuyMBLData))
	{
		pLastFoundInSearchByBuyMBLData=NULL;
		return NULL;
	}
	if (compare(theMBLMarketData->Direction,D_Buy))
	{
		pLastFoundInSearchByBuyMBLData=NULL;
		return NULL;
	}

	///返回找到的结果
	return theMBLMarketData;
}

void CMBLMarketDataFactory::endFindByBuyMBLData(void)
{
	pLastFoundInSearchByBuyMBLData=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBySellMBLDataForMBLMarketData=0;
#endif

CMBLMarketData *CMBLMarketDataFactory::startFindBySellMBLData( const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySellMBLData of CMBLMarketData while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySellMBLData!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySellMBLData();
	}

	///记录所有的查询值
	queryInstrumentIDInSearchBySellMBLData= InstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindBySellMBLDataForMBLMarketData++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CMBLMarketData *theMBLMarketData;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.Direction=D_Sell;
	compareObject.Price=-999999999;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchBySellMBLData=pSellMBLIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchBySellMBLData==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theMBLMarketData=(CMBLMarketData *)(pLastFoundInSearchBySellMBLData->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theMBLMarketData->InstrumentID.getValue(),InstrumentID.getValue()))
	{
		pLastFoundInSearchBySellMBLData=NULL;
		return NULL;
	}
	if (compare(theMBLMarketData->Direction,D_Sell))
	{
		pLastFoundInSearchBySellMBLData=NULL;
		return NULL;
	}

	///返回找到的结果
	return theMBLMarketData;
}

CMBLMarketData *CMBLMarketDataFactory::findNextBySellMBLData(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySellMBLData==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBySellMBLDataForMBLMarketData++;
#endif
	CMBLMarketData *theMBLMarketData;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchBySellMBLData=pSellMBLIndex->getNextNode(pLastFoundInSearchBySellMBLData);
	if (pLastFoundInSearchBySellMBLData==NULL)
	{
		return NULL;
	}

	theMBLMarketData=(CMBLMarketData *)(pLastFoundInSearchBySellMBLData->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theMBLMarketData->InstrumentID,queryInstrumentIDInSearchBySellMBLData))
	{
		pLastFoundInSearchBySellMBLData=NULL;
		return NULL;
	}
	if (compare(theMBLMarketData->Direction,D_Sell))
	{
		pLastFoundInSearchBySellMBLData=NULL;
		return NULL;
	}

	///返回找到的结果
	return theMBLMarketData;
}

void CMBLMarketDataFactory::endFindBySellMBLData(void)
{
	pLastFoundInSearchBySellMBLData=NULL;
}


#ifdef COUNT_SEARCH
int multiFindStartByBuyMBLDataForMBLMarketData=0;
#endif

CMBLMarketData *CMBLMarketDataFactory::startFindStartByBuyMBLData( const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByBuyMBLData of CMBLMarketData while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByBuyMBLData!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByBuyMBLData();
	}

	///记录所有的查询值
	queryInstrumentIDInSearchStartByBuyMBLData= InstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByBuyMBLDataForMBLMarketData++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CMBLMarketData *theMBLMarketData;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.Direction=D_Buy;
	compareObject.Price=999999999;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByBuyMBLData=pQBuyMBLIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByBuyMBLData==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theMBLMarketData=(CMBLMarketData *)(pLastFoundInSearchStartByBuyMBLData->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theMBLMarketData->Direction,D_Buy))
	{
		pLastFoundInSearchStartByBuyMBLData=NULL;
		return NULL;
	}

	///返回找到的结果
	return theMBLMarketData;
}

CMBLMarketData *CMBLMarketDataFactory::findNextStartByBuyMBLData(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByBuyMBLData==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByBuyMBLDataForMBLMarketData++;
#endif
	CMBLMarketData *theMBLMarketData;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByBuyMBLData=pQBuyMBLIndex->getNextNode(pLastFoundInSearchStartByBuyMBLData);
	if (pLastFoundInSearchStartByBuyMBLData==NULL)
	{
		return NULL;
	}

	theMBLMarketData=(CMBLMarketData *)(pLastFoundInSearchStartByBuyMBLData->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theMBLMarketData->Direction,D_Buy))
	{
		pLastFoundInSearchStartByBuyMBLData=NULL;
		return NULL;
	}

	///返回找到的结果
	return theMBLMarketData;
}

void CMBLMarketDataFactory::endFindStartByBuyMBLData(void)
{
	pLastFoundInSearchStartByBuyMBLData=NULL;
}


#ifdef COUNT_SEARCH
int multiFindStartBySellMBLDataForMBLMarketData=0;
#endif

CMBLMarketData *CMBLMarketDataFactory::startFindStartBySellMBLData( const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartBySellMBLData of CMBLMarketData while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartBySellMBLData!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartBySellMBLData();
	}

	///记录所有的查询值
	queryInstrumentIDInSearchStartBySellMBLData= InstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartBySellMBLDataForMBLMarketData++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CMBLMarketData *theMBLMarketData;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.Direction=D_Sell;
	compareObject.Price=-999999999;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartBySellMBLData=pQSellMBLIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartBySellMBLData==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theMBLMarketData=(CMBLMarketData *)(pLastFoundInSearchStartBySellMBLData->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theMBLMarketData->Direction,D_Sell))
	{
		pLastFoundInSearchStartBySellMBLData=NULL;
		return NULL;
	}

	///返回找到的结果
	return theMBLMarketData;
}

CMBLMarketData *CMBLMarketDataFactory::findNextStartBySellMBLData(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartBySellMBLData==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartBySellMBLDataForMBLMarketData++;
#endif
	CMBLMarketData *theMBLMarketData;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartBySellMBLData=pQSellMBLIndex->getNextNode(pLastFoundInSearchStartBySellMBLData);
	if (pLastFoundInSearchStartBySellMBLData==NULL)
	{
		return NULL;
	}

	theMBLMarketData=(CMBLMarketData *)(pLastFoundInSearchStartBySellMBLData->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theMBLMarketData->Direction,D_Sell))
	{
		pLastFoundInSearchStartBySellMBLData=NULL;
		return NULL;
	}

	///返回找到的结果
	return theMBLMarketData;
}

void CMBLMarketDataFactory::endFindStartBySellMBLData(void)
{
	pLastFoundInSearchStartBySellMBLData=NULL;
}


#ifdef COUNT_SEARCH
int findByPriceForMBLMarketData=0;
#endif
CMBLMarketData *CMBLMarketDataFactory::findByPrice( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyDirectionType&  Direction,  const CReadOnlyPriceType&  Price)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByPrice of CMBLMarketData while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByPriceForMBLMarketData++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.Direction=Direction.getValue();
	compareObject.Price=Price.getValue();
	pNode=pSellMBLIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CMBLMarketData *)(pNode->pObject);
}


int compareForTradeIDIndexinTrade(const void *pV1, const void *pV2)
{
	CTrade *p1,*p2;
	p1=(CTrade *)pV1;
	p2=(CTrade *)pV2;
	switch (compare(p1->TradeID.getValue(),p2->TradeID.getValue()))
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
int compareForPartIDIndexinTrade(const void *pV1, const void *pV2)
{
	CTrade *p1,*p2;
	p1=(CTrade *)pV1;
	p2=(CTrade *)pV2;
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
	switch (compare(p1->TradeID.getValue(),p2->TradeID.getValue()))
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
int compareForClientIDIndexinTrade(const void *pV1, const void *pV2)
{
	CTrade *p1,*p2;
	p1=(CTrade *)pV1;
	p2=(CTrade *)pV2;
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
	switch (compare(p1->TradeID.getValue(),p2->TradeID.getValue()))
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
int compareForInstrumentIDIndexinTrade(const void *pV1, const void *pV2)
{
	CTrade *p1,*p2;
	p1=(CTrade *)pV1;
	p2=(CTrade *)pV2;
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
	switch (compare(p1->TradeID.getValue(),p2->TradeID.getValue()))
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
int multiFindAllForTrade=0;
#endif

CTrade *CTradeFactory::startFindAll()
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindAll of CTrade while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindAllForTrade++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CTrade *theTrade;
	compareObject.TradeID="";
	compareObject.ParticipantID="";
	compareObject.ClientID="";
	compareObject.InstrumentID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchAll=pTradeIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theTrade=(CTrade *)(pLastFoundInSearchAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theTrade;
}

CTrade *CTradeFactory::findNextAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindAllForTrade++;
#endif
	CTrade *theTrade;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchAll=pTradeIDIndex->getNextNode(pLastFoundInSearchAll);
	if (pLastFoundInSearchAll==NULL)
	{
		return NULL;
	}

	theTrade=(CTrade *)(pLastFoundInSearchAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theTrade;
}

void CTradeFactory::endFindAll(void)
{
	pLastFoundInSearchAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByTradeIDForTrade=0;
#endif

CTrade *CTradeFactory::startFindByTradeID( const CReadOnlyTradeIDType& TradeID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTradeID of CTrade while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByTradeID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTradeID();
	}

	///记录所有的查询值
	queryTradeIDInSearchByTradeID= TradeID.getValue();

#ifdef COUNT_SEARCH
	multiFindByTradeIDForTrade++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CTrade *theTrade;
	compareObject.TradeID=TradeID.getValue();
	compareObject.ParticipantID="";
	compareObject.ClientID="";
	compareObject.InstrumentID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByTradeID=pTradeIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByTradeID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theTrade=(CTrade *)(pLastFoundInSearchByTradeID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theTrade->TradeID.getValue(),TradeID.getValue()))
	{
		pLastFoundInSearchByTradeID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theTrade;
}

CTrade *CTradeFactory::findNextByTradeID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByTradeID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTradeIDForTrade++;
#endif
	CTrade *theTrade;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByTradeID=pTradeIDIndex->getNextNode(pLastFoundInSearchByTradeID);
	if (pLastFoundInSearchByTradeID==NULL)
	{
		return NULL;
	}

	theTrade=(CTrade *)(pLastFoundInSearchByTradeID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theTrade->TradeID,queryTradeIDInSearchByTradeID))
	{
		pLastFoundInSearchByTradeID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theTrade;
}

void CTradeFactory::endFindByTradeID(void)
{
	pLastFoundInSearchByTradeID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindStartByPartIDForTrade=0;
#endif

CTrade *CTradeFactory::startFindStartByPartID( const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByPartID of CTrade while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByPartID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByPartID();
	}

	///记录所有的查询值
	queryParticipantIDInSearchStartByPartID= ParticipantID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByPartIDForTrade++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CTrade *theTrade;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.TradeID="";
	compareObject.ClientID="";
	compareObject.InstrumentID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByPartID=pPartIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByPartID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theTrade=(CTrade *)(pLastFoundInSearchStartByPartID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theTrade;
}

CTrade *CTradeFactory::findNextStartByPartID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByPartID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByPartIDForTrade++;
#endif
	CTrade *theTrade;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByPartID=pPartIDIndex->getNextNode(pLastFoundInSearchStartByPartID);
	if (pLastFoundInSearchStartByPartID==NULL)
	{
		return NULL;
	}

	theTrade=(CTrade *)(pLastFoundInSearchStartByPartID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theTrade;
}

void CTradeFactory::endFindStartByPartID(void)
{
	pLastFoundInSearchStartByPartID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByClientIDForTrade=0;
#endif

CTrade *CTradeFactory::startFindByClientID( const CReadOnlyClientIDType& ClientID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByClientID of CTrade while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByClientID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByClientID();
	}

	///记录所有的查询值
	queryClientIDInSearchByClientID= ClientID.getValue();

#ifdef COUNT_SEARCH
	multiFindByClientIDForTrade++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CTrade *theTrade;
	compareObject.ClientID=ClientID.getValue();
	compareObject.TradeID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByClientID=pClientIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByClientID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theTrade=(CTrade *)(pLastFoundInSearchByClientID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theTrade->ClientID.getValue(),ClientID.getValue()))
	{
		pLastFoundInSearchByClientID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theTrade;
}

CTrade *CTradeFactory::findNextByClientID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByClientID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByClientIDForTrade++;
#endif
	CTrade *theTrade;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByClientID=pClientIDIndex->getNextNode(pLastFoundInSearchByClientID);
	if (pLastFoundInSearchByClientID==NULL)
	{
		return NULL;
	}

	theTrade=(CTrade *)(pLastFoundInSearchByClientID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theTrade->ClientID,queryClientIDInSearchByClientID))
	{
		pLastFoundInSearchByClientID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theTrade;
}

void CTradeFactory::endFindByClientID(void)
{
	pLastFoundInSearchByClientID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindStartByInstrumentIDForTrade=0;
#endif

CTrade *CTradeFactory::startFindStartByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindStartByInstrumentID of CTrade while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchStartByInstrumentID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindStartByInstrumentID();
	}

	///记录所有的查询值
	queryInstrumentIDInSearchStartByInstrumentID= InstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindStartByInstrumentIDForTrade++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CTrade *theTrade;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.TradeID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchStartByInstrumentID=pInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchStartByInstrumentID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theTrade=(CTrade *)(pLastFoundInSearchStartByInstrumentID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theTrade;
}

CTrade *CTradeFactory::findNextStartByInstrumentID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchStartByInstrumentID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindStartByInstrumentIDForTrade++;
#endif
	CTrade *theTrade;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchStartByInstrumentID=pInstrumentIDIndex->getNextNode(pLastFoundInSearchStartByInstrumentID);
	if (pLastFoundInSearchStartByInstrumentID==NULL)
	{
		return NULL;
	}

	theTrade=(CTrade *)(pLastFoundInSearchStartByInstrumentID->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theTrade;
}

void CTradeFactory::endFindStartByInstrumentID(void)
{
	pLastFoundInSearchStartByInstrumentID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForTrade=0;
#endif

CTrade *CTradeFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CTrade while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CTrade *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CTrade *CTradeFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CTrade *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CTradeFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}

int compareForInstrumentIDIndexinFusePhase(const void *pV1, const void *pV2)
{
	CFusePhase *p1,*p2;
	p1=(CFusePhase *)pV1;
	p2=(CFusePhase *)pV2;
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
int findByInstrumentIDForFusePhase=0;
#endif
CFusePhase *CFusePhaseFactory::findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentID of CFusePhase while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentIDForFusePhase++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CFusePhase *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindBySettlementGroupIDForFusePhase=0;
#endif

CFusePhase *CFusePhaseFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CFusePhase while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CFusePhase *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CFusePhase *CFusePhaseFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CFusePhase *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CFusePhaseFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}

int compareForExecOrderIDIndexinExecOrder(const void *pV1, const void *pV2)
{
	CExecOrder *p1,*p2;
	p1=(CExecOrder *)pV1;
	p2=(CExecOrder *)pV2;
	switch (compare(p1->ExecOrderSysID.getValue(),p2->ExecOrderSysID.getValue()))
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
int compareForParticipantIDIndexinExecOrder(const void *pV1, const void *pV2)
{
	CExecOrder *p1,*p2;
	p1=(CExecOrder *)pV1;
	p2=(CExecOrder *)pV2;
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
int compareForClientAndInstrumentIndexinExecOrder(const void *pV1, const void *pV2)
{
	CExecOrder *p1,*p2;
	p1=(CExecOrder *)pV1;
	p2=(CExecOrder *)pV2;
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
int compareForExecOrderLocalIDIndexinExecOrder(const void *pV1, const void *pV2)
{
	CExecOrder *p1,*p2;
	p1=(CExecOrder *)pV1;
	p2=(CExecOrder *)pV2;
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
	switch (compare(p1->ExecOrderLocalID.getValue(),p2->ExecOrderLocalID.getValue()))
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
int compareForInstrumentIDIndexinExecOrder(const void *pV1, const void *pV2)
{
	CExecOrder *p1,*p2;
	p1=(CExecOrder *)pV1;
	p2=(CExecOrder *)pV2;
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
int multiFindBySettlementGroupIDForExecOrder=0;
#endif

CExecOrder *CExecOrderFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CExecOrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CExecOrder *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CExecOrder *CExecOrderFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CExecOrder *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CExecOrderFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByExecOrderIDForExecOrder=0;
#endif
CExecOrder *CExecOrderFactory::findByExecOrderID( const CReadOnlyExecOrderSysIDType&  ExecOrderSysID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByExecOrderID of CExecOrder while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByExecOrderIDForExecOrder++;
#endif
	CAVLNode *pNode;
	compareObject.ExecOrderSysID=ExecOrderSysID.getValue();
	pNode=pExecOrderIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CExecOrder *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByParticipantIDForExecOrder=0;
#endif

CExecOrder *CExecOrderFactory::startFindByParticipantID( const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByParticipantID of CExecOrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByParticipantID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByParticipantID();
	}

	///记录所有的查询值
	queryParticipantIDInSearchByParticipantID= ParticipantID.getValue();

#ifdef COUNT_SEARCH
	multiFindByParticipantIDForExecOrder++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CExecOrder *theExecOrder;
	compareObject.ParticipantID=ParticipantID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByParticipantID=pParticipantIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByParticipantID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theExecOrder=(CExecOrder *)(pLastFoundInSearchByParticipantID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theExecOrder->ParticipantID.getValue(),ParticipantID.getValue()))
	{
		pLastFoundInSearchByParticipantID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theExecOrder;
}

CExecOrder *CExecOrderFactory::findNextByParticipantID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByParticipantID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByParticipantIDForExecOrder++;
#endif
	CExecOrder *theExecOrder;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByParticipantID=pParticipantIDIndex->getNextNode(pLastFoundInSearchByParticipantID);
	if (pLastFoundInSearchByParticipantID==NULL)
	{
		return NULL;
	}

	theExecOrder=(CExecOrder *)(pLastFoundInSearchByParticipantID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theExecOrder->ParticipantID,queryParticipantIDInSearchByParticipantID))
	{
		pLastFoundInSearchByParticipantID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theExecOrder;
}

void CExecOrderFactory::endFindByParticipantID(void)
{
	pLastFoundInSearchByParticipantID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByClientIDForExecOrder=0;
#endif

CExecOrder *CExecOrderFactory::startFindByClientID( const CReadOnlyClientIDType& ClientID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByClientID of CExecOrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByClientID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByClientID();
	}

	///记录所有的查询值
	queryClientIDInSearchByClientID= ClientID.getValue();

#ifdef COUNT_SEARCH
	multiFindByClientIDForExecOrder++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CExecOrder *theExecOrder;
	compareObject.ClientID=ClientID.getValue();
	compareObject.InstrumentID="";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByClientID=pClientAndInstrumentIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByClientID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theExecOrder=(CExecOrder *)(pLastFoundInSearchByClientID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theExecOrder->ClientID.getValue(),ClientID.getValue()))
	{
		pLastFoundInSearchByClientID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theExecOrder;
}

CExecOrder *CExecOrderFactory::findNextByClientID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByClientID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByClientIDForExecOrder++;
#endif
	CExecOrder *theExecOrder;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByClientID=pClientAndInstrumentIndex->getNextNode(pLastFoundInSearchByClientID);
	if (pLastFoundInSearchByClientID==NULL)
	{
		return NULL;
	}

	theExecOrder=(CExecOrder *)(pLastFoundInSearchByClientID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theExecOrder->ClientID,queryClientIDInSearchByClientID))
	{
		pLastFoundInSearchByClientID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theExecOrder;
}

void CExecOrderFactory::endFindByClientID(void)
{
	pLastFoundInSearchByClientID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByClientIDAndInstrumentIDForExecOrder=0;
#endif

CExecOrder *CExecOrderFactory::startFindByClientIDAndInstrumentID( const CReadOnlyClientIDType& ClientID,  const CReadOnlyInstrumentIDType& InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByClientIDAndInstrumentID of CExecOrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByClientIDAndInstrumentID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByClientIDAndInstrumentID();
	}

	///记录所有的查询值
	queryClientIDInSearchByClientIDAndInstrumentID= ClientID.getValue();
	queryInstrumentIDInSearchByClientIDAndInstrumentID= InstrumentID.getValue();

#ifdef COUNT_SEARCH
	multiFindByClientIDAndInstrumentIDForExecOrder++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CExecOrder *theExecOrder;
	compareObject.ClientID=ClientID.getValue();
	compareObject.InstrumentID=InstrumentID.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByClientIDAndInstrumentID=pClientAndInstrumentIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByClientIDAndInstrumentID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theExecOrder=(CExecOrder *)(pLastFoundInSearchByClientIDAndInstrumentID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theExecOrder->ClientID.getValue(),ClientID.getValue()))
	{
		pLastFoundInSearchByClientIDAndInstrumentID=NULL;
		return NULL;
	}
	if (compare(theExecOrder->InstrumentID.getValue(),InstrumentID.getValue()))
	{
		pLastFoundInSearchByClientIDAndInstrumentID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theExecOrder;
}

CExecOrder *CExecOrderFactory::findNextByClientIDAndInstrumentID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByClientIDAndInstrumentID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByClientIDAndInstrumentIDForExecOrder++;
#endif
	CExecOrder *theExecOrder;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByClientIDAndInstrumentID=pClientAndInstrumentIndex->getNextNode(pLastFoundInSearchByClientIDAndInstrumentID);
	if (pLastFoundInSearchByClientIDAndInstrumentID==NULL)
	{
		return NULL;
	}

	theExecOrder=(CExecOrder *)(pLastFoundInSearchByClientIDAndInstrumentID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theExecOrder->ClientID,queryClientIDInSearchByClientIDAndInstrumentID))
	{
		pLastFoundInSearchByClientIDAndInstrumentID=NULL;
		return NULL;
	}
	if (compare(theExecOrder->InstrumentID,queryInstrumentIDInSearchByClientIDAndInstrumentID))
	{
		pLastFoundInSearchByClientIDAndInstrumentID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theExecOrder;
}

void CExecOrderFactory::endFindByClientIDAndInstrumentID(void)
{
	pLastFoundInSearchByClientIDAndInstrumentID=NULL;
}


#ifdef COUNT_SEARCH
int findByExecOrderLocalIDForExecOrder=0;
#endif
CExecOrder *CExecOrderFactory::findByExecOrderLocalID( const CReadOnlyUserIDType&  UserID,  const CReadOnlyOrderLocalIDType&  ExecOrderLocalID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByExecOrderLocalID of CExecOrder while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByExecOrderLocalIDForExecOrder++;
#endif
	CAVLNode *pNode;
	compareObject.UserID=UserID.getValue();
	compareObject.ExecOrderLocalID=ExecOrderLocalID.getValue();
	pNode=pExecOrderLocalIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CExecOrder *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByUserIDForExecOrder=0;
#endif

CExecOrder *CExecOrderFactory::startFindByUserID( const CReadOnlyUserIDType& UserID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByUserID of CExecOrder while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByUserID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByUserID();
	}

	///记录所有的查询值
	queryUserIDInSearchByUserID= UserID.getValue();

#ifdef COUNT_SEARCH
	multiFindByUserIDForExecOrder++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CExecOrder *theExecOrder;
	compareObject.UserID=UserID.getValue();
	compareObject.ExecOrderLocalID="zzzzzzzzzzzz";
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByUserID=pExecOrderLocalIDIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theExecOrder=(CExecOrder *)(pLastFoundInSearchByUserID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theExecOrder->UserID.getValue(),UserID.getValue()))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theExecOrder;
}

CExecOrder *CExecOrderFactory::findNextByUserID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByUserIDForExecOrder++;
#endif
	CExecOrder *theExecOrder;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByUserID=pExecOrderLocalIDIndex->getNextNode(pLastFoundInSearchByUserID);
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

	theExecOrder=(CExecOrder *)(pLastFoundInSearchByUserID->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theExecOrder->UserID,queryUserIDInSearchByUserID))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}

	///返回找到的结果
	return theExecOrder;
}

void CExecOrderFactory::endFindByUserID(void)
{
	pLastFoundInSearchByUserID=NULL;
}

int compareForInstrumentIDIndexinUniPressure(const void *pV1, const void *pV2)
{
	CUniPressure *p1,*p2;
	p1=(CUniPressure *)pV1;
	p2=(CUniPressure *)pV2;
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
int multiFindBySettlementGroupIDForUniPressure=0;
#endif

CUniPressure *CUniPressureFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CUniPressure while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CUniPressure *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CUniPressure *CUniPressureFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CUniPressure *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CUniPressureFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentIDForUniPressure=0;
#endif
CUniPressure *CUniPressureFactory::findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentID of CUniPressure while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentIDForUniPressure++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CUniPressure *)(pNode->pObject);
}


int compareForInstrumentIDIndexinBasePriceLimit(const void *pV1, const void *pV2)
{
	CBasePriceLimit *p1,*p2;
	p1=(CBasePriceLimit *)pV1;
	p2=(CBasePriceLimit *)pV2;
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
int multiFindBySettlementGroupIDForBasePriceLimit=0;
#endif

CBasePriceLimit *CBasePriceLimitFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CBasePriceLimit while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CBasePriceLimit *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CBasePriceLimit *CBasePriceLimitFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CBasePriceLimit *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CBasePriceLimitFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentIDForBasePriceLimit=0;
#endif
CBasePriceLimit *CBasePriceLimitFactory::findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentID of CBasePriceLimit while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentIDForBasePriceLimit++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CBasePriceLimit *)(pNode->pObject);
}


int compareForParticipantIDIndexinCreditLimit(const void *pV1, const void *pV2)
{
	CCreditLimit *p1,*p2;
	p1=(CCreditLimit *)pV1;
	p2=(CCreditLimit *)pV2;
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
	switch (compare(p1->SettlementGroupID.getValue(),p2->SettlementGroupID.getValue()))
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
int multiFindBySettlementGroupIDForCreditLimit=0;
#endif

CCreditLimit *CCreditLimitFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCreditLimit while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCreditLimit *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCreditLimit *CCreditLimitFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCreditLimit *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCreditLimitFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByParticipantIDForCreditLimit=0;
#endif
CCreditLimit *CCreditLimitFactory::findByParticipantID( const CReadOnlySettlementGroupIDType&  SettlementGroupID,  const CReadOnlyParticipantIDType&  ParticipantID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByParticipantID of CCreditLimit while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByParticipantIDForCreditLimit++;
#endif
	CAVLNode *pNode;
	compareObject.SettlementGroupID=SettlementGroupID.getValue();
	compareObject.ParticipantID=ParticipantID.getValue();
	pNode=pParticipantIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CCreditLimit *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindAllByParticipantIDForCreditLimit=0;
#endif

CCreditLimit *CCreditLimitFactory::startFindAllByParticipantID( const CReadOnlyParticipantIDType& ParticipantID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindAllByParticipantID of CCreditLimit while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchAllByParticipantID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindAllByParticipantID();
	}

	///记录所有的查询值
	queryParticipantIDInSearchAllByParticipantID= ParticipantID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchAllByParticipantID=(CCreditLimit *)(pMem->getFirst());
	
	if (pLastFoundInSearchAllByParticipantID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextAllByParticipantID来寻找下一个
	if (compare(pLastFoundInSearchAllByParticipantID->ParticipantID.getValue(),ParticipantID.getValue()))
	{
		return findNextAllByParticipantID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchAllByParticipantID;
}

CCreditLimit *CCreditLimitFactory::findNextAllByParticipantID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchAllByParticipantID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchAllByParticipantID=(CCreditLimit *)(pMem->getNext());
		if (pLastFoundInSearchAllByParticipantID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchAllByParticipantID->ParticipantID,queryParticipantIDInSearchAllByParticipantID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchAllByParticipantID;
	}
}

void CCreditLimitFactory::endFindAllByParticipantID(void)
{
	pLastFoundInSearchAllByParticipantID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindAllByClearingPartIDForCreditLimit=0;
#endif

CCreditLimit *CCreditLimitFactory::startFindAllByClearingPartID( const CReadOnlyParticipantIDType& ClearingPartID)
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindAllByClearingPartID of CCreditLimit while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchAllByClearingPartID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindAllByClearingPartID();
	}

	///记录所有的查询值
	queryClearingPartIDInSearchAllByClearingPartID= ClearingPartID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchAllByClearingPartID=(CCreditLimit *)(pMem->getFirst());
	
	if (pLastFoundInSearchAllByClearingPartID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextAllByClearingPartID来寻找下一个
	if (compare(pLastFoundInSearchAllByClearingPartID->ClearingPartID.getValue(),ClearingPartID.getValue()))
	{
		return findNextAllByClearingPartID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchAllByClearingPartID;
}

CCreditLimit *CCreditLimitFactory::findNextAllByClearingPartID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchAllByClearingPartID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchAllByClearingPartID=(CCreditLimit *)(pMem->getNext());
		if (pLastFoundInSearchAllByClearingPartID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchAllByClearingPartID->ClearingPartID,queryClearingPartIDInSearchAllByClearingPartID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchAllByClearingPartID;
	}
}

void CCreditLimitFactory::endFindAllByClearingPartID(void)
{
	pLastFoundInSearchAllByClearingPartID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindAllForCreditLimit=0;
#endif

CCreditLimit *CCreditLimitFactory::startFindAll()
{
	if (runLevel<1)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindAll of CCreditLimit while run level < 1");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindAll();
	}

	///记录所有的查询值

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchAll=(CCreditLimit *)(pMem->getFirst());
	
	if (pLastFoundInSearchAll==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextAll来寻找下一个
	
	///返回找到的结果
	return pLastFoundInSearchAll;
}

CCreditLimit *CCreditLimitFactory::findNextAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchAll==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchAll=(CCreditLimit *)(pMem->getNext());
		if (pLastFoundInSearchAll==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		///返回找到的结果
		return pLastFoundInSearchAll;
	}
}

void CCreditLimitFactory::endFindAll(void)
{
	pLastFoundInSearchAll=NULL;
}

int compareForInstrumentIDIndexinCurrInstrumentOption(const void *pV1, const void *pV2)
{
	CCurrInstrumentOption *p1,*p2;
	p1=(CCurrInstrumentOption *)pV1;
	p2=(CCurrInstrumentOption *)pV2;
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
int multiFindBySettlementGroupIDForCurrInstrumentOption=0;
#endif

CCurrInstrumentOption *CCurrInstrumentOptionFactory::startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySettlementGroupID of CCurrInstrumentOption while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchBySettlementGroupID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySettlementGroupID();
	}

	///记录所有的查询值
	querySettlementGroupIDInSearchBySettlementGroupID= SettlementGroupID.getValue();

	///如果一个对象也没有，就返回失败
	pLastFoundInSearchBySettlementGroupID=(CCurrInstrumentOption *)(pMem->getFirst());
	
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}
	
	///如果第一个不正确，则使用findNextBySettlementGroupID来寻找下一个
	if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID.getValue(),SettlementGroupID.getValue()))
	{
		return findNextBySettlementGroupID();
	}
	
	///返回找到的结果
	return pLastFoundInSearchBySettlementGroupID;
}

CCurrInstrumentOption *CCurrInstrumentOptionFactory::findNextBySettlementGroupID(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchBySettlementGroupID==NULL)
	{
		return NULL;
	}

	///反复尝试寻找
	for (;;)
	{
		///如果已经没有下一个了，则失败返回
		pLastFoundInSearchBySettlementGroupID=(CCurrInstrumentOption *)(pMem->getNext());
		if (pLastFoundInSearchBySettlementGroupID==NULL)
		{
			return NULL;
		}

		///如果一个条件不满足，则尝试下一个
		if (compare(pLastFoundInSearchBySettlementGroupID->SettlementGroupID,querySettlementGroupIDInSearchBySettlementGroupID))
		{
			continue;
		}
		///返回找到的结果
		return pLastFoundInSearchBySettlementGroupID;
	}
}

void CCurrInstrumentOptionFactory::endFindBySettlementGroupID(void)
{
	pLastFoundInSearchBySettlementGroupID=NULL;
}


#ifdef COUNT_SEARCH
int findByInstrumentIDForCurrInstrumentOption=0;
#endif
CCurrInstrumentOption *CCurrInstrumentOptionFactory::findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByInstrumentID of CCurrInstrumentOption while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByInstrumentIDForCurrInstrumentOption++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CCurrInstrumentOption *)(pNode->pObject);
}


#ifdef COUNT_SEARCH
void showAllSearchCount(void)
{
	printf("\n");
	if (findByExchangeIDForExchangeDataSyncStatus !=0)
	{
		printf("\tfindByExchangeIDForExchangeDataSyncStatus:%d\n",findByExchangeIDForExchangeDataSyncStatus);
	}
	if (findBySettlementGroupIDForSGDataSyncStatus !=0)
	{
		printf("\tfindBySettlementGroupIDForSGDataSyncStatus:%d\n",findBySettlementGroupIDForSGDataSyncStatus);
	}
	if (multiFindStartBySettlementGroupIDForSGDataSyncStatus !=0)
	{
		printf("\tmultiFindStartBySettlementGroupIDForSGDataSyncStatus:%d\n",multiFindStartBySettlementGroupIDForSGDataSyncStatus);
	}
	if (findByExchangeIDForExchange !=0)
	{
		printf("\tfindByExchangeIDForExchange:%d\n",findByExchangeIDForExchange);
	}
	if (findBySettlementGroupIDForSettlementGroup !=0)
	{
		printf("\tfindBySettlementGroupIDForSettlementGroup:%d\n",findBySettlementGroupIDForSettlementGroup);
	}
	if (findByMarketIDForMarket !=0)
	{
		printf("\tfindByMarketIDForMarket:%d\n",findByMarketIDForMarket);
	}
	if (multiFindByProductIDForMarketProduct !=0)
	{
		printf("\tmultiFindByProductIDForMarketProduct:%d\n",multiFindByProductIDForMarketProduct);
	}
	if (multiFindByProductGroupIDForMarketProductGroup !=0)
	{
		printf("\tmultiFindByProductGroupIDForMarketProductGroup:%d\n",multiFindByProductGroupIDForMarketProductGroup);
	}
	if (findByProductIDInstrumentStatusForMdPubStatus !=0)
	{
		printf("\tfindByProductIDInstrumentStatusForMdPubStatus:%d\n",findByProductIDInstrumentStatusForMdPubStatus);
	}
	if (findByTopicIDForMarketDataTopic !=0)
	{
		printf("\tfindByTopicIDForMarketDataTopic:%d\n",findByTopicIDForMarketDataTopic);
	}
	if (multiFindByMarketIDForMarketDataTopic !=0)
	{
		printf("\tmultiFindByMarketIDForMarketDataTopic:%d\n",multiFindByMarketIDForMarketDataTopic);
	}
	if (findByPartIDTopicIDForPartTopicSubscribe !=0)
	{
		printf("\tfindByPartIDTopicIDForPartTopicSubscribe:%d\n",findByPartIDTopicIDForPartTopicSubscribe);
	}
	if (multiFindByPartIDForPartTopicSubscribe !=0)
	{
		printf("\tmultiFindByPartIDForPartTopicSubscribe:%d\n",multiFindByPartIDForPartTopicSubscribe);
	}
	if (findByParticipantIDForParticipant !=0)
	{
		printf("\tfindByParticipantIDForParticipant:%d\n",findByParticipantIDForParticipant);
	}
	if (multiFindStartByParticipantIDForParticipant !=0)
	{
		printf("\tmultiFindStartByParticipantIDForParticipant:%d\n",multiFindStartByParticipantIDForParticipant);
	}
	if (findByUserIDForUser !=0)
	{
		printf("\tfindByUserIDForUser:%d\n",findByUserIDForUser);
	}
	if (multiFindStartByUserIDForUser !=0)
	{
		printf("\tmultiFindStartByUserIDForUser:%d\n",multiFindStartByUserIDForUser);
	}
	if (findByClientIDForClient !=0)
	{
		printf("\tfindByClientIDForClient:%d\n",findByClientIDForClient);
	}
	if (multiFindByUserIDForUserIP !=0)
	{
		printf("\tmultiFindByUserIDForUserIP:%d\n",multiFindByUserIDForUserIP);
	}
	if (findByUserIPAndMaskForUserIP !=0)
	{
		printf("\tfindByUserIPAndMaskForUserIP:%d\n",findByUserIPAndMaskForUserIP);
	}
	if (findByPartClientForPartClient !=0)
	{
		printf("\tfindByPartClientForPartClient:%d\n",findByPartClientForPartClient);
	}
	if (multiFindStartByParticipantForPartClient !=0)
	{
		printf("\tmultiFindStartByParticipantForPartClient:%d\n",multiFindStartByParticipantForPartClient);
	}
	if (multiFindStartByClientForPartClient !=0)
	{
		printf("\tmultiFindStartByClientForPartClient:%d\n",multiFindStartByClientForPartClient);
	}
	if (findByParticipantForClearingTradingPart !=0)
	{
		printf("\tfindByParticipantForClearingTradingPart:%d\n",findByParticipantForClearingTradingPart);
	}
	if (findByUserFunctionForUserFunctionRight !=0)
	{
		printf("\tfindByUserFunctionForUserFunctionRight:%d\n",findByUserFunctionForUserFunctionRight);
	}
	if (findByAccountIDForAccount !=0)
	{
		printf("\tfindByAccountIDForAccount:%d\n",findByAccountIDForAccount);
	}
	if (multiFindStartByParticipantIDForAccount !=0)
	{
		printf("\tmultiFindStartByParticipantIDForAccount:%d\n",multiFindStartByParticipantIDForAccount);
	}
	if (findByUserIDForUserCommFlux !=0)
	{
		printf("\tfindByUserIDForUserCommFlux:%d\n",findByUserIDForUserCommFlux);
	}
	if (multiFindByMarketDataLogNoForMarketDataLog !=0)
	{
		printf("\tmultiFindByMarketDataLogNoForMarketDataLog:%d\n",multiFindByMarketDataLogNoForMarketDataLog);
	}
	if (findMaxMarketDataLogNoForMarketDataLog !=0)
	{
		printf("\tfindMaxMarketDataLogNoForMarketDataLog:%d\n",findMaxMarketDataLogNoForMarketDataLog);
	}
	if (findBySessionIDForUserSession !=0)
	{
		printf("\tfindBySessionIDForUserSession:%d\n",findBySessionIDForUserSession);
	}
	if (multiFindByFrontIDForUserSession !=0)
	{
		printf("\tmultiFindByFrontIDForUserSession:%d\n",multiFindByFrontIDForUserSession);
	}
	if (findByUserIDForUserSession !=0)
	{
		printf("\tfindByUserIDForUserSession:%d\n",findByUserIDForUserSession);
	}
	if (multiFindStartByUserIDForUserSession !=0)
	{
		printf("\tmultiFindStartByUserIDForUserSession:%d\n",multiFindStartByUserIDForUserSession);
	}
	if (findBySessionIDForMDSession !=0)
	{
		printf("\tfindBySessionIDForMDSession:%d\n",findBySessionIDForMDSession);
	}
	if (findByUserIDForMDSession !=0)
	{
		printf("\tfindByUserIDForMDSession:%d\n",findByUserIDForMDSession);
	}
	if (findByPrimaryKeyForLoginInfo !=0)
	{
		printf("\tfindByPrimaryKeyForLoginInfo:%d\n",findByPrimaryKeyForLoginInfo);
	}
	if (findByPrimaryKeyForDepthMarketDataDetail !=0)
	{
		printf("\tfindByPrimaryKeyForDepthMarketDataDetail:%d\n",findByPrimaryKeyForDepthMarketDataDetail);
	}
	if (findByFrontIDForFrontStatus !=0)
	{
		printf("\tfindByFrontIDForFrontStatus:%d\n",findByFrontIDForFrontStatus);
	}
	if (findByUserIDForMaxLocalID !=0)
	{
		printf("\tfindByUserIDForMaxLocalID:%d\n",findByUserIDForMaxLocalID);
	}
	if (findByBulletinIDForBulletin !=0)
	{
		printf("\tfindByBulletinIDForBulletin:%d\n",findByBulletinIDForBulletin);
	}
	if (multiFindStartByBulletinIDForBulletin !=0)
	{
		printf("\tmultiFindStartByBulletinIDForBulletin:%d\n",multiFindStartByBulletinIDForBulletin);
	}
	if (multiFindBySettlementGroupIDForMarketDataModify !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForMarketDataModify:%d\n",multiFindBySettlementGroupIDForMarketDataModify);
	}
	if (findByInstrumentIDForMarketDataModify !=0)
	{
		printf("\tfindByInstrumentIDForMarketDataModify:%d\n",findByInstrumentIDForMarketDataModify);
	}
	if (multiFindBySettlementGroupIDForDepthMarketData !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForDepthMarketData:%d\n",multiFindBySettlementGroupIDForDepthMarketData);
	}
	if (findByInstrumentIDForDepthMarketData !=0)
	{
		printf("\tfindByInstrumentIDForDepthMarketData:%d\n",findByInstrumentIDForDepthMarketData);
	}
	if (findByTopicAndInstrumentForTopicMarketData !=0)
	{
		printf("\tfindByTopicAndInstrumentForTopicMarketData:%d\n",findByTopicAndInstrumentForTopicMarketData);
	}
	if (multiFindByTopicIDForTopicMarketData !=0)
	{
		printf("\tmultiFindByTopicIDForTopicMarketData:%d\n",multiFindByTopicIDForTopicMarketData);
	}
	if (multiFindByInstrumentIDForTopicMarketData !=0)
	{
		printf("\tmultiFindByInstrumentIDForTopicMarketData:%d\n",multiFindByInstrumentIDForTopicMarketData);
	}
	if (multiFindBySettlementGroupIDForTopicMarketData !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForTopicMarketData:%d\n",multiFindBySettlementGroupIDForTopicMarketData);
	}
	if (multiFindByTopicAndVersionForTopicMarketDataVersion !=0)
	{
		printf("\tmultiFindByTopicAndVersionForTopicMarketDataVersion:%d\n",multiFindByTopicAndVersionForTopicMarketDataVersion);
	}
	if (multiFindByInformationIDForInformation !=0)
	{
		printf("\tmultiFindByInformationIDForInformation:%d\n",multiFindByInformationIDForInformation);
	}
	if (findLastInInformationIDForInformation !=0)
	{
		printf("\tfindLastInInformationIDForInformation:%d\n",findLastInInformationIDForInformation);
	}
	if (findByParticipantIDForOrderCount !=0)
	{
		printf("\tfindByParticipantIDForOrderCount:%d\n",findByParticipantIDForOrderCount);
	}
	if (findByInstrumentIDForInstrument !=0)
	{
		printf("\tfindByInstrumentIDForInstrument:%d\n",findByInstrumentIDForInstrument);
	}
	if (multiFindStartByInstrumentIDForInstrument !=0)
	{
		printf("\tmultiFindStartByInstrumentIDForInstrument:%d\n",multiFindStartByInstrumentIDForInstrument);
	}
	if (multiFindBySettlementGroupIDForInstrument !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForInstrument:%d\n",multiFindBySettlementGroupIDForInstrument);
	}
	if (multiFindByProductIDForInstrument !=0)
	{
		printf("\tmultiFindByProductIDForInstrument:%d\n",multiFindByProductIDForInstrument);
	}
	if (multiFindByProductGroupIDForInstrument !=0)
	{
		printf("\tmultiFindByProductGroupIDForInstrument:%d\n",multiFindByProductGroupIDForInstrument);
	}
	if (multiFindByDeliveryMonthForInstrument !=0)
	{
		printf("\tmultiFindByDeliveryMonthForInstrument:%d\n",multiFindByDeliveryMonthForInstrument);
	}
	if (multiFindByRevDeliveryMonthForInstrument !=0)
	{
		printf("\tmultiFindByRevDeliveryMonthForInstrument:%d\n",multiFindByRevDeliveryMonthForInstrument);
	}
	if (multiFindByCombinationForCombinationLeg !=0)
	{
		printf("\tmultiFindByCombinationForCombinationLeg:%d\n",multiFindByCombinationForCombinationLeg);
	}
	if (findByCombinationLegIDForCombinationLeg !=0)
	{
		printf("\tfindByCombinationLegIDForCombinationLeg:%d\n",findByCombinationLegIDForCombinationLeg);
	}
	if (multiFindByLegForCombinationLeg !=0)
	{
		printf("\tmultiFindByLegForCombinationLeg:%d\n",multiFindByLegForCombinationLeg);
	}
	if (findByCombinationAndLegForCombinationLeg !=0)
	{
		printf("\tfindByCombinationAndLegForCombinationLeg:%d\n",findByCombinationAndLegForCombinationLeg);
	}
	if (multiFindBySettlementGroupIDForCombinationLeg !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCombinationLeg:%d\n",multiFindBySettlementGroupIDForCombinationLeg);
	}
	if (findByPartRoleAndSGForPartRoleAccount !=0)
	{
		printf("\tfindByPartRoleAndSGForPartRoleAccount:%d\n",findByPartRoleAndSGForPartRoleAccount);
	}
	if (multiFindBySettlementGroupIDForPartRoleAccount !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForPartRoleAccount:%d\n",multiFindBySettlementGroupIDForPartRoleAccount);
	}
	if (multiFindStartByParticipantIDForPartRoleAccount !=0)
	{
		printf("\tmultiFindStartByParticipantIDForPartRoleAccount:%d\n",multiFindStartByParticipantIDForPartRoleAccount);
	}
	if (multiFindBySettlementGroupIDForPartProductRole !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForPartProductRole:%d\n",multiFindBySettlementGroupIDForPartProductRole);
	}
	if (findByParticipantProductRoleForPartProductRole !=0)
	{
		printf("\tfindByParticipantProductRoleForPartProductRole:%d\n",findByParticipantProductRoleForPartProductRole);
	}
	if (multiFindBySettlementGroupIDForPartProductRight !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForPartProductRight:%d\n",multiFindBySettlementGroupIDForPartProductRight);
	}
	if (findByParticipantAndProductForPartProductRight !=0)
	{
		printf("\tfindByParticipantAndProductForPartProductRight:%d\n",findByParticipantAndProductForPartProductRight);
	}
	if (multiFindBySettlementGroupIDForPartInstrumentRight !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForPartInstrumentRight:%d\n",multiFindBySettlementGroupIDForPartInstrumentRight);
	}
	if (findByParticipantAndInstrumentForPartInstrumentRight !=0)
	{
		printf("\tfindByParticipantAndInstrumentForPartInstrumentRight:%d\n",findByParticipantAndInstrumentForPartInstrumentRight);
	}
	if (multiFindBySettlementGroupIDForClientProductRight !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForClientProductRight:%d\n",multiFindBySettlementGroupIDForClientProductRight);
	}
	if (findByClientAndProductForClientProductRight !=0)
	{
		printf("\tfindByClientAndProductForClientProductRight:%d\n",findByClientAndProductForClientProductRight);
	}
	if (multiFindBySettlementGroupIDForClientInstrumentRight !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForClientInstrumentRight:%d\n",multiFindBySettlementGroupIDForClientInstrumentRight);
	}
	if (findByClientAndInstrumentForClientInstrumentRight !=0)
	{
		printf("\tfindByClientAndInstrumentForClientInstrumentRight:%d\n",findByClientAndInstrumentForClientInstrumentRight);
	}
	if (multiFindBySettlementGroupIDForPartClientProductRight !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForPartClientProductRight:%d\n",multiFindBySettlementGroupIDForPartClientProductRight);
	}
	if (findByParticipantAndClientAndProductForPartClientProductRight !=0)
	{
		printf("\tfindByParticipantAndClientAndProductForPartClientProductRight:%d\n",findByParticipantAndClientAndProductForPartClientProductRight);
	}
	if (multiFindBySettlementGroupIDForPartClientInstrumentRight !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForPartClientInstrumentRight:%d\n",multiFindBySettlementGroupIDForPartClientInstrumentRight);
	}
	if (findByParticipantAndClientAndInstrumentForPartClientInstrumentRight !=0)
	{
		printf("\tfindByParticipantAndClientAndInstrumentForPartClientInstrumentRight:%d\n",findByParticipantAndClientAndInstrumentForPartClientInstrumentRight);
	}
	if (multiFindBySettlementGroupIDForCurrProductProperty !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCurrProductProperty:%d\n",multiFindBySettlementGroupIDForCurrProductProperty);
	}
	if (findByProductIDForCurrProductProperty !=0)
	{
		printf("\tfindByProductIDForCurrProductProperty:%d\n",findByProductIDForCurrProductProperty);
	}
	if (multiFindBySettlementGroupIDForCurrInstrumentProperty !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCurrInstrumentProperty:%d\n",multiFindBySettlementGroupIDForCurrInstrumentProperty);
	}
	if (findByInstrumentIDForCurrInstrumentProperty !=0)
	{
		printf("\tfindByInstrumentIDForCurrInstrumentProperty:%d\n",findByInstrumentIDForCurrInstrumentProperty);
	}
	if (multiFindBySettlementGroupIDForCurrPriceBanding !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCurrPriceBanding:%d\n",multiFindBySettlementGroupIDForCurrPriceBanding);
	}
	if (findByInstrumentAndSegmentForCurrPriceBanding !=0)
	{
		printf("\tfindByInstrumentAndSegmentForCurrPriceBanding:%d\n",findByInstrumentAndSegmentForCurrPriceBanding);
	}
	if (findByInstrumentAndOneSegmentForCurrPriceBanding !=0)
	{
		printf("\tfindByInstrumentAndOneSegmentForCurrPriceBanding:%d\n",findByInstrumentAndOneSegmentForCurrPriceBanding);
	}
	if (multiFindBySettlementGroupIDForCurrMarginRate !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCurrMarginRate:%d\n",multiFindBySettlementGroupIDForCurrMarginRate);
	}
	if (findByInstrumentAndPartForCurrMarginRate !=0)
	{
		printf("\tfindByInstrumentAndPartForCurrMarginRate:%d\n",findByInstrumentAndPartForCurrMarginRate);
	}
	if (multiFindBySettlementGroupIDForCurrMarginRateDetail !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCurrMarginRateDetail:%d\n",multiFindBySettlementGroupIDForCurrMarginRateDetail);
	}
	if (findByInstrumentAndParticipantForCurrMarginRateDetail !=0)
	{
		printf("\tfindByInstrumentAndParticipantForCurrMarginRateDetail:%d\n",findByInstrumentAndParticipantForCurrMarginRateDetail);
	}
	if (multiFindBySettlementGroupIDForCurrPartPosiLimit !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCurrPartPosiLimit:%d\n",multiFindBySettlementGroupIDForCurrPartPosiLimit);
	}
	if (findByInstrumentAndPartForCurrPartPosiLimit !=0)
	{
		printf("\tfindByInstrumentAndPartForCurrPartPosiLimit:%d\n",findByInstrumentAndPartForCurrPartPosiLimit);
	}
	if (multiFindBySettlementGroupIDForCurrPartPosiLimitDetail !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCurrPartPosiLimitDetail:%d\n",multiFindBySettlementGroupIDForCurrPartPosiLimitDetail);
	}
	if (findByInstrumentAndPartForCurrPartPosiLimitDetail !=0)
	{
		printf("\tfindByInstrumentAndPartForCurrPartPosiLimitDetail:%d\n",findByInstrumentAndPartForCurrPartPosiLimitDetail);
	}
	if (findByInstrumentPartAndStartPositionForCurrPartPosiLimitDetail !=0)
	{
		printf("\tfindByInstrumentPartAndStartPositionForCurrPartPosiLimitDetail:%d\n",findByInstrumentPartAndStartPositionForCurrPartPosiLimitDetail);
	}
	if (multiFindBySettlementGroupIDForCurrClientPosiLimit !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCurrClientPosiLimit:%d\n",multiFindBySettlementGroupIDForCurrClientPosiLimit);
	}
	if (multiFindBySettlementGroupIDForCurrClientPosiLimitDetail !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCurrClientPosiLimitDetail:%d\n",multiFindBySettlementGroupIDForCurrClientPosiLimitDetail);
	}
	if (findByInstrumentAndClientTypeForCurrClientPosiLimitDetail !=0)
	{
		printf("\tfindByInstrumentAndClientTypeForCurrClientPosiLimitDetail:%d\n",findByInstrumentAndClientTypeForCurrClientPosiLimitDetail);
	}
	if (findByInstrumentClientTypeAndStartPositionForCurrClientPosiLimitDetail !=0)
	{
		printf("\tfindByInstrumentClientTypeAndStartPositionForCurrClientPosiLimitDetail:%d\n",findByInstrumentClientTypeAndStartPositionForCurrClientPosiLimitDetail);
	}
	if (multiFindBySettlementGroupIDForCurrSpecialPosiLimit !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCurrSpecialPosiLimit:%d\n",multiFindBySettlementGroupIDForCurrSpecialPosiLimit);
	}
	if (multiFindBySettlementGroupIDForCurrSpecialPosiLimitDetail !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCurrSpecialPosiLimitDetail:%d\n",multiFindBySettlementGroupIDForCurrSpecialPosiLimitDetail);
	}
	if (findByInstrumentAndClientForCurrSpecialPosiLimitDetail !=0)
	{
		printf("\tfindByInstrumentAndClientForCurrSpecialPosiLimitDetail:%d\n",findByInstrumentAndClientForCurrSpecialPosiLimitDetail);
	}
	if (findByInstrumentClientAndStartPositionForCurrSpecialPosiLimitDetail !=0)
	{
		printf("\tfindByInstrumentClientAndStartPositionForCurrSpecialPosiLimitDetail:%d\n",findByInstrumentClientAndStartPositionForCurrSpecialPosiLimitDetail);
	}
	if (multiFindBySettlementGroupIDForCurrHedgeRule !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCurrHedgeRule:%d\n",multiFindBySettlementGroupIDForCurrHedgeRule);
	}
	if (findByInstrumentIDForCurrHedgeRule !=0)
	{
		printf("\tfindByInstrumentIDForCurrHedgeRule:%d\n",findByInstrumentIDForCurrHedgeRule);
	}
	if (multiFindBySettlementGroupIDForCurrTradingSegmentAttr !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCurrTradingSegmentAttr:%d\n",multiFindBySettlementGroupIDForCurrTradingSegmentAttr);
	}
	if (multiFindByTimeForCurrTradingSegmentAttr !=0)
	{
		printf("\tmultiFindByTimeForCurrTradingSegmentAttr:%d\n",multiFindByTimeForCurrTradingSegmentAttr);
	}
	if (multiFindByInstrumentForCurrTradingSegmentAttr !=0)
	{
		printf("\tmultiFindByInstrumentForCurrTradingSegmentAttr:%d\n",multiFindByInstrumentForCurrTradingSegmentAttr);
	}
	if (findByInstrumentAndSegementForCurrTradingSegmentAttr !=0)
	{
		printf("\tfindByInstrumentAndSegementForCurrTradingSegmentAttr:%d\n",findByInstrumentAndSegementForCurrTradingSegmentAttr);
	}
	if (multiFindBySettlementGroupIDForCurrFuse !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCurrFuse:%d\n",multiFindBySettlementGroupIDForCurrFuse);
	}
	if (findByInstrumentIDForCurrFuse !=0)
	{
		printf("\tfindByInstrumentIDForCurrFuse:%d\n",findByInstrumentIDForCurrFuse);
	}
	if (multiFindBySettlementGroupIDForTradingAccount !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForTradingAccount:%d\n",multiFindBySettlementGroupIDForTradingAccount);
	}
	if (findByAccountIDForTradingAccount !=0)
	{
		printf("\tfindByAccountIDForTradingAccount:%d\n",findByAccountIDForTradingAccount);
	}
	if (multiFindBySettlementGroupIDForBaseReserveAccount !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForBaseReserveAccount:%d\n",multiFindBySettlementGroupIDForBaseReserveAccount);
	}
	if (findByAccountIDForBaseReserveAccount !=0)
	{
		printf("\tfindByAccountIDForBaseReserveAccount:%d\n",findByAccountIDForBaseReserveAccount);
	}
	if (findByPartAndInstrumentForPartPosition !=0)
	{
		printf("\tfindByPartAndInstrumentForPartPosition:%d\n",findByPartAndInstrumentForPartPosition);
	}
	if (multiFindStartByInstrumentForPartPosition !=0)
	{
		printf("\tmultiFindStartByInstrumentForPartPosition:%d\n",multiFindStartByInstrumentForPartPosition);
	}
	if (multiFindStartByParticipantForPartPosition !=0)
	{
		printf("\tmultiFindStartByParticipantForPartPosition:%d\n",multiFindStartByParticipantForPartPosition);
	}
	if (multiFindBySettlementGroupIDForPartPosition !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForPartPosition:%d\n",multiFindBySettlementGroupIDForPartPosition);
	}
	if (findByPartClientAndInstrumentForClientPosition !=0)
	{
		printf("\tfindByPartClientAndInstrumentForClientPosition:%d\n",findByPartClientAndInstrumentForClientPosition);
	}
	if (multiFindByClientAndInstrumentForClientPosition !=0)
	{
		printf("\tmultiFindByClientAndInstrumentForClientPosition:%d\n",multiFindByClientAndInstrumentForClientPosition);
	}
	if (multiFindStartByParticipantForClientPosition !=0)
	{
		printf("\tmultiFindStartByParticipantForClientPosition:%d\n",multiFindStartByParticipantForClientPosition);
	}
	if (multiFindStartByClientForClientPosition !=0)
	{
		printf("\tmultiFindStartByClientForClientPosition:%d\n",multiFindStartByClientForClientPosition);
	}
	if (multiFindStartByInstrumentForClientPosition !=0)
	{
		printf("\tmultiFindStartByInstrumentForClientPosition:%d\n",multiFindStartByInstrumentForClientPosition);
	}
	if (multiFindByInstrumentIDForClientPosition !=0)
	{
		printf("\tmultiFindByInstrumentIDForClientPosition:%d\n",multiFindByInstrumentIDForClientPosition);
	}
	if (multiFindBySettlementGroupIDForClientPosition !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForClientPosition:%d\n",multiFindBySettlementGroupIDForClientPosition);
	}
	if (multiFindBySettlementGroupIDForHedgeVolume !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForHedgeVolume:%d\n",multiFindBySettlementGroupIDForHedgeVolume);
	}
	if (findByInstrumentPartClientForHedgeVolume !=0)
	{
		printf("\tfindByInstrumentPartClientForHedgeVolume:%d\n",findByInstrumentPartClientForHedgeVolume);
	}
	if (multiFindStartByPartClientAndInstrumentForHedgeVolume !=0)
	{
		printf("\tmultiFindStartByPartClientAndInstrumentForHedgeVolume:%d\n",multiFindStartByPartClientAndInstrumentForHedgeVolume);
	}
	if (multiFindBySettlementGroupIDForRemainOrder !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForRemainOrder:%d\n",multiFindBySettlementGroupIDForRemainOrder);
	}
	if (multiFindByInstrumentIDForRemainOrder !=0)
	{
		printf("\tmultiFindByInstrumentIDForRemainOrder:%d\n",multiFindByInstrumentIDForRemainOrder);
	}
	if (multiFindBySettlementGroupIDForMarketData !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForMarketData:%d\n",multiFindBySettlementGroupIDForMarketData);
	}
	if (findByInstrumentIDForMarketData !=0)
	{
		printf("\tfindByInstrumentIDForMarketData:%d\n",findByInstrumentIDForMarketData);
	}
	if (findByPartAndInstrumentForClearingPartPosition !=0)
	{
		printf("\tfindByPartAndInstrumentForClearingPartPosition:%d\n",findByPartAndInstrumentForClearingPartPosition);
	}
	if (multiFindBySettlementGroupIDForClearingPartPosition !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForClearingPartPosition:%d\n",multiFindBySettlementGroupIDForClearingPartPosition);
	}
	if (findByInstrumentIDForInstrumentStatus !=0)
	{
		printf("\tfindByInstrumentIDForInstrumentStatus:%d\n",findByInstrumentIDForInstrumentStatus);
	}
	if (multiFindStartByInstrumentIDForInstrumentStatus !=0)
	{
		printf("\tmultiFindStartByInstrumentIDForInstrumentStatus:%d\n",multiFindStartByInstrumentIDForInstrumentStatus);
	}
	if (multiFindBySettlementGroupIDForInstrumentStatus !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForInstrumentStatus:%d\n",multiFindBySettlementGroupIDForInstrumentStatus);
	}
	if (findByOrderIDForOrder !=0)
	{
		printf("\tfindByOrderIDForOrder:%d\n",findByOrderIDForOrder);
	}
	if (multiFindStartByParticipantIDForOrder !=0)
	{
		printf("\tmultiFindStartByParticipantIDForOrder:%d\n",multiFindStartByParticipantIDForOrder);
	}
	if (multiFindBySettlementGroupIDForOrder !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForOrder:%d\n",multiFindBySettlementGroupIDForOrder);
	}
	if (findByOrderLocalIDForOrder !=0)
	{
		printf("\tfindByOrderLocalIDForOrder:%d\n",findByOrderLocalIDForOrder);
	}
	if (multiFindByUserIDForOrder !=0)
	{
		printf("\tmultiFindByUserIDForOrder:%d\n",multiFindByUserIDForOrder);
	}
	if (multiFindByInstrumentIDForOrder !=0)
	{
		printf("\tmultiFindByInstrumentIDForOrder:%d\n",multiFindByInstrumentIDForOrder);
	}
	if (multiFindStartByInstrumentIDForOrder !=0)
	{
		printf("\tmultiFindStartByInstrumentIDForOrder:%d\n",multiFindStartByInstrumentIDForOrder);
	}
	if (findByCombOrderIDForCombOrder !=0)
	{
		printf("\tfindByCombOrderIDForCombOrder:%d\n",findByCombOrderIDForCombOrder);
	}
	if (multiFindStartByParticipantIDForCombOrder !=0)
	{
		printf("\tmultiFindStartByParticipantIDForCombOrder:%d\n",multiFindStartByParticipantIDForCombOrder);
	}
	if (multiFindBySettlementGroupIDForCombOrder !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCombOrder:%d\n",multiFindBySettlementGroupIDForCombOrder);
	}
	if (findByCombOrderLocalIDForCombOrder !=0)
	{
		printf("\tfindByCombOrderLocalIDForCombOrder:%d\n",findByCombOrderLocalIDForCombOrder);
	}
	if (multiFindByUserIDForCombOrder !=0)
	{
		printf("\tmultiFindByUserIDForCombOrder:%d\n",multiFindByUserIDForCombOrder);
	}
	if (findByOTCOrderLocalIDForOTCOrder !=0)
	{
		printf("\tfindByOTCOrderLocalIDForOTCOrder:%d\n",findByOTCOrderLocalIDForOTCOrder);
	}
	if (findByOTCOrderIDForOTCOrder !=0)
	{
		printf("\tfindByOTCOrderIDForOTCOrder:%d\n",findByOTCOrderIDForOTCOrder);
	}
	if (multiFindBySettlementGroupIDForOTCOrder !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForOTCOrder:%d\n",multiFindBySettlementGroupIDForOTCOrder);
	}
	if (multiFindByImplyLegForImplyOrder !=0)
	{
		printf("\tmultiFindByImplyLegForImplyOrder:%d\n",multiFindByImplyLegForImplyOrder);
	}
	if (multiFindByImplyOrderAndAnchorLegForImplyOrder !=0)
	{
		printf("\tmultiFindByImplyOrderAndAnchorLegForImplyOrder:%d\n",multiFindByImplyOrderAndAnchorLegForImplyOrder);
	}
	if (multiFindByImplyOrderForImplyOrder !=0)
	{
		printf("\tmultiFindByImplyOrderForImplyOrder:%d\n",multiFindByImplyOrderForImplyOrder);
	}
	if (findByQuoteIDForQuote !=0)
	{
		printf("\tfindByQuoteIDForQuote:%d\n",findByQuoteIDForQuote);
	}
	if (findByQuoteLocalIDForQuote !=0)
	{
		printf("\tfindByQuoteLocalIDForQuote:%d\n",findByQuoteLocalIDForQuote);
	}
	if (multiFindByUserIDForQuote !=0)
	{
		printf("\tmultiFindByUserIDForQuote:%d\n",multiFindByUserIDForQuote);
	}
	if (findByPartClientAndInstrumentForQuote !=0)
	{
		printf("\tfindByPartClientAndInstrumentForQuote:%d\n",findByPartClientAndInstrumentForQuote);
	}
	if (multiFindStartByParticipantIDForQuote !=0)
	{
		printf("\tmultiFindStartByParticipantIDForQuote:%d\n",multiFindStartByParticipantIDForQuote);
	}
	if (multiFindBySettlementGroupIDForQuote !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForQuote:%d\n",multiFindBySettlementGroupIDForQuote);
	}
	if (findByAskOrderForQuote !=0)
	{
		printf("\tfindByAskOrderForQuote:%d\n",findByAskOrderForQuote);
	}
	if (findByBidOrderForQuote !=0)
	{
		printf("\tfindByBidOrderForQuote:%d\n",findByBidOrderForQuote);
	}
	if (multiFindByBuyMBLDataForMBLMarketData !=0)
	{
		printf("\tmultiFindByBuyMBLDataForMBLMarketData:%d\n",multiFindByBuyMBLDataForMBLMarketData);
	}
	if (multiFindBySellMBLDataForMBLMarketData !=0)
	{
		printf("\tmultiFindBySellMBLDataForMBLMarketData:%d\n",multiFindBySellMBLDataForMBLMarketData);
	}
	if (multiFindStartByBuyMBLDataForMBLMarketData !=0)
	{
		printf("\tmultiFindStartByBuyMBLDataForMBLMarketData:%d\n",multiFindStartByBuyMBLDataForMBLMarketData);
	}
	if (multiFindStartBySellMBLDataForMBLMarketData !=0)
	{
		printf("\tmultiFindStartBySellMBLDataForMBLMarketData:%d\n",multiFindStartBySellMBLDataForMBLMarketData);
	}
	if (findByPriceForMBLMarketData !=0)
	{
		printf("\tfindByPriceForMBLMarketData:%d\n",findByPriceForMBLMarketData);
	}
	if (multiFindAllForTrade !=0)
	{
		printf("\tmultiFindAllForTrade:%d\n",multiFindAllForTrade);
	}
	if (multiFindByTradeIDForTrade !=0)
	{
		printf("\tmultiFindByTradeIDForTrade:%d\n",multiFindByTradeIDForTrade);
	}
	if (multiFindStartByPartIDForTrade !=0)
	{
		printf("\tmultiFindStartByPartIDForTrade:%d\n",multiFindStartByPartIDForTrade);
	}
	if (multiFindByClientIDForTrade !=0)
	{
		printf("\tmultiFindByClientIDForTrade:%d\n",multiFindByClientIDForTrade);
	}
	if (multiFindStartByInstrumentIDForTrade !=0)
	{
		printf("\tmultiFindStartByInstrumentIDForTrade:%d\n",multiFindStartByInstrumentIDForTrade);
	}
	if (multiFindBySettlementGroupIDForTrade !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForTrade:%d\n",multiFindBySettlementGroupIDForTrade);
	}
	if (findByInstrumentIDForFusePhase !=0)
	{
		printf("\tfindByInstrumentIDForFusePhase:%d\n",findByInstrumentIDForFusePhase);
	}
	if (multiFindBySettlementGroupIDForFusePhase !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForFusePhase:%d\n",multiFindBySettlementGroupIDForFusePhase);
	}
	if (multiFindBySettlementGroupIDForExecOrder !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForExecOrder:%d\n",multiFindBySettlementGroupIDForExecOrder);
	}
	if (findByExecOrderIDForExecOrder !=0)
	{
		printf("\tfindByExecOrderIDForExecOrder:%d\n",findByExecOrderIDForExecOrder);
	}
	if (multiFindByParticipantIDForExecOrder !=0)
	{
		printf("\tmultiFindByParticipantIDForExecOrder:%d\n",multiFindByParticipantIDForExecOrder);
	}
	if (multiFindByClientIDForExecOrder !=0)
	{
		printf("\tmultiFindByClientIDForExecOrder:%d\n",multiFindByClientIDForExecOrder);
	}
	if (multiFindByClientIDAndInstrumentIDForExecOrder !=0)
	{
		printf("\tmultiFindByClientIDAndInstrumentIDForExecOrder:%d\n",multiFindByClientIDAndInstrumentIDForExecOrder);
	}
	if (findByExecOrderLocalIDForExecOrder !=0)
	{
		printf("\tfindByExecOrderLocalIDForExecOrder:%d\n",findByExecOrderLocalIDForExecOrder);
	}
	if (multiFindByUserIDForExecOrder !=0)
	{
		printf("\tmultiFindByUserIDForExecOrder:%d\n",multiFindByUserIDForExecOrder);
	}
	if (multiFindBySettlementGroupIDForUniPressure !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForUniPressure:%d\n",multiFindBySettlementGroupIDForUniPressure);
	}
	if (findByInstrumentIDForUniPressure !=0)
	{
		printf("\tfindByInstrumentIDForUniPressure:%d\n",findByInstrumentIDForUniPressure);
	}
	if (multiFindBySettlementGroupIDForBasePriceLimit !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForBasePriceLimit:%d\n",multiFindBySettlementGroupIDForBasePriceLimit);
	}
	if (findByInstrumentIDForBasePriceLimit !=0)
	{
		printf("\tfindByInstrumentIDForBasePriceLimit:%d\n",findByInstrumentIDForBasePriceLimit);
	}
	if (multiFindBySettlementGroupIDForCreditLimit !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCreditLimit:%d\n",multiFindBySettlementGroupIDForCreditLimit);
	}
	if (findByParticipantIDForCreditLimit !=0)
	{
		printf("\tfindByParticipantIDForCreditLimit:%d\n",findByParticipantIDForCreditLimit);
	}
	if (multiFindAllByParticipantIDForCreditLimit !=0)
	{
		printf("\tmultiFindAllByParticipantIDForCreditLimit:%d\n",multiFindAllByParticipantIDForCreditLimit);
	}
	if (multiFindAllByClearingPartIDForCreditLimit !=0)
	{
		printf("\tmultiFindAllByClearingPartIDForCreditLimit:%d\n",multiFindAllByClearingPartIDForCreditLimit);
	}
	if (multiFindAllForCreditLimit !=0)
	{
		printf("\tmultiFindAllForCreditLimit:%d\n",multiFindAllForCreditLimit);
	}
	if (multiFindBySettlementGroupIDForCurrInstrumentOption !=0)
	{
		printf("\tmultiFindBySettlementGroupIDForCurrInstrumentOption:%d\n",multiFindBySettlementGroupIDForCurrInstrumentOption);
	}
	if (findByInstrumentIDForCurrInstrumentOption !=0)
	{
		printf("\tfindByInstrumentIDForCurrInstrumentOption:%d\n",findByInstrumentIDForCurrInstrumentOption);
	}
}

void initAllSearchCount(void)
{
	findByExchangeIDForExchangeDataSyncStatus=0;
	findBySettlementGroupIDForSGDataSyncStatus=0;
	multiFindStartBySettlementGroupIDForSGDataSyncStatus=0;
	findByExchangeIDForExchange=0;
	findBySettlementGroupIDForSettlementGroup=0;
	findByMarketIDForMarket=0;
	multiFindByProductIDForMarketProduct=0;
	multiFindByProductGroupIDForMarketProductGroup=0;
	findByProductIDInstrumentStatusForMdPubStatus=0;
	findByTopicIDForMarketDataTopic=0;
	multiFindByMarketIDForMarketDataTopic=0;
	findByPartIDTopicIDForPartTopicSubscribe=0;
	multiFindByPartIDForPartTopicSubscribe=0;
	findByParticipantIDForParticipant=0;
	multiFindStartByParticipantIDForParticipant=0;
	findByUserIDForUser=0;
	multiFindStartByUserIDForUser=0;
	findByClientIDForClient=0;
	multiFindByUserIDForUserIP=0;
	findByUserIPAndMaskForUserIP=0;
	findByPartClientForPartClient=0;
	multiFindStartByParticipantForPartClient=0;
	multiFindStartByClientForPartClient=0;
	findByParticipantForClearingTradingPart=0;
	findByUserFunctionForUserFunctionRight=0;
	findByAccountIDForAccount=0;
	multiFindStartByParticipantIDForAccount=0;
	findByUserIDForUserCommFlux=0;
	multiFindByMarketDataLogNoForMarketDataLog=0;
	findMaxMarketDataLogNoForMarketDataLog=0;
	findBySessionIDForUserSession=0;
	multiFindByFrontIDForUserSession=0;
	findByUserIDForUserSession=0;
	multiFindStartByUserIDForUserSession=0;
	findBySessionIDForMDSession=0;
	findByUserIDForMDSession=0;
	findByPrimaryKeyForLoginInfo=0;
	findByPrimaryKeyForDepthMarketDataDetail=0;
	findByFrontIDForFrontStatus=0;
	findByUserIDForMaxLocalID=0;
	findByBulletinIDForBulletin=0;
	multiFindStartByBulletinIDForBulletin=0;
	multiFindBySettlementGroupIDForMarketDataModify=0;
	findByInstrumentIDForMarketDataModify=0;
	multiFindBySettlementGroupIDForDepthMarketData=0;
	findByInstrumentIDForDepthMarketData=0;
	findByTopicAndInstrumentForTopicMarketData=0;
	multiFindByTopicIDForTopicMarketData=0;
	multiFindByInstrumentIDForTopicMarketData=0;
	multiFindBySettlementGroupIDForTopicMarketData=0;
	multiFindByTopicAndVersionForTopicMarketDataVersion=0;
	multiFindByInformationIDForInformation=0;
	findLastInInformationIDForInformation=0;
	findByParticipantIDForOrderCount=0;
	findByInstrumentIDForInstrument=0;
	multiFindStartByInstrumentIDForInstrument=0;
	multiFindBySettlementGroupIDForInstrument=0;
	multiFindByProductIDForInstrument=0;
	multiFindByProductGroupIDForInstrument=0;
	multiFindByDeliveryMonthForInstrument=0;
	multiFindByRevDeliveryMonthForInstrument=0;
	multiFindByCombinationForCombinationLeg=0;
	findByCombinationLegIDForCombinationLeg=0;
	multiFindByLegForCombinationLeg=0;
	findByCombinationAndLegForCombinationLeg=0;
	multiFindBySettlementGroupIDForCombinationLeg=0;
	findByPartRoleAndSGForPartRoleAccount=0;
	multiFindBySettlementGroupIDForPartRoleAccount=0;
	multiFindStartByParticipantIDForPartRoleAccount=0;
	multiFindBySettlementGroupIDForPartProductRole=0;
	findByParticipantProductRoleForPartProductRole=0;
	multiFindBySettlementGroupIDForPartProductRight=0;
	findByParticipantAndProductForPartProductRight=0;
	multiFindBySettlementGroupIDForPartInstrumentRight=0;
	findByParticipantAndInstrumentForPartInstrumentRight=0;
	multiFindBySettlementGroupIDForClientProductRight=0;
	findByClientAndProductForClientProductRight=0;
	multiFindBySettlementGroupIDForClientInstrumentRight=0;
	findByClientAndInstrumentForClientInstrumentRight=0;
	multiFindBySettlementGroupIDForPartClientProductRight=0;
	findByParticipantAndClientAndProductForPartClientProductRight=0;
	multiFindBySettlementGroupIDForPartClientInstrumentRight=0;
	findByParticipantAndClientAndInstrumentForPartClientInstrumentRight=0;
	multiFindBySettlementGroupIDForCurrProductProperty=0;
	findByProductIDForCurrProductProperty=0;
	multiFindBySettlementGroupIDForCurrInstrumentProperty=0;
	findByInstrumentIDForCurrInstrumentProperty=0;
	multiFindBySettlementGroupIDForCurrPriceBanding=0;
	findByInstrumentAndSegmentForCurrPriceBanding=0;
	findByInstrumentAndOneSegmentForCurrPriceBanding=0;
	multiFindBySettlementGroupIDForCurrMarginRate=0;
	findByInstrumentAndPartForCurrMarginRate=0;
	multiFindBySettlementGroupIDForCurrMarginRateDetail=0;
	findByInstrumentAndParticipantForCurrMarginRateDetail=0;
	multiFindBySettlementGroupIDForCurrPartPosiLimit=0;
	findByInstrumentAndPartForCurrPartPosiLimit=0;
	multiFindBySettlementGroupIDForCurrPartPosiLimitDetail=0;
	findByInstrumentAndPartForCurrPartPosiLimitDetail=0;
	findByInstrumentPartAndStartPositionForCurrPartPosiLimitDetail=0;
	multiFindBySettlementGroupIDForCurrClientPosiLimit=0;
	multiFindBySettlementGroupIDForCurrClientPosiLimitDetail=0;
	findByInstrumentAndClientTypeForCurrClientPosiLimitDetail=0;
	findByInstrumentClientTypeAndStartPositionForCurrClientPosiLimitDetail=0;
	multiFindBySettlementGroupIDForCurrSpecialPosiLimit=0;
	multiFindBySettlementGroupIDForCurrSpecialPosiLimitDetail=0;
	findByInstrumentAndClientForCurrSpecialPosiLimitDetail=0;
	findByInstrumentClientAndStartPositionForCurrSpecialPosiLimitDetail=0;
	multiFindBySettlementGroupIDForCurrHedgeRule=0;
	findByInstrumentIDForCurrHedgeRule=0;
	multiFindBySettlementGroupIDForCurrTradingSegmentAttr=0;
	multiFindByTimeForCurrTradingSegmentAttr=0;
	multiFindByInstrumentForCurrTradingSegmentAttr=0;
	findByInstrumentAndSegementForCurrTradingSegmentAttr=0;
	multiFindBySettlementGroupIDForCurrFuse=0;
	findByInstrumentIDForCurrFuse=0;
	multiFindBySettlementGroupIDForTradingAccount=0;
	findByAccountIDForTradingAccount=0;
	multiFindBySettlementGroupIDForBaseReserveAccount=0;
	findByAccountIDForBaseReserveAccount=0;
	findByPartAndInstrumentForPartPosition=0;
	multiFindStartByInstrumentForPartPosition=0;
	multiFindStartByParticipantForPartPosition=0;
	multiFindBySettlementGroupIDForPartPosition=0;
	findByPartClientAndInstrumentForClientPosition=0;
	multiFindByClientAndInstrumentForClientPosition=0;
	multiFindStartByParticipantForClientPosition=0;
	multiFindStartByClientForClientPosition=0;
	multiFindStartByInstrumentForClientPosition=0;
	multiFindByInstrumentIDForClientPosition=0;
	multiFindBySettlementGroupIDForClientPosition=0;
	multiFindBySettlementGroupIDForHedgeVolume=0;
	findByInstrumentPartClientForHedgeVolume=0;
	multiFindStartByPartClientAndInstrumentForHedgeVolume=0;
	multiFindBySettlementGroupIDForRemainOrder=0;
	multiFindByInstrumentIDForRemainOrder=0;
	multiFindBySettlementGroupIDForMarketData=0;
	findByInstrumentIDForMarketData=0;
	findByPartAndInstrumentForClearingPartPosition=0;
	multiFindBySettlementGroupIDForClearingPartPosition=0;
	findByInstrumentIDForInstrumentStatus=0;
	multiFindStartByInstrumentIDForInstrumentStatus=0;
	multiFindBySettlementGroupIDForInstrumentStatus=0;
	findByOrderIDForOrder=0;
	multiFindStartByParticipantIDForOrder=0;
	multiFindBySettlementGroupIDForOrder=0;
	findByOrderLocalIDForOrder=0;
	multiFindByUserIDForOrder=0;
	multiFindByInstrumentIDForOrder=0;
	multiFindStartByInstrumentIDForOrder=0;
	findByCombOrderIDForCombOrder=0;
	multiFindStartByParticipantIDForCombOrder=0;
	multiFindBySettlementGroupIDForCombOrder=0;
	findByCombOrderLocalIDForCombOrder=0;
	multiFindByUserIDForCombOrder=0;
	findByOTCOrderLocalIDForOTCOrder=0;
	findByOTCOrderIDForOTCOrder=0;
	multiFindBySettlementGroupIDForOTCOrder=0;
	multiFindByImplyLegForImplyOrder=0;
	multiFindByImplyOrderAndAnchorLegForImplyOrder=0;
	multiFindByImplyOrderForImplyOrder=0;
	findByQuoteIDForQuote=0;
	findByQuoteLocalIDForQuote=0;
	multiFindByUserIDForQuote=0;
	findByPartClientAndInstrumentForQuote=0;
	multiFindStartByParticipantIDForQuote=0;
	multiFindBySettlementGroupIDForQuote=0;
	findByAskOrderForQuote=0;
	findByBidOrderForQuote=0;
	multiFindByBuyMBLDataForMBLMarketData=0;
	multiFindBySellMBLDataForMBLMarketData=0;
	multiFindStartByBuyMBLDataForMBLMarketData=0;
	multiFindStartBySellMBLDataForMBLMarketData=0;
	findByPriceForMBLMarketData=0;
	multiFindAllForTrade=0;
	multiFindByTradeIDForTrade=0;
	multiFindStartByPartIDForTrade=0;
	multiFindByClientIDForTrade=0;
	multiFindStartByInstrumentIDForTrade=0;
	multiFindBySettlementGroupIDForTrade=0;
	findByInstrumentIDForFusePhase=0;
	multiFindBySettlementGroupIDForFusePhase=0;
	multiFindBySettlementGroupIDForExecOrder=0;
	findByExecOrderIDForExecOrder=0;
	multiFindByParticipantIDForExecOrder=0;
	multiFindByClientIDForExecOrder=0;
	multiFindByClientIDAndInstrumentIDForExecOrder=0;
	findByExecOrderLocalIDForExecOrder=0;
	multiFindByUserIDForExecOrder=0;
	multiFindBySettlementGroupIDForUniPressure=0;
	findByInstrumentIDForUniPressure=0;
	multiFindBySettlementGroupIDForBasePriceLimit=0;
	findByInstrumentIDForBasePriceLimit=0;
	multiFindBySettlementGroupIDForCreditLimit=0;
	findByParticipantIDForCreditLimit=0;
	multiFindAllByParticipantIDForCreditLimit=0;
	multiFindAllByClearingPartIDForCreditLimit=0;
	multiFindAllForCreditLimit=0;
	multiFindBySettlementGroupIDForCurrInstrumentOption=0;
	findByInstrumentIDForCurrInstrumentOption=0;
}
#endif
