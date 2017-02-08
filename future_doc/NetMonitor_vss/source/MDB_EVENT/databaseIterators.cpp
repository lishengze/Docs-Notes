/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file databaseIterators.cpp
///@briefʵ�������ɸ��ڴ����ݿ��iterator
///@history 
///20060127	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#include "databaseIterators.h"

//#define COUNT_SEARCH

CMemoryStack<CMonitorEntityIteratorByTime> CMonitorEntityIteratorByTime::iteratorList;
void CMonitorEntityIteratorByTime::init(CMonitorEntityFactory *pFactory
		, const CReadOnlyMonitorObjectType& MonitorObject, const CReadOnlyMonitorItemType& MonitorItem, const CReadOnlyMonitorTimeType& MonitorTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CMonitorEntityIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	m_compareObject.init();
	m_compareObject.MonitorObject=MonitorObject.getValue();
	m_compareObject.MonitorItem=MonitorItem.getValue();
	m_compareObject.MonitorTime=MonitorTime.getValue();

}

CMonitorEntityIteratorByTime *CMonitorEntityIteratorByTime::alloc(CMonitorEntityFactory *pFactory
		, const CReadOnlyMonitorObjectType& MonitorObject, const CReadOnlyMonitorItemType& MonitorItem, const CReadOnlyMonitorTimeType& MonitorTime)
{
	CMonitorEntityIteratorByTime *it;
	it=iteratorList.alloc();
	it->init(pFactory,MonitorObject,MonitorItem,MonitorTime);
	return it;
}

CMonitorEntityIteratorByTime::~CMonitorEntityIteratorByTime(void)
{
}

void CMonitorEntityIteratorByTime::free(void)
{
	iteratorList.free(this);
}

void CMonitorEntityIteratorByTime::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CMonitorEntityIteratorByTime");
	
	char buffer[200];
	
	m_compareObject.MonitorObject.getString(buffer);
	pLogger->output(indent+1,0,"query MonitorObject=%s",buffer);
	
	m_compareObject.MonitorItem.getString(buffer);
	pLogger->output(indent+1,0,"query MonitorItem=%s",buffer);
	
	m_compareObject.MonitorTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonitorTime=%s",buffer);
	
}

void CMonitorEntityIteratorByTime::internalGetNext()
{
	if (m_gotNext)
	{
		///�Ѿ�ȡ����һ����
		return;
	}
	if (m_isFirstTime)
	{
		///��һ�ν��룬��������Ѱ�ҵ�һ������������
		m_pNext=m_Factory->pKeyIndex->searchFirstGreatEqual(&m_compareObject);

		///���÷ǵ�һ�α�־
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///�Ѿ��ҵ����һ����
			m_pNext=NULL;
		}
		else
		{
			///����������һ���ڵ�
			m_pNext=m_Factory->pKeyIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CMonitorEntityIteratorByTime::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///��ǰ�ڵ㲻���ڣ�����Ҳ�޷�ɾ��
		return;
	}
	internalGetNext();
	m_Factory->remove((CMonitorEntity *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CMonitorEntityIteratorByTime::UpdateCurrent(CWriteableMonitorEntity * pByTime,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///��ǰ�ڵ㲻���ڣ�����Ҳ�޷��޸�
		return;
	}
	if (updateIndex)
	{
		///Ҫ�����������Ǿͱ���Ԥȡ��һ��
		internalGetNext();
	}
	m_Factory->update((CMonitorEntity *)(m_pCurrent->pObject),pByTime,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByTimeForMonitorEntity;
#endif

CMonitorEntity *CMonitorEntityIteratorByTime::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByTimeForMonitorEntity++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///���û����һ�������ˣ���ʧ�ܷ���
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CMonitorEntity *)(m_pCurrent->pObject)))
	{
		///�����������Ǿͷ�����
		return (CMonitorEntity *)(m_pCurrent->pObject);
	}
	
	///�������������ǾͲ�������
	m_pCurrent=NULL;
	return NULL;
}

int CMonitorEntityIteratorByTime::match(CMonitorEntity *pMonitorEntity)
{
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(pMonitorEntity->MonitorObject.getValue(),m_compareObject.MonitorObject.getValue())!=0)
	{
		return 0;
	}
	if (compare(pMonitorEntity->MonitorItem.getValue(),m_compareObject.MonitorItem.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CMonitorEntityIteratorByAll> CMonitorEntityIteratorByAll::iteratorList;
void CMonitorEntityIteratorByAll::init(CMonitorEntityFactory *pFactory
		)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CMonitorEntityIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	m_compareObject.init();
	m_compareObject.MonitorObject=0;

}

CMonitorEntityIteratorByAll *CMonitorEntityIteratorByAll::alloc(CMonitorEntityFactory *pFactory
		)
{
	CMonitorEntityIteratorByAll *it;
	it=iteratorList.alloc();
	it->init(pFactory);
	return it;
}

CMonitorEntityIteratorByAll::~CMonitorEntityIteratorByAll(void)
{
}

void CMonitorEntityIteratorByAll::free(void)
{
	iteratorList.free(this);
}

void CMonitorEntityIteratorByAll::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CMonitorEntityIteratorByAll");
	
	
}

