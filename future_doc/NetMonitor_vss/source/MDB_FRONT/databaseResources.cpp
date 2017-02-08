/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseResources.cpp
///@brief实现了若干内存数据资源，可以放置于事务中
///@history 
///20060127	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "databaseResources.h"


CMemoryStack<CSysInvalidateOrderResource> CSysInvalidateOrderResource::resourceList;

CSysInvalidateOrderResource * CSysInvalidateOrderResource::alloc(int type, CSysInvalidateOrderFactory *pFactory, CSysInvalidateOrder *pObject, CWriteableSysInvalidateOrder *pWriteableObject, bool updateIndex)
{
	CSysInvalidateOrderResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysInvalidateOrderResource::free(void)
{
	resourceList.free(this);
}

CSysInvalidateOrderResource::CSysInvalidateOrderResource(void)
{
}

CSysInvalidateOrderResource::~CSysInvalidateOrderResource(void)
{
}

void CSysInvalidateOrderResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysInvalidateOrder *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysInvalidateOrder *)ref,&writeableObject);	
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
	
void CSysInvalidateOrderResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysInvalidateOrder *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysInvalidateOrder *)ref,&writeableObject,m_updateIndex,false);
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

int CSysInvalidateOrderResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysOrderStatusResource> CSysOrderStatusResource::resourceList;

CSysOrderStatusResource * CSysOrderStatusResource::alloc(int type, CSysOrderStatusFactory *pFactory, CSysOrderStatus *pObject, CWriteableSysOrderStatus *pWriteableObject, bool updateIndex)
{
	CSysOrderStatusResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysOrderStatusResource::free(void)
{
	resourceList.free(this);
}

CSysOrderStatusResource::CSysOrderStatusResource(void)
{
}

CSysOrderStatusResource::~CSysOrderStatusResource(void)
{
}

void CSysOrderStatusResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysOrderStatus *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysOrderStatus *)ref,&writeableObject);	
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
	
void CSysOrderStatusResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysOrderStatus *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysOrderStatus *)ref,&writeableObject,m_updateIndex,false);
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

int CSysOrderStatusResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysBargainOrderResource> CSysBargainOrderResource::resourceList;

CSysBargainOrderResource * CSysBargainOrderResource::alloc(int type, CSysBargainOrderFactory *pFactory, CSysBargainOrder *pObject, CWriteableSysBargainOrder *pWriteableObject, bool updateIndex)
{
	CSysBargainOrderResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysBargainOrderResource::free(void)
{
	resourceList.free(this);
}

CSysBargainOrderResource::CSysBargainOrderResource(void)
{
}

CSysBargainOrderResource::~CSysBargainOrderResource(void)
{
}

void CSysBargainOrderResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysBargainOrder *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysBargainOrder *)ref,&writeableObject);	
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
	
void CSysBargainOrderResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysBargainOrder *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysBargainOrder *)ref,&writeableObject,m_updateIndex,false);
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

int CSysBargainOrderResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysInstPropertyResource> CSysInstPropertyResource::resourceList;

CSysInstPropertyResource * CSysInstPropertyResource::alloc(int type, CSysInstPropertyFactory *pFactory, CSysInstProperty *pObject, CWriteableSysInstProperty *pWriteableObject, bool updateIndex)
{
	CSysInstPropertyResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysInstPropertyResource::free(void)
{
	resourceList.free(this);
}

CSysInstPropertyResource::CSysInstPropertyResource(void)
{
}

CSysInstPropertyResource::~CSysInstPropertyResource(void)
{
}

void CSysInstPropertyResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysInstProperty *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysInstProperty *)ref,&writeableObject);	
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
	
void CSysInstPropertyResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysInstProperty *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysInstProperty *)ref,&writeableObject,m_updateIndex,false);
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

int CSysInstPropertyResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMarginRateResource> CSysMarginRateResource::resourceList;

CSysMarginRateResource * CSysMarginRateResource::alloc(int type, CSysMarginRateFactory *pFactory, CSysMarginRate *pObject, CWriteableSysMarginRate *pWriteableObject, bool updateIndex)
{
	CSysMarginRateResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMarginRateResource::free(void)
{
	resourceList.free(this);
}

CSysMarginRateResource::CSysMarginRateResource(void)
{
}

CSysMarginRateResource::~CSysMarginRateResource(void)
{
}

void CSysMarginRateResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMarginRate *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMarginRate *)ref,&writeableObject);	
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
	
void CSysMarginRateResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMarginRate *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMarginRate *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMarginRateResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysPriceLimitResource> CSysPriceLimitResource::resourceList;

CSysPriceLimitResource * CSysPriceLimitResource::alloc(int type, CSysPriceLimitFactory *pFactory, CSysPriceLimit *pObject, CWriteableSysPriceLimit *pWriteableObject, bool updateIndex)
{
	CSysPriceLimitResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysPriceLimitResource::free(void)
{
	resourceList.free(this);
}

CSysPriceLimitResource::CSysPriceLimitResource(void)
{
}

CSysPriceLimitResource::~CSysPriceLimitResource(void)
{
}

void CSysPriceLimitResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysPriceLimit *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysPriceLimit *)ref,&writeableObject);	
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
	
void CSysPriceLimitResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysPriceLimit *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysPriceLimit *)ref,&writeableObject,m_updateIndex,false);
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

int CSysPriceLimitResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysPartPosiLimitResource> CSysPartPosiLimitResource::resourceList;

CSysPartPosiLimitResource * CSysPartPosiLimitResource::alloc(int type, CSysPartPosiLimitFactory *pFactory, CSysPartPosiLimit *pObject, CWriteableSysPartPosiLimit *pWriteableObject, bool updateIndex)
{
	CSysPartPosiLimitResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysPartPosiLimitResource::free(void)
{
	resourceList.free(this);
}

CSysPartPosiLimitResource::CSysPartPosiLimitResource(void)
{
}

CSysPartPosiLimitResource::~CSysPartPosiLimitResource(void)
{
}

void CSysPartPosiLimitResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysPartPosiLimit *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysPartPosiLimit *)ref,&writeableObject);	
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
	
void CSysPartPosiLimitResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysPartPosiLimit *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysPartPosiLimit *)ref,&writeableObject,m_updateIndex,false);
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

int CSysPartPosiLimitResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysClientPosiLimitResource> CSysClientPosiLimitResource::resourceList;

CSysClientPosiLimitResource * CSysClientPosiLimitResource::alloc(int type, CSysClientPosiLimitFactory *pFactory, CSysClientPosiLimit *pObject, CWriteableSysClientPosiLimit *pWriteableObject, bool updateIndex)
{
	CSysClientPosiLimitResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysClientPosiLimitResource::free(void)
{
	resourceList.free(this);
}

CSysClientPosiLimitResource::CSysClientPosiLimitResource(void)
{
}

CSysClientPosiLimitResource::~CSysClientPosiLimitResource(void)
{
}

void CSysClientPosiLimitResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysClientPosiLimit *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysClientPosiLimit *)ref,&writeableObject);	
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
	
void CSysClientPosiLimitResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysClientPosiLimit *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysClientPosiLimit *)ref,&writeableObject,m_updateIndex,false);
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

int CSysClientPosiLimitResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysSpecialPosiLimitResource> CSysSpecialPosiLimitResource::resourceList;

CSysSpecialPosiLimitResource * CSysSpecialPosiLimitResource::alloc(int type, CSysSpecialPosiLimitFactory *pFactory, CSysSpecialPosiLimit *pObject, CWriteableSysSpecialPosiLimit *pWriteableObject, bool updateIndex)
{
	CSysSpecialPosiLimitResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysSpecialPosiLimitResource::free(void)
{
	resourceList.free(this);
}

CSysSpecialPosiLimitResource::CSysSpecialPosiLimitResource(void)
{
}

CSysSpecialPosiLimitResource::~CSysSpecialPosiLimitResource(void)
{
}

void CSysSpecialPosiLimitResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysSpecialPosiLimit *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysSpecialPosiLimit *)ref,&writeableObject);	
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
	
void CSysSpecialPosiLimitResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysSpecialPosiLimit *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysSpecialPosiLimit *)ref,&writeableObject,m_updateIndex,false);
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

int CSysSpecialPosiLimitResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysTransactionChgResource> CSysTransactionChgResource::resourceList;

CSysTransactionChgResource * CSysTransactionChgResource::alloc(int type, CSysTransactionChgFactory *pFactory, CSysTransactionChg *pObject, CWriteableSysTransactionChg *pWriteableObject, bool updateIndex)
{
	CSysTransactionChgResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysTransactionChgResource::free(void)
{
	resourceList.free(this);
}

CSysTransactionChgResource::CSysTransactionChgResource(void)
{
}

CSysTransactionChgResource::~CSysTransactionChgResource(void)
{
}

void CSysTransactionChgResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysTransactionChg *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysTransactionChg *)ref,&writeableObject);	
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
	
void CSysTransactionChgResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysTransactionChg *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysTransactionChg *)ref,&writeableObject,m_updateIndex,false);
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

int CSysTransactionChgResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysClientChgResource> CSysClientChgResource::resourceList;

CSysClientChgResource * CSysClientChgResource::alloc(int type, CSysClientChgFactory *pFactory, CSysClientChg *pObject, CWriteableSysClientChg *pWriteableObject, bool updateIndex)
{
	CSysClientChgResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysClientChgResource::free(void)
{
	resourceList.free(this);
}

CSysClientChgResource::CSysClientChgResource(void)
{
}

CSysClientChgResource::~CSysClientChgResource(void)
{
}

void CSysClientChgResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysClientChg *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysClientChg *)ref,&writeableObject);	
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
	
void CSysClientChgResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysClientChg *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysClientChg *)ref,&writeableObject,m_updateIndex,false);
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

int CSysClientChgResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysPartClientChgResource> CSysPartClientChgResource::resourceList;

CSysPartClientChgResource * CSysPartClientChgResource::alloc(int type, CSysPartClientChgFactory *pFactory, CSysPartClientChg *pObject, CWriteableSysPartClientChg *pWriteableObject, bool updateIndex)
{
	CSysPartClientChgResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysPartClientChgResource::free(void)
{
	resourceList.free(this);
}

CSysPartClientChgResource::CSysPartClientChgResource(void)
{
}

CSysPartClientChgResource::~CSysPartClientChgResource(void)
{
}

void CSysPartClientChgResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysPartClientChg *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysPartClientChg *)ref,&writeableObject);	
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
	
void CSysPartClientChgResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysPartClientChg *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysPartClientChg *)ref,&writeableObject,m_updateIndex,false);
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

int CSysPartClientChgResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysPosiLimitChgResource> CSysPosiLimitChgResource::resourceList;

CSysPosiLimitChgResource * CSysPosiLimitChgResource::alloc(int type, CSysPosiLimitChgFactory *pFactory, CSysPosiLimitChg *pObject, CWriteableSysPosiLimitChg *pWriteableObject, bool updateIndex)
{
	CSysPosiLimitChgResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysPosiLimitChgResource::free(void)
{
	resourceList.free(this);
}

CSysPosiLimitChgResource::CSysPosiLimitChgResource(void)
{
}

CSysPosiLimitChgResource::~CSysPosiLimitChgResource(void)
{
}

void CSysPosiLimitChgResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysPosiLimitChg *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysPosiLimitChg *)ref,&writeableObject);	
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
	
void CSysPosiLimitChgResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysPosiLimitChg *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysPosiLimitChg *)ref,&writeableObject,m_updateIndex,false);
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

int CSysPosiLimitChgResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysClientPosiLimitChgResource> CSysClientPosiLimitChgResource::resourceList;

