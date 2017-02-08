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
int compareForKeyIndexinMonitorEntity(const void *pV1, const void *pV2)
{
	CMonitorEntity *p1,*p2;
	p1=(CMonitorEntity *)pV1;
	p2=(CMonitorEntity *)pV2;
	switch (compare(p1->MonitorObject.getValue(),p2->MonitorObject.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonitorItem.getValue(),p2->MonitorItem.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonitorTime.getValue(),p2->MonitorTime.getValue()))
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
int findByKeyForMonitorEntity=0;
#endif
CMonitorEntity *CMonitorEntityFactory::findByKey( const CReadOnlyMonitorObjectType&  MonitorObject,  const CReadOnlyMonitorItemType&  MonitorItem,  const CReadOnlyMonitorTimeType&  MonitorTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByKey of CMonitorEntity while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByKeyForMonitorEntity++;
#endif
	CAVLNode *pNode;
	compareObject.MonitorObject=MonitorObject.getValue();
	compareObject.MonitorItem=MonitorItem.getValue();
	compareObject.MonitorTime=MonitorTime.getValue();
	pNode=pKeyIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CMonitorEntity *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByTimeForMonitorEntity=0;
#endif

CMonitorEntity *CMonitorEntityFactory::startFindByTime( const CReadOnlyMonitorObjectType& MonitorObject,  const CReadOnlyMonitorItemType& MonitorItem,  const CReadOnlyMonitorTimeType& MonitorTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTime of CMonitorEntity while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTime();
	}

	///记录所有的查询值
	queryMonitorObjectInSearchByTime= MonitorObject.getValue();
	queryMonitorItemInSearchByTime= MonitorItem.getValue();
	queryMonitorTimeInSearchByTime= MonitorTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByTimeForMonitorEntity++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CMonitorEntity *theMonitorEntity;
	compareObject.MonitorObject=MonitorObject.getValue();
	compareObject.MonitorItem=MonitorItem.getValue();
	compareObject.MonitorTime=MonitorTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByTime=pKeyIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theMonitorEntity=(CMonitorEntity *)(pLastFoundInSearchByTime->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theMonitorEntity->MonitorObject.getValue(),MonitorObject.getValue()))
	{
		pLastFoundInSearchByTime=NULL;
		return NULL;
	}
	if (compare(theMonitorEntity->MonitorItem.getValue(),MonitorItem.getValue()))
	{
		pLastFoundInSearchByTime=NULL;
		return NULL;
	}

	///返回找到的结果
	return theMonitorEntity;
}

CMonitorEntity *CMonitorEntityFactory::findNextByTime(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTimeForMonitorEntity++;
#endif
	CMonitorEntity *theMonitorEntity;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByTime=pKeyIndex->getNextNode(pLastFoundInSearchByTime);
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	theMonitorEntity=(CMonitorEntity *)(pLastFoundInSearchByTime->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theMonitorEntity->MonitorObject,queryMonitorObjectInSearchByTime))
	{
		pLastFoundInSearchByTime=NULL;
		return NULL;
	}
	if (compare(theMonitorEntity->MonitorItem,queryMonitorItemInSearchByTime))
	{
		pLastFoundInSearchByTime=NULL;
		return NULL;
	}

	///返回找到的结果
	return theMonitorEntity;
}

void CMonitorEntityFactory::endFindByTime(void)
{
	pLastFoundInSearchByTime=NULL;
}