void CMonitorEntityIteratorByAll::internalGetNext()
{
	if (m_gotNext)
	{
		///�Ѿ�ȡ����һ����
		return;
	}
	if (m_isFirstTime)
	{
		///��һ�ν��룬��������Ѱ�ҵ�һ������������
		m_pNext=m_Factory->pKeyIndex->searchFirstGreatEqual(&m_compareObject);

		///���÷ǵ�һ�α�־
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///�Ѿ��ҵ����һ����
			m_pNext=NULL;
		}
		else
		{
			///����������һ���ڵ�
			m_pNext=m_Factory->pKeyIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CMonitorEntityIteratorByAll::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///��ǰ�ڵ㲻���ڣ�����Ҳ�޷�ɾ��
		return;
	}
	internalGetNext();
	m_Factory->remove((CMonitorEntity *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CMonitorEntityIteratorByAll::UpdateCurrent(CWriteableMonitorEntity * pByAll,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///��ǰ�ڵ㲻���ڣ�����Ҳ�޷��޸�
		return;
	}
	if (updateIndex)
	{
		///Ҫ�����������Ǿͱ���Ԥȡ��һ��
		internalGetNext();
	}
	m_Factory->update((CMonitorEntity *)(m_pCurrent->pObject),pByAll,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByAllForMonitorEntity;
#endif

CMonitorEntity *CMonitorEntityIteratorByAll::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByAllForMonitorEntity++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///���û����һ�������ˣ���ʧ�ܷ���
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CMonitorEntity *)(m_pCurrent->pObject)))
	{
		///�����������Ǿͷ�����
		return (CMonitorEntity *)(m_pCurrent->pObject);
	}
	
	///�������������ǾͲ�������
	m_pCurrent=NULL;
	return NULL;
}

int CMonitorEntityIteratorByAll::match(CMonitorEntity *pMonitorEntity)
{
	///�����һ�����������㣬��ʧ�ܷ���
	return 1;
}


CMemoryStack<CEventEntityIteratorByKey> CEventEntityIteratorByKey::iteratorList;
void CEventEntityIteratorByKey::init(CEventEntityFactory *pFactory
		, const CReadOnlyMonitorItemType& EventName, const CReadOnlyMonitorTimeType& MonitorTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CEventEntityIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	m_compareObject.init();
	m_compareObject.EventName=EventName.getValue();
	m_compareObject.MonitorTime=MonitorTime.getValue();

}

CEventEntityIteratorByKey *CEventEntityIteratorByKey::alloc(CEventEntityFactory *pFactory
		, const CReadOnlyMonitorItemType& EventName, const CReadOnlyMonitorTimeType& MonitorTime)
{
	CEventEntityIteratorByKey *it;
	it=iteratorList.alloc();
	it->init(pFactory,EventName,MonitorTime);
	return it;
}

CEventEntityIteratorByKey::~CEventEntityIteratorByKey(void)
{
}

void CEventEntityIteratorByKey::free(void)
{
	iteratorList.free(this);
}

void CEventEntityIteratorByKey::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CEventEntityIteratorByKey");
	
	char buffer[200];
	
	m_compareObject.EventName.getString(buffer);
	pLogger->output(indent+1,0,"query EventName=%s",buffer);
	
	m_compareObject.MonitorTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonitorTime=%s",buffer);
	
}

void CEventEntityIteratorByKey::internalGetNext()
{
	if (m_gotNext)
	{
		///�Ѿ�ȡ����һ����
		return;
	}
	if (m_isFirstTime)
	{
		///��һ�ν��룬��������Ѱ�ҵ�һ������������
		m_pNext=m_Factory->pKeyIndex->searchFirstGreatEqual(&m_compareObject);

		///���÷ǵ�һ�α�־
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///�Ѿ��ҵ����һ����
			m_pNext=NULL;
		}
		else
		{
			///����������һ���ڵ�
			m_pNext=m_Factory->pKeyIndex->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CEventEntityIteratorByKey::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///��ǰ�ڵ㲻���ڣ�����Ҳ�޷�ɾ��
		return;
	}
	internalGetNext();
	m_Factory->remove((CEventEntity *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CEventEntityIteratorByKey::UpdateCurrent(CWriteableEventEntity * pByKey,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///��ǰ�ڵ㲻���ڣ�����Ҳ�޷��޸�
		return;
	}
	if (updateIndex)
	{
		///Ҫ�����������Ǿͱ���Ԥȡ��һ��
		internalGetNext();
	}
	m_Factory->update((CEventEntity *)(m_pCurrent->pObject),pByKey,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByKeyForEventEntity;
#endif

CEventEntity *CEventEntityIteratorByKey::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByKeyForEventEntity++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///���û����һ�������ˣ���ʧ�ܷ���
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CEventEntity *)(m_pCurrent->pObject)))
	{
		///�����������Ǿͷ�����
		return (CEventEntity *)(m_pCurrent->pObject);
	}
	
	///�������������ǾͲ�������
	m_pCurrent=NULL;
	return NULL;
}

