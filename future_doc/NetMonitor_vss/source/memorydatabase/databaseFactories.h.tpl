!!include function.tpl!!
!!enter system!!
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

!!travel tables!!
class C!!@name!!Factory;
class C!!@name!!Resource;
!!next!!

!!travel tables!!
!!if !strcmp(@hasTable,"yes")!!
!!command resetEntityMap();!!
!!travel fields!!
!!command addEntity(@name,@type)!!
!!next!!
!!let tableName=@name!!
/////////////////////////////////////////////////////////////////////////
///C!!@name!!Factory��һ��!!@usage!!�Ķ��󹤳�����������һ��!!@usage!!��
///ͬʱ�ֽ����������������Է����ѯ��
!!travel index!!
///	!!@name!!
!!next!!
///ʹ�ñ����󹤳���������ɶ�!!@usage!!����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
!!travel search!!
!!if (!strcmp(@searchUnique,"yes"))!!
///		ʹ��find!!@name!!��Ψһ�ҵ�����
!!else!!
///		ʹ��startFind!!@name!!��findNext!!@name!!��endFind!!@name!!��ɲ�ѯ����
!!endif!!
!!next!!
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	!!@author!!
///@version	!!@version!!
/////////////////////////////////////////////////////////////////////////
class C!!@name!!Factory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	C!!@name!!Factory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���Max!!@name!!��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	C!!@name!!Factory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~C!!@name!!Factory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�!!@name!!
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�!!@name!!���ļ��������������ļ��еĶ���!!@name!!CSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�!!@name!!
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�!!@name!!���ļ��������������ļ��еĶ���!!@name!!CSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class C!!@name!!Resource;

	///��һ��C!!@name!!���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	p!!@name!!	Ҫ�����!!@name!!
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	C!!@name!! *add(CWriteable!!@name!! *p!!@name!!, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�C!!@name!!��ֵ
	///@param	p!!@name!!	��ˢ�µ�C!!@name!!
	///@param	pNew!!@name!!	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(C!!@name!! *p!!@name!!, CWriteable!!@name!! *pNew!!@name!!, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	p!!@name!!	  ��Ҫ��ˢ�»���������C!!@name!!,����NULL��ʾ����Ҫ������
	///@param	pNew!!@name!!	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	C!!@name!!* addOrUpdate(C!!@name!! *p!!@name!!, CWriteable!!@name!! *pNew!!@name!!, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��C!!@name!!��ͬʱɾ��������
	///@param	p!!@name!!	Ҫɾ����C!!@name!!
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(C!!@name!! *p!!@name!!, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��C!!@name!!
	///@param	p!!@name!!	Ҫ��ȡ��C!!@name!!
	///@param	pTraget!!@name!!	��Ž����C!!@name!!
	void retrieve(C!!@name!! *p!!@name!!, CWriteable!!@name!! *pTarget!!@name!!);
	
	///��ȡ��һ��C!!@name!!
	///@return	�õ��ĵ�һ��C!!@name!!�����û�У��򷵻�NULL
	C!!@name!! *getFirst(void);
	
	///��ȡ��һ��C!!@name!!
	///@return	�õ���һ��C!!@name!!�����û�У��򷵻�NULL
	C!!@name!! *getNext(void);
	
	///������ȡC!!@name!!
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(C!!@name!!ActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(C!!@name!!ActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(C!!@name!!CommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(C!!@name!!CommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

!!travel foreigns!!
	///��������!!@comment!!��ָ��
	///@param	pFactory	����!!@comment!!��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	!!if (!strcmp(@foreignStrick,"yes"))!!
	///@exception	����Ҳ��������׳�RUNTIME_ERROR
	!!endif!!
	void linkAll!!@name!!(C!!@factory!!Factory *pFactory);
	
!!next!!
	!!let tableName=@name!!
!!travel search!!
!!if (!strcmp(@searchUnique,"yes"))!!
	///Ѱ��C!!@tableName!!
	!!travel parameter!!
	///@param	!!@name!!	!!@desc!!
	!!next!!
	///@return	�ҵ���C!!@tableName!!������Ҳ���������NULL
	C!!@tableName!! *find!!@name!!(!!travel parameter!!!!if (@pumpid!=0)!!, !!endif!! const !!command getReadOnlyEntityTypeName(@name);!!!!show_string (char *)strResult.c_str()!!&  !!@name!!!!next!!);

	!!if !strcmp(@isPK,"yes")!!
	///��������Ѱ��
	!!travel parameter!!
	///@param	!!@name!!	!!@desc!!
	!!next!!
	///@return	�ҵ���C!!@tableName!!������Ҳ���������NULL
	C!!@tableName!! *findByPK(!!travel parameter!!!!if (@pumpid!=0)!!, !!endif!! const !!command getReadOnlyEntityTypeName(@name);!!!!show_string (char *)strResult.c_str()!!&  !!@name!!!!next!!);
	
	///��������Ѱ��C!!@tableName!!
	///@param	p!!@tableName!!	Ҫ�ҵ�ֵ
	///@return	�ҵ���C!!@tableName!!������Ҳ���������NULL
	C!!@tableName!! *findByPK(CWriteable!!@tableName!! *p!!@tableName!!);

	///����������ȡC!!@tableName!!
	///@param	p!!@tableName!!	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���C!!@tableName!!������Ҳ���������NULL
	bool retrieveByPK(CWriteable!!@tableName!! *p!!@tableName!!);

	///�������������µ�C!!@tableName!!
	///@param	p!!@tableName!!	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����C!!@tableName!!���������ʧ�ܣ��򷵻�NULL
	C!!@tableName!! *addByPK(CWriteable!!@tableName!! *p!!@tableName!!, CTransaction *pTransaction=NULL);

	///������������C!!@tableName!!��ֵ
	///@param	p!!@tableName!!	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteable!!@tableName!! *p!!@tableName!!, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��C!!@tableName!!
	///@param	p!!@tableName!!	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteable!!@tableName!! *p!!@tableName!!, CTransaction *pTransaction=NULL);
	!!endif!!

!!else!!
	friend class C!!@tableName!!Iterator!!@name!!;

	///��ʼѰ��C!!@tableName!!
	!!travel parameter!!
	///@param	!!@name!!	!!@desc!!
	!!next!!
	///@return	���������ĵ�һ��C!!@tableName!!������Ҳ���������NULL
	C!!@tableName!! *startFind!!@name!!(!!travel parameter!!!!if (@pumpid!=0)!!, !!endif!! const !!command getReadOnlyEntityTypeName(@name);!!!!show_string (char *)strResult.c_str()!!& !!@name!!!!next!!);

	///Ѱ����һ������������C!!@tableName!!��������startFind!!@name!!�Ժ�endFind!!@name!!֮ǰ����
	///@return	��һ����������C!!@tableName!!������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	C!!@tableName!! *findNext!!@name!!(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFind!!@name!!(void);
	!!endif!!

!!next!!
private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��C!!@name!!���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	p!!@name!!	Ҫ�����!!@name!!
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	C!!@name!! *internalAdd(CWriteable!!@name!! *p!!@name!!, bool bNoTransaction);
	
	
	///ˢ�¸�C!!@name!!�ļ�ֵ
	///@param	p!!@name!!	��ˢ�µ�C!!@name!!
	///@param	pNew!!@name!!	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(C!!@name!! *p!!@name!!, CWriteable!!@name!! *pNew!!@name!!, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��C!!@name!!��ͬʱɾ��������
	///@param	p!!@name!!	Ҫɾ����C!!@name!!
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(C!!@name!! *p!!@name!!, bool bNoTransaction);
/*
	///���ĳ��C!!@name!!�Ƿ����ڱ����󹤳�
	///@param	p!!@name!!	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(C!!@name!! *p!!@name!!);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	!!travel index!!
	///����!!travel self!!!!if @pumpid!=0!!+!!endif!!!!@name!!!!next!!������
	CAVLTree *p!!@name!!;
	!!next!!
	
	!!if valid_name("hashindex")!!
	!!travel hashindex!!
	///����!!@hashKey!!��hash����
	CHashIndex *p!!@name!!;
	!!next!!
	!!endif!!
	
	!!travel search!!
	!!if (strcmp(@searchUnique,"yes"))!!
	///����!!travel parameter!!!!if @pumpid!=0!!��!!endif!!!!@name!!!!next!!����ʱ���洢�Ĳ�ѯ����
	!!let searchName=@name!!
	!!travel parameter!!
	!!show_string getEntityTypeName(@name)!! query!!@name!!InSearch!!@searchName!!;
	!!next!!
	
	///����!!travel parameter!!!!if @pumpid!=0!!��!!endif!!!!@name!!!!next!!����ʱ���洢���һ���ҵ��������ڵ�
	!!if (strcmp(@indexName,"noIndex"))!!
	CAVLNode *pLastFoundInSearch!!@name!!;
	!!elseif valid_name("hashIndexName")!!
	CHashIndexNode *pLastFoundInSearch!!@name!!;
	!!else!!
	C!!@tableName!! *pLastFoundInSearch!!@name!!;
	!!endif!!
	!!endif!!
	!!next!!
	
	///����ǰ����
	///@param	p!!@name!!	Ҫ�����!!@name!!
	virtual void beforeAdd(CWriteable!!@name!! *p!!@name!!);
	
	///����󴥷�
	///@param	p!!@name!!	�Ѿ������!!@name!!
	virtual void afterAdd(C!!@name!! *p!!@name!!);

	///����ǰ����	
	///@param	p!!@name!!	��ˢ�µ�C!!@name!!
	///@param	pNew!!@name!!	�µ�ֵ
	virtual void beforeUpdate(C!!@name!! *p!!@name!!, CWriteable!!@name!! *pNew!!@name!!);
	
	///���º󴥷�
	///@param	p!!@name!!	��ˢ�µ�C!!@name!!
	virtual void afterUpdate(C!!@name!! *p!!@name!!);
	
	///ɾ��ǰ����
	///@param	p!!@name!!	Ҫɾ����C!!@name!!
	virtual void beforeRemove(C!!@name!! *p!!@name!!);
	
	///ȷ�ϼ���󴥷�
	///@param	p!!@name!!	�Ѿ������!!@name!!
	virtual void commitAdd(C!!@name!! *p!!@name!!);

	///ȷ�ϸ��º󴥷�
	///@param	p!!@name!!	��ˢ�µ�C!!@name!!
	///@param	pold!!@name!!	ԭ����ֵ
	virtual void commitUpdate(C!!@name!! *p!!@name!!, CWriteable!!@name!! *pOld!!@name!!);
	
	///ȷ��ɾ���󴥷�
	///@param	p!!@name!!	�Ѿ�ɾ����C!!@name!!
	virtual void commitRemove(CWriteable!!@name!! *p!!@name!!);

	///������صĴ�����
	vector<C!!@name!!ActionTrigger *> *pActionTriggers;
	vector<C!!@name!!CommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteable!!@name!! compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

!!endif!!
!!next!!
#endif
!!leave!!