#ifdef COUNT_SEARCH
int findByKey1ForMonitorEntity=0;
#endif
CMonitorEntity *CMonitorEntityFactory::findByKey1( const CReadOnlyMonitorObjectType&  MonitorObject,  const CReadOnlyMonitorItemType&  MonitorItem)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByKey1 of CMonitorEntity while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByKey1ForMonitorEntity++;
#endif
	CAVLNode *pNode;
	compareObject.MonitorObject=MonitorObject.getValue();
	compareObject.MonitorItem=MonitorItem.getValue();
	compareObject.MonitorTime=0;
	pNode=pKeyIndex->searchFirstGreatEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	if (compare(((CMonitorEntity *)(pNode->pObject))->MonitorObject.getValue(),MonitorObject.getValue())!=0)
	{
		return NULL;
	}
	if (compare(((CMonitorEntity *)(pNode->pObject))->MonitorItem.getValue(),MonitorItem.getValue())!=0)
	{
		return NULL;
	}
	return (CMonitorEntity *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByAllForMonitorEntity=0;
#endif

CMonitorEntity *CMonitorEntityFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CMonitorEntity while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///记录所有的查询值

#ifdef COUNT_SEARCH
	multiFindByAllForMonitorEntity++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CMonitorEntity *theMonitorEntity;
	compareObject.MonitorObject=0;
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByAll=pKeyIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theMonitorEntity=(CMonitorEntity *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theMonitorEntity;
}

CMonitorEntity *CMonitorEntityFactory::findNextByAll(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForMonitorEntity++;
#endif
	CMonitorEntity *theMonitorEntity;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByAll=pKeyIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theMonitorEntity=(CMonitorEntity *)(pLastFoundInSearchByAll->pObject);
	
	///如果有一个条件不满足，则失败返回

	///返回找到的结果
	return theMonitorEntity;
}

void CMonitorEntityFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForKeyIndexinEventEntity(const void *pV1, const void *pV2)
{
	CEventEntity *p1,*p2;
	p1=(CEventEntity *)pV1;
	p2=(CEventEntity *)pV2;
	switch (compare(p1->EventName.getValue(),p2->EventName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonitorTime.getValue(),p2->MonitorTime.getValue()))
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
int compareForKeyObjectinEventEntity(const void *pV1, const void *pV2)
{
	CEventEntity *p1,*p2;
	p1=(CEventEntity *)pV1;
	p2=(CEventEntity *)pV2;
	switch (compare(p1->MonitorObject.getValue(),p2->MonitorObject.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->EventName.getValue(),p2->EventName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonitorTime.getValue(),p2->MonitorTime.getValue()))
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
int multiFindByKeyForEventEntity=0;
#endif

CEventEntity *CEventEntityFactory::startFindByKey( const CReadOnlyMonitorItemType& EventName,  const CReadOnlyMonitorTimeType& MonitorTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByKey of CEventEntity while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByKey!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByKey();
	}

	///记录所有的查询值
	queryEventNameInSearchByKey= EventName.getValue();
	queryMonitorTimeInSearchByKey= MonitorTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByKeyForEventEntity++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CEventEntity *theEventEntity;
	compareObject.EventName=EventName.getValue();
	compareObject.MonitorTime=MonitorTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByKey=pKeyIndex->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByKey==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theEventEntity=(CEventEntity *)(pLastFoundInSearchByKey->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theEventEntity->EventName.getValue(),EventName.getValue()))
	{
		pLastFoundInSearchByKey=NULL;
		return NULL;
	}

	///返回找到的结果
	return theEventEntity;
}

CEventEntity *CEventEntityFactory::findNextByKey(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByKey==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByKeyForEventEntity++;
#endif
	CEventEntity *theEventEntity;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByKey=pKeyIndex->getNextNode(pLastFoundInSearchByKey);
	if (pLastFoundInSearchByKey==NULL)
	{
		return NULL;
	}

	theEventEntity=(CEventEntity *)(pLastFoundInSearchByKey->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theEventEntity->EventName,queryEventNameInSearchByKey))
	{
		pLastFoundInSearchByKey=NULL;
		return NULL;
	}

	///返回找到的结果
	return theEventEntity;
}

