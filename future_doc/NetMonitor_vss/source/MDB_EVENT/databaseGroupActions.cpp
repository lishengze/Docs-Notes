/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseGroupActions.cpp
///@brief实现了若干个内存数据库的群组操作
///@history 
///20060127	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "databaseGroupActions.h"

void groupAction(CMonitorEntityIterator *pIterator, TMonitorEntityActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMonitorEntity *pMonitorEntity;
	
	while ((pMonitorEntity=pIterator->next())!=NULL)
	{
		if (!actionFunc(pMonitorEntity, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CMonitorEntityIterator *pIterator, TMonitorEntityUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMonitorEntity *pMonitorEntity;
	CWriteableMonitorEntity theMonitorEntity;
	bool updateIndex;
	CMonitorEntityFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMonitorEntity=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pMonitorEntity,&theMonitorEntity);
		needContinue=updateFunc(&theMonitorEntity, pTransaction, parameter, &updateIndex);
		pFactory->update(pMonitorEntity,&theMonitorEntity,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CMonitorEntityIterator *pIterator, TMonitorEntitySelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMonitorEntity *pMonitorEntity;
	int selected;
	CMonitorEntityFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMonitorEntity=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pMonitorEntity, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pMonitorEntity,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CEventEntityIterator *pIterator, TEventEntityActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CEventEntity *pEventEntity;
	
	while ((pEventEntity=pIterator->next())!=NULL)
	{
		if (!actionFunc(pEventEntity, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CEventEntityIterator *pIterator, TEventEntityUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CEventEntity *pEventEntity;
	CWriteableEventEntity theEventEntity;
	bool updateIndex;
	CEventEntityFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pEventEntity=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pEventEntity,&theEventEntity);
		needContinue=updateFunc(&theEventEntity, pTransaction, parameter, &updateIndex);
		pFactory->update(pEventEntity,&theEventEntity,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CEventEntityIterator *pIterator, TEventEntitySelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CEventEntity *pEventEntity;
	int selected;
	CEventEntityFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pEventEntity=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pEventEntity, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pEventEntity,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

