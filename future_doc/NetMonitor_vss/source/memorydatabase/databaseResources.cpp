/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseResources.cpp
///@brief实现了若干内存数据资源，可以放置于事务中
///@history 
///20060127	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "databaseResources.h"


CMemoryStack<CExchangeDataSyncStatusResource> CExchangeDataSyncStatusResource::resourceList;

CExchangeDataSyncStatusResource * CExchangeDataSyncStatusResource::alloc(int type, CExchangeDataSyncStatusFactory *pFactory, CExchangeDataSyncStatus *pObject, CWriteableExchangeDataSyncStatus *pWriteableObject, bool updateIndex)
{
	CExchangeDataSyncStatusResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CExchangeDataSyncStatusResource::free(void)
{
	resourceList.free(this);
}

CExchangeDataSyncStatusResource::CExchangeDataSyncStatusResource(void)
{
}

CExchangeDataSyncStatusResource::~CExchangeDataSyncStatusResource(void)
{
}

void CExchangeDataSyncStatusResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CExchangeDataSyncStatus *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CExchangeDataSyncStatus *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CExchangeDataSyncStatusResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CExchangeDataSyncStatus *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CExchangeDataSyncStatus *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CExchangeDataSyncStatusResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSGDataSyncStatusResource> CSGDataSyncStatusResource::resourceList;

CSGDataSyncStatusResource * CSGDataSyncStatusResource::alloc(int type, CSGDataSyncStatusFactory *pFactory, CSGDataSyncStatus *pObject, CWriteableSGDataSyncStatus *pWriteableObject, bool updateIndex)
{
	CSGDataSyncStatusResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSGDataSyncStatusResource::free(void)
{
	resourceList.free(this);
}

CSGDataSyncStatusResource::CSGDataSyncStatusResource(void)
{
}

CSGDataSyncStatusResource::~CSGDataSyncStatusResource(void)
{
}

void CSGDataSyncStatusResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSGDataSyncStatus *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSGDataSyncStatus *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CSGDataSyncStatusResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSGDataSyncStatus *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSGDataSyncStatus *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CSGDataSyncStatusResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCurrentTimeResource> CCurrentTimeResource::resourceList;

CCurrentTimeResource * CCurrentTimeResource::alloc(int type, CCurrentTimeFactory *pFactory, CCurrentTime *pObject, CWriteableCurrentTime *pWriteableObject, bool updateIndex)
{
	CCurrentTimeResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCurrentTimeResource::free(void)
{
	resourceList.free(this);
}

CCurrentTimeResource::CCurrentTimeResource(void)
{
}

CCurrentTimeResource::~CCurrentTimeResource(void)
{
}

void CCurrentTimeResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCurrentTime *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCurrentTime *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCurrentTimeResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCurrentTime *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCurrentTime *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCurrentTimeResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CDataCenterDescResource> CDataCenterDescResource::resourceList;

CDataCenterDescResource * CDataCenterDescResource::alloc(int type, CDataCenterDescFactory *pFactory, CDataCenterDesc *pObject, CWriteableDataCenterDesc *pWriteableObject, bool updateIndex)
{
	CDataCenterDescResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CDataCenterDescResource::free(void)
{
	resourceList.free(this);
}

CDataCenterDescResource::CDataCenterDescResource(void)
{
}

CDataCenterDescResource::~CDataCenterDescResource(void)
{
}

void CDataCenterDescResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CDataCenterDesc *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CDataCenterDesc *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CDataCenterDescResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CDataCenterDesc *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CDataCenterDesc *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CDataCenterDescResource::getPriority(void)
{
	return 0;
}


CMemoryStack<CExchangeResource> CExchangeResource::resourceList;

CExchangeResource * CExchangeResource::alloc(int type, CExchangeFactory *pFactory, CExchange *pObject, CWriteableExchange *pWriteableObject, bool updateIndex)
{
	CExchangeResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CExchangeResource::free(void)
{
	resourceList.free(this);
}

CExchangeResource::CExchangeResource(void)
{
}

CExchangeResource::~CExchangeResource(void)
{
}

void CExchangeResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CExchange *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CExchange *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CExchangeResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CExchange *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CExchange *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CExchangeResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSettlementGroupResource> CSettlementGroupResource::resourceList;

CSettlementGroupResource * CSettlementGroupResource::alloc(int type, CSettlementGroupFactory *pFactory, CSettlementGroup *pObject, CWriteableSettlementGroup *pWriteableObject, bool updateIndex)
{
	CSettlementGroupResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSettlementGroupResource::free(void)
{
	resourceList.free(this);
}

CSettlementGroupResource::CSettlementGroupResource(void)
{
}

CSettlementGroupResource::~CSettlementGroupResource(void)
{
}

void CSettlementGroupResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSettlementGroup *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSettlementGroup *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CSettlementGroupResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSettlementGroup *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSettlementGroup *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CSettlementGroupResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CMarketResource> CMarketResource::resourceList;

CMarketResource * CMarketResource::alloc(int type, CMarketFactory *pFactory, CMarket *pObject, CWriteableMarket *pWriteableObject, bool updateIndex)
{
	CMarketResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CMarketResource::free(void)
{
	resourceList.free(this);
}

CMarketResource::CMarketResource(void)
{
}

CMarketResource::~CMarketResource(void)
{
}

void CMarketResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CMarket *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CMarket *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CMarketResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CMarket *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CMarket *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CMarketResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CMarketProductResource> CMarketProductResource::resourceList;

CMarketProductResource * CMarketProductResource::alloc(int type, CMarketProductFactory *pFactory, CMarketProduct *pObject, CWriteableMarketProduct *pWriteableObject, bool updateIndex)
{
	CMarketProductResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CMarketProductResource::free(void)
{
	resourceList.free(this);
}

CMarketProductResource::CMarketProductResource(void)
{
}

CMarketProductResource::~CMarketProductResource(void)
{
}

void CMarketProductResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CMarketProduct *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CMarketProduct *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CMarketProductResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CMarketProduct *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CMarketProduct *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CMarketProductResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CMarketProductGroupResource> CMarketProductGroupResource::resourceList;

CMarketProductGroupResource * CMarketProductGroupResource::alloc(int type, CMarketProductGroupFactory *pFactory, CMarketProductGroup *pObject, CWriteableMarketProductGroup *pWriteableObject, bool updateIndex)
{
	CMarketProductGroupResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CMarketProductGroupResource::free(void)
{
	resourceList.free(this);
}

CMarketProductGroupResource::CMarketProductGroupResource(void)
{
}

CMarketProductGroupResource::~CMarketProductGroupResource(void)
{
}

void CMarketProductGroupResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CMarketProductGroup *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CMarketProductGroup *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CMarketProductGroupResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CMarketProductGroup *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CMarketProductGroup *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CMarketProductGroupResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CMdPubStatusResource> CMdPubStatusResource::resourceList;

CMdPubStatusResource * CMdPubStatusResource::alloc(int type, CMdPubStatusFactory *pFactory, CMdPubStatus *pObject, CWriteableMdPubStatus *pWriteableObject, bool updateIndex)
{
	CMdPubStatusResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CMdPubStatusResource::free(void)
{
	resourceList.free(this);
}

CMdPubStatusResource::CMdPubStatusResource(void)
{
}

CMdPubStatusResource::~CMdPubStatusResource(void)
{
}

void CMdPubStatusResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CMdPubStatus *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CMdPubStatus *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CMdPubStatusResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CMdPubStatus *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CMdPubStatus *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CMdPubStatusResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CMarketDataTopicResource> CMarketDataTopicResource::resourceList;

CMarketDataTopicResource * CMarketDataTopicResource::alloc(int type, CMarketDataTopicFactory *pFactory, CMarketDataTopic *pObject, CWriteableMarketDataTopic *pWriteableObject, bool updateIndex)
{
	CMarketDataTopicResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CMarketDataTopicResource::free(void)
{
	resourceList.free(this);
}

CMarketDataTopicResource::CMarketDataTopicResource(void)
{
}

CMarketDataTopicResource::~CMarketDataTopicResource(void)
{
}

void CMarketDataTopicResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CMarketDataTopic *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CMarketDataTopic *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CMarketDataTopicResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CMarketDataTopic *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CMarketDataTopic *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CMarketDataTopicResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CPartTopicSubscribeResource> CPartTopicSubscribeResource::resourceList;

CPartTopicSubscribeResource * CPartTopicSubscribeResource::alloc(int type, CPartTopicSubscribeFactory *pFactory, CPartTopicSubscribe *pObject, CWriteablePartTopicSubscribe *pWriteableObject, bool updateIndex)
{
	CPartTopicSubscribeResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CPartTopicSubscribeResource::free(void)
{
	resourceList.free(this);
}

CPartTopicSubscribeResource::CPartTopicSubscribeResource(void)
{
}

CPartTopicSubscribeResource::~CPartTopicSubscribeResource(void)
{
}

void CPartTopicSubscribeResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CPartTopicSubscribe *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CPartTopicSubscribe *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CPartTopicSubscribeResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CPartTopicSubscribe *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CPartTopicSubscribe *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CPartTopicSubscribeResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CParticipantResource> CParticipantResource::resourceList;

CParticipantResource * CParticipantResource::alloc(int type, CParticipantFactory *pFactory, CParticipant *pObject, CWriteableParticipant *pWriteableObject, bool updateIndex)
{
	CParticipantResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CParticipantResource::free(void)
{
	resourceList.free(this);
}

CParticipantResource::CParticipantResource(void)
{
}

CParticipantResource::~CParticipantResource(void)
{
}

void CParticipantResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CParticipant *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CParticipant *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CParticipantResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CParticipant *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CParticipant *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CParticipantResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CUserResource> CUserResource::resourceList;

CUserResource * CUserResource::alloc(int type, CUserFactory *pFactory, CUser *pObject, CWriteableUser *pWriteableObject, bool updateIndex)
{
	CUserResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CUserResource::free(void)
{
	resourceList.free(this);
}

CUserResource::CUserResource(void)
{
}

CUserResource::~CUserResource(void)
{
}

void CUserResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CUser *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CUser *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CUserResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CUser *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CUser *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CUserResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CClientResource> CClientResource::resourceList;

CClientResource * CClientResource::alloc(int type, CClientFactory *pFactory, CClient *pObject, CWriteableClient *pWriteableObject, bool updateIndex)
{
	CClientResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CClientResource::free(void)
{
	resourceList.free(this);
}

CClientResource::CClientResource(void)
{
}

CClientResource::~CClientResource(void)
{
}

void CClientResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CClient *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CClient *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CClientResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CClient *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CClient *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CClientResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CUserIPResource> CUserIPResource::resourceList;

CUserIPResource * CUserIPResource::alloc(int type, CUserIPFactory *pFactory, CUserIP *pObject, CWriteableUserIP *pWriteableObject, bool updateIndex)
{
	CUserIPResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CUserIPResource::free(void)
{
	resourceList.free(this);
}

CUserIPResource::CUserIPResource(void)
{
}

CUserIPResource::~CUserIPResource(void)
{
}

void CUserIPResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CUserIP *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CUserIP *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CUserIPResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CUserIP *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CUserIP *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CUserIPResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CPartClientResource> CPartClientResource::resourceList;

CPartClientResource * CPartClientResource::alloc(int type, CPartClientFactory *pFactory, CPartClient *pObject, CWriteablePartClient *pWriteableObject, bool updateIndex)
{
	CPartClientResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CPartClientResource::free(void)
{
	resourceList.free(this);
}

CPartClientResource::CPartClientResource(void)
{
}

CPartClientResource::~CPartClientResource(void)
{
}

void CPartClientResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CPartClient *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CPartClient *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CPartClientResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CPartClient *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CPartClient *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CPartClientResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CClearingTradingPartResource> CClearingTradingPartResource::resourceList;

CClearingTradingPartResource * CClearingTradingPartResource::alloc(int type, CClearingTradingPartFactory *pFactory, CClearingTradingPart *pObject, CWriteableClearingTradingPart *pWriteableObject, bool updateIndex)
{
	CClearingTradingPartResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CClearingTradingPartResource::free(void)
{
	resourceList.free(this);
}

CClearingTradingPartResource::CClearingTradingPartResource(void)
{
}

CClearingTradingPartResource::~CClearingTradingPartResource(void)
{
}

void CClearingTradingPartResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CClearingTradingPart *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CClearingTradingPart *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CClearingTradingPartResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CClearingTradingPart *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CClearingTradingPart *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CClearingTradingPartResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CAliasDefineResource> CAliasDefineResource::resourceList;

CAliasDefineResource * CAliasDefineResource::alloc(int type, CAliasDefineFactory *pFactory, CAliasDefine *pObject, CWriteableAliasDefine *pWriteableObject, bool updateIndex)
{
	CAliasDefineResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CAliasDefineResource::free(void)
{
	resourceList.free(this);
}

CAliasDefineResource::CAliasDefineResource(void)
{
}

CAliasDefineResource::~CAliasDefineResource(void)
{
}

void CAliasDefineResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CAliasDefine *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CAliasDefine *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CAliasDefineResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CAliasDefine *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CAliasDefine *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CAliasDefineResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CUserFunctionRightResource> CUserFunctionRightResource::resourceList;

CUserFunctionRightResource * CUserFunctionRightResource::alloc(int type, CUserFunctionRightFactory *pFactory, CUserFunctionRight *pObject, CWriteableUserFunctionRight *pWriteableObject, bool updateIndex)
{
	CUserFunctionRightResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CUserFunctionRightResource::free(void)
{
	resourceList.free(this);
}

CUserFunctionRightResource::CUserFunctionRightResource(void)
{
}

CUserFunctionRightResource::~CUserFunctionRightResource(void)
{
}

void CUserFunctionRightResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CUserFunctionRight *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CUserFunctionRight *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CUserFunctionRightResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CUserFunctionRight *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CUserFunctionRight *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CUserFunctionRightResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CAccountResource> CAccountResource::resourceList;

CAccountResource * CAccountResource::alloc(int type, CAccountFactory *pFactory, CAccount *pObject, CWriteableAccount *pWriteableObject, bool updateIndex)
{
	CAccountResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CAccountResource::free(void)
{
	resourceList.free(this);
}

CAccountResource::CAccountResource(void)
{
}

CAccountResource::~CAccountResource(void)
{
}

void CAccountResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CAccount *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CAccount *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CAccountResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CAccount *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CAccount *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CAccountResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CUserCommFluxResource> CUserCommFluxResource::resourceList;

CUserCommFluxResource * CUserCommFluxResource::alloc(int type, CUserCommFluxFactory *pFactory, CUserCommFlux *pObject, CWriteableUserCommFlux *pWriteableObject, bool updateIndex)
{
	CUserCommFluxResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CUserCommFluxResource::free(void)
{
	resourceList.free(this);
}

CUserCommFluxResource::CUserCommFluxResource(void)
{
}

CUserCommFluxResource::~CUserCommFluxResource(void)
{
}

void CUserCommFluxResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CUserCommFlux *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CUserCommFlux *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CUserCommFluxResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CUserCommFlux *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CUserCommFlux *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CUserCommFluxResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CMarketDataLogResource> CMarketDataLogResource::resourceList;

CMarketDataLogResource * CMarketDataLogResource::alloc(int type, CMarketDataLogFactory *pFactory, CMarketDataLog *pObject, CWriteableMarketDataLog *pWriteableObject, bool updateIndex)
{
	CMarketDataLogResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CMarketDataLogResource::free(void)
{
	resourceList.free(this);
}

CMarketDataLogResource::CMarketDataLogResource(void)
{
}

CMarketDataLogResource::~CMarketDataLogResource(void)
{
}

void CMarketDataLogResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CMarketDataLog *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CMarketDataLog *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CMarketDataLogResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CMarketDataLog *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CMarketDataLog *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CMarketDataLogResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CUserSessionResource> CUserSessionResource::resourceList;

CUserSessionResource * CUserSessionResource::alloc(int type, CUserSessionFactory *pFactory, CUserSession *pObject, CWriteableUserSession *pWriteableObject, bool updateIndex)
{
	CUserSessionResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CUserSessionResource::free(void)
{
	resourceList.free(this);
}

CUserSessionResource::CUserSessionResource(void)
{
}

CUserSessionResource::~CUserSessionResource(void)
{
}

void CUserSessionResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CUserSession *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CUserSession *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CUserSessionResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CUserSession *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CUserSession *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CUserSessionResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CMDSessionResource> CMDSessionResource::resourceList;

CMDSessionResource * CMDSessionResource::alloc(int type, CMDSessionFactory *pFactory, CMDSession *pObject, CWriteableMDSession *pWriteableObject, bool updateIndex)
{
	CMDSessionResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CMDSessionResource::free(void)
{
	resourceList.free(this);
}

CMDSessionResource::CMDSessionResource(void)
{
}

CMDSessionResource::~CMDSessionResource(void)
{
}

void CMDSessionResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CMDSession *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CMDSession *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CMDSessionResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CMDSession *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CMDSession *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CMDSessionResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CLoginInfoResource> CLoginInfoResource::resourceList;

CLoginInfoResource * CLoginInfoResource::alloc(int type, CLoginInfoFactory *pFactory, CLoginInfo *pObject, CWriteableLoginInfo *pWriteableObject, bool updateIndex)
{
	CLoginInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CLoginInfoResource::free(void)
{
	resourceList.free(this);
}

CLoginInfoResource::CLoginInfoResource(void)
{
}

CLoginInfoResource::~CLoginInfoResource(void)
{
}

void CLoginInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CLoginInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CLoginInfo *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CLoginInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CLoginInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CLoginInfo *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CLoginInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CDepthMarketDataDetailResource> CDepthMarketDataDetailResource::resourceList;

CDepthMarketDataDetailResource * CDepthMarketDataDetailResource::alloc(int type, CDepthMarketDataDetailFactory *pFactory, CDepthMarketDataDetail *pObject, CWriteableDepthMarketDataDetail *pWriteableObject, bool updateIndex)
{
	CDepthMarketDataDetailResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CDepthMarketDataDetailResource::free(void)
{
	resourceList.free(this);
}

CDepthMarketDataDetailResource::CDepthMarketDataDetailResource(void)
{
}

CDepthMarketDataDetailResource::~CDepthMarketDataDetailResource(void)
{
}

void CDepthMarketDataDetailResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CDepthMarketDataDetail *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CDepthMarketDataDetail *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CDepthMarketDataDetailResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CDepthMarketDataDetail *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CDepthMarketDataDetail *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CDepthMarketDataDetailResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CInstrumentStatusDetailResource> CInstrumentStatusDetailResource::resourceList;

CInstrumentStatusDetailResource * CInstrumentStatusDetailResource::alloc(int type, CInstrumentStatusDetailFactory *pFactory, CInstrumentStatusDetail *pObject, CWriteableInstrumentStatusDetail *pWriteableObject, bool updateIndex)
{
	CInstrumentStatusDetailResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CInstrumentStatusDetailResource::free(void)
{
	resourceList.free(this);
}

CInstrumentStatusDetailResource::CInstrumentStatusDetailResource(void)
{
}

CInstrumentStatusDetailResource::~CInstrumentStatusDetailResource(void)
{
}

void CInstrumentStatusDetailResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CInstrumentStatusDetail *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CInstrumentStatusDetail *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CInstrumentStatusDetailResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CInstrumentStatusDetail *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CInstrumentStatusDetail *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CInstrumentStatusDetailResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CFrontStatusResource> CFrontStatusResource::resourceList;

CFrontStatusResource * CFrontStatusResource::alloc(int type, CFrontStatusFactory *pFactory, CFrontStatus *pObject, CWriteableFrontStatus *pWriteableObject, bool updateIndex)
{
	CFrontStatusResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CFrontStatusResource::free(void)
{
	resourceList.free(this);
}

CFrontStatusResource::CFrontStatusResource(void)
{
}

CFrontStatusResource::~CFrontStatusResource(void)
{
}

void CFrontStatusResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CFrontStatus *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CFrontStatus *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CFrontStatusResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CFrontStatus *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CFrontStatus *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CFrontStatusResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CMaxLocalIDResource> CMaxLocalIDResource::resourceList;

CMaxLocalIDResource * CMaxLocalIDResource::alloc(int type, CMaxLocalIDFactory *pFactory, CMaxLocalID *pObject, CWriteableMaxLocalID *pWriteableObject, bool updateIndex)
{
	CMaxLocalIDResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CMaxLocalIDResource::free(void)
{
	resourceList.free(this);
}

CMaxLocalIDResource::CMaxLocalIDResource(void)
{
}

CMaxLocalIDResource::~CMaxLocalIDResource(void)
{
}

void CMaxLocalIDResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CMaxLocalID *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CMaxLocalID *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CMaxLocalIDResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CMaxLocalID *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CMaxLocalID *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CMaxLocalIDResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CBulletinResource> CBulletinResource::resourceList;

CBulletinResource * CBulletinResource::alloc(int type, CBulletinFactory *pFactory, CBulletin *pObject, CWriteableBulletin *pWriteableObject, bool updateIndex)
{
	CBulletinResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CBulletinResource::free(void)
{
	resourceList.free(this);
}

CBulletinResource::CBulletinResource(void)
{
}

CBulletinResource::~CBulletinResource(void)
{
}

void CBulletinResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CBulletin *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CBulletin *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CBulletinResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CBulletin *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CBulletin *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CBulletinResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CMarketDataModifyResource> CMarketDataModifyResource::resourceList;

CMarketDataModifyResource * CMarketDataModifyResource::alloc(int type, CMarketDataModifyFactory *pFactory, CMarketDataModify *pObject, CWriteableMarketDataModify *pWriteableObject, bool updateIndex)
{
	CMarketDataModifyResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CMarketDataModifyResource::free(void)
{
	resourceList.free(this);
}

CMarketDataModifyResource::CMarketDataModifyResource(void)
{
}

CMarketDataModifyResource::~CMarketDataModifyResource(void)
{
}

void CMarketDataModifyResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CMarketDataModify *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CMarketDataModify *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CMarketDataModifyResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CMarketDataModify *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CMarketDataModify *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CMarketDataModifyResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CDepthMarketDataResource> CDepthMarketDataResource::resourceList;

CDepthMarketDataResource * CDepthMarketDataResource::alloc(int type, CDepthMarketDataFactory *pFactory, CDepthMarketData *pObject, CWriteableDepthMarketData *pWriteableObject, bool updateIndex)
{
	CDepthMarketDataResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CDepthMarketDataResource::free(void)
{
	resourceList.free(this);
}

CDepthMarketDataResource::CDepthMarketDataResource(void)
{
}

CDepthMarketDataResource::~CDepthMarketDataResource(void)
{
}

void CDepthMarketDataResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CDepthMarketData *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CDepthMarketData *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CDepthMarketDataResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CDepthMarketData *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CDepthMarketData *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CDepthMarketDataResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CTopicMarketDataResource> CTopicMarketDataResource::resourceList;

CTopicMarketDataResource * CTopicMarketDataResource::alloc(int type, CTopicMarketDataFactory *pFactory, CTopicMarketData *pObject, CWriteableTopicMarketData *pWriteableObject, bool updateIndex)
{
	CTopicMarketDataResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CTopicMarketDataResource::free(void)
{
	resourceList.free(this);
}

CTopicMarketDataResource::CTopicMarketDataResource(void)
{
}

CTopicMarketDataResource::~CTopicMarketDataResource(void)
{
}

void CTopicMarketDataResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CTopicMarketData *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CTopicMarketData *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CTopicMarketDataResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CTopicMarketData *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CTopicMarketData *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CTopicMarketDataResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CTopicMarketDataVersionResource> CTopicMarketDataVersionResource::resourceList;

CTopicMarketDataVersionResource * CTopicMarketDataVersionResource::alloc(int type, CTopicMarketDataVersionFactory *pFactory, CTopicMarketDataVersion *pObject, CWriteableTopicMarketDataVersion *pWriteableObject, bool updateIndex)
{
	CTopicMarketDataVersionResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CTopicMarketDataVersionResource::free(void)
{
	resourceList.free(this);
}

CTopicMarketDataVersionResource::CTopicMarketDataVersionResource(void)
{
}

CTopicMarketDataVersionResource::~CTopicMarketDataVersionResource(void)
{
}

void CTopicMarketDataVersionResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CTopicMarketDataVersion *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CTopicMarketDataVersion *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CTopicMarketDataVersionResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CTopicMarketDataVersion *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CTopicMarketDataVersion *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CTopicMarketDataVersionResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CInformationResource> CInformationResource::resourceList;

CInformationResource * CInformationResource::alloc(int type, CInformationFactory *pFactory, CInformation *pObject, CWriteableInformation *pWriteableObject, bool updateIndex)
{
	CInformationResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CInformationResource::free(void)
{
	resourceList.free(this);
}

CInformationResource::CInformationResource(void)
{
}

CInformationResource::~CInformationResource(void)
{
}

void CInformationResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CInformation *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CInformation *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CInformationResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CInformation *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CInformation *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CInformationResource::getPriority(void)
{
	return 2;
}


CMemoryStack<COrderCountResource> COrderCountResource::resourceList;

COrderCountResource * COrderCountResource::alloc(int type, COrderCountFactory *pFactory, COrderCount *pObject, CWriteableOrderCount *pWriteableObject, bool updateIndex)
{
	COrderCountResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void COrderCountResource::free(void)
{
	resourceList.free(this);
}

COrderCountResource::COrderCountResource(void)
{
}

COrderCountResource::~COrderCountResource(void)
{
}

void COrderCountResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((COrderCount *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((COrderCount *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void COrderCountResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((COrderCount *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((COrderCount *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int COrderCountResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CInstrumentResource> CInstrumentResource::resourceList;

CInstrumentResource * CInstrumentResource::alloc(int type, CInstrumentFactory *pFactory, CInstrument *pObject, CWriteableInstrument *pWriteableObject, bool updateIndex)
{
	CInstrumentResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CInstrumentResource::free(void)
{
	resourceList.free(this);
}

CInstrumentResource::CInstrumentResource(void)
{
}

CInstrumentResource::~CInstrumentResource(void)
{
}

void CInstrumentResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CInstrument *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CInstrument *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CInstrumentResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CInstrument *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CInstrument *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CInstrumentResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCombinationLegResource> CCombinationLegResource::resourceList;

CCombinationLegResource * CCombinationLegResource::alloc(int type, CCombinationLegFactory *pFactory, CCombinationLeg *pObject, CWriteableCombinationLeg *pWriteableObject, bool updateIndex)
{
	CCombinationLegResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCombinationLegResource::free(void)
{
	resourceList.free(this);
}

CCombinationLegResource::CCombinationLegResource(void)
{
}

CCombinationLegResource::~CCombinationLegResource(void)
{
}

void CCombinationLegResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCombinationLeg *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCombinationLeg *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCombinationLegResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCombinationLeg *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCombinationLeg *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCombinationLegResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CPartRoleAccountResource> CPartRoleAccountResource::resourceList;

CPartRoleAccountResource * CPartRoleAccountResource::alloc(int type, CPartRoleAccountFactory *pFactory, CPartRoleAccount *pObject, CWriteablePartRoleAccount *pWriteableObject, bool updateIndex)
{
	CPartRoleAccountResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CPartRoleAccountResource::free(void)
{
	resourceList.free(this);
}

CPartRoleAccountResource::CPartRoleAccountResource(void)
{
}

CPartRoleAccountResource::~CPartRoleAccountResource(void)
{
}

void CPartRoleAccountResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CPartRoleAccount *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CPartRoleAccount *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CPartRoleAccountResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CPartRoleAccount *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CPartRoleAccount *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CPartRoleAccountResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CPartProductRoleResource> CPartProductRoleResource::resourceList;

CPartProductRoleResource * CPartProductRoleResource::alloc(int type, CPartProductRoleFactory *pFactory, CPartProductRole *pObject, CWriteablePartProductRole *pWriteableObject, bool updateIndex)
{
	CPartProductRoleResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CPartProductRoleResource::free(void)
{
	resourceList.free(this);
}

CPartProductRoleResource::CPartProductRoleResource(void)
{
}

CPartProductRoleResource::~CPartProductRoleResource(void)
{
}

void CPartProductRoleResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CPartProductRole *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CPartProductRole *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CPartProductRoleResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CPartProductRole *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CPartProductRole *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CPartProductRoleResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CPartProductRightResource> CPartProductRightResource::resourceList;

CPartProductRightResource * CPartProductRightResource::alloc(int type, CPartProductRightFactory *pFactory, CPartProductRight *pObject, CWriteablePartProductRight *pWriteableObject, bool updateIndex)
{
	CPartProductRightResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CPartProductRightResource::free(void)
{
	resourceList.free(this);
}

CPartProductRightResource::CPartProductRightResource(void)
{
}

CPartProductRightResource::~CPartProductRightResource(void)
{
}

void CPartProductRightResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CPartProductRight *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CPartProductRight *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CPartProductRightResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CPartProductRight *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CPartProductRight *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CPartProductRightResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CPartInstrumentRightResource> CPartInstrumentRightResource::resourceList;

CPartInstrumentRightResource * CPartInstrumentRightResource::alloc(int type, CPartInstrumentRightFactory *pFactory, CPartInstrumentRight *pObject, CWriteablePartInstrumentRight *pWriteableObject, bool updateIndex)
{
	CPartInstrumentRightResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CPartInstrumentRightResource::free(void)
{
	resourceList.free(this);
}

CPartInstrumentRightResource::CPartInstrumentRightResource(void)
{
}

CPartInstrumentRightResource::~CPartInstrumentRightResource(void)
{
}

void CPartInstrumentRightResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CPartInstrumentRight *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CPartInstrumentRight *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CPartInstrumentRightResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CPartInstrumentRight *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CPartInstrumentRight *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CPartInstrumentRightResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CClientProductRightResource> CClientProductRightResource::resourceList;

CClientProductRightResource * CClientProductRightResource::alloc(int type, CClientProductRightFactory *pFactory, CClientProductRight *pObject, CWriteableClientProductRight *pWriteableObject, bool updateIndex)
{
	CClientProductRightResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CClientProductRightResource::free(void)
{
	resourceList.free(this);
}

CClientProductRightResource::CClientProductRightResource(void)
{
}

CClientProductRightResource::~CClientProductRightResource(void)
{
}

void CClientProductRightResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CClientProductRight *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CClientProductRight *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CClientProductRightResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CClientProductRight *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CClientProductRight *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CClientProductRightResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CClientInstrumentRightResource> CClientInstrumentRightResource::resourceList;

CClientInstrumentRightResource * CClientInstrumentRightResource::alloc(int type, CClientInstrumentRightFactory *pFactory, CClientInstrumentRight *pObject, CWriteableClientInstrumentRight *pWriteableObject, bool updateIndex)
{
	CClientInstrumentRightResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CClientInstrumentRightResource::free(void)
{
	resourceList.free(this);
}

CClientInstrumentRightResource::CClientInstrumentRightResource(void)
{
}

CClientInstrumentRightResource::~CClientInstrumentRightResource(void)
{
}

void CClientInstrumentRightResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CClientInstrumentRight *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CClientInstrumentRight *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CClientInstrumentRightResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CClientInstrumentRight *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CClientInstrumentRight *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CClientInstrumentRightResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CPartClientProductRightResource> CPartClientProductRightResource::resourceList;

CPartClientProductRightResource * CPartClientProductRightResource::alloc(int type, CPartClientProductRightFactory *pFactory, CPartClientProductRight *pObject, CWriteablePartClientProductRight *pWriteableObject, bool updateIndex)
{
	CPartClientProductRightResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CPartClientProductRightResource::free(void)
{
	resourceList.free(this);
}

CPartClientProductRightResource::CPartClientProductRightResource(void)
{
}

CPartClientProductRightResource::~CPartClientProductRightResource(void)
{
}

void CPartClientProductRightResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CPartClientProductRight *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CPartClientProductRight *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CPartClientProductRightResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CPartClientProductRight *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CPartClientProductRight *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CPartClientProductRightResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CPartClientInstrumentRightResource> CPartClientInstrumentRightResource::resourceList;

CPartClientInstrumentRightResource * CPartClientInstrumentRightResource::alloc(int type, CPartClientInstrumentRightFactory *pFactory, CPartClientInstrumentRight *pObject, CWriteablePartClientInstrumentRight *pWriteableObject, bool updateIndex)
{
	CPartClientInstrumentRightResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CPartClientInstrumentRightResource::free(void)
{
	resourceList.free(this);
}

CPartClientInstrumentRightResource::CPartClientInstrumentRightResource(void)
{
}

CPartClientInstrumentRightResource::~CPartClientInstrumentRightResource(void)
{
}

void CPartClientInstrumentRightResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CPartClientInstrumentRight *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CPartClientInstrumentRight *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CPartClientInstrumentRightResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CPartClientInstrumentRight *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CPartClientInstrumentRight *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CPartClientInstrumentRightResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCurrProductPropertyResource> CCurrProductPropertyResource::resourceList;

CCurrProductPropertyResource * CCurrProductPropertyResource::alloc(int type, CCurrProductPropertyFactory *pFactory, CCurrProductProperty *pObject, CWriteableCurrProductProperty *pWriteableObject, bool updateIndex)
{
	CCurrProductPropertyResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCurrProductPropertyResource::free(void)
{
	resourceList.free(this);
}

CCurrProductPropertyResource::CCurrProductPropertyResource(void)
{
}

CCurrProductPropertyResource::~CCurrProductPropertyResource(void)
{
}

void CCurrProductPropertyResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCurrProductProperty *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCurrProductProperty *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCurrProductPropertyResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCurrProductProperty *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCurrProductProperty *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCurrProductPropertyResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCurrInstrumentPropertyResource> CCurrInstrumentPropertyResource::resourceList;

CCurrInstrumentPropertyResource * CCurrInstrumentPropertyResource::alloc(int type, CCurrInstrumentPropertyFactory *pFactory, CCurrInstrumentProperty *pObject, CWriteableCurrInstrumentProperty *pWriteableObject, bool updateIndex)
{
	CCurrInstrumentPropertyResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCurrInstrumentPropertyResource::free(void)
{
	resourceList.free(this);
}

CCurrInstrumentPropertyResource::CCurrInstrumentPropertyResource(void)
{
}

CCurrInstrumentPropertyResource::~CCurrInstrumentPropertyResource(void)
{
}

void CCurrInstrumentPropertyResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCurrInstrumentProperty *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCurrInstrumentProperty *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCurrInstrumentPropertyResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCurrInstrumentProperty *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCurrInstrumentProperty *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCurrInstrumentPropertyResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCurrPriceBandingResource> CCurrPriceBandingResource::resourceList;

CCurrPriceBandingResource * CCurrPriceBandingResource::alloc(int type, CCurrPriceBandingFactory *pFactory, CCurrPriceBanding *pObject, CWriteableCurrPriceBanding *pWriteableObject, bool updateIndex)
{
	CCurrPriceBandingResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCurrPriceBandingResource::free(void)
{
	resourceList.free(this);
}

CCurrPriceBandingResource::CCurrPriceBandingResource(void)
{
}

CCurrPriceBandingResource::~CCurrPriceBandingResource(void)
{
}

void CCurrPriceBandingResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCurrPriceBanding *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCurrPriceBanding *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCurrPriceBandingResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCurrPriceBanding *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCurrPriceBanding *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCurrPriceBandingResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCurrMarginRateResource> CCurrMarginRateResource::resourceList;

CCurrMarginRateResource * CCurrMarginRateResource::alloc(int type, CCurrMarginRateFactory *pFactory, CCurrMarginRate *pObject, CWriteableCurrMarginRate *pWriteableObject, bool updateIndex)
{
	CCurrMarginRateResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCurrMarginRateResource::free(void)
{
	resourceList.free(this);
}

CCurrMarginRateResource::CCurrMarginRateResource(void)
{
}

CCurrMarginRateResource::~CCurrMarginRateResource(void)
{
}

void CCurrMarginRateResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCurrMarginRate *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCurrMarginRate *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCurrMarginRateResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCurrMarginRate *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCurrMarginRate *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCurrMarginRateResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCurrMarginRateDetailResource> CCurrMarginRateDetailResource::resourceList;

CCurrMarginRateDetailResource * CCurrMarginRateDetailResource::alloc(int type, CCurrMarginRateDetailFactory *pFactory, CCurrMarginRateDetail *pObject, CWriteableCurrMarginRateDetail *pWriteableObject, bool updateIndex)
{
	CCurrMarginRateDetailResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCurrMarginRateDetailResource::free(void)
{
	resourceList.free(this);
}

CCurrMarginRateDetailResource::CCurrMarginRateDetailResource(void)
{
}

CCurrMarginRateDetailResource::~CCurrMarginRateDetailResource(void)
{
}

void CCurrMarginRateDetailResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCurrMarginRateDetail *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCurrMarginRateDetail *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCurrMarginRateDetailResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCurrMarginRateDetail *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCurrMarginRateDetail *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCurrMarginRateDetailResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCurrPartPosiLimitResource> CCurrPartPosiLimitResource::resourceList;

CCurrPartPosiLimitResource * CCurrPartPosiLimitResource::alloc(int type, CCurrPartPosiLimitFactory *pFactory, CCurrPartPosiLimit *pObject, CWriteableCurrPartPosiLimit *pWriteableObject, bool updateIndex)
{
	CCurrPartPosiLimitResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCurrPartPosiLimitResource::free(void)
{
	resourceList.free(this);
}

CCurrPartPosiLimitResource::CCurrPartPosiLimitResource(void)
{
}

CCurrPartPosiLimitResource::~CCurrPartPosiLimitResource(void)
{
}

void CCurrPartPosiLimitResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCurrPartPosiLimit *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCurrPartPosiLimit *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCurrPartPosiLimitResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCurrPartPosiLimit *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCurrPartPosiLimit *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCurrPartPosiLimitResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCurrPartPosiLimitDetailResource> CCurrPartPosiLimitDetailResource::resourceList;

CCurrPartPosiLimitDetailResource * CCurrPartPosiLimitDetailResource::alloc(int type, CCurrPartPosiLimitDetailFactory *pFactory, CCurrPartPosiLimitDetail *pObject, CWriteableCurrPartPosiLimitDetail *pWriteableObject, bool updateIndex)
{
	CCurrPartPosiLimitDetailResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCurrPartPosiLimitDetailResource::free(void)
{
	resourceList.free(this);
}

CCurrPartPosiLimitDetailResource::CCurrPartPosiLimitDetailResource(void)
{
}

CCurrPartPosiLimitDetailResource::~CCurrPartPosiLimitDetailResource(void)
{
}

void CCurrPartPosiLimitDetailResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCurrPartPosiLimitDetail *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCurrPartPosiLimitDetail *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCurrPartPosiLimitDetailResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCurrPartPosiLimitDetail *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCurrPartPosiLimitDetail *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCurrPartPosiLimitDetailResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCurrClientPosiLimitResource> CCurrClientPosiLimitResource::resourceList;

CCurrClientPosiLimitResource * CCurrClientPosiLimitResource::alloc(int type, CCurrClientPosiLimitFactory *pFactory, CCurrClientPosiLimit *pObject, CWriteableCurrClientPosiLimit *pWriteableObject, bool updateIndex)
{
	CCurrClientPosiLimitResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCurrClientPosiLimitResource::free(void)
{
	resourceList.free(this);
}

CCurrClientPosiLimitResource::CCurrClientPosiLimitResource(void)
{
}

CCurrClientPosiLimitResource::~CCurrClientPosiLimitResource(void)
{
}

void CCurrClientPosiLimitResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCurrClientPosiLimit *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCurrClientPosiLimit *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCurrClientPosiLimitResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCurrClientPosiLimit *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCurrClientPosiLimit *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCurrClientPosiLimitResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCurrClientPosiLimitDetailResource> CCurrClientPosiLimitDetailResource::resourceList;

CCurrClientPosiLimitDetailResource * CCurrClientPosiLimitDetailResource::alloc(int type, CCurrClientPosiLimitDetailFactory *pFactory, CCurrClientPosiLimitDetail *pObject, CWriteableCurrClientPosiLimitDetail *pWriteableObject, bool updateIndex)
{
	CCurrClientPosiLimitDetailResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCurrClientPosiLimitDetailResource::free(void)
{
	resourceList.free(this);
}

CCurrClientPosiLimitDetailResource::CCurrClientPosiLimitDetailResource(void)
{
}

CCurrClientPosiLimitDetailResource::~CCurrClientPosiLimitDetailResource(void)
{
}

void CCurrClientPosiLimitDetailResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCurrClientPosiLimitDetail *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCurrClientPosiLimitDetail *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCurrClientPosiLimitDetailResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCurrClientPosiLimitDetail *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCurrClientPosiLimitDetail *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCurrClientPosiLimitDetailResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCurrSpecialPosiLimitResource> CCurrSpecialPosiLimitResource::resourceList;

CCurrSpecialPosiLimitResource * CCurrSpecialPosiLimitResource::alloc(int type, CCurrSpecialPosiLimitFactory *pFactory, CCurrSpecialPosiLimit *pObject, CWriteableCurrSpecialPosiLimit *pWriteableObject, bool updateIndex)
{
	CCurrSpecialPosiLimitResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCurrSpecialPosiLimitResource::free(void)
{
	resourceList.free(this);
}

CCurrSpecialPosiLimitResource::CCurrSpecialPosiLimitResource(void)
{
}

CCurrSpecialPosiLimitResource::~CCurrSpecialPosiLimitResource(void)
{
}

void CCurrSpecialPosiLimitResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCurrSpecialPosiLimit *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCurrSpecialPosiLimit *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCurrSpecialPosiLimitResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCurrSpecialPosiLimit *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCurrSpecialPosiLimit *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCurrSpecialPosiLimitResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCurrSpecialPosiLimitDetailResource> CCurrSpecialPosiLimitDetailResource::resourceList;

CCurrSpecialPosiLimitDetailResource * CCurrSpecialPosiLimitDetailResource::alloc(int type, CCurrSpecialPosiLimitDetailFactory *pFactory, CCurrSpecialPosiLimitDetail *pObject, CWriteableCurrSpecialPosiLimitDetail *pWriteableObject, bool updateIndex)
{
	CCurrSpecialPosiLimitDetailResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCurrSpecialPosiLimitDetailResource::free(void)
{
	resourceList.free(this);
}

CCurrSpecialPosiLimitDetailResource::CCurrSpecialPosiLimitDetailResource(void)
{
}

CCurrSpecialPosiLimitDetailResource::~CCurrSpecialPosiLimitDetailResource(void)
{
}

void CCurrSpecialPosiLimitDetailResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCurrSpecialPosiLimitDetail *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCurrSpecialPosiLimitDetail *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCurrSpecialPosiLimitDetailResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCurrSpecialPosiLimitDetail *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCurrSpecialPosiLimitDetail *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCurrSpecialPosiLimitDetailResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCurrHedgeRuleResource> CCurrHedgeRuleResource::resourceList;

CCurrHedgeRuleResource * CCurrHedgeRuleResource::alloc(int type, CCurrHedgeRuleFactory *pFactory, CCurrHedgeRule *pObject, CWriteableCurrHedgeRule *pWriteableObject, bool updateIndex)
{
	CCurrHedgeRuleResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCurrHedgeRuleResource::free(void)
{
	resourceList.free(this);
}

CCurrHedgeRuleResource::CCurrHedgeRuleResource(void)
{
}

CCurrHedgeRuleResource::~CCurrHedgeRuleResource(void)
{
}

void CCurrHedgeRuleResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCurrHedgeRule *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCurrHedgeRule *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCurrHedgeRuleResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCurrHedgeRule *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCurrHedgeRule *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCurrHedgeRuleResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCurrTradingSegmentAttrResource> CCurrTradingSegmentAttrResource::resourceList;

CCurrTradingSegmentAttrResource * CCurrTradingSegmentAttrResource::alloc(int type, CCurrTradingSegmentAttrFactory *pFactory, CCurrTradingSegmentAttr *pObject, CWriteableCurrTradingSegmentAttr *pWriteableObject, bool updateIndex)
{
	CCurrTradingSegmentAttrResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCurrTradingSegmentAttrResource::free(void)
{
	resourceList.free(this);
}

CCurrTradingSegmentAttrResource::CCurrTradingSegmentAttrResource(void)
{
}

CCurrTradingSegmentAttrResource::~CCurrTradingSegmentAttrResource(void)
{
}

void CCurrTradingSegmentAttrResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCurrTradingSegmentAttr *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCurrTradingSegmentAttr *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCurrTradingSegmentAttrResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCurrTradingSegmentAttr *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCurrTradingSegmentAttr *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCurrTradingSegmentAttrResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCurrFuseResource> CCurrFuseResource::resourceList;

CCurrFuseResource * CCurrFuseResource::alloc(int type, CCurrFuseFactory *pFactory, CCurrFuse *pObject, CWriteableCurrFuse *pWriteableObject, bool updateIndex)
{
	CCurrFuseResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCurrFuseResource::free(void)
{
	resourceList.free(this);
}

CCurrFuseResource::CCurrFuseResource(void)
{
}

CCurrFuseResource::~CCurrFuseResource(void)
{
}

void CCurrFuseResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCurrFuse *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCurrFuse *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCurrFuseResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCurrFuse *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCurrFuse *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCurrFuseResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CTradingAccountResource> CTradingAccountResource::resourceList;

CTradingAccountResource * CTradingAccountResource::alloc(int type, CTradingAccountFactory *pFactory, CTradingAccount *pObject, CWriteableTradingAccount *pWriteableObject, bool updateIndex)
{
	CTradingAccountResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CTradingAccountResource::free(void)
{
	resourceList.free(this);
}

CTradingAccountResource::CTradingAccountResource(void)
{
}

CTradingAccountResource::~CTradingAccountResource(void)
{
}

void CTradingAccountResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CTradingAccount *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CTradingAccount *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CTradingAccountResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CTradingAccount *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CTradingAccount *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CTradingAccountResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CBaseReserveAccountResource> CBaseReserveAccountResource::resourceList;

CBaseReserveAccountResource * CBaseReserveAccountResource::alloc(int type, CBaseReserveAccountFactory *pFactory, CBaseReserveAccount *pObject, CWriteableBaseReserveAccount *pWriteableObject, bool updateIndex)
{
	CBaseReserveAccountResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CBaseReserveAccountResource::free(void)
{
	resourceList.free(this);
}

CBaseReserveAccountResource::CBaseReserveAccountResource(void)
{
}

CBaseReserveAccountResource::~CBaseReserveAccountResource(void)
{
}

void CBaseReserveAccountResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CBaseReserveAccount *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CBaseReserveAccount *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CBaseReserveAccountResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CBaseReserveAccount *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CBaseReserveAccount *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CBaseReserveAccountResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CPartPositionResource> CPartPositionResource::resourceList;

CPartPositionResource * CPartPositionResource::alloc(int type, CPartPositionFactory *pFactory, CPartPosition *pObject, CWriteablePartPosition *pWriteableObject, bool updateIndex)
{
	CPartPositionResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CPartPositionResource::free(void)
{
	resourceList.free(this);
}

CPartPositionResource::CPartPositionResource(void)
{
}

CPartPositionResource::~CPartPositionResource(void)
{
}

void CPartPositionResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CPartPosition *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CPartPosition *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CPartPositionResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CPartPosition *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CPartPosition *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CPartPositionResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CClientPositionResource> CClientPositionResource::resourceList;

CClientPositionResource * CClientPositionResource::alloc(int type, CClientPositionFactory *pFactory, CClientPosition *pObject, CWriteableClientPosition *pWriteableObject, bool updateIndex)
{
	CClientPositionResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CClientPositionResource::free(void)
{
	resourceList.free(this);
}

CClientPositionResource::CClientPositionResource(void)
{
}

CClientPositionResource::~CClientPositionResource(void)
{
}

void CClientPositionResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CClientPosition *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CClientPosition *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CClientPositionResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CClientPosition *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CClientPosition *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CClientPositionResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CHedgeVolumeResource> CHedgeVolumeResource::resourceList;

CHedgeVolumeResource * CHedgeVolumeResource::alloc(int type, CHedgeVolumeFactory *pFactory, CHedgeVolume *pObject, CWriteableHedgeVolume *pWriteableObject, bool updateIndex)
{
	CHedgeVolumeResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CHedgeVolumeResource::free(void)
{
	resourceList.free(this);
}

CHedgeVolumeResource::CHedgeVolumeResource(void)
{
}

CHedgeVolumeResource::~CHedgeVolumeResource(void)
{
}

void CHedgeVolumeResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CHedgeVolume *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CHedgeVolume *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CHedgeVolumeResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CHedgeVolume *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CHedgeVolume *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CHedgeVolumeResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CRemainOrderResource> CRemainOrderResource::resourceList;

CRemainOrderResource * CRemainOrderResource::alloc(int type, CRemainOrderFactory *pFactory, CRemainOrder *pObject, CWriteableRemainOrder *pWriteableObject, bool updateIndex)
{
	CRemainOrderResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CRemainOrderResource::free(void)
{
	resourceList.free(this);
}

CRemainOrderResource::CRemainOrderResource(void)
{
}

CRemainOrderResource::~CRemainOrderResource(void)
{
}

void CRemainOrderResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CRemainOrder *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CRemainOrder *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CRemainOrderResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CRemainOrder *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CRemainOrder *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CRemainOrderResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CMarketDataResource> CMarketDataResource::resourceList;

CMarketDataResource * CMarketDataResource::alloc(int type, CMarketDataFactory *pFactory, CMarketData *pObject, CWriteableMarketData *pWriteableObject, bool updateIndex)
{
	CMarketDataResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CMarketDataResource::free(void)
{
	resourceList.free(this);
}

CMarketDataResource::CMarketDataResource(void)
{
}

CMarketDataResource::~CMarketDataResource(void)
{
}

void CMarketDataResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CMarketData *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CMarketData *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CMarketDataResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CMarketData *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CMarketData *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CMarketDataResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CClearingPartPositionResource> CClearingPartPositionResource::resourceList;

CClearingPartPositionResource * CClearingPartPositionResource::alloc(int type, CClearingPartPositionFactory *pFactory, CClearingPartPosition *pObject, CWriteableClearingPartPosition *pWriteableObject, bool updateIndex)
{
	CClearingPartPositionResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CClearingPartPositionResource::free(void)
{
	resourceList.free(this);
}

CClearingPartPositionResource::CClearingPartPositionResource(void)
{
}

CClearingPartPositionResource::~CClearingPartPositionResource(void)
{
}

void CClearingPartPositionResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CClearingPartPosition *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CClearingPartPosition *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CClearingPartPositionResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CClearingPartPosition *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CClearingPartPosition *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CClearingPartPositionResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CInstrumentStatusResource> CInstrumentStatusResource::resourceList;

CInstrumentStatusResource * CInstrumentStatusResource::alloc(int type, CInstrumentStatusFactory *pFactory, CInstrumentStatus *pObject, CWriteableInstrumentStatus *pWriteableObject, bool updateIndex)
{
	CInstrumentStatusResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CInstrumentStatusResource::free(void)
{
	resourceList.free(this);
}

CInstrumentStatusResource::CInstrumentStatusResource(void)
{
}

CInstrumentStatusResource::~CInstrumentStatusResource(void)
{
}

void CInstrumentStatusResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CInstrumentStatus *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CInstrumentStatus *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CInstrumentStatusResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CInstrumentStatus *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CInstrumentStatus *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CInstrumentStatusResource::getPriority(void)
{
	return 1;
}


CMemoryStack<COrderResource> COrderResource::resourceList;

COrderResource * COrderResource::alloc(int type, COrderFactory *pFactory, COrder *pObject, CWriteableOrder *pWriteableObject, bool updateIndex)
{
	COrderResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void COrderResource::free(void)
{
	resourceList.free(this);
}

COrderResource::COrderResource(void)
{
}

COrderResource::~COrderResource(void)
{
}

void COrderResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((COrder *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((COrder *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void COrderResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((COrder *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((COrder *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int COrderResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCombOrderResource> CCombOrderResource::resourceList;

CCombOrderResource * CCombOrderResource::alloc(int type, CCombOrderFactory *pFactory, CCombOrder *pObject, CWriteableCombOrder *pWriteableObject, bool updateIndex)
{
	CCombOrderResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCombOrderResource::free(void)
{
	resourceList.free(this);
}

CCombOrderResource::CCombOrderResource(void)
{
}

CCombOrderResource::~CCombOrderResource(void)
{
}

void CCombOrderResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCombOrder *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCombOrder *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCombOrderResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCombOrder *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCombOrder *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCombOrderResource::getPriority(void)
{
	return 2;
}


CMemoryStack<COTCOrderResource> COTCOrderResource::resourceList;

COTCOrderResource * COTCOrderResource::alloc(int type, COTCOrderFactory *pFactory, COTCOrder *pObject, CWriteableOTCOrder *pWriteableObject, bool updateIndex)
{
	COTCOrderResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void COTCOrderResource::free(void)
{
	resourceList.free(this);
}

COTCOrderResource::COTCOrderResource(void)
{
}

COTCOrderResource::~COTCOrderResource(void)
{
}

void COTCOrderResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((COTCOrder *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((COTCOrder *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void COTCOrderResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((COTCOrder *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((COTCOrder *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int COTCOrderResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CImplyOrderResource> CImplyOrderResource::resourceList;

CImplyOrderResource * CImplyOrderResource::alloc(int type, CImplyOrderFactory *pFactory, CImplyOrder *pObject, CWriteableImplyOrder *pWriteableObject, bool updateIndex)
{
	CImplyOrderResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CImplyOrderResource::free(void)
{
	resourceList.free(this);
}

CImplyOrderResource::CImplyOrderResource(void)
{
}

CImplyOrderResource::~CImplyOrderResource(void)
{
}

void CImplyOrderResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CImplyOrder *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CImplyOrder *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CImplyOrderResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CImplyOrder *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CImplyOrder *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CImplyOrderResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CQuoteResource> CQuoteResource::resourceList;

CQuoteResource * CQuoteResource::alloc(int type, CQuoteFactory *pFactory, CQuote *pObject, CWriteableQuote *pWriteableObject, bool updateIndex)
{
	CQuoteResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CQuoteResource::free(void)
{
	resourceList.free(this);
}

CQuoteResource::CQuoteResource(void)
{
}

CQuoteResource::~CQuoteResource(void)
{
}

void CQuoteResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CQuote *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CQuote *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CQuoteResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CQuote *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CQuote *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CQuoteResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CMBLMarketDataResource> CMBLMarketDataResource::resourceList;

CMBLMarketDataResource * CMBLMarketDataResource::alloc(int type, CMBLMarketDataFactory *pFactory, CMBLMarketData *pObject, CWriteableMBLMarketData *pWriteableObject, bool updateIndex)
{
	CMBLMarketDataResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CMBLMarketDataResource::free(void)
{
	resourceList.free(this);
}

CMBLMarketDataResource::CMBLMarketDataResource(void)
{
}

CMBLMarketDataResource::~CMBLMarketDataResource(void)
{
}

void CMBLMarketDataResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CMBLMarketData *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CMBLMarketData *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CMBLMarketDataResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CMBLMarketData *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CMBLMarketData *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CMBLMarketDataResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CTradeResource> CTradeResource::resourceList;

CTradeResource * CTradeResource::alloc(int type, CTradeFactory *pFactory, CTrade *pObject, CWriteableTrade *pWriteableObject, bool updateIndex)
{
	CTradeResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CTradeResource::free(void)
{
	resourceList.free(this);
}

CTradeResource::CTradeResource(void)
{
}

CTradeResource::~CTradeResource(void)
{
}

void CTradeResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CTrade *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CTrade *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CTradeResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CTrade *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CTrade *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CTradeResource::getPriority(void)
{
	return 3;
}


CMemoryStack<CFusePhaseResource> CFusePhaseResource::resourceList;

CFusePhaseResource * CFusePhaseResource::alloc(int type, CFusePhaseFactory *pFactory, CFusePhase *pObject, CWriteableFusePhase *pWriteableObject, bool updateIndex)
{
	CFusePhaseResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CFusePhaseResource::free(void)
{
	resourceList.free(this);
}

CFusePhaseResource::CFusePhaseResource(void)
{
}

CFusePhaseResource::~CFusePhaseResource(void)
{
}

void CFusePhaseResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CFusePhase *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CFusePhase *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CFusePhaseResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CFusePhase *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CFusePhase *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CFusePhaseResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CExecOrderResource> CExecOrderResource::resourceList;

CExecOrderResource * CExecOrderResource::alloc(int type, CExecOrderFactory *pFactory, CExecOrder *pObject, CWriteableExecOrder *pWriteableObject, bool updateIndex)
{
	CExecOrderResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CExecOrderResource::free(void)
{
	resourceList.free(this);
}

CExecOrderResource::CExecOrderResource(void)
{
}

CExecOrderResource::~CExecOrderResource(void)
{
}

void CExecOrderResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CExecOrder *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CExecOrder *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CExecOrderResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CExecOrder *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CExecOrder *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CExecOrderResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CUniPressureResource> CUniPressureResource::resourceList;

CUniPressureResource * CUniPressureResource::alloc(int type, CUniPressureFactory *pFactory, CUniPressure *pObject, CWriteableUniPressure *pWriteableObject, bool updateIndex)
{
	CUniPressureResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CUniPressureResource::free(void)
{
	resourceList.free(this);
}

CUniPressureResource::CUniPressureResource(void)
{
}

CUniPressureResource::~CUniPressureResource(void)
{
}

void CUniPressureResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CUniPressure *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CUniPressure *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CUniPressureResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CUniPressure *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CUniPressure *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CUniPressureResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CBasePriceLimitResource> CBasePriceLimitResource::resourceList;

CBasePriceLimitResource * CBasePriceLimitResource::alloc(int type, CBasePriceLimitFactory *pFactory, CBasePriceLimit *pObject, CWriteableBasePriceLimit *pWriteableObject, bool updateIndex)
{
	CBasePriceLimitResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CBasePriceLimitResource::free(void)
{
	resourceList.free(this);
}

CBasePriceLimitResource::CBasePriceLimitResource(void)
{
}

CBasePriceLimitResource::~CBasePriceLimitResource(void)
{
}

void CBasePriceLimitResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CBasePriceLimit *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CBasePriceLimit *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CBasePriceLimitResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CBasePriceLimit *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CBasePriceLimit *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CBasePriceLimitResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCreditLimitResource> CCreditLimitResource::resourceList;

CCreditLimitResource * CCreditLimitResource::alloc(int type, CCreditLimitFactory *pFactory, CCreditLimit *pObject, CWriteableCreditLimit *pWriteableObject, bool updateIndex)
{
	CCreditLimitResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCreditLimitResource::free(void)
{
	resourceList.free(this);
}

CCreditLimitResource::CCreditLimitResource(void)
{
}

CCreditLimitResource::~CCreditLimitResource(void)
{
}

void CCreditLimitResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCreditLimit *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCreditLimit *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCreditLimitResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCreditLimit *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCreditLimit *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCreditLimitResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CCurrInstrumentOptionResource> CCurrInstrumentOptionResource::resourceList;

CCurrInstrumentOptionResource * CCurrInstrumentOptionResource::alloc(int type, CCurrInstrumentOptionFactory *pFactory, CCurrInstrumentOption *pObject, CWriteableCurrInstrumentOption *pWriteableObject, bool updateIndex)
{
	CCurrInstrumentOptionResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CCurrInstrumentOptionResource::free(void)
{
	resourceList.free(this);
}

CCurrInstrumentOptionResource::CCurrInstrumentOptionResource(void)
{
}

CCurrInstrumentOptionResource::~CCurrInstrumentOptionResource(void)
{
}

void CCurrInstrumentOptionResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CCurrInstrumentOption *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CCurrInstrumentOption *)ref,&writeableObject);	
		break;
	case DELETE_ACTION:
		pFactory->commitRemove(&writeableObject);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}
	
void CCurrInstrumentOptionResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CCurrInstrumentOption *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CCurrInstrumentOption *)ref,&writeableObject,m_updateIndex,false);
		break;
	case DELETE_ACTION:
		pFactory->internalAdd(&writeableObject,false);
		break;
	case NONE_ACTION:
		break;
	default:
		RAISE_DESIGN_ERROR("Invalid resource type");
	}
}

int CCurrInstrumentOptionResource::getPriority(void)
{
	return 2;
}

