!!include function.tpl!!
!!enter system!!
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

!!travel tables!!
!!if !strcmp(@hasTable,"yes")!!
!!command resetEntityMap();!!
!!travel fields!!
!!command addEntity(@name,@type)!!
!!next!!	
!!let tableName=@name!!
!!travel search!!
!!if (strcmp(@searchUnique,"yes"))!!
CMemoryStack<C!!@tableName!!Iterator!!@name!!> C!!@tableName!!Iterator!!@name!!::iteratorList;
!!++!!
C!!@tableName!!Iterator!!@name!!::C!!@tableName!!Iterator!!@name!!(C!!@tableName!!Factory *pFactory
		!!travel parameter!!, const !!command getReadOnlyEntityTypeName(@name);!!!!show_string (char *)strResult.c_str()!!& !!@name!!!!next!!)
{
	init(pFactory!!travel parameter!!,!!@name!!!!next!!);
}
!!--!!
!!if valid_name("hashIndexName")!!
	!!let thisHashIndexName=@hashIndexName!!
	!!enter tables!!
		!!enter_expr @tableName!!
			!!enter hashindex!!
				!!enter_expr @thisHashIndexName!!
					!!let thisHashKey=@hashKey!!
				!!leave!!
			!!leave!!
		!!leave!!
	!!leave!!
!!endif!!
void C!!@tableName!!Iterator!!@name!!::init(C!!@tableName!!Factory *pFactory
		!!travel parameter!!, const !!command getReadOnlyEntityTypeName(@name);!!!!show_string (char *)strResult.c_str()!!& !!@name!!!!next!!)
{
	if (runLevel<!!@runLevel!!)
	{
		RAISE_RUNTIME_ERROR("Can not use C!!@tableName!!Iterator while run level < !!@runLevel!!");
	}
	m_Factory=pFactory;
	m_isFirstTime=1;
	m_gotNext=false;
	m_pCurrent=NULL;
	m_pNext=NULL;

	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	m_compareObject.init();
	!!travel parameter!!
	m_compareObject.!!@name!!=!!@name!!.getValue();
	!!next!!
	!!travel default!!
	m_compareObject.!!@name!!=!!@value!!;
	!!next!!

	!!if valid_name("hashIndexName")!!
	m_compareObject.calHash!!@thisHashKey!!();
	!!endif!!
}

C!!@tableName!!Iterator!!@name!! *C!!@tableName!!Iterator!!@name!!::alloc(C!!@tableName!!Factory *pFactory
		!!travel parameter!!, const !!command getReadOnlyEntityTypeName(@name);!!!!show_string (char *)strResult.c_str()!!& !!@name!!!!next!!)
{
	C!!@tableName!!Iterator!!@name!! *it;
	it=iteratorList.alloc();
	it->init(pFactory!!travel parameter!!,!!@name!!!!next!!);
	return it;
}

C!!@tableName!!Iterator!!@name!!::~C!!@tableName!!Iterator!!@name!!(void)
{
	!!if !strcmp(@indexName,"noIndex")!!
	m_Factory->endGet();
	!!endif!!
}

void C!!@tableName!!Iterator!!@name!!::free(void)
{
	!!if (strcmp(@indexName,"noIndex"))!!
	!!elseif valid_name("hashIndexName")!!
	!!else!!
	m_Factory->endGet();
	!!endif!!
	iteratorList.free(this);
}

void C!!@tableName!!Iterator!!@name!!::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"C!!@tableName!!Iterator!!@name!!");
	
	!!if atoi(@parameter.son_size)>0!!
	char buffer[200];
	!!endif!!
	
	!!travel parameter!!
	m_compareObject.!!@name!!.getString(buffer);
	pLogger->output(indent+1,0,"query !!@name!!=%s",buffer);
	
	!!next!!
}

void C!!@tableName!!Iterator!!@name!!::internalGetNext()
{
!!if (strcmp(@indexName,"noIndex"))!!
	if (m_gotNext)
	{
		///�Ѿ�ȡ����һ����
		return;
	}
	if (m_isFirstTime)
	{
		///��һ�ν��룬��������Ѱ�ҵ�һ������������
		m_pNext=m_Factory->p!!@indexName!!->searchFirstGreatEqual(&m_compareObject);

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
			m_pNext=m_Factory->p!!@indexName!!->getNextNode(m_pCurrent);
		}
	}
	m_gotNext=true;
!!elseif valid_name("hashIndexName")!!
	if (m_gotNext)
	{
		///�Ѿ�ȡ����һ����
		return;
	}
	if (m_isFirstTime)
	{
		///��һ�ν��룬��������Ѱ�ҵ�һ������������
		m_pNext=m_Factory->p!!@hashIndexName!!->searchFirstEqual(m_compareObject.Hash!!@thisHashKey!!);

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
			m_pNext=m_Factory->p!!@hashIndexName!!->searchNextEqual(m_pCurrent);
		}
	}
	m_gotNext=true;
