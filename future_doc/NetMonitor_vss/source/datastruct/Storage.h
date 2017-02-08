// Storage.h: interface for the CStorage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STORAGE_H__FBB3B244_D4CA_4C1A_B235_99EE6DD41B43__INCLUDED_)
#define AFX_STORAGE_H__FBB3B244_D4CA_4C1A_B235_99EE6DD41B43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Index.h"

#define MAX_INDEX_NUM	10

/**
�ڴ��
�ڴ����ݹ���,����һ����������һ�������������������������¼�������������������
�������ݵĶ���ΪCQueue�����������Ķ���ΪCIndex
*/
template<typename T>
class CStorage  
{
public:
	typedef T valuetype;
	typedef T* pointer;
	CStorage(){
		m_nTotalIndex = 0;
	}
	virtual ~CStorage(){
		m_Data.clear();
		for(int i=0;i<m_nTotalIndex;i++){
			delete m_Index[i];
		}
	};

	/** ����ڴ�����м�¼ 
	�����������������
	@param data ��
	@return void
	*/
	void Clear()
	{
		m_Data.clear();
		for(int i=0;i<m_nTotalIndex;i++){
			m_Index[i]->clear();
		}
	}

	/** ���ڴ�������Ӽ�¼ 
	��������������һ����¼�����޸�������
	@param data ��¼����
	@return �����Ӽ�¼��ָ��
	*/
	pointer AppendData(T &data){
		m_Data.push_back(data);
		pointer r=&(m_Data.back());
		for(int i=0;i<m_nTotalIndex;i++){
			m_Index[i]->addObject(r);
		}
		return r;
	}

	/** �����±��ȡ��¼ 
	@param index ��¼�±�
	@return ���±��¼
	*/
	T * Get(int index)
	{
		return &m_Data.at(index);
	}

	/** ���ز�����[],�����±��ȡ��¼ 
	@param ��¼�±�
	@return ���±��¼
	*/
	T & operator [](int index)
	{
		return *Get(index);
	}

	/** ��ȡ��¼���� 
	@param ��
	@return ��¼����
	*/
	int GetCount()
	{
		return m_Data.size();
	}

protected:
	/** �ڴ���������� */
	int m_nTotalIndex;
	/** �ڴ���������飬������ */
	CIndex *m_Index[MAX_INDEX_NUM];
	/** ����ڴ���¼�������� */
	deque<T> m_Data;
};

template <typename T>
int Compare(const T &l,const T &r){
	if(l<r){
		return -1;
	}
	else if(l>r) {
		return 1;
	}
	return 0;
}

#define CREATE_INDEX_1(Field)					\
	m_Index[m_nTotalIndex++] = new CIndex(CompareFuncBy##Field);

#define CREATE_INDEX_2(Field0,Field1)			\
	m_Index[m_nTotalIndex++] = new CIndex(CompareFuncBy##Field0##Field1);

#define CREATE_INDEX_3(Field0,Field1,Field2)	\
	m_Index[m_nTotalIndex++] = new CIndex(CompareFuncBy##Field0##Field1##Field2);

#define DEFINE_INDEX_FUNC_1(Seq,Type,Field)							\
	static int CompareFuncBy##Field(void *p1,void *p2){			\
		return Compare(((pointer)p1)->Field,((pointer)p2)->Field);	\
	}																\
	CIndex *Get##Field##Index(){ return m_Index[Seq];}				\
	pointer GetBy##Field(Type Field){								\
		valuetype _value;											\
		_value.Field=Field;											\
		CIndexNode * _node=Get##Field##Index()->searchFirstEqual(&_value);			\
		if(_node != NULL)											\
			return (pointer)(_node->pObject);						\
		return NULL;												\
	}																\

#define DEFINE_INDEX_FUNC_2(Seq,Type0,Field0,Type1,Field1)			\
	static int CompareFuncBy##Field0##Field1(void *p1,void *p2){	\
		int ret = Compare(((pointer)p1)->Field0,((pointer)p2)->Field0);	\
		if(ret!=0)return ret;										\
		return Compare(((pointer)p1)->Field1,((pointer)p2)->Field1);	\
	}																\
	CIndex *Get##Field0##Field1##Index(){ return m_Index[Seq];}		\
	pointer GetBy##Field0##Field1(Type0 Field0,Type1 Field1){		\
		valuetype _value;											\
		_value.Field0=Field0;										\
		_value.Field1=Field1;										\
		CIndexNode * _node=Get##Field0##Field1##Index()->searchFirstEqual(&_value);	\
		if(_node != NULL)											\
			return (pointer)(_node->pObject);						\
		return NULL;												\
	}																\

#define DEFINE_INDEX_FUNC_3(Seq,Type0,Field0,Type1,Field1,Type2,Field2)		\
	static int CompareFuncBy##Field0##Field1##Field2(void *p1,void *p2){	\
		int ret=Compare(((pointer)p1)->Field0,((pointer)p2)->Field0);	\
		if(ret!=0)return ret;										\
		ret=Compare(((pointer)p1)->Field1,((pointer)p2)->Field1);	\
		if(ret!=0)return ret;										\
		return Compare(((pointer)p1)->Field2,((pointer)p2)->Field2);\
	}																\
	CIndex *Get##Field0##Field1##Field2##Index(){ return m_Index[Seq];}		\
	pointer GetBy##Field0##Field1##Field2(Type0 Field0,Type1 Field1,Type2 Field2){	\
		valuetype _value;											\
		_value.Field0=Field0;										\
		_value.Field1=Field1;										\
		_value.Field2=Field2;										\
		CIndexNode * _node=Get##Field0##Field1##Field2##Index()->searchFirstEqual(&_value);	\
		if(_node != NULL)											\
			return (pointer)(_node->pObject);						\
		return NULL;												\
	}																\


#endif // !defined(AFX_STORAGE_H__FBB3B244_D4CA_4C1A_B235_99EE6DD41B43__INCLUDED_)
