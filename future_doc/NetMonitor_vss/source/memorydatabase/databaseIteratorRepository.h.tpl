!!enter system!!
/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file databaseIteratorRepository.h
///@brief	���������ɸ��ڴ����ݿ��iterator�⣬�Ա���ֲ�ѯ
///@history 
///20061222	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef DATABASEITERATORREPOSITORY_H
#define DATABASEITERATORREPOSITORY_H

#include "BaseDataStruct.h"
#include "databaseFactories.h"

!!travel tables!!
!!if !strcmp(@hasTable,"yes")!!
!!let tableName=@name!!
/////////////////////////////////////////////////////////////////////////
///C!!@tableName!!SingleIterator�����෵��һ��!!@usage!!��ö����
///@author	!!@author!!
///@version	!!@version!!
/////////////////////////////////////////////////////////////////////////
class C!!@tableName!!SingleIterator: public C!!@tableName!!Iterator
{
private:
	C!!@tableName!! *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	C!!@tableName!!SingleIterator(C!!@tableName!!Factory *pFactory,C!!@tableName!! *pResult)
		:C!!@tableName!!Iterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~C!!@tableName!!SingleIterator(void)
	{
	}

	///Ѱ����һ������������C!!@tableName!!
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

/////////////////////////////////////////////////////////////////////////
///C!!@tableName!!Predict���ж�һ��!!@usage!!�Ƿ����������ν��
///@author	!!@author!!
///@version	!!@version!!
/////////////////////////////////////////////////////////////////////////
class C!!@tableName!!Predict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	p!!@tableName!!	Ҫ���жϵ�!!@usage!!
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(C!!@tableName!! *p!!@tableName!!)=0;
};

/////////////////////////////////////////////////////////////////////////
///C!!@tableName!!AndPredict�Ƕ�����!!@usage!!ν�ʵ���ν��
///@author	!!@author!!
///@version	!!@version!!
/////////////////////////////////////////////////////////////////////////
class C!!@tableName!!AndPredict : public C!!@tableName!!Predict
{
private:
	C!!@tableName!!Predict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	C!!@tableName!!AndPredict(C!!@tableName!!Predict *p1, C!!@tableName!!Predict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~C!!@tableName!!AndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	p!!@tableName!!	Ҫ���жϵ�!!@usage!!
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(C!!@tableName!! *p!!@tableName!!)
	{
		return m_p1->isValid(p!!@tableName!!) && m_p2->isValid(p!!@tableName!!);
	}
};

/////////////////////////////////////////////////////////////////////////
///C!!@tableName!!OrPredict�Ƕ�����!!@usage!!ν�ʵĻ�ν��
///@author	!!@author!!
///@version	!!@version!!
/////////////////////////////////////////////////////////////////////////
class C!!@tableName!!OrPredict : public C!!@tableName!!Predict
{
private:
	C!!@tableName!!Predict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	C!!@tableName!!OrPredict(C!!@tableName!!Predict *p1, C!!@tableName!!Predict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~C!!@tableName!!OrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	p!!@tableName!!	Ҫ���жϵ�!!@usage!!
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(C!!@tableName!! *p!!@tableName!!)
	{
		return m_p1->isValid(p!!@tableName!!) || m_p2->isValid(p!!@tableName!!);
	}
};

/////////////////////////////////////////////////////////////////////////
///C!!@tableName!!NotPredict�Ƕ�һ��!!@usage!!ν�ʵķ�ν��
///@author	!!@author!!
///@version	!!@version!!
/////////////////////////////////////////////////////////////////////////
class C!!@tableName!!NotPredict : public C!!@tableName!!Predict
{
private:
	C!!@tableName!!Predict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	C!!@tableName!!NotPredict(C!!@tableName!!Predict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~C!!@tableName!!NotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	p!!@tableName!!	Ҫ���жϵ�!!@usage!!
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(C!!@tableName!! *p!!@tableName!!)
	{
		return !m_predict->isValid(p!!@tableName!!);
	}
};

/////////////////////////////////////////////////////////////////////////
///C!!@tableName!!Filter��һ�������е�!!@usage!!ö�������й��˵�ö����
///@author	!!@author!!
///@version	!!@version!!
/////////////////////////////////////////////////////////////////////////
class C!!@tableName!!Filter: public C!!@tableName!!Iterator
{
private:
	C!!@tableName!!Iterator *m_baseIterator;
	C!!@tableName!!Predict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	C!!@tableName!!Filter(C!!@tableName!!Iterator *pBaseIterator, C!!@tableName!!Predict *pPredict, bool continueResult=false)
		:C!!@tableName!!Iterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~C!!@tableName!!Filter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������C!!@tableName!!
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

/////////////////////////////////////////////////////////////////////////
///C!!@tableName!!LinkIterator����������!!@usage!!ö������ö����
///@author	!!@author!!
///@version	!!@version!!
/////////////////////////////////////////////////////////////////////////
class C!!@tableName!!LinkIterator: public C!!@tableName!!Iterator
{
private:
	C!!@tableName!!Iterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	C!!@tableName!!LinkIterator(C!!@tableName!!Iterator *pBaseIterator1,C!!@tableName!!Iterator *pBaseIterator2)
		:C!!@tableName!!Iterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~C!!@tableName!!LinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������C!!@tableName!!
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

!!travel foreigns!!
!!let foreignName=@name!!
/////////////////////////////////////////////////////////////////////////
///C!!@foreignName!!Of!!@tableName!!Iterator��һ��!!@usage!!ö����!!@comment!!��ö����
///@author	!!@author!!
///@version	!!@version!!
/////////////////////////////////////////////////////////////////////////
class C!!@foreignName!!Of!!@tableName!!Iterator: public C!!@factory!!Iterator
{
private:
	C!!@tableName!!Iterator *m_baseIterator;
	C!!@factory!! *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	C!!@foreignName!!Of!!@tableName!!Iterator(C!!@factory!!Factory *pFactory,C!!@tableName!!Iterator *pBaseIterator)
		:C!!@factory!!Iterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~C!!@foreignName!!Of!!@tableName!!Iterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������C!!@factory!!
	///@return	��һ����������C!!@factory!!������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual C!!@factory!! *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	p!!@factory!! ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteable!!@factory!! *p!!@factory!!,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

!!next!!

!!endif!!
!!next!!
#endif
!!leave!!
