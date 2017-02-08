/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseResources.cpp
///@brief实现了若干内存数据资源，可以放置于事务中
///@history 
///20060127	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "databaseResources.h"


CMemoryStack<CMonitorEntityResource> CMonitorEntityResource::resourceList;

CMonitorEntityResource * CMonitorEntityResource::alloc(int type, CMonitorEntityFactory *pFactory, CMonitorEntity *pObject, CWriteableMonitorEntity *pWriteableObject, bool updateIndex)
{
	CMonitorEntityResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CMonitorEntityResource::free(void)
{
	resourceList.free(this);
}

CMonitorEntityResource::CMonitorEntityResource(void)
{
}

CMonitorEntityResource::~CMonitorEntityResource(void)
{
}

void CMonitorEntityResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CMonitorEntity *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CMonitorEntity *)ref,&writeableObject);	
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
	
void CMonitorEntityResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CMonitorEntity *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CMonitorEntity *)ref,&writeableObject,m_updateIndex,false);
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

int CMonitorEntityResource::getPriority(void)
{
	return 1;
}


CMemoryStack<CEventEntityResource> CEventEntityResource::resourceList;

CEventEntityResource * CEventEntityResource::alloc(int type, CEventEntityFactory *pFactory, CEventEntity *pObject, CWriteableEventEntity *pWriteableObject, bool updateIndex)
{
	CEventEntityResource *pResource=resourceList.alloc();
	pResource->init(type,pFactory,pObject,pWriteableObject,updateIndex);
	return pResource;
}

void CEventEntityResource::free(void)
{
	resourceList.free(this);
}

CEventEntityResource::CEventEntityResource(void)
{
}

CEventEntityResource::~CEventEntityResource(void)
{
}

void CEventEntityResource::commit(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->commitAdd((CEventEntity *)ref);
		break;
	case UPDATE_ACTION:
		pFactory->commitUpdate((CEventEntity *)ref,&writeableObject);	
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
	
void CEventEntityResource::rollback(void)
{
	switch (m_type)
	{
	case CREATE_ACTION:
		pFactory->internalRemove((CEventEntity *)ref,false);
		break;
	case UPDATE_ACTION:
		pFactory->internalUpdate((CEventEntity *)ref,&writeableObject,m_updateIndex,false);
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

int CEventEntityResource::getPriority(void)
{
	return 1;
}