!!else
	if (m_gotNext)
	{
		///�Ѿ�ȡ����һ����
		return;
	}
	if (m_isFirstTime)
	{
		///�ҵ���һ������
		m_pNext=(C!!@tableName!! *)(m_Factory->getFirst());
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
			///�ҵ���һ������
			m_pNext=(C!!@tableName!! *)(m_Factory->getNext());
		}
	}
	m_gotNext=true;
!!endif!!
}


void C!!@tableName!!Iterator!!@name!!::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_pCurrent==NULL)
	{
		///��ǰ�ڵ㲻���ڣ�����Ҳ�޷�ɾ��
		return;
	}
	internalGetNext();
!!if (strcmp(@indexName,"noIndex"))!!
	m_Factory->remove((C!!@tableName!! *)(m_pCurrent->pObject),pTransaction);
!!elseif valid_name("hashIndexName")!!
	m_Factory->remove((C!!@tableName!! *)(m_pCurrent->pObject),pTransaction);
!!else!!
	m_Factory->remove(m_pCurrent,pTransaction);
!!endif!!
	m_pCurrent=NULL;
}
	

void C!!@tableName!!Iterator!!@name!!::UpdateCurrent(CWriteable!!@tableName!! * p!!@name!!,CTransaction* pTransaction, bool updateIndex)
{
	if (m_pCurrent==NULL)
	{
		///��ǰ�ڵ㲻���ڣ�����Ҳ�޷��޸�
		return;
	}
!!if (strcmp(@indexName,"noIndex"))!!
	if (updateIndex)
	{
		///Ҫ�����������Ǿͱ���Ԥȡ��һ��
		internalGetNext();
	}
	m_Factory->update((C!!@tableName!! *)(m_pCurrent->pObject),p!!@name!!,pTransaction,updateIndex);
!!elseif valid_name("hashIndexName")!!
	if (updateIndex)
	{
		///Ҫ�����������Ǿͱ���Ԥȡ��һ��
		internalGetNext();
	}
	m_Factory->update((C!!@tableName!! *)(m_pCurrent->pObject),p!!@name!!,pTransaction,updateIndex);
!!else!!
	///��ö��������Ҫ��������������ֱ���޸��޷�
	m_Factory->update(m_pCurrent,p!!@name!!,pTransaction,updateIndex);
!!endif!!
}

#ifdef COUNT_SEARCH
extern int multiFind!!@name!!For!!@tableName!!;
#endif

C!!@tableName!! *C!!@tableName!!Iterator!!@name!!::next(void)
{
!!if (strcmp(@indexName,"noIndex"))!!
#ifdef COUNT_SEARCH
	multiFind!!@name!!For!!@tableName!!++;
#endif
	internalGetNext();
	m_gotNext = false;
	m_pCurrent=m_pNext;

	///���û����һ�������ˣ���ʧ�ܷ���
	if (m_pCurrent==NULL)
	{
		return NULL;
	}		

	if (match((C!!@tableName!! *)(m_pCurrent->pObject)))
	{
		///�����������Ǿͷ�����
		return (C!!@tableName!! *)(m_pCurrent->pObject);
	}
	
	///�������������ǾͲ�������
	m_pCurrent=NULL;
	return NULL;
!!elseif valid_name("hashIndexName")!!
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///���û����һ�������ˣ���ʧ�ܷ���
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match((C!!@tableName!! *)(m_pCurrent->pObject)))
		{
			///�����������Ǿͷ�����
			return (C!!@tableName!! *)(m_pCurrent->pObject);
		}
		///�����ϣ��Ǿ��ٿ���һ��		
	}
!!else!!
	for (;;)
	{
		internalGetNext();
		m_gotNext=false;
		m_pCurrent=m_pNext;

		///���û����һ�������ˣ���ʧ�ܷ���
		if (m_pCurrent==NULL)
		{
			return NULL;
		}
		
		if (match(m_pCurrent))
		{
			///�����������Ǿͷ�����
			return m_pCurrent;
		}
		///�����ϣ��Ǿ��ٿ���һ��		
	}
!!endif!!
}

int C!!@tableName!!Iterator!!@name!!::match(C!!@tableName!! *p!!@tableName!!)
{
	///�����һ�����������㣬��ʧ�ܷ���
!!if valid_name("hashIndexName")!!
	if (p!!@tableName!!->Hash!!@thisHashKey!! != m_compareObject.Hash!!@thisHashKey!!)
	{
		return 0;
	}
!!endif!!
!!travel parameter!!
!!if !strcmp(@checkParameter,"yes")!!
	if (compare(p!!@tableName!!->!!@name!!.getValue(),m_compareObject.!!@name!!.getValue())!=0)
	{
		return 0;
	}
!!endif!!
!!next!!
!!travel default!!
!!if !strcmp(@checkDefault,"yes")!!
	if (compare(p!!@tableName!!->!!@name!!.getValue(),!!@value!!)!=0)
	{
		return 0;
	}
!!endif!!
!!next!!
	return 1;
}

!!endif!!
!!next!!

!!endif!!
!!next!!
!!leave!!
