!!include function.tpl!!
!!enter system!!
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

!!travel tables!!
!!if !strcmp(@hasTable,"yes")!!
!!command resetEntityMap();!!
!!travel fields!!
!!command addEntity(@name,@type)!!
!!next!!
!!let tableName=@name!!
!!travel search!!
!!if (strcmp(@searchUnique,"yes"))!!
/////////////////////////////////////////////////////////////////////////
///C!!@tableName!!Iterator!!@name!!��һ����!!@usage!!ʹ��!!@name!!��������
///���ҵ�ö����
///@author	!!@author!!
///@version	!!@version!!
/////////////////////////////////////////////////////////////////////////
class C!!@tableName!!Iterator!!@name!!: public C!!@tableName!!Iterator
{
	friend class C!!@tableName!!Factory;
private:
	///���˶����Ƿ���������
	///@param	p!!@tableName!!		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(C!!@tableName!! *p!!@tableName!!);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

!!if (strcmp(@indexName,"noIndex"))!!
	///�洢���һ���ҵ��������ڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CAVLNode *m_pCurrent;

	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ��Ӧ�������ڵ㣬���������������
	CAVLNode *m_pNext;
!!elseif valid_name("hashIndexName")!!
	///�洢���һ���ҵ��������ڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CHashIndexNode *m_pCurrent;

	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ��Ӧ�������ڵ㣬���������������
	CHashIndexNode *m_pNext;
!!else!!
	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	C!!@tableName!! *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	C!!@tableName!! *m_pNext;
!!endif!!

	///���ڴ洢��ѯ�����Ķ���
	CWriteable!!@tableName!! m_compareObject;
	
	static CMemoryStack<C!!@tableName!!Iterator!!@name!!> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	!!travel parameter!!
	///@param	!!@name!!	!!@desc!!
	!!next!!
	C!!@tableName!!Iterator!!@name!!(C!!@tableName!!Factory *pFactory
		!!travel parameter!!,const !!command getReadOnlyEntityTypeName(@name);!!!!show_string (char *)strResult.c_str()!!& !!@name!!!!next!!)
	{
		init(pFactory!!travel parameter!!,!!@name!!!!next!!);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	!!travel parameter!!
	///@param	!!@name!!	!!@desc!!
	!!next!!
	static C!!@tableName!!Iterator!!@name!! *alloc(C!!@tableName!!Factory *pFactory
		!!travel parameter!!,const !!command getReadOnlyEntityTypeName(@name);!!!!show_string (char *)strResult.c_str()!!& !!@name!!!!next!!);

	///���췽��
	C!!@tableName!!Iterator!!@name!!(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	!!travel parameter!!
	///@param	!!@name!!	!!@desc!!
	!!next!!
	void init(C!!@tableName!!Factory *pFactory
		!!travel parameter!!,const !!command getReadOnlyEntityTypeName(@name);!!!!show_string (char *)strResult.c_str()!!& !!@name!!!!next!!);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~C!!@tableName!!Iterator!!@name!!(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������C!!@tableName!!��������startFind!!@name!!�Ժ�endFind!!@name!!֮ǰ����
	///@return	��һ����������C!!@tableName!!������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual C!!@tableName!! *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	p!!@name!! ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteable!!@tableName!! * p!!@name!!,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
!!endif!!
!!next!!

!!endif!!
!!next!!
#endif
!!leave!!