CSysClientPosiLimitChgResource * CSysClientPosiLimitChgResource::alloc(int type, CSysClientPosiLimitChgFactory *pFactory, CSysClientPosiLimitChg *pObject, CWriteableSysClientPosiLimitChg *pWriteableObject, bool updateIndex)
{
	CSysClientPosiLimitChgResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysClientPosiLimitChgResource::free(void)
{
	resourceList.free(this);
}

CSysClientPosiLimitChgResource::CSysClientPosiLimitChgResource(void)
{
}

CSysClientPosiLimitChgResource::~CSysClientPosiLimitChgResource(void)
{
}

void CSysClientPosiLimitChgResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysClientPosiLimitChg *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysClientPosiLimitChg *)ref,&writeableObject);	
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
	
void CSysClientPosiLimitChgResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysClientPosiLimitChg *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysClientPosiLimitChg *)ref,&writeableObject,m_updateIndex,false);
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

int CSysClientPosiLimitChgResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysSpecPosiLimitChgResource> CSysSpecPosiLimitChgResource::resourceList;

CSysSpecPosiLimitChgResource * CSysSpecPosiLimitChgResource::alloc(int type, CSysSpecPosiLimitChgFactory *pFactory, CSysSpecPosiLimitChg *pObject, CWriteableSysSpecPosiLimitChg *pWriteableObject, bool updateIndex)
{
	CSysSpecPosiLimitChgResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysSpecPosiLimitChgResource::free(void)
{
	resourceList.free(this);
}

CSysSpecPosiLimitChgResource::CSysSpecPosiLimitChgResource(void)
{
}

CSysSpecPosiLimitChgResource::~CSysSpecPosiLimitChgResource(void)
{
}

void CSysSpecPosiLimitChgResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysSpecPosiLimitChg *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysSpecPosiLimitChg *)ref,&writeableObject);	
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
	
void CSysSpecPosiLimitChgResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysSpecPosiLimitChg *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysSpecPosiLimitChg *)ref,&writeableObject,m_updateIndex,false);
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

int CSysSpecPosiLimitChgResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysHedgeDetailChgResource> CSysHedgeDetailChgResource::resourceList;

CSysHedgeDetailChgResource * CSysHedgeDetailChgResource::alloc(int type, CSysHedgeDetailChgFactory *pFactory, CSysHedgeDetailChg *pObject, CWriteableSysHedgeDetailChg *pWriteableObject, bool updateIndex)
{
	CSysHedgeDetailChgResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysHedgeDetailChgResource::free(void)
{
	resourceList.free(this);
}

CSysHedgeDetailChgResource::CSysHedgeDetailChgResource(void)
{
}

CSysHedgeDetailChgResource::~CSysHedgeDetailChgResource(void)
{
}

void CSysHedgeDetailChgResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysHedgeDetailChg *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysHedgeDetailChg *)ref,&writeableObject);	
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
	
void CSysHedgeDetailChgResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysHedgeDetailChg *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysHedgeDetailChg *)ref,&writeableObject,m_updateIndex,false);
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

int CSysHedgeDetailChgResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysParticipantChgResource> CSysParticipantChgResource::resourceList;

CSysParticipantChgResource * CSysParticipantChgResource::alloc(int type, CSysParticipantChgFactory *pFactory, CSysParticipantChg *pObject, CWriteableSysParticipantChg *pWriteableObject, bool updateIndex)
{
	CSysParticipantChgResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysParticipantChgResource::free(void)
{
	resourceList.free(this);
}

CSysParticipantChgResource::CSysParticipantChgResource(void)
{
}

CSysParticipantChgResource::~CSysParticipantChgResource(void)
{
}

void CSysParticipantChgResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysParticipantChg *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysParticipantChg *)ref,&writeableObject);	
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
	
void CSysParticipantChgResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysParticipantChg *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysParticipantChg *)ref,&writeableObject,m_updateIndex,false);
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

int CSysParticipantChgResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMarginRateChgResource> CSysMarginRateChgResource::resourceList;

CSysMarginRateChgResource * CSysMarginRateChgResource::alloc(int type, CSysMarginRateChgFactory *pFactory, CSysMarginRateChg *pObject, CWriteableSysMarginRateChg *pWriteableObject, bool updateIndex)
{
	CSysMarginRateChgResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMarginRateChgResource::free(void)
{
	resourceList.free(this);
}

CSysMarginRateChgResource::CSysMarginRateChgResource(void)
{
}

CSysMarginRateChgResource::~CSysMarginRateChgResource(void)
{
}

void CSysMarginRateChgResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMarginRateChg *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMarginRateChg *)ref,&writeableObject);	
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
	
void CSysMarginRateChgResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMarginRateChg *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMarginRateChg *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMarginRateChgResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysUserIpChgResource> CSysUserIpChgResource::resourceList;

CSysUserIpChgResource * CSysUserIpChgResource::alloc(int type, CSysUserIpChgFactory *pFactory, CSysUserIpChg *pObject, CWriteableSysUserIpChg *pWriteableObject, bool updateIndex)
{
	CSysUserIpChgResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysUserIpChgResource::free(void)
{
	resourceList.free(this);
}

CSysUserIpChgResource::CSysUserIpChgResource(void)
{
}

CSysUserIpChgResource::~CSysUserIpChgResource(void)
{
}

void CSysUserIpChgResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysUserIpChg *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysUserIpChg *)ref,&writeableObject);	
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
	
void CSysUserIpChgResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysUserIpChg *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysUserIpChg *)ref,&writeableObject,m_updateIndex,false);
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

int CSysUserIpChgResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysPartTradeResource> CSysPartTradeResource::resourceList;

CSysPartTradeResource * CSysPartTradeResource::alloc(int type, CSysPartTradeFactory *pFactory, CSysPartTrade *pObject, CWriteableSysPartTrade *pWriteableObject, bool updateIndex)
{
	CSysPartTradeResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysPartTradeResource::free(void)
{
	resourceList.free(this);
}

CSysPartTradeResource::CSysPartTradeResource(void)
{
}

CSysPartTradeResource::~CSysPartTradeResource(void)
{
}

void CSysPartTradeResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysPartTrade *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysPartTrade *)ref,&writeableObject);	
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
	
void CSysPartTradeResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysPartTrade *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysPartTrade *)ref,&writeableObject,m_updateIndex,false);
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

int CSysPartTradeResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMdbObjectAttrResource> CSysMdbObjectAttrResource::resourceList;

CSysMdbObjectAttrResource * CSysMdbObjectAttrResource::alloc(int type, CSysMdbObjectAttrFactory *pFactory, CSysMdbObjectAttr *pObject, CWriteableSysMdbObjectAttr *pWriteableObject, bool updateIndex)
{
	CSysMdbObjectAttrResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMdbObjectAttrResource::free(void)
{
	resourceList.free(this);
}

CSysMdbObjectAttrResource::CSysMdbObjectAttrResource(void)
{
}

CSysMdbObjectAttrResource::~CSysMdbObjectAttrResource(void)
{
}

void CSysMdbObjectAttrResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMdbObjectAttr *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMdbObjectAttr *)ref,&writeableObject);	
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
	
void CSysMdbObjectAttrResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMdbObjectAttr *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMdbObjectAttr *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMdbObjectAttrResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMdbSyslogInfoResource> CSysMdbSyslogInfoResource::resourceList;

CSysMdbSyslogInfoResource * CSysMdbSyslogInfoResource::alloc(int type, CSysMdbSyslogInfoFactory *pFactory, CSysMdbSyslogInfo *pObject, CWriteableSysMdbSyslogInfo *pWriteableObject, bool updateIndex)
{
	CSysMdbSyslogInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMdbSyslogInfoResource::free(void)
{
	resourceList.free(this);
}

CSysMdbSyslogInfoResource::CSysMdbSyslogInfoResource(void)
{
}

CSysMdbSyslogInfoResource::~CSysMdbSyslogInfoResource(void)
{
}

void CSysMdbSyslogInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMdbSyslogInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMdbSyslogInfo *)ref,&writeableObject);	
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
	
void CSysMdbSyslogInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMdbSyslogInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMdbSyslogInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMdbSyslogInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysUserInfoResource> CSysUserInfoResource::resourceList;

CSysUserInfoResource * CSysUserInfoResource::alloc(int type, CSysUserInfoFactory *pFactory, CSysUserInfo *pObject, CWriteableSysUserInfo *pWriteableObject, bool updateIndex)
{
	CSysUserInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysUserInfoResource::free(void)
{
	resourceList.free(this);
}

CSysUserInfoResource::CSysUserInfoResource(void)
{
}

CSysUserInfoResource::~CSysUserInfoResource(void)
{
}

void CSysUserInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysUserInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysUserInfo *)ref,&writeableObject);	
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
	
void CSysUserInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysUserInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysUserInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysUserInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysOnlineUserInfoResource> CSysOnlineUserInfoResource::resourceList;

CSysOnlineUserInfoResource * CSysOnlineUserInfoResource::alloc(int type, CSysOnlineUserInfoFactory *pFactory, CSysOnlineUserInfo *pObject, CWriteableSysOnlineUserInfo *pWriteableObject, bool updateIndex)
{
	CSysOnlineUserInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysOnlineUserInfoResource::free(void)
{
	resourceList.free(this);
}

CSysOnlineUserInfoResource::CSysOnlineUserInfoResource(void)
{
}

CSysOnlineUserInfoResource::~CSysOnlineUserInfoResource(void)
{
}

void CSysOnlineUserInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysOnlineUserInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysOnlineUserInfo *)ref,&writeableObject);	
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
	
void CSysOnlineUserInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysOnlineUserInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysOnlineUserInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysOnlineUserInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysWarningEventResource> CSysWarningEventResource::resourceList;

CSysWarningEventResource * CSysWarningEventResource::alloc(int type, CSysWarningEventFactory *pFactory, CSysWarningEvent *pObject, CWriteableSysWarningEvent *pWriteableObject, bool updateIndex)
{
	CSysWarningEventResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysWarningEventResource::free(void)
{
	resourceList.free(this);
}

CSysWarningEventResource::CSysWarningEventResource(void)
{
}

CSysWarningEventResource::~CSysWarningEventResource(void)
{
}

void CSysWarningEventResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysWarningEvent *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysWarningEvent *)ref,&writeableObject);	
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
	
void CSysWarningEventResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysWarningEvent *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysWarningEvent *)ref,&writeableObject,m_updateIndex,false);
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

int CSysWarningEventResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysWarningQueryResource> CSysWarningQueryResource::resourceList;

CSysWarningQueryResource * CSysWarningQueryResource::alloc(int type, CSysWarningQueryFactory *pFactory, CSysWarningQuery *pObject, CWriteableSysWarningQuery *pWriteableObject, bool updateIndex)
{
	CSysWarningQueryResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysWarningQueryResource::free(void)
{
	resourceList.free(this);
}

CSysWarningQueryResource::CSysWarningQueryResource(void)
{
}

CSysWarningQueryResource::~CSysWarningQueryResource(void)
{
}

void CSysWarningQueryResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysWarningQuery *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysWarningQuery *)ref,&writeableObject);	
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
	
void CSysWarningQueryResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysWarningQuery *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysWarningQuery *)ref,&writeableObject,m_updateIndex,false);
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

int CSysWarningQueryResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSyslogEventResource> CSyslogEventResource::resourceList;

CSyslogEventResource * CSyslogEventResource::alloc(int type, CSyslogEventFactory *pFactory, CSyslogEvent *pObject, CWriteableSyslogEvent *pWriteableObject, bool updateIndex)
{
	CSyslogEventResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSyslogEventResource::free(void)
{
	resourceList.free(this);
}

CSyslogEventResource::CSyslogEventResource(void)
{
}

CSyslogEventResource::~CSyslogEventResource(void)
{
}

void CSyslogEventResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSyslogEvent *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSyslogEvent *)ref,&writeableObject);	
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
	
void CSyslogEventResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSyslogEvent *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSyslogEvent *)ref,&writeableObject,m_updateIndex,false);
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

int CSyslogEventResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysEventDescripResource> CSysEventDescripResource::resourceList;

CSysEventDescripResource * CSysEventDescripResource::alloc(int type, CSysEventDescripFactory *pFactory, CSysEventDescrip *pObject, CWriteableSysEventDescrip *pWriteableObject, bool updateIndex)
{
	CSysEventDescripResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysEventDescripResource::free(void)
{
	resourceList.free(this);
}

CSysEventDescripResource::CSysEventDescripResource(void)
{
}

CSysEventDescripResource::~CSysEventDescripResource(void)
{
}

void CSysEventDescripResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysEventDescrip *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysEventDescrip *)ref,&writeableObject);	
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
	
void CSysEventDescripResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysEventDescrip *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysEventDescrip *)ref,&writeableObject,m_updateIndex,false);
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

int CSysEventDescripResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CRspQryHostEnvCommonResource> CRspQryHostEnvCommonResource::resourceList;

CRspQryHostEnvCommonResource * CRspQryHostEnvCommonResource::alloc(int type, CRspQryHostEnvCommonFactory *pFactory, CRspQryHostEnvCommon *pObject, CWriteableRspQryHostEnvCommon *pWriteableObject, bool updateIndex)
{
	CRspQryHostEnvCommonResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CRspQryHostEnvCommonResource::free(void)
{
	resourceList.free(this);
}

CRspQryHostEnvCommonResource::CRspQryHostEnvCommonResource(void)
{
}

CRspQryHostEnvCommonResource::~CRspQryHostEnvCommonResource(void)
{
}

void CRspQryHostEnvCommonResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CRspQryHostEnvCommon *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CRspQryHostEnvCommon *)ref,&writeableObject);	
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
	
void CRspQryHostEnvCommonResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CRspQryHostEnvCommon *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CRspQryHostEnvCommon *)ref,&writeableObject,m_updateIndex,false);
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

int CRspQryHostEnvCommonResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CRspQryHostEnvLanResource> CRspQryHostEnvLanResource::resourceList;

CRspQryHostEnvLanResource * CRspQryHostEnvLanResource::alloc(int type, CRspQryHostEnvLanFactory *pFactory, CRspQryHostEnvLan *pObject, CWriteableRspQryHostEnvLan *pWriteableObject, bool updateIndex)
{
	CRspQryHostEnvLanResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CRspQryHostEnvLanResource::free(void)
{
	resourceList.free(this);
}

CRspQryHostEnvLanResource::CRspQryHostEnvLanResource(void)
{
}

CRspQryHostEnvLanResource::~CRspQryHostEnvLanResource(void)
{
}

void CRspQryHostEnvLanResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CRspQryHostEnvLan *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CRspQryHostEnvLan *)ref,&writeableObject);	
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
	
void CRspQryHostEnvLanResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CRspQryHostEnvLan *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CRspQryHostEnvLan *)ref,&writeableObject,m_updateIndex,false);
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

int CRspQryHostEnvLanResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CRspQryHostEnvStorageResource> CRspQryHostEnvStorageResource::resourceList;

CRspQryHostEnvStorageResource * CRspQryHostEnvStorageResource::alloc(int type, CRspQryHostEnvStorageFactory *pFactory, CRspQryHostEnvStorage *pObject, CWriteableRspQryHostEnvStorage *pWriteableObject, bool updateIndex)
{
	CRspQryHostEnvStorageResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CRspQryHostEnvStorageResource::free(void)
{
	resourceList.free(this);
}

CRspQryHostEnvStorageResource::CRspQryHostEnvStorageResource(void)
{
}

CRspQryHostEnvStorageResource::~CRspQryHostEnvStorageResource(void)
{
}

void CRspQryHostEnvStorageResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CRspQryHostEnvStorage *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CRspQryHostEnvStorage *)ref,&writeableObject);	
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
	
void CRspQryHostEnvStorageResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CRspQryHostEnvStorage *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CRspQryHostEnvStorage *)ref,&writeableObject,m_updateIndex,false);
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

int CRspQryHostEnvStorageResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CRspQryHostEnvIOResource> CRspQryHostEnvIOResource::resourceList;

CRspQryHostEnvIOResource * CRspQryHostEnvIOResource::alloc(int type, CRspQryHostEnvIOFactory *pFactory, CRspQryHostEnvIO *pObject, CWriteableRspQryHostEnvIO *pWriteableObject, bool updateIndex)
{
	CRspQryHostEnvIOResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CRspQryHostEnvIOResource::free(void)
{
	resourceList.free(this);
}

CRspQryHostEnvIOResource::CRspQryHostEnvIOResource(void)
{
}

CRspQryHostEnvIOResource::~CRspQryHostEnvIOResource(void)
{
}

void CRspQryHostEnvIOResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CRspQryHostEnvIO *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CRspQryHostEnvIO *)ref,&writeableObject);	
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
	
void CRspQryHostEnvIOResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CRspQryHostEnvIO *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CRspQryHostEnvIO *)ref,&writeableObject,m_updateIndex,false);
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

int CRspQryHostEnvIOResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CRspQryHostEnvFSResource> CRspQryHostEnvFSResource::resourceList;

CRspQryHostEnvFSResource * CRspQryHostEnvFSResource::alloc(int type, CRspQryHostEnvFSFactory *pFactory, CRspQryHostEnvFS *pObject, CWriteableRspQryHostEnvFS *pWriteableObject, bool updateIndex)
{
	CRspQryHostEnvFSResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CRspQryHostEnvFSResource::free(void)
{
	resourceList.free(this);
}

CRspQryHostEnvFSResource::CRspQryHostEnvFSResource(void)
{
}

CRspQryHostEnvFSResource::~CRspQryHostEnvFSResource(void)
{
}

void CRspQryHostEnvFSResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CRspQryHostEnvFS *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CRspQryHostEnvFS *)ref,&writeableObject);	
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
	
void CRspQryHostEnvFSResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CRspQryHostEnvFS *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CRspQryHostEnvFS *)ref,&writeableObject,m_updateIndex,false);
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

int CRspQryHostEnvFSResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CRspQryHostEnvSwapResource> CRspQryHostEnvSwapResource::resourceList;

CRspQryHostEnvSwapResource * CRspQryHostEnvSwapResource::alloc(int type, CRspQryHostEnvSwapFactory *pFactory, CRspQryHostEnvSwap *pObject, CWriteableRspQryHostEnvSwap *pWriteableObject, bool updateIndex)
{
	CRspQryHostEnvSwapResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CRspQryHostEnvSwapResource::free(void)
{
	resourceList.free(this);
}

CRspQryHostEnvSwapResource::CRspQryHostEnvSwapResource(void)
{
}

CRspQryHostEnvSwapResource::~CRspQryHostEnvSwapResource(void)
{
}

void CRspQryHostEnvSwapResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CRspQryHostEnvSwap *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CRspQryHostEnvSwap *)ref,&writeableObject);	
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
	
void CRspQryHostEnvSwapResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CRspQryHostEnvSwap *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CRspQryHostEnvSwap *)ref,&writeableObject,m_updateIndex,false);
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

int CRspQryHostEnvSwapResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CRspQryHostEnvLanCfgResource> CRspQryHostEnvLanCfgResource::resourceList;

CRspQryHostEnvLanCfgResource * CRspQryHostEnvLanCfgResource::alloc(int type, CRspQryHostEnvLanCfgFactory *pFactory, CRspQryHostEnvLanCfg *pObject, CWriteableRspQryHostEnvLanCfg *pWriteableObject, bool updateIndex)
{
	CRspQryHostEnvLanCfgResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CRspQryHostEnvLanCfgResource::free(void)
{
	resourceList.free(this);
}

CRspQryHostEnvLanCfgResource::CRspQryHostEnvLanCfgResource(void)
{
}

CRspQryHostEnvLanCfgResource::~CRspQryHostEnvLanCfgResource(void)
{
}

void CRspQryHostEnvLanCfgResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CRspQryHostEnvLanCfg *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CRspQryHostEnvLanCfg *)ref,&writeableObject);	
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
	
void CRspQryHostEnvLanCfgResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CRspQryHostEnvLanCfg *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CRspQryHostEnvLanCfg *)ref,&writeableObject,m_updateIndex,false);
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

int CRspQryHostEnvLanCfgResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMdbTopCpuInfoResource> CSysMdbTopCpuInfoResource::resourceList;

CSysMdbTopCpuInfoResource * CSysMdbTopCpuInfoResource::alloc(int type, CSysMdbTopCpuInfoFactory *pFactory, CSysMdbTopCpuInfo *pObject, CWriteableSysMdbTopCpuInfo *pWriteableObject, bool updateIndex)
{
	CSysMdbTopCpuInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMdbTopCpuInfoResource::free(void)
{
	resourceList.free(this);
}

CSysMdbTopCpuInfoResource::CSysMdbTopCpuInfoResource(void)
{
}

CSysMdbTopCpuInfoResource::~CSysMdbTopCpuInfoResource(void)
{
}

void CSysMdbTopCpuInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMdbTopCpuInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMdbTopCpuInfo *)ref,&writeableObject);	
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
	
void CSysMdbTopCpuInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMdbTopCpuInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMdbTopCpuInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMdbTopCpuInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMdbTopMemInfoResource> CSysMdbTopMemInfoResource::resourceList;

CSysMdbTopMemInfoResource * CSysMdbTopMemInfoResource::alloc(int type, CSysMdbTopMemInfoFactory *pFactory, CSysMdbTopMemInfo *pObject, CWriteableSysMdbTopMemInfo *pWriteableObject, bool updateIndex)
{
	CSysMdbTopMemInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMdbTopMemInfoResource::free(void)
{
	resourceList.free(this);
}

CSysMdbTopMemInfoResource::CSysMdbTopMemInfoResource(void)
{
}

CSysMdbTopMemInfoResource::~CSysMdbTopMemInfoResource(void)
{
}

void CSysMdbTopMemInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMdbTopMemInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMdbTopMemInfo *)ref,&writeableObject);	
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
	
void CSysMdbTopMemInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMdbTopMemInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMdbTopMemInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMdbTopMemInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMdbTopProcessInfoResource> CSysMdbTopProcessInfoResource::resourceList;

CSysMdbTopProcessInfoResource * CSysMdbTopProcessInfoResource::alloc(int type, CSysMdbTopProcessInfoFactory *pFactory, CSysMdbTopProcessInfo *pObject, CWriteableSysMdbTopProcessInfo *pWriteableObject, bool updateIndex)
{
	CSysMdbTopProcessInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMdbTopProcessInfoResource::free(void)
{
	resourceList.free(this);
}

CSysMdbTopProcessInfoResource::CSysMdbTopProcessInfoResource(void)
{
}

CSysMdbTopProcessInfoResource::~CSysMdbTopProcessInfoResource(void)
{
}

void CSysMdbTopProcessInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMdbTopProcessInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMdbTopProcessInfo *)ref,&writeableObject);	
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
	
void CSysMdbTopProcessInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMdbTopProcessInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMdbTopProcessInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMdbTopProcessInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMdbFileSystemInfoResource> CSysMdbFileSystemInfoResource::resourceList;

CSysMdbFileSystemInfoResource * CSysMdbFileSystemInfoResource::alloc(int type, CSysMdbFileSystemInfoFactory *pFactory, CSysMdbFileSystemInfo *pObject, CWriteableSysMdbFileSystemInfo *pWriteableObject, bool updateIndex)
{
	CSysMdbFileSystemInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMdbFileSystemInfoResource::free(void)
{
	resourceList.free(this);
}

CSysMdbFileSystemInfoResource::CSysMdbFileSystemInfoResource(void)
{
}

CSysMdbFileSystemInfoResource::~CSysMdbFileSystemInfoResource(void)
{
}

void CSysMdbFileSystemInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMdbFileSystemInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMdbFileSystemInfo *)ref,&writeableObject);	
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
	
void CSysMdbFileSystemInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMdbFileSystemInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMdbFileSystemInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMdbFileSystemInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMdbNetworkInfoResource> CSysMdbNetworkInfoResource::resourceList;

CSysMdbNetworkInfoResource * CSysMdbNetworkInfoResource::alloc(int type, CSysMdbNetworkInfoFactory *pFactory, CSysMdbNetworkInfo *pObject, CWriteableSysMdbNetworkInfo *pWriteableObject, bool updateIndex)
{
	CSysMdbNetworkInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMdbNetworkInfoResource::free(void)
{
	resourceList.free(this);
}

CSysMdbNetworkInfoResource::CSysMdbNetworkInfoResource(void)
{
}

CSysMdbNetworkInfoResource::~CSysMdbNetworkInfoResource(void)
{
}

void CSysMdbNetworkInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMdbNetworkInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMdbNetworkInfo *)ref,&writeableObject);	
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
	
void CSysMdbNetworkInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMdbNetworkInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMdbNetworkInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMdbNetworkInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysParticipantInitResource> CSysParticipantInitResource::resourceList;

CSysParticipantInitResource * CSysParticipantInitResource::alloc(int type, CSysParticipantInitFactory *pFactory, CSysParticipantInit *pObject, CWriteableSysParticipantInit *pWriteableObject, bool updateIndex)
{
	CSysParticipantInitResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysParticipantInitResource::free(void)
{
	resourceList.free(this);
}

CSysParticipantInitResource::CSysParticipantInitResource(void)
{
}

CSysParticipantInitResource::~CSysParticipantInitResource(void)
{
}

void CSysParticipantInitResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysParticipantInit *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysParticipantInit *)ref,&writeableObject);	
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
	
void CSysParticipantInitResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysParticipantInit *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysParticipantInit *)ref,&writeableObject,m_updateIndex,false);
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

int CSysParticipantInitResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysUserInitResource> CSysUserInitResource::resourceList;

CSysUserInitResource * CSysUserInitResource::alloc(int type, CSysUserInitFactory *pFactory, CSysUserInit *pObject, CWriteableSysUserInit *pWriteableObject, bool updateIndex)
{
	CSysUserInitResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysUserInitResource::free(void)
{
	resourceList.free(this);
}

CSysUserInitResource::CSysUserInitResource(void)
{
}

CSysUserInitResource::~CSysUserInitResource(void)
{
}

void CSysUserInitResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysUserInit *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysUserInit *)ref,&writeableObject);	
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
	
void CSysUserInitResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysUserInit *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysUserInit *)ref,&writeableObject,m_updateIndex,false);
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

int CSysUserInitResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysClientInitResource> CSysClientInitResource::resourceList;

CSysClientInitResource * CSysClientInitResource::alloc(int type, CSysClientInitFactory *pFactory, CSysClientInit *pObject, CWriteableSysClientInit *pWriteableObject, bool updateIndex)
{
	CSysClientInitResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysClientInitResource::free(void)
{
	resourceList.free(this);
}

CSysClientInitResource::CSysClientInitResource(void)
{
}

CSysClientInitResource::~CSysClientInitResource(void)
{
}

void CSysClientInitResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysClientInit *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysClientInit *)ref,&writeableObject);	
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
	
void CSysClientInitResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysClientInit *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysClientInit *)ref,&writeableObject,m_updateIndex,false);
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

int CSysClientInitResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysTradeUserLoginInfoResource> CSysTradeUserLoginInfoResource::resourceList;

CSysTradeUserLoginInfoResource * CSysTradeUserLoginInfoResource::alloc(int type, CSysTradeUserLoginInfoFactory *pFactory, CSysTradeUserLoginInfo *pObject, CWriteableSysTradeUserLoginInfo *pWriteableObject, bool updateIndex)
{
	CSysTradeUserLoginInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysTradeUserLoginInfoResource::free(void)
{
	resourceList.free(this);
}

CSysTradeUserLoginInfoResource::CSysTradeUserLoginInfoResource(void)
{
}

CSysTradeUserLoginInfoResource::~CSysTradeUserLoginInfoResource(void)
{
}

void CSysTradeUserLoginInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysTradeUserLoginInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysTradeUserLoginInfo *)ref,&writeableObject);	
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
	
void CSysTradeUserLoginInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysTradeUserLoginInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysTradeUserLoginInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysTradeUserLoginInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMdbWebAppInfoResource> CSysMdbWebAppInfoResource::resourceList;

CSysMdbWebAppInfoResource * CSysMdbWebAppInfoResource::alloc(int type, CSysMdbWebAppInfoFactory *pFactory, CSysMdbWebAppInfo *pObject, CWriteableSysMdbWebAppInfo *pWriteableObject, bool updateIndex)
{
	CSysMdbWebAppInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMdbWebAppInfoResource::free(void)
{
	resourceList.free(this);
}

CSysMdbWebAppInfoResource::CSysMdbWebAppInfoResource(void)
{
}

CSysMdbWebAppInfoResource::~CSysMdbWebAppInfoResource(void)
{
}

void CSysMdbWebAppInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMdbWebAppInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMdbWebAppInfo *)ref,&writeableObject);	
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
	
void CSysMdbWebAppInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMdbWebAppInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMdbWebAppInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMdbWebAppInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMdbMemPoolInfoResource> CSysMdbMemPoolInfoResource::resourceList;

CSysMdbMemPoolInfoResource * CSysMdbMemPoolInfoResource::alloc(int type, CSysMdbMemPoolInfoFactory *pFactory, CSysMdbMemPoolInfo *pObject, CWriteableSysMdbMemPoolInfo *pWriteableObject, bool updateIndex)
{
	CSysMdbMemPoolInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMdbMemPoolInfoResource::free(void)
{
	resourceList.free(this);
}

CSysMdbMemPoolInfoResource::CSysMdbMemPoolInfoResource(void)
{
}

CSysMdbMemPoolInfoResource::~CSysMdbMemPoolInfoResource(void)
{
}

void CSysMdbMemPoolInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMdbMemPoolInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMdbMemPoolInfo *)ref,&writeableObject);	
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
	
void CSysMdbMemPoolInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMdbMemPoolInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMdbMemPoolInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMdbMemPoolInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMdbConnectorInfoResource> CSysMdbConnectorInfoResource::resourceList;

CSysMdbConnectorInfoResource * CSysMdbConnectorInfoResource::alloc(int type, CSysMdbConnectorInfoFactory *pFactory, CSysMdbConnectorInfo *pObject, CWriteableSysMdbConnectorInfo *pWriteableObject, bool updateIndex)
{
	CSysMdbConnectorInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMdbConnectorInfoResource::free(void)
{
	resourceList.free(this);
}

CSysMdbConnectorInfoResource::CSysMdbConnectorInfoResource(void)
{
}

CSysMdbConnectorInfoResource::~CSysMdbConnectorInfoResource(void)
{
}

void CSysMdbConnectorInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMdbConnectorInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMdbConnectorInfo *)ref,&writeableObject);	
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
	
void CSysMdbConnectorInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMdbConnectorInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMdbConnectorInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMdbConnectorInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMdbDBQueryResource> CSysMdbDBQueryResource::resourceList;

CSysMdbDBQueryResource * CSysMdbDBQueryResource::alloc(int type, CSysMdbDBQueryFactory *pFactory, CSysMdbDBQuery *pObject, CWriteableSysMdbDBQuery *pWriteableObject, bool updateIndex)
{
	CSysMdbDBQueryResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMdbDBQueryResource::free(void)
{
	resourceList.free(this);
}

CSysMdbDBQueryResource::CSysMdbDBQueryResource(void)
{
}

CSysMdbDBQueryResource::~CSysMdbDBQueryResource(void)
{
}

void CSysMdbDBQueryResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMdbDBQuery *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMdbDBQuery *)ref,&writeableObject);	
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
	
void CSysMdbDBQueryResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMdbDBQuery *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMdbDBQuery *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMdbDBQueryResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetAreaResource> CSysNetAreaResource::resourceList;

CSysNetAreaResource * CSysNetAreaResource::alloc(int type, CSysNetAreaFactory *pFactory, CSysNetArea *pObject, CWriteableSysNetArea *pWriteableObject, bool updateIndex)
{
	CSysNetAreaResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetAreaResource::free(void)
{
	resourceList.free(this);
}

CSysNetAreaResource::CSysNetAreaResource(void)
{
}

CSysNetAreaResource::~CSysNetAreaResource(void)
{
}

void CSysNetAreaResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetArea *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetArea *)ref,&writeableObject);	
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
	
void CSysNetAreaResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetArea *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetArea *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetAreaResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetSubAreaResource> CSysNetSubAreaResource::resourceList;

CSysNetSubAreaResource * CSysNetSubAreaResource::alloc(int type, CSysNetSubAreaFactory *pFactory, CSysNetSubArea *pObject, CWriteableSysNetSubArea *pWriteableObject, bool updateIndex)
{
	CSysNetSubAreaResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetSubAreaResource::free(void)
{
	resourceList.free(this);
}

CSysNetSubAreaResource::CSysNetSubAreaResource(void)
{
}

CSysNetSubAreaResource::~CSysNetSubAreaResource(void)
{
}

void CSysNetSubAreaResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetSubArea *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetSubArea *)ref,&writeableObject);	
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
	
void CSysNetSubAreaResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetSubArea *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetSubArea *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetSubAreaResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetSubAreaIPResource> CSysNetSubAreaIPResource::resourceList;

CSysNetSubAreaIPResource * CSysNetSubAreaIPResource::alloc(int type, CSysNetSubAreaIPFactory *pFactory, CSysNetSubAreaIP *pObject, CWriteableSysNetSubAreaIP *pWriteableObject, bool updateIndex)
{
	CSysNetSubAreaIPResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetSubAreaIPResource::free(void)
{
	resourceList.free(this);
}

CSysNetSubAreaIPResource::CSysNetSubAreaIPResource(void)
{
}

CSysNetSubAreaIPResource::~CSysNetSubAreaIPResource(void)
{
}

void CSysNetSubAreaIPResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetSubAreaIP *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetSubAreaIP *)ref,&writeableObject);	
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
	
void CSysNetSubAreaIPResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetSubAreaIP *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetSubAreaIP *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetSubAreaIPResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetFuncAreaResource> CSysNetFuncAreaResource::resourceList;

CSysNetFuncAreaResource * CSysNetFuncAreaResource::alloc(int type, CSysNetFuncAreaFactory *pFactory, CSysNetFuncArea *pObject, CWriteableSysNetFuncArea *pWriteableObject, bool updateIndex)
{
	CSysNetFuncAreaResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetFuncAreaResource::free(void)
{
	resourceList.free(this);
}

CSysNetFuncAreaResource::CSysNetFuncAreaResource(void)
{
}

CSysNetFuncAreaResource::~CSysNetFuncAreaResource(void)
{
}

void CSysNetFuncAreaResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetFuncArea *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetFuncArea *)ref,&writeableObject);	
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
	
void CSysNetFuncAreaResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetFuncArea *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetFuncArea *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetFuncAreaResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetDeviceResource> CSysNetDeviceResource::resourceList;

CSysNetDeviceResource * CSysNetDeviceResource::alloc(int type, CSysNetDeviceFactory *pFactory, CSysNetDevice *pObject, CWriteableSysNetDevice *pWriteableObject, bool updateIndex)
{
	CSysNetDeviceResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetDeviceResource::free(void)
{
	resourceList.free(this);
}

CSysNetDeviceResource::CSysNetDeviceResource(void)
{
}

CSysNetDeviceResource::~CSysNetDeviceResource(void)
{
}

void CSysNetDeviceResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetDevice *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetDevice *)ref,&writeableObject);	
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
	
void CSysNetDeviceResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetDevice *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetDevice *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetDeviceResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetDeviceLinkedResource> CSysNetDeviceLinkedResource::resourceList;

CSysNetDeviceLinkedResource * CSysNetDeviceLinkedResource::alloc(int type, CSysNetDeviceLinkedFactory *pFactory, CSysNetDeviceLinked *pObject, CWriteableSysNetDeviceLinked *pWriteableObject, bool updateIndex)
{
	CSysNetDeviceLinkedResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetDeviceLinkedResource::free(void)
{
	resourceList.free(this);
}

CSysNetDeviceLinkedResource::CSysNetDeviceLinkedResource(void)
{
}

CSysNetDeviceLinkedResource::~CSysNetDeviceLinkedResource(void)
{
}

void CSysNetDeviceLinkedResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetDeviceLinked *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetDeviceLinked *)ref,&writeableObject);	
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
	
void CSysNetDeviceLinkedResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetDeviceLinked *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetDeviceLinked *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetDeviceLinkedResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetOIDResource> CSysNetOIDResource::resourceList;

CSysNetOIDResource * CSysNetOIDResource::alloc(int type, CSysNetOIDFactory *pFactory, CSysNetOID *pObject, CWriteableSysNetOID *pWriteableObject, bool updateIndex)
{
	CSysNetOIDResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetOIDResource::free(void)
{
	resourceList.free(this);
}

CSysNetOIDResource::CSysNetOIDResource(void)
{
}

CSysNetOIDResource::~CSysNetOIDResource(void)
{
}

void CSysNetOIDResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetOID *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetOID *)ref,&writeableObject);	
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
	
void CSysNetOIDResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetOID *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetOID *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetOIDResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetDeviceTypeResource> CSysNetDeviceTypeResource::resourceList;

CSysNetDeviceTypeResource * CSysNetDeviceTypeResource::alloc(int type, CSysNetDeviceTypeFactory *pFactory, CSysNetDeviceType *pObject, CWriteableSysNetDeviceType *pWriteableObject, bool updateIndex)
{
	CSysNetDeviceTypeResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetDeviceTypeResource::free(void)
{
	resourceList.free(this);
}

CSysNetDeviceTypeResource::CSysNetDeviceTypeResource(void)
{
}

CSysNetDeviceTypeResource::~CSysNetDeviceTypeResource(void)
{
}

void CSysNetDeviceTypeResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetDeviceType *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetDeviceType *)ref,&writeableObject);	
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
	
void CSysNetDeviceTypeResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetDeviceType *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetDeviceType *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetDeviceTypeResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetTimePolicyResource> CSysNetTimePolicyResource::resourceList;

CSysNetTimePolicyResource * CSysNetTimePolicyResource::alloc(int type, CSysNetTimePolicyFactory *pFactory, CSysNetTimePolicy *pObject, CWriteableSysNetTimePolicy *pWriteableObject, bool updateIndex)
{
	CSysNetTimePolicyResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetTimePolicyResource::free(void)
{
	resourceList.free(this);
}

CSysNetTimePolicyResource::CSysNetTimePolicyResource(void)
{
}

CSysNetTimePolicyResource::~CSysNetTimePolicyResource(void)
{
}

void CSysNetTimePolicyResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetTimePolicy *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetTimePolicy *)ref,&writeableObject);	
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
	
void CSysNetTimePolicyResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetTimePolicy *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetTimePolicy *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetTimePolicyResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetGatherTaskResource> CSysNetGatherTaskResource::resourceList;

CSysNetGatherTaskResource * CSysNetGatherTaskResource::alloc(int type, CSysNetGatherTaskFactory *pFactory, CSysNetGatherTask *pObject, CWriteableSysNetGatherTask *pWriteableObject, bool updateIndex)
{
	CSysNetGatherTaskResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetGatherTaskResource::free(void)
{
	resourceList.free(this);
}

CSysNetGatherTaskResource::CSysNetGatherTaskResource(void)
{
}

CSysNetGatherTaskResource::~CSysNetGatherTaskResource(void)
{
}

void CSysNetGatherTaskResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetGatherTask *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetGatherTask *)ref,&writeableObject);	
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
	
void CSysNetGatherTaskResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetGatherTask *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetGatherTask *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetGatherTaskResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetDeviceCategoryResource> CSysNetDeviceCategoryResource::resourceList;

CSysNetDeviceCategoryResource * CSysNetDeviceCategoryResource::alloc(int type, CSysNetDeviceCategoryFactory *pFactory, CSysNetDeviceCategory *pObject, CWriteableSysNetDeviceCategory *pWriteableObject, bool updateIndex)
{
	CSysNetDeviceCategoryResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetDeviceCategoryResource::free(void)
{
	resourceList.free(this);
}

CSysNetDeviceCategoryResource::CSysNetDeviceCategoryResource(void)
{
}

CSysNetDeviceCategoryResource::~CSysNetDeviceCategoryResource(void)
{
}

void CSysNetDeviceCategoryResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetDeviceCategory *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetDeviceCategory *)ref,&writeableObject);	
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
	
void CSysNetDeviceCategoryResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetDeviceCategory *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetDeviceCategory *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetDeviceCategoryResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetManufactoryResource> CSysNetManufactoryResource::resourceList;

CSysNetManufactoryResource * CSysNetManufactoryResource::alloc(int type, CSysNetManufactoryFactory *pFactory, CSysNetManufactory *pObject, CWriteableSysNetManufactory *pWriteableObject, bool updateIndex)
{
	CSysNetManufactoryResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetManufactoryResource::free(void)
{
	resourceList.free(this);
}

CSysNetManufactoryResource::CSysNetManufactoryResource(void)
{
}

CSysNetManufactoryResource::~CSysNetManufactoryResource(void)
{
}

void CSysNetManufactoryResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetManufactory *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetManufactory *)ref,&writeableObject);	
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
	
void CSysNetManufactoryResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetManufactory *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetManufactory *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetManufactoryResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetCommunityResource> CSysNetCommunityResource::resourceList;

CSysNetCommunityResource * CSysNetCommunityResource::alloc(int type, CSysNetCommunityFactory *pFactory, CSysNetCommunity *pObject, CWriteableSysNetCommunity *pWriteableObject, bool updateIndex)
{
	CSysNetCommunityResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetCommunityResource::free(void)
{
	resourceList.free(this);
}

CSysNetCommunityResource::CSysNetCommunityResource(void)
{
}

CSysNetCommunityResource::~CSysNetCommunityResource(void)
{
}

void CSysNetCommunityResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetCommunity *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetCommunity *)ref,&writeableObject);	
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
	
void CSysNetCommunityResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetCommunity *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetCommunity *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetCommunityResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetPortTypeResource> CSysNetPortTypeResource::resourceList;

CSysNetPortTypeResource * CSysNetPortTypeResource::alloc(int type, CSysNetPortTypeFactory *pFactory, CSysNetPortType *pObject, CWriteableSysNetPortType *pWriteableObject, bool updateIndex)
{
	CSysNetPortTypeResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetPortTypeResource::free(void)
{
	resourceList.free(this);
}

CSysNetPortTypeResource::CSysNetPortTypeResource(void)
{
}

CSysNetPortTypeResource::~CSysNetPortTypeResource(void)
{
}

void CSysNetPortTypeResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetPortType *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetPortType *)ref,&writeableObject);	
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
	
void CSysNetPortTypeResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetPortType *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetPortType *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetPortTypeResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetInterfaceResource> CSysNetInterfaceResource::resourceList;

CSysNetInterfaceResource * CSysNetInterfaceResource::alloc(int type, CSysNetInterfaceFactory *pFactory, CSysNetInterface *pObject, CWriteableSysNetInterface *pWriteableObject, bool updateIndex)
{
	CSysNetInterfaceResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetInterfaceResource::free(void)
{
	resourceList.free(this);
}

CSysNetInterfaceResource::CSysNetInterfaceResource(void)
{
}

CSysNetInterfaceResource::~CSysNetInterfaceResource(void)
{
}

void CSysNetInterfaceResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetInterface *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetInterface *)ref,&writeableObject);	
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
	
void CSysNetInterfaceResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetInterface *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetInterface *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetInterfaceResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetGeneralOIDResource> CSysNetGeneralOIDResource::resourceList;

CSysNetGeneralOIDResource * CSysNetGeneralOIDResource::alloc(int type, CSysNetGeneralOIDFactory *pFactory, CSysNetGeneralOID *pObject, CWriteableSysNetGeneralOID *pWriteableObject, bool updateIndex)
{
	CSysNetGeneralOIDResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetGeneralOIDResource::free(void)
{
	resourceList.free(this);
}

CSysNetGeneralOIDResource::CSysNetGeneralOIDResource(void)
{
}

CSysNetGeneralOIDResource::~CSysNetGeneralOIDResource(void)
{
}

void CSysNetGeneralOIDResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetGeneralOID *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetGeneralOID *)ref,&writeableObject);	
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
	
void CSysNetGeneralOIDResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetGeneralOID *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetGeneralOID *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetGeneralOIDResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetMonitorTypeResource> CSysNetMonitorTypeResource::resourceList;

CSysNetMonitorTypeResource * CSysNetMonitorTypeResource::alloc(int type, CSysNetMonitorTypeFactory *pFactory, CSysNetMonitorType *pObject, CWriteableSysNetMonitorType *pWriteableObject, bool updateIndex)
{
	CSysNetMonitorTypeResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetMonitorTypeResource::free(void)
{
	resourceList.free(this);
}

CSysNetMonitorTypeResource::CSysNetMonitorTypeResource(void)
{
}

CSysNetMonitorTypeResource::~CSysNetMonitorTypeResource(void)
{
}

void CSysNetMonitorTypeResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetMonitorType *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetMonitorType *)ref,&writeableObject);	
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
	
void CSysNetMonitorTypeResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetMonitorType *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetMonitorType *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetMonitorTypeResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetMonitorAttrScopeResource> CSysNetMonitorAttrScopeResource::resourceList;

CSysNetMonitorAttrScopeResource * CSysNetMonitorAttrScopeResource::alloc(int type, CSysNetMonitorAttrScopeFactory *pFactory, CSysNetMonitorAttrScope *pObject, CWriteableSysNetMonitorAttrScope *pWriteableObject, bool updateIndex)
{
	CSysNetMonitorAttrScopeResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetMonitorAttrScopeResource::free(void)
{
	resourceList.free(this);
}

CSysNetMonitorAttrScopeResource::CSysNetMonitorAttrScopeResource(void)
{
}

CSysNetMonitorAttrScopeResource::~CSysNetMonitorAttrScopeResource(void)
{
}

void CSysNetMonitorAttrScopeResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetMonitorAttrScope *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetMonitorAttrScope *)ref,&writeableObject);	
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
	
void CSysNetMonitorAttrScopeResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetMonitorAttrScope *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetMonitorAttrScope *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetMonitorAttrScopeResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetMonitorAttrTypeResource> CSysNetMonitorAttrTypeResource::resourceList;

CSysNetMonitorAttrTypeResource * CSysNetMonitorAttrTypeResource::alloc(int type, CSysNetMonitorAttrTypeFactory *pFactory, CSysNetMonitorAttrType *pObject, CWriteableSysNetMonitorAttrType *pWriteableObject, bool updateIndex)
{
	CSysNetMonitorAttrTypeResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetMonitorAttrTypeResource::free(void)
{
	resourceList.free(this);
}

CSysNetMonitorAttrTypeResource::CSysNetMonitorAttrTypeResource(void)
{
}

CSysNetMonitorAttrTypeResource::~CSysNetMonitorAttrTypeResource(void)
{
}

void CSysNetMonitorAttrTypeResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetMonitorAttrType *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetMonitorAttrType *)ref,&writeableObject);	
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
	
void CSysNetMonitorAttrTypeResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetMonitorAttrType *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetMonitorAttrType *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetMonitorAttrTypeResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetMonitorCommandTypeResource> CSysNetMonitorCommandTypeResource::resourceList;

CSysNetMonitorCommandTypeResource * CSysNetMonitorCommandTypeResource::alloc(int type, CSysNetMonitorCommandTypeFactory *pFactory, CSysNetMonitorCommandType *pObject, CWriteableSysNetMonitorCommandType *pWriteableObject, bool updateIndex)
{
	CSysNetMonitorCommandTypeResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetMonitorCommandTypeResource::free(void)
{
	resourceList.free(this);
}

CSysNetMonitorCommandTypeResource::CSysNetMonitorCommandTypeResource(void)
{
}

CSysNetMonitorCommandTypeResource::~CSysNetMonitorCommandTypeResource(void)
{
}

void CSysNetMonitorCommandTypeResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetMonitorCommandType *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetMonitorCommandType *)ref,&writeableObject);	
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
	
void CSysNetMonitorCommandTypeResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetMonitorCommandType *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetMonitorCommandType *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetMonitorCommandTypeResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetMonitorActionGroupResource> CSysNetMonitorActionGroupResource::resourceList;

CSysNetMonitorActionGroupResource * CSysNetMonitorActionGroupResource::alloc(int type, CSysNetMonitorActionGroupFactory *pFactory, CSysNetMonitorActionGroup *pObject, CWriteableSysNetMonitorActionGroup *pWriteableObject, bool updateIndex)
{
	CSysNetMonitorActionGroupResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetMonitorActionGroupResource::free(void)
{
	resourceList.free(this);
}

CSysNetMonitorActionGroupResource::CSysNetMonitorActionGroupResource(void)
{
}

CSysNetMonitorActionGroupResource::~CSysNetMonitorActionGroupResource(void)
{
}

void CSysNetMonitorActionGroupResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetMonitorActionGroup *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetMonitorActionGroup *)ref,&writeableObject);	
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
	
void CSysNetMonitorActionGroupResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetMonitorActionGroup *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetMonitorActionGroup *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetMonitorActionGroupResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetMonitorDeviceGroupResource> CSysNetMonitorDeviceGroupResource::resourceList;

CSysNetMonitorDeviceGroupResource * CSysNetMonitorDeviceGroupResource::alloc(int type, CSysNetMonitorDeviceGroupFactory *pFactory, CSysNetMonitorDeviceGroup *pObject, CWriteableSysNetMonitorDeviceGroup *pWriteableObject, bool updateIndex)
{
	CSysNetMonitorDeviceGroupResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetMonitorDeviceGroupResource::free(void)
{
	resourceList.free(this);
}

CSysNetMonitorDeviceGroupResource::CSysNetMonitorDeviceGroupResource(void)
{
}

CSysNetMonitorDeviceGroupResource::~CSysNetMonitorDeviceGroupResource(void)
{
}

void CSysNetMonitorDeviceGroupResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetMonitorDeviceGroup *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetMonitorDeviceGroup *)ref,&writeableObject);	
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
	
void CSysNetMonitorDeviceGroupResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetMonitorDeviceGroup *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetMonitorDeviceGroup *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetMonitorDeviceGroupResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetMonitorTaskInfoResource> CSysNetMonitorTaskInfoResource::resourceList;

CSysNetMonitorTaskInfoResource * CSysNetMonitorTaskInfoResource::alloc(int type, CSysNetMonitorTaskInfoFactory *pFactory, CSysNetMonitorTaskInfo *pObject, CWriteableSysNetMonitorTaskInfo *pWriteableObject, bool updateIndex)
{
	CSysNetMonitorTaskInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetMonitorTaskInfoResource::free(void)
{
	resourceList.free(this);
}

CSysNetMonitorTaskInfoResource::CSysNetMonitorTaskInfoResource(void)
{
}

CSysNetMonitorTaskInfoResource::~CSysNetMonitorTaskInfoResource(void)
{
}

void CSysNetMonitorTaskInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetMonitorTaskInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetMonitorTaskInfo *)ref,&writeableObject);	
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
	
void CSysNetMonitorTaskInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetMonitorTaskInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetMonitorTaskInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetMonitorTaskInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetMonitorTaskObjectSetResource> CSysNetMonitorTaskObjectSetResource::resourceList;

CSysNetMonitorTaskObjectSetResource * CSysNetMonitorTaskObjectSetResource::alloc(int type, CSysNetMonitorTaskObjectSetFactory *pFactory, CSysNetMonitorTaskObjectSet *pObject, CWriteableSysNetMonitorTaskObjectSet *pWriteableObject, bool updateIndex)
{
	CSysNetMonitorTaskObjectSetResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetMonitorTaskObjectSetResource::free(void)
{
	resourceList.free(this);
}

CSysNetMonitorTaskObjectSetResource::CSysNetMonitorTaskObjectSetResource(void)
{
}

CSysNetMonitorTaskObjectSetResource::~CSysNetMonitorTaskObjectSetResource(void)
{
}

void CSysNetMonitorTaskObjectSetResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetMonitorTaskObjectSet *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetMonitorTaskObjectSet *)ref,&writeableObject);	
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
	
void CSysNetMonitorTaskObjectSetResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetMonitorTaskObjectSet *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetMonitorTaskObjectSet *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetMonitorTaskObjectSetResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetMonitorTaskResultResource> CSysNetMonitorTaskResultResource::resourceList;

CSysNetMonitorTaskResultResource * CSysNetMonitorTaskResultResource::alloc(int type, CSysNetMonitorTaskResultFactory *pFactory, CSysNetMonitorTaskResult *pObject, CWriteableSysNetMonitorTaskResult *pWriteableObject, bool updateIndex)
{
	CSysNetMonitorTaskResultResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetMonitorTaskResultResource::free(void)
{
	resourceList.free(this);
}

CSysNetMonitorTaskResultResource::CSysNetMonitorTaskResultResource(void)
{
}

CSysNetMonitorTaskResultResource::~CSysNetMonitorTaskResultResource(void)
{
}

void CSysNetMonitorTaskResultResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetMonitorTaskResult *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetMonitorTaskResult *)ref,&writeableObject);	
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
	
void CSysNetMonitorTaskResultResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetMonitorTaskResult *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetMonitorTaskResult *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetMonitorTaskResultResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetPartyLinkInfoResource> CSysNetPartyLinkInfoResource::resourceList;

CSysNetPartyLinkInfoResource * CSysNetPartyLinkInfoResource::alloc(int type, CSysNetPartyLinkInfoFactory *pFactory, CSysNetPartyLinkInfo *pObject, CWriteableSysNetPartyLinkInfo *pWriteableObject, bool updateIndex)
{
	CSysNetPartyLinkInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetPartyLinkInfoResource::free(void)
{
	resourceList.free(this);
}

CSysNetPartyLinkInfoResource::CSysNetPartyLinkInfoResource(void)
{
}

CSysNetPartyLinkInfoResource::~CSysNetPartyLinkInfoResource(void)
{
}

void CSysNetPartyLinkInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetPartyLinkInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetPartyLinkInfo *)ref,&writeableObject);	
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
	
void CSysNetPartyLinkInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetPartyLinkInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetPartyLinkInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetPartyLinkInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetDelPartyLinkInfoResource> CSysNetDelPartyLinkInfoResource::resourceList;

CSysNetDelPartyLinkInfoResource * CSysNetDelPartyLinkInfoResource::alloc(int type, CSysNetDelPartyLinkInfoFactory *pFactory, CSysNetDelPartyLinkInfo *pObject, CWriteableSysNetDelPartyLinkInfo *pWriteableObject, bool updateIndex)
{
	CSysNetDelPartyLinkInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetDelPartyLinkInfoResource::free(void)
{
	resourceList.free(this);
}

CSysNetDelPartyLinkInfoResource::CSysNetDelPartyLinkInfoResource(void)
{
}

CSysNetDelPartyLinkInfoResource::~CSysNetDelPartyLinkInfoResource(void)
{
}

void CSysNetDelPartyLinkInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetDelPartyLinkInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetDelPartyLinkInfo *)ref,&writeableObject);	
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
	
void CSysNetDelPartyLinkInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetDelPartyLinkInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetDelPartyLinkInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetDelPartyLinkInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetPartyLinkAddrChangeResource> CSysNetPartyLinkAddrChangeResource::resourceList;

CSysNetPartyLinkAddrChangeResource * CSysNetPartyLinkAddrChangeResource::alloc(int type, CSysNetPartyLinkAddrChangeFactory *pFactory, CSysNetPartyLinkAddrChange *pObject, CWriteableSysNetPartyLinkAddrChange *pWriteableObject, bool updateIndex)
{
	CSysNetPartyLinkAddrChangeResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetPartyLinkAddrChangeResource::free(void)
{
	resourceList.free(this);
}

CSysNetPartyLinkAddrChangeResource::CSysNetPartyLinkAddrChangeResource(void)
{
}

CSysNetPartyLinkAddrChangeResource::~CSysNetPartyLinkAddrChangeResource(void)
{
}

void CSysNetPartyLinkAddrChangeResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetPartyLinkAddrChange *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetPartyLinkAddrChange *)ref,&writeableObject);	
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
	
void CSysNetPartyLinkAddrChangeResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetPartyLinkAddrChange *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetPartyLinkAddrChange *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetPartyLinkAddrChangeResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetMonitorActionAttrResource> CSysNetMonitorActionAttrResource::resourceList;

CSysNetMonitorActionAttrResource * CSysNetMonitorActionAttrResource::alloc(int type, CSysNetMonitorActionAttrFactory *pFactory, CSysNetMonitorActionAttr *pObject, CWriteableSysNetMonitorActionAttr *pWriteableObject, bool updateIndex)
{
	CSysNetMonitorActionAttrResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetMonitorActionAttrResource::free(void)
{
	resourceList.free(this);
}

CSysNetMonitorActionAttrResource::CSysNetMonitorActionAttrResource(void)
{
}

CSysNetMonitorActionAttrResource::~CSysNetMonitorActionAttrResource(void)
{
}

void CSysNetMonitorActionAttrResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetMonitorActionAttr *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetMonitorActionAttr *)ref,&writeableObject);	
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
	
void CSysNetMonitorActionAttrResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetMonitorActionAttr *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetMonitorActionAttr *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetMonitorActionAttrResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetModuleResource> CSysNetModuleResource::resourceList;

CSysNetModuleResource * CSysNetModuleResource::alloc(int type, CSysNetModuleFactory *pFactory, CSysNetModule *pObject, CWriteableSysNetModule *pWriteableObject, bool updateIndex)
{
	CSysNetModuleResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetModuleResource::free(void)
{
	resourceList.free(this);
}

CSysNetModuleResource::CSysNetModuleResource(void)
{
}

CSysNetModuleResource::~CSysNetModuleResource(void)
{
}

void CSysNetModuleResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetModule *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetModule *)ref,&writeableObject);	
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
	
void CSysNetModuleResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetModule *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetModule *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetModuleResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetEventExprResource> CSysNetEventExprResource::resourceList;

CSysNetEventExprResource * CSysNetEventExprResource::alloc(int type, CSysNetEventExprFactory *pFactory, CSysNetEventExpr *pObject, CWriteableSysNetEventExpr *pWriteableObject, bool updateIndex)
{
	CSysNetEventExprResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetEventExprResource::free(void)
{
	resourceList.free(this);
}

CSysNetEventExprResource::CSysNetEventExprResource(void)
{
}

CSysNetEventExprResource::~CSysNetEventExprResource(void)
{
}

void CSysNetEventExprResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetEventExpr *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetEventExpr *)ref,&writeableObject);	
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
	
void CSysNetEventExprResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetEventExpr *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetEventExpr *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetEventExprResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetEventTypeResource> CSysNetEventTypeResource::resourceList;