void CEventEntityFactory::endFindByKey(void)
{
	pLastFoundInSearchByKey=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByObjectForEventEntity=0;
#endif

CEventEntity *CEventEntityFactory::startFindByObject( const CReadOnlyMonitorObjectType& MonitorObject,  const CReadOnlyMonitorItemType& EventName,  const CReadOnlyMonitorTimeType& MonitorTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByObject of CEventEntity while run level < 0");
	}
	///如果原来正在查询，就不能再次开始查询了，给出警告错误
	if (pLastFoundInSearchByObject!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByObject();
	}

	///记录所有的查询值
	queryMonitorObjectInSearchByObject= MonitorObject.getValue();
	queryEventNameInSearchByObject= EventName.getValue();
	queryMonitorTimeInSearchByObject= MonitorTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByObjectForEventEntity++;
#endif
	///根据参数和缺省值，设置用于比较的对象的各个分量
	CEventEntity *theEventEntity;
	compareObject.MonitorObject=MonitorObject.getValue();
	compareObject.EventName=EventName.getValue();
	compareObject.MonitorTime=MonitorTime.getValue();
	
	///在索引中寻找第一个满足条件的
	pLastFoundInSearchByObject=pKeyObject->searchFirstGreatEqual(&compareObject);
	
	///如果没有找到，则返回
	if (pLastFoundInSearchByObject==NULL)
	{
		return NULL;
	}

	///获取找到的对象
	theEventEntity=(CEventEntity *)(pLastFoundInSearchByObject->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theEventEntity->MonitorObject.getValue(),MonitorObject.getValue()))
	{
		pLastFoundInSearchByObject=NULL;
		return NULL;
	}
	if (compare(theEventEntity->EventName.getValue(),EventName.getValue()))
	{
		pLastFoundInSearchByObject=NULL;
		return NULL;
	}

	///返回找到的结果
	return theEventEntity;
}

CEventEntity *CEventEntityFactory::findNextByObject(void)
{
	///还没有开始查找，或者已经找到最后一个了，就立即返回
	if (pLastFoundInSearchByObject==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByObjectForEventEntity++;
#endif
	CEventEntity *theEventEntity;

	///找下一个节点，如果没有，则查找结束
	pLastFoundInSearchByObject=pKeyObject->getNextNode(pLastFoundInSearchByObject);
	if (pLastFoundInSearchByObject==NULL)
	{
		return NULL;
	}

	theEventEntity=(CEventEntity *)(pLastFoundInSearchByObject->pObject);
	
	///如果有一个条件不满足，则失败返回
	if (compare(theEventEntity->MonitorObject,queryMonitorObjectInSearchByObject))
	{
		pLastFoundInSearchByObject=NULL;
		return NULL;
	}
	if (compare(theEventEntity->EventName,queryEventNameInSearchByObject))
	{
		pLastFoundInSearchByObject=NULL;
		return NULL;
	}

	///返回找到的结果
	return theEventEntity;
}

void CEventEntityFactory::endFindByObject(void)
{
	pLastFoundInSearchByObject=NULL;
}

#ifdef COUNT_SEARCH
void showAllSearchCount(void)
{
	printf("\n");
	if (findByKeyForMonitorEntity !=0)
	{
		printf("\tfindByKeyForMonitorEntity:%d\n",findByKeyForMonitorEntity);
	}
	if (multiFindByTimeForMonitorEntity !=0)
	{
		printf("\tmultiFindByTimeForMonitorEntity:%d\n",multiFindByTimeForMonitorEntity);
	}
	if (findByKey1ForMonitorEntity !=0)
	{
		printf("\tfindByKey1ForMonitorEntity:%d\n",findByKey1ForMonitorEntity);
	}
	if (multiFindByAllForMonitorEntity !=0)
	{
		printf("\tmultiFindByAllForMonitorEntity:%d\n",multiFindByAllForMonitorEntity);
	}
	if (multiFindByKeyForEventEntity !=0)
	{
		printf("\tmultiFindByKeyForEventEntity:%d\n",multiFindByKeyForEventEntity);
	}
	if (multiFindByObjectForEventEntity !=0)
	{
		printf("\tmultiFindByObjectForEventEntity:%d\n",multiFindByObjectForEventEntity);
	}
}

void initAllSearchCount(void)
{
	findByKeyForMonitorEntity=0;
	multiFindByTimeForMonitorEntity=0;
	findByKey1ForMonitorEntity=0;
	multiFindByAllForMonitorEntity=0;
	multiFindByKeyForEventEntity=0;
	multiFindByObjectForEventEntity=0;
}
#endif