int CEventEntityIteratorByKey::match(CEventEntity *pEventEntity)
{
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(pEventEntity->EventName.getValue(),m_compareObject.EventName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}

CMemoryStack<CEventEntityIteratorByObject> CEventEntityIteratorByObject::iteratorList;
void CEventEntityIteratorByObject::init(CEventEntityFactory *pFactory
		, const CReadOnlyMonitorObjectType& MonitorObject, const CReadOnlyMonitorItemType& EventName, const CReadOnlyMonitorTimeType& MonitorTime)
{
	if (runLevel<0)
	{
		RAISE_RUNTIME_ERROR("Can not use CEventEntityIterator while run level < 0");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	m_compareObject.init();
	m_compareObject.MonitorObject=MonitorObject.getValue();
	m_compareObject.EventName=EventName.getValue();
	m_compareObject.MonitorTime=MonitorTime.getValue();

}

CEventEntityIteratorByObject *CEventEntityIteratorByObject::alloc(CEventEntityFactory *pFactory
		, const CReadOnlyMonitorObjectType& MonitorObject, const CReadOnlyMonitorItemType& EventName, const CReadOnlyMonitorTimeType& MonitorTime)
{
	CEventEntityIteratorByObject *it;
	it=iteratorList.alloc();
	it->init(pFactory,MonitorObject,EventName,MonitorTime);
	return it;
}

CEventEntityIteratorByObject::~CEventEntityIteratorByObject(void)
{
}

void CEventEntityIteratorByObject::free(void)
{
	iteratorList.free(this);
}

void CEventEntityIteratorByObject::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CEventEntityIteratorByObject");
	
	char buffer[200];
	
	m_compareObject.MonitorObject.getString(buffer);
	pLogger->output(indent+1,0,"query MonitorObject=%s",buffer);
	
	m_compareObject.EventName.getString(buffer);
	pLogger->output(indent+1,0,"query EventName=%s",buffer);
	
	m_compareObject.MonitorTime.getString(buffer);
	pLogger->output(indent+1,0,"query MonitorTime=%s",buffer);
	
}

void CEventEntityIteratorByObject::internalGetNext()
{
	if (m_gotNext)
	{
		///�Ѿ�ȡ����һ����
		return;
	}
	if (m_isFirstTime)
	{
		///��һ�ν��룬��������Ѱ�ҵ�һ������������
		m_pNext=m_Factory->pKeyObject->searchFirstGreatEqual(&m_compareObject);

		///���÷ǵ�һ�α�־
		m_isFirstTime=0;
	}
	else
	{
		if (m_pCurrent==NULL)
		{
			///�Ѿ��ҵ����һ����
			m_pNext=NULL;
		}
		else
		{
			///����������һ���ڵ�
			m_pNext=m_Factory->pKeyObject->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
}


void CEventEntityIteratorByObject::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///��ǰ�ڵ㲻���ڣ�����Ҳ�޷�ɾ��
		return;
	}
	internalGetNext();
	m_Factory->remove((CEventEntity *)(m_pCurrent->pObject),pTransaction);
	m_pCurrent=NULL;
}
	

void CEventEntityIteratorByObject::UpdateCurrent(CWriteableEventEntity * pByObject,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///��ǰ�ڵ㲻���ڣ�����Ҳ�޷��޸�
		return;
	}
	if (updateIndex)
	{
		///Ҫ�����������Ǿͱ���Ԥȡ��һ��
		internalGetNext();
	}
	m_Factory->update((CEventEntity *)(m_pCurrent->pObject),pByObject,pTransaction,updateIndex);
}

#ifdef COUNT_SEARCH
extern int multiFindByObjectForEventEntity;
#endif

CEventEntity *CEventEntityIteratorByObject::next(void)
{
#ifdef COUNT_SEARCH
	multiFindByObjectForEventEntity++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///���û����һ�������ˣ���ʧ�ܷ���
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((CEventEntity *)(m_pCurrent->pObject)))
	{
		///�����������Ǿͷ�����
		return (CEventEntity *)(m_pCurrent->pObject);
	}
	
	///�������������ǾͲ�������
	m_pCurrent=NULL;
	return NULL;
}

int CEventEntityIteratorByObject::match(CEventEntity *pEventEntity)
{
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(pEventEntity->MonitorObject.getValue(),m_compareObject.MonitorObject.getValue())!=0)
	{
		return 0;
	}
	if (compare(pEventEntity->EventName.getValue(),m_compareObject.EventName.getValue())!=0)
	{
		return 0;
	}
	return 1;
}