CSysNetEventTypeResource * CSysNetEventTypeResource::alloc(int type, CSysNetEventTypeFactory *pFactory, CSysNetEventType *pObject, CWriteableSysNetEventType *pWriteableObject, bool updateIndex)
{
	CSysNetEventTypeResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetEventTypeResource::free(void)
{
	resourceList.free(this);
}

CSysNetEventTypeResource::CSysNetEventTypeResource(void)
{
}

CSysNetEventTypeResource::~CSysNetEventTypeResource(void)
{
}

void CSysNetEventTypeResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetEventType *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetEventType *)ref,&writeableObject);	
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
	
void CSysNetEventTypeResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetEventType *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetEventType *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetEventTypeResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetSubEventTypeResource> CSysNetSubEventTypeResource::resourceList;

CSysNetSubEventTypeResource * CSysNetSubEventTypeResource::alloc(int type, CSysNetSubEventTypeFactory *pFactory, CSysNetSubEventType *pObject, CWriteableSysNetSubEventType *pWriteableObject, bool updateIndex)
{
	CSysNetSubEventTypeResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetSubEventTypeResource::free(void)
{
	resourceList.free(this);
}

CSysNetSubEventTypeResource::CSysNetSubEventTypeResource(void)
{
}

CSysNetSubEventTypeResource::~CSysNetSubEventTypeResource(void)
{
}

void CSysNetSubEventTypeResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetSubEventType *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetSubEventType *)ref,&writeableObject);	
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
	
void CSysNetSubEventTypeResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetSubEventType *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetSubEventType *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetSubEventTypeResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetEventLevelResource> CSysNetEventLevelResource::resourceList;

CSysNetEventLevelResource * CSysNetEventLevelResource::alloc(int type, CSysNetEventLevelFactory *pFactory, CSysNetEventLevel *pObject, CWriteableSysNetEventLevel *pWriteableObject, bool updateIndex)
{
	CSysNetEventLevelResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetEventLevelResource::free(void)
{
	resourceList.free(this);
}

CSysNetEventLevelResource::CSysNetEventLevelResource(void)
{
}

CSysNetEventLevelResource::~CSysNetEventLevelResource(void)
{
}

void CSysNetEventLevelResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetEventLevel *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetEventLevel *)ref,&writeableObject);	
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
	
void CSysNetEventLevelResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetEventLevel *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetEventLevel *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetEventLevelResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetMonitorDeviceTaskResource> CSysNetMonitorDeviceTaskResource::resourceList;

CSysNetMonitorDeviceTaskResource * CSysNetMonitorDeviceTaskResource::alloc(int type, CSysNetMonitorDeviceTaskFactory *pFactory, CSysNetMonitorDeviceTask *pObject, CWriteableSysNetMonitorDeviceTask *pWriteableObject, bool updateIndex)
{
	CSysNetMonitorDeviceTaskResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetMonitorDeviceTaskResource::free(void)
{
	resourceList.free(this);
}

CSysNetMonitorDeviceTaskResource::CSysNetMonitorDeviceTaskResource(void)
{
}

CSysNetMonitorDeviceTaskResource::~CSysNetMonitorDeviceTaskResource(void)
{
}

void CSysNetMonitorDeviceTaskResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetMonitorDeviceTask *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetMonitorDeviceTask *)ref,&writeableObject);	
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
	
void CSysNetMonitorDeviceTaskResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetMonitorDeviceTask *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetMonitorDeviceTask *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetMonitorDeviceTaskResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetMonitorTaskInstAttrsResource> CSysNetMonitorTaskInstAttrsResource::resourceList;

CSysNetMonitorTaskInstAttrsResource * CSysNetMonitorTaskInstAttrsResource::alloc(int type, CSysNetMonitorTaskInstAttrsFactory *pFactory, CSysNetMonitorTaskInstAttrs *pObject, CWriteableSysNetMonitorTaskInstAttrs *pWriteableObject, bool updateIndex)
{
	CSysNetMonitorTaskInstAttrsResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetMonitorTaskInstAttrsResource::free(void)
{
	resourceList.free(this);
}

CSysNetMonitorTaskInstAttrsResource::CSysNetMonitorTaskInstAttrsResource(void)
{
}

CSysNetMonitorTaskInstAttrsResource::~CSysNetMonitorTaskInstAttrsResource(void)
{
}

void CSysNetMonitorTaskInstAttrsResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetMonitorTaskInstAttrs *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetMonitorTaskInstAttrs *)ref,&writeableObject);	
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
	
void CSysNetMonitorTaskInstAttrsResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetMonitorTaskInstAttrs *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetMonitorTaskInstAttrs *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetMonitorTaskInstAttrsResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetBaseLineResource> CSysNetBaseLineResource::resourceList;

CSysNetBaseLineResource * CSysNetBaseLineResource::alloc(int type, CSysNetBaseLineFactory *pFactory, CSysNetBaseLine *pObject, CWriteableSysNetBaseLine *pWriteableObject, bool updateIndex)
{
	CSysNetBaseLineResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetBaseLineResource::free(void)
{
	resourceList.free(this);
}

CSysNetBaseLineResource::CSysNetBaseLineResource(void)
{
}

CSysNetBaseLineResource::~CSysNetBaseLineResource(void)
{
}

void CSysNetBaseLineResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetBaseLine *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetBaseLine *)ref,&writeableObject);	
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
	
void CSysNetBaseLineResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetBaseLine *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetBaseLine *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetBaseLineResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetBaseLineTaskResource> CSysNetBaseLineTaskResource::resourceList;

CSysNetBaseLineTaskResource * CSysNetBaseLineTaskResource::alloc(int type, CSysNetBaseLineTaskFactory *pFactory, CSysNetBaseLineTask *pObject, CWriteableSysNetBaseLineTask *pWriteableObject, bool updateIndex)
{
	CSysNetBaseLineTaskResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetBaseLineTaskResource::free(void)
{
	resourceList.free(this);
}

CSysNetBaseLineTaskResource::CSysNetBaseLineTaskResource(void)
{
}

CSysNetBaseLineTaskResource::~CSysNetBaseLineTaskResource(void)
{
}

void CSysNetBaseLineTaskResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetBaseLineTask *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetBaseLineTask *)ref,&writeableObject);	
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
	
void CSysNetBaseLineTaskResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetBaseLineTask *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetBaseLineTask *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetBaseLineTaskResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMdbNetPartyLinkStatusInfoResource> CSysMdbNetPartyLinkStatusInfoResource::resourceList;

CSysMdbNetPartyLinkStatusInfoResource * CSysMdbNetPartyLinkStatusInfoResource::alloc(int type, CSysMdbNetPartyLinkStatusInfoFactory *pFactory, CSysMdbNetPartyLinkStatusInfo *pObject, CWriteableSysMdbNetPartyLinkStatusInfo *pWriteableObject, bool updateIndex)
{
	CSysMdbNetPartyLinkStatusInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMdbNetPartyLinkStatusInfoResource::free(void)
{
	resourceList.free(this);
}

CSysMdbNetPartyLinkStatusInfoResource::CSysMdbNetPartyLinkStatusInfoResource(void)
{
}

CSysMdbNetPartyLinkStatusInfoResource::~CSysMdbNetPartyLinkStatusInfoResource(void)
{
}

void CSysMdbNetPartyLinkStatusInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMdbNetPartyLinkStatusInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMdbNetPartyLinkStatusInfo *)ref,&writeableObject);	
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
	
void CSysMdbNetPartyLinkStatusInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMdbNetPartyLinkStatusInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMdbNetPartyLinkStatusInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMdbNetPartyLinkStatusInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetMemberSDHLineInfoResource> CSysNetMemberSDHLineInfoResource::resourceList;

CSysNetMemberSDHLineInfoResource * CSysNetMemberSDHLineInfoResource::alloc(int type, CSysNetMemberSDHLineInfoFactory *pFactory, CSysNetMemberSDHLineInfo *pObject, CWriteableSysNetMemberSDHLineInfo *pWriteableObject, bool updateIndex)
{
	CSysNetMemberSDHLineInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetMemberSDHLineInfoResource::free(void)
{
	resourceList.free(this);
}

CSysNetMemberSDHLineInfoResource::CSysNetMemberSDHLineInfoResource(void)
{
}

CSysNetMemberSDHLineInfoResource::~CSysNetMemberSDHLineInfoResource(void)
{
}

void CSysNetMemberSDHLineInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetMemberSDHLineInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetMemberSDHLineInfo *)ref,&writeableObject);	
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
	
void CSysNetMemberSDHLineInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetMemberSDHLineInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetMemberSDHLineInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetMemberSDHLineInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetDDNLinkInfoResource> CSysNetDDNLinkInfoResource::resourceList;

CSysNetDDNLinkInfoResource * CSysNetDDNLinkInfoResource::alloc(int type, CSysNetDDNLinkInfoFactory *pFactory, CSysNetDDNLinkInfo *pObject, CWriteableSysNetDDNLinkInfo *pWriteableObject, bool updateIndex)
{
	CSysNetDDNLinkInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetDDNLinkInfoResource::free(void)
{
	resourceList.free(this);
}

CSysNetDDNLinkInfoResource::CSysNetDDNLinkInfoResource(void)
{
}

CSysNetDDNLinkInfoResource::~CSysNetDDNLinkInfoResource(void)
{
}

void CSysNetDDNLinkInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetDDNLinkInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetDDNLinkInfo *)ref,&writeableObject);	
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
	
void CSysNetDDNLinkInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetDDNLinkInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetDDNLinkInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetDDNLinkInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetPseudMemberLinkInfoResource> CSysNetPseudMemberLinkInfoResource::resourceList;

CSysNetPseudMemberLinkInfoResource * CSysNetPseudMemberLinkInfoResource::alloc(int type, CSysNetPseudMemberLinkInfoFactory *pFactory, CSysNetPseudMemberLinkInfo *pObject, CWriteableSysNetPseudMemberLinkInfo *pWriteableObject, bool updateIndex)
{
	CSysNetPseudMemberLinkInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetPseudMemberLinkInfoResource::free(void)
{
	resourceList.free(this);
}

CSysNetPseudMemberLinkInfoResource::CSysNetPseudMemberLinkInfoResource(void)
{
}

CSysNetPseudMemberLinkInfoResource::~CSysNetPseudMemberLinkInfoResource(void)
{
}

void CSysNetPseudMemberLinkInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetPseudMemberLinkInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetPseudMemberLinkInfo *)ref,&writeableObject);	
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
	
void CSysNetPseudMemberLinkInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetPseudMemberLinkInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetPseudMemberLinkInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetPseudMemberLinkInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetOuterDeviceInfoResource> CSysNetOuterDeviceInfoResource::resourceList;

CSysNetOuterDeviceInfoResource * CSysNetOuterDeviceInfoResource::alloc(int type, CSysNetOuterDeviceInfoFactory *pFactory, CSysNetOuterDeviceInfo *pObject, CWriteableSysNetOuterDeviceInfo *pWriteableObject, bool updateIndex)
{
	CSysNetOuterDeviceInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetOuterDeviceInfoResource::free(void)
{
	resourceList.free(this);
}

CSysNetOuterDeviceInfoResource::CSysNetOuterDeviceInfoResource(void)
{
}

CSysNetOuterDeviceInfoResource::~CSysNetOuterDeviceInfoResource(void)
{
}

void CSysNetOuterDeviceInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetOuterDeviceInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetOuterDeviceInfo *)ref,&writeableObject);	
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
	
void CSysNetOuterDeviceInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetOuterDeviceInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetOuterDeviceInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetOuterDeviceInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysLocalPingResultInfoResource> CSysLocalPingResultInfoResource::resourceList;

