/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file databaseIterators.h
///@brief���������ɸ��ڴ����ݿ��iterator
///@history 
///20060127	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef DATABASEITERATORS_H
#define DATABASEITERATORS_H

#include "BaseDataStruct.h"
#include "databaseFactories.h"
#include "MemoryStack.h"

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityIteratorByTime��һ���Լ��ʵ��ʹ��ByTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityIteratorByTime: public CMonitorEntityIterator
{
	friend class CMonitorEntityFactory;
private:
	///���˶����Ƿ���������
	///@param	pMonitorEntity		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CMonitorEntity *pMonitorEntity);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��������ڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CAVLNode *m_pCurrent;

	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ��Ӧ�������ڵ㣬���������������
	CAVLNode *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableMonitorEntity m_compareObject;
	
	static CMemoryStack<CMonitorEntityIteratorByTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonitorObject	��ض���
	///@param	MonitorItem	���ָ����
	///@param	MonitorTime	���ʱ��
	CMonitorEntityIteratorByTime(CMonitorEntityFactory *pFactory
		,const CReadOnlyMonitorObjectType& MonitorObject,const CReadOnlyMonitorItemType& MonitorItem,const CReadOnlyMonitorTimeType& MonitorTime)
	{
		init(pFactory,MonitorObject,MonitorItem,MonitorTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonitorObject	��ض���
	///@param	MonitorItem	���ָ����
	///@param	MonitorTime	���ʱ��
	static CMonitorEntityIteratorByTime *alloc(CMonitorEntityFactory *pFactory
		,const CReadOnlyMonitorObjectType& MonitorObject,const CReadOnlyMonitorItemType& MonitorItem,const CReadOnlyMonitorTimeType& MonitorTime);

	///���췽��
	CMonitorEntityIteratorByTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonitorObject	��ض���
	///@param	MonitorItem	���ָ����
	///@param	MonitorTime	���ʱ��
	void init(CMonitorEntityFactory *pFactory
		,const CReadOnlyMonitorObjectType& MonitorObject,const CReadOnlyMonitorItemType& MonitorItem,const CReadOnlyMonitorTimeType& MonitorTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMonitorEntityIteratorByTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CMonitorEntity��������startFindByTime�Ժ�endFindByTime֮ǰ����
	///@return	��һ����������CMonitorEntity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMonitorEntity *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMonitorEntity * pByTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CMonitorEntityIteratorByAll��һ���Լ��ʵ��ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityIteratorByAll: public CMonitorEntityIterator
{
	friend class CMonitorEntityFactory;
private:
	///���˶����Ƿ���������
	///@param	pMonitorEntity		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CMonitorEntity *pMonitorEntity);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��������ڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CAVLNode *m_pCurrent;

	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ��Ӧ�������ڵ㣬���������������
	CAVLNode *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableMonitorEntity m_compareObject;
	
	static CMemoryStack<CMonitorEntityIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CMonitorEntityIteratorByAll(CMonitorEntityFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CMonitorEntityIteratorByAll *alloc(CMonitorEntityFactory *pFactory
		);

	///���췽��
	CMonitorEntityIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CMonitorEntityFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMonitorEntityIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CMonitorEntity��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CMonitorEntity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMonitorEntity *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMonitorEntity * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityIteratorByKey��һ�����¼�ʵ��ʹ��ByKey��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityIteratorByKey: public CEventEntityIterator
{
	friend class CEventEntityFactory;
private:
	///���˶����Ƿ���������
	///@param	pEventEntity		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CEventEntity *pEventEntity);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��������ڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CAVLNode *m_pCurrent;

	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ��Ӧ�������ڵ㣬���������������
	CAVLNode *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableEventEntity m_compareObject;
	
	static CMemoryStack<CEventEntityIteratorByKey> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	EventName	�¼���
	///@param	MonitorTime	���ʱ��
	CEventEntityIteratorByKey(CEventEntityFactory *pFactory
		,const CReadOnlyMonitorItemType& EventName,const CReadOnlyMonitorTimeType& MonitorTime)
	{
		init(pFactory,EventName,MonitorTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	EventName	�¼���
	///@param	MonitorTime	���ʱ��
	static CEventEntityIteratorByKey *alloc(CEventEntityFactory *pFactory
		,const CReadOnlyMonitorItemType& EventName,const CReadOnlyMonitorTimeType& MonitorTime);

	///���췽��
	CEventEntityIteratorByKey(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	EventName	�¼���
	///@param	MonitorTime	���ʱ��
	void init(CEventEntityFactory *pFactory
		,const CReadOnlyMonitorItemType& EventName,const CReadOnlyMonitorTimeType& MonitorTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CEventEntityIteratorByKey(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CEventEntity��������startFindByKey�Ժ�endFindByKey֮ǰ����
	///@return	��һ����������CEventEntity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CEventEntity *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByKey ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableEventEntity * pByKey,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CEventEntityIteratorByObject��һ�����¼�ʵ��ʹ��ByObject��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityIteratorByObject: public CEventEntityIterator
{
	friend class CEventEntityFactory;
private:
	///���˶����Ƿ���������
	///@param	pEventEntity		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CEventEntity *pEventEntity);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��������ڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CAVLNode *m_pCurrent;

	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ��Ӧ�������ڵ㣬���������������
	CAVLNode *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableEventEntity m_compareObject;
	
	static CMemoryStack<CEventEntityIteratorByObject> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonitorObject	������
	///@param	EventName	�¼���
	///@param	MonitorTime	���ʱ��
	CEventEntityIteratorByObject(CEventEntityFactory *pFactory
		,const CReadOnlyMonitorObjectType& MonitorObject,const CReadOnlyMonitorItemType& EventName,const CReadOnlyMonitorTimeType& MonitorTime)
	{
		init(pFactory,MonitorObject,EventName,MonitorTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonitorObject	������
	///@param	EventName	�¼���
	///@param	MonitorTime	���ʱ��
	static CEventEntityIteratorByObject *alloc(CEventEntityFactory *pFactory
		,const CReadOnlyMonitorObjectType& MonitorObject,const CReadOnlyMonitorItemType& EventName,const CReadOnlyMonitorTimeType& MonitorTime);

	///���췽��
	CEventEntityIteratorByObject(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonitorObject	������
	///@param	EventName	�¼���
	///@param	MonitorTime	���ʱ��
	void init(CEventEntityFactory *pFactory
		,const CReadOnlyMonitorObjectType& MonitorObject,const CReadOnlyMonitorItemType& EventName,const CReadOnlyMonitorTimeType& MonitorTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CEventEntityIteratorByObject(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CEventEntity��������startFindByObject�Ժ�endFindByObject֮ǰ����
	///@return	��һ����������CEventEntity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CEventEntity *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByObject ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableEventEntity * pByObject,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

#endif
