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

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderSingleIterator�����෵��һ����Ч������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderSingleIterator: public CSysInvalidateOrderIterator
{
private:
	CSysInvalidateOrder *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysInvalidateOrderSingleIterator(CSysInvalidateOrderFactory *pFactory,CSysInvalidateOrder *pResult)
		:CSysInvalidateOrderIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysInvalidateOrderSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysInvalidateOrder
	///@return	��һ����������CSysInvalidateOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysInvalidateOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysInvalidateOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysInvalidateOrder * pSysInvalidateOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderPredict���ж�һ����Ч�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysInvalidateOrder	Ҫ���жϵ���Ч����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysInvalidateOrder *pSysInvalidateOrder)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderAndPredict�Ƕ�������Ч����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderAndPredict : public CSysInvalidateOrderPredict
{
private:
	CSysInvalidateOrderPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysInvalidateOrderAndPredict(CSysInvalidateOrderPredict *p1, CSysInvalidateOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysInvalidateOrderAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysInvalidateOrder	Ҫ���жϵ���Ч����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysInvalidateOrder *pSysInvalidateOrder)
	{
		return m_p1->isValid(pSysInvalidateOrder) && m_p2->isValid(pSysInvalidateOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderOrPredict�Ƕ�������Ч����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderOrPredict : public CSysInvalidateOrderPredict
{
private:
	CSysInvalidateOrderPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysInvalidateOrderOrPredict(CSysInvalidateOrderPredict *p1, CSysInvalidateOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysInvalidateOrderOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysInvalidateOrder	Ҫ���жϵ���Ч����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysInvalidateOrder *pSysInvalidateOrder)
	{
		return m_p1->isValid(pSysInvalidateOrder) || m_p2->isValid(pSysInvalidateOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderNotPredict�Ƕ�һ����Ч����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderNotPredict : public CSysInvalidateOrderPredict
{
private:
	CSysInvalidateOrderPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysInvalidateOrderNotPredict(CSysInvalidateOrderPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysInvalidateOrderNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysInvalidateOrder	Ҫ���жϵ���Ч����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysInvalidateOrder *pSysInvalidateOrder)
	{
		return !m_predict->isValid(pSysInvalidateOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderFilter��һ�������е���Ч����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderFilter: public CSysInvalidateOrderIterator
{
private:
	CSysInvalidateOrderIterator *m_baseIterator;
	CSysInvalidateOrderPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysInvalidateOrderFilter(CSysInvalidateOrderIterator *pBaseIterator, CSysInvalidateOrderPredict *pPredict, bool continueResult=false)
		:CSysInvalidateOrderIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysInvalidateOrderFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysInvalidateOrder
	///@return	��һ����������CSysInvalidateOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysInvalidateOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysInvalidateOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysInvalidateOrder * pSysInvalidateOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderLinkIterator������������Ч����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderLinkIterator: public CSysInvalidateOrderIterator
{
private:
	CSysInvalidateOrderIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysInvalidateOrderLinkIterator(CSysInvalidateOrderIterator *pBaseIterator1,CSysInvalidateOrderIterator *pBaseIterator2)
		:CSysInvalidateOrderIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysInvalidateOrderLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysInvalidateOrder
	///@return	��һ����������CSysInvalidateOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysInvalidateOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysInvalidateOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysInvalidateOrder * pSysInvalidateOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusSingleIterator�����෵��һ������״̬��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusSingleIterator: public CSysOrderStatusIterator
{
private:
	CSysOrderStatus *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysOrderStatusSingleIterator(CSysOrderStatusFactory *pFactory,CSysOrderStatus *pResult)
		:CSysOrderStatusIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysOrderStatusSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysOrderStatus
	///@return	��һ����������CSysOrderStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysOrderStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysOrderStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysOrderStatus * pSysOrderStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusPredict���ж�һ������״̬�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysOrderStatus	Ҫ���жϵı���״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysOrderStatus *pSysOrderStatus)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusAndPredict�Ƕ���������״̬ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusAndPredict : public CSysOrderStatusPredict
{
private:
	CSysOrderStatusPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysOrderStatusAndPredict(CSysOrderStatusPredict *p1, CSysOrderStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysOrderStatusAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysOrderStatus	Ҫ���жϵı���״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysOrderStatus *pSysOrderStatus)
	{
		return m_p1->isValid(pSysOrderStatus) && m_p2->isValid(pSysOrderStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusOrPredict�Ƕ���������״̬ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusOrPredict : public CSysOrderStatusPredict
{
private:
	CSysOrderStatusPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysOrderStatusOrPredict(CSysOrderStatusPredict *p1, CSysOrderStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysOrderStatusOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysOrderStatus	Ҫ���жϵı���״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysOrderStatus *pSysOrderStatus)
	{
		return m_p1->isValid(pSysOrderStatus) || m_p2->isValid(pSysOrderStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusNotPredict�Ƕ�һ������״̬ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusNotPredict : public CSysOrderStatusPredict
{
private:
	CSysOrderStatusPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysOrderStatusNotPredict(CSysOrderStatusPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysOrderStatusNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysOrderStatus	Ҫ���жϵı���״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysOrderStatus *pSysOrderStatus)
	{
		return !m_predict->isValid(pSysOrderStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusFilter��һ�������еı���״̬ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusFilter: public CSysOrderStatusIterator
{
private:
	CSysOrderStatusIterator *m_baseIterator;
	CSysOrderStatusPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysOrderStatusFilter(CSysOrderStatusIterator *pBaseIterator, CSysOrderStatusPredict *pPredict, bool continueResult=false)
		:CSysOrderStatusIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysOrderStatusFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysOrderStatus
	///@return	��һ����������CSysOrderStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysOrderStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysOrderStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysOrderStatus * pSysOrderStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusLinkIterator��������������״̬ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusLinkIterator: public CSysOrderStatusIterator
{
private:
	CSysOrderStatusIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysOrderStatusLinkIterator(CSysOrderStatusIterator *pBaseIterator1,CSysOrderStatusIterator *pBaseIterator2)
		:CSysOrderStatusIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysOrderStatusLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysOrderStatus
	///@return	��һ����������CSysOrderStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysOrderStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysOrderStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysOrderStatus * pSysOrderStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderSingleIterator�����෵��һ�������ɽ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderSingleIterator: public CSysBargainOrderIterator
{
private:
	CSysBargainOrder *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysBargainOrderSingleIterator(CSysBargainOrderFactory *pFactory,CSysBargainOrder *pResult)
		:CSysBargainOrderIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysBargainOrderSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysBargainOrder
	///@return	��һ����������CSysBargainOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysBargainOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysBargainOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysBargainOrder * pSysBargainOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderPredict���ж�һ�������ɽ��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysBargainOrder	Ҫ���жϵı����ɽ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysBargainOrder *pSysBargainOrder)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderAndPredict�Ƕ����������ɽ�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderAndPredict : public CSysBargainOrderPredict
{
private:
	CSysBargainOrderPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysBargainOrderAndPredict(CSysBargainOrderPredict *p1, CSysBargainOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysBargainOrderAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysBargainOrder	Ҫ���жϵı����ɽ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysBargainOrder *pSysBargainOrder)
	{
		return m_p1->isValid(pSysBargainOrder) && m_p2->isValid(pSysBargainOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderOrPredict�Ƕ����������ɽ�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderOrPredict : public CSysBargainOrderPredict
{
private:
	CSysBargainOrderPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysBargainOrderOrPredict(CSysBargainOrderPredict *p1, CSysBargainOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysBargainOrderOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysBargainOrder	Ҫ���жϵı����ɽ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysBargainOrder *pSysBargainOrder)
	{
		return m_p1->isValid(pSysBargainOrder) || m_p2->isValid(pSysBargainOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderNotPredict�Ƕ�һ�������ɽ�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderNotPredict : public CSysBargainOrderPredict
{
private:
	CSysBargainOrderPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysBargainOrderNotPredict(CSysBargainOrderPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysBargainOrderNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysBargainOrder	Ҫ���жϵı����ɽ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysBargainOrder *pSysBargainOrder)
	{
		return !m_predict->isValid(pSysBargainOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderFilter��һ�������еı����ɽ�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderFilter: public CSysBargainOrderIterator
{
private:
	CSysBargainOrderIterator *m_baseIterator;
	CSysBargainOrderPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysBargainOrderFilter(CSysBargainOrderIterator *pBaseIterator, CSysBargainOrderPredict *pPredict, bool continueResult=false)
		:CSysBargainOrderIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysBargainOrderFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysBargainOrder
	///@return	��һ����������CSysBargainOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysBargainOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysBargainOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysBargainOrder * pSysBargainOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderLinkIterator���������������ɽ�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderLinkIterator: public CSysBargainOrderIterator
{
private:
	CSysBargainOrderIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysBargainOrderLinkIterator(CSysBargainOrderIterator *pBaseIterator1,CSysBargainOrderIterator *pBaseIterator2)
		:CSysBargainOrderIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysBargainOrderLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysBargainOrder
	///@return	��һ����������CSysBargainOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysBargainOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysBargainOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysBargainOrder * pSysBargainOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysInstPropertySingleIterator�����෵��һ����Լ�������Ե�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertySingleIterator: public CSysInstPropertyIterator
{
private:
	CSysInstProperty *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysInstPropertySingleIterator(CSysInstPropertyFactory *pFactory,CSysInstProperty *pResult)
		:CSysInstPropertyIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysInstPropertySingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysInstProperty
	///@return	��һ����������CSysInstProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysInstProperty *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysInstProperty ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysInstProperty * pSysInstProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyPredict���ж�һ����Լ���������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysInstProperty	Ҫ���жϵĺ�Լ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysInstProperty *pSysInstProperty)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyAndPredict�Ƕ�������Լ��������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyAndPredict : public CSysInstPropertyPredict
{
private:
	CSysInstPropertyPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysInstPropertyAndPredict(CSysInstPropertyPredict *p1, CSysInstPropertyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysInstPropertyAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysInstProperty	Ҫ���жϵĺ�Լ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysInstProperty *pSysInstProperty)
	{
		return m_p1->isValid(pSysInstProperty) && m_p2->isValid(pSysInstProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyOrPredict�Ƕ�������Լ��������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyOrPredict : public CSysInstPropertyPredict
{
private:
	CSysInstPropertyPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysInstPropertyOrPredict(CSysInstPropertyPredict *p1, CSysInstPropertyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysInstPropertyOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysInstProperty	Ҫ���жϵĺ�Լ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysInstProperty *pSysInstProperty)
	{
		return m_p1->isValid(pSysInstProperty) || m_p2->isValid(pSysInstProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyNotPredict�Ƕ�һ����Լ��������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyNotPredict : public CSysInstPropertyPredict
{
private:
	CSysInstPropertyPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysInstPropertyNotPredict(CSysInstPropertyPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysInstPropertyNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysInstProperty	Ҫ���жϵĺ�Լ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysInstProperty *pSysInstProperty)
	{
		return !m_predict->isValid(pSysInstProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyFilter��һ�������еĺ�Լ��������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyFilter: public CSysInstPropertyIterator
{
private:
	CSysInstPropertyIterator *m_baseIterator;
	CSysInstPropertyPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysInstPropertyFilter(CSysInstPropertyIterator *pBaseIterator, CSysInstPropertyPredict *pPredict, bool continueResult=false)
		:CSysInstPropertyIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysInstPropertyFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysInstProperty
	///@return	��һ����������CSysInstProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysInstProperty *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysInstProperty ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysInstProperty * pSysInstProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyLinkIterator������������Լ��������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyLinkIterator: public CSysInstPropertyIterator
{
private:
	CSysInstPropertyIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysInstPropertyLinkIterator(CSysInstPropertyIterator *pBaseIterator1,CSysInstPropertyIterator *pBaseIterator2)
		:CSysInstPropertyIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysInstPropertyLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysInstProperty
	///@return	��һ����������CSysInstProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysInstProperty *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysInstProperty ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysInstProperty * pSysInstProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMarginRateSingleIterator�����෵��һ����Լ��֤���ʵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateSingleIterator: public CSysMarginRateIterator
{
private:
	CSysMarginRate *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMarginRateSingleIterator(CSysMarginRateFactory *pFactory,CSysMarginRate *pResult)
		:CSysMarginRateIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMarginRateSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMarginRate
	///@return	��һ����������CSysMarginRate������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMarginRate *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMarginRate ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMarginRate * pSysMarginRate,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRatePredict���ж�һ����Լ��֤�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRatePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMarginRate	Ҫ���жϵĺ�Լ��֤����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMarginRate *pSysMarginRate)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateAndPredict�Ƕ�������Լ��֤����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateAndPredict : public CSysMarginRatePredict
{
private:
	CSysMarginRatePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMarginRateAndPredict(CSysMarginRatePredict *p1, CSysMarginRatePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMarginRateAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMarginRate	Ҫ���жϵĺ�Լ��֤����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMarginRate *pSysMarginRate)
	{
		return m_p1->isValid(pSysMarginRate) && m_p2->isValid(pSysMarginRate);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateOrPredict�Ƕ�������Լ��֤����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateOrPredict : public CSysMarginRatePredict
{
private:
	CSysMarginRatePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMarginRateOrPredict(CSysMarginRatePredict *p1, CSysMarginRatePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMarginRateOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMarginRate	Ҫ���жϵĺ�Լ��֤����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMarginRate *pSysMarginRate)
	{
		return m_p1->isValid(pSysMarginRate) || m_p2->isValid(pSysMarginRate);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateNotPredict�Ƕ�һ����Լ��֤����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateNotPredict : public CSysMarginRatePredict
{
private:
	CSysMarginRatePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMarginRateNotPredict(CSysMarginRatePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMarginRateNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMarginRate	Ҫ���жϵĺ�Լ��֤����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMarginRate *pSysMarginRate)
	{
		return !m_predict->isValid(pSysMarginRate);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateFilter��һ�������еĺ�Լ��֤����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateFilter: public CSysMarginRateIterator
{
private:
	CSysMarginRateIterator *m_baseIterator;
	CSysMarginRatePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMarginRateFilter(CSysMarginRateIterator *pBaseIterator, CSysMarginRatePredict *pPredict, bool continueResult=false)
		:CSysMarginRateIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMarginRateFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMarginRate
	///@return	��һ����������CSysMarginRate������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMarginRate *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMarginRate ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMarginRate * pSysMarginRate,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateLinkIterator������������Լ��֤����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateLinkIterator: public CSysMarginRateIterator
{
private:
	CSysMarginRateIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMarginRateLinkIterator(CSysMarginRateIterator *pBaseIterator1,CSysMarginRateIterator *pBaseIterator2)
		:CSysMarginRateIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMarginRateLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMarginRate
	///@return	��һ����������CSysMarginRate������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMarginRate *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMarginRate ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMarginRate * pSysMarginRate,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitSingleIterator�����෵��һ����Լ�ǵ�ͣ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitSingleIterator: public CSysPriceLimitIterator
{
private:
	CSysPriceLimit *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysPriceLimitSingleIterator(CSysPriceLimitFactory *pFactory,CSysPriceLimit *pResult)
		:CSysPriceLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysPriceLimitSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysPriceLimit
	///@return	��һ����������CSysPriceLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPriceLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPriceLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPriceLimit * pSysPriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitPredict���ж�һ����Լ�ǵ�ͣ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysPriceLimit	Ҫ���жϵĺ�Լ�ǵ�ͣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPriceLimit *pSysPriceLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitAndPredict�Ƕ�������Լ�ǵ�ͣ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitAndPredict : public CSysPriceLimitPredict
{
private:
	CSysPriceLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysPriceLimitAndPredict(CSysPriceLimitPredict *p1, CSysPriceLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysPriceLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysPriceLimit	Ҫ���жϵĺ�Լ�ǵ�ͣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPriceLimit *pSysPriceLimit)
	{
		return m_p1->isValid(pSysPriceLimit) && m_p2->isValid(pSysPriceLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitOrPredict�Ƕ�������Լ�ǵ�ͣ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitOrPredict : public CSysPriceLimitPredict
{
private:
	CSysPriceLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysPriceLimitOrPredict(CSysPriceLimitPredict *p1, CSysPriceLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysPriceLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysPriceLimit	Ҫ���жϵĺ�Լ�ǵ�ͣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPriceLimit *pSysPriceLimit)
	{
		return m_p1->isValid(pSysPriceLimit) || m_p2->isValid(pSysPriceLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitNotPredict�Ƕ�һ����Լ�ǵ�ͣ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitNotPredict : public CSysPriceLimitPredict
{
private:
	CSysPriceLimitPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysPriceLimitNotPredict(CSysPriceLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysPriceLimitNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysPriceLimit	Ҫ���жϵĺ�Լ�ǵ�ͣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPriceLimit *pSysPriceLimit)
	{
		return !m_predict->isValid(pSysPriceLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitFilter��һ�������еĺ�Լ�ǵ�ͣ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitFilter: public CSysPriceLimitIterator
{
private:
	CSysPriceLimitIterator *m_baseIterator;
	CSysPriceLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysPriceLimitFilter(CSysPriceLimitIterator *pBaseIterator, CSysPriceLimitPredict *pPredict, bool continueResult=false)
		:CSysPriceLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysPriceLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysPriceLimit
	///@return	��һ����������CSysPriceLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPriceLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPriceLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPriceLimit * pSysPriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitLinkIterator������������Լ�ǵ�ͣ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitLinkIterator: public CSysPriceLimitIterator
{
private:
	CSysPriceLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysPriceLimitLinkIterator(CSysPriceLimitIterator *pBaseIterator1,CSysPriceLimitIterator *pBaseIterator2)
		:CSysPriceLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysPriceLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysPriceLimit
	///@return	��һ����������CSysPriceLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPriceLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPriceLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPriceLimit * pSysPriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitSingleIterator�����෵��һ����Ա�޲ֵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitSingleIterator: public CSysPartPosiLimitIterator
{
private:
	CSysPartPosiLimit *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysPartPosiLimitSingleIterator(CSysPartPosiLimitFactory *pFactory,CSysPartPosiLimit *pResult)
		:CSysPartPosiLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysPartPosiLimitSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysPartPosiLimit
	///@return	��һ����������CSysPartPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPartPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPartPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPartPosiLimit * pSysPartPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitPredict���ж�һ����Ա�޲��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysPartPosiLimit	Ҫ���жϵĻ�Ա�޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPartPosiLimit *pSysPartPosiLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitAndPredict�Ƕ�������Ա�޲�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitAndPredict : public CSysPartPosiLimitPredict
{
private:
	CSysPartPosiLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysPartPosiLimitAndPredict(CSysPartPosiLimitPredict *p1, CSysPartPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysPartPosiLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysPartPosiLimit	Ҫ���жϵĻ�Ա�޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPartPosiLimit *pSysPartPosiLimit)
	{
		return m_p1->isValid(pSysPartPosiLimit) && m_p2->isValid(pSysPartPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitOrPredict�Ƕ�������Ա�޲�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitOrPredict : public CSysPartPosiLimitPredict
{
private:
	CSysPartPosiLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysPartPosiLimitOrPredict(CSysPartPosiLimitPredict *p1, CSysPartPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysPartPosiLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysPartPosiLimit	Ҫ���жϵĻ�Ա�޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPartPosiLimit *pSysPartPosiLimit)
	{
		return m_p1->isValid(pSysPartPosiLimit) || m_p2->isValid(pSysPartPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitNotPredict�Ƕ�һ����Ա�޲�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitNotPredict : public CSysPartPosiLimitPredict
{
private:
	CSysPartPosiLimitPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysPartPosiLimitNotPredict(CSysPartPosiLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysPartPosiLimitNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysPartPosiLimit	Ҫ���жϵĻ�Ա�޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPartPosiLimit *pSysPartPosiLimit)
	{
		return !m_predict->isValid(pSysPartPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitFilter��һ�������еĻ�Ա�޲�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitFilter: public CSysPartPosiLimitIterator
{
private:
	CSysPartPosiLimitIterator *m_baseIterator;
	CSysPartPosiLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysPartPosiLimitFilter(CSysPartPosiLimitIterator *pBaseIterator, CSysPartPosiLimitPredict *pPredict, bool continueResult=false)
		:CSysPartPosiLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysPartPosiLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysPartPosiLimit
	///@return	��һ����������CSysPartPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPartPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPartPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPartPosiLimit * pSysPartPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitLinkIterator������������Ա�޲�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitLinkIterator: public CSysPartPosiLimitIterator
{
private:
	CSysPartPosiLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysPartPosiLimitLinkIterator(CSysPartPosiLimitIterator *pBaseIterator1,CSysPartPosiLimitIterator *pBaseIterator2)
		:CSysPartPosiLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysPartPosiLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysPartPosiLimit
	///@return	��һ����������CSysPartPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPartPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPartPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPartPosiLimit * pSysPartPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitSingleIterator�����෵��һ���ͻ��޲ֵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitSingleIterator: public CSysClientPosiLimitIterator
{
private:
	CSysClientPosiLimit *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysClientPosiLimitSingleIterator(CSysClientPosiLimitFactory *pFactory,CSysClientPosiLimit *pResult)
		:CSysClientPosiLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysClientPosiLimitSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysClientPosiLimit
	///@return	��һ����������CSysClientPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysClientPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientPosiLimit * pSysClientPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitPredict���ж�һ���ͻ��޲��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysClientPosiLimit	Ҫ���жϵĿͻ��޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysClientPosiLimit *pSysClientPosiLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitAndPredict�Ƕ������ͻ��޲�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitAndPredict : public CSysClientPosiLimitPredict
{
private:
	CSysClientPosiLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysClientPosiLimitAndPredict(CSysClientPosiLimitPredict *p1, CSysClientPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysClientPosiLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysClientPosiLimit	Ҫ���жϵĿͻ��޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysClientPosiLimit *pSysClientPosiLimit)
	{
		return m_p1->isValid(pSysClientPosiLimit) && m_p2->isValid(pSysClientPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitOrPredict�Ƕ������ͻ��޲�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitOrPredict : public CSysClientPosiLimitPredict
{
private:
	CSysClientPosiLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysClientPosiLimitOrPredict(CSysClientPosiLimitPredict *p1, CSysClientPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysClientPosiLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysClientPosiLimit	Ҫ���жϵĿͻ��޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysClientPosiLimit *pSysClientPosiLimit)
	{
		return m_p1->isValid(pSysClientPosiLimit) || m_p2->isValid(pSysClientPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitNotPredict�Ƕ�һ���ͻ��޲�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitNotPredict : public CSysClientPosiLimitPredict
{
private:
	CSysClientPosiLimitPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysClientPosiLimitNotPredict(CSysClientPosiLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysClientPosiLimitNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysClientPosiLimit	Ҫ���жϵĿͻ��޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysClientPosiLimit *pSysClientPosiLimit)
	{
		return !m_predict->isValid(pSysClientPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitFilter��һ�������еĿͻ��޲�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitFilter: public CSysClientPosiLimitIterator
{
private:
	CSysClientPosiLimitIterator *m_baseIterator;
	CSysClientPosiLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysClientPosiLimitFilter(CSysClientPosiLimitIterator *pBaseIterator, CSysClientPosiLimitPredict *pPredict, bool continueResult=false)
		:CSysClientPosiLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysClientPosiLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysClientPosiLimit
	///@return	��һ����������CSysClientPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysClientPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientPosiLimit * pSysClientPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitLinkIterator�����������ͻ��޲�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitLinkIterator: public CSysClientPosiLimitIterator
{
private:
	CSysClientPosiLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysClientPosiLimitLinkIterator(CSysClientPosiLimitIterator *pBaseIterator1,CSysClientPosiLimitIterator *pBaseIterator2)
		:CSysClientPosiLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysClientPosiLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysClientPosiLimit
	///@return	��һ����������CSysClientPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysClientPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientPosiLimit * pSysClientPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitSingleIterator�����෵��һ������ͻ��޲ֵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitSingleIterator: public CSysSpecialPosiLimitIterator
{
private:
	CSysSpecialPosiLimit *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysSpecialPosiLimitSingleIterator(CSysSpecialPosiLimitFactory *pFactory,CSysSpecialPosiLimit *pResult)
		:CSysSpecialPosiLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysSpecialPosiLimitSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysSpecialPosiLimit
	///@return	��һ����������CSysSpecialPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysSpecialPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysSpecialPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysSpecialPosiLimit * pSysSpecialPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitPredict���ж�һ������ͻ��޲��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysSpecialPosiLimit	Ҫ���жϵ�����ͻ��޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysSpecialPosiLimit *pSysSpecialPosiLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitAndPredict�Ƕ���������ͻ��޲�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitAndPredict : public CSysSpecialPosiLimitPredict
{
private:
	CSysSpecialPosiLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysSpecialPosiLimitAndPredict(CSysSpecialPosiLimitPredict *p1, CSysSpecialPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysSpecialPosiLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysSpecialPosiLimit	Ҫ���жϵ�����ͻ��޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return m_p1->isValid(pSysSpecialPosiLimit) && m_p2->isValid(pSysSpecialPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitOrPredict�Ƕ���������ͻ��޲�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitOrPredict : public CSysSpecialPosiLimitPredict
{
private:
	CSysSpecialPosiLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysSpecialPosiLimitOrPredict(CSysSpecialPosiLimitPredict *p1, CSysSpecialPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysSpecialPosiLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysSpecialPosiLimit	Ҫ���жϵ�����ͻ��޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return m_p1->isValid(pSysSpecialPosiLimit) || m_p2->isValid(pSysSpecialPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitNotPredict�Ƕ�һ������ͻ��޲�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitNotPredict : public CSysSpecialPosiLimitPredict
{
private:
	CSysSpecialPosiLimitPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysSpecialPosiLimitNotPredict(CSysSpecialPosiLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysSpecialPosiLimitNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysSpecialPosiLimit	Ҫ���жϵ�����ͻ��޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return !m_predict->isValid(pSysSpecialPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitFilter��һ�������е�����ͻ��޲�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitFilter: public CSysSpecialPosiLimitIterator
{
private:
	CSysSpecialPosiLimitIterator *m_baseIterator;
	CSysSpecialPosiLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysSpecialPosiLimitFilter(CSysSpecialPosiLimitIterator *pBaseIterator, CSysSpecialPosiLimitPredict *pPredict, bool continueResult=false)
		:CSysSpecialPosiLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysSpecialPosiLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysSpecialPosiLimit
	///@return	��һ����������CSysSpecialPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysSpecialPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysSpecialPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysSpecialPosiLimit * pSysSpecialPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitLinkIterator��������������ͻ��޲�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitLinkIterator: public CSysSpecialPosiLimitIterator
{
private:
	CSysSpecialPosiLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysSpecialPosiLimitLinkIterator(CSysSpecialPosiLimitIterator *pBaseIterator1,CSysSpecialPosiLimitIterator *pBaseIterator2)
		:CSysSpecialPosiLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysSpecialPosiLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysSpecialPosiLimit
	///@return	��һ����������CSysSpecialPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysSpecialPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysSpecialPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysSpecialPosiLimit * pSysSpecialPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgSingleIterator�����෵��һ���˻�������ѯ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgSingleIterator: public CSysTransactionChgIterator
{
private:
	CSysTransactionChg *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysTransactionChgSingleIterator(CSysTransactionChgFactory *pFactory,CSysTransactionChg *pResult)
		:CSysTransactionChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysTransactionChgSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysTransactionChg
	///@return	��һ����������CSysTransactionChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysTransactionChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysTransactionChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysTransactionChg * pSysTransactionChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgPredict���ж�һ���˻�������ѯ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysTransactionChg	Ҫ���жϵ��˻�������ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysTransactionChg *pSysTransactionChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgAndPredict�Ƕ������˻�������ѯν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgAndPredict : public CSysTransactionChgPredict
{
private:
	CSysTransactionChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysTransactionChgAndPredict(CSysTransactionChgPredict *p1, CSysTransactionChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysTransactionChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysTransactionChg	Ҫ���жϵ��˻�������ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysTransactionChg *pSysTransactionChg)
	{
		return m_p1->isValid(pSysTransactionChg) && m_p2->isValid(pSysTransactionChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgOrPredict�Ƕ������˻�������ѯν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgOrPredict : public CSysTransactionChgPredict
{
private:
	CSysTransactionChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysTransactionChgOrPredict(CSysTransactionChgPredict *p1, CSysTransactionChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysTransactionChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysTransactionChg	Ҫ���жϵ��˻�������ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysTransactionChg *pSysTransactionChg)
	{
		return m_p1->isValid(pSysTransactionChg) || m_p2->isValid(pSysTransactionChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgNotPredict�Ƕ�һ���˻�������ѯν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgNotPredict : public CSysTransactionChgPredict
{
private:
	CSysTransactionChgPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysTransactionChgNotPredict(CSysTransactionChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysTransactionChgNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysTransactionChg	Ҫ���жϵ��˻�������ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysTransactionChg *pSysTransactionChg)
	{
		return !m_predict->isValid(pSysTransactionChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgFilter��һ�������е��˻�������ѯö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgFilter: public CSysTransactionChgIterator
{
private:
	CSysTransactionChgIterator *m_baseIterator;
	CSysTransactionChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysTransactionChgFilter(CSysTransactionChgIterator *pBaseIterator, CSysTransactionChgPredict *pPredict, bool continueResult=false)
		:CSysTransactionChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysTransactionChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysTransactionChg
	///@return	��һ����������CSysTransactionChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysTransactionChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysTransactionChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysTransactionChg * pSysTransactionChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgLinkIterator�����������˻�������ѯö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgLinkIterator: public CSysTransactionChgIterator
{
private:
	CSysTransactionChgIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysTransactionChgLinkIterator(CSysTransactionChgIterator *pBaseIterator1,CSysTransactionChgIterator *pBaseIterator2)
		:CSysTransactionChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysTransactionChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysTransactionChg
	///@return	��һ����������CSysTransactionChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysTransactionChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysTransactionChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysTransactionChg * pSysTransactionChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysClientChgSingleIterator�����෵��һ���ͻ����ݱ䶯��ѯ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgSingleIterator: public CSysClientChgIterator
{
private:
	CSysClientChg *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysClientChgSingleIterator(CSysClientChgFactory *pFactory,CSysClientChg *pResult)
		:CSysClientChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysClientChgSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysClientChg
	///@return	��һ����������CSysClientChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysClientChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientChg * pSysClientChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgPredict���ж�һ���ͻ����ݱ䶯��ѯ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysClientChg	Ҫ���жϵĿͻ����ݱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysClientChg *pSysClientChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgAndPredict�Ƕ������ͻ����ݱ䶯��ѯν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgAndPredict : public CSysClientChgPredict
{
private:
	CSysClientChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysClientChgAndPredict(CSysClientChgPredict *p1, CSysClientChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysClientChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysClientChg	Ҫ���жϵĿͻ����ݱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysClientChg *pSysClientChg)
	{
		return m_p1->isValid(pSysClientChg) && m_p2->isValid(pSysClientChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgOrPredict�Ƕ������ͻ����ݱ䶯��ѯν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgOrPredict : public CSysClientChgPredict
{
private:
	CSysClientChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysClientChgOrPredict(CSysClientChgPredict *p1, CSysClientChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysClientChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysClientChg	Ҫ���жϵĿͻ����ݱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysClientChg *pSysClientChg)
	{
		return m_p1->isValid(pSysClientChg) || m_p2->isValid(pSysClientChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgNotPredict�Ƕ�һ���ͻ����ݱ䶯��ѯν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgNotPredict : public CSysClientChgPredict
{
private:
	CSysClientChgPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysClientChgNotPredict(CSysClientChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysClientChgNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysClientChg	Ҫ���жϵĿͻ����ݱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysClientChg *pSysClientChg)
	{
		return !m_predict->isValid(pSysClientChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgFilter��һ�������еĿͻ����ݱ䶯��ѯö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgFilter: public CSysClientChgIterator
{
private:
	CSysClientChgIterator *m_baseIterator;
	CSysClientChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysClientChgFilter(CSysClientChgIterator *pBaseIterator, CSysClientChgPredict *pPredict, bool continueResult=false)
		:CSysClientChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysClientChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysClientChg
	///@return	��һ����������CSysClientChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysClientChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientChg * pSysClientChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgLinkIterator�����������ͻ����ݱ䶯��ѯö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgLinkIterator: public CSysClientChgIterator
{
private:
	CSysClientChgIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysClientChgLinkIterator(CSysClientChgIterator *pBaseIterator1,CSysClientChgIterator *pBaseIterator2)
		:CSysClientChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysClientChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysClientChg
	///@return	��һ����������CSysClientChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysClientChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientChg * pSysClientChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgSingleIterator�����෵��һ����Ա�ͻ����ձ䶯��ѯ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgSingleIterator: public CSysPartClientChgIterator
{
private:
	CSysPartClientChg *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysPartClientChgSingleIterator(CSysPartClientChgFactory *pFactory,CSysPartClientChg *pResult)
		:CSysPartClientChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysPartClientChgSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysPartClientChg
	///@return	��һ����������CSysPartClientChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPartClientChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPartClientChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPartClientChg * pSysPartClientChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgPredict���ж�һ����Ա�ͻ����ձ䶯��ѯ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysPartClientChg	Ҫ���жϵĻ�Ա�ͻ����ձ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPartClientChg *pSysPartClientChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgAndPredict�Ƕ�������Ա�ͻ����ձ䶯��ѯν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgAndPredict : public CSysPartClientChgPredict
{
private:
	CSysPartClientChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysPartClientChgAndPredict(CSysPartClientChgPredict *p1, CSysPartClientChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysPartClientChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysPartClientChg	Ҫ���жϵĻ�Ա�ͻ����ձ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPartClientChg *pSysPartClientChg)
	{
		return m_p1->isValid(pSysPartClientChg) && m_p2->isValid(pSysPartClientChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgOrPredict�Ƕ�������Ա�ͻ����ձ䶯��ѯν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgOrPredict : public CSysPartClientChgPredict
{
private:
	CSysPartClientChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysPartClientChgOrPredict(CSysPartClientChgPredict *p1, CSysPartClientChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysPartClientChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysPartClientChg	Ҫ���жϵĻ�Ա�ͻ����ձ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPartClientChg *pSysPartClientChg)
	{
		return m_p1->isValid(pSysPartClientChg) || m_p2->isValid(pSysPartClientChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgNotPredict�Ƕ�һ����Ա�ͻ����ձ䶯��ѯν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgNotPredict : public CSysPartClientChgPredict
{
private:
	CSysPartClientChgPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysPartClientChgNotPredict(CSysPartClientChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysPartClientChgNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysPartClientChg	Ҫ���жϵĻ�Ա�ͻ����ձ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPartClientChg *pSysPartClientChg)
	{
		return !m_predict->isValid(pSysPartClientChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgFilter��һ�������еĻ�Ա�ͻ����ձ䶯��ѯö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgFilter: public CSysPartClientChgIterator
{
private:
	CSysPartClientChgIterator *m_baseIterator;
	CSysPartClientChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysPartClientChgFilter(CSysPartClientChgIterator *pBaseIterator, CSysPartClientChgPredict *pPredict, bool continueResult=false)
		:CSysPartClientChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysPartClientChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysPartClientChg
	///@return	��һ����������CSysPartClientChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPartClientChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPartClientChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPartClientChg * pSysPartClientChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgLinkIterator������������Ա�ͻ����ձ䶯��ѯö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgLinkIterator: public CSysPartClientChgIterator
{
private:
	CSysPartClientChgIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysPartClientChgLinkIterator(CSysPartClientChgIterator *pBaseIterator1,CSysPartClientChgIterator *pBaseIterator2)
		:CSysPartClientChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysPartClientChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysPartClientChg
	///@return	��һ����������CSysPartClientChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPartClientChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPartClientChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPartClientChg * pSysPartClientChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgSingleIterator�����෵��һ���޲����ݱ䶯��ѯ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgSingleIterator: public CSysPosiLimitChgIterator
{
private:
	CSysPosiLimitChg *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysPosiLimitChgSingleIterator(CSysPosiLimitChgFactory *pFactory,CSysPosiLimitChg *pResult)
		:CSysPosiLimitChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysPosiLimitChgSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysPosiLimitChg
	///@return	��һ����������CSysPosiLimitChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPosiLimitChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPosiLimitChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPosiLimitChg * pSysPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgPredict���ж�һ���޲����ݱ䶯��ѯ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysPosiLimitChg	Ҫ���жϵ��޲����ݱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPosiLimitChg *pSysPosiLimitChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgAndPredict�Ƕ������޲����ݱ䶯��ѯν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgAndPredict : public CSysPosiLimitChgPredict
{
private:
	CSysPosiLimitChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysPosiLimitChgAndPredict(CSysPosiLimitChgPredict *p1, CSysPosiLimitChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysPosiLimitChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysPosiLimitChg	Ҫ���жϵ��޲����ݱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPosiLimitChg *pSysPosiLimitChg)
	{
		return m_p1->isValid(pSysPosiLimitChg) && m_p2->isValid(pSysPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgOrPredict�Ƕ������޲����ݱ䶯��ѯν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgOrPredict : public CSysPosiLimitChgPredict
{
private:
	CSysPosiLimitChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysPosiLimitChgOrPredict(CSysPosiLimitChgPredict *p1, CSysPosiLimitChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysPosiLimitChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysPosiLimitChg	Ҫ���жϵ��޲����ݱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPosiLimitChg *pSysPosiLimitChg)
	{
		return m_p1->isValid(pSysPosiLimitChg) || m_p2->isValid(pSysPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgNotPredict�Ƕ�һ���޲����ݱ䶯��ѯν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgNotPredict : public CSysPosiLimitChgPredict
{
private:
	CSysPosiLimitChgPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysPosiLimitChgNotPredict(CSysPosiLimitChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysPosiLimitChgNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysPosiLimitChg	Ҫ���жϵ��޲����ݱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPosiLimitChg *pSysPosiLimitChg)
	{
		return !m_predict->isValid(pSysPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgFilter��һ�������е��޲����ݱ䶯��ѯö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgFilter: public CSysPosiLimitChgIterator
{
private:
	CSysPosiLimitChgIterator *m_baseIterator;
	CSysPosiLimitChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysPosiLimitChgFilter(CSysPosiLimitChgIterator *pBaseIterator, CSysPosiLimitChgPredict *pPredict, bool continueResult=false)
		:CSysPosiLimitChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysPosiLimitChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysPosiLimitChg
	///@return	��һ����������CSysPosiLimitChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPosiLimitChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPosiLimitChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPosiLimitChg * pSysPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgLinkIterator�����������޲����ݱ䶯��ѯö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgLinkIterator: public CSysPosiLimitChgIterator
{
private:
	CSysPosiLimitChgIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysPosiLimitChgLinkIterator(CSysPosiLimitChgIterator *pBaseIterator1,CSysPosiLimitChgIterator *pBaseIterator2)
		:CSysPosiLimitChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysPosiLimitChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysPosiLimitChg
	///@return	��һ����������CSysPosiLimitChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPosiLimitChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPosiLimitChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPosiLimitChg * pSysPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgSingleIterator�����෵��һ���޲����ݱ䶯��ѯ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgSingleIterator: public CSysClientPosiLimitChgIterator
{
private:
	CSysClientPosiLimitChg *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysClientPosiLimitChgSingleIterator(CSysClientPosiLimitChgFactory *pFactory,CSysClientPosiLimitChg *pResult)
		:CSysClientPosiLimitChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysClientPosiLimitChgSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysClientPosiLimitChg
	///@return	��һ����������CSysClientPosiLimitChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientPosiLimitChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysClientPosiLimitChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientPosiLimitChg * pSysClientPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgPredict���ж�һ���޲����ݱ䶯��ѯ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysClientPosiLimitChg	Ҫ���жϵ��޲����ݱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysClientPosiLimitChg *pSysClientPosiLimitChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgAndPredict�Ƕ������޲����ݱ䶯��ѯν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgAndPredict : public CSysClientPosiLimitChgPredict
{
private:
	CSysClientPosiLimitChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysClientPosiLimitChgAndPredict(CSysClientPosiLimitChgPredict *p1, CSysClientPosiLimitChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysClientPosiLimitChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysClientPosiLimitChg	Ҫ���жϵ��޲����ݱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return m_p1->isValid(pSysClientPosiLimitChg) && m_p2->isValid(pSysClientPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgOrPredict�Ƕ������޲����ݱ䶯��ѯν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgOrPredict : public CSysClientPosiLimitChgPredict
{
private:
	CSysClientPosiLimitChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysClientPosiLimitChgOrPredict(CSysClientPosiLimitChgPredict *p1, CSysClientPosiLimitChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysClientPosiLimitChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysClientPosiLimitChg	Ҫ���жϵ��޲����ݱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return m_p1->isValid(pSysClientPosiLimitChg) || m_p2->isValid(pSysClientPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgNotPredict�Ƕ�һ���޲����ݱ䶯��ѯν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgNotPredict : public CSysClientPosiLimitChgPredict
{
private:
	CSysClientPosiLimitChgPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysClientPosiLimitChgNotPredict(CSysClientPosiLimitChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysClientPosiLimitChgNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysClientPosiLimitChg	Ҫ���жϵ��޲����ݱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return !m_predict->isValid(pSysClientPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgFilter��һ�������е��޲����ݱ䶯��ѯö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgFilter: public CSysClientPosiLimitChgIterator
{
private:
	CSysClientPosiLimitChgIterator *m_baseIterator;
	CSysClientPosiLimitChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysClientPosiLimitChgFilter(CSysClientPosiLimitChgIterator *pBaseIterator, CSysClientPosiLimitChgPredict *pPredict, bool continueResult=false)
		:CSysClientPosiLimitChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysClientPosiLimitChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysClientPosiLimitChg
	///@return	��һ����������CSysClientPosiLimitChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientPosiLimitChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysClientPosiLimitChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientPosiLimitChg * pSysClientPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgLinkIterator�����������޲����ݱ䶯��ѯö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgLinkIterator: public CSysClientPosiLimitChgIterator
{
private:
	CSysClientPosiLimitChgIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysClientPosiLimitChgLinkIterator(CSysClientPosiLimitChgIterator *pBaseIterator1,CSysClientPosiLimitChgIterator *pBaseIterator2)
		:CSysClientPosiLimitChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysClientPosiLimitChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysClientPosiLimitChg
	///@return	��һ����������CSysClientPosiLimitChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientPosiLimitChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysClientPosiLimitChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientPosiLimitChg * pSysClientPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgSingleIterator�����෵��һ���޲����ݱ䶯��ѯ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgSingleIterator: public CSysSpecPosiLimitChgIterator
{
private:
	CSysSpecPosiLimitChg *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysSpecPosiLimitChgSingleIterator(CSysSpecPosiLimitChgFactory *pFactory,CSysSpecPosiLimitChg *pResult)
		:CSysSpecPosiLimitChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysSpecPosiLimitChgSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysSpecPosiLimitChg
	///@return	��һ����������CSysSpecPosiLimitChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysSpecPosiLimitChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysSpecPosiLimitChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysSpecPosiLimitChg * pSysSpecPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgPredict���ж�һ���޲����ݱ䶯��ѯ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysSpecPosiLimitChg	Ҫ���жϵ��޲����ݱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgAndPredict�Ƕ������޲����ݱ䶯��ѯν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgAndPredict : public CSysSpecPosiLimitChgPredict
{
private:
	CSysSpecPosiLimitChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysSpecPosiLimitChgAndPredict(CSysSpecPosiLimitChgPredict *p1, CSysSpecPosiLimitChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysSpecPosiLimitChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysSpecPosiLimitChg	Ҫ���жϵ��޲����ݱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return m_p1->isValid(pSysSpecPosiLimitChg) && m_p2->isValid(pSysSpecPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgOrPredict�Ƕ������޲����ݱ䶯��ѯν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgOrPredict : public CSysSpecPosiLimitChgPredict
{
private:
	CSysSpecPosiLimitChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysSpecPosiLimitChgOrPredict(CSysSpecPosiLimitChgPredict *p1, CSysSpecPosiLimitChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysSpecPosiLimitChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysSpecPosiLimitChg	Ҫ���жϵ��޲����ݱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return m_p1->isValid(pSysSpecPosiLimitChg) || m_p2->isValid(pSysSpecPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgNotPredict�Ƕ�һ���޲����ݱ䶯��ѯν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgNotPredict : public CSysSpecPosiLimitChgPredict
{
private:
	CSysSpecPosiLimitChgPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysSpecPosiLimitChgNotPredict(CSysSpecPosiLimitChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysSpecPosiLimitChgNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysSpecPosiLimitChg	Ҫ���жϵ��޲����ݱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return !m_predict->isValid(pSysSpecPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgFilter��һ�������е��޲����ݱ䶯��ѯö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgFilter: public CSysSpecPosiLimitChgIterator
{
private:
	CSysSpecPosiLimitChgIterator *m_baseIterator;
	CSysSpecPosiLimitChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysSpecPosiLimitChgFilter(CSysSpecPosiLimitChgIterator *pBaseIterator, CSysSpecPosiLimitChgPredict *pPredict, bool continueResult=false)
		:CSysSpecPosiLimitChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysSpecPosiLimitChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysSpecPosiLimitChg
	///@return	��һ����������CSysSpecPosiLimitChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysSpecPosiLimitChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysSpecPosiLimitChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysSpecPosiLimitChg * pSysSpecPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgLinkIterator�����������޲����ݱ䶯��ѯö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgLinkIterator: public CSysSpecPosiLimitChgIterator
{
private:
	CSysSpecPosiLimitChgIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysSpecPosiLimitChgLinkIterator(CSysSpecPosiLimitChgIterator *pBaseIterator1,CSysSpecPosiLimitChgIterator *pBaseIterator2)
		:CSysSpecPosiLimitChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysSpecPosiLimitChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysSpecPosiLimitChg
	///@return	��һ����������CSysSpecPosiLimitChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysSpecPosiLimitChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysSpecPosiLimitChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysSpecPosiLimitChg * pSysSpecPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgSingleIterator�����෵��һ����ֵ��ȱ䶯��ѯ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgSingleIterator: public CSysHedgeDetailChgIterator
{
private:
	CSysHedgeDetailChg *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysHedgeDetailChgSingleIterator(CSysHedgeDetailChgFactory *pFactory,CSysHedgeDetailChg *pResult)
		:CSysHedgeDetailChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysHedgeDetailChgSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysHedgeDetailChg
	///@return	��һ����������CSysHedgeDetailChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysHedgeDetailChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysHedgeDetailChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysHedgeDetailChg * pSysHedgeDetailChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgPredict���ж�һ����ֵ��ȱ䶯��ѯ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysHedgeDetailChg	Ҫ���жϵı�ֵ��ȱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysHedgeDetailChg *pSysHedgeDetailChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgAndPredict�Ƕ�������ֵ��ȱ䶯��ѯν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgAndPredict : public CSysHedgeDetailChgPredict
{
private:
	CSysHedgeDetailChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysHedgeDetailChgAndPredict(CSysHedgeDetailChgPredict *p1, CSysHedgeDetailChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysHedgeDetailChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysHedgeDetailChg	Ҫ���жϵı�ֵ��ȱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return m_p1->isValid(pSysHedgeDetailChg) && m_p2->isValid(pSysHedgeDetailChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgOrPredict�Ƕ�������ֵ��ȱ䶯��ѯν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgOrPredict : public CSysHedgeDetailChgPredict
{
private:
	CSysHedgeDetailChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysHedgeDetailChgOrPredict(CSysHedgeDetailChgPredict *p1, CSysHedgeDetailChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysHedgeDetailChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysHedgeDetailChg	Ҫ���жϵı�ֵ��ȱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return m_p1->isValid(pSysHedgeDetailChg) || m_p2->isValid(pSysHedgeDetailChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgNotPredict�Ƕ�һ����ֵ��ȱ䶯��ѯν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgNotPredict : public CSysHedgeDetailChgPredict
{
private:
	CSysHedgeDetailChgPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysHedgeDetailChgNotPredict(CSysHedgeDetailChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysHedgeDetailChgNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysHedgeDetailChg	Ҫ���жϵı�ֵ��ȱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return !m_predict->isValid(pSysHedgeDetailChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgFilter��һ�������еı�ֵ��ȱ䶯��ѯö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgFilter: public CSysHedgeDetailChgIterator
{
private:
	CSysHedgeDetailChgIterator *m_baseIterator;
	CSysHedgeDetailChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysHedgeDetailChgFilter(CSysHedgeDetailChgIterator *pBaseIterator, CSysHedgeDetailChgPredict *pPredict, bool continueResult=false)
		:CSysHedgeDetailChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysHedgeDetailChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysHedgeDetailChg
	///@return	��һ����������CSysHedgeDetailChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysHedgeDetailChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysHedgeDetailChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysHedgeDetailChg * pSysHedgeDetailChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgLinkIterator������������ֵ��ȱ䶯��ѯö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgLinkIterator: public CSysHedgeDetailChgIterator
{
private:
	CSysHedgeDetailChgIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysHedgeDetailChgLinkIterator(CSysHedgeDetailChgIterator *pBaseIterator1,CSysHedgeDetailChgIterator *pBaseIterator2)
		:CSysHedgeDetailChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysHedgeDetailChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysHedgeDetailChg
	///@return	��һ����������CSysHedgeDetailChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysHedgeDetailChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysHedgeDetailChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysHedgeDetailChg * pSysHedgeDetailChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgSingleIterator�����෵��һ����Ա�䶯��ѯ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgSingleIterator: public CSysParticipantChgIterator
{
private:
	CSysParticipantChg *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysParticipantChgSingleIterator(CSysParticipantChgFactory *pFactory,CSysParticipantChg *pResult)
		:CSysParticipantChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysParticipantChgSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysParticipantChg
	///@return	��һ����������CSysParticipantChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysParticipantChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysParticipantChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysParticipantChg * pSysParticipantChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgPredict���ж�һ����Ա�䶯��ѯ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysParticipantChg	Ҫ���жϵĻ�Ա�䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysParticipantChg *pSysParticipantChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgAndPredict�Ƕ�������Ա�䶯��ѯν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgAndPredict : public CSysParticipantChgPredict
{
private:
	CSysParticipantChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysParticipantChgAndPredict(CSysParticipantChgPredict *p1, CSysParticipantChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysParticipantChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysParticipantChg	Ҫ���жϵĻ�Ա�䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysParticipantChg *pSysParticipantChg)
	{
		return m_p1->isValid(pSysParticipantChg) && m_p2->isValid(pSysParticipantChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgOrPredict�Ƕ�������Ա�䶯��ѯν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgOrPredict : public CSysParticipantChgPredict
{
private:
	CSysParticipantChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysParticipantChgOrPredict(CSysParticipantChgPredict *p1, CSysParticipantChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysParticipantChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysParticipantChg	Ҫ���жϵĻ�Ա�䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysParticipantChg *pSysParticipantChg)
	{
		return m_p1->isValid(pSysParticipantChg) || m_p2->isValid(pSysParticipantChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgNotPredict�Ƕ�һ����Ա�䶯��ѯν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgNotPredict : public CSysParticipantChgPredict
{
private:
	CSysParticipantChgPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysParticipantChgNotPredict(CSysParticipantChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysParticipantChgNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysParticipantChg	Ҫ���жϵĻ�Ա�䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysParticipantChg *pSysParticipantChg)
	{
		return !m_predict->isValid(pSysParticipantChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgFilter��һ�������еĻ�Ա�䶯��ѯö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgFilter: public CSysParticipantChgIterator
{
private:
	CSysParticipantChgIterator *m_baseIterator;
	CSysParticipantChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysParticipantChgFilter(CSysParticipantChgIterator *pBaseIterator, CSysParticipantChgPredict *pPredict, bool continueResult=false)
		:CSysParticipantChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysParticipantChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysParticipantChg
	///@return	��һ����������CSysParticipantChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysParticipantChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysParticipantChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysParticipantChg * pSysParticipantChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgLinkIterator������������Ա�䶯��ѯö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgLinkIterator: public CSysParticipantChgIterator
{
private:
	CSysParticipantChgIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysParticipantChgLinkIterator(CSysParticipantChgIterator *pBaseIterator1,CSysParticipantChgIterator *pBaseIterator2)
		:CSysParticipantChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysParticipantChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysParticipantChg
	///@return	��һ����������CSysParticipantChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysParticipantChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysParticipantChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysParticipantChg * pSysParticipantChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgSingleIterator�����෵��һ����֤���ʱ䶯��ѯ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgSingleIterator: public CSysMarginRateChgIterator
{
private:
	CSysMarginRateChg *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMarginRateChgSingleIterator(CSysMarginRateChgFactory *pFactory,CSysMarginRateChg *pResult)
		:CSysMarginRateChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMarginRateChgSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMarginRateChg
	///@return	��һ����������CSysMarginRateChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMarginRateChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMarginRateChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMarginRateChg * pSysMarginRateChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgPredict���ж�һ����֤���ʱ䶯��ѯ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMarginRateChg	Ҫ���жϵı�֤���ʱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMarginRateChg *pSysMarginRateChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgAndPredict�Ƕ�������֤���ʱ䶯��ѯν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgAndPredict : public CSysMarginRateChgPredict
{
private:
	CSysMarginRateChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMarginRateChgAndPredict(CSysMarginRateChgPredict *p1, CSysMarginRateChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMarginRateChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMarginRateChg	Ҫ���жϵı�֤���ʱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMarginRateChg *pSysMarginRateChg)
	{
		return m_p1->isValid(pSysMarginRateChg) && m_p2->isValid(pSysMarginRateChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgOrPredict�Ƕ�������֤���ʱ䶯��ѯν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgOrPredict : public CSysMarginRateChgPredict
{
private:
	CSysMarginRateChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMarginRateChgOrPredict(CSysMarginRateChgPredict *p1, CSysMarginRateChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMarginRateChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMarginRateChg	Ҫ���жϵı�֤���ʱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMarginRateChg *pSysMarginRateChg)
	{
		return m_p1->isValid(pSysMarginRateChg) || m_p2->isValid(pSysMarginRateChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgNotPredict�Ƕ�һ����֤���ʱ䶯��ѯν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgNotPredict : public CSysMarginRateChgPredict
{
private:
	CSysMarginRateChgPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMarginRateChgNotPredict(CSysMarginRateChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMarginRateChgNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMarginRateChg	Ҫ���жϵı�֤���ʱ䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMarginRateChg *pSysMarginRateChg)
	{
		return !m_predict->isValid(pSysMarginRateChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgFilter��һ�������еı�֤���ʱ䶯��ѯö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgFilter: public CSysMarginRateChgIterator
{
private:
	CSysMarginRateChgIterator *m_baseIterator;
	CSysMarginRateChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMarginRateChgFilter(CSysMarginRateChgIterator *pBaseIterator, CSysMarginRateChgPredict *pPredict, bool continueResult=false)
		:CSysMarginRateChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMarginRateChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMarginRateChg
	///@return	��һ����������CSysMarginRateChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMarginRateChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMarginRateChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMarginRateChg * pSysMarginRateChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgLinkIterator������������֤���ʱ䶯��ѯö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgLinkIterator: public CSysMarginRateChgIterator
{
private:
	CSysMarginRateChgIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMarginRateChgLinkIterator(CSysMarginRateChgIterator *pBaseIterator1,CSysMarginRateChgIterator *pBaseIterator2)
		:CSysMarginRateChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMarginRateChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMarginRateChg
	///@return	��һ����������CSysMarginRateChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMarginRateChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMarginRateChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMarginRateChg * pSysMarginRateChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgSingleIterator�����෵��һ��IP��ַ�䶯��ѯ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgSingleIterator: public CSysUserIpChgIterator
{
private:
	CSysUserIpChg *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysUserIpChgSingleIterator(CSysUserIpChgFactory *pFactory,CSysUserIpChg *pResult)
		:CSysUserIpChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysUserIpChgSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysUserIpChg
	///@return	��һ����������CSysUserIpChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserIpChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysUserIpChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserIpChg * pSysUserIpChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgPredict���ж�һ��IP��ַ�䶯��ѯ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysUserIpChg	Ҫ���жϵ�IP��ַ�䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysUserIpChg *pSysUserIpChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgAndPredict�Ƕ�����IP��ַ�䶯��ѯν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgAndPredict : public CSysUserIpChgPredict
{
private:
	CSysUserIpChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysUserIpChgAndPredict(CSysUserIpChgPredict *p1, CSysUserIpChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysUserIpChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysUserIpChg	Ҫ���жϵ�IP��ַ�䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysUserIpChg *pSysUserIpChg)
	{
		return m_p1->isValid(pSysUserIpChg) && m_p2->isValid(pSysUserIpChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgOrPredict�Ƕ�����IP��ַ�䶯��ѯν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgOrPredict : public CSysUserIpChgPredict
{
private:
	CSysUserIpChgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysUserIpChgOrPredict(CSysUserIpChgPredict *p1, CSysUserIpChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysUserIpChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysUserIpChg	Ҫ���жϵ�IP��ַ�䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysUserIpChg *pSysUserIpChg)
	{
		return m_p1->isValid(pSysUserIpChg) || m_p2->isValid(pSysUserIpChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgNotPredict�Ƕ�һ��IP��ַ�䶯��ѯν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgNotPredict : public CSysUserIpChgPredict
{
private:
	CSysUserIpChgPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysUserIpChgNotPredict(CSysUserIpChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysUserIpChgNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysUserIpChg	Ҫ���жϵ�IP��ַ�䶯��ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysUserIpChg *pSysUserIpChg)
	{
		return !m_predict->isValid(pSysUserIpChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgFilter��һ�������е�IP��ַ�䶯��ѯö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgFilter: public CSysUserIpChgIterator
{
private:
	CSysUserIpChgIterator *m_baseIterator;
	CSysUserIpChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysUserIpChgFilter(CSysUserIpChgIterator *pBaseIterator, CSysUserIpChgPredict *pPredict, bool continueResult=false)
		:CSysUserIpChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysUserIpChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysUserIpChg
	///@return	��һ����������CSysUserIpChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserIpChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysUserIpChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserIpChg * pSysUserIpChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgLinkIterator����������IP��ַ�䶯��ѯö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgLinkIterator: public CSysUserIpChgIterator
{
private:
	CSysUserIpChgIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysUserIpChgLinkIterator(CSysUserIpChgIterator *pBaseIterator1,CSysUserIpChgIterator *pBaseIterator2)
		:CSysUserIpChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysUserIpChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysUserIpChg
	///@return	��һ����������CSysUserIpChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserIpChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysUserIpChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserIpChg * pSysUserIpChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysPartTradeSingleIterator�����෵��һ����Ա������Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeSingleIterator: public CSysPartTradeIterator
{
private:
	CSysPartTrade *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysPartTradeSingleIterator(CSysPartTradeFactory *pFactory,CSysPartTrade *pResult)
		:CSysPartTradeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysPartTradeSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysPartTrade
	///@return	��һ����������CSysPartTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPartTrade *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPartTrade ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPartTrade * pSysPartTrade,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradePredict���ж�һ����Ա������Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysPartTrade	Ҫ���жϵĻ�Ա������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPartTrade *pSysPartTrade)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeAndPredict�Ƕ�������Ա������Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeAndPredict : public CSysPartTradePredict
{
private:
	CSysPartTradePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysPartTradeAndPredict(CSysPartTradePredict *p1, CSysPartTradePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysPartTradeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysPartTrade	Ҫ���жϵĻ�Ա������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPartTrade *pSysPartTrade)
	{
		return m_p1->isValid(pSysPartTrade) && m_p2->isValid(pSysPartTrade);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeOrPredict�Ƕ�������Ա������Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeOrPredict : public CSysPartTradePredict
{
private:
	CSysPartTradePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysPartTradeOrPredict(CSysPartTradePredict *p1, CSysPartTradePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysPartTradeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysPartTrade	Ҫ���жϵĻ�Ա������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPartTrade *pSysPartTrade)
	{
		return m_p1->isValid(pSysPartTrade) || m_p2->isValid(pSysPartTrade);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeNotPredict�Ƕ�һ����Ա������Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeNotPredict : public CSysPartTradePredict
{
private:
	CSysPartTradePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysPartTradeNotPredict(CSysPartTradePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysPartTradeNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysPartTrade	Ҫ���жϵĻ�Ա������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysPartTrade *pSysPartTrade)
	{
		return !m_predict->isValid(pSysPartTrade);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeFilter��һ�������еĻ�Ա������Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeFilter: public CSysPartTradeIterator
{
private:
	CSysPartTradeIterator *m_baseIterator;
	CSysPartTradePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysPartTradeFilter(CSysPartTradeIterator *pBaseIterator, CSysPartTradePredict *pPredict, bool continueResult=false)
		:CSysPartTradeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysPartTradeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysPartTrade
	///@return	��һ����������CSysPartTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPartTrade *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPartTrade ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPartTrade * pSysPartTrade,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeLinkIterator������������Ա������Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeLinkIterator: public CSysPartTradeIterator
{
private:
	CSysPartTradeIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysPartTradeLinkIterator(CSysPartTradeIterator *pBaseIterator1,CSysPartTradeIterator *pBaseIterator2)
		:CSysPartTradeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysPartTradeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysPartTrade
	///@return	��һ����������CSysPartTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPartTrade *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPartTrade ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPartTrade * pSysPartTrade,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrSingleIterator�����෵��һ������״ָ̬���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrSingleIterator: public CSysMdbObjectAttrIterator
{
private:
	CSysMdbObjectAttr *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMdbObjectAttrSingleIterator(CSysMdbObjectAttrFactory *pFactory,CSysMdbObjectAttr *pResult)
		:CSysMdbObjectAttrIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMdbObjectAttrSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMdbObjectAttr
	///@return	��һ����������CSysMdbObjectAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbObjectAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbObjectAttr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbObjectAttr * pSysMdbObjectAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrPredict���ж�һ������״ָ̬���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbObjectAttr	Ҫ���жϵĶ���״ָ̬��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbObjectAttr *pSysMdbObjectAttr)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrAndPredict�Ƕ���������״ָ̬��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrAndPredict : public CSysMdbObjectAttrPredict
{
private:
	CSysMdbObjectAttrPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbObjectAttrAndPredict(CSysMdbObjectAttrPredict *p1, CSysMdbObjectAttrPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbObjectAttrAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbObjectAttr	Ҫ���жϵĶ���״ָ̬��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return m_p1->isValid(pSysMdbObjectAttr) && m_p2->isValid(pSysMdbObjectAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrOrPredict�Ƕ���������״ָ̬��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrOrPredict : public CSysMdbObjectAttrPredict
{
private:
	CSysMdbObjectAttrPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbObjectAttrOrPredict(CSysMdbObjectAttrPredict *p1, CSysMdbObjectAttrPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbObjectAttrOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbObjectAttr	Ҫ���жϵĶ���״ָ̬��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return m_p1->isValid(pSysMdbObjectAttr) || m_p2->isValid(pSysMdbObjectAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrNotPredict�Ƕ�һ������״ָ̬��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrNotPredict : public CSysMdbObjectAttrPredict
{
private:
	CSysMdbObjectAttrPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMdbObjectAttrNotPredict(CSysMdbObjectAttrPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMdbObjectAttrNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbObjectAttr	Ҫ���жϵĶ���״ָ̬��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return !m_predict->isValid(pSysMdbObjectAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrFilter��һ�������еĶ���״ָ̬��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrFilter: public CSysMdbObjectAttrIterator
{
private:
	CSysMdbObjectAttrIterator *m_baseIterator;
	CSysMdbObjectAttrPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMdbObjectAttrFilter(CSysMdbObjectAttrIterator *pBaseIterator, CSysMdbObjectAttrPredict *pPredict, bool continueResult=false)
		:CSysMdbObjectAttrIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMdbObjectAttrFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMdbObjectAttr
	///@return	��һ����������CSysMdbObjectAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbObjectAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbObjectAttr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbObjectAttr * pSysMdbObjectAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrLinkIterator��������������״ָ̬��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrLinkIterator: public CSysMdbObjectAttrIterator
{
private:
	CSysMdbObjectAttrIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMdbObjectAttrLinkIterator(CSysMdbObjectAttrIterator *pBaseIterator1,CSysMdbObjectAttrIterator *pBaseIterator2)
		:CSysMdbObjectAttrIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMdbObjectAttrLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMdbObjectAttr
	///@return	��һ����������CSysMdbObjectAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbObjectAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbObjectAttr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbObjectAttr * pSysMdbObjectAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoSingleIterator�����෵��һ����־�ļ����ݴ�����Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoSingleIterator: public CSysMdbSyslogInfoIterator
{
private:
	CSysMdbSyslogInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMdbSyslogInfoSingleIterator(CSysMdbSyslogInfoFactory *pFactory,CSysMdbSyslogInfo *pResult)
		:CSysMdbSyslogInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMdbSyslogInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMdbSyslogInfo
	///@return	��һ����������CSysMdbSyslogInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbSyslogInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbSyslogInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbSyslogInfo * pSysMdbSyslogInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoPredict���ж�һ����־�ļ����ݴ�����Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbSyslogInfo	Ҫ���жϵ���־�ļ����ݴ�����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbSyslogInfo *pSysMdbSyslogInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoAndPredict�Ƕ�������־�ļ����ݴ�����Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoAndPredict : public CSysMdbSyslogInfoPredict
{
private:
	CSysMdbSyslogInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbSyslogInfoAndPredict(CSysMdbSyslogInfoPredict *p1, CSysMdbSyslogInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbSyslogInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbSyslogInfo	Ҫ���жϵ���־�ļ����ݴ�����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return m_p1->isValid(pSysMdbSyslogInfo) && m_p2->isValid(pSysMdbSyslogInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoOrPredict�Ƕ�������־�ļ����ݴ�����Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoOrPredict : public CSysMdbSyslogInfoPredict
{
private:
	CSysMdbSyslogInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbSyslogInfoOrPredict(CSysMdbSyslogInfoPredict *p1, CSysMdbSyslogInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbSyslogInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbSyslogInfo	Ҫ���жϵ���־�ļ����ݴ�����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return m_p1->isValid(pSysMdbSyslogInfo) || m_p2->isValid(pSysMdbSyslogInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoNotPredict�Ƕ�һ����־�ļ����ݴ�����Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoNotPredict : public CSysMdbSyslogInfoPredict
{
private:
	CSysMdbSyslogInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMdbSyslogInfoNotPredict(CSysMdbSyslogInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMdbSyslogInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbSyslogInfo	Ҫ���жϵ���־�ļ����ݴ�����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return !m_predict->isValid(pSysMdbSyslogInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoFilter��һ�������е���־�ļ����ݴ�����Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoFilter: public CSysMdbSyslogInfoIterator
{
private:
	CSysMdbSyslogInfoIterator *m_baseIterator;
	CSysMdbSyslogInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMdbSyslogInfoFilter(CSysMdbSyslogInfoIterator *pBaseIterator, CSysMdbSyslogInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbSyslogInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMdbSyslogInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMdbSyslogInfo
	///@return	��һ����������CSysMdbSyslogInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbSyslogInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbSyslogInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbSyslogInfo * pSysMdbSyslogInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoLinkIterator������������־�ļ����ݴ�����Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoLinkIterator: public CSysMdbSyslogInfoIterator
{
private:
	CSysMdbSyslogInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMdbSyslogInfoLinkIterator(CSysMdbSyslogInfoIterator *pBaseIterator1,CSysMdbSyslogInfoIterator *pBaseIterator2)
		:CSysMdbSyslogInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMdbSyslogInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMdbSyslogInfo
	///@return	��һ����������CSysMdbSyslogInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbSyslogInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbSyslogInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbSyslogInfo * pSysMdbSyslogInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysUserInfoSingleIterator�����෵��һ���û���Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoSingleIterator: public CSysUserInfoIterator
{
private:
	CSysUserInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysUserInfoSingleIterator(CSysUserInfoFactory *pFactory,CSysUserInfo *pResult)
		:CSysUserInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysUserInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysUserInfo
	///@return	��һ����������CSysUserInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysUserInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserInfo * pSysUserInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoPredict���ж�һ���û���Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysUserInfo	Ҫ���жϵ��û���Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysUserInfo *pSysUserInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoAndPredict�Ƕ������û���Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoAndPredict : public CSysUserInfoPredict
{
private:
	CSysUserInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysUserInfoAndPredict(CSysUserInfoPredict *p1, CSysUserInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysUserInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysUserInfo	Ҫ���жϵ��û���Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysUserInfo *pSysUserInfo)
	{
		return m_p1->isValid(pSysUserInfo) && m_p2->isValid(pSysUserInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoOrPredict�Ƕ������û���Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoOrPredict : public CSysUserInfoPredict
{
private:
	CSysUserInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysUserInfoOrPredict(CSysUserInfoPredict *p1, CSysUserInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysUserInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysUserInfo	Ҫ���жϵ��û���Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysUserInfo *pSysUserInfo)
	{
		return m_p1->isValid(pSysUserInfo) || m_p2->isValid(pSysUserInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoNotPredict�Ƕ�һ���û���Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoNotPredict : public CSysUserInfoPredict
{
private:
	CSysUserInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysUserInfoNotPredict(CSysUserInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysUserInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysUserInfo	Ҫ���жϵ��û���Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysUserInfo *pSysUserInfo)
	{
		return !m_predict->isValid(pSysUserInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoFilter��һ�������е��û���Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoFilter: public CSysUserInfoIterator
{
private:
	CSysUserInfoIterator *m_baseIterator;
	CSysUserInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysUserInfoFilter(CSysUserInfoIterator *pBaseIterator, CSysUserInfoPredict *pPredict, bool continueResult=false)
		:CSysUserInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysUserInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysUserInfo
	///@return	��һ����������CSysUserInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysUserInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserInfo * pSysUserInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoLinkIterator�����������û���Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoLinkIterator: public CSysUserInfoIterator
{
private:
	CSysUserInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysUserInfoLinkIterator(CSysUserInfoIterator *pBaseIterator1,CSysUserInfoIterator *pBaseIterator2)
		:CSysUserInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysUserInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysUserInfo
	///@return	��һ����������CSysUserInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysUserInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserInfo * pSysUserInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoSingleIterator�����෵��һ�������û���Ϣ��ѯӦ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoSingleIterator: public CSysOnlineUserInfoIterator
{
private:
	CSysOnlineUserInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysOnlineUserInfoSingleIterator(CSysOnlineUserInfoFactory *pFactory,CSysOnlineUserInfo *pResult)
		:CSysOnlineUserInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysOnlineUserInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysOnlineUserInfo
	///@return	��һ����������CSysOnlineUserInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysOnlineUserInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysOnlineUserInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysOnlineUserInfo * pSysOnlineUserInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoPredict���ж�һ�������û���Ϣ��ѯӦ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysOnlineUserInfo	Ҫ���жϵ������û���Ϣ��ѯӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysOnlineUserInfo *pSysOnlineUserInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoAndPredict�Ƕ����������û���Ϣ��ѯӦ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoAndPredict : public CSysOnlineUserInfoPredict
{
private:
	CSysOnlineUserInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysOnlineUserInfoAndPredict(CSysOnlineUserInfoPredict *p1, CSysOnlineUserInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysOnlineUserInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysOnlineUserInfo	Ҫ���жϵ������û���Ϣ��ѯӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return m_p1->isValid(pSysOnlineUserInfo) && m_p2->isValid(pSysOnlineUserInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoOrPredict�Ƕ����������û���Ϣ��ѯӦ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoOrPredict : public CSysOnlineUserInfoPredict
{
private:
	CSysOnlineUserInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysOnlineUserInfoOrPredict(CSysOnlineUserInfoPredict *p1, CSysOnlineUserInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysOnlineUserInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysOnlineUserInfo	Ҫ���жϵ������û���Ϣ��ѯӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return m_p1->isValid(pSysOnlineUserInfo) || m_p2->isValid(pSysOnlineUserInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoNotPredict�Ƕ�һ�������û���Ϣ��ѯӦ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoNotPredict : public CSysOnlineUserInfoPredict
{
private:
	CSysOnlineUserInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysOnlineUserInfoNotPredict(CSysOnlineUserInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysOnlineUserInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysOnlineUserInfo	Ҫ���жϵ������û���Ϣ��ѯӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return !m_predict->isValid(pSysOnlineUserInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoFilter��һ�������е������û���Ϣ��ѯӦ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoFilter: public CSysOnlineUserInfoIterator
{
private:
	CSysOnlineUserInfoIterator *m_baseIterator;
	CSysOnlineUserInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysOnlineUserInfoFilter(CSysOnlineUserInfoIterator *pBaseIterator, CSysOnlineUserInfoPredict *pPredict, bool continueResult=false)
		:CSysOnlineUserInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysOnlineUserInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysOnlineUserInfo
	///@return	��һ����������CSysOnlineUserInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysOnlineUserInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysOnlineUserInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysOnlineUserInfo * pSysOnlineUserInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoLinkIterator���������������û���Ϣ��ѯӦ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoLinkIterator: public CSysOnlineUserInfoIterator
{
private:
	CSysOnlineUserInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysOnlineUserInfoLinkIterator(CSysOnlineUserInfoIterator *pBaseIterator1,CSysOnlineUserInfoIterator *pBaseIterator2)
		:CSysOnlineUserInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysOnlineUserInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysOnlineUserInfo
	///@return	��һ����������CSysOnlineUserInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysOnlineUserInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysOnlineUserInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysOnlineUserInfo * pSysOnlineUserInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysWarningEventSingleIterator�����෵��һ���澯�¼���ѯӦ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventSingleIterator: public CSysWarningEventIterator
{
private:
	CSysWarningEvent *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysWarningEventSingleIterator(CSysWarningEventFactory *pFactory,CSysWarningEvent *pResult)
		:CSysWarningEventIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysWarningEventSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysWarningEvent
	///@return	��һ����������CSysWarningEvent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysWarningEvent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysWarningEvent ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysWarningEvent * pSysWarningEvent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventPredict���ж�һ���澯�¼���ѯӦ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysWarningEvent	Ҫ���жϵĸ澯�¼���ѯӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysWarningEvent *pSysWarningEvent)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventAndPredict�Ƕ������澯�¼���ѯӦ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventAndPredict : public CSysWarningEventPredict
{
private:
	CSysWarningEventPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysWarningEventAndPredict(CSysWarningEventPredict *p1, CSysWarningEventPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysWarningEventAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysWarningEvent	Ҫ���жϵĸ澯�¼���ѯӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysWarningEvent *pSysWarningEvent)
	{
		return m_p1->isValid(pSysWarningEvent) && m_p2->isValid(pSysWarningEvent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventOrPredict�Ƕ������澯�¼���ѯӦ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventOrPredict : public CSysWarningEventPredict
{
private:
	CSysWarningEventPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysWarningEventOrPredict(CSysWarningEventPredict *p1, CSysWarningEventPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysWarningEventOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysWarningEvent	Ҫ���жϵĸ澯�¼���ѯӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysWarningEvent *pSysWarningEvent)
	{
		return m_p1->isValid(pSysWarningEvent) || m_p2->isValid(pSysWarningEvent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventNotPredict�Ƕ�һ���澯�¼���ѯӦ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventNotPredict : public CSysWarningEventPredict
{
private:
	CSysWarningEventPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysWarningEventNotPredict(CSysWarningEventPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysWarningEventNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysWarningEvent	Ҫ���жϵĸ澯�¼���ѯӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysWarningEvent *pSysWarningEvent)
	{
		return !m_predict->isValid(pSysWarningEvent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventFilter��һ�������еĸ澯�¼���ѯӦ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventFilter: public CSysWarningEventIterator
{
private:
	CSysWarningEventIterator *m_baseIterator;
	CSysWarningEventPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysWarningEventFilter(CSysWarningEventIterator *pBaseIterator, CSysWarningEventPredict *pPredict, bool continueResult=false)
		:CSysWarningEventIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysWarningEventFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysWarningEvent
	///@return	��һ����������CSysWarningEvent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysWarningEvent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysWarningEvent ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysWarningEvent * pSysWarningEvent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventLinkIterator�����������澯�¼���ѯӦ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventLinkIterator: public CSysWarningEventIterator
{
private:
	CSysWarningEventIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysWarningEventLinkIterator(CSysWarningEventIterator *pBaseIterator1,CSysWarningEventIterator *pBaseIterator2)
		:CSysWarningEventIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysWarningEventLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysWarningEvent
	///@return	��һ����������CSysWarningEvent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysWarningEvent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysWarningEvent ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysWarningEvent * pSysWarningEvent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysWarningQuerySingleIterator�����෵��һ���澯��ϸӦ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQuerySingleIterator: public CSysWarningQueryIterator
{
private:
	CSysWarningQuery *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysWarningQuerySingleIterator(CSysWarningQueryFactory *pFactory,CSysWarningQuery *pResult)
		:CSysWarningQueryIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysWarningQuerySingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysWarningQuery
	///@return	��һ����������CSysWarningQuery������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysWarningQuery *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysWarningQuery ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysWarningQuery * pSysWarningQuery,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryPredict���ж�һ���澯��ϸӦ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysWarningQuery	Ҫ���жϵĸ澯��ϸӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysWarningQuery *pSysWarningQuery)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryAndPredict�Ƕ������澯��ϸӦ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryAndPredict : public CSysWarningQueryPredict
{
private:
	CSysWarningQueryPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysWarningQueryAndPredict(CSysWarningQueryPredict *p1, CSysWarningQueryPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysWarningQueryAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysWarningQuery	Ҫ���жϵĸ澯��ϸӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysWarningQuery *pSysWarningQuery)
	{
		return m_p1->isValid(pSysWarningQuery) && m_p2->isValid(pSysWarningQuery);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryOrPredict�Ƕ������澯��ϸӦ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryOrPredict : public CSysWarningQueryPredict
{
private:
	CSysWarningQueryPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysWarningQueryOrPredict(CSysWarningQueryPredict *p1, CSysWarningQueryPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysWarningQueryOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysWarningQuery	Ҫ���жϵĸ澯��ϸӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysWarningQuery *pSysWarningQuery)
	{
		return m_p1->isValid(pSysWarningQuery) || m_p2->isValid(pSysWarningQuery);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryNotPredict�Ƕ�һ���澯��ϸӦ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryNotPredict : public CSysWarningQueryPredict
{
private:
	CSysWarningQueryPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysWarningQueryNotPredict(CSysWarningQueryPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysWarningQueryNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysWarningQuery	Ҫ���жϵĸ澯��ϸӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysWarningQuery *pSysWarningQuery)
	{
		return !m_predict->isValid(pSysWarningQuery);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryFilter��һ�������еĸ澯��ϸӦ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryFilter: public CSysWarningQueryIterator
{
private:
	CSysWarningQueryIterator *m_baseIterator;
	CSysWarningQueryPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysWarningQueryFilter(CSysWarningQueryIterator *pBaseIterator, CSysWarningQueryPredict *pPredict, bool continueResult=false)
		:CSysWarningQueryIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysWarningQueryFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysWarningQuery
	///@return	��һ����������CSysWarningQuery������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysWarningQuery *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysWarningQuery ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysWarningQuery * pSysWarningQuery,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryLinkIterator�����������澯��ϸӦ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryLinkIterator: public CSysWarningQueryIterator
{
private:
	CSysWarningQueryIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysWarningQueryLinkIterator(CSysWarningQueryIterator *pBaseIterator1,CSysWarningQueryIterator *pBaseIterator2)
		:CSysWarningQueryIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysWarningQueryLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysWarningQuery
	///@return	��һ����������CSysWarningQuery������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysWarningQuery *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysWarningQuery ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysWarningQuery * pSysWarningQuery,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSyslogEventSingleIterator�����෵��һ����־�¼���ѯӦ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventSingleIterator: public CSyslogEventIterator
{
private:
	CSyslogEvent *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSyslogEventSingleIterator(CSyslogEventFactory *pFactory,CSyslogEvent *pResult)
		:CSyslogEventIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSyslogEventSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSyslogEvent
	///@return	��һ����������CSyslogEvent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSyslogEvent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSyslogEvent ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSyslogEvent * pSyslogEvent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventPredict���ж�һ����־�¼���ѯӦ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSyslogEvent	Ҫ���жϵ���־�¼���ѯӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSyslogEvent *pSyslogEvent)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventAndPredict�Ƕ�������־�¼���ѯӦ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventAndPredict : public CSyslogEventPredict
{
private:
	CSyslogEventPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSyslogEventAndPredict(CSyslogEventPredict *p1, CSyslogEventPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSyslogEventAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSyslogEvent	Ҫ���жϵ���־�¼���ѯӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSyslogEvent *pSyslogEvent)
	{
		return m_p1->isValid(pSyslogEvent) && m_p2->isValid(pSyslogEvent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventOrPredict�Ƕ�������־�¼���ѯӦ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventOrPredict : public CSyslogEventPredict
{
private:
	CSyslogEventPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSyslogEventOrPredict(CSyslogEventPredict *p1, CSyslogEventPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSyslogEventOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSyslogEvent	Ҫ���жϵ���־�¼���ѯӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSyslogEvent *pSyslogEvent)
	{
		return m_p1->isValid(pSyslogEvent) || m_p2->isValid(pSyslogEvent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventNotPredict�Ƕ�һ����־�¼���ѯӦ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventNotPredict : public CSyslogEventPredict
{
private:
	CSyslogEventPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSyslogEventNotPredict(CSyslogEventPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSyslogEventNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSyslogEvent	Ҫ���жϵ���־�¼���ѯӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSyslogEvent *pSyslogEvent)
	{
		return !m_predict->isValid(pSyslogEvent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventFilter��һ�������е���־�¼���ѯӦ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventFilter: public CSyslogEventIterator
{
private:
	CSyslogEventIterator *m_baseIterator;
	CSyslogEventPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSyslogEventFilter(CSyslogEventIterator *pBaseIterator, CSyslogEventPredict *pPredict, bool continueResult=false)
		:CSyslogEventIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSyslogEventFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSyslogEvent
	///@return	��һ����������CSyslogEvent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSyslogEvent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSyslogEvent ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSyslogEvent * pSyslogEvent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventLinkIterator������������־�¼���ѯӦ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventLinkIterator: public CSyslogEventIterator
{
private:
	CSyslogEventIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSyslogEventLinkIterator(CSyslogEventIterator *pBaseIterator1,CSyslogEventIterator *pBaseIterator2)
		:CSyslogEventIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSyslogEventLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSyslogEvent
	///@return	��һ����������CSyslogEvent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSyslogEvent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSyslogEvent ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSyslogEvent * pSyslogEvent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysEventDescripSingleIterator�����෵��һ���¼�������ѯ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripSingleIterator: public CSysEventDescripIterator
{
private:
	CSysEventDescrip *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysEventDescripSingleIterator(CSysEventDescripFactory *pFactory,CSysEventDescrip *pResult)
		:CSysEventDescripIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysEventDescripSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysEventDescrip
	///@return	��һ����������CSysEventDescrip������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysEventDescrip *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysEventDescrip ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysEventDescrip * pSysEventDescrip,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripPredict���ж�һ���¼�������ѯ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysEventDescrip	Ҫ���жϵ��¼�������ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysEventDescrip *pSysEventDescrip)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripAndPredict�Ƕ������¼�������ѯν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripAndPredict : public CSysEventDescripPredict
{
private:
	CSysEventDescripPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysEventDescripAndPredict(CSysEventDescripPredict *p1, CSysEventDescripPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysEventDescripAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysEventDescrip	Ҫ���жϵ��¼�������ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysEventDescrip *pSysEventDescrip)
	{
		return m_p1->isValid(pSysEventDescrip) && m_p2->isValid(pSysEventDescrip);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripOrPredict�Ƕ������¼�������ѯν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripOrPredict : public CSysEventDescripPredict
{
private:
	CSysEventDescripPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysEventDescripOrPredict(CSysEventDescripPredict *p1, CSysEventDescripPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysEventDescripOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysEventDescrip	Ҫ���жϵ��¼�������ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysEventDescrip *pSysEventDescrip)
	{
		return m_p1->isValid(pSysEventDescrip) || m_p2->isValid(pSysEventDescrip);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripNotPredict�Ƕ�һ���¼�������ѯν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripNotPredict : public CSysEventDescripPredict
{
private:
	CSysEventDescripPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysEventDescripNotPredict(CSysEventDescripPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysEventDescripNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysEventDescrip	Ҫ���жϵ��¼�������ѯ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysEventDescrip *pSysEventDescrip)
	{
		return !m_predict->isValid(pSysEventDescrip);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripFilter��һ�������е��¼�������ѯö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripFilter: public CSysEventDescripIterator
{
private:
	CSysEventDescripIterator *m_baseIterator;
	CSysEventDescripPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysEventDescripFilter(CSysEventDescripIterator *pBaseIterator, CSysEventDescripPredict *pPredict, bool continueResult=false)
		:CSysEventDescripIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysEventDescripFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysEventDescrip
	///@return	��һ����������CSysEventDescrip������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysEventDescrip *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysEventDescrip ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysEventDescrip * pSysEventDescrip,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripLinkIterator�����������¼�������ѯö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripLinkIterator: public CSysEventDescripIterator
{
private:
	CSysEventDescripIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysEventDescripLinkIterator(CSysEventDescripIterator *pBaseIterator1,CSysEventDescripIterator *pBaseIterator2)
		:CSysEventDescripIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysEventDescripLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysEventDescrip
	///@return	��һ����������CSysEventDescrip������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysEventDescrip *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysEventDescrip ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysEventDescrip * pSysEventDescrip,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonSingleIterator�����෵��һ������������Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonSingleIterator: public CRspQryHostEnvCommonIterator
{
private:
	CRspQryHostEnvCommon *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CRspQryHostEnvCommonSingleIterator(CRspQryHostEnvCommonFactory *pFactory,CRspQryHostEnvCommon *pResult)
		:CRspQryHostEnvCommonIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CRspQryHostEnvCommonSingleIterator(void)
	{
	}

	///Ѱ����һ������������CRspQryHostEnvCommon
	///@return	��һ����������CRspQryHostEnvCommon������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvCommon *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvCommon ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvCommon * pRspQryHostEnvCommon,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonPredict���ж�һ������������Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvCommon	Ҫ���жϵ�����������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvCommon *pRspQryHostEnvCommon)=0;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonAndPredict�Ƕ���������������Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonAndPredict : public CRspQryHostEnvCommonPredict
{
private:
	CRspQryHostEnvCommonPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CRspQryHostEnvCommonAndPredict(CRspQryHostEnvCommonPredict *p1, CRspQryHostEnvCommonPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CRspQryHostEnvCommonAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvCommon	Ҫ���жϵ�����������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return m_p1->isValid(pRspQryHostEnvCommon) && m_p2->isValid(pRspQryHostEnvCommon);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonOrPredict�Ƕ���������������Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonOrPredict : public CRspQryHostEnvCommonPredict
{
private:
	CRspQryHostEnvCommonPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CRspQryHostEnvCommonOrPredict(CRspQryHostEnvCommonPredict *p1, CRspQryHostEnvCommonPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CRspQryHostEnvCommonOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvCommon	Ҫ���жϵ�����������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return m_p1->isValid(pRspQryHostEnvCommon) || m_p2->isValid(pRspQryHostEnvCommon);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonNotPredict�Ƕ�һ������������Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonNotPredict : public CRspQryHostEnvCommonPredict
{
private:
	CRspQryHostEnvCommonPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CRspQryHostEnvCommonNotPredict(CRspQryHostEnvCommonPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CRspQryHostEnvCommonNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvCommon	Ҫ���жϵ�����������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return !m_predict->isValid(pRspQryHostEnvCommon);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonFilter��һ�������е�����������Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonFilter: public CRspQryHostEnvCommonIterator
{
private:
	CRspQryHostEnvCommonIterator *m_baseIterator;
	CRspQryHostEnvCommonPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CRspQryHostEnvCommonFilter(CRspQryHostEnvCommonIterator *pBaseIterator, CRspQryHostEnvCommonPredict *pPredict, bool continueResult=false)
		:CRspQryHostEnvCommonIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CRspQryHostEnvCommonFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CRspQryHostEnvCommon
	///@return	��һ����������CRspQryHostEnvCommon������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvCommon *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvCommon ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvCommon * pRspQryHostEnvCommon,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonLinkIterator��������������������Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonLinkIterator: public CRspQryHostEnvCommonIterator
{
private:
	CRspQryHostEnvCommonIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CRspQryHostEnvCommonLinkIterator(CRspQryHostEnvCommonIterator *pBaseIterator1,CRspQryHostEnvCommonIterator *pBaseIterator2)
		:CRspQryHostEnvCommonIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CRspQryHostEnvCommonLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CRspQryHostEnvCommon
	///@return	��һ����������CRspQryHostEnvCommon������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvCommon *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvCommon ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvCommon * pRspQryHostEnvCommon,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanSingleIterator�����෵��һ����������Lan��Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanSingleIterator: public CRspQryHostEnvLanIterator
{
private:
	CRspQryHostEnvLan *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CRspQryHostEnvLanSingleIterator(CRspQryHostEnvLanFactory *pFactory,CRspQryHostEnvLan *pResult)
		:CRspQryHostEnvLanIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CRspQryHostEnvLanSingleIterator(void)
	{
	}

	///Ѱ����һ������������CRspQryHostEnvLan
	///@return	��һ����������CRspQryHostEnvLan������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvLan *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvLan ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLan * pRspQryHostEnvLan,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanPredict���ж�һ����������Lan��Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvLan	Ҫ���жϵ���������Lan��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvLan *pRspQryHostEnvLan)=0;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanAndPredict�Ƕ�������������Lan��Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanAndPredict : public CRspQryHostEnvLanPredict
{
private:
	CRspQryHostEnvLanPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CRspQryHostEnvLanAndPredict(CRspQryHostEnvLanPredict *p1, CRspQryHostEnvLanPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CRspQryHostEnvLanAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvLan	Ҫ���жϵ���������Lan��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return m_p1->isValid(pRspQryHostEnvLan) && m_p2->isValid(pRspQryHostEnvLan);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanOrPredict�Ƕ�������������Lan��Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanOrPredict : public CRspQryHostEnvLanPredict
{
private:
	CRspQryHostEnvLanPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CRspQryHostEnvLanOrPredict(CRspQryHostEnvLanPredict *p1, CRspQryHostEnvLanPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CRspQryHostEnvLanOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvLan	Ҫ���жϵ���������Lan��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return m_p1->isValid(pRspQryHostEnvLan) || m_p2->isValid(pRspQryHostEnvLan);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanNotPredict�Ƕ�һ����������Lan��Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanNotPredict : public CRspQryHostEnvLanPredict
{
private:
	CRspQryHostEnvLanPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CRspQryHostEnvLanNotPredict(CRspQryHostEnvLanPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CRspQryHostEnvLanNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvLan	Ҫ���жϵ���������Lan��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return !m_predict->isValid(pRspQryHostEnvLan);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanFilter��һ�������е���������Lan��Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanFilter: public CRspQryHostEnvLanIterator
{
private:
	CRspQryHostEnvLanIterator *m_baseIterator;
	CRspQryHostEnvLanPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CRspQryHostEnvLanFilter(CRspQryHostEnvLanIterator *pBaseIterator, CRspQryHostEnvLanPredict *pPredict, bool continueResult=false)
		:CRspQryHostEnvLanIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CRspQryHostEnvLanFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CRspQryHostEnvLan
	///@return	��һ����������CRspQryHostEnvLan������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvLan *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvLan ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLan * pRspQryHostEnvLan,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanLinkIterator������������������Lan��Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanLinkIterator: public CRspQryHostEnvLanIterator
{
private:
	CRspQryHostEnvLanIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CRspQryHostEnvLanLinkIterator(CRspQryHostEnvLanIterator *pBaseIterator1,CRspQryHostEnvLanIterator *pBaseIterator2)
		:CRspQryHostEnvLanIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CRspQryHostEnvLanLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CRspQryHostEnvLan
	///@return	��һ����������CRspQryHostEnvLan������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvLan *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvLan ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLan * pRspQryHostEnvLan,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageSingleIterator�����෵��һ�����������洢�豸��Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageSingleIterator: public CRspQryHostEnvStorageIterator
{
private:
	CRspQryHostEnvStorage *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CRspQryHostEnvStorageSingleIterator(CRspQryHostEnvStorageFactory *pFactory,CRspQryHostEnvStorage *pResult)
		:CRspQryHostEnvStorageIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CRspQryHostEnvStorageSingleIterator(void)
	{
	}

	///Ѱ����һ������������CRspQryHostEnvStorage
	///@return	��һ����������CRspQryHostEnvStorage������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvStorage *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvStorage ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvStorage * pRspQryHostEnvStorage,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStoragePredict���ж�һ�����������洢�豸��Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStoragePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvStorage	Ҫ���жϵ����������洢�豸��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvStorage *pRspQryHostEnvStorage)=0;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageAndPredict�Ƕ��������������洢�豸��Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageAndPredict : public CRspQryHostEnvStoragePredict
{
private:
	CRspQryHostEnvStoragePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CRspQryHostEnvStorageAndPredict(CRspQryHostEnvStoragePredict *p1, CRspQryHostEnvStoragePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CRspQryHostEnvStorageAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvStorage	Ҫ���жϵ����������洢�豸��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return m_p1->isValid(pRspQryHostEnvStorage) && m_p2->isValid(pRspQryHostEnvStorage);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageOrPredict�Ƕ��������������洢�豸��Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageOrPredict : public CRspQryHostEnvStoragePredict
{
private:
	CRspQryHostEnvStoragePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CRspQryHostEnvStorageOrPredict(CRspQryHostEnvStoragePredict *p1, CRspQryHostEnvStoragePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CRspQryHostEnvStorageOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvStorage	Ҫ���жϵ����������洢�豸��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return m_p1->isValid(pRspQryHostEnvStorage) || m_p2->isValid(pRspQryHostEnvStorage);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageNotPredict�Ƕ�һ�����������洢�豸��Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageNotPredict : public CRspQryHostEnvStoragePredict
{
private:
	CRspQryHostEnvStoragePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CRspQryHostEnvStorageNotPredict(CRspQryHostEnvStoragePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CRspQryHostEnvStorageNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvStorage	Ҫ���жϵ����������洢�豸��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return !m_predict->isValid(pRspQryHostEnvStorage);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageFilter��һ�������е����������洢�豸��Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageFilter: public CRspQryHostEnvStorageIterator
{
private:
	CRspQryHostEnvStorageIterator *m_baseIterator;
	CRspQryHostEnvStoragePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CRspQryHostEnvStorageFilter(CRspQryHostEnvStorageIterator *pBaseIterator, CRspQryHostEnvStoragePredict *pPredict, bool continueResult=false)
		:CRspQryHostEnvStorageIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CRspQryHostEnvStorageFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CRspQryHostEnvStorage
	///@return	��һ����������CRspQryHostEnvStorage������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvStorage *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvStorage ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvStorage * pRspQryHostEnvStorage,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageLinkIterator�������������������洢�豸��Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageLinkIterator: public CRspQryHostEnvStorageIterator
{
private:
	CRspQryHostEnvStorageIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CRspQryHostEnvStorageLinkIterator(CRspQryHostEnvStorageIterator *pBaseIterator1,CRspQryHostEnvStorageIterator *pBaseIterator2)
		:CRspQryHostEnvStorageIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CRspQryHostEnvStorageLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CRspQryHostEnvStorage
	///@return	��һ����������CRspQryHostEnvStorage������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvStorage *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvStorage ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvStorage * pRspQryHostEnvStorage,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOSingleIterator�����෵��һ����������IO�豸��Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOSingleIterator: public CRspQryHostEnvIOIterator
{
private:
	CRspQryHostEnvIO *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CRspQryHostEnvIOSingleIterator(CRspQryHostEnvIOFactory *pFactory,CRspQryHostEnvIO *pResult)
		:CRspQryHostEnvIOIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CRspQryHostEnvIOSingleIterator(void)
	{
	}

	///Ѱ����һ������������CRspQryHostEnvIO
	///@return	��һ����������CRspQryHostEnvIO������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvIO *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvIO ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvIO * pRspQryHostEnvIO,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOPredict���ж�һ����������IO�豸��Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvIO	Ҫ���жϵ���������IO�豸��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvIO *pRspQryHostEnvIO)=0;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOAndPredict�Ƕ�������������IO�豸��Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOAndPredict : public CRspQryHostEnvIOPredict
{
private:
	CRspQryHostEnvIOPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CRspQryHostEnvIOAndPredict(CRspQryHostEnvIOPredict *p1, CRspQryHostEnvIOPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CRspQryHostEnvIOAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvIO	Ҫ���жϵ���������IO�豸��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return m_p1->isValid(pRspQryHostEnvIO) && m_p2->isValid(pRspQryHostEnvIO);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOOrPredict�Ƕ�������������IO�豸��Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOOrPredict : public CRspQryHostEnvIOPredict
{
private:
	CRspQryHostEnvIOPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CRspQryHostEnvIOOrPredict(CRspQryHostEnvIOPredict *p1, CRspQryHostEnvIOPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CRspQryHostEnvIOOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvIO	Ҫ���жϵ���������IO�豸��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return m_p1->isValid(pRspQryHostEnvIO) || m_p2->isValid(pRspQryHostEnvIO);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIONotPredict�Ƕ�һ����������IO�豸��Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIONotPredict : public CRspQryHostEnvIOPredict
{
private:
	CRspQryHostEnvIOPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CRspQryHostEnvIONotPredict(CRspQryHostEnvIOPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CRspQryHostEnvIONotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvIO	Ҫ���жϵ���������IO�豸��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return !m_predict->isValid(pRspQryHostEnvIO);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOFilter��һ�������е���������IO�豸��Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOFilter: public CRspQryHostEnvIOIterator
{
private:
	CRspQryHostEnvIOIterator *m_baseIterator;
	CRspQryHostEnvIOPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CRspQryHostEnvIOFilter(CRspQryHostEnvIOIterator *pBaseIterator, CRspQryHostEnvIOPredict *pPredict, bool continueResult=false)
		:CRspQryHostEnvIOIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CRspQryHostEnvIOFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CRspQryHostEnvIO
	///@return	��һ����������CRspQryHostEnvIO������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvIO *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvIO ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvIO * pRspQryHostEnvIO,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOLinkIterator������������������IO�豸��Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOLinkIterator: public CRspQryHostEnvIOIterator
{
private:
	CRspQryHostEnvIOIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CRspQryHostEnvIOLinkIterator(CRspQryHostEnvIOIterator *pBaseIterator1,CRspQryHostEnvIOIterator *pBaseIterator2)
		:CRspQryHostEnvIOIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CRspQryHostEnvIOLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CRspQryHostEnvIO
	///@return	��һ����������CRspQryHostEnvIO������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvIO *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvIO ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvIO * pRspQryHostEnvIO,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSSingleIterator�����෵��һ�����������ļ�ϵͳ��Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSSingleIterator: public CRspQryHostEnvFSIterator
{
private:
	CRspQryHostEnvFS *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CRspQryHostEnvFSSingleIterator(CRspQryHostEnvFSFactory *pFactory,CRspQryHostEnvFS *pResult)
		:CRspQryHostEnvFSIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CRspQryHostEnvFSSingleIterator(void)
	{
	}

	///Ѱ����һ������������CRspQryHostEnvFS
	///@return	��һ����������CRspQryHostEnvFS������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvFS *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvFS ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvFS * pRspQryHostEnvFS,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSPredict���ж�һ�����������ļ�ϵͳ��Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvFS	Ҫ���жϵ����������ļ�ϵͳ��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvFS *pRspQryHostEnvFS)=0;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSAndPredict�Ƕ��������������ļ�ϵͳ��Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSAndPredict : public CRspQryHostEnvFSPredict
{
private:
	CRspQryHostEnvFSPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CRspQryHostEnvFSAndPredict(CRspQryHostEnvFSPredict *p1, CRspQryHostEnvFSPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CRspQryHostEnvFSAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvFS	Ҫ���жϵ����������ļ�ϵͳ��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return m_p1->isValid(pRspQryHostEnvFS) && m_p2->isValid(pRspQryHostEnvFS);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSOrPredict�Ƕ��������������ļ�ϵͳ��Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSOrPredict : public CRspQryHostEnvFSPredict
{
private:
	CRspQryHostEnvFSPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CRspQryHostEnvFSOrPredict(CRspQryHostEnvFSPredict *p1, CRspQryHostEnvFSPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CRspQryHostEnvFSOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvFS	Ҫ���жϵ����������ļ�ϵͳ��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return m_p1->isValid(pRspQryHostEnvFS) || m_p2->isValid(pRspQryHostEnvFS);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSNotPredict�Ƕ�һ�����������ļ�ϵͳ��Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSNotPredict : public CRspQryHostEnvFSPredict
{
private:
	CRspQryHostEnvFSPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CRspQryHostEnvFSNotPredict(CRspQryHostEnvFSPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CRspQryHostEnvFSNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvFS	Ҫ���жϵ����������ļ�ϵͳ��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return !m_predict->isValid(pRspQryHostEnvFS);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSFilter��һ�������е����������ļ�ϵͳ��Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSFilter: public CRspQryHostEnvFSIterator
{
private:
	CRspQryHostEnvFSIterator *m_baseIterator;
	CRspQryHostEnvFSPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CRspQryHostEnvFSFilter(CRspQryHostEnvFSIterator *pBaseIterator, CRspQryHostEnvFSPredict *pPredict, bool continueResult=false)
		:CRspQryHostEnvFSIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CRspQryHostEnvFSFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CRspQryHostEnvFS
	///@return	��һ����������CRspQryHostEnvFS������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvFS *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvFS ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvFS * pRspQryHostEnvFS,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSLinkIterator�������������������ļ�ϵͳ��Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSLinkIterator: public CRspQryHostEnvFSIterator
{
private:
	CRspQryHostEnvFSIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CRspQryHostEnvFSLinkIterator(CRspQryHostEnvFSIterator *pBaseIterator1,CRspQryHostEnvFSIterator *pBaseIterator2)
		:CRspQryHostEnvFSIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CRspQryHostEnvFSLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CRspQryHostEnvFS
	///@return	��һ����������CRspQryHostEnvFS������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvFS *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvFS ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvFS * pRspQryHostEnvFS,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapSingleIterator�����෵��һ��������������������Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapSingleIterator: public CRspQryHostEnvSwapIterator
{
private:
	CRspQryHostEnvSwap *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CRspQryHostEnvSwapSingleIterator(CRspQryHostEnvSwapFactory *pFactory,CRspQryHostEnvSwap *pResult)
		:CRspQryHostEnvSwapIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CRspQryHostEnvSwapSingleIterator(void)
	{
	}

	///Ѱ����һ������������CRspQryHostEnvSwap
	///@return	��һ����������CRspQryHostEnvSwap������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvSwap *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvSwap ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvSwap * pRspQryHostEnvSwap,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapPredict���ж�һ��������������������Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvSwap	Ҫ���жϵ�������������������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvSwap *pRspQryHostEnvSwap)=0;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapAndPredict�Ƕ�����������������������Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapAndPredict : public CRspQryHostEnvSwapPredict
{
private:
	CRspQryHostEnvSwapPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CRspQryHostEnvSwapAndPredict(CRspQryHostEnvSwapPredict *p1, CRspQryHostEnvSwapPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CRspQryHostEnvSwapAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvSwap	Ҫ���жϵ�������������������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return m_p1->isValid(pRspQryHostEnvSwap) && m_p2->isValid(pRspQryHostEnvSwap);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapOrPredict�Ƕ�����������������������Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapOrPredict : public CRspQryHostEnvSwapPredict
{
private:
	CRspQryHostEnvSwapPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CRspQryHostEnvSwapOrPredict(CRspQryHostEnvSwapPredict *p1, CRspQryHostEnvSwapPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CRspQryHostEnvSwapOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvSwap	Ҫ���жϵ�������������������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return m_p1->isValid(pRspQryHostEnvSwap) || m_p2->isValid(pRspQryHostEnvSwap);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapNotPredict�Ƕ�һ��������������������Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapNotPredict : public CRspQryHostEnvSwapPredict
{
private:
	CRspQryHostEnvSwapPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CRspQryHostEnvSwapNotPredict(CRspQryHostEnvSwapPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CRspQryHostEnvSwapNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvSwap	Ҫ���жϵ�������������������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return !m_predict->isValid(pRspQryHostEnvSwap);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapFilter��һ�������е�������������������Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapFilter: public CRspQryHostEnvSwapIterator
{
private:
	CRspQryHostEnvSwapIterator *m_baseIterator;
	CRspQryHostEnvSwapPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CRspQryHostEnvSwapFilter(CRspQryHostEnvSwapIterator *pBaseIterator, CRspQryHostEnvSwapPredict *pPredict, bool continueResult=false)
		:CRspQryHostEnvSwapIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CRspQryHostEnvSwapFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CRspQryHostEnvSwap
	///@return	��һ����������CRspQryHostEnvSwap������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvSwap *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvSwap ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvSwap * pRspQryHostEnvSwap,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapLinkIterator����������������������������Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapLinkIterator: public CRspQryHostEnvSwapIterator
{
private:
	CRspQryHostEnvSwapIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CRspQryHostEnvSwapLinkIterator(CRspQryHostEnvSwapIterator *pBaseIterator1,CRspQryHostEnvSwapIterator *pBaseIterator2)
		:CRspQryHostEnvSwapIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CRspQryHostEnvSwapLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CRspQryHostEnvSwap
	///@return	��һ����������CRspQryHostEnvSwap������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvSwap *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvSwap ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvSwap * pRspQryHostEnvSwap,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgSingleIterator�����෵��һ��������������������Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgSingleIterator: public CRspQryHostEnvLanCfgIterator
{
private:
	CRspQryHostEnvLanCfg *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CRspQryHostEnvLanCfgSingleIterator(CRspQryHostEnvLanCfgFactory *pFactory,CRspQryHostEnvLanCfg *pResult)
		:CRspQryHostEnvLanCfgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CRspQryHostEnvLanCfgSingleIterator(void)
	{
	}

	///Ѱ����һ������������CRspQryHostEnvLanCfg
	///@return	��һ����������CRspQryHostEnvLanCfg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvLanCfg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvLanCfg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgPredict���ж�һ��������������������Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvLanCfg	Ҫ���жϵ�������������������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgAndPredict�Ƕ�����������������������Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgAndPredict : public CRspQryHostEnvLanCfgPredict
{
private:
	CRspQryHostEnvLanCfgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CRspQryHostEnvLanCfgAndPredict(CRspQryHostEnvLanCfgPredict *p1, CRspQryHostEnvLanCfgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CRspQryHostEnvLanCfgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvLanCfg	Ҫ���жϵ�������������������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return m_p1->isValid(pRspQryHostEnvLanCfg) && m_p2->isValid(pRspQryHostEnvLanCfg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgOrPredict�Ƕ�����������������������Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgOrPredict : public CRspQryHostEnvLanCfgPredict
{
private:
	CRspQryHostEnvLanCfgPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CRspQryHostEnvLanCfgOrPredict(CRspQryHostEnvLanCfgPredict *p1, CRspQryHostEnvLanCfgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CRspQryHostEnvLanCfgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvLanCfg	Ҫ���жϵ�������������������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return m_p1->isValid(pRspQryHostEnvLanCfg) || m_p2->isValid(pRspQryHostEnvLanCfg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgNotPredict�Ƕ�һ��������������������Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgNotPredict : public CRspQryHostEnvLanCfgPredict
{
private:
	CRspQryHostEnvLanCfgPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CRspQryHostEnvLanCfgNotPredict(CRspQryHostEnvLanCfgPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CRspQryHostEnvLanCfgNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRspQryHostEnvLanCfg	Ҫ���жϵ�������������������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return !m_predict->isValid(pRspQryHostEnvLanCfg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgFilter��һ�������е�������������������Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgFilter: public CRspQryHostEnvLanCfgIterator
{
private:
	CRspQryHostEnvLanCfgIterator *m_baseIterator;
	CRspQryHostEnvLanCfgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CRspQryHostEnvLanCfgFilter(CRspQryHostEnvLanCfgIterator *pBaseIterator, CRspQryHostEnvLanCfgPredict *pPredict, bool continueResult=false)
		:CRspQryHostEnvLanCfgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CRspQryHostEnvLanCfgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CRspQryHostEnvLanCfg
	///@return	��һ����������CRspQryHostEnvLanCfg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvLanCfg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvLanCfg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgLinkIterator����������������������������Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgLinkIterator: public CRspQryHostEnvLanCfgIterator
{
private:
	CRspQryHostEnvLanCfgIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CRspQryHostEnvLanCfgLinkIterator(CRspQryHostEnvLanCfgIterator *pBaseIterator1,CRspQryHostEnvLanCfgIterator *pBaseIterator2)
		:CRspQryHostEnvLanCfgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CRspQryHostEnvLanCfgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CRspQryHostEnvLanCfg
	///@return	��һ����������CRspQryHostEnvLanCfg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvLanCfg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvLanCfg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoSingleIterator�����෵��һ��CPU��Դʹ����Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoSingleIterator: public CSysMdbTopCpuInfoIterator
{
private:
	CSysMdbTopCpuInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMdbTopCpuInfoSingleIterator(CSysMdbTopCpuInfoFactory *pFactory,CSysMdbTopCpuInfo *pResult)
		:CSysMdbTopCpuInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMdbTopCpuInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMdbTopCpuInfo
	///@return	��һ����������CSysMdbTopCpuInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopCpuInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbTopCpuInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopCpuInfo * pSysMdbTopCpuInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoPredict���ж�һ��CPU��Դʹ����Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbTopCpuInfo	Ҫ���жϵ�CPU��Դʹ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoAndPredict�Ƕ�����CPU��Դʹ����Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoAndPredict : public CSysMdbTopCpuInfoPredict
{
private:
	CSysMdbTopCpuInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbTopCpuInfoAndPredict(CSysMdbTopCpuInfoPredict *p1, CSysMdbTopCpuInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbTopCpuInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbTopCpuInfo	Ҫ���жϵ�CPU��Դʹ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return m_p1->isValid(pSysMdbTopCpuInfo) && m_p2->isValid(pSysMdbTopCpuInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoOrPredict�Ƕ�����CPU��Դʹ����Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoOrPredict : public CSysMdbTopCpuInfoPredict
{
private:
	CSysMdbTopCpuInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbTopCpuInfoOrPredict(CSysMdbTopCpuInfoPredict *p1, CSysMdbTopCpuInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbTopCpuInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbTopCpuInfo	Ҫ���жϵ�CPU��Դʹ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return m_p1->isValid(pSysMdbTopCpuInfo) || m_p2->isValid(pSysMdbTopCpuInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoNotPredict�Ƕ�һ��CPU��Դʹ����Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoNotPredict : public CSysMdbTopCpuInfoPredict
{
private:
	CSysMdbTopCpuInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMdbTopCpuInfoNotPredict(CSysMdbTopCpuInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMdbTopCpuInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbTopCpuInfo	Ҫ���жϵ�CPU��Դʹ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return !m_predict->isValid(pSysMdbTopCpuInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoFilter��һ�������е�CPU��Դʹ����Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoFilter: public CSysMdbTopCpuInfoIterator
{
private:
	CSysMdbTopCpuInfoIterator *m_baseIterator;
	CSysMdbTopCpuInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMdbTopCpuInfoFilter(CSysMdbTopCpuInfoIterator *pBaseIterator, CSysMdbTopCpuInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbTopCpuInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMdbTopCpuInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMdbTopCpuInfo
	///@return	��һ����������CSysMdbTopCpuInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopCpuInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbTopCpuInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopCpuInfo * pSysMdbTopCpuInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoLinkIterator����������CPU��Դʹ����Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoLinkIterator: public CSysMdbTopCpuInfoIterator
{
private:
	CSysMdbTopCpuInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMdbTopCpuInfoLinkIterator(CSysMdbTopCpuInfoIterator *pBaseIterator1,CSysMdbTopCpuInfoIterator *pBaseIterator2)
		:CSysMdbTopCpuInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMdbTopCpuInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMdbTopCpuInfo
	///@return	��һ����������CSysMdbTopCpuInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopCpuInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbTopCpuInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopCpuInfo * pSysMdbTopCpuInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoSingleIterator�����෵��һ���ڴ���Դʹ����Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoSingleIterator: public CSysMdbTopMemInfoIterator
{
private:
	CSysMdbTopMemInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMdbTopMemInfoSingleIterator(CSysMdbTopMemInfoFactory *pFactory,CSysMdbTopMemInfo *pResult)
		:CSysMdbTopMemInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMdbTopMemInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMdbTopMemInfo
	///@return	��һ����������CSysMdbTopMemInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopMemInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbTopMemInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopMemInfo * pSysMdbTopMemInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoPredict���ж�һ���ڴ���Դʹ����Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbTopMemInfo	Ҫ���жϵ��ڴ���Դʹ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbTopMemInfo *pSysMdbTopMemInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoAndPredict�Ƕ������ڴ���Դʹ����Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoAndPredict : public CSysMdbTopMemInfoPredict
{
private:
	CSysMdbTopMemInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbTopMemInfoAndPredict(CSysMdbTopMemInfoPredict *p1, CSysMdbTopMemInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbTopMemInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbTopMemInfo	Ҫ���жϵ��ڴ���Դʹ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return m_p1->isValid(pSysMdbTopMemInfo) && m_p2->isValid(pSysMdbTopMemInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoOrPredict�Ƕ������ڴ���Դʹ����Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoOrPredict : public CSysMdbTopMemInfoPredict
{
private:
	CSysMdbTopMemInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbTopMemInfoOrPredict(CSysMdbTopMemInfoPredict *p1, CSysMdbTopMemInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbTopMemInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbTopMemInfo	Ҫ���жϵ��ڴ���Դʹ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return m_p1->isValid(pSysMdbTopMemInfo) || m_p2->isValid(pSysMdbTopMemInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoNotPredict�Ƕ�һ���ڴ���Դʹ����Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoNotPredict : public CSysMdbTopMemInfoPredict
{
private:
	CSysMdbTopMemInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMdbTopMemInfoNotPredict(CSysMdbTopMemInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMdbTopMemInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbTopMemInfo	Ҫ���жϵ��ڴ���Դʹ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return !m_predict->isValid(pSysMdbTopMemInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoFilter��һ�������е��ڴ���Դʹ����Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoFilter: public CSysMdbTopMemInfoIterator
{
private:
	CSysMdbTopMemInfoIterator *m_baseIterator;
	CSysMdbTopMemInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMdbTopMemInfoFilter(CSysMdbTopMemInfoIterator *pBaseIterator, CSysMdbTopMemInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbTopMemInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMdbTopMemInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMdbTopMemInfo
	///@return	��һ����������CSysMdbTopMemInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopMemInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbTopMemInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopMemInfo * pSysMdbTopMemInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoLinkIterator�����������ڴ���Դʹ����Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoLinkIterator: public CSysMdbTopMemInfoIterator
{
private:
	CSysMdbTopMemInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMdbTopMemInfoLinkIterator(CSysMdbTopMemInfoIterator *pBaseIterator1,CSysMdbTopMemInfoIterator *pBaseIterator2)
		:CSysMdbTopMemInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMdbTopMemInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMdbTopMemInfo
	///@return	��һ����������CSysMdbTopMemInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopMemInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbTopMemInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopMemInfo * pSysMdbTopMemInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoSingleIterator�����෵��һ��������Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoSingleIterator: public CSysMdbTopProcessInfoIterator
{
private:
	CSysMdbTopProcessInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMdbTopProcessInfoSingleIterator(CSysMdbTopProcessInfoFactory *pFactory,CSysMdbTopProcessInfo *pResult)
		:CSysMdbTopProcessInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMdbTopProcessInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMdbTopProcessInfo
	///@return	��һ����������CSysMdbTopProcessInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopProcessInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbTopProcessInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopProcessInfo * pSysMdbTopProcessInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoPredict���ж�һ��������Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbTopProcessInfo	Ҫ���жϵĽ�����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoAndPredict�Ƕ�����������Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoAndPredict : public CSysMdbTopProcessInfoPredict
{
private:
	CSysMdbTopProcessInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbTopProcessInfoAndPredict(CSysMdbTopProcessInfoPredict *p1, CSysMdbTopProcessInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbTopProcessInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbTopProcessInfo	Ҫ���жϵĽ�����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return m_p1->isValid(pSysMdbTopProcessInfo) && m_p2->isValid(pSysMdbTopProcessInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoOrPredict�Ƕ�����������Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoOrPredict : public CSysMdbTopProcessInfoPredict
{
private:
	CSysMdbTopProcessInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbTopProcessInfoOrPredict(CSysMdbTopProcessInfoPredict *p1, CSysMdbTopProcessInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbTopProcessInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbTopProcessInfo	Ҫ���жϵĽ�����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return m_p1->isValid(pSysMdbTopProcessInfo) || m_p2->isValid(pSysMdbTopProcessInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoNotPredict�Ƕ�һ��������Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoNotPredict : public CSysMdbTopProcessInfoPredict
{
private:
	CSysMdbTopProcessInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMdbTopProcessInfoNotPredict(CSysMdbTopProcessInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMdbTopProcessInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbTopProcessInfo	Ҫ���жϵĽ�����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return !m_predict->isValid(pSysMdbTopProcessInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoFilter��һ�������еĽ�����Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoFilter: public CSysMdbTopProcessInfoIterator
{
private:
	CSysMdbTopProcessInfoIterator *m_baseIterator;
	CSysMdbTopProcessInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMdbTopProcessInfoFilter(CSysMdbTopProcessInfoIterator *pBaseIterator, CSysMdbTopProcessInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbTopProcessInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMdbTopProcessInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMdbTopProcessInfo
	///@return	��һ����������CSysMdbTopProcessInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopProcessInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbTopProcessInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopProcessInfo * pSysMdbTopProcessInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoLinkIterator����������������Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoLinkIterator: public CSysMdbTopProcessInfoIterator
{
private:
	CSysMdbTopProcessInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMdbTopProcessInfoLinkIterator(CSysMdbTopProcessInfoIterator *pBaseIterator1,CSysMdbTopProcessInfoIterator *pBaseIterator2)
		:CSysMdbTopProcessInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMdbTopProcessInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMdbTopProcessInfo
	///@return	��һ����������CSysMdbTopProcessInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopProcessInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbTopProcessInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopProcessInfo * pSysMdbTopProcessInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoSingleIterator�����෵��һ���ļ�ϵͳ��Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoSingleIterator: public CSysMdbFileSystemInfoIterator
{
private:
	CSysMdbFileSystemInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMdbFileSystemInfoSingleIterator(CSysMdbFileSystemInfoFactory *pFactory,CSysMdbFileSystemInfo *pResult)
		:CSysMdbFileSystemInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMdbFileSystemInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMdbFileSystemInfo
	///@return	��һ����������CSysMdbFileSystemInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbFileSystemInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbFileSystemInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbFileSystemInfo * pSysMdbFileSystemInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoPredict���ж�һ���ļ�ϵͳ��Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbFileSystemInfo	Ҫ���жϵ��ļ�ϵͳ��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoAndPredict�Ƕ������ļ�ϵͳ��Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoAndPredict : public CSysMdbFileSystemInfoPredict
{
private:
	CSysMdbFileSystemInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbFileSystemInfoAndPredict(CSysMdbFileSystemInfoPredict *p1, CSysMdbFileSystemInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbFileSystemInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbFileSystemInfo	Ҫ���жϵ��ļ�ϵͳ��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return m_p1->isValid(pSysMdbFileSystemInfo) && m_p2->isValid(pSysMdbFileSystemInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoOrPredict�Ƕ������ļ�ϵͳ��Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoOrPredict : public CSysMdbFileSystemInfoPredict
{
private:
	CSysMdbFileSystemInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbFileSystemInfoOrPredict(CSysMdbFileSystemInfoPredict *p1, CSysMdbFileSystemInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbFileSystemInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbFileSystemInfo	Ҫ���жϵ��ļ�ϵͳ��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return m_p1->isValid(pSysMdbFileSystemInfo) || m_p2->isValid(pSysMdbFileSystemInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoNotPredict�Ƕ�һ���ļ�ϵͳ��Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoNotPredict : public CSysMdbFileSystemInfoPredict
{
private:
	CSysMdbFileSystemInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMdbFileSystemInfoNotPredict(CSysMdbFileSystemInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMdbFileSystemInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbFileSystemInfo	Ҫ���жϵ��ļ�ϵͳ��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return !m_predict->isValid(pSysMdbFileSystemInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoFilter��һ�������е��ļ�ϵͳ��Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoFilter: public CSysMdbFileSystemInfoIterator
{
private:
	CSysMdbFileSystemInfoIterator *m_baseIterator;
	CSysMdbFileSystemInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMdbFileSystemInfoFilter(CSysMdbFileSystemInfoIterator *pBaseIterator, CSysMdbFileSystemInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbFileSystemInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMdbFileSystemInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMdbFileSystemInfo
	///@return	��һ����������CSysMdbFileSystemInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbFileSystemInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbFileSystemInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbFileSystemInfo * pSysMdbFileSystemInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoLinkIterator�����������ļ�ϵͳ��Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoLinkIterator: public CSysMdbFileSystemInfoIterator
{
private:
	CSysMdbFileSystemInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMdbFileSystemInfoLinkIterator(CSysMdbFileSystemInfoIterator *pBaseIterator1,CSysMdbFileSystemInfoIterator *pBaseIterator2)
		:CSysMdbFileSystemInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMdbFileSystemInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMdbFileSystemInfo
	///@return	��һ����������CSysMdbFileSystemInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbFileSystemInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbFileSystemInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbFileSystemInfo * pSysMdbFileSystemInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoSingleIterator�����෵��һ������ʹ����Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoSingleIterator: public CSysMdbNetworkInfoIterator
{
private:
	CSysMdbNetworkInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMdbNetworkInfoSingleIterator(CSysMdbNetworkInfoFactory *pFactory,CSysMdbNetworkInfo *pResult)
		:CSysMdbNetworkInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMdbNetworkInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMdbNetworkInfo
	///@return	��һ����������CSysMdbNetworkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbNetworkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbNetworkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbNetworkInfo * pSysMdbNetworkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoPredict���ж�һ������ʹ����Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbNetworkInfo	Ҫ���жϵ�����ʹ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbNetworkInfo *pSysMdbNetworkInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoAndPredict�Ƕ���������ʹ����Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoAndPredict : public CSysMdbNetworkInfoPredict
{
private:
	CSysMdbNetworkInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbNetworkInfoAndPredict(CSysMdbNetworkInfoPredict *p1, CSysMdbNetworkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbNetworkInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbNetworkInfo	Ҫ���жϵ�����ʹ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return m_p1->isValid(pSysMdbNetworkInfo) && m_p2->isValid(pSysMdbNetworkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoOrPredict�Ƕ���������ʹ����Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoOrPredict : public CSysMdbNetworkInfoPredict
{
private:
	CSysMdbNetworkInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbNetworkInfoOrPredict(CSysMdbNetworkInfoPredict *p1, CSysMdbNetworkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbNetworkInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbNetworkInfo	Ҫ���жϵ�����ʹ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return m_p1->isValid(pSysMdbNetworkInfo) || m_p2->isValid(pSysMdbNetworkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoNotPredict�Ƕ�һ������ʹ����Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoNotPredict : public CSysMdbNetworkInfoPredict
{
private:
	CSysMdbNetworkInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMdbNetworkInfoNotPredict(CSysMdbNetworkInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMdbNetworkInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbNetworkInfo	Ҫ���жϵ�����ʹ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return !m_predict->isValid(pSysMdbNetworkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoFilter��һ�������е�����ʹ����Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoFilter: public CSysMdbNetworkInfoIterator
{
private:
	CSysMdbNetworkInfoIterator *m_baseIterator;
	CSysMdbNetworkInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMdbNetworkInfoFilter(CSysMdbNetworkInfoIterator *pBaseIterator, CSysMdbNetworkInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbNetworkInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMdbNetworkInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMdbNetworkInfo
	///@return	��һ����������CSysMdbNetworkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbNetworkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbNetworkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbNetworkInfo * pSysMdbNetworkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoLinkIterator��������������ʹ����Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoLinkIterator: public CSysMdbNetworkInfoIterator
{
private:
	CSysMdbNetworkInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMdbNetworkInfoLinkIterator(CSysMdbNetworkInfoIterator *pBaseIterator1,CSysMdbNetworkInfoIterator *pBaseIterator2)
		:CSysMdbNetworkInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMdbNetworkInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMdbNetworkInfo
	///@return	��һ����������CSysMdbNetworkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbNetworkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbNetworkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbNetworkInfo * pSysMdbNetworkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitSingleIterator�����෵��һ����Ա��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitSingleIterator: public CSysParticipantInitIterator
{
private:
	CSysParticipantInit *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysParticipantInitSingleIterator(CSysParticipantInitFactory *pFactory,CSysParticipantInit *pResult)
		:CSysParticipantInitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysParticipantInitSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysParticipantInit
	///@return	��һ����������CSysParticipantInit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysParticipantInit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysParticipantInit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysParticipantInit * pSysParticipantInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitPredict���ж�һ����Ա�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysParticipantInit	Ҫ���жϵĻ�Ա
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysParticipantInit *pSysParticipantInit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitAndPredict�Ƕ�������Աν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitAndPredict : public CSysParticipantInitPredict
{
private:
	CSysParticipantInitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysParticipantInitAndPredict(CSysParticipantInitPredict *p1, CSysParticipantInitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysParticipantInitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysParticipantInit	Ҫ���жϵĻ�Ա
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysParticipantInit *pSysParticipantInit)
	{
		return m_p1->isValid(pSysParticipantInit) && m_p2->isValid(pSysParticipantInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitOrPredict�Ƕ�������Աν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitOrPredict : public CSysParticipantInitPredict
{
private:
	CSysParticipantInitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysParticipantInitOrPredict(CSysParticipantInitPredict *p1, CSysParticipantInitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysParticipantInitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysParticipantInit	Ҫ���жϵĻ�Ա
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysParticipantInit *pSysParticipantInit)
	{
		return m_p1->isValid(pSysParticipantInit) || m_p2->isValid(pSysParticipantInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitNotPredict�Ƕ�һ����Աν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitNotPredict : public CSysParticipantInitPredict
{
private:
	CSysParticipantInitPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysParticipantInitNotPredict(CSysParticipantInitPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysParticipantInitNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysParticipantInit	Ҫ���жϵĻ�Ա
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysParticipantInit *pSysParticipantInit)
	{
		return !m_predict->isValid(pSysParticipantInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitFilter��һ�������еĻ�Աö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitFilter: public CSysParticipantInitIterator
{
private:
	CSysParticipantInitIterator *m_baseIterator;
	CSysParticipantInitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysParticipantInitFilter(CSysParticipantInitIterator *pBaseIterator, CSysParticipantInitPredict *pPredict, bool continueResult=false)
		:CSysParticipantInitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysParticipantInitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysParticipantInit
	///@return	��һ����������CSysParticipantInit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysParticipantInit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysParticipantInit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysParticipantInit * pSysParticipantInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitLinkIterator������������Աö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitLinkIterator: public CSysParticipantInitIterator
{
private:
	CSysParticipantInitIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysParticipantInitLinkIterator(CSysParticipantInitIterator *pBaseIterator1,CSysParticipantInitIterator *pBaseIterator2)
		:CSysParticipantInitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysParticipantInitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysParticipantInit
	///@return	��һ����������CSysParticipantInit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysParticipantInit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysParticipantInit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysParticipantInit * pSysParticipantInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysUserInitSingleIterator�����෵��һ�������û���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitSingleIterator: public CSysUserInitIterator
{
private:
	CSysUserInit *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysUserInitSingleIterator(CSysUserInitFactory *pFactory,CSysUserInit *pResult)
		:CSysUserInitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysUserInitSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysUserInit
	///@return	��һ����������CSysUserInit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserInit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysUserInit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserInit * pSysUserInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitPredict���ж�һ�������û��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysUserInit	Ҫ���жϵĽ����û�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysUserInit *pSysUserInit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitAndPredict�Ƕ����������û�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitAndPredict : public CSysUserInitPredict
{
private:
	CSysUserInitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysUserInitAndPredict(CSysUserInitPredict *p1, CSysUserInitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysUserInitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysUserInit	Ҫ���жϵĽ����û�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysUserInit *pSysUserInit)
	{
		return m_p1->isValid(pSysUserInit) && m_p2->isValid(pSysUserInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitOrPredict�Ƕ����������û�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitOrPredict : public CSysUserInitPredict
{
private:
	CSysUserInitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysUserInitOrPredict(CSysUserInitPredict *p1, CSysUserInitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysUserInitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysUserInit	Ҫ���жϵĽ����û�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysUserInit *pSysUserInit)
	{
		return m_p1->isValid(pSysUserInit) || m_p2->isValid(pSysUserInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitNotPredict�Ƕ�һ�������û�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitNotPredict : public CSysUserInitPredict
{
private:
	CSysUserInitPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysUserInitNotPredict(CSysUserInitPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysUserInitNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysUserInit	Ҫ���жϵĽ����û�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysUserInit *pSysUserInit)
	{
		return !m_predict->isValid(pSysUserInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitFilter��һ�������еĽ����û�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitFilter: public CSysUserInitIterator
{
private:
	CSysUserInitIterator *m_baseIterator;
	CSysUserInitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysUserInitFilter(CSysUserInitIterator *pBaseIterator, CSysUserInitPredict *pPredict, bool continueResult=false)
		:CSysUserInitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysUserInitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysUserInit
	///@return	��һ����������CSysUserInit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserInit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysUserInit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserInit * pSysUserInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitLinkIterator���������������û�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitLinkIterator: public CSysUserInitIterator
{
private:
	CSysUserInitIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysUserInitLinkIterator(CSysUserInitIterator *pBaseIterator1,CSysUserInitIterator *pBaseIterator2)
		:CSysUserInitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysUserInitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysUserInit
	///@return	��һ����������CSysUserInit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserInit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysUserInit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserInit * pSysUserInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysClientInitSingleIterator�����෵��һ���ͻ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitSingleIterator: public CSysClientInitIterator
{
private:
	CSysClientInit *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysClientInitSingleIterator(CSysClientInitFactory *pFactory,CSysClientInit *pResult)
		:CSysClientInitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysClientInitSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysClientInit
	///@return	��һ����������CSysClientInit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientInit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysClientInit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientInit * pSysClientInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitPredict���ж�һ���ͻ��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysClientInit	Ҫ���жϵĿͻ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysClientInit *pSysClientInit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitAndPredict�Ƕ������ͻ�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitAndPredict : public CSysClientInitPredict
{
private:
	CSysClientInitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysClientInitAndPredict(CSysClientInitPredict *p1, CSysClientInitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysClientInitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysClientInit	Ҫ���жϵĿͻ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysClientInit *pSysClientInit)
	{
		return m_p1->isValid(pSysClientInit) && m_p2->isValid(pSysClientInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitOrPredict�Ƕ������ͻ�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitOrPredict : public CSysClientInitPredict
{
private:
	CSysClientInitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysClientInitOrPredict(CSysClientInitPredict *p1, CSysClientInitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysClientInitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysClientInit	Ҫ���жϵĿͻ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysClientInit *pSysClientInit)
	{
		return m_p1->isValid(pSysClientInit) || m_p2->isValid(pSysClientInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitNotPredict�Ƕ�һ���ͻ�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitNotPredict : public CSysClientInitPredict
{
private:
	CSysClientInitPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysClientInitNotPredict(CSysClientInitPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysClientInitNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysClientInit	Ҫ���жϵĿͻ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysClientInit *pSysClientInit)
	{
		return !m_predict->isValid(pSysClientInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitFilter��һ�������еĿͻ�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitFilter: public CSysClientInitIterator
{
private:
	CSysClientInitIterator *m_baseIterator;
	CSysClientInitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysClientInitFilter(CSysClientInitIterator *pBaseIterator, CSysClientInitPredict *pPredict, bool continueResult=false)
		:CSysClientInitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysClientInitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysClientInit
	///@return	��һ����������CSysClientInit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientInit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysClientInit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientInit * pSysClientInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitLinkIterator�����������ͻ�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitLinkIterator: public CSysClientInitIterator
{
private:
	CSysClientInitIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysClientInitLinkIterator(CSysClientInitIterator *pBaseIterator1,CSysClientInitIterator *pBaseIterator2)
		:CSysClientInitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysClientInitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysClientInit
	///@return	��һ����������CSysClientInit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientInit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysClientInit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientInit * pSysClientInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoSingleIterator�����෵��һ������ϵͳ��¼��Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoSingleIterator: public CSysTradeUserLoginInfoIterator
{
private:
	CSysTradeUserLoginInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysTradeUserLoginInfoSingleIterator(CSysTradeUserLoginInfoFactory *pFactory,CSysTradeUserLoginInfo *pResult)
		:CSysTradeUserLoginInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysTradeUserLoginInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysTradeUserLoginInfo
	///@return	��һ����������CSysTradeUserLoginInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysTradeUserLoginInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysTradeUserLoginInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysTradeUserLoginInfo * pSysTradeUserLoginInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoPredict���ж�һ������ϵͳ��¼��Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysTradeUserLoginInfo	Ҫ���жϵĽ���ϵͳ��¼��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoAndPredict�Ƕ���������ϵͳ��¼��Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoAndPredict : public CSysTradeUserLoginInfoPredict
{
private:
	CSysTradeUserLoginInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysTradeUserLoginInfoAndPredict(CSysTradeUserLoginInfoPredict *p1, CSysTradeUserLoginInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysTradeUserLoginInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysTradeUserLoginInfo	Ҫ���жϵĽ���ϵͳ��¼��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return m_p1->isValid(pSysTradeUserLoginInfo) && m_p2->isValid(pSysTradeUserLoginInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoOrPredict�Ƕ���������ϵͳ��¼��Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoOrPredict : public CSysTradeUserLoginInfoPredict
{
private:
	CSysTradeUserLoginInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysTradeUserLoginInfoOrPredict(CSysTradeUserLoginInfoPredict *p1, CSysTradeUserLoginInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysTradeUserLoginInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysTradeUserLoginInfo	Ҫ���жϵĽ���ϵͳ��¼��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return m_p1->isValid(pSysTradeUserLoginInfo) || m_p2->isValid(pSysTradeUserLoginInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoNotPredict�Ƕ�һ������ϵͳ��¼��Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoNotPredict : public CSysTradeUserLoginInfoPredict
{
private:
	CSysTradeUserLoginInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysTradeUserLoginInfoNotPredict(CSysTradeUserLoginInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysTradeUserLoginInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysTradeUserLoginInfo	Ҫ���жϵĽ���ϵͳ��¼��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return !m_predict->isValid(pSysTradeUserLoginInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoFilter��һ�������еĽ���ϵͳ��¼��Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoFilter: public CSysTradeUserLoginInfoIterator
{
private:
	CSysTradeUserLoginInfoIterator *m_baseIterator;
	CSysTradeUserLoginInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysTradeUserLoginInfoFilter(CSysTradeUserLoginInfoIterator *pBaseIterator, CSysTradeUserLoginInfoPredict *pPredict, bool continueResult=false)
		:CSysTradeUserLoginInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysTradeUserLoginInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysTradeUserLoginInfo
	///@return	��һ����������CSysTradeUserLoginInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysTradeUserLoginInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysTradeUserLoginInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysTradeUserLoginInfo * pSysTradeUserLoginInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoLinkIterator��������������ϵͳ��¼��Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoLinkIterator: public CSysTradeUserLoginInfoIterator
{
private:
	CSysTradeUserLoginInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysTradeUserLoginInfoLinkIterator(CSysTradeUserLoginInfoIterator *pBaseIterator1,CSysTradeUserLoginInfoIterator *pBaseIterator2)
		:CSysTradeUserLoginInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysTradeUserLoginInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysTradeUserLoginInfo
	///@return	��һ����������CSysTradeUserLoginInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysTradeUserLoginInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysTradeUserLoginInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysTradeUserLoginInfo * pSysTradeUserLoginInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoSingleIterator�����෵��һ��WebӦ����Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoSingleIterator: public CSysMdbWebAppInfoIterator
{
private:
	CSysMdbWebAppInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMdbWebAppInfoSingleIterator(CSysMdbWebAppInfoFactory *pFactory,CSysMdbWebAppInfo *pResult)
		:CSysMdbWebAppInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMdbWebAppInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMdbWebAppInfo
	///@return	��һ����������CSysMdbWebAppInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbWebAppInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbWebAppInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbWebAppInfo * pSysMdbWebAppInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoPredict���ж�һ��WebӦ����Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbWebAppInfo	Ҫ���жϵ�WebӦ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbWebAppInfo *pSysMdbWebAppInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoAndPredict�Ƕ�����WebӦ����Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoAndPredict : public CSysMdbWebAppInfoPredict
{
private:
	CSysMdbWebAppInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbWebAppInfoAndPredict(CSysMdbWebAppInfoPredict *p1, CSysMdbWebAppInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbWebAppInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbWebAppInfo	Ҫ���жϵ�WebӦ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return m_p1->isValid(pSysMdbWebAppInfo) && m_p2->isValid(pSysMdbWebAppInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoOrPredict�Ƕ�����WebӦ����Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoOrPredict : public CSysMdbWebAppInfoPredict
{
private:
	CSysMdbWebAppInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbWebAppInfoOrPredict(CSysMdbWebAppInfoPredict *p1, CSysMdbWebAppInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbWebAppInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbWebAppInfo	Ҫ���жϵ�WebӦ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return m_p1->isValid(pSysMdbWebAppInfo) || m_p2->isValid(pSysMdbWebAppInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoNotPredict�Ƕ�һ��WebӦ����Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoNotPredict : public CSysMdbWebAppInfoPredict
{
private:
	CSysMdbWebAppInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMdbWebAppInfoNotPredict(CSysMdbWebAppInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMdbWebAppInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbWebAppInfo	Ҫ���жϵ�WebӦ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return !m_predict->isValid(pSysMdbWebAppInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoFilter��һ�������е�WebӦ����Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoFilter: public CSysMdbWebAppInfoIterator
{
private:
	CSysMdbWebAppInfoIterator *m_baseIterator;
	CSysMdbWebAppInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMdbWebAppInfoFilter(CSysMdbWebAppInfoIterator *pBaseIterator, CSysMdbWebAppInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbWebAppInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMdbWebAppInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMdbWebAppInfo
	///@return	��һ����������CSysMdbWebAppInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbWebAppInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbWebAppInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbWebAppInfo * pSysMdbWebAppInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoLinkIterator����������WebӦ����Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoLinkIterator: public CSysMdbWebAppInfoIterator
{
private:
	CSysMdbWebAppInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMdbWebAppInfoLinkIterator(CSysMdbWebAppInfoIterator *pBaseIterator1,CSysMdbWebAppInfoIterator *pBaseIterator2)
		:CSysMdbWebAppInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMdbWebAppInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMdbWebAppInfo
	///@return	��һ����������CSysMdbWebAppInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbWebAppInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbWebAppInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbWebAppInfo * pSysMdbWebAppInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoSingleIterator�����෵��һ��ϵͳ�ڴ����Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoSingleIterator: public CSysMdbMemPoolInfoIterator
{
private:
	CSysMdbMemPoolInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMdbMemPoolInfoSingleIterator(CSysMdbMemPoolInfoFactory *pFactory,CSysMdbMemPoolInfo *pResult)
		:CSysMdbMemPoolInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMdbMemPoolInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMdbMemPoolInfo
	///@return	��һ����������CSysMdbMemPoolInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbMemPoolInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbMemPoolInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbMemPoolInfo * pSysMdbMemPoolInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoPredict���ж�һ��ϵͳ�ڴ����Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbMemPoolInfo	Ҫ���жϵ�ϵͳ�ڴ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoAndPredict�Ƕ�����ϵͳ�ڴ����Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoAndPredict : public CSysMdbMemPoolInfoPredict
{
private:
	CSysMdbMemPoolInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbMemPoolInfoAndPredict(CSysMdbMemPoolInfoPredict *p1, CSysMdbMemPoolInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbMemPoolInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbMemPoolInfo	Ҫ���жϵ�ϵͳ�ڴ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return m_p1->isValid(pSysMdbMemPoolInfo) && m_p2->isValid(pSysMdbMemPoolInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoOrPredict�Ƕ�����ϵͳ�ڴ����Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoOrPredict : public CSysMdbMemPoolInfoPredict
{
private:
	CSysMdbMemPoolInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbMemPoolInfoOrPredict(CSysMdbMemPoolInfoPredict *p1, CSysMdbMemPoolInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbMemPoolInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbMemPoolInfo	Ҫ���жϵ�ϵͳ�ڴ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return m_p1->isValid(pSysMdbMemPoolInfo) || m_p2->isValid(pSysMdbMemPoolInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoNotPredict�Ƕ�һ��ϵͳ�ڴ����Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoNotPredict : public CSysMdbMemPoolInfoPredict
{
private:
	CSysMdbMemPoolInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMdbMemPoolInfoNotPredict(CSysMdbMemPoolInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMdbMemPoolInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbMemPoolInfo	Ҫ���жϵ�ϵͳ�ڴ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return !m_predict->isValid(pSysMdbMemPoolInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoFilter��һ�������е�ϵͳ�ڴ����Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoFilter: public CSysMdbMemPoolInfoIterator
{
private:
	CSysMdbMemPoolInfoIterator *m_baseIterator;
	CSysMdbMemPoolInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMdbMemPoolInfoFilter(CSysMdbMemPoolInfoIterator *pBaseIterator, CSysMdbMemPoolInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbMemPoolInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMdbMemPoolInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMdbMemPoolInfo
	///@return	��һ����������CSysMdbMemPoolInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbMemPoolInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbMemPoolInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbMemPoolInfo * pSysMdbMemPoolInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoLinkIterator����������ϵͳ�ڴ����Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoLinkIterator: public CSysMdbMemPoolInfoIterator
{
private:
	CSysMdbMemPoolInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMdbMemPoolInfoLinkIterator(CSysMdbMemPoolInfoIterator *pBaseIterator1,CSysMdbMemPoolInfoIterator *pBaseIterator2)
		:CSysMdbMemPoolInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMdbMemPoolInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMdbMemPoolInfo
	///@return	��һ����������CSysMdbMemPoolInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbMemPoolInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbMemPoolInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbMemPoolInfo * pSysMdbMemPoolInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoSingleIterator�����෵��һ����������Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoSingleIterator: public CSysMdbConnectorInfoIterator
{
private:
	CSysMdbConnectorInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMdbConnectorInfoSingleIterator(CSysMdbConnectorInfoFactory *pFactory,CSysMdbConnectorInfo *pResult)
		:CSysMdbConnectorInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMdbConnectorInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMdbConnectorInfo
	///@return	��һ����������CSysMdbConnectorInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbConnectorInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbConnectorInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbConnectorInfo * pSysMdbConnectorInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoPredict���ж�һ����������Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbConnectorInfo	Ҫ���жϵ���������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbConnectorInfo *pSysMdbConnectorInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoAndPredict�Ƕ�������������Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoAndPredict : public CSysMdbConnectorInfoPredict
{
private:
	CSysMdbConnectorInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbConnectorInfoAndPredict(CSysMdbConnectorInfoPredict *p1, CSysMdbConnectorInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbConnectorInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbConnectorInfo	Ҫ���жϵ���������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return m_p1->isValid(pSysMdbConnectorInfo) && m_p2->isValid(pSysMdbConnectorInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoOrPredict�Ƕ�������������Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoOrPredict : public CSysMdbConnectorInfoPredict
{
private:
	CSysMdbConnectorInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbConnectorInfoOrPredict(CSysMdbConnectorInfoPredict *p1, CSysMdbConnectorInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbConnectorInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbConnectorInfo	Ҫ���жϵ���������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return m_p1->isValid(pSysMdbConnectorInfo) || m_p2->isValid(pSysMdbConnectorInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoNotPredict�Ƕ�һ����������Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoNotPredict : public CSysMdbConnectorInfoPredict
{
private:
	CSysMdbConnectorInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMdbConnectorInfoNotPredict(CSysMdbConnectorInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMdbConnectorInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbConnectorInfo	Ҫ���жϵ���������Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return !m_predict->isValid(pSysMdbConnectorInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoFilter��һ�������е���������Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoFilter: public CSysMdbConnectorInfoIterator
{
private:
	CSysMdbConnectorInfoIterator *m_baseIterator;
	CSysMdbConnectorInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMdbConnectorInfoFilter(CSysMdbConnectorInfoIterator *pBaseIterator, CSysMdbConnectorInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbConnectorInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMdbConnectorInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMdbConnectorInfo
	///@return	��һ����������CSysMdbConnectorInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbConnectorInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbConnectorInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbConnectorInfo * pSysMdbConnectorInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoLinkIterator������������������Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoLinkIterator: public CSysMdbConnectorInfoIterator
{
private:
	CSysMdbConnectorInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMdbConnectorInfoLinkIterator(CSysMdbConnectorInfoIterator *pBaseIterator1,CSysMdbConnectorInfoIterator *pBaseIterator2)
		:CSysMdbConnectorInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMdbConnectorInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMdbConnectorInfo
	///@return	��һ����������CSysMdbConnectorInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbConnectorInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbConnectorInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbConnectorInfo * pSysMdbConnectorInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQuerySingleIterator�����෵��һ�����ݿ��ѯӦ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQuerySingleIterator: public CSysMdbDBQueryIterator
{
private:
	CSysMdbDBQuery *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMdbDBQuerySingleIterator(CSysMdbDBQueryFactory *pFactory,CSysMdbDBQuery *pResult)
		:CSysMdbDBQueryIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMdbDBQuerySingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMdbDBQuery
	///@return	��һ����������CSysMdbDBQuery������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbDBQuery *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbDBQuery ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbDBQuery * pSysMdbDBQuery,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryPredict���ж�һ�����ݿ��ѯӦ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbDBQuery	Ҫ���жϵ����ݿ��ѯӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbDBQuery *pSysMdbDBQuery)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryAndPredict�Ƕ��������ݿ��ѯӦ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryAndPredict : public CSysMdbDBQueryPredict
{
private:
	CSysMdbDBQueryPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbDBQueryAndPredict(CSysMdbDBQueryPredict *p1, CSysMdbDBQueryPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbDBQueryAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbDBQuery	Ҫ���жϵ����ݿ��ѯӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbDBQuery *pSysMdbDBQuery)
	{
		return m_p1->isValid(pSysMdbDBQuery) && m_p2->isValid(pSysMdbDBQuery);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryOrPredict�Ƕ��������ݿ��ѯӦ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryOrPredict : public CSysMdbDBQueryPredict
{
private:
	CSysMdbDBQueryPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbDBQueryOrPredict(CSysMdbDBQueryPredict *p1, CSysMdbDBQueryPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbDBQueryOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbDBQuery	Ҫ���жϵ����ݿ��ѯӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbDBQuery *pSysMdbDBQuery)
	{
		return m_p1->isValid(pSysMdbDBQuery) || m_p2->isValid(pSysMdbDBQuery);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryNotPredict�Ƕ�һ�����ݿ��ѯӦ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryNotPredict : public CSysMdbDBQueryPredict
{
private:
	CSysMdbDBQueryPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMdbDBQueryNotPredict(CSysMdbDBQueryPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMdbDBQueryNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbDBQuery	Ҫ���жϵ����ݿ��ѯӦ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbDBQuery *pSysMdbDBQuery)
	{
		return !m_predict->isValid(pSysMdbDBQuery);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryFilter��һ�������е����ݿ��ѯӦ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryFilter: public CSysMdbDBQueryIterator
{
private:
	CSysMdbDBQueryIterator *m_baseIterator;
	CSysMdbDBQueryPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMdbDBQueryFilter(CSysMdbDBQueryIterator *pBaseIterator, CSysMdbDBQueryPredict *pPredict, bool continueResult=false)
		:CSysMdbDBQueryIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMdbDBQueryFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMdbDBQuery
	///@return	��һ����������CSysMdbDBQuery������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbDBQuery *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbDBQuery ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbDBQuery * pSysMdbDBQuery,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryLinkIterator�������������ݿ��ѯӦ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryLinkIterator: public CSysMdbDBQueryIterator
{
private:
	CSysMdbDBQueryIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMdbDBQueryLinkIterator(CSysMdbDBQueryIterator *pBaseIterator1,CSysMdbDBQueryIterator *pBaseIterator2)
		:CSysMdbDBQueryIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMdbDBQueryLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMdbDBQuery
	///@return	��һ����������CSysMdbDBQuery������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbDBQuery *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbDBQuery ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbDBQuery * pSysMdbDBQuery,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetAreaSingleIterator�����෵��һ������������ֵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaSingleIterator: public CSysNetAreaIterator
{
private:
	CSysNetArea *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetAreaSingleIterator(CSysNetAreaFactory *pFactory,CSysNetArea *pResult)
		:CSysNetAreaIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetAreaSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetArea
	///@return	��һ����������CSysNetArea������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetArea *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetArea ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetArea * pSysNetArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaPredict���ж�һ��������������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetArea	Ҫ���жϵ������������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetArea *pSysNetArea)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaAndPredict�Ƕ����������������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaAndPredict : public CSysNetAreaPredict
{
private:
	CSysNetAreaPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetAreaAndPredict(CSysNetAreaPredict *p1, CSysNetAreaPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetAreaAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetArea	Ҫ���жϵ������������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetArea *pSysNetArea)
	{
		return m_p1->isValid(pSysNetArea) && m_p2->isValid(pSysNetArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaOrPredict�Ƕ����������������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaOrPredict : public CSysNetAreaPredict
{
private:
	CSysNetAreaPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetAreaOrPredict(CSysNetAreaPredict *p1, CSysNetAreaPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetAreaOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetArea	Ҫ���жϵ������������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetArea *pSysNetArea)
	{
		return m_p1->isValid(pSysNetArea) || m_p2->isValid(pSysNetArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaNotPredict�Ƕ�һ�������������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaNotPredict : public CSysNetAreaPredict
{
private:
	CSysNetAreaPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetAreaNotPredict(CSysNetAreaPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetAreaNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetArea	Ҫ���жϵ������������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetArea *pSysNetArea)
	{
		return !m_predict->isValid(pSysNetArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaFilter��һ�������е������������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaFilter: public CSysNetAreaIterator
{
private:
	CSysNetAreaIterator *m_baseIterator;
	CSysNetAreaPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetAreaFilter(CSysNetAreaIterator *pBaseIterator, CSysNetAreaPredict *pPredict, bool continueResult=false)
		:CSysNetAreaIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetAreaFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetArea
	///@return	��һ����������CSysNetArea������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetArea *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetArea ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetArea * pSysNetArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaLinkIterator���������������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaLinkIterator: public CSysNetAreaIterator
{
private:
	CSysNetAreaIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetAreaLinkIterator(CSysNetAreaIterator *pBaseIterator1,CSysNetAreaIterator *pBaseIterator2)
		:CSysNetAreaIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetAreaLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetArea
	///@return	��һ����������CSysNetArea������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetArea *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetArea ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetArea * pSysNetArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaSingleIterator�����෵��һ������������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaSingleIterator: public CSysNetSubAreaIterator
{
private:
	CSysNetSubArea *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetSubAreaSingleIterator(CSysNetSubAreaFactory *pFactory,CSysNetSubArea *pResult)
		:CSysNetSubAreaIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetSubAreaSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetSubArea
	///@return	��һ����������CSysNetSubArea������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetSubArea *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetSubArea ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetSubArea * pSysNetSubArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaPredict���ж�һ�����������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetSubArea	Ҫ���жϵ���������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetSubArea *pSysNetSubArea)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaAndPredict�Ƕ�������������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaAndPredict : public CSysNetSubAreaPredict
{
private:
	CSysNetSubAreaPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetSubAreaAndPredict(CSysNetSubAreaPredict *p1, CSysNetSubAreaPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetSubAreaAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetSubArea	Ҫ���жϵ���������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetSubArea *pSysNetSubArea)
	{
		return m_p1->isValid(pSysNetSubArea) && m_p2->isValid(pSysNetSubArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaOrPredict�Ƕ�������������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaOrPredict : public CSysNetSubAreaPredict
{
private:
	CSysNetSubAreaPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetSubAreaOrPredict(CSysNetSubAreaPredict *p1, CSysNetSubAreaPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetSubAreaOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetSubArea	Ҫ���жϵ���������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetSubArea *pSysNetSubArea)
	{
		return m_p1->isValid(pSysNetSubArea) || m_p2->isValid(pSysNetSubArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaNotPredict�Ƕ�һ����������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaNotPredict : public CSysNetSubAreaPredict
{
private:
	CSysNetSubAreaPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetSubAreaNotPredict(CSysNetSubAreaPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetSubAreaNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetSubArea	Ҫ���жϵ���������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetSubArea *pSysNetSubArea)
	{
		return !m_predict->isValid(pSysNetSubArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaFilter��һ�������е���������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaFilter: public CSysNetSubAreaIterator
{
private:
	CSysNetSubAreaIterator *m_baseIterator;
	CSysNetSubAreaPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetSubAreaFilter(CSysNetSubAreaIterator *pBaseIterator, CSysNetSubAreaPredict *pPredict, bool continueResult=false)
		:CSysNetSubAreaIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetSubAreaFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetSubArea
	///@return	��һ����������CSysNetSubArea������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetSubArea *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetSubArea ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetSubArea * pSysNetSubArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaLinkIterator������������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaLinkIterator: public CSysNetSubAreaIterator
{
private:
	CSysNetSubAreaIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetSubAreaLinkIterator(CSysNetSubAreaIterator *pBaseIterator1,CSysNetSubAreaIterator *pBaseIterator2)
		:CSysNetSubAreaIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetSubAreaLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetSubArea
	///@return	��һ����������CSysNetSubArea������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetSubArea *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetSubArea ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetSubArea * pSysNetSubArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPSingleIterator�����෵��һ����������IP��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPSingleIterator: public CSysNetSubAreaIPIterator
{
private:
	CSysNetSubAreaIP *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetSubAreaIPSingleIterator(CSysNetSubAreaIPFactory *pFactory,CSysNetSubAreaIP *pResult)
		:CSysNetSubAreaIPIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetSubAreaIPSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetSubAreaIP
	///@return	��һ����������CSysNetSubAreaIP������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetSubAreaIP *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetSubAreaIP ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetSubAreaIP * pSysNetSubAreaIP,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPPredict���ж�һ����������IP�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetSubAreaIP	Ҫ���жϵ���������IP
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetSubAreaIP *pSysNetSubAreaIP)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPAndPredict�Ƕ�������������IPν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPAndPredict : public CSysNetSubAreaIPPredict
{
private:
	CSysNetSubAreaIPPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetSubAreaIPAndPredict(CSysNetSubAreaIPPredict *p1, CSysNetSubAreaIPPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetSubAreaIPAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetSubAreaIP	Ҫ���жϵ���������IP
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return m_p1->isValid(pSysNetSubAreaIP) && m_p2->isValid(pSysNetSubAreaIP);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPOrPredict�Ƕ�������������IPν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPOrPredict : public CSysNetSubAreaIPPredict
{
private:
	CSysNetSubAreaIPPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetSubAreaIPOrPredict(CSysNetSubAreaIPPredict *p1, CSysNetSubAreaIPPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetSubAreaIPOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetSubAreaIP	Ҫ���жϵ���������IP
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return m_p1->isValid(pSysNetSubAreaIP) || m_p2->isValid(pSysNetSubAreaIP);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPNotPredict�Ƕ�һ����������IPν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPNotPredict : public CSysNetSubAreaIPPredict
{
private:
	CSysNetSubAreaIPPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetSubAreaIPNotPredict(CSysNetSubAreaIPPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetSubAreaIPNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetSubAreaIP	Ҫ���жϵ���������IP
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return !m_predict->isValid(pSysNetSubAreaIP);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPFilter��һ�������е���������IPö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPFilter: public CSysNetSubAreaIPIterator
{
private:
	CSysNetSubAreaIPIterator *m_baseIterator;
	CSysNetSubAreaIPPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetSubAreaIPFilter(CSysNetSubAreaIPIterator *pBaseIterator, CSysNetSubAreaIPPredict *pPredict, bool continueResult=false)
		:CSysNetSubAreaIPIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetSubAreaIPFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetSubAreaIP
	///@return	��һ����������CSysNetSubAreaIP������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetSubAreaIP *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetSubAreaIP ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetSubAreaIP * pSysNetSubAreaIP,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPLinkIterator������������������IPö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPLinkIterator: public CSysNetSubAreaIPIterator
{
private:
	CSysNetSubAreaIPIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetSubAreaIPLinkIterator(CSysNetSubAreaIPIterator *pBaseIterator1,CSysNetSubAreaIPIterator *pBaseIterator2)
		:CSysNetSubAreaIPIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetSubAreaIPLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetSubAreaIP
	///@return	��һ����������CSysNetSubAreaIP������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetSubAreaIP *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetSubAreaIP ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetSubAreaIP * pSysNetSubAreaIP,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaSingleIterator�����෵��һ��ְ������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaSingleIterator: public CSysNetFuncAreaIterator
{
private:
	CSysNetFuncArea *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetFuncAreaSingleIterator(CSysNetFuncAreaFactory *pFactory,CSysNetFuncArea *pResult)
		:CSysNetFuncAreaIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetFuncAreaSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetFuncArea
	///@return	��һ����������CSysNetFuncArea������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetFuncArea *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetFuncArea ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetFuncArea * pSysNetFuncArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaPredict���ж�һ��ְ�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetFuncArea	Ҫ���жϵ�ְ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetFuncArea *pSysNetFuncArea)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaAndPredict�Ƕ�����ְ����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaAndPredict : public CSysNetFuncAreaPredict
{
private:
	CSysNetFuncAreaPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetFuncAreaAndPredict(CSysNetFuncAreaPredict *p1, CSysNetFuncAreaPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetFuncAreaAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetFuncArea	Ҫ���жϵ�ְ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetFuncArea *pSysNetFuncArea)
	{
		return m_p1->isValid(pSysNetFuncArea) && m_p2->isValid(pSysNetFuncArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaOrPredict�Ƕ�����ְ����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaOrPredict : public CSysNetFuncAreaPredict
{
private:
	CSysNetFuncAreaPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetFuncAreaOrPredict(CSysNetFuncAreaPredict *p1, CSysNetFuncAreaPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetFuncAreaOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetFuncArea	Ҫ���жϵ�ְ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetFuncArea *pSysNetFuncArea)
	{
		return m_p1->isValid(pSysNetFuncArea) || m_p2->isValid(pSysNetFuncArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaNotPredict�Ƕ�һ��ְ����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaNotPredict : public CSysNetFuncAreaPredict
{
private:
	CSysNetFuncAreaPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetFuncAreaNotPredict(CSysNetFuncAreaPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetFuncAreaNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetFuncArea	Ҫ���жϵ�ְ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetFuncArea *pSysNetFuncArea)
	{
		return !m_predict->isValid(pSysNetFuncArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaFilter��һ�������е�ְ����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaFilter: public CSysNetFuncAreaIterator
{
private:
	CSysNetFuncAreaIterator *m_baseIterator;
	CSysNetFuncAreaPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetFuncAreaFilter(CSysNetFuncAreaIterator *pBaseIterator, CSysNetFuncAreaPredict *pPredict, bool continueResult=false)
		:CSysNetFuncAreaIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetFuncAreaFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetFuncArea
	///@return	��һ����������CSysNetFuncArea������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetFuncArea *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetFuncArea ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetFuncArea * pSysNetFuncArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaLinkIterator����������ְ����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaLinkIterator: public CSysNetFuncAreaIterator
{
private:
	CSysNetFuncAreaIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetFuncAreaLinkIterator(CSysNetFuncAreaIterator *pBaseIterator1,CSysNetFuncAreaIterator *pBaseIterator2)
		:CSysNetFuncAreaIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetFuncAreaLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetFuncArea
	///@return	��һ����������CSysNetFuncArea������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetFuncArea *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetFuncArea ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetFuncArea * pSysNetFuncArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceSingleIterator�����෵��һ�������豸��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceSingleIterator: public CSysNetDeviceIterator
{
private:
	CSysNetDevice *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetDeviceSingleIterator(CSysNetDeviceFactory *pFactory,CSysNetDevice *pResult)
		:CSysNetDeviceIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetDeviceSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetDevice
	///@return	��һ����������CSysNetDevice������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDevice *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDevice ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDevice * pSysNetDevice,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDevicePredict���ж�һ�������豸�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDevicePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDevice	Ҫ���жϵ������豸
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDevice *pSysNetDevice)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceAndPredict�Ƕ����������豸ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceAndPredict : public CSysNetDevicePredict
{
private:
	CSysNetDevicePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetDeviceAndPredict(CSysNetDevicePredict *p1, CSysNetDevicePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetDeviceAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDevice	Ҫ���жϵ������豸
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDevice *pSysNetDevice)
	{
		return m_p1->isValid(pSysNetDevice) && m_p2->isValid(pSysNetDevice);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceOrPredict�Ƕ����������豸ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceOrPredict : public CSysNetDevicePredict
{
private:
	CSysNetDevicePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetDeviceOrPredict(CSysNetDevicePredict *p1, CSysNetDevicePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetDeviceOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDevice	Ҫ���жϵ������豸
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDevice *pSysNetDevice)
	{
		return m_p1->isValid(pSysNetDevice) || m_p2->isValid(pSysNetDevice);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceNotPredict�Ƕ�һ�������豸ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceNotPredict : public CSysNetDevicePredict
{
private:
	CSysNetDevicePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetDeviceNotPredict(CSysNetDevicePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetDeviceNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDevice	Ҫ���жϵ������豸
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDevice *pSysNetDevice)
	{
		return !m_predict->isValid(pSysNetDevice);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceFilter��һ�������е������豸ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceFilter: public CSysNetDeviceIterator
{
private:
	CSysNetDeviceIterator *m_baseIterator;
	CSysNetDevicePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetDeviceFilter(CSysNetDeviceIterator *pBaseIterator, CSysNetDevicePredict *pPredict, bool continueResult=false)
		:CSysNetDeviceIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetDeviceFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetDevice
	///@return	��һ����������CSysNetDevice������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDevice *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDevice ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDevice * pSysNetDevice,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkIterator���������������豸ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkIterator: public CSysNetDeviceIterator
{
private:
	CSysNetDeviceIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetDeviceLinkIterator(CSysNetDeviceIterator *pBaseIterator1,CSysNetDeviceIterator *pBaseIterator2)
		:CSysNetDeviceIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetDeviceLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetDevice
	///@return	��һ����������CSysNetDevice������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDevice *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDevice ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDevice * pSysNetDevice,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedSingleIterator�����෵��һ�������豸���ӹ�ϵ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedSingleIterator: public CSysNetDeviceLinkedIterator
{
private:
	CSysNetDeviceLinked *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetDeviceLinkedSingleIterator(CSysNetDeviceLinkedFactory *pFactory,CSysNetDeviceLinked *pResult)
		:CSysNetDeviceLinkedIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetDeviceLinkedSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetDeviceLinked
	///@return	��һ����������CSysNetDeviceLinked������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceLinked *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDeviceLinked ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceLinked * pSysNetDeviceLinked,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedPredict���ж�һ�������豸���ӹ�ϵ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDeviceLinked	Ҫ���жϵ������豸���ӹ�ϵ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDeviceLinked *pSysNetDeviceLinked)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedAndPredict�Ƕ����������豸���ӹ�ϵν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedAndPredict : public CSysNetDeviceLinkedPredict
{
private:
	CSysNetDeviceLinkedPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetDeviceLinkedAndPredict(CSysNetDeviceLinkedPredict *p1, CSysNetDeviceLinkedPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetDeviceLinkedAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDeviceLinked	Ҫ���жϵ������豸���ӹ�ϵ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return m_p1->isValid(pSysNetDeviceLinked) && m_p2->isValid(pSysNetDeviceLinked);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedOrPredict�Ƕ����������豸���ӹ�ϵν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedOrPredict : public CSysNetDeviceLinkedPredict
{
private:
	CSysNetDeviceLinkedPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetDeviceLinkedOrPredict(CSysNetDeviceLinkedPredict *p1, CSysNetDeviceLinkedPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetDeviceLinkedOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDeviceLinked	Ҫ���жϵ������豸���ӹ�ϵ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return m_p1->isValid(pSysNetDeviceLinked) || m_p2->isValid(pSysNetDeviceLinked);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedNotPredict�Ƕ�һ�������豸���ӹ�ϵν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedNotPredict : public CSysNetDeviceLinkedPredict
{
private:
	CSysNetDeviceLinkedPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetDeviceLinkedNotPredict(CSysNetDeviceLinkedPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetDeviceLinkedNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDeviceLinked	Ҫ���жϵ������豸���ӹ�ϵ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return !m_predict->isValid(pSysNetDeviceLinked);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedFilter��һ�������е������豸���ӹ�ϵö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedFilter: public CSysNetDeviceLinkedIterator
{
private:
	CSysNetDeviceLinkedIterator *m_baseIterator;
	CSysNetDeviceLinkedPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetDeviceLinkedFilter(CSysNetDeviceLinkedIterator *pBaseIterator, CSysNetDeviceLinkedPredict *pPredict, bool continueResult=false)
		:CSysNetDeviceLinkedIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetDeviceLinkedFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetDeviceLinked
	///@return	��һ����������CSysNetDeviceLinked������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceLinked *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDeviceLinked ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceLinked * pSysNetDeviceLinked,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedLinkIterator���������������豸���ӹ�ϵö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedLinkIterator: public CSysNetDeviceLinkedIterator
{
private:
	CSysNetDeviceLinkedIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetDeviceLinkedLinkIterator(CSysNetDeviceLinkedIterator *pBaseIterator1,CSysNetDeviceLinkedIterator *pBaseIterator2)
		:CSysNetDeviceLinkedIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetDeviceLinkedLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetDeviceLinked
	///@return	��һ����������CSysNetDeviceLinked������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceLinked *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDeviceLinked ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceLinked * pSysNetDeviceLinked,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetOIDSingleIterator�����෵��һ��OID��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDSingleIterator: public CSysNetOIDIterator
{
private:
	CSysNetOID *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetOIDSingleIterator(CSysNetOIDFactory *pFactory,CSysNetOID *pResult)
		:CSysNetOIDIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetOIDSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetOID
	///@return	��һ����������CSysNetOID������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetOID *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetOID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetOID * pSysNetOID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDPredict���ж�һ��OID�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetOID	Ҫ���жϵ�OID
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetOID *pSysNetOID)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDAndPredict�Ƕ�����OIDν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDAndPredict : public CSysNetOIDPredict
{
private:
	CSysNetOIDPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetOIDAndPredict(CSysNetOIDPredict *p1, CSysNetOIDPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetOIDAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetOID	Ҫ���жϵ�OID
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetOID *pSysNetOID)
	{
		return m_p1->isValid(pSysNetOID) && m_p2->isValid(pSysNetOID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDOrPredict�Ƕ�����OIDν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDOrPredict : public CSysNetOIDPredict
{
private:
	CSysNetOIDPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetOIDOrPredict(CSysNetOIDPredict *p1, CSysNetOIDPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetOIDOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetOID	Ҫ���жϵ�OID
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetOID *pSysNetOID)
	{
		return m_p1->isValid(pSysNetOID) || m_p2->isValid(pSysNetOID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDNotPredict�Ƕ�һ��OIDν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDNotPredict : public CSysNetOIDPredict
{
private:
	CSysNetOIDPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetOIDNotPredict(CSysNetOIDPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetOIDNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetOID	Ҫ���жϵ�OID
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetOID *pSysNetOID)
	{
		return !m_predict->isValid(pSysNetOID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDFilter��һ�������е�OIDö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDFilter: public CSysNetOIDIterator
{
private:
	CSysNetOIDIterator *m_baseIterator;
	CSysNetOIDPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetOIDFilter(CSysNetOIDIterator *pBaseIterator, CSysNetOIDPredict *pPredict, bool continueResult=false)
		:CSysNetOIDIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetOIDFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetOID
	///@return	��һ����������CSysNetOID������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetOID *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetOID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetOID * pSysNetOID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDLinkIterator����������OIDö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDLinkIterator: public CSysNetOIDIterator
{
private:
	CSysNetOIDIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetOIDLinkIterator(CSysNetOIDIterator *pBaseIterator1,CSysNetOIDIterator *pBaseIterator2)
		:CSysNetOIDIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetOIDLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetOID
	///@return	��һ����������CSysNetOID������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetOID *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetOID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetOID * pSysNetOID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeSingleIterator�����෵��һ�������豸���͵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeSingleIterator: public CSysNetDeviceTypeIterator
{
private:
	CSysNetDeviceType *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetDeviceTypeSingleIterator(CSysNetDeviceTypeFactory *pFactory,CSysNetDeviceType *pResult)
		:CSysNetDeviceTypeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetDeviceTypeSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetDeviceType
	///@return	��һ����������CSysNetDeviceType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDeviceType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceType * pSysNetDeviceType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypePredict���ж�һ�������豸�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDeviceType	Ҫ���жϵ������豸����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDeviceType *pSysNetDeviceType)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeAndPredict�Ƕ����������豸����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeAndPredict : public CSysNetDeviceTypePredict
{
private:
	CSysNetDeviceTypePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetDeviceTypeAndPredict(CSysNetDeviceTypePredict *p1, CSysNetDeviceTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetDeviceTypeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDeviceType	Ҫ���жϵ������豸����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDeviceType *pSysNetDeviceType)
	{
		return m_p1->isValid(pSysNetDeviceType) && m_p2->isValid(pSysNetDeviceType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeOrPredict�Ƕ����������豸����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeOrPredict : public CSysNetDeviceTypePredict
{
private:
	CSysNetDeviceTypePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetDeviceTypeOrPredict(CSysNetDeviceTypePredict *p1, CSysNetDeviceTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetDeviceTypeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDeviceType	Ҫ���жϵ������豸����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDeviceType *pSysNetDeviceType)
	{
		return m_p1->isValid(pSysNetDeviceType) || m_p2->isValid(pSysNetDeviceType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeNotPredict�Ƕ�һ�������豸����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeNotPredict : public CSysNetDeviceTypePredict
{
private:
	CSysNetDeviceTypePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetDeviceTypeNotPredict(CSysNetDeviceTypePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetDeviceTypeNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDeviceType	Ҫ���жϵ������豸����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDeviceType *pSysNetDeviceType)
	{
		return !m_predict->isValid(pSysNetDeviceType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeFilter��һ�������е������豸����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeFilter: public CSysNetDeviceTypeIterator
{
private:
	CSysNetDeviceTypeIterator *m_baseIterator;
	CSysNetDeviceTypePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetDeviceTypeFilter(CSysNetDeviceTypeIterator *pBaseIterator, CSysNetDeviceTypePredict *pPredict, bool continueResult=false)
		:CSysNetDeviceTypeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetDeviceTypeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetDeviceType
	///@return	��һ����������CSysNetDeviceType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDeviceType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceType * pSysNetDeviceType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeLinkIterator���������������豸����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeLinkIterator: public CSysNetDeviceTypeIterator
{
private:
	CSysNetDeviceTypeIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetDeviceTypeLinkIterator(CSysNetDeviceTypeIterator *pBaseIterator1,CSysNetDeviceTypeIterator *pBaseIterator2)
		:CSysNetDeviceTypeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetDeviceTypeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetDeviceType
	///@return	��һ����������CSysNetDeviceType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDeviceType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceType * pSysNetDeviceType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicySingleIterator�����෵��һ��ʱ����Ե�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicySingleIterator: public CSysNetTimePolicyIterator
{
private:
	CSysNetTimePolicy *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetTimePolicySingleIterator(CSysNetTimePolicyFactory *pFactory,CSysNetTimePolicy *pResult)
		:CSysNetTimePolicyIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetTimePolicySingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetTimePolicy
	///@return	��һ����������CSysNetTimePolicy������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetTimePolicy *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetTimePolicy ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetTimePolicy * pSysNetTimePolicy,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyPredict���ж�һ��ʱ������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetTimePolicy	Ҫ���жϵ�ʱ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetTimePolicy *pSysNetTimePolicy)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyAndPredict�Ƕ�����ʱ�����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyAndPredict : public CSysNetTimePolicyPredict
{
private:
	CSysNetTimePolicyPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetTimePolicyAndPredict(CSysNetTimePolicyPredict *p1, CSysNetTimePolicyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetTimePolicyAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetTimePolicy	Ҫ���жϵ�ʱ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetTimePolicy *pSysNetTimePolicy)
	{
		return m_p1->isValid(pSysNetTimePolicy) && m_p2->isValid(pSysNetTimePolicy);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyOrPredict�Ƕ�����ʱ�����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyOrPredict : public CSysNetTimePolicyPredict
{
private:
	CSysNetTimePolicyPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetTimePolicyOrPredict(CSysNetTimePolicyPredict *p1, CSysNetTimePolicyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetTimePolicyOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetTimePolicy	Ҫ���жϵ�ʱ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetTimePolicy *pSysNetTimePolicy)
	{
		return m_p1->isValid(pSysNetTimePolicy) || m_p2->isValid(pSysNetTimePolicy);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyNotPredict�Ƕ�һ��ʱ�����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyNotPredict : public CSysNetTimePolicyPredict
{
private:
	CSysNetTimePolicyPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetTimePolicyNotPredict(CSysNetTimePolicyPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetTimePolicyNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetTimePolicy	Ҫ���жϵ�ʱ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetTimePolicy *pSysNetTimePolicy)
	{
		return !m_predict->isValid(pSysNetTimePolicy);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyFilter��һ�������е�ʱ�����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyFilter: public CSysNetTimePolicyIterator
{
private:
	CSysNetTimePolicyIterator *m_baseIterator;
	CSysNetTimePolicyPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetTimePolicyFilter(CSysNetTimePolicyIterator *pBaseIterator, CSysNetTimePolicyPredict *pPredict, bool continueResult=false)
		:CSysNetTimePolicyIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetTimePolicyFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetTimePolicy
	///@return	��һ����������CSysNetTimePolicy������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetTimePolicy *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetTimePolicy ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetTimePolicy * pSysNetTimePolicy,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyLinkIterator����������ʱ�����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyLinkIterator: public CSysNetTimePolicyIterator
{
private:
	CSysNetTimePolicyIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetTimePolicyLinkIterator(CSysNetTimePolicyIterator *pBaseIterator1,CSysNetTimePolicyIterator *pBaseIterator2)
		:CSysNetTimePolicyIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetTimePolicyLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetTimePolicy
	///@return	��һ����������CSysNetTimePolicy������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetTimePolicy *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetTimePolicy ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetTimePolicy * pSysNetTimePolicy,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskSingleIterator�����෵��һ���ɼ������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskSingleIterator: public CSysNetGatherTaskIterator
{
private:
	CSysNetGatherTask *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetGatherTaskSingleIterator(CSysNetGatherTaskFactory *pFactory,CSysNetGatherTask *pResult)
		:CSysNetGatherTaskIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetGatherTaskSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetGatherTask
	///@return	��һ����������CSysNetGatherTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetGatherTask *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetGatherTask ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetGatherTask * pSysNetGatherTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskPredict���ж�һ���ɼ������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetGatherTask	Ҫ���жϵĲɼ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetGatherTask *pSysNetGatherTask)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskAndPredict�Ƕ������ɼ�����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskAndPredict : public CSysNetGatherTaskPredict
{
private:
	CSysNetGatherTaskPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetGatherTaskAndPredict(CSysNetGatherTaskPredict *p1, CSysNetGatherTaskPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetGatherTaskAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetGatherTask	Ҫ���жϵĲɼ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetGatherTask *pSysNetGatherTask)
	{
		return m_p1->isValid(pSysNetGatherTask) && m_p2->isValid(pSysNetGatherTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskOrPredict�Ƕ������ɼ�����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskOrPredict : public CSysNetGatherTaskPredict
{
private:
	CSysNetGatherTaskPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetGatherTaskOrPredict(CSysNetGatherTaskPredict *p1, CSysNetGatherTaskPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetGatherTaskOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetGatherTask	Ҫ���жϵĲɼ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetGatherTask *pSysNetGatherTask)
	{
		return m_p1->isValid(pSysNetGatherTask) || m_p2->isValid(pSysNetGatherTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskNotPredict�Ƕ�һ���ɼ�����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskNotPredict : public CSysNetGatherTaskPredict
{
private:
	CSysNetGatherTaskPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetGatherTaskNotPredict(CSysNetGatherTaskPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetGatherTaskNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetGatherTask	Ҫ���жϵĲɼ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetGatherTask *pSysNetGatherTask)
	{
		return !m_predict->isValid(pSysNetGatherTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskFilter��һ�������еĲɼ�����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskFilter: public CSysNetGatherTaskIterator
{
private:
	CSysNetGatherTaskIterator *m_baseIterator;
	CSysNetGatherTaskPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetGatherTaskFilter(CSysNetGatherTaskIterator *pBaseIterator, CSysNetGatherTaskPredict *pPredict, bool continueResult=false)
		:CSysNetGatherTaskIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetGatherTaskFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetGatherTask
	///@return	��һ����������CSysNetGatherTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetGatherTask *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetGatherTask ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetGatherTask * pSysNetGatherTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskLinkIterator�����������ɼ�����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskLinkIterator: public CSysNetGatherTaskIterator
{
private:
	CSysNetGatherTaskIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetGatherTaskLinkIterator(CSysNetGatherTaskIterator *pBaseIterator1,CSysNetGatherTaskIterator *pBaseIterator2)
		:CSysNetGatherTaskIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetGatherTaskLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetGatherTask
	///@return	��һ����������CSysNetGatherTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetGatherTask *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetGatherTask ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetGatherTask * pSysNetGatherTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategorySingleIterator�����෵��һ�������豸����ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategorySingleIterator: public CSysNetDeviceCategoryIterator
{
private:
	CSysNetDeviceCategory *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetDeviceCategorySingleIterator(CSysNetDeviceCategoryFactory *pFactory,CSysNetDeviceCategory *pResult)
		:CSysNetDeviceCategoryIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetDeviceCategorySingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetDeviceCategory
	///@return	��һ����������CSysNetDeviceCategory������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceCategory *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDeviceCategory ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceCategory * pSysNetDeviceCategory,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryPredict���ж�һ�������豸����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDeviceCategory	Ҫ���жϵĳ����豸���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDeviceCategory *pSysNetDeviceCategory)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryAndPredict�Ƕ����������豸���ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryAndPredict : public CSysNetDeviceCategoryPredict
{
private:
	CSysNetDeviceCategoryPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetDeviceCategoryAndPredict(CSysNetDeviceCategoryPredict *p1, CSysNetDeviceCategoryPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetDeviceCategoryAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDeviceCategory	Ҫ���жϵĳ����豸���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return m_p1->isValid(pSysNetDeviceCategory) && m_p2->isValid(pSysNetDeviceCategory);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryOrPredict�Ƕ����������豸���ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryOrPredict : public CSysNetDeviceCategoryPredict
{
private:
	CSysNetDeviceCategoryPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetDeviceCategoryOrPredict(CSysNetDeviceCategoryPredict *p1, CSysNetDeviceCategoryPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetDeviceCategoryOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDeviceCategory	Ҫ���жϵĳ����豸���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return m_p1->isValid(pSysNetDeviceCategory) || m_p2->isValid(pSysNetDeviceCategory);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryNotPredict�Ƕ�һ�������豸���ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryNotPredict : public CSysNetDeviceCategoryPredict
{
private:
	CSysNetDeviceCategoryPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetDeviceCategoryNotPredict(CSysNetDeviceCategoryPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetDeviceCategoryNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDeviceCategory	Ҫ���жϵĳ����豸���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return !m_predict->isValid(pSysNetDeviceCategory);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryFilter��һ�������еĳ����豸���ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryFilter: public CSysNetDeviceCategoryIterator
{
private:
	CSysNetDeviceCategoryIterator *m_baseIterator;
	CSysNetDeviceCategoryPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetDeviceCategoryFilter(CSysNetDeviceCategoryIterator *pBaseIterator, CSysNetDeviceCategoryPredict *pPredict, bool continueResult=false)
		:CSysNetDeviceCategoryIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetDeviceCategoryFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetDeviceCategory
	///@return	��һ����������CSysNetDeviceCategory������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceCategory *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDeviceCategory ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceCategory * pSysNetDeviceCategory,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryLinkIterator���������������豸���ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryLinkIterator: public CSysNetDeviceCategoryIterator
{
private:
	CSysNetDeviceCategoryIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetDeviceCategoryLinkIterator(CSysNetDeviceCategoryIterator *pBaseIterator1,CSysNetDeviceCategoryIterator *pBaseIterator2)
		:CSysNetDeviceCategoryIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetDeviceCategoryLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetDeviceCategory
	///@return	��һ����������CSysNetDeviceCategory������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceCategory *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDeviceCategory ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceCategory * pSysNetDeviceCategory,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetManufactorySingleIterator�����෵��һ���豸���̵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactorySingleIterator: public CSysNetManufactoryIterator
{
private:
	CSysNetManufactory *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetManufactorySingleIterator(CSysNetManufactoryFactory *pFactory,CSysNetManufactory *pResult)
		:CSysNetManufactoryIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetManufactorySingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetManufactory
	///@return	��һ����������CSysNetManufactory������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetManufactory *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetManufactory ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetManufactory * pSysNetManufactory,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryPredict���ж�һ���豸�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetManufactory	Ҫ���жϵ��豸����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetManufactory *pSysNetManufactory)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryAndPredict�Ƕ������豸����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryAndPredict : public CSysNetManufactoryPredict
{
private:
	CSysNetManufactoryPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetManufactoryAndPredict(CSysNetManufactoryPredict *p1, CSysNetManufactoryPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetManufactoryAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetManufactory	Ҫ���жϵ��豸����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetManufactory *pSysNetManufactory)
	{
		return m_p1->isValid(pSysNetManufactory) && m_p2->isValid(pSysNetManufactory);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryOrPredict�Ƕ������豸����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryOrPredict : public CSysNetManufactoryPredict
{
private:
	CSysNetManufactoryPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetManufactoryOrPredict(CSysNetManufactoryPredict *p1, CSysNetManufactoryPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetManufactoryOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetManufactory	Ҫ���жϵ��豸����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetManufactory *pSysNetManufactory)
	{
		return m_p1->isValid(pSysNetManufactory) || m_p2->isValid(pSysNetManufactory);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryNotPredict�Ƕ�һ���豸����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryNotPredict : public CSysNetManufactoryPredict
{
private:
	CSysNetManufactoryPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetManufactoryNotPredict(CSysNetManufactoryPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetManufactoryNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetManufactory	Ҫ���жϵ��豸����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetManufactory *pSysNetManufactory)
	{
		return !m_predict->isValid(pSysNetManufactory);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryFilter��һ�������е��豸����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryFilter: public CSysNetManufactoryIterator
{
private:
	CSysNetManufactoryIterator *m_baseIterator;
	CSysNetManufactoryPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetManufactoryFilter(CSysNetManufactoryIterator *pBaseIterator, CSysNetManufactoryPredict *pPredict, bool continueResult=false)
		:CSysNetManufactoryIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetManufactoryFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetManufactory
	///@return	��һ����������CSysNetManufactory������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetManufactory *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetManufactory ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetManufactory * pSysNetManufactory,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryLinkIterator�����������豸����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryLinkIterator: public CSysNetManufactoryIterator
{
private:
	CSysNetManufactoryIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetManufactoryLinkIterator(CSysNetManufactoryIterator *pBaseIterator1,CSysNetManufactoryIterator *pBaseIterator2)
		:CSysNetManufactoryIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetManufactoryLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetManufactory
	///@return	��һ����������CSysNetManufactory������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetManufactory *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetManufactory ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetManufactory * pSysNetManufactory,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetCommunitySingleIterator�����෵��һ���豸��ͬ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunitySingleIterator: public CSysNetCommunityIterator
{
private:
	CSysNetCommunity *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetCommunitySingleIterator(CSysNetCommunityFactory *pFactory,CSysNetCommunity *pResult)
		:CSysNetCommunityIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetCommunitySingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetCommunity
	///@return	��һ����������CSysNetCommunity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetCommunity *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetCommunity ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetCommunity * pSysNetCommunity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityPredict���ж�һ���豸��ͬ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetCommunity	Ҫ���жϵ��豸��ͬ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetCommunity *pSysNetCommunity)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityAndPredict�Ƕ������豸��ͬ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityAndPredict : public CSysNetCommunityPredict
{
private:
	CSysNetCommunityPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetCommunityAndPredict(CSysNetCommunityPredict *p1, CSysNetCommunityPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetCommunityAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetCommunity	Ҫ���жϵ��豸��ͬ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetCommunity *pSysNetCommunity)
	{
		return m_p1->isValid(pSysNetCommunity) && m_p2->isValid(pSysNetCommunity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityOrPredict�Ƕ������豸��ͬ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityOrPredict : public CSysNetCommunityPredict
{
private:
	CSysNetCommunityPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetCommunityOrPredict(CSysNetCommunityPredict *p1, CSysNetCommunityPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetCommunityOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetCommunity	Ҫ���жϵ��豸��ͬ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetCommunity *pSysNetCommunity)
	{
		return m_p1->isValid(pSysNetCommunity) || m_p2->isValid(pSysNetCommunity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityNotPredict�Ƕ�һ���豸��ͬ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityNotPredict : public CSysNetCommunityPredict
{
private:
	CSysNetCommunityPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetCommunityNotPredict(CSysNetCommunityPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetCommunityNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetCommunity	Ҫ���жϵ��豸��ͬ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetCommunity *pSysNetCommunity)
	{
		return !m_predict->isValid(pSysNetCommunity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityFilter��һ�������е��豸��ͬ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityFilter: public CSysNetCommunityIterator
{
private:
	CSysNetCommunityIterator *m_baseIterator;
	CSysNetCommunityPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetCommunityFilter(CSysNetCommunityIterator *pBaseIterator, CSysNetCommunityPredict *pPredict, bool continueResult=false)
		:CSysNetCommunityIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetCommunityFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetCommunity
	///@return	��һ����������CSysNetCommunity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetCommunity *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetCommunity ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetCommunity * pSysNetCommunity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityLinkIterator�����������豸��ͬ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityLinkIterator: public CSysNetCommunityIterator
{
private:
	CSysNetCommunityIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetCommunityLinkIterator(CSysNetCommunityIterator *pBaseIterator1,CSysNetCommunityIterator *pBaseIterator2)
		:CSysNetCommunityIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetCommunityLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetCommunity
	///@return	��һ����������CSysNetCommunity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetCommunity *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetCommunity ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetCommunity * pSysNetCommunity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeSingleIterator�����෵��һ���˿����͵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeSingleIterator: public CSysNetPortTypeIterator
{
private:
	CSysNetPortType *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetPortTypeSingleIterator(CSysNetPortTypeFactory *pFactory,CSysNetPortType *pResult)
		:CSysNetPortTypeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetPortTypeSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetPortType
	///@return	��һ����������CSysNetPortType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPortType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPortType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPortType * pSysNetPortType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypePredict���ж�һ���˿������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPortType	Ҫ���жϵĶ˿�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPortType *pSysNetPortType)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeAndPredict�Ƕ������˿�����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeAndPredict : public CSysNetPortTypePredict
{
private:
	CSysNetPortTypePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetPortTypeAndPredict(CSysNetPortTypePredict *p1, CSysNetPortTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetPortTypeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPortType	Ҫ���жϵĶ˿�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPortType *pSysNetPortType)
	{
		return m_p1->isValid(pSysNetPortType) && m_p2->isValid(pSysNetPortType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeOrPredict�Ƕ������˿�����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeOrPredict : public CSysNetPortTypePredict
{
private:
	CSysNetPortTypePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetPortTypeOrPredict(CSysNetPortTypePredict *p1, CSysNetPortTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetPortTypeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPortType	Ҫ���жϵĶ˿�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPortType *pSysNetPortType)
	{
		return m_p1->isValid(pSysNetPortType) || m_p2->isValid(pSysNetPortType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeNotPredict�Ƕ�һ���˿�����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeNotPredict : public CSysNetPortTypePredict
{
private:
	CSysNetPortTypePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetPortTypeNotPredict(CSysNetPortTypePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetPortTypeNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPortType	Ҫ���жϵĶ˿�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPortType *pSysNetPortType)
	{
		return !m_predict->isValid(pSysNetPortType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeFilter��һ�������еĶ˿�����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeFilter: public CSysNetPortTypeIterator
{
private:
	CSysNetPortTypeIterator *m_baseIterator;
	CSysNetPortTypePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetPortTypeFilter(CSysNetPortTypeIterator *pBaseIterator, CSysNetPortTypePredict *pPredict, bool continueResult=false)
		:CSysNetPortTypeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetPortTypeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetPortType
	///@return	��һ����������CSysNetPortType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPortType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPortType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPortType * pSysNetPortType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeLinkIterator�����������˿�����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeLinkIterator: public CSysNetPortTypeIterator
{
private:
	CSysNetPortTypeIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetPortTypeLinkIterator(CSysNetPortTypeIterator *pBaseIterator1,CSysNetPortTypeIterator *pBaseIterator2)
		:CSysNetPortTypeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetPortTypeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetPortType
	///@return	��һ����������CSysNetPortType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPortType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPortType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPortType * pSysNetPortType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceSingleIterator�����෵��һ���˿ڵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceSingleIterator: public CSysNetInterfaceIterator
{
private:
	CSysNetInterface *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetInterfaceSingleIterator(CSysNetInterfaceFactory *pFactory,CSysNetInterface *pResult)
		:CSysNetInterfaceIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetInterfaceSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetInterface
	///@return	��һ����������CSysNetInterface������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetInterface *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetInterface ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetInterface * pSysNetInterface,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfacePredict���ж�һ���˿��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfacePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetInterface	Ҫ���жϵĶ˿�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetInterface *pSysNetInterface)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceAndPredict�Ƕ������˿�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceAndPredict : public CSysNetInterfacePredict
{
private:
	CSysNetInterfacePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetInterfaceAndPredict(CSysNetInterfacePredict *p1, CSysNetInterfacePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetInterfaceAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetInterface	Ҫ���жϵĶ˿�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetInterface *pSysNetInterface)
	{
		return m_p1->isValid(pSysNetInterface) && m_p2->isValid(pSysNetInterface);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceOrPredict�Ƕ������˿�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceOrPredict : public CSysNetInterfacePredict
{
private:
	CSysNetInterfacePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetInterfaceOrPredict(CSysNetInterfacePredict *p1, CSysNetInterfacePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetInterfaceOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetInterface	Ҫ���жϵĶ˿�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetInterface *pSysNetInterface)
	{
		return m_p1->isValid(pSysNetInterface) || m_p2->isValid(pSysNetInterface);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceNotPredict�Ƕ�һ���˿�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceNotPredict : public CSysNetInterfacePredict
{
private:
	CSysNetInterfacePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetInterfaceNotPredict(CSysNetInterfacePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetInterfaceNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetInterface	Ҫ���жϵĶ˿�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetInterface *pSysNetInterface)
	{
		return !m_predict->isValid(pSysNetInterface);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceFilter��һ�������еĶ˿�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceFilter: public CSysNetInterfaceIterator
{
private:
	CSysNetInterfaceIterator *m_baseIterator;
	CSysNetInterfacePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetInterfaceFilter(CSysNetInterfaceIterator *pBaseIterator, CSysNetInterfacePredict *pPredict, bool continueResult=false)
		:CSysNetInterfaceIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetInterfaceFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetInterface
	///@return	��һ����������CSysNetInterface������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetInterface *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetInterface ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetInterface * pSysNetInterface,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceLinkIterator�����������˿�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceLinkIterator: public CSysNetInterfaceIterator
{
private:
	CSysNetInterfaceIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetInterfaceLinkIterator(CSysNetInterfaceIterator *pBaseIterator1,CSysNetInterfaceIterator *pBaseIterator2)
		:CSysNetInterfaceIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetInterfaceLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetInterface
	///@return	��һ����������CSysNetInterface������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetInterface *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetInterface ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetInterface * pSysNetInterface,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDSingleIterator�����෵��һ��ͨ��OID��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDSingleIterator: public CSysNetGeneralOIDIterator
{
private:
	CSysNetGeneralOID *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetGeneralOIDSingleIterator(CSysNetGeneralOIDFactory *pFactory,CSysNetGeneralOID *pResult)
		:CSysNetGeneralOIDIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetGeneralOIDSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetGeneralOID
	///@return	��һ����������CSysNetGeneralOID������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetGeneralOID *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetGeneralOID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetGeneralOID * pSysNetGeneralOID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDPredict���ж�һ��ͨ��OID�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetGeneralOID	Ҫ���жϵ�ͨ��OID
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetGeneralOID *pSysNetGeneralOID)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDAndPredict�Ƕ�����ͨ��OIDν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDAndPredict : public CSysNetGeneralOIDPredict
{
private:
	CSysNetGeneralOIDPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetGeneralOIDAndPredict(CSysNetGeneralOIDPredict *p1, CSysNetGeneralOIDPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetGeneralOIDAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetGeneralOID	Ҫ���жϵ�ͨ��OID
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetGeneralOID *pSysNetGeneralOID)
	{
		return m_p1->isValid(pSysNetGeneralOID) && m_p2->isValid(pSysNetGeneralOID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDOrPredict�Ƕ�����ͨ��OIDν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDOrPredict : public CSysNetGeneralOIDPredict
{
private:
	CSysNetGeneralOIDPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetGeneralOIDOrPredict(CSysNetGeneralOIDPredict *p1, CSysNetGeneralOIDPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetGeneralOIDOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetGeneralOID	Ҫ���жϵ�ͨ��OID
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetGeneralOID *pSysNetGeneralOID)
	{
		return m_p1->isValid(pSysNetGeneralOID) || m_p2->isValid(pSysNetGeneralOID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDNotPredict�Ƕ�һ��ͨ��OIDν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDNotPredict : public CSysNetGeneralOIDPredict
{
private:
	CSysNetGeneralOIDPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetGeneralOIDNotPredict(CSysNetGeneralOIDPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetGeneralOIDNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetGeneralOID	Ҫ���жϵ�ͨ��OID
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetGeneralOID *pSysNetGeneralOID)
	{
		return !m_predict->isValid(pSysNetGeneralOID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDFilter��һ�������е�ͨ��OIDö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDFilter: public CSysNetGeneralOIDIterator
{
private:
	CSysNetGeneralOIDIterator *m_baseIterator;
	CSysNetGeneralOIDPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetGeneralOIDFilter(CSysNetGeneralOIDIterator *pBaseIterator, CSysNetGeneralOIDPredict *pPredict, bool continueResult=false)
		:CSysNetGeneralOIDIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetGeneralOIDFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetGeneralOID
	///@return	��һ����������CSysNetGeneralOID������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetGeneralOID *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetGeneralOID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetGeneralOID * pSysNetGeneralOID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDLinkIterator����������ͨ��OIDö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDLinkIterator: public CSysNetGeneralOIDIterator
{
private:
	CSysNetGeneralOIDIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetGeneralOIDLinkIterator(CSysNetGeneralOIDIterator *pBaseIterator1,CSysNetGeneralOIDIterator *pBaseIterator2)
		:CSysNetGeneralOIDIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetGeneralOIDLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetGeneralOID
	///@return	��һ����������CSysNetGeneralOID������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetGeneralOID *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetGeneralOID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetGeneralOID * pSysNetGeneralOID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeSingleIterator�����෵��һ����ض�������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeSingleIterator: public CSysNetMonitorTypeIterator
{
private:
	CSysNetMonitorType *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetMonitorTypeSingleIterator(CSysNetMonitorTypeFactory *pFactory,CSysNetMonitorType *pResult)
		:CSysNetMonitorTypeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetMonitorTypeSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetMonitorType
	///@return	��һ����������CSysNetMonitorType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorType * pSysNetMonitorType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypePredict���ж�һ����ض�������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorType	Ҫ���жϵļ�ض������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorType *pSysNetMonitorType)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeAndPredict�Ƕ�������ض������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeAndPredict : public CSysNetMonitorTypePredict
{
private:
	CSysNetMonitorTypePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorTypeAndPredict(CSysNetMonitorTypePredict *p1, CSysNetMonitorTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorTypeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorType	Ҫ���жϵļ�ض������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorType *pSysNetMonitorType)
	{
		return m_p1->isValid(pSysNetMonitorType) && m_p2->isValid(pSysNetMonitorType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeOrPredict�Ƕ�������ض������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeOrPredict : public CSysNetMonitorTypePredict
{
private:
	CSysNetMonitorTypePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorTypeOrPredict(CSysNetMonitorTypePredict *p1, CSysNetMonitorTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorTypeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorType	Ҫ���жϵļ�ض������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorType *pSysNetMonitorType)
	{
		return m_p1->isValid(pSysNetMonitorType) || m_p2->isValid(pSysNetMonitorType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeNotPredict�Ƕ�һ����ض������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeNotPredict : public CSysNetMonitorTypePredict
{
private:
	CSysNetMonitorTypePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetMonitorTypeNotPredict(CSysNetMonitorTypePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetMonitorTypeNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorType	Ҫ���жϵļ�ض������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorType *pSysNetMonitorType)
	{
		return !m_predict->isValid(pSysNetMonitorType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeFilter��һ�������еļ�ض������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeFilter: public CSysNetMonitorTypeIterator
{
private:
	CSysNetMonitorTypeIterator *m_baseIterator;
	CSysNetMonitorTypePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetMonitorTypeFilter(CSysNetMonitorTypeIterator *pBaseIterator, CSysNetMonitorTypePredict *pPredict, bool continueResult=false)
		:CSysNetMonitorTypeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetMonitorTypeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetMonitorType
	///@return	��һ����������CSysNetMonitorType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorType * pSysNetMonitorType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeLinkIterator������������ض������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeLinkIterator: public CSysNetMonitorTypeIterator
{
private:
	CSysNetMonitorTypeIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetMonitorTypeLinkIterator(CSysNetMonitorTypeIterator *pBaseIterator1,CSysNetMonitorTypeIterator *pBaseIterator2)
		:CSysNetMonitorTypeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetMonitorTypeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetMonitorType
	///@return	��һ����������CSysNetMonitorType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorType * pSysNetMonitorType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeSingleIterator�����෵��һ��ָ��ͳ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeSingleIterator: public CSysNetMonitorAttrScopeIterator
{
private:
	CSysNetMonitorAttrScope *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetMonitorAttrScopeSingleIterator(CSysNetMonitorAttrScopeFactory *pFactory,CSysNetMonitorAttrScope *pResult)
		:CSysNetMonitorAttrScopeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetMonitorAttrScopeSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetMonitorAttrScope
	///@return	��һ����������CSysNetMonitorAttrScope������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorAttrScope *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorAttrScope ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrScope * pSysNetMonitorAttrScope,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopePredict���ж�һ��ָ��ͳ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorAttrScope	Ҫ���жϵ�ָ��ͳ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeAndPredict�Ƕ�����ָ��ͳ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeAndPredict : public CSysNetMonitorAttrScopePredict
{
private:
	CSysNetMonitorAttrScopePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorAttrScopeAndPredict(CSysNetMonitorAttrScopePredict *p1, CSysNetMonitorAttrScopePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorAttrScopeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorAttrScope	Ҫ���жϵ�ָ��ͳ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return m_p1->isValid(pSysNetMonitorAttrScope) && m_p2->isValid(pSysNetMonitorAttrScope);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeOrPredict�Ƕ�����ָ��ͳ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeOrPredict : public CSysNetMonitorAttrScopePredict
{
private:
	CSysNetMonitorAttrScopePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorAttrScopeOrPredict(CSysNetMonitorAttrScopePredict *p1, CSysNetMonitorAttrScopePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorAttrScopeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorAttrScope	Ҫ���жϵ�ָ��ͳ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return m_p1->isValid(pSysNetMonitorAttrScope) || m_p2->isValid(pSysNetMonitorAttrScope);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeNotPredict�Ƕ�һ��ָ��ͳ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeNotPredict : public CSysNetMonitorAttrScopePredict
{
private:
	CSysNetMonitorAttrScopePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetMonitorAttrScopeNotPredict(CSysNetMonitorAttrScopePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetMonitorAttrScopeNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorAttrScope	Ҫ���жϵ�ָ��ͳ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return !m_predict->isValid(pSysNetMonitorAttrScope);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeFilter��һ�������е�ָ��ͳ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeFilter: public CSysNetMonitorAttrScopeIterator
{
private:
	CSysNetMonitorAttrScopeIterator *m_baseIterator;
	CSysNetMonitorAttrScopePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetMonitorAttrScopeFilter(CSysNetMonitorAttrScopeIterator *pBaseIterator, CSysNetMonitorAttrScopePredict *pPredict, bool continueResult=false)
		:CSysNetMonitorAttrScopeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetMonitorAttrScopeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetMonitorAttrScope
	///@return	��һ����������CSysNetMonitorAttrScope������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorAttrScope *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorAttrScope ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrScope * pSysNetMonitorAttrScope,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeLinkIterator����������ָ��ͳ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeLinkIterator: public CSysNetMonitorAttrScopeIterator
{
private:
	CSysNetMonitorAttrScopeIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetMonitorAttrScopeLinkIterator(CSysNetMonitorAttrScopeIterator *pBaseIterator1,CSysNetMonitorAttrScopeIterator *pBaseIterator2)
		:CSysNetMonitorAttrScopeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetMonitorAttrScopeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetMonitorAttrScope
	///@return	��һ����������CSysNetMonitorAttrScope������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorAttrScope *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorAttrScope ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrScope * pSysNetMonitorAttrScope,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeSingleIterator�����෵��һ�����ָ����ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeSingleIterator: public CSysNetMonitorAttrTypeIterator
{
private:
	CSysNetMonitorAttrType *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetMonitorAttrTypeSingleIterator(CSysNetMonitorAttrTypeFactory *pFactory,CSysNetMonitorAttrType *pResult)
		:CSysNetMonitorAttrTypeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetMonitorAttrTypeSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetMonitorAttrType
	///@return	��һ����������CSysNetMonitorAttrType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorAttrType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorAttrType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrType * pSysNetMonitorAttrType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypePredict���ж�һ�����ָ����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorAttrType	Ҫ���жϵļ��ָ���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorAttrType *pSysNetMonitorAttrType)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeAndPredict�Ƕ��������ָ���ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeAndPredict : public CSysNetMonitorAttrTypePredict
{
private:
	CSysNetMonitorAttrTypePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorAttrTypeAndPredict(CSysNetMonitorAttrTypePredict *p1, CSysNetMonitorAttrTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorAttrTypeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorAttrType	Ҫ���жϵļ��ָ���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return m_p1->isValid(pSysNetMonitorAttrType) && m_p2->isValid(pSysNetMonitorAttrType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeOrPredict�Ƕ��������ָ���ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeOrPredict : public CSysNetMonitorAttrTypePredict
{
private:
	CSysNetMonitorAttrTypePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorAttrTypeOrPredict(CSysNetMonitorAttrTypePredict *p1, CSysNetMonitorAttrTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorAttrTypeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorAttrType	Ҫ���жϵļ��ָ���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return m_p1->isValid(pSysNetMonitorAttrType) || m_p2->isValid(pSysNetMonitorAttrType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeNotPredict�Ƕ�һ�����ָ���ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeNotPredict : public CSysNetMonitorAttrTypePredict
{
private:
	CSysNetMonitorAttrTypePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetMonitorAttrTypeNotPredict(CSysNetMonitorAttrTypePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetMonitorAttrTypeNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorAttrType	Ҫ���жϵļ��ָ���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return !m_predict->isValid(pSysNetMonitorAttrType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeFilter��һ�������еļ��ָ���ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeFilter: public CSysNetMonitorAttrTypeIterator
{
private:
	CSysNetMonitorAttrTypeIterator *m_baseIterator;
	CSysNetMonitorAttrTypePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetMonitorAttrTypeFilter(CSysNetMonitorAttrTypeIterator *pBaseIterator, CSysNetMonitorAttrTypePredict *pPredict, bool continueResult=false)
		:CSysNetMonitorAttrTypeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetMonitorAttrTypeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetMonitorAttrType
	///@return	��һ����������CSysNetMonitorAttrType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorAttrType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorAttrType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrType * pSysNetMonitorAttrType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeLinkIterator�������������ָ���ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeLinkIterator: public CSysNetMonitorAttrTypeIterator
{
private:
	CSysNetMonitorAttrTypeIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetMonitorAttrTypeLinkIterator(CSysNetMonitorAttrTypeIterator *pBaseIterator1,CSysNetMonitorAttrTypeIterator *pBaseIterator2)
		:CSysNetMonitorAttrTypeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetMonitorAttrTypeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetMonitorAttrType
	///@return	��һ����������CSysNetMonitorAttrType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorAttrType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorAttrType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrType * pSysNetMonitorAttrType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeSingleIterator�����෵��һ�����ָ����ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeSingleIterator: public CSysNetMonitorCommandTypeIterator
{
private:
	CSysNetMonitorCommandType *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetMonitorCommandTypeSingleIterator(CSysNetMonitorCommandTypeFactory *pFactory,CSysNetMonitorCommandType *pResult)
		:CSysNetMonitorCommandTypeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetMonitorCommandTypeSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetMonitorCommandType
	///@return	��һ����������CSysNetMonitorCommandType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorCommandType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorCommandType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorCommandType * pSysNetMonitorCommandType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypePredict���ж�һ�����ָ����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorCommandType	Ҫ���жϵļ��ָ���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorCommandType *pSysNetMonitorCommandType)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeAndPredict�Ƕ��������ָ���ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeAndPredict : public CSysNetMonitorCommandTypePredict
{
private:
	CSysNetMonitorCommandTypePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorCommandTypeAndPredict(CSysNetMonitorCommandTypePredict *p1, CSysNetMonitorCommandTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorCommandTypeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorCommandType	Ҫ���жϵļ��ָ���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return m_p1->isValid(pSysNetMonitorCommandType) && m_p2->isValid(pSysNetMonitorCommandType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeOrPredict�Ƕ��������ָ���ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeOrPredict : public CSysNetMonitorCommandTypePredict
{
private:
	CSysNetMonitorCommandTypePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorCommandTypeOrPredict(CSysNetMonitorCommandTypePredict *p1, CSysNetMonitorCommandTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorCommandTypeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorCommandType	Ҫ���жϵļ��ָ���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return m_p1->isValid(pSysNetMonitorCommandType) || m_p2->isValid(pSysNetMonitorCommandType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeNotPredict�Ƕ�һ�����ָ���ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeNotPredict : public CSysNetMonitorCommandTypePredict
{
private:
	CSysNetMonitorCommandTypePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetMonitorCommandTypeNotPredict(CSysNetMonitorCommandTypePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetMonitorCommandTypeNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorCommandType	Ҫ���жϵļ��ָ���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return !m_predict->isValid(pSysNetMonitorCommandType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeFilter��һ�������еļ��ָ���ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeFilter: public CSysNetMonitorCommandTypeIterator
{
private:
	CSysNetMonitorCommandTypeIterator *m_baseIterator;
	CSysNetMonitorCommandTypePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetMonitorCommandTypeFilter(CSysNetMonitorCommandTypeIterator *pBaseIterator, CSysNetMonitorCommandTypePredict *pPredict, bool continueResult=false)
		:CSysNetMonitorCommandTypeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetMonitorCommandTypeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetMonitorCommandType
	///@return	��һ����������CSysNetMonitorCommandType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorCommandType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorCommandType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorCommandType * pSysNetMonitorCommandType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeLinkIterator�������������ָ���ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeLinkIterator: public CSysNetMonitorCommandTypeIterator
{
private:
	CSysNetMonitorCommandTypeIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetMonitorCommandTypeLinkIterator(CSysNetMonitorCommandTypeIterator *pBaseIterator1,CSysNetMonitorCommandTypeIterator *pBaseIterator2)
		:CSysNetMonitorCommandTypeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetMonitorCommandTypeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetMonitorCommandType
	///@return	��һ����������CSysNetMonitorCommandType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorCommandType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorCommandType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorCommandType * pSysNetMonitorCommandType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupSingleIterator�����෵��һ����������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupSingleIterator: public CSysNetMonitorActionGroupIterator
{
private:
	CSysNetMonitorActionGroup *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetMonitorActionGroupSingleIterator(CSysNetMonitorActionGroupFactory *pFactory,CSysNetMonitorActionGroup *pResult)
		:CSysNetMonitorActionGroupIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetMonitorActionGroupSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetMonitorActionGroup
	///@return	��һ����������CSysNetMonitorActionGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorActionGroup *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorActionGroup ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionGroup * pSysNetMonitorActionGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupPredict���ж�һ����������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorActionGroup	Ҫ���жϵĶ������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupAndPredict�Ƕ������������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupAndPredict : public CSysNetMonitorActionGroupPredict
{
private:
	CSysNetMonitorActionGroupPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorActionGroupAndPredict(CSysNetMonitorActionGroupPredict *p1, CSysNetMonitorActionGroupPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorActionGroupAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorActionGroup	Ҫ���жϵĶ������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return m_p1->isValid(pSysNetMonitorActionGroup) && m_p2->isValid(pSysNetMonitorActionGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupOrPredict�Ƕ������������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupOrPredict : public CSysNetMonitorActionGroupPredict
{
private:
	CSysNetMonitorActionGroupPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorActionGroupOrPredict(CSysNetMonitorActionGroupPredict *p1, CSysNetMonitorActionGroupPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorActionGroupOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorActionGroup	Ҫ���жϵĶ������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return m_p1->isValid(pSysNetMonitorActionGroup) || m_p2->isValid(pSysNetMonitorActionGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupNotPredict�Ƕ�һ���������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupNotPredict : public CSysNetMonitorActionGroupPredict
{
private:
	CSysNetMonitorActionGroupPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetMonitorActionGroupNotPredict(CSysNetMonitorActionGroupPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetMonitorActionGroupNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorActionGroup	Ҫ���жϵĶ������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return !m_predict->isValid(pSysNetMonitorActionGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupFilter��һ�������еĶ������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupFilter: public CSysNetMonitorActionGroupIterator
{
private:
	CSysNetMonitorActionGroupIterator *m_baseIterator;
	CSysNetMonitorActionGroupPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetMonitorActionGroupFilter(CSysNetMonitorActionGroupIterator *pBaseIterator, CSysNetMonitorActionGroupPredict *pPredict, bool continueResult=false)
		:CSysNetMonitorActionGroupIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetMonitorActionGroupFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetMonitorActionGroup
	///@return	��һ����������CSysNetMonitorActionGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorActionGroup *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorActionGroup ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionGroup * pSysNetMonitorActionGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupLinkIterator�����������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupLinkIterator: public CSysNetMonitorActionGroupIterator
{
private:
	CSysNetMonitorActionGroupIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetMonitorActionGroupLinkIterator(CSysNetMonitorActionGroupIterator *pBaseIterator1,CSysNetMonitorActionGroupIterator *pBaseIterator2)
		:CSysNetMonitorActionGroupIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetMonitorActionGroupLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetMonitorActionGroup
	///@return	��һ����������CSysNetMonitorActionGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorActionGroup *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorActionGroup ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionGroup * pSysNetMonitorActionGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupSingleIterator�����෵��һ���豸��������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupSingleIterator: public CSysNetMonitorDeviceGroupIterator
{
private:
	CSysNetMonitorDeviceGroup *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetMonitorDeviceGroupSingleIterator(CSysNetMonitorDeviceGroupFactory *pFactory,CSysNetMonitorDeviceGroup *pResult)
		:CSysNetMonitorDeviceGroupIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetMonitorDeviceGroupSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetMonitorDeviceGroup
	///@return	��һ����������CSysNetMonitorDeviceGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorDeviceGroup *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorDeviceGroup ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupPredict���ж�һ���豸��������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorDeviceGroup	Ҫ���жϵ��豸�������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupAndPredict�Ƕ������豸�������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupAndPredict : public CSysNetMonitorDeviceGroupPredict
{
private:
	CSysNetMonitorDeviceGroupPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorDeviceGroupAndPredict(CSysNetMonitorDeviceGroupPredict *p1, CSysNetMonitorDeviceGroupPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorDeviceGroupAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorDeviceGroup	Ҫ���жϵ��豸�������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return m_p1->isValid(pSysNetMonitorDeviceGroup) && m_p2->isValid(pSysNetMonitorDeviceGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupOrPredict�Ƕ������豸�������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupOrPredict : public CSysNetMonitorDeviceGroupPredict
{
private:
	CSysNetMonitorDeviceGroupPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorDeviceGroupOrPredict(CSysNetMonitorDeviceGroupPredict *p1, CSysNetMonitorDeviceGroupPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorDeviceGroupOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorDeviceGroup	Ҫ���жϵ��豸�������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return m_p1->isValid(pSysNetMonitorDeviceGroup) || m_p2->isValid(pSysNetMonitorDeviceGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupNotPredict�Ƕ�һ���豸�������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupNotPredict : public CSysNetMonitorDeviceGroupPredict
{
private:
	CSysNetMonitorDeviceGroupPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetMonitorDeviceGroupNotPredict(CSysNetMonitorDeviceGroupPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetMonitorDeviceGroupNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorDeviceGroup	Ҫ���жϵ��豸�������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return !m_predict->isValid(pSysNetMonitorDeviceGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupFilter��һ�������е��豸�������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupFilter: public CSysNetMonitorDeviceGroupIterator
{
private:
	CSysNetMonitorDeviceGroupIterator *m_baseIterator;
	CSysNetMonitorDeviceGroupPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetMonitorDeviceGroupFilter(CSysNetMonitorDeviceGroupIterator *pBaseIterator, CSysNetMonitorDeviceGroupPredict *pPredict, bool continueResult=false)
		:CSysNetMonitorDeviceGroupIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetMonitorDeviceGroupFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetMonitorDeviceGroup
	///@return	��һ����������CSysNetMonitorDeviceGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorDeviceGroup *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorDeviceGroup ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupLinkIterator�����������豸�������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupLinkIterator: public CSysNetMonitorDeviceGroupIterator
{
private:
	CSysNetMonitorDeviceGroupIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetMonitorDeviceGroupLinkIterator(CSysNetMonitorDeviceGroupIterator *pBaseIterator1,CSysNetMonitorDeviceGroupIterator *pBaseIterator2)
		:CSysNetMonitorDeviceGroupIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetMonitorDeviceGroupLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetMonitorDeviceGroup
	///@return	��һ����������CSysNetMonitorDeviceGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorDeviceGroup *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorDeviceGroup ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoSingleIterator�����෵��һ��������Ϣ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoSingleIterator: public CSysNetMonitorTaskInfoIterator
{
private:
	CSysNetMonitorTaskInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetMonitorTaskInfoSingleIterator(CSysNetMonitorTaskInfoFactory *pFactory,CSysNetMonitorTaskInfo *pResult)
		:CSysNetMonitorTaskInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetMonitorTaskInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetMonitorTaskInfo
	///@return	��һ����������CSysNetMonitorTaskInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorTaskInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoPredict���ж�һ��������Ϣ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorTaskInfo	Ҫ���жϵ�������Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoAndPredict�Ƕ�����������Ϣ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoAndPredict : public CSysNetMonitorTaskInfoPredict
{
private:
	CSysNetMonitorTaskInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorTaskInfoAndPredict(CSysNetMonitorTaskInfoPredict *p1, CSysNetMonitorTaskInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorTaskInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorTaskInfo	Ҫ���жϵ�������Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return m_p1->isValid(pSysNetMonitorTaskInfo) && m_p2->isValid(pSysNetMonitorTaskInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoOrPredict�Ƕ�����������Ϣ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoOrPredict : public CSysNetMonitorTaskInfoPredict
{
private:
	CSysNetMonitorTaskInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorTaskInfoOrPredict(CSysNetMonitorTaskInfoPredict *p1, CSysNetMonitorTaskInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorTaskInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorTaskInfo	Ҫ���жϵ�������Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return m_p1->isValid(pSysNetMonitorTaskInfo) || m_p2->isValid(pSysNetMonitorTaskInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoNotPredict�Ƕ�һ��������Ϣ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoNotPredict : public CSysNetMonitorTaskInfoPredict
{
private:
	CSysNetMonitorTaskInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetMonitorTaskInfoNotPredict(CSysNetMonitorTaskInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetMonitorTaskInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorTaskInfo	Ҫ���жϵ�������Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return !m_predict->isValid(pSysNetMonitorTaskInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoFilter��һ�������е�������Ϣ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoFilter: public CSysNetMonitorTaskInfoIterator
{
private:
	CSysNetMonitorTaskInfoIterator *m_baseIterator;
	CSysNetMonitorTaskInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetMonitorTaskInfoFilter(CSysNetMonitorTaskInfoIterator *pBaseIterator, CSysNetMonitorTaskInfoPredict *pPredict, bool continueResult=false)
		:CSysNetMonitorTaskInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetMonitorTaskInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetMonitorTaskInfo
	///@return	��һ����������CSysNetMonitorTaskInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorTaskInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoLinkIterator����������������Ϣ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoLinkIterator: public CSysNetMonitorTaskInfoIterator
{
private:
	CSysNetMonitorTaskInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetMonitorTaskInfoLinkIterator(CSysNetMonitorTaskInfoIterator *pBaseIterator1,CSysNetMonitorTaskInfoIterator *pBaseIterator2)
		:CSysNetMonitorTaskInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetMonitorTaskInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetMonitorTaskInfo
	///@return	��һ����������CSysNetMonitorTaskInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorTaskInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetSingleIterator�����෵��һ��������󼯵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetSingleIterator: public CSysNetMonitorTaskObjectSetIterator
{
private:
	CSysNetMonitorTaskObjectSet *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetMonitorTaskObjectSetSingleIterator(CSysNetMonitorTaskObjectSetFactory *pFactory,CSysNetMonitorTaskObjectSet *pResult)
		:CSysNetMonitorTaskObjectSetIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetMonitorTaskObjectSetSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetMonitorTaskObjectSet
	///@return	��һ����������CSysNetMonitorTaskObjectSet������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskObjectSet *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorTaskObjectSet ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetPredict���ж�һ����������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorTaskObjectSet	Ҫ���жϵ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetAndPredict�Ƕ������������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetAndPredict : public CSysNetMonitorTaskObjectSetPredict
{
private:
	CSysNetMonitorTaskObjectSetPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorTaskObjectSetAndPredict(CSysNetMonitorTaskObjectSetPredict *p1, CSysNetMonitorTaskObjectSetPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorTaskObjectSetAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorTaskObjectSet	Ҫ���жϵ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return m_p1->isValid(pSysNetMonitorTaskObjectSet) && m_p2->isValid(pSysNetMonitorTaskObjectSet);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetOrPredict�Ƕ������������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetOrPredict : public CSysNetMonitorTaskObjectSetPredict
{
private:
	CSysNetMonitorTaskObjectSetPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorTaskObjectSetOrPredict(CSysNetMonitorTaskObjectSetPredict *p1, CSysNetMonitorTaskObjectSetPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorTaskObjectSetOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorTaskObjectSet	Ҫ���жϵ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return m_p1->isValid(pSysNetMonitorTaskObjectSet) || m_p2->isValid(pSysNetMonitorTaskObjectSet);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetNotPredict�Ƕ�һ���������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetNotPredict : public CSysNetMonitorTaskObjectSetPredict
{
private:
	CSysNetMonitorTaskObjectSetPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetMonitorTaskObjectSetNotPredict(CSysNetMonitorTaskObjectSetPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetMonitorTaskObjectSetNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorTaskObjectSet	Ҫ���жϵ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return !m_predict->isValid(pSysNetMonitorTaskObjectSet);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetFilter��һ�������е��������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetFilter: public CSysNetMonitorTaskObjectSetIterator
{
private:
	CSysNetMonitorTaskObjectSetIterator *m_baseIterator;
	CSysNetMonitorTaskObjectSetPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetMonitorTaskObjectSetFilter(CSysNetMonitorTaskObjectSetIterator *pBaseIterator, CSysNetMonitorTaskObjectSetPredict *pPredict, bool continueResult=false)
		:CSysNetMonitorTaskObjectSetIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetMonitorTaskObjectSetFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetMonitorTaskObjectSet
	///@return	��һ����������CSysNetMonitorTaskObjectSet������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskObjectSet *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorTaskObjectSet ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetLinkIterator�����������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetLinkIterator: public CSysNetMonitorTaskObjectSetIterator
{
private:
	CSysNetMonitorTaskObjectSetIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetMonitorTaskObjectSetLinkIterator(CSysNetMonitorTaskObjectSetIterator *pBaseIterator1,CSysNetMonitorTaskObjectSetIterator *pBaseIterator2)
		:CSysNetMonitorTaskObjectSetIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetMonitorTaskObjectSetLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetMonitorTaskObjectSet
	///@return	��һ����������CSysNetMonitorTaskObjectSet������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskObjectSet *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorTaskObjectSet ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultSingleIterator�����෵��һ�����������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultSingleIterator: public CSysNetMonitorTaskResultIterator
{
private:
	CSysNetMonitorTaskResult *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetMonitorTaskResultSingleIterator(CSysNetMonitorTaskResultFactory *pFactory,CSysNetMonitorTaskResult *pResult)
		:CSysNetMonitorTaskResultIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetMonitorTaskResultSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetMonitorTaskResult
	///@return	��һ����������CSysNetMonitorTaskResult������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskResult *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorTaskResult ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pSysNetMonitorTaskResult,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultPredict���ж�һ�����������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorTaskResult	Ҫ���жϵ���������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultAndPredict�Ƕ�������������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultAndPredict : public CSysNetMonitorTaskResultPredict
{
private:
	CSysNetMonitorTaskResultPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorTaskResultAndPredict(CSysNetMonitorTaskResultPredict *p1, CSysNetMonitorTaskResultPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorTaskResultAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorTaskResult	Ҫ���жϵ���������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return m_p1->isValid(pSysNetMonitorTaskResult) && m_p2->isValid(pSysNetMonitorTaskResult);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultOrPredict�Ƕ�������������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultOrPredict : public CSysNetMonitorTaskResultPredict
{
private:
	CSysNetMonitorTaskResultPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorTaskResultOrPredict(CSysNetMonitorTaskResultPredict *p1, CSysNetMonitorTaskResultPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorTaskResultOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorTaskResult	Ҫ���жϵ���������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return m_p1->isValid(pSysNetMonitorTaskResult) || m_p2->isValid(pSysNetMonitorTaskResult);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultNotPredict�Ƕ�һ����������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultNotPredict : public CSysNetMonitorTaskResultPredict
{
private:
	CSysNetMonitorTaskResultPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetMonitorTaskResultNotPredict(CSysNetMonitorTaskResultPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetMonitorTaskResultNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorTaskResult	Ҫ���жϵ���������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return !m_predict->isValid(pSysNetMonitorTaskResult);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultFilter��һ�������е���������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultFilter: public CSysNetMonitorTaskResultIterator
{
private:
	CSysNetMonitorTaskResultIterator *m_baseIterator;
	CSysNetMonitorTaskResultPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetMonitorTaskResultFilter(CSysNetMonitorTaskResultIterator *pBaseIterator, CSysNetMonitorTaskResultPredict *pPredict, bool continueResult=false)
		:CSysNetMonitorTaskResultIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetMonitorTaskResultFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetMonitorTaskResult
	///@return	��һ����������CSysNetMonitorTaskResult������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskResult *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorTaskResult ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pSysNetMonitorTaskResult,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultLinkIterator������������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultLinkIterator: public CSysNetMonitorTaskResultIterator
{
private:
	CSysNetMonitorTaskResultIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetMonitorTaskResultLinkIterator(CSysNetMonitorTaskResultIterator *pBaseIterator1,CSysNetMonitorTaskResultIterator *pBaseIterator2)
		:CSysNetMonitorTaskResultIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetMonitorTaskResultLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetMonitorTaskResult
	///@return	��һ����������CSysNetMonitorTaskResult������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskResult *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorTaskResult ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pSysNetMonitorTaskResult,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoSingleIterator�����෵��һ����Ա��·��Ϣ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoSingleIterator: public CSysNetPartyLinkInfoIterator
{
private:
	CSysNetPartyLinkInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetPartyLinkInfoSingleIterator(CSysNetPartyLinkInfoFactory *pFactory,CSysNetPartyLinkInfo *pResult)
		:CSysNetPartyLinkInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetPartyLinkInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetPartyLinkInfo
	///@return	��һ����������CSysNetPartyLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartyLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPartyLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkInfo * pSysNetPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoPredict���ж�һ����Ա��·��Ϣ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPartyLinkInfo	Ҫ���жϵĻ�Ա��·��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoAndPredict�Ƕ�������Ա��·��Ϣ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoAndPredict : public CSysNetPartyLinkInfoPredict
{
private:
	CSysNetPartyLinkInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetPartyLinkInfoAndPredict(CSysNetPartyLinkInfoPredict *p1, CSysNetPartyLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetPartyLinkInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPartyLinkInfo	Ҫ���жϵĻ�Ա��·��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return m_p1->isValid(pSysNetPartyLinkInfo) && m_p2->isValid(pSysNetPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoOrPredict�Ƕ�������Ա��·��Ϣ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoOrPredict : public CSysNetPartyLinkInfoPredict
{
private:
	CSysNetPartyLinkInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetPartyLinkInfoOrPredict(CSysNetPartyLinkInfoPredict *p1, CSysNetPartyLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetPartyLinkInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPartyLinkInfo	Ҫ���жϵĻ�Ա��·��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return m_p1->isValid(pSysNetPartyLinkInfo) || m_p2->isValid(pSysNetPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoNotPredict�Ƕ�һ����Ա��·��Ϣ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoNotPredict : public CSysNetPartyLinkInfoPredict
{
private:
	CSysNetPartyLinkInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetPartyLinkInfoNotPredict(CSysNetPartyLinkInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetPartyLinkInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPartyLinkInfo	Ҫ���жϵĻ�Ա��·��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return !m_predict->isValid(pSysNetPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoFilter��һ�������еĻ�Ա��·��Ϣ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoFilter: public CSysNetPartyLinkInfoIterator
{
private:
	CSysNetPartyLinkInfoIterator *m_baseIterator;
	CSysNetPartyLinkInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetPartyLinkInfoFilter(CSysNetPartyLinkInfoIterator *pBaseIterator, CSysNetPartyLinkInfoPredict *pPredict, bool continueResult=false)
		:CSysNetPartyLinkInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetPartyLinkInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetPartyLinkInfo
	///@return	��һ����������CSysNetPartyLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartyLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPartyLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkInfo * pSysNetPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoLinkIterator������������Ա��·��Ϣ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoLinkIterator: public CSysNetPartyLinkInfoIterator
{
private:
	CSysNetPartyLinkInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetPartyLinkInfoLinkIterator(CSysNetPartyLinkInfoIterator *pBaseIterator1,CSysNetPartyLinkInfoIterator *pBaseIterator2)
		:CSysNetPartyLinkInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetPartyLinkInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetPartyLinkInfo
	///@return	��һ����������CSysNetPartyLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartyLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPartyLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkInfo * pSysNetPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoSingleIterator�����෵��һ����Ա��·��Ϣ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoSingleIterator: public CSysNetDelPartyLinkInfoIterator
{
private:
	CSysNetDelPartyLinkInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetDelPartyLinkInfoSingleIterator(CSysNetDelPartyLinkInfoFactory *pFactory,CSysNetDelPartyLinkInfo *pResult)
		:CSysNetDelPartyLinkInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetDelPartyLinkInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetDelPartyLinkInfo
	///@return	��һ����������CSysNetDelPartyLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDelPartyLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDelPartyLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoPredict���ж�һ����Ա��·��Ϣ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDelPartyLinkInfo	Ҫ���жϵĻ�Ա��·��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoAndPredict�Ƕ�������Ա��·��Ϣ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoAndPredict : public CSysNetDelPartyLinkInfoPredict
{
private:
	CSysNetDelPartyLinkInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetDelPartyLinkInfoAndPredict(CSysNetDelPartyLinkInfoPredict *p1, CSysNetDelPartyLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetDelPartyLinkInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDelPartyLinkInfo	Ҫ���жϵĻ�Ա��·��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return m_p1->isValid(pSysNetDelPartyLinkInfo) && m_p2->isValid(pSysNetDelPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoOrPredict�Ƕ�������Ա��·��Ϣ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoOrPredict : public CSysNetDelPartyLinkInfoPredict
{
private:
	CSysNetDelPartyLinkInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetDelPartyLinkInfoOrPredict(CSysNetDelPartyLinkInfoPredict *p1, CSysNetDelPartyLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetDelPartyLinkInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDelPartyLinkInfo	Ҫ���жϵĻ�Ա��·��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return m_p1->isValid(pSysNetDelPartyLinkInfo) || m_p2->isValid(pSysNetDelPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoNotPredict�Ƕ�һ����Ա��·��Ϣ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoNotPredict : public CSysNetDelPartyLinkInfoPredict
{
private:
	CSysNetDelPartyLinkInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetDelPartyLinkInfoNotPredict(CSysNetDelPartyLinkInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetDelPartyLinkInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDelPartyLinkInfo	Ҫ���жϵĻ�Ա��·��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return !m_predict->isValid(pSysNetDelPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoFilter��һ�������еĻ�Ա��·��Ϣ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoFilter: public CSysNetDelPartyLinkInfoIterator
{
private:
	CSysNetDelPartyLinkInfoIterator *m_baseIterator;
	CSysNetDelPartyLinkInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetDelPartyLinkInfoFilter(CSysNetDelPartyLinkInfoIterator *pBaseIterator, CSysNetDelPartyLinkInfoPredict *pPredict, bool continueResult=false)
		:CSysNetDelPartyLinkInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetDelPartyLinkInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetDelPartyLinkInfo
	///@return	��һ����������CSysNetDelPartyLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDelPartyLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDelPartyLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoLinkIterator������������Ա��·��Ϣ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoLinkIterator: public CSysNetDelPartyLinkInfoIterator
{
private:
	CSysNetDelPartyLinkInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetDelPartyLinkInfoLinkIterator(CSysNetDelPartyLinkInfoIterator *pBaseIterator1,CSysNetDelPartyLinkInfoIterator *pBaseIterator2)
		:CSysNetDelPartyLinkInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetDelPartyLinkInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetDelPartyLinkInfo
	///@return	��һ����������CSysNetDelPartyLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDelPartyLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDelPartyLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeSingleIterator�����෵��һ����Ա��·��Ϣ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeSingleIterator: public CSysNetPartyLinkAddrChangeIterator
{
private:
	CSysNetPartyLinkAddrChange *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetPartyLinkAddrChangeSingleIterator(CSysNetPartyLinkAddrChangeFactory *pFactory,CSysNetPartyLinkAddrChange *pResult)
		:CSysNetPartyLinkAddrChangeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetPartyLinkAddrChangeSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetPartyLinkAddrChange
	///@return	��һ����������CSysNetPartyLinkAddrChange������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartyLinkAddrChange *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPartyLinkAddrChange ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangePredict���ж�һ����Ա��·��Ϣ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPartyLinkAddrChange	Ҫ���жϵĻ�Ա��·��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeAndPredict�Ƕ�������Ա��·��Ϣ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeAndPredict : public CSysNetPartyLinkAddrChangePredict
{
private:
	CSysNetPartyLinkAddrChangePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetPartyLinkAddrChangeAndPredict(CSysNetPartyLinkAddrChangePredict *p1, CSysNetPartyLinkAddrChangePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetPartyLinkAddrChangeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPartyLinkAddrChange	Ҫ���жϵĻ�Ա��·��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return m_p1->isValid(pSysNetPartyLinkAddrChange) && m_p2->isValid(pSysNetPartyLinkAddrChange);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeOrPredict�Ƕ�������Ա��·��Ϣ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeOrPredict : public CSysNetPartyLinkAddrChangePredict
{
private:
	CSysNetPartyLinkAddrChangePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetPartyLinkAddrChangeOrPredict(CSysNetPartyLinkAddrChangePredict *p1, CSysNetPartyLinkAddrChangePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetPartyLinkAddrChangeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPartyLinkAddrChange	Ҫ���жϵĻ�Ա��·��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return m_p1->isValid(pSysNetPartyLinkAddrChange) || m_p2->isValid(pSysNetPartyLinkAddrChange);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeNotPredict�Ƕ�һ����Ա��·��Ϣ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeNotPredict : public CSysNetPartyLinkAddrChangePredict
{
private:
	CSysNetPartyLinkAddrChangePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetPartyLinkAddrChangeNotPredict(CSysNetPartyLinkAddrChangePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetPartyLinkAddrChangeNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPartyLinkAddrChange	Ҫ���жϵĻ�Ա��·��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return !m_predict->isValid(pSysNetPartyLinkAddrChange);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeFilter��һ�������еĻ�Ա��·��Ϣ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeFilter: public CSysNetPartyLinkAddrChangeIterator
{
private:
	CSysNetPartyLinkAddrChangeIterator *m_baseIterator;
	CSysNetPartyLinkAddrChangePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetPartyLinkAddrChangeFilter(CSysNetPartyLinkAddrChangeIterator *pBaseIterator, CSysNetPartyLinkAddrChangePredict *pPredict, bool continueResult=false)
		:CSysNetPartyLinkAddrChangeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetPartyLinkAddrChangeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetPartyLinkAddrChange
	///@return	��һ����������CSysNetPartyLinkAddrChange������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartyLinkAddrChange *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPartyLinkAddrChange ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeLinkIterator������������Ա��·��Ϣ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeLinkIterator: public CSysNetPartyLinkAddrChangeIterator
{
private:
	CSysNetPartyLinkAddrChangeIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetPartyLinkAddrChangeLinkIterator(CSysNetPartyLinkAddrChangeIterator *pBaseIterator1,CSysNetPartyLinkAddrChangeIterator *pBaseIterator2)
		:CSysNetPartyLinkAddrChangeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetPartyLinkAddrChangeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetPartyLinkAddrChange
	///@return	��һ����������CSysNetPartyLinkAddrChange������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartyLinkAddrChange *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPartyLinkAddrChange ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrSingleIterator�����෵��һ����ض���ָ����ձ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrSingleIterator: public CSysNetMonitorActionAttrIterator
{
private:
	CSysNetMonitorActionAttr *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetMonitorActionAttrSingleIterator(CSysNetMonitorActionAttrFactory *pFactory,CSysNetMonitorActionAttr *pResult)
		:CSysNetMonitorActionAttrIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetMonitorActionAttrSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetMonitorActionAttr
	///@return	��һ����������CSysNetMonitorActionAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorActionAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorActionAttr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionAttr * pSysNetMonitorActionAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrPredict���ж�һ����ض���ָ����ձ��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorActionAttr	Ҫ���жϵļ�ض���ָ����ձ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrAndPredict�Ƕ�������ض���ָ����ձ�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrAndPredict : public CSysNetMonitorActionAttrPredict
{
private:
	CSysNetMonitorActionAttrPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorActionAttrAndPredict(CSysNetMonitorActionAttrPredict *p1, CSysNetMonitorActionAttrPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorActionAttrAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorActionAttr	Ҫ���жϵļ�ض���ָ����ձ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return m_p1->isValid(pSysNetMonitorActionAttr) && m_p2->isValid(pSysNetMonitorActionAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrOrPredict�Ƕ�������ض���ָ����ձ�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrOrPredict : public CSysNetMonitorActionAttrPredict
{
private:
	CSysNetMonitorActionAttrPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorActionAttrOrPredict(CSysNetMonitorActionAttrPredict *p1, CSysNetMonitorActionAttrPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorActionAttrOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorActionAttr	Ҫ���жϵļ�ض���ָ����ձ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return m_p1->isValid(pSysNetMonitorActionAttr) || m_p2->isValid(pSysNetMonitorActionAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrNotPredict�Ƕ�һ����ض���ָ����ձ�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrNotPredict : public CSysNetMonitorActionAttrPredict
{
private:
	CSysNetMonitorActionAttrPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetMonitorActionAttrNotPredict(CSysNetMonitorActionAttrPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetMonitorActionAttrNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorActionAttr	Ҫ���жϵļ�ض���ָ����ձ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return !m_predict->isValid(pSysNetMonitorActionAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrFilter��һ�������еļ�ض���ָ����ձ�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrFilter: public CSysNetMonitorActionAttrIterator
{
private:
	CSysNetMonitorActionAttrIterator *m_baseIterator;
	CSysNetMonitorActionAttrPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetMonitorActionAttrFilter(CSysNetMonitorActionAttrIterator *pBaseIterator, CSysNetMonitorActionAttrPredict *pPredict, bool continueResult=false)
		:CSysNetMonitorActionAttrIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetMonitorActionAttrFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetMonitorActionAttr
	///@return	��һ����������CSysNetMonitorActionAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorActionAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorActionAttr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionAttr * pSysNetMonitorActionAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrLinkIterator������������ض���ָ����ձ�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrLinkIterator: public CSysNetMonitorActionAttrIterator
{
private:
	CSysNetMonitorActionAttrIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetMonitorActionAttrLinkIterator(CSysNetMonitorActionAttrIterator *pBaseIterator1,CSysNetMonitorActionAttrIterator *pBaseIterator2)
		:CSysNetMonitorActionAttrIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetMonitorActionAttrLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetMonitorActionAttr
	///@return	��һ����������CSysNetMonitorActionAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorActionAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorActionAttr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionAttr * pSysNetMonitorActionAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetModuleSingleIterator�����෵��һ��ģ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleSingleIterator: public CSysNetModuleIterator
{
private:
	CSysNetModule *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetModuleSingleIterator(CSysNetModuleFactory *pFactory,CSysNetModule *pResult)
		:CSysNetModuleIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetModuleSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetModule
	///@return	��һ����������CSysNetModule������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetModule *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetModule ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetModule * pSysNetModule,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModulePredict���ж�һ��ģ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModulePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetModule	Ҫ���жϵ�ģ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetModule *pSysNetModule)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleAndPredict�Ƕ�����ģ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleAndPredict : public CSysNetModulePredict
{
private:
	CSysNetModulePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetModuleAndPredict(CSysNetModulePredict *p1, CSysNetModulePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetModuleAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetModule	Ҫ���жϵ�ģ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetModule *pSysNetModule)
	{
		return m_p1->isValid(pSysNetModule) && m_p2->isValid(pSysNetModule);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleOrPredict�Ƕ�����ģ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleOrPredict : public CSysNetModulePredict
{
private:
	CSysNetModulePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetModuleOrPredict(CSysNetModulePredict *p1, CSysNetModulePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetModuleOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetModule	Ҫ���жϵ�ģ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetModule *pSysNetModule)
	{
		return m_p1->isValid(pSysNetModule) || m_p2->isValid(pSysNetModule);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleNotPredict�Ƕ�һ��ģ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleNotPredict : public CSysNetModulePredict
{
private:
	CSysNetModulePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetModuleNotPredict(CSysNetModulePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetModuleNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetModule	Ҫ���жϵ�ģ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetModule *pSysNetModule)
	{
		return !m_predict->isValid(pSysNetModule);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleFilter��һ�������е�ģ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleFilter: public CSysNetModuleIterator
{
private:
	CSysNetModuleIterator *m_baseIterator;
	CSysNetModulePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetModuleFilter(CSysNetModuleIterator *pBaseIterator, CSysNetModulePredict *pPredict, bool continueResult=false)
		:CSysNetModuleIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetModuleFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetModule
	///@return	��һ����������CSysNetModule������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetModule *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetModule ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetModule * pSysNetModule,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleLinkIterator����������ģ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleLinkIterator: public CSysNetModuleIterator
{
private:
	CSysNetModuleIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetModuleLinkIterator(CSysNetModuleIterator *pBaseIterator1,CSysNetModuleIterator *pBaseIterator2)
		:CSysNetModuleIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetModuleLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetModule
	///@return	��һ����������CSysNetModule������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetModule *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetModule ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetModule * pSysNetModule,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprSingleIterator�����෵��һ���澯���ʽ��Ϣ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprSingleIterator: public CSysNetEventExprIterator
{
private:
	CSysNetEventExpr *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetEventExprSingleIterator(CSysNetEventExprFactory *pFactory,CSysNetEventExpr *pResult)
		:CSysNetEventExprIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetEventExprSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetEventExpr
	///@return	��һ����������CSysNetEventExpr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetEventExpr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetEventExpr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetEventExpr * pSysNetEventExpr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprPredict���ж�һ���澯���ʽ��Ϣ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetEventExpr	Ҫ���жϵĸ澯���ʽ��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetEventExpr *pSysNetEventExpr)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprAndPredict�Ƕ������澯���ʽ��Ϣ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprAndPredict : public CSysNetEventExprPredict
{
private:
	CSysNetEventExprPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetEventExprAndPredict(CSysNetEventExprPredict *p1, CSysNetEventExprPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetEventExprAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetEventExpr	Ҫ���жϵĸ澯���ʽ��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetEventExpr *pSysNetEventExpr)
	{
		return m_p1->isValid(pSysNetEventExpr) && m_p2->isValid(pSysNetEventExpr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprOrPredict�Ƕ������澯���ʽ��Ϣ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprOrPredict : public CSysNetEventExprPredict
{
private:
	CSysNetEventExprPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetEventExprOrPredict(CSysNetEventExprPredict *p1, CSysNetEventExprPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetEventExprOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetEventExpr	Ҫ���жϵĸ澯���ʽ��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetEventExpr *pSysNetEventExpr)
	{
		return m_p1->isValid(pSysNetEventExpr) || m_p2->isValid(pSysNetEventExpr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprNotPredict�Ƕ�һ���澯���ʽ��Ϣ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprNotPredict : public CSysNetEventExprPredict
{
private:
	CSysNetEventExprPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetEventExprNotPredict(CSysNetEventExprPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetEventExprNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetEventExpr	Ҫ���жϵĸ澯���ʽ��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetEventExpr *pSysNetEventExpr)
	{
		return !m_predict->isValid(pSysNetEventExpr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprFilter��һ�������еĸ澯���ʽ��Ϣ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprFilter: public CSysNetEventExprIterator
{
private:
	CSysNetEventExprIterator *m_baseIterator;
	CSysNetEventExprPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetEventExprFilter(CSysNetEventExprIterator *pBaseIterator, CSysNetEventExprPredict *pPredict, bool continueResult=false)
		:CSysNetEventExprIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetEventExprFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetEventExpr
	///@return	��һ����������CSysNetEventExpr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetEventExpr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetEventExpr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetEventExpr * pSysNetEventExpr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprLinkIterator�����������澯���ʽ��Ϣ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprLinkIterator: public CSysNetEventExprIterator
{
private:
	CSysNetEventExprIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetEventExprLinkIterator(CSysNetEventExprIterator *pBaseIterator1,CSysNetEventExprIterator *pBaseIterator2)
		:CSysNetEventExprIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetEventExprLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetEventExpr
	///@return	��һ����������CSysNetEventExpr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetEventExpr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetEventExpr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetEventExpr * pSysNetEventExpr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeSingleIterator�����෵��һ���¼����͵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeSingleIterator: public CSysNetEventTypeIterator
{
private:
	CSysNetEventType *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetEventTypeSingleIterator(CSysNetEventTypeFactory *pFactory,CSysNetEventType *pResult)
		:CSysNetEventTypeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetEventTypeSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetEventType
	///@return	��һ����������CSysNetEventType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetEventType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetEventType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetEventType * pSysNetEventType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypePredict���ж�һ���¼������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetEventType	Ҫ���жϵ��¼�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetEventType *pSysNetEventType)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeAndPredict�Ƕ������¼�����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeAndPredict : public CSysNetEventTypePredict
{
private:
	CSysNetEventTypePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetEventTypeAndPredict(CSysNetEventTypePredict *p1, CSysNetEventTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetEventTypeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetEventType	Ҫ���жϵ��¼�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetEventType *pSysNetEventType)
	{
		return m_p1->isValid(pSysNetEventType) && m_p2->isValid(pSysNetEventType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeOrPredict�Ƕ������¼�����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeOrPredict : public CSysNetEventTypePredict
{
private:
	CSysNetEventTypePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetEventTypeOrPredict(CSysNetEventTypePredict *p1, CSysNetEventTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetEventTypeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetEventType	Ҫ���жϵ��¼�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetEventType *pSysNetEventType)
	{
		return m_p1->isValid(pSysNetEventType) || m_p2->isValid(pSysNetEventType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeNotPredict�Ƕ�һ���¼�����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeNotPredict : public CSysNetEventTypePredict
{
private:
	CSysNetEventTypePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetEventTypeNotPredict(CSysNetEventTypePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetEventTypeNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetEventType	Ҫ���жϵ��¼�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetEventType *pSysNetEventType)
	{
		return !m_predict->isValid(pSysNetEventType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeFilter��һ�������е��¼�����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeFilter: public CSysNetEventTypeIterator
{
private:
	CSysNetEventTypeIterator *m_baseIterator;
	CSysNetEventTypePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetEventTypeFilter(CSysNetEventTypeIterator *pBaseIterator, CSysNetEventTypePredict *pPredict, bool continueResult=false)
		:CSysNetEventTypeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetEventTypeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetEventType
	///@return	��һ����������CSysNetEventType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetEventType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetEventType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetEventType * pSysNetEventType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeLinkIterator�����������¼�����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeLinkIterator: public CSysNetEventTypeIterator
{
private:
	CSysNetEventTypeIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetEventTypeLinkIterator(CSysNetEventTypeIterator *pBaseIterator1,CSysNetEventTypeIterator *pBaseIterator2)
		:CSysNetEventTypeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetEventTypeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetEventType
	///@return	��һ����������CSysNetEventType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetEventType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetEventType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetEventType * pSysNetEventType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeSingleIterator�����෵��һ���¼������͵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeSingleIterator: public CSysNetSubEventTypeIterator
{
private:
	CSysNetSubEventType *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetSubEventTypeSingleIterator(CSysNetSubEventTypeFactory *pFactory,CSysNetSubEventType *pResult)
		:CSysNetSubEventTypeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetSubEventTypeSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetSubEventType
	///@return	��һ����������CSysNetSubEventType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetSubEventType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetSubEventType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetSubEventType * pSysNetSubEventType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypePredict���ж�һ���¼��������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetSubEventType	Ҫ���жϵ��¼�������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetSubEventType *pSysNetSubEventType)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeAndPredict�Ƕ������¼�������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeAndPredict : public CSysNetSubEventTypePredict
{
private:
	CSysNetSubEventTypePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetSubEventTypeAndPredict(CSysNetSubEventTypePredict *p1, CSysNetSubEventTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetSubEventTypeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetSubEventType	Ҫ���жϵ��¼�������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetSubEventType *pSysNetSubEventType)
	{
		return m_p1->isValid(pSysNetSubEventType) && m_p2->isValid(pSysNetSubEventType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeOrPredict�Ƕ������¼�������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeOrPredict : public CSysNetSubEventTypePredict
{
private:
	CSysNetSubEventTypePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetSubEventTypeOrPredict(CSysNetSubEventTypePredict *p1, CSysNetSubEventTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetSubEventTypeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetSubEventType	Ҫ���жϵ��¼�������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetSubEventType *pSysNetSubEventType)
	{
		return m_p1->isValid(pSysNetSubEventType) || m_p2->isValid(pSysNetSubEventType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeNotPredict�Ƕ�һ���¼�������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeNotPredict : public CSysNetSubEventTypePredict
{
private:
	CSysNetSubEventTypePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetSubEventTypeNotPredict(CSysNetSubEventTypePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetSubEventTypeNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetSubEventType	Ҫ���жϵ��¼�������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetSubEventType *pSysNetSubEventType)
	{
		return !m_predict->isValid(pSysNetSubEventType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeFilter��һ�������е��¼�������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeFilter: public CSysNetSubEventTypeIterator
{
private:
	CSysNetSubEventTypeIterator *m_baseIterator;
	CSysNetSubEventTypePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetSubEventTypeFilter(CSysNetSubEventTypeIterator *pBaseIterator, CSysNetSubEventTypePredict *pPredict, bool continueResult=false)
		:CSysNetSubEventTypeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetSubEventTypeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetSubEventType
	///@return	��һ����������CSysNetSubEventType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetSubEventType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetSubEventType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetSubEventType * pSysNetSubEventType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeLinkIterator�����������¼�������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeLinkIterator: public CSysNetSubEventTypeIterator
{
private:
	CSysNetSubEventTypeIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetSubEventTypeLinkIterator(CSysNetSubEventTypeIterator *pBaseIterator1,CSysNetSubEventTypeIterator *pBaseIterator2)
		:CSysNetSubEventTypeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetSubEventTypeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetSubEventType
	///@return	��һ����������CSysNetSubEventType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetSubEventType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetSubEventType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetSubEventType * pSysNetSubEventType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelSingleIterator�����෵��һ���¼������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelSingleIterator: public CSysNetEventLevelIterator
{
private:
	CSysNetEventLevel *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetEventLevelSingleIterator(CSysNetEventLevelFactory *pFactory,CSysNetEventLevel *pResult)
		:CSysNetEventLevelIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetEventLevelSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetEventLevel
	///@return	��һ����������CSysNetEventLevel������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetEventLevel *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetEventLevel ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetEventLevel * pSysNetEventLevel,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelPredict���ж�һ���¼������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetEventLevel	Ҫ���жϵ��¼�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetEventLevel *pSysNetEventLevel)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelAndPredict�Ƕ������¼�����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelAndPredict : public CSysNetEventLevelPredict
{
private:
	CSysNetEventLevelPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetEventLevelAndPredict(CSysNetEventLevelPredict *p1, CSysNetEventLevelPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetEventLevelAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetEventLevel	Ҫ���жϵ��¼�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetEventLevel *pSysNetEventLevel)
	{
		return m_p1->isValid(pSysNetEventLevel) && m_p2->isValid(pSysNetEventLevel);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelOrPredict�Ƕ������¼�����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelOrPredict : public CSysNetEventLevelPredict
{
private:
	CSysNetEventLevelPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetEventLevelOrPredict(CSysNetEventLevelPredict *p1, CSysNetEventLevelPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetEventLevelOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetEventLevel	Ҫ���жϵ��¼�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetEventLevel *pSysNetEventLevel)
	{
		return m_p1->isValid(pSysNetEventLevel) || m_p2->isValid(pSysNetEventLevel);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelNotPredict�Ƕ�һ���¼�����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelNotPredict : public CSysNetEventLevelPredict
{
private:
	CSysNetEventLevelPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetEventLevelNotPredict(CSysNetEventLevelPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetEventLevelNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetEventLevel	Ҫ���жϵ��¼�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetEventLevel *pSysNetEventLevel)
	{
		return !m_predict->isValid(pSysNetEventLevel);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelFilter��һ�������е��¼�����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelFilter: public CSysNetEventLevelIterator
{
private:
	CSysNetEventLevelIterator *m_baseIterator;
	CSysNetEventLevelPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetEventLevelFilter(CSysNetEventLevelIterator *pBaseIterator, CSysNetEventLevelPredict *pPredict, bool continueResult=false)
		:CSysNetEventLevelIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetEventLevelFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetEventLevel
	///@return	��һ����������CSysNetEventLevel������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetEventLevel *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetEventLevel ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetEventLevel * pSysNetEventLevel,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelLinkIterator�����������¼�����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelLinkIterator: public CSysNetEventLevelIterator
{
private:
	CSysNetEventLevelIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetEventLevelLinkIterator(CSysNetEventLevelIterator *pBaseIterator1,CSysNetEventLevelIterator *pBaseIterator2)
		:CSysNetEventLevelIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetEventLevelLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetEventLevel
	///@return	��һ����������CSysNetEventLevel������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetEventLevel *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetEventLevel ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetEventLevel * pSysNetEventLevel,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskSingleIterator�����෵��һ������������������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskSingleIterator: public CSysNetMonitorDeviceTaskIterator
{
private:
	CSysNetMonitorDeviceTask *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetMonitorDeviceTaskSingleIterator(CSysNetMonitorDeviceTaskFactory *pFactory,CSysNetMonitorDeviceTask *pResult)
		:CSysNetMonitorDeviceTaskIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetMonitorDeviceTaskSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetMonitorDeviceTask
	///@return	��һ����������CSysNetMonitorDeviceTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorDeviceTask *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorDeviceTask ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskPredict���ж�һ������������������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorDeviceTask	Ҫ���жϵ����������������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskAndPredict�Ƕ��������������������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskAndPredict : public CSysNetMonitorDeviceTaskPredict
{
private:
	CSysNetMonitorDeviceTaskPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorDeviceTaskAndPredict(CSysNetMonitorDeviceTaskPredict *p1, CSysNetMonitorDeviceTaskPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorDeviceTaskAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorDeviceTask	Ҫ���жϵ����������������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return m_p1->isValid(pSysNetMonitorDeviceTask) && m_p2->isValid(pSysNetMonitorDeviceTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskOrPredict�Ƕ��������������������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskOrPredict : public CSysNetMonitorDeviceTaskPredict
{
private:
	CSysNetMonitorDeviceTaskPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorDeviceTaskOrPredict(CSysNetMonitorDeviceTaskPredict *p1, CSysNetMonitorDeviceTaskPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorDeviceTaskOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorDeviceTask	Ҫ���жϵ����������������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return m_p1->isValid(pSysNetMonitorDeviceTask) || m_p2->isValid(pSysNetMonitorDeviceTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskNotPredict�Ƕ�һ�����������������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskNotPredict : public CSysNetMonitorDeviceTaskPredict
{
private:
	CSysNetMonitorDeviceTaskPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetMonitorDeviceTaskNotPredict(CSysNetMonitorDeviceTaskPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetMonitorDeviceTaskNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorDeviceTask	Ҫ���жϵ����������������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return !m_predict->isValid(pSysNetMonitorDeviceTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskFilter��һ�������е����������������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskFilter: public CSysNetMonitorDeviceTaskIterator
{
private:
	CSysNetMonitorDeviceTaskIterator *m_baseIterator;
	CSysNetMonitorDeviceTaskPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetMonitorDeviceTaskFilter(CSysNetMonitorDeviceTaskIterator *pBaseIterator, CSysNetMonitorDeviceTaskPredict *pPredict, bool continueResult=false)
		:CSysNetMonitorDeviceTaskIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetMonitorDeviceTaskFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetMonitorDeviceTask
	///@return	��һ����������CSysNetMonitorDeviceTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorDeviceTask *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorDeviceTask ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskLinkIterator�������������������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskLinkIterator: public CSysNetMonitorDeviceTaskIterator
{
private:
	CSysNetMonitorDeviceTaskIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetMonitorDeviceTaskLinkIterator(CSysNetMonitorDeviceTaskIterator *pBaseIterator1,CSysNetMonitorDeviceTaskIterator *pBaseIterator2)
		:CSysNetMonitorDeviceTaskIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetMonitorDeviceTaskLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetMonitorDeviceTask
	///@return	��һ����������CSysNetMonitorDeviceTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorDeviceTask *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorDeviceTask ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsSingleIterator�����෵��һ������ָ��ָ�꼯���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsSingleIterator: public CSysNetMonitorTaskInstAttrsIterator
{
private:
	CSysNetMonitorTaskInstAttrs *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetMonitorTaskInstAttrsSingleIterator(CSysNetMonitorTaskInstAttrsFactory *pFactory,CSysNetMonitorTaskInstAttrs *pResult)
		:CSysNetMonitorTaskInstAttrsIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetMonitorTaskInstAttrsSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetMonitorTaskInstAttrs
	///@return	��һ����������CSysNetMonitorTaskInstAttrs������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskInstAttrs *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorTaskInstAttrs ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsPredict���ж�һ������ָ��ָ�꼯���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorTaskInstAttrs	Ҫ���жϵ�����ָ��ָ�꼯��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsAndPredict�Ƕ���������ָ��ָ�꼯��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsAndPredict : public CSysNetMonitorTaskInstAttrsPredict
{
private:
	CSysNetMonitorTaskInstAttrsPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorTaskInstAttrsAndPredict(CSysNetMonitorTaskInstAttrsPredict *p1, CSysNetMonitorTaskInstAttrsPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorTaskInstAttrsAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorTaskInstAttrs	Ҫ���жϵ�����ָ��ָ�꼯��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return m_p1->isValid(pSysNetMonitorTaskInstAttrs) && m_p2->isValid(pSysNetMonitorTaskInstAttrs);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsOrPredict�Ƕ���������ָ��ָ�꼯��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsOrPredict : public CSysNetMonitorTaskInstAttrsPredict
{
private:
	CSysNetMonitorTaskInstAttrsPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMonitorTaskInstAttrsOrPredict(CSysNetMonitorTaskInstAttrsPredict *p1, CSysNetMonitorTaskInstAttrsPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMonitorTaskInstAttrsOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorTaskInstAttrs	Ҫ���жϵ�����ָ��ָ�꼯��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return m_p1->isValid(pSysNetMonitorTaskInstAttrs) || m_p2->isValid(pSysNetMonitorTaskInstAttrs);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsNotPredict�Ƕ�һ������ָ��ָ�꼯��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsNotPredict : public CSysNetMonitorTaskInstAttrsPredict
{
private:
	CSysNetMonitorTaskInstAttrsPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetMonitorTaskInstAttrsNotPredict(CSysNetMonitorTaskInstAttrsPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetMonitorTaskInstAttrsNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMonitorTaskInstAttrs	Ҫ���жϵ�����ָ��ָ�꼯��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return !m_predict->isValid(pSysNetMonitorTaskInstAttrs);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsFilter��һ�������е�����ָ��ָ�꼯��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsFilter: public CSysNetMonitorTaskInstAttrsIterator
{
private:
	CSysNetMonitorTaskInstAttrsIterator *m_baseIterator;
	CSysNetMonitorTaskInstAttrsPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetMonitorTaskInstAttrsFilter(CSysNetMonitorTaskInstAttrsIterator *pBaseIterator, CSysNetMonitorTaskInstAttrsPredict *pPredict, bool continueResult=false)
		:CSysNetMonitorTaskInstAttrsIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetMonitorTaskInstAttrsFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetMonitorTaskInstAttrs
	///@return	��һ����������CSysNetMonitorTaskInstAttrs������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskInstAttrs *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorTaskInstAttrs ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsLinkIterator��������������ָ��ָ�꼯��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsLinkIterator: public CSysNetMonitorTaskInstAttrsIterator
{
private:
	CSysNetMonitorTaskInstAttrsIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetMonitorTaskInstAttrsLinkIterator(CSysNetMonitorTaskInstAttrsIterator *pBaseIterator1,CSysNetMonitorTaskInstAttrsIterator *pBaseIterator2)
		:CSysNetMonitorTaskInstAttrsIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetMonitorTaskInstAttrsLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetMonitorTaskInstAttrs
	///@return	��һ����������CSysNetMonitorTaskInstAttrs������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskInstAttrs *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorTaskInstAttrs ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineSingleIterator�����෵��һ�����߱��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineSingleIterator: public CSysNetBaseLineIterator
{
private:
	CSysNetBaseLine *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetBaseLineSingleIterator(CSysNetBaseLineFactory *pFactory,CSysNetBaseLine *pResult)
		:CSysNetBaseLineIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetBaseLineSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetBaseLine
	///@return	��һ����������CSysNetBaseLine������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetBaseLine *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetBaseLine ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetBaseLine * pSysNetBaseLine,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLinePredict���ж�һ�����߱��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLinePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetBaseLine	Ҫ���жϵĻ��߱�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetBaseLine *pSysNetBaseLine)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineAndPredict�Ƕ��������߱�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineAndPredict : public CSysNetBaseLinePredict
{
private:
	CSysNetBaseLinePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetBaseLineAndPredict(CSysNetBaseLinePredict *p1, CSysNetBaseLinePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetBaseLineAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetBaseLine	Ҫ���жϵĻ��߱�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetBaseLine *pSysNetBaseLine)
	{
		return m_p1->isValid(pSysNetBaseLine) && m_p2->isValid(pSysNetBaseLine);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineOrPredict�Ƕ��������߱�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineOrPredict : public CSysNetBaseLinePredict
{
private:
	CSysNetBaseLinePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetBaseLineOrPredict(CSysNetBaseLinePredict *p1, CSysNetBaseLinePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetBaseLineOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetBaseLine	Ҫ���жϵĻ��߱�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetBaseLine *pSysNetBaseLine)
	{
		return m_p1->isValid(pSysNetBaseLine) || m_p2->isValid(pSysNetBaseLine);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineNotPredict�Ƕ�һ�����߱�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineNotPredict : public CSysNetBaseLinePredict
{
private:
	CSysNetBaseLinePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetBaseLineNotPredict(CSysNetBaseLinePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetBaseLineNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetBaseLine	Ҫ���жϵĻ��߱�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetBaseLine *pSysNetBaseLine)
	{
		return !m_predict->isValid(pSysNetBaseLine);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineFilter��һ�������еĻ��߱�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineFilter: public CSysNetBaseLineIterator
{
private:
	CSysNetBaseLineIterator *m_baseIterator;
	CSysNetBaseLinePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetBaseLineFilter(CSysNetBaseLineIterator *pBaseIterator, CSysNetBaseLinePredict *pPredict, bool continueResult=false)
		:CSysNetBaseLineIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetBaseLineFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetBaseLine
	///@return	��һ����������CSysNetBaseLine������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetBaseLine *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetBaseLine ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetBaseLine * pSysNetBaseLine,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineLinkIterator�������������߱�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineLinkIterator: public CSysNetBaseLineIterator
{
private:
	CSysNetBaseLineIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetBaseLineLinkIterator(CSysNetBaseLineIterator *pBaseIterator1,CSysNetBaseLineIterator *pBaseIterator2)
		:CSysNetBaseLineIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetBaseLineLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetBaseLine
	///@return	��һ����������CSysNetBaseLine������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetBaseLine *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetBaseLine ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetBaseLine * pSysNetBaseLine,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskSingleIterator�����෵��һ������������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskSingleIterator: public CSysNetBaseLineTaskIterator
{
private:
	CSysNetBaseLineTask *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetBaseLineTaskSingleIterator(CSysNetBaseLineTaskFactory *pFactory,CSysNetBaseLineTask *pResult)
		:CSysNetBaseLineTaskIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetBaseLineTaskSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetBaseLineTask
	///@return	��һ����������CSysNetBaseLineTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetBaseLineTask *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetBaseLineTask ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetBaseLineTask * pSysNetBaseLineTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskPredict���ж�һ������������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetBaseLineTask	Ҫ���жϵĻ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetBaseLineTask *pSysNetBaseLineTask)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskAndPredict�Ƕ��������������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskAndPredict : public CSysNetBaseLineTaskPredict
{
private:
	CSysNetBaseLineTaskPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetBaseLineTaskAndPredict(CSysNetBaseLineTaskPredict *p1, CSysNetBaseLineTaskPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetBaseLineTaskAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetBaseLineTask	Ҫ���жϵĻ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return m_p1->isValid(pSysNetBaseLineTask) && m_p2->isValid(pSysNetBaseLineTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskOrPredict�Ƕ��������������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskOrPredict : public CSysNetBaseLineTaskPredict
{
private:
	CSysNetBaseLineTaskPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetBaseLineTaskOrPredict(CSysNetBaseLineTaskPredict *p1, CSysNetBaseLineTaskPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetBaseLineTaskOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetBaseLineTask	Ҫ���жϵĻ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return m_p1->isValid(pSysNetBaseLineTask) || m_p2->isValid(pSysNetBaseLineTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskNotPredict�Ƕ�һ�����������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskNotPredict : public CSysNetBaseLineTaskPredict
{
private:
	CSysNetBaseLineTaskPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetBaseLineTaskNotPredict(CSysNetBaseLineTaskPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetBaseLineTaskNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetBaseLineTask	Ҫ���жϵĻ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return !m_predict->isValid(pSysNetBaseLineTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskFilter��һ�������еĻ��������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskFilter: public CSysNetBaseLineTaskIterator
{
private:
	CSysNetBaseLineTaskIterator *m_baseIterator;
	CSysNetBaseLineTaskPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetBaseLineTaskFilter(CSysNetBaseLineTaskIterator *pBaseIterator, CSysNetBaseLineTaskPredict *pPredict, bool continueResult=false)
		:CSysNetBaseLineTaskIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetBaseLineTaskFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetBaseLineTask
	///@return	��һ����������CSysNetBaseLineTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetBaseLineTask *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetBaseLineTask ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetBaseLineTask * pSysNetBaseLineTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskLinkIterator�������������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskLinkIterator: public CSysNetBaseLineTaskIterator
{
private:
	CSysNetBaseLineTaskIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetBaseLineTaskLinkIterator(CSysNetBaseLineTaskIterator *pBaseIterator1,CSysNetBaseLineTaskIterator *pBaseIterator2)
		:CSysNetBaseLineTaskIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetBaseLineTaskLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetBaseLineTask
	///@return	��һ����������CSysNetBaseLineTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetBaseLineTask *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetBaseLineTask ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetBaseLineTask * pSysNetBaseLineTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoSingleIterator�����෵��һ����Ա��·״̬��Ϣ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoSingleIterator: public CSysMdbNetPartyLinkStatusInfoIterator
{
private:
	CSysMdbNetPartyLinkStatusInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMdbNetPartyLinkStatusInfoSingleIterator(CSysMdbNetPartyLinkStatusInfoFactory *pFactory,CSysMdbNetPartyLinkStatusInfo *pResult)
		:CSysMdbNetPartyLinkStatusInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMdbNetPartyLinkStatusInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMdbNetPartyLinkStatusInfo
	///@return	��һ����������CSysMdbNetPartyLinkStatusInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbNetPartyLinkStatusInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbNetPartyLinkStatusInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoPredict���ж�һ����Ա��·״̬��Ϣ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbNetPartyLinkStatusInfo	Ҫ���жϵĻ�Ա��·״̬��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoAndPredict�Ƕ�������Ա��·״̬��Ϣ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoAndPredict : public CSysMdbNetPartyLinkStatusInfoPredict
{
private:
	CSysMdbNetPartyLinkStatusInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbNetPartyLinkStatusInfoAndPredict(CSysMdbNetPartyLinkStatusInfoPredict *p1, CSysMdbNetPartyLinkStatusInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbNetPartyLinkStatusInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbNetPartyLinkStatusInfo	Ҫ���жϵĻ�Ա��·״̬��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return m_p1->isValid(pSysMdbNetPartyLinkStatusInfo) && m_p2->isValid(pSysMdbNetPartyLinkStatusInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoOrPredict�Ƕ�������Ա��·״̬��Ϣ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoOrPredict : public CSysMdbNetPartyLinkStatusInfoPredict
{
private:
	CSysMdbNetPartyLinkStatusInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbNetPartyLinkStatusInfoOrPredict(CSysMdbNetPartyLinkStatusInfoPredict *p1, CSysMdbNetPartyLinkStatusInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbNetPartyLinkStatusInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbNetPartyLinkStatusInfo	Ҫ���жϵĻ�Ա��·״̬��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return m_p1->isValid(pSysMdbNetPartyLinkStatusInfo) || m_p2->isValid(pSysMdbNetPartyLinkStatusInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoNotPredict�Ƕ�һ����Ա��·״̬��Ϣ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoNotPredict : public CSysMdbNetPartyLinkStatusInfoPredict
{
private:
	CSysMdbNetPartyLinkStatusInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMdbNetPartyLinkStatusInfoNotPredict(CSysMdbNetPartyLinkStatusInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMdbNetPartyLinkStatusInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbNetPartyLinkStatusInfo	Ҫ���жϵĻ�Ա��·״̬��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return !m_predict->isValid(pSysMdbNetPartyLinkStatusInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoFilter��һ�������еĻ�Ա��·״̬��Ϣ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoFilter: public CSysMdbNetPartyLinkStatusInfoIterator
{
private:
	CSysMdbNetPartyLinkStatusInfoIterator *m_baseIterator;
	CSysMdbNetPartyLinkStatusInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMdbNetPartyLinkStatusInfoFilter(CSysMdbNetPartyLinkStatusInfoIterator *pBaseIterator, CSysMdbNetPartyLinkStatusInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbNetPartyLinkStatusInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMdbNetPartyLinkStatusInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMdbNetPartyLinkStatusInfo
	///@return	��һ����������CSysMdbNetPartyLinkStatusInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbNetPartyLinkStatusInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbNetPartyLinkStatusInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoLinkIterator������������Ա��·״̬��Ϣ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoLinkIterator: public CSysMdbNetPartyLinkStatusInfoIterator
{
private:
	CSysMdbNetPartyLinkStatusInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMdbNetPartyLinkStatusInfoLinkIterator(CSysMdbNetPartyLinkStatusInfoIterator *pBaseIterator1,CSysMdbNetPartyLinkStatusInfoIterator *pBaseIterator2)
		:CSysMdbNetPartyLinkStatusInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMdbNetPartyLinkStatusInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMdbNetPartyLinkStatusInfo
	///@return	��һ����������CSysMdbNetPartyLinkStatusInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbNetPartyLinkStatusInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbNetPartyLinkStatusInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoSingleIterator�����෵��һ����ԱSDH��·��ϸ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoSingleIterator: public CSysNetMemberSDHLineInfoIterator
{
private:
	CSysNetMemberSDHLineInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetMemberSDHLineInfoSingleIterator(CSysNetMemberSDHLineInfoFactory *pFactory,CSysNetMemberSDHLineInfo *pResult)
		:CSysNetMemberSDHLineInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetMemberSDHLineInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetMemberSDHLineInfo
	///@return	��һ����������CSysNetMemberSDHLineInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMemberSDHLineInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMemberSDHLineInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoPredict���ж�һ����ԱSDH��·��ϸ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMemberSDHLineInfo	Ҫ���жϵĻ�ԱSDH��·��ϸ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoAndPredict�Ƕ�������ԱSDH��·��ϸ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoAndPredict : public CSysNetMemberSDHLineInfoPredict
{
private:
	CSysNetMemberSDHLineInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMemberSDHLineInfoAndPredict(CSysNetMemberSDHLineInfoPredict *p1, CSysNetMemberSDHLineInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMemberSDHLineInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMemberSDHLineInfo	Ҫ���жϵĻ�ԱSDH��·��ϸ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return m_p1->isValid(pSysNetMemberSDHLineInfo) && m_p2->isValid(pSysNetMemberSDHLineInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoOrPredict�Ƕ�������ԱSDH��·��ϸ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoOrPredict : public CSysNetMemberSDHLineInfoPredict
{
private:
	CSysNetMemberSDHLineInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetMemberSDHLineInfoOrPredict(CSysNetMemberSDHLineInfoPredict *p1, CSysNetMemberSDHLineInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetMemberSDHLineInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMemberSDHLineInfo	Ҫ���жϵĻ�ԱSDH��·��ϸ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return m_p1->isValid(pSysNetMemberSDHLineInfo) || m_p2->isValid(pSysNetMemberSDHLineInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoNotPredict�Ƕ�һ����ԱSDH��·��ϸ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoNotPredict : public CSysNetMemberSDHLineInfoPredict
{
private:
	CSysNetMemberSDHLineInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetMemberSDHLineInfoNotPredict(CSysNetMemberSDHLineInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetMemberSDHLineInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetMemberSDHLineInfo	Ҫ���жϵĻ�ԱSDH��·��ϸ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return !m_predict->isValid(pSysNetMemberSDHLineInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoFilter��һ�������еĻ�ԱSDH��·��ϸ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoFilter: public CSysNetMemberSDHLineInfoIterator
{
private:
	CSysNetMemberSDHLineInfoIterator *m_baseIterator;
	CSysNetMemberSDHLineInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetMemberSDHLineInfoFilter(CSysNetMemberSDHLineInfoIterator *pBaseIterator, CSysNetMemberSDHLineInfoPredict *pPredict, bool continueResult=false)
		:CSysNetMemberSDHLineInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetMemberSDHLineInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetMemberSDHLineInfo
	///@return	��һ����������CSysNetMemberSDHLineInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMemberSDHLineInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMemberSDHLineInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoLinkIterator������������ԱSDH��·��ϸ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoLinkIterator: public CSysNetMemberSDHLineInfoIterator
{
private:
	CSysNetMemberSDHLineInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetMemberSDHLineInfoLinkIterator(CSysNetMemberSDHLineInfoIterator *pBaseIterator1,CSysNetMemberSDHLineInfoIterator *pBaseIterator2)
		:CSysNetMemberSDHLineInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetMemberSDHLineInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetMemberSDHLineInfo
	///@return	��һ����������CSysNetMemberSDHLineInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMemberSDHLineInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMemberSDHLineInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoSingleIterator�����෵��һ��DDN��·��Ϣ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoSingleIterator: public CSysNetDDNLinkInfoIterator
{
private:
	CSysNetDDNLinkInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetDDNLinkInfoSingleIterator(CSysNetDDNLinkInfoFactory *pFactory,CSysNetDDNLinkInfo *pResult)
		:CSysNetDDNLinkInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetDDNLinkInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetDDNLinkInfo
	///@return	��һ����������CSysNetDDNLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDDNLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDDNLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDDNLinkInfo * pSysNetDDNLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoPredict���ж�һ��DDN��·��Ϣ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDDNLinkInfo	Ҫ���жϵ�DDN��·��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoAndPredict�Ƕ�����DDN��·��Ϣ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoAndPredict : public CSysNetDDNLinkInfoPredict
{
private:
	CSysNetDDNLinkInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetDDNLinkInfoAndPredict(CSysNetDDNLinkInfoPredict *p1, CSysNetDDNLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetDDNLinkInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDDNLinkInfo	Ҫ���жϵ�DDN��·��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return m_p1->isValid(pSysNetDDNLinkInfo) && m_p2->isValid(pSysNetDDNLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoOrPredict�Ƕ�����DDN��·��Ϣ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoOrPredict : public CSysNetDDNLinkInfoPredict
{
private:
	CSysNetDDNLinkInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetDDNLinkInfoOrPredict(CSysNetDDNLinkInfoPredict *p1, CSysNetDDNLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetDDNLinkInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDDNLinkInfo	Ҫ���жϵ�DDN��·��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return m_p1->isValid(pSysNetDDNLinkInfo) || m_p2->isValid(pSysNetDDNLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoNotPredict�Ƕ�һ��DDN��·��Ϣ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoNotPredict : public CSysNetDDNLinkInfoPredict
{
private:
	CSysNetDDNLinkInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetDDNLinkInfoNotPredict(CSysNetDDNLinkInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetDDNLinkInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetDDNLinkInfo	Ҫ���жϵ�DDN��·��Ϣ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return !m_predict->isValid(pSysNetDDNLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoFilter��һ�������е�DDN��·��Ϣ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoFilter: public CSysNetDDNLinkInfoIterator
{
private:
	CSysNetDDNLinkInfoIterator *m_baseIterator;
	CSysNetDDNLinkInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetDDNLinkInfoFilter(CSysNetDDNLinkInfoIterator *pBaseIterator, CSysNetDDNLinkInfoPredict *pPredict, bool continueResult=false)
		:CSysNetDDNLinkInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetDDNLinkInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetDDNLinkInfo
	///@return	��һ����������CSysNetDDNLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDDNLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDDNLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDDNLinkInfo * pSysNetDDNLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoLinkIterator����������DDN��·��Ϣ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoLinkIterator: public CSysNetDDNLinkInfoIterator
{
private:
	CSysNetDDNLinkInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetDDNLinkInfoLinkIterator(CSysNetDDNLinkInfoIterator *pBaseIterator1,CSysNetDDNLinkInfoIterator *pBaseIterator2)
		:CSysNetDDNLinkInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetDDNLinkInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetDDNLinkInfo
	///@return	��һ����������CSysNetDDNLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDDNLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDDNLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDDNLinkInfo * pSysNetDDNLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoSingleIterator�����෵��һ���ǻ�Ա��·ʹ����Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoSingleIterator: public CSysNetPseudMemberLinkInfoIterator
{
private:
	CSysNetPseudMemberLinkInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetPseudMemberLinkInfoSingleIterator(CSysNetPseudMemberLinkInfoFactory *pFactory,CSysNetPseudMemberLinkInfo *pResult)
		:CSysNetPseudMemberLinkInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetPseudMemberLinkInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetPseudMemberLinkInfo
	///@return	��һ����������CSysNetPseudMemberLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPseudMemberLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPseudMemberLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoPredict���ж�һ���ǻ�Ա��·ʹ����Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPseudMemberLinkInfo	Ҫ���жϵķǻ�Ա��·ʹ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoAndPredict�Ƕ������ǻ�Ա��·ʹ����Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoAndPredict : public CSysNetPseudMemberLinkInfoPredict
{
private:
	CSysNetPseudMemberLinkInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetPseudMemberLinkInfoAndPredict(CSysNetPseudMemberLinkInfoPredict *p1, CSysNetPseudMemberLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetPseudMemberLinkInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPseudMemberLinkInfo	Ҫ���жϵķǻ�Ա��·ʹ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return m_p1->isValid(pSysNetPseudMemberLinkInfo) && m_p2->isValid(pSysNetPseudMemberLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoOrPredict�Ƕ������ǻ�Ա��·ʹ����Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoOrPredict : public CSysNetPseudMemberLinkInfoPredict
{
private:
	CSysNetPseudMemberLinkInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetPseudMemberLinkInfoOrPredict(CSysNetPseudMemberLinkInfoPredict *p1, CSysNetPseudMemberLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetPseudMemberLinkInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPseudMemberLinkInfo	Ҫ���жϵķǻ�Ա��·ʹ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return m_p1->isValid(pSysNetPseudMemberLinkInfo) || m_p2->isValid(pSysNetPseudMemberLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoNotPredict�Ƕ�һ���ǻ�Ա��·ʹ����Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoNotPredict : public CSysNetPseudMemberLinkInfoPredict
{
private:
	CSysNetPseudMemberLinkInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetPseudMemberLinkInfoNotPredict(CSysNetPseudMemberLinkInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetPseudMemberLinkInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPseudMemberLinkInfo	Ҫ���жϵķǻ�Ա��·ʹ����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return !m_predict->isValid(pSysNetPseudMemberLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoFilter��һ�������еķǻ�Ա��·ʹ����Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoFilter: public CSysNetPseudMemberLinkInfoIterator
{
private:
	CSysNetPseudMemberLinkInfoIterator *m_baseIterator;
	CSysNetPseudMemberLinkInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetPseudMemberLinkInfoFilter(CSysNetPseudMemberLinkInfoIterator *pBaseIterator, CSysNetPseudMemberLinkInfoPredict *pPredict, bool continueResult=false)
		:CSysNetPseudMemberLinkInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetPseudMemberLinkInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetPseudMemberLinkInfo
	///@return	��һ����������CSysNetPseudMemberLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPseudMemberLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPseudMemberLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoLinkIterator�����������ǻ�Ա��·ʹ����Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoLinkIterator: public CSysNetPseudMemberLinkInfoIterator
{
private:
	CSysNetPseudMemberLinkInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetPseudMemberLinkInfoLinkIterator(CSysNetPseudMemberLinkInfoIterator *pBaseIterator1,CSysNetPseudMemberLinkInfoIterator *pBaseIterator2)
		:CSysNetPseudMemberLinkInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetPseudMemberLinkInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetPseudMemberLinkInfo
	///@return	��һ����������CSysNetPseudMemberLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPseudMemberLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPseudMemberLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoSingleIterator�����෵��һ��Զ���豸��Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoSingleIterator: public CSysNetOuterDeviceInfoIterator
{
private:
	CSysNetOuterDeviceInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetOuterDeviceInfoSingleIterator(CSysNetOuterDeviceInfoFactory *pFactory,CSysNetOuterDeviceInfo *pResult)
		:CSysNetOuterDeviceInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetOuterDeviceInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetOuterDeviceInfo
	///@return	��һ����������CSysNetOuterDeviceInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetOuterDeviceInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetOuterDeviceInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoPredict���ж�һ��Զ���豸��Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetOuterDeviceInfo	Ҫ���жϵ�Զ���豸��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoAndPredict�Ƕ�����Զ���豸��Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoAndPredict : public CSysNetOuterDeviceInfoPredict
{
private:
	CSysNetOuterDeviceInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetOuterDeviceInfoAndPredict(CSysNetOuterDeviceInfoPredict *p1, CSysNetOuterDeviceInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetOuterDeviceInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetOuterDeviceInfo	Ҫ���жϵ�Զ���豸��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return m_p1->isValid(pSysNetOuterDeviceInfo) && m_p2->isValid(pSysNetOuterDeviceInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoOrPredict�Ƕ�����Զ���豸��Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoOrPredict : public CSysNetOuterDeviceInfoPredict
{
private:
	CSysNetOuterDeviceInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetOuterDeviceInfoOrPredict(CSysNetOuterDeviceInfoPredict *p1, CSysNetOuterDeviceInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetOuterDeviceInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetOuterDeviceInfo	Ҫ���жϵ�Զ���豸��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return m_p1->isValid(pSysNetOuterDeviceInfo) || m_p2->isValid(pSysNetOuterDeviceInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoNotPredict�Ƕ�һ��Զ���豸��Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoNotPredict : public CSysNetOuterDeviceInfoPredict
{
private:
	CSysNetOuterDeviceInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetOuterDeviceInfoNotPredict(CSysNetOuterDeviceInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetOuterDeviceInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetOuterDeviceInfo	Ҫ���жϵ�Զ���豸��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return !m_predict->isValid(pSysNetOuterDeviceInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoFilter��һ�������е�Զ���豸��Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoFilter: public CSysNetOuterDeviceInfoIterator
{
private:
	CSysNetOuterDeviceInfoIterator *m_baseIterator;
	CSysNetOuterDeviceInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetOuterDeviceInfoFilter(CSysNetOuterDeviceInfoIterator *pBaseIterator, CSysNetOuterDeviceInfoPredict *pPredict, bool continueResult=false)
		:CSysNetOuterDeviceInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetOuterDeviceInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetOuterDeviceInfo
	///@return	��һ����������CSysNetOuterDeviceInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetOuterDeviceInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetOuterDeviceInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoLinkIterator����������Զ���豸��Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoLinkIterator: public CSysNetOuterDeviceInfoIterator
{
private:
	CSysNetOuterDeviceInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetOuterDeviceInfoLinkIterator(CSysNetOuterDeviceInfoIterator *pBaseIterator1,CSysNetOuterDeviceInfoIterator *pBaseIterator2)
		:CSysNetOuterDeviceInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetOuterDeviceInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetOuterDeviceInfo
	///@return	��һ����������CSysNetOuterDeviceInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetOuterDeviceInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetOuterDeviceInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoSingleIterator�����෵��һ������ping�����ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoSingleIterator: public CSysLocalPingResultInfoIterator
{
private:
	CSysLocalPingResultInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysLocalPingResultInfoSingleIterator(CSysLocalPingResultInfoFactory *pFactory,CSysLocalPingResultInfo *pResult)
		:CSysLocalPingResultInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysLocalPingResultInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysLocalPingResultInfo
	///@return	��һ����������CSysLocalPingResultInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysLocalPingResultInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysLocalPingResultInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysLocalPingResultInfo * pSysLocalPingResultInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoPredict���ж�һ������ping����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysLocalPingResultInfo	Ҫ���жϵı���ping���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysLocalPingResultInfo *pSysLocalPingResultInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoAndPredict�Ƕ���������ping���ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoAndPredict : public CSysLocalPingResultInfoPredict
{
private:
	CSysLocalPingResultInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysLocalPingResultInfoAndPredict(CSysLocalPingResultInfoPredict *p1, CSysLocalPingResultInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysLocalPingResultInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysLocalPingResultInfo	Ҫ���жϵı���ping���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return m_p1->isValid(pSysLocalPingResultInfo) && m_p2->isValid(pSysLocalPingResultInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoOrPredict�Ƕ���������ping���ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoOrPredict : public CSysLocalPingResultInfoPredict
{
private:
	CSysLocalPingResultInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysLocalPingResultInfoOrPredict(CSysLocalPingResultInfoPredict *p1, CSysLocalPingResultInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysLocalPingResultInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysLocalPingResultInfo	Ҫ���жϵı���ping���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return m_p1->isValid(pSysLocalPingResultInfo) || m_p2->isValid(pSysLocalPingResultInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoNotPredict�Ƕ�һ������ping���ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoNotPredict : public CSysLocalPingResultInfoPredict
{
private:
	CSysLocalPingResultInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysLocalPingResultInfoNotPredict(CSysLocalPingResultInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysLocalPingResultInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysLocalPingResultInfo	Ҫ���жϵı���ping���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return !m_predict->isValid(pSysLocalPingResultInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoFilter��һ�������еı���ping���ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoFilter: public CSysLocalPingResultInfoIterator
{
private:
	CSysLocalPingResultInfoIterator *m_baseIterator;
	CSysLocalPingResultInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysLocalPingResultInfoFilter(CSysLocalPingResultInfoIterator *pBaseIterator, CSysLocalPingResultInfoPredict *pPredict, bool continueResult=false)
		:CSysLocalPingResultInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysLocalPingResultInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysLocalPingResultInfo
	///@return	��һ����������CSysLocalPingResultInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysLocalPingResultInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysLocalPingResultInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysLocalPingResultInfo * pSysLocalPingResultInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoLinkIterator��������������ping���ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoLinkIterator: public CSysLocalPingResultInfoIterator
{
private:
	CSysLocalPingResultInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysLocalPingResultInfoLinkIterator(CSysLocalPingResultInfoIterator *pBaseIterator1,CSysLocalPingResultInfoIterator *pBaseIterator2)
		:CSysLocalPingResultInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysLocalPingResultInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysLocalPingResultInfo
	///@return	��һ����������CSysLocalPingResultInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysLocalPingResultInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysLocalPingResultInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysLocalPingResultInfo * pSysLocalPingResultInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoSingleIterator�����෵��һ��Զ��ping�����ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoSingleIterator: public CSysRomotePingResultInfoIterator
{
private:
	CSysRomotePingResultInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysRomotePingResultInfoSingleIterator(CSysRomotePingResultInfoFactory *pFactory,CSysRomotePingResultInfo *pResult)
		:CSysRomotePingResultInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysRomotePingResultInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysRomotePingResultInfo
	///@return	��һ����������CSysRomotePingResultInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysRomotePingResultInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysRomotePingResultInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysRomotePingResultInfo * pSysRomotePingResultInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoPredict���ж�һ��Զ��ping����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysRomotePingResultInfo	Ҫ���жϵ�Զ��ping���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysRomotePingResultInfo *pSysRomotePingResultInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoAndPredict�Ƕ�����Զ��ping���ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoAndPredict : public CSysRomotePingResultInfoPredict
{
private:
	CSysRomotePingResultInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysRomotePingResultInfoAndPredict(CSysRomotePingResultInfoPredict *p1, CSysRomotePingResultInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysRomotePingResultInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysRomotePingResultInfo	Ҫ���жϵ�Զ��ping���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return m_p1->isValid(pSysRomotePingResultInfo) && m_p2->isValid(pSysRomotePingResultInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoOrPredict�Ƕ�����Զ��ping���ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoOrPredict : public CSysRomotePingResultInfoPredict
{
private:
	CSysRomotePingResultInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysRomotePingResultInfoOrPredict(CSysRomotePingResultInfoPredict *p1, CSysRomotePingResultInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysRomotePingResultInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysRomotePingResultInfo	Ҫ���жϵ�Զ��ping���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return m_p1->isValid(pSysRomotePingResultInfo) || m_p2->isValid(pSysRomotePingResultInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoNotPredict�Ƕ�һ��Զ��ping���ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoNotPredict : public CSysRomotePingResultInfoPredict
{
private:
	CSysRomotePingResultInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysRomotePingResultInfoNotPredict(CSysRomotePingResultInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysRomotePingResultInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysRomotePingResultInfo	Ҫ���жϵ�Զ��ping���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return !m_predict->isValid(pSysRomotePingResultInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoFilter��һ�������е�Զ��ping���ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoFilter: public CSysRomotePingResultInfoIterator
{
private:
	CSysRomotePingResultInfoIterator *m_baseIterator;
	CSysRomotePingResultInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysRomotePingResultInfoFilter(CSysRomotePingResultInfoIterator *pBaseIterator, CSysRomotePingResultInfoPredict *pPredict, bool continueResult=false)
		:CSysRomotePingResultInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysRomotePingResultInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysRomotePingResultInfo
	///@return	��һ����������CSysRomotePingResultInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysRomotePingResultInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysRomotePingResultInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysRomotePingResultInfo * pSysRomotePingResultInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoLinkIterator����������Զ��ping���ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoLinkIterator: public CSysRomotePingResultInfoIterator
{
private:
	CSysRomotePingResultInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysRomotePingResultInfoLinkIterator(CSysRomotePingResultInfoIterator *pBaseIterator1,CSysRomotePingResultInfoIterator *pBaseIterator2)
		:CSysRomotePingResultInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysRomotePingResultInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysRomotePingResultInfo
	///@return	��һ����������CSysRomotePingResultInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysRomotePingResultInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysRomotePingResultInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysRomotePingResultInfo * pSysRomotePingResultInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesSingleIterator�����෵��һ����Աϯλ����״̬��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesSingleIterator: public CSysParticTradeOrderStatesIterator
{
private:
	CSysParticTradeOrderStates *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysParticTradeOrderStatesSingleIterator(CSysParticTradeOrderStatesFactory *pFactory,CSysParticTradeOrderStates *pResult)
		:CSysParticTradeOrderStatesIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysParticTradeOrderStatesSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysParticTradeOrderStates
	///@return	��һ����������CSysParticTradeOrderStates������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysParticTradeOrderStates *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysParticTradeOrderStates ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysParticTradeOrderStates * pSysParticTradeOrderStates,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesPredict���ж�һ����Աϯλ����״̬�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysParticTradeOrderStates	Ҫ���жϵĻ�Աϯλ����״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysParticTradeOrderStates *pSysParticTradeOrderStates)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesAndPredict�Ƕ�������Աϯλ����״̬ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesAndPredict : public CSysParticTradeOrderStatesPredict
{
private:
	CSysParticTradeOrderStatesPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysParticTradeOrderStatesAndPredict(CSysParticTradeOrderStatesPredict *p1, CSysParticTradeOrderStatesPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysParticTradeOrderStatesAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysParticTradeOrderStates	Ҫ���жϵĻ�Աϯλ����״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return m_p1->isValid(pSysParticTradeOrderStates) && m_p2->isValid(pSysParticTradeOrderStates);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesOrPredict�Ƕ�������Աϯλ����״̬ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesOrPredict : public CSysParticTradeOrderStatesPredict
{
private:
	CSysParticTradeOrderStatesPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysParticTradeOrderStatesOrPredict(CSysParticTradeOrderStatesPredict *p1, CSysParticTradeOrderStatesPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysParticTradeOrderStatesOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysParticTradeOrderStates	Ҫ���жϵĻ�Աϯλ����״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return m_p1->isValid(pSysParticTradeOrderStates) || m_p2->isValid(pSysParticTradeOrderStates);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesNotPredict�Ƕ�һ����Աϯλ����״̬ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesNotPredict : public CSysParticTradeOrderStatesPredict
{
private:
	CSysParticTradeOrderStatesPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysParticTradeOrderStatesNotPredict(CSysParticTradeOrderStatesPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysParticTradeOrderStatesNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysParticTradeOrderStates	Ҫ���жϵĻ�Աϯλ����״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return !m_predict->isValid(pSysParticTradeOrderStates);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesFilter��һ�������еĻ�Աϯλ����״̬ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesFilter: public CSysParticTradeOrderStatesIterator
{
private:
	CSysParticTradeOrderStatesIterator *m_baseIterator;
	CSysParticTradeOrderStatesPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysParticTradeOrderStatesFilter(CSysParticTradeOrderStatesIterator *pBaseIterator, CSysParticTradeOrderStatesPredict *pPredict, bool continueResult=false)
		:CSysParticTradeOrderStatesIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysParticTradeOrderStatesFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysParticTradeOrderStates
	///@return	��һ����������CSysParticTradeOrderStates������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysParticTradeOrderStates *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysParticTradeOrderStates ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysParticTradeOrderStates * pSysParticTradeOrderStates,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesLinkIterator������������Աϯλ����״̬ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesLinkIterator: public CSysParticTradeOrderStatesIterator
{
private:
	CSysParticTradeOrderStatesIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysParticTradeOrderStatesLinkIterator(CSysParticTradeOrderStatesIterator *pBaseIterator1,CSysParticTradeOrderStatesIterator *pBaseIterator2)
		:CSysParticTradeOrderStatesIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysParticTradeOrderStatesLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysParticTradeOrderStates
	///@return	��һ����������CSysParticTradeOrderStates������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysParticTradeOrderStates *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysParticTradeOrderStates ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysParticTradeOrderStates * pSysParticTradeOrderStates,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoSingleIterator�����෵��һ��ϵͳ·����Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoSingleIterator: public CSysMdbRouterInfoIterator
{
private:
	CSysMdbRouterInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMdbRouterInfoSingleIterator(CSysMdbRouterInfoFactory *pFactory,CSysMdbRouterInfo *pResult)
		:CSysMdbRouterInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMdbRouterInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMdbRouterInfo
	///@return	��һ����������CSysMdbRouterInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbRouterInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbRouterInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbRouterInfo * pSysMdbRouterInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoPredict���ж�һ��ϵͳ·����Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbRouterInfo	Ҫ���жϵ�ϵͳ·����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbRouterInfo *pSysMdbRouterInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoAndPredict�Ƕ�����ϵͳ·����Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoAndPredict : public CSysMdbRouterInfoPredict
{
private:
	CSysMdbRouterInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbRouterInfoAndPredict(CSysMdbRouterInfoPredict *p1, CSysMdbRouterInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbRouterInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbRouterInfo	Ҫ���жϵ�ϵͳ·����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return m_p1->isValid(pSysMdbRouterInfo) && m_p2->isValid(pSysMdbRouterInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoOrPredict�Ƕ�����ϵͳ·����Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoOrPredict : public CSysMdbRouterInfoPredict
{
private:
	CSysMdbRouterInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbRouterInfoOrPredict(CSysMdbRouterInfoPredict *p1, CSysMdbRouterInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbRouterInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbRouterInfo	Ҫ���жϵ�ϵͳ·����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return m_p1->isValid(pSysMdbRouterInfo) || m_p2->isValid(pSysMdbRouterInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoNotPredict�Ƕ�һ��ϵͳ·����Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoNotPredict : public CSysMdbRouterInfoPredict
{
private:
	CSysMdbRouterInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMdbRouterInfoNotPredict(CSysMdbRouterInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMdbRouterInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbRouterInfo	Ҫ���жϵ�ϵͳ·����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return !m_predict->isValid(pSysMdbRouterInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoFilter��һ�������е�ϵͳ·����Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoFilter: public CSysMdbRouterInfoIterator
{
private:
	CSysMdbRouterInfoIterator *m_baseIterator;
	CSysMdbRouterInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMdbRouterInfoFilter(CSysMdbRouterInfoIterator *pBaseIterator, CSysMdbRouterInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbRouterInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMdbRouterInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMdbRouterInfo
	///@return	��һ����������CSysMdbRouterInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbRouterInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbRouterInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbRouterInfo * pSysMdbRouterInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoLinkIterator����������ϵͳ·����Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoLinkIterator: public CSysMdbRouterInfoIterator
{
private:
	CSysMdbRouterInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMdbRouterInfoLinkIterator(CSysMdbRouterInfoIterator *pBaseIterator1,CSysMdbRouterInfoIterator *pBaseIterator2)
		:CSysMdbRouterInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMdbRouterInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMdbRouterInfo
	///@return	��һ����������CSysMdbRouterInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbRouterInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbRouterInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbRouterInfo * pSysMdbRouterInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOSingleIterator�����෵��һ������I/O��Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOSingleIterator: public CSysMdbDiskIOIterator
{
private:
	CSysMdbDiskIO *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMdbDiskIOSingleIterator(CSysMdbDiskIOFactory *pFactory,CSysMdbDiskIO *pResult)
		:CSysMdbDiskIOIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMdbDiskIOSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMdbDiskIO
	///@return	��һ����������CSysMdbDiskIO������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbDiskIO *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbDiskIO ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbDiskIO * pSysMdbDiskIO,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOPredict���ж�һ������I/O��Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbDiskIO	Ҫ���жϵĴ���I/O��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbDiskIO *pSysMdbDiskIO)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOAndPredict�Ƕ���������I/O��Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOAndPredict : public CSysMdbDiskIOPredict
{
private:
	CSysMdbDiskIOPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbDiskIOAndPredict(CSysMdbDiskIOPredict *p1, CSysMdbDiskIOPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbDiskIOAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbDiskIO	Ҫ���жϵĴ���I/O��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbDiskIO *pSysMdbDiskIO)
	{
		return m_p1->isValid(pSysMdbDiskIO) && m_p2->isValid(pSysMdbDiskIO);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOOrPredict�Ƕ���������I/O��Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOOrPredict : public CSysMdbDiskIOPredict
{
private:
	CSysMdbDiskIOPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbDiskIOOrPredict(CSysMdbDiskIOPredict *p1, CSysMdbDiskIOPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbDiskIOOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbDiskIO	Ҫ���жϵĴ���I/O��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbDiskIO *pSysMdbDiskIO)
	{
		return m_p1->isValid(pSysMdbDiskIO) || m_p2->isValid(pSysMdbDiskIO);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIONotPredict�Ƕ�һ������I/O��Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIONotPredict : public CSysMdbDiskIOPredict
{
private:
	CSysMdbDiskIOPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMdbDiskIONotPredict(CSysMdbDiskIOPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMdbDiskIONotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbDiskIO	Ҫ���жϵĴ���I/O��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbDiskIO *pSysMdbDiskIO)
	{
		return !m_predict->isValid(pSysMdbDiskIO);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOFilter��һ�������еĴ���I/O��Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOFilter: public CSysMdbDiskIOIterator
{
private:
	CSysMdbDiskIOIterator *m_baseIterator;
	CSysMdbDiskIOPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMdbDiskIOFilter(CSysMdbDiskIOIterator *pBaseIterator, CSysMdbDiskIOPredict *pPredict, bool continueResult=false)
		:CSysMdbDiskIOIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMdbDiskIOFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMdbDiskIO
	///@return	��һ����������CSysMdbDiskIO������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbDiskIO *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbDiskIO ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbDiskIO * pSysMdbDiskIO,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOLinkIterator��������������I/O��Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOLinkIterator: public CSysMdbDiskIOIterator
{
private:
	CSysMdbDiskIOIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMdbDiskIOLinkIterator(CSysMdbDiskIOIterator *pBaseIterator1,CSysMdbDiskIOIterator *pBaseIterator2)
		:CSysMdbDiskIOIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMdbDiskIOLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMdbDiskIO
	///@return	��һ����������CSysMdbDiskIO������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbDiskIO *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbDiskIO ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbDiskIO * pSysMdbDiskIO,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoSingleIterator�����෵��һ��ϵͳ״̬��Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoSingleIterator: public CSysMdbStatInfoIterator
{
private:
	CSysMdbStatInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMdbStatInfoSingleIterator(CSysMdbStatInfoFactory *pFactory,CSysMdbStatInfo *pResult)
		:CSysMdbStatInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMdbStatInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMdbStatInfo
	///@return	��һ����������CSysMdbStatInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbStatInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbStatInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbStatInfo * pSysMdbStatInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoPredict���ж�һ��ϵͳ״̬��Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbStatInfo	Ҫ���жϵ�ϵͳ״̬��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbStatInfo *pSysMdbStatInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoAndPredict�Ƕ�����ϵͳ״̬��Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoAndPredict : public CSysMdbStatInfoPredict
{
private:
	CSysMdbStatInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbStatInfoAndPredict(CSysMdbStatInfoPredict *p1, CSysMdbStatInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbStatInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbStatInfo	Ҫ���жϵ�ϵͳ״̬��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbStatInfo *pSysMdbStatInfo)
	{
		return m_p1->isValid(pSysMdbStatInfo) && m_p2->isValid(pSysMdbStatInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoOrPredict�Ƕ�����ϵͳ״̬��Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoOrPredict : public CSysMdbStatInfoPredict
{
private:
	CSysMdbStatInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbStatInfoOrPredict(CSysMdbStatInfoPredict *p1, CSysMdbStatInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbStatInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbStatInfo	Ҫ���жϵ�ϵͳ״̬��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbStatInfo *pSysMdbStatInfo)
	{
		return m_p1->isValid(pSysMdbStatInfo) || m_p2->isValid(pSysMdbStatInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoNotPredict�Ƕ�һ��ϵͳ״̬��Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoNotPredict : public CSysMdbStatInfoPredict
{
private:
	CSysMdbStatInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMdbStatInfoNotPredict(CSysMdbStatInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMdbStatInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbStatInfo	Ҫ���жϵ�ϵͳ״̬��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbStatInfo *pSysMdbStatInfo)
	{
		return !m_predict->isValid(pSysMdbStatInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoFilter��һ�������е�ϵͳ״̬��Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoFilter: public CSysMdbStatInfoIterator
{
private:
	CSysMdbStatInfoIterator *m_baseIterator;
	CSysMdbStatInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMdbStatInfoFilter(CSysMdbStatInfoIterator *pBaseIterator, CSysMdbStatInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbStatInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMdbStatInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMdbStatInfo
	///@return	��һ����������CSysMdbStatInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbStatInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbStatInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbStatInfo * pSysMdbStatInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoLinkIterator����������ϵͳ״̬��Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoLinkIterator: public CSysMdbStatInfoIterator
{
private:
	CSysMdbStatInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMdbStatInfoLinkIterator(CSysMdbStatInfoIterator *pBaseIterator1,CSysMdbStatInfoIterator *pBaseIterator2)
		:CSysMdbStatInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMdbStatInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMdbStatInfo
	///@return	��һ����������CSysMdbStatInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbStatInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbStatInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbStatInfo * pSysMdbStatInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatSingleIterator�����෵��һ������ϵͳǰ�ñ�����Ӧ��Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatSingleIterator: public CSysMdbTradeFrontOrderRttStatIterator
{
private:
	CSysMdbTradeFrontOrderRttStat *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMdbTradeFrontOrderRttStatSingleIterator(CSysMdbTradeFrontOrderRttStatFactory *pFactory,CSysMdbTradeFrontOrderRttStat *pResult)
		:CSysMdbTradeFrontOrderRttStatIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMdbTradeFrontOrderRttStatSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMdbTradeFrontOrderRttStat
	///@return	��һ����������CSysMdbTradeFrontOrderRttStat������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTradeFrontOrderRttStat *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbTradeFrontOrderRttStat ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatPredict���ж�һ������ϵͳǰ�ñ�����Ӧ��Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbTradeFrontOrderRttStat	Ҫ���жϵĽ���ϵͳǰ�ñ�����Ӧ��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatAndPredict�Ƕ���������ϵͳǰ�ñ�����Ӧ��Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatAndPredict : public CSysMdbTradeFrontOrderRttStatPredict
{
private:
	CSysMdbTradeFrontOrderRttStatPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbTradeFrontOrderRttStatAndPredict(CSysMdbTradeFrontOrderRttStatPredict *p1, CSysMdbTradeFrontOrderRttStatPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbTradeFrontOrderRttStatAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbTradeFrontOrderRttStat	Ҫ���жϵĽ���ϵͳǰ�ñ�����Ӧ��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return m_p1->isValid(pSysMdbTradeFrontOrderRttStat) && m_p2->isValid(pSysMdbTradeFrontOrderRttStat);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatOrPredict�Ƕ���������ϵͳǰ�ñ�����Ӧ��Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatOrPredict : public CSysMdbTradeFrontOrderRttStatPredict
{
private:
	CSysMdbTradeFrontOrderRttStatPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMdbTradeFrontOrderRttStatOrPredict(CSysMdbTradeFrontOrderRttStatPredict *p1, CSysMdbTradeFrontOrderRttStatPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMdbTradeFrontOrderRttStatOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbTradeFrontOrderRttStat	Ҫ���жϵĽ���ϵͳǰ�ñ�����Ӧ��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return m_p1->isValid(pSysMdbTradeFrontOrderRttStat) || m_p2->isValid(pSysMdbTradeFrontOrderRttStat);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatNotPredict�Ƕ�һ������ϵͳǰ�ñ�����Ӧ��Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatNotPredict : public CSysMdbTradeFrontOrderRttStatPredict
{
private:
	CSysMdbTradeFrontOrderRttStatPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMdbTradeFrontOrderRttStatNotPredict(CSysMdbTradeFrontOrderRttStatPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMdbTradeFrontOrderRttStatNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMdbTradeFrontOrderRttStat	Ҫ���жϵĽ���ϵͳǰ�ñ�����Ӧ��Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return !m_predict->isValid(pSysMdbTradeFrontOrderRttStat);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatFilter��һ�������еĽ���ϵͳǰ�ñ�����Ӧ��Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatFilter: public CSysMdbTradeFrontOrderRttStatIterator
{
private:
	CSysMdbTradeFrontOrderRttStatIterator *m_baseIterator;
	CSysMdbTradeFrontOrderRttStatPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMdbTradeFrontOrderRttStatFilter(CSysMdbTradeFrontOrderRttStatIterator *pBaseIterator, CSysMdbTradeFrontOrderRttStatPredict *pPredict, bool continueResult=false)
		:CSysMdbTradeFrontOrderRttStatIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMdbTradeFrontOrderRttStatFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMdbTradeFrontOrderRttStat
	///@return	��һ����������CSysMdbTradeFrontOrderRttStat������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTradeFrontOrderRttStat *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbTradeFrontOrderRttStat ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatLinkIterator��������������ϵͳǰ�ñ�����Ӧ��Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatLinkIterator: public CSysMdbTradeFrontOrderRttStatIterator
{
private:
	CSysMdbTradeFrontOrderRttStatIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMdbTradeFrontOrderRttStatLinkIterator(CSysMdbTradeFrontOrderRttStatIterator *pBaseIterator1,CSysMdbTradeFrontOrderRttStatIterator *pBaseIterator2)
		:CSysMdbTradeFrontOrderRttStatIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMdbTradeFrontOrderRttStatLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMdbTradeFrontOrderRttStat
	///@return	��һ����������CSysMdbTradeFrontOrderRttStat������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTradeFrontOrderRttStat *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbTradeFrontOrderRttStat ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusSingleIterator�����෵��һ����Լ״̬�л���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusSingleIterator: public CSysInstrumentStatusIterator
{
private:
	CSysInstrumentStatus *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysInstrumentStatusSingleIterator(CSysInstrumentStatusFactory *pFactory,CSysInstrumentStatus *pResult)
		:CSysInstrumentStatusIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysInstrumentStatusSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysInstrumentStatus
	///@return	��һ����������CSysInstrumentStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysInstrumentStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysInstrumentStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysInstrumentStatus * pSysInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusPredict���ж�һ����Լ״̬�л��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysInstrumentStatus	Ҫ���жϵĺ�Լ״̬�л�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysInstrumentStatus *pSysInstrumentStatus)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusAndPredict�Ƕ�������Լ״̬�л�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusAndPredict : public CSysInstrumentStatusPredict
{
private:
	CSysInstrumentStatusPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysInstrumentStatusAndPredict(CSysInstrumentStatusPredict *p1, CSysInstrumentStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysInstrumentStatusAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysInstrumentStatus	Ҫ���жϵĺ�Լ״̬�л�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysInstrumentStatus *pSysInstrumentStatus)
	{
		return m_p1->isValid(pSysInstrumentStatus) && m_p2->isValid(pSysInstrumentStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusOrPredict�Ƕ�������Լ״̬�л�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusOrPredict : public CSysInstrumentStatusPredict
{
private:
	CSysInstrumentStatusPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysInstrumentStatusOrPredict(CSysInstrumentStatusPredict *p1, CSysInstrumentStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysInstrumentStatusOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysInstrumentStatus	Ҫ���жϵĺ�Լ״̬�л�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysInstrumentStatus *pSysInstrumentStatus)
	{
		return m_p1->isValid(pSysInstrumentStatus) || m_p2->isValid(pSysInstrumentStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusNotPredict�Ƕ�һ����Լ״̬�л�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusNotPredict : public CSysInstrumentStatusPredict
{
private:
	CSysInstrumentStatusPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysInstrumentStatusNotPredict(CSysInstrumentStatusPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysInstrumentStatusNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysInstrumentStatus	Ҫ���жϵĺ�Լ״̬�л�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysInstrumentStatus *pSysInstrumentStatus)
	{
		return !m_predict->isValid(pSysInstrumentStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusFilter��һ�������еĺ�Լ״̬�л�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusFilter: public CSysInstrumentStatusIterator
{
private:
	CSysInstrumentStatusIterator *m_baseIterator;
	CSysInstrumentStatusPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysInstrumentStatusFilter(CSysInstrumentStatusIterator *pBaseIterator, CSysInstrumentStatusPredict *pPredict, bool continueResult=false)
		:CSysInstrumentStatusIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysInstrumentStatusFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysInstrumentStatus
	///@return	��һ����������CSysInstrumentStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysInstrumentStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysInstrumentStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysInstrumentStatus * pSysInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusLinkIterator������������Լ״̬�л�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusLinkIterator: public CSysInstrumentStatusIterator
{
private:
	CSysInstrumentStatusIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysInstrumentStatusLinkIterator(CSysInstrumentStatusIterator *pBaseIterator1,CSysInstrumentStatusIterator *pBaseIterator2)
		:CSysInstrumentStatusIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysInstrumentStatusLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysInstrumentStatus
	///@return	��һ����������CSysInstrumentStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysInstrumentStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysInstrumentStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysInstrumentStatus * pSysInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrSingleIterator�����෵��һ����Լ���׽���Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrSingleIterator: public CSysCurrTradingSegmentAttrIterator
{
private:
	CSysCurrTradingSegmentAttr *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysCurrTradingSegmentAttrSingleIterator(CSysCurrTradingSegmentAttrFactory *pFactory,CSysCurrTradingSegmentAttr *pResult)
		:CSysCurrTradingSegmentAttrIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysCurrTradingSegmentAttrSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysCurrTradingSegmentAttr
	///@return	��һ����������CSysCurrTradingSegmentAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysCurrTradingSegmentAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysCurrTradingSegmentAttr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrPredict���ж�һ����Լ���׽���Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysCurrTradingSegmentAttr	Ҫ���жϵĺ�Լ���׽���Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrAndPredict�Ƕ�������Լ���׽���Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrAndPredict : public CSysCurrTradingSegmentAttrPredict
{
private:
	CSysCurrTradingSegmentAttrPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysCurrTradingSegmentAttrAndPredict(CSysCurrTradingSegmentAttrPredict *p1, CSysCurrTradingSegmentAttrPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysCurrTradingSegmentAttrAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysCurrTradingSegmentAttr	Ҫ���жϵĺ�Լ���׽���Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return m_p1->isValid(pSysCurrTradingSegmentAttr) && m_p2->isValid(pSysCurrTradingSegmentAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrOrPredict�Ƕ�������Լ���׽���Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrOrPredict : public CSysCurrTradingSegmentAttrPredict
{
private:
	CSysCurrTradingSegmentAttrPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysCurrTradingSegmentAttrOrPredict(CSysCurrTradingSegmentAttrPredict *p1, CSysCurrTradingSegmentAttrPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysCurrTradingSegmentAttrOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysCurrTradingSegmentAttr	Ҫ���жϵĺ�Լ���׽���Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return m_p1->isValid(pSysCurrTradingSegmentAttr) || m_p2->isValid(pSysCurrTradingSegmentAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrNotPredict�Ƕ�һ����Լ���׽���Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrNotPredict : public CSysCurrTradingSegmentAttrPredict
{
private:
	CSysCurrTradingSegmentAttrPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysCurrTradingSegmentAttrNotPredict(CSysCurrTradingSegmentAttrPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysCurrTradingSegmentAttrNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysCurrTradingSegmentAttr	Ҫ���жϵĺ�Լ���׽���Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return !m_predict->isValid(pSysCurrTradingSegmentAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrFilter��һ�������еĺ�Լ���׽���Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrFilter: public CSysCurrTradingSegmentAttrIterator
{
private:
	CSysCurrTradingSegmentAttrIterator *m_baseIterator;
	CSysCurrTradingSegmentAttrPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysCurrTradingSegmentAttrFilter(CSysCurrTradingSegmentAttrIterator *pBaseIterator, CSysCurrTradingSegmentAttrPredict *pPredict, bool continueResult=false)
		:CSysCurrTradingSegmentAttrIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysCurrTradingSegmentAttrFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysCurrTradingSegmentAttr
	///@return	��һ����������CSysCurrTradingSegmentAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysCurrTradingSegmentAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysCurrTradingSegmentAttr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrLinkIterator������������Լ���׽���Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrLinkIterator: public CSysCurrTradingSegmentAttrIterator
{
private:
	CSysCurrTradingSegmentAttrIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysCurrTradingSegmentAttrLinkIterator(CSysCurrTradingSegmentAttrIterator *pBaseIterator1,CSysCurrTradingSegmentAttrIterator *pBaseIterator2)
		:CSysCurrTradingSegmentAttrIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysCurrTradingSegmentAttrLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysCurrTradingSegmentAttr
	///@return	��һ����������CSysCurrTradingSegmentAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysCurrTradingSegmentAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysCurrTradingSegmentAttr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostSingleIterator�����෵��һ����Ա��·���ñ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostSingleIterator: public CSysMemberLinkCostIterator
{
private:
	CSysMemberLinkCost *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysMemberLinkCostSingleIterator(CSysMemberLinkCostFactory *pFactory,CSysMemberLinkCost *pResult)
		:CSysMemberLinkCostIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysMemberLinkCostSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysMemberLinkCost
	///@return	��һ����������CSysMemberLinkCost������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMemberLinkCost *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMemberLinkCost ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMemberLinkCost * pSysMemberLinkCost,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostPredict���ж�һ����Ա��·���ñ��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysMemberLinkCost	Ҫ���жϵĻ�Ա��·���ñ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMemberLinkCost *pSysMemberLinkCost)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostAndPredict�Ƕ�������Ա��·���ñ�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostAndPredict : public CSysMemberLinkCostPredict
{
private:
	CSysMemberLinkCostPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMemberLinkCostAndPredict(CSysMemberLinkCostPredict *p1, CSysMemberLinkCostPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMemberLinkCostAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMemberLinkCost	Ҫ���жϵĻ�Ա��·���ñ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMemberLinkCost *pSysMemberLinkCost)
	{
		return m_p1->isValid(pSysMemberLinkCost) && m_p2->isValid(pSysMemberLinkCost);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostOrPredict�Ƕ�������Ա��·���ñ�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostOrPredict : public CSysMemberLinkCostPredict
{
private:
	CSysMemberLinkCostPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysMemberLinkCostOrPredict(CSysMemberLinkCostPredict *p1, CSysMemberLinkCostPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysMemberLinkCostOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMemberLinkCost	Ҫ���жϵĻ�Ա��·���ñ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMemberLinkCost *pSysMemberLinkCost)
	{
		return m_p1->isValid(pSysMemberLinkCost) || m_p2->isValid(pSysMemberLinkCost);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostNotPredict�Ƕ�һ����Ա��·���ñ�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostNotPredict : public CSysMemberLinkCostPredict
{
private:
	CSysMemberLinkCostPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysMemberLinkCostNotPredict(CSysMemberLinkCostPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysMemberLinkCostNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysMemberLinkCost	Ҫ���жϵĻ�Ա��·���ñ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysMemberLinkCost *pSysMemberLinkCost)
	{
		return !m_predict->isValid(pSysMemberLinkCost);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostFilter��һ�������еĻ�Ա��·���ñ�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostFilter: public CSysMemberLinkCostIterator
{
private:
	CSysMemberLinkCostIterator *m_baseIterator;
	CSysMemberLinkCostPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysMemberLinkCostFilter(CSysMemberLinkCostIterator *pBaseIterator, CSysMemberLinkCostPredict *pPredict, bool continueResult=false)
		:CSysMemberLinkCostIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysMemberLinkCostFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysMemberLinkCost
	///@return	��һ����������CSysMemberLinkCost������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMemberLinkCost *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMemberLinkCost ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMemberLinkCost * pSysMemberLinkCost,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostLinkIterator������������Ա��·���ñ�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostLinkIterator: public CSysMemberLinkCostIterator
{
private:
	CSysMemberLinkCostIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysMemberLinkCostLinkIterator(CSysMemberLinkCostIterator *pBaseIterator1,CSysMemberLinkCostIterator *pBaseIterator2)
		:CSysMemberLinkCostIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysMemberLinkCostLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysMemberLinkCost
	///@return	��һ����������CSysMemberLinkCost������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMemberLinkCost *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMemberLinkCost ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMemberLinkCost * pSysMemberLinkCost,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentSingleIterator�����෵��һ����Ա��·������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentSingleIterator: public CSysNetPartylinkMonthlyRentIterator
{
private:
	CSysNetPartylinkMonthlyRent *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetPartylinkMonthlyRentSingleIterator(CSysNetPartylinkMonthlyRentFactory *pFactory,CSysNetPartylinkMonthlyRent *pResult)
		:CSysNetPartylinkMonthlyRentIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetPartylinkMonthlyRentSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetPartylinkMonthlyRent
	///@return	��һ����������CSysNetPartylinkMonthlyRent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartylinkMonthlyRent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPartylinkMonthlyRent ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentPredict���ж�һ����Ա��·������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPartylinkMonthlyRent	Ҫ���жϵĻ�Ա��·�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentAndPredict�Ƕ�������Ա��·�����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentAndPredict : public CSysNetPartylinkMonthlyRentPredict
{
private:
	CSysNetPartylinkMonthlyRentPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetPartylinkMonthlyRentAndPredict(CSysNetPartylinkMonthlyRentPredict *p1, CSysNetPartylinkMonthlyRentPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetPartylinkMonthlyRentAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPartylinkMonthlyRent	Ҫ���жϵĻ�Ա��·�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return m_p1->isValid(pSysNetPartylinkMonthlyRent) && m_p2->isValid(pSysNetPartylinkMonthlyRent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentOrPredict�Ƕ�������Ա��·�����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentOrPredict : public CSysNetPartylinkMonthlyRentPredict
{
private:
	CSysNetPartylinkMonthlyRentPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetPartylinkMonthlyRentOrPredict(CSysNetPartylinkMonthlyRentPredict *p1, CSysNetPartylinkMonthlyRentPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetPartylinkMonthlyRentOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPartylinkMonthlyRent	Ҫ���жϵĻ�Ա��·�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return m_p1->isValid(pSysNetPartylinkMonthlyRent) || m_p2->isValid(pSysNetPartylinkMonthlyRent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentNotPredict�Ƕ�һ����Ա��·�����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentNotPredict : public CSysNetPartylinkMonthlyRentPredict
{
private:
	CSysNetPartylinkMonthlyRentPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetPartylinkMonthlyRentNotPredict(CSysNetPartylinkMonthlyRentPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetPartylinkMonthlyRentNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetPartylinkMonthlyRent	Ҫ���жϵĻ�Ա��·�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return !m_predict->isValid(pSysNetPartylinkMonthlyRent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentFilter��һ�������еĻ�Ա��·�����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentFilter: public CSysNetPartylinkMonthlyRentIterator
{
private:
	CSysNetPartylinkMonthlyRentIterator *m_baseIterator;
	CSysNetPartylinkMonthlyRentPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetPartylinkMonthlyRentFilter(CSysNetPartylinkMonthlyRentIterator *pBaseIterator, CSysNetPartylinkMonthlyRentPredict *pPredict, bool continueResult=false)
		:CSysNetPartylinkMonthlyRentIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetPartylinkMonthlyRentFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetPartylinkMonthlyRent
	///@return	��һ����������CSysNetPartylinkMonthlyRent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartylinkMonthlyRent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPartylinkMonthlyRent ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentLinkIterator������������Ա��·�����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentLinkIterator: public CSysNetPartylinkMonthlyRentIterator
{
private:
	CSysNetPartylinkMonthlyRentIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetPartylinkMonthlyRentLinkIterator(CSysNetPartylinkMonthlyRentIterator *pBaseIterator1,CSysNetPartylinkMonthlyRentIterator *pBaseIterator2)
		:CSysNetPartylinkMonthlyRentIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetPartylinkMonthlyRentLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetPartylinkMonthlyRent
	///@return	��һ����������CSysNetPartylinkMonthlyRent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartylinkMonthlyRent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPartylinkMonthlyRent ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoSingleIterator�����෵��һ����Ա��·������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoSingleIterator: public CSysNetNonPartyLinkInfoIterator
{
private:
	CSysNetNonPartyLinkInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSysNetNonPartyLinkInfoSingleIterator(CSysNetNonPartyLinkInfoFactory *pFactory,CSysNetNonPartyLinkInfo *pResult)
		:CSysNetNonPartyLinkInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSysNetNonPartyLinkInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSysNetNonPartyLinkInfo
	///@return	��һ����������CSysNetNonPartyLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetNonPartyLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetNonPartyLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoPredict���ж�һ����Ա��·������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSysNetNonPartyLinkInfo	Ҫ���жϵĻ�Ա��·�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoAndPredict�Ƕ�������Ա��·�����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoAndPredict : public CSysNetNonPartyLinkInfoPredict
{
private:
	CSysNetNonPartyLinkInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetNonPartyLinkInfoAndPredict(CSysNetNonPartyLinkInfoPredict *p1, CSysNetNonPartyLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetNonPartyLinkInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetNonPartyLinkInfo	Ҫ���жϵĻ�Ա��·�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return m_p1->isValid(pSysNetNonPartyLinkInfo) && m_p2->isValid(pSysNetNonPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoOrPredict�Ƕ�������Ա��·�����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoOrPredict : public CSysNetNonPartyLinkInfoPredict
{
private:
	CSysNetNonPartyLinkInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSysNetNonPartyLinkInfoOrPredict(CSysNetNonPartyLinkInfoPredict *p1, CSysNetNonPartyLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSysNetNonPartyLinkInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetNonPartyLinkInfo	Ҫ���жϵĻ�Ա��·�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return m_p1->isValid(pSysNetNonPartyLinkInfo) || m_p2->isValid(pSysNetNonPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoNotPredict�Ƕ�һ����Ա��·�����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoNotPredict : public CSysNetNonPartyLinkInfoPredict
{
private:
	CSysNetNonPartyLinkInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSysNetNonPartyLinkInfoNotPredict(CSysNetNonPartyLinkInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSysNetNonPartyLinkInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSysNetNonPartyLinkInfo	Ҫ���жϵĻ�Ա��·�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return !m_predict->isValid(pSysNetNonPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoFilter��һ�������еĻ�Ա��·�����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoFilter: public CSysNetNonPartyLinkInfoIterator
{
private:
	CSysNetNonPartyLinkInfoIterator *m_baseIterator;
	CSysNetNonPartyLinkInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSysNetNonPartyLinkInfoFilter(CSysNetNonPartyLinkInfoIterator *pBaseIterator, CSysNetNonPartyLinkInfoPredict *pPredict, bool continueResult=false)
		:CSysNetNonPartyLinkInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSysNetNonPartyLinkInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSysNetNonPartyLinkInfo
	///@return	��һ����������CSysNetNonPartyLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetNonPartyLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetNonPartyLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoLinkIterator������������Ա��·�����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoLinkIterator: public CSysNetNonPartyLinkInfoIterator
{
private:
	CSysNetNonPartyLinkInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSysNetNonPartyLinkInfoLinkIterator(CSysNetNonPartyLinkInfoIterator *pBaseIterator1,CSysNetNonPartyLinkInfoIterator *pBaseIterator2)
		:CSysNetNonPartyLinkInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSysNetNonPartyLinkInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSysNetNonPartyLinkInfo
	///@return	��һ����������CSysNetNonPartyLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetNonPartyLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetNonPartyLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


#endif