CSysLocalPingResultInfoResource * CSysLocalPingResultInfoResource::alloc(int type, CSysLocalPingResultInfoFactory *pFactory, CSysLocalPingResultInfo *pObject, CWriteableSysLocalPingResultInfo *pWriteableObject, bool updateIndex)
{
	CSysLocalPingResultInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysLocalPingResultInfoResource::free(void)
{
	resourceList.free(this);
}

CSysLocalPingResultInfoResource::CSysLocalPingResultInfoResource(void)
{
}

CSysLocalPingResultInfoResource::~CSysLocalPingResultInfoResource(void)
{
}

void CSysLocalPingResultInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysLocalPingResultInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysLocalPingResultInfo *)ref,&writeableObject);	
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
	
void CSysLocalPingResultInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysLocalPingResultInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysLocalPingResultInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysLocalPingResultInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysRomotePingResultInfoResource> CSysRomotePingResultInfoResource::resourceList;

CSysRomotePingResultInfoResource * CSysRomotePingResultInfoResource::alloc(int type, CSysRomotePingResultInfoFactory *pFactory, CSysRomotePingResultInfo *pObject, CWriteableSysRomotePingResultInfo *pWriteableObject, bool updateIndex)
{
	CSysRomotePingResultInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysRomotePingResultInfoResource::free(void)
{
	resourceList.free(this);
}

CSysRomotePingResultInfoResource::CSysRomotePingResultInfoResource(void)
{
}

CSysRomotePingResultInfoResource::~CSysRomotePingResultInfoResource(void)
{
}

void CSysRomotePingResultInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysRomotePingResultInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysRomotePingResultInfo *)ref,&writeableObject);	
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
	
void CSysRomotePingResultInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysRomotePingResultInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysRomotePingResultInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysRomotePingResultInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysParticTradeOrderStatesResource> CSysParticTradeOrderStatesResource::resourceList;

CSysParticTradeOrderStatesResource * CSysParticTradeOrderStatesResource::alloc(int type, CSysParticTradeOrderStatesFactory *pFactory, CSysParticTradeOrderStates *pObject, CWriteableSysParticTradeOrderStates *pWriteableObject, bool updateIndex)
{
	CSysParticTradeOrderStatesResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysParticTradeOrderStatesResource::free(void)
{
	resourceList.free(this);
}

CSysParticTradeOrderStatesResource::CSysParticTradeOrderStatesResource(void)
{
}

CSysParticTradeOrderStatesResource::~CSysParticTradeOrderStatesResource(void)
{
}

void CSysParticTradeOrderStatesResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysParticTradeOrderStates *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysParticTradeOrderStates *)ref,&writeableObject);	
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
	
void CSysParticTradeOrderStatesResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysParticTradeOrderStates *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysParticTradeOrderStates *)ref,&writeableObject,m_updateIndex,false);
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

int CSysParticTradeOrderStatesResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMdbRouterInfoResource> CSysMdbRouterInfoResource::resourceList;

CSysMdbRouterInfoResource * CSysMdbRouterInfoResource::alloc(int type, CSysMdbRouterInfoFactory *pFactory, CSysMdbRouterInfo *pObject, CWriteableSysMdbRouterInfo *pWriteableObject, bool updateIndex)
{
	CSysMdbRouterInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMdbRouterInfoResource::free(void)
{
	resourceList.free(this);
}

CSysMdbRouterInfoResource::CSysMdbRouterInfoResource(void)
{
}

CSysMdbRouterInfoResource::~CSysMdbRouterInfoResource(void)
{
}

void CSysMdbRouterInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMdbRouterInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMdbRouterInfo *)ref,&writeableObject);	
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
	
void CSysMdbRouterInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMdbRouterInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMdbRouterInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMdbRouterInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMdbDiskIOResource> CSysMdbDiskIOResource::resourceList;

CSysMdbDiskIOResource * CSysMdbDiskIOResource::alloc(int type, CSysMdbDiskIOFactory *pFactory, CSysMdbDiskIO *pObject, CWriteableSysMdbDiskIO *pWriteableObject, bool updateIndex)
{
	CSysMdbDiskIOResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMdbDiskIOResource::free(void)
{
	resourceList.free(this);
}

CSysMdbDiskIOResource::CSysMdbDiskIOResource(void)
{
}

CSysMdbDiskIOResource::~CSysMdbDiskIOResource(void)
{
}

void CSysMdbDiskIOResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMdbDiskIO *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMdbDiskIO *)ref,&writeableObject);	
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
	
void CSysMdbDiskIOResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMdbDiskIO *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMdbDiskIO *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMdbDiskIOResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMdbStatInfoResource> CSysMdbStatInfoResource::resourceList;

CSysMdbStatInfoResource * CSysMdbStatInfoResource::alloc(int type, CSysMdbStatInfoFactory *pFactory, CSysMdbStatInfo *pObject, CWriteableSysMdbStatInfo *pWriteableObject, bool updateIndex)
{
	CSysMdbStatInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMdbStatInfoResource::free(void)
{
	resourceList.free(this);
}

CSysMdbStatInfoResource::CSysMdbStatInfoResource(void)
{
}

CSysMdbStatInfoResource::~CSysMdbStatInfoResource(void)
{
}

void CSysMdbStatInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMdbStatInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMdbStatInfo *)ref,&writeableObject);	
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
	
void CSysMdbStatInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMdbStatInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMdbStatInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMdbStatInfoResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMdbTradeFrontOrderRttStatResource> CSysMdbTradeFrontOrderRttStatResource::resourceList;

CSysMdbTradeFrontOrderRttStatResource * CSysMdbTradeFrontOrderRttStatResource::alloc(int type, CSysMdbTradeFrontOrderRttStatFactory *pFactory, CSysMdbTradeFrontOrderRttStat *pObject, CWriteableSysMdbTradeFrontOrderRttStat *pWriteableObject, bool updateIndex)
{
	CSysMdbTradeFrontOrderRttStatResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMdbTradeFrontOrderRttStatResource::free(void)
{
	resourceList.free(this);
}

CSysMdbTradeFrontOrderRttStatResource::CSysMdbTradeFrontOrderRttStatResource(void)
{
}

CSysMdbTradeFrontOrderRttStatResource::~CSysMdbTradeFrontOrderRttStatResource(void)
{
}

void CSysMdbTradeFrontOrderRttStatResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMdbTradeFrontOrderRttStat *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMdbTradeFrontOrderRttStat *)ref,&writeableObject);	
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
	
void CSysMdbTradeFrontOrderRttStatResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMdbTradeFrontOrderRttStat *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMdbTradeFrontOrderRttStat *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMdbTradeFrontOrderRttStatResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysInstrumentStatusResource> CSysInstrumentStatusResource::resourceList;

CSysInstrumentStatusResource * CSysInstrumentStatusResource::alloc(int type, CSysInstrumentStatusFactory *pFactory, CSysInstrumentStatus *pObject, CWriteableSysInstrumentStatus *pWriteableObject, bool updateIndex)
{
	CSysInstrumentStatusResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysInstrumentStatusResource::free(void)
{
	resourceList.free(this);
}

CSysInstrumentStatusResource::CSysInstrumentStatusResource(void)
{
}

CSysInstrumentStatusResource::~CSysInstrumentStatusResource(void)
{
}

void CSysInstrumentStatusResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysInstrumentStatus *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysInstrumentStatus *)ref,&writeableObject);	
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
	
void CSysInstrumentStatusResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysInstrumentStatus *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysInstrumentStatus *)ref,&writeableObject,m_updateIndex,false);
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

int CSysInstrumentStatusResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysCurrTradingSegmentAttrResource> CSysCurrTradingSegmentAttrResource::resourceList;

CSysCurrTradingSegmentAttrResource * CSysCurrTradingSegmentAttrResource::alloc(int type, CSysCurrTradingSegmentAttrFactory *pFactory, CSysCurrTradingSegmentAttr *pObject, CWriteableSysCurrTradingSegmentAttr *pWriteableObject, bool updateIndex)
{
	CSysCurrTradingSegmentAttrResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysCurrTradingSegmentAttrResource::free(void)
{
	resourceList.free(this);
}

CSysCurrTradingSegmentAttrResource::CSysCurrTradingSegmentAttrResource(void)
{
}

CSysCurrTradingSegmentAttrResource::~CSysCurrTradingSegmentAttrResource(void)
{
}

void CSysCurrTradingSegmentAttrResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysCurrTradingSegmentAttr *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysCurrTradingSegmentAttr *)ref,&writeableObject);	
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
	
void CSysCurrTradingSegmentAttrResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysCurrTradingSegmentAttr *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysCurrTradingSegmentAttr *)ref,&writeableObject,m_updateIndex,false);
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

int CSysCurrTradingSegmentAttrResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysMemberLinkCostResource> CSysMemberLinkCostResource::resourceList;

CSysMemberLinkCostResource * CSysMemberLinkCostResource::alloc(int type, CSysMemberLinkCostFactory *pFactory, CSysMemberLinkCost *pObject, CWriteableSysMemberLinkCost *pWriteableObject, bool updateIndex)
{
	CSysMemberLinkCostResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysMemberLinkCostResource::free(void)
{
	resourceList.free(this);
}

CSysMemberLinkCostResource::CSysMemberLinkCostResource(void)
{
}

CSysMemberLinkCostResource::~CSysMemberLinkCostResource(void)
{
}

void CSysMemberLinkCostResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysMemberLinkCost *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysMemberLinkCost *)ref,&writeableObject);	
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
	
void CSysMemberLinkCostResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysMemberLinkCost *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysMemberLinkCost *)ref,&writeableObject,m_updateIndex,false);
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

int CSysMemberLinkCostResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetPartylinkMonthlyRentResource> CSysNetPartylinkMonthlyRentResource::resourceList;

CSysNetPartylinkMonthlyRentResource * CSysNetPartylinkMonthlyRentResource::alloc(int type, CSysNetPartylinkMonthlyRentFactory *pFactory, CSysNetPartylinkMonthlyRent *pObject, CWriteableSysNetPartylinkMonthlyRent *pWriteableObject, bool updateIndex)
{
	CSysNetPartylinkMonthlyRentResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetPartylinkMonthlyRentResource::free(void)
{
	resourceList.free(this);
}

CSysNetPartylinkMonthlyRentResource::CSysNetPartylinkMonthlyRentResource(void)
{
}

CSysNetPartylinkMonthlyRentResource::~CSysNetPartylinkMonthlyRentResource(void)
{
}

void CSysNetPartylinkMonthlyRentResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetPartylinkMonthlyRent *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetPartylinkMonthlyRent *)ref,&writeableObject);	
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
	
void CSysNetPartylinkMonthlyRentResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetPartylinkMonthlyRent *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetPartylinkMonthlyRent *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetPartylinkMonthlyRentResource::getPriority(void)
{
	return 2;
}


CMemoryStack<CSysNetNonPartyLinkInfoResource> CSysNetNonPartyLinkInfoResource::resourceList;

CSysNetNonPartyLinkInfoResource * CSysNetNonPartyLinkInfoResource::alloc(int type, CSysNetNonPartyLinkInfoFactory *pFactory, CSysNetNonPartyLinkInfo *pObject, CWriteableSysNetNonPartyLinkInfo *pWriteableObject, bool updateIndex)
{
	CSysNetNonPartyLinkInfoResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CSysNetNonPartyLinkInfoResource::free(void)
{
	resourceList.free(this);
}

CSysNetNonPartyLinkInfoResource::CSysNetNonPartyLinkInfoResource(void)
{
}

CSysNetNonPartyLinkInfoResource::~CSysNetNonPartyLinkInfoResource(void)
{
}

void CSysNetNonPartyLinkInfoResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CSysNetNonPartyLinkInfo *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CSysNetNonPartyLinkInfo *)ref,&writeableObject);	
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
	
void CSysNetNonPartyLinkInfoResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CSysNetNonPartyLinkInfo *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CSysNetNonPartyLinkInfo *)ref,&writeableObject,m_updateIndex,false);
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

int CSysNetNonPartyLinkInfoResource::getPriority(void)
{
	return 2;
}

