/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file databaseFactories.pp
///@briefʵ�������ɸ��ڴ����ݿ�Ķ��󹤳�
///@history 
///20060127	���ض�		�������ļ�
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
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTime();
	}

	///��¼���еĲ�ѯֵ
	queryMonitorObjectInSearchByTime= MonitorObject.getValue();
	queryMonitorItemInSearchByTime= MonitorItem.getValue();
	queryMonitorTimeInSearchByTime= MonitorTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByTimeForMonitorEntity++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CMonitorEntity *theMonitorEntity;
	compareObject.MonitorObject=MonitorObject.getValue();
	compareObject.MonitorItem=MonitorItem.getValue();
	compareObject.MonitorTime=MonitorTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByTime=pKeyIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theMonitorEntity=(CMonitorEntity *)(pLastFoundInSearchByTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
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

	///�����ҵ��Ľ��
	return theMonitorEntity;
}

CMonitorEntity *CMonitorEntityFactory::findNextByTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTimeForMonitorEntity++;
#endif
	CMonitorEntity *theMonitorEntity;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByTime=pKeyIndex->getNextNode(pLastFoundInSearchByTime);
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	theMonitorEntity=(CMonitorEntity *)(pLastFoundInSearchByTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
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

	///�����ҵ��Ľ��
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
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForMonitorEntity++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CMonitorEntity *theMonitorEntity;
	compareObject.MonitorObject=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pKeyIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theMonitorEntity=(CMonitorEntity *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theMonitorEntity;
}

CMonitorEntity *CMonitorEntityFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForMonitorEntity++;
#endif
	CMonitorEntity *theMonitorEntity;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pKeyIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theMonitorEntity=(CMonitorEntity *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
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
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByKey!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByKey();
	}

	///��¼���еĲ�ѯֵ
	queryEventNameInSearchByKey= EventName.getValue();
	queryMonitorTimeInSearchByKey= MonitorTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByKeyForEventEntity++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CEventEntity *theEventEntity;
	compareObject.EventName=EventName.getValue();
	compareObject.MonitorTime=MonitorTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByKey=pKeyIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByKey==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theEventEntity=(CEventEntity *)(pLastFoundInSearchByKey->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theEventEntity->EventName.getValue(),EventName.getValue()))
	{
		pLastFoundInSearchByKey=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theEventEntity;
}

CEventEntity *CEventEntityFactory::findNextByKey(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByKey==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByKeyForEventEntity++;
#endif
	CEventEntity *theEventEntity;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByKey=pKeyIndex->getNextNode(pLastFoundInSearchByKey);
	if (pLastFoundInSearchByKey==NULL)
	{
		return NULL;
	}

	theEventEntity=(CEventEntity *)(pLastFoundInSearchByKey->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theEventEntity->EventName,queryEventNameInSearchByKey))
	{
		pLastFoundInSearchByKey=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
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
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByObject!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByObject();
	}

	///��¼���еĲ�ѯֵ
	queryMonitorObjectInSearchByObject= MonitorObject.getValue();
	queryEventNameInSearchByObject= EventName.getValue();
	queryMonitorTimeInSearchByObject= MonitorTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByObjectForEventEntity++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CEventEntity *theEventEntity;
	compareObject.MonitorObject=MonitorObject.getValue();
	compareObject.EventName=EventName.getValue();
	compareObject.MonitorTime=MonitorTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByObject=pKeyObject->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByObject==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theEventEntity=(CEventEntity *)(pLastFoundInSearchByObject->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
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

	///�����ҵ��Ľ��
	return theEventEntity;
}

CEventEntity *CEventEntityFactory::findNextByObject(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByObject==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByObjectForEventEntity++;
#endif
	CEventEntity *theEventEntity;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByObject=pKeyObject->getNextNode(pLastFoundInSearchByObject);
	if (pLastFoundInSearchByObject==NULL)
	{
		return NULL;
	}

	theEventEntity=(CEventEntity *)(pLastFoundInSearchByObject->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
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

	///�����ҵ��Ľ��
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
