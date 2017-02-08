/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file databaseFactories.h
///@brief���������ɸ��ڴ����ݿ�Ķ��󹤳�
///@history 
///20060127	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef DATABASEFACTORIES_H
#define DATABASEFACTORIES_H

#include "platform.h"
#include "CBaseObject.h"
#include "CConfig.h"
#include "CAVLTree.h"
#include "CHashIndex.h"
#include "customDataType.h"
#include "CDatabaseDataFactory.h"
#include "CTransaction.h"
#include "BaseDataStruct.h"
#include "CDatabaseResource.h"
#include "Allocator.h"

class CMonitorEntityFactory;
class CMonitorEntityResource;
class CEventEntityFactory;
class CEventEntityResource;

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityFactory��һ�����ʵ��Ķ��󹤳�����������һ�����ʵ�壬
///ͬʱ�ֽ����������������Է����ѯ��
///	KeyIndex
///ʹ�ñ����󹤳���������ɶԼ��ʵ�����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByKey��Ψһ�ҵ�����
///		ʹ��startFindByTime��findNextByTime��endFindByTime��ɲ�ѯ����
///		ʹ��findByKey1��Ψһ�ҵ�����
///		ʹ��startFindByAll��findNextByAll��endFindByAll��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMonitorEntityFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxMonitorEntity��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMonitorEntityFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMonitorEntityFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�MonitorEntity
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�MonitorEntity���ļ��������������ļ��еĶ���MonitorEntityCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�MonitorEntity
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�MonitorEntity���ļ��������������ļ��еĶ���MonitorEntityCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CMonitorEntityResource;

	///��һ��CMonitorEntity���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMonitorEntity	Ҫ�����MonitorEntity
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMonitorEntity *add(CWriteableMonitorEntity *pMonitorEntity, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CMonitorEntity��ֵ
	///@param	pMonitorEntity	��ˢ�µ�CMonitorEntity
	///@param	pNewMonitorEntity	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pMonitorEntity	  ��Ҫ��ˢ�»���������CMonitorEntity,����NULL��ʾ����Ҫ������
	///@param	pNewMonitorEntity	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CMonitorEntity* addOrUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CMonitorEntity��ͬʱɾ��������
	///@param	pMonitorEntity	Ҫɾ����CMonitorEntity
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CMonitorEntity *pMonitorEntity, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CMonitorEntity
	///@param	pMonitorEntity	Ҫ��ȡ��CMonitorEntity
	///@param	pTragetMonitorEntity	��Ž����CMonitorEntity
	void retrieve(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pTargetMonitorEntity);
	
	///��ȡ��һ��CMonitorEntity
	///@return	�õ��ĵ�һ��CMonitorEntity�����û�У��򷵻�NULL
	CMonitorEntity *getFirst(void);
	
	///��ȡ��һ��CMonitorEntity
	///@return	�õ���һ��CMonitorEntity�����û�У��򷵻�NULL
	CMonitorEntity *getNext(void);
	
	///������ȡCMonitorEntity
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CMonitorEntityActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CMonitorEntityActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CMonitorEntityCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CMonitorEntityCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CMonitorEntity
	///@param	MonitorObject	��ض���
	///@param	MonitorItem	���ָ����
	///@param	MonitorTime	���ʱ��
	///@return	�ҵ���CMonitorEntity������Ҳ���������NULL
	CMonitorEntity *findByKey( const CReadOnlyMonitorObjectType&  MonitorObject,  const CReadOnlyMonitorItemType&  MonitorItem,  const CReadOnlyMonitorTimeType&  MonitorTime);



	friend class CMonitorEntityIteratorByTime;

	///��ʼѰ��CMonitorEntity
	///@param	MonitorObject	��ض���
	///@param	MonitorItem	���ָ����
	///@param	MonitorTime	���ʱ��
	///@return	���������ĵ�һ��CMonitorEntity������Ҳ���������NULL
	CMonitorEntity *startFindByTime( const CReadOnlyMonitorObjectType& MonitorObject,  const CReadOnlyMonitorItemType& MonitorItem,  const CReadOnlyMonitorTimeType& MonitorTime);

	///Ѱ����һ������������CMonitorEntity��������startFindByTime�Ժ�endFindByTime֮ǰ����
	///@return	��һ����������CMonitorEntity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CMonitorEntity *findNextByTime(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByTime(void);

	///Ѱ��CMonitorEntity
	///@param	MonitorObject	��ض���
	///@param	MonitorItem	���ָ����
	///@return	�ҵ���CMonitorEntity������Ҳ���������NULL
	CMonitorEntity *findByKey1( const CReadOnlyMonitorObjectType&  MonitorObject,  const CReadOnlyMonitorItemType&  MonitorItem);



	friend class CMonitorEntityIteratorByAll;

	///��ʼѰ��CMonitorEntity
	///@return	���������ĵ�һ��CMonitorEntity������Ҳ���������NULL
	CMonitorEntity *startFindByAll();

	///Ѱ����һ������������CMonitorEntity��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CMonitorEntity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CMonitorEntity *findNextByAll(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByAll(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CMonitorEntity���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMonitorEntity	Ҫ�����MonitorEntity
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMonitorEntity *internalAdd(CWriteableMonitorEntity *pMonitorEntity, bool bNoTransaction);
	
	
	///ˢ�¸�CMonitorEntity�ļ�ֵ
	///@param	pMonitorEntity	��ˢ�µ�CMonitorEntity
	///@param	pNewMonitorEntity	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CMonitorEntity��ͬʱɾ��������
	///@param	pMonitorEntity	Ҫɾ����CMonitorEntity
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CMonitorEntity *pMonitorEntity, bool bNoTransaction);
/*
	///���ĳ��CMonitorEntity�Ƿ����ڱ����󹤳�
	///@param	pMonitorEntity	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CMonitorEntity *pMonitorEntity);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����MonitorObject+MonitorItem+MonitorTime������
	CAVLTree *pKeyIndex;
	
	
	///����MonitorObject��MonitorItem��MonitorTime����ʱ���洢�Ĳ�ѯ����
	CMonitorObjectType queryMonitorObjectInSearchByTime;
	CMonitorItemType queryMonitorItemInSearchByTime;
	CMonitorTimeType queryMonitorTimeInSearchByTime;
	
	///����MonitorObject��MonitorItem��MonitorTime����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByTime;
	///���ռ���ʱ���洢�Ĳ�ѯ����
	
	///���ռ���ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByAll;
	
	///����ǰ����
	///@param	pMonitorEntity	Ҫ�����MonitorEntity
	virtual void beforeAdd(CWriteableMonitorEntity *pMonitorEntity);
	
	///����󴥷�
	///@param	pMonitorEntity	�Ѿ������MonitorEntity
	virtual void afterAdd(CMonitorEntity *pMonitorEntity);

	///����ǰ����	
	///@param	pMonitorEntity	��ˢ�µ�CMonitorEntity
	///@param	pNewMonitorEntity	�µ�ֵ
	virtual void beforeUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity);
	
	///���º󴥷�
	///@param	pMonitorEntity	��ˢ�µ�CMonitorEntity
	virtual void afterUpdate(CMonitorEntity *pMonitorEntity);
	
	///ɾ��ǰ����
	///@param	pMonitorEntity	Ҫɾ����CMonitorEntity
	virtual void beforeRemove(CMonitorEntity *pMonitorEntity);
	
	///ȷ�ϼ���󴥷�
	///@param	pMonitorEntity	�Ѿ������MonitorEntity
	virtual void commitAdd(CMonitorEntity *pMonitorEntity);

	///ȷ�ϸ��º󴥷�
	///@param	pMonitorEntity	��ˢ�µ�CMonitorEntity
	///@param	poldMonitorEntity	ԭ����ֵ
	virtual void commitUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pOldMonitorEntity);
	
	///ȷ��ɾ���󴥷�
	///@param	pMonitorEntity	�Ѿ�ɾ����CMonitorEntity
	virtual void commitRemove(CWriteableMonitorEntity *pMonitorEntity);

	///������صĴ�����
	vector<CMonitorEntityActionTrigger *> *pActionTriggers;
	vector<CMonitorEntityCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableMonitorEntity compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityFactory��һ���¼�ʵ��Ķ��󹤳�����������һ���¼�ʵ�壬
///ͬʱ�ֽ����������������Է����ѯ��
///	KeyIndex
///	KeyObject
///ʹ�ñ����󹤳���������ɶ��¼�ʵ�����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindByKey��findNextByKey��endFindByKey��ɲ�ѯ����
///		ʹ��startFindByObject��findNextByObject��endFindByObject��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CEventEntityFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxEventEntity��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CEventEntityFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CEventEntityFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�EventEntity
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�EventEntity���ļ��������������ļ��еĶ���EventEntityCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�EventEntity
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�EventEntity���ļ��������������ļ��еĶ���EventEntityCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CEventEntityResource;

	///��һ��CEventEntity���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pEventEntity	Ҫ�����EventEntity
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CEventEntity *add(CWriteableEventEntity *pEventEntity, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CEventEntity��ֵ
	///@param	pEventEntity	��ˢ�µ�CEventEntity
	///@param	pNewEventEntity	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pEventEntity	  ��Ҫ��ˢ�»���������CEventEntity,����NULL��ʾ����Ҫ������
	///@param	pNewEventEntity	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CEventEntity* addOrUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CEventEntity��ͬʱɾ��������
	///@param	pEventEntity	Ҫɾ����CEventEntity
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CEventEntity *pEventEntity, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CEventEntity
	///@param	pEventEntity	Ҫ��ȡ��CEventEntity
	///@param	pTragetEventEntity	��Ž����CEventEntity
	void retrieve(CEventEntity *pEventEntity, CWriteableEventEntity *pTargetEventEntity);
	
	///��ȡ��һ��CEventEntity
	///@return	�õ��ĵ�һ��CEventEntity�����û�У��򷵻�NULL
	CEventEntity *getFirst(void);
	
	///��ȡ��һ��CEventEntity
	///@return	�õ���һ��CEventEntity�����û�У��򷵻�NULL
	CEventEntity *getNext(void);
	
	///������ȡCEventEntity
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CEventEntityActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CEventEntityActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CEventEntityCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CEventEntityCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CEventEntityIteratorByKey;

	///��ʼѰ��CEventEntity
	///@param	EventName	�¼���
	///@param	MonitorTime	���ʱ��
	///@return	���������ĵ�һ��CEventEntity������Ҳ���������NULL
	CEventEntity *startFindByKey( const CReadOnlyMonitorItemType& EventName,  const CReadOnlyMonitorTimeType& MonitorTime);

	///Ѱ����һ������������CEventEntity��������startFindByKey�Ժ�endFindByKey֮ǰ����
	///@return	��һ����������CEventEntity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CEventEntity *findNextByKey(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByKey(void);

	friend class CEventEntityIteratorByObject;

	///��ʼѰ��CEventEntity
	///@param	MonitorObject	������
	///@param	EventName	�¼���
	///@param	MonitorTime	���ʱ��
	///@return	���������ĵ�һ��CEventEntity������Ҳ���������NULL
	CEventEntity *startFindByObject( const CReadOnlyMonitorObjectType& MonitorObject,  const CReadOnlyMonitorItemType& EventName,  const CReadOnlyMonitorTimeType& MonitorTime);

	///Ѱ����һ������������CEventEntity��������startFindByObject�Ժ�endFindByObject֮ǰ����
	///@return	��һ����������CEventEntity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CEventEntity *findNextByObject(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByObject(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CEventEntity���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pEventEntity	Ҫ�����EventEntity
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CEventEntity *internalAdd(CWriteableEventEntity *pEventEntity, bool bNoTransaction);
	
	
	///ˢ�¸�CEventEntity�ļ�ֵ
	///@param	pEventEntity	��ˢ�µ�CEventEntity
	///@param	pNewEventEntity	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CEventEntity��ͬʱɾ��������
	///@param	pEventEntity	Ҫɾ����CEventEntity
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CEventEntity *pEventEntity, bool bNoTransaction);
/*
	///���ĳ��CEventEntity�Ƿ����ڱ����󹤳�
	///@param	pEventEntity	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CEventEntity *pEventEntity);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����EventName+MonitorTime������
	CAVLTree *pKeyIndex;
	///����MonitorObject+EventName+MonitorTime������
	CAVLTree *pKeyObject;
	
	
	///����EventName��MonitorTime����ʱ���洢�Ĳ�ѯ����
	CMonitorItemType queryEventNameInSearchByKey;
	CMonitorTimeType queryMonitorTimeInSearchByKey;
	
	///����EventName��MonitorTime����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByKey;
	///����MonitorObject��EventName��MonitorTime����ʱ���洢�Ĳ�ѯ����
	CMonitorObjectType queryMonitorObjectInSearchByObject;
	CMonitorItemType queryEventNameInSearchByObject;
	CMonitorTimeType queryMonitorTimeInSearchByObject;
	
	///����MonitorObject��EventName��MonitorTime����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByObject;
	
	///����ǰ����
	///@param	pEventEntity	Ҫ�����EventEntity
	virtual void beforeAdd(CWriteableEventEntity *pEventEntity);
	
	///����󴥷�
	///@param	pEventEntity	�Ѿ������EventEntity
	virtual void afterAdd(CEventEntity *pEventEntity);

	///����ǰ����	
	///@param	pEventEntity	��ˢ�µ�CEventEntity
	///@param	pNewEventEntity	�µ�ֵ
	virtual void beforeUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity);
	
	///���º󴥷�
	///@param	pEventEntity	��ˢ�µ�CEventEntity
	virtual void afterUpdate(CEventEntity *pEventEntity);
	
	///ɾ��ǰ����
	///@param	pEventEntity	Ҫɾ����CEventEntity
	virtual void beforeRemove(CEventEntity *pEventEntity);
	
	///ȷ�ϼ���󴥷�
	///@param	pEventEntity	�Ѿ������EventEntity
	virtual void commitAdd(CEventEntity *pEventEntity);

	///ȷ�ϸ��º󴥷�
	///@param	pEventEntity	��ˢ�µ�CEventEntity
	///@param	poldEventEntity	ԭ����ֵ
	virtual void commitUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pOldEventEntity);
	
	///ȷ��ɾ���󴥷�
	///@param	pEventEntity	�Ѿ�ɾ����CEventEntity
	virtual void commitRemove(CWriteableEventEntity *pEventEntity);

	///������صĴ�����
	vector<CEventEntityActionTrigger *> *pActionTriggers;
	vector<CEventEntityCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableEventEntity compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

#endif
